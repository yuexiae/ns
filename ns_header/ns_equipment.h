#ifndef NSHEADER_NS_EQUIPMENT_H_
#define NSHEADER_NS_EQUIPMENT_H_


class CNSCharacter;
class CNSPc;
class CNSItem;


class CNSEquipment {
public:
	static const unsigned int _size = 0x114;
	enum EQUIPMENTTYPE {
		EquipType_NULL = 0x0,
		EquipType_Head = 0x1,
		EquipType_Upper = 0x2,
		EquipType_LeftHand = 0x3,
		EquipType_RightHand = 0x4,
		EquipType_Glove = 0x5,
		EquipType_Lower = 0x6,
		EquipType_Foot = 0x7,
		EquipType_Cloak = 0x8,
		EquipType_Necklace = 0x9,
		EquipType_Earring = 0xA,
		EquipType_Armlet = 0xB,
		EquipType_LeftRing = 0xC,
		EquipType_RightRing = 0xD,
		EquipType_Belt = 0xE,
		EquipType_NsTank = 0xF,
		EquipType_Backpack = 0x10,
		EquipType_Mask = 0x11,
		EquipType_Cap = 0x12,
		EquipType_Upper2 = 0x13,
		EquipType_Lower2 = 0x14,
		EquipType_Glove2 = 0x15,
		EquipType_Foot2 = 0x16,
		EquipType_PSW_Slot1 = 0x40,
		EquipType_PSW_Slot2 = 0x41,
		EquipType_PSW_Slot3 = 0x42,
		EquipType_End = 0x43,
	};

	CNSEquipment();    PATCH_MEMBER(CNSEquipment &, Constructor, , 0x431480);
	~CNSEquipment();    PATCH_MEMBER(void, Destructor, , 0x4314C0);
	void SetParent(CNSPc *);    PATCH_MEMBER(void, SetParent, CNSPc *, 0x481CD0);
	unsigned long GetCount();
	void Clear();    PATCH_MEMBER(void, Clear, , 0x4823E0);
	int CheckItem(unsigned short);    PATCH_MEMBER(int, CheckItem, unsigned short, 0x4314D0);
	int GetPos(unsigned long);    PATCH_MEMBER(int, GetPos, unsigned long, 0x431530);
	CNSItem * Get(CNSEquipment::EQUIPMENTTYPE);    PATCH_MEMBER(CNSItem *, Get, CNSEquipment::EQUIPMENTTYPE, 0x423B60);
	CNSItem * GetObjectA(unsigned long);    PATCH_MEMBER(CNSItem *, GetObjectA, unsigned long, 0x431590);
	int DeleteObject(unsigned long);    PATCH_MEMBER(int, DeleteObject, unsigned long, 0x4315D0);
	unsigned short GetItemId(CNSEquipment::EQUIPMENTTYPE);    PATCH_MEMBER(unsigned short, GetItemId, CNSEquipment::EQUIPMENTTYPE, 0x4827D0);
	unsigned char GetItemGrade(CNSEquipment::EQUIPMENTTYPE);    PATCH_MEMBER(unsigned char, GetItemGrade, CNSEquipment::EQUIPMENTTYPE, 0x44A650);
	int Set(CNSEquipment::EQUIPMENTTYPE, CNSItem *);    PATCH_MEMBER(int, Set, CNSEquipment::EQUIPMENTTYPE _COMMA CNSItem *, 0x483280);
	void Delete(CNSEquipment::EQUIPMENTTYPE);    PATCH_MEMBER(void, Delete, CNSEquipment::EQUIPMENTTYPE, 0x4831F0);
	void DeleteAll();    PATCH_MEMBER(void, DeleteAll, , 0x431DB0);
	int CheckEquipment(CNSEquipment::EQUIPMENTTYPE, CNSItem *);    PATCH_MEMBER(int, CheckEquipment, CNSEquipment::EQUIPMENTTYPE _COMMA CNSItem *, 0x431630);
	static int CheckLimitRace(unsigned char, CNSItem *);    PATCH_STATIC(int, CheckLimitRace, unsigned char _COMMA CNSItem *, 0x431BC0);
	static int CheckLimitJob(unsigned char, CNSItem *);    PATCH_STATIC(int, CheckLimitJob, unsigned char _COMMA CNSItem *, 0x431C50);
	static int CheckLimitLevel(CNSCharacter *, CNSItem *);    PATCH_STATIC(int, CheckLimitLevel, CNSCharacter * _COMMA CNSItem *, 0x431D80);
	unsigned long m_dwCount;//this+0x0
	class CNSPc * m_pParent;//this+0x4
	class CNSItem * m_ItemArray[0x43];//this+0x8
	//void * __vecDelDtor(unsigned int);

