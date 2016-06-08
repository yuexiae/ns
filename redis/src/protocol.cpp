#include "redis/src/protocol.h"

#pragma warning (disable:4146)

typedef long long PORT_LONGLONG;
typedef unsigned long long PORT_ULONGLONG;

namespace redis {

Protocol::Protocol() : is_invalid_(false) {
}

void Protocol::Connect(const char *host, uint16_t port) {
    if (!socket_.Create(AF_INET, SOCK_STREAM, 0)) {
        RedisThrow("socket create error:%d", socket_.GetErrorCode()); 
    }

    if (!socket_.SetTCPKeepAlive(true, 60)) {
        RedisThrow("socket set keepalive error:%d", socket_.GetErrorCode()); 
    }

    if (!socket_.DisableNagle(true)) {
        RedisThrow("socket disable nagle error:%d", socket_.GetErrorCode()); 
    }

    if (!socket_.SetTimeOut(30)) {
        RedisThrow("socket set send timeout error:%d", socket_.GetErrorCode()); 
    }

    if (!socket_.Connect(host, port)) {
        RedisThrow("socket connect(%s, %u) error:%d", host, port, socket_.GetErrorCode()); 
    }
}

void Protocol::PushCommand(const char *cmd) {
	CheckInvalid();
    pipeline_.PushCommand(cmd);
}

void Protocol::PushParameter(Ref& v) {
	CheckInvalid();
    pipeline_.Push(v);
}

size_t Protocol::GetCommandCount() {
    return pipeline_.Finish();
}

void Protocol::Execute() {
    size_t count = pipeline_.Finish();
    if (count == 0) {
        RedisThrow("pipeline is nil");
    }

    reply_reader_.SetCount(count);

    if (socket_.Send(pipeline_.Data(), pipeline_.Len()) != pipeline_.Len()) {
        is_invalid_ = true;
        RedisThrow("send error(%d)", socket_.GetErrorCode());
    }

    pipeline_.Clear();

    reader_buffer_.Clear();
    while (true) {
        ReplyReader::Result result = reply_reader_.ProcessAll(reader_buffer_);

        if (result == ReplyReader::kStatusFinish) {
            break;
        } else if (result == ReplyReader::kStatusError) {
			 is_invalid_ = true;
             RedisThrow("protocol error");
        } else if (result == ReplyReader::kStatusPending) {
            char temp[1024*10];
            int n = socket_.Recv(temp, sizeof(temp));;
            if (n < 0) {
				is_invalid_ = true;
                RedisThrow("recv error(%d)", socket_.GetErrorCode());
            } else if (n == 0) {
				is_invalid_ = true;
                RedisThrow("server closed the connection");
            }

            reader_buffer_.Shirk();
            reader_buffer_.Put(temp, n);
        } else {
            ASSERT(NULL);
        }
    };
}

GenericReply Protocol::GetReply() {
	CheckInvalid();
	Execute();

    GenericReply reply = reply_reader_.Pop();
    switch (reply.GetType()) {
    case kDefaultType:
        RedisThrow("reply is nil");
    case kNullType:
        RedisThrow("reply is nil type");
    case kArrayType:
        if (reply.HasNull()) {
            RedisThrow("one of elements is nil");
        }
    }
    return reply;
}

GenericReply Protocol::GetAllReply() {
    CheckInvalid();
	Execute();
    return reply_reader_.PopAll();
}


void Protocol::CheckInvalid() {
	if (is_invalid_) {
		RedisThrow("protocol was invalid");
	}
}

}