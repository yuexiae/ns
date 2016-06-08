#ifndef NSHEADER_NS_MAP_MANAGER_H_
#define NSHEADER_NS_MAP_MANAGER_H_


class CNSMapManager {
public:
    static const unsigned int _size = 0x53c;

    CNSMapManager(const CNSMapManager &);
    CNSMapManager(char *, unsigned char, unsigned long, unsigned long, unsigned short);    PATCH_MEMBER(CNSMapManager &, Constructor, char * _COMMA unsigned char _COMMA unsigned long _COMMA unsigned long _COMMA unsigned short, 0x442120);
    virtual ~CNSMapManager();    PATCH_MEMBER(void, Destructor, , 0x4421D0);
    int SetCharMap(NSPOINT2 &, unsigned short, int);    PATCH_MEMBER(int, SetCharMap, NSPOINT2 & _COMMA unsigned short _COMMA int, 0x442500);
    int SetCharMap(NSPOINT2, unsigned short);    PATCH_MEMBER(int, SetCharMap, NSPOINT2 _COMMA unsigned short, 0x44C830);
    int UnSetCharMap(NSPOINT2, unsigned short);    PATCH_MEMBER(int, UnSetCharMap, NSPOINT2 _COMMA unsigned short, 0x426EA0);
    int CheckSeeTarget(NSPOINT2 &, NSPOINT2 &, int);    PATCH_MEMBER(int, CheckSeeTarget, NSPOINT2 & _COMMA NSPOINT2 & _COMMA int, 0x442B70);
    int GetFreePos(NSPOINT2 &, unsigned short, unsigned short, unsigned short, NSPOINT2 &);    PATCH_MEMBER(int, GetFreePos, NSPOINT2 & _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA NSPOINT2 &, 0x442960);
    int GetFreePos2(NSPOINT2 &, unsigned short, unsigned short, unsigned short, NSPOINT2 &);    PATCH_MEMBER(int, GetFreePos2, NSPOINT2 & _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA NSPOINT2 &, 0x442A70);
    int GetTargetFreePos(NSPOINT2 &, unsigned short, unsigned short, unsigned short, NSPOINT2 &);    PATCH_MEMBER(int, GetTargetFreePos, NSPOINT2 & _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA NSPOINT2 &, 0x4433B0);
    int ConvertLimitDestPos(NSPOINT2 &, unsigned short, NSPOINT2 &, NSPOINT2 &, unsigned short);    PATCH_MEMBER(int, ConvertLimitDestPos, NSPOINT2 & _COMMA unsigned short _COMMA NSPOINT2 & _COMMA NSPOINT2 & _COMMA unsigned short, 0x442E30);
    int ConvertLimitDestPos2(NSPOINT2 &, unsigned short, NSPOINT2 &, NSPOINT2 &, unsigned short);    PATCH_MEMBER(int, ConvertLimitDestPos2, NSPOINT2 & _COMMA unsigned short _COMMA NSPOINT2 & _COMMA NSPOINT2 & _COMMA unsigned short, 0x443080);
    int CheckMap(NSPOINT2 &, unsigned short);    PATCH_MEMBER(int, CheckMap, NSPOINT2 & _COMMA unsigned short, 0x443730);
    int CheckMap(NSPOINT2 &, unsigned short, unsigned char &);    PATCH_MEMBER(int, CheckMap, NSPOINT2 & _COMMA unsigned short _COMMA unsigned char &, 0x442740);
    int CheckCharMap(NSPOINT2 &, unsigned short);    PATCH_MEMBER(int, CheckCharMap, NSPOINT2 & _COMMA unsigned short, 0x442670);
    unsigned char GetMapAttr(NSPOINT2 &, unsigned short);    PATCH_MEMBER(unsigned char, GetMapAttr, NSPOINT2 & _COMMA unsigned short, 0x4428A0);
    void DebugPrint();    PATCH_MEMBER(void, DebugPrint, , 0x443650);
    unsigned char m_btRegion;//this+0x4
    unsigned long m_dwWidth;//this+0x8
    unsigned long m_dwHeight;//this+0xC
    unsigned short m_wCellSize;//this+0x10
    unsigned char * * m_ppMapData;//this+0x14
    unsigned char * * m_ppCharMapData;//this+0x18
    char m_szFileName[0x104];//this+0x1C
    class CNSCriticalSection m_cs;//this+0x120
    int Init();    PATCH_MEMBER(int, Init, , 0x442270);
    int MapLoad();    PATCH_MEMBER(int, MapLoad, , 0x442310);
    void CalcCheckArea(NSPOINT2 &, unsigned short, NSPOINT2 &, int &);    PATCH_MEMBER(void, CalcCheckArea, NSPOINT2 & _COMMA unsigned short _COMMA NSPOINT2 & _COMMA int &, 0x4423D0);
    static class CNSMapManager ms_MapDummy;//[0x55C728]  [0015C728:0003:0003C728]
    CNSMapManager & operator=(const CNSMapManager &);
    //virtual void * __vecDelDtor(unsigned int);

/*struct _Invoke {
PATCH_MEMBER_INVOKE(CNSMapManager &, CNSMapManager, Constructor, char * _COMMA unsigned char _COMMA unsigned long _COMMA unsigned long _COMMA unsigned short);
PATCH_MEMBER_INVOKE(void, CNSMapManager, Destructor, );
PATCH_MEMBER_INVOKE(int, CNSMapManager, SetCharMap, NSPOINT2 & _COMMA unsigned short _COMMA int);
PATCH_MEMBER_INVOKE(int, CNSMapManager, SetCharMap, NSPOINT2 _COMMA unsigned short);
PATCH_MEMBER_INVOKE(int, CNSMapManager, UnSetCharMap, NSPOINT2 _COMMA unsigned short);
PATCH_MEMBER_INVOKE(int, CNSMapManager, CheckSeeTarget, NSPOINT2 & _COMMA NSPOINT2 & _COMMA int);
PATCH_MEMBER_INVOKE(int, CNSMapManager, GetFreePos, NSPOINT2 & _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA NSPOINT2 &);
PATCH_MEMBER_INVOKE(int, CNSMapManager, GetFreePos2, NSPOINT2 & _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA NSPOINT2 &);
PATCH_MEMBER_INVOKE(int, CNSMapManager, GetTargetFreePos, NSPOINT2 & _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA NSPOINT2 &);
PATCH_MEMBER_INVOKE(int, CNSMapManager, ConvertLimitDestPos, NSPOINT2 & _COMMA unsigned short _COMMA NSPOINT2 & _COMMA NSPOINT2 & _COMMA unsigned short);
PATCH_MEMBER_INVOKE(int, CNSMapManager, ConvertLimitDestPos2, NSPOINT2 & _COMMA unsigned short _COMMA NSPOINT2 & _COMMA NSPOINT2 & _COMMA unsigned short);
PATCH_MEMBER_INVOKE(int, CNSMapManager, CheckMap, NSPOINT2 & _COMMA unsigned short);
PATCH_MEMBER_INVOKE(int, CNSMapManager, CheckMap, NSPOINT2 & _COMMA unsigned short _COMMA unsigned char &);
PATCH_MEMBER_INVOKE(int, CNSMapManager, CheckCharMap, NSPOINT2 & _COMMA unsigned short);
PATCH_MEMBER_INVOKE(unsigned char, CNSMapManager, GetMapAttr, NSPOINT2 & _COMMA unsigned short);
PATCH_MEMBER_INVOKE(void, CNSMapManager, DebugPrint, );
PATCH_MEMBER_INVOKE(int, CNSMapManager, Init, );
PATCH_MEMBER_INVOKE(int, CNSMapManager, MapLoad, );
PATCH_MEMBER_INVOKE(void, CNSMapManager, CalcCheckArea, NSPOINT2 & _COMMA unsigned short _COMMA NSPOINT2 & _COMMA int &);
};*/
};
#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(CNSMapManager::Constructor(char * _COMMA unsigned char _COMMA unsigned long _COMMA unsigned long _COMMA unsigned short), 0x442120);
//DEFINE_NAKED_JMP(CNSMapManager::Destructor(), 0x4421D0);
DEFINE_NAKED_JMP(int CNSMapManager::SetCharMap(NSPOINT2 & _COMMA unsigned short _COMMA int), 0x442500);
DEFINE_NAKED_JMP(int CNSMapManager::SetCharMap(NSPOINT2 _COMMA unsigned short), 0x44C830);
DEFINE_NAKED_JMP(int CNSMapManager::UnSetCharMap(NSPOINT2 _COMMA unsigned short), 0x426EA0);
DEFINE_NAKED_JMP(int CNSMapManager::CheckSeeTarget(NSPOINT2 & _COMMA NSPOINT2 & _COMMA int), 0x442B70);
DEFINE_NAKED_JMP(int CNSMapManager::GetFreePos(NSPOINT2 & _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA NSPOINT2 &), 0x442960);
DEFINE_NAKED_JMP(int CNSMapManager::GetFreePos2(NSPOINT2 & _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA NSPOINT2 &), 0x442A70);
DEFINE_NAKED_JMP(int CNSMapManager::GetTargetFreePos(NSPOINT2 & _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA NSPOINT2 &), 0x4433B0);
DEFINE_NAKED_JMP(int CNSMapManager::ConvertLimitDestPos(NSPOINT2 & _COMMA unsigned short _COMMA NSPOINT2 & _COMMA NSPOINT2 & _COMMA unsigned short), 0x442E30);
DEFINE_NAKED_JMP(int CNSMapManager::ConvertLimitDestPos2(NSPOINT2 & _COMMA unsigned short _COMMA NSPOINT2 & _COMMA NSPOINT2 & _COMMA unsigned short), 0x443080);
DEFINE_NAKED_JMP(int CNSMapManager::CheckMap(NSPOINT2 & _COMMA unsigned short), 0x443730);
DEFINE_NAKED_JMP(int CNSMapManager::CheckMap(NSPOINT2 & _COMMA unsigned short _COMMA unsigned char &), 0x442740);
DEFINE_NAKED_JMP(int CNSMapManager::CheckCharMap(NSPOINT2 & _COMMA unsigned short), 0x442670);
DEFINE_NAKED_JMP(unsigned char CNSMapManager::GetMapAttr(NSPOINT2 & _COMMA unsigned short), 0x4428A0);
//DEFINE_NAKED_JMP(void CNSMapManager::DebugPrint(), 0x443650);
//DEFINE_NAKED_JMP(int CNSMapManager::Init(), 0x442270);
//DEFINE_NAKED_JMP(int CNSMapManager::MapLoad(), 0x442310);
DEFINE_NAKED_JMP(void CNSMapManager::CalcCheckArea(NSPOINT2 & _COMMA unsigned short _COMMA NSPOINT2 & _COMMA int &), 0x4423D0);
#endif


#endif