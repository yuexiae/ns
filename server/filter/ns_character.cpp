#include "server/server_pch.h"

#include "server/ext/ns_ext.h"


class CNSCharacterFilter : public CNSCharacter {
public:
    NSPOINT2 GetCurrentCellFilter(unsigned long dwTime) {
        NSPOINT2 cell;
        if (this->m_dwFinishTime <= dwTime) {
            cell = this->m_cellDest;
        } else {
            if (this->IsPcClass()) {
                CNSPcExt *pPc = reinterpret_cast<CNSPcExt *>(this);
                if (pPc->m_dwCheckMoveTime + 100 > dwTime) {
                    return this->m_cell;
                }

                pPc->m_dwCheckMoveTime = dwTime;
            } else {
                CNSNpcExt *pNpc = reinterpret_cast<CNSNpcExt *>(this);
                if (pNpc->m_dwCheckMoveTime + 100 > dwTime) {
                    return this->m_cell;
                }

                pNpc->m_dwCheckMoveTime = dwTime;
            }

            float l = NSPOINT2::GetLength(this->m_cell, this->m_cellDest);
            float t = (float)(this->GetMoveSpeedF() * (this->m_dwFinishTime - dwTime));
            cell.x = (unsigned short)(this->m_cellDest.x - floor((this->m_cellDest.x - this->m_cell.x) / l * t));
            cell.y = (unsigned short)(this->m_cellDest.y - floor((this->m_cellDest.y - this->m_cell.y) / l * t));

        }

        if (NSPOINT2::GetLength(this->m_cellMoveStart, cell) >= this->m_fMoveLength) {
            cell = this->m_cellDest;
        } 

        return cell;
    }

    void OnMoveFilter(unsigned long dwTime)  {
        if (this->m_cell != this->m_cellDest)  {
            NSPOINT2 dest = this->GetCurrentCell(dwTime);
            if (this->m_cell != dest) {
                this->MoveTo(dest);
            }
        }

        if (this->IsFinish(dwTime)) {
            if (this->m_bStopped){
                if (this->m_state != StateType_Sitdown && this->m_state != StateType_Dead) {
                    this->m_state = StateType_Stand;
                }
            } else {
                this->OnStop(dwTime);
            }
        }
    }

    void IncGoldFilter(unsigned long dwGold) {
        if (this->m_dwGold + dwGold > 2000000000) {
            this->m_dwGold = 2000000000;
        } else {
            this->m_dwGold += dwGold;
        }
    }
};



bool CNSCharacterFilterInit() {
    return CNSCharacter::_PatchGetCurrentCell(&CNSCharacterFilter::GetCurrentCellFilter)
        && CNSCharacter::_PatchOnMove(&CNSCharacterFilter::OnMoveFilter)
        && CNSCharacter::_PatchIncGold(&CNSCharacterFilter::IncGoldFilter);
}