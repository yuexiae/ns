#ifndef NSHAEDER_NS_SKILL_H_
#define NSHAEDER_NS_SKILL_H_



#include <vector>
#include "ns_equipment.h"

class CNSCharacter;
class CNSPc;


class CNSSkill {
public:
    static const unsigned int _size = 0x64;


    enum SKILLTYPE {
        SkillType_NULL =  0x0,
        SkillType_Dummy =  0x1,
        SkillType_Passive =  0x2,
        SkillType_NormalAttack =  0x3,
        SkillType_SpecialAttack =  0x4,
        SkillType_MagicAttack =  0x5,
        SkillType_MagicAttack2 =  0x6,
        SkillType_MagicAttack3 =  0x7,
        SkillType_Heal =  0x8,
        SkillType_HealEx =  0x9,
        SkillType_Cure =  0xA,
        SkillType_Rebirth =  0xB,
        SkillType_Buff =  0xC,
        SkillType_Debuff =  0xD,
        SkillType_NSNormalAttack =  0xE,
        SkillType_NSSpecialAttack =  0xF,
        SkillType_Taming =  0x10,
        SkillType_Summoning =  0x11,
        SkillType_Teleport =  0x12,
        SkillType_Gel =  0x13,
        SkillType_BowAttack =  0x14,
        SkillType_Spawn =  0x15,
        SkillType_Resolution =  0x16,
        SkillType_Production =  0x17,
        SkillType_MobControl =  0x18,
        SkillType_PetControl =  0x19,
        SkillType_Steal =  0x1A,
        SkillType_Suicide =  0x1B,
        SkillType_Detection =  0x1C,
        SkillType_Amulet =  0x1D,
        SkillType_Bomb =  0x1E,
        SkillType_MinorNormalAttack =  0x1F,
        SkillType_NpcSpecialAttack =  0x20,
        SkillType_NormalAttackEx =  0x21,
        SkillType_DebuffAttack =  0x22,
        SkillType_SpeedyHand =  0x23,
        SkillType_KnockBack =  0x24,
        SkillType_DirectAttack =  0x25,
        SkillType_PSWControl =  0x26,
        SkillType_HitHeal =  0x27,
        SkillType_End =  0x28,
    };

    enum RANGETYPE {
        RangeType_Weapon =  0x0,
        RangeType_Skill =  0x1,
        RangeType_Self =  0x2,
        RangeType_Party =  0x3,
        RangeType_Group =  0x4,
        RangeType_Range =  0x5,
        RangeType_Random =  0x6,
    };

    enum TARGETTYPE {
        TargetType_Passive =  0x0,
        TargetType_Self =  0x1,
        TargetType_Buff =  0x2,
        TargetType_Attack =  0x3,
        TargetType_Party =  0x4,
    };

