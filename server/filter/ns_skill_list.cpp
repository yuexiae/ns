#include "server/server_pch.h"

#include "server/ext/ns_ext.h"



class CNSSkillListFilter : public CNSSkillList {
public:
    BOOL DBSkillListBuildFilter(unsigned char btRaceRegion, unsigned char btJob) {
        struct _JobSkillTable {
        public:
            unsigned char btRaceRegion;//this+0x0
            unsigned char btJob;//this+0x1
            unsigned short wSkillId[0x78];//this+0x2
        };

        /*
        1.remove mythic ocean
        1.remove mythic force
        */
        static _JobSkillTable JobSkillTable[0x24] = {
            { 1, 1, { 0x101, 0x110, 0x103, 0xF01, 0xB101u, 0xB102u, 0xB103u, 0xB104u, 0xB201u, 0xB202u, 0xB203u, 0xB204u, 0xB205u, 0xB206u, 0xB301u, 0xB302u, 0xB303u, 0xB304u, 0xB305u, 0xB306u, 0xB307u, 0xB308u, 0xB309u, 0xB30Au } },
            { 1, 2, { 0x111, 0x112, 0x107, 0xB10, 0xB02, 0xB12, 0xB11, 0xB05, 0x1301, 0x1302, 0x1303, 0x1304, 0x1305, 0x201, 0x210, 0x211 } },
            { 1, 3, { 0x111, 0x112, 0x107, 0x201, 0x203, 0x207, 0x205, 0x206, 0x212, 0xE01, 0xE02, 0xE03, 0xE04, 0xA01, 0xA02, 0xA03 } },

            { 1, 33, { 0x410, 0x413, 0x412, 0xF01, 0xB101u, 0xB102u, 0xB103u, 0xB104u, 0xB201u, 0xB202u, 0xB203u, 0xB204u, 0xB205u, 0xB206u, 0xB301u, 0xB302u, 0xB303u, 0xB304u, 0xB305u, 0xB306u, 0xB307u, 0xB308u, 0xB309u, 0xB30Au } },
            { 1, 34, { 0x411, 0x414, 0x415, 0x416, 0x417, 0x501, 0x502, 0x503, 0x504, 0x505, 0x506, 0x507, 0x603, 0x605, 0x606 } },
            { 1, 35, { 0xE01, 0xE02, 0xE03, 0xE04, 0xE10, 0xA01, 0xA02, 0xA03, 0xA04, 0xA05, 0xA06, 0x601, 0x604, 0x602, 0x60B, 0x608 } },

            { 1, 65, { 0x301, 0x310, 0x303, 0xF01, 0xB101u, 0xB102u, 0xB103u, 0xB104u, 0xB201u, 0xB202u, 0xB203u, 0xB204u, 0xB205u, 0xB206u,0xB301u, 0xB302u, 0xB303u, 0xB304u, 0xB305u, 0xB306u, 0xB307u, 0xB308u, 0xB309u, 0xB30Au } },
            { 1, 67, { 0x311, 0x305, 0x312, 0x1101, 0x1102, 0x1103, 0x1104, 0x1105, 0x1106, 0x1107, 0x1001, 0x1002, 0x1003, 0x1004, 0x201, 0x210 } },
            { 1, 66, { 0x201, 0x210, 0x1001, 0x1002, 0x1003, 0x1004, 0x1005, 0x1006, 0x1201, 0x1202, 0x1203, 0x1204, 0x1205, 0x1206, 0x1207, 0x1208 } },

            { 1, 97, { 0x301, 0x310, 0x303, 0xF01, 0xB101u, 0xB102u, 0xB103u, 0xB104u, 0xB201u, 0xB202u, 0xB203u, 0xB204u, 0xB205u, 0xB206u, 0xB301u, 0xB302u, 0xB303u, 0xB304u, 0xB305u, 0xB306u, 0xB307u, 0xB308u, 0xB309u, 0xB30Au } },
            { 1, 98, { 0x311, 0x305, 0x312, 0x1500, 0x1501, 0x1502, 0x1503, 0x1504, 0x801, 0x806, 0x810, 0x811, 0x804, 0x813, 0x603, 0x60A } },
            { 1, 99, { 0x311, 0x305, 0x312, 0x1500, 0x1501, 0x1401, 0x1402, 0x1403, 0x1404, 0x1405, 0x1406, 0x910, 0x902, 0x911, 0x904, 0x905 } },

            { 2, 1, { 0x101, 0x102, 0x103, 0xB101u, 0xB102u, 0xB103u, 0xB104u, 0xB201u, 0xB202u, 0xB203u, 0xB204u, 0xB205u, 0xB206u, 0xB301u, 0xB302u, 0xB303u, 0xB304u, 0xB305u, 0xB306u, 0xB307u, 0xB308u, 0xB309u, 0xB30Au } },
            { 2, 2, { 0x104, 0x105, 0x107, 0x701, 0x702, 0x703, 0x704, 0x705, 0xB01, 0xB02, 0xB04, 0xB03, 0xB05, 0x201, 0x202, 0x207 } },
            { 2, 3, { 0x104, 0x105, 0x107, 0x202, 0x203, 0x204, 0x205, 0x206, 0x208, 0xA01, 0xA02, 0xA03, 0x601, 0x607, 0x608, 0x609 } },

            { 2, 33, { 0x401, 0x404, 0x403, 0xB101u, 0xB102u, 0xB103u, 0xB104u, 0xB201u, 0xB202u, 0xB203u, 0xB204u, 0xB205u, 0xB206u, 0xB301u, 0xB302u, 0xB303u, 0xB304u, 0xB305u, 0xB306u, 0xB307u, 0xB308u, 0xB309u, 0xB30Au } },
            { 2, 34, { 0x402, 0x405, 0x406, 0x407, 0x408, 0x501, 0x502, 0x503, 0x504, 0x505, 0x506, 0x507, 0x603, 0x605, 0x606 } },
            { 2, 35, { 0xA01, 0xA02, 0xA03, 0xA04, 0xA05, 0xA06, 0x601, 0x604, 0x602, 0x60B, 0x608, 0xE01, 0xE02, 0xE03, 0xE04, 0xE05 } },

            { 2, 65, { 0x301, 0x302, 0x303, 0xB101u, 0xB102u, 0xB103u, 0xB104u, 0xB201u, 0xB202u, 0xB203u, 0xB204u, 0xB205u, 0xB206u, 0xB301u, 0xB302u, 0xB303u, 0xB304u, 0xB305u, 0xB306u, 0xB307u, 0xB308u, 0xB309u, 0xB30Au } },
            { 2, 67, { 0x304, 0x305, 0x306, 0x1101, 0x1102, 0x1103, 0x1104, 0x1105, 0x1106, 0x1107, 0x1001, 0x1002, 0x1003, 0x1004, 0x201, 0x202 } },
            { 2, 66, { 0x1201, 0x1202, 0x1203, 0x1204, 0x1205, 0x1206, 0x1207, 0x1208, 0x1001, 0x1002, 0x1003, 0x1004, 0x1005, 0x1006, 0x201, 0x202 } },

            { 2, 97, { 0x301, 0x302, 0x303, 0xB101u, 0xB102u, 0xB103u, 0xB104u, 0xB201u, 0xB202u, 0xB203u, 0xB204u, 0xB205u, 0xB206u, 0xB301u, 0xB302u, 0xB303u, 0xB304u, 0xB305u, 0xB306u, 0xB307u, 0xB308u, 0xB309u, 0xB30Au } },
            { 2, 98, { 0x304, 0x305, 0x306, 0x801, 0x806, 0x802, 0x803, 0x804, 0x805, 0xC01, 0xC02, 0xC03, 0xC04, 0xC05, 0x603, 0x60A } },
            { 2, 99, { 0x304, 0x305, 0x306, 0x901, 0x902, 0x903, 0x904, 0x905, 0xC01, 0xC02, 0xD01, 0xD02, 0xD03, 0xD04, 0xD05, 0xD06 } },

            { 3, 1, { 0x101, 0x102, 0x103 } },
            { 3, 2, { 0x104, 0x105, 0x107, 0x701, 0x702, 0x703, 0x704, 0x705, 0xB01, 0xB02, 0xB04, 0xB03, 0xB05, 0x201, 0x202, 0x207 } },
            { 3, 3, { 0x104, 0x105, 0x107, 0x202, 0x203, 0x204, 0x205, 0x206, 0x208, 0xA01, 0xA02, 0xA03, 0x601, 0x607, 0x608, 0x609 } },
            { 3, 33, { 0x401, 0x404, 0x403 } },
            { 3, 34, { 0x402, 0x405, 0x406, 0x407, 0x408, 0x501, 0x502, 0x503, 0x504, 0x505, 0x506, 0x603, 0x605, 0x606 } },
            { 3, 35, { 0xA01, 0xA02, 0xA03, 0xA04, 0xA05, 0x601, 0x604, 0x602, 0x605, 0x608, 0xE01, 0xE02, 0xE03, 0xE04 } },
            { 3, 65, { 0x301, 0x302, 0x303 } },
            { 3, 67, { 0x304, 0x305, 0x306, 0x1101, 0x1102, 0x1103, 0x1104, 0x1105, 0x1106, 0x1107, 0x1001, 0x1002, 0x1003 } },
            { 3, 66, { 0x1201, 0x1202, 0x1203, 0x1204, 0x1205, 0x1206, 0x1207, 0x1208, 0x1001, 0x1002, 0x1003, 0x1004, 0x1005, 0x1006, 0x201, 0x202 } },
            { 3, 97, { 0x301, 0x302, 0x303 } },
            { 3, 98, { 0x304, 0x305, 0x306, 0x801, 0x806, 0x802, 0x803, 0x804, 0x805, 0xC01, 0xC02, 0xC03, 0xC04, 0xC05, 0x603, 0x60A } },
            { 3, 99, { 0x304, 0x305, 0x306, 0x903, 0x902, 0x901, 0x904, 0x905, 0xD01, 0xD02, 0xD03, 0xD04, 0xD05, 0xD06 } }
        };

        CNSPc *pPc = dynamic_cast<CNSPc *>(this->m_pChar);
        if (pPc == NULL) {
            return FALSE;
        }

        for (int i = 0; i < 0x24; ++i) {
            if (JobSkillTable[i].btRaceRegion == btRaceRegion && JobSkillTable[i].btJob == btJob)  {
                for (unsigned int j = 0; j < this->GetMaxList() && JobSkillTable[i].wSkillId[j]; ++j) {
                    CNSSkill *pSkill = this->Add(btRaceRegion, btJob, JobSkillTable[i].wSkillId[j], 0, 0);
                    if (pSkill == NULL){
                        GameUtil::Output("Error: CNSSkillList::DBSkillListBuildSkill{Add(Job=0x%x, SkillId=0x%04x)}\n", btJob, JobSkillTable[i].wSkillId[j]);
                        return FALSE;
                    }
                    pPc->DBSkillInsert(pSkill);
                }

                return TRUE;
            }
        }

        GameUtil::Output("Error: CNSSkillList::DBSkillListBuildSkill{Find(Region=%d, Job=0x%x)}\n", btRaceRegion, btJob);
        return FALSE;
    }

