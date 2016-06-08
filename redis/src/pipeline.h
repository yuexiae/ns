#ifndef REDIS_SRC_COMMAND_H_
#define REDIS_SRC_COMMAND_H_


#include "base/buffer.h"
#include "redis/redis.h"
#include "redis/src/reply.h"
#include <vector>

namespace redis {

class CommandBuffer : public base::Buffer {
public:
    CommandBuffer() : count_() {}

    inline void PushCommand(const char *s) {
        PushRaw(s, strlen(s));
    }

    inline void PushRaw(const void *s, size_t l) {
        Put('$');
        Put(l);
        Put("\r\n", 2);
        Put(s, l);
        Put("\r\n", 2);

        ++count_;
    }

    inline void PushLongLong(long long i) {
        char buffer[21];
        size_t len = base::itoa::i64toa(i, buffer) - buffer;

        Put('$');
        Put(len);
        Put("\r\n", 2);
        Put(buffer, len);
        Put("\r\n", 2);

        ++count_;
    }

    inline void PushULongLong(long long i) {
        char buffer[20];
        size_t len = base::itoa::u64toa(i, buffer) - buffer;

        Put('$');
        Put(len);
        Put("\r\n", 2);
        Put(buffer, len);
        Put("\r\n", 2);

        ++count_;
    }

    inline size_t Count() { return count_; }

    inline void Clear() {
        Buffer::Clear();
        count_ = 0;
    }

private:
    size_t count_;
};

class PipelineBuffer : public base::Buffer {
public:
    PipelineBuffer() : count_() {}

    inline void PushCommand(const char *cmd) {
        if (command_.Count()) {
            Put('*');
            Put(command_.Count());
            Put("\r\n", 2);
            Put(command_);

            ++count_;
            command_.Clear();
        }

        command_.PushCommand(cmd);
    }

    inline void Push(Ref& v) {
        if (v.flags_ == Ref::kStringFlag) {
            command_.PushRaw(v.data_.s.str, v.data_.s.length);
        } else {
            if (v.flags_ == Ref::kSignedFlag) {
                command_.PushLongLong(v.data_.i);
            } else if (v.flags_ == Ref::kUnsignedFlag) {
                command_.PushULongLong(v.data_.u);
            } else {
                RedisThrow("invailed flags_");
            }
        }
    }

    size_t Finish() {
        if (command_.Count()) {
            Put('*');
            Put(command_.Count());
            Put("\r\n", 2);
            Put(command_);

            ++count_;
            command_.Clear();
        }

        return count_;
    }

    inline void Clear() {
        Buffer::Clear();
        count_ = 0;
    }

private:
   size_t count_;
   CommandBuffer command_;
};


} //namespace redis





#endif