#ifndef NSHEADER_NS_QUESTPARAMS_H_
#define NSHEADER_NS_QUESTPARAMS_H_

class CNSQuestParams;

template<>
class CSingleton<CNSQuestParams> {
public:
    static const unsigned int _size = 0x1;

    static CNSQuestParams * GetInstance();    PATCH_STATIC(CNSQuestParams *, GetInstance, , 0x403170);
    static void ReleaseInstance();    PATCH_STATIC(void, ReleaseInstance, , 0x403200);
    static class CNSQuestParams * m_selfInstance;//[0x559E04]  [00159E04:0003:00039E04]

    /*struct _Invoke {
    PATCH_STATIC_INVOKE(CNSQuestParams *, GetInstance, );
    PATCH_STATIC_INVOKE(void, ReleaseInstance, );
    };*/
};

#ifdef DEFINE_NS_CPP
    DEFINE_NAKED_JMP(CNSQuestParams * CSingleton<CNSQuestParams>::GetInstance(), 0x403170);
    //DEFINE_NAKED_JMP(void CSingleton<CNSQuestParams>::ReleaseInstance(), 0x403200);
#endif

class CNSQuestParams : public CSingleton<CNSQuestParams> {
public:
    static const unsigned int _size = 0x24;

    CNSQuestParams(const CNSQuestParams &);
    CNSQuestParams();    PATCH_MEMBER(CNSQuestParams &, Constructor, , 0x49B630);
    virtual ~CNSQuestParams();    PATCH_MEMBER(void, Destructor, , 0x49B660);
    virtual int Init();    PATCH_MEMBER(int, Init, , 0x49B720);
    int Load();    PATCH_MEMBER(int, Load, , 0x49B790);
    CNSQuest * GetObjectA(unsigned short);    PATCH_MEMBER(CNSQuest *, GetObjectA, unsigned short, 0x49B740);
    class std::map<unsigned short,CNSQuest *,std::less<unsigned short>,std::allocator<std::pair<unsigned short const ,CNSQuest *> > > m_mapQuest;//this+0x4
    int LoadQuest();    PATCH_MEMBER(int, LoadQuest, , 0x49B7D0);
    int LoadQuestStep();    PATCH_MEMBER(int, LoadQuestStep, , 0x49BC40);
    int LoadQuestReward();    PATCH_MEMBER(int, LoadQuestReward, , 0x49C180);
    CNSQuestParams & operator=(const CNSQuestParams &);
    //void __local_vftable_ctor_closure();
    //virtual void * __vecDelDtor(unsigned int);

    /*struct _Invoke {
    PATCH_MEMBER_INVOKE(CNSQuestParams &, CNSQuestParams, Constructor, );
    PATCH_MEMBER_INVOKE(void, CNSQuestParams, Destructor, );
    PATCH_MEMBER_INVOKE(int, CNSQuestParams, Init, );
    PATCH_MEMBER_INVOKE(int, CNSQuestParams, Load, );
    PATCH_MEMBER_INVOKE(CNSQuest *, CNSQuestParams, GetObjectA, unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSQuestParams, LoadQuest, );
    PATCH_MEMBER_INVOKE(int, CNSQuestParams, LoadQuestStep, );
    PATCH_MEMBER_INVOKE(int, CNSQuestParams, LoadQuestReward, );
    };*/

#ifdef DEFINE_NS_CPP
    //DEFINE_NAKED_JMP(CNSQuestParams::Constructor(), 0x49B630);
    //DEFINE_NAKED_JMP(CNSQuestParams::Destructor(), 0x49B660);
    //DEFINE_NAKED_JMP(int CNSQuestParams::Init(), 0x49B720);
    //DEFINE_NAKED_JMP(int CNSQuestParams::Load(), 0x49B790);
    //DEFINE_NAKED_JMP(CNSQuest * CNSQuestParams::GetObjectA(unsigned short), 0x49B740);
    //DEFINE_NAKED_JMP(int CNSQuestParams::LoadQuest(), 0x49B7D0);
    //DEFINE_NAKED_JMP(int CNSQuestParams::LoadQuestStep(), 0x49BC40);
    //DEFINE_NAKED_JMP(int CNSQuestParams::LoadQuestReward(), 0x49C180);
#endif
};




#endif