    BOOL SkillDefaultListFilter() {
        CNSPc *pPc = dynamic_cast<CNSPc *>(this->m_pChar);
        if (!pPc) {
            return FALSE;
        }

        if (pPc->m_btRaceRegion == 2) {
            if (pPc->m_btJob == 34) {
                if (!this->Get(0x507u)) {
                    CNSSkill *pSkill = this->Add(pPc->m_btRaceRegion, pPc->m_btJob, 0x507u, 0, 0);
                    if (pSkill) {
                        pPc->DBSkillInsert(pSkill);
                    }
                }
            } else if (pPc->m_btJob == 67 && !this->Get(0x1004u)) {
                CNSSkill *pSkilla = this->Add(pPc->m_btRaceRegion, pPc->m_btJob, 0x1004u, 0, 0);
                if (pSkilla) {
                    pPc->DBSkillInsert(pSkilla);
                }
            }
        }

        this->Add(pPc->m_btRaceRegion, pPc->m_btJob, 0xF001u, 0, 0);
        this->Add(pPc->m_btRaceRegion, pPc->m_btJob, 0xF003u, 0, 0);
        this->Add(pPc->m_btRaceRegion, pPc->m_btJob, 0xF004u, 0, 0);
        this->Add(pPc->m_btRaceRegion, pPc->m_btJob, 0xF002u, 0, 0);
        this->Add(pPc->m_btRaceRegion, pPc->m_btJob, 0xF005u, 0, 0);
        //this->Add(pPc->m_btRaceRegion, pPc->m_btJob, 0xF006u, 0, 0);
        this->Add(pPc->m_btRaceRegion, pPc->m_btJob, 0xF082u, 0, 0);
        this->Add(pPc->m_btRaceRegion, pPc->m_btJob, 0xF083u, 0, 0);
        this->Add(pPc->m_btRaceRegion, pPc->m_btJob, 0xF085u, 0, 0);
        this->Add(pPc->m_btRaceRegion, pPc->m_btJob, 0xF101u, 0, 0);
        this->Add(pPc->m_btRaceRegion, pPc->m_btJob, 0xF102u, 0, 0);
        this->Add(pPc->m_btRaceRegion, pPc->m_btJob, 0xF103u, 0, 0);
        this->Add(pPc->m_btRaceRegion, pPc->m_btJob, 0xF104u, 0, 0);
        this->Add(pPc->m_btRaceRegion, pPc->m_btJob, 0xF105u, 0, 0);
        this->Add(pPc->m_btRaceRegion, pPc->m_btJob, 0xF106u, 0, 0);
        this->Add(pPc->m_btRaceRegion, pPc->m_btJob, 0xF107u, 0, 0);
        this->Add(pPc->m_btRaceRegion, pPc->m_btJob, 0xF108u, 0, 0);
        this->Add(pPc->m_btRaceRegion, pPc->m_btJob, 0xF109u, 0, 0);
        this->Add(pPc->m_btRaceRegion, pPc->m_btJob, 0xF10Au, 0, 0);
        this->Add(pPc->m_btRaceRegion, pPc->m_btJob, 0xF10Bu, 0, 0);
        this->Add(pPc->m_btRaceRegion, pPc->m_btJob, 0xF10Cu, 0, 0);
        this->Add(pPc->m_btRaceRegion, pPc->m_btJob, 0xF10Du, 0, 0);
        this->Add(pPc->m_btRaceRegion, pPc->m_btJob, 0xF10Eu, 0, 0);
        this->Add(pPc->m_btRaceRegion, pPc->m_btJob, 0xF10Fu, 0, 0);
        this->Add(pPc->m_btRaceRegion, pPc->m_btJob, 0xF110u, 0, 0);
        this->Add(pPc->m_btRaceRegion, pPc->m_btJob, 0xF111u, 0, 0);
        this->Add(pPc->m_btRaceRegion, pPc->m_btJob, 0xF112u, 0, 0);
        this->Add(pPc->m_btRaceRegion, pPc->m_btJob, 0xF113u, 0, 0);
        this->Add(pPc->m_btRaceRegion, pPc->m_btJob, 0xF114u, 0, 0);
        this->Add(pPc->m_btRaceRegion, pPc->m_btJob, 0xF115u, 0, 0);
        this->Add(pPc->m_btRaceRegion, pPc->m_btJob, 0xF116u, 0, 0);
        this->Add(pPc->m_btRaceRegion, pPc->m_btJob, 0xF117u, 0, 0);
        this->Add(pPc->m_btRaceRegion, pPc->m_btJob, 0xF118u, 0, 0);
        this->Add(pPc->m_btRaceRegion, pPc->m_btJob, 0xF119u, 0, 0);
        this->Add(pPc->m_btRaceRegion, pPc->m_btJob, 0xF11Au, 0, 0);
        this->Add(pPc->m_btRaceRegion, pPc->m_btJob, 0xF203u, 1, 0);

        if (pPc->m_btRaceRegion == 2) {
            this->Add(pPc->m_btRaceRegion, pPc->m_btJob, 0xF204u, 1, 0);
        }

        this->Add(pPc->m_btRaceRegion, pPc->m_btJob, 0xF6A0u, 1, 0);
        this->Add(pPc->m_btRaceRegion, pPc->m_btJob, 0xF6A1u, 1, 0);

        if (pPc->m_SkillList.Get(0xF520u)) {
            this->Add(pPc->m_btRaceRegion, pPc->m_btJob, 0xF6B0u, 1, 0);
        } else if (pPc->m_SkillList.Get(0xF540u)) {
            this->Add(pPc->m_btRaceRegion, pPc->m_btJob, 0xF6B1u, 1, 0);
        } else if (pPc->m_SkillList.Get(0xF560u)) {
            this->Add(pPc->m_btRaceRegion, pPc->m_btJob, 0xF6B2u, 1, 0);
        }

        this->SetRaceAbility(pPc);

        if (pPc->m_btJob == 98) {
			this->Add(pPc->m_btRaceRegion, pPc->m_btJob, 0x814, 0, 0); //not impl
		}

        return TRUE;
    }
    BOOL StudyFilter(unsigned short wSkillId) {
        CNSPc *pPc = dynamic_cast<CNSPc *>(this->m_pChar);
        if (!pPc || !wSkillId) {
            return FALSE;
        }

        CNSSkill *pSkill = NULL;
        for (unsigned long i = 0; i < this->GetMaxList(); ++i) {
            CNSSkill& pTmpSkill = this->GetSkill(i);
            if (pTmpSkill.m_bUsed) {
                if (pTmpSkill.m_wSkillId == wSkillId) {
                    pSkill = &pTmpSkill;
                    break;
                }

                //wPrevSkillId = pTmpSkill->m_wSkillId;
                //btPrevSkillLevel = pTmpSkill->m_btSkillLevel;
            }
        }

        if (!pSkill || pSkill->m_btSkillLevel >= 10) {
            return FALSE;
        }

        if (pSkill->m_nDbSeq <= 0 || pSkill->IsSteamAbility() == TRUE) {
            pPc->SendSystemMessage(NS_MSG_SKILL_ERROR_LEVELUP);
            return FALSE;
        }


        if (pSkill->IsPassive() == TRUE && pSkill->m_wSkillId != 2308 && pSkill->m_btSkillLevel) {
            pPc->SendSystemMessage(NS_MSG_SKILL_ERROR_LEVELUP);
            return FALSE;
        } else if (pSkill->IsMastery() == TRUE) {
            pPc->SendSystemMessage(NS_MSG_SKILL_ERROR_LEVELUP);
            return FALSE;
        } else if (pSkill->IsAttrib() == TRUE) {
            pPc->SendSystemMessage(NS_MSG_SKILL_ERROR_LEVELUP);
            return FALSE;
        } else { //} else if (pSkill->IsSpecialActive() != TRUE || pSkill->m_btSkillLevel) {
            if (pSkill->m_btLimitLevel <= pPc->GetLevel())  {
                if (pSkill->GetLimitPcLevel(pPc) <= pPc->GetLevel()) {
                    if (pSkill->IsMythic() || pPc->m_btSp >= 1) {
                        if (pSkill->GetUseSkillExpPoint(0) <= pPc->GetSkillExp()) {
                            if (!pSkill->IsMythic()) {
                                --pPc->m_btSp;
                                ++pPc->m_wLogSp;
                            }

                            pPc->UseSkillExpPoint(pSkill->GetUseSkillExpPoint(0));
                            ++pSkill->m_btSkillLevel;
                            pSkill->m_wSkillExp = 0;
                            pSkill->m_wSkillNextExp = 0;
                            //pSkill->m_dwLastUseTime = 0;
                            pPc->DBSkillUpdate(pSkill);
                            //pPc->DBPcSave();
                            pPc->SendSkillLevelUpMessage(pSkill->m_wSkillId, pSkill->m_btSkillLevel);
                            pPc->SendSkillListMessage();
                            pPc->SendStatusMessage(1);
                            return TRUE;
                        } else {
                            pPc->SendSystemMessage(77, pSkill->GetUseSkillExpPoint(0));
                            return FALSE;
                        }
                    } else {
                        pPc->SendSystemMessage(76, 1);
                        return FALSE;
                    }
                } else {
                    pPc->SendSystemMessage(75, pSkill->GetLimitPcLevel(pPc));
                    return FALSE;
                }
            } else {
                pPc->SendSystemMessage(75, pSkill->m_btLimitLevel);
                return FALSE;
            }
        }
    }

