#ifndef NSHEADER_NS_PC_PARAMS_H_
#define NSHEADER_NS_PC_PARAMS_H_

class CNSPcParams;

template <>
class CSingleton<CNSPcParams> {
public:
    static const unsigned int _size = 0x1;

    static CNSPcParams * GetInstance();    PATCH_STATIC(CNSPcParams *, GetInstance, , 0x4036A0);
    static void ReleaseInstance();    PATCH_STATIC(void, ReleaseInstance, , 0x403730);
    static class CNSPcParams * m_selfInstance;//[0x559E20]  [00159E20:0003:00039E20]

/*struct _Invoke {
PATCH_STATIC_INVOKE(CNSPcParams *, GetInstance, );
PATCH_STATIC_INVOKE(void, ReleaseInstance, );
};*/
};
#ifdef DEFINE_NS_CPP
DEFINE_NAKED_JMP(CNSPcParams * CSingleton<CNSPcParams>::GetInstance(), 0x4036A0);
//DEFINE_NAKED_JMP(void CSingleton<CNSPcParams>::ReleaseInstance(), 0x403730);
#endif

class CNSPcParams : public CSingleton<CNSPcParams> {
public:
    static const unsigned int _size = 0x64;
    
    struct _Status {
        static const unsigned int _size = 0x8;

        unsigned short btStr;//this+0x0
        unsigned short btCon;//this+0x2
        unsigned short btDex;//this+0x4
        unsigned short btInt;//this+0x6
    };

    struct _Path {
        static const unsigned int _size = 0x58;

        unsigned short wId;//this+0x0
        unsigned long dwCount;//this+0x4
        class NSPOINT2 cell[0x14];//this+0x8
        _Path();    PATCH_MEMBER(CNSPcParams::_Path &, Constructor, , 0x454150);

/*struct _Invoke {
PATCH_MEMBER_INVOKE(CNSPcParams::_Path &, CNSPcParams::_Path, Constructor, );
};*/

#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(CNSPcParams::_Path::Constructor(), 0x454150);
#endif
    };

