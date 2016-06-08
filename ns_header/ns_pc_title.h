#ifndef NSHEADER_NS_PC_TITLE_H_
#define NSHEADER_NS_PC_TITLE_H_


class CNSPcTitle {
public:
	static const unsigned int _size = 0x144;

	enum OPTIONTYPE {
		OptionType_NULL = 0x0,
		OptionType_Str = 0x1,
		OptionType_Dex = 0x2,
		OptionType_Con = 0x3,
		OptionType_Int = 0x4,
		OptionType_Hp = 0x10,
		OptionType_Mp = 0x11,
		OptionType_Sta = 0x12,
		OptionType_Ap = 0x13,
		OptionType_Dp = 0x14,
		OptionType_Ma = 0x15,
		OptionType_Rs = 0x16,
		OptionType_HpRegen = 0x20,
		OptionType_MpRegen = 0x21,
		OptionType_StaRegen = 0x22,
		OptionType_NsTank = 0xA0,
		OptionType_LimitRank = 0xF0,
	};

	unsigned short m_wTitleId;//this+0x0
	char m_szTitleName[0x19];//this+0x2
	char m_szDescription[0x100];//this+0x1B
	struct _Option {
		static const unsigned int _size = 0x4;

		unsigned char btParam;//this+0x0
		short nValue;//this+0x2
	};

	struct CNSPcTitle::_Option m_Option[0xA];//this+0x11C
	unsigned short GetTitleId();
	char * GetTitleName();    PATCH_MEMBER(char *, GetTitleName, , 0x497290);
	char * GetDescription(CNSPc *, char *);    PATCH_MEMBER(char *, GetDescription, CNSPc * _COMMA char *, 0x495A90);
	short GetOptionValue(CNSPcTitle::OPTIONTYPE);    PATCH_MEMBER(short, GetOptionValue, CNSPcTitle::OPTIONTYPE, 0x495A40);

	/*struct _Invoke {
	PATCH_MEMBER_INVOKE(char *, CNSPcTitle, GetTitleName, );
	PATCH_MEMBER_INVOKE(char *, CNSPcTitle, GetDescription, CNSPc * _COMMA char *);
	PATCH_MEMBER_INVOKE(short, CNSPcTitle, GetOptionValue, CNSPcTitle::OPTIONTYPE);
	};*/
};
#ifdef DEFINE_NS_CPP
	DEFINE_NAKED_JMP(char * CNSPcTitle::GetTitleName(), 0x497290);
	DEFINE_NAKED_JMP(char * CNSPcTitle::GetDescription(CNSPc * _COMMA char *), 0x495A90);
	DEFINE_NAKED_JMP(short CNSPcTitle::GetOptionValue(CNSPcTitle::OPTIONTYPE), 0x495A40);
#endif


class CNSPcTitleList {
public:
	static const unsigned int _size = 0x28;

	CNSPcTitleList(const CNSPcTitleList &);
	CNSPcTitleList();    PATCH_MEMBER(CNSPcTitleList &, Constructor, , 0x496560);
	void Clear();    PATCH_MEMBER(void, Clear, , 0x482460);
	void SetParent(CNSPc *);    PATCH_MEMBER(void, SetParent, CNSPc *, 0x481E50);
	unsigned long GetCount();
	int IsFull();    PATCH_MEMBER(int, IsFull, , 0x497270);
	int Add(unsigned short);    PATCH_MEMBER(int, Add, unsigned short, 0x497220);
	CNSPcTitle * GetTitle(unsigned short);    PATCH_MEMBER(CNSPcTitle *, GetTitle, unsigned short, 0x4972B0);
	int Select(unsigned short);    PATCH_MEMBER(int, Select, unsigned short, 0x496980);
	int IsExist(unsigned short);    PATCH_MEMBER(int, IsExist, unsigned short, 0x4B0A80);
	char * GetActiveTitleName();    PATCH_MEMBER(char *, GetActiveTitleName, , 0x4828B0);
	int DbLoad();    PATCH_MEMBER(int, DbLoad, , 0x496590);
	int DbAdd(unsigned short);    PATCH_MEMBER(int, DbAdd, unsigned short, 0x496770);
	unsigned long PacketList(CPacket &);    PATCH_MEMBER(unsigned long, PacketList, CPacket &, 0x496A10);
	char * GetDescription(unsigned short, char *);    PATCH_MEMBER(char *, GetDescription, unsigned short _COMMA char *, 0x496B10);
	void DebugList();    PATCH_MEMBER(void, DebugList, , 0x496B50);
	void CalcOption();    PATCH_MEMBER(void, CalcOption, , 0x496C40);
	void CalcOption2();    PATCH_MEMBER(void, CalcOption2, , 0x496E80);
	void CalcOption3();    PATCH_MEMBER(void, CalcOption3, , 0x497070);
	class CNSPc * m_pParent;//this+0x0
	class CNSPcTitle * m_pActiveTitle;//this+0x4
	class std::map<unsigned short,CNSPcTitle *,std::less<unsigned short>,std::allocator<std::pair<unsigned short const ,CNSPcTitle *> > > m_mapTitle;//this+0x8
	~CNSPcTitleList();    PATCH_MEMBER(void, Destructor, , 0x4823C0);
	CNSPcTitleList & operator=(const CNSPcTitleList &);
	//void * __vecDelDtor(unsigned int);

