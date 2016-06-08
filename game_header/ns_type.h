#ifndef GAME_HEADER_NS_TYPE_H_
#define GAME_HEADER_NS_TYPE_H_

#include "base/hook_util.h"

#define __CHECK_STRUCT_SIZE(x, s) do { sizeof(x) == s ? LOGINFO("sizeof(%s):0x%x == 0x%x", typeid(x).name(), sizeof(x), s)\
    : LOGERROR("sizeof(%s):0x%x != 0x%x", typeid(x).name(), sizeof(x), s);\
    } while(0)

#define __CHECK_THIS_SIZE(x) do { sizeof(x) == x::_size ? LOGINFO("sizeof(%s):0x%x == 0x%x", typeid(x).name(), sizeof(x), x::_size)\
    : LOGERROR("sizeof(%s):0x%x != 0x%x", typeid(x).name(), sizeof(x), x::_size);\
    } while(0)


#define __CHECK_STRUCT_OFFSET(x, y, a) do { STRUCT_OFFSET(x, y) == a ? LOGINFO("%s::%s 0x%x==0x%x", #x, #y, STRUCT_OFFSET(x, y), a)\
    : LOGERROR("%s::%s 0x%x != 0x%x", #x, #y, STRUCT_OFFSET(x, y), a);\
    } while(0)


 
#define _ASM_CC_RESERVE {__asm _emit 0xcc __asm _emit 0xcc __asm _emit 0xcc __asm _emit 0xcc __asm _emit 0xcc}


#define CLIENT_DLL_NAME "game.dll"
#define EXPORT_NO_INLINE __declspec(dllexport) __declspec(noinline)

template <class T>
class NSRect {
public:
    NSRect() {}

    NSRect(T left, T top = T(0), T right = T(0), T bottom = T(0)) {
		m_left = left;
		m_top = top;
		m_right = right;
		m_bottom = bottom;
	}

	T m_left, m_top, m_right, m_bottom;
};





#endif