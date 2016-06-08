#ifndef NSHEADER_NS_MOVE_PATH_H_
#define NSHEADER_NS_MOVE_PATH_H_


class CNSMovePath {
public:
	static const unsigned int _size = 0x5c;

	enum MOVETYPE {
		MoveType_Normal = 0x0,
		MoveType_Manual = 0x1,
	};

	CNSMovePath();    PATCH_MEMBER(CNSMovePath &, Constructor, , 0x426A60);
	void SetMode(unsigned char);
	CNSMovePath::MOVETYPE GetMode();
	int Add(NSPOINT2 &);    PATCH_MEMBER(int, Add, NSPOINT2 &, 0x44A250);
	int GetFirstPath(NSPOINT2 &);    PATCH_MEMBER(int, GetFirstPath, NSPOINT2 &, 0x459D10);
	int GetPath(NSPOINT2 &);    PATCH_MEMBER(int, GetPath, NSPOINT2 &, 0x459D50);
	void SetCurPath();    PATCH_MEMBER(void, SetCurPath, , 0x44C680);
	void Reset();
	void Clear();    PATCH_MEMBER(void, Clear, , 0x482400);
	int IsFull();    PATCH_MEMBER(int, IsFull, , 0x44A2A0);
	int IsEmpty();    PATCH_MEMBER(int, IsEmpty, , 0x484B20);
	enum CNSMovePath::MOVETYPE m_moveType;//this+0x0
	unsigned long m_dwPos;//this+0x4
	unsigned long m_dwCount;//this+0x8
	class NSPOINT2 m_cellArray[0x14];//this+0xC

	/*struct _Invoke {
	PATCH_MEMBER_INVOKE(CNSMovePath &, CNSMovePath, Constructor, );
	PATCH_MEMBER_INVOKE(int, CNSMovePath, Add, NSPOINT2 &);
	PATCH_MEMBER_INVOKE(int, CNSMovePath, GetFirstPath, NSPOINT2 &);
	PATCH_MEMBER_INVOKE(int, CNSMovePath, GetPath, NSPOINT2 &);
	PATCH_MEMBER_INVOKE(void, CNSMovePath, SetCurPath, );
	PATCH_MEMBER_INVOKE(void, CNSMovePath, Clear, );
	PATCH_MEMBER_INVOKE(int, CNSMovePath, IsFull, );
	PATCH_MEMBER_INVOKE(int, CNSMovePath, IsEmpty, );
	};*/
};
#ifdef DEFINE_NS_CPP
	//DEFINE_NAKED_JMP(CNSMovePath::Constructor(), 0x426A60);
	DEFINE_NAKED_JMP(int CNSMovePath::Add(NSPOINT2 &), 0x44A250);
	DEFINE_NAKED_JMP(int CNSMovePath::GetFirstPath(NSPOINT2 &), 0x459D10);
	DEFINE_NAKED_JMP(int CNSMovePath::GetPath(NSPOINT2 &), 0x459D50);
	DEFINE_NAKED_JMP(void CNSMovePath::SetCurPath(), 0x44C680);
	DEFINE_NAKED_JMP(void CNSMovePath::Clear(), 0x482400);
	DEFINE_NAKED_JMP(int CNSMovePath::IsFull(), 0x44A2A0);
	DEFINE_NAKED_JMP(int CNSMovePath::IsEmpty(), 0x484B20);
#endif



#endif