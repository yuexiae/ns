#ifndef NSHEADER_NS_BUFF_H_
#define NSHEADER_NS_BUFF_H_


class CNSBuff {
public:
    static const unsigned int _size = 0x5c;

    enum BUFFTYPE {
        BuffType_NULL = 0x0,
        BuffType_Dp = 0x1,
        BuffType_Ap = 0x2,
        BuffType_Speed = 0x3,
        BuffType_MaxHp = 0x4,
        BuffType_Rs = 0x5,
        BuffType_Ma = 0x6,
        BuffType_Ar = 0x7,
        BuffType_Glory = 0x8,
        BuffType_Berserker = 0x9,
        BuffType_Dump = 0xA,
        BuffType_Thorn = 0xB,
        BuffType_LowCounter = 0xC,
        BuffType_SaveExp = 0xD,
        BuffType_Clarity = 0xE,
        BuffType_ClarityEx = 0xF,
        BuffType_Pet = 0x10,
        BuffType_Tame = 0x11,
        BuffType_Summon = 0x12,
        BuffType_RangeBlock = 0x13,
        BuffType_FullSwine = 0x14,
        BuffType_TendMelee = 0x15,
        BuffType_TendRange = 0x16,
        BuffType_MythicBone = 0x17,
        BuffType_MythicOcean = 0x18,
        BuffType_MythicForce = 0x19,
        BuffType_HpDrain = 0x1A,
        BuffType_Ac = 0x1B,
        BuffType_WeaponStick = 0x1C,
        BuffType_Transfer = 0x1D,
        BuffType_Rider = 0x1E,
        BuffType_DwellDeity = 0x1F,
        BuffType_DwellGoat = 0x20,
        BuffType_BloodOcean = 0x21,
        BuffType_HolyDefense = 0x22,
        BuffType_ImmunDebuff = 0x23,
        BuffType_FullBarrel = 0x24,
        BuffType_Inspiration = 0x25,
        BuffType_NeedleCounter = 0x26,
        BuffType_NobleShield = 0x27,
        BuffType_DwellHero = 0x28,
        BuffType_ImmunSleep = 0x29,
        BuffType_ImmunSlow = 0x2A,
        BuffType_ImmunRoot = 0x2B,
        BuffType_ImmunRage = 0x2C,
        BuffType_ImmunPoison = 0x2D,
        BuffType_ImmunStun = 0x2E,
        BuffType_AspecVolition = 0x2F,
        BuffType_PowerStaff = 0x30,
        BuffType_MachineShield = 0x31,
        BuffType_MachineProtecter = 0x32,
        BuffType_AutoSkill = 0x33,
        BuffType_ExpUp = 0x34,
        BuffType_ExpUpParty = 0x35,
        BuffType_MiningUp = 0x36,
        BuffType_AmuletProperty = 0x37,
        BuffType_InvenExpand = 0x38,
        BuffType_WareHouseExpand = 0x39,
        BuffType_ExpUpExpand = 0x3A,
        BuffType_SiegeWeapon = 0x3B,
        BuffType_WpMa = 0x3C,
        BuffType_DpPerSkill = 0x3D,
        BuffType_DpPerPremium = 0x3E,
        BuffType_Dr = 0x3F,
        BuffType_DpBeast = 0x40,
        BuffType_ApBeast = 0x41,
        BuffType_Hidden = 0x42,
        BuffType_RsPer = 0x43,
        BuffType_NSTank = 0x44,
        BuffType_SpeedBeast = 0x45,
        BuffType_AutoMining = 0x46,
        BuffType_TpUp = 0x47,
        BuffType_Dash = 0x48,
        BuffType_CrushDivision = 0x49,
        BuffType_SummonMaster = 0x4A,
        BuffType_ProtectField = 0x4B,
        BuffType_AbsolutPower = 0x4C,
        BuffType_MaxHpExpand = 0x4D,
        BuffType_Reflection = 0x4E,
        BuffType_ExpUpShort = 0x4F,
        BuffType_ExpPenalty = 0x50,
        BuffType_RearlandKill = 0x51,
        BuffType_NoviceSheild = 0x52,
        BuffType_OverlapExpUp1 = 0x53,
        BuffType_OverlapExpUp2 = 0x54,
        BuffType_OverlapExpUp3 = 0x55,
        BuffType_OverlapExpUp4 = 0x56,
        BuffType_OverlapExpUp5 = 0x57,
        BuffType_OverlapExpUp6 = 0x58,
        BuffType_OverlapExpUp7 = 0x59,
        BuffType_OverlapExpUp8 = 0x5A,
        BuffType_OverlapExpUp9 = 0x5B,
        BuffType_OverlapExpUp10 = 0x5C,
        BuffType_PersonalSiegeWeapon = 0x5D,
        BuffType_SiegeMode = 0x5E,
        BuffType_OverlapGoldUp1 = 0x5F,
        BuffType_OverlapGoldUp2 = 0x60,
        BuffType_OverlapGoldUp3 = 0x61,
        BuffType_OverlapGoldUp4 = 0x62,
        BuffType_OverlapGoldUp5 = 0x63,
        BuffType_OverlapGoldUp6 = 0x64,
        BuffType_OverlapGoldUp7 = 0x65,
        BuffType_OverlapGoldUp8 = 0x66,
        BuffType_OverlapGoldUp9 = 0x67,
        BuffType_OverlapGoldUp10 = 0x68,
        BuffType_ImmunPoisonEx = 0x69,
        BuffType_DutyFront = 0x6A,
        BuffType_MaxStaMp = 0x6B,
        BuffType_NeoSteamShield = 0x6C,
        BuffType_NeoSteamDecrease = 0x6D,
        BuffType_DevineShield = 0x6E,
        BuffType_ImmunIncrease = 0x6F,
        BuffType_RecoveryStun = 0x70,
        BuffType_Poison = 0xC8,
        BuffType_Slow = 0xC9,
        BuffType_Rage = 0xCA,
        BuffType_Root = 0xCB,
        BuffType_Stun = 0xCC,
        BuffType_Sleep = 0xCD,
        BuffType_Chaos = 0xCE,
        BuffType_Curse = 0xCF,
        BuffType_WeaponBreak = 0xD0,
        BuffType_ArmorBreak = 0xD1,
        BuffType_Kilgician = 0xD2,
        BuffType_BoneBreak = 0xD3,
        BuffType_Tranquil = 0xD4,
        BuffType_BrainShock = 0xD5,
        BuffType_Tired = 0xD6,
        BuffType_InsertCoal = 0xD7,
        BuffType_SignTarget = 0xD8,
        BuffType_DelayAttack = 0xD9,
        BuffType_RedPowder = 0xDA,
        BuffType_WeaveIllusion = 0xDB,
        BuffType_DpBreak = 0xDC,
        BuffType_Taunt = 0xDD,
        BuffType_Battle = 0xDE,
        BuffType_LimitHpRecovery = 0xDF,
        BuffType_CurseProperty = 0xE0,
        BuffType_Fire = 0xE1,
        BuffType_DeathHealing = 0xE2,
        BuffType_Vertigo = 0xE3,
        BuffType_VitalAttack = 0xE4,
        BuffType_PSWLimit = 0xE5,
        BuffType_End = 0xE6,
    };

