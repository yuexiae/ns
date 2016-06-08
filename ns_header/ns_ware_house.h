#ifndef NSHEADER_NS_WARE_HOUSE_H_
#define NSHEADER_NS_WARE_HOUSE_H_


class CNSWareHouse {
public:
	static const unsigned int _size = 0x34c;

	CNSWareHouse();    PATCH_MEMBER(CNSWareHouse &, Constructor, , 0x481D50);
	~CNSWareHouse();    PATCH_MEMBER(void, Destructor, , 0x481DF0);
	void SetParent(CNSPc *);    PATCH_MEMBER(void, SetParent, CNSPc *, 0x4E0A50);
	unsigned long GetCount();
	unsigned long GetTrayCount();
	unsigned long GetMaxSpace();    PATCH_MEMBER(unsigned long, GetMaxSpace, , 0x4E3120);
	int IsFull();    PATCH_MEMBER(int, IsFull, , 0x4E3100);
	int IsTrayFull();    PATCH_MEMBER(int, IsTrayFull, , 0x4E3220);
	int _Add(CNSItem *);    PATCH_MEMBER(int, _Add, CNSItem *, 0x4E0A80);
	int Add(CNSItem *);    PATCH_MEMBER(int, Add, CNSItem *, 0x4E0AD0);
	int GetSameItemPos(CNSItem *);    PATCH_MEMBER(int, GetSameItemPos, CNSItem *, 0x4E0B20);
	int InItem(CNSItem *);    PATCH_MEMBER(int, InItem, CNSItem *, 0x4E0BF0);
	int OutItem(CNSItem *);    PATCH_MEMBER(int, OutItem, CNSItem *, 0x4E0D30);
	int InGold(unsigned long);    PATCH_MEMBER(int, InGold, unsigned long, 0x4E0EF0);
	int OutGold(unsigned long);    PATCH_MEMBER(int, OutGold, unsigned long, 0x4E0F60);
	unsigned long GetGold();    PATCH_MEMBER(unsigned long, GetGold, , 0x414F50);
	CNSItem * GetObjectA(int);    PATCH_MEMBER(CNSItem *, GetObjectA, int, 0x4C8480);
	int GetPos(unsigned long);    PATCH_MEMBER(int, GetPos, unsigned long, 0x4E0FC0);
	CNSItem * FindObject(unsigned long);    PATCH_MEMBER(CNSItem *, FindObject, unsigned long, 0x4E1030);
	int Delete(unsigned short);    PATCH_MEMBER(int, Delete, unsigned short, 0x4E10B0);
	int DeleteObject(unsigned long);    PATCH_MEMBER(int, DeleteObject, unsigned long, 0x4E1070);
	void DeleteAll();    PATCH_MEMBER(void, DeleteAll, , 0x4E1170);
	void DeleteTray();    PATCH_MEMBER(void, DeleteTray, , 0x4E1200);
	int DBInHouseItem(CNSItem *);    PATCH_MEMBER(int, DBInHouseItem, CNSItem *, 0x4E1290);
	int DBOutHouseItem(CNSItem *);    PATCH_MEMBER(int, DBOutHouseItem, CNSItem *, 0x4E14C0);
	int DBInHouse();    PATCH_MEMBER(int, DBInHouse, , 0x4E16F0);
	int DBOutHouse();    PATCH_MEMBER(int, DBOutHouse, , 0x4E1B30);
	int DBGoldLoad(unsigned char &, unsigned long &);    PATCH_MEMBER(int, DBGoldLoad, unsigned char & _COMMA unsigned long &, 0x4E1E20);
	int DBGoldInsert();    PATCH_MEMBER(int, DBGoldInsert, , 0x4E1FD0);
	void DBDeleteAll();    PATCH_MEMBER(void, DBDeleteAll, , 0x4E2630);
	int DBItemLoad();    PATCH_MEMBER(int, DBItemLoad, , 0x4E27A0);
	static int DBIncGold(int, unsigned long);    PATCH_STATIC(int, DBIncGold, int _COMMA unsigned long, 0x4E2120);
	static int DBIncGold2Alias(int, unsigned long);    PATCH_STATIC(int, DBIncGold2Alias, int _COMMA unsigned long, 0x4E2230);
	static int DBDecGold(int, unsigned long);    PATCH_STATIC(int, DBDecGold, int _COMMA unsigned long, 0x4E2340);
	static int DBInItem2Alias(CNSPc *, char *, int);    PATCH_STATIC(int, DBInItem2Alias, CNSPc * _COMMA char * _COMMA int, 0x4E2450);
	int DBLoad(int);    PATCH_MEMBER(int, DBLoad, int, 0x4E2DB0);
	int DBSort(int);    PATCH_MEMBER(int, DBSort, int, 0x4E2E70);
	unsigned long PacketItemList(CPacket &);    PATCH_MEMBER(unsigned long, PacketItemList, CPacket &, 0x4E2F30);
	void SendWareHouseListMessage(unsigned char);    PATCH_MEMBER(void, SendWareHouseListMessage, unsigned char, 0x4E2FB0);
	int m_bLoad;//this+0x0
	int m_bGuildWareHouse;//this+0x4
	int m_nGuildSeq;//this+0x8
	unsigned long m_dwGuildRank;//this+0xC
	int m_nUserSeq;//this+0x10
	class CNSPc * m_pParent;//this+0x14
	unsigned long m_dwGold;//this+0x18
	unsigned long m_dwGoldTray;//this+0x1C
	unsigned long m_dwCount;//this+0x20
	class CNSItem * m_ItemArray[0x64];//this+0x24
	unsigned long m_dwTrayCount;//this+0x1B4
	class CNSItem * m_ItemTrayArray[0x64];//this+0x1B8
	int m_bExpand;//this+0x348
	//void * __vecDelDtor(unsigned int);

