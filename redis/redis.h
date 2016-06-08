#ifndef REDIS_REDIS_H_
#define REDIS_REDIS_H_

#include <string>
#include "base/util.h"
#include <msgpack.hpp>



#define RedisThrow(format, ...) do { \
	throw redis::Exception( \
		base::Util::Format("[%s:%d]", __FUNCTION__, __LINE__).append(base::Util::Format(format, __VA_ARGS__))); \
} while (0)


namespace redis {

enum Type {
    kDefaultType = 0,
    kNullType = 1,
    kStatusType = 2,
    kErrorType = 3,
    kIntegerType = 4,
    kStringType = 5,
    kArrayType = 6
};



class GenericReply;
class Protocol;

namespace internal {
template <typename Ch>
static inline size_t StrLen(const Ch* s) {
	const Ch* p = s;
	while (*p) ++p;
	return size_t(p - s);
}

static inline  const char* GetTypeString(Type type) {
    switch (type) {
    case kDefaultType:
        return "DefaultType";
    case kNullType:
        return "NullType";
    case kStatusType:
        return "StatusType";
    case kErrorType:
        return "ErrorType";
    case kIntegerType:
        return "IntegerType";
    case kStringType:
        return "StringType";
    case kArrayType:
        return "ArrayType";
    default:
        return "UnknowType";
    }
}

template <typename T, bool Signed>
struct convert_integer_sign;

template <typename T>
struct convert_integer_sign<T, true> {
    static inline T as(GenericReply& r) {
        if (!r.IsInteger()) {
            RedisThrow("type error '%s'!='Integer'", r.GetTypeString());
        } else if (r.data_.i < static_cast<int64_t>(std::numeric_limits<T>::min()) || r.data_.i > static_cast<int64_t>(std::numeric_limits<T>::max())) {
            RedisThrow("type error(%lld,%lld):'%lld'", static_cast<int64_t>(std::numeric_limits<T>::min()), static_cast<int64_t>(std::numeric_limits<T>::max()), r.data_.i);
        } else {
            return static_cast<T>(r.data_.i);
        }
    }

    static inline T convert(GenericReply& r) {
        if(!r.IsString()) {
            RedisThrow("type error '%s' != 'String'", r.GetTypeString());
        } else {
            char *end = NULL;
            long long value = _strtoi64(r.GetString(), &end, 10);
            if (end != r.GetString() + r.GetLength()) {
                RedisThrow("'%s' is not number string", r.GetString());
            } else if (value < static_cast<int64_t>(std::numeric_limits<T>::min()) || value > static_cast<int64_t>(std::numeric_limits<T>::max())) {
                RedisThrow("type error(%lld,%lld):'%lld'", static_cast<int64_t>(std::numeric_limits<T>::min()), static_cast<int64_t>(std::numeric_limits<T>::max()), value);
            } else {
                return static_cast<T>(value);
            }
        }
    }
};

template <typename T>
struct convert_integer_sign<T, false> {
    static inline T as(GenericReply& r) {
        if (!r.IsInteger()) {
            RedisThrow("type error '%s'!='Integer'", r.GetTypeString());
        } else if (r.data_.u > static_cast<uint64_t>(std::numeric_limits<T>::max())) {
            RedisThrow("type error(%llu):'%llu'", static_cast<uint64_t>(std::numeric_limits<T>::max()), r.data_.u);
        } else {
            return static_cast<T>(r.data_.u);
        }

        
        
    }

    static inline T convert(GenericReply& r) {
        if(!r.IsString()) {
            RedisThrow("type error '%s' != 'String'", r.GetTypeString());
        } else {
            char *end = NULL;
            unsigned long long value = _strtoui64(r.GetString(), &end, 10);
            if (end != r.GetString() + r.GetLength()) {
                RedisThrow("'%s' is not number string", r.GetString());
            } else if (value > static_cast<uint64_t>(std::numeric_limits<T>::max())) {
                RedisThrow("type error(%llu):'%llu'", static_cast<uint64_t>(std::numeric_limits<T>::max()), value);
            } else {
                return static_cast<T>(value);
            }
        }
    }
};

} //namespace internal 

class Exception : public std::exception {
public:
    Exception(std::string &msg) : exception(msg.c_str()) {}
};


template <typename CharType>
class GenericRef {
    typedef CharType Ch;

protected:
    GenericRef() : data_(), flags_() {}
    
