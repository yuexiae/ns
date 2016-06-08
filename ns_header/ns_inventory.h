#ifndef NSHEADER_NS_INVENTORY_H_
#define NSHEADER_NS_INVENTORY_H_


class CNSInventory {
public:
	static const unsigned int _size = 0x198;

	CNSInventory();    PATCH_MEMBER(CNSInventory &, Constructor, , 0x436780);
	~CNSInventory();    PATCH_MEMBER(void, Destructor, , 0x4367C0);
	unsigned long GetCount();    PATCH_MEMBER(unsigned long, GetCount, , 0x402B90);
	unsigned long GetMaxSpace();    PATCH_MEMBER(unsigned long, GetMaxSpace, , 0x437A20);
	int _IsFull();    PATCH_MEMBER(int, _IsFull, , 0x4832D0);
	int IsFull();    PATCH_MEMBER(int, IsFull, , 0x437A00);
	unsigned long GetSpace();    PATCH_MEMBER(unsigned long, GetSpace, , 0x43EBF0);
	int _Add(CNSItem *);    PATCH_MEMBER(int, _Add, CNSItem *, 0x4367E0);
	int Add(CNSItem *);    PATCH_MEMBER(int, Add, CNSItem *, 0x436830);
	CNSItem * Add2(CNSItem *, int);    PATCH_MEMBER(CNSItem *, Add2, CNSItem * _COMMA int, 0x436880);
	CNSItem * Get(unsigned short);    PATCH_MEMBER(CNSItem *, Get, unsigned short, 0x436C10);
	int Set(CNSItem *);    PATCH_MEMBER(int, Set, CNSItem *, 0x436BA0);
	int Set(unsigned short, CNSItem *);    PATCH_MEMBER(int, Set, unsigned short _COMMA CNSItem *, 0x436AE0);
	int SetPrimum(CNSItem *);    PATCH_MEMBER(int, SetPrimum, CNSItem *, 0x4369F0);
	int Delete(unsigned short);    PATCH_MEMBER(int, Delete, unsigned short, 0x436C50);
	void DeleteAll();    PATCH_MEMBER(void, DeleteAll, , 0x436E90);
	int GetPos(unsigned long);    PATCH_MEMBER(int, GetPos, unsigned long, 0x436F80);
	CNSItem * FindObject(unsigned short);    PATCH_MEMBER(CNSItem *, FindObject, unsigned short, 0x437040);
	CNSItem * FindObject(unsigned long);    PATCH_MEMBER(CNSItem *, FindObject, unsigned long, 0x436FF0);
	CNSItem * FindRandomObject();    PATCH_MEMBER(CNSItem *, FindRandomObject, , 0x4370C0);
	int DeleteObject(unsigned long);    PATCH_MEMBER(int, DeleteObject, unsigned long, 0x4371B0);
	int CheckItem(unsigned short);    PATCH_MEMBER(int, CheckItem, unsigned short, 0x4371F0);
	unsigned long GetItemCount(unsigned short);    PATCH_MEMBER(unsigned long, GetItemCount, unsigned short, 0x437260);
	unsigned long DeleteItem(CNSPc *, unsigned short, unsigned long, char *, unsigned long);    PATCH_MEMBER(unsigned long, DeleteItem, CNSPc * _COMMA unsigned short _COMMA unsigned long _COMMA char * _COMMA unsigned long, 0x4372D0);
	int DeleteQuestItem(CNSPc *, unsigned short);    PATCH_MEMBER(int, DeleteQuestItem, CNSPc * _COMMA unsigned short, 0x437430);
	void CheckPremiumItem(CNSPc *);    PATCH_MEMBER(void, CheckPremiumItem, CNSPc *, 0x437550);
	void Sort();    PATCH_MEMBER(void, Sort, , 0x436E60);
	int m_bExpand;//this+0x0
	unsigned long m_dwCount;//this+0x4
	class CNSItem * m_ItemArray[0x64];//this+0x8
	//void * __vecDelDtor(unsigned int);

