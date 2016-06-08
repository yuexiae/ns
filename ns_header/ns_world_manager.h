#ifndef NSHEADER_NS_WORLD_MANAGER_H_
#define NSHEADER_NS_WORLD_MANAGER_H_

class CNSWorldManager;
class CNSWorldManagerExt;

template <>
class CSingleton<CNSWorldManager> {
public:
    static const unsigned int _size = 0x1;

    static CNSWorldManagerExt * GetInstance();    PATCH_STATIC(CNSWorldManager *, GetInstance, , 0x402ED0);
    static void ReleaseInstance();    PATCH_STATIC(void, ReleaseInstance, , 0x402F60);
    static class CNSWorldManager * m_selfInstance;//[0x559DF8]  [00159DF8:0003:00039DF8]

    /*struct _Invoke {
    PATCH_STATIC_INVOKE(CNSWorldManager *, GetInstance, );
    PATCH_STATIC_INVOKE(void, ReleaseInstance, );
    };*/
};
#ifdef DEFINE_NS_CPP
DEFINE_NAKED_JMP(CNSWorldManagerExt * CSingleton<CNSWorldManager>::GetInstance(), 0x402ED0);
//DEFINE_NAKED_JMP(void CSingleton<CNSWorldManager>::ReleaseInstance(), 0x402F60);
#endif

class CNSWorldManager : public CSingleton<CNSWorldManager> {
public:
    static const unsigned int _size = 0x1a0c;

    struct CNSMapInstant {
        static const unsigned int _size = 0x18;


        CNSMapInstant(const CNSWorldManager::CNSMapInstant &);
        CNSMapInstant();    PATCH_MEMBER(CNSWorldManager::CNSMapInstant &, Constructor, , 0x4E4DA0);
        virtual ~CNSMapInstant();    PATCH_MEMBER(void, Destructor, , 0x4E4DE0);
        int Init(unsigned char);    PATCH_MEMBER(int, Init, unsigned char, 0x4E4EA0);
        void Join(CNSPc *);    PATCH_MEMBER(void, Join, CNSPc *, 0x484160);
        void Exit(CNSPc *);    PATCH_MEMBER(void, Exit, CNSPc *, 0x4E5050);
        unsigned char GetRegion();    PATCH_MEMBER(unsigned char, GetRegion, , 0x450280);
        CNSVrBlockManager * GetVrMap();    PATCH_MEMBER(CNSVrBlockManager *, GetVrMap, , 0x423E70);
        CNSMapManager * GetMap();    PATCH_MEMBER(CNSMapManager *, GetMap, , 0x406500);
        unsigned char m_btRegion;//this+0x4
        long m_nRefCount;//this+0x8
        unsigned long m_dwInstantKey;//this+0xC
        class CNSVrBlockManager * m_pVrMap;//this+0x10
        class CNSMapManager * m_pMap;//this+0x14
        CNSWorldManager::CNSMapInstant & operator=(const CNSWorldManager::CNSMapInstant &);
        //void __local_vftable_ctor_closure();
        //virtual void * __vecDelDtor(unsigned int);

