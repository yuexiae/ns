#include "server/server_pch.h"

#include "server/ext/ns_ext.h"
#include "base/util.h"
#include <boost/crc.hpp>

class NSScriptFilter {
public:
    static NSScript::_Invoke invoke_;

    static lua_State * NSScriptInitFilter(unsigned short wNpcId) {
        char *pszScript = CSingleton<CNSNpcParams>::GetInstance()->GetObjectNpcScript(wNpcId);
        if (pszScript) {
            lua_State *L = lua_open();
            lua_atpanic(L, NSScript::NSScriptPanic);
            luaopen_base(L);
            luaopen_io(L);
            luaopen_math(L);
            //luaopen_table(L);
            if (lua_dobuffer(L, pszScript, strlen(pszScript), "NSScriptInit") == 3) {
                GameUtil::Output("Error: NSScriptInit {Syntax Error(NpcId:%04x)\n", wNpcId);
                lua_close(L);
                return NULL;
            } else {
                return L;
            }
        } else {
            return NULL;
        }
    }

    static BOOL NSScriptNpcIdleFilter(lua_State *L, CNSNpc *pNpc, char *szFuncName) {
        SYSTEMTIME SystemTime;
        GetLocalTime(&SystemTime);

        lua_pushlightuserdata(L, pNpc);
        lua_pushstring(L, "pNpc");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);

