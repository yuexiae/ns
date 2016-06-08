#ifndef NSHEADER_NS_ACUTION_H_
#define NSHEADER_NS_ACUTION_H_

#include "ns_critical_section.h"

class CNSAuction;

template <>
class CSingleton<CNSAuction> {
public:
    static const unsigned int _size = 0x1;

    static CNSAuction * GetInstance();    PATCH_STATIC(CNSAuction *, GetInstance, , 0x4038F0);
    static void ReleaseInstance();
    static class CNSAuction * m_selfInstance;//[0x559E2C]  [00159E2C:0003:00039E2C]

/*struct _Invoke {
PATCH_STATIC_INVOKE(CNSAuction *, GetInstance, );
};*/

#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(CNSAuction * CSingleton<CNSAuction>::GetInstance(), 0x4038F0);
#endif
};

class CNSAuction : public CSingleton<CNSAuction>{
public:
    static const unsigned int _size = 0x3c;

    enum SEARCHTYPE {
        SearchType_All = 0x0,
        SearchType_Owner = 0x1,
        SearchType_Sword = 0x10,
        SearchType_Blunt = 0x11,
        SearchType_TwoHanded_Sword = 0x20,
        SearchType_TwoHanded_Spear = 0x21,
        SearchType_TwoHanded_Blunt = 0x22,
        SearchType_TwoHanded_Staff = 0x23,
        SearchType_TwoHanded_Gun = 0x24,
        SearchType_TwoHanded_Bow = 0x25,
        SearchType_Head = 0x30,
        SearchType_Upper = 0x31,
        SearchType_Glove = 0x32,
        SearchType_Shield = 0x33,
        SearchType_Lower = 0x34,
        SearchType_Foot = 0x35,
        SearchType_Robe = 0x36,
        SearchType_Cloak = 0x37,
        SearchType_Necklace = 0x40,
        SearchType_Earring = 0x41,
        SearchType_Ring = 0x42,
        SearchType_Armlet = 0x43,
        SearchType_Belt = 0x44,
        SearchType_Core = 0x51,
        SearchType_Etc = 0x90,
    };

