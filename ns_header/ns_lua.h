#ifndef NSHEADER_NS_LUA_H_
#define NSHEADER_NS_LUA_H_

extern "C" {
#include "third-party/lua/lua.h"
#include "third-party/lua/lualib.h"
#include "third-party/lua/lauxlib.h"
#ifdef DEFINE_NS_CPP
DEFINE_NAKED_JMP(lua_Number lua_tonumber (lua_State *L _COMMA int idx), 0x4e5680)
DEFINE_NAKED_JMP(lua_State *lua_newthread (lua_State *L), 0x4e5320)
DEFINE_NAKED_JMP(void lua_pushnil (lua_State *L), 0x4e58c0)
DEFINE_NAKED_JMP(void *lua_newuserdata (lua_State *L _COMMA size_t sz), 0x4e60a0)
DEFINE_NAKED_JMP(int lua_toboolean (lua_State *L _COMMA int idx), 0x4e56d0)
DEFINE_NAKED_JMP(lua_State *lua_tothread (lua_State *L _COMMA int idx), 0x4e5820)
DEFINE_NAKED_JMP(int lua_getinfo (lua_State *L _COMMA const char *what, lua_Debug *ar), 0x4ec110)
DEFINE_NAKED_JMP(void lua_remove (lua_State *L _COMMA int idx), 0x4e53c0)
DEFINE_NAKED_JMP(void lua_insert (lua_State *L _COMMA int idx), 0x4e5410)
DEFINE_NAKED_JMP(int lua_getgccount (lua_State *L), 0x4e5f80)
DEFINE_NAKED_JMP(const char *lua_pushvfstring (lua_State *L _COMMA const char *fmt, va_list argp), 0x4e59b0)
DEFINE_NAKED_JMP(void lua_getfenv (lua_State *L _COMMA int idx), 0x4e5c80)
DEFINE_NAKED_JMP(int lua_yield (lua_State *L _COMMA int nresults), 0x4e6e40)
DEFINE_NAKED_JMP(int lua_getgcthreshold (lua_State *L), 0x4e5f70)
DEFINE_NAKED_JMP(int lua_iscfunction (lua_State *L _COMMA int idx), 0x4e5540)
DEFINE_NAKED_JMP(void lua_settop (lua_State *L _COMMA int idx), 0x4e5370)
DEFINE_NAKED_JMP(void lua_close (lua_State *L), 0x4e6490)
//DEFINE_NAKED_JMP(lua_ident, 0x412980)
DEFINE_NAKED_JMP(int lua_getmetatable (lua_State *L _COMMA int objindex), 0x4e5c10)
DEFINE_NAKED_JMP(lua_State *lua_open (void), 0x4e6400)
DEFINE_NAKED_JMP(void	 *lua_touserdata (lua_State *L _COMMA int idx), 0x4e57e0)
DEFINE_NAKED_JMP(int lua_rawequal (lua_State *L _COMMA int idx1 _COMMA int idx2), 0x4e5610)
DEFINE_NAKED_JMP(void lua_call (lua_State *L _COMMA int nargs _COMMA int nresults), 0x4e5e70)
DEFINE_NAKED_JMP(void lua_replace (lua_State *L _COMMA int idx), 0x4e5470)
DEFINE_NAKED_JMP(const char *lua_pushfstring (lua_State *L _COMMA const char *fmt, ...), 0x4e59e0)
DEFINE_NAKED_JMP(void lua_concat (lua_State *L _COMMA int n), 0x4e6030)
DEFINE_NAKED_JMP(int lua_pcall (lua_State *L _COMMA int nargs _COMMA int nresults _COMMA int errfunc), 0x4e5eb0)
DEFINE_NAKED_JMP(void lua_pushcclosure (lua_State *L _COMMA lua_CFunction fn _COMMA int n), 0x4e5a10)
DEFINE_NAKED_JMP(void lua_pushnumber (lua_State *L _COMMA lua_Number n), 0x4e58e0)
DEFINE_NAKED_JMP(int lua_isstring (lua_State *L _COMMA int idx), 0x4e55d0)
DEFINE_NAKED_JMP(int lua_setfenv (lua_State *L _COMMA int idx), 0x4e5e10)
DEFINE_NAKED_JMP(void lua_setgcthreshold (lua_State *L _COMMA int newthreshold), 0x4e5f90)
DEFINE_NAKED_JMP(void lua_newtable (lua_State *L), 0x4e5bd0)
DEFINE_NAKED_JMP(int lua_resume (lua_State *L _COMMA int narg), 0x4e7060)
DEFINE_NAKED_JMP(int lua_load (lua_State *L _COMMA lua_Chunkreader reader, void *dt, const char *chunkname), 0x4e5f20)
DEFINE_NAKED_JMP(int lua_gettop (lua_State *L), 0x4e5360)
DEFINE_NAKED_JMP(int lua_getstack (lua_State *L _COMMA int level, lua_Debug *ar), 0x4eb6b0)
DEFINE_NAKED_JMP(int lua_setmetatable (lua_State *L _COMMA int objindex), 0x4e5db0)
DEFINE_NAKED_JMP(const char *lua_typename (lua_State *L _COMMA int tp), 0x4e5520)
DEFINE_NAKED_JMP(void lua_rawgeti (lua_State *L _COMMA int idx _COMMA int n), 0x4e5b80)
DEFINE_NAKED_JMP(void lua_rawseti (lua_State *L _COMMA int idx _COMMA int n), 0x4e5d60)
DEFINE_NAKED_JMP(const char *lua_tostring (lua_State *L _COMMA int idx), 0x4e5710)
DEFINE_NAKED_JMP(void lua_xmove (lua_State *from, lua_State *to _COMMA int n), 0x4e52b0)
DEFINE_NAKED_JMP(const void *lua_topointer (lua_State *L _COMMA int idx), 0x4e5850)
DEFINE_NAKED_JMP(void lua_settable (lua_State *L _COMMA int idx), 0x4e5cd0)
DEFINE_NAKED_JMP(int lua_checkstack (lua_State *L _COMMA int sz), 0x4e5250)
DEFINE_NAKED_JMP(void lua_rawget (lua_State *L _COMMA int idx), 0x4e5b30)
DEFINE_NAKED_JMP(void lua_rawset (lua_State *L _COMMA int idx), 0x4e5d10)
DEFINE_NAKED_JMP(lua_CFunction lua_atpanic (lua_State *L _COMMA lua_CFunction panicf), 0x4e5300)
DEFINE_NAKED_JMP(int lua_error (lua_State *L), 0x4e5fd0)
DEFINE_NAKED_JMP(int lua_type (lua_State *L _COMMA int idx), 0x4e54f0)
DEFINE_NAKED_JMP(void lua_gettable (lua_State *L _COMMA int idx), 0x4e5ae0)
DEFINE_NAKED_JMP(size_t lua_strlen (lua_State *L _COMMA int idx), 0x4e5780)
DEFINE_NAKED_JMP(int lua_next (lua_State *L _COMMA int idx), 0x4e5fe0)
DEFINE_NAKED_JMP(void lua_pushvalue (lua_State *L _COMMA int idx), 0x4e54b0)
DEFINE_NAKED_JMP(void lua_pushboolean (lua_State *L _COMMA int b), 0x4e5aa0)
DEFINE_NAKED_JMP(int lua_isnumber (lua_State *L _COMMA int idx), 0x4e5580)
DEFINE_NAKED_JMP(void lua_pushlightuserdata (lua_State *L _COMMA void *p), 0x4e5ac0)
DEFINE_NAKED_JMP(void lua_pushstring (lua_State *L _COMMA const char *s), 0x4e5940)
DEFINE_NAKED_JMP(void lua_pushlstring (lua_State *L _COMMA const char *s, size_t l), 0x4e5900)


DEFINE_NAKED_JMP(int luaopen_base (lua_State *L), 0x4F6A00)
//DEFINE_NAKED_JMP(int luaopen_table (lua_State *L), );
DEFINE_NAKED_JMP(int luaopen_io (lua_State *L), 0x4F5550);
//DEFINE_NAKED_JMP(int luaopen_string (lua_State *L), );
DEFINE_NAKED_JMP(int luaopen_math (lua_State *L), 0x4F3D60);
//DEFINE_NAKED_JMP(int luaopen_debug (lua_State *L), );


LUALIB_API int luaopen_loadlib (lua_State *L);

DEFINE_NAKED_JMP(int lua_dobuffer (lua_State *L _COMMA const char *buff _COMMA size_t sz _COMMA const char *n), 0x4f3350)
DEFINE_NAKED_JMP(int lua_dostring (lua_State *L _COMMA const char *str), 0x4f33b0)


#endif
}

class lua_warpper {
    lua_State *L_;
public:
    lua_warpper(lua_State *L) : L_(L) {}

    ~lua_warpper() {}

    void lua_pushnumber(lua_Number n) {
        ::lua_pushnumber(L_, n);
    }

    void push_function(char *key, lua_CFunction fn) {
        lua_pushstring(L_, key);
        lua_pushcclosure(L_, fn, 0);
        lua_settable(L_, LUA_GLOBALSINDEX);
    }

    void push_number(char *key, lua_Number num) {
        ::lua_pushnumber(L_, num);
        lua_pushstring(L_, key);
        lua_insert(L_, -2);
        lua_settable(L_, LUA_GLOBALSINDEX);

    }

    void push_string(char *key, char *str) {
        lua_pushstring(L_,str);
        lua_pushstring(L_,key);
        lua_insert(L_,-2);
        lua_settable(L_,LUA_GLOBALSINDEX);
    }

    template<class T>
    T *get_table(char *str) {
        lua_pushstring(L_, str);
        lua_gettable(L_, LUA_GLOBALSINDEX);
        T *ptr = (T *)(lua_topointer(L_, lua_gettop(L_)));
        lua_settop(L_, -2);
        return ptr;
    }
};



#endif