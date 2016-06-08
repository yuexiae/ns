#ifndef NSHEADER_NS_CONSOLE_H_
#define NSHEADER_NS_CONSOLE_H_


class CNSConsole {
public:
    static const unsigned int _size = 0x750;
    
    enum OUTPUTTYPE {
        OutputType_Normal = 0x0,
        OutputType_Info = 0x1,
        OutputType_Warring = 0x2,
        OutputType_Error = 0x3,
    };

    CNSConsole(const CNSConsole &);
    CNSConsole(char *, char *);    PATCH_MEMBER(CNSConsole &, Constructor, char * _COMMA char *, 0x4DC840);
    CNSConsole();    PATCH_MEMBER(CNSConsole &, Constructor, , 0x4DC7D0);
    virtual ~CNSConsole();    PATCH_MEMBER(void, Destructor, , 0x4DC8C0);
    void Init();    PATCH_MEMBER(void, Init, , 0x4DC8F0);
    void SetConsole(int);    PATCH_MEMBER(void, SetConsole, int, 0x4DC970);
    void SetFilename(char *, char *);    PATCH_MEMBER(void, SetFilename, char * _COMMA char *, 0x4DCA50);
    void Output(char *, ...);    PATCH_MEMBER(void, Output, char * _COMMA ..., 0x4DCAC0);
    void Output(CNSConsole::OUTPUTTYPE, char *, ...);    PATCH_MEMBER(void, Output, CNSConsole::OUTPUTTYPE _COMMA char * _COMMA ..., 0x4DCBF0);
    void * m_hStd;//this+0x4
    struct _COORD m_dwSize;//this+0x8
    unsigned short m_wAttributes;//this+0xC
    int m_bConsoleOutput;//this+0x10
    char m_szPath[0x104];//this+0x14
    char m_szFilename[0x104];//this+0x118
    struct _SYSTEMTIME m_stOld;//this+0x21C
    char m_szOutputFilename[0x400];//this+0x22C
    class SteamEngine::Win32::Utility::COutputFile m_OutputFile;//this+0x62C
    int MakeCurrentFilename();    PATCH_MEMBER(int, MakeCurrentFilename, , 0x4DC990);
    CNSConsole & operator=(const CNSConsole &);
    //void __local_vftable_ctor_closure();
    //virtual void * __vecDelDtor(unsigned int);

/*struct _Invoke {
PATCH_MEMBER_INVOKE(CNSConsole &, CNSConsole, Constructor, char * _COMMA char *);
PATCH_MEMBER_INVOKE(CNSConsole &, CNSConsole, Constructor, );
PATCH_MEMBER_INVOKE(void, CNSConsole, Destructor, );
PATCH_MEMBER_INVOKE(void, CNSConsole, Init, );
PATCH_MEMBER_INVOKE(void, CNSConsole, SetConsole, int);
PATCH_MEMBER_INVOKE(void, CNSConsole, SetFilename, char * _COMMA char *);
PATCH_MEMBER_INVOKE(void, CNSConsole, Output, char * _COMMA ...);
PATCH_MEMBER_INVOKE(void, CNSConsole, Output, CNSConsole::OUTPUTTYPE _COMMA char * _COMMA ...);
PATCH_MEMBER_INVOKE(int, CNSConsole, MakeCurrentFilename, );
};*/

#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(CNSConsole::Constructor(char * _COMMA char *), 0x4DC840);
//DEFINE_NAKED_JMP(CNSConsole::Constructor(), 0x4DC7D0);
//DEFINE_NAKED_JMP(CNSConsole::Destructor(), 0x4DC8C0);
//DEFINE_NAKED_JMP(void CNSConsole::Init(), 0x4DC8F0);
//DEFINE_NAKED_JMP(void CNSConsole::SetConsole(int), 0x4DC970);
//DEFINE_NAKED_JMP(void CNSConsole::SetFilename(char * _COMMA char *), 0x4DCA50);
//DEFINE_NAKED_JMP(void CNSConsole::Output(char * _COMMA ...), 0x4DCAC0);
//DEFINE_NAKED_JMP(void CNSConsole::Output(CNSConsole::OUTPUTTYPE _COMMA char * _COMMA ...), 0x4DCBF0);
//DEFINE_NAKED_JMP(int CNSConsole::MakeCurrentFilename(), 0x4DC990);
#endif
};






#endif