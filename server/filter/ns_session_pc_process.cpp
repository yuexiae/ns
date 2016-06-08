#include "server/server_pch.h"

#include "server/ext/ns_ext.h"
#include "server/application.h"
#include "server/helper/ns_option.h"
#include <boost/crc.hpp>

class NSSessionPcProcessFilter {
public:
    static void SessionPcProcessInitFilter() {
        CNSSessionPcExt::ProcessInit(NSSessionPcProcessFilter::OnUnknow);

        CNSSessionPc::ProcessAdd(CNSMessageId::SCIdle,  NSSessionPcProcess::OnSCIdle);
        //CNSSessionPc::ProcessAdd(CNSMessageId::SCGameLoginReq,  NSSessionPcProcess::OnSCGameLoginReq);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCAliasList,  NSSessionPcProcess::OnSCAliasList);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCAliasSelect,  NSSessionPcProcess::OnSCAliasSelect);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCAliasCreate,  NSSessionPcProcess::OnSCAliasCreate);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCAliasDelete,  NSSessionPcProcess::OnSCAliasDelete);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCGameLogin2Req,  NSSessionPcProcess::OnSCGameLogin2Req);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCGameEnter,  NSSessionPcProcess::OnSCGameEnter);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCGameLeave,  NSSessionPcProcess::OnSCGameLeave);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCGameLeave2,  NSSessionPcProcess::OnSCGameLeave2);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCSessionPcMove,  NSSessionPcProcess::OnSCSessionPcMove);
        //CNSSessionPc::ProcessAdd(CNSMessageId::SCPcChat,  NSSessionPcProcess::OnSCPcChat);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCStatus,  NSSessionPcProcess::OnSCStatus);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCItemList,  NSSessionPcProcess::OnSCItemList);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCItemSort,  NSSessionPcProcess::OnSCItemSort);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCPcMoveReq,  NSSessionPcProcess::OnSCPcMoveReq);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCPcBindPos,  NSSessionPcProcess::OnSCPcBindPos);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCAutoRunStart,  NSSessionPcProcess::OnSCAutoRunStart);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCAutoRunEnd,  NSSessionPcProcess::OnSCAutoRunEnd);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCPCJump,  NSSessionPcProcess::OnSCPCJump);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCPcAttackReq,  NSSessionPcProcess::OnSCPcAttackReq);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCPcAttackCancel,  NSSessionPcProcess::OnSCPcAttackCancel);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCPcResistReq,  NSSessionPcProcess::OnSCPcResistReq);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCPcTraceLootReq,  NSSessionPcProcess::OnSCPcTraceLootReq);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCPcAssistReq,  NSSessionPcProcess::OnSCPcAssistReq);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCCharInfoReq,  NSSessionPcProcess::OnSCCharInfoReq);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCTameMobInfoReq,  NSSessionPcProcess::OnSCTameMobInfoReq);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCPetInfoReq,  NSSessionPcProcess::OnSCPetInfoReq);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCTameMobNameChange,  NSSessionPcProcess::OnSCTameMobNameChange);
        //CNSSessionPc::ProcessAdd(CNSMessageId::SCPcChat2,  NSSessionPcProcess::OnSCPcChat);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCItemDescription,  NSSessionPcProcess::OnSCItemDescription);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCItemParamDescription,  NSSessionPcProcess::OnSCItemParamDescription);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCDropItemList,  NSSessionPcProcess::OnSCDropItemList);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCItemLoot,  NSSessionPcProcess::OnSCItemLoot);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCItemEquipment,  NSSessionPcProcess::OnSCItemEquipment);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCItemMove,  NSSessionPcProcess::OnSCItemMove);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCItemUse,  NSSessionPcProcess::OnSCItemUse);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCItemDelete,  NSSessionPcProcess::OnSCItemDelete);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCItemCombine,  NSSessionPcProcess::OnSCItemCombine);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCItemDivide,  NSSessionPcProcess::OnSCItemDivide);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCItemUpgrade,  NSSessionPcProcess::OnSCItemUpgrade);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCItemInfo,  NSSessionPcProcess::OnSCItemInfo);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCShopItemList,  NSSessionPcProcess::OnSCShopItemList);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCShopItemTrade,  NSSessionPcProcess::OnSCShopItemTrade);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCShopItemCost,  NSSessionPcProcess::OnSCShopItemCost);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCExchangeReq,  NSSessionPcProcess::OnSCExchangeReq);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCExchangeItem,  NSSessionPcProcess::OnSCExchangeItem);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCExchangeConfirm,  NSSessionPcProcess::OnSCExchangeConfirm);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCExchangeCancel,  NSSessionPcProcess::OnSCExchangeCancel);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCNpcTalk,  NSSessionPcProcess::OnSCNpcTalk);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCSkillCast,  NSSessionPcProcess::OnSCSkillCast);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCSkillCancel,  NSSessionPcProcess::OnSCSkillCancel);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCSkillStudy,  NSSessionPcProcess::OnSCSkillStudy);
        //CNSSessionPc::ProcessAdd(CNSMessageId::SCSkillDescription,  NSSessionPcProcess::OnSCSkillDescription);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCBuffDescription,  NSSessionPcProcess::OnSCBuffDescription);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCPremiumSkillLevelUp,  NSSessionPcProcess::OnSCPremiumSkillLevelUp);
        //CNSSessionPc::ProcessAdd(CNSMessageId::SCQuestGiveUp,  NSSessionPcProcess::OnSCQuestGiveUp);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCQuestSummary,  NSSessionPcProcess::OnSCQuestSummary);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCQuickBarSave,  NSSessionPcProcess::OnSCQuickBarSave);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCProductList,  NSSessionPcProcess::OnSCProductList);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCProductDescription,  NSSessionPcProcess::OnSCProductDescription);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCProductMake,  NSSessionPcProcess::OnSCProductMake);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCResolution,  NSSessionPcProcess::OnSCResolution);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCRecombination,  NSSessionPcProcess::OnSCRecombination);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCPartyCreate,  NSSessionPcProcess::OnSCPartyCreate);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCPartyJoin,  NSSessionPcProcess::OnSCPartyJoin);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCPartyQuit,  NSSessionPcProcess::OnSCPartyQuit);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCPartyKick,  NSSessionPcProcess::OnSCPartyKick);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCPartyNameChange,  NSSessionPcProcess::OnSCPartyNameChange);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCPartyPasswordChange,  NSSessionPcProcess::OnSCPartyPasswordChange);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCPartyLootChange,  NSSessionPcProcess::OnSCPartyLootChange);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCPartyInvite,  NSSessionPcProcess::OnSCPartyInvite);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCPartyInviteReq,  NSSessionPcProcess::OnSCPartyInviteReq);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCRebirth,  NSSessionPcProcess::OnSCRebirth);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCEventEnd,  NSSessionPcProcess::OnSCEventEnd);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCPcEquipInfo,  NSSessionPcProcess::OnSCPcEquipInfo);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCUsePhoenix,  NSSessionPcProcess::OnSCUsePhoenix);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCUseSkillReset,  NSSessionPcProcess::OnSCUseSkillReset);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCPetFood,  NSSessionPcProcess::OnSCPetFood);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCTeleportList,  NSSessionPcProcess::OnSCTeleportList);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCTeleportAdd,  NSSessionPcProcess::OnSCTeleportAdd);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCTeleportDelete,  NSSessionPcProcess::OnSCTeleportDelete);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCTeleportCast,  NSSessionPcProcess::OnSCTeleportCast);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCFriendList,  NSSessionPcProcess::OnSCFriendList);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCFriendAdd,  NSSessionPcProcess::OnSCFriendAdd);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCFriendDelete,  NSSessionPcProcess::OnSCFriendDelete);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCFriendAddReq,  NSSessionPcProcess::OnSCFriendAddReq);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCPremiumShopList,  NSSessionPcProcess::OnSCPremiumShopList);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCPremiumShopSell,  NSSessionPcProcess::OnSCPremiumShopSell);
        //CNSSessionPc::ProcessAdd(CNSMessageId::SCCashInfo,  NSSessionPcProcess::OnSCCashInfo);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCPcShopOpen,  NSSessionPcProcess::OnSCPcShopOpen);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCPcShopClose,  NSSessionPcProcess::OnSCPcShopClose);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCPcShopList,  NSSessionPcProcess::OnSCPcShopList);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCPcShopSell,  NSSessionPcProcess::OnSCPcShopSell);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCPcShopBuy,  NSSessionPcProcess::OnSCPcShopBuy);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCGuildOpen,  NSSessionPcProcess::OnSCGuildOpen);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCGuildClose,  NSSessionPcProcess::OnSCGuildClose);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCGuildList,  NSSessionPcProcess::OnSCGuildList);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCGuildInfo,  NSSessionPcProcess::OnSCGuildInfo);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCGuildChangeMaster,  NSSessionPcProcess::OnSCGuildChangeMaster);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCGuildChangeName,  NSSessionPcProcess::OnSCGuildChangeName);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCGuildChangeComment,  NSSessionPcProcess::OnSCGuildChangeComment);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCGuildChangeRank,  NSSessionPcProcess::OnSCGuildChangeRank);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCGuildJoinReq,  NSSessionPcProcess::OnSCGuildJoinReq);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCGuildJoin,  NSSessionPcProcess::OnSCGuildJoin);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCGuildQuit,  NSSessionPcProcess::OnSCGuildQuit);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCGuildKick,  NSSessionPcProcess::OnSCGuildKick);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCWareHouseList,  NSSessionPcProcess::OnSCWareHouseList);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCWareHouseInItem,  NSSessionPcProcess::OnSCWareHouseInItem);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCWareHouseInGold,  NSSessionPcProcess::OnSCWareHouseInGold);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCWareHouseInConfirm,  NSSessionPcProcess::OnSCWareHouseInConfirm);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCWareHouseOutItem,  NSSessionPcProcess::OnSCWareHouseOutItem);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCWareHouseOutGold,  NSSessionPcProcess::OnSCWareHouseOutGold);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCWareHouseOutConfirm,  NSSessionPcProcess::OnSCWareHouseOutConfirm);
        //CNSSessionPc::ProcessAdd(CNSMessageId::SCAuctionList,  NSSessionPcProcess::OnSCAuctionList);
        //CNSSessionPc::ProcessAdd(CNSMessageId::SCAuctionAdd,  NSSessionPcProcess::OnSCAuctionAdd);
        //CNSSessionPc::ProcessAdd(CNSMessageId::SCAuctionSell,  NSSessionPcProcess::OnSCAuctionSell);
        //CNSSessionPc::ProcessAdd(CNSMessageId::SCAuctionDelete,  NSSessionPcProcess::OnSCAuctionDelete);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCTitleSelect,  NSSessionPcProcess::OnSCTitleSelect);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCTitleDescription,  NSSessionPcProcess::OnSCTitleDescription);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCCmdRename,  NSSessionPcProcess::OnSCCmdRename);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCRealmMapInfo,  NSSessionPcProcess::OnSCRealmMapInfo);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCDebug,  NSSessionPcProcess::OnSCDebug);
        //CNSSessionPc::ProcessAdd(CNSMessageId::SCEcho,  NSSessionPcProcess::OnSCEcho);
        //CNSSessionPc::ProcessAdd(CNSMessageId::SCSkillTest,  NSSessionPcProcess::OnSCSkillTest);
        //CNSSessionPc::ProcessAdd(CNSMessageId::SCBuffTest,  NSSessionPcProcess::OnSCBuffTest);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCServerDisconnect,  NSSessionPcProcess::OnSCServerDisconnect);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCServerCheck,  NSSessionPcProcess::OnSCServerCheck);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCServerNotice,  NSSessionPcProcess::OnSCServerNotice);
        CNSSessionPc::ProcessAdd(CNSMessageId::ISItemLootAll,  NSSessionPcProcess::OnISItemLootAll);
        CNSSessionPc::ProcessAdd(CNSMessageId::ISQuestMobCheck,  NSSessionPcProcess::OnISQuestMobCheck);
        CNSSessionPc::ProcessAdd(CNSMessageId::ISPVPItemAdd,  NSSessionPcProcess::OnISPVPItemAdd);
        CNSSessionPc::ProcessAdd(CNSMessageId::ISSkillUse,  NSSessionPcProcess::OnISSkillUse);
        CNSSessionPc::ProcessAdd(CNSMessageId::ISMemoWrite,  NSSessionPcProcess::OnISMemoWrite);
        CNSSessionPc::ProcessAdd(CNSMessageId::ISGMemoWrite,  NSSessionPcProcess::OnISGMemoWrite);
        CNSSessionPc::ProcessAdd(CNSMessageId::ISTameMobSave,  NSSessionPcProcess::OnISTameMobSave);
        CNSSessionPc::ProcessAdd(CNSMessageId::ISCheckDoubleConnect,  NSSessionPcProcess::OnISCheckDoubleConnect);
        //CNSSessionPc::ProcessAdd(CNSMessageId::ISLogWrite,  NSSessionPcProcess::OnISLogWrite);
        CNSSessionPc::ProcessAdd(CNSMessageId::ISEventItemAdd,  NSSessionPcProcess::OnISEventItemAdd);
        //CNSSessionPc::ProcessAdd(CNSMessageId::SSTest,  NSSessionPcProcess::OnSSTest);
        CNSSessionPc::ProcessAdd(CNSMessageId::SSGuildInfo,  NSSessionPcProcess::OnSSGuildInfo);
        CNSSessionPc::ProcessAdd(CNSMessageId::SSGuildClose,  NSSessionPcProcess::OnSSGuildClose);
        CNSSessionPc::ProcessAdd(CNSMessageId::SSGuildMemberJoin,  NSSessionPcProcess::OnSSGuildMemberJoin);
        CNSSessionPc::ProcessAdd(CNSMessageId::SSGuildMemberUpdate,  NSSessionPcProcess::OnSSGuildMemberUpdate);
        CNSSessionPc::ProcessAdd(CNSMessageId::SSGuildMemberQuit,  NSSessionPcProcess::OnSSGuildMemberQuit);
        CNSSessionPc::ProcessAdd(CNSMessageId::SSGMemoWrite,  NSSessionPcProcess::OnSSGMemoWrite);
        //CNSSessionPc::ProcessAdd(CNSMessageId::SSNpcTalk,  NSSessionPcProcess::OnSSNpcTalk);
        CNSSessionPc::ProcessAdd(CNSMessageId::SSChatChannelChat,  NSSessionPcProcess::OnSSChatChannelChat);
        CNSSessionPc::ProcessAdd(CNSMessageId::SSChatBroadcast,  NSSessionPcProcess::OnSSChatBroadcast);
        CNSSessionPc::ProcessAdd(CNSMessageId::SSGuildPointAdd,  NSSessionPcProcess::OnSSGuildPointAdd);
        CNSSessionPc::ProcessAdd(CNSMessageId::SSFriendAdd,  NSSessionPcProcess::OnSSFriendAdd);
        CNSSessionPc::ProcessAdd(CNSMessageId::SSFriendDelete,  NSSessionPcProcess::OnSSFriendDelete);
        CNSSessionPc::ProcessAdd(CNSMessageId::SSGameLeave,  NSSessionPcProcess::OnSSGameLeave);

        //filter
        CNSSessionPc::ProcessAdd(CNSMessageId::SCGameLoginReq, OnSCGameLoginReqFilter);
        CNSSessionPc::ProcessAdd(CNSMessageId::SSNpcTalk, OnSSNpcTalkFilter);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCCashInfo, OnSCCashInfoFilter);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCPcChat, OnSCPcChatFilter);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCPcChat2, OnSCPcChatFilter);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCSkillDescription, OnSCSkillDescriptionFilter);
        CNSSessionPc::ProcessAdd(CNSMessageId::SCQuestGiveUp, OnSCQuestGiveUpFilter);

        //add
        CNSSessionPc::ProcessAdd(0x1014, NSSessionPcProcessFilter::OnLoginAuth);

        //on servermain
        Application::GetSingleton()->OnServerMain();
    }

    static void  OnUnknow(CNSSessionPc *session_pc, CPacket& packet) {
        LOGERROR("CNSSessionPcExt::OnUnknow(%04x) userid:%s", packet.GetId(), session_pc->m_pPc->m_szUserId);
    }

    static void OnSCGameLoginReqFilter(CNSSessionPc *pParent, CPacket& packet) {
        static char sign[0x18] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00};

        char temp[sizeof(sign)];
        packet.ReadData(temp, sizeof(sign));
        if (memcmp(temp, sign, sizeof(sign)) == 0) {
            return;
        }

        packet.ResetPos();
        NSSessionPcProcess::OnSCGameLoginReq(pParent, packet);
    }

    static void OnSSNpcTalkFilter(CNSSessionPc *pParent, CPacket& packet) {
        unsigned long dwObjectId;
        char szMenuKey[32] = { 0 };

        packet.ReadULong(&dwObjectId);
        packet.ReadString(szMenuKey, sizeof(szMenuKey));

        pParent->m_pPc->m_NpcMenuKey.clear();
        if (strcmp(szMenuKey, "Make_") > 0) {
            boost::crc_32_type crc;
            crc.process_bytes(szMenuKey, strlen(szMenuKey));
            pParent->m_pPc->m_NpcMenuKey.push_back(crc.checksum());
        }

        CNSObject::Owner<CNSNpc> pNpc = CNSObjectManagerExt::GetInstance()->Get<CNSNpc>(dwObjectId);
        if (pNpc) {
            CPacket packeta(0x2161);
            packeta.WriteUChar(1);
            packeta.WriteULong(dwObjectId);
            if (pNpc->NpcScriptTalk(pParent->m_pPc, szMenuKey, packeta)) {
                pParent->m_pPc->SetNpcTalkObjectId(dwObjectId);
                pParent->SendMessageA(packeta, 1);
                return;
            }
        }

        CPacket packeta(0x2161);
        packeta.WriteUChar(0);
        packeta.WriteULong(dwObjectId);
        pParent->SendMessageA(packeta, TRUE);
    }

    static void OnSCCashInfoFilter(CNSSessionPc *pParent, CPacket& packet) {
        pParent->m_pPc->SendCashInfoMessage();

        CPacket send_packet(CNSMessageId::CSPremiumShopLimitList);
        CNSItemParams::GetInstance()->PacketPremiumShopLimitList(pParent->m_pPc, send_packet);

        boost::crc_32_type crc;
        crc.process_bytes(send_packet.GetDataBuffer(), send_packet.GetDataSize());
        if (pParent->m_pPc->m_PremiumShopLimitChecksum != crc.checksum()) {
            pParent->m_pPc->SendMessageA(send_packet, TRUE);
            pParent->m_pPc->m_PremiumShopLimitChecksum = crc.checksum();
        }
    }
    static void OnSCPcChatFilter(CNSSessionPc *pParent, CPacket& packet) {
        char szText[0x100];
        packet.ReadString(szText, sizeof(szText));

		if (szText[0] == '.' && pParent->m_pPc->IsSessionGameMode()
			&& pParent->m_pPc->m_Command.OnCommand(&szText[1])) {
			return;
		}

        packet.ResetPos();
        NSSessionPcProcess::OnSCPcChat(pParent, packet);
    }

	static void OnSCSkillDescriptionFilter(CNSSessionPc *pParent, CPacket& packet) {
        unsigned short wSkillId = packet.ReadUShort();

        CPacket send_packet(CNSMessageId::CSSkillDescription);

        CNSSkill *pSkill = pParent->m_pPc->m_SkillList.Get(wSkillId);
        if (!pSkill) {
            send_packet.WriteUChar(0);
            pParent->SendMessageA(send_packet, TRUE);
        }

        char szDescription[2048];

        switch (pSkill->m_wSkillId) {
        case 0xF01:
            pSkill->GetDescription(pParent->m_pPc, szDescription);
            strcat(szDescription, "\r\n");
            NSOption::GetDescription(NSOption::m_Mythic[pParent->m_pPc->GetDefaultLimitSkillLevel() - 1], szDescription);
            break;
        case 0x814:
            pSkill->GetDescription(pParent->m_pPc, szDescription);
            if (pParent->m_pPc->m_TameState.wNpcId > 0) {
                CNSNpc *pNpc = CNSNpcParams::GetInstance()->GetObjectA(pParent->m_pPc->m_TameState.wNpcId);
                if (pNpc) {
                    sprintf(szDescription, "%s\r\n\r\n^[GLv%d %s", szDescription, pNpc->m_btLevel, pNpc->m_szNpcName);
                }
            }
            break;
        default:
            pSkill->GetDescription(pParent->m_pPc, szDescription);
        }

        send_packet.WriteUChar(1);
        send_packet.WriteString(szDescription);
        send_packet.WriteUShort(pSkill->m_wSkillExp);
        send_packet.WriteUShort(pSkill->GetNextExp());
        pParent->SendMessageA(send_packet, TRUE);
    }

    static void OnSCQuestGiveUpFilter(CNSSessionPc *pParent, CPacket& packet) {
        unsigned short wQuestId = packet.ReadUShort();

        CNSQuest *pQuest = pParent->m_pPc->m_QuestList.Find(wQuestId);
        if (pQuest && pQuest->m_btCompleted != 0) {
            LOGERROR("QuestId:%u, pQuest->m_btCompleted:%u", wQuestId, pQuest->m_btCompleted);
            return;
        }

        CPacket packeta(0x2361u);
        if (pParent->m_pPc->m_QuestList.Delete(wQuestId)) {
            packeta.WriteUChar(1);
        } else {
            packeta.WriteUChar(0);
        }

        packeta.WriteUShort(wQuestId);
        pParent->SendMessageA(packeta, TRUE);
    }

    static void OnLoginAuth(CNSSessionPc *pParent, CPacket& packet) {
        unsigned char key[16];
        char userid[25] = { 0 };
        char password[33] = { 0 };

        packet.ReadString(userid, sizeof(userid));
        packet.ReadString(password, sizeof(password));

        CNSPcManager *pc_manager = CSingleton<CNSPcManager>::GetInstance();

        NSKeyMakeGameLogin2(userid, pParent->m_szPeerIpAddress, CNSSessionPc::ms_btServerIpArray(), pc_manager->m_nServerPort, key);

        CPacket send_packet(0x1023);
        send_packet.WriteUChar(1);
        send_packet.WriteData(CNSSessionPc::ms_btServerIpArray(), 4);
        send_packet.WriteULong(pc_manager->m_nServerPort);
        send_packet.WriteData(key, 16);
        pParent->SendMessageA(send_packet, TRUE);
    }
};


bool NSSessionPcProcessFilterInit() {
    return NSSessionPcProcess::_PatchSessionPcProcessInit(NSSessionPcProcessFilter::SessionPcProcessInitFilter);
}