        /*struct _Invoke {
        PATCH_MEMBER_INVOKE(CNSWorldManager::CNSMapInstant &, CNSWorldManager::CNSMapInstant, Constructor, );
        PATCH_MEMBER_INVOKE(void, CNSWorldManager::CNSMapInstant, Destructor, );
        PATCH_MEMBER_INVOKE(int, CNSWorldManager::CNSMapInstant, Init, unsigned char);
        PATCH_MEMBER_INVOKE(void, CNSWorldManager::CNSMapInstant, Join, CNSPc *);
        PATCH_MEMBER_INVOKE(void, CNSWorldManager::CNSMapInstant, Exit, CNSPc *);
        PATCH_MEMBER_INVOKE(unsigned char, CNSWorldManager::CNSMapInstant, GetRegion, );
        PATCH_MEMBER_INVOKE(CNSVrBlockManager *, CNSWorldManager::CNSMapInstant, GetVrMap, );
        PATCH_MEMBER_INVOKE(CNSMapManager *, CNSWorldManager::CNSMapInstant, GetMap, );
        };*/

#ifdef DEFINE_NS_CPP
        //DEFINE_NAKED_JMP(CNSWorldManager::CNSMapInstant::Constructor(), 0x4E4DA0);
        //DEFINE_NAKED_JMP(CNSWorldManager::CNSMapInstant::Destructor(), 0x4E4DE0);
        //DEFINE_NAKED_JMP(int CNSWorldManager::CNSMapInstant::Init(unsigned char), 0x4E4EA0);
        //DEFINE_NAKED_JMP(void CNSWorldManager::CNSMapInstant::Join(CNSPc *), 0x484160);
        //DEFINE_NAKED_JMP(void CNSWorldManager::CNSMapInstant::Exit(CNSPc *), 0x4E5050);
        //DEFINE_NAKED_JMP(unsigned char CNSWorldManager::CNSMapInstant::GetRegion(), 0x450280);
        //DEFINE_NAKED_JMP(CNSVrBlockManager * CNSWorldManager::CNSMapInstant::GetVrMap(), 0x423E70);
        //DEFINE_NAKED_JMP(CNSMapManager * CNSWorldManager::CNSMapInstant::GetMap(), 0x406500);
#endif
    };