	/*struct _Invoke {
	PATCH_MEMBER_INVOKE(CNSPcTitleList &, CNSPcTitleList, Constructor, );
	PATCH_MEMBER_INVOKE(void, CNSPcTitleList, Clear, );
	PATCH_MEMBER_INVOKE(void, CNSPcTitleList, SetParent, CNSPc *);
	PATCH_MEMBER_INVOKE(int, CNSPcTitleList, IsFull, );
	PATCH_MEMBER_INVOKE(int, CNSPcTitleList, Add, unsigned short);
	PATCH_MEMBER_INVOKE(CNSPcTitle *, CNSPcTitleList, GetTitle, unsigned short);
	PATCH_MEMBER_INVOKE(int, CNSPcTitleList, Select, unsigned short);
	PATCH_MEMBER_INVOKE(int, CNSPcTitleList, IsExist, unsigned short);
	PATCH_MEMBER_INVOKE(char *, CNSPcTitleList, GetActiveTitleName, );
	PATCH_MEMBER_INVOKE(int, CNSPcTitleList, DbLoad, );
	PATCH_MEMBER_INVOKE(int, CNSPcTitleList, DbAdd, unsigned short);
	PATCH_MEMBER_INVOKE(unsigned long, CNSPcTitleList, PacketList, CPacket &);
	PATCH_MEMBER_INVOKE(char *, CNSPcTitleList, GetDescription, unsigned short _COMMA char *);
	PATCH_MEMBER_INVOKE(void, CNSPcTitleList, DebugList, );
	PATCH_MEMBER_INVOKE(void, CNSPcTitleList, CalcOption, );
	PATCH_MEMBER_INVOKE(void, CNSPcTitleList, CalcOption2, );
	PATCH_MEMBER_INVOKE(void, CNSPcTitleList, CalcOption3, );
	PATCH_MEMBER_INVOKE(void, CNSPcTitleList, Destructor, );
	};*/
};
#ifdef DEFINE_NS_CPP
	//DEFINE_NAKED_JMP(CNSPcTitleList::Constructor(), 0x496560);
	DEFINE_NAKED_JMP(void CNSPcTitleList::Clear(), 0x482460);
	//DEFINE_NAKED_JMP(void CNSPcTitleList::SetParent(CNSPc *), 0x481E50);
	DEFINE_NAKED_JMP(int CNSPcTitleList::IsFull(), 0x497270);
	DEFINE_NAKED_JMP(int CNSPcTitleList::Add(unsigned short), 0x497220);
	DEFINE_NAKED_JMP(CNSPcTitle * CNSPcTitleList::GetTitle(unsigned short), 0x4972B0);
	DEFINE_NAKED_JMP(int CNSPcTitleList::Select(unsigned short), 0x496980);
	DEFINE_NAKED_JMP(int CNSPcTitleList::IsExist(unsigned short), 0x4B0A80);
	DEFINE_NAKED_JMP(char * CNSPcTitleList::GetActiveTitleName(), 0x4828B0);
	//DEFINE_NAKED_JMP(int CNSPcTitleList::DbLoad(), 0x496590);
	//DEFINE_NAKED_JMP(int CNSPcTitleList::DbAdd(unsigned short), 0x496770);
	//DEFINE_NAKED_JMP(unsigned long CNSPcTitleList::PacketList(CPacket &), 0x496A10);
	DEFINE_NAKED_JMP(char * CNSPcTitleList::GetDescription(unsigned short _COMMA char *), 0x496B10);
	//DEFINE_NAKED_JMP(void CNSPcTitleList::DebugList(), 0x496B50);
	DEFINE_NAKED_JMP(void CNSPcTitleList::CalcOption(), 0x496C40);
	DEFINE_NAKED_JMP(void CNSPcTitleList::CalcOption2(), 0x496E80);
	DEFINE_NAKED_JMP(void CNSPcTitleList::CalcOption3(), 0x497070);
	//DEFINE_NAKED_JMP(CNSPcTitleList::Destructor(), 0x4823C0);
#endif








#endif