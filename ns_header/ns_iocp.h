#ifndef NSHEADER_NS_IOCP_WORKER_H_
#define NSHEADER_NS_IOCP_WORKER_H_

namespace SteamEngine { namespace Win32 { namespace Net {

class CIOCompletionPort {
public:
    static const unsigned int _size = 0x4;

    CIOCompletionPort(const CIOCompletionPort &);
    CIOCompletionPort(unsigned long);    PATCH_MEMBER(CIOCompletionPort &, Constructor, unsigned long, 0x40DAA0);
    ~CIOCompletionPort();    PATCH_MEMBER(void, Destructor, , 0x40DB10);
    void * GetHandle();    PATCH_MEMBER(void *, GetHandle, , 0x40DB30);
    void AssociateDevice(void *, unsigned long);    PATCH_MEMBER(void, AssociateDevice, void * _COMMA unsigned long, 0x40DB40);
    void PostStatus(unsigned long, unsigned long, _OVERLAPPED *);    PATCH_MEMBER(void, PostStatus, unsigned long _COMMA unsigned long _COMMA _OVERLAPPED *, 0x40DBA0);
    int GetStatus(unsigned long *, unsigned long *, _OVERLAPPED * *, unsigned long);    PATCH_MEMBER(int, GetStatus, unsigned long * _COMMA unsigned long * _COMMA _OVERLAPPED * * _COMMA unsigned long, 0x40DC60);
    void GetStatus(unsigned long *, unsigned long *, _OVERLAPPED * *);    PATCH_MEMBER(void, GetStatus, unsigned long * _COMMA unsigned long * _COMMA _OVERLAPPED * *, 0x40DC00);
    void * m_hIocp;//this+0x0
    CIOCompletionPort & operator=(const CIOCompletionPort &);
    //void * __vecDelDtor(unsigned int);

/*struct _Invoke {
PATCH_MEMBER_INVOKE(CIOCompletionPort &, CIOCompletionPort, Constructor, unsigned long);
PATCH_MEMBER_INVOKE(void, CIOCompletionPort, Destructor, );
PATCH_MEMBER_INVOKE(void *, CIOCompletionPort, GetHandle, );
PATCH_MEMBER_INVOKE(void, CIOCompletionPort, AssociateDevice, void * _COMMA unsigned long);
PATCH_MEMBER_INVOKE(void, CIOCompletionPort, PostStatus, unsigned long _COMMA unsigned long _COMMA _OVERLAPPED *);
PATCH_MEMBER_INVOKE(int, CIOCompletionPort, GetStatus, unsigned long * _COMMA unsigned long * _COMMA _OVERLAPPED * * _COMMA unsigned long);
PATCH_MEMBER_INVOKE(void, CIOCompletionPort, GetStatus, unsigned long * _COMMA unsigned long * _COMMA _OVERLAPPED * *);
};*/
};
#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(CIOCompletionPort::Constructor(unsigned long), 0x40DAA0);
//DEFINE_NAKED_JMP(CIOCompletionPort::Destructor(), 0x40DB10);
//DEFINE_NAKED_JMP(void * CIOCompletionPort::GetHandle(), 0x40DB30);
//DEFINE_NAKED_JMP(void CIOCompletionPort::AssociateDevice(void * _COMMA unsigned long), 0x40DB40);
DEFINE_NAKED_JMP(void CIOCompletionPort::PostStatus(unsigned long _COMMA unsigned long _COMMA _OVERLAPPED *), 0x40DBA0);
DEFINE_NAKED_JMP(int CIOCompletionPort::GetStatus(unsigned long * _COMMA unsigned long * _COMMA _OVERLAPPED * * _COMMA unsigned long), 0x40DC60);
DEFINE_NAKED_JMP(void CIOCompletionPort::GetStatus(unsigned long * _COMMA unsigned long * _COMMA _OVERLAPPED * *), 0x40DC00);
#endif
}}}//namespace SteamEngine { namespace Win32 { namespace Net {

typedef SteamEngine::Win32::Net::CIOCompletionPort CIOCompletionPort;

namespace SteamEngine { namespace Win32 { namespace System {

class CIOCompletionWorker;

class CIOCompletionHandler {
public:
    static const unsigned int _size = 0x10;

