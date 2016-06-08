#ifndef CLIENT_APPLICACTION_H_
#define CLIENT_APPLICACTION_H_


#include "base/singleton.h"


class Application : public base::Singleton<Application> {
public:
    void Initialize();

    void OnMain();

    void PatchClient();
};







#endif