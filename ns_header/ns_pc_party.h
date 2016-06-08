#ifndef NSHEADER_NS_PC_PARTY_H_
#define NSHEADER_NS_PC_PARTY_H_

#include "ns_header/ns_object.h"

class CNSPcParty : public CNSObject {
public:
    static const unsigned int _size = 0xb28;

    enum LOOTMODE {
        LootMode_Free = 0x0,
        LootMode_Order = 0x1,
        LootMode_Random = 0x2,
    };

    CNSPcParty(const CNSPcParty &);
    CNSPcParty(CNSPc *, char *, char *, CNSPcParty::LOOTMODE);    PATCH_MEMBER(CNSPcParty &, Constructor, CNSPc * _COMMA char * _COMMA char * _COMMA CNSPcParty::LOOTMODE, 0x490000);
    virtual ~CNSPcParty();    PATCH_MEMBER(void, Destructor, , 0x490170);
    int IsFull();    PATCH_MEMBER(int, IsFull, , 0x492590);
    int IsPrivate();    PATCH_MEMBER(int, IsPrivate, , 0x482800);
    int IsLeader(char *);    PATCH_MEMBER(int, IsLeader, char *, 0x482820);
    int IsMember(char *);    PATCH_MEMBER(int, IsMember, char *, 0x4901C0);
    unsigned long GetCount();    PATCH_MEMBER(unsigned long, GetCount, , 0x483EE0);
    char * GetPartyLeader();    PATCH_MEMBER(char *, GetPartyLeader, , 0x48BEA0);
    char * GetPartyName();    PATCH_MEMBER(char *, GetPartyName, , 0x42B770);
    char * GetPassword();    PATCH_MEMBER(char *, GetPassword, , 0x4C8420);
    int ChangeUserAlias(char *, char *);    PATCH_MEMBER(int, ChangeUserAlias, char * _COMMA char *, 0x490390);
    int Join(CNSPc *, char *);    PATCH_MEMBER(int, Join, CNSPc * _COMMA char *, 0x4906D0);
    int Quit(CNSPc *);    PATCH_MEMBER(int, Quit, CNSPc *, 0x490900);
    void PacketPartyInfo(CPacket &);    PATCH_MEMBER(void, PacketPartyInfo, CPacket &, 0x490410);
    void PacketPartySyncInfo(CPacket &);    PATCH_MEMBER(void, PacketPartySyncInfo, CPacket &, 0x4904F0);
    void Broadcast(CPacket &, unsigned long);    PATCH_MEMBER(void, Broadcast, CPacket & _COMMA unsigned long, 0x490C70);
    void DivisionExp(CNSCharacter *, unsigned char, unsigned short, unsigned long, unsigned long, unsigned short);    PATCH_MEMBER(void, DivisionExp, CNSCharacter * _COMMA unsigned char _COMMA unsigned short _COMMA unsigned long _COMMA unsigned long _COMMA unsigned short, 0x4916D0);
    void DivisionRealmPoint(CNSCharacter *, CNSPc *);    PATCH_MEMBER(void, DivisionRealmPoint, CNSCharacter * _COMMA CNSPc *, 0x491E80);
    void ChangeLootMode(CNSPcParty::LOOTMODE);    PATCH_MEMBER(void, ChangeLootMode, CNSPcParty::LOOTMODE, 0x490190);
    void ChangePartyName(char *);    PATCH_MEMBER(void, ChangePartyName, char *, 0x4C8340);
    void ChangePartyPassword(char *);    PATCH_MEMBER(void, ChangePartyPassword, char *, 0x4C83B0);
    int CheckQuestItem(unsigned short);    PATCH_MEMBER(int, CheckQuestItem, unsigned short, 0x490D30);
    unsigned long HitPartyDamage(CNSPc *, CNSCharacter *, unsigned short, unsigned short, CNSObject::HITTYPE);    PATCH_MEMBER(unsigned long, HitPartyDamage, CNSPc * _COMMA CNSCharacter * _COMMA unsigned short _COMMA unsigned short _COMMA CNSObject::HITTYPE, 0x490DF0);
    int CheckTargetLength(CNSCharacter *, unsigned short);    PATCH_MEMBER(int, CheckTargetLength, CNSCharacter * _COMMA unsigned short, 0x491070);
    void AddQuestItem(unsigned short, unsigned char, unsigned short, unsigned long);    PATCH_MEMBER(void, AddQuestItem, unsigned short _COMMA unsigned char _COMMA unsigned short _COMMA unsigned long, 0x491480);
    unsigned long GetInstantKey(unsigned char);    PATCH_MEMBER(unsigned long, GetInstantKey, unsigned char, 0x491610);
    unsigned short GetMemberBuffValue(CNSBuff::BUFFTYPE);    PATCH_MEMBER(unsigned short, GetMemberBuffValue, CNSBuff::BUFFTYPE, 0x490FB0);
    unsigned char GetMaxLevel(CNSCharacter *, unsigned short);    PATCH_MEMBER(unsigned char, GetMaxLevel, CNSCharacter * _COMMA unsigned short, 0x491120);
    unsigned char GetAvrLevel(CNSCharacter *, unsigned short);    PATCH_MEMBER(unsigned char, GetAvrLevel, CNSCharacter * _COMMA unsigned short, 0x4912D0);
    unsigned char GetAvrLevel();    PATCH_MEMBER(unsigned char, GetAvrLevel, , 0x491200);
    unsigned long GetMemberCount(CNSCharacter *, unsigned short);    PATCH_MEMBER(unsigned long, GetMemberCount, CNSCharacter * _COMMA unsigned short, 0x4913C0);
    CNSPc * Get(int);    PATCH_MEMBER(CNSPc *, Get, int, 0x483F00);
    CNSPc * GetCurrentLootPc();    PATCH_MEMBER(CNSPc *, GetCurrentLootPc, , 0x491560);
    struct PartyMember {
        static const unsigned int _size = 0x20;

