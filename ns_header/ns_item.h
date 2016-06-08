#ifndef NSHEADER_NS_ITEM_H_
#define NSHEADER_NS_ITEM_H_

#include "ns_header/ns_object.h"

class CNSItem : public CNSObject {
public:
    static const unsigned int _size = 0xb8;

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
        OptionType_Ar = 0x17,
        OptionType_Dr = 0x18,
        OptionType_HpRegen = 0x20,
        OptionType_MpRegen = 0x21,
        OptionType_StaRegen = 0x22,
        OptionType_HpSteal = 0x23,
        OptionType_MpSteal = 0x24,
        OptionType_StaSteal = 0x25,
        OptionType_HpRecovery = 0x26,
        OptionType_MpRecovery = 0x27,
        OptionType_StaRecovery = 0x28,
        OptionType_HpRecoveryPer = 0x29,
        OptionType_MpRecoveryPer = 0x2A,
        OptionType_StaRecoveryPer = 0x2B,
        OptionType_HpRecovery2 = 0x2C,
        OptionType_Rs1 = 0x30,
        OptionType_Rs2 = 0x31,
        OptionType_Rs3 = 0x32,
        OptionType_Rs4 = 0x33,
        OptionType_MoveSpeed = 0x40,
        OptionType_LevelDown = 0x41,
        OptionType_AttackSpeed = 0x42,
        OptionType_DpPer = 0x43,
        OptionType_MaxHpExpand = 0x44,
        OptionType_Grade = 0x50,
        OptionType_Rank = 0x51,
        OptionType_Set = 0x52,
        OptionType_Skill = 0x61,
        OptionType_SkillLevel = 0x62,
        OptionType_FullSwine = 0x63,
        OptionType_Cure = 0x64,
        OptionType_Bundle_ItemId = 0x70,
        OptionType_Bundle_ItemCount = 0x71,
        OptionType_Date_Available = 0x72,
        OptionType_Date_StartUsed1 = 0x73,
        OptionType_Date_StartUsed2 = 0x74,
        OptionType_Date_Available2 = 0x75,
        OptionType_Bundle_Gold = 0x76,
        OptionType_Date_EndBind1 = 0x77,
        OptionType_Date_EndBind2 = 0x78,
        OptionType_Duration_Time = 0x80,
        OptionType_Minute_Available = 0x81,
        OptionType_Minute_StartUsed1 = 0x82,
        OptionType_Minute_StartUsed2 = 0x83,
        OptionType_NsTank = 0xA0,
        OptionType_NsSkill = 0xA1,
        OptionType_NsGrade = 0xA2,
        OptionType_MobFood = 0xB0,
        OptionType_PetFood = 0xB1,
        OptionType_TpPotion = 0xB2,
        OptionType_DashPotion = 0xB3,
        OptionType_ImmunPoisonPotion = 0xB4,
        OptionType_Warp = 0xC0,
        OptionType_Call = 0xC1,
        OptionType_Dice = 0xC2,
        OptionType_ExpUp = 0xC3,
        OptionType_ExpUpParty = 0xC4,
        OptionType_MiningUp = 0xC5,
        OptionType_BlockCall = 0xC6,
        OptionType_RealmBuff = 0xC7,
        OptionType_TpUp = 0xC8,
        OptionType_Quest = 0xC9,
        OptionType_Random = 0xCA,
        OptionType_ExpUpShort = 0xCB,
        OptionType_OverlapExpUp = 0xCC,
        OptionType_OverlapGoldUp = 0xCD,
        OptionType_MaxStaMp = 0xCE,
        OptionType_TraceDarkStone = 0xCF,
    };

    enum EQUIPMENTTYPE {
        EquipType_NULL = 0x0,
        EquipType_Head = 0x1,
        EquipType_Upper = 0x2,
        EquipType_Glove = 0x3,
        EquipType_Lower = 0x4,
        EquipType_Foot = 0x5,
        EquipType_Cloak = 0x6,
        EquipType_NsTank = 0x7,
        EquipType_LeftHand = 0x10,
        EquipType_RightHand = 0x11,
        EquipType_LeftOrRightHand = 0x12,
        EquipType_TwoHand = 0x13,
        EquipType_Necklace = 0x20,
        EquipType_Earring = 0x21,
        EquipType_Ring = 0x22,
        EquipType_Armlet = 0x23,
        EquipType_Belt = 0x24,
        EquipType_Backpack = 0x30,
        EquipType_Mask = 0x31,
        EquipType_Cap = 0x32,
        EquipType_PSW_Slot1 = 0x40,
        EquipType_PSW_Slot2 = 0x41,
        EquipType_PSW_Slot3 = 0x42,
    };

    enum ITEMSEQTYPE {
        PosType_NULL = 0x0,
        PosType_Equip = 0x1,
        PosType_Inven = 0x100,
        PosType_WareHouse = 0x1000,
        PosType_Auction = 0x2000,
        PosType_Auction2 = 0x3000,
    };

    enum ITEMTYPE {
        ItemType_Sword = 0x10,
        ItemType_Blunt = 0x11,
        ItemType_Gun = 0x12,
        ItemType_TwoHanded_Sword = 0x20,
        ItemType_TwoHanded_Spear = 0x21,
        ItemType_TwoHanded_Blunt = 0x22,
        ItemType_TwoHanded_Staff = 0x23,
        ItemType_TwoHanded_Gun = 0x24,
        ItemType_TwoHanded_Bow = 0x25,
        ItemType_Head = 0x30,
        ItemType_Upper = 0x31,
        ItemType_Glove = 0x32,
        ItemType_Shield = 0x33,
        ItemType_Lower = 0x34,
        ItemType_Foot = 0x35,
        ItemType_Robe = 0x36,
        ItemType_Cloak = 0x37,
        ItemType_NSTank = 0x38,
        ItemType_RobeLower = 0x39,
        ItemType_Necklace = 0x40,
        ItemType_Earring = 0x41,
        ItemType_Ring = 0x42,
        ItemType_Armlet = 0x43,
        ItemType_Belt = 0x44,
        ItemType_Backpack = 0x45,
        ItemType_Mask = 0x46,
        ItemType_Core = 0x51,
        ItemType_Upgrade = 0x52,
    };

    enum ITEMKIND {
        KindType_Equipment = 0x0,
        KindType_UseItem = 0x1,
        KindType_Material = 0x2,
        KindType_Upgrade = 0x3,
        KindType_UpgradePlus = 0x4,
        KindType_Core = 0xA,
        KindType_AncientCore = 0xB,
    };

    enum ITEMRARE {
        RareType_Normal = 0x0,
        RareType_SemiRare = 0x1,
        RareType_Socket = 0x2,
        RareType_Steam = 0x3,
        RareType_AncientSteam = 0x4,
        RareType_Rare = 0x5,
        RareType_RareSteam = 0x6,
        RareType_Quest = 0xA,
        RareType_Revert = 0xB,
        RareType_Costume = 0xC,
        RareType_Premium = 0x14,
        RareType_Premium_Confirm = 0x15,
    };

    char m_szItemName[0x19];//this+0x1C
    int m_nSeq;//this+0x38
    unsigned short m_wPosDb;//this+0x3C
    unsigned short m_wPos;//this+0x3E
    unsigned short m_wItemId;//this+0x40
    unsigned short m_wQuestId;//this+0x42
    unsigned char m_btKind;//this+0x44
    unsigned short m_wType;//this+0x46
    unsigned char m_btRare;//this+0x48
    unsigned long m_dwGold;//this+0x4C
    unsigned char m_btCount;//this+0x50
    unsigned char m_btCountDb;//this+0x51
    unsigned char m_btLimitLevel;//this+0x52
    unsigned char m_btLimitRace;//this+0x53
    unsigned char m_btLimitJob[0x4];//this+0x54
    unsigned char m_btEquipmentPart;//this+0x58
    unsigned char m_btSteamMachine;//this+0x59
    unsigned short m_wAttackMinDamage;//this+0x5A
    unsigned short m_wAttackMaxDamage;//this+0x5C
    unsigned char m_btAttackSpeed;//this+0x5E
    unsigned char m_btAttackDistance;//this+0x5F
    unsigned char m_btDefenseDamage;//this+0x60
    struct Option {
        static const unsigned int _size = 0x4;

        unsigned char btParam;//this+0x0
        unsigned short wValue;//this+0x2
    };
    struct CNSItem::Option m_Option[0xA];//this+0x62
    char * m_szDbDescription;//this+0x8C
    char m_szOwnerUserAlias[0x19];//this+0x90
    int m_nUserSeq;//this+0xAC
    int m_nAliasSeq;//this+0xB0
    int m_nUniqueSeq;//this+0xB4
    unsigned short GetMachineSkillId(unsigned char, unsigned short);    PATCH_MEMBER(unsigned short, GetMachineSkillId, unsigned char _COMMA unsigned short, 0x43F5D0);
    CNSItem(const CNSItem &);
    CNSItem(); CNSItem & CNSItem::Constructor();   PATCH_MEMBER(CNSItem &, Constructor, , 0x437DD0);
    virtual ~CNSItem();    PATCH_MEMBER(void, Destructor, , 0x437EA0);
    static void * operator new(unsigned int);    //PATCH_STATIC(void *, operator new, unsigned int, 0x419FC0);
    static void operator delete(void *);    //PATCH_STATIC(void, operator delete, void *, 0x41A0B0);
    int IsRevert();    PATCH_MEMBER(int, IsRevert, , 0x419A80);
    int IsRevertWareHouse();    PATCH_MEMBER(int, IsRevertWareHouse, , 0x4E3180);
    int IsQuest();    PATCH_MEMBER(int, IsQuest, , 0x419AC0);
    int IsPremium();    PATCH_MEMBER(int, IsPremium, , 0x44C620);
    int IsNormal();    PATCH_MEMBER(int, IsNormal, , 0x44C530);
    int IsNotDelete();    PATCH_MEMBER(int, IsNotDelete, , 0x483740);
    int IsRider();    PATCH_MEMBER(int, IsRider, , 0x437B40);
    int IsBlockMedium();
    int IsBlockSmall();
    int IsSiegeWeapon();    PATCH_MEMBER(int, IsSiegeWeapon, , 0x4832F0);
    int IsBinding();    PATCH_MEMBER(int, IsBinding, , 0x4837A0);
    char * GetItemName();    PATCH_MEMBER(char *, GetItemName, , 0x419D30);
    unsigned short GetItemId();    PATCH_MEMBER(unsigned short, GetItemId, , 0x419D50);
    CNSItem::ITEMTYPE GetItemType();    PATCH_MEMBER(CNSItem::ITEMTYPE, GetItemType, , 0x423B40);
    CNSItem::ITEMRARE GetRare();    PATCH_MEMBER(CNSItem::ITEMRARE, GetRare, , 0x44C580);
    int GetOptionLevelDown(CNSCharacter *);    PATCH_MEMBER(int, GetOptionLevelDown, CNSCharacter *, 0x437EF0);
    unsigned short GetOptionValue(CNSItem::OPTIONTYPE);    PATCH_MEMBER(unsigned short, GetOptionValue, CNSItem::OPTIONTYPE, 0x437FA0);
    void AddOptionValue(CNSItem::OPTIONTYPE, unsigned short);    PATCH_MEMBER(void, AddOptionValue, CNSItem::OPTIONTYPE _COMMA unsigned short, 0x438130);
    unsigned long GetOptionSpace();    PATCH_MEMBER(unsigned long, GetOptionSpace, , 0x4381D0);
    int GetGrade();    PATCH_MEMBER(int, GetGrade, , 0x419F30);
    int GetSpecialGrade();    PATCH_MEMBER(int, GetSpecialGrade, , 0x419F50);
    int GetGradeValue();    PATCH_MEMBER(int, GetGradeValue, , 0x438000);
    char * GetItemTitle(char *, int);    PATCH_MEMBER(char *, GetItemTitle, char * _COMMA int, 0x419DD0);
    void SetGold(unsigned long);
    unsigned char GetCount();    PATCH_MEMBER(unsigned char, GetCount, , 0x419D70);
    unsigned char IncCount(unsigned char);
    unsigned char DecCount(unsigned char);    PATCH_MEMBER(unsigned char, DecCount, unsigned char, 0x44C640);
    unsigned char GetMaxCount();    PATCH_MEMBER(unsigned char, GetMaxCount, , 0x437A40);
    unsigned short GetQuestId();    PATCH_MEMBER(unsigned short, GetQuestId, , 0x483780);
    void SetOwner(char *);    PATCH_MEMBER(void, SetOwner, char *, 0x437EC0);
    void MakeRandom(int);    PATCH_MEMBER(void, MakeRandom, int, 0x43B3B0);
    char * GetDescription(CNSPc *, char *, int);    PATCH_MEMBER(char *, GetDescription, CNSPc * _COMMA char * _COMMA int, 0x43E010);
    int AddOptionString(CNSPc *, char *);    PATCH_MEMBER(int, AddOptionString, CNSPc * _COMMA char *, 0x43CC70);
    int Use(unsigned char);    PATCH_MEMBER(int, Use, unsigned char, 0x437B80);
    int Use(CNSPc *, unsigned char);    PATCH_MEMBER(int, Use, CNSPc * _COMMA unsigned char, 0x4389F0);
    int GetPremiumItemBuff();    PATCH_MEMBER(int, GetPremiumItemBuff, , 0x43C330);
    int IsEnablePremiumItemBuff(CNSPc *);    PATCH_MEMBER(int, IsEnablePremiumItemBuff, CNSPc *, 0x43C3E0);
    int UsePremiumItem(CNSPc *);    PATCH_MEMBER(int, UsePremiumItem, CNSPc *, 0x43BD10);
    int UsePremiumItem2(CNSPc *);    PATCH_MEMBER(int, UsePremiumItem2, CNSPc *, 0x43BDD0);
    int UsePremiumItem3(CNSPc *);    PATCH_MEMBER(int, UsePremiumItem3, CNSPc *, 0x43BEB0);
    int UseRandomItem(CNSPc *);    PATCH_MEMBER(int, UseRandomItem, CNSPc *, 0x43BF60);
    static int UseRandomItemTest(CNSPc *, unsigned short, unsigned long);    PATCH_STATIC(int, UseRandomItemTest, CNSPc * _COMMA unsigned short _COMMA unsigned long, 0x43C090);
    int AddPremiumItemBuff(CNSPc *);    PATCH_MEMBER(int, AddPremiumItemBuff, CNSPc *, 0x43C4E0);
    int DeletePremiumItemBuff(CNSPc *);    PATCH_MEMBER(int, DeletePremiumItemBuff, CNSPc *, 0x43C750);
    int GetPremiumAbleDays();    PATCH_MEMBER(int, GetPremiumAbleDays, , 0x43C7E0);
    int GetPremiumAbleMinutes();    PATCH_MEMBER(int, GetPremiumAbleMinutes, , 0x43C930);
    int GetBindAbleDays();    PATCH_MEMBER(int, GetBindAbleDays, , 0x43CA70);
    int SetBindItem(unsigned short, int);    PATCH_MEMBER(int, SetBindItem, unsigned short _COMMA int, 0x43CB40);
    int CalcOption(CNSCharacter *);    PATCH_MEMBER(int, CalcOption, CNSCharacter *, 0x438220);
    int CalcOption2(CNSCharacter *);    PATCH_MEMBER(int, CalcOption2, CNSCharacter *, 0x438490);
    int CalcOption3(CNSCharacter *);    PATCH_MEMBER(int, CalcOption3, CNSCharacter *, 0x438720);
    int CalcNsOption(CNSPc *, int, unsigned char);    PATCH_MEMBER(int, CalcNsOption, CNSPc * _COMMA int _COMMA unsigned char, 0x438870);
    CNSItem * Clone(unsigned char);    PATCH_MEMBER(CNSItem *, Clone, unsigned char, 0x43B310);
    unsigned char GetUseLevel(CNSCharacter *);    PATCH_MEMBER(unsigned char, GetUseLevel, CNSCharacter *, 0x431E10);
    void PacketItemInfo(CPacket &);    PATCH_MEMBER(void, PacketItemInfo, CPacket &, 0x44C470);
    CNSItem & operator=(const CNSItem &);    //PATCH_MEMBER(CNSItem &, operator=, const CNSItem &, 0x41A9B0);
    //void __local_vftable_ctor_closure();
    //virtual void * __vecDelDtor(unsigned int);

    /*struct _Invoke {
    PATCH_MEMBER_INVOKE(unsigned short, CNSItem, GetMachineSkillId, unsigned char _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(CNSItem &, CNSItem, Constructor, );
    PATCH_MEMBER_INVOKE(void, CNSItem, Destructor, );
    //PATCH_STATIC_INVOKE(void *, operator new, unsigned int);
    //PATCH_STATIC_INVOKE(void, operator delete, void *);
    PATCH_MEMBER_INVOKE(int, CNSItem, IsRevert, );
    PATCH_MEMBER_INVOKE(int, CNSItem, IsRevertWareHouse, );
    PATCH_MEMBER_INVOKE(int, CNSItem, IsQuest, );
    PATCH_MEMBER_INVOKE(int, CNSItem, IsPremium, );
    PATCH_MEMBER_INVOKE(int, CNSItem, IsNormal, );
    PATCH_MEMBER_INVOKE(int, CNSItem, IsNotDelete, );
    PATCH_MEMBER_INVOKE(int, CNSItem, IsRider, );
    PATCH_MEMBER_INVOKE(int, CNSItem, IsSiegeWeapon, );
    PATCH_MEMBER_INVOKE(int, CNSItem, IsBinding, );
    PATCH_MEMBER_INVOKE(char *, CNSItem, GetItemName, );
    PATCH_MEMBER_INVOKE(unsigned short, CNSItem, GetItemId, );
    PATCH_MEMBER_INVOKE(CNSItem::ITEMTYPE, CNSItem, GetItemType, );
    PATCH_MEMBER_INVOKE(CNSItem::ITEMRARE, CNSItem, GetRare, );
    PATCH_MEMBER_INVOKE(int, CNSItem, GetOptionLevelDown, CNSCharacter *);
    PATCH_MEMBER_INVOKE(unsigned short, CNSItem, GetOptionValue, CNSItem::OPTIONTYPE);
    PATCH_MEMBER_INVOKE(void, CNSItem, AddOptionValue, CNSItem::OPTIONTYPE _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(unsigned long, CNSItem, GetOptionSpace, );
    PATCH_MEMBER_INVOKE(int, CNSItem, GetGrade, );
    PATCH_MEMBER_INVOKE(int, CNSItem, GetSpecialGrade, );
    PATCH_MEMBER_INVOKE(int, CNSItem, GetGradeValue, );
    PATCH_MEMBER_INVOKE(char *, CNSItem, GetItemTitle, char * _COMMA int);
    PATCH_MEMBER_INVOKE(unsigned char, CNSItem, GetCount, );
    PATCH_MEMBER_INVOKE(unsigned char, CNSItem, DecCount, unsigned char);
    PATCH_MEMBER_INVOKE(unsigned char, CNSItem, GetMaxCount, );
    PATCH_MEMBER_INVOKE(unsigned short, CNSItem, GetQuestId, );
    PATCH_MEMBER_INVOKE(void, CNSItem, SetOwner, char *);
    PATCH_MEMBER_INVOKE(void, CNSItem, MakeRandom, int);
    PATCH_MEMBER_INVOKE(char *, CNSItem, GetDescription, CNSPc * _COMMA char * _COMMA int);
    PATCH_MEMBER_INVOKE(int, CNSItem, AddOptionString, CNSPc * _COMMA char *);
    PATCH_MEMBER_INVOKE(int, CNSItem, Use, unsigned char);
    PATCH_MEMBER_INVOKE(int, CNSItem, Use, CNSPc * _COMMA unsigned char);
    PATCH_MEMBER_INVOKE(int, CNSItem, GetPremiumItemBuff, );
    PATCH_MEMBER_INVOKE(int, CNSItem, IsEnablePremiumItemBuff, CNSPc *);
    PATCH_MEMBER_INVOKE(int, CNSItem, UsePremiumItem, CNSPc *);
    PATCH_MEMBER_INVOKE(int, CNSItem, UsePremiumItem2, CNSPc *);
    PATCH_MEMBER_INVOKE(int, CNSItem, UsePremiumItem3, CNSPc *);
    PATCH_MEMBER_INVOKE(int, CNSItem, UseRandomItem, CNSPc *);
    PATCH_STATIC_INVOKE(int, UseRandomItemTest, CNSPc * _COMMA unsigned short _COMMA unsigned long);
    PATCH_MEMBER_INVOKE(int, CNSItem, AddPremiumItemBuff, CNSPc *);
    PATCH_MEMBER_INVOKE(int, CNSItem, DeletePremiumItemBuff, CNSPc *);
    PATCH_MEMBER_INVOKE(int, CNSItem, GetPremiumAbleDays, );
    PATCH_MEMBER_INVOKE(int, CNSItem, GetPremiumAbleMinutes, );
    PATCH_MEMBER_INVOKE(int, CNSItem, GetBindAbleDays, );
    PATCH_MEMBER_INVOKE(int, CNSItem, SetBindItem, unsigned short _COMMA int);
    PATCH_MEMBER_INVOKE(int, CNSItem, CalcOption, CNSCharacter *);
    PATCH_MEMBER_INVOKE(int, CNSItem, CalcOption2, CNSCharacter *);
    PATCH_MEMBER_INVOKE(int, CNSItem, CalcOption3, CNSCharacter *);
    PATCH_MEMBER_INVOKE(int, CNSItem, CalcNsOption, CNSPc * _COMMA int _COMMA unsigned char);
    PATCH_MEMBER_INVOKE(CNSItem *, CNSItem, Clone, unsigned char);
    PATCH_MEMBER_INVOKE(unsigned char, CNSItem, GetUseLevel, CNSCharacter *);
    PATCH_MEMBER_INVOKE(void, CNSItem, PacketItemInfo, CPacket &);
    //PATCH_MEMBER_INVOKE(CNSItem &, CNSItem, operator=, const CNSItem &);
    };*/
};
#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(unsigned short CNSItem::GetMachineSkillId(unsigned char _COMMA unsigned short), 0x43F5D0);
DEFINE_NAKED_JMP(CNSItem & CNSItem::Constructor(), 0x437DD0);
//DEFINE_NAKED_JMP(CNSItem::Destructor(), 0x437EA0);
DEFINE_NAKED_JMP(void * CNSItem::operator new(unsigned int), 0x419FC0);
DEFINE_NAKED_JMP(void CNSItem::operator delete(void *), 0x41A0B0);
DEFINE_NAKED_JMP(int CNSItem::IsRevert(), 0x419A80);
DEFINE_NAKED_JMP(int CNSItem::IsRevertWareHouse(), 0x4E3180);
DEFINE_NAKED_JMP(int CNSItem::IsQuest(), 0x419AC0);
DEFINE_NAKED_JMP(int CNSItem::IsPremium(), 0x44C620);
DEFINE_NAKED_JMP(int CNSItem::IsNormal(), 0x44C530);
DEFINE_NAKED_JMP(int CNSItem::IsNotDelete(), 0x483740);
DEFINE_NAKED_JMP(int CNSItem::IsRider(), 0x437B40);
DEFINE_NAKED_JMP(int CNSItem::IsSiegeWeapon(), 0x4832F0);
DEFINE_NAKED_JMP(int CNSItem::IsBinding(), 0x4837A0);
DEFINE_NAKED_JMP(char * CNSItem::GetItemName(), 0x419D30);
DEFINE_NAKED_JMP(unsigned short CNSItem::GetItemId(), 0x419D50);
DEFINE_NAKED_JMP(CNSItem::ITEMTYPE CNSItem::GetItemType(), 0x423B40);
DEFINE_NAKED_JMP(CNSItem::ITEMRARE CNSItem::GetRare(), 0x44C580);
DEFINE_NAKED_JMP(int CNSItem::GetOptionLevelDown(CNSCharacter *), 0x437EF0);
DEFINE_NAKED_JMP(unsigned short CNSItem::GetOptionValue(CNSItem::OPTIONTYPE), 0x437FA0);
DEFINE_NAKED_JMP(void CNSItem::AddOptionValue(CNSItem::OPTIONTYPE _COMMA unsigned short), 0x438130);
DEFINE_NAKED_JMP(unsigned long CNSItem::GetOptionSpace(), 0x4381D0);
DEFINE_NAKED_JMP(int CNSItem::GetGrade(), 0x419F30);
DEFINE_NAKED_JMP(int CNSItem::GetSpecialGrade(), 0x419F50);
DEFINE_NAKED_JMP(int CNSItem::GetGradeValue(), 0x438000);
DEFINE_NAKED_JMP(char * CNSItem::GetItemTitle(char * _COMMA int), 0x419DD0);
DEFINE_NAKED_JMP(unsigned char CNSItem::GetCount(), 0x419D70);
DEFINE_NAKED_JMP(unsigned char CNSItem::DecCount(unsigned char), 0x44C640);
DEFINE_NAKED_JMP(unsigned char CNSItem::GetMaxCount(), 0x437A40);
DEFINE_NAKED_JMP(unsigned short CNSItem::GetQuestId(), 0x483780);
DEFINE_NAKED_JMP(void CNSItem::SetOwner(char *), 0x437EC0);
DEFINE_NAKED_JMP(void CNSItem::MakeRandom(int), 0x43B3B0);
DEFINE_NAKED_JMP(char * CNSItem::GetDescription(CNSPc * _COMMA char * _COMMA int), 0x43E010);
DEFINE_NAKED_JMP(int CNSItem::AddOptionString(CNSPc * _COMMA char *), 0x43CC70);
DEFINE_NAKED_JMP(int CNSItem::Use(unsigned char), 0x437B80);
DEFINE_NAKED_JMP(int CNSItem::Use(CNSPc * _COMMA unsigned char), 0x4389F0);
DEFINE_NAKED_JMP(int CNSItem::GetPremiumItemBuff(), 0x43C330);
DEFINE_NAKED_JMP(int CNSItem::IsEnablePremiumItemBuff(CNSPc *), 0x43C3E0);
DEFINE_NAKED_JMP(int CNSItem::UsePremiumItem(CNSPc *), 0x43BD10);
DEFINE_NAKED_JMP(int CNSItem::UsePremiumItem2(CNSPc *), 0x43BDD0);
DEFINE_NAKED_JMP(int CNSItem::UsePremiumItem3(CNSPc *), 0x43BEB0);
DEFINE_NAKED_JMP(int CNSItem::UseRandomItem(CNSPc *), 0x43BF60);
DEFINE_NAKED_JMP(int CNSItem::UseRandomItemTest(CNSPc * _COMMA unsigned short _COMMA unsigned long), 0x43C090);
DEFINE_NAKED_JMP(int CNSItem::AddPremiumItemBuff(CNSPc *), 0x43C4E0);
DEFINE_NAKED_JMP(int CNSItem::DeletePremiumItemBuff(CNSPc *), 0x43C750);
DEFINE_NAKED_JMP(int CNSItem::GetPremiumAbleDays(), 0x43C7E0);
DEFINE_NAKED_JMP(int CNSItem::GetPremiumAbleMinutes(), 0x43C930);
DEFINE_NAKED_JMP(int CNSItem::GetBindAbleDays(), 0x43CA70);
DEFINE_NAKED_JMP(int CNSItem::SetBindItem(unsigned short _COMMA int), 0x43CB40);
DEFINE_NAKED_JMP(int CNSItem::CalcOption(CNSCharacter *), 0x438220);
DEFINE_NAKED_JMP(int CNSItem::CalcOption2(CNSCharacter *), 0x438490);
DEFINE_NAKED_JMP(int CNSItem::CalcOption3(CNSCharacter *), 0x438720);
DEFINE_NAKED_JMP(int CNSItem::CalcNsOption(CNSPc * _COMMA int _COMMA unsigned char), 0x438870);
DEFINE_NAKED_JMP(CNSItem * CNSItem::Clone(unsigned char), 0x43B310);
DEFINE_NAKED_JMP(unsigned char CNSItem::GetUseLevel(CNSCharacter *), 0x431E10);
DEFINE_NAKED_JMP(void CNSItem::PacketItemInfo(CPacket &), 0x44C470);
//DEFINE_NAKED_JMP(CNSItem & CNSItem::operator=(const CNSItem &), 0x41A9B0);
#endif






#endif