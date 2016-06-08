#ifndef NSHEADER_NS_MESSAGE_ID_H_
#define NSHEADER_NS_MESSAGE_ID_H_


class CNSMessageId {
public:
	static const unsigned short SCIdle = 0x90;
	static const unsigned short SCGameLoginReq = 0x2010;
	static const unsigned short SCAliasList = 0x2020;
	static const unsigned short SCAliasSelect = 0x2022;
	static const unsigned short SCAliasCreate = 0x2024;
	static const unsigned short SCAliasDelete = 0x2026;
	static const unsigned short SCGameLogin2Req = 0x2012;
	static const unsigned short SCGameEnter = 0x2100;
	static const unsigned short SCGameLeave = 0x2102;
	static const unsigned short SCGameLeave2 = 0x2104;
	static const unsigned short SCSessionPcMove = 0x2030;
	static const unsigned short SCPcChat = 0x2032;
	static const unsigned short SCStatus = 0x2110;
	static const unsigned short SCItemList = 0x2112;
	static const unsigned short SCItemSort = 0x211A;
	static const unsigned short SCPcMoveReq = 0x2320;
	static const unsigned short SCPcBindPos = 0x2322;
	static const unsigned short SCAutoRunStart = 0x2324;
	static const unsigned short SCAutoRunEnd = 0x2326;
	static const unsigned short SCPCJump = 0x2328;
	static const unsigned short SCPcAttackReq = 0x2330;
	static const unsigned short SCPcAttackCancel = 0x2332;
	static const unsigned short SCPcResistReq = 0x2334;
	static const unsigned short SCPcTraceLootReq = 0x2336;
	static const unsigned short SCPcAssistReq = 0x2338;
	static const unsigned short SCCharInfoReq = 0x2310;
	static const unsigned short SCTameMobInfoReq = 0x2316;
	static const unsigned short SCPetInfoReq = 0x231A;
	static const unsigned short SCTameMobNameChange = 0x2318;
	static const unsigned short SCPcChat2 = 0x3010;
	static const unsigned short SCItemDescription = 0x2124;
	static const unsigned short SCItemParamDescription = 0x2126;
	static const unsigned short SCDropItemList = 0x2120;
	static const unsigned short SCItemLoot = 0x2122;
	static const unsigned short SCItemEquipment = 0x2132;
	static const unsigned short SCItemMove = 0x2134;
	static const unsigned short SCItemUse = 0x2130;
	static const unsigned short SCItemDelete = 0x2136;
	static const unsigned short SCItemCombine = 0x2138;
	static const unsigned short SCItemDivide = 0x213A;
	static const unsigned short SCItemUpgrade = 0x213C;
	static const unsigned short SCItemInfo = 0x213E;
	static const unsigned short SCShopItemList = 0x2140;
	static const unsigned short SCShopItemTrade = 0x2142;
	static const unsigned short SCShopItemCost = 0x2144;
	static const unsigned short SCExchangeReq = 0x2150;
	static const unsigned short SCExchangeItem = 0x2152;
	static const unsigned short SCExchangeConfirm = 0x2154;
	static const unsigned short SCExchangeCancel = 0x2156;
	static const unsigned short SCNpcTalk = 0x2160;
	static const unsigned short SCSkillCast = 0x2340;
	static const unsigned short SCSkillCancel = 0x2344;
	static const unsigned short SCSkillStudy = 0x2346;
	static const unsigned short SCSkillDescription = 0x2348;
	static const unsigned short SCBuffDescription = 0x234A;
	static const unsigned short SCPremiumSkillLevelUp = 0x234C;
	static const unsigned short SCQuestGiveUp = 0x2360;
	static const unsigned short SCQuestSummary = 0x2363;
	static const unsigned short SCQuickBarSave = 0x2370;
	static const unsigned short SCProductList = 0x2380;
	static const unsigned short SCProductDescription = 0x2382;
	static const unsigned short SCProductMake = 0x2384;
	static const unsigned short SCResolution = 0x2388;
	static const unsigned short SCRecombination = 0x238A;
	static const unsigned short SCPartyCreate = 0x3110;
	static const unsigned short SCPartyJoin = 0x3120;
	static const unsigned short SCPartyQuit = 0x3122;
	static const unsigned short SCPartyKick = 0x312D;
	static const unsigned short SCPartyNameChange = 0x3124;
	static const unsigned short SCPartyPasswordChange = 0x3126;
	static const unsigned short SCPartyLootChange = 0x312B;
	static const unsigned short SCPartyInvite = 0x3128;
	static const unsigned short SCPartyInviteReq = 0x312A;
	static const unsigned short SCRebirth = 0x2350;
	static const unsigned short SCEventEnd = 0x2352;
	static const unsigned short SCPcEquipInfo = 0x2354;
	static const unsigned short SCUsePhoenix = 0x2356;
	static const unsigned short SCUseSkillReset = 0x2358;
	static const unsigned short SCPetFood = 0x2390;
	static const unsigned short SCTeleportList = 0x23A0;
	static const unsigned short SCTeleportAdd = 0x23A2;
	static const unsigned short SCTeleportDelete = 0x23A4;
	static const unsigned short SCTeleportCast = 0x23A6;
	static const unsigned short SCFriendList = 0x23B0;
	static const unsigned short SCFriendAdd = 0x23B2;
	static const unsigned short SCFriendDelete = 0x23B4;
	static const unsigned short SCFriendAddReq = 0x23B6;
	static const unsigned short SCPremiumShopList = 0x23C0;
	static const unsigned short SCPremiumShopSell = 0x23C2;
	static const unsigned short SCCashInfo = 0x23C4;
	static const unsigned short SCPcShopOpen = 0x3210;
	static const unsigned short SCPcShopClose = 0x3212;
	static const unsigned short SCPcShopList = 0x3214;
	static const unsigned short SCPcShopSell = 0x3220;
	static const unsigned short SCPcShopBuy = 0x3222;
	static const unsigned short SCGuildOpen = 0x3310;
	static const unsigned short SCGuildClose = 0x3312;
	static const unsigned short SCGuildList = 0x3314;
	static const unsigned short SCGuildInfo = 0x3316;
	static const unsigned short SCGuildChangeMaster = 0x3320;
	static const unsigned short SCGuildChangeName = 0x3322;
	static const unsigned short SCGuildChangeComment = 0x3324;
	static const unsigned short SCGuildChangeRank = 0x3326;
	static const unsigned short SCGuildJoinReq = 0x3330;
	static const unsigned short SCGuildJoin = 0x3332;
	static const unsigned short SCGuildQuit = 0x3334;
	static const unsigned short SCGuildKick = 0x3336;
	static const unsigned short SCWareHouseList = 0x3410;
	static const unsigned short SCWareHouseInItem = 0x3420;
	static const unsigned short SCWareHouseInGold = 0x3422;
	static const unsigned short SCWareHouseInConfirm = 0x3424;
	static const unsigned short SCWareHouseOutItem = 0x3430;
	static const unsigned short SCWareHouseOutGold = 0x3432;
	static const unsigned short SCWareHouseOutConfirm = 0x3434;
	static const unsigned short SCAuctionList = 0x3800;
	static const unsigned short SCAuctionAdd = 0x3802;
	static const unsigned short SCAuctionSell = 0x3804;
	static const unsigned short SCAuctionDelete = 0x3806;
	static const unsigned short SCTitleSelect = 0x2902;
	static const unsigned short SCTitleDescription = 0x2904;
	static const unsigned short SCCmdRename = 0x3600;
	static const unsigned short SCRealmMapInfo = 0x3700;
	static const unsigned short SCDebug = 0x9000;
	static const unsigned short SCEcho = 0x9100;
	static const unsigned short SCSkillTest = 0x9102;
	static const unsigned short SCBuffTest = 0x9104;
	static const unsigned short SCServerDisconnect = 0xF012;
	static const unsigned short SCServerCheck = 0xF010;
	static const unsigned short SCServerNotice = 0xF014;
	static const unsigned short ISItemLootAll = 0xE010;
	static const unsigned short ISQuestMobCheck = 0xE011;
	static const unsigned short ISPVPItemAdd = 0xE012;
	static const unsigned short ISSkillUse = 0xE013;
	static const unsigned short ISMemoWrite = 0xE014;
	static const unsigned short ISGMemoWrite = 0xE015;
	static const unsigned short ISTameMobSave = 0xE016;
	static const unsigned short ISCheckDoubleConnect = 0xE017;
	static const unsigned short ISLogWrite = 0xE018;
	static const unsigned short ISEventItemAdd = 0xE019;
	static const unsigned short SSTest = 0xD109;
	static const unsigned short SSGuildInfo = 0xD110;
	static const unsigned short SSGuildClose = 0xD111;
	static const unsigned short SSGuildMemberJoin = 0xD112;
	static const unsigned short SSGuildMemberUpdate = 0xD113;
	static const unsigned short SSGuildMemberQuit = 0xD114;
	static const unsigned short SSGMemoWrite = 0xD115;
	static const unsigned short SSNpcTalk = 0xD116;
	static const unsigned short SSChatChannelChat = 0xD117;
	static const unsigned short SSChatBroadcast = 0xD118;
	static const unsigned short SSGuildPointAdd = 0xD119;
	static const unsigned short SSFriendAdd = 0xD11A;
	static const unsigned short SSFriendDelete = 0xD11B;
	static const unsigned short SSGameLeave = 0xD210;