    CNSSkill(const CNSSkill &);
    CNSSkill(); CNSSkill& Constructor();    PATCH_MEMBER(CNSSkill &, Constructor, , 0x4C9550);
    virtual ~CNSSkill();    PATCH_MEMBER(void, Destructor, , 0x4C95E0);
    void Clear();    PATCH_MEMBER(void, Clear, , 0x4C9690);
    int IsSteamAbility();    PATCH_MEMBER(int, IsSteamAbility, , 0x483840);
    int IsPassive();    PATCH_MEMBER(int, IsPassive, , 0x4D6D60);
    int IsMythic();    PATCH_MEMBER(int, IsMythic, , 0x4D6D80);
    int IsRaceAbility();    PATCH_MEMBER(int, IsRaceAbility, , 0x4D6DA0);
    int IsRebirth();    PATCH_MEMBER(int, IsRebirth, , 0x4D6FF0);
    int IsAttrib();    PATCH_MEMBER(int, IsAttrib, , 0x4D6F70);
    int IsMastery();    PATCH_MEMBER(int, IsMastery, , 0x4D6F90);
    int IsSpecialActive();    PATCH_MEMBER(int, IsSpecialActive, , 0x4D6FB0);
    int IsHelper();    PATCH_MEMBER(int, IsHelper, , 0x4D7040);
    int IsPSWSkill();    PATCH_MEMBER(int, IsPSWSkill, , 0x4D72C0);
    unsigned short GetSkillId();    PATCH_MEMBER(unsigned short, GetSkillId, , 0x45A920);
    char * GetSkillName();    PATCH_MEMBER(char *, GetSkillName, , 0x406500);
    unsigned char GetSkillLevel();    PATCH_MEMBER(unsigned char, GetSkillLevel, , 0x482A20);
    char * GetDescription(CNSPc *, char *);    PATCH_MEMBER(char *, GetDescription, CNSPc * _COMMA char *, 0x4C9840);
    unsigned short GetExp();    PATCH_MEMBER(unsigned short, GetExp, , 0x4C81D0);
    unsigned short GetNextExp();    PATCH_MEMBER(unsigned short, GetNextExp, , 0x4C81F0);
    unsigned char GetRangeType();    PATCH_MEMBER(unsigned char, GetRangeType, , 0x44C3B0);
    unsigned short GetRange(CNSCharacter *);    PATCH_MEMBER(unsigned short, GetRange, CNSCharacter *, 0x4CCB40);
    unsigned short GetDurationTime(unsigned char);    PATCH_MEMBER(unsigned short, GetDurationTime, unsigned char, 0x43EC50);
    int CheckTarget(CNSCharacter *, CNSCharacter *);    PATCH_MEMBER(int, CheckTarget, CNSCharacter * _COMMA CNSCharacter *, 0x4CC700);
    int CheckSkill(CNSCharacter *, unsigned long);    PATCH_MEMBER(int, CheckSkill, CNSCharacter * _COMMA unsigned long, 0x4C9F90);
    int Cast(CNSCharacter *, unsigned long);    PATCH_MEMBER(int, Cast, CNSCharacter * _COMMA unsigned long, 0x4CA400);
    int Use(CNSCharacter *, CNSCharacter *, unsigned long);    PATCH_MEMBER(int, Use, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned long, 0x4CA420);
    static unsigned short Attack(CNSCharacter *, CNSCharacter *, unsigned short, CNSObject::HITTYPE, int);    PATCH_STATIC(unsigned short, Attack, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA CNSObject::HITTYPE _COMMA int, 0x4CCD10);
    static CNSSkill::TARGETTYPE GetTargetType(CNSSkill *);    PATCH_STATIC(CNSSkill::TARGETTYPE, GetTargetType, CNSSkill *, 0x4D74D0);
    void AddSkillExpPoint(CNSPc *, unsigned short);    PATCH_MEMBER(void, AddSkillExpPoint, CNSPc * _COMMA unsigned short, 0x4CC4A0);
    int CheckSuccessRate4(unsigned char, unsigned char);    PATCH_MEMBER(int, CheckSuccessRate4, unsigned char _COMMA unsigned char, 0x4D70E0);
    static int CheckSuccessRate4(unsigned char, unsigned char, unsigned char);    PATCH_STATIC(int, CheckSuccessRate4, unsigned char _COMMA unsigned char _COMMA unsigned char, 0x423B80);
    void SetTempValue(int, unsigned long);    PATCH_MEMBER(void, SetTempValue, int _COMMA unsigned long, 0x43EC30);
    static int CheckPSWLimit(CNSPc *, unsigned long);    PATCH_STATIC(int, CheckPSWLimit, CNSPc * _COMMA unsigned long, 0x4D0DF0);
    int m_bUsed;//this+0x4
    int m_nSkillSeq;//this+0x8
    int m_nDbSeq;//this+0xC
    unsigned short m_wSkillId;//this+0x10
    char * m_szSkillName;//this+0x14
    unsigned char m_btSkillLevel;//this+0x18
    unsigned short m_wSkillExp;//this+0x1A
    unsigned short m_wSkillNextExp;//this+0x1C
    unsigned char m_btSkillLevelDb;//this+0x1E
    unsigned short m_wSkillExpDb;//this+0x20
    unsigned char m_btUseSkillPoint;//this+0x22
    unsigned char m_btUseSkillPoint2;//this+0x23
    unsigned char m_btUseKind;//this+0x24
    unsigned short m_wUsePoint;//this+0x26
    unsigned char m_btLimitJob;//this+0x28
    unsigned char m_btLimitLevel;//this+0x29
    unsigned char m_btSkillType[0x2];//this+0x2A
    unsigned char m_btSkillOption[0x2];//this+0x2C
    unsigned short m_wSkillValue[0x2];//this+0x2E
    unsigned char m_btRangeType;//this+0x32
    unsigned short m_wRangeValue;//this+0x34
    unsigned char m_btMaxTarget;//this+0x36
    unsigned char m_btCastTime;//this+0x37
    unsigned short m_wCoolTime;//this+0x38
    unsigned char m_btAttackSpeed;//this+0x3A
    unsigned short m_wDurationTimeSeed;//this+0x3C
    unsigned short m_wDurationTime;//this+0x3E
    unsigned long m_dwTempValue[0x4];//this+0x40
    unsigned long m_dwTotalHitDamage;//this+0x50
    unsigned char m_btTargetType;//this+0x54
    enum CNSEquipment::EQUIPMENTTYPE m_EquipmentType;//this+0x58
    unsigned long m_dwLastUseTime;//this+0x5C
    char * m_szComment;//this+0x60
    void SendSkillUseMessage(CNSCharacter *, CNSCharacter *, unsigned char, unsigned short);    PATCH_MEMBER(void, SendSkillUseMessage, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned char _COMMA unsigned short, 0x4CCCC0);
    unsigned short GetUsePoint(CNSCharacter *);    PATCH_MEMBER(unsigned short, GetUsePoint, CNSCharacter *, 0x4C96B0);
    unsigned char GetLimitSkillLevel(CNSPc *, int);    PATCH_MEMBER(unsigned char, GetLimitSkillLevel, CNSPc * _COMMA int, 0x4CC190);
    unsigned char GetLimitPcLevel(CNSPc *);    PATCH_MEMBER(unsigned char, GetLimitPcLevel, CNSPc *, 0x4CC3F0);
    unsigned long GetUseSkillExpPoint(unsigned char);    PATCH_MEMBER(unsigned long, GetUseSkillExpPoint, unsigned char, 0x4D6DC0);
    unsigned long GetUseSkillExpPointAll();    PATCH_MEMBER(unsigned long, GetUseSkillExpPointAll, , 0x4C9F30);
    CNSObject * SearchObject(int, unsigned char, unsigned short, std::vector<CNSObject *,std::allocator<CNSObject *> > &, CNSCharacter *, CNSCharacter *);    PATCH_MEMBER(CNSObject *, SearchObject, int _COMMA unsigned char _COMMA unsigned short _COMMA std::vector<CNSObject * _COMMA std::allocator<CNSObject *> > & _COMMA CNSCharacter * _COMMA CNSCharacter *, 0x4CCBE0);
    void SearchObjectFinish(std::vector<CNSObject *,std::allocator<CNSObject *> > &);    PATCH_MEMBER(void, SearchObjectFinish, std::vector<CNSObject * _COMMA std::allocator<CNSObject *> > &, 0x4CCC80);
    int CheckSuccessRate(unsigned char, unsigned char);
    int CheckSuccessRate(unsigned char);    PATCH_MEMBER(int, CheckSuccessRate, unsigned char, 0x4D7060);
    static int CheckSuccessRate2(unsigned char, unsigned char);    PATCH_STATIC(int, CheckSuccessRate2, unsigned char _COMMA unsigned char, 0x482A40);
    int CheckSuccessRate3();
    int OnNormalAttack(CNSCharacter *, CNSCharacter *, unsigned short, int);    PATCH_MEMBER(int, OnNormalAttack, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA int, 0x4CCDB0);
    int OnNormalAttackEx(CNSCharacter *, CNSCharacter *, unsigned char, unsigned short, int);    PATCH_MEMBER(int, OnNormalAttackEx, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned char _COMMA unsigned short _COMMA int, 0x4CCFF0);
    int OnMinorNormalAttack(CNSCharacter *, CNSCharacter *, unsigned short, int);    PATCH_MEMBER(int, OnMinorNormalAttack, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA int, 0x4CD440);
    int OnDirectAttack(CNSCharacter *, CNSCharacter *, unsigned short, int);    PATCH_MEMBER(int, OnDirectAttack, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA int, 0x4CDDE0);
    int OnMagicAttack(CNSCharacter *, CNSCharacter *, unsigned short, int);    PATCH_MEMBER(int, OnMagicAttack, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA int, 0x4CD6A0);
    int OnMagicAttack2(CNSCharacter *, CNSCharacter *, unsigned short, int);    PATCH_MEMBER(int, OnMagicAttack2, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA int, 0x4CD820);
    int OnMagicAttack3(CNSCharacter *, CNSCharacter *, unsigned short, int);    PATCH_MEMBER(int, OnMagicAttack3, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA int, 0x4CD990);
    int OnBuff(CNSCharacter *, CNSCharacter *, unsigned char, unsigned short, unsigned long);    PATCH_MEMBER(int, OnBuff, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned char _COMMA unsigned short _COMMA unsigned long, 0x4CDEB0);
    int OnHeal(CNSCharacter *, CNSCharacter *, unsigned short);    PATCH_MEMBER(int, OnHeal, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short, 0x4CEC50);
    int OnHealEx(CNSCharacter *, CNSCharacter *, unsigned short);    PATCH_MEMBER(int, OnHealEx, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short, 0x4CF180);
    int OnCure(CNSCharacter *, CNSCharacter *, unsigned short, unsigned long);    PATCH_MEMBER(int, OnCure, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA unsigned long, 0x4CF240);
    int OnRebirth(CNSCharacter *, CNSCharacter *, unsigned short);    PATCH_MEMBER(int, OnRebirth, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short, 0x4CF860);
    int OnBowAttack(CNSCharacter *, CNSCharacter *, unsigned short, int);    PATCH_MEMBER(int, OnBowAttack, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA int, 0x4CD510);
    int OnGel(CNSCharacter *, CNSCharacter *, unsigned char, unsigned short, unsigned long);    PATCH_MEMBER(int, OnGel, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned char _COMMA unsigned short _COMMA unsigned long, 0x4CFF60);
    int OnTaming(CNSCharacter *, CNSCharacter *, unsigned long);    PATCH_MEMBER(int, OnTaming, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned long, 0x4CFCF0);
    int OnSummoning(CNSCharacter *, unsigned long);    PATCH_MEMBER(int, OnSummoning, CNSCharacter * _COMMA unsigned long, 0x4CFD70);
    int OnSpawn(CNSCharacter *, CNSCharacter *, unsigned char, unsigned short, unsigned long);    PATCH_MEMBER(int, OnSpawn, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned char _COMMA unsigned short _COMMA unsigned long, 0x4D0490);
    int OnTeleport(CNSCharacter *, CNSCharacter *, unsigned short);    PATCH_MEMBER(int, OnTeleport, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short, 0x4CFAE0);
    int OnProduction(CNSCharacter *, CNSCharacter *);    PATCH_MEMBER(int, OnProduction, CNSCharacter * _COMMA CNSCharacter *, 0x4D0900);
    int OnResolution(CNSCharacter *, CNSCharacter *);    PATCH_MEMBER(int, OnResolution, CNSCharacter * _COMMA CNSCharacter *, 0x4D09B0);
    int OnMobControl(CNSCharacter *, CNSCharacter *, unsigned short);    PATCH_MEMBER(int, OnMobControl, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short, 0x4D0A50);
    int OnPetControl(CNSCharacter *, CNSCharacter *, unsigned short, unsigned long);    PATCH_MEMBER(int, OnPetControl, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA unsigned long, 0x4D0C20);
    int OnPSWControl(CNSCharacter *, CNSCharacter *, unsigned short, unsigned long);    PATCH_MEMBER(int, OnPSWControl, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA unsigned long, 0x4D0E80);
    int OnSteal(CNSCharacter *, CNSCharacter *, unsigned char, unsigned short);    PATCH_MEMBER(int, OnSteal, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned char _COMMA unsigned short, 0x4D06C0);
    int OnAmulet(CNSCharacter *, CNSCharacter *, unsigned short, unsigned long);    PATCH_MEMBER(int, OnAmulet, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA unsigned long, 0x4D01E0);
    int OnDetection(CNSCharacter *, CNSCharacter *);    PATCH_MEMBER(int, OnDetection, CNSCharacter * _COMMA CNSCharacter *, 0x4D1390);
    int OnBomb(CNSCharacter *, CNSCharacter *, unsigned short, int);    PATCH_MEMBER(int, OnBomb, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA int, 0x4CDB90);
    int OnKnockBack(CNSCharacter *, CNSCharacter *, unsigned short, int);    PATCH_MEMBER(int, OnKnockBack, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA int, 0x4CDD20);
    int OnBuffCheckAttack(CNSCharacter *, CNSCharacter *, unsigned short, int, int);    PATCH_MEMBER(int, OnBuffCheckAttack, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA int _COMMA int, 0x4D1470);
    int OnMortalAttack(CNSCharacter *, CNSCharacter *, unsigned short, int);    PATCH_MEMBER(int, OnMortalAttack, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA int, 0x4D16D0);
    int OnDebuffAttack(CNSCharacter *, CNSCharacter *, unsigned short, int);    PATCH_MEMBER(int, OnDebuffAttack, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA int, 0x4CD330);
    int OnNsNormalAttack(CNSCharacter *, CNSCharacter *, unsigned short, int);    PATCH_MEMBER(int, OnNsNormalAttack, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA int, 0x4CDB00);
    int OnRangeAttack(CNSSkill::SKILLTYPE, CNSCharacter *, CNSCharacter *, CNSCharacter *, unsigned short, unsigned short, unsigned char, int, int);    PATCH_MEMBER(int, OnRangeAttack, CNSSkill::SKILLTYPE _COMMA CNSCharacter * _COMMA CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char _COMMA int _COMMA int, 0x4D17A0);
    int OnParty(CNSSkill::SKILLTYPE, CNSCharacter *, unsigned short, unsigned short, unsigned char, int);    PATCH_MEMBER(int, OnParty, CNSSkill::SKILLTYPE _COMMA CNSCharacter * _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char _COMMA int, 0x4D23E0);
    int OnSpeicalAttack(CNSCharacter *, CNSCharacter *, unsigned char, unsigned short);    PATCH_MEMBER(int, OnSpeicalAttack, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned char _COMMA unsigned short, 0x4D7810);
    int OnBackAttack(CNSCharacter *, CNSCharacter *, unsigned short);    PATCH_MEMBER(int, OnBackAttack, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short, 0x4D8860);
    int OnKillgician(CNSCharacter *, CNSCharacter *, unsigned short);    PATCH_MEMBER(int, OnKillgician, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short, 0x4D8950);
    int OnImpaleDoom(CNSCharacter *, CNSCharacter *, unsigned short);    PATCH_MEMBER(int, OnImpaleDoom, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short, 0x4D8BD0);
    int OnSnapAttack(CNSCharacter *, CNSCharacter *, unsigned short);    PATCH_MEMBER(int, OnSnapAttack, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short, 0x4D8E70);
    int OnChainAssault(CNSCharacter *, CNSCharacter *, unsigned short);    PATCH_MEMBER(int, OnChainAssault, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short, 0x4D90D0);
    int OnBodyCommit(CNSCharacter *, CNSCharacter *, unsigned short);    PATCH_MEMBER(int, OnBodyCommit, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short, 0x4D9670);
    int OnLifeCommit(CNSCharacter *, CNSCharacter *, unsigned short);    PATCH_MEMBER(int, OnLifeCommit, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short, 0x4D9840);
    int OnTranquil(CNSCharacter *, CNSCharacter *, unsigned short);    PATCH_MEMBER(int, OnTranquil, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short, 0x4D99A0);
    int OnHardChopper(CNSCharacter *, CNSCharacter *, unsigned short);    PATCH_MEMBER(int, OnHardChopper, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short, 0x4D9AD0);
    int OnRedSwipe(CNSCharacter *, CNSCharacter *, unsigned short);    PATCH_MEMBER(int, OnRedSwipe, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short, 0x4D9D00);
    int OnViceTouch(CNSCharacter *, CNSCharacter *, unsigned short);    PATCH_MEMBER(int, OnViceTouch, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short, 0x4DA600);
    int OnVitalDrain(CNSCharacter *, CNSCharacter *, unsigned short);    PATCH_MEMBER(int, OnVitalDrain, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short, 0x4DA800);
    int OnMeteo(CNSCharacter *, CNSCharacter *, unsigned short);    PATCH_MEMBER(int, OnMeteo, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short, 0x4DAA30);
    int OnPurgeAttack(CNSCharacter *, CNSCharacter *, unsigned short);    PATCH_MEMBER(int, OnPurgeAttack, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short, 0x4DA100);
    int OnUpPower(CNSCharacter *, CNSCharacter *, unsigned short);
    int OnNutDefense(CNSCharacter *, CNSCharacter *, unsigned short);    PATCH_MEMBER(int, OnNutDefense, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short, 0x4DA180);
    int OnStrainTool(CNSCharacter *, CNSCharacter *, unsigned short);    PATCH_MEMBER(int, OnStrainTool, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short, 0x4DA2D0);
    int OnAssassination(CNSCharacter *, CNSCharacter *, unsigned short);    PATCH_MEMBER(int, OnAssassination, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short, 0x4D9EE0);
    int OnVeinDraw(CNSCharacter *, CNSCharacter *, unsigned short);    PATCH_MEMBER(int, OnVeinDraw, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short, 0x4DAE30);
    int OnGleamBlade(CNSCharacter *, CNSCharacter *, unsigned short);    PATCH_MEMBER(int, OnGleamBlade, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short, 0x4DAE90);
    int OnIgnite(CNSCharacter *, CNSCharacter *, unsigned short);    PATCH_MEMBER(int, OnIgnite, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short, 0x4DAED0);
    int OnSilentCall(CNSCharacter *, CNSCharacter *, unsigned short);    PATCH_MEMBER(int, OnSilentCall, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short, 0x4DB4F0);
    int OnInfernalForce(CNSCharacter *, CNSCharacter *, unsigned short);    PATCH_MEMBER(int, OnInfernalForce, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short, 0x4DAF60);
    int OnPassWhole(CNSCharacter *, CNSCharacter *, unsigned short);    PATCH_MEMBER(int, OnPassWhole, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short, 0x4DB060);
    int OnImmanence(CNSCharacter *, CNSCharacter *, unsigned short, int);    PATCH_MEMBER(int, OnImmanence, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA int, 0x4DB340);
    int OnInsertCoal(CNSCharacter *, CNSCharacter *, unsigned short);    PATCH_MEMBER(int, OnInsertCoal, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short, 0x4DB580);
    int OnInterBomb(CNSCharacter *);    PATCH_MEMBER(int, OnInterBomb, CNSCharacter *, 0x4DB5F0);
    int OnExtractBomb(CNSCharacter *, unsigned short);    PATCH_MEMBER(int, OnExtractBomb, CNSCharacter * _COMMA unsigned short, 0x4DB7F0);
    int OnDutyFront(CNSCharacter *);    PATCH_MEMBER(int, OnDutyFront, CNSCharacter *, 0x4DB9A0);
    int OnStrike(CNSCharacter *, CNSCharacter *, unsigned short);    PATCH_MEMBER(int, OnStrike, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short, 0x4DBA50);
    int OnBullsHydra(CNSCharacter *, CNSCharacter *, unsigned short);    PATCH_MEMBER(int, OnBullsHydra, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short, 0x4DB1B0);
    int OnSavageOrder(CNSCharacter *, CNSCharacter *, unsigned short);    PATCH_MEMBER(int, OnSavageOrder, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short, 0x4DBEF0);
    int OnNsSpecialAttack(CNSCharacter *, CNSCharacter *, unsigned short);    PATCH_MEMBER(int, OnNsSpecialAttack, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short, 0x4D8750);
    int OnDeathShadow(CNSCharacter *, CNSCharacter *);    PATCH_MEMBER(int, OnDeathShadow, CNSCharacter * _COMMA CNSCharacter *, 0x4DAC70);
    int OnNeoSteamRecovery(CNSCharacter *, CNSCharacter *, unsigned short);    PATCH_MEMBER(int, OnNeoSteamRecovery, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short, 0x4DAD70);
    int OnWeaveIllusion(CNSCharacter *, CNSCharacter *);
    int OnNpcSpeicalAttack(CNSCharacter *, CNSCharacter *, unsigned char, unsigned short, int);    PATCH_MEMBER(int, OnNpcSpeicalAttack, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned char _COMMA unsigned short _COMMA int, 0x4DBBB0);
    CNSSkill & operator=(const CNSSkill &);    //PATCH_MEMBER(CNSSkill &, operator=, const CNSSkill &, 0x43F6F0);
    //void __local_vftable_ctor_closure();
    //virtual void * __vecDelDtor(unsigned int);