    BOOL PremiumSkillLevelUpFilter(unsigned short wSkillId, int bItemUse, int bForce) {
        CNSPc *pPc = dynamic_cast<CNSPc *>(this->m_pChar);
        if (!pPc) {
            return FALSE;
        }

        CNSSkill *pSkill = this->Get(wSkillId);
        if (!pSkill) {
            if (bItemUse) {
                pPc->SendSystemMessage(NS_MSG_SKILL_ERROR_LEVELUP);
            }
            return FALSE;
        }

        if (pSkill->m_nDbSeq <= 0) {
            if (bItemUse) {
                pPc->SendSystemMessage(NS_MSG_SKILL_ERROR_LEVELUP);
            }
            return FALSE;
        }

        if (bForce) {
            if (pSkill->IsSteamAbility()) {
                return FALSE;
            }
        } else {
            if (pSkill->IsPassive() == TRUE || pSkill->IsSteamAbility() == TRUE) {
                if (bItemUse) {
                    pPc->SendSystemMessage(NS_MSG_SKILL_ERROR_LEVELUP);
                }
                return FALSE;
            }

            if (pSkill->IsAttrib() == TRUE || pSkill->IsMastery() == TRUE) {
                if (bItemUse) {
                    pPc->SendSystemMessage(NS_MSG_SKILL_ERROR_LEVELUP);
                }
                return FALSE;
            }
        }
        
        if (pSkill->m_btSkillLevel < pSkill->GetLimitSkillLevel(pPc, 0)) {
            if (pSkill->IsMythic() || pSkill->IsPSWSkill() || pPc->m_btSp >= 1) {
                if (bItemUse != TRUE || pPc->ItemUse(0xA322u) || pPc->ItemUse(0xA323u)) {
                    if (!pSkill->IsMythic() && !pSkill->IsPSWSkill()) {
                        --pPc->m_btSp;
                        ++pPc->m_wLogSp;
                        //pPc->DBPcSave();
                    }

                    ++pSkill->m_btSkillLevel;
                    pSkill->m_wSkillExp = 0;
                    pSkill->m_wSkillNextExp = 0;
                    //pSkill->m_dwLastUseTime = 0;
                    pPc->DBSkillUpdate(pSkill);
                    pPc->SendSkillLevelUpMessage(pSkill->GetSkillId(), pSkill->GetSkillLevel());
                    pPc->SendSkillUpdateMessage(pSkill);
                    pPc->SendStatusMessage(1);
                    return TRUE;
                } else {
                    pPc->SendSystemMessage(NS_MSG_SKILL_NEED_LEVELUP_ITEM);
                    return FALSE;
                }
            } else {
                pPc->SendSystemMessage(NS_MSG_SKILL_LEVELUP_NEED_SP, 1);
                return FALSE;
            }
        } else {
            if (bItemUse) {
                pPc->SendSystemMessage(NS_MSG_SKILL_ERROR_LEVELUP);
            }
            return FALSE;
        }
    }

