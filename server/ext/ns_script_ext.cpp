#include "server/server_pch.h"

#include "server/ext/ns_script_ext.h"


bool NSScriptExt::Init(lua_State *L, CNSNpcExt *pNpc, CNSPc *pPc) {
    return true;
}

int __cdecl NSScriptRaceChangeOpen(lua_State *L) {
    //lua_warpper warpper(L);
    //
	//CNSPc *pc = warpper.get_table<CNSPc>("pCaller");
	//if (pc) {
	//	CPacket packet(CNSMessageId::ClientRaceChange);
	//	pc->SendMessageA(packet, 1);
	//}

	return 0;
}

int __cdecl NSScriptCustomItemStart(lua_State *L) {
    /*lua_warpper warpper(L);

	CNSPc *pc = warpper.get_table<CNSPc>("pCaller");
	CNSNpcExt *npc = warpper.get_table<CNSNpcExt>("pNpc");
	if (pc && npc) {
		CPacket packet(CNSMessageId::ClientCustomItemStart);
		packet.WriteUlong(npc->m_dwObjectId);
		pc->SendMessageA(packet, 1);
	}
    */
	return 0;
}

int __cdecl NSScriptGetOwnerGuildRank(lua_State *L) {
    lua_warpper warpper(L);
	int nResult = 0;

	CNSNpcExt *pNpc = warpper.get_table<CNSNpcExt>("pNpc");
	if (pNpc) {
        if (pNpc->m_nGuildBaseSeq > 0) {
            CNSObject::Owner<CNSGuild> pGuild = CNSPcManager::GetInstance()->GuildFind(pNpc->m_nGuildBaseSeq);
			if (pGuild != NULL) {
				nResult = pGuild->m_dwRankMonth;
			}
		}
	}

	warpper.lua_pushnumber(nResult);
	return 1;
}

int __cdecl NSScriptGetOwnerGuildName(lua_State *L) {
    lua_warpper warpper(L);
	char buffer[48] = "NULL";
	return 1;
}

int __cdecl NSScriptIsOwnerGuildNpc(lua_State *L) {
}

int __cdecl NSScriptGetOwnerGuildCell(lua_State *L) {
}

int __cdecl NSScriptGuildIconChangeOpen(lua_State *L) {
}