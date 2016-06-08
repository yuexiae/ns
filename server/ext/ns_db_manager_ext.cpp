#include "server/server_pch.h"

#include "server/ext/ns_db_manager_ext.h"

base::WaitableEvent CNSDbManagerExt::m_WaitableEvent(false, false);
