#include "server/server_pch.h"

#include "server/ext/ns_ext.h"
#include "server/game_config.h"

class CNSSessionPcFilter : public CNSSessionPcExt {
public:
    static CNSSessionPc::_Invoke invoke_;
    
    CNSSessionPc& ConstructorFilter() {
        (this->*invoke_.Constructor)();
        if (this != CNSPc::m_DummySession()) {
            this->CNSSessionPcExtImpl::CNSSessionPcExtImpl();
        }
        return *this;
    }

    void DestructorFilter() {
        if (this != CNSPc::m_DummySession()) {
            this->CNSSessionPcExtImpl::~CNSSessionPcExtImpl();
        }
        (this->*invoke_.Destructor)();
    }

    void InitFilter(unsigned int socket) {
        (this->*invoke_.Init)(socket);
        if (this != CNSPc::m_DummySession()) {
            this->InitExt();
        }
    }

    void OnDestroyFilter() {
        if (!this->m_bDestroy  && this->m_pPc) {
            this->m_QueueBuffer.Clear();
        }

        (this->*invoke_.OnDestroy)();
    }

    BOOL SendMessageAFilter(CPacket& packet, int bEncode) {
        if (this->m_bCloseConnection)
            return TRUE;

        if (bEncode) {
            CPacketEncipher::g_Encipher()->Encode(packet);
        }

        unsigned short wId = packet.GetId();
        if (wId != CNSMessageId::CSNpcTalk && wId != CNSMessageId::CSGameLeave2 && CNSDbManager::GetInstance()->m_dwThread == GetCurrentThreadId()) {
            if (!this->m_QueueBuffer.Add(packet.GetPacketBuffer(), packet.GetPacketSize())) {
                this->SendDbMessageQueue();
                this->m_QueueBuffer.Add(packet.GetPacketBuffer(), packet.GetPacketSize());
            }
            
            return TRUE;
        } else {
            switch (wId) {
            case CNSMessageId::CSPcEnter:
            case CNSMessageId::CSNpcEnter:
            case CNSMessageId::CSCharacterLeave:
            case CNSMessageId::CSPetEnter:
            case CNSMessageId::CSPetLeave:
            case CNSMessageId::CSCharacterRecovery:
            case CNSMessageId::CSMove:
            case CNSMessageId::CSText:
                this->m_csQueuePacket.Enter(10000);
                if (!this->m_packetBinder.Add(packet.GetPacketBuffer(), packet.GetPacketSize())) {
                    this->SendMessageQueue();
                    this->m_packetBinder.Add(packet.GetPacketBuffer(), packet.GetPacketSize());
                }
                this->m_csQueuePacket.Leave();
                return TRUE;
            default:
                return this->_SendMessage(packet);
            }
        }
        
    }



    BOOL CheckSyncPosFilter(NSPOINT2 pt2Current) {
        return NSPOINT2::GetLength(this->m_pt2Sync, pt2Current) > GameConfig::GetSingleton()->GetCheckSyncPos();
    }