    enum BUFFOPTIONTYPE {
        BuffOption_NULL = 0x0,
        BuffOption_Str = 0x1,
        BuffOption_Dex = 0x2,
        BuffOption_Con = 0x3,
        BuffOption_Int = 0x4,
        BuffOption_Hp = 0x10,
        BuffOption_Mp = 0x11,
        BuffOption_Sta = 0x12,
        BuffOption_Ap = 0x13,
        BuffOption_Dp = 0x14,
        BuffOption_Ma = 0x15,
        BuffOption_Rs = 0x16,
        BuffOption_Ar = 0x17,
        BuffOption_Dr = 0x18,
        BuffOption_MoveSpeed = 0x40,
        BuffOption_AttackSpeed = 0x41,
        BuffOption_MaxHp = 0x50,
        BuffOption_DefenseDamage = 0x51,
        BuffOption_WpMa = 0x52,
        BuffOption_DpPer = 0x53,
        BuffOption_DpBeast = 0x54,
        BuffOption_ApBeast = 0x55,
        BuffOption_RsPer = 0x56,
        BuffOption_NSTank = 0x57,
        BuffOption_MaxHpExpand = 0x58,
        BuffOption_Poison = 0xA0,
        BuffOption_LowCounter = 0xA1,
        BuffOption_Thorn = 0xA2,
        BuffOption_HpDrain = 0xA3,
        BuffOption_RangeBlock = 0xA4,
        BuffOption_FullSwine = 0xA5,
        BuffOption_SaveExp = 0xA6,
        BuffOption_Tranquil = 0xA7,
        BuffOption_WeaponStick = 0xA8,
        BuffOption_ImmunDebuff = 0xA9,
        BuffOption_InsertCoal = 0xAA,
        BuffOption_BrainShock = 0xAB,
        BuffOption_SignTarget = 0xAC,
        BuffOption_FullBarrel = 0xAD,
        BuffOption_Inspiration = 0xAE,
        BuffOption_BoneBreak = 0xAF,
        BuffOption_DelayAttack = 0xB0,
        BuffOption_NeedleCounter = 0xB1,
        BuffOption_RedPowder = 0xB2,
        BuffOption_ImmunSleep = 0xB3,
        BuffOption_ImmunSlow = 0xB4,
        BuffOption_ImmunRoot = 0xB5,
        BuffOption_ImmunRage = 0xB6,
        BuffOption_ImmunPoison = 0xB7,
        BuffOption_ImmunStun = 0xB8,
        BuffOption_AspecVolition = 0xB9,
        BuffOption_WeaveIllusion = 0xBA,
        BuffOption_Taunt = 0xBB,
        BuffOption_PowerStaff = 0xBC,
        BuffOption_Kilgician = 0xBD,
        BuffOption_MachineShield = 0xBE,
        BuffOption_MachineProtecter = 0xBF,
        BuffOption_ExpUp = 0xC0,
        BuffOption_ExpUpParty = 0xC1,
        BuffOption_MiningUp = 0xC2,
        BuffOption_CurseProperty = 0xC3,
        BuffOption_AmuletProperty = 0xC4,
        BuffOption_Hidden = 0xC5,
        BuffOption_TpUp = 0xC6,
        BuffOption_DeathHealing = 0xC7,
        BuffOption_CrushDivision = 0xC8,
        BuffOption_GoldUp = 0xC9,
    };

