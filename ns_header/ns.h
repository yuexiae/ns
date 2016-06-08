#ifndef NSHEADER_NS_H_
#define NSHEADER_NS_H_


template<typename T> class CSingleton;

#include <typeinfo>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mbstring.h>
#include <msgpack.hpp>

#include "base/micros.h"
#include "base/logging.h"
#include "server/game_util.h"

#include "ns_header/ns_packet.h"
#include "ns_header/ns_critical_section.h"
#include "ns_header/ns_pc.h"
#include "ns_header/ns_npc.h"
#include "ns_header/ns_odbc.h"
#include "ns_header/ns_world_manager.h"
#include "ns_header/ns_csv_reader.h"
#include "ns_header/ns_pc_chat_channel_list.h"
#include "ns_header/ns_slang_filter.h"
#include "ns_header/ns_session_pc.h"
#include "ns_header/ns_item.h"
#include "ns_header/ns_session_pc_process.h"
#include "ns_header/ns_message_id.h"
#include "ns_header/ns_exception.h"
#include "ns_header/ns_mini_dumper.h"
#include "ns_header/ns_pc_manager.h"
#include "ns_header/ns_crypto.h"
#include "ns_header/ns_item_params.h"
#include "ns_header/ns_pc_params.h"
#include "ns_header/ns_quest_params.h"
#include "ns_header/ns_npc_manager.h"
#include "ns_header/ns_db_log_manager.h"
#include "ns_header/ns_skill_params.h"
#include "ns_header/ns_db_params.h"
#include "ns_header/ns_acution.h"
#include "ns_header/ns_msg_params.h"
#include "ns_header/ns_reserve_manager.h"
#include "ns_header/ns_object_manager.h"
#include "ns_header/ns_guild.h"
#include "ns_header/ns_vr_block_manager.h"
#include "ns_header/ns_pc_title_params.h"
#include "ns_header/ns_map_manager.h"
#include "ns_header/ns_lua.h"
#include "ns_header/ns_script.h"
#include "ns_header/ns_admin_params.h"
#include "ns_header/ns_public.h"
#include "ns_header/ns_game_server_params.h"
#include "ns_header/ns_csession_manager.h"
#include "ns_header/ns_block_sys_manager.h"
#include "ns_header/ns_iocp.h"
#include "ns_header/ns_c_output_file.h"
#include "ns_header/ns_console.h"
#include "ns_header/ns_msg_counter.h"
#include "ns_header/ns_global.h"
#include "ns_header/ns_utility.h"

class NSStructCheck {
public:
	static void Check() {
#define __CHECK_STRUCT_SIZE(x)   do { GameUtil::Output(\
	"sizeof(%s):0x%x check:0x%x %s", typeid(x).name(), sizeof(x), x::_size, sizeof(x) != x::_size ? "failed" : "ok"); \
	sizeof(x) != x::_size ? getchar() : (void)0; \
	} while(0)

