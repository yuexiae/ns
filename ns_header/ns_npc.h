#ifndef NSHEADER_NS_NPC_H_
#define NSHEADER_NS_NPC_H_

#include "ns_header/ns_character.h"
#include "ns_header/ns_shop_inventory.h"
#include "ns_header/ns_npc_skill.h"
#include "ns_header/ns_npc_state.h"

class CFiniteStateMachine;


class CNSNpc : public CNSCharacter {
public:
    static const unsigned int _size = 0x4a64;

    enum STATETYPE {
        StateType_Stand = 0x0,
        StateType_Move = 0x1,
        StateType_Attack = 0x2,
        StateType_Runaway = 0x3,
        StateType_Return = 0x4,
        StateType_Dead = 0x5,
        StateType_Underground = 0x6,
        StateType_Skill = 0x7,
        StateType_End = 0x8,
    };

    enum EVENTTYPE {
        EventType_FindTarget = 0x0,
        EventType_LostTarget = 0x1,
        EventType_BeAttacked = 0x2,
        EventType_Tired = 0x3,
        EventType_StopWalk = 0x4,
        EventType_Patrol = 0x5,
        EventType_HealthDryUp = 0x6,
        EventType_TooFar = 0x7,
        EventType_Disappear = 0x8,
        EventType_Reborn = 0x9,
    };

    enum ATTACKTYPE {
        AttackType_Normal = 0x0,
        AttackType_Aggressive = 0x1,
        AttackType_Link = 0x2,
        AttackType_AggressiveLink = 0x3,
        AttackType_Dummy = 0x4,
        AttackType_Leader = 0x5,
        AttackType_AggressiveSplash = 0x6,
        AttackType_MobAttack = 0xA,
    };

    enum MOVETYPE {
        MoveType_Normal = 0x0,
        MoveType_Scarecrow = 0x1,
        MoveType_Fly = 0x2,
        MoveType_Ghost = 0x3,
        MoveType_Guard = 0x4,
    };

    enum NPCTYPE {
        NpcType_Mob = 0x1,
        NpcType_Npc = 0x2,
        NpcType_Merchant = 0x4,
    };

    enum PETSTATETYPE {
        PetStateType_Aggressive = 0x0,
        PetStateType_Defensive = 0x1,
        PetStateType_Stick = 0x2,
    };

