#include "server/server_pch.h"

#include "server/ext/ns_ext.h"
#include "server/db/game_db.h"


class CNSWareHouseFilter : public CNSWareHouse {
public:
    BOOL DBLoadFilter(int bGuildWareHouse) {
        this->m_bGuildWareHouse = bGuildWareHouse;
        if (this->m_bLoad == 1) {
            this->DeleteAll();
        }

        this->m_dwGold = 0;
        if (!this->m_bGuildWareHouse) {
            unsigned long dwGold;
            if (GameDb::GetSingleton()->DBWareHouseGoldLoad(this->m_pParent->m_nUserSeq, this->m_pParent->m_btRaceRegion, dwGold)) {
               this->m_dwGold = dwGold;
            } else {
                return FALSE;
            }
        }

        if (!GameDb::GetSingleton()->DBWareItemLoad(this)) {
            return FALSE;
        } else {
            this->m_bLoad = 1;
            return TRUE;
        }
    }

    void DBDeleteAllFilter();

    BOOL DBInHouseItemFilter(CNSItem *pItem) {
        if (pItem->m_nSeq == -1)
            return FALSE;

        if (this->m_bGuildWareHouse) {
            CNSObject::Owner<CNSGuild> guild = CNSObjectManager::GetInstance()->Get<CNSGuild>(CNSObject::ObjectType_Guild, this->m_pParent->m_dwGuildId);
            if (!guild) {
                return FALSE;
            }

            return GameDb::GetSingleton()->DBWareItemIn(pItem, guild->m_nDbSeq + 2000000000, this->m_pParent->m_nAliasSeq);
        } else {
            return GameDb::GetSingleton()->DBWareItemIn(pItem, this->m_pParent->m_nUserSeq, this->m_pParent->m_nAliasSeq);
        }
    }

    BOOL DBOutHouseItemFilter(CNSItem *pItem) {
        if (pItem->m_nSeq == -1)
            return FALSE;

        if (this->m_bGuildWareHouse) {
            CNSObject::Owner<CNSGuild> guild = CNSObjectManager::GetInstance()->Get<CNSGuild>(CNSObject::ObjectType_Guild, this->m_pParent->m_dwGuildId);
            if (!guild) {
                return FALSE;
            }

            return GameDb::GetSingleton()->DBWareItemOut(pItem, guild->m_nDbSeq + 2000000000, this->m_pParent->m_nAliasSeq);
        } else {
            return GameDb::GetSingleton()->DBWareItemOut(pItem, this->m_pParent->m_nUserSeq, this->m_pParent->m_nAliasSeq);
        }
    }

    static BOOL DBIncGoldFilter(int nUserSeq, unsigned long dwGold) {
        return GameDb::GetSingleton()->DBWareHouseGoldIncrment(nUserSeq, dwGold);
    }

    static BOOL DBDecGoldFilter(int nUserSeq, unsigned long dwGold) {
        return GameDb::GetSingleton()->DBWareHouseGoldDecrease(nUserSeq, dwGold);
    }

};

bool CNSWareHouseFilterInit() {
	return CNSWareHouse::_PatchDBLoad(&CNSWareHouseFilter::DBLoadFilter)
        && CNSWareHouse::_PatchDBInHouseItem(&CNSWareHouseFilter::DBInHouseItemFilter)
        && CNSWareHouse::_PatchDBOutHouseItem(&CNSWareHouseFilter::DBOutHouseItemFilter)
        && CNSWareHouse::_PatchDBIncGold(&CNSWareHouseFilter::DBIncGoldFilter)
        && CNSWareHouse::_PatchDBDecGold(&CNSWareHouseFilter::DBDecGoldFilter);
}
