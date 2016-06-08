#include "redis/redis.h"
#include "redis/src/protocol.h"
#include "base/file_util.h"

namespace redis {

Connector::Connector() {
    protocol_ = new Protocol();
}


Connector::~Connector() {
    delete protocol_;
}

void Connector::Connect(const char *host, uint16_t port) {
    protocol_->Connect(host, port);
}


void Connector::PushCommand(const char *cmd) {
    protocol_->PushCommand(cmd);
}

void Connector::PushSeqment(const char *str, char seps) {
    const char *start = str;

	if (*str == seps) {
		++start;
	}

	while (*str) {
		if (*str == seps) {
			PushRaw(start, str - start);
			start = ++str;
		} else {
			++str;
		}
	}

	if (str != start) {
		PushRaw(start, str - start);
	}
}

void Connector::Push(Ref v) {
    protocol_->PushParameter(v);
}

size_t Connector::GetCommandCount() {
    return protocol_->GetCommandCount();
}

Reply Connector::GetReply() {
    GenericReply reply = protocol_->GetReply();
    if (reply.IsError()) {
        RedisThrow("reply err:'%s'", reply.GetString());
    }

    return *reinterpret_cast<Reply*>(&reply);
}

Reply Connector::GetAllReply() {
    return *reinterpret_cast<Reply*>(&protocol_->GetAllReply());
}

void Connector::auth(const char *password) {
    PushCommand("AUTH");
	Push(password);
    GetReply().CheckStatusOk();
}

void Connector::select(int dbid) {
    PushCommand("SELECT");
	Push(dbid);
	GetReply().CheckStatusOk();
}

void Connector::set(Ref k, Ref v) {
    PushCommand("SET");
	Push(k, v);
	GetReply().CheckStatusOk();
}

Reply Connector::get(Ref k) {
    PushCommand("GET");
	Push(k);
	return GetReply();
}

bool Connector::exists(Ref k) {
    PushCommand("EXISTS");
	Push(k);
	return GetReply().as<long long>() == 1;
}

bool Connector::del(Ref k) {
    PushCommand("DEL");
	Push(k);
	return GetReply().as<long long>() == 1;
}


bool Connector::hexists(Ref key, Ref field) {
	PushCommand("HEXISTS");
	Push(key, field);
	return GetReply().as<long long>() == 1;
}

bool Connector::hdel(Ref key, Ref field) {
	PushCommand("HDEL");
	Push(key, field);
	return GetReply().as<long long>() == 1;
}


bool Connector::hset(Ref key, Ref field, Ref value) {
	PushCommand("HSET");
	Push(key, field, value);
	return GetReply().as<long long>() == 1;
}

bool Connector::hsetnx(Ref key, Ref field, Ref value) {
	PushCommand("HSETNX");
	Push(key, field, value);
	return GetReply().as<long long>() == 1;
}

void Connector::hmset(Ref key, Ref field, Ref value, Ref field2, Ref value2) {
    PushCommand("HMSET");
	Push(key);
    Push(field, value);
    Push(field2, value2);
	GetReply().CheckStatusOk();
}

Reply Connector::hincrby(Ref key, Ref field, Ref increment) {
	PushCommand("HINCRBY");
	Push(key, field, increment);
	return GetReply();
}

Reply Connector::hget(Ref key, Ref field) {
	PushCommand("HGET");
	Push(key, field);
	return GetReply();
}

Reply Connector::hmget(Ref key, const char *fields) {
	PushCommand("HMGET");
	Push(key);
	PushSeqment(fields, ' ');
	return GetReply();
}

Reply Connector::hgetall(Ref key) {
	PushCommand("HGETALL");
	Push(key);
	return GetReply();
}

Reply Connector::hvals(Ref key) {
    PushCommand("HVALS");
	Push(key);
	return GetReply();
}

bool Connector::sadd(Ref key, Ref value) {
    PushCommand("SADD");
	Push(key, value);
	return GetReply().as<long long>() == 1;
}

bool Connector::srem(Ref key, Ref value) {
    PushCommand("SREM");
	Push(key, value);
	return GetReply().as<long long>() == 1;
}

long long Connector::lpush(Ref key, Ref value) {
	PushCommand("LPUSH");
	Push(key, value);
	return GetReply().as<long long>();
}

void Connector::script_load(const char *path, std::string &hash) {
	base::FileReader reader(path);
	if (!reader.IsSuccess()) {
		RedisThrow("can not load path:%s", path);
	}

	hash.assign(reader.sha1());

	PushCommand("SCRIPT");
	Push("EXISTS");
	Push(hash);

    if (GetReply()[0].as<long long>() == 0) {
		PushCommand("SCRIPT");
		Push("LOAD");
		Push(Ref(reader.Get(), reader.Size()));
		hash.assign(GetReply().GetString());
	}
}

Reply Connector::evalsha(std::string& hash, Ref arg) {
    PushCommand("EVALSHA");
	Push(hash.c_str());
	Push(0);
	Push(arg);
	return GetReply();
}

Reply Connector::evalsha(std::string& hash, Ref arg, Ref arg2) {
	PushCommand("EVALSHA");
	Push(hash.c_str());
	Push(0);
	Push(arg);
	Push(arg2);
	return GetReply();
}

Reply Connector::evalsha(std::string& hash, Ref arg, Ref arg2, Ref arg3) {
	PushCommand("EVALSHA");
	Push(hash.c_str());
	Push(0);
	Push(arg);
	Push(arg2);
    Push(arg3);
	return GetReply();
}

Reply Connector::evalsha(std::string& hash, Ref arg, Ref arg2, Ref arg3, Ref arg4) {
	PushCommand("EVALSHA");
	Push(hash.c_str());
	Push(0);
	Push(arg);
	Push(arg2);
    Push(arg3);
    Push(arg4);
	return GetReply();
}

Reply Connector::evalsha(std::string& hash, Ref arg, Ref arg2, Ref arg3, Ref arg4, Ref arg5) {
	PushCommand("EVALSHA");
	Push(hash.c_str());
	Push(0);
	Push(arg);
	Push(arg2);
    Push(arg3);
    Push(arg4);
    Push(arg5);
	return GetReply();
}


}