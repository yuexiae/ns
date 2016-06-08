#ifndef NSHEADER_NS_SKILL_PARAMS_H_
#define NSHEADER_NS_SKILL_PARAMS_H_

class CNSSkillParams;

template <>
class CSingleton<CNSSkillParams> {
public:
    static const unsigned int _size = 0x1;

    static CNSSkillParams * GetInstance();    PATCH_STATIC(CNSSkillParams *, GetInstance, , 0x403090);
    static void ReleaseInstance();    PATCH_STATIC(void, ReleaseInstance, , 0x403120);
    static class CNSSkillParams * m_selfInstance;//[0x559E00]  [00159E00:0003:00039E00]

/*struct _Invoke {
PATCH_STATIC_INVOKE(CNSSkillParams *, GetInstance, );
PATCH_STATIC_INVOKE(void, ReleaseInstance, );
};*/
};
#ifdef DEFINE_NS_CPP
DEFINE_NAKED_JMP(CNSSkillParams * CSingleton<CNSSkillParams>::GetInstance(), 0x403090);
//DEFINE_NAKED_JMP(void CSingleton<CNSSkillParams>::ReleaseInstance(), 0x403120);
#endif

class CNSSkillParams : public CSingleton<CNSSkillParams> {
public:
    static const unsigned int _size = 0x24;

    class _SkillTypeTable {
    public:
        static const unsigned int _size = 0x51;

        unsigned char btType;//this+0x0
        char szName[0x50];//this+0x1
    };

    class _SkillOptionTable {
    public:
        static const unsigned int _size = 0x51;

        unsigned char btType;//this+0x0
        char szName[0x50];//this+0x1
    };

    class _RangeTypeTable {
    public:
        static const unsigned int _size = 0x51;

        unsigned char btType;//this+0x0
        char szName[0x50];//this+0x1
    };

    
    CNSSkillParams(const CNSSkillParams &);
    CNSSkillParams();    PATCH_MEMBER(CNSSkillParams &, Constructor, , 0x4D60A0);
    virtual ~CNSSkillParams();    PATCH_MEMBER(void, Destructor, , 0x4D60D0);
    virtual int Init();    PATCH_MEMBER(int, Init, , 0x4D61B0);
    int Load();    PATCH_MEMBER(int, Load, , 0x4D6460);
    CNSSkill * GetObjectA(unsigned char, unsigned short);    PATCH_MEMBER(CNSSkill *, GetObjectA, unsigned char _COMMA unsigned short, 0x4D61D0);
    void DebugCheckSkillPoint();    PATCH_MEMBER(void, DebugCheckSkillPoint, , 0x4D6930);
    class std::map<unsigned long,CNSSkill *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const ,CNSSkill *> > > m_mapSkill;//this+0x4
    unsigned char ConvertSkillTypeString(char *);    PATCH_MEMBER(unsigned char, ConvertSkillTypeString, char *, 0x4D62F0);
    unsigned char ConvertRangeTypeString(char *);    PATCH_MEMBER(unsigned char, ConvertRangeTypeString, char *, 0x4D6400);
    unsigned char ConvertSkillOptionString(char *);    PATCH_MEMBER(unsigned char, ConvertSkillOptionString, char *, 0x4D6370);
    CNSSkillParams & operator=(const CNSSkillParams &);
    //void __local_vftable_ctor_closure();
    //virtual void * __vecDelDtor(unsigned int);

/*struct _Invoke {
PATCH_MEMBER_INVOKE(CNSSkillParams &, CNSSkillParams, Constructor, );
PATCH_MEMBER_INVOKE(void, CNSSkillParams, Destructor, );
PATCH_MEMBER_INVOKE(int, CNSSkillParams, Init, );
PATCH_MEMBER_INVOKE(int, CNSSkillParams, Load, );
PATCH_MEMBER_INVOKE(CNSSkill *, CNSSkillParams, GetObjectA, unsigned char _COMMA unsigned short);
PATCH_MEMBER_INVOKE(void, CNSSkillParams, DebugCheckSkillPoint, );
PATCH_MEMBER_INVOKE(unsigned char, CNSSkillParams, ConvertSkillTypeString, char *);
PATCH_MEMBER_INVOKE(unsigned char, CNSSkillParams, ConvertRangeTypeString, char *);
PATCH_MEMBER_INVOKE(unsigned char, CNSSkillParams, ConvertSkillOptionString, char *);
};*/
};
#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(CNSSkillParams::Constructor(), 0x4D60A0);
//DEFINE_NAKED_JMP(CNSSkillParams::Destructor(), 0x4D60D0);
//DEFINE_NAKED_JMP(int CNSSkillParams::Init(), 0x4D61B0);
//DEFINE_NAKED_JMP(int CNSSkillParams::Load(), 0x4D6460);
//DEFINE_NAKED_JMP(CNSSkill * CNSSkillParams::GetObjectA(unsigned char _COMMA unsigned short), 0x4D61D0);
//DEFINE_NAKED_JMP(void CNSSkillParams::DebugCheckSkillPoint(), 0x4D6930);
DEFINE_NAKED_JMP(unsigned char CNSSkillParams::ConvertSkillTypeString(char *), 0x4D62F0);
DEFINE_NAKED_JMP(unsigned char CNSSkillParams::ConvertRangeTypeString(char *), 0x4D6400);
DEFINE_NAKED_JMP(unsigned char CNSSkillParams::ConvertSkillOptionString(char *), 0x4D6370);
#endif










#endif