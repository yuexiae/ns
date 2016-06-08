#include "server/server_pch.h"

#include "server/ext/ns_ext.h"


class CNSSkillFilter : public CNSSkill {
public:
    BOOL OnSummoningFilter(CNSCharacter *pChar, unsigned long dwTime) {
        if (!pChar->IsPcClass()) {
            return FALSE;
        }

        unsigned short dwNpcId = 0;
        unsigned char btRaceRegion = static_cast<CNSPc *>(pChar)->GetRaceRegion();
        switch (this->m_wSkillId) {
        case 0xE01u:
            if (btRaceRegion == 1) {
                dwNpcId = this->m_btSkillLevel - 257;
            } else if ( btRaceRegion == 2) {
                dwNpcId = this->m_btSkillLevel - 209;
            } else {
                dwNpcId = this->m_btSkillLevel - 161;
            }
            break;
        case 0xE03u:
            if (btRaceRegion == 1) {
                dwNpcId = this->m_btSkillLevel - 241;
            } else if (btRaceRegion == 2) {
                dwNpcId = this->m_btSkillLevel - 193;
            } else {
                dwNpcId = this->m_btSkillLevel - 145;
            }
            break;
        case 0xE05u:
        case 0xE10u:
            if (btRaceRegion == 1) {
                dwNpcId = this->m_btSkillLevel - 225;
            } else if (btRaceRegion == 2) {
                dwNpcId = this->m_btSkillLevel - 177;
            } else {
                dwNpcId = this->m_btSkillLevel - 129;
            }
            break;
        case 0x814://add
            if (static_cast<CNSPc *>(pChar)->DBTameMobLoad()) {
                CNSObject::Owner<CNSNpc> pMob = static_cast<CNSPc *>(pChar)->PetGetMobObject();
                if (pMob) {
                    this->SendSkillUseMessage(pChar, pMob, 0, 0);
                    return TRUE;
                } else {
                    return FALSE;
                }
            } else {
                return FALSE;
            }
        default:
            break;
        }

        if (dwNpcId && pChar->GetLevel() >= 100 && this->m_btSkillLevel == 10) {
            ++dwNpcId;
        }

        CNSNpc *pNpc = static_cast<CNSPc *>(pChar)->PetSummoning(dwNpcId, this->m_wSkillId, this->m_btSkillLevel, this->GetDurationTime(0), dwTime);
        if (pNpc) {
            this->SendSkillUseMessage(pChar, pNpc, 0, 0);
            return TRUE;
        }

        return FALSE;
    }

    unsigned char GetLimitPcLevelFilter(CNSPc *pPc) {
        if (this->m_wSkillId >> 8 == 0xB3 && this->m_btSkillLevel == 0) {
            int nSpecialCount = 0;
            for (unsigned int i = 0; i < pPc->m_SkillList.GetMaxList(); ++i) {
                CNSSkill& pSkill = pPc->m_SkillList.GetSkill(i);
                if (pSkill.m_bUsed && pSkill.m_wSkillId >> 8 == 0xB3 && pSkill.m_btSkillLevel > 0) {
                    ++nSpecialCount;
                }
            }

            if (this->m_wSkillId == 0xB306) {
                return 255;
            }

            switch (nSpecialCount) {
            case 0:
                return 100;
            case 1:
                return 105;
            case 2:
                return 110;
            default:
                return 255;
            }
        }


        if (this->m_wSkillId > 0x1101) {
            if (this->m_wSkillId == 0x1105 || this->m_wSkillId == 0x1201 || this->m_wSkillId == 0x1206) {
                return 1;
            }
        } else {
            if (this->m_wSkillId == 0x1101) {
                return 1;
            }

            if ( this->m_wSkillId > 0x401) {
                if (this->m_wSkillId == 0x410) {
                    return 1;
                }
            } else if (this->m_wSkillId == 0x401 || this->m_wSkillId == 0x101 || this->m_wSkillId == 0x301) {
                return 1;
            }
        }

        if (this->m_btSkillLevel > 1) {
            return 10 * (this->m_btSkillLevel - 1) + 1;
        } else {
            return 1;
        }
    }

};



bool CNSSkillFilterInit() {
    return CNSSkill::_PatchOnSummoning(&CNSSkillFilter::OnSummoningFilter)//CNSSkill::_PatchOnBuff(&CNSSkillFilter::OnBuffFilter);
        && CNSSkill::_PatchGetLimitPcLevel(&CNSSkillFilter::GetLimitPcLevelFilter);
}



