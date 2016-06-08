#ifndef NSHEADER_NS_SESSION_PC_H_
#define NSHEADER_NS_SESSION_PC_H_

#include "ns_header/ns_packet.h"

class CNSPcExt;

class CSession {
public:
    static const unsigned int _size = 0x2048;


    struct OVERLAPPED2 : public _OVERLAPPED {
        static const unsigned int _size = 0x18;

        unsigned long flags;//this+0x14
    };

    struct OVERLAPPED2_SEND : public OVERLAPPED2 {
        static const unsigned int _size = 0x2018;

        char pSendBuff[0x2000];//this+0x18
    };

    static CSession * Allocator();    PATCH_STATIC(CSession *, Allocator, , 0x412030);
    virtual void Init(unsigned int);    PATCH_MEMBER(void, Init, unsigned int, 0x4117E0);
    virtual void OnCreate();    PATCH_MEMBER(void, OnCreate, , 0x411840);
    virtual void OnDestroy();    PATCH_MEMBER(void, OnDestroy, , 0x411850);
    virtual void Dispatch(unsigned long, _OVERLAPPED *);    PATCH_MEMBER(void, Dispatch, unsigned long _COMMA _OVERLAPPED *, 0x411D40);
    virtual int SendMessageA(void *, unsigned long);    PATCH_MEMBER(int, SendMessageA, void * _COMMA unsigned long, 0x411FD0);
    virtual int SendMessageA(CPacket &);    PATCH_MEMBER(int, SendMessageA, CPacket &, 0x411F90);
    static int _SendMessage(CSession *, unsigned int, void *, unsigned long, unsigned long);    PATCH_STATIC(int, _SendMessage, CSession * _COMMA unsigned int _COMMA void * _COMMA unsigned long _COMMA unsigned long, 0x411B00);
    int ConnectTo(char *, int);    PATCH_MEMBER(int, ConnectTo, char * _COMMA int, 0x4118E0);
    virtual void CloseConnection();    PATCH_MEMBER(void, CloseConnection, , 0x411AD0);
    unsigned int GetSocket();    PATCH_MEMBER(unsigned int, GetSocket, , 0x402B90);
    int IsDisconnected();    PATCH_MEMBER(int, IsDisconnected, , 0x411F20);
    unsigned long GetRecvCount();    PATCH_MEMBER(unsigned long, GetRecvCount, , 0x412DA0);
    unsigned int m_socket;//this+0x4
    CSession(const CSession &);
    CSession();    PATCH_MEMBER(CSession &, Constructor, , 0x411760);
    virtual ~CSession();    PATCH_MEMBER(void, Destructor, , 0x4117C0);
    virtual void PacketParsing(CPacket &);    PATCH_MEMBER(void, PacketParsing, CPacket &, 0x426AB0);
    int WaitForPacketReceive();    PATCH_MEMBER(int, WaitForPacketReceive, , 0x411C90);
    void * m_hRecvEvent;//this+0x8
    struct CSession::OVERLAPPED2 m_overlappedSend;//this+0xC
    struct CSession::OVERLAPPED2 m_overlappedRecv;//this+0x24
    char m_cRecvBuffer[0x2000];//this+0x3C
    int m_nRecvPacketSize;//this+0x203C
    unsigned long m_dwCheckTime;//this+0x2040
    unsigned long m_dwRecvCount;//this+0x2044
    void DispatchReceive(unsigned long, unsigned long);    PATCH_MEMBER(void, DispatchReceive, unsigned long _COMMA unsigned long, 0x411DA0);
    CSession & operator=(const CSession &);
    //void __local_vftable_ctor_closure();
    //virtual void * __vecDelDtor(unsigned int);