    BOOL SkillResetFilter(unsigned short wSkillId, int bForce) {
        unsigned char btSkillPoint = 0;
        unsigned long dwUseSkillExpPoint = 0;

        CNSPc *pPc = dynamic_cast<CNSPc *>(this->m_pChar);
        if (!pPc) {
            return FALSE;
        }

        if (wSkillId && !bForce) {
            if (!pPc->m_Inven.CheckItem(0xA320u) && !pPc->m_Inven.CheckItem(0xA321u)) {
                return FALSE;
            }

            if (wSkillId >> 8 == 0xB1 || wSkillId >> 8 == 0xB2 || wSkillId >> 8 == 0xB3) {
                pPc->SendSystemMessage(NS_MSG_SKILL_ERROR_RESET);
                return FALSE;
            }
        }

        if (wSkillId && wSkillId != 0x806 || !pPc->m_Inven.GetItemCount(0x6030u)) {
            if (!wSkillId || wSkillId == 0xE01 || wSkillId == 0xE03 || wSkillId == 0xE05 || wSkillId == 0xE10) {
                unsigned long dwObjectId = pPc->PetGetObjectId(CNSPc::PetType_Summon);
                if (dwObjectId) {
                    pPc->PetDelete(dwObjectId);
                }
            }

            if (!wSkillId || wSkillId == 0x806){
                unsigned long dwObjectId = pPc->PetGetObjectId(CNSPc::PetType_Tame);
                if (dwObjectId) {
                    pPc->PetDelete(dwObjectId);
                    
                }
                memset(&static_cast<CNSPcExt *>(pPc)->m_TameState, 0, sizeof(CNSPc::CNSTameInfo));
            }

            for (unsigned int i = 0; i < this->GetMaxList(); ++i) {
                CNSSkill *pSkill = &this->GetSkill(i);
                if (pSkill->m_bUsed) {
                    BOOL bBaseSkill = FALSE;
                    unsigned char btPreSkillPoint = 0;
                    if (!wSkillId) {
                        //pSkill->m_dwLastUseTime = 0;
                    }

                    if ( pSkill->m_btSkillLevel
                        && pSkill->m_nDbSeq > 0
                        && !pSkill->IsMythic()
                        && !pSkill->IsAttrib()
                        && !pSkill->IsMastery()
                        && !pSkill->IsHelper()
                        && !pSkill->IsPSWSkill()
                        && (!wSkillId || wSkillId == pSkill->m_wSkillId)) {
                        if ( pSkill->GetSkillId() != 0x101
                            && pSkill->GetSkillId() != 0x301
                            && pSkill->GetSkillId() != 0x401
                            && pSkill->GetSkillId() != 0x410 )
                        {
                            btPreSkillPoint = pSkill->m_btSkillLevel;
                        } else {
                            btPreSkillPoint = pSkill->m_btSkillLevel - 1;
                            bBaseSkill = TRUE;
                        }

                        btSkillPoint += btPreSkillPoint;
                        if (btPreSkillPoint) {
                            if (wSkillId) {
                                //pSkill->m_dwLastUseTime = 0;
                                dwUseSkillExpPoint += static_cast<unsigned long>(pSkill->GetUseSkillExpPointAll() * 0.8);

                                pPc->SendSystemMessage("%s(LV: %u, SP: %u, TP: %u)", pSkill->m_szSkillName, pSkill->GetSkillLevel(), btPreSkillPoint, pSkill->GetUseSkillExpPointAll() * 0.8);
                            } else {
                                dwUseSkillExpPoint += pSkill->GetUseSkillExpPointAll();
                                pPc->SendSystemMessage("%s(LV: %u, SP: %u, TP: %u)", pSkill->m_szSkillName, pSkill->GetSkillLevel(), btPreSkillPoint, pSkill->GetUseSkillExpPointAll());
                            }

                            pSkill->m_btSkillLevel = bBaseSkill == TRUE;
                            pSkill->m_wSkillExp = 0;
                            pSkill->m_wSkillNextExp = 0;
                            if (pSkill->m_wSkillId == 0x605 || pSkill->m_wSkillId == 0x1403) {
                                pPc->m_TeleportList.Clear();
                                pPc->DBTeleportDeleteAll();
                            }

                            pPc->DBSkillUpdate(pSkill);
                            if (wSkillId) {
                                pPc->SendSystemMessage(NS_MSG_SKILL_RESET, pSkill->m_szSkillName);
                                if (!bForce && !pPc->ItemUseDb(0xA321u, 1)) {
                                    pPc->ItemUseDb(0xA320u, 1);
                                }
                                break;
                            }
                        }
                    }
                }
            }

            pPc->SendSystemMessage(NS_MSG_LEVELUP_5, btSkillPoint);
            NS::SafeValue(pPc->m_btSp, btSkillPoint + pPc->m_btSp);
            NS::SafeValue(pPc->m_wLogSp, pPc->m_wLogSp - btSkillPoint);
            pPc->AddSkillExpPoint(dwUseSkillExpPoint, 2);
            pPc->SendSystemMessage("Total(SP: %u, TP: %u)\n", btSkillPoint, dwUseSkillExpPoint);
            pPc->DBPcSave();
            pPc->SendStatusMessage(1);
            pPc->SendSkillListMessage();
            return TRUE;
        } else {
            pPc->SendSystemMessage(NS_MSG_SKILL_RESET_TAME_SAVE);
            return FALSE;
        }
    }
};



bool CNSSkillListFilterInit() {
    return CNSSkillList::_PatchDBSkillListBuild(&CNSSkillListFilter::DBSkillListBuildFilter)
        && CNSSkillList::_PatchSkillDefaultList(&CNSSkillListFilter::SkillDefaultListFilter)
        && CNSSkillList::_PatchStudy(&CNSSkillListFilter::StudyFilter)
        && CNSSkillList::_PatchPremiumSkillLevelUp(&CNSSkillListFilter::PremiumSkillLevelUpFilter)
        && CNSSkillList::_PatchSkillReset(&CNSSkillListFilter::SkillResetFilter);
}