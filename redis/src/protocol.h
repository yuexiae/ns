#ifndef REDIS_SRC_PROTOCOL_H_
#define REDIS_SRC_PROTOCOL_H_


#include "base/socket_ptr.h"
#include "redis/redis.h"
#include "redis/src/pipeline.h"
#include "redis/src/reply.h"

namespace redis {


class Protocol {
public:
    Protocol();

    void Connect(const char *host, uint16_t port);

    void PushCommand(const char *cmd);

    void PushParameter(Ref& v);

    size_t GetCommandCount();

    void Execute();

    GenericReply GetReply();

    GenericReply GetAllReply();

private:
	void CheckInvalid();

	bool is_invalid_;
    base::SocketPtr socket_;
    CommandBuffer command_;
    PipelineBuffer pipeline_;
    ReaderBuffer reader_buffer_;
    ReplyReader reply_reader_;
};




}


#endif