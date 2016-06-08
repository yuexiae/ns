#ifndef NSHEADER_NS_NPC_MANAGER_H_
#define NSHEADER_NS_NPC_MANAGER_H_

#include "ns_header/ns_npc_params.h"

class CNSNpcManager;
class CNSNpcManagerExt;

template <>
class CSingleton<CNSNpcManager> {
public:
    static const unsigned int _size = 0x1;

    static CNSNpcManagerExt * GetInstance();    PATCH_STATIC(CNSNpcManager *, GetInstance, , 0x4034E0);
    static void ReleaseInstance();    PATCH_STATIC(void, ReleaseInstance, , 0x403570);
    static class CNSNpcManager * m_selfInstance;//[0x559E18]  [00159E18:0003:00039E18]

    /*struct _Invoke {
    PATCH_STATIC_INVOKE(CNSNpcManager *, GetInstance, );
    PATCH_STATIC_INVOKE(void, ReleaseInstance, );
    };*/
};
#ifdef DEFINE_NS_CPP
DEFINE_NAKED_JMP(CNSNpcManagerExt * CSingleton<CNSNpcManager>::GetInstance(), 0x4034E0);
//DEFINE_NAKED_JMP(void CSingleton<CNSNpcManager>::ReleaseInstance(), 0x403570);
#endif

class CNSNpcManager : public CThread, public CSingleton<CNSNpcManager> {
public:
    static const unsigned int _size = 0x2790;

