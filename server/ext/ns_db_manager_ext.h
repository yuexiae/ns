#ifndef SERVER_EXT_NS_DB_MANAGER_EXT_H_
#define SERVER_EXT_NS_DB_MANAGER_EXT_H_

#include "ns_header/ns.h"
#include "base/waitable_event.h"

class CNSDbManagerExt : public CNSDbManager {
public:
    static base::WaitableEvent m_WaitableEvent;
};









#endif