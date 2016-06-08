#ifndef BASE_BUFFER_H_
#define BASE_BUFFER_H_

#include <string>
#include <stdlib.h>
#include <memory.h>
#include "base/itoa.h"


namespace base {

struct Buffer {
    static const unsigned int kDefaultCapacity = 256;
       
    Buffer() :data_(), len_(), capacity_() {
        Reserve(kDefaultCapacity);
    }

    Buffer(Buffer& rhs) {
        data_ = rhs.data_;
        len_ = rhs.len_;
        capacity_ = rhs.capacity_;
        rhs.data_ = NULL;
    }

    ~Buffer() {
        if (data_) {
            free(data_);
            data_ = NULL;
        }
    }

    Buffer& operator=(Buffer& rhs) {
        this->~Buffer();
        data_ = rhs.data_;
        len_ = rhs.len_;
        capacity_ = rhs.capacity_;
        rhs.data_ = NULL;
        return *this;
    }

    inline char *Data() { return data_; }

    inline size_t Len() { return len_; }
    
    inline void Put(char c) {
        Reserve(len_ + sizeof(char));
        data_[len_++] = c;
    }

    inline void Put(const void *s, size_t l) {
        Reserve(len_ + l);
        memcpy(data_ + len_, s, l);
        len_ += l;
    }

    inline void Put(int i) {
        Reserve(len_ + 11);
        len_ = base::itoa::i32toa(i, data_ + len_) - data_;
    }

    inline void Put(unsigned int i) {
        Reserve(len_ + 10);
        len_ = base::itoa::u32toa(i, data_ + len_) - data_;
    }

    inline void Put(long long i) {
        Reserve(len_ + 21);
        len_ = base::itoa::i64toa(i, data_ + len_) - data_;
    }

    inline void Put(unsigned long long u) {
        Reserve(len_ + 20);
        len_ = base::itoa::u64toa(u, data_ + len_) - data_;
    }

    inline void Put(Buffer& b) {
        Put(b.data_, b.len_);
    }

    inline void Clear() {
        len_ = 0;
    }

    inline void Shirk(size_t len) {
        if (len >= len_) {
            len_ = 0;
        } else {
            len_ = len_ - len;
            memcpy(data_, data_ + len, len_);
        }
    }

protected:
    inline void Reserve(size_t size) {
        if (data_ == NULL) {
            len_ = 0;
            capacity_ = size;
            data_ = reinterpret_cast<char *>(malloc(capacity_));
            if (data_ == NULL) {
                throw std::bad_alloc();
            }
        } else if (size > capacity_) {
            capacity_ = size + (size + 1) / 2;
            data_ = reinterpret_cast<char *>(realloc(data_, capacity_));
            if (data_ == NULL) {
                throw std::bad_alloc();
            }
        }
    }

    char *data_;
    size_t len_;
    size_t capacity_;
};

/*
class StreamByte {
    StreamByte(StreamByte&);
    StreamByte& operator=(StreamByte&);

public:
	StreamByte() { Initialize(STREAMBUF_DEFAULT_SIZE); }

	explicit StreamByte(size_t size) { Initialize(size); }

	~StreamByte() {
        if (data_)
            free(data_);
    }

    StreamByte(StreamByte& rhs) {
       data_ = rhs.data_;
       len_ = rhs.len_;
       res_size_ = rhs.res_size_;
	   read_pos_ = rhs.read_pos_;
    }

    inline char* Data() { return data_; } const

	inline size_t Len() { return len_; } const

    inline char* RemainingData() { return data_ + read_pos_; } const

    inline size_t RemainingLen() { return len_ - read_pos_; } const

	inline size_t GetAllocLen() { return res_size_; } const

    inline void IncReadPos(size_t len) {
        if (read_pos_ + len > len_) {
            throw Exception("over flow");
        }
        read_pos_ += len;
    }

	inline void Read(void *buf, size_t size) {
		if (RemainingLen() < size) {
            throw Exception("over flow");
		}

		memcpy(buf, data_ + read_pos_, size);
        read_pos_ += size;
	}

	inline void Write(const void *buf, size_t size) {
		ReallocCheck(len_ + size);

		memcpy(data_ + len_, buf, size);
		len_ += size;
	}

	template <typename T>
	inline char Read() {
		T value = 0;
		Read(&value, sizeof(T));
		return value;
	}

    inline bool ReadLine(StreamByte& dest) {
        for (size_t i = read_pos_; i < len_; ++i) {
            if (data_[i] == '\r' && i + 1 < len_ && data_[i + 1] == '\n') {
                dest.Write(data_ + read_pos_, i - read_pos_);
                read_pos_ = i + 2;
                return true;
            }
        }

        return false;
    }

	inline void Write(char arg) {
		Write(&arg, sizeof(char));
	}

    inline void Write(unsigned char arg) {
		Write(&arg, sizeof(unsigned char));
	}

    inline void Write(short arg) {
		Write(&arg, sizeof(short));
	}

    inline void Write(unsigned short arg) {
		Write(&arg, sizeof(unsigned short));
	}

    inline void Write(long arg) {
		Write(&arg, sizeof(long));
	}

    inline void Write(unsigned long arg) {
		Write(&arg, sizeof(unsigned long));
	}

    inline void Write(const char *arg) {
		Write(arg, strlen(arg));
	}


    inline void Write(StreamByte & arg) {
		Write(arg.Data(), arg.Len());
	}

    void Clear() {
        read_pos_ = 0;
		len_ = 0;
    }

    void FreeReadBuffer() {
        if (read_pos_ > 0) {
            memmove(data_, data_ + read_pos_, len_ - read_pos_);
            len_ -= read_pos_;
            read_pos_ = 0;
        }
    }

private:
	inline void Initialize(size_t size) {
		data_ = static_cast<char *>(malloc(size));

		if (data_ == NULL) throw std::bad_alloc();

		res_size_ = size;
		Clear();
	}


	inline void ReallocCheck(size_t size) {
		if (res_size_ < size) {
			res_size_ = (size / 256 + 1) * 3 / 2 * 256;
			data_ = static_cast<char *>(realloc(data_, res_size_));

            if (data_ == NULL) {
                throw std::bad_alloc();
            }
		}
	}

protected:
	char *data_;
    size_t len_;
	size_t res_size_;
	size_t read_pos_;
};
*/

} //namespace base

#endif