    CNSBuff(const CNSBuff &);
    CNSBuff();    PATCH_MEMBER(CNSBuff &, Constructor, , 0x41AF90);
    virtual ~CNSBuff();    PATCH_MEMBER(void, Destructor, , 0x41AFB0);
    void OptionClear();    PATCH_MEMBER(void, OptionClear, , 0x423340);
    void OptionAdd(CNSBuff::BUFFOPTIONTYPE, unsigned char, unsigned long);    PATCH_MEMBER(void, OptionAdd, CNSBuff::BUFFOPTIONTYPE _COMMA unsigned char _COMMA unsigned long, 0x423560);
    char * GetName();    PATCH_MEMBER(char *, GetName, , 0x41AFD0);
    char * GetDescription(char *);    PATCH_MEMBER(char *, GetDescription, char *, 0x41B050);
    unsigned long GetRemainTime();    PATCH_MEMBER(unsigned long, GetRemainTime, , 0x423510);
    unsigned short GetValue();    PATCH_MEMBER(unsigned short, GetValue, , 0x426EF0);
    unsigned short GetSkillId();    PATCH_MEMBER(unsigned short, GetSkillId, , 0x426F10);
    unsigned char GetLevel();    PATCH_MEMBER(unsigned char, GetLevel, , 0x426F30);
    void SetValue(unsigned short);    PATCH_MEMBER(void, SetValue, unsigned short, 0x4D7450);
    int IsDebuff();    PATCH_MEMBER(int, IsDebuff, , 0x423440);
    static int IsDebuff(CNSBuff::BUFFTYPE);    PATCH_STATIC(int, IsDebuff, CNSBuff::BUFFTYPE, 0x41C3D0);
    int IsBuff();    PATCH_MEMBER(int, IsBuff, , 0x4234A0);
    static int CalcImmunRate(unsigned char);    PATCH_STATIC(int, CalcImmunRate, unsigned char, 0x4D7390);
    enum CNSBuff::BUFFTYPE m_buffType;//this+0x4
    unsigned short m_wSkillId;//this+0x8
    unsigned char m_btLevel;//this+0xA
    unsigned short m_wValue;//this+0xC
    unsigned short m_wDurationTime;//this+0xE
    unsigned long m_dwStartTime;//this+0x10
    unsigned long m_dwLastActiveTime;//this+0x14
    unsigned long m_dwCasterObjectId;//this+0x18
    struct BuffOption {
        static const unsigned int _size = 0xc;
        enum CNSBuff::BUFFOPTIONTYPE buffOption;//this+0x0
        unsigned char btSign;//this+0x4
        unsigned long dwValue;//this+0x8
    };

    struct CNSBuff::BuffOption m_BuffOptionArray[0x5];//this+0x1C
    unsigned long m_dwBuffOptionCount;//this+0x58
    CNSBuff & operator=(const CNSBuff &);    //PATCH_MEMBER(CNSBuff &, operator=, const CNSBuff &, 0x4235E0);
    //void __local_vftable_ctor_closure();
    //virtual void * __vecDelDtor(unsigned int);