    CNSWorldManager(const CNSWorldManager &);
    CNSWorldManager();    PATCH_MEMBER(CNSWorldManager &, Constructor, , 0x4E3250);
    virtual ~CNSWorldManager();    PATCH_MEMBER(void, Destructor, , 0x4E33F0);
    virtual int Init();    PATCH_MEMBER(int, Init, , 0x4E3520);
    void Config(unsigned char);    PATCH_MEMBER(void, Config, unsigned char, 0x4E39E0);
    void ConfigMainServer(unsigned char, unsigned char *, int);    PATCH_MEMBER(void, ConfigMainServer, unsigned char _COMMA unsigned char * _COMMA int, 0x4E3B50);
    void ConfigSubServer(unsigned char *, int);    PATCH_MEMBER(void, ConfigSubServer, unsigned char * _COMMA int, 0x4E3BA0);
    int IsRVRServer();    PATCH_MEMBER(int, IsRVRServer, , 0x404AD0);
    int IsMainServer(unsigned char);    PATCH_MEMBER(int, IsMainServer, unsigned char, 0x436750);
    int IsSubServer(unsigned char);    PATCH_MEMBER(int, IsSubServer, unsigned char, 0x483FB0);
    int IsRealmServer();
    int IsRVRServerFull(unsigned char);    PATCH_MEMBER(int, IsRVRServerFull, unsigned char, 0x483FE0);
    int IsMainServerFull(unsigned char, unsigned char);    PATCH_MEMBER(int, IsMainServerFull, unsigned char _COMMA unsigned char, 0x484030);
    unsigned char GetRegion();    PATCH_MEMBER(unsigned char, GetRegion, , 0x402320);
    void GetMainServer(unsigned char, unsigned char *, int &);    PATCH_MEMBER(void, GetMainServer, unsigned char _COMMA unsigned char * _COMMA int &, 0x4E3BE0);
    void GetSubServer(unsigned char *, int &);    PATCH_MEMBER(void, GetSubServer, unsigned char * _COMMA int &, 0x4E3C30);
    void DebugServerUserPrint(CNSPc *);    PATCH_MEMBER(void, DebugServerUserPrint, CNSPc *, 0x4E3E20);
    void UpdateUserCount(unsigned char *, int, unsigned short *);    PATCH_MEMBER(void, UpdateUserCount, unsigned char * _COMMA int _COMMA unsigned short *, 0x4E3C70);
    int CheckMyWorldIp(unsigned char *, int);    PATCH_MEMBER(int, CheckMyWorldIp, unsigned char * _COMMA int, 0x4E3D80);
    CNSVrBlockManager * GetVrMap(unsigned char);    PATCH_MEMBER(CNSVrBlockManager *, GetVrMap, unsigned char, 0x4E3A00);
    CNSMapManager * GetMap(unsigned char);    PATCH_MEMBER(CNSMapManager *, GetMap, unsigned char, 0x4E3A60);
    int GetRegionSize(unsigned char, unsigned short &, unsigned short &);    PATCH_MEMBER(int, GetRegionSize, unsigned char _COMMA unsigned short & _COMMA unsigned short &, 0x4E3AC0);
    unsigned long GetPcProcessTime();    PATCH_MEMBER(unsigned long, GetPcProcessTime, , 0x402340);
    unsigned long GetNpcProcessTime();    PATCH_MEMBER(unsigned long, GetNpcProcessTime, , 0x402380);
    unsigned long GetDbProcessTime();    PATCH_MEMBER(unsigned long, GetDbProcessTime, , 0x4023C0);
    unsigned long GetPcProcessCount();    PATCH_MEMBER(unsigned long, GetPcProcessCount, , 0x402400);
    unsigned long GetNpcProcessCount();    PATCH_MEMBER(unsigned long, GetNpcProcessCount, , 0x402440);
    unsigned long GetDbProcessCount();    PATCH_MEMBER(unsigned long, GetDbProcessCount, , 0x402480);
    void SetPcProcessTime(unsigned long);    PATCH_MEMBER(void, SetPcProcessTime, unsigned long, 0x48BFA0);
    void SetNpcProcessTime(unsigned long);    PATCH_MEMBER(void, SetNpcProcessTime, unsigned long, 0x48BFF0);
    void SetDbProcessTime(unsigned long);    PATCH_MEMBER(void, SetDbProcessTime, unsigned long, 0x42E1D0);
    unsigned long AddInstant(CNSWorldManager::CNSMapInstant *);    PATCH_MEMBER(unsigned long, AddInstant, CNSWorldManager::CNSMapInstant *, 0x4E4B60);
    void DeleteInstant(unsigned long);    PATCH_MEMBER(void, DeleteInstant, unsigned long, 0x4E4C40);
    CNSWorldManager::CNSMapInstant * GetInstantMap(unsigned long);    PATCH_MEMBER(CNSWorldManager::CNSMapInstant *, GetInstantMap, unsigned long, 0x4E4CD0);
    int SocketSendMain(unsigned char, CPacket &);    PATCH_MEMBER(int, SocketSendMain, unsigned char _COMMA CPacket &, 0x4E4330);
    int SocketSendSub(unsigned char, CPacket &);    PATCH_MEMBER(int, SocketSendSub, unsigned char _COMMA CPacket &, 0x4E4380);
    int SocketSendRegion(unsigned char, CPacket &);    PATCH_MEMBER(int, SocketSendRegion, unsigned char _COMMA CPacket &, 0x4E4400);
    void RVRStart();    PATCH_MEMBER(void, RVRStart, , 0x4E4550);
    void RVREnd();    PATCH_MEMBER(void, RVREnd, , 0x4E45F0);
    int IsRVRStart();    PATCH_MEMBER(int, IsRVRStart, , 0x428660);
    int CheckCurrentRVREnd();    PATCH_MEMBER(int, CheckCurrentRVREnd, , 0x4E4630);
    unsigned char GetFortressRealm(unsigned long);    PATCH_MEMBER(unsigned char, GetFortressRealm, unsigned long, 0x429630);
    void SetFortressRealm(unsigned long, unsigned char);    PATCH_MEMBER(void, SetFortressRealm, unsigned long _COMMA unsigned char, 0x4B09B0);
    unsigned char GetOldFortressRealm(unsigned long);    PATCH_MEMBER(unsigned char, GetOldFortressRealm, unsigned long, 0x4B09D0);
    void SetOneTownMode(unsigned char);    PATCH_MEMBER(void, SetOneTownMode, unsigned char, 0x404AF0);
    void SetTotalPVPMode();    PATCH_MEMBER(void, SetTotalPVPMode, , 0x404B10);
    void SetRVRServerMode();    PATCH_MEMBER(void, SetRVRServerMode, , 0x404B30);
    void SetPVPTournament();    PATCH_MEMBER(void, SetPVPTournament, , 0x404B50);
    void SetPSWStopMode(int);    PATCH_MEMBER(void, SetPSWStopMode, int, 0x4C8440);
    void SetPVEServerMode();    PATCH_MEMBER(void, SetPVEServerMode, , 0x404B70);
    int IsOneTownMode(unsigned char);    PATCH_MEMBER(int, IsOneTownMode, unsigned char, 0x404B90);
    int IsTotalPVPMode();    PATCH_MEMBER(int, IsTotalPVPMode, , 0x404BB0);
    int IsRVRServerMode();    PATCH_MEMBER(int, IsRVRServerMode, , 0x404BD0);
    int IsPVPTournamentMode();    PATCH_MEMBER(int, IsPVPTournamentMode, , 0x404BF0);
    int IsPSWStopMode();    PATCH_MEMBER(int, IsPSWStopMode, , 0x4C8460);
    int IsPVEServerMode();    PATCH_MEMBER(int, IsPVEServerMode, , 0x404C10);
    void PVPTournamentStart();    PATCH_MEMBER(void, PVPTournamentStart, , 0x4B0970);
    void PVPTournamentEnd();    PATCH_MEMBER(void, PVPTournamentEnd, , 0x4B0990);
    int IsPVPTournamentStart();    PATCH_MEMBER(int, IsPVPTournamentStart, , 0x429A40);
    unsigned char * GetMainServerIp(unsigned char);    PATCH_MEMBER(unsigned char *, GetMainServerIp, unsigned char, 0x484400);
    int GetMainServerPort(unsigned char);    PATCH_MEMBER(int, GetMainServerPort, unsigned char, 0x484430);
    void DBFortressSave(int);    PATCH_MEMBER(void, DBFortressSave, int, 0x4E48D0);
    struct _Server {
        static const unsigned int _size = 0x10;