    struct _Invoke {
        //PATCH_STATIC_INVOKE(CSession *, Allocator, );
        //PATCH_MEMBER_INVOKE(void, CSession, Init, unsigned int);
        //PATCH_MEMBER_INVOKE(void, CSession, OnCreate, );
        //PATCH_MEMBER_INVOKE(void, CSession, OnDestroy, );
        //PATCH_MEMBER_INVOKE(void, CSession, Dispatch, unsigned long _COMMA _OVERLAPPED *);
        //PATCH_MEMBER_INVOKE(int, CSession, SendMessageA, void * _COMMA unsigned long);
        //PATCH_MEMBER_INVOKE(int, CSession, SendMessageA, CPacket &);
        //PATCH_STATIC_INVOKE(int, _SendMessage, CSession * _COMMA unsigned int _COMMA void * _COMMA unsigned long _COMMA unsigned long);
        //PATCH_MEMBER_INVOKE(int, CSession, ConnectTo, char * _COMMA int);
        //PATCH_MEMBER_INVOKE(void, CSession, CloseConnection, );
        //PATCH_MEMBER_INVOKE(unsigned int, CSession, GetSocket, );
        //PATCH_MEMBER_INVOKE(int, CSession, IsDisconnected, );
        //PATCH_MEMBER_INVOKE(unsigned long, CSession, GetRecvCount, );
        //PATCH_MEMBER_INVOKE(CSession &, CSession, Constructor, );
        //PATCH_MEMBER_INVOKE(void, CSession, Destructor, );
        //PATCH_MEMBER_INVOKE(void, CSession, PacketParsing, CPacket &);
        //PATCH_MEMBER_INVOKE(int, CSession, WaitForPacketReceive, );
        //PATCH_MEMBER_INVOKE(void, CSession, DispatchReceive, unsigned long _COMMA unsigned long);
    };
};
#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(CSession * CSession::Allocator(), 0x412030);
//DEFINE_NAKED_JMP(void CSession::Init(unsigned int), 0x4117E0);
//DEFINE_NAKED_JMP(void CSession::OnCreate(), 0x411840);
//DEFINE_NAKED_JMP(void CSession::OnDestroy(), 0x411850);
DEFINE_NAKED_JMP(void CSession::Dispatch(unsigned long _COMMA _OVERLAPPED *), 0x411D40);
//DEFINE_NAKED_JMP(int CSession::SendMessageA(void * _COMMA unsigned long), 0x411FD0);
//DEFINE_NAKED_JMP(int CSession::SendMessageA(CPacket &), 0x411F90);
//DEFINE_NAKED_JMP(int CSession::_SendMessage(CSession * _COMMA unsigned int _COMMA void * _COMMA unsigned long _COMMA unsigned long), 0x411B00);
//DEFINE_NAKED_JMP(int CSession::ConnectTo(char * _COMMA int), 0x4118E0);
//DEFINE_NAKED_JMP(void CSession::CloseConnection(), 0x411AD0);
//DEFINE_NAKED_JMP(unsigned int CSession::GetSocket(), 0x402B90);
//DEFINE_NAKED_JMP(int CSession::IsDisconnected(), 0x411F20);
//DEFINE_NAKED_JMP(unsigned long CSession::GetRecvCount(), 0x412DA0);
//DEFINE_NAKED_JMP(CSession::Constructor(), 0x411760);
//DEFINE_NAKED_JMP(CSession::Destructor(), 0x4117C0);
//DEFINE_NAKED_JMP(void CSession::PacketParsing(CPacket &), 0x426AB0);
DEFINE_NAKED_JMP(int CSession::WaitForPacketReceive(), 0x411C90);
DEFINE_NAKED_JMP(void CSession::DispatchReceive(unsigned long _COMMA unsigned long), 0x411DA0);
#endif

class CNSSessionPc : public CSession {
public:
    static const unsigned int _size = 0x64a0;

    typedef void (__cdecl *pfnProcess)(CNSSessionPc *, CPacket &);

    enum SESSIONLEVEL {
        SessionLevel_None =  0x0,
        SessionLevel_Login =  0x1,
        SessionLevel_Load =  0x2,
        SessionLevel_Game =  0x3,
        SessionLevel_Session =  0x4,
    };

