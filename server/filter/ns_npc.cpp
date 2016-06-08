#include "server/server_pch.h"

#include "server/ext/ns_ext.h"


class CNSNpcFilter : public CNSNpcExt {
public:
    static CNSNpc::_Invoke invoke_;
    
    CNSNpc& ConstructorFilter() {
        (this->*invoke_.Constructor)();
        this->CNSNpcExtImpl::CNSNpcExtImpl();
        return *this;
    }

    void DestructorFilter() {
        this->CNSNpcExtImpl::~CNSNpcExtImpl();
        (this->*invoke_.Destructor)();
    }

    void OnEnterFilter() {
        CNSCharacter::OnEnter();
        if (this->IsBlockDefense()) {
            CSingleton<CNSBlockSysManager>::GetInstance()->Add(this->m_dwObjectId, this->m_btRegion, this->m_cell, this->m_btSize);
        }
        this->SendEnterMessage(1);
        this->m_bNpcEnter = true;
    }

    void OnLeaveFilter() {
        if (this->m_btRegion) {
            this->SendLeaveMessage();
            if (this->IsBlockDefense()) {
                CSingleton<CNSBlockSysManager>::GetInstance()->Delete(this->m_dwObjectId);
            }
            CNSCharacter::OnLeave();
            this->m_bNpcEnter = false;
        }
    }

    void PacketEnterMessageFilter(CPacket& packet) {
        unsigned char buffArray[30];
        unsigned short buffSkillArray[30];
        unsigned short buffTimeArray[30];

        unsigned char buffCount = this->m_BuffList.GetBuffArray(buffArray, buffSkillArray, buffTimeArray);

        packet.SetId(CNSMessageId::CSNpcEnter);
        packet.WriteULong(this->m_dwObjectId);
        packet.WriteUShort(this->m_wNpcId);
        packet.WriteUChar(this->m_btLevel);
        packet.WriteUChar(this->GetHpPercent());
        packet.WriteUChar(buffCount);

        if (buffCount) {
            packet.WriteData(buffArray, buffCount * sizeof(char));
            packet.WriteData(buffSkillArray, buffCount * sizeof(unsigned short));
            packet.WriteData(buffTimeArray, buffCount * sizeof(unsigned short));
        }

        if (this->IsFriendlyMob()) {
            packet.WriteUChar(this->GetStaPercent());

            if (this->m_wNpcId >= 5284 && this->m_wNpcId <= 5287 && this->m_nGuildBaseSeq) {
                Owner<CNSGuild> guild = CNSPcManager::GetInstance()->GuildFind(this->m_nGuildBaseSeq);
                if (guild) {
                    char temp[128];
                    sprintf(temp, "%.24s^[G[%.24s]", this->m_szNpcName, guild->m_szGuildName);
                    packet.WriteString(temp);
                } else {
                    packet.WriteString(this->m_szNpcName);
                }
            } else if (this->IsPVPTournamentZone()) {
                packet.WriteString("############");
            } else {
                packet.WriteString(this->m_szNpcName);
            }
        }

        char actionState = this->m_state;
        if (this->m_cell.x == this->m_cellDest.x
            && this->m_cell.y == this->m_cellDest.y) {
                if (actionState != 4)
                    actionState = 0;
        }

        packet.WriteUChar(actionState);
        packet.WriteUShort(this->m_cell.x);
        packet.WriteUShort(this->m_cell.y);


        if (actionState != 2 && actionState != 1) {
            packet.WriteUShort(this->m_wAngle);
        } else {
            packet.WriteUShort(this->m_cellDest.x);
            packet.WriteUShort(this->m_cellDest.y);
            packet.WriteUShort(this->GetMoveSpeed());
        }

        packet.WriteUChar(this->m_btRealm);
        packet.WriteUShort(this->m_wStartAngle);
        packet.WriteUChar(this->m_SkillList.GetAttribSkill());

        //packet.WriteUlong(CNSMessageId::ExtraData);
        //packet.WriteUlong(this->m_dwObjectId);
        //packet.WriteUlong((unsigned long)this->m_fHp);
        //packet.WriteUlong(this->m_dwMaxHp);
    }


    void SendEnterMessageFilter(int bSend) {
        if (bSend){
            CPacket packet(CNSMessageId::CSNpcEnter);//this->PacketEnterMessage(packet);
            this->GetVrMap()->Broadcast(this, packet, 0, 0);
        } else {
            this->m_bCheckEnter = 1;
        }
    }

    void SendMoveMessageFilter(unsigned long dwTime, int bSend) {
        CPacket packet(CNSMessageId::CSMove);
        this->GetVrMap()->Broadcast(this, packet, 0, 0);
    }

    void ItemDropFilter(CNSCharacter *pChar) {
        (this->*invoke_.ItemDrop)(pChar);
        this->m_bPetPickFlag = false;
    }

  
};

CNSNpc::_Invoke CNSNpcFilter::invoke_;

bool CNSNpcFilterInit() {
    base::HookUtil::PatchULong(0x00403AE7 + 1, sizeof(CNSNpcExt));
	GameUtil::Output("modify cnsnpc memory pool size:0x%04x ok", sizeof(CNSNpcExt));

    return CNSNpc::_PatchConstructor(&CNSNpcFilter::ConstructorFilter, &CNSNpcFilter::invoke_.Constructor)
        && CNSNpc::_PatchDestructor(&CNSNpcFilter::DestructorFilter, &CNSNpcFilter::invoke_.Destructor)
        && CNSNpc::_PatchOnEnter(&CNSNpcFilter::OnEnterFilter)
        && CNSNpc::_PatchOnLeave(&CNSNpcFilter::OnLeaveFilter)
        && CNSNpc::_PatchPacketEnterMessage(&CNSNpcFilter::PacketEnterMessageFilter)
        && CNSNpc::_PatchSendEnterMessage(&CNSNpcFilter::SendEnterMessageFilter)
        && CNSNpc::_PatchSendMoveMessage(&CNSNpcFilter::SendMoveMessageFilter)
        && CNSNpc::_PatchItemDrop(&CNSNpcFilter::ItemDropFilter, &CNSNpcFilter::invoke_.ItemDrop);
}