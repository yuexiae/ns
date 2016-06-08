#ifndef NSHEADER_NS_DB_MANAGER_H_
#define NSHEADER_NS_DB_MANAGER_H_

#include "ns_header/ns_thread.h"
#include "ns_header/ns_ch_socket.h"
#include "ns_header/ns_odbc.h"
#include <queue>
#include <sqltypes.h>



class CNSSessionPc;
class CNSDbManager;

template<>
class CSingleton<CNSDbManager> {
public:
    static const unsigned int _size = 0x1;
    static CNSDbManager * GetInstance();    PATCH_STATIC(CNSDbManager *, GetInstance, , 0x402DF0);
    static void ReleaseInstance();    PATCH_STATIC(void, ReleaseInstance, , 0x402E80);
    static class CNSDbManager * m_selfInstance;//[0x559DF4]  [00159DF4:0003:00039DF4]

    /*struct _Invoke {
    PATCH_STATIC_INVOKE(CNSDbManager *, GetInstance, );
    PATCH_STATIC_INVOKE(void, ReleaseInstance, );
    };*/
};

#ifdef DEFINE_NS_CPP
DEFINE_NAKED_JMP(CNSDbManager * CSingleton<CNSDbManager>::GetInstance(), 0x402DF0);
//DEFINE_NAKED_JMP(void CSingleton<CNSDbManager>::ReleaseInstance(), 0x402E80);
#endif


class CNSDbManager : public CThread, public CSingleton<CNSDbManager> {
public:
    static const unsigned int _size = 0x7a74;

    enum SAVEPCMODE {
        SavePcMode_Auto =  0x0,
        SavePcMode_Logout =  0x1,
        SavePcMode_SessionLogout =  0x2,
        SavePcMode_ServerMove =  0x3,
        SavePcMode_Destroy =  0x4,
        SavePcMode_LimitLogout =  0x5,
    };

    CNSDbManager(const CNSDbManager &);
    CNSDbManager();    PATCH_MEMBER(CNSDbManager &, Constructor, , 0x42C6D0);
    virtual ~CNSDbManager();    PATCH_MEMBER(void, Destructor, , 0x42C8B0);
    virtual void Action();    PATCH_MEMBER(void, Action, , 0x42DF00);
    void ConfigDb(char *, char *, char *, char *);    PATCH_MEMBER(void, ConfigDb, char * _COMMA char * _COMMA char * _COMMA char *, 0x42CBF0);
    int Init();    PATCH_MEMBER(int, Init, , 0x42C9B0);
    void Stop();    PATCH_MEMBER(void, Stop, , 0x42CC70);
    SteamEngine::Win32::DB::COdbc * GetDb();    PATCH_MEMBER(COdbc *, GetDb, , 0x414F50);
    int GetDbCheck();    PATCH_MEMBER(int, GetDbCheck, , 0x4C9450);
    int DbCheck();    PATCH_MEMBER(int, DbCheck, , 0x42D630);
    void AddDbSession(CNSSessionPc *, CPacket &);    PATCH_MEMBER(void, AddDbSession, CNSSessionPc * _COMMA CPacket &, 0x42D0A0);
    unsigned long DeleteDbSession(CNSSessionPc *);    PATCH_MEMBER(unsigned long, DeleteDbSession, CNSSessionPc *, 0x42D110);
    void AddDbSavePc(CNSDbManager::SAVEPCMODE, CNSPc *);    PATCH_MEMBER(void, AddDbSavePc, CNSDbManager::SAVEPCMODE _COMMA CNSPc *, 0x42D480);
    unsigned long GetCount();    PATCH_MEMBER(unsigned long, GetCount, , 0x4022B0);
    unsigned char GetEventFlag(int);    PATCH_MEMBER(unsigned char, GetEventFlag, int, 0x42DDE0);
    char * GetTodayEventComment();    PATCH_MEMBER(char *, GetTodayEventComment, , 0x42DE40);
    void DbLogWrite(char *, ...);    PATCH_MEMBER(void, DbLogWrite, char * _COMMA ..., 0x42D710);
    int SocketBillSend(int, CNSPc *, char *, int, char *, int, unsigned short);    PATCH_MEMBER(int, SocketBillSend, int _COMMA CNSPc * _COMMA char * _COMMA int _COMMA char * _COMMA int _COMMA unsigned short, 0x484A10);
    int SocketChannelBillSend(int, CNSPc *, char *, int, char *, int, unsigned short);
    void SocketClose();
    unsigned long m_dwLagTest;//this+0x10
    int m_bThreadLoop;//this+0x14
    class SteamEngine::Win32::DB::COdbc * m_pDb;//this+0x18
    struct _SavePc {
        static const unsigned int _size = 0x8;
        enum CNSDbManager::SAVEPCMODE mode;//this+0x0
        class CNSPc * pPc;//this+0x4
    };
    struct _EventParams {
        static const unsigned int _size = 0x8;
        int nEventId;//this+0x0
        unsigned char btFlag;//this+0x4
    };