	/*struct _Invoke {
	PATCH_MEMBER_INVOKE(CNSInventory &, CNSInventory, Constructor, );
	PATCH_MEMBER_INVOKE(void, CNSInventory, Destructor, );
	PATCH_MEMBER_INVOKE(unsigned long, CNSInventory, GetCount, );
	PATCH_MEMBER_INVOKE(unsigned long, CNSInventory, GetMaxSpace, );
	PATCH_MEMBER_INVOKE(int, CNSInventory, _IsFull, );
	PATCH_MEMBER_INVOKE(int, CNSInventory, IsFull, );
	PATCH_MEMBER_INVOKE(unsigned long, CNSInventory, GetSpace, );
	PATCH_MEMBER_INVOKE(int, CNSInventory, _Add, CNSItem *);
	PATCH_MEMBER_INVOKE(int, CNSInventory, Add, CNSItem *);
	PATCH_MEMBER_INVOKE(CNSItem *, CNSInventory, Add2, CNSItem * _COMMA int);
	PATCH_MEMBER_INVOKE(CNSItem *, CNSInventory, Get, unsigned short);
	PATCH_MEMBER_INVOKE(int, CNSInventory, Set, CNSItem *);
	PATCH_MEMBER_INVOKE(int, CNSInventory, Set, unsigned short _COMMA CNSItem *);
	PATCH_MEMBER_INVOKE(int, CNSInventory, SetPrimum, CNSItem *);
	PATCH_MEMBER_INVOKE(int, CNSInventory, Delete, unsigned short);
	PATCH_MEMBER_INVOKE(void, CNSInventory, DeleteAll, );
	PATCH_MEMBER_INVOKE(int, CNSInventory, GetPos, unsigned long);
	PATCH_MEMBER_INVOKE(CNSItem *, CNSInventory, FindObject, unsigned short);
	PATCH_MEMBER_INVOKE(CNSItem *, CNSInventory, FindObject, unsigned long);
	PATCH_MEMBER_INVOKE(CNSItem *, CNSInventory, FindRandomObject, );
	PATCH_MEMBER_INVOKE(int, CNSInventory, DeleteObject, unsigned long);
	PATCH_MEMBER_INVOKE(int, CNSInventory, CheckItem, unsigned short);
	PATCH_MEMBER_INVOKE(unsigned long, CNSInventory, GetItemCount, unsigned short);
	PATCH_MEMBER_INVOKE(unsigned long, CNSInventory, DeleteItem, CNSPc * _COMMA unsigned short _COMMA unsigned long _COMMA char * _COMMA unsigned long);
	PATCH_MEMBER_INVOKE(int, CNSInventory, DeleteQuestItem, CNSPc * _COMMA unsigned short);
	PATCH_MEMBER_INVOKE(void, CNSInventory, CheckPremiumItem, CNSPc *);
	PATCH_MEMBER_INVOKE(void, CNSInventory, Sort, );
	};*/
};
#ifdef DEFINE_NS_CPP
	//DEFINE_NAKED_JMP(CNSInventory::Constructor(), 0x436780);
	//DEFINE_NAKED_JMP(CNSInventory::Destructor(), 0x4367C0);
	DEFINE_NAKED_JMP(unsigned long CNSInventory::GetCount(), 0x402B90);
	DEFINE_NAKED_JMP(unsigned long CNSInventory::GetMaxSpace(), 0x437A20);
	DEFINE_NAKED_JMP(int CNSInventory::_IsFull(), 0x4832D0);
	DEFINE_NAKED_JMP(int CNSInventory::IsFull(), 0x437A00);
	DEFINE_NAKED_JMP(unsigned long CNSInventory::GetSpace(), 0x43EBF0);
	DEFINE_NAKED_JMP(int CNSInventory::_Add(CNSItem *), 0x4367E0);
	DEFINE_NAKED_JMP(int CNSInventory::Add(CNSItem *), 0x436830);
	DEFINE_NAKED_JMP(CNSItem * CNSInventory::Add2(CNSItem * _COMMA int), 0x436880);
	DEFINE_NAKED_JMP(CNSItem * CNSInventory::Get(unsigned short), 0x436C10);
	DEFINE_NAKED_JMP(int CNSInventory::Set(CNSItem *), 0x436BA0);
	DEFINE_NAKED_JMP(int CNSInventory::Set(unsigned short _COMMA CNSItem *), 0x436AE0);
	DEFINE_NAKED_JMP(int CNSInventory::SetPrimum(CNSItem *), 0x4369F0);
	DEFINE_NAKED_JMP(int CNSInventory::Delete(unsigned short), 0x436C50);
	DEFINE_NAKED_JMP(void CNSInventory::DeleteAll(), 0x436E90);
	DEFINE_NAKED_JMP(int CNSInventory::GetPos(unsigned long), 0x436F80);
	DEFINE_NAKED_JMP(CNSItem * CNSInventory::FindObject(unsigned short), 0x437040);
	DEFINE_NAKED_JMP(CNSItem * CNSInventory::FindObject(unsigned long), 0x436FF0);
	DEFINE_NAKED_JMP(CNSItem * CNSInventory::FindRandomObject(), 0x4370C0);
	DEFINE_NAKED_JMP(int CNSInventory::DeleteObject(unsigned long), 0x4371B0);
	DEFINE_NAKED_JMP(int CNSInventory::CheckItem(unsigned short), 0x4371F0);
	DEFINE_NAKED_JMP(unsigned long CNSInventory::GetItemCount(unsigned short), 0x437260);
	DEFINE_NAKED_JMP(unsigned long CNSInventory::DeleteItem(CNSPc * _COMMA unsigned short _COMMA unsigned long _COMMA char * _COMMA unsigned long), 0x4372D0);
	DEFINE_NAKED_JMP(int CNSInventory::DeleteQuestItem(CNSPc * _COMMA unsigned short), 0x437430);
	DEFINE_NAKED_JMP(void CNSInventory::CheckPremiumItem(CNSPc *), 0x437550);
	DEFINE_NAKED_JMP(void CNSInventory::Sort(), 0x436E60);
#endif






#endif