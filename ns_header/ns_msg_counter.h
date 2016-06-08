#ifndef NSHEADER_NS_MSG_COUNTER_H_
#define NSHEADER_NS_MSG_COUNTER_H_

class CMsgCounter {
public:
    static const unsigned int _size = 0xc0854;

    CMsgCounter(const CMsgCounter &);
    CMsgCounter(char *, char *);    PATCH_MEMBER(CMsgCounter &, Constructor, char * _COMMA char *, 0x4B49A0);
    void AddCount(int, unsigned long);    PATCH_MEMBER(void, AddCount, int _COMMA unsigned long, 0x44C8E0);
    void PrintLog(int, int);    PATCH_MEMBER(void, PrintLog, int _COMMA int, 0x4024E0);
    struct _Msg {
        static const unsigned int _size = 0xc;

        unsigned long dwCount;//this+0x0
        unsigned long dwTime;//this+0x4
        unsigned long dwMaxTime;//this+0x8
    };

    struct CMsgCounter::_Msg m_Msg[0xFFFF];//this+0x0
    unsigned long m_dwCount;//this+0xBFFF4
    unsigned long m_dwTime;//this+0xBFFF8
    char m_szFilename[0x105];//this+0xBFFFC
    class CNSConsole m_Console;//this+0xC0104
    void Clear();    PATCH_MEMBER(void, Clear, , 0x4026D0);
    ~CMsgCounter();    PATCH_MEMBER(void, Destructor, , 0x4B4A30);
    CMsgCounter & operator=(const CMsgCounter &);
    //void * __vecDelDtor(unsigned int);

/*struct _Invoke {
PATCH_MEMBER_INVOKE(CMsgCounter &, CMsgCounter, Constructor, char * _COMMA char *);
PATCH_MEMBER_INVOKE(void, CMsgCounter, AddCount, int _COMMA unsigned long);
PATCH_MEMBER_INVOKE(void, CMsgCounter, PrintLog, int _COMMA int);
PATCH_MEMBER_INVOKE(void, CMsgCounter, Clear, );
PATCH_MEMBER_INVOKE(void, CMsgCounter, Destructor, );
};*/

#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(CMsgCounter::Constructor(char * _COMMA char *), 0x4B49A0);
//DEFINE_NAKED_JMP(void CMsgCounter::AddCount(int _COMMA unsigned long), 0x44C8E0);
//DEFINE_NAKED_JMP(void CMsgCounter::PrintLog(int _COMMA int), 0x4024E0);
//DEFINE_NAKED_JMP(void CMsgCounter::Clear(), 0x4026D0);
//DEFINE_NAKED_JMP(CMsgCounter::Destructor(), 0x4B4A30);
#endif
};


#endif