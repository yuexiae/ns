#ifndef SERVER_NS_GAME_SERVER_PARAMS_H_
#define SERVER_NS_GAME_SERVER_PARAMS_H_

class CNSGameServerParams;

template <>
class CSingleton<CNSGameServerParams> {
public:
    static const unsigned int _size = 0x1;

    static CNSGameServerParams * GetInstance();    PATCH_STATIC(CNSGameServerParams *, GetInstance, , 0x402C30);
    static void ReleaseInstance();    PATCH_STATIC(void, ReleaseInstance, , 0x402CC0);
    static class CNSGameServerParams * m_selfInstance;//[0x559DEC]  [00159DEC:0003:00039DEC]

/*struct _Invoke {
PATCH_STATIC_INVOKE(CNSGameServerParams *, GetInstance, );
PATCH_STATIC_INVOKE(void, ReleaseInstance, );
};*/
};
#ifdef DEFINE_NS_CPP
DEFINE_NAKED_JMP(CNSGameServerParams * CSingleton<CNSGameServerParams>::GetInstance(), 0x402C30);
//DEFINE_NAKED_JMP(void CSingleton<CNSGameServerParams>::ReleaseInstance(), 0x402CC0);
#endif

class CNSGameServerParams : public CSingleton<CNSGameServerParams> {
public:
    static const unsigned int _size = 0xc;

    
    CNSGameServerParams(const CNSGameServerParams &);
    CNSGameServerParams();    PATCH_MEMBER(CNSGameServerParams &, Constructor, , 0x403E80);
    virtual ~CNSGameServerParams();    PATCH_MEMBER(void, Destructor, , 0x403EA0);
    int Init();    PATCH_MEMBER(int, Init, , 0x403EC0);
    int InitProfile();    PATCH_MEMBER(int, InitProfile, , 0x403EE0);
    int ReadServerInfo(char *, int, unsigned char *, int &);    PATCH_MEMBER(int, ReadServerInfo, char * _COMMA int _COMMA unsigned char * _COMMA int &, 0x404990);
    int GetUserMax();    PATCH_MEMBER(int, GetUserMax, , 0x402B90);
    int GetServerPort();    PATCH_MEMBER(int, GetServerPort, , 0x402210);
    int m_nUserMax;//this+0x4
    int m_nServerPort;//this+0x8
    CNSGameServerParams & operator=(const CNSGameServerParams &);
    //void __local_vftable_ctor_closure();
    //virtual void * __vecDelDtor(unsigned int);

/*struct _Invoke {
PATCH_MEMBER_INVOKE(CNSGameServerParams &, CNSGameServerParams, Constructor, );
PATCH_MEMBER_INVOKE(void, CNSGameServerParams, Destructor, );
PATCH_MEMBER_INVOKE(int, CNSGameServerParams, Init, );
PATCH_MEMBER_INVOKE(int, CNSGameServerParams, InitProfile, );
PATCH_MEMBER_INVOKE(int, CNSGameServerParams, ReadServerInfo, char * _COMMA int _COMMA unsigned char * _COMMA int &);
PATCH_MEMBER_INVOKE(int, CNSGameServerParams, GetUserMax, );
PATCH_MEMBER_INVOKE(int, CNSGameServerParams, GetServerPort, );
};*/

#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(CNSGameServerParams::Constructor(), 0x403E80);
//DEFINE_NAKED_JMP(CNSGameServerParams::Destructor(), 0x403EA0);
//DEFINE_NAKED_JMP(int CNSGameServerParams::Init(), 0x403EC0);
//DEFINE_NAKED_JMP(int CNSGameServerParams::InitProfile(), 0x403EE0);
//DEFINE_NAKED_JMP(int CNSGameServerParams::ReadServerInfo(char * _COMMA int _COMMA unsigned char * _COMMA int &), 0x404990);
//DEFINE_NAKED_JMP(int CNSGameServerParams::GetUserMax(), 0x402B90);
//DEFINE_NAKED_JMP(int CNSGameServerParams::GetServerPort(), 0x402210);
#endif
};



#endif