    void PacketParsingFilter(CPacket &packet) {
        if (this->m_bCloseConnection || !this->m_pPc) {
            return;
        }

        if (!CPacketEncipher::g_Encipher()->Decode(packet)){
            GameUtil::Output("Error: PacketParsing(Decode - ID: %x / Size : %u, Socket: %d)", packet.GetId(), packet.GetPacketSize(), this->m_socket);
            this->CloseConnection();
            return;
        }

        switch (packet.GetId()) {
        case CNSMessageId::SCIdle:
        case CNSMessageId::SCSessionPcMove:
        case CNSMessageId::SCPcChat:
        case CNSMessageId::SCStatus:
        case CNSMessageId::SCItemList:
        case CNSMessageId::SCItemSort:
        case CNSMessageId::SCPcMoveReq:
        case CNSMessageId::SCPcBindPos:
        case CNSMessageId::SCAutoRunStart:
        case CNSMessageId::SCAutoRunEnd:
        case CNSMessageId::SCPCJump:
        case CNSMessageId::SCPcAttackReq:
        case CNSMessageId::SCPcAttackCancel:
        case CNSMessageId::SCPcResistReq:
        case CNSMessageId::SCPcTraceLootReq:
        case CNSMessageId::SCPcAssistReq:
        case CNSMessageId::SCCharInfoReq:
        case CNSMessageId::SCTameMobInfoReq:
        case CNSMessageId::SCPetInfoReq:
        case CNSMessageId::SCTameMobNameChange:
        case CNSMessageId::SCPcChat2:
        case CNSMessageId::SCItemDescription:
        case CNSMessageId::SCItemParamDescription:
        case CNSMessageId::SCDropItemList:
        case CNSMessageId::SCItemEquipment:
        case CNSMessageId::SCItemMove:
        case CNSMessageId::SCItemInfo:
        case CNSMessageId::SCShopItemList:
        case CNSMessageId::SCShopItemCost:
        case CNSMessageId::SCExchangeReq:
        case CNSMessageId::SCExchangeItem:
        case CNSMessageId::SCExchangeCancel:
        case CNSMessageId::SCSkillCast:
        case CNSMessageId::SCSkillCancel:
        case CNSMessageId::SCSkillDescription:
        case CNSMessageId::SCBuffDescription:
        case CNSMessageId::SCQuickBarSave:
        case CNSMessageId::SCProductList:
        case CNSMessageId::SCProductDescription:
        case CNSMessageId::SCResolution:
        case CNSMessageId::SCPartyCreate:
        case CNSMessageId::SCPartyJoin:
        case CNSMessageId::SCPartyQuit:
        case CNSMessageId::SCPartyKick:
        case CNSMessageId::SCPartyNameChange:
        case CNSMessageId::SCPartyPasswordChange:
        case CNSMessageId::SCPartyLootChange:
        case CNSMessageId::SCPartyInvite:
        case CNSMessageId::SCPartyInviteReq:
        case CNSMessageId::SCEventEnd:
        case CNSMessageId::SCPcEquipInfo:
        case CNSMessageId::SCUsePhoenix:
        case CNSMessageId::SCUseSkillReset:
        case CNSMessageId::SCTeleportList:
        case CNSMessageId::SCTeleportCast:
        case CNSMessageId::SCFriendList:
        case CNSMessageId::SCFriendAddReq:
        case CNSMessageId::SCPcShopOpen:
        case CNSMessageId::SCPcShopClose:
        case CNSMessageId::SCPcShopList:
        case CNSMessageId::SCWareHouseInItem:
        case CNSMessageId::SCWareHouseInGold:
        case CNSMessageId::SCWareHouseOutItem:
        case CNSMessageId::SCWareHouseOutGold:
        case CNSMessageId::SCTitleSelect:
        case CNSMessageId::SCTitleDescription:
        case CNSMessageId::SCRealmMapInfo:
            this->PacketProcess(packet);
            break;
            //case CNSMessageId::SCEcho:
            //case CNSMessageId::SCSkillTest:
            //case CNSMessageId::SCBuffTest:
            //case CNSMessageId::SCServerDisconnect:
            //case CNSMessageId::SCServerCheck:
            //case CNSMessageId::SCServerNotice:
            //case CNSMessageId::ISItemLootAll:
            //case CNSMessageId::ISQuestMobCheck:
            //case CNSMessageId::ISPVPItemAdd:
            //case CNSMessageId::ISSkillUse:
            //case CNSMessageId::ISMemoWrite:
            //case CNSMessageId::ISGMemoWrite:
            //case CNSMessageId::ISTameMobSave:
            //case CNSMessageId::ISCheckDoubleConnect:
            //case CNSMessageId::ISLogWrite:
            //case CNSMessageId::ISEventItemAdd:
            //case CNSMessageId::SSTest:
        case CNSMessageId::SSGuildInfo:
        case CNSMessageId::SSGuildClose:
        case CNSMessageId::SSGuildMemberJoin:
        case CNSMessageId::SSGuildMemberUpdate:
        case CNSMessageId::SSGuildMemberQuit:
        case CNSMessageId::SSGMemoWrite:
        case CNSMessageId::SSNpcTalk:
        case CNSMessageId::SSChatChannelChat:
        case CNSMessageId::SSChatBroadcast:
        case CNSMessageId::SSGuildPointAdd:
        case CNSMessageId::SSFriendAdd:
        case CNSMessageId::SSFriendDelete:
        case CNSMessageId::SSGameLeave:
            if (this->peer.m_dwPeerIp != CNSSessionPcExt::GetServerIp()) {
                LOGERROR("Error: PacketParsing(invaild ID: %x(%s) / PeerIp : %04X, ServerIp: %04X)",
                    packet.GetId(), CNSMessageId::GetName(packet.GetId()), this->peer.m_dwPeerIp, CNSSessionPcExt::GetServerIp());
            } else {
                this->PacketProcess(packet);
            }
            break;
        case CNSMessageId::SCGameLoginReq:
        case CNSMessageId::SCAliasList:
        case CNSMessageId::SCAliasSelect:
        case CNSMessageId::SCAliasCreate:
        case CNSMessageId::SCAliasDelete:
        case CNSMessageId::SCGameLogin2Req:
        case CNSMessageId::SCGameEnter:
        case CNSMessageId::SCGameLeave:
        case CNSMessageId::SCGameLeave2:
        case CNSMessageId::SCItemLoot:
        case CNSMessageId::SCItemUse:
        case CNSMessageId::SCItemDelete:
        case CNSMessageId::SCItemCombine:
        case CNSMessageId::SCItemDivide:
        case CNSMessageId::SCItemUpgrade:
        case CNSMessageId::SCShopItemTrade:
        case CNSMessageId::SCExchangeConfirm:
        case CNSMessageId::SCNpcTalk:
        case CNSMessageId::SCSkillStudy:
        case CNSMessageId::SCPremiumSkillLevelUp:
        case CNSMessageId::SCQuestGiveUp:
        case CNSMessageId::SCQuestSummary:
        case CNSMessageId::SCProductMake:
        case CNSMessageId::SCRecombination:
        case CNSMessageId::SCRebirth:
        case CNSMessageId::SCPetFood:
        case CNSMessageId::SCTeleportAdd:
        case CNSMessageId::SCTeleportDelete:
        case CNSMessageId::SCFriendAdd:
        case CNSMessageId::SCFriendDelete:
        case CNSMessageId::SCPremiumShopList:
        case CNSMessageId::SCPremiumShopSell:
        case CNSMessageId::SCCashInfo:
        case CNSMessageId::SCPcShopSell:
        case CNSMessageId::SCPcShopBuy:
        case CNSMessageId::SCGuildOpen:
        case CNSMessageId::SCGuildClose:
        case CNSMessageId::SCGuildList:
        case CNSMessageId::SCGuildInfo:
        case CNSMessageId::SCGuildChangeMaster:
        case CNSMessageId::SCGuildChangeName:
        case CNSMessageId::SCGuildChangeComment:
        case CNSMessageId::SCGuildChangeRank:
        case CNSMessageId::SCGuildJoinReq:
        case CNSMessageId::SCGuildJoin:
        case CNSMessageId::SCGuildQuit:
        case CNSMessageId::SCGuildKick:
        case CNSMessageId::SCWareHouseList:
        case CNSMessageId::SCWareHouseInConfirm:
        case CNSMessageId::SCWareHouseOutConfirm:
        case CNSMessageId::SCAuctionList:
        case CNSMessageId::SCAuctionAdd:
        case CNSMessageId::SCAuctionSell:
        case CNSMessageId::SCAuctionDelete:
        case CNSMessageId::SCCmdRename:
        case CNSMessageId::SCDebug:
        case 0x1014:///////////////////////////////////////////////////////////////////////////////////////////////////////tmp
            CSingleton<CNSDbManager>::GetInstance()->AddDbSession(this, packet);
            break;
        default:
            GameUtil::Output("Error: PacketParsing(invaild ID: %x(%s) / Size : %u, Socket: %d)",
                packet.GetId(), CNSMessageId::GetName(packet.GetId()), packet.GetPacketSize(), this->m_socket);
            break;
        }
    }