	/*struct _Invoke {
	PATCH_MEMBER_INVOKE(CNSWareHouse &, CNSWareHouse, Constructor, );
	PATCH_MEMBER_INVOKE(void, CNSWareHouse, Destructor, );
	PATCH_MEMBER_INVOKE(void, CNSWareHouse, SetParent, CNSPc *);
	PATCH_MEMBER_INVOKE(unsigned long, CNSWareHouse, GetMaxSpace, );
	PATCH_MEMBER_INVOKE(int, CNSWareHouse, IsFull, );
	PATCH_MEMBER_INVOKE(int, CNSWareHouse, IsTrayFull, );
	PATCH_MEMBER_INVOKE(int, CNSWareHouse, _Add, CNSItem *);
	PATCH_MEMBER_INVOKE(int, CNSWareHouse, Add, CNSItem *);
	PATCH_MEMBER_INVOKE(int, CNSWareHouse, GetSameItemPos, CNSItem *);
	PATCH_MEMBER_INVOKE(int, CNSWareHouse, InItem, CNSItem *);
	PATCH_MEMBER_INVOKE(int, CNSWareHouse, OutItem, CNSItem *);
	PATCH_MEMBER_INVOKE(int, CNSWareHouse, InGold, unsigned long);
	PATCH_MEMBER_INVOKE(int, CNSWareHouse, OutGold, unsigned long);
	PATCH_MEMBER_INVOKE(unsigned long, CNSWareHouse, GetGold, );
	PATCH_MEMBER_INVOKE(CNSItem *, CNSWareHouse, GetObjectA, int);
	PATCH_MEMBER_INVOKE(int, CNSWareHouse, GetPos, unsigned long);
	PATCH_MEMBER_INVOKE(CNSItem *, CNSWareHouse, FindObject, unsigned long);
	PATCH_MEMBER_INVOKE(int, CNSWareHouse, Delete, unsigned short);
	PATCH_MEMBER_INVOKE(int, CNSWareHouse, DeleteObject, unsigned long);
	PATCH_MEMBER_INVOKE(void, CNSWareHouse, DeleteAll, );
	PATCH_MEMBER_INVOKE(void, CNSWareHouse, DeleteTray, );
	PATCH_MEMBER_INVOKE(int, CNSWareHouse, DBInHouseItem, CNSItem *);
	PATCH_MEMBER_INVOKE(int, CNSWareHouse, DBOutHouseItem, CNSItem *);
	PATCH_MEMBER_INVOKE(int, CNSWareHouse, DBInHouse, );
	PATCH_MEMBER_INVOKE(int, CNSWareHouse, DBOutHouse, );
	PATCH_MEMBER_INVOKE(int, CNSWareHouse, DBGoldLoad, unsigned char & _COMMA unsigned long &);
	PATCH_MEMBER_INVOKE(int, CNSWareHouse, DBGoldInsert, );
	PATCH_MEMBER_INVOKE(void, CNSWareHouse, DBDeleteAll, );
	PATCH_MEMBER_INVOKE(int, CNSWareHouse, DBItemLoad, );
	PATCH_STATIC_INVOKE(int, DBIncGold, int _COMMA unsigned long);
	PATCH_STATIC_INVOKE(int, DBIncGold2Alias, int _COMMA unsigned long);
	PATCH_STATIC_INVOKE(int, DBDecGold, int _COMMA unsigned long);
	PATCH_STATIC_INVOKE(int, DBInItem2Alias, CNSPc * _COMMA char * _COMMA int);
	PATCH_MEMBER_INVOKE(int, CNSWareHouse, DBLoad, int);
	PATCH_MEMBER_INVOKE(int, CNSWareHouse, DBSort, int);
	PATCH_MEMBER_INVOKE(unsigned long, CNSWareHouse, PacketItemList, CPacket &);
	PATCH_MEMBER_INVOKE(void, CNSWareHouse, SendWareHouseListMessage, unsigned char);
	};*/
};
#ifdef DEFINE_NS_CPP
	//DEFINE_NAKED_JMP(CNSWareHouse::Constructor(), 0x481D50);
	//DEFINE_NAKED_JMP(CNSWareHouse::Destructor(), 0x481DF0);
	//DEFINE_NAKED_JMP(void CNSWareHouse::SetParent(CNSPc *), 0x4E0A50);
	//DEFINE_NAKED_JMP(unsigned long CNSWareHouse::GetMaxSpace(), 0x4E3120);
	//DEFINE_NAKED_JMP(int CNSWareHouse::IsFull(), 0x4E3100);
	//DEFINE_NAKED_JMP(int CNSWareHouse::IsTrayFull(), 0x4E3220);
	DEFINE_NAKED_JMP(int CNSWareHouse::_Add(CNSItem *), 0x4E0A80);
	//DEFINE_NAKED_JMP(int CNSWareHouse::Add(CNSItem *), 0x4E0AD0);
	//DEFINE_NAKED_JMP(int CNSWareHouse::GetSameItemPos(CNSItem *), 0x4E0B20);
	//DEFINE_NAKED_JMP(int CNSWareHouse::InItem(CNSItem *), 0x4E0BF0);
	//DEFINE_NAKED_JMP(int CNSWareHouse::OutItem(CNSItem *), 0x4E0D30);
	//DEFINE_NAKED_JMP(int CNSWareHouse::InGold(unsigned long), 0x4E0EF0);
	//DEFINE_NAKED_JMP(int CNSWareHouse::OutGold(unsigned long), 0x4E0F60);
	//DEFINE_NAKED_JMP(unsigned long CNSWareHouse::GetGold(), 0x414F50);
	//DEFINE_NAKED_JMP(CNSItem * CNSWareHouse::GetObjectA(int), 0x4C8480);
	//DEFINE_NAKED_JMP(int CNSWareHouse::GetPos(unsigned long), 0x4E0FC0);
	//DEFINE_NAKED_JMP(CNSItem * CNSWareHouse::FindObject(unsigned long), 0x4E1030);
	//DEFINE_NAKED_JMP(int CNSWareHouse::Delete(unsigned short), 0x4E10B0);
	//DEFINE_NAKED_JMP(int CNSWareHouse::DeleteObject(unsigned long), 0x4E1070);
	DEFINE_NAKED_JMP(void CNSWareHouse::DeleteAll(), 0x4E1170);
	//DEFINE_NAKED_JMP(void CNSWareHouse::DeleteTray(), 0x4E1200);
	//DEFINE_NAKED_JMP(int CNSWareHouse::DBInHouseItem(CNSItem *), 0x4E1290);
	//DEFINE_NAKED_JMP(int CNSWareHouse::DBOutHouseItem(CNSItem *), 0x4E14C0);
	//DEFINE_NAKED_JMP(int CNSWareHouse::DBInHouse(), 0x4E16F0);
	//DEFINE_NAKED_JMP(int CNSWareHouse::DBOutHouse(), 0x4E1B30);
	//DEFINE_NAKED_JMP(int CNSWareHouse::DBGoldLoad(unsigned char & _COMMA unsigned long &), 0x4E1E20);
	//DEFINE_NAKED_JMP(int CNSWareHouse::DBGoldInsert(), 0x4E1FD0);
	//DEFINE_NAKED_JMP(void CNSWareHouse::DBDeleteAll(), 0x4E2630);
	//DEFINE_NAKED_JMP(int CNSWareHouse::DBItemLoad(), 0x4E27A0);
	//DEFINE_NAKED_JMP(int CNSWareHouse::DBIncGold(int _COMMA unsigned long), 0x4E2120);
	//DEFINE_NAKED_JMP(int CNSWareHouse::DBIncGold2Alias(int _COMMA unsigned long), 0x4E2230);
	//DEFINE_NAKED_JMP(int CNSWareHouse::DBDecGold(int _COMMA unsigned long), 0x4E2340);
	//DEFINE_NAKED_JMP(int CNSWareHouse::DBInItem2Alias(CNSPc * _COMMA char * _COMMA int), 0x4E2450);
	//DEFINE_NAKED_JMP(int CNSWareHouse::DBLoad(int), 0x4E2DB0);
	//DEFINE_NAKED_JMP(int CNSWareHouse::DBSort(int), 0x4E2E70);
	//DEFINE_NAKED_JMP(unsigned long CNSWareHouse::PacketItemList(CPacket &), 0x4E2F30);
	//DEFINE_NAKED_JMP(void CNSWareHouse::SendWareHouseListMessage(unsigned char), 0x4E2FB0);
#endif




#endif