#ifndef SERVER_EXT_NS_WORLD_MANAGER_EXT_H_
#define SERVER_EXT_NS_WORLD_MANAGER_EXT_H_

#include "ns_header/ns.h"
#include "base/util.h"

class CNSWorldManagerExt : public CNSWorldManager {
public:
    static base::TimeElapseHigh m_PcProcessTime;
    static base::TimeElapseHigh m_NpcProcessTime;
    static base::TimeElapse m_DbProcessTime;
};

#endif