    CNSNpcManager(const CNSNpcManager &);
    CNSNpcManager();    PATCH_MEMBER(CNSNpcManager &, Constructor, , 0x44CD20);
    virtual ~CNSNpcManager();    PATCH_MEMBER(void, Destructor, , 0x44CE10);
    virtual void Action();    PATCH_MEMBER(void, Action, , 0x450170);
    int Init();    PATCH_MEMBER(int, Init, , 0x44CF50);
    unsigned long GetCount();    PATCH_MEMBER(unsigned long, GetCount, , 0x44CF80);
    void Add(unsigned long, CNSNpc *);    PATCH_MEMBER(void, Add, unsigned long _COMMA CNSNpc *, 0x44EA30);
    int Delete(unsigned long);    PATCH_MEMBER(int, Delete, unsigned long, 0x44EAB0);
    int GetRespawnPos(NSPOINT2 &, unsigned short, NSPOINT2 &);
    CNSNpc * Create(unsigned short, unsigned char, NSPOINT2 &, unsigned short, NSPOINT2 &, unsigned short, unsigned short, unsigned short, unsigned long, unsigned short);    PATCH_MEMBER(CNSNpc *, Create, unsigned short _COMMA unsigned char _COMMA NSPOINT2 & _COMMA unsigned short _COMMA NSPOINT2 & _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned long _COMMA unsigned short, 0x44E340);
    int Create(CNSNpcParams::_NpcArrange *);    PATCH_MEMBER(int, Create, CNSNpcParams::_NpcArrange *, 0x44E130);
    CNSNpc * CreatePet(unsigned short, unsigned char, unsigned char, unsigned char, NSPOINT2 &, unsigned short, NSPOINT2 &, unsigned short, unsigned short, unsigned short, unsigned long);    PATCH_MEMBER(CNSNpc *, CreatePet, unsigned short _COMMA unsigned char _COMMA unsigned char _COMMA unsigned char _COMMA NSPOINT2 & _COMMA unsigned short _COMMA NSPOINT2 & _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned long, 0x44E4E0);
    CNSNpc * CreateTester(unsigned short);    PATCH_MEMBER(CNSNpc *, CreateTester, unsigned short, 0x44E640);
    void Process();    PATCH_MEMBER(void, Process, , 0x44FF70);
    void Arrange();    PATCH_MEMBER(void, Arrange, , 0x44CFF0);
    void ArrangeInstantNpc(unsigned long);    PATCH_MEMBER(void, ArrangeInstantNpc, unsigned long, 0x44D120);
    void DeleteInstantNpc(unsigned long);    PATCH_MEMBER(void, DeleteInstantNpc, unsigned long, 0x44D200);
    int CheckNpc(unsigned short, unsigned short, unsigned short, unsigned short, unsigned short, unsigned char);    PATCH_MEMBER(int, CheckNpc, unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char, 0x44D7A0);
    unsigned long GetNpcCount(unsigned short, unsigned short, unsigned short, unsigned short, unsigned short, unsigned char);    PATCH_MEMBER(unsigned long, GetNpcCount, unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char, 0x44D9A0);
    int GetNpcPos(unsigned short, NSPOINT2 &, unsigned short, unsigned short, unsigned short, unsigned short, unsigned char);    PATCH_MEMBER(int, GetNpcPos, unsigned short _COMMA NSPOINT2 & _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char, 0x44DB90);
    unsigned long GetBlockCount(unsigned char, int);    PATCH_MEMBER(unsigned long, GetBlockCount, unsigned char _COMMA int, 0x44DF70);
    unsigned long DisappearNpc(unsigned short, unsigned short, unsigned short, unsigned short, unsigned short, unsigned char);    PATCH_MEMBER(unsigned long, DisappearNpc, unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char, 0x44D5E0);
    unsigned long DeleteNpc(unsigned short);    PATCH_MEMBER(unsigned long, DeleteNpc, unsigned short, 0x44D2F0);
    unsigned long DeleteBlock(unsigned short, unsigned short, unsigned short, unsigned short, unsigned char);    PATCH_MEMBER(unsigned long, DeleteBlock, unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char, 0x44D400);
    unsigned long GetInNpcHpPercent(unsigned short, unsigned short, unsigned short, unsigned short, unsigned short, unsigned long);    PATCH_MEMBER(unsigned long, GetInNpcHpPercent, unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned long, 0x44DD90);
    CNSObject::Owner<CNSNpc> CallMob(unsigned short wNpcId, unsigned short x, unsigned short y, unsigned short wDisappearSecond, unsigned short wAngle, unsigned short wPathId) { return CNSObject::Owner<CNSNpc>(_CallMob(wNpcId, x, y, wDisappearSecond, wAngle, wPathId)); } CNSNpc * _CallMob(unsigned short, unsigned short, unsigned short, unsigned short, unsigned short, unsigned short);    PATCH_MEMBER(CNSNpc *, CallMob, unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short, 0x44E760);
    unsigned long PacketBlockInfo(CPacket &);    PATCH_MEMBER(unsigned long, PacketBlockInfo, CPacket &, 0x44EB50);
    void BroadcastEnterMessage_PVPTournamentZone();    PATCH_MEMBER(void, BroadcastEnterMessage_PVPTournamentZone, , 0x44EBD0);
    void DebugBlockPrint(CNSPc *);    PATCH_MEMBER(void, DebugBlockPrint, CNSPc *, 0x44ECD0);
    void DebugNpcPrint(CNSPc *, unsigned short);    PATCH_MEMBER(void, DebugNpcPrint, CNSPc * _COMMA unsigned short, 0x44ED50);
    void AttackRectInNpc(unsigned short, unsigned short, unsigned short, unsigned short, unsigned short, unsigned char, unsigned short);    PATCH_MEMBER(void, AttackRectInNpc, unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char _COMMA unsigned short, 0x44EEB0);
    void AwakeRectInNpc(unsigned short, unsigned short, unsigned short, unsigned short, unsigned char, int);    PATCH_MEMBER(void, AwakeRectInNpc, unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char _COMMA int, 0x44F070);
    void HealRectInNpc(unsigned short, unsigned short, unsigned short, unsigned short, unsigned short, unsigned short, unsigned char);    PATCH_MEMBER(void, HealRectInNpc, unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char, 0x44F220);
    int IsExistBlock(unsigned short, unsigned short, unsigned short);    PATCH_MEMBER(int, IsExistBlock, unsigned short _COMMA unsigned short _COMMA unsigned short, 0x44F400);
    void DBBlockLoad();    PATCH_MEMBER(void, DBBlockLoad, , 0x44F550);
    void DBBlockSave();    PATCH_MEMBER(void, DBBlockSave, , 0x44F9C0);
    unsigned long GetRealmCastle(unsigned char);    PATCH_MEMBER(unsigned long, GetRealmCastle, unsigned char, 0x4827B0);
    CNSCriticalSection * GetLockObject();
    struct _BlockObject {
        static const unsigned int _size = 0x8;

