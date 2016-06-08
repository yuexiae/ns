#include "server/server_pch.h"

#include "server/ext/ns_world_manager_ext.h"


base::TimeElapseHigh CNSWorldManagerExt::m_PcProcessTime;
base::TimeElapseHigh CNSWorldManagerExt::m_NpcProcessTime;
base::TimeElapse CNSWorldManagerExt::m_DbProcessTime;