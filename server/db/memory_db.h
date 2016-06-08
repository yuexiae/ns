#ifndef SERVER_DB_MEMORY_DB_H_
#define SERVER_DB_MEMORY_DB_H_


namespace redis {
class Connector;
}

class MemoryDb {
public:
	MemoryDb();

	~MemoryDb();

	bool Init(const char *host, unsigned short port,
		const char *password, int dbid);

	void SetThreadId();

	bool CheckThreadId();

	redis::Connector & GetConnector();

protected:
	redis::Connector *connector_;
	unsigned int thread_id_;
};



#endif