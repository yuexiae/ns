#ifndef NSHEADER_NS_NPC_SKILL_H_
#define NSHEADER_NS_NPC_SKILL_H_


class CNSNpcSkill {
public:
    static const unsigned int _size = 0x3c;

    enum NPCSKILLTYPE {
        NpcSkillType_Null = 0x0,
        NpcSkillType_HardAttack = 0x1,
        NpcSkillType_HardAttackEx = 0x2,
        NpcSkillType_MucusPoison = 0x3,
        NpcSkillType_Shock = 0x4,
        NpcSkillType_Shout = 0x5,
        NpcSkillType_CrippleAttack = 0x6,
        NpcSkillType_WalkDamage = 0x7,
        NpcSkillType_Claw = 0x8,
        NpcSkillType_JumpAttack = 0x9,
        NpcSkillType_Missile = 0xA,
        NpcSkillType_SelfBomb = 0xB,
        NpcSkillType_StunAttack = 0xC,
        NpcSkillType_RootAttack = 0xD,
        NpcSkillType_MassSleep = 0xE,
        NpcSkillType_MassStun = 0xF,
        NpcSkillType_MassSlow = 0x10,
        NpcSkillType_PowerBlade = 0x11,
        NpcSkillType_DeadlyPoison = 0x12,
        NpcSkillType_MassDeadlyPoison = 0x13,
        NpcSkillType_MassBrokenHammer = 0x14,
        NpcSkillType_CrazyBerserker = 0x15,
        NpcSkillType_Interruption = 0x16,
        NpcSkillType_MassInterruption = 0x17,
        NpcSkillType_AbilityReduction = 0x18,
        NpcSkillType_MassAbilityReduction = 0x19,
        NpcSkillType_RootSelfBome = 0x1A,
        NpcSkillType_ReflectionField = 0x1B,
        NpcSkillType_DarkShadow = 0x1C,
        NpcSkillType_MinorHardAttack = 0x1D,
        NpcSkillType_SelfHeal = 0x1E,
        NpcSkillType_SelfHealEx = 0x1F,
        NpcSkillType_SelfHealEx2 = 0x20,
        NpcSkillType_SelfHealEx3 = 0x21,
        NpcSkillType_GroupHeal = 0x22,
        NpcSkillType_GroupHealEx = 0x23,
        NpcSkillType_FireBall = 0x24,
        NpcSkillType_FireBallEx = 0x25,
        NpcSkillType_BluntBack = 0x26,
        NpcSkillType_WindBlade = 0x27,
        NpcSkillType_Dump = 0x28,
        NpcSkillType_LowCounter = 0x29,
        NpcSkillType_MuscleBreaker = 0x2A,
        NpcSkillType_FireWall = 0x2B,
        NpcSkillType_ImpaleDoom = 0x2C,
        NpcSkillType_DoubleRush = 0x2D,
        NpcSkillType_Berserker = 0x2E,
        NpcSkillType_GroupDivineWeapon = 0x2F,
        NpcSkillType_StoneSkin = 0x30,
        NpcSkillType_Rage = 0x31,
        NpcSkillType_Chaos = 0x32,
        NpcSkillType_Bomb = 0x33,
        NpcSkillType_BigThorn = 0x34,
        NpcSkillType_IceBolt = 0x35,
        NpcSkillType_RedSwipe = 0x36,
        NpcSkillType_InterruptionAttack = 0x37,
        NpcSkillType_ImpactAttack = 0x38,
        NpcSkillType_ReflectionWave = 0x39,
        NpcSkillType_HazardStorm = 0x3A,
        NpcSkillType_AttackPower = 0x3B,
        NpcSkillType_AssaultDisease = 0x3C,
        NpcSkillType_FatalPosion = 0x3D,
        NpcSkillType_FatalStorm = 0x3E,
        NpcSkillType_RecoveryField = 0x3F,
        NpcSkillType_DeathSign = 0x40,
        NpcSkillType_MentalBreaker = 0x41,
        NpcSkillType_ProtectCure = 0x42,
        NpcSkillType_HeavyQuake = 0x43,
        NpcSkillType_Fury = 0x44,
        NpcSkillType_MortalAttack = 0x45,
        NpcSkillType_MortalBlast = 0x46,
        NpcSkillType_RootBreath = 0x47,
        NpcSkillType_GroupDivineWeaponEx = 0x48,
        NpcSkillType_BlockCurse = 0x49,
        NpcSkillType_BlockSlow = 0x4A,
        NpcSkillType_BlockRage = 0x4B,
        NpcSkillType_BlockStun = 0x4C,
        NpcSkillType_BlockSleep = 0x4D,
        NpcSkillType_BlockBomb1 = 0x4E,
        NpcSkillType_BlockBomb2 = 0x4F,
        NpcSkillType_MassDeathSign = 0x50,
        NpcSkillType_GroupHealEx2 = 0x51,
        NpcSkillType_GroupHealEx3 = 0x52,
        NpcSkillType_HardAttackEx2 = 0x53,
        NpcSkillType_DeathHealing = 0x54,
        NpcSkillType_AbsolutePower = 0x55,
        NpcSkillType_ProtectField = 0x56,
        NpcSkillType_WalkDamageEx = 0x57,
        NpcSkillType_WarCry = 0x58,
        NpcSkillType_HolyStorm = 0x59,
        NpcSkillType_GroupDivineDefenseEx = 0x5A,
        NpcSkillType_MassDeadlyPoisonEx = 0x5B,
        NpcSkillType_Taunt = 0x5C,
        NpcSkillType_SlowAttack = 0x5D,
        NpcSkillType_Pet_Heal = 0x5E,
        NpcSkillType_Pet_BluntBack = 0x5F,
        NpcSkillType_Pet_Steal = 0x60,
        NpcSkillType_Pet_TownPortal = 0x61,
        NpcSkillType_End = 0x62,
    };