    /*struct _Invoke {
    PATCH_MEMBER_INVOKE(CNSBuff &, CNSBuff, Constructor, );
    PATCH_MEMBER_INVOKE(void, CNSBuff, Destructor, );
    PATCH_MEMBER_INVOKE(void, CNSBuff, OptionClear, );
    PATCH_MEMBER_INVOKE(void, CNSBuff, OptionAdd, CNSBuff::BUFFOPTIONTYPE _COMMA unsigned char _COMMA unsigned long);
    PATCH_MEMBER_INVOKE(char *, CNSBuff, GetName, );
    PATCH_MEMBER_INVOKE(char *, CNSBuff, GetDescription, char *);
    PATCH_MEMBER_INVOKE(unsigned long, CNSBuff, GetRemainTime, );
    PATCH_MEMBER_INVOKE(unsigned short, CNSBuff, GetValue, );
    PATCH_MEMBER_INVOKE(unsigned short, CNSBuff, GetSkillId, );
    PATCH_MEMBER_INVOKE(unsigned char, CNSBuff, GetLevel, );
    PATCH_MEMBER_INVOKE(void, CNSBuff, SetValue, unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSBuff, IsDebuff, );
    PATCH_STATIC_INVOKE(int, IsDebuff, CNSBuff::BUFFTYPE);
    PATCH_MEMBER_INVOKE(int, CNSBuff, IsBuff, );
    PATCH_STATIC_INVOKE(int, CalcImmunRate, unsigned char);
    //PATCH_MEMBER_INVOKE(CNSBuff &, CNSBuff, operator=, const CNSBuff &);
    };*/
};
#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(CNSBuff::Constructor(), 0x41AF90);
//DEFINE_NAKED_JMP(CNSBuff::Destructor(), 0x41AFB0);
DEFINE_NAKED_JMP(void CNSBuff::OptionClear(), 0x423340);
DEFINE_NAKED_JMP(void CNSBuff::OptionAdd(CNSBuff::BUFFOPTIONTYPE _COMMA unsigned char _COMMA unsigned long), 0x423560);
DEFINE_NAKED_JMP(char * CNSBuff::GetName(), 0x41AFD0);
DEFINE_NAKED_JMP(char * CNSBuff::GetDescription(char *), 0x41B050);
DEFINE_NAKED_JMP(unsigned long CNSBuff::GetRemainTime(), 0x423510);
DEFINE_NAKED_JMP(unsigned short CNSBuff::GetValue(), 0x426EF0);
DEFINE_NAKED_JMP(unsigned short CNSBuff::GetSkillId(), 0x426F10);
DEFINE_NAKED_JMP(unsigned char CNSBuff::GetLevel(), 0x426F30);
DEFINE_NAKED_JMP(void CNSBuff::SetValue(unsigned short), 0x4D7450);
DEFINE_NAKED_JMP(int CNSBuff::IsDebuff(), 0x423440);
DEFINE_NAKED_JMP(int CNSBuff::IsDebuff(CNSBuff::BUFFTYPE), 0x41C3D0);
DEFINE_NAKED_JMP(int CNSBuff::IsBuff(), 0x4234A0);
DEFINE_NAKED_JMP(int CNSBuff::CalcImmunRate(unsigned char), 0x4D7390);
//DEFINE_NAKED_JMP(CNSBuff & CNSBuff::operator=(const CNSBuff &), 0x4235E0);
#endif



class CNSBuffList {
public:
    static const unsigned int _size = 0xad4;