    struct _DateEventParams {
        static const unsigned int _size = 0x110;
        struct tagTIMESTAMP_STRUCT tsEventDate;//this+0x0
        char szComment[0x100];//this+0x10
    };

    class std::multimap<CNSSessionPc *,CPacket *,std::less<CNSSessionPc *>,std::allocator<std::pair<CNSSessionPc * const,CPacket *> > > m_mapDbSession;//this+0x1C
    class CNSCriticalSection m_csMapDbSession;//this+0x3C
    class std::queue<CNSDbManager::_SavePc *,std::deque<CNSDbManager::_SavePc *,std::allocator<CNSDbManager::_SavePc *> > > m_queueDbSavePc;//this+0x458
    class CNSCriticalSection m_csQueueDbSavePc;//this+0x478
    struct CNSDbManager::_EventParams m_eventParamsArray[0x64];//this+0x894
    struct CNSDbManager::_DateEventParams m_dateEventParamsArray[0x64];//this+0xBB4
    char m_szServerName[0x100];//this+0x75F4
    char m_szDbName[0x100];//this+0x76F4
    char m_szUserId[0x100];//this+0x77F4
    char m_szPassword[0x100];//this+0x78F4
    class SteamEngine::Win32::System::CCriticalSection m_csSock[0x2];//this+0x79F4
    class CChSocket m_Socket[0x2];//this+0x7A2C
    int m_bDbCheck;//this+0x7A6C
    unsigned long m_dwLastCheckTime;//this+0x7A70
    void DbSavePc(CNSDbManager::_SavePc *);    PATCH_MEMBER(void, DbSavePc, CNSDbManager::_SavePc *, 0x42D530);
    void _ProcessSession(CNSSessionPc *, CPacket *);    PATCH_MEMBER(void, _ProcessSession, CNSSessionPc * _COMMA CPacket *, 0x42D220);
    int ProcessDbSession();    PATCH_MEMBER(int, ProcessDbSession, , 0x42D330);
    int ProcessDbSavePc();    PATCH_MEMBER(int, ProcessDbSavePc, , 0x42DCE0);
    void DbLoadEventParams();    PATCH_MEMBER(void, DbLoadEventParams, , 0x42D8B0);
    void DbLoadDateEventParams();    PATCH_MEMBER(void, DbLoadDateEventParams, , 0x42DAC0);
    int SocketInit(int);    PATCH_MEMBER(int, SocketInit, int, 0x42CAF0);
    int _SocketBillSend(int, int, CNSPc *, char *, int, char *, int, unsigned short);    PATCH_MEMBER(int, _SocketBillSend, int _COMMA int _COMMA CNSPc * _COMMA char * _COMMA int _COMMA char * _COMMA int _COMMA unsigned short, 0x42CC90);
    CNSDbManager & operator=(const CNSDbManager &);
    //void __local_vftable_ctor_closure();
    //virtual void * __vecDelDtor(unsigned int);

    struct _Invoke {
        //PATCH_MEMBER_INVOKE(CNSDbManager &, CNSDbManager, Constructor, );
        //PATCH_MEMBER_INVOKE(void, CNSDbManager, Destructor, );
        //PATCH_MEMBER_INVOKE(void, CNSDbManager, Action, );
        //PATCH_MEMBER_INVOKE(void, CNSDbManager, ConfigDb, char * _COMMA char * _COMMA char * _COMMA char *);
        PATCH_MEMBER_INVOKE(int, CNSDbManager, Init, );
        //PATCH_MEMBER_INVOKE(void, CNSDbManager, Stop, );
        //PATCH_MEMBER_INVOKE(COdbc *, CNSDbManager, GetDb, );
        //PATCH_MEMBER_INVOKE(int, CNSDbManager, GetDbCheck, );
        //PATCH_MEMBER_INVOKE(int, CNSDbManager, DbCheck, );
        PATCH_MEMBER_INVOKE(void, CNSDbManager, AddDbSession, CNSSessionPc * _COMMA CPacket &);
        //PATCH_MEMBER_INVOKE(unsigned long, CNSDbManager, DeleteDbSession, CNSSessionPc *);
        PATCH_MEMBER_INVOKE(void, CNSDbManager, AddDbSavePc, CNSDbManager::SAVEPCMODE _COMMA CNSPc *);
        //PATCH_MEMBER_INVOKE(unsigned long, CNSDbManager, GetCount, );
        //PATCH_MEMBER_INVOKE(unsigned char, CNSDbManager, GetEventFlag, int);
        //PATCH_MEMBER_INVOKE(char *, CNSDbManager, GetTodayEventComment, );
        //PATCH_MEMBER_INVOKE(void, CNSDbManager, DbLogWrite, char * _COMMA ...);
        //PATCH_MEMBER_INVOKE(int, CNSDbManager, SocketBillSend, int _COMMA CNSPc * _COMMA char * _COMMA int _COMMA char * _COMMA int _COMMA unsigned short);
        //PATCH_MEMBER_INVOKE(void, CNSDbManager, DbSavePc, CNSDbManager::_SavePc *);
        //PATCH_MEMBER_INVOKE(void, CNSDbManager, _ProcessSession, CNSSessionPc * _COMMA CPacket *);
        //PATCH_MEMBER_INVOKE(int, CNSDbManager, ProcessDbSession, );
        //PATCH_MEMBER_INVOKE(int, CNSDbManager, ProcessDbSavePc, );
        //PATCH_MEMBER_INVOKE(void, CNSDbManager, DbLoadEventParams, );
        //PATCH_MEMBER_INVOKE(void, CNSDbManager, DbLoadDateEventParams, );
        //PATCH_MEMBER_INVOKE(int, CNSDbManager, SocketInit, int);
        //PATCH_MEMBER_INVOKE(int, CNSDbManager, _SocketBillSend, int _COMMA int _COMMA CNSPc * _COMMA char * _COMMA int _COMMA char * _COMMA int _COMMA unsigned short);
    };
};