    unsigned short m_wStartAngle;//this+0x4430
    unsigned short m_wNpcId;//this+0x4432
    char m_szNpcName[0x19];//this+0x4434
    unsigned char m_btNpcGroup;//this+0x444D
    unsigned char m_btAttackType;//this+0x444E
    unsigned char m_btMoveType;//this+0x444F
    unsigned char m_btSkillGroup;//this+0x4450
    unsigned long m_dwMaxHpBasic;//this+0x4454
    unsigned short m_wDefenseDamageBasic;//this+0x4458
    unsigned short m_wAttackMaxDamageBasic;//this+0x445A
    unsigned short m_wAttackMinDamageBasic;//this+0x445C
    class NSPOINT2 m_cellRespawn;//this+0x445E
    unsigned short m_wRespawnScope;//this+0x4462
    unsigned short m_wRespawnSecond;//this+0x4464
    unsigned long m_dwDisappearTime;//this+0x4468
    unsigned short m_wLimitMoveScope;//this+0x446C
    unsigned long m_dwSkillTargetObjectId;//this+0x4470
    unsigned long m_dwOldTargetObjectId;//this+0x4474
    unsigned long m_dwLeaderObjectId;//this+0x4478
    unsigned long m_dwOwnerObjectId;//this+0x447C
    class CNSShopInventory m_ShopInven;//this+0x4480
    class CNSNpcSkill m_NpcSkill;//this+0x44A4
    unsigned char m_btPetGrade;//this+0x44E0
    int m_bPetInfoAfterHide;//this+0x44E4
    unsigned long m_dwPetInfoTime;//this+0x44E8
    unsigned long m_dwScriptLastTime;//this+0x44EC
    char m_szScriptLastString[0x100];//this+0x44F0
    unsigned short m_wTargetNpcId;//this+0x45F0
    unsigned char m_btAttribute;//this+0x45F2
    unsigned char m_btAttributeLevel;//this+0x45F3
    CNSNpc(const CNSNpc &);
    CNSNpc();  CNSNpc& Constructor();   PATCH_MEMBER(CNSNpc &, Constructor, , 0x443B60);
    virtual ~CNSNpc();    PATCH_MEMBER(void, Destructor, , 0x443CE0);
    CNSNpc & operator=(CNSNpc &);    //PATCH_MEMBER(CNSNpc &, operator=, CNSNpc &, 0x451310);
    void Init(CFiniteStateMachine *, NSPOINT2 &, unsigned short);    PATCH_MEMBER(void, Init, CFiniteStateMachine * _COMMA NSPOINT2 & _COMMA unsigned short, 0x443E80);
    CNSObject::OBJECTTYPE GetNpcType();    PATCH_MEMBER(CNSObject::OBJECTTYPE, GetNpcType, , 0x44A2C0);
    void Reset(int);    PATCH_MEMBER(void, Reset, int, 0x444500);
    virtual void OnEnter();    PATCH_MEMBER(void, OnEnter, , 0x4447A0);
    virtual void OnLeave();    PATCH_MEMBER(void, OnLeave, , 0x444800);
    virtual void OnBuff(unsigned long, int);    PATCH_MEMBER(void, OnBuff, unsigned long _COMMA int, 0x444850);
    virtual void OnHitLastDamage(CNSCharacter *);    PATCH_MEMBER(void, OnHitLastDamage, CNSCharacter *, 0x444B10);
    virtual unsigned short HitDamage(CNSCharacter *, unsigned short, CNSObject::HITTYPE, int);    PATCH_MEMBER(unsigned short, HitDamage, CNSCharacter * _COMMA unsigned short _COMMA CNSObject::HITTYPE _COMMA int, 0x445540);
    void SetTargetNpcId(unsigned short);    PATCH_MEMBER(void, SetTargetNpcId, unsigned short, 0x4B07C0);
    virtual void OnStart(unsigned long);    PATCH_MEMBER(void, OnStart, unsigned long, 0x449A80);
    virtual void OnStop(unsigned long);    PATCH_MEMBER(void, OnStop, unsigned long, 0x449AC0);
    virtual void OnAction(unsigned long);    PATCH_MEMBER(void, OnAction, unsigned long, 0x4449C0);
    void OnHide(unsigned long);    PATCH_MEMBER(void, OnHide, unsigned long, 0x444A40);
    unsigned short PetUseSta(unsigned short);    PATCH_MEMBER(unsigned short, PetUseSta, unsigned short, 0x444AA0);
    virtual void Stop(unsigned long);    PATCH_MEMBER(void, Stop, unsigned long, 0x449D10);
    void Action(unsigned long, unsigned long);    PATCH_MEMBER(void, Action, unsigned long _COMMA unsigned long, 0x449D60);
    int IsAggrassive();    PATCH_MEMBER(int, IsAggrassive, , 0x459830);
    int IsLink();    PATCH_MEMBER(int, IsLink, , 0x44C2D0);
    int IsTooFar(CNSCharacter *);    PATCH_MEMBER(int, IsTooFar, CNSCharacter *, 0x445800);
    int IsDelete();    PATCH_MEMBER(int, IsDelete, , 0x4504B0);
    int IsMobAttack();    PATCH_MEMBER(int, IsMobAttack, , 0x44C220);
    int IsFriendlyMob();    PATCH_MEMBER(int, IsFriendlyMob, , 0x44A8C0);
    int IsPet();    PATCH_MEMBER(int, IsPet, , 0x44A8A0);
    int IsTameMob();    PATCH_MEMBER(int, IsTameMob, , 0x44AAB0);
    int IsSummon();    PATCH_MEMBER(int, IsSummon, , 0x44A560);
    int IsBomb();    PATCH_MEMBER(int, IsBomb, , 0x44A920);
    int IsBoss();    PATCH_MEMBER(int, IsBoss, , 0x4582C0);
    int IsBonusMob();    PATCH_MEMBER(int, IsBonusMob, , 0x44AAE0);
    int IsSummonMelee();    PATCH_MEMBER(int, IsSummonMelee, , 0x4D7110);
    int IsSummonRange();    PATCH_MEMBER(int, IsSummonRange, , 0x4D71A0);
    int IsSummonSaver();    PATCH_MEMBER(int, IsSummonSaver, , 0x4D7230);
    int IsBlock();    PATCH_MEMBER(int, IsBlock, , 0x44A3B0);
    int IsBlockDefense();    PATCH_MEMBER(int, IsBlockDefense, , 0x44A400);
    int IsBlockLarge();    PATCH_MEMBER(int, IsBlockLarge, , 0x44C240);
    int IsBlockMedium();    PATCH_MEMBER(int, IsBlockMedium, , 0x44A450);
    int IsBlockSmall();    PATCH_MEMBER(int, IsBlockSmall, , 0x44A4A0);
    int IsSiegeWeapon();
    int IsBlockSteamCore();    PATCH_MEMBER(int, IsBlockSteamCore, , 0x44A4F0);
    int CheckTarget(CNSCharacter *);    PATCH_MEMBER(int, CheckTarget, CNSCharacter *, 0x44AB30);
    void SetDelete();    PATCH_MEMBER(void, SetDelete, , 0x4502C0);
    void SetCellStart(NSPOINT2 &);    PATCH_MEMBER(void, SetCellStart, NSPOINT2 &, 0x458CB0);
    NSPOINT2 & GetCellStart();    PATCH_MEMBER(NSPOINT2 &, GetCellStart, , 0x459FC0);
    NSPOINT2 & GetCellRespawn();    PATCH_MEMBER(NSPOINT2 &, GetCellRespawn, , 0x458CD0);
    char * GetNpcName();    PATCH_MEMBER(char *, GetNpcName, , 0x44C7E0);
    void SetNpcName(char *);    PATCH_MEMBER(void, SetNpcName, char *, 0x4C7F70);
    unsigned short GetNpcId();    PATCH_MEMBER(unsigned short, GetNpcId, , 0x42B9F0);
    unsigned short GetStartAngle();    PATCH_MEMBER(unsigned short, GetStartAngle, , 0x450490);
    void ResetAngle();    PATCH_MEMBER(void, ResetAngle, , 0x44A540);
    int GetRespawnPos(NSPOINT2 &);    PATCH_MEMBER(int, GetRespawnPos, NSPOINT2 &, 0x4446B0);
    void SetRespawnInfo(NSPOINT2 &, unsigned short, unsigned short, unsigned short);    PATCH_MEMBER(void, SetRespawnInfo, NSPOINT2 & _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short, 0x450320);
    _NSRANGE GetLimitMoveRange();    PATCH_MEMBER(_NSRANGE, GetLimitMoveRange, , 0x444EC0);
    NSPOINT2 GetNewDestination(NSPOINT2 &);    PATCH_MEMBER(NSPOINT2, GetNewDestination, NSPOINT2 &, 0x444FA0);
    unsigned short GetRespawnSecond();    PATCH_MEMBER(unsigned short, GetRespawnSecond, , 0x45AE90);
    void SetRespawnSecond(unsigned short);    PATCH_MEMBER(void, SetRespawnSecond, unsigned short, 0x4503B0);
    void SetDisapper(unsigned short);    PATCH_MEMBER(void, SetDisapper, unsigned short, 0x4503F0);
    unsigned long GetLeaderObjectId();    PATCH_MEMBER(unsigned long, GetLeaderObjectId, , 0x485570);
    void SetLeaderObjectId(unsigned long);    PATCH_MEMBER(void, SetLeaderObjectId, unsigned long, 0x44C2B0);
    int GetLeaderDestination(NSPOINT2 &, int);    PATCH_MEMBER(int, GetLeaderDestination, NSPOINT2 & _COMMA int, 0x4451A0);
    int GetLeaderDestination2(NSPOINT2 &);    PATCH_MEMBER(int, GetLeaderDestination2, NSPOINT2 &, 0x445370);
    unsigned long GetOwnerObjectId();    PATCH_MEMBER(unsigned long, GetOwnerObjectId, , 0x43EE30);
    void SetOwnerObjectId(unsigned long);    PATCH_MEMBER(void, SetOwnerObjectId, unsigned long, 0x4503D0);
    virtual void SetTargetObjectId(unsigned long);    PATCH_MEMBER(void, SetTargetObjectId, unsigned long, 0x44A1E0);
    unsigned long GetLastSetTargetTime();    PATCH_MEMBER(unsigned long, GetLastSetTargetTime, , 0x459810);
    unsigned long FindTarget(int);    PATCH_MEMBER(unsigned long, FindTarget, int, 0x4458C0);
    unsigned long FindRandomTarget(unsigned long);    PATCH_MEMBER(unsigned long, FindRandomTarget, unsigned long, 0x4460C0);
    int CallFriend();    PATCH_MEMBER(int, CallFriend, , 0x4462C0);
    CNSCharacter * GetSkillTargetObject();    PATCH_MEMBER(CNSCharacter *, GetSkillTargetObject, , 0x45A9C0);
    void SetSkillTargetObjectId(unsigned long);
    void Attack(CNSCharacter *, unsigned long);    PATCH_MEMBER(void, Attack, CNSCharacter * _COMMA unsigned long, 0x4465E0);
    int SkillCast(unsigned short, unsigned long);    PATCH_MEMBER(int, SkillCast, unsigned short _COMMA unsigned long, 0x446C40);
    unsigned short AttackBlockMode(CNSCharacter *, unsigned short);    PATCH_MEMBER(unsigned short, AttackBlockMode, CNSCharacter * _COMMA unsigned short, 0x446B40);
    void Warp(unsigned short, unsigned short);    PATCH_MEMBER(void, Warp, unsigned short _COMMA unsigned short, 0x446D30);
    void WarpArea(unsigned short, unsigned short, unsigned short, unsigned short, unsigned short, unsigned short, unsigned char);    PATCH_MEMBER(void, WarpArea, unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char, 0x446DB0);
    unsigned long GetRectInPcCount(unsigned short, unsigned short, unsigned short, unsigned short, unsigned char);    PATCH_MEMBER(unsigned long, GetRectInPcCount, unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char, 0x446FC0);
    unsigned long GetRectInNpcCount(unsigned short, unsigned short, unsigned short, unsigned short, unsigned short);    PATCH_MEMBER(unsigned long, GetRectInNpcCount, unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short, 0x446ED0);
    unsigned long RectInDisappearNpc(unsigned short, unsigned short, unsigned short, unsigned short, unsigned short);    PATCH_MEMBER(unsigned long, RectInDisappearNpc, unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short, 0x4471E0);
    unsigned long HitRectInPcDebuff(int, unsigned char, unsigned char, unsigned short, unsigned short, unsigned short, unsigned short);    PATCH_MEMBER(unsigned long, HitRectInPcDebuff, int _COMMA unsigned char _COMMA unsigned char _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short, 0x4470C0);
    static int ItemDropTest(CNSCharacter *, unsigned short, unsigned long);    PATCH_STATIC(int, ItemDropTest, CNSCharacter * _COMMA unsigned short _COMMA unsigned long, 0x4472E0);
    virtual void ItemDrop(CNSCharacter *);    PATCH_MEMBER(void, ItemDrop, CNSCharacter *, 0x447530);
    int ItemCheckLootOwner(char *);    PATCH_MEMBER(int, ItemCheckLootOwner, char *, 0x447AC0);
    unsigned long ItemList(CPacket &);    PATCH_MEMBER(unsigned long, ItemList, CPacket &, 0x447B70);
    int ItemPick(CNSPc *, unsigned long);    PATCH_MEMBER(int, ItemPick, CNSPc * _COMMA unsigned long, 0x447BF0);
    int ShopItemSell(CNSPc *, unsigned long, unsigned char, unsigned long &);    PATCH_MEMBER(int, ShopItemSell, CNSPc * _COMMA unsigned long _COMMA unsigned char _COMMA unsigned long &, 0x447F90);
    int ShopItemCost(CNSPc *, unsigned long, unsigned char, unsigned long &);    PATCH_MEMBER(int, ShopItemCost, CNSPc * _COMMA unsigned long _COMMA unsigned char _COMMA unsigned long &, 0x4481F0);
    int ShopItemBuy(CNSPc *, unsigned long, unsigned char, unsigned long &);    PATCH_MEMBER(int, ShopItemBuy, CNSPc * _COMMA unsigned long _COMMA unsigned char _COMMA unsigned long &, 0x448290);
    void NpcScriptInit();    PATCH_MEMBER(void, NpcScriptInit, , 0x448440);
    int NpcScriptTalk(CNSPc *, char *, CPacket &);    PATCH_MEMBER(int, NpcScriptTalk, CNSPc * _COMMA char * _COMMA CPacket &, 0x4484E0);
    int NpcScriptIdle(CNSPc *);    PATCH_MEMBER(int, NpcScriptIdle, CNSPc *, 0x448800);
    int NpcScriptDead(CNSPc *);    PATCH_MEMBER(int, NpcScriptDead, CNSPc *, 0x448960);
    int NpcScriptQuestCheck(CNSPc *);    PATCH_MEMBER(int, NpcScriptQuestCheck, CNSPc *, 0x448AC0);
    void Reborn();    PATCH_MEMBER(void, Reborn, , 0x4443F0);
    void PacketEnterMessage(CPacket &);    PATCH_MEMBER(void, PacketEnterMessage, CPacket &, 0x448EF0);
    void PacketItemListMessage(CPacket &);    PATCH_MEMBER(void, PacketItemListMessage, CPacket &, 0x449200);
    void PacketShopItemListMessage(CNSPc *, CPacket &);    PATCH_MEMBER(void, PacketShopItemListMessage, CNSPc * _COMMA CPacket &, 0x4492A0);
    void PacketStatusMessage(CPacket &);    PATCH_MEMBER(void, PacketStatusMessage, CPacket &, 0x4499A0);
    virtual void SendEnterMessage(int);    PATCH_MEMBER(void, SendEnterMessage, int, 0x449350);
    virtual void SendMoveMessage(unsigned long, int);    PATCH_MEMBER(void, SendMoveMessage, unsigned long _COMMA int, 0x4493D0);
    virtual void SendRecoveryMessage(int, int);    PATCH_MEMBER(void, SendRecoveryMessage, int _COMMA int, 0x449750);
    void SendAttackMessage(unsigned long, unsigned char, unsigned short, unsigned char, unsigned long);    PATCH_MEMBER(void, SendAttackMessage, unsigned long _COMMA unsigned char _COMMA unsigned short _COMMA unsigned char _COMMA unsigned long, 0x449530);
    void SendItemListMessage();
    virtual void SendLeaveMessage();    PATCH_MEMBER(void, SendLeaveMessage, , 0x4496D0);
    void SendDeadMessage();    PATCH_MEMBER(void, SendDeadMessage, , 0x449650);
    void SendPetRecoveryMessage(unsigned short);    PATCH_MEMBER(void, SendPetRecoveryMessage, unsigned short, 0x449820);
    void SendChatMessage(unsigned char, char *);    PATCH_MEMBER(void, SendChatMessage, unsigned char _COMMA char *, 0x4498E0);
    void SendDelayedMessage();    PATCH_MEMBER(void, SendDelayedMessage, , 0x44C850);
    unsigned long GetCurrentState();    PATCH_MEMBER(unsigned long, GetCurrentState, , 0x448D10);
    void SetTransition(unsigned long);    PATCH_MEMBER(void, SetTransition, unsigned long, 0x448E30);
    void StateTransition(unsigned long);    PATCH_MEMBER(void, StateTransition, unsigned long, 0x448E90);
    unsigned long GetOldState();
    void ChangeCharacterState(unsigned long);    PATCH_MEMBER(void, ChangeCharacterState, unsigned long, 0x448D30);
    void PetInit(CNSCharacter *, char *, unsigned short, unsigned short);    PATCH_MEMBER(void, PetInit, CNSCharacter * _COMMA char * _COMMA unsigned short _COMMA unsigned short, 0x4830A0);
    void PetInit(CNSCharacter *);    PATCH_MEMBER(void, PetInit, CNSCharacter *, 0x483150);
    void PetStateChange(CNSNpc::PETSTATETYPE);    PATCH_MEMBER(void, PetStateChange, CNSNpc::PETSTATETYPE, 0x4831D0);
    unsigned char PetGetState();    PATCH_MEMBER(unsigned char, PetGetState, , 0x4D7410);
    void PetSetTargetObjectId(unsigned long);    PATCH_MEMBER(void, PetSetTargetObjectId, unsigned long, 0x4822A0);
    void PetDelete();    PATCH_MEMBER(void, PetDelete, , 0x4591E0);
    int PetCheckSkillUse(int);    PATCH_MEMBER(int, PetCheckSkillUse, int, 0x4D7320);
    void PetMessageStart(unsigned long, unsigned long);    PATCH_MEMBER(void, PetMessageStart, unsigned long _COMMA unsigned long, 0x482900);
    unsigned char PetGetGrade();    PATCH_MEMBER(unsigned char, PetGetGrade, , 0x4582A0);
    void PetSetGrade(unsigned char);    PATCH_MEMBER(void, PetSetGrade, unsigned char, 0x450390);
    unsigned long GetHitLastPcObjectId();    PATCH_MEMBER(unsigned long, GetHitLastPcObjectId, , 0x4B0A40);
    unsigned char GetHitLastPcRealm();    PATCH_MEMBER(unsigned char, GetHitLastPcRealm, , 0x4B0A60);
    class NSPOINT2 m_cellStart;//this+0x45F4
    int m_bDelete;//this+0x45F8
    class CFiniteStateMachine * m_fsm;//this+0x45FC
    class CNSNpcState * m_ActionCurrent;//this+0x4600
    class CNSNpcState * m_ActionArray[0x8];//this+0x4604
    class CNSNpcState * m_ActionGlobal;//this+0x4624
    unsigned long m_dwNpcIdleTime;//this+0x4628
    unsigned long m_dwQuestCheckTime;//this+0x462C
    unsigned long m_dwLastSetTargetTime;//this+0x4630
    unsigned long m_dwHitLastPcObjectId;//this+0x4634
    unsigned char m_btHitLastPcRealm;//this+0x4638
    unsigned long m_dwStateOld;//this+0x463C
    unsigned char m_btPetState;//this+0x4640
    class CNSCriticalSection m_cs;//this+0x4644
    struct lua_State * m_L;//this+0x4A60
    static void * operator new(unsigned int);    //PATCH_STATIC(void *, operator new, unsigned int, 0x406200);
    static void operator delete(void *, unsigned int);    //PATCH_STATIC(void, operator delete, void * _COMMA unsigned int, 0x406210);
    //void __local_vftable_ctor_closure();
    //virtual void * __vecDelDtor(unsigned int);