    CNSBuffList(const CNSBuffList &);
    CNSBuffList();    PATCH_MEMBER(CNSBuffList &, Constructor, , 0x41C3F0);
    virtual ~CNSBuffList();    PATCH_MEMBER(void, Destructor, , 0x41C480);
    void Clear();    PATCH_MEMBER(void, Clear, , 0x41C4B0);
    void ClearDebuff();    PATCH_MEMBER(void, ClearDebuff, , 0x41C4F0);
    int ClearBuff(int);    PATCH_MEMBER(int, ClearBuff, int, 0x41C630);
    int ClearDebuffLast();    PATCH_MEMBER(int, ClearDebuffLast, , 0x41C580);
    int ClearBuffLast();    PATCH_MEMBER(int, ClearBuffLast, , 0x4D73F0);
    unsigned long GetBuffCount();    PATCH_MEMBER(unsigned long, GetBuffCount, , 0x423280);
    unsigned long GetDebuffCount();    PATCH_MEMBER(unsigned long, GetDebuffCount, , 0x4232E0);
    int IsEnable(CNSBuff::BUFFTYPE);    PATCH_MEMBER(int, IsEnable, CNSBuff::BUFFTYPE, 0x4237F0);
    int IsEnableAttr(CNSBuff::BUFFTYPE);    PATCH_MEMBER(int, IsEnableAttr, CNSBuff::BUFFTYPE, 0x484AF0);
    unsigned short GetBuffValue(CNSBuff::BUFFTYPE);    PATCH_MEMBER(unsigned short, GetBuffValue, CNSBuff::BUFFTYPE, 0x41C960);
    int Find(CNSBuff::BUFFTYPE, unsigned short);    PATCH_MEMBER(int, Find, CNSBuff::BUFFTYPE _COMMA unsigned short, 0x41C800);
    int Find(CNSBuff::BUFFTYPE);    PATCH_MEMBER(int, Find, CNSBuff::BUFFTYPE, 0x41C7B0);
    int FindAttr(CNSBuff::BUFFTYPE);    PATCH_MEMBER(int, FindAttr, CNSBuff::BUFFTYPE, 0x41C890);
    unsigned short FindSkillId(unsigned short, unsigned short);    PATCH_MEMBER(unsigned short, FindSkillId, unsigned short _COMMA unsigned short, 0x41C8F0);
    CNSBuff * GetBuff(unsigned char);    PATCH_MEMBER(CNSBuff *, GetBuff, unsigned char, 0x4C82A0);
    CNSBuff * GetBuff(CNSBuff::BUFFTYPE);    PATCH_MEMBER(CNSBuff *, GetBuff, CNSBuff::BUFFTYPE, 0x4234D0);
    CNSBuff * Add(unsigned long, CNSBuff::BUFFTYPE, unsigned short, unsigned char, unsigned short, unsigned short, unsigned long, int);    PATCH_MEMBER(CNSBuff *, Add, unsigned long _COMMA CNSBuff::BUFFTYPE _COMMA unsigned short _COMMA unsigned char _COMMA unsigned short _COMMA unsigned short _COMMA unsigned long _COMMA int, 0x41CB80);
    int Delete(CNSBuff::BUFFTYPE);    PATCH_MEMBER(int, Delete, CNSBuff::BUFFTYPE, 0x41CFE0);
    int DeleteAttr(CNSBuff::BUFFTYPE);    PATCH_MEMBER(int, DeleteAttr, CNSBuff::BUFFTYPE, 0x41D030);
    void CalcBuff(CNSCharacter *);    PATCH_MEMBER(void, CalcBuff, CNSCharacter *, 0x41D080);
    void CalcBuff2(CNSCharacter *);    PATCH_MEMBER(void, CalcBuff2, CNSCharacter *, 0x41E4F0);
    void CalcPSWBuff(CNSCharacter *);    PATCH_MEMBER(void, CalcPSWBuff, CNSCharacter *, 0x421600);
    void CalcPSWBuff2(CNSCharacter *);    PATCH_MEMBER(void, CalcPSWBuff2, CNSCharacter *, 0x421740);
    int GetBuffArray(unsigned char *, unsigned short *, unsigned short *);    PATCH_MEMBER(int, GetBuffArray, unsigned char * _COMMA unsigned short * _COMMA unsigned short *, 0x421840);
    unsigned char GetBuffLevel(CNSBuff::BUFFTYPE);    PATCH_MEMBER(unsigned char, GetBuffLevel, CNSBuff::BUFFTYPE, 0x426F50);
    unsigned short GetBuffSkillId(CNSBuff::BUFFTYPE);    PATCH_MEMBER(unsigned short, GetBuffSkillId, CNSBuff::BUFFTYPE, 0x43ED10);
    void OnTick(CNSCharacter *, unsigned long);    PATCH_MEMBER(void, OnTick, CNSCharacter * _COMMA unsigned long, 0x4219E0);
    int HitLowCounter(CNSCharacter *, CNSCharacter *);    PATCH_MEMBER(int, HitLowCounter, CNSCharacter * _COMMA CNSCharacter *, 0x422430);
    int HitNeedleCounter(CNSCharacter *, CNSCharacter *);    PATCH_MEMBER(int, HitNeedleCounter, CNSCharacter * _COMMA CNSCharacter *, 0x422740);
    int HitPoison(CNSCharacter *, CNSCharacter *);    PATCH_MEMBER(int, HitPoison, CNSCharacter * _COMMA CNSCharacter *, 0x421F50);
    int HitDOT(CNSCharacter *, CNSCharacter *, CNSBuff::BUFFTYPE);    PATCH_MEMBER(int, HitDOT, CNSCharacter * _COMMA CNSCharacter * _COMMA CNSBuff::BUFFTYPE, 0x422320);
    int HitThorn(CNSCharacter *, CNSCharacter *);    PATCH_MEMBER(int, HitThorn, CNSCharacter * _COMMA CNSCharacter *, 0x4225E0);
    int HitHpDrain(CNSCharacter *, CNSCharacter *);    PATCH_MEMBER(int, HitHpDrain, CNSCharacter * _COMMA CNSCharacter *, 0x422A20);
    int HitStun(CNSCharacter *, CNSCharacter *);    PATCH_MEMBER(int, HitStun, CNSCharacter * _COMMA CNSCharacter *, 0x4228F0);
    int HitRedPowder(CNSCharacter *, CNSCharacter *);    PATCH_MEMBER(int, HitRedPowder, CNSCharacter * _COMMA CNSCharacter *, 0x422B20);
    int HitCurseProperty(CNSCharacter *, CNSCharacter *, unsigned short);    PATCH_MEMBER(int, HitCurseProperty, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short, 0x422E00);
    int HitDeathHealing(CNSCharacter *, unsigned short);    PATCH_MEMBER(int, HitDeathHealing, CNSCharacter * _COMMA unsigned short, 0x422180);
    int HitReflection(CNSCharacter *, CNSCharacter *, unsigned short);    PATCH_MEMBER(int, HitReflection, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short, 0x422F40);
    unsigned short CalcRangeBlock(unsigned short);    PATCH_MEMBER(unsigned short, CalcRangeBlock, unsigned short, 0x422FA0);
    unsigned short CalcFullSwine(unsigned short);    PATCH_MEMBER(unsigned short, CalcFullSwine, unsigned short, 0x423060);
    unsigned long CalcSaveExp(CNSPc *, unsigned long);    PATCH_MEMBER(unsigned long, CalcSaveExp, CNSPc * _COMMA unsigned long, 0x423140);
    int OnTranquil(CNSCharacter *);    PATCH_MEMBER(int, OnTranquil, CNSCharacter *, 0x423230);
    void ResistStart(CNSBuff::BUFFTYPE);    PATCH_MEMBER(void, ResistStart, CNSBuff::BUFFTYPE, 0x41CA20);
    int ResistEnd(int &);    PATCH_MEMBER(int, ResistEnd, int &, 0x41CA40);
    static int CheckImmunDebuff(unsigned short, CNSBuff::BUFFTYPE);    PATCH_STATIC(int, CheckImmunDebuff, unsigned short _COMMA CNSBuff::BUFFTYPE, 0x423820);
    unsigned long m_dwCount;//this+0x4
    class CNSBuff m_buffList[0x1E];//this+0x8
    enum CNSBuff::BUFFTYPE m_resistBuff;//this+0xAD0
    CNSBuffList & operator=(const CNSBuffList &);
    //void __local_vftable_ctor_closure();
    //virtual void * __vecDelDtor(unsigned int);

