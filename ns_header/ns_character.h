#ifndef NSHEADER_NS_CHARACTER_H_
#define NSHEADER_NS_CHARACTER_H_

#include "ns_header/ns_object.h"
#include "ns_header/ns_skill.h"
#include "ns_header/ns_inventory.h"
#include "ns_header/ns_buff.h"
#include "ns_header/ns_damage_counter.h"
#include "ns_header/ns_move_path.h"
#include "ns_header/ns_rand32.h"

class CNSVrBlockManager;
class CNSMapManager;

class CNSCharacter : public CNSObject {
public:
    static const unsigned int _size = 0x4430;

    enum STATETYPE {
        StateType_Stand = 0x0,
        StateType_Walk = 0x1,
        StateType_Run = 0x2,
        StateType_Sitdown = 0x3,
        StateType_Dead = 0x4,
    };

    unsigned char m_btLevel;//this+0x1C
    struct _BasicParam {
        static const unsigned int _size = 0xc;
        unsigned short btStr;//this+0x0
        unsigned short btCon;//this+0x2
        unsigned short btDex;//this+0x4
        unsigned short btInt;//this+0x6
        unsigned char btRs4[0x4];//this+0x8
    };

    struct CNSCharacter::_BasicParam m_BasicParam;//this+0x1E
    unsigned char m_btRealm;//this+0x2A
    unsigned short m_btStr;//this+0x2C
    unsigned short m_btCon;//this+0x2E
    unsigned short m_btDex;//this+0x30
    unsigned short m_btInt;//this+0x32
    unsigned char m_btRs4[0x4];//this+0x34
    unsigned short m_wAttackMinDamage;//this+0x38
    unsigned short m_wAttackMaxDamage;//this+0x3A
    unsigned char m_btAttackSpeed;//this+0x3C
    unsigned short m_wAttackDistance;//this+0x3E
    unsigned short m_wDefenseDamage;//this+0x40
    unsigned short m_wSight;//this+0x42
    unsigned char m_btMoveSpeed;//this+0x44
    unsigned long m_dwExp;//this+0x48
    unsigned short m_wNs;//this+0x4C
    unsigned char m_btSp;//this+0x4E
    unsigned short m_wAp;//this+0x50
    unsigned short m_wDp;//this+0x52
    unsigned short m_wMa;//this+0x54
    unsigned short m_wAr;//this+0x56
    unsigned short m_wRs;//this+0x58
    unsigned short m_wDr;//this+0x5A
    unsigned long m_dwMaxHp;//this+0x5C
    unsigned short m_wMaxSta;//this+0x60
    unsigned short m_wMaxMp;//this+0x62
    float m_fHp;//this+0x64
    float m_fSta;//this+0x68
    float m_fMp;//this+0x6C
    unsigned short m_wWpMa;//this+0x70
    unsigned char m_btDpPer;//this+0x72
    float m_fHpRegen;//this+0x74
    float m_fStaRegen;//this+0x78
    float m_fMpRegen;//this+0x7C
    float m_fMoveSpeed;//this+0x80
    unsigned long m_dwGold;//this+0x84
    unsigned long m_dwTargetObjectId;//this+0x88
    class NSPOINT2 m_cellMoveStart;//this+0x8C
    class NSPOINT2 m_cellMoveEnd;//this+0x90
    float m_fMoveLength;//this+0x94
    class CNSSkillList m_SkillList;//this+0x98
    class CNSInventory m_Inven;//this+0x28D8
    class CNSBuffList m_BuffList;//this+0x2A70
    class CNSDamageCounter m_DamageCounter;//this+0x3544
    class CNSMovePath m_MovePath;//this+0x39E0
    CNSCharacter(const CNSCharacter &);
    CNSCharacter();    PATCH_MEMBER(CNSCharacter &, Constructor, , 0x4243A0);
    virtual ~CNSCharacter();    PATCH_MEMBER(void, Destructor, , 0x424510);
    virtual void OnEnter();    PATCH_MEMBER(void, OnEnter, , 0x424660);
    virtual void OnLeave();    PATCH_MEMBER(void, OnLeave, , 0x424690);
    virtual void OnBuff(unsigned long, int);    PATCH_MEMBER(void, OnBuff, unsigned long _COMMA int, 0x426AA0);
    virtual void OnAction(unsigned long);    PATCH_MEMBER(void, OnAction, unsigned long, 0x426AE0);
    virtual void OnHitLastDamage(CNSCharacter *);    PATCH_MEMBER(void, OnHitLastDamage, CNSCharacter *, 0x426AB0);
    virtual void Init();    PATCH_MEMBER(void, Init, , 0x4245B0);
    virtual void Reset();    PATCH_MEMBER(void, Reset, , 0x424750);
    virtual void Reset2();    PATCH_MEMBER(void, Reset2, , 0x4247C0);
    virtual void Reset3(int);    PATCH_MEMBER(void, Reset3, int, 0x424E90);
    virtual void ItemDrop(CNSCharacter *);    PATCH_MEMBER(void, ItemDrop, CNSCharacter *, 0x426AB0);
    virtual void Stop(unsigned long);    PATCH_MEMBER(void, Stop, unsigned long, 0x426AB0);
    int CheckPVPZone(CNSCharacter *, int);    PATCH_MEMBER(int, CheckPVPZone, CNSCharacter * _COMMA int, 0x44C0C0);
    int IsHide();    PATCH_MEMBER(int, IsHide, , 0x4246D0);
    unsigned char GetRealm();    PATCH_MEMBER(unsigned char, GetRealm, , 0x423DF0);
    void SetRealm(unsigned char);    PATCH_MEMBER(void, SetRealm, unsigned char, 0x450370);
    unsigned long GetRand32();    PATCH_MEMBER(unsigned long, GetRand32, , 0x43EF40);
    int CalcHitRate(CNSCharacter *);    PATCH_MEMBER(int, CalcHitRate, CNSCharacter *, 0x44C320);
    int CalcWeaponPoint(int);    PATCH_MEMBER(int, CalcWeaponPoint, int, 0x425CF0);
    unsigned short CalcExpPoint(unsigned long);    PATCH_MEMBER(unsigned short, CalcExpPoint, unsigned long, 0x425E80);
    unsigned char GetHpPercent();    PATCH_MEMBER(unsigned char, GetHpPercent, , 0x4270D0);
    unsigned char GetMpPercent();    PATCH_MEMBER(unsigned char, GetMpPercent, , 0x482950);
    unsigned char GetStaPercent();    PATCH_MEMBER(unsigned char, GetStaPercent, , 0x44C710);
    virtual unsigned short HitDamage(CNSCharacter *, unsigned short, CNSObject::HITTYPE, int);    PATCH_MEMBER(unsigned short, HitDamage, CNSCharacter * _COMMA unsigned short _COMMA CNSObject::HITTYPE _COMMA int, 0x424FF0);
    unsigned short HitHeal(CNSCharacter *, unsigned short, int, int);    PATCH_MEMBER(unsigned short, HitHeal, CNSCharacter * _COMMA unsigned short _COMMA int _COMMA int, 0x423C70);
    unsigned short GetDefenseDamage();    PATCH_MEMBER(unsigned short, GetDefenseDamage, , 0x44C390);
    unsigned short GetMagicDefenseDamage();    PATCH_MEMBER(unsigned short, GetMagicDefenseDamage, , 0x4D7360);
    int CheckFriendly(CNSCharacter *);    PATCH_MEMBER(int, CheckFriendly, CNSCharacter *, 0x44AC20);
    void AddBattleBuff(CNSCharacter *);    PATCH_MEMBER(void, AddBattleBuff, CNSCharacter *, 0x4275A0);
    virtual unsigned short UseHp(unsigned short);    PATCH_MEMBER(unsigned short, UseHp, unsigned short, 0x426B20);
    virtual unsigned short UseMp(unsigned short);    PATCH_MEMBER(unsigned short, UseMp, unsigned short, 0x426BB0);
    virtual unsigned short UseSta(unsigned short);    PATCH_MEMBER(unsigned short, UseSta, unsigned short, 0x426C40);
    virtual unsigned short UseNs(unsigned short, int);    PATCH_MEMBER(unsigned short, UseNs, unsigned short _COMMA int, 0x426CD0);
    unsigned char GetLevel();    PATCH_MEMBER(unsigned char, GetLevel, , 0x42B9D0);
    float GetHp();    PATCH_MEMBER(float, GetHp, , 0x484970);
    float GetMp();    PATCH_MEMBER(float, GetMp, , 0x4D6FD0);
    float GetSta();    PATCH_MEMBER(float, GetSta, , 0x483080);
    virtual unsigned short GetNs();    PATCH_MEMBER(unsigned short, GetNs, , 0x426AC0);
    unsigned short GetAttackDistance();    PATCH_MEMBER(unsigned short, GetAttackDistance, , 0x4D7300);
    unsigned long GetGold();    PATCH_MEMBER(unsigned long, GetGold, , 0x419CD0);
    unsigned long GetExp();    PATCH_MEMBER(unsigned long, GetExp, , 0x4591C0);
    int GiveGold(unsigned long);    PATCH_MEMBER(int, GiveGold, unsigned long, 0x419CF0);
    void DecGold(unsigned long);    PATCH_MEMBER(void, DecGold, unsigned long, 0x419D90);
    void IncGold(unsigned long);    PATCH_MEMBER(void, IncGold, unsigned long, 0x43ED50);
    CNSCharacter::STATETYPE GetState();    PATCH_MEMBER(CNSCharacter::STATETYPE, GetState, , 0x427330);
    void SetState(CNSCharacter::STATETYPE);    PATCH_MEMBER(void, SetState, CNSCharacter::STATETYPE, 0x44C6B0);
    void SetMoveSpeed(unsigned char);    PATCH_MEMBER(void, SetMoveSpeed, unsigned char, 0x426EC0);
    unsigned short GetMoveSpeed();    PATCH_MEMBER(unsigned short, GetMoveSpeed, , 0x44C6D0);
    float GetMoveSpeedF();    PATCH_MEMBER(float, GetMoveSpeedF, , 0x4272D0);
    unsigned long GetTargetObjectId();    PATCH_MEMBER(unsigned long, GetTargetObjectId, , 0x44C290);
    virtual void SetTargetObjectId(unsigned long);    PATCH_MEMBER(void, SetTargetObjectId, unsigned long, 0x426B00);
    CNSCharacter * GetTargetObject();    PATCH_MEMBER(CNSCharacter *, GetTargetObject, , 0x44C800);
    void MapUnset();    PATCH_MEMBER(void, MapUnset, , 0x424700);
    static int Recovery(float &, unsigned long, float);    PATCH_STATIC(int, Recovery, float & _COMMA unsigned long _COMMA float, 0x426FE0);
    int RecoveryHp(float);    PATCH_MEMBER(int, RecoveryHp, float, 0x426F90);
    int RecoveryMp(float);    PATCH_MEMBER(int, RecoveryMp, float, 0x427070);
    int RecoverySta(float);    PATCH_MEMBER(int, RecoverySta, float, 0x4270A0);
    int RecoveryAll(float);    PATCH_MEMBER(int, RecoveryAll, float, 0x425F00);
    int IsFinish(unsigned long);    PATCH_MEMBER(int, IsFinish, unsigned long, 0x4273D0);
    unsigned long GetFinishTime();    PATCH_MEMBER(unsigned long, GetFinishTime, , 0x458C50);
    unsigned long GetLastActionTime();    PATCH_MEMBER(unsigned long, GetLastActionTime, , 0x4D7430);
    void SetFinishTime(unsigned long);    PATCH_MEMBER(void, SetFinishTime, unsigned long, 0x44A880);
    unsigned long GetStartSecond();    PATCH_MEMBER(unsigned long, GetStartSecond, , 0x4B09F0);
    int IsDead();    PATCH_MEMBER(int, IsDead, , 0x423940);
    int IsClarity(CNSCharacter *);    PATCH_MEMBER(int, IsClarity, CNSCharacter *, 0x484180);
    int IsTooFarTarget(CNSCharacter *, float);    PATCH_MEMBER(int, IsTooFarTarget, CNSCharacter * _COMMA float, 0x44ABC0);
    int IsSafeZone();    PATCH_MEMBER(int, IsSafeZone, , 0x44ADF0);
    int IsEventZone();    PATCH_MEMBER(int, IsEventZone, , 0x44C060);
    int IsTutorialZone();    PATCH_MEMBER(int, IsTutorialZone, , 0x428680);
    int IsSemiBattleZone();    PATCH_MEMBER(int, IsSemiBattleZone, , 0x427680);
    int IsRealmBattleZone(int);    PATCH_MEMBER(int, IsRealmBattleZone, int, 0x4287C0);
    int IsOneVsOneZone();    PATCH_MEMBER(int, IsOneVsOneZone, , 0x482620);
    int IsPVPZone();    PATCH_MEMBER(int, IsPVPZone, , 0x429800);
    int IsPVPTournamentZone();    PATCH_MEMBER(int, IsPVPTournamentZone, , 0x429A60);
    int IsNotPcShop();    PATCH_MEMBER(int, IsNotPcShop, , 0x4C84E0);
    int IsRearLand();    PATCH_MEMBER(int, IsRearLand, , 0x429650);
    int IsNewRearLand();    PATCH_MEMBER(int, IsNewRearLand, , 0x482AC0);
    int IsTownZone();    PATCH_MEMBER(int, IsTownZone, , 0x483330);
    int IsRVRZone();    PATCH_MEMBER(int, IsRVRZone, , 0x43ED80);
    int IsMiniRVRZone(NSPOINT2 &);    PATCH_MEMBER(int, IsMiniRVRZone, NSPOINT2 &, 0x44C160);
    static int IsNotTransfer(unsigned char, unsigned char, NSPOINT2 &);    PATCH_STATIC(int, IsNotTransfer, unsigned char _COMMA unsigned char _COMMA NSPOINT2 &, 0x483960);
    int IsNotTransfer();    PATCH_MEMBER(int, IsNotTransfer, , 0x4838C0);
    int IsNeutralZone();    PATCH_MEMBER(int, IsNeutralZone, , 0x44B930);
    int IsRegionRVRQuestZone();    PATCH_MEMBER(int, IsRegionRVRQuestZone, , 0x483D80);
    int IsGuildAgit();    PATCH_MEMBER(int, IsGuildAgit, , 0x482680);
    int IsUnderworldBossZone();    PATCH_MEMBER(int, IsUnderworldBossZone, , 0x4844A0);
    int IsColosseumZone();    PATCH_MEMBER(int, IsColosseumZone, , 0x483E30);
    unsigned short GetAngle();    PATCH_MEMBER(unsigned short, GetAngle, , 0x44A9B0);
    NSPOINT2 GetCellStop();    PATCH_MEMBER(NSPOINT2, GetCellStop, , 0x484A50);
    NSPOINT2 GetCurrentCell(unsigned long);    PATCH_MEMBER(NSPOINT2, GetCurrentCell, unsigned long, 0x427400);
    NSPOINT2 GetTargetDestination(NSPOINT2 &, NSPOINT2 &, unsigned short);    PATCH_MEMBER(NSPOINT2, GetTargetDestination, NSPOINT2 & _COMMA NSPOINT2 & _COMMA unsigned short, 0x4265A0);
    void ResetMove(NSPOINT2 &, unsigned long);    PATCH_MEMBER(void, ResetMove, NSPOINT2 & _COMMA unsigned long, 0x4840D0);
    unsigned short GetTargetLength(CNSObject *);    PATCH_MEMBER(unsigned short, GetTargetLength, CNSObject *, 0x423980);
    unsigned short GetTargetBasicDistance(CNSObject *);    PATCH_MEMBER(unsigned short, GetTargetBasicDistance, CNSObject *, 0x45A990);
    unsigned short GetTargetAttackDistance(CNSObject *);    PATCH_MEMBER(unsigned short, GetTargetAttackDistance, CNSObject *, 0x458C70);
    unsigned long SetDestination(NSPOINT2 &, unsigned long);    PATCH_MEMBER(unsigned long, SetDestination, NSPOINT2 & _COMMA unsigned long, 0x4266C0);
    unsigned long MoveCharacter(NSPOINT2 &, unsigned long);    PATCH_MEMBER(unsigned long, MoveCharacter, NSPOINT2 & _COMMA unsigned long, 0x44A6A0);
    CNSVrBlockManager * GetVrMap();    PATCH_MEMBER(CNSVrBlockManager *, GetVrMap, , 0x423E10);
    CNSMapManager * GetMap();    PATCH_MEMBER(CNSMapManager *, GetMap, , 0x426E40);
    void Broadcast(CPacket &, int, unsigned short);    PATCH_MEMBER(void, Broadcast, CPacket & _COMMA int _COMMA unsigned short, 0x426010);
    void SendSkillUseMessage(unsigned long, unsigned short, unsigned char, unsigned char, unsigned short, unsigned char);    PATCH_MEMBER(void, SendSkillUseMessage, unsigned long _COMMA unsigned short _COMMA unsigned char _COMMA unsigned char _COMMA unsigned short _COMMA unsigned char, 0x4260E0);
    void SendDOTMessage(unsigned long, unsigned short, unsigned short);    PATCH_MEMBER(void, SendDOTMessage, unsigned long _COMMA unsigned short _COMMA unsigned short, 0x4261D0);
    void SendSkillCastMessage(unsigned long, unsigned short, unsigned char, int);    PATCH_MEMBER(void, SendSkillCastMessage, unsigned long _COMMA unsigned short _COMMA unsigned char _COMMA int, 0x4262B0);
    void SendSkillCancelMessage();    PATCH_MEMBER(void, SendSkillCancelMessage, , 0x426410);
    void SendStatusChangeMessage(unsigned char, unsigned short);    PATCH_MEMBER(void, SendStatusChangeMessage, unsigned char _COMMA unsigned short, 0x426380);
    void SendSystemMessageBroadcast(int, ...);    PATCH_MEMBER(void, SendSystemMessageBroadcast, int _COMMA ..., 0x426490);
    virtual void SendRecoveryMessage(int, int);
    virtual void SendEnterMessage(int);
    virtual void SendMoveMessage(unsigned long, int);
    virtual void SendLeaveMessage();
    int CalcSkillCancel(unsigned short);    PATCH_MEMBER(int, CalcSkillCancel, unsigned short, 0x4D76F0);
    int MoveTo(NSPOINT2 &);    PATCH_MEMBER(int, MoveTo, NSPOINT2 &, 0x425FE0);
    virtual void OnMove(unsigned long);    PATCH_MEMBER(void, OnMove, unsigned long, 0x4267E0);
    void _OnStop(unsigned long);    PATCH_MEMBER(void, _OnStop, unsigned long, 0x426DC0);
    virtual void OnStart(unsigned long);    PATCH_MEMBER(void, OnStart, unsigned long, 0x426D70);
    virtual void OnStop(unsigned long);    PATCH_MEMBER(void, OnStop, unsigned long, 0x426DA0);
    int CheckSeeTarget(NSPOINT2 &, int);    PATCH_MEMBER(int, CheckSeeTarget, NSPOINT2 & _COMMA int, 0x426890);
    void SetInstantKey(unsigned long);    PATCH_MEMBER(void, SetInstantKey, unsigned long, 0x450300);
    unsigned long GetInstantKey();    PATCH_MEMBER(unsigned long, GetInstantKey, , 0x4502A0);
    void CheckBattleMode(CNSCharacter *);    PATCH_MEMBER(void, CheckBattleMode, CNSCharacter *, 0x4268C0);
    unsigned long m_dwInstantKey;//this+0x3A3C
    enum CNSCharacter::STATETYPE m_state;//this+0x3A40
    unsigned short m_wAngle;//this+0x3A44
    unsigned long m_dwFinishTime;//this+0x3A48
    unsigned long m_dwItemDropTime;//this+0x3A4C
    unsigned long m_dwLastActionTime;//this+0x3A50
    unsigned long m_dwStartTime;//this+0x3A54
    int m_bStopped;//this+0x3A58
    class NSPOINT2 m_cellStop;//this+0x3A5C
    int m_bCheckEnter;//this+0x3A60
    int m_bCheckRecovery;//this+0x3A64
    int m_bCheckMove;//this+0x3A68
    class CRand32 m_Rand;//this+0x3A6C
    CNSCharacter & operator=(const CNSCharacter &);
    //void __local_vftable_ctor_closure();
    //virtual void * __vecDelDtor(unsigned int);