        unsigned char btServerIpArray[0x4];//this+0x0
        int nServerPort;//this+0x4
        unsigned short wUserCountArray[0x3];//this+0x8
    };

    class CNSCriticalSection m_cs;//this+0x4
    class CNSCriticalSection m_csInMap;//this+0x420
    unsigned char m_btRegion;//this+0x83C
    class CNSVrBlockManager * m_pVrMap[0x5];//this+0x840
    class CNSMapManager * m_pMap[0x5];//this+0x854
    struct CNSWorldManager::_Server m_mainServer[0x3];//this+0x868
    struct CNSWorldManager::_Server m_subServer;//this+0x898
    unsigned long m_dwPcProcessTime;//this+0x8A8
    unsigned long m_dwPcProcessCount;//this+0x8AC
    unsigned long m_dwNpcProcessTime;//this+0x8B0
    unsigned long m_dwNpcProcessCount;//this+0x8B4
    unsigned long m_dwDbProcessTime;//this+0x8B8
    unsigned long m_dwDbProcessCount;//this+0x8BC
    int m_bMapInstancedUsed[0x3E8];//this+0x8C0
    class std::map<unsigned long,CNSWorldManager::CNSMapInstant *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const ,CNSWorldManager::CNSMapInstant *> > > m_mapInstant;//this+0x1860
    class SteamEngine::Win32::System::CCriticalSection m_csSock[0x5];//this+0x1880
    class CChSocket m_Socket[0x5];//this+0x190C
    int m_bRVRStart;//this+0x19AC
    unsigned short m_wRVREndDate;//this+0x19B0
    unsigned char m_btFortressArray[0x14];//this+0x19B2
    unsigned char m_btOldFortressArray[0x14];//this+0x19C6
    unsigned long m_dwFortressCount;//this+0x19DC
    int m_bOneTownMode[0x5];//this+0x19E0
    int m_bTotalPVPMode;//this+0x19F4
    int m_bRVRServerMode;//this+0x19F8
    int m_bPVPTournamentMode;//this+0x19FC
    int m_bPVEServerMode;//this+0x1A00
    int m_bPVPTournamentStart;//this+0x1A04
    int m_bPSWStopMode;//this+0x1A08
    int SocketInit(unsigned char);    PATCH_MEMBER(int, SocketInit, unsigned char, 0x4E3ED0);
    int _SocketSend(unsigned char, CPacket &);    PATCH_MEMBER(int, _SocketSend, unsigned char _COMMA CPacket &, 0x4E41E0);
    int SocketRecv(unsigned char, CPacket &);    PATCH_MEMBER(int, SocketRecv, unsigned char _COMMA CPacket &, 0x4E4430);
    int DBFortressLoad();    PATCH_MEMBER(int, DBFortressLoad, , 0x4E46A0);
    CNSWorldManager & operator=(const CNSWorldManager &);
    //void __local_vftable_ctor_closure();
    //virtual void * __vecDelDtor(unsigned int);

