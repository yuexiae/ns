#ifndef NSHEADER_NS_SHOP_INVENTORY_H_
#define NSHEADER_NS_SHOP_INVENTORY_H_


class CNSShopInventory {
public:
	static const unsigned int _size = 0x24;

	struct _Goods {
		static const unsigned int _size = 0x8;

		class CNSItem * pItem;//this+0x0
		unsigned long dwSellGold;//this+0x4
	};

	CNSShopInventory(const CNSShopInventory &);
	CNSShopInventory();    PATCH_MEMBER(CNSShopInventory &, Constructor, , 0x4375D0);
	~CNSShopInventory();    PATCH_MEMBER(void, Destructor, , 0x437600);
	void SetRate(unsigned short, unsigned short);    PATCH_MEMBER(void, SetRate, unsigned short _COMMA unsigned short, 0x4B07E0);
	int Add(unsigned short, unsigned long);    PATCH_MEMBER(int, Add, unsigned short _COMMA unsigned long, 0x4377C0);
	int Add(unsigned short);    PATCH_MEMBER(int, Add, unsigned short, 0x4376F0);
	CNSShopInventory::_Goods * Find(unsigned long);    PATCH_MEMBER(CNSShopInventory::_Goods *, Find, unsigned long, 0x437850);
	unsigned long GetSellGold(unsigned long);
	unsigned long GetBuyGold(unsigned short);    PATCH_MEMBER(unsigned long, GetBuyGold, unsigned short, 0x44C5A0);
	unsigned long PacketItemList(CNSPc *, CPacket &);    PATCH_MEMBER(unsigned long, PacketItemList, CNSPc * _COMMA CPacket &, 0x4378A0);
	unsigned short m_wSellPer;//this+0x0
	unsigned short m_wBuyPer;//this+0x2
	class std::map<unsigned long,CNSShopInventory::_Goods *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const ,CNSShopInventory::_Goods *> > > m_mapGoods;//this+0x4
	CNSShopInventory & operator=(const CNSShopInventory &);
	//void * __vecDelDtor(unsigned int);

	/*struct _Invoke {
	PATCH_MEMBER_INVOKE(CNSShopInventory &, CNSShopInventory, Constructor, );
	PATCH_MEMBER_INVOKE(void, CNSShopInventory, Destructor, );
	PATCH_MEMBER_INVOKE(void, CNSShopInventory, SetRate, unsigned short _COMMA unsigned short);
	PATCH_MEMBER_INVOKE(int, CNSShopInventory, Add, unsigned short _COMMA unsigned long);
	PATCH_MEMBER_INVOKE(int, CNSShopInventory, Add, unsigned short);
	PATCH_MEMBER_INVOKE(CNSShopInventory::_Goods *, CNSShopInventory, Find, unsigned long);
	PATCH_MEMBER_INVOKE(unsigned long, CNSShopInventory, GetBuyGold, unsigned short);
	PATCH_MEMBER_INVOKE(unsigned long, CNSShopInventory, PacketItemList, CNSPc * _COMMA CPacket &);
	};*/

#ifdef DEFINE_NS_CPP
	//DEFINE_NAKED_JMP(CNSShopInventory::Constructor(), 0x4375D0);
	//DEFINE_NAKED_JMP(CNSShopInventory::Destructor(), 0x437600);
	//DEFINE_NAKED_JMP(void CNSShopInventory::SetRate(unsigned short _COMMA unsigned short), 0x4B07E0);
	//DEFINE_NAKED_JMP(int CNSShopInventory::Add(unsigned short _COMMA unsigned long), 0x4377C0);
	//DEFINE_NAKED_JMP(int CNSShopInventory::Add(unsigned short), 0x4376F0);
	//DEFINE_NAKED_JMP(CNSShopInventory::_Goods * CNSShopInventory::Find(unsigned long), 0x437850);
	//DEFINE_NAKED_JMP(unsigned long CNSShopInventory::GetBuyGold(unsigned short), 0x44C5A0);
	//DEFINE_NAKED_JMP(unsigned long CNSShopInventory::PacketItemList(CNSPc * _COMMA CPacket &), 0x4378A0);
#endif
};




#endif