    void SetString(const Ch* s) {
		flags_ = kStringFlag;
		data_.s.str = s;
		data_.s.length = internal::StrLen(s);
	}


public:
    enum {
        kSignedFlag  = 1,
        kUnsignedFlag,
        kStringFlag
    };

    GenericRef(int32_t i) : data_(), flags_(kSignedFlag) { data_.i = i; }

    GenericRef(int64_t i64) : data_(), flags_(kSignedFlag) { data_.i = i64; }

    GenericRef(unsigned ui) : data_(), flags_(kUnsignedFlag) { data_.u = ui; }

    GenericRef(unsigned long ui) : data_(), flags_(kUnsignedFlag) { data_.u = ui; }

    GenericRef(uint64_t ui64) : data_(), flags_(kUnsignedFlag) { data_.u = ui64; }

    GenericRef(const Ch*s) : data_(), flags_(kStringFlag) {
        data_.s.str = s;
        data_.s.length = internal::StrLen(s);
    }

    GenericRef(const void* s, size_t length) : data_(), flags_(kStringFlag) {
        data_.s.str = static_cast<const char *>(s);
        data_.s.length = length;
    }

    GenericRef(std::string & str) : data_(), flags_(kStringFlag) {
        data_.s.str = str.c_str();
        data_.s.length = str.size();
    }

    GenericRef(msgpack::sbuffer &buffer) : data_(), flags_(kStringFlag) {
        data_.s.str = buffer.data();
        data_.s.length = buffer.size();
    }

    struct String {
        const Ch* str;
        size_t length;
    };

    union Data {
        int64_t i;
        uint64_t u;
        String s;
    };

    Data data_;
    unsigned flags_;
};

typedef GenericRef<char> Ref;

template <size_t N>
class GenericUniqueKey : public GenericRef<char> {
	static const int kMaxSize = N;
public:
	GenericUniqueKey(const char* key, uint32_t unique) {
		int n = snprintf(key_, kMaxSize, "%s:%u", key, unique);
		if (n == -1 || n >= kMaxSize) {
			RedisThrow("key too long");
		}

		SetString(key_);
	}

	GenericUniqueKey(const char* key, int32_t unique) {
		int n = snprintf(key_, kMaxSize, "%s:%d", key, unique);
		if (n == -1 || n >= kMaxSize) {
			RedisThrow("key too long");
		}

		SetString(key_);
	}

	GenericUniqueKey(const char* key, const char* unique) {
		int n = snprintf(key_, kMaxSize, "%s:%s", key, unique);
		if (n == -1 || n >= kMaxSize) {
			RedisThrow("key too long");
		}

		SetString(key_);
	}
	
private:
	char key_[kMaxSize];
};

typedef GenericUniqueKey<256> UniqueKey;


class GenericReply {
    typedef char Ch;
    typedef size_t SizeType;

public:
    enum {
        kCopyStringFlag = 0x1000
    };

    GenericReply() : data_(), flags_(kDefaultType) {}

    GenericReply(GenericReply& rhs) {
        data_ = rhs.data_;
        flags_ = rhs.flags_;
        rhs.flags_ = 0;
    }

    ~GenericReply() {
        if (IsArray()) {
            for (GenericReply* v = data_.a.elements; v != data_.a.elements + data_.a.size; ++v) {
                v->~GenericReply();
            }
            free(data_.a.elements);
        } else if (IsCopyString()) {
            free(const_cast<Ch*>(data_.s.str));
        }
    }

    GenericReply& operator=(GenericReply& rhs) {
        this->~GenericReply();
        data_ = rhs.data_;
        flags_ = rhs.flags_;
        rhs.flags_ = kDefaultType;
        return *this;
    }