    /*struct _Invoke {
    PATCH_MEMBER_INVOKE(CNSSkill &, CNSSkill, Constructor, );
    PATCH_MEMBER_INVOKE(void, CNSSkill, Destructor, );
    PATCH_MEMBER_INVOKE(void, CNSSkill, Clear, );
    PATCH_MEMBER_INVOKE(int, CNSSkill, IsSteamAbility, );
    PATCH_MEMBER_INVOKE(int, CNSSkill, IsPassive, );
    PATCH_MEMBER_INVOKE(int, CNSSkill, IsMythic, );
    PATCH_MEMBER_INVOKE(int, CNSSkill, IsRaceAbility, );
    PATCH_MEMBER_INVOKE(int, CNSSkill, IsRebirth, );
    PATCH_MEMBER_INVOKE(int, CNSSkill, IsAttrib, );
    PATCH_MEMBER_INVOKE(int, CNSSkill, IsMastery, );
    PATCH_MEMBER_INVOKE(int, CNSSkill, IsSpecialActive, );
    PATCH_MEMBER_INVOKE(int, CNSSkill, IsHelper, );
    PATCH_MEMBER_INVOKE(int, CNSSkill, IsPSWSkill, );
    PATCH_MEMBER_INVOKE(unsigned short, CNSSkill, GetSkillId, );
    PATCH_MEMBER_INVOKE(char *, CNSSkill, GetSkillName, );
    PATCH_MEMBER_INVOKE(unsigned char, CNSSkill, GetSkillLevel, );
    PATCH_MEMBER_INVOKE(char *, CNSSkill, GetDescription, CNSPc * _COMMA char *);
    PATCH_MEMBER_INVOKE(unsigned short, CNSSkill, GetExp, );
    PATCH_MEMBER_INVOKE(unsigned short, CNSSkill, GetNextExp, );
    PATCH_MEMBER_INVOKE(unsigned char, CNSSkill, GetRangeType, );
    PATCH_MEMBER_INVOKE(unsigned short, CNSSkill, GetRange, CNSCharacter *);
    PATCH_MEMBER_INVOKE(unsigned short, CNSSkill, GetDurationTime, unsigned char);
    PATCH_MEMBER_INVOKE(int, CNSSkill, CheckTarget, CNSCharacter * _COMMA CNSCharacter *);
    PATCH_MEMBER_INVOKE(int, CNSSkill, CheckSkill, CNSCharacter * _COMMA unsigned long);
    PATCH_MEMBER_INVOKE(int, CNSSkill, Cast, CNSCharacter * _COMMA unsigned long);
    PATCH_MEMBER_INVOKE(int, CNSSkill, Use, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned long);
    PATCH_STATIC_INVOKE(unsigned short, Attack, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA CNSObject::HITTYPE _COMMA int);
    PATCH_STATIC_INVOKE(CNSSkill::TARGETTYPE, GetTargetType, CNSSkill *);
    PATCH_MEMBER_INVOKE(void, CNSSkill, AddSkillExpPoint, CNSPc * _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSSkill, CheckSuccessRate4, unsigned char _COMMA unsigned char);
    PATCH_STATIC_INVOKE(int, CheckSuccessRate4, unsigned char _COMMA unsigned char _COMMA unsigned char);
    PATCH_MEMBER_INVOKE(void, CNSSkill, SetTempValue, int _COMMA unsigned long);
    PATCH_STATIC_INVOKE(int, CheckPSWLimit, CNSPc * _COMMA unsigned long);
    PATCH_MEMBER_INVOKE(void, CNSSkill, SendSkillUseMessage, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned char _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(unsigned short, CNSSkill, GetUsePoint, CNSCharacter *);
    PATCH_MEMBER_INVOKE(unsigned char, CNSSkill, GetLimitSkillLevel, CNSPc * _COMMA int);
    PATCH_MEMBER_INVOKE(unsigned char, CNSSkill, GetLimitPcLevel, CNSPc *);
    PATCH_MEMBER_INVOKE(unsigned long, CNSSkill, GetUseSkillExpPoint, unsigned char);
    PATCH_MEMBER_INVOKE(unsigned long, CNSSkill, GetUseSkillExpPointAll, );
    PATCH_MEMBER_INVOKE(CNSObject *, CNSSkill, SearchObject, int _COMMA unsigned char _COMMA unsigned short _COMMA std::vector<CNSObject * _COMMA std::allocator<CNSObject *> > & _COMMA CNSCharacter * _COMMA CNSCharacter *);
    PATCH_MEMBER_INVOKE(void, CNSSkill, SearchObjectFinish, std::vector<CNSObject * _COMMA std::allocator<CNSObject *> > &);
    PATCH_MEMBER_INVOKE(int, CNSSkill, CheckSuccessRate, unsigned char);
    PATCH_STATIC_INVOKE(int, CheckSuccessRate2, unsigned char _COMMA unsigned char);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnNormalAttack, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA int);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnNormalAttackEx, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned char _COMMA unsigned short _COMMA int);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnMinorNormalAttack, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA int);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnDirectAttack, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA int);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnMagicAttack, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA int);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnMagicAttack2, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA int);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnMagicAttack3, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA int);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnBuff, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned char _COMMA unsigned short _COMMA unsigned long);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnHeal, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnHealEx, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnCure, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA unsigned long);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnRebirth, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnBowAttack, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA int);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnGel, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned char _COMMA unsigned short _COMMA unsigned long);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnTaming, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned long);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnSummoning, CNSCharacter * _COMMA unsigned long);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnSpawn, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned char _COMMA unsigned short _COMMA unsigned long);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnTeleport, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnProduction, CNSCharacter * _COMMA CNSCharacter *);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnResolution, CNSCharacter * _COMMA CNSCharacter *);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnMobControl, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnPetControl, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA unsigned long);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnPSWControl, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA unsigned long);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnSteal, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned char _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnAmulet, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA unsigned long);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnDetection, CNSCharacter * _COMMA CNSCharacter *);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnBomb, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA int);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnKnockBack, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA int);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnBuffCheckAttack, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA int _COMMA int);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnMortalAttack, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA int);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnDebuffAttack, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA int);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnNsNormalAttack, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA int);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnRangeAttack, CNSSkill::SKILLTYPE _COMMA CNSCharacter * _COMMA CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char _COMMA int _COMMA int);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnParty, CNSSkill::SKILLTYPE _COMMA CNSCharacter * _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char _COMMA int);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnSpeicalAttack, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned char _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnBackAttack, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnKillgician, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnImpaleDoom, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnSnapAttack, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnChainAssault, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnBodyCommit, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnLifeCommit, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnTranquil, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnHardChopper, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnRedSwipe, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnViceTouch, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnVitalDrain, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnMeteo, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnPurgeAttack, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnNutDefense, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnStrainTool, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnAssassination, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnVeinDraw, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnGleamBlade, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnIgnite, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnSilentCall, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnInfernalForce, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnPassWhole, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnImmanence, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA int);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnInsertCoal, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnInterBomb, CNSCharacter *);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnExtractBomb, CNSCharacter * _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnDutyFront, CNSCharacter *);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnStrike, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnBullsHydra, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnSavageOrder, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnNsSpecialAttack, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnDeathShadow, CNSCharacter * _COMMA CNSCharacter *);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnNeoSteamRecovery, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSSkill, OnNpcSpeicalAttack, CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned char _COMMA unsigned short _COMMA int);
    //PATCH_MEMBER_INVOKE(CNSSkill &, CNSSkill, operator=, const CNSSkill &);
    };*/
};
#ifdef DEFINE_NS_CPP
DEFINE_NAKED_JMP(CNSSkill& CNSSkill::Constructor(), 0x4C9550);
//DEFINE_NAKED_JMP(CNSSkill::Destructor(), 0x4C95E0);
DEFINE_NAKED_JMP(void CNSSkill::Clear(), 0x4C9690);
DEFINE_NAKED_JMP(int CNSSkill::IsSteamAbility(), 0x483840);
DEFINE_NAKED_JMP(int CNSSkill::IsPassive(), 0x4D6D60);
DEFINE_NAKED_JMP(int CNSSkill::IsMythic(), 0x4D6D80);
DEFINE_NAKED_JMP(int CNSSkill::IsRaceAbility(), 0x4D6DA0);
DEFINE_NAKED_JMP(int CNSSkill::IsRebirth(), 0x4D6FF0);
DEFINE_NAKED_JMP(int CNSSkill::IsAttrib(), 0x4D6F70);
DEFINE_NAKED_JMP(int CNSSkill::IsMastery(), 0x4D6F90);
DEFINE_NAKED_JMP(int CNSSkill::IsSpecialActive(), 0x4D6FB0);
DEFINE_NAKED_JMP(int CNSSkill::IsHelper(), 0x4D7040);
DEFINE_NAKED_JMP(int CNSSkill::IsPSWSkill(), 0x4D72C0);
DEFINE_NAKED_JMP(unsigned short CNSSkill::GetSkillId(), 0x45A920);
DEFINE_NAKED_JMP(char * CNSSkill::GetSkillName(), 0x406500);
DEFINE_NAKED_JMP(unsigned char CNSSkill::GetSkillLevel(), 0x482A20);
DEFINE_NAKED_JMP(char * CNSSkill::GetDescription(CNSPc * _COMMA char *), 0x4C9840);
DEFINE_NAKED_JMP(unsigned short CNSSkill::GetExp(), 0x4C81D0);
DEFINE_NAKED_JMP(unsigned short CNSSkill::GetNextExp(), 0x4C81F0);
DEFINE_NAKED_JMP(unsigned char CNSSkill::GetRangeType(), 0x44C3B0);
DEFINE_NAKED_JMP(unsigned short CNSSkill::GetRange(CNSCharacter *), 0x4CCB40);
DEFINE_NAKED_JMP(unsigned short CNSSkill::GetDurationTime(unsigned char), 0x43EC50);
DEFINE_NAKED_JMP(int CNSSkill::CheckTarget(CNSCharacter * _COMMA CNSCharacter *), 0x4CC700);
DEFINE_NAKED_JMP(int CNSSkill::CheckSkill(CNSCharacter * _COMMA unsigned long), 0x4C9F90);
DEFINE_NAKED_JMP(int CNSSkill::Cast(CNSCharacter * _COMMA unsigned long), 0x4CA400);
DEFINE_NAKED_JMP(int CNSSkill::Use(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned long), 0x4CA420);
DEFINE_NAKED_JMP(unsigned short CNSSkill::Attack(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA CNSObject::HITTYPE _COMMA int), 0x4CCD10);
DEFINE_NAKED_JMP(CNSSkill::TARGETTYPE CNSSkill::GetTargetType(CNSSkill *), 0x4D74D0);
DEFINE_NAKED_JMP(void CNSSkill::AddSkillExpPoint(CNSPc * _COMMA unsigned short), 0x4CC4A0);
DEFINE_NAKED_JMP(int CNSSkill::CheckSuccessRate4(unsigned char _COMMA unsigned char), 0x4D70E0);
DEFINE_NAKED_JMP(int CNSSkill::CheckSuccessRate4(unsigned char _COMMA unsigned char _COMMA unsigned char), 0x423B80);
DEFINE_NAKED_JMP(void CNSSkill::SetTempValue(int _COMMA unsigned long), 0x43EC30);
DEFINE_NAKED_JMP(int CNSSkill::CheckPSWLimit(CNSPc * _COMMA unsigned long), 0x4D0DF0);
DEFINE_NAKED_JMP(void CNSSkill::SendSkillUseMessage(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned char _COMMA unsigned short), 0x4CCCC0);
DEFINE_NAKED_JMP(unsigned short CNSSkill::GetUsePoint(CNSCharacter *), 0x4C96B0);
DEFINE_NAKED_JMP(unsigned char CNSSkill::GetLimitSkillLevel(CNSPc * _COMMA int), 0x4CC190);
DEFINE_NAKED_JMP(unsigned char CNSSkill::GetLimitPcLevel(CNSPc *), 0x4CC3F0);
DEFINE_NAKED_JMP(unsigned long CNSSkill::GetUseSkillExpPoint(unsigned char), 0x4D6DC0);
DEFINE_NAKED_JMP(unsigned long CNSSkill::GetUseSkillExpPointAll(), 0x4C9F30);
DEFINE_NAKED_JMP(CNSObject * CNSSkill::SearchObject(int _COMMA unsigned char _COMMA unsigned short _COMMA std::vector<CNSObject * _COMMA std::allocator<CNSObject *> > & _COMMA CNSCharacter * _COMMA CNSCharacter *), 0x4CCBE0);
DEFINE_NAKED_JMP(void CNSSkill::SearchObjectFinish(std::vector<CNSObject * _COMMA std::allocator<CNSObject *> > &), 0x4CCC80);
DEFINE_NAKED_JMP(int CNSSkill::CheckSuccessRate(unsigned char), 0x4D7060);
DEFINE_NAKED_JMP(int CNSSkill::CheckSuccessRate2(unsigned char _COMMA unsigned char), 0x482A40);
DEFINE_NAKED_JMP(int CNSSkill::OnNormalAttack(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA int), 0x4CCDB0);
DEFINE_NAKED_JMP(int CNSSkill::OnNormalAttackEx(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned char _COMMA unsigned short _COMMA int), 0x4CCFF0);
DEFINE_NAKED_JMP(int CNSSkill::OnMinorNormalAttack(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA int), 0x4CD440);
DEFINE_NAKED_JMP(int CNSSkill::OnDirectAttack(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA int), 0x4CDDE0);
DEFINE_NAKED_JMP(int CNSSkill::OnMagicAttack(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA int), 0x4CD6A0);
DEFINE_NAKED_JMP(int CNSSkill::OnMagicAttack2(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA int), 0x4CD820);
DEFINE_NAKED_JMP(int CNSSkill::OnMagicAttack3(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA int), 0x4CD990);
DEFINE_NAKED_JMP(int CNSSkill::OnBuff(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned char _COMMA unsigned short _COMMA unsigned long), 0x4CDEB0);
DEFINE_NAKED_JMP(int CNSSkill::OnHeal(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short), 0x4CEC50);
DEFINE_NAKED_JMP(int CNSSkill::OnHealEx(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short), 0x4CF180);
DEFINE_NAKED_JMP(int CNSSkill::OnCure(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA unsigned long), 0x4CF240);
DEFINE_NAKED_JMP(int CNSSkill::OnRebirth(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short), 0x4CF860);
DEFINE_NAKED_JMP(int CNSSkill::OnBowAttack(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA int), 0x4CD510);
DEFINE_NAKED_JMP(int CNSSkill::OnGel(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned char _COMMA unsigned short _COMMA unsigned long), 0x4CFF60);
DEFINE_NAKED_JMP(int CNSSkill::OnTaming(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned long), 0x4CFCF0);
DEFINE_NAKED_JMP(int CNSSkill::OnSummoning(CNSCharacter * _COMMA unsigned long), 0x4CFD70);
DEFINE_NAKED_JMP(int CNSSkill::OnSpawn(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned char _COMMA unsigned short _COMMA unsigned long), 0x4D0490);
DEFINE_NAKED_JMP(int CNSSkill::OnTeleport(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short), 0x4CFAE0);
DEFINE_NAKED_JMP(int CNSSkill::OnProduction(CNSCharacter * _COMMA CNSCharacter *), 0x4D0900);
DEFINE_NAKED_JMP(int CNSSkill::OnResolution(CNSCharacter * _COMMA CNSCharacter *), 0x4D09B0);
DEFINE_NAKED_JMP(int CNSSkill::OnMobControl(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short), 0x4D0A50);
DEFINE_NAKED_JMP(int CNSSkill::OnPetControl(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA unsigned long), 0x4D0C20);
DEFINE_NAKED_JMP(int CNSSkill::OnPSWControl(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA unsigned long), 0x4D0E80);
DEFINE_NAKED_JMP(int CNSSkill::OnSteal(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned char _COMMA unsigned short), 0x4D06C0);
DEFINE_NAKED_JMP(int CNSSkill::OnAmulet(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA unsigned long), 0x4D01E0);
DEFINE_NAKED_JMP(int CNSSkill::OnDetection(CNSCharacter * _COMMA CNSCharacter *), 0x4D1390);
DEFINE_NAKED_JMP(int CNSSkill::OnBomb(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA int), 0x4CDB90);
DEFINE_NAKED_JMP(int CNSSkill::OnKnockBack(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA int), 0x4CDD20);
DEFINE_NAKED_JMP(int CNSSkill::OnBuffCheckAttack(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA int _COMMA int), 0x4D1470);
DEFINE_NAKED_JMP(int CNSSkill::OnMortalAttack(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA int), 0x4D16D0);
DEFINE_NAKED_JMP(int CNSSkill::OnDebuffAttack(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA int), 0x4CD330);
DEFINE_NAKED_JMP(int CNSSkill::OnNsNormalAttack(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA int), 0x4CDB00);
DEFINE_NAKED_JMP(int CNSSkill::OnRangeAttack(CNSSkill::SKILLTYPE _COMMA CNSCharacter * _COMMA CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char _COMMA int _COMMA int), 0x4D17A0);
DEFINE_NAKED_JMP(int CNSSkill::OnParty(CNSSkill::SKILLTYPE _COMMA CNSCharacter * _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char _COMMA int), 0x4D23E0);
DEFINE_NAKED_JMP(int CNSSkill::OnSpeicalAttack(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned char _COMMA unsigned short), 0x4D7810);
DEFINE_NAKED_JMP(int CNSSkill::OnBackAttack(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short), 0x4D8860);
DEFINE_NAKED_JMP(int CNSSkill::OnKillgician(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short), 0x4D8950);
DEFINE_NAKED_JMP(int CNSSkill::OnImpaleDoom(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short), 0x4D8BD0);
DEFINE_NAKED_JMP(int CNSSkill::OnSnapAttack(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short), 0x4D8E70);
DEFINE_NAKED_JMP(int CNSSkill::OnChainAssault(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short), 0x4D90D0);
DEFINE_NAKED_JMP(int CNSSkill::OnBodyCommit(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short), 0x4D9670);
DEFINE_NAKED_JMP(int CNSSkill::OnLifeCommit(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short), 0x4D9840);
DEFINE_NAKED_JMP(int CNSSkill::OnTranquil(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short), 0x4D99A0);
DEFINE_NAKED_JMP(int CNSSkill::OnHardChopper(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short), 0x4D9AD0);
DEFINE_NAKED_JMP(int CNSSkill::OnRedSwipe(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short), 0x4D9D00);
DEFINE_NAKED_JMP(int CNSSkill::OnViceTouch(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short), 0x4DA600);
DEFINE_NAKED_JMP(int CNSSkill::OnVitalDrain(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short), 0x4DA800);
DEFINE_NAKED_JMP(int CNSSkill::OnMeteo(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short), 0x4DAA30);
DEFINE_NAKED_JMP(int CNSSkill::OnPurgeAttack(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short), 0x4DA100);
DEFINE_NAKED_JMP(int CNSSkill::OnNutDefense(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short), 0x4DA180);
DEFINE_NAKED_JMP(int CNSSkill::OnStrainTool(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short), 0x4DA2D0);
DEFINE_NAKED_JMP(int CNSSkill::OnAssassination(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short), 0x4D9EE0);
DEFINE_NAKED_JMP(int CNSSkill::OnVeinDraw(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short), 0x4DAE30);
DEFINE_NAKED_JMP(int CNSSkill::OnGleamBlade(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short), 0x4DAE90);
DEFINE_NAKED_JMP(int CNSSkill::OnIgnite(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short), 0x4DAED0);
DEFINE_NAKED_JMP(int CNSSkill::OnSilentCall(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short), 0x4DB4F0);
DEFINE_NAKED_JMP(int CNSSkill::OnInfernalForce(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short), 0x4DAF60);
DEFINE_NAKED_JMP(int CNSSkill::OnPassWhole(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short), 0x4DB060);
DEFINE_NAKED_JMP(int CNSSkill::OnImmanence(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short _COMMA int), 0x4DB340);
DEFINE_NAKED_JMP(int CNSSkill::OnInsertCoal(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short), 0x4DB580);
DEFINE_NAKED_JMP(int CNSSkill::OnInterBomb(CNSCharacter *), 0x4DB5F0);
DEFINE_NAKED_JMP(int CNSSkill::OnExtractBomb(CNSCharacter * _COMMA unsigned short), 0x4DB7F0);
DEFINE_NAKED_JMP(int CNSSkill::OnDutyFront(CNSCharacter *), 0x4DB9A0);
DEFINE_NAKED_JMP(int CNSSkill::OnStrike(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short), 0x4DBA50);
DEFINE_NAKED_JMP(int CNSSkill::OnBullsHydra(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short), 0x4DB1B0);
DEFINE_NAKED_JMP(int CNSSkill::OnSavageOrder(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short), 0x4DBEF0);
DEFINE_NAKED_JMP(int CNSSkill::OnNsSpecialAttack(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short), 0x4D8750);
DEFINE_NAKED_JMP(int CNSSkill::OnDeathShadow(CNSCharacter * _COMMA CNSCharacter *), 0x4DAC70);
DEFINE_NAKED_JMP(int CNSSkill::OnNeoSteamRecovery(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned short), 0x4DAD70);
DEFINE_NAKED_JMP(int CNSSkill::OnNpcSpeicalAttack(CNSCharacter * _COMMA CNSCharacter * _COMMA unsigned char _COMMA unsigned short _COMMA int), 0x4DBBB0);
DEFINE_NAKED_JMP(CNSSkill & CNSSkill::operator=(const CNSSkill &), 0x43F6F0);
#endif