    enum NPCSKILLSTATETYPE {
        NpcSkillStateType_Null = 0x0,
        NpcSkillStateType_Idle = 0x1,
        NpcSkillStateType_AttackStart = 0x2,
        NpcSkillStateType_Attack = 0x3,
        NpcSkillStateType_RangeAttack = 0x4,
        NpcSkillStateType_HealthDryUp = 0x5,
        NpcSkillStateType_Dead = 0x6,
        NpcSkillStateType_Move = 0x7,
        NpcSkillStateType_TownPortal = 0x8,
        NpcSkillStateType_End = 0x9,
    };

    CNSNpcSkill();    PATCH_MEMBER(CNSNpcSkill &, Constructor, , 0x44A1A0);
    int Init(CNSNpc *, unsigned char);    PATCH_MEMBER(int, Init, CNSNpc * _COMMA unsigned char, 0x454420);
    int IsEnable(CNSNpcSkill::NPCSKILLSTATETYPE, CNSNpcSkill::NPCSKILLTYPE);    PATCH_MEMBER(int, IsEnable, CNSNpcSkill::NPCSKILLSTATETYPE _COMMA CNSNpcSkill::NPCSKILLTYPE, 0x457AA0);
    int SkillCast(CNSNpcSkill::NPCSKILLSTATETYPE, unsigned long);    PATCH_MEMBER(int, SkillCast, CNSNpcSkill::NPCSKILLSTATETYPE _COMMA unsigned long, 0x457D90);
    int PetSkillCast(CNSNpcSkill::NPCSKILLTYPE, unsigned short, unsigned long);    PATCH_MEMBER(int, PetSkillCast, CNSNpcSkill::NPCSKILLTYPE _COMMA unsigned short _COMMA unsigned long, 0x457F30);
    int SelectSkillId(CNSNpcSkill::NPCSKILLSTATETYPE, CNSNpcSkill::NPCSKILLTYPE &);    PATCH_MEMBER(int, SelectSkillId, CNSNpcSkill::NPCSKILLSTATETYPE _COMMA CNSNpcSkill::NPCSKILLTYPE &, 0x457B00);
    void Add(CNSNpcSkill::NPCSKILLSTATETYPE, CNSNpcSkill::NPCSKILLTYPE);    PATCH_MEMBER(void, Add, CNSNpcSkill::NPCSKILLSTATETYPE _COMMA CNSNpcSkill::NPCSKILLTYPE, 0x458250);
    unsigned char GetCount(CNSNpcSkill::NPCSKILLSTATETYPE);    PATCH_MEMBER(unsigned char, GetCount, CNSNpcSkill::NPCSKILLSTATETYPE, 0x458230);
    int ConvertSkillType2SkillId(CNSNpcSkill::NPCSKILLTYPE);    PATCH_MEMBER(int, ConvertSkillType2SkillId, CNSNpcSkill::NPCSKILLTYPE, 0x457B80);
    unsigned long SearchFriend(int);    PATCH_MEMBER(unsigned long, SearchFriend, int, 0x457BD0);
    class CNSNpc * m_pParent;//this+0x0
    unsigned char m_btCount[0x9];//this+0x4
    unsigned char m_btSkillArray[9][5];//this+0xD

