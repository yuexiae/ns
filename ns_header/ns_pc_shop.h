#ifndef NSHEADER_NS_PC_SHOP_H_
#define NSHEADER_NS_PC_SHOP_H_


class CNSPcShop {
public:
	static const unsigned int _size = 0xc8;

	struct _good {
		static const unsigned int _size = 0x10;

		unsigned long dwItemObjectId;//this+0x0
		unsigned short wItemId;//this+0x4
		unsigned char btKind;//this+0x6
		unsigned char btEquipmentPart;//this+0x7
		unsigned char btRare;//this+0x8
		unsigned char btCount;//this+0x9
		unsigned long dwGold;//this+0xC
	};


	enum OPENTYPE {
		OpenType_Close =  0x0,
		OpenType_Sell =  0x1,
		OpenType_Buy =  0x2,
	};

	CNSPcShop();    PATCH_MEMBER(CNSPcShop &, Constructor, , 0x492F70);
	~CNSPcShop();    PATCH_MEMBER(void, Destructor, , 0x492FC0);
	void SetParent(CNSPc *);    PATCH_MEMBER(void, SetParent, CNSPc *, 0x481E50);
	void Open(char *, int);    PATCH_MEMBER(void, Open, char * _COMMA int, 0x492FE0);
	int Close();    PATCH_MEMBER(int, Close, , 0x493030);
	int IsOpen();    PATCH_MEMBER(int, IsOpen, , 0x482850);
	int IsBuy();    PATCH_MEMBER(int, IsBuy, , 0x482870);
	int IsSell();    PATCH_MEMBER(int, IsSell, , 0x494070);
	char * GetTitle();    PATCH_MEMBER(char *, GetTitle, , 0x482890);
	unsigned long GetCount();
	int IsFull();    PATCH_MEMBER(int, IsFull, , 0x494090);
	unsigned long GetSpace();
	unsigned char DecCount(CNSPcShop::_good *, unsigned char);    PATCH_MEMBER(unsigned char, DecCount, CNSPcShop::_good * _COMMA unsigned char, 0x493440);
	int Add(unsigned long, unsigned char, unsigned long);    PATCH_MEMBER(int, Add, unsigned long _COMMA unsigned char _COMMA unsigned long, 0x493070);
	CNSPcShop::_good * Find(unsigned long);    PATCH_MEMBER(CNSPcShop::_good *, Find, unsigned long, 0x4932D0);
	CNSPcShop::_good * Find(unsigned short);    PATCH_MEMBER(CNSPcShop::_good *, Find, unsigned short, 0x493270);
	void SearchItem(CNSPc *, char *);    PATCH_MEMBER(void, SearchItem, CNSPc * _COMMA char *, 0x493330);
	int Sell(CNSPc *, unsigned long, unsigned char);    PATCH_MEMBER(int, Sell, CNSPc * _COMMA unsigned long _COMMA unsigned char, 0x4936B0);
	int Buy(CNSPc *, unsigned long, unsigned char);    PATCH_MEMBER(int, Buy, CNSPc * _COMMA unsigned long _COMMA unsigned char, 0x493B40);
	unsigned long PacketList(CPacket &);    PATCH_MEMBER(unsigned long, PacketList, CPacket &, 0x4934C0);
	int Delete(unsigned long);    PATCH_MEMBER(int, Delete, unsigned long, 0x4935D0);
	void Clear();    PATCH_MEMBER(void, Clear, , 0x494040);
	class CNSPc * m_pParent;//this+0x0
	enum CNSPcShop::OPENTYPE m_openType;//this+0x4
	unsigned long m_dwCount;//this+0x8
	struct CNSPcShop::_good m_goodArray[0xA];//this+0xC
	char m_szTitle[0x19];//this+0xAC
	//void * __vecDelDtor(unsigned int);