class CNSSkillList {
public:
    static const unsigned int _size = 0x2840;


    enum SKILLSTEP {
        SkillStep_None =  0x0,
        SkillStep_Cast =  0x1,
        SkillStep_Use =  0x2,
        SkillStep_Cancel =  0x3,
    };

    CNSSkillList(const CNSSkillList &);
    CNSSkillList(CNSCharacter *);    PATCH_MEMBER(CNSSkillList &, Constructor, CNSCharacter *, 0x4D2690);
    virtual ~CNSSkillList();    PATCH_MEMBER(void, Destructor, , 0x4D2720);
    void SetParent(CNSCharacter *);    PATCH_MEMBER(void, SetParent, CNSCharacter *, 0x481CD0);
    unsigned long GetCount();    PATCH_MEMBER(unsigned long, GetCount, , 0x48FAB0);
    virtual unsigned long GetMaxList();    PATCH_MEMBER(unsigned long, GetMaxList, , 0x4D7470);
    virtual CNSSkill & GetSkill(int);    PATCH_MEMBER(CNSSkill &, GetSkill, int, 0x4D7480);
    virtual void Clear();    PATCH_MEMBER(void, Clear, , 0x4D2790);
    CNSSkill * Add(unsigned short, unsigned char);    PATCH_MEMBER(CNSSkill *, Add, unsigned short _COMMA unsigned char, 0x4D2AC0);
    CNSSkill * Add(unsigned short, unsigned char, unsigned char, unsigned char, unsigned short, unsigned char, unsigned char, unsigned short, unsigned char, unsigned short, unsigned char, unsigned short, unsigned char, unsigned short, unsigned short);    PATCH_MEMBER(CNSSkill *, Add, unsigned short _COMMA unsigned char _COMMA unsigned char _COMMA unsigned char _COMMA unsigned short _COMMA unsigned char _COMMA unsigned char _COMMA unsigned short _COMMA unsigned char _COMMA unsigned short _COMMA unsigned char _COMMA unsigned short _COMMA unsigned char _COMMA unsigned short _COMMA unsigned short, 0x4D2940);
    CNSSkill * Add(unsigned char, unsigned char, unsigned short, unsigned char, unsigned short);    PATCH_MEMBER(CNSSkill *, Add, unsigned char _COMMA unsigned char _COMMA unsigned short _COMMA unsigned char _COMMA unsigned short, 0x4D2800);
    CNSSkill * AddMachine(CNSEquipment::EQUIPMENTTYPE, unsigned short, unsigned char);    PATCH_MEMBER(CNSSkill *, AddMachine, CNSEquipment::EQUIPMENTTYPE _COMMA unsigned short _COMMA unsigned char, 0x4D2BA0);
    void Delete(unsigned short);    PATCH_MEMBER(void, Delete, unsigned short, 0x4D2D10);
    CNSSkill * GetActiveSkill();    PATCH_MEMBER(CNSSkill *, GetActiveSkill, , 0x402210);
    CNSSkill * Get(unsigned short);    PATCH_MEMBER(CNSSkill *, Get, unsigned short, 0x4D2D70);
    unsigned char GetSkillLevel(unsigned short);    PATCH_MEMBER(unsigned char, GetSkillLevel, unsigned short, 0x4D2750);
    int Study(unsigned short);    PATCH_MEMBER(int, Study, unsigned short, 0x4D3FA0);
    void AutoExpUp(unsigned char);    PATCH_MEMBER(void, AutoExpUp, unsigned char, 0x4D4340);
    unsigned short GetRange();    PATCH_MEMBER(unsigned short, GetRange, , 0x45A8A0);
    unsigned short GetSkillId();    PATCH_MEMBER(unsigned short, GetSkillId, , 0x45A8E0);
    unsigned char GetSkillType(int);    PATCH_MEMBER(unsigned char, GetSkillType, int, 0x494DD0);
    unsigned long GetSkillAttackSpeed();    PATCH_MEMBER(unsigned long, GetSkillAttackSpeed, , 0x494E10);
    unsigned char GetCastTime();    PATCH_MEMBER(unsigned char, GetCastTime, , 0x45A940);
    unsigned long GetTargetObjectId();    PATCH_MEMBER(unsigned long, GetTargetObjectId, , 0x423E70);
    int Target(unsigned short, unsigned long, unsigned long);    PATCH_MEMBER(int, Target, unsigned short _COMMA unsigned long _COMMA unsigned long, 0x4D4400);
    int Cast(unsigned long, unsigned long &);    PATCH_MEMBER(int, Cast, unsigned long _COMMA unsigned long &, 0x4D4790);
    int Use(unsigned long, unsigned long &);    PATCH_MEMBER(int, Use, unsigned long _COMMA unsigned long &, 0x4D4800);
    int DirectCast(unsigned short, unsigned long, unsigned long);    PATCH_MEMBER(int, DirectCast, unsigned short _COMMA unsigned long _COMMA unsigned long, 0x4D4970);
    void Cancel(int);    PATCH_MEMBER(void, Cancel, int, 0x4D4A30);
    CNSSkillList::SKILLSTEP GetStep();    PATCH_MEMBER(CNSSkillList::SKILLSTEP, GetStep, , 0x45A970);
    int CheckTargetDead(CNSCharacter *);    PATCH_MEMBER(int, CheckTargetDead, CNSCharacter *, 0x4D49E0);
    int DBSkillListBuild(unsigned char, unsigned char);    PATCH_MEMBER(int, DBSkillListBuild, unsigned char _COMMA unsigned char, 0x4D2E00);
    int SkillDefaultList();    PATCH_MEMBER(int, SkillDefaultList, , 0x4D3760);
    unsigned short SetRaceAbility(CNSPc *);    PATCH_MEMBER(unsigned short, SetRaceAbility, CNSPc *, 0x4D2F90);
    int IsActiveSkill();    PATCH_MEMBER(int, IsActiveSkill, , 0x4831B0);
    void CheckSkillCancel(unsigned short);    PATCH_MEMBER(void, CheckSkillCancel, unsigned short, 0x4D4AE0);
    unsigned long GetOverHeat(CNSSkill *, unsigned long);    PATCH_MEMBER(unsigned long, GetOverHeat, CNSSkill * _COMMA unsigned long, 0x4D7600);
    unsigned long GetOverHeat(CNSEquipment::EQUIPMENTTYPE, unsigned long);    PATCH_MEMBER(unsigned long, GetOverHeat, CNSEquipment::EQUIPMENTTYPE _COMMA unsigned long, 0x483240);
    void SetOverHeat(CNSSkill *, unsigned long);    PATCH_MEMBER(void, SetOverHeat, CNSSkill * _COMMA unsigned long, 0x4D7670);
    void SetCancel();    PATCH_MEMBER(void, SetCancel, , 0x4838A0);
    int PremiumSkillLevelUp(unsigned short, int, int);    PATCH_MEMBER(int, PremiumSkillLevelUp, unsigned short _COMMA int _COMMA int, 0x4D4C80);
    int DebugSkillLevelUp(unsigned short);    PATCH_MEMBER(int, DebugSkillLevelUp, unsigned short, 0x4D4F10);
    int DebugSkillExp(unsigned short, unsigned short);    PATCH_MEMBER(int, DebugSkillExp, unsigned short _COMMA unsigned short, 0x4D5040);
    void DebugSkillLevelUpAll();    PATCH_MEMBER(void, DebugSkillLevelUpAll, , 0x4D4FD0);
    void ClearCoolTime();    PATCH_MEMBER(void, ClearCoolTime, , 0x4D5090);
    void AddSkillExpPoint(unsigned short, unsigned short);    PATCH_MEMBER(void, AddSkillExpPoint, unsigned short _COMMA unsigned short, 0x4D5130);
    unsigned long GetNpcCoolTime();
    int SkillReset(unsigned char);    PATCH_MEMBER(int, SkillReset, unsigned char, 0x4D56D0);
    int SkillReset(unsigned short, int);    PATCH_MEMBER(int, SkillReset, unsigned short _COMMA int, 0x4D5180);
    int SkillPSWPartReset();    PATCH_MEMBER(int, SkillPSWPartReset, , 0x4D5CB0);
    int SkillChange(unsigned short);    PATCH_MEMBER(int, SkillChange, unsigned short, 0x4D5A90);
    int SkillPointSetup();    PATCH_MEMBER(int, SkillPointSetup, , 0x4D5DD0);
    unsigned char GetAttribSkill();    PATCH_MEMBER(unsigned char, GetAttribSkill, , 0x4D5FC0);
    int CheckCastTime(unsigned long);    PATCH_MEMBER(int, CheckCastTime, unsigned long, 0x494E50);
    class CNSCharacter * m_pChar;//this+0x4
    class CNSSkill * m_pActiveSkill;//this+0x8
    unsigned long m_dwOldTargetObjectId;//this+0xC
    unsigned long m_dwTargetObjectId;//this+0x10
    unsigned long m_dwLastUseTime;//this+0x14
    unsigned long m_dwCheckCastTime;//this+0x18
    unsigned long m_dwCount;//this+0x1C
    class CNSSkill m_skillList[0x64];//this+0x20
    enum CNSSkillList::SKILLSTEP m_skillStep;//this+0x2730
    unsigned long m_dwOverHeatTime[0x43];//this+0x2734
    CNSSkillList & operator=(const CNSSkillList &);
    //void __dflt_ctor_closure();
    //void __local_vftable_ctor_closure();
    //virtual void * __vecDelDtor(unsigned int);

