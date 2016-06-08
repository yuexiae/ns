#include "server/server_pch.h"

#include "server/db/memory_db.h"
#include "server/game_util.h"
#include "redis/redis.h"

MemoryDb::MemoryDb() {
	connector_ = new redis::Connector();
	thread_id_ = 0;
}


MemoryDb::~MemoryDb() {
	if (connector_) {
		delete connector_;
	}
}

bool MemoryDb::Init(const char *host, unsigned short port, const char *password, int dbid) {
	try {
		connector_->Connect(host, port);
		connector_->auth(password);
		connector_->select(dbid);
		
	} catch (redis::Exception &ex) {
		LOGERROR("MemoryDb::Init error(%s)", ex.what());
		return false;
	}

	return true;
}


void MemoryDb::SetThreadId() {
	thread_id_ = GetCurrentThreadId();
}

bool MemoryDb::CheckThreadId() {
	return GetCurrentThreadId() == thread_id_;
}

redis::Connector & MemoryDb::GetConnector() {
	if (!CheckThreadId()) {
		LOGERROR("CheckThreadId failed(%u,%u)", thread_id_, GetCurrentThreadId());
	}

	return *connector_;
}