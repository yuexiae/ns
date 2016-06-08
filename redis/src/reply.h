#ifndef REDIS_SRC_REPLY_H_
#define REDIS_SRC_REPLY_H_


#include "redis/redis.h"
#include "base/buffer.h"
#include <assert.h>

namespace redis {

class ReaderBuffer : public base::Buffer {
public:
    ReaderBuffer() {
        pos_ = 0;
    }

    bool ReadType(char& type) {
        if (pos_ < len_) {
            type = *(data_ + pos_++);
            return true;
        }

        return false;
    }

    const char* SeekNewline(size_t& len) {
        char *s = data_ + pos_;
        int pos = 0;
        int _len = (int)(len_-pos_-2);

        while (pos < _len) {
            while(pos < _len && s[pos] != '\r') pos++;
            if (s[pos] != '\r') {
                return NULL;
            } else {
                if (s[pos+1] == '\n') {
                    len = pos;
                    pos_ += (pos + 2);
                    return s;
                } else {
                    pos++;
                }
            }
        }
        return NULL;
    }

    const char* SeekBytes(size_t len) {
        if (len + 2> len_ - pos_) {
            return NULL;
        }

        char *s = data_ + pos_;
        if (s[len] != '\r' || s[len + 1] != '\n') {
            return NULL;
        }

        pos_ += (len + 2);
        return s;
    }

    static int64_t ReadLongLong(const char *s) {
        int64_t v = 0;
        int dec, mult = 1;
        char c;

        if (*s == '-') {
            mult = -1;
            s++;
        } else if (*s == '+') {
            mult = 1;
            s++;
        }

        while ((c = *(s++)) != '\r') {
            dec = c - '0';
            if (dec >= 0 && dec < 10) {
                v *= 10;
                v += dec;
            } else {
                return -1;
            }
        }

        return mult*v;
    }

    void Shirk() {
		Buffer::Shirk(pos_);
        pos_ = 0;
    }

    void Clear() {
        Buffer::Clear();
        pos_ = 0;
    }
    
private:
    size_t pos_;
};

class ReplyImpl : public GenericReply {
public:
    void SetType(Type type) { 
        flags_ = type;
        memset(&data_, 0, sizeof(data_));
    }
    void SetInterger(long long v) { data_.i = v; }
    long long GetInterger() { return data_.i; }
    void SetStringRaw(const void* s, size_t length) {
        char* str = NULL;
        if(ShortString::Usable(length)) {
            data_.ss.SetLength(length);
            str = data_.ss.str;
        } else {
            flags_ |= kCopyStringFlag;
            data_.s.length = length;
            str = (char *)malloc((length + 1) * sizeof(char));
            data_.s.str = str;
        }
        std::memcpy(str, s, length * sizeof(char));
        str[length] = '\0';
    }

    void SetArrayRaw(size_t capacity) {
        data_.a.size = 0;
        data_.a.elements = (GenericReply *)malloc(capacity * sizeof(GenericReply));
        data_.a.capacity = capacity;
        memset(data_.a.elements, 0, capacity * sizeof(GenericReply));
    }

    void ReallocArrayRaw(size_t capacity) {
        data_.a.size = 0;
        if (data_.a.elements == NULL) {
            data_.a.elements = (GenericReply *)malloc(capacity * sizeof(GenericReply));
			if (data_.a.elements == NULL) {
				throw std::bad_alloc();
			}
        } else if (capacity > data_.a.capacity) {
            data_.a.elements = (GenericReply *)realloc(data_.a.elements, capacity * sizeof(GenericReply));
			if (data_.a.elements == NULL) {
				throw std::bad_alloc();
			}
        }

        data_.a.capacity = capacity;
        memset(data_.a.elements, 0, capacity * sizeof(GenericReply));
    }


    void PushBack(GenericReply& reply) {
        if (data_.a.size < data_.a.capacity) {
		    data_.a.elements[data_.a.size++] = reply;
        } else {
            throw std::bad_exception();
        }
	}

    GenericReply Pop() {
        GenericReply result;
        if (data_.a.size) {
            result = *data_.a.elements;
            --data_.a.size;
            memcpy(data_.a.elements, data_.a.elements + 1, data_.a.size * sizeof(GenericReply));
        }

        return result;
    }

