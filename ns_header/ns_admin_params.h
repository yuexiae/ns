#ifndef NSHEADER_NS_ADMIN_PARAMS_H_
#define NSHEADER_NS_ADMIN_PARAMS_H_

class CNSAdminParams;

template <>
class CSingleton<CNSAdminParams> {
public:
    static const unsigned int _size = 0x1;

    static CNSAdminParams * GetInstance();    PATCH_STATIC(CNSAdminParams *, GetInstance, , 0x4035C0);
    static void ReleaseInstance();    PATCH_STATIC(void, ReleaseInstance, , 0x403650);
    static class CNSAdminParams * m_selfInstance;//[0x559E1C]  [00159E1C:0003:00039E1C]

/*struct _Invoke {
PATCH_STATIC_INVOKE(CNSAdminParams *, GetInstance, );
PATCH_STATIC_INVOKE(void, ReleaseInstance, );
};*/
};
#ifdef DEFINE_NS_CPP
DEFINE_NAKED_JMP(CNSAdminParams * CSingleton<CNSAdminParams>::GetInstance(), 0x4035C0);
//DEFINE_NAKED_JMP(void CSingleton<CNSAdminParams>::ReleaseInstance(), 0x403650);
#endif

class CNSAdminParams : public CSingleton<CNSAdminParams> {
public:
    static const unsigned int _size = 0x24;
    
    struct _Admin {
        static const unsigned int _size = 0x35;

        char szUserId[0x34];//this+0x0
        unsigned char btLevel;//this+0x34
    };

    CNSAdminParams(const CNSAdminParams &);
    CNSAdminParams();    PATCH_MEMBER(CNSAdminParams &, Constructor, , 0x416510);
    virtual ~CNSAdminParams();    PATCH_MEMBER(void, Destructor, , 0x416540);
    int Init(SteamEngine::Win32::DB::COdbc *);    PATCH_MEMBER(int, Init, SteamEngine::Win32::DB::COdbc *, 0x416620);
    virtual int Init();    PATCH_MEMBER(int, Init, , 0x416610);
    int Load(SteamEngine::Win32::DB::COdbc *);    PATCH_MEMBER(int, Load, SteamEngine::Win32::DB::COdbc *, 0x4166C0);
    int GetAdminLevel(char *);    PATCH_MEMBER(int, GetAdminLevel, char *, 0x416640);
    class std::map<unsigned long,CNSAdminParams::_Admin *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const ,CNSAdminParams::_Admin *> > > m_mapAdmin;//this+0x4
    CNSAdminParams & operator=(const CNSAdminParams &);
    //void __local_vftable_ctor_closure();
    //virtual void * __vecDelDtor(unsigned int);

/*struct _Invoke {
PATCH_MEMBER_INVOKE(CNSAdminParams &, CNSAdminParams, Constructor, );
PATCH_MEMBER_INVOKE(void, CNSAdminParams, Destructor, );
PATCH_MEMBER_INVOKE(int, CNSAdminParams, Init, SteamEngine::Win32::DB::COdbc *);
PATCH_MEMBER_INVOKE(int, CNSAdminParams, Init, );
PATCH_MEMBER_INVOKE(int, CNSAdminParams, Load, SteamEngine::Win32::DB::COdbc *);
PATCH_MEMBER_INVOKE(int, CNSAdminParams, GetAdminLevel, char *);
};*/
};
#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(CNSAdminParams::Constructor(), 0x416510);
//DEFINE_NAKED_JMP(CNSAdminParams::Destructor(), 0x416540);
//DEFINE_NAKED_JMP(int CNSAdminParams::Init(SteamEngine::Win32::DB::COdbc *), 0x416620);
//DEFINE_NAKED_JMP(int CNSAdminParams::Init(), 0x416610);
//DEFINE_NAKED_JMP(int CNSAdminParams::Load(SteamEngine::Win32::DB::COdbc *), 0x4166C0);
DEFINE_NAKED_JMP(int CNSAdminParams::GetAdminLevel(char *), 0x416640);
#endif






#endif