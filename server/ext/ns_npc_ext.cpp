#include "server/server_pch.h"

#include "server/ext/ns_ext.h"

void CNSNpcExt::ActionNew() {
    __try {
        if (this->m_bNpcEnter || this->GetCurrentState() == StateType_Underground) { //!this->IsHide()

            unsigned long dwTime = timeGetTime();

            if (this->m_state != StateType_Return) {
                this->OnMove(dwTime);
            }

            if (!this->m_BuffList.IsEnable(CNSBuff::BuffType_Stun) && !this->m_BuffList.IsEnable(CNSBuff::BuffType_Sleep) || this->IsDead()) {
                this->m_ActionGlobal->Action(dwTime);
                this->m_ActionCurrent->Action(dwTime);
            }

            if (this->m_BuffList.m_dwCount > 0) {
                this->m_BuffList.OnTick(this, dwTime);
            }

            if (this->m_bReloadScript) {
                this->m_cs.Enter(10000);
                if (CNSNpcParamsExt::GetInstance()->ReloadNpcScript(this->m_wNpcId)) {
                    if (this->m_L) {
                        NSScript::NSScriptEnd(this->m_L);
                    }
                    this->m_L = NSScript::NSScriptInit(this->m_wNpcId);
                }
                this->m_cs.Leave();
                this->m_bReloadScript = false;
                this->m_bScriptIdle = true;
                this->m_bScriptQuestCheck = true;
            }

            if (this->GetCurrentState() != StateType_Underground) {
                if (this->m_bScriptIdle && this->m_dwNpcIdleTime < dwTime) {
                    NpcScriptIdleNew(NULL);
                    this->m_dwNpcIdleTime = dwTime + 10000;
                }

                if (this->m_bScriptQuestCheck && this->m_dwQuestCheckTime < dwTime) {
                    if (this->m_btMoveType == MoveType_Scarecrow) {
                        this->SendEnterMessage(0);
                    }
                    NpcScriptQuestCheckNew(NULL);
                    this->m_dwQuestCheckTime = dwTime + rand() % 4000 + 8000;
                }
            }

            if (this->IsPet()
                && this->m_dwLastActionTime != 0xFFFFFFFF
                && !this->m_dwTargetObjectId
                && this->m_dwLastActionTime < dwTime
                && this->m_dwPetInfoTime < dwTime) {
                    this->OnHide(dwTime);
            }

            if (this->m_dwDisappearTime < dwTime) {
                this->SetTransition(StateType_Underground);
                this->m_dwDisappearTime = 0xFFFFFFFF;
            }

            this->SendDelayedMessage();
        }
    } __except (CMiniDumper::WriteMiniDump(GetExceptionInformation())) {
        GameUtil::Output("Exception: CNSNpc::Action{ObjectId:%08x, NpcId:%04x, Cell:%u/%u/%u}",
            this->m_dwObjectId,
            this->m_wNpcId,
            this->m_btRegion,
            this->m_cell.x,
            this->m_cell.y);
    }
}

void CNSNpcExt::PacketMoveMessage(CPacket& packet) {
    CNSCharacter::STATETYPE state = this->GetState();
    if (this->m_cell == this->m_cellDest) {
        state = CNSCharacter::StateType_Stand;
    }

    packet.SetId(0x2241u);
    packet.WriteULong(this->m_dwObjectId);
    packet.WriteUChar(state);
    packet.WriteUShort(this->m_cell.x);
    packet.WriteUShort(this->m_cell.y);
    if (state != CNSCharacter::StateType_Run && state != CNSCharacter::StateType_Walk) {
        packet.WriteUShort(this->m_wAngle);
    } else {
        packet.WriteUShort(this->m_cellDest.x);
        packet.WriteUShort(this->m_cellDest.y);
        packet.WriteUShort(this->GetMoveSpeed());
    }
}

BOOL CNSNpcExt::NpcScriptIdleNew(CNSPc *pCaller) {
    struct lua_State *L = NULL;
    if (this->m_L) {
        this->m_cs.Enter(10000);
        L = this->m_L;
        this->m_L = NSScript::NSScriptInit(this->m_wNpcId);
        this->m_cs.Leave();
    } else {
        L = NSScript::NSScriptInit(this->m_wNpcId);
    }

    if (L) {
        if (NSScript::NSScriptNpcFuncExist(L, "Idle")) {
            int dwTest = lua_gettop(L);
            NSScript::NSScriptNpcIdle(L, this, "Idle");
            if (dwTest != lua_gettop(L)) {
                GameUtil::Output("Error: CNSNpc::NSScriptNpcIdle{NpcId:%04x, Stack:%d}\n", this->m_wNpcId, lua_gettop(L));
            }
        } else {
            this->m_bScriptIdle = false;
        }

        if (this->m_L){
            NSScript::NSScriptEnd(L);
        } else {
            this->m_cs.Enter(10000);
            this->m_L = L;
            this->m_cs.Leave();
        }
    }

    return TRUE;
}

BOOL CNSNpcExt::NpcScriptQuestCheckNew(CNSPc *pCaller) {
    struct lua_State *L = NULL;
    if (this->m_L) {
        this->m_cs.Enter(10000);
        L = this->m_L;
        this->m_L = NSScript::NSScriptInit(this->m_wNpcId);
        this->m_cs.Leave();
    } else {
        L = NSScript::NSScriptInit(this->m_wNpcId);
    }

    if (L) {
        if (NSScript::NSScriptNpcFuncExist(L, "QuestCheck")) {
            std::vector<CNSObject *> vObject;
            vObject.reserve(0x64u);

            this->GetVrMap()->FieldInfoPc(this, 0x12Cu, vObject);
            for (size_t i = 0; i < vObject.size(); ++i) {
                if (this->CheckFriendly(static_cast<CNSPc *>(vObject[i]))) {
                    int dwTest = lua_gettop(L);
                    NSScript::NSScriptNpcQuestCheck(L, this, static_cast<CNSPc *>(vObject[i]));
                    if (dwTest != lua_gettop(L)) {
                        GameUtil::Output("Error: CNSNpc::NpcScriptQuestCheck{i:%d, NpcId:%04x, UserAlias:%s, Stack:%d}\n",
                            i, this->m_wNpcId, static_cast<CNSPc *>(vObject[i])->m_szUserAlias, lua_gettop(L));
                    }
                }

                vObject[i]->DecRefCount();
            }
        } else {
            this->m_bScriptQuestCheck = false;
        }

        if (this->m_L){
            NSScript::NSScriptEnd(L);
        } else {
            this->m_cs.Enter(10000);
            this->m_L = L;
            this->m_cs.Leave();
        }
    }
    return TRUE;
}