    /*struct _Invoke {
    PATCH_MEMBER_INVOKE(CNSBuffList &, CNSBuffList, Constructor, );
    PATCH_MEMBER_INVOKE(void, CNSBuffList, Destructor, );
    PATCH_MEMBER_INVOKE(void, CNSBuffList, Clear, );
    PATCH_MEMBER_INVOKE(void, CNSBuffList, ClearDebuff, );
    PATCH_MEMBER_INVOKE(int, CNSBuffList, ClearBuff, int);
    PATCH_MEMBER_INVOKE(int, CNSBuffList, ClearDebuffLast, );
    PATCH_MEMBER_INVOKE(int, CNSBuffList, ClearBuffLast, );
    PATCH_MEMBER_INVOKE(unsigned long, CNSBuffList, GetBuffCount, );
    PATCH_MEMBER_INVOKE(unsigned long, CNSBuffList, GetDebuffCount, );
    PATCH_MEMBER_INVOKE(int, CNSBuffList, IsEnable, CNSBuff::BUFFTYPE);
    PATCH_MEMBER_INVOKE(int, CNSBuffList, IsEnableAttr, CNSBuff::BUFFTYPE);
    PATCH_MEMBER_INVOKE(unsigned short, CNSBuffList, GetBuffValue, CNSBuff::BUFFTYPE);
    PATCH_MEMBER_INVOKE(int, CNSBuffList, Find, CNSBuff::BUFFTYPE _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSBuffList, Find, CNSBuff::BUFFTYPE);
    PATCH_MEMBER_INVOKE(int, CNSBuffList, FindAttr, CNSBuff::BUFFTYPE);
    PATCH_MEMBER_INVOKE(unsigned short, CNSBuffList, FindSkillId, unsigned short _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(CNSBuff *, CNSBuffList, GetBuff, unsigned char);
    PATCH_MEMBER_INVOKE(CNSBuff *, CNSBuffList, GetBuff, CNSBuff::BUFFTYPE);
    PATCH_MEMBER_INVOKE(CNSBuff *, CNSBuffList, Add, unsigned long _COMMA CNSBuff::BUFFTYPE _COMMA unsigned short _COMMA unsigned char _COMMA unsigned short _COMMA unsigned short _COMMA unsigned long _COMMA int);
    PATCH_MEMBER_INVOKE(int, CNSBuffList, Delete, CNSBuff::BUFFTYPE);
    PATCH_MEMBER_INVOKE(int, CNSBuffList, DeleteAttr, CNSBuff::BUFFTYPE);
    PATCH_MEMBER_INVOKE(void, CNSBuffList, CalcBuff, CNSCharacter *);
    PATCH_MEMBER_INVOKE(void, CNSBuffList, CalcBuff2, CNSCharacter *);
    PATCH_MEMBER_INVOKE(void, CNSBuffList, CalcPSWBuff, CNSCharacter *);
    PATCH_MEMBER_INVOKE(void, CNSBuffList, CalcPSWBuff2, CNSCharacter *);
    PATCH_MEMBER_INVOKE(int, CNSBuffList, GetBuffArray, unsigned char * _COMMA unsigned short * _COMMA unsigned short *);
    PATCH_MEMBER_INVOKE(unsigned char, CNSBuffList, GetBuffLevel, CNSBuff::BUFFTYPE);
    PATCH_MEMBER_INVOKE(unsigned short, CNSBuffList, GetBuffSkillId, CNSBuff::BUFFTYPE);
    PATCH_MEMBER_INVOKE(void, CNSBuffList, OnTick, CNSCharacter * _COMMA unsigned long);
    PATCH_MEMBER_INVOKE(int, CNSBuffList, HitLowCounter, CNSCharacter * _COMMA CNSCharacter *);
    PATCH_MEMBER_INVOKE(int, CNSBuffList, HitNeedleCounter, CNSCharacter * _COMMA CNSCharacter *);
    PATCH_MEMBER_INVOKE(int, CNSBuffList, HitPoison, CNSCharacter * _COMMA CNSCharacter *);
    PATCH_MEMBER_INVOKE(int, CNSBuffList, HitDOT, CNSCharacter * _COMMA CNSCharacter * _COMMA CNSBuff::BUFFTYPE);
    PATCH_MEMBER_INVOKE(int, CNSBuffList, HitThorn, CNSCharacter * _COMMA CNSCharacter *);
    PATCH_MEMBER_INVOKE(int, CNSBuffList, HitHpDrain, CNSCharacter * _COMMA CNSCharacter *);
    PATCH_MEMBER_INVOKE(int, CNSBuffList, HitStun, CNSCharacter * _COMMA CNSCharacter *);
    PATCH_MEMBER_INVOKE(int, CNSBuffList, HitRedPowder, CNSCharacter * _COMMA CNSCharacter *);
    PATCH_MEMBER_INVOKE(int, CNSBuffList, HitCurseProperty, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSBuffList, HitDeathHealing, CNSCharacter * _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSBuffList, HitReflection, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(unsigned short, CNSBuffList, CalcRangeBlock, unsigned short);
    PATCH_MEMBER_INVOKE(unsigned short, CNSBuffList, CalcFullSwine, unsigned short);
    PATCH_MEMBER_INVOKE(unsigned long, CNSBuffList, CalcSaveExp, CNSPc * _COMMA unsigned long);
    PATCH_MEMBER_INVOKE(int, CNSBuffList, OnTranquil, CNSCharacter *);
    PATCH_MEMBER_INVOKE(void, CNSBuffList, ResistStart, CNSBuff::BUFFTYPE);
    PATCH_MEMBER_INVOKE(int, CNSBuffList, ResistEnd, int &);
    PATCH_STATIC_INVOKE(int, CheckImmunDebuff, unsigned short _COMMA CNSBuff::BUFFTYPE);
    };*/
};
#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(CNSBuffList::Constructor(), 0x41C3F0);
//DEFINE_NAKED_JMP(CNSBuffList::Destructor(), 0x41C480);
DEFINE_NAKED_JMP(void CNSBuffList::Clear(), 0x41C4B0);
DEFINE_NAKED_JMP(void CNSBuffList::ClearDebuff(), 0x41C4F0);
DEFINE_NAKED_JMP(int CNSBuffList::ClearBuff(int), 0x41C630);
DEFINE_NAKED_JMP(int CNSBuffList::ClearDebuffLast(), 0x41C580);
DEFINE_NAKED_JMP(int CNSBuffList::ClearBuffLast(), 0x4D73F0);
DEFINE_NAKED_JMP(unsigned long CNSBuffList::GetBuffCount(), 0x423280);
DEFINE_NAKED_JMP(unsigned long CNSBuffList::GetDebuffCount(), 0x4232E0);
DEFINE_NAKED_JMP(int CNSBuffList::IsEnable(CNSBuff::BUFFTYPE), 0x4237F0);
DEFINE_NAKED_JMP(int CNSBuffList::IsEnableAttr(CNSBuff::BUFFTYPE), 0x484AF0);
DEFINE_NAKED_JMP(unsigned short CNSBuffList::GetBuffValue(CNSBuff::BUFFTYPE), 0x41C960);
DEFINE_NAKED_JMP(int CNSBuffList::Find(CNSBuff::BUFFTYPE _COMMA unsigned short), 0x41C800);
DEFINE_NAKED_JMP(int CNSBuffList::Find(CNSBuff::BUFFTYPE), 0x41C7B0);
DEFINE_NAKED_JMP(int CNSBuffList::FindAttr(CNSBuff::BUFFTYPE), 0x41C890);
DEFINE_NAKED_JMP(unsigned short CNSBuffList::FindSkillId(unsigned short _COMMA unsigned short), 0x41C8F0);
DEFINE_NAKED_JMP(CNSBuff * CNSBuffList::GetBuff(unsigned char), 0x4C82A0);
DEFINE_NAKED_JMP(CNSBuff * CNSBuffList::GetBuff(CNSBuff::BUFFTYPE), 0x4234D0);
DEFINE_NAKED_JMP(CNSBuff * CNSBuffList::Add(unsigned long _COMMA CNSBuff::BUFFTYPE _COMMA unsigned short _COMMA unsigned char _COMMA unsigned short _COMMA unsigned short _COMMA unsigned long _COMMA int), 0x41CB80);
DEFINE_NAKED_JMP(int CNSBuffList::Delete(CNSBuff::BUFFTYPE), 0x41CFE0);
DEFINE_NAKED_JMP(int CNSBuffList::DeleteAttr(CNSBuff::BUFFTYPE), 0x41D030);
DEFINE_NAKED_JMP(void CNSBuffList::CalcBuff(CNSCharacter *), 0x41D080);
DEFINE_NAKED_JMP(void CNSBuffList::CalcBuff2(CNSCharacter *), 0x41E4F0);
DEFINE_NAKED_JMP(void CNSBuffList::CalcPSWBuff(CNSCharacter *), 0x421600);
DEFINE_NAKED_JMP(void CNSBuffList::CalcPSWBuff2(CNSCharacter *), 0x421740);
DEFINE_NAKED_JMP(int CNSBuffList::GetBuffArray(unsigned char * _COMMA unsigned short * _COMMA unsigned short *), 0x421840);
DEFINE_NAKED_JMP(unsigned char CNSBuffList::GetBuffLevel(CNSBuff::BUFFTYPE), 0x426F50);
DEFINE_NAKED_JMP(unsigned short CNSBuffList::GetBuffSkillId(CNSBuff::BUFFTYPE), 0x43ED10);
DEFINE_NAKED_JMP(void CNSBuffList::OnTick(CNSCharacter * _COMMA unsigned long), 0x4219E0);
DEFINE_NAKED_JMP(int CNSBuffList::HitLowCounter(CNSCharacter * _COMMA CNSCharacter *), 0x422430);
DEFINE_NAKED_JMP(int CNSBuffList::HitNeedleCounter(CNSCharacter * _COMMA CNSCharacter *), 0x422740);
DEFINE_NAKED_JMP(int CNSBuffList::HitPoison(CNSCharacter * _COMMA CNSCharacter *), 0x421F50);
DEFINE_NAKED_JMP(int CNSBuffList::HitDOT(CNSCharacter * _COMMA CNSCharacter * _COMMA CNSBuff::BUFFTYPE), 0x422320);
DEFINE_NAKED_JMP(int CNSBuffList::HitThorn(CNSCharacter * _COMMA CNSCharacter *), 0x4225E0);
DEFINE_NAKED_JMP(int CNSBuffList::HitHpDrain(CNSCharacter * _COMMA CNSCharacter *), 0x422A20);
DEFINE_NAKED_JMP(int CNSBuffList::HitStun(CNSCharacter * _COMMA CNSCharacter *), 0x4228F0);
DEFINE_NAKED_JMP(int CNSBuffList::HitRedPowder(CNSCharacter * _COMMA CNSCharacter *), 0x422B20);
DEFINE_NAKED_JMP(int CNSBuffList::HitCurseProperty(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short), 0x422E00);
DEFINE_NAKED_JMP(int CNSBuffList::HitDeathHealing(CNSCharacter * _COMMA unsigned short), 0x422180);
DEFINE_NAKED_JMP(int CNSBuffList::HitReflection(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short), 0x422F40);
DEFINE_NAKED_JMP(unsigned short CNSBuffList::CalcRangeBlock(unsigned short), 0x422FA0);
DEFINE_NAKED_JMP(unsigned short CNSBuffList::CalcFullSwine(unsigned short), 0x423060);
DEFINE_NAKED_JMP(unsigned long CNSBuffList::CalcSaveExp(CNSPc * _COMMA unsigned long), 0x423140);
DEFINE_NAKED_JMP(int CNSBuffList::OnTranquil(CNSCharacter *), 0x423230);
DEFINE_NAKED_JMP(void CNSBuffList::ResistStart(CNSBuff::BUFFTYPE), 0x41CA20);
DEFINE_NAKED_JMP(int CNSBuffList::ResistEnd(int &), 0x41CA40);
DEFINE_NAKED_JMP(int CNSBuffList::CheckImmunDebuff(unsigned short _COMMA CNSBuff::BUFFTYPE), 0x423820);
#endif




#endif