        unsigned short wNpcId;//this+0x0
        class NSPOINT2 cell;//this+0x2
        unsigned short wAngle;//this+0x6
        _BlockObject();    PATCH_MEMBER(CNSNpcManager::_BlockObject &, Constructor, , 0x450260);

        /*struct _Invoke {
        PATCH_MEMBER_INVOKE(CNSNpcManager::_BlockObject &, CNSNpcManager::_BlockObject, Constructor, );
        };*/

#ifdef DEFINE_NS_CPP
        //DEFINE_NAKED_JMP(CNSNpcManager::_BlockObject::Constructor(), 0x450260);
#endif
    };

    class std::map<unsigned long,CNSNpc *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const ,CNSNpc *> > > m_mapNpc;//this+0x10
    unsigned long m_dwBlockObjectCount;//this+0x30
    struct CNSNpcManager::_BlockObject m_blockObjectArray[0x400];//this+0x34
    unsigned long m_dwSteamCoreCount;//this+0x2034
    struct CNSNpcManager::_BlockObject m_steamCoreArray[0x64];//this+0x2038
    unsigned long m_dwRealmCastleCountArray[0x5];//this+0x2358
    static int m_bThreadLoop;//[0x530788]  [00130788:0003:00010788]
    class CNSCriticalSection m_cs;//this+0x236C
    unsigned short m_dwId;//this+0x2788
    unsigned long m_dwTickCounter;//this+0x278C
    CFiniteStateMachine * AllocStateMachine(CNSNpc *);    PATCH_MEMBER(CFiniteStateMachine *, AllocStateMachine, CNSNpc *, 0x44E820);
    void NpcAction(CNSNpc *, unsigned long, unsigned long);    PATCH_MEMBER(void, NpcAction, CNSNpc * _COMMA unsigned long _COMMA unsigned long, 0x4504D0);
    CNSNpcManager & operator=(const CNSNpcManager &);
    //void __local_vftable_ctor_closure();
    //virtual void * __vecDelDtor(unsigned int);