    GenericReply PopAll() {
        ReplyImpl result;
        result.SetType(kArrayType);
        result.SetArrayRaw(data_.a.size);
        result.data_.a.size = data_.a.size;
        memcpy(result.data_.a.elements, data_.a.elements, data_.a.size * sizeof(GenericReply));
        data_.a.size = 0;
        return result;
    }

    ReplyImpl* GetLastNotFullArray() {
        if (IsArray() && Capacity()) {
            if (Size() == 0) {
                return this;
            } else {
                ReplyImpl *r = reinterpret_cast<ReplyImpl *>(&data_.a.elements[data_.a.size - 1])->GetLastNotFullArray();
                if (r) {
                    return r;
                } else {
                    if (Size() < Capacity()) {
                        return this;
                    } else {
                        return NULL;
                    }
                }
            }
        } else {
            return NULL;
        }
    }
};


class ReplyReader {
public:
    enum Result {
        kStatusError = -2,
        kStatusPending = -1,
        kStatusFinish = 0
    };

    
    ReplyReader() { replys_.SetType(kArrayType); }

    void SetCount(size_t count) {
        replys_.ReallocArrayRaw(count);
    }

    GenericReply Pop() { return replys_.Pop(); }

    GenericReply PopAll() { return replys_.PopAll(); }
    
    Result ProcessAll(ReaderBuffer& buffer) {
        ReplyImpl *r;
        while (r = replys_.GetLastNotFullArray()) {
            Result result = Process(buffer);
            if (result != kStatusFinish) {
                return result;
            } else {
                r->PushBack(reply_);
            }
        }

        return kStatusFinish;
    }

    
private:
    Result Process(ReaderBuffer& buffer) {
        if (reply_.GetType() == kDefaultType) {
            char type;
            if (!buffer.ReadType(type)) {
                return kStatusPending;
            }

            switch (type) {
            case '+':
                reply_.SetType(kStatusType);
                break;
            case '-':
                reply_.SetType(kErrorType);
                break;
            case ':':
                reply_.SetType(kIntegerType);
                break;
            case '$':
                reply_.SetType(kStringType);
                break;
            case '*':
                reply_.SetType(kArrayType);
                break;
            default:
                return kStatusError;
            }
        }

        Result result;
        switch (reply_.GetType()) {
        case kStatusType:
        case kErrorType:
        case kIntegerType:
            result = ProcessLine(buffer);
            break;
        case kStringType:
            result = ProcessBulk(buffer);
            break;
        case kArrayType:
            result = ProcessMultiBulk(buffer);
            break;
        default:
            assert(NULL);
        }
        
        return result;
    }

    Result ProcessLine(ReaderBuffer& buffer) {
        size_t len;
        const char *line;
        if ((line = buffer.SeekNewline(len)) != NULL) {
            if (reply_.IsInteger()) {
                reply_.SetInterger(ReaderBuffer::ReadLongLong(line));
            } else {
                reply_.SetStringRaw(line, len);
            }

            return kStatusFinish;
        } else {
            return kStatusPending;
        }
    }

    Result ProcessBulk(ReaderBuffer& buffer) {
        if (reply_.GetInterger() == 0) {
            size_t len;
            const char *line;
            if ((line = buffer.SeekNewline(len)) != NULL) {
                reply_.SetInterger(ReaderBuffer::ReadLongLong(line));
            } else {
                return kStatusPending;
            }
        }
        
        if (reply_.GetInterger() < 0) {
            reply_.SetType(kNullType);
            return kStatusFinish;
        } else {
            const char *s;
            if ((s = buffer.SeekBytes(static_cast<size_t>(reply_.GetInterger()))) != NULL) {
                reply_.SetStringRaw(s, static_cast<size_t>(reply_.GetInterger()));
                return kStatusFinish;
            } else {
                return kStatusPending;
            }
        }
    }

    Result ProcessMultiBulk(ReaderBuffer& buffer) {
        size_t len;
        const char *line;
        if ((line = buffer.SeekNewline(len)) != NULL) {
            reply_.SetInterger(ReaderBuffer::ReadLongLong(line));
        } else {
            return kStatusPending;
        }

        if (reply_.GetInterger() < 0) {
            reply_.SetType(kNullType);
        } else {
            reply_.SetArrayRaw(static_cast<size_t>(reply_.GetInterger()));
        }

		return kStatusFinish;
    }


    ReplyImpl reply_;
    ReplyImpl replys_;
};

} //namespace redis





#endif