#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(CNSDbManager::Constructor(), 0x42C6D0);
//DEFINE_NAKED_JMP(CNSDbManager::Destructor(), 0x42C8B0);
DEFINE_NAKED_JMP(void CNSDbManager::Action(), 0x42DF00);
DEFINE_NAKED_JMP(void CNSDbManager::ConfigDb(char * _COMMA char * _COMMA char * _COMMA char *), 0x42CBF0);
DEFINE_NAKED_JMP(int CNSDbManager::Init(), 0x42C9B0);
DEFINE_NAKED_JMP(void CNSDbManager::Stop(), 0x42CC70);
DEFINE_NAKED_JMP(SteamEngine::Win32::DB::COdbc * CNSDbManager::GetDb(), 0x414F50);
DEFINE_NAKED_JMP(int CNSDbManager::GetDbCheck(), 0x4C9450);
DEFINE_NAKED_JMP(int CNSDbManager::DbCheck(), 0x42D630);
DEFINE_NAKED_JMP(void CNSDbManager::AddDbSession(CNSSessionPc * _COMMA CPacket &), 0x42D0A0);
DEFINE_NAKED_JMP(unsigned long CNSDbManager::DeleteDbSession(CNSSessionPc *), 0x42D110);
DEFINE_NAKED_JMP(void CNSDbManager::AddDbSavePc(CNSDbManager::SAVEPCMODE _COMMA CNSPc *), 0x42D480);
DEFINE_NAKED_JMP(unsigned long CNSDbManager::GetCount(), 0x4022B0);
DEFINE_NAKED_JMP(unsigned char CNSDbManager::GetEventFlag(int), 0x42DDE0);
DEFINE_NAKED_JMP(char * CNSDbManager::GetTodayEventComment(), 0x42DE40);
DEFINE_NAKED_JMP(void CNSDbManager::DbLogWrite(char * _COMMA ...), 0x42D710);
DEFINE_NAKED_JMP(int CNSDbManager::SocketBillSend(int _COMMA CNSPc * _COMMA char * _COMMA int _COMMA char * _COMMA int _COMMA unsigned short), 0x484A10);
DEFINE_NAKED_JMP(void CNSDbManager::DbSavePc(CNSDbManager::_SavePc *), 0x42D530);
DEFINE_NAKED_JMP(void CNSDbManager::_ProcessSession(CNSSessionPc * _COMMA CPacket *), 0x42D220);
DEFINE_NAKED_JMP(int CNSDbManager::ProcessDbSession(), 0x42D330);
DEFINE_NAKED_JMP(int CNSDbManager::ProcessDbSavePc(), 0x42DCE0);
DEFINE_NAKED_JMP(void CNSDbManager::DbLoadEventParams(), 0x42D8B0);
DEFINE_NAKED_JMP(void CNSDbManager::DbLoadDateEventParams(), 0x42DAC0);
DEFINE_NAKED_JMP(int CNSDbManager::SocketInit(int), 0x42CAF0);
DEFINE_NAKED_JMP(int CNSDbManager::_SocketBillSend(int _COMMA int _COMMA CNSPc * _COMMA char * _COMMA int _COMMA char * _COMMA int _COMMA unsigned short), 0x42CC90);
#endif



#endif