    /*struct _Invoke {
    PATCH_MEMBER_INVOKE(CNSNpcManager &, CNSNpcManager, Constructor, );
    PATCH_MEMBER_INVOKE(void, CNSNpcManager, Destructor, );
    PATCH_MEMBER_INVOKE(void, CNSNpcManager, Action, );
    PATCH_MEMBER_INVOKE(int, CNSNpcManager, Init, );
    PATCH_MEMBER_INVOKE(unsigned long, CNSNpcManager, GetCount, );
    PATCH_MEMBER_INVOKE(void, CNSNpcManager, Add, unsigned long _COMMA CNSNpc *);
    PATCH_MEMBER_INVOKE(int, CNSNpcManager, Delete, unsigned long);
    PATCH_MEMBER_INVOKE(CNSNpc *, CNSNpcManager, Create, unsigned short _COMMA unsigned char _COMMA NSPOINT2 & _COMMA unsigned short _COMMA NSPOINT2 & _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned long _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSNpcManager, Create, CNSNpcParams::_NpcArrange *);
    PATCH_MEMBER_INVOKE(CNSNpc *, CNSNpcManager, CreatePet, unsigned short _COMMA unsigned char _COMMA unsigned char _COMMA unsigned char _COMMA NSPOINT2 & _COMMA unsigned short _COMMA NSPOINT2 & _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned long);
    PATCH_MEMBER_INVOKE(CNSNpc *, CNSNpcManager, CreateTester, unsigned short);
    PATCH_MEMBER_INVOKE(void, CNSNpcManager, Process, );
    PATCH_MEMBER_INVOKE(void, CNSNpcManager, Arrange, );
    PATCH_MEMBER_INVOKE(void, CNSNpcManager, ArrangeInstantNpc, unsigned long);
    PATCH_MEMBER_INVOKE(void, CNSNpcManager, DeleteInstantNpc, unsigned long);
    PATCH_MEMBER_INVOKE(int, CNSNpcManager, CheckNpc, unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char);
    PATCH_MEMBER_INVOKE(unsigned long, CNSNpcManager, GetNpcCount, unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char);
    PATCH_MEMBER_INVOKE(int, CNSNpcManager, GetNpcPos, unsigned short _COMMA NSPOINT2 & _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char);
    PATCH_MEMBER_INVOKE(unsigned long, CNSNpcManager, GetBlockCount, unsigned char _COMMA int);
    PATCH_MEMBER_INVOKE(unsigned long, CNSNpcManager, DisappearNpc, unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char);
    PATCH_MEMBER_INVOKE(unsigned long, CNSNpcManager, DeleteNpc, unsigned short);
    PATCH_MEMBER_INVOKE(unsigned long, CNSNpcManager, DeleteBlock, unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char);
    PATCH_MEMBER_INVOKE(unsigned long, CNSNpcManager, GetInNpcHpPercent, unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned long);
    PATCH_MEMBER_INVOKE(CNSNpc *, CNSNpcManager, CallMob, unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(unsigned long, CNSNpcManager, PacketBlockInfo, CPacket &);
    PATCH_MEMBER_INVOKE(void, CNSNpcManager, BroadcastEnterMessage_PVPTournamentZone, );
    PATCH_MEMBER_INVOKE(void, CNSNpcManager, DebugBlockPrint, CNSPc *);
    PATCH_MEMBER_INVOKE(void, CNSNpcManager, DebugNpcPrint, CNSPc * _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(void, CNSNpcManager, AttackRectInNpc, unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(void, CNSNpcManager, AwakeRectInNpc, unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char _COMMA int);
    PATCH_MEMBER_INVOKE(void, CNSNpcManager, HealRectInNpc, unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char);
    PATCH_MEMBER_INVOKE(int, CNSNpcManager, IsExistBlock, unsigned short _COMMA unsigned short _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(void, CNSNpcManager, DBBlockLoad, );
    PATCH_MEMBER_INVOKE(void, CNSNpcManager, DBBlockSave, );
    PATCH_MEMBER_INVOKE(unsigned long, CNSNpcManager, GetRealmCastle, unsigned char);
    PATCH_MEMBER_INVOKE(CFiniteStateMachine *, CNSNpcManager, AllocStateMachine, CNSNpc *);
    PATCH_MEMBER_INVOKE(void, CNSNpcManager, NpcAction, CNSNpc * _COMMA unsigned long _COMMA unsigned long);
    };*/
};
#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(CNSNpcManager::Constructor(), 0x44CD20);
//DEFINE_NAKED_JMP(CNSNpcManager::Destructor(), 0x44CE10);
DEFINE_NAKED_JMP(void CNSNpcManager::Action(), 0x450170);
DEFINE_NAKED_JMP(int CNSNpcManager::Init(), 0x44CF50);
DEFINE_NAKED_JMP(unsigned long CNSNpcManager::GetCount(), 0x44CF80);
DEFINE_NAKED_JMP(void CNSNpcManager::Add(unsigned long _COMMA CNSNpc *), 0x44EA30);
DEFINE_NAKED_JMP(int CNSNpcManager::Delete(unsigned long), 0x44EAB0);
DEFINE_NAKED_JMP(CNSNpc * CNSNpcManager::Create(unsigned short _COMMA unsigned char _COMMA NSPOINT2 & _COMMA unsigned short _COMMA NSPOINT2 & _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned long _COMMA unsigned short), 0x44E340);
DEFINE_NAKED_JMP(int CNSNpcManager::Create(CNSNpcParams::_NpcArrange *), 0x44E130);
DEFINE_NAKED_JMP(CNSNpc * CNSNpcManager::CreatePet(unsigned short _COMMA unsigned char _COMMA unsigned char _COMMA unsigned char _COMMA NSPOINT2 & _COMMA unsigned short _COMMA NSPOINT2 & _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned long), 0x44E4E0);
DEFINE_NAKED_JMP(CNSNpc * CNSNpcManager::CreateTester(unsigned short), 0x44E640);
DEFINE_NAKED_JMP(void CNSNpcManager::Process(), 0x44FF70);
DEFINE_NAKED_JMP(void CNSNpcManager::Arrange(), 0x44CFF0);
DEFINE_NAKED_JMP(void CNSNpcManager::ArrangeInstantNpc(unsigned long), 0x44D120);
DEFINE_NAKED_JMP(void CNSNpcManager::DeleteInstantNpc(unsigned long), 0x44D200);
DEFINE_NAKED_JMP(int CNSNpcManager::CheckNpc(unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char), 0x44D7A0);
DEFINE_NAKED_JMP(unsigned long CNSNpcManager::GetNpcCount(unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char), 0x44D9A0);
DEFINE_NAKED_JMP(int CNSNpcManager::GetNpcPos(unsigned short _COMMA NSPOINT2 & _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char), 0x44DB90);
DEFINE_NAKED_JMP(unsigned long CNSNpcManager::GetBlockCount(unsigned char _COMMA int), 0x44DF70);
DEFINE_NAKED_JMP(unsigned long CNSNpcManager::DisappearNpc(unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char), 0x44D5E0);
DEFINE_NAKED_JMP(unsigned long CNSNpcManager::DeleteNpc(unsigned short), 0x44D2F0);
DEFINE_NAKED_JMP(unsigned long CNSNpcManager::DeleteBlock(unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char), 0x44D400);
DEFINE_NAKED_JMP(unsigned long CNSNpcManager::GetInNpcHpPercent(unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned long), 0x44DD90);
DEFINE_NAKED_JMP(CNSNpc * CNSNpcManager::_CallMob(unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short), 0x44E760);
DEFINE_NAKED_JMP(unsigned long CNSNpcManager::PacketBlockInfo(CPacket &), 0x44EB50);
DEFINE_NAKED_JMP(void CNSNpcManager::BroadcastEnterMessage_PVPTournamentZone(), 0x44EBD0);
DEFINE_NAKED_JMP(void CNSNpcManager::DebugBlockPrint(CNSPc *), 0x44ECD0);
DEFINE_NAKED_JMP(void CNSNpcManager::DebugNpcPrint(CNSPc * _COMMA unsigned short), 0x44ED50);
DEFINE_NAKED_JMP(void CNSNpcManager::AttackRectInNpc(unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char _COMMA unsigned short), 0x44EEB0);
DEFINE_NAKED_JMP(void CNSNpcManager::AwakeRectInNpc(unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char _COMMA int), 0x44F070);
DEFINE_NAKED_JMP(void CNSNpcManager::HealRectInNpc(unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char), 0x44F220);
DEFINE_NAKED_JMP(int CNSNpcManager::IsExistBlock(unsigned short _COMMA unsigned short _COMMA unsigned short), 0x44F400);
DEFINE_NAKED_JMP(void CNSNpcManager::DBBlockLoad(), 0x44F550);
DEFINE_NAKED_JMP(void CNSNpcManager::DBBlockSave(), 0x44F9C0);
DEFINE_NAKED_JMP(unsigned long CNSNpcManager::GetRealmCastle(unsigned char), 0x4827B0);
DEFINE_NAKED_JMP(CFiniteStateMachine * CNSNpcManager::AllocStateMachine(CNSNpc *), 0x44E820);
DEFINE_NAKED_JMP(void CNSNpcManager::NpcAction(CNSNpc * _COMMA unsigned long _COMMA unsigned long), 0x4504D0);
#endif







#endif