#ifndef SERVER_APPLICATION_H_
#define SERVER_APPLICATION_H_

#include "base/singleton.h"
#include <vector>

class Application : public base::Singleton<Application> {
public:
	void Initialize();
	
    void OnMain();

	void OnServerMain();
private:
	bool InitFunction();

	bool ModifyConfigFile(const char *region);

	bool ModifyLoginKey();

	bool ModifyConnectString();
};







#endif