    inline Type GetType() { return  static_cast<Type>(flags_ & 0xFF); }
    inline bool IsNull() { return (flags_ & 0xFF) == kNullType; }
    inline bool IsStatus() { return (flags_ & 0xFF) == kStatusType; }
    inline bool IsError() { return (flags_ & 0xFF) == kErrorType; }
    inline bool IsInteger() { return (flags_ & 0xFF) == kIntegerType; }
    inline bool IsString() { return (flags_ & 0xFF) == kStringType; }
    inline bool IsArray() { return (flags_ & 0xFF) == kArrayType; }
    inline bool IsCopyString() { return (flags_ & kCopyStringFlag) != 0; }

    inline bool HasNull() {
        if (IsArray()) {
            for (GenericReply* v = data_.a.elements; v != data_.a.elements + data_.a.size; ++v) {
                if (v->HasNull()) {
                    return true;
                }
            }

            return false;
        } else {
            return IsNull();
        }
    }

    inline const Ch* GetString() { return IsCopyString() ? data_.s.str : data_.ss.str; }
    inline const size_t GetLength() { return IsCopyString() ? data_.s.length : data_.ss.GetLength(); }

    inline long long GetIngteger() { return data_.i; }

    inline size_t Size() const { return data_.a.size; }
    inline size_t Capacity() const { return data_.a.capacity; }

    inline const char* GetTypeString() { return internal::GetTypeString(GetType()); }


    void PrintDetial(int ident = 0) {
        for (int i = 0; i < ident; ++i) {
            printf("    ");
        }

        switch (GetType()) {
        case kDefaultType:
            printf("Default(nil)\n");
        case kNullType:
            printf("NULL(nil)\n");
            break;
        case kStatusType:
            printf("STATUS(%s,%u)\n", GetString(), GetLength());
            break;
        case kErrorType:
            printf("ERROR(%s,%u)\n", GetString(), GetLength());
            break;
        case kIntegerType:
            printf("INTEGER(%lld)\n", data_.i);
            break;
        case kStringType:
            printf("STRING(%s)\n", GetString());
            break;
        case kArrayType:
            printf("ARRAGE(%u):\n", data_.a.size);
            for (GenericReply* v = data_.a.elements; v != data_.a.elements + data_.a.size; ++v) {
                v->PrintDetial(ident + 1);
            }
            break;
        default:
             printf("Unknow(%u)\n", flags_);
        }
    }

    struct String {
        const Ch* str;
        size_t length;
        int reserved;
    };

    struct ShortString {
        enum { MaxChars = sizeof(String) / sizeof(Ch), MaxSize = MaxChars - 1, LenPos = MaxSize };
        Ch str[MaxChars];

        inline static bool Usable(size_t len) { return            (MaxSize >= len); }
        //inline static bool Usable(size_t len) { return            false; }
        inline void     SetLength(size_t len) { str[LenPos] = (Ch)(MaxSize -  len); }
        inline size_t GetLength() const       { return  (SizeType)(MaxSize -  str[LenPos]); }
    };

    struct Array {
        GenericReply* elements;
        size_t size;
        size_t capacity;
    };


    union Data {
        int64_t i;
        uint64_t u;
        String s;
        ShortString ss;
        Array a;
    };


    Data data_;
    unsigned flags_;
};

class Reply : private GenericReply {
public:
    void CheckStatusOk() {
        if (!IsStatus()) {
            RedisThrow("reply('%s') not a status type", GetTypeString());
        }

        if (strcmp(GenericReply::GetString(), "OK") != 0) {
            RedisThrow("reply status error('%s')", GenericReply::GetString());
        }
    }

    Reply& operator[](size_t index) {
        if (!IsArray()) {
            RedisThrow("index('%u') is not array", index);
        } else if (index < data_.a.size) {
            return static_cast<Reply &>(data_.a.elements[index]);
        } else {
            RedisThrow("index('%u') must be less than '%u'", index, data_.a.size);
        }
    }


    Reply* Begin() {
        if (!IsArray()) {
            RedisThrow("not a array");
        } else {
            return static_cast<Reply *>(data_.a.elements);
        }
    }

    Reply* End() { 
        if (!IsArray()) {
            RedisThrow("not a array");
        } else {
            return static_cast<Reply *>(data_.a.elements + data_.a.size);
        }
    }

    size_t Count() {
        if (!IsArray()) {
            RedisThrow("not a array");
        } else {
            return data_.a.size;
        }
    }