    void PacketProcessFilter(CPacket &packet) {
        if (this->m_bCloseConnection || this->m_pPc == NULL)
            return;

        if (this == CNSPc::m_DummySession()) {
            GameUtil::Output("Error: PacketProcess(ID: %x(%s) / Socket: %d) { DummySession }",
                packet.GetId(), CNSMessageId::GetName(packet.GetId()), this->m_socket);
            return;
        }

        switch (packet.GetId()) {
        case CNSMessageId::SCStatus:
        case CNSMessageId::SCItemList:
        case CNSMessageId::SCItemSort:
        case CNSMessageId::SCDropItemList:
        case CNSMessageId::SCItemLoot:
        case CNSMessageId::SCItemDescription:
        case CNSMessageId::SCItemParamDescription:
        case CNSMessageId::SCItemUse:
        case CNSMessageId::SCItemEquipment:
        case CNSMessageId::SCItemMove:
        case CNSMessageId::SCItemDelete:
        case CNSMessageId::SCItemCombine:
        case CNSMessageId::SCItemDivide:
        case CNSMessageId::SCItemUpgrade:
        case CNSMessageId::SCItemInfo:
        case CNSMessageId::SCShopItemList:
        case CNSMessageId::SCShopItemTrade:
        case CNSMessageId::SCShopItemCost:
        case CNSMessageId::SCExchangeReq:
        case CNSMessageId::SCExchangeItem:
        case CNSMessageId::SCExchangeConfirm:
        case CNSMessageId::SCExchangeCancel:
        case CNSMessageId::SCNpcTalk:
        case CNSMessageId::SCCharInfoReq:
        case CNSMessageId::SCTameMobInfoReq:
        case CNSMessageId::SCTameMobNameChange:
        case CNSMessageId::SCPetInfoReq:
        case CNSMessageId::SCPcMoveReq:
        case CNSMessageId::SCPcBindPos:
        case CNSMessageId::SCAutoRunStart:
        case CNSMessageId::SCAutoRunEnd:
        case CNSMessageId::SCPCJump:
        case CNSMessageId::SCPcAttackReq:
        case CNSMessageId::SCPcAttackCancel:
        case CNSMessageId::SCPcResistReq:
        case CNSMessageId::SCPcTraceLootReq:
        case CNSMessageId::SCPcAssistReq:
        case CNSMessageId::SCSkillCast:
        case CNSMessageId::SCSkillCancel:
        case CNSMessageId::SCSkillStudy:
        case CNSMessageId::SCSkillDescription:
        case CNSMessageId::SCBuffDescription:
        case CNSMessageId::SCPremiumSkillLevelUp:
        case CNSMessageId::SCRebirth:
        case CNSMessageId::SCEventEnd:
        case CNSMessageId::SCPcEquipInfo:
        case CNSMessageId::SCUsePhoenix:
        case CNSMessageId::SCUseSkillReset:
        case CNSMessageId::SCQuestGiveUp:
        case CNSMessageId::SCQuestSummary:
        case CNSMessageId::SCQuickBarSave:
        case CNSMessageId::SCProductList:
        case CNSMessageId::SCProductDescription:
        case CNSMessageId::SCProductMake:
        case CNSMessageId::SCResolution:
        case CNSMessageId::SCRecombination:
        case CNSMessageId::SCPetFood:
        case CNSMessageId::SCTeleportList:
        case CNSMessageId::SCTeleportAdd:
        case CNSMessageId::SCTeleportDelete:
        case CNSMessageId::SCTeleportCast:
        case CNSMessageId::SCPremiumShopList:
        case CNSMessageId::SCPremiumShopSell:
        case CNSMessageId::SCCashInfo:
        case CNSMessageId::SCTitleSelect:
        case CNSMessageId::SCTitleDescription:
        case CNSMessageId::SCPcChat2:
        case CNSMessageId::SCPartyCreate:
        case CNSMessageId::SCPartyJoin:
        case CNSMessageId::SCPartyQuit:
        case CNSMessageId::SCPartyNameChange:
        case CNSMessageId::SCPartyPasswordChange:
        case CNSMessageId::SCPartyInvite:
        case CNSMessageId::SCPartyInviteReq:
        case CNSMessageId::SCPartyLootChange:
        case CNSMessageId::SCPartyKick:
        case CNSMessageId::SCPcShopOpen:
        case CNSMessageId::SCPcShopClose:
        case CNSMessageId::SCPcShopList:
        case CNSMessageId::SCPcShopSell:
        case CNSMessageId::SCPcShopBuy:
        case CNSMessageId::SCGuildOpen:
        case CNSMessageId::SCGuildClose:
        case CNSMessageId::SCWareHouseList:
        case CNSMessageId::SCWareHouseInItem:
        case CNSMessageId::SCWareHouseInGold:
        case CNSMessageId::SCWareHouseInConfirm:
        case CNSMessageId::SCWareHouseOutItem:
        case CNSMessageId::SCWareHouseOutGold:
        case CNSMessageId::SCWareHouseOutConfirm:
        case CNSMessageId::SCCmdRename:
        case CNSMessageId::SCRealmMapInfo:
        case CNSMessageId::SCAuctionList:
        case CNSMessageId::SCAuctionAdd:
        case CNSMessageId::SCAuctionSell:
        case CNSMessageId::SCAuctionDelete:
        case CNSMessageId::SCDebug:
        case CNSMessageId::SCEcho:
        case CNSMessageId::SCSkillTest:
        case CNSMessageId::SCBuffTest:
        case CNSMessageId::SSTest:
        case CNSMessageId::SSNpcTalk:
        case CNSMessageId::SSGameLeave:
        case CNSMessageId::ISItemLootAll:
        case CNSMessageId::ISQuestMobCheck:
        case CNSMessageId::ISPVPItemAdd:
        case CNSMessageId::ISSkillUse:
        case CNSMessageId::ISTameMobSave:
        case CNSMessageId::ISCheckDoubleConnect:
        case CNSMessageId::ISEventItemAdd:
            if (this->m_sessionLevel != SessionLevel_Game) {
                GameUtil::Output("Warning: PacketProcess{SessionLevel(%d) != SessionLevel_Game} (ID: %x(%s) / Socket: %d)",
                    this->m_sessionLevel, packet.GetId(), CNSMessageId::GetName(packet.GetId()), this->m_socket);
                return;
            }
            break;
        case CNSMessageId::SCSessionPcMove:
        case CNSMessageId::SCPcChat:
            if (this->m_sessionLevel != SessionLevel_Session) {
                GameUtil::Output("Warning: PacketProcess{SessionLevel(%d) != SessionLevel_Session} (ID: %x(%s) / Socket: %d)",
                    this->m_sessionLevel, packet.GetId(), CNSMessageId::GetName(packet.GetId()), this->m_socket);
                return;
            }
            break;
        case CNSMessageId::SCAliasList:
        case CNSMessageId::SCAliasSelect:
        case CNSMessageId::SCAliasCreate:
        case CNSMessageId::SCAliasDelete:
            if (this->m_sessionLevel != SessionLevel_Login && this->m_sessionLevel != SessionLevel_Session) {
                GameUtil::Output("Warning: PacketProcess{SessionLevel(%d) != SessionLevel_Login && SessionLevel_Session} (ID: %x(%s) / Socket: %d)",
                    this->m_sessionLevel, packet.GetId(), CNSMessageId::GetName(packet.GetId()), this->m_socket);
                return;
            }
            break;
        case CNSMessageId::SCGameEnter:
            if (this->m_sessionLevel != SessionLevel_Load && this->m_sessionLevel != SessionLevel_Session) {
                GameUtil::Output("Warning: PacketProcess{SessionLevel(%d) != SessionLevel_Load && SessionLevel_Session} (ID: %x(%s) / Socket: %d)",
                    this->m_sessionLevel, packet.GetId(), CNSMessageId::GetName(packet.GetId()), this->m_socket);
                return;
            }
            break;
        case CNSMessageId::SCGameLeave:
        case CNSMessageId::SCFriendList:
        case CNSMessageId::SCFriendAdd:
        case CNSMessageId::SCFriendDelete:
        case CNSMessageId::SCFriendAddReq:
        case CNSMessageId::SCGuildList:
        case CNSMessageId::SCGuildInfo:
        case CNSMessageId::SCGuildChangeMaster:
        case CNSMessageId::SCGuildChangeName:
        case CNSMessageId::SCGuildChangeComment:
        case CNSMessageId::SCGuildChangeRank:
        case CNSMessageId::SCGuildJoinReq:
        case CNSMessageId::SCGuildJoin:
        case CNSMessageId::SCGuildQuit:
        case CNSMessageId::SCGuildKick:
        case CNSMessageId::ISMemoWrite:
        case CNSMessageId::ISGMemoWrite:
            if (this->m_sessionLevel != SessionLevel_Game && this->m_sessionLevel != SessionLevel_Session) {
                GameUtil::Output("Warning: PacketProcess{SessionLevel(%d) != SessionLevel_Game && SessionLevel_Session} (ID: %x(%s) / Socket: %d)",
                    this->m_sessionLevel, packet.GetId(), CNSMessageId::GetName(packet.GetId()), this->m_socket);
                return;
            }
            break;
        case CNSMessageId::SCGameLeave2:
            if (this->m_sessionLevel != SessionLevel_Load && this->m_sessionLevel != SessionLevel_Game && this->m_sessionLevel != SessionLevel_Session) {
                GameUtil::Output("Warning: PacketProcess{SessionLevel(%d) != SessionLevel_Load && SessionLevel_Game && SessionLevel_Session} (ID: %x(%s) / Socket: %d)",
                    this->m_sessionLevel, packet.GetId(), CNSMessageId::GetName(packet.GetId()), this->m_socket);
                return;
            }
            break;
        case CNSMessageId::SCIdle:
        case CNSMessageId::SCGameLoginReq:
        case CNSMessageId::SCGameLogin2Req:
        case CNSMessageId::SSGuildInfo:
        case CNSMessageId::SSGuildClose:
        case CNSMessageId::SSGuildMemberJoin:
        case CNSMessageId::SSGuildMemberUpdate:
        case CNSMessageId::SSGuildMemberQuit:
        case CNSMessageId::SSGMemoWrite:
        case CNSMessageId::SSChatChannelChat:
        case CNSMessageId::SSChatBroadcast:
        case CNSMessageId::SSGuildPointAdd:
        case CNSMessageId::SSFriendAdd:
        case CNSMessageId::SSFriendDelete:
        case CNSMessageId::ISLogWrite:
        case CNSMessageId::SCServerCheck:
        case CNSMessageId::SCServerDisconnect:
        case CNSMessageId::SCServerNotice:
        case 0x1014:///////////////////////////////////////////////////////////////////////////////////////////////////////tmp
            break;
        default:
            GameUtil::Output("Warning: PacketProcess(Unknow ID: %x(%s) / Socket: %d)",
                this->m_sessionLevel, packet.GetId(), CNSMessageId::GetName(packet.GetId()), this->m_socket);
            return;
        }

        __try {
            ms_pProcessArray()[packet.GetId()](this, packet);
        } __except (CMiniDumper::WriteMiniDump(GetExceptionInformation())) {
            GameUtil::Output("Exception: PacketProcess(ID: %x(%s) / Socket: %d / pSession: %p / pPc: %p",
                packet.GetId(), CNSMessageId::GetName(packet.GetId()), this->m_socket, this, this->m_pPc);
        }
    }
};

