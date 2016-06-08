#include "server/server_pch.h"

#include "server/ext/ns_ext.h"
#include "server/db/game_db.h"

class CNSPcTitleListFilter : public CNSPcTitleList {
public:
    BOOL DbAddFilter(unsigned short wTitleId) {
        CNSPcTitle *pPcTitle = CNSPcTitleParams::GetInstance()->GetTitle(wTitleId);
        if (pPcTitle) {
            if (this->IsFull() == 1) {
                return FALSE;
            }

            std::map<unsigned short, CNSPcTitle *>::iterator iter = this->m_mapTitle.find(wTitleId);
            if (iter != this->m_mapTitle.end()) {
                return TRUE;
            }

            this->m_mapTitle.insert(std::make_pair(wTitleId, pPcTitle));
            GameDb::GetSingleton()->DbTitleAdd(static_cast<CNSPcExt *>(this->m_pParent), wTitleId);
            this->m_pParent->SendSystemMessage(NS_MSG_TITLE_ADD, pPcTitle->m_szTitleName);
            return TRUE;
        }

        return FALSE;
    }
};



bool CNSPcTitleListFilterInit() {
    return CNSPcTitleList::_PatchDbAdd(&CNSPcTitleListFilter::DbAddFilter);
}