    /*struct _Invoke {
    PATCH_MEMBER_INVOKE(CNSSkillList &, CNSSkillList, Constructor, CNSCharacter *);
    PATCH_MEMBER_INVOKE(void, CNSSkillList, Destructor, );
    PATCH_MEMBER_INVOKE(void, CNSSkillList, SetParent, CNSCharacter *);
    PATCH_MEMBER_INVOKE(unsigned long, CNSSkillList, GetCount, );
    PATCH_MEMBER_INVOKE(unsigned long, CNSSkillList, GetMaxList, );
    PATCH_MEMBER_INVOKE(CNSSkill &, CNSSkillList, GetSkill, int);
    PATCH_MEMBER_INVOKE(void, CNSSkillList, Clear, );
    PATCH_MEMBER_INVOKE(CNSSkill *, CNSSkillList, Add, unsigned short _COMMA unsigned char);
    PATCH_MEMBER_INVOKE(CNSSkill *, CNSSkillList, Add, unsigned short _COMMA unsigned char _COMMA unsigned char _COMMA unsigned char _COMMA unsigned short _COMMA unsigned char _COMMA unsigned char _COMMA unsigned short _COMMA unsigned char _COMMA unsigned short _COMMA unsigned char _COMMA unsigned short _COMMA unsigned char _COMMA unsigned short _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(CNSSkill *, CNSSkillList, Add, unsigned char _COMMA unsigned char _COMMA unsigned short _COMMA unsigned char _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(CNSSkill *, CNSSkillList, AddMachine, CNSEquipment::EQUIPMENTTYPE _COMMA unsigned short _COMMA unsigned char);
    PATCH_MEMBER_INVOKE(void, CNSSkillList, Delete, unsigned short);
    PATCH_MEMBER_INVOKE(CNSSkill *, CNSSkillList, GetActiveSkill, );
    PATCH_MEMBER_INVOKE(CNSSkill *, CNSSkillList, Get, unsigned short);
    PATCH_MEMBER_INVOKE(unsigned char, CNSSkillList, GetSkillLevel, unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSSkillList, Study, unsigned short);
    PATCH_MEMBER_INVOKE(void, CNSSkillList, AutoExpUp, unsigned char);
    PATCH_MEMBER_INVOKE(unsigned short, CNSSkillList, GetRange, );
    PATCH_MEMBER_INVOKE(unsigned short, CNSSkillList, GetSkillId, );
    PATCH_MEMBER_INVOKE(unsigned char, CNSSkillList, GetSkillType, int);
    PATCH_MEMBER_INVOKE(unsigned long, CNSSkillList, GetSkillAttackSpeed, );
    PATCH_MEMBER_INVOKE(unsigned char, CNSSkillList, GetCastTime, );
    PATCH_MEMBER_INVOKE(unsigned long, CNSSkillList, GetTargetObjectId, );
    PATCH_MEMBER_INVOKE(int, CNSSkillList, Target, unsigned short _COMMA unsigned long _COMMA unsigned long);
    PATCH_MEMBER_INVOKE(int, CNSSkillList, Cast, unsigned long _COMMA unsigned long &);
    PATCH_MEMBER_INVOKE(int, CNSSkillList, Use, unsigned long _COMMA unsigned long &);
    PATCH_MEMBER_INVOKE(int, CNSSkillList, DirectCast, unsigned short _COMMA unsigned long _COMMA unsigned long);
    PATCH_MEMBER_INVOKE(void, CNSSkillList, Cancel, int);
    PATCH_MEMBER_INVOKE(CNSSkillList::SKILLSTEP, CNSSkillList, GetStep, );
    PATCH_MEMBER_INVOKE(int, CNSSkillList, CheckTargetDead, CNSCharacter *);
    PATCH_MEMBER_INVOKE(int, CNSSkillList, DBSkillListBuild, unsigned char _COMMA unsigned char);
    PATCH_MEMBER_INVOKE(int, CNSSkillList, SkillDefaultList, );
    PATCH_MEMBER_INVOKE(unsigned short, CNSSkillList, SetRaceAbility, CNSPc *);
    PATCH_MEMBER_INVOKE(int, CNSSkillList, IsActiveSkill, );
    PATCH_MEMBER_INVOKE(void, CNSSkillList, CheckSkillCancel, unsigned short);
    PATCH_MEMBER_INVOKE(unsigned long, CNSSkillList, GetOverHeat, CNSSkill * _COMMA unsigned long);
    PATCH_MEMBER_INVOKE(unsigned long, CNSSkillList, GetOverHeat, CNSEquipment::EQUIPMENTTYPE _COMMA unsigned long);
    PATCH_MEMBER_INVOKE(void, CNSSkillList, SetOverHeat, CNSSkill * _COMMA unsigned long);
    PATCH_MEMBER_INVOKE(void, CNSSkillList, SetCancel, );
    PATCH_MEMBER_INVOKE(int, CNSSkillList, PremiumSkillLevelUp, unsigned short _COMMA int _COMMA int);
    PATCH_MEMBER_INVOKE(int, CNSSkillList, DebugSkillLevelUp, unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSSkillList, DebugSkillExp, unsigned short _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(void, CNSSkillList, DebugSkillLevelUpAll, );
    PATCH_MEMBER_INVOKE(void, CNSSkillList, ClearCoolTime, );
    PATCH_MEMBER_INVOKE(void, CNSSkillList, AddSkillExpPoint, unsigned short _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSSkillList, SkillReset, unsigned char);
    PATCH_MEMBER_INVOKE(int, CNSSkillList, SkillReset, unsigned short _COMMA int);
    PATCH_MEMBER_INVOKE(int, CNSSkillList, SkillPSWPartReset, );
    PATCH_MEMBER_INVOKE(int, CNSSkillList, SkillChange, unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSSkillList, SkillPointSetup, );
    PATCH_MEMBER_INVOKE(unsigned char, CNSSkillList, GetAttribSkill, );
    PATCH_MEMBER_INVOKE(int, CNSSkillList, CheckCastTime, unsigned long);
    };*/
};