/*
    BOOL OnBuffFilter(CNSCharacter *pChar, CNSCharacter *pTarget, unsigned char btSkillOption, unsigned short wSkillValue, unsigned long dwTime) {
    if (!btSkillOption) {
    return FALSE;
    }

    if (pTarget->m_BuffList.IsEnable(CNSBuff::BuffType_SiegeWeapon) == TRUE)  {
    return TRUE;
    }

    if (pTarget->m_BuffList.IsEnable(CNSBuff::BuffType_PersonalSiegeWeapon) == TRUE) {
    return TRUE;
    }

    if (pTarget->m_BuffList.IsEnable(CNSBuff::BuffType_Pet) == TRUE) {
    return TRUE;
    }

    if (pTarget->m_BuffList.IsEnable(CNSBuff::BuffType_Dash) == TRUE
    || btSkillOption == CNSBuff::BuffType_Slow
    || btSkillOption == CNSBuff::BuffType_Stun
    || btSkillOption == CNSBuff::BuffType_Root
    || btSkillOption == CNSBuff::BuffType_Sleep) {
    return TRUE;
    }

    CNSPc *pPc = NULL;
    switch ( btSkillOption )
    {
    case CNSBuff::BuffType_ArmorBreak: {
    CNSPc *pPc = dynamic_cast<CNSPc *>(pChar);
    if (pPc && (pPc->GetJob() == 1 || pPc->GetJob() == 2 || pPc->GetJob() == 3)) {
    wSkillValue = floor(wSkillValue * 1.2);
    }
    break;
    }
    case CNSBuff::BuffType_Clarity: {
    if (pChar->GetType() != 1 || this->m_wSkillId == 1542 || this->m_wSkillId == 1547) {
    break;
    }

    bool bClarityFlag = TRUE;
    std::vector<CNSObject *> vectorObject;
    pChar->GetVrMap()->FieldInfo(pChar, 0x64u, CNSObject::ObjectType_Mob, vectorObject);
    pChar->GetVrMap()->FieldInfoPc(pChar, 0x64u, vectorObject);
    for (int _Pos = 0; _Pos < vectorObject.size(); ++_Pos ) {
    if (static_cast<CNSCharacter *>(vectorObject[_Pos])->GetRealm() != pChar->GetRealm()) {
    bClarityFlag = 0;
    }
    vectorObject[_Pos]->DecRefCount();
    }

    if (!bClarityFlag) {
    return FALSE;
    }
    break;
    }
    case CNSBuff::BuffType_RedPowder: {
    CNSPc *pPc = dynamic_cast<CNSPc *>(pChar);
    if (!pPc || pPc->ItemUse(0x5090u)) {
    break;
    }

    pPc->SendCenterMessage(82, NS_MSG_SKILL_NEED_REDPOWDER);
    return FALSE;
    }
    case CNSBuff::BuffType_CrushDivision: {
    CNSPc *pPc = dynamic_cast<CNSPc *>(pChar);
    if (!pPc) {
    break;
    }

    if (pPc->IsPartyEnableMember() == TRUE) {
    CNSPcParty *pParty = (CNSPcParty *)CNSObjectManager::GetInstance()->_GetObjectA(CNSObject::ObjectType_Party, pPc->GetPartyId());
    if (pParty) {
    if (pParty->GetMemberBuffValue(CNSBuff::BuffType_CrushDivision) > 0) {
    pPc->SendCenterMessage(82, NS_MSG_USE_ALREADY);
    pParty->DecRefCount();
    return FALSE;
    }
    pParty->DecRefCount();

    CNSPc *v40 = dynamic_cast<CNSPc *>(pTarget);
    if (v40) {
    if (pPc->GetPartyId() == v40->GetPartyId()) {
    break;
    }
    pPc->SendCenterMessage(82, NS_MSG_SKILL_NOT_PARTY);
    } else {
    pPc->SendCenterMessage(82, NS_MSG_SKILL_NOT_PARTY);
    }
    } else {
    pPc->SendCenterMessage(82, NS_MSG_SKILL_NOT_PARTY);
    }
    } else {
    pPc->SendCenterMessage(82, NS_MSG_SKILL_NOT_PARTY);
    }
    return FALSE;
    }
    case CNSBuff::BuffType_AspecVolition: {
    pPc = dynamic_cast<CNSPc *>(pChar);
    if (!pPc) {
    break;
    }

    if (pTarget->m_BuffList.Add(pChar->m_dwObjectId, CNSBuff::BuffType_Stun, this->m_wSkillId, this->m_btSkillLevel, wSkillValue, this->GetDurationTime(0), dwTime, 0)) {
    break;
    }
    return FALSE;
    }
    case CNSBuff::BuffType_WeaveIllusion: {
    if (100 - (3 * (pTarget->GetLevel() - 10 * this->m_btSkillLevel) + 20) >= rand() % 100) {
    break;
    }
    return FALSE;
    }
    case CNSBuff::BuffType_Stun: {
    unsigned short nRecoveryStun = pTarget->m_BuffList.GetBuffValue(CNSBuff::BuffType_RecoveryStun);
    if (nRecoveryStun > 0) {
    unsigned short wHitHeal = pTarget->HitHeal(pTarget, pTarget->m_dwMaxHp * nRecoveryStun / 0x64, 1, 0);
    if (wHitHeal > 0) {
    pTarget->SendStatusChangeMessage(0,  wHitHeal);
    pTarget->SendRecoveryMessage(0, 0);
    }
    }
    break;
    }
    case CNSBuff::BuffType_Kilgician: {
    if (this->m_wSkillId != 0xA1D2) {
    break;
    }
    if (100 - (3 * (pTarget->GetLevel() - 10 * this->m_btSkillLevel) + 20) < rand() % 100)
    return FALSE;
    if (pTarget->GetType() == CNSObject::ObjectType_Pc)
    return FALSE;
    if (pTarget->GetType() != CNSObject::ObjectType_Mob)
    return FALSE;
    if (static_cast<CNSNpc *>(pTarget)->IsBoss() == TRUE)
    return FALSE;

    break;
    }
    case CNSBuff::BuffType_DeathHealing: {
    if (pTarget->GetType() != CNSObject::ObjectType_Mob || static_cast<CNSNpc *>(pTarget)->IsBoss() != TRUE) {
    break;
    }
    pPc = dynamic_cast<CNSPc *>(pChar);
    if (pPc) {
    pPc->SendCenterMessage(82, NS_MSG_NOT_TARGET);
    }
    return FALSE;
    }
    default:
    break;
    }

    int v78 = 12345678;

    return TRUE;
    }*/
    