    static int ms_bBlockConnect;//[0x577FBC]  [00177FBC:0003:00057FBC]
    static int ms_bShutdown;//[0x577FC0]  [00177FC0:0003:00057FC0]
    DEFINE_STATIC_MEMBER(unsigned char *, ms_btServerIpArray, 0x577FB8);// static unsigned char ms_btServerIpArray[0x4];//[0x577FB8]  [00177FB8:0003:00057FB8]
    char m_szPeerIpAddress[0x10];//this+0x2048
    static char ms_szServerIpAddress[0x10];//[0x577FC4]  [00177FC4:0003:00057FC4]
    char m_szLastChatMessage[0x2000];//this+0x2058
    unsigned long m_dwLastChatTime;//this+0x4058
    static CSession * Allocator();    PATCH_STATIC(CSession *, Allocator, , 0x402BB0);
    virtual void OnCreate();    PATCH_MEMBER(void, OnCreate, , 0x4B0D20);
    virtual void OnDestroy();    PATCH_MEMBER(void, OnDestroy, , 0x4B0D90);
    virtual void CloseConnection();    PATCH_MEMBER(void, CloseConnection, , 0x4B4860);
    static unsigned char * GetServerIpArray();    PATCH_STATIC(unsigned char *, GetServerIpArray, , 0x484750);
    void SetPcNULL();
    int _SendMessage(void *, unsigned long);    PATCH_MEMBER(int, _SendMessage, void * _COMMA unsigned long, 0x4B1120);
    int _SendMessage(CPacket &);    PATCH_MEMBER(int, _SendMessage, CPacket &, 0x4B1060);
    int SendMessageA(CPacket &, int);    PATCH_MEMBER(int, SendMessageA, CPacket & _COMMA int, 0x4B11E0);
    int SendMessageQueue();    PATCH_MEMBER(int, SendMessageQueue, , 0x4B13B0);
    void SendMessageQueueClear();    PATCH_MEMBER(void, SendMessageQueueClear, , 0x4B14A0);
    int IsDestroy();    PATCH_MEMBER(int, IsDestroy, , 0x42E170);
    void SetSyncPos(NSPOINT2);    PATCH_MEMBER(void, SetSyncPos, NSPOINT2, 0x484140);
    int CheckSyncPos(NSPOINT2);    PATCH_MEMBER(int, CheckSyncPos, NSPOINT2, 0x484CE0);
    void SyncField(NSPOINT2);    PATCH_MEMBER(void, SyncField, NSPOINT2, 0x484CA0);
    void SyncField();    PATCH_MEMBER(void, SyncField, , 0x4B22E0);
    void SyncField2(NSPOINT2);    PATCH_MEMBER(void, SyncField2, NSPOINT2, 0x4B23C0);
    void SyncObject(CNSObject *);    PATCH_MEMBER(void, SyncObject, CNSObject *, 0x4B20B0);
    CNSPc * GetPcObject();    PATCH_MEMBER(CNSPc *, GetPcObject, , 0x4066D0);
    CNSSessionPc::SESSIONLEVEL GetSessionLevel();    PATCH_MEMBER(CNSSessionPc::SESSIONLEVEL, GetSessionLevel, , 0x482480);
    void SetSessionLevel(CNSSessionPc::SESSIONLEVEL);    PATCH_MEMBER(void, SetSessionLevel, CNSSessionPc::SESSIONLEVEL, 0x482510);
    static void ProcessAdd(unsigned short, pfnProcess);    PATCH_STATIC(void, ProcessAdd, unsigned short _COMMA pfnProcess, 0x4C9510);
    static void ProcessClear();    PATCH_STATIC(void, ProcessClear, , 0x4C9530);
    int SpecialCommand(char *);    PATCH_MEMBER(int, SpecialCommand, char *, 0x4B2570);
    static void Shutdown();    PATCH_STATIC(void, Shutdown, , 0x4B24D0);
    static void BlockServer();    PATCH_STATIC(void, BlockServer, , 0x4B2540);
    int IsCloseConnection();    PATCH_MEMBER(int, IsCloseConnection, , 0x4824A0);
    CNSSessionPc(const CNSSessionPc &);
    CNSSessionPc();    PATCH_MEMBER(CNSSessionPc &, Constructor, , 0x4B0AF0);
    virtual ~CNSSessionPc();    PATCH_MEMBER(void, Destructor, , 0x4B0BB0);
    virtual void Init(unsigned int);    PATCH_MEMBER(void, Init, unsigned int, 0x4B0C30);
    virtual void PacketParsing(CPacket &);    PATCH_MEMBER(void, PacketParsing, CPacket &, 0x4B1510);
    class CNSPcExt * m_pPc;//this+0x405C
    DEFINE_STATIC_MEMBER(pfnProcess *, ms_pProcessArray, 0x577FD8);//static pfnProcess ms_pProcessArray[0xFFFF];//[0x577FD8]  [00177FD8:0003:00057FD8]
    class CNSCriticalSection m_csQueuePacket;//this+0x4060
    CPacketBinder m_packetBinder;//this+0x447C
    union {
        unsigned char m_btPeerIpArray[0x4];//this+0x6484
        unsigned long m_dwPeerIp;
    } peer;
    class NSPOINT2 m_pt2Sync;//this+0x6488
    unsigned long m_dwLastTimeSync;//this+0x648C
    unsigned long m_dwLoginCount;//this+0x6490
    enum CNSSessionPc::SESSIONLEVEL m_sessionLevel;//this+0x6494
    int m_bDestroy;//this+0x6498
    int m_bCloseConnection;//this+0x649C
    void PacketProcess(CPacket &);    PATCH_MEMBER(void, PacketProcess, CPacket &, 0x4B1940);
    void GetConnectInfo();    PATCH_MEMBER(void, GetConnectInfo, , 0x4B0F50);
    CNSSessionPc & operator=(const CNSSessionPc &);
    //void __local_vftable_ctor_closure();
    //virtual void * __vecDelDtor(unsigned int);