        char szUserAlias[0x19];//this+0x0
        unsigned long dwObjectId;//this+0x1C
    };

    struct CNSPcParty::PartyMember m_PartyMember[0x8];//this+0x1C
    class CRand32 m_Rand;//this+0x11C
    unsigned long m_dwCount;//this+0xAE0
    enum CNSPcParty::LOOTMODE m_lootMode;//this+0xAE4
    unsigned long m_dwLootSeq;//this+0xAE8
    char m_szPartyName[0x19];//this+0xAEC
    char m_szPartyPassword[0x9];//this+0xB05
    char m_szPartyLeader[0x19];//this+0xB0E
    void Clear();    PATCH_MEMBER(void, Clear, , 0x4925B0);
    void Create(char *, char *);
    int ChangeLeader(char *);    PATCH_MEMBER(int, ChangeLeader, char *, 0x490220);
    CNSPc * operator[](int);    //PATCH_MEMBER(CNSPc *, operator[], int, 0x490B90);
    CNSPcParty & operator=(const CNSPcParty &);
    //virtual void * __vecDelDtor(unsigned int);

    /*struct _Invoke {
    PATCH_MEMBER_INVOKE(CNSPcParty &, CNSPcParty, Constructor, CNSPc * _COMMA char * _COMMA char * _COMMA CNSPcParty::LOOTMODE);
    PATCH_MEMBER_INVOKE(void, CNSPcParty, Destructor, );
    PATCH_MEMBER_INVOKE(int, CNSPcParty, IsFull, );
    PATCH_MEMBER_INVOKE(int, CNSPcParty, IsPrivate, );
    PATCH_MEMBER_INVOKE(int, CNSPcParty, IsLeader, char *);
    PATCH_MEMBER_INVOKE(int, CNSPcParty, IsMember, char *);
    PATCH_MEMBER_INVOKE(unsigned long, CNSPcParty, GetCount, );
    PATCH_MEMBER_INVOKE(char *, CNSPcParty, GetPartyLeader, );
    PATCH_MEMBER_INVOKE(char *, CNSPcParty, GetPartyName, );
    PATCH_MEMBER_INVOKE(char *, CNSPcParty, GetPassword, );
    PATCH_MEMBER_INVOKE(int, CNSPcParty, ChangeUserAlias, char * _COMMA char *);
    PATCH_MEMBER_INVOKE(int, CNSPcParty, Join, CNSPc * _COMMA char *);
    PATCH_MEMBER_INVOKE(int, CNSPcParty, Quit, CNSPc *);
    PATCH_MEMBER_INVOKE(void, CNSPcParty, PacketPartyInfo, CPacket &);
    PATCH_MEMBER_INVOKE(void, CNSPcParty, PacketPartySyncInfo, CPacket &);
    PATCH_MEMBER_INVOKE(void, CNSPcParty, Broadcast, CPacket & _COMMA unsigned long);
    PATCH_MEMBER_INVOKE(void, CNSPcParty, DivisionExp, CNSCharacter * _COMMA unsigned char _COMMA unsigned short _COMMA unsigned long _COMMA unsigned long _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(void, CNSPcParty, DivisionRealmPoint, CNSCharacter * _COMMA CNSPc *);
    PATCH_MEMBER_INVOKE(void, CNSPcParty, ChangeLootMode, CNSPcParty::LOOTMODE);
    PATCH_MEMBER_INVOKE(void, CNSPcParty, ChangePartyName, char *);
    PATCH_MEMBER_INVOKE(void, CNSPcParty, ChangePartyPassword, char *);
    PATCH_MEMBER_INVOKE(int, CNSPcParty, CheckQuestItem, unsigned short);
    PATCH_MEMBER_INVOKE(unsigned long, CNSPcParty, HitPartyDamage, CNSPc * _COMMA CNSCharacter * _COMMA unsigned short _COMMA unsigned short _COMMA CNSObject::HITTYPE);
    PATCH_MEMBER_INVOKE(int, CNSPcParty, CheckTargetLength, CNSCharacter * _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(void, CNSPcParty, AddQuestItem, unsigned short _COMMA unsigned char _COMMA unsigned short _COMMA unsigned long);
    PATCH_MEMBER_INVOKE(unsigned long, CNSPcParty, GetInstantKey, unsigned char);
    PATCH_MEMBER_INVOKE(unsigned short, CNSPcParty, GetMemberBuffValue, CNSBuff::BUFFTYPE);
    PATCH_MEMBER_INVOKE(unsigned char, CNSPcParty, GetMaxLevel, CNSCharacter * _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(unsigned char, CNSPcParty, GetAvrLevel, CNSCharacter * _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(unsigned char, CNSPcParty, GetAvrLevel, );
    PATCH_MEMBER_INVOKE(unsigned long, CNSPcParty, GetMemberCount, CNSCharacter * _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(CNSPc *, CNSPcParty, Get, int);
    PATCH_MEMBER_INVOKE(CNSPc *, CNSPcParty, GetCurrentLootPc, );
    PATCH_MEMBER_INVOKE(void, CNSPcParty, Clear, );
    PATCH_MEMBER_INVOKE(int, CNSPcParty, ChangeLeader, char *);
    //PATCH_MEMBER_INVOKE(CNSPc *, CNSPcParty, operator[], int);
    };*/
};
#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(CNSPcParty::Constructor(CNSPc * _COMMA char * _COMMA char * _COMMA CNSPcParty::LOOTMODE), 0x490000);
//DEFINE_NAKED_JMP(CNSPcParty::Destructor(), 0x490170);
DEFINE_NAKED_JMP(int CNSPcParty::IsFull(), 0x492590);
DEFINE_NAKED_JMP(int CNSPcParty::IsPrivate(), 0x482800);
DEFINE_NAKED_JMP(int CNSPcParty::IsLeader(char *), 0x482820);
DEFINE_NAKED_JMP(int CNSPcParty::IsMember(char *), 0x4901C0);
DEFINE_NAKED_JMP(unsigned long CNSPcParty::GetCount(), 0x483EE0);
DEFINE_NAKED_JMP(char * CNSPcParty::GetPartyLeader(), 0x48BEA0);
DEFINE_NAKED_JMP(char * CNSPcParty::GetPartyName(), 0x42B770);
DEFINE_NAKED_JMP(char * CNSPcParty::GetPassword(), 0x4C8420);
DEFINE_NAKED_JMP(int CNSPcParty::ChangeUserAlias(char * _COMMA char *), 0x490390);
DEFINE_NAKED_JMP(int CNSPcParty::Join(CNSPc * _COMMA char *), 0x4906D0);
DEFINE_NAKED_JMP(int CNSPcParty::Quit(CNSPc *), 0x490900);
DEFINE_NAKED_JMP(void CNSPcParty::PacketPartyInfo(CPacket &), 0x490410);
DEFINE_NAKED_JMP(void CNSPcParty::PacketPartySyncInfo(CPacket &), 0x4904F0);
DEFINE_NAKED_JMP(void CNSPcParty::Broadcast(CPacket & _COMMA unsigned long), 0x490C70);
DEFINE_NAKED_JMP(void CNSPcParty::DivisionExp(CNSCharacter * _COMMA unsigned char _COMMA unsigned short _COMMA unsigned long _COMMA unsigned long _COMMA unsigned short), 0x4916D0);
DEFINE_NAKED_JMP(void CNSPcParty::DivisionRealmPoint(CNSCharacter * _COMMA CNSPc *), 0x491E80);
DEFINE_NAKED_JMP(void CNSPcParty::ChangeLootMode(CNSPcParty::LOOTMODE), 0x490190);
DEFINE_NAKED_JMP(void CNSPcParty::ChangePartyName(char *), 0x4C8340);
DEFINE_NAKED_JMP(void CNSPcParty::ChangePartyPassword(char *), 0x4C83B0);
DEFINE_NAKED_JMP(int CNSPcParty::CheckQuestItem(unsigned short), 0x490D30);
DEFINE_NAKED_JMP(unsigned long CNSPcParty::HitPartyDamage(CNSPc * _COMMA CNSCharacter * _COMMA unsigned short _COMMA unsigned short _COMMA CNSObject::HITTYPE), 0x490DF0);
DEFINE_NAKED_JMP(int CNSPcParty::CheckTargetLength(CNSCharacter * _COMMA unsigned short), 0x491070);
DEFINE_NAKED_JMP(void CNSPcParty::AddQuestItem(unsigned short _COMMA unsigned char _COMMA unsigned short _COMMA unsigned long), 0x491480);
DEFINE_NAKED_JMP(unsigned long CNSPcParty::GetInstantKey(unsigned char), 0x491610);
DEFINE_NAKED_JMP(unsigned short CNSPcParty::GetMemberBuffValue(CNSBuff::BUFFTYPE), 0x490FB0);
DEFINE_NAKED_JMP(unsigned char CNSPcParty::GetMaxLevel(CNSCharacter * _COMMA unsigned short), 0x491120);
DEFINE_NAKED_JMP(unsigned char CNSPcParty::GetAvrLevel(CNSCharacter * _COMMA unsigned short), 0x4912D0);
DEFINE_NAKED_JMP(unsigned char CNSPcParty::GetAvrLevel(), 0x491200);
DEFINE_NAKED_JMP(unsigned long CNSPcParty::GetMemberCount(CNSCharacter * _COMMA unsigned short), 0x4913C0);
DEFINE_NAKED_JMP(CNSPc * CNSPcParty::Get(int), 0x483F00);
DEFINE_NAKED_JMP(CNSPc * CNSPcParty::GetCurrentLootPc(), 0x491560);
DEFINE_NAKED_JMP(void CNSPcParty::Clear(), 0x4925B0);
DEFINE_NAKED_JMP(int CNSPcParty::ChangeLeader(char *), 0x490220);
DEFINE_NAKED_JMP(CNSPc * CNSPcParty::operator[](int), 0x490B90);
#endif




#endif