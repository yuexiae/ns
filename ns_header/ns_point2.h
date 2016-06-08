#ifndef NSHEADER_NS_POINT2_H_
#define NSHEADER_NS_POINT2_H_

#include "base/micros.h"
#include "base/hook_util.h"
#include "ns_header/ns_type.h"


class NSPOINT2_S {
public:
	static const unsigned int _size = 0x8;

	int x;//this+0x0
	int y;//this+0x4
	NSPOINT2_S(int, int);    PATCH_MEMBER(NSPOINT2_S &, Constructor, int _COMMA int, 0x4272A0);
	NSPOINT2_S();

	/*struct _Invoke {
	PATCH_MEMBER_INVOKE(NSPOINT2_S &, NSPOINT2_S, Constructor, int _COMMA int);
	};*/

#ifdef DEFINE_NS_CPP
	//DEFINE_NAKED_JMP(NSPOINT2_S::Constructor(int _COMMA int), 0x4272A0);
#endif
};


class NSPOINT2 {
public:
	static const unsigned int _size = 0x4;

	unsigned short x;//this+0x0
	unsigned short y;//this+0x2
	NSPOINT2(unsigned short x , unsigned short y) : x(x), y(y) {}    PATCH_MEMBER(NSPOINT2 &, Constructor, unsigned short _COMMA unsigned short, 0x484AC0);
	NSPOINT2() {}    PATCH_MEMBER(NSPOINT2 &, Constructor, , 0x437DC0);
	bool operator==(const NSPOINT2 &);    //PATCH_MEMBER(bool, operator==, const NSPOINT2 &, 0x427380);
	bool operator!=(const NSPOINT2 &);    //PATCH_MEMBER(bool, operator!=, const NSPOINT2 &, 0x427350);
	NSPOINT2_S operator-(const NSPOINT2 &);    //PATCH_MEMBER(NSPOINT2_S, operator-, const NSPOINT2 &, 0x427260);
	static float GetLength(NSPOINT2 &, NSPOINT2 &);    PATCH_STATIC(float, GetLength, NSPOINT2 & _COMMA NSPOINT2 &, 0x423A30);
	static float GetDirection(NSPOINT2 &, NSPOINT2 &);    PATCH_STATIC(float, GetDirection, NSPOINT2 & _COMMA NSPOINT2 &, 0x4271C0);
	static unsigned short GetAngle(NSPOINT2 &, NSPOINT2 &);    PATCH_STATIC(unsigned short, GetAngle, NSPOINT2 & _COMMA NSPOINT2 &, 0x427190);

	/*struct _Invoke {
	PATCH_MEMBER_INVOKE(NSPOINT2 &, NSPOINT2, Constructor, unsigned short _COMMA unsigned short);
	PATCH_MEMBER_INVOKE(NSPOINT2 &, NSPOINT2, Constructor, );
	//PATCH_MEMBER_INVOKE(bool, NSPOINT2, operator==, const NSPOINT2 &);
	//PATCH_MEMBER_INVOKE(bool, NSPOINT2, operator!=, const NSPOINT2 &);
	//PATCH_MEMBER_INVOKE(NSPOINT2_S, NSPOINT2, operator-, const NSPOINT2 &);
	PATCH_STATIC_INVOKE(float, GetLength, NSPOINT2 & _COMMA NSPOINT2 &);
	PATCH_STATIC_INVOKE(float, GetDirection, NSPOINT2 & _COMMA NSPOINT2 &);
	PATCH_STATIC_INVOKE(unsigned short, GetAngle, NSPOINT2 & _COMMA NSPOINT2 &);
	};*/

	MSGPACK_DEFINE(x, y);
};
#ifdef DEFINE_NS_CPP
	//DEFINE_NAKED_JMP(NSPOINT2::Constructor(unsigned short _COMMA unsigned short), 0x484AC0);
	//DEFINE_NAKED_JMP(NSPOINT2::Constructor(), 0x437DC0);
	DEFINE_NAKED_JMP(bool NSPOINT2::operator==(const NSPOINT2 &), 0x427380);
	DEFINE_NAKED_JMP(bool NSPOINT2::operator!=(const NSPOINT2 &), 0x427350);
	DEFINE_NAKED_JMP(NSPOINT2_S NSPOINT2::operator-(const NSPOINT2 &), 0x427260);
	DEFINE_NAKED_JMP(float NSPOINT2::GetLength(NSPOINT2 & _COMMA NSPOINT2 &), 0x423A30);
	DEFINE_NAKED_JMP(float NSPOINT2::GetDirection(NSPOINT2 & _COMMA NSPOINT2 &), 0x4271C0);
	DEFINE_NAKED_JMP(unsigned short NSPOINT2::GetAngle(NSPOINT2 & _COMMA NSPOINT2 &), 0x427190);
#endif







#endif