    struct _Invoke {
        PATCH_MEMBER_INVOKE(CNSNpc &, CNSNpc, Constructor, );
        PATCH_MEMBER_INVOKE(void, CNSNpc, Destructor, );
        ////PATCH_MEMBER_INVOKE(CNSNpc &, CNSNpc, operator=, CNSNpc &);
        //PATCH_MEMBER_INVOKE(void, CNSNpc, Init, CFiniteStateMachine * _COMMA NSPOINT2 & _COMMA unsigned short);
        //PATCH_MEMBER_INVOKE(CNSObject::OBJECTTYPE, CNSNpc, GetNpcType, );
        //PATCH_MEMBER_INVOKE(void, CNSNpc, Reset, int);
        //PATCH_MEMBER_INVOKE(void, CNSNpc, OnEnter, );
        //PATCH_MEMBER_INVOKE(void, CNSNpc, OnLeave, );
        //PATCH_MEMBER_INVOKE(void, CNSNpc, OnBuff, unsigned long _COMMA int);
        //PATCH_MEMBER_INVOKE(void, CNSNpc, OnHitLastDamage, CNSCharacter *);
        //PATCH_MEMBER_INVOKE(unsigned short, CNSNpc, HitDamage, CNSCharacter * _COMMA unsigned short _COMMA CNSObject::HITTYPE _COMMA int);
        //PATCH_MEMBER_INVOKE(void, CNSNpc, SetTargetNpcId, unsigned short);
        //PATCH_MEMBER_INVOKE(void, CNSNpc, OnStart, unsigned long);
        //PATCH_MEMBER_INVOKE(void, CNSNpc, OnStop, unsigned long);
        //PATCH_MEMBER_INVOKE(void, CNSNpc, OnAction, unsigned long);
        //PATCH_MEMBER_INVOKE(void, CNSNpc, OnHide, unsigned long);
        //PATCH_MEMBER_INVOKE(unsigned short, CNSNpc, PetUseSta, unsigned short);
        //PATCH_MEMBER_INVOKE(void, CNSNpc, Stop, unsigned long);
        //PATCH_MEMBER_INVOKE(void, CNSNpc, Action, unsigned long _COMMA unsigned long);
        //PATCH_MEMBER_INVOKE(int, CNSNpc, IsAggrassive, );
        //PATCH_MEMBER_INVOKE(int, CNSNpc, IsLink, );
        //PATCH_MEMBER_INVOKE(int, CNSNpc, IsTooFar, CNSCharacter *);
        //PATCH_MEMBER_INVOKE(int, CNSNpc, IsDelete, );
        //PATCH_MEMBER_INVOKE(int, CNSNpc, IsMobAttack, );
        //PATCH_MEMBER_INVOKE(int, CNSNpc, IsFriendlyMob, );
        //PATCH_MEMBER_INVOKE(int, CNSNpc, IsPet, );
        //PATCH_MEMBER_INVOKE(int, CNSNpc, IsTameMob, );
        //PATCH_MEMBER_INVOKE(int, CNSNpc, IsSummon, );
        //PATCH_MEMBER_INVOKE(int, CNSNpc, IsBomb, );
        //PATCH_MEMBER_INVOKE(int, CNSNpc, IsBoss, );
        //PATCH_MEMBER_INVOKE(int, CNSNpc, IsBonusMob, );
        //PATCH_MEMBER_INVOKE(int, CNSNpc, IsSummonMelee, );
        //PATCH_MEMBER_INVOKE(int, CNSNpc, IsSummonRange, );
        //PATCH_MEMBER_INVOKE(int, CNSNpc, IsSummonSaver, );
        //PATCH_MEMBER_INVOKE(int, CNSNpc, IsBlock, );
        //PATCH_MEMBER_INVOKE(int, CNSNpc, IsBlockDefense, );
        //PATCH_MEMBER_INVOKE(int, CNSNpc, IsBlockLarge, );
        //PATCH_MEMBER_INVOKE(int, CNSNpc, IsBlockMedium, );
        //PATCH_MEMBER_INVOKE(int, CNSNpc, IsBlockSmall, );
        //PATCH_MEMBER_INVOKE(int, CNSNpc, IsBlockSteamCore, );
        //PATCH_MEMBER_INVOKE(int, CNSNpc, CheckTarget, CNSCharacter *);
        //PATCH_MEMBER_INVOKE(void, CNSNpc, SetDelete, );
        //PATCH_MEMBER_INVOKE(void, CNSNpc, SetCellStart, NSPOINT2 &);
        //PATCH_MEMBER_INVOKE(NSPOINT2 &, CNSNpc, GetCellStart, );
        //PATCH_MEMBER_INVOKE(NSPOINT2 &, CNSNpc, GetCellRespawn, );
        //PATCH_MEMBER_INVOKE(char *, CNSNpc, GetNpcName, );
        //PATCH_MEMBER_INVOKE(void, CNSNpc, SetNpcName, char *);
        //PATCH_MEMBER_INVOKE(unsigned short, CNSNpc, GetNpcId, );
        //PATCH_MEMBER_INVOKE(unsigned short, CNSNpc, GetStartAngle, );
        //PATCH_MEMBER_INVOKE(void, CNSNpc, ResetAngle, );
        //PATCH_MEMBER_INVOKE(int, CNSNpc, GetRespawnPos, NSPOINT2 &);
        //PATCH_MEMBER_INVOKE(void, CNSNpc, SetRespawnInfo, NSPOINT2 & _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short);
        //PATCH_MEMBER_INVOKE(_NSRANGE, CNSNpc, GetLimitMoveRange, );
        //PATCH_MEMBER_INVOKE(NSPOINT2, CNSNpc, GetNewDestination, NSPOINT2 &);
        //PATCH_MEMBER_INVOKE(unsigned short, CNSNpc, GetRespawnSecond, );
        //PATCH_MEMBER_INVOKE(void, CNSNpc, SetRespawnSecond, unsigned short);
        //PATCH_MEMBER_INVOKE(void, CNSNpc, SetDisapper, unsigned short);
        //PATCH_MEMBER_INVOKE(unsigned long, CNSNpc, GetLeaderObjectId, );
        //PATCH_MEMBER_INVOKE(void, CNSNpc, SetLeaderObjectId, unsigned long);
        //PATCH_MEMBER_INVOKE(int, CNSNpc, GetLeaderDestination, NSPOINT2 & _COMMA int);
        //PATCH_MEMBER_INVOKE(int, CNSNpc, GetLeaderDestination2, NSPOINT2 &);
        //PATCH_MEMBER_INVOKE(unsigned long, CNSNpc, GetOwnerObjectId, );
        //PATCH_MEMBER_INVOKE(void, CNSNpc, SetOwnerObjectId, unsigned long);
        //PATCH_MEMBER_INVOKE(void, CNSNpc, SetTargetObjectId, unsigned long);
        //PATCH_MEMBER_INVOKE(unsigned long, CNSNpc, GetLastSetTargetTime, );
        //PATCH_MEMBER_INVOKE(unsigned long, CNSNpc, FindTarget, int);
        //PATCH_MEMBER_INVOKE(unsigned long, CNSNpc, FindRandomTarget, unsigned long);
        //PATCH_MEMBER_INVOKE(int, CNSNpc, CallFriend, );
        //PATCH_MEMBER_INVOKE(CNSCharacter *, CNSNpc, GetSkillTargetObject, );
        //PATCH_MEMBER_INVOKE(void, CNSNpc, Attack, CNSCharacter * _COMMA unsigned long);
        //PATCH_MEMBER_INVOKE(int, CNSNpc, SkillCast, unsigned short _COMMA unsigned long);
        //PATCH_MEMBER_INVOKE(unsigned short, CNSNpc, AttackBlockMode, CNSCharacter * _COMMA unsigned short);
        //PATCH_MEMBER_INVOKE(void, CNSNpc, Warp, unsigned short _COMMA unsigned short);
        //PATCH_MEMBER_INVOKE(void, CNSNpc, WarpArea, unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char);
        //PATCH_MEMBER_INVOKE(unsigned long, CNSNpc, GetRectInPcCount, unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char);
        //PATCH_MEMBER_INVOKE(unsigned long, CNSNpc, GetRectInNpcCount, unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short);
        //PATCH_MEMBER_INVOKE(unsigned long, CNSNpc, RectInDisappearNpc, unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short);
        //PATCH_MEMBER_INVOKE(unsigned long, CNSNpc, HitRectInPcDebuff, int _COMMA unsigned char _COMMA unsigned char _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short);
        //PATCH_STATIC_INVOKE(int, ItemDropTest, CNSCharacter * _COMMA unsigned short _COMMA unsigned long);
        PATCH_MEMBER_INVOKE(void, CNSNpc, ItemDrop, CNSCharacter *);
        //PATCH_MEMBER_INVOKE(int, CNSNpc, ItemCheckLootOwner, char *);
        //PATCH_MEMBER_INVOKE(unsigned long, CNSNpc, ItemList, CPacket &);
        //PATCH_MEMBER_INVOKE(int, CNSNpc, ItemPick, CNSPc * _COMMA unsigned long);
        //PATCH_MEMBER_INVOKE(int, CNSNpc, ShopItemSell, CNSPc * _COMMA unsigned long _COMMA unsigned char _COMMA unsigned long &);
        //PATCH_MEMBER_INVOKE(int, CNSNpc, ShopItemCost, CNSPc * _COMMA unsigned long _COMMA unsigned char _COMMA unsigned long &);
        //PATCH_MEMBER_INVOKE(int, CNSNpc, ShopItemBuy, CNSPc * _COMMA unsigned long _COMMA unsigned char _COMMA unsigned long &);
        //PATCH_MEMBER_INVOKE(void, CNSNpc, NpcScriptInit, );
        //PATCH_MEMBER_INVOKE(int, CNSNpc, NpcScriptTalk, CNSPc * _COMMA char * _COMMA CPacket &);
        //PATCH_MEMBER_INVOKE(int, CNSNpc, NpcScriptIdle, CNSPc *);
        //PATCH_MEMBER_INVOKE(int, CNSNpc, NpcScriptDead, CNSPc *);
        //PATCH_MEMBER_INVOKE(int, CNSNpc, NpcScriptQuestCheck, CNSPc *);
        //PATCH_MEMBER_INVOKE(void, CNSNpc, Reborn, );
        //PATCH_MEMBER_INVOKE(void, CNSNpc, PacketEnterMessage, CPacket &);
        //PATCH_MEMBER_INVOKE(void, CNSNpc, PacketItemListMessage, CPacket &);
        //PATCH_MEMBER_INVOKE(void, CNSNpc, PacketShopItemListMessage, CNSPc * _COMMA CPacket &);
        //PATCH_MEMBER_INVOKE(void, CNSNpc, PacketStatusMessage, CPacket &);
        //PATCH_MEMBER_INVOKE(void, CNSNpc, SendEnterMessage, int);
        //PATCH_MEMBER_INVOKE(void, CNSNpc, SendMoveMessage, unsigned long _COMMA int);
        //PATCH_MEMBER_INVOKE(void, CNSNpc, SendRecoveryMessage, int _COMMA int);
        //PATCH_MEMBER_INVOKE(void, CNSNpc, SendAttackMessage, unsigned long _COMMA unsigned char _COMMA unsigned short _COMMA unsigned char _COMMA unsigned long);
        //PATCH_MEMBER_INVOKE(void, CNSNpc, SendLeaveMessage, );
        //PATCH_MEMBER_INVOKE(void, CNSNpc, SendDeadMessage, );
        //PATCH_MEMBER_INVOKE(void, CNSNpc, SendPetRecoveryMessage, unsigned short);
        //PATCH_MEMBER_INVOKE(void, CNSNpc, SendChatMessage, unsigned char _COMMA char *);
        //PATCH_MEMBER_INVOKE(void, CNSNpc, SendDelayedMessage, );
        //PATCH_MEMBER_INVOKE(unsigned long, CNSNpc, GetCurrentState, );
        //PATCH_MEMBER_INVOKE(void, CNSNpc, SetTransition, unsigned long);
        //PATCH_MEMBER_INVOKE(void, CNSNpc, StateTransition, unsigned long);
        //PATCH_MEMBER_INVOKE(void, CNSNpc, ChangeCharacterState, unsigned long);
        //PATCH_MEMBER_INVOKE(void, CNSNpc, PetInit, CNSCharacter * _COMMA char * _COMMA unsigned short _COMMA unsigned short);
        //PATCH_MEMBER_INVOKE(void, CNSNpc, PetInit, CNSCharacter *);
        //PATCH_MEMBER_INVOKE(void, CNSNpc, PetStateChange, CNSNpc::PETSTATETYPE);
        //PATCH_MEMBER_INVOKE(unsigned char, CNSNpc, PetGetState, );
        //PATCH_MEMBER_INVOKE(void, CNSNpc, PetSetTargetObjectId, unsigned long);
        //PATCH_MEMBER_INVOKE(void, CNSNpc, PetDelete, );
        //PATCH_MEMBER_INVOKE(int, CNSNpc, PetCheckSkillUse, int);
        //PATCH_MEMBER_INVOKE(void, CNSNpc, PetMessageStart, unsigned long _COMMA unsigned long);
        //PATCH_MEMBER_INVOKE(unsigned char, CNSNpc, PetGetGrade, );
        //PATCH_MEMBER_INVOKE(void, CNSNpc, PetSetGrade, unsigned char);
        //PATCH_MEMBER_INVOKE(unsigned long, CNSNpc, GetHitLastPcObjectId, );
        //PATCH_MEMBER_INVOKE(unsigned char, CNSNpc, GetHitLastPcRealm, );
        //PATCH_STATIC_INVOKE(void *, operator new, unsigned int);
        //PATCH_STATIC_INVOKE(void, operator delete, void * _COMMA unsigned int);
    };
};
#ifdef DEFINE_NS_CPP
DEFINE_NAKED_JMP(CNSNpc& CNSNpc::Constructor(), 0x443B60);
//DEFINE_NAKED_JMP(CNSNpc::Destructor(), 0x443CE0);
DEFINE_NAKED_JMP(CNSNpc & CNSNpc::operator=(CNSNpc &), 0x451310);
//DEFINE_NAKED_JMP(void CNSNpc::Init(CFiniteStateMachine * _COMMA NSPOINT2 & _COMMA unsigned short), 0x443E80);
DEFINE_NAKED_JMP(CNSObject::OBJECTTYPE CNSNpc::GetNpcType(), 0x44A2C0);
DEFINE_NAKED_JMP(void CNSNpc::Reset(int), 0x444500);
DEFINE_NAKED_JMP(void CNSNpc::OnEnter(), 0x4447A0);
DEFINE_NAKED_JMP(void CNSNpc::OnLeave(), 0x444800);
DEFINE_NAKED_JMP(void CNSNpc::OnBuff(unsigned long _COMMA int), 0x444850);
DEFINE_NAKED_JMP(void CNSNpc::OnHitLastDamage(CNSCharacter *), 0x444B10);
DEFINE_NAKED_JMP(unsigned short CNSNpc::HitDamage(CNSCharacter * _COMMA unsigned short _COMMA CNSObject::HITTYPE _COMMA int), 0x445540);
DEFINE_NAKED_JMP(void CNSNpc::SetTargetNpcId(unsigned short), 0x4B07C0);
DEFINE_NAKED_JMP(void CNSNpc::OnStart(unsigned long), 0x449A80);
DEFINE_NAKED_JMP(void CNSNpc::OnStop(unsigned long), 0x449AC0);
DEFINE_NAKED_JMP(void CNSNpc::OnAction(unsigned long), 0x4449C0);
DEFINE_NAKED_JMP(void CNSNpc::OnHide(unsigned long), 0x444A40);
DEFINE_NAKED_JMP(unsigned short CNSNpc::PetUseSta(unsigned short), 0x444AA0);
DEFINE_NAKED_JMP(void CNSNpc::Stop(unsigned long), 0x449D10);
DEFINE_NAKED_JMP(void CNSNpc::Action(unsigned long _COMMA unsigned long), 0x449D60);
DEFINE_NAKED_JMP(int CNSNpc::IsAggrassive(), 0x459830);
DEFINE_NAKED_JMP(int CNSNpc::IsLink(), 0x44C2D0);
DEFINE_NAKED_JMP(int CNSNpc::IsTooFar(CNSCharacter *), 0x445800);
DEFINE_NAKED_JMP(int CNSNpc::IsDelete(), 0x4504B0);
DEFINE_NAKED_JMP(int CNSNpc::IsMobAttack(), 0x44C220);
DEFINE_NAKED_JMP(int CNSNpc::IsFriendlyMob(), 0x44A8C0);
DEFINE_NAKED_JMP(int CNSNpc::IsPet(), 0x44A8A0);
DEFINE_NAKED_JMP(int CNSNpc::IsTameMob(), 0x44AAB0);
DEFINE_NAKED_JMP(int CNSNpc::IsSummon(), 0x44A560);
DEFINE_NAKED_JMP(int CNSNpc::IsBomb(), 0x44A920);
DEFINE_NAKED_JMP(int CNSNpc::IsBoss(), 0x4582C0);
DEFINE_NAKED_JMP(int CNSNpc::IsBonusMob(), 0x44AAE0);
DEFINE_NAKED_JMP(int CNSNpc::IsSummonMelee(), 0x4D7110);
DEFINE_NAKED_JMP(int CNSNpc::IsSummonRange(), 0x4D71A0);
DEFINE_NAKED_JMP(int CNSNpc::IsSummonSaver(), 0x4D7230);
DEFINE_NAKED_JMP(int CNSNpc::IsBlock(), 0x44A3B0);
DEFINE_NAKED_JMP(int CNSNpc::IsBlockDefense(), 0x44A400);
DEFINE_NAKED_JMP(int CNSNpc::IsBlockLarge(), 0x44C240);
DEFINE_NAKED_JMP(int CNSNpc::IsBlockMedium(), 0x44A450);
DEFINE_NAKED_JMP(int CNSNpc::IsBlockSmall(), 0x44A4A0);
DEFINE_NAKED_JMP(int CNSNpc::IsBlockSteamCore(), 0x44A4F0);
DEFINE_NAKED_JMP(int CNSNpc::CheckTarget(CNSCharacter *), 0x44AB30);
DEFINE_NAKED_JMP(void CNSNpc::SetDelete(), 0x4502C0);
DEFINE_NAKED_JMP(void CNSNpc::SetCellStart(NSPOINT2 &), 0x458CB0);
DEFINE_NAKED_JMP(NSPOINT2 & CNSNpc::GetCellStart(), 0x459FC0);
DEFINE_NAKED_JMP(NSPOINT2 & CNSNpc::GetCellRespawn(), 0x458CD0);
DEFINE_NAKED_JMP(char * CNSNpc::GetNpcName(), 0x44C7E0);
DEFINE_NAKED_JMP(void CNSNpc::SetNpcName(char *), 0x4C7F70);
DEFINE_NAKED_JMP(unsigned short CNSNpc::GetNpcId(), 0x42B9F0);
DEFINE_NAKED_JMP(unsigned short CNSNpc::GetStartAngle(), 0x450490);
DEFINE_NAKED_JMP(void CNSNpc::ResetAngle(), 0x44A540);
DEFINE_NAKED_JMP(int CNSNpc::GetRespawnPos(NSPOINT2 &), 0x4446B0);
DEFINE_NAKED_JMP(void CNSNpc::SetRespawnInfo(NSPOINT2 & _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short), 0x450320);
DEFINE_NAKED_JMP(_NSRANGE CNSNpc::GetLimitMoveRange(), 0x444EC0);
DEFINE_NAKED_JMP(NSPOINT2 CNSNpc::GetNewDestination(NSPOINT2 &), 0x444FA0);
DEFINE_NAKED_JMP(unsigned short CNSNpc::GetRespawnSecond(), 0x45AE90);
DEFINE_NAKED_JMP(void CNSNpc::SetRespawnSecond(unsigned short), 0x4503B0);
DEFINE_NAKED_JMP(void CNSNpc::SetDisapper(unsigned short), 0x4503F0);
DEFINE_NAKED_JMP(unsigned long CNSNpc::GetLeaderObjectId(), 0x485570);
DEFINE_NAKED_JMP(void CNSNpc::SetLeaderObjectId(unsigned long), 0x44C2B0);
DEFINE_NAKED_JMP(int CNSNpc::GetLeaderDestination(NSPOINT2 & _COMMA int), 0x4451A0);
DEFINE_NAKED_JMP(int CNSNpc::GetLeaderDestination2(NSPOINT2 &), 0x445370);
DEFINE_NAKED_JMP(unsigned long CNSNpc::GetOwnerObjectId(), 0x43EE30);
DEFINE_NAKED_JMP(void CNSNpc::SetOwnerObjectId(unsigned long), 0x4503D0);
DEFINE_NAKED_JMP(void CNSNpc::SetTargetObjectId(unsigned long), 0x44A1E0);
DEFINE_NAKED_JMP(unsigned long CNSNpc::GetLastSetTargetTime(), 0x459810);
DEFINE_NAKED_JMP(unsigned long CNSNpc::FindTarget(int), 0x4458C0);
DEFINE_NAKED_JMP(unsigned long CNSNpc::FindRandomTarget(unsigned long), 0x4460C0);
DEFINE_NAKED_JMP(int CNSNpc::CallFriend(), 0x4462C0);
DEFINE_NAKED_JMP(CNSCharacter * CNSNpc::GetSkillTargetObject(), 0x45A9C0);
DEFINE_NAKED_JMP(void CNSNpc::Attack(CNSCharacter * _COMMA unsigned long), 0x4465E0);
DEFINE_NAKED_JMP(int CNSNpc::SkillCast(unsigned short _COMMA unsigned long), 0x446C40);
DEFINE_NAKED_JMP(unsigned short CNSNpc::AttackBlockMode(CNSCharacter * _COMMA unsigned short), 0x446B40);
DEFINE_NAKED_JMP(void CNSNpc::Warp(unsigned short _COMMA unsigned short), 0x446D30);
DEFINE_NAKED_JMP(void CNSNpc::WarpArea(unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char), 0x446DB0);
DEFINE_NAKED_JMP(unsigned long CNSNpc::GetRectInPcCount(unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char), 0x446FC0);
DEFINE_NAKED_JMP(unsigned long CNSNpc::GetRectInNpcCount(unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short), 0x446ED0);
DEFINE_NAKED_JMP(unsigned long CNSNpc::RectInDisappearNpc(unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short), 0x4471E0);
DEFINE_NAKED_JMP(unsigned long CNSNpc::HitRectInPcDebuff(int _COMMA unsigned char _COMMA unsigned char _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short), 0x4470C0);
DEFINE_NAKED_JMP(int CNSNpc::ItemDropTest(CNSCharacter * _COMMA unsigned short _COMMA unsigned long), 0x4472E0);
DEFINE_NAKED_JMP(void CNSNpc::ItemDrop(CNSCharacter *), 0x447530);
DEFINE_NAKED_JMP(int CNSNpc::ItemCheckLootOwner(char *), 0x447AC0);
DEFINE_NAKED_JMP(unsigned long CNSNpc::ItemList(CPacket &), 0x447B70);
DEFINE_NAKED_JMP(int CNSNpc::ItemPick(CNSPc * _COMMA unsigned long), 0x447BF0);
DEFINE_NAKED_JMP(int CNSNpc::ShopItemSell(CNSPc * _COMMA unsigned long _COMMA unsigned char _COMMA unsigned long &), 0x447F90);
DEFINE_NAKED_JMP(int CNSNpc::ShopItemCost(CNSPc * _COMMA unsigned long _COMMA unsigned char _COMMA unsigned long &), 0x4481F0);
DEFINE_NAKED_JMP(int CNSNpc::ShopItemBuy(CNSPc * _COMMA unsigned long _COMMA unsigned char _COMMA unsigned long &), 0x448290);
DEFINE_NAKED_JMP(void CNSNpc::NpcScriptInit(), 0x448440);
DEFINE_NAKED_JMP(int CNSNpc::NpcScriptTalk(CNSPc * _COMMA char * _COMMA CPacket &), 0x4484E0);
DEFINE_NAKED_JMP(int CNSNpc::NpcScriptIdle(CNSPc *), 0x448800);
DEFINE_NAKED_JMP(int CNSNpc::NpcScriptDead(CNSPc *), 0x448960);
DEFINE_NAKED_JMP(int CNSNpc::NpcScriptQuestCheck(CNSPc *), 0x448AC0);
DEFINE_NAKED_JMP(void CNSNpc::Reborn(), 0x4443F0);
DEFINE_NAKED_JMP(void CNSNpc::PacketEnterMessage(CPacket &), 0x448EF0);
DEFINE_NAKED_JMP(void CNSNpc::PacketItemListMessage(CPacket &), 0x449200);
DEFINE_NAKED_JMP(void CNSNpc::PacketShopItemListMessage(CNSPc * _COMMA CPacket &), 0x4492A0);
DEFINE_NAKED_JMP(void CNSNpc::PacketStatusMessage(CPacket &), 0x4499A0);
DEFINE_NAKED_JMP(void CNSNpc::SendEnterMessage(int), 0x449350);
DEFINE_NAKED_JMP(void CNSNpc::SendMoveMessage(unsigned long _COMMA int), 0x4493D0);
DEFINE_NAKED_JMP(void CNSNpc::SendRecoveryMessage(int _COMMA int), 0x449750);
DEFINE_NAKED_JMP(void CNSNpc::SendAttackMessage(unsigned long _COMMA unsigned char _COMMA unsigned short _COMMA unsigned char _COMMA unsigned long), 0x449530);
DEFINE_NAKED_JMP(void CNSNpc::SendLeaveMessage(), 0x4496D0);
DEFINE_NAKED_JMP(void CNSNpc::SendDeadMessage(), 0x449650);
DEFINE_NAKED_JMP(void CNSNpc::SendPetRecoveryMessage(unsigned short), 0x449820);
DEFINE_NAKED_JMP(void CNSNpc::SendChatMessage(unsigned char _COMMA char *), 0x4498E0);
DEFINE_NAKED_JMP(void CNSNpc::SendDelayedMessage(), 0x44C850);
DEFINE_NAKED_JMP(unsigned long CNSNpc::GetCurrentState(), 0x448D10);
DEFINE_NAKED_JMP(void CNSNpc::SetTransition(unsigned long), 0x448E30);
DEFINE_NAKED_JMP(void CNSNpc::StateTransition(unsigned long), 0x448E90);
DEFINE_NAKED_JMP(void CNSNpc::ChangeCharacterState(unsigned long), 0x448D30);
DEFINE_NAKED_JMP(void CNSNpc::PetInit(CNSCharacter * _COMMA char * _COMMA unsigned short _COMMA unsigned short), 0x4830A0);
DEFINE_NAKED_JMP(void CNSNpc::PetInit(CNSCharacter *), 0x483150);
DEFINE_NAKED_JMP(void CNSNpc::PetStateChange(CNSNpc::PETSTATETYPE), 0x4831D0);
DEFINE_NAKED_JMP(unsigned char CNSNpc::PetGetState(), 0x4D7410);
DEFINE_NAKED_JMP(void CNSNpc::PetSetTargetObjectId(unsigned long), 0x4822A0);
DEFINE_NAKED_JMP(void CNSNpc::PetDelete(), 0x4591E0);
DEFINE_NAKED_JMP(int CNSNpc::PetCheckSkillUse(int), 0x4D7320);
DEFINE_NAKED_JMP(void CNSNpc::PetMessageStart(unsigned long _COMMA unsigned long), 0x482900);
DEFINE_NAKED_JMP(unsigned char CNSNpc::PetGetGrade(), 0x4582A0);
DEFINE_NAKED_JMP(void CNSNpc::PetSetGrade(unsigned char), 0x450390);
DEFINE_NAKED_JMP(unsigned long CNSNpc::GetHitLastPcObjectId(), 0x4B0A40);
DEFINE_NAKED_JMP(unsigned char CNSNpc::GetHitLastPcRealm(), 0x4B0A60);
DEFINE_NAKED_JMP(void * CNSNpc::operator new(unsigned int), 0x406200);
DEFINE_NAKED_JMP(void CNSNpc::operator delete(void * _COMMA unsigned int), 0x406210);
#endif





#endif