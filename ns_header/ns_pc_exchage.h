#ifndef NSHEADER_NS_PC_EXCHAGE_H_
#define NSHEADER_NS_PC_EXCHAGE_H_



class CNSPcExchange {
public:
	static const unsigned int _size = 0xb4;

	CNSPcExchange(CNSPc *);    PATCH_MEMBER(CNSPcExchange &, Constructor, CNSPc *, 0x485800);
	void SetParent(CNSPc *);    PATCH_MEMBER(void, SetParent, CNSPc *, 0x481CF0);
	void Clear();    PATCH_MEMBER(void, Clear, , 0x485830);
	int Find(unsigned long);    PATCH_MEMBER(int, Find, unsigned long, 0x485890);
	int SetGold(unsigned long);    PATCH_MEMBER(int, SetGold, unsigned long, 0x485940);
	int Add(unsigned long, unsigned char, unsigned short &, unsigned char &, unsigned char &);    PATCH_MEMBER(int, Add, unsigned long _COMMA unsigned char _COMMA unsigned short & _COMMA unsigned char & _COMMA unsigned char &, 0x485980);
	int Delete(unsigned long);    PATCH_MEMBER(int, Delete, unsigned long, 0x485AA0);
	int Confirm(CNSPc *);    PATCH_MEMBER(int, Confirm, CNSPc *, 0x485B00);
	int Exchange(CNSPc *);    PATCH_MEMBER(int, Exchange, CNSPc *, 0x485BE0);
	int IsActive();    PATCH_MEMBER(int, IsActive, , 0x482730);
	int IsExchange();    PATCH_MEMBER(int, IsExchange, , 0x4C8120);
	int IsConfirm();    PATCH_MEMBER(int, IsConfirm, , 0x4C8190);
	int SetExchange();    PATCH_MEMBER(int, SetExchange, , 0x4C8160);
	void SetTarget(unsigned long);    PATCH_MEMBER(void, SetTarget, unsigned long, 0x4C8140);
	unsigned long GetTarget();    PATCH_MEMBER(unsigned long, GetTarget, , 0x43F930);
	int FindTargetItem(unsigned long);    PATCH_MEMBER(int, FindTargetItem, unsigned long, 0x4858D0);
	struct ITEMARRAY {
		static const unsigned int _size = 0x8;

		unsigned long dwItemObjectId;//this+0x0
		unsigned char btCount;//this+0x4
	};

	struct CNSPcExchange::ITEMARRAY m_ItemArray[0x14];//this+0x0
	class CNSPc * m_pParent;//this+0xA0
	unsigned long m_dwTargetObjectId;//this+0xA4
	unsigned long m_dwGold;//this+0xA8
	int m_bConfirm;//this+0xAC
	int m_bExchange;//this+0xB0
	//void __dflt_ctor_closure();

	/*struct _Invoke {
	PATCH_MEMBER_INVOKE(CNSPcExchange &, CNSPcExchange, Constructor, CNSPc *);
	PATCH_MEMBER_INVOKE(void, CNSPcExchange, SetParent, CNSPc *);
	PATCH_MEMBER_INVOKE(void, CNSPcExchange, Clear, );
	PATCH_MEMBER_INVOKE(int, CNSPcExchange, Find, unsigned long);
	PATCH_MEMBER_INVOKE(int, CNSPcExchange, SetGold, unsigned long);
	PATCH_MEMBER_INVOKE(int, CNSPcExchange, Add, unsigned long _COMMA unsigned char _COMMA unsigned short & _COMMA unsigned char & _COMMA unsigned char &);
	PATCH_MEMBER_INVOKE(int, CNSPcExchange, Delete, unsigned long);
	PATCH_MEMBER_INVOKE(int, CNSPcExchange, Confirm, CNSPc *);
	PATCH_MEMBER_INVOKE(int, CNSPcExchange, Exchange, CNSPc *);
	PATCH_MEMBER_INVOKE(int, CNSPcExchange, IsActive, );
	PATCH_MEMBER_INVOKE(int, CNSPcExchange, IsExchange, );
	PATCH_MEMBER_INVOKE(int, CNSPcExchange, IsConfirm, );
	PATCH_MEMBER_INVOKE(int, CNSPcExchange, SetExchange, );
	PATCH_MEMBER_INVOKE(void, CNSPcExchange, SetTarget, unsigned long);
	PATCH_MEMBER_INVOKE(unsigned long, CNSPcExchange, GetTarget, );
	PATCH_MEMBER_INVOKE(int, CNSPcExchange, FindTargetItem, unsigned long);
	};*/

#ifdef DEFINE_NS_CPP
	//DEFINE_NAKED_JMP(CNSPcExchange::Constructor(CNSPc *), 0x485800);
	//DEFINE_NAKED_JMP(void CNSPcExchange::SetParent(CNSPc *), 0x481CF0);
	//DEFINE_NAKED_JMP(void CNSPcExchange::Clear(), 0x485830);
	//DEFINE_NAKED_JMP(int CNSPcExchange::Find(unsigned long), 0x485890);
	//DEFINE_NAKED_JMP(int CNSPcExchange::SetGold(unsigned long), 0x485940);
	//DEFINE_NAKED_JMP(int CNSPcExchange::Add(unsigned long _COMMA unsigned char _COMMA unsigned short & _COMMA unsigned char & _COMMA unsigned char &), 0x485980);
	//DEFINE_NAKED_JMP(int CNSPcExchange::Delete(unsigned long), 0x485AA0);
	//DEFINE_NAKED_JMP(int CNSPcExchange::Confirm(CNSPc *), 0x485B00);
	//DEFINE_NAKED_JMP(int CNSPcExchange::Exchange(CNSPc *), 0x485BE0);
	//DEFINE_NAKED_JMP(int CNSPcExchange::IsActive(), 0x482730);
	//DEFINE_NAKED_JMP(int CNSPcExchange::IsExchange(), 0x4C8120);
	//DEFINE_NAKED_JMP(int CNSPcExchange::IsConfirm(), 0x4C8190);
	//DEFINE_NAKED_JMP(int CNSPcExchange::SetExchange(), 0x4C8160);
	//DEFINE_NAKED_JMP(void CNSPcExchange::SetTarget(unsigned long), 0x4C8140);
	//DEFINE_NAKED_JMP(unsigned long CNSPcExchange::GetTarget(), 0x43F930);
	//DEFINE_NAKED_JMP(int CNSPcExchange::FindTargetItem(unsigned long), 0x4858D0);
#endif
};




#endif