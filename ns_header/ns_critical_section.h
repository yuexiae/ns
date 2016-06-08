#ifndef NSHEADER_NS_CRITICAL_SECTION_H_
#define NSHEADER_NS_CRITICAL_SECTION_H_

namespace SteamEngine { namespace Win32 { namespace System {
    class CCriticalSection {
    public:
        static const unsigned int _size = 0x1c;

        struct Owner {
            static const unsigned int _size = 0x4;
            Owner(const CCriticalSection::Owner &);
            Owner(CCriticalSection &);    PATCH_MEMBER(CCriticalSection::Owner &, Constructor, CCriticalSection &, 0x40B520);
            ~Owner();    PATCH_MEMBER(void, Destructor, , 0x40B550);
            class CCriticalSection & m_crit;//this+0x0
            CCriticalSection::Owner & operator=(const CCriticalSection::Owner &);
            //void * __vecDelDtor(unsigned int);

            /*struct _Invoke {
            PATCH_MEMBER_INVOKE(CCriticalSection::Owner &, CCriticalSection::Owner, Constructor, CCriticalSection &);
            PATCH_MEMBER_INVOKE(void, CCriticalSection::Owner, Destructor, );
            };*/

#ifdef DEFINE_NS_CPP
            //DEFINE_NAKED_JMP(CCriticalSection::Owner::Constructor(CCriticalSection &), 0x40B520);
            //DEFINE_NAKED_JMP(CCriticalSection::Owner::Destructor(), 0x40B550);
#endif
        };

        CCriticalSection(const CCriticalSection &);
        CCriticalSection();    PATCH_MEMBER(CCriticalSection &, Constructor, , 0x40B460);
        ~CCriticalSection();    PATCH_MEMBER(void, Destructor, , 0x40B490);
        int TryEnter();    PATCH_MEMBER(int, TryEnter, , 0x40B4C0);
        virtual void Enter();    PATCH_MEMBER(void, Enter, , 0x40B4E0);
        virtual void Leave();    PATCH_MEMBER(void, Leave, , 0x40B500);
        _RTL_CRITICAL_SECTION * GetObjectA();
        struct _RTL_CRITICAL_SECTION m_crit;//this+0x4
        CCriticalSection & operator=(const CCriticalSection &);
        //void * __vecDelDtor(unsigned int);

        /*struct _Invoke {
        PATCH_MEMBER_INVOKE(CCriticalSection &, CCriticalSection, Constructor, );
        PATCH_MEMBER_INVOKE(void, CCriticalSection, Destructor, );
        PATCH_MEMBER_INVOKE(int, CCriticalSection, TryEnter, );
        PATCH_MEMBER_INVOKE(void, CCriticalSection, Enter, );
        PATCH_MEMBER_INVOKE(void, CCriticalSection, Leave, );
        };*/
    };
#ifdef DEFINE_NS_CPP
    //DEFINE_NAKED_JMP(CCriticalSection::Constructor(), 0x40B460);
    //DEFINE_NAKED_JMP(CCriticalSection::Destructor(), 0x40B490);
    DEFINE_NAKED_JMP(int CCriticalSection::TryEnter(), 0x40B4C0);
    //DEFINE_NAKED_JMP(void CCriticalSection::Enter(), 0x40B4E0);
    //DEFINE_NAKED_JMP(void CCriticalSection::Leave(), 0x40B500);
#endif

}}}//namespace SteamEngine { namespace Win32 { namespace System {


typedef SteamEngine::Win32::System::CCriticalSection CCriticalSection;

class CNSCriticalSection : public SteamEngine::Win32::System::CCriticalSection {
public:
    static const unsigned int _size = 0x41c;

    struct Owner {
        static const unsigned int _size = 0x4;
        Owner(CNSCriticalSection &crit) : m_crit(crit) { this->m_crit.Enter(10000); } PATCH_MEMBER(CNSCriticalSection::Owner &, Constructor, CNSCriticalSection &, 0x429CA0);
        ~Owner() { this->m_crit.Leave(); }    PATCH_MEMBER(void, Destructor, , 0x429CD0);
        class CNSCriticalSection & m_crit;//this+0x0
        //void * __vecDelDtor(unsigned int);

        /*struct _Invoke {
        PATCH_MEMBER_INVOKE(CNSCriticalSection::Owner &, CNSCriticalSection::Owner, Constructor, CNSCriticalSection &);
        PATCH_MEMBER_INVOKE(void, CNSCriticalSection::Owner, Destructor, );
        };*/

#ifdef DEFINE_NS_CPP
        //DEFINE_NAKED_JMP(CNSCriticalSection::Owner::Constructor(CNSCriticalSection &), 0x429CA0);
        //DEFINE_NAKED_JMP(CNSCriticalSection::Owner::Destructor(), 0x429CD0);
#endif
    };

    CNSCriticalSection(const CNSCriticalSection &);
    CNSCriticalSection();    PATCH_MEMBER(CNSCriticalSection &, Constructor, , 0x429B30);
    void Enter(int);    PATCH_MEMBER(void, Enter, int, 0x429BB0);
    void AddText(char *, ...);
    void Clear();    PATCH_MEMBER(void, Clear, , 0x429CF0);
    char m_szMsg[0x400];//this+0x1C
    ~CNSCriticalSection();    PATCH_MEMBER(void, Destructor, , 0x42B6B0);
    CNSCriticalSection & operator=(const CNSCriticalSection &);
    //void * __vecDelDtor(unsigned int);

    /*struct _Invoke {
    PATCH_MEMBER_INVOKE(CNSCriticalSection &, CNSCriticalSection, Constructor, );
    PATCH_MEMBER_INVOKE(void, CNSCriticalSection, Enter, int);
    PATCH_MEMBER_INVOKE(void, CNSCriticalSection, Clear, );
    PATCH_MEMBER_INVOKE(void, CNSCriticalSection, Destructor, );
    };*/
};
#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(CNSCriticalSection::Constructor(), 0x429B30);
DEFINE_NAKED_JMP(void CNSCriticalSection::Enter(int), 0x429BB0);
//DEFINE_NAKED_JMP(void CNSCriticalSection::Clear(), 0x429CF0);
//DEFINE_NAKED_JMP(CNSCriticalSection::Destructor(), 0x42B6B0);
#endif






#endif