	/*struct _Invoke {
	PATCH_MEMBER_INVOKE(CNSPcShop &, CNSPcShop, Constructor, );
	PATCH_MEMBER_INVOKE(void, CNSPcShop, Destructor, );
	PATCH_MEMBER_INVOKE(void, CNSPcShop, SetParent, CNSPc *);
	PATCH_MEMBER_INVOKE(void, CNSPcShop, Open, char * _COMMA int);
	PATCH_MEMBER_INVOKE(int, CNSPcShop, Close, );
	PATCH_MEMBER_INVOKE(int, CNSPcShop, IsOpen, );
	PATCH_MEMBER_INVOKE(int, CNSPcShop, IsBuy, );
	PATCH_MEMBER_INVOKE(int, CNSPcShop, IsSell, );
	PATCH_MEMBER_INVOKE(char *, CNSPcShop, GetTitle, );
	PATCH_MEMBER_INVOKE(int, CNSPcShop, IsFull, );
	PATCH_MEMBER_INVOKE(unsigned char, CNSPcShop, DecCount, CNSPcShop::_good * _COMMA unsigned char);
	PATCH_MEMBER_INVOKE(int, CNSPcShop, Add, unsigned long _COMMA unsigned char _COMMA unsigned long);
	PATCH_MEMBER_INVOKE(CNSPcShop::_good *, CNSPcShop, Find, unsigned long);
	PATCH_MEMBER_INVOKE(CNSPcShop::_good *, CNSPcShop, Find, unsigned short);
	PATCH_MEMBER_INVOKE(void, CNSPcShop, SearchItem, CNSPc * _COMMA char *);
	PATCH_MEMBER_INVOKE(int, CNSPcShop, Sell, CNSPc * _COMMA unsigned long _COMMA unsigned char);
	PATCH_MEMBER_INVOKE(int, CNSPcShop, Buy, CNSPc * _COMMA unsigned long _COMMA unsigned char);
	PATCH_MEMBER_INVOKE(unsigned long, CNSPcShop, PacketList, CPacket &);
	PATCH_MEMBER_INVOKE(int, CNSPcShop, Delete, unsigned long);
	PATCH_MEMBER_INVOKE(void, CNSPcShop, Clear, );
	};*/

#ifdef DEFINE_NS_CPP
	//DEFINE_NAKED_JMP(CNSPcShop::Constructor(), 0x492F70);
	//DEFINE_NAKED_JMP(CNSPcShop::Destructor(), 0x492FC0);
	//DEFINE_NAKED_JMP(void CNSPcShop::SetParent(CNSPc *), 0x481E50);
	//DEFINE_NAKED_JMP(void CNSPcShop::Open(char * _COMMA int), 0x492FE0);
	//DEFINE_NAKED_JMP(int CNSPcShop::Close(), 0x493030);
	//DEFINE_NAKED_JMP(int CNSPcShop::IsOpen(), 0x482850);
	//DEFINE_NAKED_JMP(int CNSPcShop::IsBuy(), 0x482870);
	//DEFINE_NAKED_JMP(int CNSPcShop::IsSell(), 0x494070);
	//DEFINE_NAKED_JMP(char * CNSPcShop::GetTitle(), 0x482890);
	//DEFINE_NAKED_JMP(int CNSPcShop::IsFull(), 0x494090);
	//DEFINE_NAKED_JMP(unsigned char CNSPcShop::DecCount(CNSPcShop::_good * _COMMA unsigned char), 0x493440);
	//DEFINE_NAKED_JMP(int CNSPcShop::Add(unsigned long _COMMA unsigned char _COMMA unsigned long), 0x493070);
	//DEFINE_NAKED_JMP(CNSPcShop::_good * CNSPcShop::Find(unsigned long), 0x4932D0);
	//DEFINE_NAKED_JMP(CNSPcShop::_good * CNSPcShop::Find(unsigned short), 0x493270);
	//DEFINE_NAKED_JMP(void CNSPcShop::SearchItem(CNSPc * _COMMA char *), 0x493330);
	//DEFINE_NAKED_JMP(int CNSPcShop::Sell(CNSPc * _COMMA unsigned long _COMMA unsigned char), 0x4936B0);
	//DEFINE_NAKED_JMP(int CNSPcShop::Buy(CNSPc * _COMMA unsigned long _COMMA unsigned char), 0x493B40);
	//DEFINE_NAKED_JMP(unsigned long CNSPcShop::PacketList(CPacket &), 0x4934C0);
	//DEFINE_NAKED_JMP(int CNSPcShop::Delete(unsigned long), 0x4935D0);
	//DEFINE_NAKED_JMP(void CNSPcShop::Clear(), 0x494040);
#endif
};



#endif