#define __CHECK_STRUCT_OFFSET(x, y, a)   do { GameUtil::Output(\
	"%s::%s check:0x%x:0x%x %s", #x, #y, STRUCT_OFFSET(x, y), a, STRUCT_OFFSET(x, y) != a ? "failed" : "ok"); \
	STRUCT_OFFSET(x, y) != a ? getchar() : (void)0; \
	} while(0)

		
		__CHECK_STRUCT_SIZE(base::GamePacket);
		__CHECK_STRUCT_SIZE(SteamEngine::Win32::System::CPacket);
		__CHECK_STRUCT_SIZE(_NSRANGE);
		__CHECK_STRUCT_SIZE(CNSObject);
		__CHECK_STRUCT_SIZE(CNSObject::Owner<CNSObject>);
		__CHECK_STRUCT_SIZE(CPacket);
		__CHECK_STRUCT_SIZE(CNSSkill);
		__CHECK_STRUCT_SIZE(CNSSkillList);
		__CHECK_STRUCT_SIZE(CNSInventory);
		__CHECK_STRUCT_SIZE(CNSBuff);
		__CHECK_STRUCT_SIZE(CNSBuffList);
		__CHECK_STRUCT_SIZE(SteamEngine::Win32::System::CCriticalSection);
		__CHECK_STRUCT_SIZE(CNSDamageCounter);
		__CHECK_STRUCT_SIZE(CNSMovePath);
		__CHECK_STRUCT_SIZE(CRand32);
		__CHECK_STRUCT_OFFSET(CNSCharacter, m_Rand, 0x3A6C);
		__CHECK_STRUCT_SIZE(CNSCharacter);
		__CHECK_STRUCT_SIZE(CNSEquipment);
		__CHECK_STRUCT_SIZE(CNSQuest);
		__CHECK_STRUCT_SIZE(CNSQuestList);
		__CHECK_STRUCT_SIZE(CNSPcExchange);
		__CHECK_STRUCT_SIZE(CNSProductList);
		__CHECK_STRUCT_SIZE(CNSPcTeleportList);
		__CHECK_STRUCT_SIZE(CNSPcShop);
		__CHECK_STRUCT_SIZE(CNSWareHouse);
		__CHECK_STRUCT_SIZE(CNSPcPremiumUseList);
		__CHECK_STRUCT_SIZE(CNSPcSetItemList);
		__CHECK_STRUCT_SIZE(CNSPcTitleList);
		__CHECK_STRUCT_SIZE(CNSPcParty);
		__CHECK_STRUCT_SIZE(CNSPcState);
		__CHECK_STRUCT_SIZE(CNSPcStateGlobal);
		__CHECK_STRUCT_SIZE(CNSPc);
		__CHECK_STRUCT_SIZE(CNSShopInventory);
		__CHECK_STRUCT_SIZE(CNSNpcSkill);
		__CHECK_STRUCT_SIZE(CNSNpc);
		__CHECK_STRUCT_SIZE(CThread);
		__CHECK_STRUCT_SIZE(CChSocket);
		__CHECK_STRUCT_SIZE(SteamEngine::Win32::DB::COdbc);
		__CHECK_STRUCT_SIZE(SteamEngine::Win32::DB::COdbcBindColumn);
		__CHECK_STRUCT_SIZE(CNSWorldManager);
		__CHECK_STRUCT_SIZE(CSession);
		__CHECK_STRUCT_SIZE(CNSSessionPc);
        __CHECK_STRUCT_OFFSET(CNSSessionPc, m_packetBinder, 0x447C);
        __CHECK_STRUCT_OFFSET(CNSSessionPc, peer.m_btPeerIpArray, 0x6484);
        __CHECK_STRUCT_OFFSET(CNSSessionPc, m_pt2Sync, 0x6488);
		__CHECK_STRUCT_SIZE(CCsvReader);
		__CHECK_STRUCT_SIZE(CNSSlangFilter);
		__CHECK_STRUCT_SIZE(CNSPcChatChannelList);
		__CHECK_STRUCT_SIZE(CNSItem);
		__CHECK_STRUCT_SIZE(CException);
		__CHECK_STRUCT_SIZE(CMiniDumper);
		__CHECK_STRUCT_SIZE(CNSSkillParams);
		__CHECK_STRUCT_SIZE(CNSDbParams);
		__CHECK_STRUCT_SIZE(CNSItemParams);
        __CHECK_STRUCT_SIZE(CNSPcParams);
        __CHECK_STRUCT_SIZE(CNSQuestParams);
        __CHECK_STRUCT_SIZE(CNSMsgParams);
        __CHECK_STRUCT_SIZE(CNSPcManager);
		__CHECK_STRUCT_SIZE(CNSNpcManager);
        __CHECK_STRUCT_SIZE(CNSDbManager);
		__CHECK_STRUCT_SIZE(CNSDbLogManager);
        __CHECK_STRUCT_SIZE(CNSAuction);
        __CHECK_STRUCT_SIZE(CNSReserveManager);
        __CHECK_STRUCT_SIZE(CNSObjectManager);
        __CHECK_STRUCT_SIZE(CNSGuild);
        __CHECK_STRUCT_SIZE(NSVrBlockPc);
        __CHECK_STRUCT_SIZE(NSVrBlockObject);
        __CHECK_STRUCT_SIZE(CNSVrBlockManager);
        __CHECK_STRUCT_SIZE(CNSPcTitleParams);
        __CHECK_STRUCT_SIZE(CNSMapManager);
        __CHECK_STRUCT_SIZE(CNSAdminParams);
        __CHECK_STRUCT_SIZE(CNSGameServerParams);
        __CHECK_STRUCT_SIZE(CSessionManager);
        __CHECK_STRUCT_SIZE(CNSBlockSysManager);
        __CHECK_STRUCT_SIZE(SteamEngine::Win32::Net::CIOCompletionPort);
        __CHECK_STRUCT_SIZE(SteamEngine::Win32::System::CIOCompletionHandler);
        __CHECK_STRUCT_SIZE(SteamEngine::Win32::System::CIOCompletionWorker);
        __CHECK_STRUCT_SIZE(SteamEngine::Win32::Utility::COutputFile);
        __CHECK_STRUCT_SIZE(CNSConsole);
        __CHECK_STRUCT_SIZE(CMsgCounter);

        __CHECK_STRUCT_SIZE(CNSNpcState);
        __CHECK_STRUCT_SIZE(CNSNpcStateUnderground);
        __CHECK_STRUCT_SIZE(CNSNpcStateStand);
        __CHECK_STRUCT_SIZE(CNSNpcStateSkill);
        __CHECK_STRUCT_SIZE(CNSNpcStateRunaway);
        __CHECK_STRUCT_SIZE(CNSNpcStateReturn);
        __CHECK_STRUCT_SIZE(CNSNpcStateMove);
        __CHECK_STRUCT_SIZE(CNSNpcStateGlobal);
        __CHECK_STRUCT_SIZE(CNSNpcStateDead);
        __CHECK_STRUCT_SIZE(CNSNpcStateAttack);

        

#undef __CHECK_STRUCT_SIZE
#undef __CHECK_STRUCT_OFFSET
	}

};

#endif