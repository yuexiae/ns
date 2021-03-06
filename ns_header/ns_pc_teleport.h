#ifndef NSHEAER_CNS_PC_TELEPORT_H_
#define NSHEAER_CNS_PC_TELEPORT_H_



class CNSPcTeleportList {
public:
	static const unsigned int _size = 0x174;

	struct Teleport {
		static const unsigned int _size = 0x24;

		int nDbSeq;//this+0x0
		char szName[0x19];//this+0x4
		unsigned char btRegion;//this+0x1D
		unsigned short wPosX;//this+0x1E
		unsigned short wPosY;//this+0x20
	};

	struct CNSPcTeleportList::Teleport m_TeleportArray[0xA];//this+0x0
	CNSPcTeleportList();    PATCH_MEMBER(CNSPcTeleportList &, Constructor, , 0x495690);
	void SetParent(CNSPc *);    PATCH_MEMBER(void, SetParent, CNSPc *, 0x481D10);
	void SetTeleportPos(int);    PATCH_MEMBER(void, SetTeleportPos, int, 0x4C94F0);
	unsigned long GetCount();    PATCH_MEMBER(unsigned long, GetCount, , 0x483F20);
	int IsFull();
	void Clear();    PATCH_MEMBER(void, Clear, , 0x4849B0);
	int Add(CNSPcTeleportList::Teleport &);    PATCH_MEMBER(int, Add, CNSPcTeleportList::Teleport &, 0x4956C0);
	int Delete(int);    PATCH_MEMBER(int, Delete, int, 0x495720);
	int Warp();    PATCH_MEMBER(int, Warp, , 0x495800);
	unsigned long PacketList(CPacket &);    PATCH_MEMBER(unsigned long, PacketList, CPacket &, 0x495960);
	class CNSPc * m_pParent;//this+0x168
	unsigned long m_dwCount;//this+0x16C
	int m_nPos;//this+0x170

	/*struct _Invoke {
	PATCH_MEMBER_INVOKE(CNSPcTeleportList &, CNSPcTeleportList, Constructor, );
	PATCH_MEMBER_INVOKE(void, CNSPcTeleportList, SetParent, CNSPc *);
	PATCH_MEMBER_INVOKE(void, CNSPcTeleportList, SetTeleportPos, int);
	PATCH_MEMBER_INVOKE(unsigned long, CNSPcTeleportList, GetCount, );
	PATCH_MEMBER_INVOKE(void, CNSPcTeleportList, Clear, );
	PATCH_MEMBER_INVOKE(int, CNSPcTeleportList, Add, CNSPcTeleportList::Teleport &);
	PATCH_MEMBER_INVOKE(int, CNSPcTeleportList, Delete, int);
	PATCH_MEMBER_INVOKE(int, CNSPcTeleportList, Warp, );
	PATCH_MEMBER_INVOKE(unsigned long, CNSPcTeleportList, PacketList, CPacket &);
	};*/
};
#ifdef DEFINE_NS_CPP
	//DEFINE_NAKED_JMP(CNSPcTeleportList::Constructor(), 0x495690);
	//DEFINE_NAKED_JMP(void CNSPcTeleportList::SetParent(CNSPc *), 0x481D10);
	//DEFINE_NAKED_JMP(void CNSPcTeleportList::SetTeleportPos(int), 0x4C94F0);
	//DEFINE_NAKED_JMP(unsigned long CNSPcTeleportList::GetCount(), 0x483F20);
	DEFINE_NAKED_JMP(void CNSPcTeleportList::Clear(), 0x4849B0);
	DEFINE_NAKED_JMP(int CNSPcTeleportList::Add(CNSPcTeleportList::Teleport &), 0x4956C0);
	//DEFINE_NAKED_JMP(int CNSPcTeleportList::Delete(int), 0x495720);
	//DEFINE_NAKED_JMP(int CNSPcTeleportList::Warp(), 0x495800);
	//DEFINE_NAKED_JMP(unsigned long CNSPcTeleportList::PacketList(CPacket &), 0x495960);
#endif



#endif