    inline const char* GetString() {
        if (!IsString()) {
            RedisThrow("not a string");
        } else {
            return GenericReply::GetString();
        }
    }

    inline const size_t GetLength() {
        if (!IsString()) {
            RedisThrow("not a string");
        } else {
            return GenericReply::GetLength();
        }
    }

    template <typename T> T as() { return internal::convert_integer_sign<T, std::numeric_limits<T>::is_signed>::as(*this); }

    template <typename T> T convert() { return internal::convert_integer_sign<T, std::numeric_limits<T>::is_signed>::convert(*this); }


    size_t assgin(char *dest, size_t max) {
        if (!IsString()) {
            RedisThrow("not a string");
        } else if (GetLength() > max - 1) {
            RedisThrow("dest not enough size");
        } else {
            memcpy(dest, GetString(), GetLength());
            dest[GetLength()] = '\0';
            return GetLength();
        }
    }

    void assgin_raw_eq(void *dest, size_t size) {
        if (!IsString()) {
            RedisThrow("not a string");
        } else if (GetLength() != size) {
            RedisThrow("dest not equal size");
        } else {
            memcpy(dest, GetString(), size);
        }
    }

    void assgin_raw(void *dest, size_t size) {
        if (!IsString()) {
            RedisThrow("not a string");
        } else if (GetLength() > size) {
            RedisThrow("dest not enough size");
        } else {
            memcpy(dest, GetString(), GetLength());
        }
    }

    template <size_t MAX>
    void assgin_sbuffer_stack(msgpack::sbuffer& buffer) {
        if (!IsString()) {
            RedisThrow("not a string");
        } else if (GetLength() > MAX) {
            RedisThrow("dest not enough size");
        } else {
            size_t size = GetLength();
            char *tmp = (char *)alloca(size);
            memcpy(tmp, GetString(), size);
            buffer.clear();
            buffer.write(tmp, size);
        }
    }

    void PrintDetial(int ident = 0) {
        GenericReply::PrintDetial(ident);
    }

};


class Connector {
public:
    Connector();

    ~Connector();

    void Connect(const char *host, uint16_t port);

    void PushCommand(const char *cmd);

    void Push(Ref v);
    void Push(Ref v, Ref v2) { Push(v); Push(v2); }
    void Push(Ref v, Ref v2, Ref v3) { Push(v); Push(v2); Push(v3); }
    void PushRaw(const void *buf, size_t len) { Push(Ref(buf, len));  }
    void PushRaw(Ref v, const void *buf, size_t len) { Push(v); Push(Ref(buf, len));  }
    void PushSeqment(const char *str, char seps);
    
    size_t GetCommandCount();

    Reply GetReply();
    Reply GetAllReply();

    //connection
	void auth(const char *password);
	void select(int dbid);

    //key
	void set(Ref k, Ref v);
    Reply get(Ref k);
	bool exists(Ref k);
	bool del(Ref k);

    //hash
	bool hexists(Ref key, Ref field);
	bool hdel(Ref key, Ref field);
	bool hset(Ref key, Ref field, Ref value);
	bool hsetnx(Ref key, Ref field, Ref value);
    void hmset(Ref key, Ref field, Ref value, Ref field2, Ref value2);
	Reply hincrby(Ref key, Ref field, Ref increment);
	Reply hget(Ref key, Ref field);
	Reply hmget(Ref key, const char *fields);
    Reply hgetall(Ref key);
    Reply hvals(Ref key);

    //set
    bool sadd(Ref key, Ref value);
    bool srem(Ref key, Ref value);

    //list
    long long lpush(Ref key, Ref value);

    //script
    void script_load(const char *path, std::string &hash);
    Reply evalsha(std::string& hash, Ref arg);
    Reply evalsha(std::string& hash, Ref arg, Ref arg2);
    Reply evalsha(std::string& hash, Ref arg, Ref arg2, Ref arg3);
    Reply evalsha(std::string& hash, Ref arg, Ref arg2, Ref arg3, Ref arg4);
    Reply evalsha(std::string& hash, Ref arg, Ref arg2, Ref arg3, Ref arg4, Ref arg5);
private:
    Protocol *protocol_;
};




}



#endif