    CNSPcParams(const CNSPcParams &);
    CNSPcParams();    PATCH_MEMBER(CNSPcParams &, Constructor, , 0x48E710);
    virtual ~CNSPcParams();    PATCH_MEMBER(void, Destructor, , 0x48E790);
    virtual int Init();    PATCH_MEMBER(int, Init, , 0x48E880);
    int Load();    PATCH_MEMBER(int, Load, , 0x48EA40);
    int LoadStatus();    PATCH_MEMBER(int, LoadStatus, , 0x48ECE0);
    int LoadPcPathFile();    PATCH_MEMBER(int, LoadPcPathFile, , 0x48EA70);
    CNSPcParams::_Status * GetStatus(unsigned char, unsigned char, unsigned char);    PATCH_MEMBER(CNSPcParams::_Status *, GetStatus, unsigned char _COMMA unsigned char _COMMA unsigned char, 0x48E8A0);
    unsigned long GetNextExp(unsigned char, unsigned char);    PATCH_MEMBER(unsigned long, GetNextExp, unsigned char _COMMA unsigned char, 0x48E940);
    CNSPcParams::_Path * GetObjectPath(unsigned short);    PATCH_MEMBER(CNSPcParams::_Path *, GetObjectPath, unsigned short, 0x48E9F0);
    int LoadGuildMember(CNSGuild *);    PATCH_MEMBER(int, LoadGuildMember, CNSGuild *, 0x48F1E0);
    CNSGuild * LoadGuild(int);    PATCH_MEMBER(CNSGuild *, LoadGuild, int, 0x48F4E0);
    class std::map<unsigned long,CNSPcParams::_Status *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const ,CNSPcParams::_Status *> > > m_mapStatus;//this+0x4
    class std::map<unsigned short,unsigned long,std::less<unsigned short>,std::allocator<std::pair<unsigned short const ,unsigned long> > > m_mapExp;//this+0x24
    class std::map<unsigned short,CNSPcParams::_Path *,std::less<unsigned short>,std::allocator<std::pair<unsigned short const ,CNSPcParams::_Path *> > > m_mapPath;//this+0x44
    unsigned long MakeStatusId(unsigned char, unsigned char, unsigned char);    PATCH_MEMBER(unsigned long, MakeStatusId, unsigned char _COMMA unsigned char _COMMA unsigned char, 0x48F860);
    unsigned short MakeExpId(unsigned char, unsigned char);    PATCH_MEMBER(unsigned short, MakeExpId, unsigned char _COMMA unsigned char, 0x48F890);
    CNSPcParams & operator=(const CNSPcParams &);
    //void __local_vftable_ctor_closure();
    //virtual void * __vecDelDtor(unsigned int);

/*struct _Invoke {
PATCH_MEMBER_INVOKE(CNSPcParams &, CNSPcParams, Constructor, );
PATCH_MEMBER_INVOKE(void, CNSPcParams, Destructor, );
PATCH_MEMBER_INVOKE(int, CNSPcParams, Init, );
PATCH_MEMBER_INVOKE(int, CNSPcParams, Load, );
PATCH_MEMBER_INVOKE(int, CNSPcParams, LoadStatus, );
PATCH_MEMBER_INVOKE(int, CNSPcParams, LoadPcPathFile, );
PATCH_MEMBER_INVOKE(CNSPcParams::_Status *, CNSPcParams, GetStatus, unsigned char _COMMA unsigned char _COMMA unsigned char);
PATCH_MEMBER_INVOKE(unsigned long, CNSPcParams, GetNextExp, unsigned char _COMMA unsigned char);
PATCH_MEMBER_INVOKE(CNSPcParams::_Path *, CNSPcParams, GetObjectPath, unsigned short);
PATCH_MEMBER_INVOKE(int, CNSPcParams, LoadGuildMember, CNSGuild *);
PATCH_MEMBER_INVOKE(CNSGuild *, CNSPcParams, LoadGuild, int);
PATCH_MEMBER_INVOKE(unsigned long, CNSPcParams, MakeStatusId, unsigned char _COMMA unsigned char _COMMA unsigned char);
PATCH_MEMBER_INVOKE(unsigned short, CNSPcParams, MakeExpId, unsigned char _COMMA unsigned char);
};*/
};
#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(CNSPcParams::Constructor(), 0x48E710);
//DEFINE_NAKED_JMP(CNSPcParams::Destructor(), 0x48E790);
//DEFINE_NAKED_JMP(int CNSPcParams::Init(), 0x48E880);
//DEFINE_NAKED_JMP(int CNSPcParams::Load(), 0x48EA40);
//DEFINE_NAKED_JMP(int CNSPcParams::LoadStatus(), 0x48ECE0);
//DEFINE_NAKED_JMP(int CNSPcParams::LoadPcPathFile(), 0x48EA70);
DEFINE_NAKED_JMP(CNSPcParams::_Status * CNSPcParams::GetStatus(unsigned char _COMMA unsigned char _COMMA unsigned char), 0x48E8A0);
//DEFINE_NAKED_JMP(unsigned long CNSPcParams::GetNextExp(unsigned char _COMMA unsigned char), 0x48E940);
//DEFINE_NAKED_JMP(CNSPcParams::_Path * CNSPcParams::GetObjectPath(unsigned short), 0x48E9F0);
DEFINE_NAKED_JMP(int CNSPcParams::LoadGuildMember(CNSGuild *), 0x48F1E0);
//DEFINE_NAKED_JMP(CNSGuild * CNSPcParams::LoadGuild(int), 0x48F4E0);
//DEFINE_NAKED_JMP(unsigned long CNSPcParams::MakeStatusId(unsigned char _COMMA unsigned char _COMMA unsigned char), 0x48F860);
//DEFINE_NAKED_JMP(unsigned short CNSPcParams::MakeExpId(unsigned char _COMMA unsigned char), 0x48F890);
#endif








#endif