#include "server/server_pch.h"

#include "server/ext/ns_ext.h"


class CNSNpcStateMoveFilter : public CNSNpcStateMoveExt {
public:
    void ActionFilter(unsigned long dwTime) {
        NSPOINT2 cell = this->m_pParent->GetCell();

        if (this->IsFirst() == TRUE) {
            if (!this->m_pParent->IsFinish(dwTime)) {
                return;
            }

            if (this->m_pParent->IsFriendlyMob() == TRUE) {
                this->m_pParent->GetLeaderDestination2(cell);
                if (NSPOINT2::GetLength(this->m_pParent->GetCell(), cell) > 15.0) {
                    this->m_pParent->SetState(CNSNpc::StateType_Run);
                }
            } else if (this->m_pParent->GetLeaderDestination(cell, 1) == TRUE) {
                if (NSPOINT2::GetLength(this->m_pParent->GetCell(), cell) > 100.0) {
                    this->m_pParent->SetState(CNSNpc::StateType_Run);
                }
            } else if (!this->m_pParent->m_MovePath.GetFirstPath(cell)) {
                cell = this->m_pParent->GetNewDestination(this->m_pParent->GetCell());
            }

            if (NSPOINT2::GetLength(this->m_pParent->GetCell(), cell) > 10.0) {
                this->m_pParent->MoveCharacter(cell, dwTime);
            }

            this->m_bFirst = FALSE;
        }

        if (this->m_pParent->GetTargetObjectId() && this->m_pParent->m_btAttackType != CNSNpc::AttackType_Dummy) {
            if (this->m_pParent->IsPet() != TRUE) {
                this->Clear();
                this->m_pParent->SetFinishTime(dwTime);
                this->m_pParent->StateTransition(2u);
                return;
            }

            if (this->m_pParent->m_NpcSkill.SkillCast(CNSNpcSkill::NpcSkillStateType_Attack, this->m_pParent->GetTargetObjectId()) == TRUE) {
                this->Clear();
                return;
            }
        }

        if (this->m_pParent->IsFinish(dwTime) == TRUE) {
            if (this->m_pParent->m_MovePath.GetPath(cell) == TRUE) {
                this->m_pParent->MoveCharacter(cell, dwTime);
            } else {
                this->Clear();
                if (this->m_pParent->IsFriendlyMob() != TRUE) {
                    this->m_pParent->StateTransition(4u);
                }
            }
        } else {
            CNSNpcSkill::NPCSKILLTYPE skillType;
            int nSkillId = this->m_pParent->m_NpcSkill.SelectSkillId(CNSNpcSkill::NpcSkillStateType_Move, skillType);
            if (nSkillId != -1) {
                CNSSkill *pSkill = this->m_pParent->m_SkillList.Get(nSkillId);
               
                if (this->m_pParent->m_SkillList.Target(nSkillId, this->m_pParent->m_dwObjectId, dwTime) == TRUE) {
                    unsigned long dwCastTime;
                    if (this->m_pParent->m_SkillList.Cast(dwTime, dwCastTime) == TRUE) {
                        if (this->m_pParent->m_SkillList.Use(dwTime, dwCastTime) != TRUE) {
                            this->m_pParent->m_SkillList.Cancel(1);
                            this->m_pParent->SendSkillCancelMessage();
                        }
                    } else {
                        this->m_pParent->m_SkillList.Cancel(1);
                        this->m_pParent->SendSkillCancelMessage();
                    }
                }
            }

            if (this->m_pParent->IsFriendlyMob() == TRUE && this->m_pParent->GetLeaderDestination2(cell) == TRUE) {
                if (NSPOINT2::GetLength(this->m_pParent->GetCell(), cell) > 15.0) {
                    this->m_pParent->SetState(CNSNpc::StateType_Run);
                }
                this->m_pParent->MoveCharacter(cell, dwTime);
            }
        }
    }
};



bool CNSNpcStateMoveFilterInit() {
	return CNSNpcStateMove::_PatchAction(&CNSNpcStateMoveFilter::ActionFilter);
}