    struct _Invoke {
        //PATCH_STATIC_INVOKE(CSession *, Allocator, );
        //PATCH_MEMBER_INVOKE(void, CNSSessionPc, OnCreate, );
        PATCH_MEMBER_INVOKE(void, CNSSessionPc, OnDestroy, );
        //PATCH_MEMBER_INVOKE(void, CNSSessionPc, CloseConnection, );
        //PATCH_STATIC_INVOKE(unsigned char *, GetServerIpArray, );
        //PATCH_MEMBER_INVOKE(int, CNSSessionPc, _SendMessage, void * _COMMA unsigned long);
        //PATCH_MEMBER_INVOKE(int, CNSSessionPc, _SendMessage, CPacket &);
        //PATCH_MEMBER_INVOKE(int, CNSSessionPc, SendMessageA, CPacket & _COMMA int);
        //PATCH_MEMBER_INVOKE(int, CNSSessionPc, SendMessageQueue, );
        //PATCH_MEMBER_INVOKE(void, CNSSessionPc, SendMessageQueueClear, );
        //PATCH_MEMBER_INVOKE(int, CNSSessionPc, IsDestroy, );
        //PATCH_MEMBER_INVOKE(void, CNSSessionPc, SetSyncPos, NSPOINT2);
        //PATCH_MEMBER_INVOKE(int, CNSSessionPc, CheckSyncPos, NSPOINT2);
        //PATCH_MEMBER_INVOKE(void, CNSSessionPc, SyncField, NSPOINT2);
        //PATCH_MEMBER_INVOKE(void, CNSSessionPc, SyncField, );
        //PATCH_MEMBER_INVOKE(void, CNSSessionPc, SyncField2, NSPOINT2);
        //PATCH_MEMBER_INVOKE(void, CNSSessionPc, SyncObject, CNSObject *);
        //PATCH_MEMBER_INVOKE(CNSPc *, CNSSessionPc, GetPcObject, );
        //PATCH_MEMBER_INVOKE(CNSSessionPc::SESSIONLEVEL, CNSSessionPc, GetSessionLevel, );
        //PATCH_MEMBER_INVOKE(void, CNSSessionPc, SetSessionLevel, CNSSessionPc::SESSIONLEVEL);
        //PATCH_STATIC_INVOKE(void, ProcessAdd, unsigned short _COMMA function  *);
        //PATCH_STATIC_INVOKE(void, ProcessClear, );
        //PATCH_MEMBER_INVOKE(int, CNSSessionPc, SpecialCommand, char *);
        //PATCH_STATIC_INVOKE(void, Shutdown, );
        //PATCH_STATIC_INVOKE(void, BlockServer, );
        //PATCH_MEMBER_INVOKE(int, CNSSessionPc, IsCloseConnection, );
        PATCH_MEMBER_INVOKE(CNSSessionPc &, CNSSessionPc, Constructor, );
        PATCH_MEMBER_INVOKE(void, CNSSessionPc, Destructor, );
        PATCH_MEMBER_INVOKE(void, CNSSessionPc, Init, unsigned int);
        PATCH_MEMBER_INVOKE(void, CNSSessionPc, PacketParsing, CPacket &);
        PATCH_MEMBER_INVOKE(void, CNSSessionPc, PacketProcess, CPacket &);
        //PATCH_MEMBER_INVOKE(void, CNSSessionPc, GetConnectInfo, );
    };
};


