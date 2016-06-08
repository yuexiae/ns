#include "server/server_pch.h"

#include "server/ext/ns_ext.h"


bool CNSNpcStateMoveExt::GetPetPickDestination(NSPOINT2& cell) {
    //unfinished
    if (!this->m_pParent->IsPet()) {
        return false;
    }

    if (GetCurrentThreadId() != CNSDbManager::GetInstance()->m_dwThread) {
        LOGERROR("GetCurrentThreadId() == CNSDbManager::GetInstance()->m_dwThread");
        return false;
    }

    CNSObject::Owner<CNSPcExt> pPc = CNSObjectManagerExt::GetInstance()->Get<CNSPcExt>(this->m_pParent->m_dwLeaderObjectId);

    if (pPc == NULL) {
		return false;
    }

	cell.x = 0;
	cell.y = 0;


	std::vector<CNSObject *> vectorObject;
	vectorObject.reserve(100);

	pPc->GetVrMap()->FieldInfo(pPc, 300, CNSObject::ObjectType_Mob, vectorObject);
	pPc->GetVrMap()->FieldInfo(pPc, 300, CNSObject::ObjectType_Npc, vectorObject);

    float fMinLength = 301.0f;
	for (std::vector<CNSObject *>::iterator iter = vectorObject.begin();
		iter != vectorObject.end(); ++iter) {
		CNSNpcExt *pNpc = static_cast<CNSNpcExt *>(*iter);

		if (pNpc->IsDead() 
			&& !pNpc->m_bPetPickFlag
			&& pNpc->m_Inven.m_dwCount > 0 
			&& pNpc->ItemCheckLootOwner(pPc->m_szUserAlias)) {
			float length = NSPOINT2::GetLength(pNpc->m_cell, this->m_pParent->m_cell);
			if (length < 15) {
                pPc->ItemPickupAll(pNpc);
                pNpc->m_bPetPickFlag = true;
			} else if (length < fMinLength) {
				cell = pNpc->m_cell;
				fMinLength = length;
			}
		}

		pNpc->DecRefCount();
	}

	if (cell.x != 0 && cell.y != 0) {
		return true;
	}

	return false;
}
