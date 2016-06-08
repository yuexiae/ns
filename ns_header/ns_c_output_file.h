#ifndef NSHEADER_NS_C_OUTPUT_FILE_H_
#define NSHEADER_NS_C_OUTPUT_FILE_H_

namespace SteamEngine { namespace Win32 { namespace Utility {

class COutputFile {
public:
    static const unsigned int _size = 0x124;

    
    COutputFile(const COutputFile &);
    COutputFile();    PATCH_MEMBER(COutputFile &, Constructor, , 0x416080);
    virtual ~COutputFile();    PATCH_MEMBER(void, Destructor, , 0x4160B0);
    void SetFilename(char *);    PATCH_MEMBER(void, SetFilename, char *, 0x416120);
    int Open();    PATCH_MEMBER(int, Open, , 0x4161D0);
    void Close();    PATCH_MEMBER(void, Close, , 0x416240);
    void Output(char *, ...);    PATCH_MEMBER(void, Output, char * _COMMA ..., 0x4162A0);
    struct _iobuf * m_fp;//this+0x4
    char m_szFilename[0x100];//this+0x8
    class SteamEngine::Win32::System::CCriticalSection m_cs;//this+0x108
    COutputFile & operator=(const COutputFile &);
    //void __local_vftable_ctor_closure();
    //virtual void * __vecDelDtor(unsigned int);

/*struct _Invoke {
PATCH_MEMBER_INVOKE(COutputFile &, COutputFile, Constructor, );
PATCH_MEMBER_INVOKE(void, COutputFile, Destructor, );
PATCH_MEMBER_INVOKE(void, COutputFile, SetFilename, char *);
PATCH_MEMBER_INVOKE(int, COutputFile, Open, );
PATCH_MEMBER_INVOKE(void, COutputFile, Close, );
PATCH_MEMBER_INVOKE(void, COutputFile, Output, char * _COMMA ...);
};*/
};
#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(COutputFile::Constructor(), 0x416080);
//DEFINE_NAKED_JMP(COutputFile::Destructor(), 0x4160B0);
//DEFINE_NAKED_JMP(void COutputFile::SetFilename(char *), 0x416120);
DEFINE_NAKED_JMP(int COutputFile::Open(), 0x4161D0);
DEFINE_NAKED_JMP(void COutputFile::Close(), 0x416240);
//DEFINE_NAKED_JMP(void COutputFile::Output(char * _COMMA ...), 0x4162A0);
#endif

}}}//namespace SteamEngine { namespace Win32 { namespace Utility {

typedef SteamEngine::Win32::Utility::COutputFile COutputFile; 

#endif