    CNSAuction(const CNSAuction &);
    CNSAuction();    PATCH_MEMBER(CNSAuction &, Constructor, , 0x416B70);
    ~CNSAuction();    PATCH_MEMBER(void, Destructor, , 0x416BD0);
    int Init();    PATCH_MEMBER(int, Init, , 0x416C30);
    int Add(CNSPc *, unsigned long, unsigned long, unsigned short, unsigned char);    PATCH_MEMBER(int, Add, CNSPc * _COMMA unsigned long _COMMA unsigned long _COMMA unsigned short _COMMA unsigned char, 0x416C50);
    int Delete(int, int, int);    PATCH_MEMBER(int, Delete, int _COMMA int _COMMA int, 0x417380);
    int Delete(CNSPc *, int);    PATCH_MEMBER(int, Delete, CNSPc * _COMMA int, 0x417510);
    int Sell(CNSPc *, int);    PATCH_MEMBER(int, Sell, CNSPc * _COMMA int, 0x417560);
    unsigned long DBAuctionCount(char *);    PATCH_MEMBER(unsigned long, DBAuctionCount, char *, 0x418050);
    unsigned long DBAuctionList(CNSPc *, CNSAuction::SEARCHTYPE, unsigned long, unsigned long &, CPacket &, unsigned char);    PATCH_MEMBER(unsigned long, DBAuctionList, CNSPc * _COMMA CNSAuction::SEARCHTYPE _COMMA unsigned long _COMMA unsigned long & _COMMA CPacket & _COMMA unsigned char, 0x417A20);
    unsigned long DebugDBAuctionList(CNSPc *, CNSAuction::SEARCHTYPE, unsigned long);    PATCH_MEMBER(unsigned long, DebugDBAuctionList, CNSPc * _COMMA CNSAuction::SEARCHTYPE _COMMA unsigned long, 0x418290);
    int DBAuctionItem(int, unsigned char &, unsigned long &);    PATCH_MEMBER(int, DBAuctionItem, int _COMMA unsigned char & _COMMA unsigned long &, 0x418150);
    void DebugList(CNSPc *);    PATCH_MEMBER(void, DebugList, CNSPc *, 0x4198D0);
    unsigned long CheckItem();    PATCH_MEMBER(unsigned long, CheckItem, , 0x4192C0);
    void Process(unsigned long);    PATCH_MEMBER(void, Process, unsigned long, 0x4199F0);
    class SteamEngine::Win32::System::CCriticalSection m_csMap;//this+0x0
    class std::map<int,CNSItem *,std::less<int>,std::allocator<std::pair<int const ,CNSItem *> > > m_mapItem;//this+0x1C
    int CacheAdd(int, CNSItem *);    PATCH_MEMBER(int, CacheAdd, int _COMMA CNSItem *, 0x419AE0);
    int CacheDelete(int);    PATCH_MEMBER(int, CacheDelete, int, 0x419B90);
    void CacheDeleteAll();
    CNSItem * CacheGetObject(int);    PATCH_MEMBER(CNSItem *, CacheGetObject, int, 0x418940);
    int CachePacketObject(int, CPacket &, int, unsigned short, unsigned long);    PATCH_MEMBER(int, CachePacketObject, int _COMMA CPacket & _COMMA int _COMMA unsigned short _COMMA unsigned long, 0x418A20);
    int CacheLoad();    PATCH_MEMBER(int, CacheLoad, , 0x418C20);
    CNSAuction & operator=(const CNSAuction &);
    //void * __vecDelDtor(unsigned int);

/*struct _Invoke {
PATCH_MEMBER_INVOKE(CNSAuction &, CNSAuction, Constructor, );
PATCH_MEMBER_INVOKE(void, CNSAuction, Destructor, );
PATCH_MEMBER_INVOKE(int, CNSAuction, Init, );
PATCH_MEMBER_INVOKE(int, CNSAuction, Add, CNSPc * _COMMA unsigned long _COMMA unsigned long _COMMA unsigned short _COMMA unsigned char);
PATCH_MEMBER_INVOKE(int, CNSAuction, Delete, int _COMMA int _COMMA int);
PATCH_MEMBER_INVOKE(int, CNSAuction, Delete, CNSPc * _COMMA int);
PATCH_MEMBER_INVOKE(int, CNSAuction, Sell, CNSPc * _COMMA int);
PATCH_MEMBER_INVOKE(unsigned long, CNSAuction, DBAuctionCount, char *);
PATCH_MEMBER_INVOKE(unsigned long, CNSAuction, DBAuctionList, CNSPc * _COMMA CNSAuction::SEARCHTYPE _COMMA unsigned long _COMMA unsigned long & _COMMA CPacket & _COMMA unsigned char);
PATCH_MEMBER_INVOKE(unsigned long, CNSAuction, DebugDBAuctionList, CNSPc * _COMMA CNSAuction::SEARCHTYPE _COMMA unsigned long);
PATCH_MEMBER_INVOKE(int, CNSAuction, DBAuctionItem, int _COMMA unsigned char & _COMMA unsigned long &);
PATCH_MEMBER_INVOKE(void, CNSAuction, DebugList, CNSPc *);
PATCH_MEMBER_INVOKE(unsigned long, CNSAuction, CheckItem, );
PATCH_MEMBER_INVOKE(void, CNSAuction, Process, unsigned long);
PATCH_MEMBER_INVOKE(int, CNSAuction, CacheAdd, int _COMMA CNSItem *);
PATCH_MEMBER_INVOKE(int, CNSAuction, CacheDelete, int);
PATCH_MEMBER_INVOKE(CNSItem *, CNSAuction, CacheGetObject, int);
PATCH_MEMBER_INVOKE(int, CNSAuction, CachePacketObject, int _COMMA CPacket & _COMMA int _COMMA unsigned short _COMMA unsigned long);
PATCH_MEMBER_INVOKE(int, CNSAuction, CacheLoad, );
};*/

#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(CNSAuction::Constructor(), 0x416B70);
//DEFINE_NAKED_JMP(CNSAuction::Destructor(), 0x416BD0);
//DEFINE_NAKED_JMP(int CNSAuction::Init(), 0x416C30);
//DEFINE_NAKED_JMP(int CNSAuction::Add(CNSPc * _COMMA unsigned long _COMMA unsigned long _COMMA unsigned short _COMMA unsigned char), 0x416C50);
//DEFINE_NAKED_JMP(int CNSAuction::Delete(int _COMMA int _COMMA int), 0x417380);
//DEFINE_NAKED_JMP(int CNSAuction::Delete(CNSPc * _COMMA int), 0x417510);
//DEFINE_NAKED_JMP(int CNSAuction::Sell(CNSPc * _COMMA int), 0x417560);
//DEFINE_NAKED_JMP(unsigned long CNSAuction::DBAuctionCount(char *), 0x418050);
//DEFINE_NAKED_JMP(unsigned long CNSAuction::DBAuctionList(CNSPc * _COMMA CNSAuction::SEARCHTYPE _COMMA unsigned long _COMMA unsigned long & _COMMA CPacket & _COMMA unsigned char), 0x417A20);
//DEFINE_NAKED_JMP(unsigned long CNSAuction::DebugDBAuctionList(CNSPc * _COMMA CNSAuction::SEARCHTYPE _COMMA unsigned long), 0x418290);
//DEFINE_NAKED_JMP(int CNSAuction::DBAuctionItem(int _COMMA unsigned char & _COMMA unsigned long &), 0x418150);
//DEFINE_NAKED_JMP(void CNSAuction::DebugList(CNSPc *), 0x4198D0);
//DEFINE_NAKED_JMP(unsigned long CNSAuction::CheckItem(), 0x4192C0);
//DEFINE_NAKED_JMP(void CNSAuction::Process(unsigned long), 0x4199F0);
//DEFINE_NAKED_JMP(int CNSAuction::CacheAdd(int _COMMA CNSItem *), 0x419AE0);
//DEFINE_NAKED_JMP(int CNSAuction::CacheDelete(int), 0x419B90);
//DEFINE_NAKED_JMP(CNSItem * CNSAuction::CacheGetObject(int), 0x418940);
//DEFINE_NAKED_JMP(int CNSAuction::CachePacketObject(int _COMMA CPacket & _COMMA int _COMMA unsigned short _COMMA unsigned long), 0x418A20);
//DEFINE_NAKED_JMP(int CNSAuction::CacheLoad(), 0x418C20);
#endif
};



#endif