#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(CNSSkillList::Constructor(CNSCharacter *), 0x4D2690);
//DEFINE_NAKED_JMP(CNSSkillList::Destructor(), 0x4D2720);
DEFINE_NAKED_JMP(void CNSSkillList::SetParent(CNSCharacter *), 0x481CD0);
DEFINE_NAKED_JMP(unsigned long CNSSkillList::GetCount(), 0x48FAB0);
DEFINE_NAKED_JMP(unsigned long CNSSkillList::GetMaxList(), 0x4D7470);
DEFINE_NAKED_JMP(CNSSkill & CNSSkillList::GetSkill(int), 0x4D7480);
DEFINE_NAKED_JMP(void CNSSkillList::Clear(), 0x4D2790);
DEFINE_NAKED_JMP(CNSSkill * CNSSkillList::Add(unsigned short _COMMA unsigned char), 0x4D2AC0);
DEFINE_NAKED_JMP(CNSSkill * CNSSkillList::Add(unsigned short _COMMA unsigned char _COMMA unsigned char _COMMA unsigned char _COMMA unsigned short _COMMA unsigned char _COMMA unsigned char _COMMA unsigned short _COMMA unsigned char _COMMA unsigned short _COMMA unsigned char _COMMA unsigned short _COMMA unsigned char _COMMA unsigned short _COMMA unsigned short), 0x4D2940);
DEFINE_NAKED_JMP(CNSSkill * CNSSkillList::Add(unsigned char _COMMA unsigned char _COMMA unsigned short _COMMA unsigned char _COMMA unsigned short), 0x4D2800);
DEFINE_NAKED_JMP(CNSSkill * CNSSkillList::AddMachine(CNSEquipment::EQUIPMENTTYPE _COMMA unsigned short _COMMA unsigned char), 0x4D2BA0);
DEFINE_NAKED_JMP(void CNSSkillList::Delete(unsigned short), 0x4D2D10);
DEFINE_NAKED_JMP(CNSSkill * CNSSkillList::GetActiveSkill(), 0x402210);
DEFINE_NAKED_JMP(CNSSkill * CNSSkillList::Get(unsigned short), 0x4D2D70);
DEFINE_NAKED_JMP(unsigned char CNSSkillList::GetSkillLevel(unsigned short), 0x4D2750);
DEFINE_NAKED_JMP(int CNSSkillList::Study(unsigned short), 0x4D3FA0);
DEFINE_NAKED_JMP(void CNSSkillList::AutoExpUp(unsigned char), 0x4D4340);
DEFINE_NAKED_JMP(unsigned short CNSSkillList::GetRange(), 0x45A8A0);
DEFINE_NAKED_JMP(unsigned short CNSSkillList::GetSkillId(), 0x45A8E0);
DEFINE_NAKED_JMP(unsigned char CNSSkillList::GetSkillType(int), 0x494DD0);
DEFINE_NAKED_JMP(unsigned long CNSSkillList::GetSkillAttackSpeed(), 0x494E10);
DEFINE_NAKED_JMP(unsigned char CNSSkillList::GetCastTime(), 0x45A940);
DEFINE_NAKED_JMP(unsigned long CNSSkillList::GetTargetObjectId(), 0x423E70);
DEFINE_NAKED_JMP(int CNSSkillList::Target(unsigned short _COMMA unsigned long _COMMA unsigned long), 0x4D4400);
DEFINE_NAKED_JMP(int CNSSkillList::Cast(unsigned long _COMMA unsigned long &), 0x4D4790);
DEFINE_NAKED_JMP(int CNSSkillList::Use(unsigned long _COMMA unsigned long &), 0x4D4800);
DEFINE_NAKED_JMP(int CNSSkillList::DirectCast(unsigned short _COMMA unsigned long _COMMA unsigned long), 0x4D4970);
DEFINE_NAKED_JMP(void CNSSkillList::Cancel(int), 0x4D4A30);
DEFINE_NAKED_JMP(CNSSkillList::SKILLSTEP CNSSkillList::GetStep(), 0x45A970);
DEFINE_NAKED_JMP(int CNSSkillList::CheckTargetDead(CNSCharacter *), 0x4D49E0);
DEFINE_NAKED_JMP(int CNSSkillList::DBSkillListBuild(unsigned char _COMMA unsigned char), 0x4D2E00);
DEFINE_NAKED_JMP(int CNSSkillList::SkillDefaultList(), 0x4D3760);
DEFINE_NAKED_JMP(unsigned short CNSSkillList::SetRaceAbility(CNSPc *), 0x4D2F90);
DEFINE_NAKED_JMP(int CNSSkillList::IsActiveSkill(), 0x4831B0);
DEFINE_NAKED_JMP(void CNSSkillList::CheckSkillCancel(unsigned short), 0x4D4AE0);
DEFINE_NAKED_JMP(unsigned long CNSSkillList::GetOverHeat(CNSSkill * _COMMA unsigned long), 0x4D7600);
DEFINE_NAKED_JMP(unsigned long CNSSkillList::GetOverHeat(CNSEquipment::EQUIPMENTTYPE _COMMA unsigned long), 0x483240);
DEFINE_NAKED_JMP(void CNSSkillList::SetOverHeat(CNSSkill * _COMMA unsigned long), 0x4D7670);
DEFINE_NAKED_JMP(void CNSSkillList::SetCancel(), 0x4838A0);
DEFINE_NAKED_JMP(int CNSSkillList::PremiumSkillLevelUp(unsigned short _COMMA int _COMMA int), 0x4D4C80);
DEFINE_NAKED_JMP(int CNSSkillList::DebugSkillLevelUp(unsigned short), 0x4D4F10);
DEFINE_NAKED_JMP(int CNSSkillList::DebugSkillExp(unsigned short _COMMA unsigned short), 0x4D5040);
DEFINE_NAKED_JMP(void CNSSkillList::DebugSkillLevelUpAll(), 0x4D4FD0);
DEFINE_NAKED_JMP(void CNSSkillList::ClearCoolTime(), 0x4D5090);
DEFINE_NAKED_JMP(void CNSSkillList::AddSkillExpPoint(unsigned short _COMMA unsigned short), 0x4D5130);
DEFINE_NAKED_JMP(int CNSSkillList::SkillReset(unsigned char), 0x4D56D0);
DEFINE_NAKED_JMP(int CNSSkillList::SkillReset(unsigned short _COMMA int), 0x4D5180);
DEFINE_NAKED_JMP(int CNSSkillList::SkillPSWPartReset(), 0x4D5CB0);
DEFINE_NAKED_JMP(int CNSSkillList::SkillChange(unsigned short), 0x4D5A90);
DEFINE_NAKED_JMP(int CNSSkillList::SkillPointSetup(), 0x4D5DD0);
DEFINE_NAKED_JMP(unsigned char CNSSkillList::GetAttribSkill(), 0x4D5FC0);
DEFINE_NAKED_JMP(int CNSSkillList::CheckCastTime(unsigned long), 0x494E50);
#endif






#endif