#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(CSession * CNSSessionPc::Allocator(), 0x402BB0);
//DEFINE_NAKED_JMP(void CNSSessionPc::OnCreate(), 0x4B0D20);
//DEFINE_NAKED_JMP(void CNSSessionPc::OnDestroy(), 0x4B0D90);
//DEFINE_NAKED_JMP(void CNSSessionPc::CloseConnection(), 0x4B4860);
//DEFINE_NAKED_JMP(unsigned char * CNSSessionPc::GetServerIpArray(), 0x484750);
DEFINE_NAKED_JMP(int CNSSessionPc::_SendMessage(void * _COMMA unsigned long), 0x4B1120);
DEFINE_NAKED_JMP(int CNSSessionPc::_SendMessage(CPacket &), 0x4B1060);
DEFINE_NAKED_JMP(int CNSSessionPc::SendMessageA(CPacket & _COMMA int), 0x4B11E0);
DEFINE_NAKED_JMP(int CNSSessionPc::SendMessageQueue(), 0x4B13B0);
DEFINE_NAKED_JMP(void CNSSessionPc::SendMessageQueueClear(), 0x4B14A0);
//DEFINE_NAKED_JMP(int CNSSessionPc::IsDestroy(), 0x42E170);
//DEFINE_NAKED_JMP(void CNSSessionPc::SetSyncPos(NSPOINT2), 0x484140);
//DEFINE_NAKED_JMP(int CNSSessionPc::CheckSyncPos(NSPOINT2), 0x484CE0);
//DEFINE_NAKED_JMP(void CNSSessionPc::SyncField(NSPOINT2), 0x484CA0);
//DEFINE_NAKED_JMP(void CNSSessionPc::SyncField(), 0x4B22E0);
//DEFINE_NAKED_JMP(void CNSSessionPc::SyncField2(NSPOINT2), 0x4B23C0);
//DEFINE_NAKED_JMP(void CNSSessionPc::SyncObject(CNSObject *), 0x4B20B0);
//DEFINE_NAKED_JMP(CNSPc * CNSSessionPc::GetPcObject(), 0x4066D0);
DEFINE_NAKED_JMP(CNSSessionPc::SESSIONLEVEL CNSSessionPc::GetSessionLevel(), 0x482480);
DEFINE_NAKED_JMP(void CNSSessionPc::SetSessionLevel(CNSSessionPc::SESSIONLEVEL), 0x482510);
DEFINE_NAKED_JMP(void CNSSessionPc::ProcessAdd(unsigned short _COMMA pfnProcess), 0x4C9510);
DEFINE_NAKED_JMP(void CNSSessionPc::ProcessClear(), 0x4C9530);
//DEFINE_NAKED_JMP(int CNSSessionPc::SpecialCommand(char *), 0x4B2570);
//DEFINE_NAKED_JMP(void CNSSessionPc::Shutdown(), 0x4B24D0);
//DEFINE_NAKED_JMP(void CNSSessionPc::BlockServer(), 0x4B2540);
//DEFINE_NAKED_JMP(int CNSSessionPc::IsCloseConnection(), 0x4824A0);
//DEFINE_NAKED_JMP(CNSSessionPc::Constructor(), 0x4B0AF0);
//DEFINE_NAKED_JMP(CNSSessionPc::Destructor(), 0x4B0BB0);
//DEFINE_NAKED_JMP(void CNSSessionPc::Init(unsigned int), 0x4B0C30);
//DEFINE_NAKED_JMP(void CNSSessionPc::PacketParsing(CPacket &), 0x4B1510);
DEFINE_NAKED_JMP(void CNSSessionPc::PacketProcess(CPacket &), 0x4B1940);
//DEFINE_NAKED_JMP(void CNSSessionPc::GetConnectInfo(), 0x4B0F50);
#endif



#endif