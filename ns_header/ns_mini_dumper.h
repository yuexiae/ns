#ifndef NSHEADER_NS_MINI_DUMPER_H_
#define NSHEADER_NS_MINI_DUMPER_H_

#include <dbghelp.h>

namespace SteamEngine { namespace Win32 { namespace System {
class CMiniDumper {
public:
    static const unsigned int _size = 0x318;
    
	typedef int (__stdcall *pfn_MiniDumpWriteDump)(void *, unsigned int, void *, _MINIDUMP_TYPE, _MINIDUMP_EXCEPTION_INFORMATION *const, _MINIDUMP_USER_STREAM_INFORMATION *const, _MINIDUMP_CALLBACK_INFORMATION *const);

    CMiniDumper(const SteamEngine::Win32::System::CMiniDumper &);
    CMiniDumper();    PATCH_MEMBER(SteamEngine::Win32::System::CMiniDumper &, Constructor, , 0x40DF40);
    virtual ~CMiniDumper();    PATCH_MEMBER(void, Destructor, , 0x40DFD0);
    static unsigned long WriteMiniDump(_EXCEPTION_POINTERS *);    PATCH_STATIC(unsigned long, WriteMiniDump, _EXCEPTION_POINTERS *, 0x40E1F0);
    static class SteamEngine::Win32::System::CMiniDumper * m_selfInstance;//[0x55B0C4]  [0015B0C4:0003:0003B0C4]
    struct HINSTANCE__ * m_hDll;//this+0x4
    pfn_MiniDumpWriteDump m_pMiniDumpWriteDump;//this+0x8
    char m_szDumpPath[0x104];//this+0xC
    char m_szAppPath[0x104];//this+0x110
    char m_szAppBaseName[0x104];//this+0x214
    void Init();    PATCH_MEMBER(void, Init, , 0x40E010);
    static long Handler(_EXCEPTION_POINTERS *);    PATCH_STATIC(long, Handler, _EXCEPTION_POINTERS *, 0x40E190);
    static unsigned long _WriteMiniDump(void *);    PATCH_STATIC(unsigned long, _WriteMiniDump, void *, 0x40E340);
    virtual void OnEndProcess();    PATCH_MEMBER(void, OnEndProcess, , 0x40E000);
    virtual void VSetDumpFileName();    PATCH_MEMBER(void, VSetDumpFileName, , 0x40E2D0);
    virtual void VPrintOut(char *, char *);    PATCH_MEMBER(void, VPrintOut, char * _COMMA char *, 0x40E2B0);
    virtual _MINIDUMP_USER_STREAM_INFORMATION * VGetUserStreamArray();    PATCH_MEMBER(_MINIDUMP_USER_STREAM_INFORMATION *, VGetUserStreamArray, , 0x4039A0);
    SteamEngine::Win32::System::CMiniDumper & operator=(const SteamEngine::Win32::System::CMiniDumper &);
    //void __local_vftable_ctor_closure();
    //virtual void * __vecDelDtor(unsigned int);

/*struct _Invoke {
PATCH_MEMBER_INVOKE(SteamEngine::Win32::System::CMiniDumper &, SteamEngine::Win32::System::CMiniDumper, Constructor, );
PATCH_MEMBER_INVOKE(void, SteamEngine::Win32::System::CMiniDumper, Destructor, );
PA
TCH_STATIC_INVOKE(unsigned long, WriteMiniDump, _EXCEPTION_POINTERS *);
PATCH_MEMBER_INVOKE(void, SteamEngine::Win32::System::CMiniDumper, Init, );
PATCH_STATIC_INVOKE(long, Handler, _EXCEPTION_POINTERS *);
PATCH_STATIC_INVOKE(unsigned long, _WriteMiniDump, void *);
PATCH_MEMBER_INVOKE(void, SteamEngine::Win32::System::CMiniDumper, OnEndProcess, );
PATCH_MEMBER_INVOKE(void, SteamEngine::Win32::System::CMiniDumper, VSetDumpFileName, );
PATCH_MEMBER_INVOKE(void, SteamEngine::Win32::System::CMiniDumper, VPrintOut, char * _COMMA char *);
PATCH_MEMBER_INVOKE(_MINIDUMP_USER_STREAM_INFORMATION *, SteamEngine::Win32::System::CMiniDumper, VGetUserStreamArray, );
};*/
};

#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(SteamEngine::Win32::System::CMiniDumper::Constructor(), 0x40DF40);
//DEFINE_NAKED_JMP(SteamEngine::Win32::System::CMiniDumper::Destructor(), 0x40DFD0);
DEFINE_NAKED_JMP(unsigned long SteamEngine::Win32::System::CMiniDumper::WriteMiniDump(_EXCEPTION_POINTERS *), 0x40E1F0);
//DEFINE_NAKED_JMP(void SteamEngine::Win32::System::CMiniDumper::Init(), 0x40E010);
//DEFINE_NAKED_JMP(long SteamEngine::Win32::System::CMiniDumper::Handler(_EXCEPTION_POINTERS *), 0x40E190);
//DEFINE_NAKED_JMP(unsigned long SteamEngine::Win32::System::CMiniDumper::_WriteMiniDump(void *), 0x40E340);
//DEFINE_NAKED_JMP(void SteamEngine::Win32::System::CMiniDumper::OnEndProcess(), 0x40E000);
//DEFINE_NAKED_JMP(void SteamEngine::Win32::System::CMiniDumper::VSetDumpFileName(), 0x40E2D0);
//DEFINE_NAKED_JMP(void SteamEngine::Win32::System::CMiniDumper::VPrintOut(char * _COMMA char *), 0x40E2B0);
//DEFINE_NAKED_JMP(_MINIDUMP_USER_STREAM_INFORMATION * SteamEngine::Win32::System::CMiniDumper::VGetUserStreamArray(), 0x4039A0);
#endif

}}} //namespace SteamEngine { namespace Win32 { namespace System {

typedef SteamEngine::Win32::System::CMiniDumper CMiniDumper;





#endif