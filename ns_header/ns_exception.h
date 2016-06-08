#ifndef NSHEADER_NS_EXCEPTION_H_
#define NSHEADER_NS_EXCEPTION_H_


/*
namespace SteamEngine { namespace Win32 { namespace System {
class CException {
public:
    static const unsigned int _size = 0x404;
    
    CException(const SteamEngine::Win32::System::CException &);    PATCH_MEMBER(SteamEngine::Win32::System::CException &, Constructor, const SteamEngine::Win32::System::CException &, 0x402A40);
    CException(const char *, const char *);    PATCH_MEMBER(SteamEngine::Win32::System::CException &, Constructor, const char * _COMMA const char *, 0x40B890);
    virtual ~CException();    PATCH_MEMBER(void, Destructor, , 0x4029F0);
    virtual char * GetWhere();    PATCH_MEMBER(char *, GetWhere, , 0x40B8E0);
    virtual char * GetMessageA();    PATCH_MEMBER(char *, GetMessageA, , 0x40B900);
    void MessageBoxA(HWND__ *);    PATCH_MEMBER(void, MessageBoxA, HWND__ *, 0x40B920);
    char m_szWhere[0x200];//this+0x4
    char m_szMessage[0x200];//this+0x204
    SteamEngine::Win32::System::CException & operator=(const SteamEngine::Win32::System::CException &);
    //virtual void * __vecDelDtor(unsigned int);

struct _Invoke {
PATCH_MEMBER_INVOKE(SteamEngine::Win32::System::CException &, SteamEngine::Win32::System::CException, Constructor, const SteamEngine::Win32::System::CException &);
PATCH_MEMBER_INVOKE(SteamEngine::Win32::System::CException &, SteamEngine::Win32::System::CException, Constructor, const char * _COMMA const char *);
PATCH_MEMBER_INVOKE(void, SteamEngine::Win32::System::CException, Destructor, );
PATCH_MEMBER_INVOKE(char *, SteamEngine::Win32::System::CException, GetWhere, );
PATCH_MEMBER_INVOKE(char *, SteamEngine::Win32::System::CException, GetMessageA, );
PATCH_MEMBER_INVOKE(void, SteamEngine::Win32::System::CException, MessageBoxA, HWND__ *);
};
};

#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(SteamEngine::Win32::System::CException::Constructor(const SteamEngine::Win32::System::CException &), 0x402A40);
//DEFINE_NAKED_JMP(SteamEngine::Win32::System::CException::Constructor(const char * _COMMA const char *), 0x40B890);
//DEFINE_NAKED_JMP(SteamEngine::Win32::System::CException::Destructor(), 0x4029F0);
DEFINE_NAKED_JMP(char * SteamEngine::Win32::System::CException::GetWhere(), 0x40B8E0);
DEFINE_NAKED_JMP(char * SteamEngine::Win32::System::CException::GetMessageA(), 0x40B900);
//DEFINE_NAKED_JMP(void SteamEngine::Win32::System::CException::MessageBoxA(HWND__ *), 0x40B920);
#endif

}}} //namespace SteamEngine { namespace Win32 { namespace System {



typedef SteamEngine::Win32::System::CException CException;

*/

#endif