    /*struct _Invoke {
    PATCH_MEMBER_INVOKE(CNSNpcSkill &, CNSNpcSkill, Constructor, );
    PATCH_MEMBER_INVOKE(int, CNSNpcSkill, Init, CNSNpc * _COMMA unsigned char);
    PATCH_MEMBER_INVOKE(int, CNSNpcSkill, IsEnable, CNSNpcSkill::NPCSKILLSTATETYPE _COMMA CNSNpcSkill::NPCSKILLTYPE);
    PATCH_MEMBER_INVOKE(int, CNSNpcSkill, SkillCast, CNSNpcSkill::NPCSKILLSTATETYPE _COMMA unsigned long);
    PATCH_MEMBER_INVOKE(int, CNSNpcSkill, PetSkillCast, CNSNpcSkill::NPCSKILLTYPE _COMMA unsigned short _COMMA unsigned long);
    PATCH_MEMBER_INVOKE(int, CNSNpcSkill, SelectSkillId, CNSNpcSkill::NPCSKILLSTATETYPE _COMMA CNSNpcSkill::NPCSKILLTYPE &);
    PATCH_MEMBER_INVOKE(void, CNSNpcSkill, Add, CNSNpcSkill::NPCSKILLSTATETYPE _COMMA CNSNpcSkill::NPCSKILLTYPE);
    PATCH_MEMBER_INVOKE(unsigned char, CNSNpcSkill, GetCount, CNSNpcSkill::NPCSKILLSTATETYPE);
    PATCH_MEMBER_INVOKE(int, CNSNpcSkill, ConvertSkillType2SkillId, CNSNpcSkill::NPCSKILLTYPE);
    PATCH_MEMBER_INVOKE(unsigned long, CNSNpcSkill, SearchFriend, int);
    };*/
};
#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(CNSNpcSkill::Constructor(), 0x44A1A0);
DEFINE_NAKED_JMP(int CNSNpcSkill::Init(CNSNpc * _COMMA unsigned char), 0x454420);
DEFINE_NAKED_JMP(int CNSNpcSkill::IsEnable(CNSNpcSkill::NPCSKILLSTATETYPE _COMMA CNSNpcSkill::NPCSKILLTYPE), 0x457AA0);
DEFINE_NAKED_JMP(int CNSNpcSkill::SkillCast(CNSNpcSkill::NPCSKILLSTATETYPE _COMMA unsigned long), 0x457D90);
DEFINE_NAKED_JMP(int CNSNpcSkill::PetSkillCast(CNSNpcSkill::NPCSKILLTYPE _COMMA unsigned short _COMMA unsigned long), 0x457F30);
DEFINE_NAKED_JMP(int CNSNpcSkill::SelectSkillId(CNSNpcSkill::NPCSKILLSTATETYPE _COMMA CNSNpcSkill::NPCSKILLTYPE &), 0x457B00);
DEFINE_NAKED_JMP(void CNSNpcSkill::Add(CNSNpcSkill::NPCSKILLSTATETYPE _COMMA CNSNpcSkill::NPCSKILLTYPE), 0x458250);
DEFINE_NAKED_JMP(unsigned char CNSNpcSkill::GetCount(CNSNpcSkill::NPCSKILLSTATETYPE), 0x458230);
DEFINE_NAKED_JMP(int CNSNpcSkill::ConvertSkillType2SkillId(CNSNpcSkill::NPCSKILLTYPE), 0x457B80);
DEFINE_NAKED_JMP(unsigned long CNSNpcSkill::SearchFriend(int), 0x457BD0);
#endif



#endif