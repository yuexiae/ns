#ifndef NSHEADER_NS_PC_TITLE_PARAMS_H_
#define NSHEADER_NS_PC_TILTE_PARAMS_H_

class CNSPcTitleParams;

template <>
class CSingleton<CNSPcTitleParams> {
public:
    static const unsigned int _size = 0x1;

    static CNSPcTitleParams * GetInstance();    PATCH_STATIC(CNSPcTitleParams *, GetInstance, , 0x403370);
    static void ReleaseInstance();
    static class CNSPcTitleParams * m_selfInstance;//[0x559E10]  [00159E10:0003:00039E10]

    /*struct _Invoke {
    PATCH_STATIC_INVOKE(CNSPcTitleParams *, GetInstance, );
    };*/
};
#ifdef DEFINE_NS_CPP
DEFINE_NAKED_JMP(CNSPcTitleParams * CSingleton<CNSPcTitleParams>::GetInstance(), 0x403370);
#endif

class CNSPcTitleParams : public CSingleton<CNSPcTitleParams> {
public:
    static const unsigned int _size = 0x24;

    CNSPcTitleParams(const CNSPcTitleParams &);
    CNSPcTitleParams();    PATCH_MEMBER(CNSPcTitleParams &, Constructor, , 0x4961C0);
    virtual ~CNSPcTitleParams();    PATCH_MEMBER(void, Destructor, , 0x4961F0);
    virtual int Init();    PATCH_MEMBER(int, Init, , 0x496210);
    int Load();    PATCH_MEMBER(int, Load, , 0x496230);
    CNSPcTitle * GetTitle(unsigned short);    PATCH_MEMBER(CNSPcTitle *, GetTitle, unsigned short, 0x43F6A0);
    class std::map<unsigned short,CNSPcTitle *,std::less<unsigned short>,std::allocator<std::pair<unsigned short const ,CNSPcTitle *> > > m_mapTitle;//this+0x4
    CNSPcTitleParams & operator=(const CNSPcTitleParams &);
    //void __local_vftable_ctor_closure();
    //virtual void * __vecDelDtor(unsigned int);

    /*struct _Invoke {
    PATCH_MEMBER_INVOKE(CNSPcTitleParams &, CNSPcTitleParams, Constructor, );
    PATCH_MEMBER_INVOKE(void, CNSPcTitleParams, Destructor, );
    PATCH_MEMBER_INVOKE(int, CNSPcTitleParams, Init, );
    PATCH_MEMBER_INVOKE(int, CNSPcTitleParams, Load, );
    PATCH_MEMBER_INVOKE(CNSPcTitle *, CNSPcTitleParams, GetTitle, unsigned short);
    };*/
};
#ifdef DEFINE_NS_CPP
    //DEFINE_NAKED_JMP(CNSPcTitleParams::Constructor(), 0x4961C0);
    //DEFINE_NAKED_JMP(CNSPcTitleParams::Destructor(), 0x4961F0);
    //DEFINE_NAKED_JMP(int CNSPcTitleParams::Init(), 0x496210);
    //DEFINE_NAKED_JMP(int CNSPcTitleParams::Load(), 0x496230);
    DEFINE_NAKED_JMP(CNSPcTitle * CNSPcTitleParams::GetTitle(unsigned short), 0x43F6A0);
#endif


#endif