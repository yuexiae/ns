#ifndef NSHEADER_NS_CSESSION_MANAGER_H_
#define NSHEADER_NS_CSESSION_MANAGER_H_


class CSessionManagerExt;

namespace SteamEngine { namespace Win32 { namespace Net {

class CSessionManager;

template <>
class CSingleton<CSessionManager> {
public:
    static const unsigned int _size = 0x1;

    static CSessionManagerExt * GetInstance();    PATCH_STATIC(CSessionManager *, GetInstance, , 0x402D10);
    static void ReleaseInstance();    PATCH_STATIC(void, ReleaseInstance, , 0x402DA0);
    static class CSessionManager * m_selfInstance;//[0x559DF0]  [00159DF0:0003:00039DF0]

/*struct _Invoke {
PATCH_STATIC_INVOKE(CSessionManager *, GetInstance, );
PATCH_STATIC_INVOKE(void, ReleaseInstance, );
};*/
};


class CSessionManager : public CThread, public CSingleton<CSessionManager> {
public:
    static const unsigned int _size = 0x64;

    enum {
        GHOST_CHECK_TIME_MS = 0x36EE80,
        GHOST_CONNECT_CHECK_TIME_MS = 0xFFFFEA60,
    };

    struct _socketBuff {
        static const unsigned int _size = 0xc;

        unsigned long dwCompletionKey;//this+0x0
        unsigned char * pBuff;//this+0x4
        int dwLength;//this+0x8
    };

    unsigned long m_dwSendCount;//this+0x10
    unsigned long m_dwWriteBytes;//this+0x14
    unsigned long m_dwStartTick;//this+0x18
    static unsigned char ms_btServerIpArray[0x4];//[0x55B8D0]  [0015B8D0:0003:0003B8D0]
    CSessionManager(const CSessionManager &);
    CSessionManager();    PATCH_MEMBER(CSessionManager &, Constructor, , 0x4120B0);
    virtual ~CSessionManager();    PATCH_MEMBER(void, Destructor, , 0x4121E0);
    void Init(CSession *(__cdecl *FuncAllocator)());    PATCH_MEMBER(void, Init, CSession *(__cdecl *FuncAllocator)(), 0x4129B0);
    int InitSession(unsigned int, CSession *);    PATCH_MEMBER(int, InitSession, unsigned int _COMMA CSession *, 0x412510);
    CSession * CreateNewSession(unsigned long, unsigned int);    PATCH_MEMBER(CSession *, CreateNewSession, unsigned long _COMMA unsigned int, 0x412620);
    void RemoveSession(CSession *);    PATCH_MEMBER(void, RemoveSession, CSession *, 0x412850);
    unsigned long GetCount();    PATCH_MEMBER(unsigned long, GetCount, , 0x412430);
    unsigned long GetFreeQueueCount();    PATCH_MEMBER(unsigned long, GetFreeQueueCount, , 0x4124A0);
    void GhostCheck();    PATCH_MEMBER(void, GhostCheck, , 0x412A50);
    void GhostConnectCheck();    PATCH_MEMBER(void, GhostConnectCheck, , 0x412B70);
    unsigned long ProcessSendQueue();
    virtual void Action();    PATCH_MEMBER(void, Action, , 0x412CB0);
    int _SendQueue(CSession *);
    void SetGhostConnectCheck(int);
    int m_bThreadLoop;//this+0x1C
    int m_bGhostConnectCheck;//this+0x20
    class std::list<CSession *,std::allocator<CSession *> > * m_listSession;//this+0x24
    class std::deque<CSession *,std::allocator<CSession *> > * m_dequeFreeSession;//this+0x28
    class SteamEngine::Win32::System::CCriticalSection m_csListSession;//this+0x2C
    class SteamEngine::Win32::System::CCriticalSection m_csDequeFreeSession;//this+0x48
    static CSession *(__cdecl *m_FuncAllocator)();//[0x523104]  [00123104:0003:00003104]
    CSessionManager & operator=(const CSessionManager &);
    //void __local_vftable_ctor_closure();
    //virtual void * __vecDelDtor(unsigned int);

/*struct _Invoke {
PATCH_MEMBER_INVOKE(CSessionManager &, CSessionManager, Constructor, );
PATCH_MEMBER_INVOKE(void, CSessionManager, Destructor, );
PATCH_MEMBER_INVOKE(void, CSessionManager, Init, function  *);
PATCH_MEMBER_INVOKE(int, CSessionManager, InitSession, unsigned int _COMMA CSession *);
PATCH_MEMBER_INVOKE(CSession *, CSessionManager, CreateNewSession, unsigned long _COMMA unsigned int);
PATCH_MEMBER_INVOKE(void, CSessionManager, RemoveSession, CSession *);
PATCH_MEMBER_INVOKE(unsigned long, CSessionManager, GetCount, );
PATCH_MEMBER_INVOKE(unsigned long, CSessionManager, GetFreeQueueCount, );
PATCH_MEMBER_INVOKE(void, CSessionManager, GhostCheck, );
PATCH_MEMBER_INVOKE(void, CSessionManager, GhostConnectCheck, );
PATCH_MEMBER_INVOKE(void, CSessionManager, Action, );
};*/
};
#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(CSessionManager::Constructor(), 0x4120B0);
//DEFINE_NAKED_JMP(CSessionManager::Destructor(), 0x4121E0);
//DEFINE_NAKED_JMP(void CSessionManager::Init(function  *), 0x4129B0);
//DEFINE_NAKED_JMP(int CSessionManager::InitSession(unsigned int _COMMA CSession *), 0x412510);
//DEFINE_NAKED_JMP(CSession * CSessionManager::CreateNewSession(unsigned long _COMMA unsigned int), 0x412620);
DEFINE_NAKED_JMP(void CSessionManager::RemoveSession(CSession *), 0x412850);
DEFINE_NAKED_JMP(unsigned long CSessionManager::GetCount(), 0x412430);
//DEFINE_NAKED_JMP(unsigned long CSessionManager::GetFreeQueueCount(), 0x4124A0);
//DEFINE_NAKED_JMP(void CSessionManager::GhostCheck(), 0x412A50);
//DEFINE_NAKED_JMP(void CSessionManager::GhostConnectCheck(), 0x412B70);
//DEFINE_NAKED_JMP(void CSessionManager::Action(), 0x412CB0);
#endif

}}}//namespace SteamEngine { namespace Win32 { namespace Net {

typedef SteamEngine::Win32::Net::CSessionManager CSessionManager;

#ifdef DEFINE_NS_CPP
DEFINE_NAKED_JMP(CSessionManagerExt * CSingleton<CSessionManager>::GetInstance(), 0x402D10);
//DEFINE_NAKED_JMP(void CSingleton<CSessionManager>::ReleaseInstance(), 0x402DA0);
#endif


#endif