        lua_pushnumber(L, (double)SystemTime.wYear);
        lua_pushstring(L, "localYear");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);

        lua_pushnumber(L, (double)SystemTime.wMonth);
        lua_pushstring(L, "localMonth");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);

        lua_pushnumber(L, (double)SystemTime.wDay);
        lua_pushstring(L, "localDay");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);

        lua_pushnumber(L, (double)SystemTime.wDayOfWeek);
        lua_pushstring(L, "localDayOfWeek");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);

        lua_pushnumber(L, (double)SystemTime.wHour);
        lua_pushstring(L, "localHour");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);

        lua_pushnumber(L, (double)SystemTime.wMinute);
        lua_pushstring(L, "localMinute");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);

        lua_pushnumber(L, (double)pNpc->m_btRegion);
        lua_pushstring(L, "npcRegion");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);

        lua_pushnumber(L, (double)pNpc->m_cell.x);
        lua_pushstring(L, "npcPosX");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);

        lua_pushnumber(L, (double)pNpc->m_cell.y);
        lua_pushstring(L, "npcPosY");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);

        lua_pushboolean(L, 0);
        lua_pushstring(L, "langKR");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);

        lua_pushboolean(L, 0);
        lua_pushstring(L, "langCN");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);

        lua_pushboolean(L, 0);
        lua_pushstring(L, "langJP");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);

        lua_pushboolean(L, 1);
        lua_pushstring(L, "langTW");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);

        lua_pushboolean(L, 0);
        lua_pushstring(L, "langEN");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);

        lua_pushstring(L, "WarpNpc");
        lua_pushcclosure(L, NSScript::NSScriptWarpNpc, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "Broadcast");
        lua_pushcclosure(L, NSScript::NSScriptBroadcast, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "BroadcastNotify");
        lua_pushcclosure(L, NSScript::NSScriptBroadcastNotify, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "CheckNpc");
        lua_pushcclosure(L, NSScript::NSScriptCheckNpc, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GetRectInPcCount");
        lua_pushcclosure(L, NSScript::NSScriptGetRectInPcCount, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GetRectInNpcCount");
        lua_pushcclosure(L, NSScript::NSScriptGetRectInNpcCount, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GetLocalTime");
        lua_pushcclosure(L, NSScript::NSScriptGetLocalTime, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "Disappear");
        lua_pushcclosure(L, NSScript::NSScriptDisappear, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "DeleteNpc");
        lua_pushcclosure(L, NSScript::NSScriptDeleteNpc, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "CallMob");
        lua_pushcclosure(L, NSScript::NSScriptCallMob, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "MakeBlockLarge");
        lua_pushcclosure(L, NSScript::NSScriptMakeBlockLarge, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "RideSiegeWeapon");
        lua_pushcclosure(L, NSScript::NSScriptRideSiegeWeapon, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "AddRealmPoint");
        lua_pushcclosure(L, NSScript::NSScriptAddRealmPoint, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "DeleteBlock");
        lua_pushcclosure(L, NSScript::NSScriptDeleteBlock, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "RVRStart");
        lua_pushcclosure(L, NSScript::NSScriptRVRStart, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "RVREnd");
        lua_pushcclosure(L, NSScript::NSScriptRVREnd, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "IsRVRStart");
        lua_pushcclosure(L, NSScript::NSScriptIsRVRStart, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "CheckCurrentRVREnd");
        lua_pushcclosure(L, NSScript::NSScriptCheckCurrentRVREnd, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GetFortressRealm");
        lua_pushcclosure(L, NSScript::NSScriptGetFortressRealm, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "SetFortressRealm");
        lua_pushcclosure(L, NSScript::NSScriptSetFortressRealm, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GetOldFortressRealm");
        lua_pushcclosure(L, NSScript::NSScriptGetOldFortressRealm, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "WarpArea");
        lua_pushcclosure(L, NSScript::NSScriptWarpArea, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "WarpArea2");
        lua_pushcclosure(L, NSScript::NSScriptWarpArea2, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GetZoneInfo");
        lua_pushcclosure(L, NSScript::NSScriptGetZoneInfo, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "IsRVRServerMode");
        lua_pushcclosure(L, NSScript::NSScriptIsRVRServerMode, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "WarpNpc");
        lua_pushcclosure(L, NSScript::NSScriptWarpNpc, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "HitBuff");
        lua_pushcclosure(L, NSScript::NSScriptHitBuff, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "BroadcastRealm");
        lua_pushcclosure(L, NSScript::NSScriptBroadcastRealm, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "BroadcastRealmTitle");
        lua_pushcclosure(L, NSScript::NSScriptBroadcastRealmTitle, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GetRectInPcCount2");
        lua_pushcclosure(L, NSScript::NSScriptGetRectInPcCount2, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GetRectInNpcCount2");
        lua_pushcclosure(L, NSScript::NSScriptGetRectInNpcCount2, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "RectInDisappearNpc2");
        lua_pushcclosure(L, NSScript::NSScriptRectInDisappearNpc2, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "AddRectInPcRealmPoint");
        lua_pushcclosure(L, NSScript::NSScriptAddRectInPcRealmPoint, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "AttackRectInNpc");
        lua_pushcclosure(L, NSScript::NSScriptAttackRectInNpc, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GetStartSecond");
        lua_pushcclosure(L, NSScript::NSScriptGetStartSecond, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "BroadcastCenter");
        lua_pushcclosure(L, NSScript::NSScriptBroadcastCenter, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "AutoRectInPartyJoin");
        lua_pushcclosure(L, NSScript::NSScriptAutoRectInPartyJoin, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GetRectInPcAvrLevel");
        lua_pushcclosure(L, NSScript::NSScriptGetRectInPcAvrLevel, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GetHpPercent");
        lua_pushcclosure(L, NSScript::NSScriptGetHpPercent, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "IsAggro");
        lua_pushcclosure(L, NSScript::NSScriptIsAggro, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "AttackRectInPc");
        lua_pushcclosure(L, NSScript::NSScriptAttackRectInPc, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "LevelUpRectInPc");
        lua_pushcclosure(L, NSScript::NSScriptLevelUpRectInPc, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "SelfBuff");
        lua_pushcclosure(L, NSScript::NSScriptSelfBuff, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "ReserveStart");
        lua_pushcclosure(L, NSScript::NSScriptReserveStart, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "ReserveEnd");
        lua_pushcclosure(L, NSScript::NSScriptReserveEnd, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "ReserveWarp");
        lua_pushcclosure(L, NSScript::NSScriptReserveWarp, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "ReserveIsStart");
        lua_pushcclosure(L, NSScript::NSScriptReserveIsStart, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "AwakeRectInNpc");
        lua_pushcclosure(L, NSScript::NSScriptAwakeRectInNpc, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "HealRectInNpc");
        lua_pushcclosure(L, NSScript::NSScriptHealRectInNpc, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GetRectInNpcHpPercent");
        lua_pushcclosure(L, NSScript::NSScriptGetRectInNpcHpPercent, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "EffectSkillCast");
        lua_pushcclosure(L, NSScript::NSScriptEffectSkillCast, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "HealRectInPersonalSiegeWeapon");
        lua_pushcclosure(L, NSScript::NSScriptHealRectInPersonalSiegeWeapon, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "AddExpHitLastPc");
        lua_pushcclosure(L, NSScript::NSScriptAddExpHitLastPc, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GetHitLastPcRealm");
        lua_pushcclosure(L, NSScript::NSScriptGetHitLastPcRealm, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "AddRectInPcExpPoint");
        lua_pushcclosure(L, NSScript::NSScriptAddRectInPcExpPoint, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "HitRectInPcDebuff");
        lua_pushcclosure(L, NSScript::NSScriptHitRectInPcDebuff, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "BroadcastBuff2");
        lua_pushcclosure(L, NSScript::NSScriptBroadcastBuff2, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "IsPVEServerMode");
        lua_pushcclosure(L, NSScript::NSScriptIsPVEServerMode, 0);
        lua_settable(L, LUA_GLOBALSINDEX);

        lua_getglobal(L, "__Init__");
        if (!lua_isfunction(L, lua_gettop(L))) {
            lua_settop(L, -2);
            return FALSE;
        }

        if (lua_pcall(L, 0, 0, 0)) {
            GameUtil::Output("Error: NSScriptNpcIdle {Call %s(NpcId:%04x) '%s'}\n", "__Init__", pNpc->m_wNpcId, lua_tostring(L, -1));
            lua_settop(L, -2);
            return FALSE;
        }

        lua_getglobal(L, szFuncName);
        if (!lua_isfunction(L, lua_gettop(L))) {
            lua_settop(L, -2);
            return FALSE;
        }

        if (lua_pcall(L, 0, 0, 0)){
            GameUtil::Output("Error: NSScriptNpcIdle {Call %s(NpcId:%04x) '%s'}\n", szFuncName, pNpc->m_wNpcId, lua_tostring(L, -1));
            lua_settop(L, -2);
            return FALSE;
        } 

        lua_getglobal(L, "msg");
        char *msg = (char *)lua_tostring(L, lua_gettop(L));
        lua_settop(L, -2);

        if (msg && *msg) {
            CPacket packet(0x3011u);
            packet.WriteUChar('M');
            packet.WriteData(pNpc->m_szNpcName, strlen(pNpc->m_szNpcName));
            packet.WriteData(" : ", strlen(" : "));
            packet.WriteString(msg);
            packet.WriteULong(pNpc->m_dwObjectId);
            pNpc->Broadcast(packet, 0, 0x258u);
        }
        return TRUE;
    }

    static BOOL NSScriptNpcTalkFilter(lua_State *L, CNSNpcExt *pNpc, CNSPcExt *pCaller, char *szKey, CPacket& packet) {
        if (strcmp(szKey, "Hello") != 0) {
            boost::crc_32_type crc;
		    crc.process_bytes(szKey, strlen(szKey));
            std::vector<unsigned int>::iterator iter = std::find(pCaller->m_NpcMenuKey.begin(), pCaller->m_NpcMenuKey.end(), crc.checksum());
            if (iter == pCaller->m_NpcMenuKey.end()) {
                pCaller->m_NpcMenuKey.clear();
                pCaller->SendSystemMessage("permission denied('%s')", szKey);
                return FALSE;
            }

            pCaller->m_NpcMenuKey.clear();

            if (strcmp(szKey, "ReloadScript") == 0) {
                pNpc->m_bReloadScript = true;
                pCaller->SendSystemMessage("ReloadScript set flag success");
                return FALSE;
            }
        }
        
        SYSTEMTIME SystemTime;
        GetLocalTime(&SystemTime);

        lua_pushnumber(L, (double)0x01);
        lua_pushstring(L, "Fighter");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushnumber(L, (double)0x02);
        lua_pushstring(L, "Warrior");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushnumber(L, (double)0x03);
        lua_pushstring(L, "Paladin");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushnumber(L, (double)0x21);
        lua_pushstring(L, "Magician");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushnumber(L, (double)0x22);
        lua_pushstring(L, "Wizard");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushnumber(L, (double)0x23);
        lua_pushstring(L, "Summoner");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushnumber(L, (double)0x41);
        lua_pushstring(L, "Technician");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushnumber(L, (double)0x42);
        lua_pushstring(L, "Engineer");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushnumber(L, (double)0x43);
        lua_pushstring(L, "Blacksmith");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushnumber(L, (double)0x61);
        lua_pushstring(L, "Rogue");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushnumber(L, (double)0x62);
        lua_pushstring(L, "Hunter");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushnumber(L, (double)0x63);
        lua_pushstring(L, "Thief");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);

        lua_pushlightuserdata(L, pNpc);
        lua_pushstring(L, "pNpc");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);

        lua_pushlightuserdata(L, pCaller);
        lua_pushstring(L, "pCaller");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);

        lua_pushnumber(L, (double)pCaller->m_btJob);
        lua_pushstring(L, "userJob");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);

        lua_pushnumber(L, (double)pCaller->m_btLevel);
        lua_pushstring(L, "userLevel");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);

        lua_pushnumber(L, (double)pCaller->m_btRace);
        lua_pushstring(L, "userRace");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);

        lua_pushnumber(L, pCaller->m_dwGold);
        lua_pushstring(L, "userGold");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);

        lua_pushnumber(L, (double)pCaller->GetNs());
        lua_pushstring(L, "userNeoSteam");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);

        lua_pushstring(L, pCaller->m_szUserAlias);
        lua_pushstring(L, "userAlias");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);

        lua_pushstring(L, pCaller->m_szUserId);
        lua_pushstring(L, "userId");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);

        lua_pushnumber(L, (double)pCaller->m_btRealm);
        lua_pushstring(L, "userRealm");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);

        lua_pushnumber(L, (double)pCaller->m_wNsCharge);
        lua_pushstring(L, "userNeoSteamCharge");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);

        lua_pushnumber(L, (double)pCaller->m_dwGuildId);
        lua_pushstring(L, "userGuildId");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);

        lua_pushnumber(L, (double)pCaller->m_btRank);
        lua_pushstring(L, "userRank");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);

        lua_pushnumber(L, (double)pCaller->m_btSp);
        lua_pushstring(L, "userSp");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);

        lua_pushnumber(L, (double)pNpc->m_wNpcId);
        lua_pushstring(L, "npcId");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);

        lua_pushnumber(L, (double)pNpc->m_btRegion);
        lua_pushstring(L, "npcRegion");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);

        lua_pushnumber(L, (double)pNpc->m_cell.x);
        lua_pushstring(L, "npcPosX");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);

        lua_pushnumber(L, (double)pNpc->m_cell.y);
        lua_pushstring(L, "npcPosY");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);

        lua_pushnumber(L, (double)pCaller->m_PetInfo.btPetKind);
        lua_pushstring(L, "petKind");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);

        lua_pushnumber(L, (double)pCaller->m_PetInfo.btLevel);
        lua_pushstring(L, "petLevel");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);

        lua_pushnumber(L, (double)pCaller->m_PetInfo.btGrade);
        lua_pushstring(L, "petGrade");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);

        lua_pushnumber(L, (double)SystemTime.wYear);
        lua_pushstring(L, "localYear");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);

        lua_pushnumber(L, (double)SystemTime.wMonth);
        lua_pushstring(L, "localMonth");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);

        lua_pushnumber(L, (double)SystemTime.wDay);
        lua_pushstring(L, "localDay");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);

        lua_pushnumber(L, (double)SystemTime.wDayOfWeek);
        lua_pushstring(L, "localDayOfWeek");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);

        lua_pushnumber(L, (double)SystemTime.wHour);
        lua_pushstring(L, "localHour");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);

        lua_pushnumber(L, (double)SystemTime.wMinute);
        lua_pushstring(L, "localMinute");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);

        lua_pushboolean(L, 0);
        lua_pushstring(L, "langKR");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);

        lua_pushboolean(L, 0);
        lua_pushstring(L, "langCN");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);

        lua_pushboolean(L, 0);
        lua_pushstring(L, "langJP");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);

        lua_pushboolean(L, 1);
        lua_pushstring(L, "langTW");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);

        lua_pushboolean(L, 0);
        lua_pushstring(L, "langEN");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);

        lua_pushnumber(L, pCaller->GetAdminLevel());
        lua_pushstring(L, "userAdminLevel");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);
        
        lua_pushboolean(L, strcmp(szKey, "Hello") == 0);
        lua_pushstring(L, "isHello");
        lua_insert(L, -2);
        lua_settable(L, LUA_GLOBALSINDEX);

        lua_pushstring(L, "GetServerHour");
        lua_pushcclosure(L, NSScript::NSScriptGetServerHour, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GetServerMinute");
        lua_pushcclosure(L, NSScript::NSScriptGetServerMinute, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GetItemCount");
        lua_pushcclosure(L, NSScript::NSScriptGetItemCount, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GetSkillLevel");
        lua_pushcclosure(L, NSScript::NSScriptGetSkillLevel, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GetInvenSpace");
        lua_pushcclosure(L, NSScript::NSScriptGetInvenSpace, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "AddExp");
        lua_pushcclosure(L, NSScript::NSScriptAddExp, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "AddGold");
        lua_pushcclosure(L, NSScript::NSScriptAddGold, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "AddItem");
        lua_pushcclosure(L, NSScript::NSScriptAddItem, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "AddItem2");
        lua_pushcclosure(L, NSScript::NSScriptAddItem2, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "AddItem3");
        lua_pushcclosure(L, NSScript::NSScriptAddItem3, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "AddQuest");
        lua_pushcclosure(L, NSScript::NSScriptAddQuest, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "AddPoint");
        lua_pushcclosure(L, NSScript::NSScriptAddPoint, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "AddNeoSteam");
        lua_pushcclosure(L, NSScript::NSScriptAddNeoSteam, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GiveNeoSteam");
        lua_pushcclosure(L, NSScript::NSScriptGiveNeoSteam, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GetPoint");
        lua_pushcclosure(L, NSScript::NSScriptGetPoint, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GiveGold");
        lua_pushcclosure(L, NSScript::NSScriptGiveGold, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "DeleteItem");
        lua_pushcclosure(L, NSScript::NSScriptDeleteItem, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "CheckItem");
        lua_pushcclosure(L, NSScript::NSScriptCheckItem, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "CheckEquipItem");
        lua_pushcclosure(L, NSScript::NSScriptCheckEquipItem, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "CheckQuest");
        lua_pushcclosure(L, NSScript::NSScriptCheckQuest, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "CheckCompleteStep");
        lua_pushcclosure(L, NSScript::NSScriptCheckCompleteStep, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GetStep");
        lua_pushcclosure(L, NSScript::NSScriptGetStep, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "SetStep");
        lua_pushcclosure(L, NSScript::NSScriptSetStep, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "SetNextStep");
        lua_pushcclosure(L, NSScript::NSScriptSetNextStep, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "SetClear");
        lua_pushcclosure(L, NSScript::NSScriptSetClear, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "SetQuestComplete");
        lua_pushcclosure(L, NSScript::NSScriptSetQuestComplete, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GetQuestComplete");
        lua_pushcclosure(L, NSScript::NSScriptGetQuestComplete, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "TameMobExist");
        lua_pushcclosure(L, NSScript::NSScriptTameMobExist, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "TameMobLoad");
        lua_pushcclosure(L, NSScript::NSScriptTameMobLoad, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "TameMobSave");
        lua_pushcclosure(L, NSScript::NSScriptTameMobSave, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "ProductList");
        lua_pushcclosure(L, NSScript::NSScriptProductList, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "MaterialList");
        lua_pushcclosure(L, NSScript::NSScriptMaterialList, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "CallMob");
        lua_pushcclosure(L, NSScript::NSScriptCallMob, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "ShopList");
        lua_pushcclosure(L, NSScript::NSScriptShopList, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "ChangeJob");
        lua_pushcclosure(L, NSScript::NSScriptChangeJob, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "ChangeBindPos");
        lua_pushcclosure(L, NSScript::NSScriptChangeBindPos, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "Warp");
        lua_pushcclosure(L, NSScript::NSScriptWarp, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "WarpParty");
        lua_pushcclosure(L, NSScript::NSScriptWarpParty, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "WarpGuild");
        lua_pushcclosure(L, NSScript::NSScriptWarpGuild, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "WarpAndBind");
        lua_pushcclosure(L, NSScript::NSScriptWarpAndBind, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "Disappear");
        lua_pushcclosure(L, NSScript::NSScriptDisappear, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "EventStart");
        lua_pushcclosure(L, NSScript::NSScriptEventStart, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GetDescriptNpc");
        lua_pushcclosure(L, NSScript::NSScriptGetDescriptNpc, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GetDescriptItem");
        lua_pushcclosure(L, NSScript::NSScriptGetDescriptItem, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "TransferMachine");
        lua_pushcclosure(L, NSScript::NSScriptTransferMachine, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "ChangePet");
        lua_pushcclosure(L, NSScript::NSScriptChangePet, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "PetMessage");
        lua_pushcclosure(L, NSScript::NSScriptPetMessage, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "ResolutionStart");
        lua_pushcclosure(L, NSScript::NSScriptResolutionStart, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "UpgradeStart");
        lua_pushcclosure(L, NSScript::NSScriptUpgradeStart, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "RecombinationStart");
        lua_pushcclosure(L, NSScript::NSScriptRecombinationStart, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "IsPartyMember");
        lua_pushcclosure(L, NSScript::NSScriptIsPartyMember, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "DeleteNpc");
        lua_pushcclosure(L, NSScript::NSScriptDeleteNpc, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "DisappearNpc");
        lua_pushcclosure(L, NSScript::NSScriptDisappearNpc, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "CheckNpc");
        lua_pushcclosure(L, NSScript::NSScriptCheckNpc, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "Gathering");
        lua_pushcclosure(L, NSScript::NSScriptItemGathering, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "Unlock");
        lua_pushcclosure(L, NSScript::NSScriptItemUnlock, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "Mining");
        lua_pushcclosure(L, NSScript::NSScriptItemMining, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "SetTimeOut");
        lua_pushcclosure(L, NSScript::NSScriptSetTimeOut, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "CheckTimeOut");
        lua_pushcclosure(L, NSScript::NSScriptCheckTimeOut, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "IsTimeOut");
        lua_pushcclosure(L, NSScript::NSScriptIsTimeOut, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "ClearTimeOut");
        lua_pushcclosure(L, NSScript::NSScriptClearTimeOut, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "WarpNpc");
        lua_pushcclosure(L, NSScript::NSScriptWarpNpc, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GetPetExpPercent");
        lua_pushcclosure(L, NSScript::NSScriptGetPetExpPercent, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "ChangePetLevel");
        lua_pushcclosure(L, NSScript::NSScriptChangePetLevel, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "UpgradePet");
        lua_pushcclosure(L, NSScript::NSScriptUpgradePet, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GetNsCharge");
        lua_pushcclosure(L, NSScript::NSScriptGetNsCharge, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GetNsMaxCharge");
        lua_pushcclosure(L, NSScript::NSScriptGetNsMaxCharge, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "Broadcast");
        lua_pushcclosure(L, NSScript::NSScriptBroadcast, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "BroadcastNotify");
        lua_pushcclosure(L, NSScript::NSScriptBroadcastNotify, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GuildList");
        lua_pushcclosure(L, NSScript::NSScriptGuildList, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GuildCreate");
        lua_pushcclosure(L, NSScript::NSScriptGuildCreate, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GuildClose");
        lua_pushcclosure(L, NSScript::NSScriptGuildClose, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "AddSkillExp");
        lua_pushcclosure(L, NSScript::NSScriptAddSkillExp, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "WareHouseList");
        lua_pushcclosure(L, NSScript::NSScriptWareHouseList, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "SkillReset");
        lua_pushcclosure(L, NSScript::NSScriptSkillReset, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GetLocalTime");
        lua_pushcclosure(L, NSScript::NSScriptGetLocalTime, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "WarpArea");
        lua_pushcclosure(L, NSScript::NSScriptWarpArea, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "IsAdmin");
        lua_pushcclosure(L, NSScript::NSScriptIsAdmin, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "WarpBind");
        lua_pushcclosure(L, NSScript::NSScriptWarpBind, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GetRectInPcCount");
        lua_pushcclosure(L, NSScript::NSScriptGetRectInPcCount, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "DialogOpen");
        lua_pushcclosure(L, NSScript::NSScriptDialogOpen, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "PetRebirth");
        lua_pushcclosure(L, NSScript::NSScriptPetRebirth, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "AutoSkill");
        lua_pushcclosure(L, NSScript::NSScriptAutoSkill, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GetGuildMemberCount");
        lua_pushcclosure(L, NSScript::NSScriptGetGuildMemberCount, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GetGuildMemberLevel");
        lua_pushcclosure(L, NSScript::NSScriptGetGuildMemberLevel, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GetGuildLevel");
        lua_pushcclosure(L, NSScript::NSScriptGetGuildLevel, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "ChangeGuildLevel");
        lua_pushcclosure(L, NSScript::NSScriptChangeGuildLevel, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "IsGuildMaster");
        lua_pushcclosure(L, NSScript::NSScriptIsGuildMaster, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GetGuildPoint");
        lua_pushcclosure(L, NSScript::NSScriptGetGuildPoint, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "AddGuildPoint");
        lua_pushcclosure(L, NSScript::NSScriptAddGuildPoint, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GiveGuildPoint");
        lua_pushcclosure(L, NSScript::NSScriptGiveGuildPoint, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GetRiderId");
        lua_pushcclosure(L, NSScript::NSScriptGetRiderId, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "TameMobInsert");
        lua_pushcclosure(L, NSScript::NSScriptTameMobInsert, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "PartyAvrLevel");
        lua_pushcclosure(L, NSScript::NSScriptPartyAvrLevel, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GetRectInNpcCount");
        lua_pushcclosure(L, NSScript::NSScriptGetRectInNpcCount, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "RectInDisappearNpc");
        lua_pushcclosure(L, NSScript::NSScriptRectInDisappearNpc, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "WarpDelay");
        lua_pushcclosure(L, NSScript::NSScriptWarpDelay, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GetRemainTime");
        lua_pushcclosure(L, NSScript::NSScriptGetRemainTime, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "MakeBlockLarge");
        lua_pushcclosure(L, NSScript::NSScriptMakeBlockLarge, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "MakeBlockMiniRVR");
        lua_pushcclosure(L, NSScript::NSScriptMakeBlockMiniRVR, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "RideSiegeWeapon");
        lua_pushcclosure(L, NSScript::NSScriptRideSiegeWeapon, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GetRealmPoint");
        lua_pushcclosure(L, NSScript::NSScriptGetRealmPoint, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "AddRealmPoint");
        lua_pushcclosure(L, NSScript::NSScriptAddRealmPoint, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GiveRealmPoint");
        lua_pushcclosure(L, NSScript::NSScriptGiveRealmPoint, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "DeleteBlock");
        lua_pushcclosure(L, NSScript::NSScriptDeleteBlock, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "RVRStart");
        lua_pushcclosure(L, NSScript::NSScriptRVRStart, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "RVREnd");
        lua_pushcclosure(L, NSScript::NSScriptRVREnd, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "IsRVRStart");
        lua_pushcclosure(L, NSScript::NSScriptIsRVRStart, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "CheckCurrentRVREnd");
        lua_pushcclosure(L, NSScript::NSScriptCheckCurrentRVREnd, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GetFortressRealm");
        lua_pushcclosure(L, NSScript::NSScriptGetFortressRealm, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "SetFortressRealm");
        lua_pushcclosure(L, NSScript::NSScriptSetFortressRealm, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GetOldFortressRealm");
        lua_pushcclosure(L, NSScript::NSScriptGetOldFortressRealm, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "WarpArea2");
        lua_pushcclosure(L, NSScript::NSScriptWarpArea2, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GetZoneInfo");
        lua_pushcclosure(L, NSScript::NSScriptGetZoneInfo, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GetPcZoneInfo");
        lua_pushcclosure(L, NSScript::NSScriptGetPcZoneInfo, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "IsRVRServerMode");
        lua_pushcclosure(L, NSScript::NSScriptIsRVRServerMode, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "PartyMemberCount");
        lua_pushcclosure(L, NSScript::NSScriptPartyMemberCount, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "WarpAndStun");
        lua_pushcclosure(L, NSScript::NSScriptWarpAndStun, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "WarpAndClarity");
        lua_pushcclosure(L, NSScript::NSScriptWarpAndClarity, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GetRectInPcCount2");
        lua_pushcclosure(L, NSScript::NSScriptGetRectInPcCount2, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GetRectInNpcCount2");
        lua_pushcclosure(L, NSScript::NSScriptGetRectInNpcCount2, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "RectInDisappearNpc2");
        lua_pushcclosure(L, NSScript::NSScriptRectInDisappearNpc2, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GetRectInSiegeWeaponCount");
        lua_pushcclosure(L, NSScript::NSScriptGetRectInSiegeWeaponCount, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "HitBuff");
        lua_pushcclosure(L, NSScript::NSScriptHitBuff, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "BroadcastBuff");
        lua_pushcclosure(L, NSScript::NSScriptBroadcastBuff, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "HitPartyBuff");
        lua_pushcclosure(L, NSScript::NSScriptHitPartyBuff, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "BroadcastRealm");
        lua_pushcclosure(L, NSScript::NSScriptBroadcastRealm, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "BroadcastRealmTitle");
        lua_pushcclosure(L, NSScript::NSScriptBroadcastRealmTitle, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "SteamCoreDestroy");
        lua_pushcclosure(L, NSScript::NSScriptSteamCoreDestroy, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "SteamCoreDestroy2");
        lua_pushcclosure(L, NSScript::NSScriptSteamCoreDestroy2, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "SteamCoreDestroy3");
        lua_pushcclosure(L, NSScript::NSScriptSteamCoreDestroy3, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "AddRectInPcRealmPoint");
        lua_pushcclosure(L, NSScript::NSScriptAddRectInPcRealmPoint, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "AttackRectInNpc");
        lua_pushcclosure(L, NSScript::NSScriptAttackRectInNpc, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "AwakeRectInNpc");
        lua_pushcclosure(L, NSScript::NSScriptAwakeRectInNpc, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "HealRectInNpc");
        lua_pushcclosure(L, NSScript::NSScriptHealRectInNpc, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GetStartSecond");
        lua_pushcclosure(L, NSScript::NSScriptGetStartSecond, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "BroadcastCenter");
        lua_pushcclosure(L, NSScript::NSScriptBroadcastCenter, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "AutoRectInPartyJoin");
        lua_pushcclosure(L, NSScript::NSScriptAutoRectInPartyJoin, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GetRectInPcAvrLevel");
        lua_pushcclosure(L, NSScript::NSScriptGetRectInPcAvrLevel, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "CallNpc");
        lua_pushcclosure(L, NSScript::NSScriptCallNpc, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GetRectInMyParty");
        lua_pushcclosure(L, NSScript::NSScriptGetRectInMyParty, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "AddNeoSlotCoin");
        lua_pushcclosure(L, NSScript::NSScriptNeoSlotCoinAdd, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GetNeoSlotCoin");
        lua_pushcclosure(L, NSScript::NSScriptNeoSlotCoinCount, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "AutoMining");
        lua_pushcclosure(L, NSScript::NSScriptItemAutoMining, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "AddSkill");
        lua_pushcclosure(L, NSScript::NSScriptAddSkill, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "SkillLevelUp");
        lua_pushcclosure(L, NSScript::NSScriptSkillLevelUp, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GetHpPercent");
        lua_pushcclosure(L, NSScript::NSScriptGetHpPercent, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "IsAggro");
        lua_pushcclosure(L, NSScript::NSScriptIsAggro, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        //lua_pushstring(L, "LevelUp100");
        //lua_pushcclosure(L, NSScript::NSScriptLevelUp100, 0);
        //lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "IsMaxExp");
        lua_pushcclosure(L, NSScript::NSScriptIsMaxExp, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "SkillChange");
        lua_pushcclosure(L, NSScript::NSScriptSkillChange, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "PVPTournamentStart");
        lua_pushcclosure(L, NSScript::NSScriptPVPTournamentStart, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "PVPTournamentEnd");
        lua_pushcclosure(L, NSScript::NSScriptPVPTournamentEnd, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "IsPVPTournamentStart");
        lua_pushcclosure(L, NSScript::NSScriptIsPVPTournamentStart, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "ReserveStart");
        lua_pushcclosure(L, NSScript::NSScriptReserveStart, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "ReserveEnd");
        lua_pushcclosure(L, NSScript::NSScriptReserveEnd, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "ReserveWarp");
        lua_pushcclosure(L, NSScript::NSScriptReserveWarp, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "ReserveAdd");
        lua_pushcclosure(L, NSScript::NSScriptReserveAdd, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "ReserveDelete");
        lua_pushcclosure(L, NSScript::NSScriptReserveDelete, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "ReserveIsStart");
        lua_pushcclosure(L, NSScript::NSScriptReserveIsStart, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GetRectInNpcHpPercent");
        lua_pushcclosure(L, NSScript::NSScriptGetRectInNpcHpPercent, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "ChangeRace");
        lua_pushcclosure(L, NSScript::NSScriptChangeRace, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "IsEquipRemoveAll");
        lua_pushcclosure(L, NSScript::NSScriptIsEquipRemoveAll, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "PSWFactory");
        lua_pushcclosure(L, NSScript::NSScriptPSWFactory, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        //lua_pushstring(L, "SkillMake60");
        //lua_pushcclosure(L, NSScript::NSScriptSkillMake60, 0);
        //lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "IsExistSkill");
        lua_pushcclosure(L, NSScript::NSScriptIsExistSkill, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "RidePSW");
        lua_pushcclosure(L, NSScript::NSScriptRidePersonalSiegeWeapon, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GetGuildMemberRank");
        lua_pushcclosure(L, NSScript::NSScriptGetGuildMemberRank, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "PrintGuildLog");
        lua_pushcclosure(L, NSScript::NSScriptPrintGuildLog, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "EffectSkillCast");
        lua_pushcclosure(L, NSScript::NSScriptEffectSkillCast, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "WareHouseSort");
        lua_pushcclosure(L, NSScript::NSScriptWareHouseSort, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "HealRectInPersonalSiegeWeapon");
        lua_pushcclosure(L, NSScript::NSScriptHealRectInPersonalSiegeWeapon, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "PcTitleAdd");
        lua_pushcclosure(L, NSScript::NSScriptPcTitleAdd, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GetGuildRankMonth");
        lua_pushcclosure(L, NSScript::NSScriptGetGuildRankMonth, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "AddRectInPcItem");
        lua_pushcclosure(L, NSScript::NSScriptAddRectInPcItem, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "ChangeGuildMark");
        lua_pushcclosure(L, NSScript::NSScriptChangeGuildMark, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "SkillPSWPartReset");
        lua_pushcclosure(L, NSScript::NSScriptSkillPSWPartReset, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "AddGuildPremiumItem");
        lua_pushcclosure(L, NSScript::NSScriptAddGuildPremiumItem, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GetGuildPremiumItemDays");
        lua_pushcclosure(L, NSScript::NSScriptGetGuildPremiumItemDays, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "PcTitleIsExist");
        lua_pushcclosure(L, NSScript::NSScriptPcTitleIsExist, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "PcTitleGetCount");
        lua_pushcclosure(L, NSScript::NSScriptPcTitleGetCount, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "GetGuildRankMonthName");
        lua_pushcclosure(L, NSScript::NSScriptGetGuildRankMonthName, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "BroadcastBuff2");
        lua_pushcclosure(L, NSScript::NSScriptBroadcastBuff2, 0);
        lua_settable(L, LUA_GLOBALSINDEX);
        lua_pushstring(L, "IsPVEServerMode");
        lua_pushcclosure(L, NSScript::NSScriptIsPVEServerMode, 0);
        lua_settable(L, LUA_GLOBALSINDEX);

        //add
        NSScriptExt::Init(L, pNpc, pCaller);

        lua_getglobal(L, "__Init__");
        if (!lua_isfunction(L, lua_gettop(L))) {
            lua_settop(L, -2);
            return FALSE;
        }

        if (lua_pcall(L, 0, 0, 0)) {
            GameUtil::Output("Error: NSScriptNpcTalk {NpcId:%04x, Key:%s, Msg:%s}\n", pNpc->m_wNpcId, szKey, lua_tostring(L, -1));
            lua_settop(L, -2);
            return FALSE;
        }

        lua_getglobal(L, szKey);
        if (!lua_isfunction(L, lua_gettop(L))) {
            lua_settop(L, -2);
            return FALSE;
        }

        if (lua_pcall(L, 0, 0, 0)){
            GameUtil::Output("Error: NSScriptNpcTalk {NpcId:%04x, Key:%s, Msg:%s}\n", pNpc->m_wNpcId, szKey, lua_tostring(L, -1));
            lua_settop(L, -2);
            return FALSE;
        }

        lua_getglobal(L, "msg");
        char *msg = (char *)lua_tostring(L, lua_gettop(L));
        lua_settop(L, -2);


        lua_getglobal(L, "__menu");
        char *menu_string = (char *)lua_tostring(L, lua_gettop(L));
        lua_settop(L, -2);

        unsigned int menu_count = 0;
        char *temp = menu_string;
        while (true) {
            char *end = NULL;
            if (end = (char *)_mbschr((unsigned char *)temp, '|')) {
                *end = '\0';
                temp = end + 1;
            } else {
                break;
            }
            
            if (end = (char *)_mbschr((unsigned char *)temp, '|')) {
                *end = '\0';

                boost::crc_32_type crc;
		        crc.process_bytes(temp, strlen(temp));
                pCaller->m_NpcMenuKey.push_back(crc.checksum());

                temp = end + 1;
            } else {
                break;
            }

            ++menu_count;
        }

        if (msg && menu_count > 0){
            packet.WriteString(msg);
            packet.WriteUChar(menu_count);
            packet.WriteData(menu_string, temp - menu_string);
            return TRUE;
        }
        
        if (!msg) {
            return TRUE;
        }

        if (*msg){
            CPacket packeta(0x3011u);
            packeta.WriteUChar(1);
            packeta.WriteData("^[M", strlen("^[M"));
            char *chat_head_whisper = CSingleton<CNSMsgParams>::GetInstance()->GetObjectA(NS_MSG_CHAT_HEAD_WHISPER);
            packeta.WriteData(chat_head_whisper, strlen(chat_head_whisper));
            packeta.WriteData(pNpc->m_szNpcName, strlen(pNpc->m_szNpcName));
            packeta.WriteString(msg);
            packeta.WriteULong(pNpc->m_dwObjectId);
            pCaller->SendMessageA(packeta, 1);
        }

        return FALSE;
    }

};

NSScript::_Invoke NSScriptFilter::invoke_;

bool NSScriptFilterInit() {
    return NSScript::_PatchNSScriptInit(&NSScriptFilter::NSScriptInitFilter)
        && NSScript::_PatchNSScriptNpcIdle(&NSScriptFilter::NSScriptNpcIdleFilter)
        && NSScript::_PatchNSScriptNpcTalk(&NSScriptFilter::NSScriptNpcTalkFilter);
}