    static const unsigned short CSPcEnter = 0x2211;
    static const unsigned short CSNpcEnter = 0x2213;
    static const unsigned short CSCharacterLeave = 0x2223;
    static const unsigned short CSMove = 0x2241;
    static const unsigned short CSPremiumShopLimitList = 0x23C7;
    static const unsigned short CSText = 0x3011;
    static const unsigned short CSGuildCreate = 0x331F;
    static const unsigned short CSCharacterRecovery = 0x2233;
    static const unsigned short CSPetLeave = 0x2227;
    static const unsigned short CSPetEnter = 0x2225;
    static const unsigned short CSNpcTalk = 0x2161;
    static const unsigned short CSSkillDescription = 0x2349;
    static const unsigned short CSGameLeave2 = 0x2105;

	static const char * GetName(unsigned short message_id) {
		switch (message_id) {
		case CNSMessageId::SCIdle: return "SCIdle";
		case CNSMessageId::SCGameLoginReq: return "SCGameLoginReq";
		case CNSMessageId::SCAliasList: return "SCAliasList";
		case CNSMessageId::SCAliasSelect: return "SCAliasSelect";
		case CNSMessageId::SCAliasCreate: return "SCAliasCreate";
		case CNSMessageId::SCAliasDelete: return "SCAliasDelete";
		case CNSMessageId::SCGameLogin2Req: return "SCGameLogin2Req";
		case CNSMessageId::SCGameEnter: return "SCGameEnter";
		case CNSMessageId::SCGameLeave: return "SCGameLeave";
		case CNSMessageId::SCGameLeave2: return "SCGameLeave2";
		case CNSMessageId::SCSessionPcMove: return "SCSessionPcMove";
		case CNSMessageId::SCPcChat: return "SCPcChat";
		case CNSMessageId::SCStatus: return "SCStatus";
		case CNSMessageId::SCItemList: return "SCItemList";
		case CNSMessageId::SCItemSort: return "SCItemSort";
		case CNSMessageId::SCPcMoveReq: return "SCPcMoveReq";
		case CNSMessageId::SCPcBindPos: return "SCPcBindPos";
		case CNSMessageId::SCAutoRunStart: return "SCAutoRunStart";
		case CNSMessageId::SCAutoRunEnd: return "SCAutoRunEnd";
		case CNSMessageId::SCPCJump: return "SCPCJump";
		case CNSMessageId::SCPcAttackReq: return "SCPcAttackReq";
		case CNSMessageId::SCPcAttackCancel: return "SCPcAttackCancel";
		case CNSMessageId::SCPcResistReq: return "SCPcResistReq";
		case CNSMessageId::SCPcTraceLootReq: return "SCPcTraceLootReq";
		case CNSMessageId::SCPcAssistReq: return "SCPcAssistReq";
		case CNSMessageId::SCCharInfoReq: return "SCCharInfoReq";
		case CNSMessageId::SCTameMobInfoReq: return "SCTameMobInfoReq";
		case CNSMessageId::SCPetInfoReq: return "SCPetInfoReq";
		case CNSMessageId::SCTameMobNameChange: return "SCTameMobNameChange";
		case CNSMessageId::SCPcChat2: return "SCPcChat2";
		case CNSMessageId::SCItemDescription: return "SCItemDescription";
		case CNSMessageId::SCItemParamDescription: return "SCItemParamDescription";
		case CNSMessageId::SCDropItemList: return "SCDropItemList";
		case CNSMessageId::SCItemLoot: return "SCItemLoot";
		case CNSMessageId::SCItemEquipment: return "SCItemEquipment";
		case CNSMessageId::SCItemMove: return "SCItemMove";
		case CNSMessageId::SCItemUse: return "SCItemUse";
		case CNSMessageId::SCItemDelete: return "SCItemDelete";
		case CNSMessageId::SCItemCombine: return "SCItemCombine";
		case CNSMessageId::SCItemDivide: return "SCItemDivide";
		case CNSMessageId::SCItemUpgrade: return "SCItemUpgrade";
		case CNSMessageId::SCItemInfo: return "SCItemInfo";
		case CNSMessageId::SCShopItemList: return "SCShopItemList";
		case CNSMessageId::SCShopItemTrade: return "SCShopItemTrade";
		case CNSMessageId::SCShopItemCost: return "SCShopItemCost";
		case CNSMessageId::SCExchangeReq: return "SCExchangeReq";
		case CNSMessageId::SCExchangeItem: return "SCExchangeItem";
		case CNSMessageId::SCExchangeConfirm: return "SCExchangeConfirm";
		case CNSMessageId::SCExchangeCancel: return "SCExchangeCancel";
		case CNSMessageId::SCNpcTalk: return "SCNpcTalk";
		case CNSMessageId::SCSkillCast: return "SCSkillCast";
		case CNSMessageId::SCSkillCancel: return "SCSkillCancel";
		case CNSMessageId::SCSkillStudy: return "SCSkillStudy";
		case CNSMessageId::SCSkillDescription: return "SCSkillDescription";
		case CNSMessageId::SCBuffDescription: return "SCBuffDescription";
		case CNSMessageId::SCPremiumSkillLevelUp: return "SCPremiumSkillLevelUp";
		case CNSMessageId::SCQuestGiveUp: return "SCQuestGiveUp";
		case CNSMessageId::SCQuestSummary: return "SCQuestSummary";
		case CNSMessageId::SCQuickBarSave: return "SCQuickBarSave";
		case CNSMessageId::SCProductList: return "SCProductList";
		case CNSMessageId::SCProductDescription: return "SCProductDescription";
		case CNSMessageId::SCProductMake: return "SCProductMake";
		case CNSMessageId::SCResolution: return "SCResolution";
		case CNSMessageId::SCRecombination: return "SCRecombination";
		case CNSMessageId::SCPartyCreate: return "SCPartyCreate";
		case CNSMessageId::SCPartyJoin: return "SCPartyJoin";
		case CNSMessageId::SCPartyQuit: return "SCPartyQuit";
		case CNSMessageId::SCPartyKick: return "SCPartyKick";
		case CNSMessageId::SCPartyNameChange: return "SCPartyNameChange";
		case CNSMessageId::SCPartyPasswordChange: return "SCPartyPasswordChange";
		case CNSMessageId::SCPartyLootChange: return "SCPartyLootChange";
		case CNSMessageId::SCPartyInvite: return "SCPartyInvite";
		case CNSMessageId::SCPartyInviteReq: return "SCPartyInviteReq";
		case CNSMessageId::SCRebirth: return "SCRebirth";
		case CNSMessageId::SCEventEnd: return "SCEventEnd";
		case CNSMessageId::SCPcEquipInfo: return "SCPcEquipInfo";
		case CNSMessageId::SCUsePhoenix: return "SCUsePhoenix";
		case CNSMessageId::SCUseSkillReset: return "SCUseSkillReset";
		case CNSMessageId::SCPetFood: return "SCPetFood";
		case CNSMessageId::SCTeleportList: return "SCTeleportList";
		case CNSMessageId::SCTeleportAdd: return "SCTeleportAdd";
		case CNSMessageId::SCTeleportDelete: return "SCTeleportDelete";
		case CNSMessageId::SCTeleportCast: return "SCTeleportCast";
		case CNSMessageId::SCFriendList: return "SCFriendList";
		case CNSMessageId::SCFriendAdd: return "SCFriendAdd";
		case CNSMessageId::SCFriendDelete: return "SCFriendDelete";
		case CNSMessageId::SCFriendAddReq: return "SCFriendAddReq";
		case CNSMessageId::SCPremiumShopList: return "SCPremiumShopList";
		case CNSMessageId::SCPremiumShopSell: return "SCPremiumShopSell";
		case CNSMessageId::SCCashInfo: return "SCCashInfo";
		case CNSMessageId::SCPcShopOpen: return "SCPcShopOpen";
		case CNSMessageId::SCPcShopClose: return "SCPcShopClose";
		case CNSMessageId::SCPcShopList: return "SCPcShopList";
		case CNSMessageId::SCPcShopSell: return "SCPcShopSell";
		case CNSMessageId::SCPcShopBuy: return "SCPcShopBuy";
		case CNSMessageId::SCGuildOpen: return "SCGuildOpen";
		case CNSMessageId::SCGuildClose: return "SCGuildClose";
		case CNSMessageId::SCGuildList: return "SCGuildList";
		case CNSMessageId::SCGuildInfo: return "SCGuildInfo";
		case CNSMessageId::SCGuildChangeMaster: return "SCGuildChangeMaster";
		case CNSMessageId::SCGuildChangeName: return "SCGuildChangeName";
		case CNSMessageId::SCGuildChangeComment: return "SCGuildChangeComment";
		case CNSMessageId::SCGuildChangeRank: return "SCGuildChangeRank";
		case CNSMessageId::SCGuildJoinReq: return "SCGuildJoinReq";
		case CNSMessageId::SCGuildJoin: return "SCGuildJoin";
		case CNSMessageId::SCGuildQuit: return "SCGuildQuit";
		case CNSMessageId::SCGuildKick: return "SCGuildKick";
		case CNSMessageId::SCWareHouseList: return "SCWareHouseList";
		case CNSMessageId::SCWareHouseInItem: return "SCWareHouseInItem";
		case CNSMessageId::SCWareHouseInGold: return "SCWareHouseInGold";
		case CNSMessageId::SCWareHouseInConfirm: return "SCWareHouseInConfirm";
		case CNSMessageId::SCWareHouseOutItem: return "SCWareHouseOutItem";
		case CNSMessageId::SCWareHouseOutGold: return "SCWareHouseOutGold";
		case CNSMessageId::SCWareHouseOutConfirm: return "SCWareHouseOutConfirm";
		case CNSMessageId::SCAuctionList: return "SCAuctionList";
		case CNSMessageId::SCAuctionAdd: return "SCAuctionAdd";
		case CNSMessageId::SCAuctionSell: return "SCAuctionSell";
		case CNSMessageId::SCAuctionDelete: return "SCAuctionDelete";
		case CNSMessageId::SCTitleSelect: return "SCTitleSelect";
		case CNSMessageId::SCTitleDescription: return "SCTitleDescription";
		case CNSMessageId::SCCmdRename: return "SCCmdRename";
		case CNSMessageId::SCRealmMapInfo: return "SCRealmMapInfo";
		case CNSMessageId::SCDebug: return "SCDebug";
		case CNSMessageId::SCEcho: return "SCEcho";
		case CNSMessageId::SCSkillTest: return "SCSkillTest";
		case CNSMessageId::SCBuffTest: return "SCBuffTest";
		case CNSMessageId::SCServerDisconnect: return "SCServerDisconnect";
		case CNSMessageId::SCServerCheck: return "SCServerCheck";
		case CNSMessageId::SCServerNotice: return "SCServerNotice";
		case CNSMessageId::ISItemLootAll: return "ISItemLootAll";
		case CNSMessageId::ISQuestMobCheck: return "ISQuestMobCheck";
		case CNSMessageId::ISPVPItemAdd: return "ISPVPItemAdd";
		case CNSMessageId::ISSkillUse: return "ISSkillUse";
		case CNSMessageId::ISMemoWrite: return "ISMemoWrite";
		case CNSMessageId::ISGMemoWrite: return "ISGMemoWrite";
		case CNSMessageId::ISTameMobSave: return "ISTameMobSave";
		case CNSMessageId::ISCheckDoubleConnect: return "ISCheckDoubleConnect";
		case CNSMessageId::ISLogWrite: return "ISLogWrite";
		case CNSMessageId::ISEventItemAdd: return "ISEventItemAdd";
		case CNSMessageId::SSTest: return "SSTest";
		case CNSMessageId::SSGuildInfo: return "SSGuildInfo";
		case CNSMessageId::SSGuildClose: return "SSGuildClose";
		case CNSMessageId::SSGuildMemberJoin: return "SSGuildMemberJoin";
		case CNSMessageId::SSGuildMemberUpdate: return "SSGuildMemberUpdate";
		case CNSMessageId::SSGuildMemberQuit: return "SSGuildMemberQuit";
		case CNSMessageId::SSGMemoWrite: return "SSGMemoWrite";
		case CNSMessageId::SSNpcTalk: return "SSNpcTalk";
		case CNSMessageId::SSChatChannelChat: return "SSChatChannelChat";
		case CNSMessageId::SSChatBroadcast: return "SSChatBroadcast";
		case CNSMessageId::SSGuildPointAdd: return "SSGuildPointAdd";
		case CNSMessageId::SSFriendAdd: return "SSFriendAdd";
		case CNSMessageId::SSFriendDelete: return "SSFriendDelete";
		case CNSMessageId::SSGameLeave: return "SSGameLeave";

        case CNSMessageId::CSPcEnter: return "CSPcEnter";
        case CNSMessageId::CSNpcEnter: return "CSNpcEnter";
        case CNSMessageId::CSCharacterLeave: return "CSCharacterLeave";
        case CNSMessageId::CSMove: return "CSMove";
        case CNSMessageId::CSPremiumShopLimitList: return "CSPremiumShopLimitList";
        case CNSMessageId::CSText: return "CSText";
        case CNSMessageId::CSGuildCreate: return "CSGuildCreate";
        case CNSMessageId::CSCharacterRecovery: return "CSCharacterRecovery";
        case CNSMessageId::CSPetLeave: return "CSPetLeave";
        case CNSMessageId::CSPetEnter: return "CSPetEnter";
        case CNSMessageId::CSNpcTalk: return "CSNpcTalk";
        case CNSMessageId::CSSkillDescription: return "CSSkillDescription";
        case CNSMessageId::CSGameLeave2: return "CSGameLeave2";

		default: return "Unknow";
		}
	}
};


#endif