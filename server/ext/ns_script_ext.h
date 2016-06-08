#ifndef SERVER_EXT_NS_SCRIPT_EXT_H_
#define SERVER_EXT_NS_SCRIPT_EXT_H_


class NSScriptExt {
public:
    static bool Init(lua_State *L, CNSNpcExt *pNpc, CNSPc *pPc);

    static int __cdecl RaceChangeOpen(lua_State *L);

	static int __cdecl CustomItemStart(lua_State *L);

	static int __cdecl GetOwnerGuildRank(lua_State *L);

	static int __cdecl GetOwnerGuildName(lua_State *L);

	static int __cdecl IsOwnerGuildNpc(lua_State *L);

	static int __cdecl GetOwnerGuildCell(lua_State *L);

	static int __cdecl GuildIconChangeOpen(lua_State *L);
};



#endif