    static CIOCompletionHandler * GetInstance();    PATCH_STATIC(CIOCompletionHandler *, GetInstance, , 0x40D710);
    static void ReleaseInstance();    PATCH_STATIC(void, ReleaseInstance, , 0x40D7A0);
    int Init(unsigned long);    PATCH_MEMBER(int, Init, unsigned long, 0x40D7F0);
    unsigned long GetCountWorker();    PATCH_MEMBER(unsigned long, GetCountWorker, , 0x4024C0);
    SteamEngine::Win32::Net::CIOCompletionPort * GetIOCP();    PATCH_MEMBER(CIOCompletionPort *, GetIOCP, , 0x40D990);
    CIOCompletionWorker * GetWorker(int);    PATCH_MEMBER(SteamEngine::Win32::System::CIOCompletionWorker *, GetWorker, int, 0x40D9B0);
    int AssociateDevice(void *, unsigned long);    PATCH_MEMBER(int, AssociateDevice, void * _COMMA unsigned long, 0x40D9D0);
    CIOCompletionHandler(const CIOCompletionHandler &);
    CIOCompletionHandler();    PATCH_MEMBER(CIOCompletionHandler &, Constructor, , 0x40D660);
    virtual ~CIOCompletionHandler();    PATCH_MEMBER(void, Destructor, , 0x40D690);
    static class CIOCompletionHandler * m_selfInstance;//[0x55B0C0]  [0015B0C0:0003:0003B0C0]
    class CIOCompletionPort * IOCP;//this+0x4
    class SteamEngine::Win32::System::CIOCompletionWorker * * WorkerThread;//this+0x8
    unsigned long m_dwMaxWorker;//this+0xC
    CIOCompletionHandler & operator=(const CIOCompletionHandler &);
    //void __local_vftable_ctor_closure();
    //virtual void * __vecDelDtor(unsigned int);

/*struct _Invoke {
PATCH_STATIC_INVOKE(CIOCompletionHandler *, GetInstance, );
PATCH_STATIC_INVOKE(void, ReleaseInstance, );
PATCH_MEMBER_INVOKE(int, CIOCompletionHandler, Init, unsigned long);
PATCH_MEMBER_INVOKE(unsigned long, CIOCompletionHandler, GetCountWorker, );
PATCH_MEMBER_INVOKE(CIOCompletionPort *, CIOCompletionHandler, GetIOCP, );
PATCH_MEMBER_INVOKE(SteamEngine::Win32::System::CIOCompletionWorker *, CIOCompletionHandler, GetWorker, int);
PATCH_MEMBER_INVOKE(int, CIOCompletionHandler, AssociateDevice, void * _COMMA unsigned long);
PATCH_MEMBER_INVOKE(CIOCompletionHandler &, CIOCompletionHandler, Constructor, );
PATCH_MEMBER_INVOKE(void, CIOCompletionHandler, Destructor, );
};*/
};
#ifdef DEFINE_NS_CPP
DEFINE_NAKED_JMP(CIOCompletionHandler * CIOCompletionHandler::GetInstance(), 0x40D710);
//DEFINE_NAKED_JMP(void CIOCompletionHandler::ReleaseInstance(), 0x40D7A0);
//DEFINE_NAKED_JMP(int CIOCompletionHandler::Init(unsigned long), 0x40D7F0);
//DEFINE_NAKED_JMP(unsigned long CIOCompletionHandler::GetCountWorker(), 0x4024C0);
DEFINE_NAKED_JMP(SteamEngine::Win32::Net::CIOCompletionPort * CIOCompletionHandler::GetIOCP(), 0x40D990);
//DEFINE_NAKED_JMP(SteamEngine::Win32::System::CIOCompletionWorker * CIOCompletionHandler::GetWorker(int), 0x40D9B0);
//DEFINE_NAKED_JMP(int CIOCompletionHandler::AssociateDevice(void * _COMMA unsigned long), 0x40D9D0);
//DEFINE_NAKED_JMP(CIOCompletionHandler::Constructor(), 0x40D660);
//DEFINE_NAKED_JMP(CIOCompletionHandler::Destructor(), 0x40D690);
#endif

class CIOCompletionWorker : public CThread {
public:
    static const unsigned int _size = 0x1c;

    virtual void Action();    PATCH_MEMBER(void, Action, , 0x40DD60);
    unsigned long m_dwDispatchCount;//this+0x10
    unsigned long m_dwReadBytes;//this+0x14
    unsigned long m_dwStartTick;//this+0x18
    DEFINE_STATIC_MEMBER(int *, m_bThreadLoop, 0x522F34);//static int m_bThreadLoop;//[0x522F34]  [00122F34:0003:00002F34]
    CIOCompletionWorker(const CIOCompletionWorker &);
    CIOCompletionWorker();    PATCH_MEMBER(CIOCompletionWorker &, Constructor, , 0x40DCE0);
    virtual ~CIOCompletionWorker();    PATCH_MEMBER(void, Destructor, , 0x40DD20);
    CIOCompletionWorker & operator=(const CIOCompletionWorker &);
    //void __local_vftable_ctor_closure();
    //virtual void * __vecDelDtor(unsigned int);

/*struct _Invoke {
PATCH_MEMBER_INVOKE(void, CIOCompletionWorker, Action, );
PATCH_MEMBER_INVOKE(CIOCompletionWorker &, CIOCompletionWorker, Constructor, );
PATCH_MEMBER_INVOKE(void, CIOCompletionWorker, Destructor, );
};*/

#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(void CIOCompletionWorker::Action(), 0x40DD60);
//DEFINE_NAKED_JMP(CIOCompletionWorker::Constructor(), 0x40DCE0);
//DEFINE_NAKED_JMP(CIOCompletionWorker::Destructor(), 0x40DD20);
#endif
};
}}}//namespace SteamEngine { namespace Win32 { namespace System {



typedef SteamEngine::Win32::System::CIOCompletionHandler CIOCompletionHandler;
typedef SteamEngine::Win32::System::CIOCompletionWorker CIOCompletionWorker;





#endif