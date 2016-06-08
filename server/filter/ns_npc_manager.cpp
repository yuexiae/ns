#include "server/server_pch.h"

#include "server/ext/ns_ext.h"
#include "server/db/game_db.h"

class CNSNpcManagerFilter : public CNSNpcManager {
public:
    void ActionFilter() {
        return;
    }

    BOOL InitFilter() {
        this->Arrange();
        this->DBBlockLoad();
        CNSGuildExt::LoadGuildBase();
        this->Start();
        return TRUE;
    }

	void DBBlockLoadFilter() {
		GameUtil::Output("DBBlockLoad");

		if (!GameDb::GetSingleton()->DBBlockLoad(this)) {
			return;
		}

		this->m_dwSteamCoreCount = 0;
		memset(this->m_steamCoreArray, 0, sizeof(this->m_steamCoreArray));
		memset(this->m_dwRealmCastleCountArray, 0, sizeof(this->m_dwRealmCastleCountArray));

		CNSWorldManager *world_manager = CNSWorldManager::GetInstance();
		for (unsigned int i = 0; i < this->m_dwBlockObjectCount; ++i) {
			if (world_manager->IsRVRServer() && world_manager->m_bRVRServerMode) {
				if (!this->IsExistBlock(this->m_blockObjectArray[i].wNpcId, this->m_blockObjectArray[i].cell.x, this->m_blockObjectArray[i].cell.y)) {
					this->CallMob(
						this->m_blockObjectArray[i].wNpcId,
						this->m_blockObjectArray[i].cell.x,
						this->m_blockObjectArray[i].cell.y,
						0,
						this->m_blockObjectArray[i].wAngle,
						0);
				}
			} else {
				if (this->m_blockObjectArray[i].wNpcId < 0xD000 || this->m_blockObjectArray[i].wNpcId >= 0xD100) {
					if (this->m_blockObjectArray[i].wNpcId >= 0xD100 && this->m_blockObjectArray[i].wNpcId < 0xD200) {
						++this->m_dwRealmCastleCountArray[2];
					}
				} else {
					++this->m_dwRealmCastleCountArray[1];
				}
			}
		}
	}

	void DBBlockSaveFilter() {
		GameUtil::Output("DBBlockSave");

		CNSWorldManager *world_manager = CNSWorldManager::GetInstance();
		if (!world_manager->IsRVRServer() || !world_manager->m_bRVRServerMode) {
			return;
		}

		this->m_dwSteamCoreCount = 0;
		this->m_dwBlockObjectCount = 0;
		memset(this->m_steamCoreArray, 0, sizeof(this->m_steamCoreArray));
		memset(this->m_blockObjectArray, 0, sizeof(this->m_blockObjectArray));
		memset(this->m_dwRealmCastleCountArray, 0, sizeof(this->m_dwRealmCastleCountArray));


		CNSCriticalSection::Owner lock(this->m_cs);

		for (std::map<unsigned long, CNSNpc *>::iterator iter = this->m_mapNpc.begin();
			iter != this->m_mapNpc.end();
			++iter) {
				if (!iter->second->IsBlockSteamCore() && !iter->second->IsBlockDefense() && !iter->second->IsBlockLarge()) {
					continue;
				}

				if(iter->second->IsBlockSteamCore() && this->m_dwSteamCoreCount < 100) {
					if (iter->second->m_wNpcId < 53248 || iter->second->m_wNpcId >= 53504) {
						if (iter->second->m_wNpcId >= 53504 && iter->second->m_wNpcId < 53760) {
							++this->m_dwRealmCastleCountArray[2];
						}
					} else {
						++this->m_dwRealmCastleCountArray[1];
					}

					this->m_steamCoreArray[this->m_dwSteamCoreCount].wNpcId = iter->second->m_wNpcId;
					this->m_steamCoreArray[this->m_dwSteamCoreCount].wAngle = iter->second->m_wAngle;
					this->m_steamCoreArray[this->m_dwSteamCoreCount].cell = iter->second->m_cell;
					++this->m_dwSteamCoreCount;
				}

				this->m_blockObjectArray[this->m_dwBlockObjectCount].wNpcId = iter->second->m_wNpcId;
				this->m_blockObjectArray[this->m_dwBlockObjectCount].wAngle = iter->second->m_wAngle;
				this->m_blockObjectArray[this->m_dwBlockObjectCount].cell = iter->second->m_cell;
				++this->m_dwBlockObjectCount;
		}

		GameDb::GetSingleton()->DBBlockSave(this);
	}
};

bool CNSNpcManagerFilterInit() {
    return CNSNpcManager::_PatchInit(&CNSNpcManagerFilter::InitFilter)
     && CNSNpcManager::_PatchAction(&CNSNpcManagerFilter::ActionFilter)
     && CNSNpcManager::_PatchDBBlockLoad(&CNSNpcManagerFilter::DBBlockLoadFilter)
	 && CNSNpcManager::_PatchDBBlockSave(&CNSNpcManagerFilter::DBBlockSaveFilter);
}