CNSSessionPc::_Invoke CNSSessionPcFilter::invoke_;

bool CNSSessionPcFilterInit() {
    base::HookUtil::PatchULong(0x00402BD5 + 1, sizeof(CNSSessionPcExt));
	GameUtil::Output("modify CNSSessionPc memory allocator size:0x%04x ok", sizeof(CNSSessionPcExt));

    return CNSSessionPc::_PatchConstructor(&CNSSessionPcFilter::ConstructorFilter, &CNSSessionPcFilter::invoke_.Constructor)
        && CNSSessionPc::_PatchDestructor(&CNSSessionPcFilter::DestructorFilter, &CNSSessionPcFilter::invoke_.Destructor)
        && CNSSessionPc::_PatchInit(&CNSSessionPcFilter::InitFilter, &CNSSessionPcFilter::invoke_.Init)
        && CNSSessionPc::_PatchOnDestroy(&CNSSessionPcFilter::OnDestroyFilter, &CNSSessionPcFilter::invoke_.OnDestroy)
        && CNSSessionPc::_PatchSendMessageA(&CNSSessionPcFilter::SendMessageAFilter)
        && CNSSessionPc::_PatchCheckSyncPos(&CNSSessionPcFilter::CheckSyncPosFilter)
        && CNSSessionPc::_PatchPacketParsing(&CNSSessionPcFilter::PacketParsingFilter, &CNSSessionPcFilter::invoke_.PacketParsing)
        && CNSSessionPc::_PatchPacketProcess(&CNSSessionPcFilter::PacketProcessFilter, &CNSSessionPcFilter::invoke_.PacketProcess);
}  