	/*struct _Invoke {
	PATCH_MEMBER_INVOKE(CNSEquipment &, CNSEquipment, Constructor, );
	PATCH_MEMBER_INVOKE(void, CNSEquipment, Destructor, );
	PATCH_MEMBER_INVOKE(void, CNSEquipment, SetParent, CNSPc *);
	PATCH_MEMBER_INVOKE(void, CNSEquipment, Clear, );
	PATCH_MEMBER_INVOKE(int, CNSEquipment, CheckItem, unsigned short);
	PATCH_MEMBER_INVOKE(int, CNSEquipment, GetPos, unsigned long);
	PATCH_MEMBER_INVOKE(CNSItem *, CNSEquipment, Get, CNSEquipment::EQUIPMENTTYPE);
	PATCH_MEMBER_INVOKE(CNSItem *, CNSEquipment, GetObjectA, unsigned long);
	PATCH_MEMBER_INVOKE(int, CNSEquipment, DeleteObject, unsigned long);
	PATCH_MEMBER_INVOKE(unsigned short, CNSEquipment, GetItemId, CNSEquipment::EQUIPMENTTYPE);
	PATCH_MEMBER_INVOKE(unsigned char, CNSEquipment, GetItemGrade, CNSEquipment::EQUIPMENTTYPE);
	PATCH_MEMBER_INVOKE(int, CNSEquipment, Set, CNSEquipment::EQUIPMENTTYPE _COMMA CNSItem *);
	PATCH_MEMBER_INVOKE(void, CNSEquipment, Delete, CNSEquipment::EQUIPMENTTYPE);
	PATCH_MEMBER_INVOKE(void, CNSEquipment, DeleteAll, );
	PATCH_MEMBER_INVOKE(int, CNSEquipment, CheckEquipment, CNSEquipment::EQUIPMENTTYPE _COMMA CNSItem *);
	PATCH_STATIC_INVOKE(int, CheckLimitRace, unsigned char _COMMA CNSItem *);
	PATCH_STATIC_INVOKE(int, CheckLimitJob, unsigned char _COMMA CNSItem *);
	PATCH_STATIC_INVOKE(int, CheckLimitLevel, CNSCharacter * _COMMA CNSItem *);
	};*/
};
#ifdef DEFINE_NS_CPP
	//DEFINE_NAKED_JMP(CNSEquipment::Constructor(), 0x431480);
	//DEFINE_NAKED_JMP(CNSEquipment::Destructor(), 0x4314C0);
	//DEFINE_NAKED_JMP(void CNSEquipment::SetParent(CNSPc *), 0x481CD0);
	//DEFINE_NAKED_JMP(void CNSEquipment::Clear(), 0x4823E0);
	//DEFINE_NAKED_JMP(int CNSEquipment::CheckItem(unsigned short), 0x4314D0);
	//DEFINE_NAKED_JMP(int CNSEquipment::GetPos(unsigned long), 0x431530);
	DEFINE_NAKED_JMP(CNSItem * CNSEquipment::Get(CNSEquipment::EQUIPMENTTYPE), 0x423B60);
	//DEFINE_NAKED_JMP(CNSItem * CNSEquipment::GetObjectA(unsigned long), 0x431590);
	//DEFINE_NAKED_JMP(int CNSEquipment::DeleteObject(unsigned long), 0x4315D0);
	//DEFINE_NAKED_JMP(unsigned short CNSEquipment::GetItemId(CNSEquipment::EQUIPMENTTYPE), 0x4827D0);
	//DEFINE_NAKED_JMP(unsigned char CNSEquipment::GetItemGrade(CNSEquipment::EQUIPMENTTYPE), 0x44A650);
	DEFINE_NAKED_JMP(int CNSEquipment::Set(CNSEquipment::EQUIPMENTTYPE _COMMA CNSItem *), 0x483280);
	//DEFINE_NAKED_JMP(void CNSEquipment::Delete(CNSEquipment::EQUIPMENTTYPE), 0x4831F0);
	//DEFINE_NAKED_JMP(void CNSEquipment::DeleteAll(), 0x431DB0);
	//DEFINE_NAKED_JMP(int CNSEquipment::CheckEquipment(CNSEquipment::EQUIPMENTTYPE _COMMA CNSItem *), 0x431630);
	//DEFINE_NAKED_JMP(int CNSEquipment::CheckLimitRace(unsigned char _COMMA CNSItem *), 0x431BC0);
	//DEFINE_NAKED_JMP(int CNSEquipment::CheckLimitJob(unsigned char _COMMA CNSItem *), 0x431C50);
	//DEFINE_NAKED_JMP(int CNSEquipment::CheckLimitLevel(CNSCharacter * _COMMA CNSItem *), 0x431D80);
#endif






#endif