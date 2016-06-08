#include "server/server_pch.h"

#include "server/ext/ns_pc_manager_ext.h"
#include "server/ext/ns_ext.h"

static unsigned int dwChannelGhostCheckTime = timeGetTime();
static unsigned int dwChannelCheckTime = timeGetTime();
static unsigned int dwReserveCheckTime = timeGetTime();
static unsigned int dwGuildSaveCheckTime = timeGetTime();
 
void CNSPcManagerExt::ActionNew() {
    CNSWorldManagerExt::m_PcProcessTime.Start();
    this->Process(timeGetTime());
    CNSWorldManagerExt::m_PcProcessTime.End();

    CNSWorldManagerExt::m_NpcProcessTime.Start();
    CNSNpcManager::GetInstance()->ProcessNew();
    CNSWorldManagerExt::m_NpcProcessTime.End();

    unsigned int dwTime = timeGetTime();
    if (dwChannelGhostCheckTime + 43200 * 1000 < dwTime) {
        this->ChannelGhostKiller();
        dwChannelGhostCheckTime = dwTime;
    }

    dwTime = timeGetTime();
    if (dwChannelCheckTime + 10 * 000 < dwTime) {
        this->CheckZoneChannel();
        dwChannelCheckTime = dwTime;
    }

    dwTime = timeGetTime();
    if (dwReserveCheckTime + 30 * 000 < dwTime) {
        CNSReserveManager::GetInstance()->Broadcast();
        dwReserveCheckTime = dwTime;
    }

    dwTime = timeGetTime();
    if (dwGuildSaveCheckTime + 300 * 1000 < dwTime) {
        this->GuildSaveAll();
        dwGuildSaveCheckTime = dwTime;
    }
}

void CNSPcManagerExt::SendDbQueueMessage() {
    CNSCriticalSection::Owner lock(this->m_csPc);
    for (std::map<unsigned long,CNSPc *>::iterator iter = this->m_mapPc.begin();
        iter != this->m_mapPc.end();
        ++iter) {
            if (iter->second->m_pSession != CNSPc::m_DummySession()) {
                iter->second->m_pSession->SendDbMessageQueue();
            }
    }
}