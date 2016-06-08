#include "server/server_pch.h"

#include "server/ext/ns_npc_manager_ext.h"
#include "server/ext/ns_ext.h"


void CNSNpcManagerExt::ProcessNew() {
    static std::vector<CNSNpcExt *> singleNpc;
    static std::vector<CNSNpcExt *> doubleNpc;

    if (singleNpc.empty() && doubleNpc.empty()) {
        CNSCriticalSection::Owner lock(this->m_cs);
        for (std::map<unsigned long, CNSNpc *>::iterator iter = m_mapNpc.begin();
            iter != m_mapNpc.end();
            ++iter) {
                if (iter->second->m_dwObjectId % 2) {
                    doubleNpc.push_back(static_cast<CNSNpcExt *>(iter->second));
                } else {
                    singleNpc.push_back(static_cast<CNSNpcExt *>(iter->second));
                }
        }
    }

    if (!singleNpc.empty()) {
        for (size_t i = 0; i < singleNpc.size(); ++i) {
            singleNpc[i]->ActionNew();
            if (singleNpc[i]->m_bDelete) {
                CNSCriticalSection::Owner lock(this->m_cs);
                m_mapNpc.erase(singleNpc[i]->m_dwObjectId);
                singleNpc[i]->DecRefCount(); 
            }
        }
        singleNpc.clear();
    } else if (!doubleNpc.empty()) {
        for (size_t i = 0; i < doubleNpc.size(); ++i) {
            doubleNpc[i]->ActionNew();
            if (doubleNpc[i]->m_bDelete) {
                CNSCriticalSection::Owner lock(this->m_cs);
                m_mapNpc.erase(doubleNpc[i]->m_dwObjectId);
                doubleNpc[i]->DecRefCount(); 
            }
        }
        doubleNpc.clear();
    }


	++this->m_dwTickCounter;
}

void CNSNpcManagerExt::ActionNew() {
    static unsigned int dwBlockSaveTime = timeGetTime();

    unsigned int dwTime = timeGetTime();

    if (dwBlockSaveTime + 60000 * 5 < dwTime)  {
        this->DBBlockSave();

        CNSWorldManager *pWorldManager = CNSWorldManager::GetInstance();

        if (pWorldManager->m_bRVRStart) {
            pWorldManager->DBFortressSave(0);
        }

        if (!pWorldManager->IsRVRServer() || !pWorldManager->m_bRVRServerMode) {
            this->DBBlockLoad();
        }

        dwBlockSaveTime = dwTime;
    }
}