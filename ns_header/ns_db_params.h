#ifndef NSHEADER_NS_DB_PARAMS_H_
#define NSHEADER_NS_DB_PARAMS_H_


class CNSDbParams;

template <>
class CSingleton<CNSDbParams> {
public:
    static const unsigned int _size = 0x1;

    static CNSDbParams * GetInstance();    PATCH_STATIC(CNSDbParams *, GetInstance, , 0x404C30);
    static void ReleaseInstance();
    static class CNSDbParams * m_selfInstance;//[0x55B058]  [0015B058:0003:0003B058]

/*struct _Invoke {
PATCH_STATIC_INVOKE(CNSDbParams *, GetInstance, );
};*/
};
#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(CNSDbParams * CSingleton<CNSDbParams>::GetInstance(), 0x404C30);
#endif

class CNSDbParams : public CSingleton<CNSDbParams> {
public:
    static const unsigned int _size = 0x104;
    
    CNSDbParams(const CNSDbParams &);
    CNSDbParams();    PATCH_MEMBER(CNSDbParams &, Constructor, , 0x4313C0);
    virtual ~CNSDbParams();    PATCH_MEMBER(void, Destructor, , 0x4313F0);
    int Init();    PATCH_MEMBER(int, Init, , 0x431410);
    void ConfigDbAuth(char *);    PATCH_MEMBER(void, ConfigDbAuth, char *, 0x431420);
    char * GetAuthDbName();    PATCH_MEMBER(char *, GetAuthDbName, , 0x4B4930);
    char m_szAuthDbName[0x100];//this+0x4
    CNSDbParams & operator=(const CNSDbParams &);
    //void __local_vftable_ctor_closure();
    //virtual void * __vecDelDtor(unsigned int);

/*struct _Invoke {
PATCH_MEMBER_INVOKE(CNSDbParams &, CNSDbParams, Constructor, );
PATCH_MEMBER_INVOKE(void, CNSDbParams, Destructor, );
PATCH_MEMBER_INVOKE(int, CNSDbParams, Init, );
PATCH_MEMBER_INVOKE(void, CNSDbParams, ConfigDbAuth, char *);
PATCH_MEMBER_INVOKE(char *, CNSDbParams, GetAuthDbName, );
};*/

#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(CNSDbParams::Constructor(), 0x4313C0);
//DEFINE_NAKED_JMP(CNSDbParams::Destructor(), 0x4313F0);
//DEFINE_NAKED_JMP(int CNSDbParams::Init(), 0x431410);
//DEFINE_NAKED_JMP(void CNSDbParams::ConfigDbAuth(char *), 0x431420);
//DEFINE_NAKED_JMP(char * CNSDbParams::GetAuthDbName(), 0x4B4930);
#endif
};



#endif