    /*struct _Invoke {
    PATCH_MEMBER_INVOKE(CNSWorldManager &, CNSWorldManager, Constructor, );
    PATCH_MEMBER_INVOKE(void, CNSWorldManager, Destructor, );
    PATCH_MEMBER_INVOKE(int, CNSWorldManager, Init, );
    PATCH_MEMBER_INVOKE(void, CNSWorldManager, Config, unsigned char);
    PATCH_MEMBER_INVOKE(void, CNSWorldManager, ConfigMainServer, unsigned char _COMMA unsigned char * _COMMA int);
    PATCH_MEMBER_INVOKE(void, CNSWorldManager, ConfigSubServer, unsigned char * _COMMA int);
    PATCH_MEMBER_INVOKE(int, CNSWorldManager, IsRVRServer, );
    PATCH_MEMBER_INVOKE(int, CNSWorldManager, IsMainServer, unsigned char);
    PATCH_MEMBER_INVOKE(int, CNSWorldManager, IsSubServer, unsigned char);
    PATCH_MEMBER_INVOKE(int, CNSWorldManager, IsRVRServerFull, unsigned char);
    PATCH_MEMBER_INVOKE(int, CNSWorldManager, IsMainServerFull, unsigned char _COMMA unsigned char);
    PATCH_MEMBER_INVOKE(unsigned char, CNSWorldManager, GetRegion, );
    PATCH_MEMBER_INVOKE(void, CNSWorldManager, GetMainServer, unsigned char _COMMA unsigned char * _COMMA int &);
    PATCH_MEMBER_INVOKE(void, CNSWorldManager, GetSubServer, unsigned char * _COMMA int &);
    PATCH_MEMBER_INVOKE(void, CNSWorldManager, DebugServerUserPrint, CNSPc *);
    PATCH_MEMBER_INVOKE(void, CNSWorldManager, UpdateUserCount, unsigned char * _COMMA int _COMMA unsigned short *);
    PATCH_MEMBER_INVOKE(int, CNSWorldManager, CheckMyWorldIp, unsigned char * _COMMA int);
    PATCH_MEMBER_INVOKE(CNSVrBlockManager *, CNSWorldManager, GetVrMap, unsigned char);
    PATCH_MEMBER_INVOKE(CNSMapManager *, CNSWorldManager, GetMap, unsigned char);
    PATCH_MEMBER_INVOKE(int, CNSWorldManager, GetRegionSize, unsigned char _COMMA unsigned short & _COMMA unsigned short &);
    PATCH_MEMBER_INVOKE(unsigned long, CNSWorldManager, GetPcProcessTime, );
    PATCH_MEMBER_INVOKE(unsigned long, CNSWorldManager, GetNpcProcessTime, );
    PATCH_MEMBER_INVOKE(unsigned long, CNSWorldManager, GetDbProcessTime, );
    PATCH_MEMBER_INVOKE(unsigned long, CNSWorldManager, GetPcProcessCount, );
    PATCH_MEMBER_INVOKE(unsigned long, CNSWorldManager, GetNpcProcessCount, );
    PATCH_MEMBER_INVOKE(unsigned long, CNSWorldManager, GetDbProcessCount, );
    PATCH_MEMBER_INVOKE(void, CNSWorldManager, SetPcProcessTime, unsigned long);
    PATCH_MEMBER_INVOKE(void, CNSWorldManager, SetNpcProcessTime, unsigned long);
    PATCH_MEMBER_INVOKE(void, CNSWorldManager, SetDbProcessTime, unsigned long);
    PATCH_MEMBER_INVOKE(unsigned long, CNSWorldManager, AddInstant, CNSWorldManager::CNSMapInstant *);
    PATCH_MEMBER_INVOKE(void, CNSWorldManager, DeleteInstant, unsigned long);
    PATCH_MEMBER_INVOKE(CNSWorldManager::CNSMapInstant *, CNSWorldManager, GetInstantMap, unsigned long);
    PATCH_MEMBER_INVOKE(int, CNSWorldManager, SocketSendMain, unsigned char _COMMA CPacket &);
    PATCH_MEMBER_INVOKE(int, CNSWorldManager, SocketSendSub, unsigned char _COMMA CPacket &);
    PATCH_MEMBER_INVOKE(int, CNSWorldManager, SocketSendRegion, unsigned char _COMMA CPacket &);
    PATCH_MEMBER_INVOKE(void, CNSWorldManager, RVRStart, );
    PATCH_MEMBER_INVOKE(void, CNSWorldManager, RVREnd, );
    PATCH_MEMBER_INVOKE(int, CNSWorldManager, IsRVRStart, );
    PATCH_MEMBER_INVOKE(int, CNSWorldManager, CheckCurrentRVREnd, );
    PATCH_MEMBER_INVOKE(unsigned char, CNSWorldManager, GetFortressRealm, unsigned long);
    PATCH_MEMBER_INVOKE(void, CNSWorldManager, SetFortressRealm, unsigned long _COMMA unsigned char);
    PATCH_MEMBER_INVOKE(unsigned char, CNSWorldManager, GetOldFortressRealm, unsigned long);
    PATCH_MEMBER_INVOKE(void, CNSWorldManager, SetOneTownMode, unsigned char);
    PATCH_MEMBER_INVOKE(void, CNSWorldManager, SetTotalPVPMode, );
    PATCH_MEMBER_INVOKE(void, CNSWorldManager, SetRVRServerMode, );
    PATCH_MEMBER_INVOKE(void, CNSWorldManager, SetPVPTournament, );
    PATCH_MEMBER_INVOKE(void, CNSWorldManager, SetPSWStopMode, int);
    PATCH_MEMBER_INVOKE(void, CNSWorldManager, SetPVEServerMode, );
    PATCH_MEMBER_INVOKE(int, CNSWorldManager, IsOneTownMode, unsigned char);
    PATCH_MEMBER_INVOKE(int, CNSWorldManager, IsTotalPVPMode, );
    PATCH_MEMBER_INVOKE(int, CNSWorldManager, IsRVRServerMode, );
    PATCH_MEMBER_INVOKE(int, CNSWorldManager, IsPVPTournamentMode, );
    PATCH_MEMBER_INVOKE(int, CNSWorldManager, IsPSWStopMode, );
    PATCH_MEMBER_INVOKE(int, CNSWorldManager, IsPVEServerMode, );
    PATCH_MEMBER_INVOKE(void, CNSWorldManager, PVPTournamentStart, );
    PATCH_MEMBER_INVOKE(void, CNSWorldManager, PVPTournamentEnd, );
    PATCH_MEMBER_INVOKE(int, CNSWorldManager, IsPVPTournamentStart, );
    PATCH_MEMBER_INVOKE(unsigned char *, CNSWorldManager, GetMainServerIp, unsigned char);
    PATCH_MEMBER_INVOKE(int, CNSWorldManager, GetMainServerPort, unsigned char);
    PATCH_MEMBER_INVOKE(void, CNSWorldManager, DBFortressSave, int);
    PATCH_MEMBER_INVOKE(int, CNSWorldManager, SocketInit, unsigned char);
    PATCH_MEMBER_INVOKE(int, CNSWorldManager, _SocketSend, unsigned char _COMMA CPacket &);
    PATCH_MEMBER_INVOKE(int, CNSWorldManager, SocketRecv, unsigned char _COMMA CPacket &);
    PATCH_MEMBER_INVOKE(int, CNSWorldManager, DBFortressLoad, );
    };*/
};
#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(CNSWorldManager::Constructor(), 0x4E3250);
//DEFINE_NAKED_JMP(CNSWorldManager::Destructor(), 0x4E33F0);
DEFINE_NAKED_JMP(int CNSWorldManager::Init(), 0x4E3520);
DEFINE_NAKED_JMP(void CNSWorldManager::Config(unsigned char), 0x4E39E0);
DEFINE_NAKED_JMP(void CNSWorldManager::ConfigMainServer(unsigned char _COMMA unsigned char * _COMMA int), 0x4E3B50);
DEFINE_NAKED_JMP(void CNSWorldManager::ConfigSubServer(unsigned char * _COMMA int), 0x4E3BA0);
DEFINE_NAKED_JMP(int CNSWorldManager::IsRVRServer(), 0x404AD0);
DEFINE_NAKED_JMP(int CNSWorldManager::IsMainServer(unsigned char), 0x436750);
DEFINE_NAKED_JMP(int CNSWorldManager::IsSubServer(unsigned char), 0x483FB0);
DEFINE_NAKED_JMP(int CNSWorldManager::IsRVRServerFull(unsigned char), 0x483FE0);
DEFINE_NAKED_JMP(int CNSWorldManager::IsMainServerFull(unsigned char _COMMA unsigned char), 0x484030);
DEFINE_NAKED_JMP(unsigned char CNSWorldManager::GetRegion(), 0x402320);
DEFINE_NAKED_JMP(void CNSWorldManager::GetMainServer(unsigned char _COMMA unsigned char * _COMMA int &), 0x4E3BE0);
DEFINE_NAKED_JMP(void CNSWorldManager::GetSubServer(unsigned char * _COMMA int &), 0x4E3C30);
DEFINE_NAKED_JMP(void CNSWorldManager::DebugServerUserPrint(CNSPc *), 0x4E3E20);
DEFINE_NAKED_JMP(void CNSWorldManager::UpdateUserCount(unsigned char * _COMMA int _COMMA unsigned short *), 0x4E3C70);
DEFINE_NAKED_JMP(int CNSWorldManager::CheckMyWorldIp(unsigned char * _COMMA int), 0x4E3D80);
DEFINE_NAKED_JMP(CNSVrBlockManager * CNSWorldManager::GetVrMap(unsigned char), 0x4E3A00);
DEFINE_NAKED_JMP(CNSMapManager * CNSWorldManager::GetMap(unsigned char), 0x4E3A60);
DEFINE_NAKED_JMP(int CNSWorldManager::GetRegionSize(unsigned char _COMMA unsigned short & _COMMA unsigned short &), 0x4E3AC0);
DEFINE_NAKED_JMP(unsigned long CNSWorldManager::GetPcProcessTime(), 0x402340);
DEFINE_NAKED_JMP(unsigned long CNSWorldManager::GetNpcProcessTime(), 0x402380);
DEFINE_NAKED_JMP(unsigned long CNSWorldManager::GetDbProcessTime(), 0x4023C0);
DEFINE_NAKED_JMP(unsigned long CNSWorldManager::GetPcProcessCount(), 0x402400);
DEFINE_NAKED_JMP(unsigned long CNSWorldManager::GetNpcProcessCount(), 0x402440);
DEFINE_NAKED_JMP(unsigned long CNSWorldManager::GetDbProcessCount(), 0x402480);
DEFINE_NAKED_JMP(void CNSWorldManager::SetPcProcessTime(unsigned long), 0x48BFA0);
DEFINE_NAKED_JMP(void CNSWorldManager::SetNpcProcessTime(unsigned long), 0x48BFF0);
DEFINE_NAKED_JMP(void CNSWorldManager::SetDbProcessTime(unsigned long), 0x42E1D0);
DEFINE_NAKED_JMP(unsigned long CNSWorldManager::AddInstant(CNSWorldManager::CNSMapInstant *), 0x4E4B60);
DEFINE_NAKED_JMP(void CNSWorldManager::DeleteInstant(unsigned long), 0x4E4C40);
DEFINE_NAKED_JMP(CNSWorldManager::CNSMapInstant * CNSWorldManager::GetInstantMap(unsigned long), 0x4E4CD0);
DEFINE_NAKED_JMP(int CNSWorldManager::SocketSendMain(unsigned char _COMMA CPacket &), 0x4E4330);
DEFINE_NAKED_JMP(int CNSWorldManager::SocketSendSub(unsigned char _COMMA CPacket &), 0x4E4380);
DEFINE_NAKED_JMP(int CNSWorldManager::SocketSendRegion(unsigned char _COMMA CPacket &), 0x4E4400);
DEFINE_NAKED_JMP(void CNSWorldManager::RVRStart(), 0x4E4550);
DEFINE_NAKED_JMP(void CNSWorldManager::RVREnd(), 0x4E45F0);
DEFINE_NAKED_JMP(int CNSWorldManager::IsRVRStart(), 0x428660);
DEFINE_NAKED_JMP(int CNSWorldManager::CheckCurrentRVREnd(), 0x4E4630);
DEFINE_NAKED_JMP(unsigned char CNSWorldManager::GetFortressRealm(unsigned long), 0x429630);
DEFINE_NAKED_JMP(void CNSWorldManager::SetFortressRealm(unsigned long _COMMA unsigned char), 0x4B09B0);
DEFINE_NAKED_JMP(unsigned char CNSWorldManager::GetOldFortressRealm(unsigned long), 0x4B09D0);
DEFINE_NAKED_JMP(void CNSWorldManager::SetOneTownMode(unsigned char), 0x404AF0);
DEFINE_NAKED_JMP(void CNSWorldManager::SetTotalPVPMode(), 0x404B10);
DEFINE_NAKED_JMP(void CNSWorldManager::SetRVRServerMode(), 0x404B30);
DEFINE_NAKED_JMP(void CNSWorldManager::SetPVPTournament(), 0x404B50);
DEFINE_NAKED_JMP(void CNSWorldManager::SetPSWStopMode(int), 0x4C8440);
DEFINE_NAKED_JMP(void CNSWorldManager::SetPVEServerMode(), 0x404B70);
DEFINE_NAKED_JMP(int CNSWorldManager::IsOneTownMode(unsigned char), 0x404B90);
DEFINE_NAKED_JMP(int CNSWorldManager::IsTotalPVPMode(), 0x404BB0);
DEFINE_NAKED_JMP(int CNSWorldManager::IsRVRServerMode(), 0x404BD0);
DEFINE_NAKED_JMP(int CNSWorldManager::IsPVPTournamentMode(), 0x404BF0);
DEFINE_NAKED_JMP(int CNSWorldManager::IsPSWStopMode(), 0x4C8460);
DEFINE_NAKED_JMP(int CNSWorldManager::IsPVEServerMode(), 0x404C10);
DEFINE_NAKED_JMP(void CNSWorldManager::PVPTournamentStart(), 0x4B0970);
DEFINE_NAKED_JMP(void CNSWorldManager::PVPTournamentEnd(), 0x4B0990);
DEFINE_NAKED_JMP(int CNSWorldManager::IsPVPTournamentStart(), 0x429A40);
DEFINE_NAKED_JMP(unsigned char * CNSWorldManager::GetMainServerIp(unsigned char), 0x484400);
DEFINE_NAKED_JMP(int CNSWorldManager::GetMainServerPort(unsigned char), 0x484430);
DEFINE_NAKED_JMP(void CNSWorldManager::DBFortressSave(int), 0x4E48D0);
DEFINE_NAKED_JMP(int CNSWorldManager::SocketInit(unsigned char), 0x4E3ED0);
DEFINE_NAKED_JMP(int CNSWorldManager::_SocketSend(unsigned char _COMMA CPacket &), 0x4E41E0);
DEFINE_NAKED_JMP(int CNSWorldManager::SocketRecv(unsigned char _COMMA CPacket &), 0x4E4430);
DEFINE_NAKED_JMP(int CNSWorldManager::DBFortressLoad(), 0x4E46A0);
#endif




#endif