    /*struct _Invoke {
    PATCH_MEMBER_INVOKE(CNSCharacter &, CNSCharacter, Constructor, );
    PATCH_MEMBER_INVOKE(void, CNSCharacter, Destructor, );
    PATCH_MEMBER_INVOKE(void, CNSCharacter, OnEnter, );
    PATCH_MEMBER_INVOKE(void, CNSCharacter, OnLeave, );
    PATCH_MEMBER_INVOKE(void, CNSCharacter, OnBuff, unsigned long _COMMA int);
    PATCH_MEMBER_INVOKE(void, CNSCharacter, OnAction, unsigned long);
    PATCH_MEMBER_INVOKE(void, CNSCharacter, OnHitLastDamage, CNSCharacter *);
    PATCH_MEMBER_INVOKE(void, CNSCharacter, Init, );
    PATCH_MEMBER_INVOKE(void, CNSCharacter, Reset, );
    PATCH_MEMBER_INVOKE(void, CNSCharacter, Reset2, );
    PATCH_MEMBER_INVOKE(void, CNSCharacter, Reset3, int);
    PATCH_MEMBER_INVOKE(void, CNSCharacter, ItemDrop, CNSCharacter *);
    PATCH_MEMBER_INVOKE(void, CNSCharacter, Stop, unsigned long);
    PATCH_MEMBER_INVOKE(int, CNSCharacter, CheckPVPZone, CNSCharacter * _COMMA int);
    PATCH_MEMBER_INVOKE(int, CNSCharacter, IsHide, );
    PATCH_MEMBER_INVOKE(unsigned char, CNSCharacter, GetRealm, );
    PATCH_MEMBER_INVOKE(void, CNSCharacter, SetRealm, unsigned char);
    PATCH_MEMBER_INVOKE(unsigned long, CNSCharacter, GetRand32, );
    PATCH_MEMBER_INVOKE(int, CNSCharacter, CalcHitRate, CNSCharacter *);
    PATCH_MEMBER_INVOKE(int, CNSCharacter, CalcWeaponPoint, int);
    PATCH_MEMBER_INVOKE(unsigned short, CNSCharacter, CalcExpPoint, unsigned long);
    PATCH_MEMBER_INVOKE(unsigned char, CNSCharacter, GetHpPercent, );
    PATCH_MEMBER_INVOKE(unsigned char, CNSCharacter, GetMpPercent, );
    PATCH_MEMBER_INVOKE(unsigned char, CNSCharacter, GetStaPercent, );
    PATCH_MEMBER_INVOKE(unsigned short, CNSCharacter, HitDamage, CNSCharacter * _COMMA unsigned short _COMMA CNSObject::HITTYPE _COMMA int);
    PATCH_MEMBER_INVOKE(unsigned short, CNSCharacter, HitHeal, CNSCharacter * _COMMA unsigned short _COMMA int _COMMA int);
    PATCH_MEMBER_INVOKE(unsigned short, CNSCharacter, GetDefenseDamage, );
    PATCH_MEMBER_INVOKE(unsigned short, CNSCharacter, GetMagicDefenseDamage, );
    PATCH_MEMBER_INVOKE(int, CNSCharacter, CheckFriendly, CNSCharacter *);
    PATCH_MEMBER_INVOKE(void, CNSCharacter, AddBattleBuff, CNSCharacter *);
    PATCH_MEMBER_INVOKE(unsigned short, CNSCharacter, UseHp, unsigned short);
    PATCH_MEMBER_INVOKE(unsigned short, CNSCharacter, UseMp, unsigned short);
    PATCH_MEMBER_INVOKE(unsigned short, CNSCharacter, UseSta, unsigned short);
    PATCH_MEMBER_INVOKE(unsigned short, CNSCharacter, UseNs, unsigned short _COMMA int);
    PATCH_MEMBER_INVOKE(unsigned char, CNSCharacter, GetLevel, );
    PATCH_MEMBER_INVOKE(float, CNSCharacter, GetHp, );
    PATCH_MEMBER_INVOKE(float, CNSCharacter, GetMp, );
    PATCH_MEMBER_INVOKE(float, CNSCharacter, GetSta, );
    PATCH_MEMBER_INVOKE(unsigned short, CNSCharacter, GetNs, );
    PATCH_MEMBER_INVOKE(unsigned short, CNSCharacter, GetAttackDistance, );
    PATCH_MEMBER_INVOKE(unsigned long, CNSCharacter, GetGold, );
    PATCH_MEMBER_INVOKE(unsigned long, CNSCharacter, GetExp, );
    PATCH_MEMBER_INVOKE(int, CNSCharacter, GiveGold, unsigned long);
    PATCH_MEMBER_INVOKE(void, CNSCharacter, DecGold, unsigned long);
    PATCH_MEMBER_INVOKE(void, CNSCharacter, IncGold, unsigned long);
    PATCH_MEMBER_INVOKE(CNSCharacter::STATETYPE, CNSCharacter, GetState, );
    PATCH_MEMBER_INVOKE(void, CNSCharacter, SetState, CNSCharacter::STATETYPE);
    PATCH_MEMBER_INVOKE(void, CNSCharacter, SetMoveSpeed, unsigned char);
    PATCH_MEMBER_INVOKE(unsigned short, CNSCharacter, GetMoveSpeed, );
    PATCH_MEMBER_INVOKE(float, CNSCharacter, GetMoveSpeedF, );
    PATCH_MEMBER_INVOKE(unsigned long, CNSCharacter, GetTargetObjectId, );
    PATCH_MEMBER_INVOKE(void, CNSCharacter, SetTargetObjectId, unsigned long);
    PATCH_MEMBER_INVOKE(CNSCharacter *, CNSCharacter, GetTargetObject, );
    PATCH_MEMBER_INVOKE(void, CNSCharacter, MapUnset, );
    PATCH_STATIC_INVOKE(int, Recovery, float & _COMMA unsigned long _COMMA float);
    PATCH_MEMBER_INVOKE(int, CNSCharacter, RecoveryHp, float);
    PATCH_MEMBER_INVOKE(int, CNSCharacter, RecoveryMp, float);
    PATCH_MEMBER_INVOKE(int, CNSCharacter, RecoverySta, float);
    PATCH_MEMBER_INVOKE(int, CNSCharacter, RecoveryAll, float);
    PATCH_MEMBER_INVOKE(int, CNSCharacter, IsFinish, unsigned long);
    PATCH_MEMBER_INVOKE(unsigned long, CNSCharacter, GetFinishTime, );
    PATCH_MEMBER_INVOKE(unsigned long, CNSCharacter, GetLastActionTime, );
    PATCH_MEMBER_INVOKE(void, CNSCharacter, SetFinishTime, unsigned long);
    PATCH_MEMBER_INVOKE(unsigned long, CNSCharacter, GetStartSecond, );
    PATCH_MEMBER_INVOKE(int, CNSCharacter, IsDead, );
    PATCH_MEMBER_INVOKE(int, CNSCharacter, IsClarity, CNSCharacter *);
    PATCH_MEMBER_INVOKE(int, CNSCharacter, IsTooFarTarget, CNSCharacter * _COMMA float);
    PATCH_MEMBER_INVOKE(int, CNSCharacter, IsSafeZone, );
    PATCH_MEMBER_INVOKE(int, CNSCharacter, IsEventZone, );
    PATCH_MEMBER_INVOKE(int, CNSCharacter, IsTutorialZone, );
    PATCH_MEMBER_INVOKE(int, CNSCharacter, IsSemiBattleZone, );
    PATCH_MEMBER_INVOKE(int, CNSCharacter, IsRealmBattleZone, int);
    PATCH_MEMBER_INVOKE(int, CNSCharacter, IsOneVsOneZone, );
    PATCH_MEMBER_INVOKE(int, CNSCharacter, IsPVPZone, );
    PATCH_MEMBER_INVOKE(int, CNSCharacter, IsPVPTournamentZone, );
    PATCH_MEMBER_INVOKE(int, CNSCharacter, IsNotPcShop, );
    PATCH_MEMBER_INVOKE(int, CNSCharacter, IsRearLand, );
    PATCH_MEMBER_INVOKE(int, CNSCharacter, IsNewRearLand, );
    PATCH_MEMBER_INVOKE(int, CNSCharacter, IsTownZone, );
    PATCH_MEMBER_INVOKE(int, CNSCharacter, IsRVRZone, );
    PATCH_MEMBER_INVOKE(int, CNSCharacter, IsMiniRVRZone, NSPOINT2 &);
    PATCH_STATIC_INVOKE(int, IsNotTransfer, unsigned char _COMMA unsigned char _COMMA NSPOINT2 &);
    PATCH_MEMBER_INVOKE(int, CNSCharacter, IsNotTransfer, );
    PATCH_MEMBER_INVOKE(int, CNSCharacter, IsNeutralZone, );
    PATCH_MEMBER_INVOKE(int, CNSCharacter, IsRegionRVRQuestZone, );
    PATCH_MEMBER_INVOKE(int, CNSCharacter, IsGuildAgit, );
    PATCH_MEMBER_INVOKE(int, CNSCharacter, IsUnderworldBossZone, );
    PATCH_MEMBER_INVOKE(int, CNSCharacter, IsColosseumZone, );
    PATCH_MEMBER_INVOKE(unsigned short, CNSCharacter, GetAngle, );
    PATCH_MEMBER_INVOKE(NSPOINT2, CNSCharacter, GetCellStop, );
    PATCH_MEMBER_INVOKE(NSPOINT2, CNSCharacter, GetCurrentCell, unsigned long);
    PATCH_MEMBER_INVOKE(NSPOINT2, CNSCharacter, GetTargetDestination, NSPOINT2 & _COMMA NSPOINT2 & _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(void, CNSCharacter, ResetMove, NSPOINT2 & _COMMA unsigned long);
    PATCH_MEMBER_INVOKE(unsigned short, CNSCharacter, GetTargetLength, CNSObject *);
    PATCH_MEMBER_INVOKE(unsigned short, CNSCharacter, GetTargetBasicDistance, CNSObject *);
    PATCH_MEMBER_INVOKE(unsigned short, CNSCharacter, GetTargetAttackDistance, CNSObject *);
    PATCH_MEMBER_INVOKE(unsigned long, CNSCharacter, SetDestination, NSPOINT2 & _COMMA unsigned long);
    PATCH_MEMBER_INVOKE(unsigned long, CNSCharacter, MoveCharacter, NSPOINT2 & _COMMA unsigned long);
    PATCH_MEMBER_INVOKE(CNSVrBlockManager *, CNSCharacter, GetVrMap, );
    PATCH_MEMBER_INVOKE(CNSMapManager *, CNSCharacter, GetMap, );
    PATCH_MEMBER_INVOKE(void, CNSCharacter, Broadcast, CPacket & _COMMA int _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(void, CNSCharacter, SendSkillUseMessage, unsigned long _COMMA unsigned short _COMMA unsigned char _COMMA unsigned char _COMMA unsigned short _COMMA unsigned char);
    PATCH_MEMBER_INVOKE(void, CNSCharacter, SendDOTMessage, unsigned long _COMMA unsigned short _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(void, CNSCharacter, SendSkillCastMessage, unsigned long _COMMA unsigned short _COMMA unsigned char _COMMA int);
    PATCH_MEMBER_INVOKE(void, CNSCharacter, SendSkillCancelMessage, );
    PATCH_MEMBER_INVOKE(void, CNSCharacter, SendStatusChangeMessage, unsigned char _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(void, CNSCharacter, SendSystemMessageBroadcast, int _COMMA ...);
    PATCH_MEMBER_INVOKE(int, CNSCharacter, CalcSkillCancel, unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSCharacter, MoveTo, NSPOINT2 &);
    PATCH_MEMBER_INVOKE(void, CNSCharacter, OnMove, unsigned long);
    PATCH_MEMBER_INVOKE(void, CNSCharacter, _OnStop, unsigned long);
    PATCH_MEMBER_INVOKE(void, CNSCharacter, OnStart, unsigned long);
    PATCH_MEMBER_INVOKE(void, CNSCharacter, OnStop, unsigned long);
    PATCH_MEMBER_INVOKE(int, CNSCharacter, CheckSeeTarget, NSPOINT2 & _COMMA int);
    PATCH_MEMBER_INVOKE(void, CNSCharacter, SetInstantKey, unsigned long);
    PATCH_MEMBER_INVOKE(unsigned long, CNSCharacter, GetInstantKey, );
    PATCH_MEMBER_INVOKE(void, CNSCharacter, CheckBattleMode, CNSCharacter *);
    };*/
};
#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(CNSCharacter::Constructor(), 0x4243A0);
//DEFINE_NAKED_JMP(CNSCharacter::Destructor(), 0x424510);
DEFINE_NAKED_JMP(void CNSCharacter::OnEnter(), 0x424660);
DEFINE_NAKED_JMP(void CNSCharacter::OnLeave(), 0x424690);
DEFINE_NAKED_JMP(void CNSCharacter::OnBuff(unsigned long _COMMA int), 0x426AA0);
DEFINE_NAKED_JMP(void CNSCharacter::OnAction(unsigned long), 0x426AE0);
DEFINE_NAKED_JMP(void CNSCharacter::OnHitLastDamage(CNSCharacter *), 0x426AB0);
DEFINE_NAKED_JMP(void CNSCharacter::Init(), 0x4245B0);
DEFINE_NAKED_JMP(void CNSCharacter::Reset(), 0x424750);
DEFINE_NAKED_JMP(void CNSCharacter::Reset2(), 0x4247C0);
DEFINE_NAKED_JMP(void CNSCharacter::Reset3(int), 0x424E90);
DEFINE_NAKED_JMP(void CNSCharacter::ItemDrop(CNSCharacter *), 0x426AB0);
DEFINE_NAKED_JMP(void CNSCharacter::Stop(unsigned long), 0x426AB0);
DEFINE_NAKED_JMP(int CNSCharacter::CheckPVPZone(CNSCharacter * _COMMA int), 0x44C0C0);
DEFINE_NAKED_JMP(int CNSCharacter::IsHide(), 0x4246D0);
DEFINE_NAKED_JMP(unsigned char CNSCharacter::GetRealm(), 0x423DF0);
DEFINE_NAKED_JMP(void CNSCharacter::SetRealm(unsigned char), 0x450370);
DEFINE_NAKED_JMP(unsigned long CNSCharacter::GetRand32(), 0x43EF40);
DEFINE_NAKED_JMP(int CNSCharacter::CalcHitRate(CNSCharacter *), 0x44C320);
DEFINE_NAKED_JMP(int CNSCharacter::CalcWeaponPoint(int), 0x425CF0);
DEFINE_NAKED_JMP(unsigned short CNSCharacter::CalcExpPoint(unsigned long), 0x425E80);
DEFINE_NAKED_JMP(unsigned char CNSCharacter::GetHpPercent(), 0x4270D0);
DEFINE_NAKED_JMP(unsigned char CNSCharacter::GetMpPercent(), 0x482950);
DEFINE_NAKED_JMP(unsigned char CNSCharacter::GetStaPercent(), 0x44C710);
DEFINE_NAKED_JMP(unsigned short CNSCharacter::HitDamage(CNSCharacter * _COMMA unsigned short _COMMA CNSObject::HITTYPE _COMMA int), 0x424FF0);
DEFINE_NAKED_JMP(unsigned short CNSCharacter::HitHeal(CNSCharacter * _COMMA unsigned short _COMMA int _COMMA int), 0x423C70);
DEFINE_NAKED_JMP(unsigned short CNSCharacter::GetDefenseDamage(), 0x44C390);
DEFINE_NAKED_JMP(unsigned short CNSCharacter::GetMagicDefenseDamage(), 0x4D7360);
DEFINE_NAKED_JMP(int CNSCharacter::CheckFriendly(CNSCharacter *), 0x44AC20);
DEFINE_NAKED_JMP(void CNSCharacter::AddBattleBuff(CNSCharacter *), 0x4275A0);
DEFINE_NAKED_JMP(unsigned short CNSCharacter::UseHp(unsigned short), 0x426B20);
DEFINE_NAKED_JMP(unsigned short CNSCharacter::UseMp(unsigned short), 0x426BB0);
DEFINE_NAKED_JMP(unsigned short CNSCharacter::UseSta(unsigned short), 0x426C40);
DEFINE_NAKED_JMP(unsigned short CNSCharacter::UseNs(unsigned short _COMMA int), 0x426CD0);
DEFINE_NAKED_JMP(unsigned char CNSCharacter::GetLevel(), 0x42B9D0);
DEFINE_NAKED_JMP(float CNSCharacter::GetHp(), 0x484970);
DEFINE_NAKED_JMP(float CNSCharacter::GetMp(), 0x4D6FD0);
DEFINE_NAKED_JMP(float CNSCharacter::GetSta(), 0x483080);
DEFINE_NAKED_JMP(unsigned short CNSCharacter::GetNs(), 0x426AC0);
DEFINE_NAKED_JMP(unsigned short CNSCharacter::GetAttackDistance(), 0x4D7300);
DEFINE_NAKED_JMP(unsigned long CNSCharacter::GetGold(), 0x419CD0);
DEFINE_NAKED_JMP(unsigned long CNSCharacter::GetExp(), 0x4591C0);
DEFINE_NAKED_JMP(int CNSCharacter::GiveGold(unsigned long), 0x419CF0);
DEFINE_NAKED_JMP(void CNSCharacter::DecGold(unsigned long), 0x419D90);
DEFINE_NAKED_JMP(void CNSCharacter::IncGold(unsigned long), 0x43ED50);
DEFINE_NAKED_JMP(CNSCharacter::STATETYPE CNSCharacter::GetState(), 0x427330);
DEFINE_NAKED_JMP(void CNSCharacter::SetState(CNSCharacter::STATETYPE), 0x44C6B0);
DEFINE_NAKED_JMP(void CNSCharacter::SetMoveSpeed(unsigned char), 0x426EC0);
DEFINE_NAKED_JMP(unsigned short CNSCharacter::GetMoveSpeed(), 0x44C6D0);
DEFINE_NAKED_JMP(float CNSCharacter::GetMoveSpeedF(), 0x4272D0);
DEFINE_NAKED_JMP(unsigned long CNSCharacter::GetTargetObjectId(), 0x44C290);
DEFINE_NAKED_JMP(void CNSCharacter::SetTargetObjectId(unsigned long), 0x426B00);
DEFINE_NAKED_JMP(CNSCharacter * CNSCharacter::GetTargetObject(), 0x44C800);
DEFINE_NAKED_JMP(void CNSCharacter::MapUnset(), 0x424700);
DEFINE_NAKED_JMP(int CNSCharacter::Recovery(float & _COMMA unsigned long _COMMA float), 0x426FE0);
DEFINE_NAKED_JMP(int CNSCharacter::RecoveryHp(float), 0x426F90);
DEFINE_NAKED_JMP(int CNSCharacter::RecoveryMp(float), 0x427070);
DEFINE_NAKED_JMP(int CNSCharacter::RecoverySta(float), 0x4270A0);
DEFINE_NAKED_JMP(int CNSCharacter::RecoveryAll(float), 0x425F00);
DEFINE_NAKED_JMP(int CNSCharacter::IsFinish(unsigned long), 0x4273D0);
DEFINE_NAKED_JMP(unsigned long CNSCharacter::GetFinishTime(), 0x458C50);
DEFINE_NAKED_JMP(unsigned long CNSCharacter::GetLastActionTime(), 0x4D7430);
DEFINE_NAKED_JMP(void CNSCharacter::SetFinishTime(unsigned long), 0x44A880);
DEFINE_NAKED_JMP(unsigned long CNSCharacter::GetStartSecond(), 0x4B09F0);
DEFINE_NAKED_JMP(int CNSCharacter::IsDead(), 0x423940);
DEFINE_NAKED_JMP(int CNSCharacter::IsClarity(CNSCharacter *), 0x484180);
DEFINE_NAKED_JMP(int CNSCharacter::IsTooFarTarget(CNSCharacter * _COMMA float), 0x44ABC0);
DEFINE_NAKED_JMP(int CNSCharacter::IsSafeZone(), 0x44ADF0);
DEFINE_NAKED_JMP(int CNSCharacter::IsEventZone(), 0x44C060);
DEFINE_NAKED_JMP(int CNSCharacter::IsTutorialZone(), 0x428680);
DEFINE_NAKED_JMP(int CNSCharacter::IsSemiBattleZone(), 0x427680);
DEFINE_NAKED_JMP(int CNSCharacter::IsRealmBattleZone(int), 0x4287C0);
DEFINE_NAKED_JMP(int CNSCharacter::IsOneVsOneZone(), 0x482620);
DEFINE_NAKED_JMP(int CNSCharacter::IsPVPZone(), 0x429800);
DEFINE_NAKED_JMP(int CNSCharacter::IsPVPTournamentZone(), 0x429A60);
DEFINE_NAKED_JMP(int CNSCharacter::IsNotPcShop(), 0x4C84E0);
DEFINE_NAKED_JMP(int CNSCharacter::IsRearLand(), 0x429650);
DEFINE_NAKED_JMP(int CNSCharacter::IsNewRearLand(), 0x482AC0);
DEFINE_NAKED_JMP(int CNSCharacter::IsTownZone(), 0x483330);
DEFINE_NAKED_JMP(int CNSCharacter::IsRVRZone(), 0x43ED80);
DEFINE_NAKED_JMP(int CNSCharacter::IsMiniRVRZone(NSPOINT2 &), 0x44C160);
DEFINE_NAKED_JMP(int CNSCharacter::IsNotTransfer(unsigned char _COMMA unsigned char _COMMA NSPOINT2 &), 0x483960);
DEFINE_NAKED_JMP(int CNSCharacter::IsNotTransfer(), 0x4838C0);
DEFINE_NAKED_JMP(int CNSCharacter::IsNeutralZone(), 0x44B930);
DEFINE_NAKED_JMP(int CNSCharacter::IsRegionRVRQuestZone(), 0x483D80);
DEFINE_NAKED_JMP(int CNSCharacter::IsGuildAgit(), 0x482680);
DEFINE_NAKED_JMP(int CNSCharacter::IsUnderworldBossZone(), 0x4844A0);
DEFINE_NAKED_JMP(int CNSCharacter::IsColosseumZone(), 0x483E30);
DEFINE_NAKED_JMP(unsigned short CNSCharacter::GetAngle(), 0x44A9B0);
DEFINE_NAKED_JMP(NSPOINT2 CNSCharacter::GetCellStop(), 0x484A50);
DEFINE_NAKED_JMP(NSPOINT2 CNSCharacter::GetCurrentCell(unsigned long), 0x427400);
DEFINE_NAKED_JMP(NSPOINT2 CNSCharacter::GetTargetDestination(NSPOINT2 & _COMMA NSPOINT2 & _COMMA unsigned short), 0x4265A0);
DEFINE_NAKED_JMP(void CNSCharacter::ResetMove(NSPOINT2 & _COMMA unsigned long), 0x4840D0);
DEFINE_NAKED_JMP(unsigned short CNSCharacter::GetTargetLength(CNSObject *), 0x423980);
DEFINE_NAKED_JMP(unsigned short CNSCharacter::GetTargetBasicDistance(CNSObject *), 0x45A990);
DEFINE_NAKED_JMP(unsigned short CNSCharacter::GetTargetAttackDistance(CNSObject *), 0x458C70);
DEFINE_NAKED_JMP(unsigned long CNSCharacter::SetDestination(NSPOINT2 & _COMMA unsigned long), 0x4266C0);
DEFINE_NAKED_JMP(unsigned long CNSCharacter::MoveCharacter(NSPOINT2 & _COMMA unsigned long), 0x44A6A0);
DEFINE_NAKED_JMP(CNSVrBlockManager * CNSCharacter::GetVrMap(), 0x423E10);
DEFINE_NAKED_JMP(CNSMapManager * CNSCharacter::GetMap(), 0x426E40);
DEFINE_NAKED_JMP(void CNSCharacter::Broadcast(CPacket & _COMMA int _COMMA unsigned short), 0x426010);
DEFINE_NAKED_JMP(void CNSCharacter::SendSkillUseMessage(unsigned long _COMMA unsigned short _COMMA unsigned char _COMMA unsigned char _COMMA unsigned short _COMMA unsigned char), 0x4260E0);
DEFINE_NAKED_JMP(void CNSCharacter::SendDOTMessage(unsigned long _COMMA unsigned short _COMMA unsigned short), 0x4261D0);
DEFINE_NAKED_JMP(void CNSCharacter::SendSkillCastMessage(unsigned long _COMMA unsigned short _COMMA unsigned char _COMMA int), 0x4262B0);
DEFINE_NAKED_JMP(void CNSCharacter::SendSkillCancelMessage(), 0x426410);
DEFINE_NAKED_JMP(void CNSCharacter::SendStatusChangeMessage(unsigned char _COMMA unsigned short), 0x426380);
DEFINE_NAKED_JMP(void CNSCharacter::SendSystemMessageBroadcast(int _COMMA ...), 0x426490);
DEFINE_NAKED_JMP(int CNSCharacter::CalcSkillCancel(unsigned short), 0x4D76F0);
DEFINE_NAKED_JMP(int CNSCharacter::MoveTo(NSPOINT2 &), 0x425FE0);
DEFINE_NAKED_JMP(void CNSCharacter::OnMove(unsigned long), 0x4267E0);
DEFINE_NAKED_JMP(void CNSCharacter::_OnStop(unsigned long), 0x426DC0);
DEFINE_NAKED_JMP(void CNSCharacter::OnStart(unsigned long), 0x426D70);
DEFINE_NAKED_JMP(void CNSCharacter::OnStop(unsigned long), 0x426DA0);
DEFINE_NAKED_JMP(int CNSCharacter::CheckSeeTarget(NSPOINT2 & _COMMA int), 0x426890);
DEFINE_NAKED_JMP(void CNSCharacter::SetInstantKey(unsigned long), 0x450300);
DEFINE_NAKED_JMP(unsigned long CNSCharacter::GetInstantKey(), 0x4502A0);
DEFINE_NAKED_JMP(void CNSCharacter::CheckBattleMode(CNSCharacter *), 0x4268C0);
#endif



#endif