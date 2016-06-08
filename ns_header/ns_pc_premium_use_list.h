#ifndef NSHEADER_NS_PC_PREMIUM_USE_LIST_H_
#define NSHEADER_NS_PC_PREMIUM_USE_LIST_H_


class CNSPcPremiumUseList {
public:
	static const unsigned int _size = 0x194;

	struct PremiumUse {
		static const unsigned int _size = 0x14;

		unsigned short wItemId;//this+0x0
		unsigned short wDays;//this+0x2
		struct _SYSTEMTIME stStart;//this+0x4
	};

	struct CNSPcPremiumUseList::PremiumUse m_PremiumUseArray[0x14];//this+0x0
	CNSPcPremiumUseList();    PATCH_MEMBER(CNSPcPremiumUseList &, Constructor, , 0x492620);
	void Clear();    PATCH_MEMBER(void, Clear, , 0x492C30);
	void SetParent(CNSPc *);    PATCH_MEMBER(void, SetParent, CNSPc *, 0x481E10);
	int Add(unsigned short, unsigned short, _SYSTEMTIME &);    PATCH_MEMBER(int, Add, unsigned short _COMMA unsigned short _COMMA _SYSTEMTIME &, 0x492640);
	int Delete(unsigned short);    PATCH_MEMBER(int, Delete, unsigned short, 0x492830);
	int DbAdd(unsigned short, unsigned short, _SYSTEMTIME &);    PATCH_MEMBER(int, DbAdd, unsigned short _COMMA unsigned short _COMMA _SYSTEMTIME &, 0x4926E0);
	int DbLoad();    PATCH_MEMBER(int, DbLoad, , 0x4928A0);
	class CNSPc * m_pParent;//this+0x190

	/*struct _Invoke {
	PATCH_MEMBER_INVOKE(CNSPcPremiumUseList &, CNSPcPremiumUseList, Constructor, );
	PATCH_MEMBER_INVOKE(void, CNSPcPremiumUseList, Clear, );
	PATCH_MEMBER_INVOKE(void, CNSPcPremiumUseList, SetParent, CNSPc *);
	PATCH_MEMBER_INVOKE(int, CNSPcPremiumUseList, Add, unsigned short _COMMA unsigned short _COMMA _SYSTEMTIME &);
	PATCH_MEMBER_INVOKE(int, CNSPcPremiumUseList, Delete, unsigned short);
	PATCH_MEMBER_INVOKE(int, CNSPcPremiumUseList, DbAdd, unsigned short _COMMA unsigned short _COMMA _SYSTEMTIME &);
	PATCH_MEMBER_INVOKE(int, CNSPcPremiumUseList, DbLoad, );
	};*/

#ifdef DEFINE_NS_CPP
	//DEFINE_NAKED_JMP(CNSPcPremiumUseList::Constructor(), 0x492620);
	//DEFINE_NAKED_JMP(void CNSPcPremiumUseList::Clear(), 0x492C30);
	//DEFINE_NAKED_JMP(void CNSPcPremiumUseList::SetParent(CNSPc *), 0x481E10);
	//DEFINE_NAKED_JMP(int CNSPcPremiumUseList::Add(unsigned short _COMMA unsigned short _COMMA _SYSTEMTIME &), 0x492640);
	//DEFINE_NAKED_JMP(int CNSPcPremiumUseList::Delete(unsigned short), 0x492830);
	//DEFINE_NAKED_JMP(int CNSPcPremiumUseList::DbAdd(unsigned short _COMMA unsigned short _COMMA _SYSTEMTIME &), 0x4926E0);
	//DEFINE_NAKED_JMP(int CNSPcPremiumUseList::DbLoad(), 0x4928A0);
#endif
};




#endif