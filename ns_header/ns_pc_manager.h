#ifndef NSHEADER_NSPCMANAGER_H_
#define NSHEADER_NSPCMANAGER_H_

#include "ns_header/ns_thread.h"

class CNSGuild;
class CNSPcDamageCounter;
class CNSPcManager;
class CNSPcManagerExt;
class CNSPcExt;

template <>
class CSingleton<CNSPcManager> {
public:
    static const unsigned int _size = 0x1;

    static CNSPcManagerExt * GetInstance();    PATCH_STATIC(CNSPcManager *, GetInstance, , 0x403780);
    static void ReleaseInstance();    PATCH_STATIC(void, ReleaseInstance, , 0x403810);
    static class CNSPcManagerExt * m_selfInstance;//[0x559E24]  [00159E24:0003:00039E24]

    /*struct _Invoke {
    PATCH_STATIC_INVOKE(CNSPcManager *, GetInstance, );
    PATCH_STATIC_INVOKE(void, ReleaseInstance, );
    };*/
};
#ifdef DEFINE_NS_CPP
DEFINE_NAKED_JMP(CNSPcManagerExt * CSingleton<CNSPcManager>::GetInstance(), 0x403780);
//DEFINE_NAKED_JMP(void CSingleton<CNSPcManager>::ReleaseInstance(), 0x403810);
#endif


class CNSPcManager : public CThread, public CSingleton<CNSPcManager> {
public:
    static const unsigned int _size = 0x112cc;

    CNSPcManager(const CNSPcManager &);
    CNSPcManager();    PATCH_MEMBER(CNSPcManager &, Constructor, , 0x4866B0);
    virtual ~CNSPcManager();    PATCH_MEMBER(void, Destructor, , 0x486840);
    virtual void Action();    PATCH_MEMBER(void, Action, , 0x48B6C0);
    int Init();    PATCH_MEMBER(int, Init, , 0x486920);
    void Stop();    PATCH_MEMBER(void, Stop, , 0x486950);
    unsigned long GetCount();    PATCH_MEMBER(unsigned long, GetCount, , 0x486970);
    void GetUserCount(unsigned short *);    PATCH_MEMBER(void, GetUserCount, unsigned short *, 0x4869F0);
    void Config(int, int);    PATCH_MEMBER(void, Config, int _COMMA int, 0x486B30);
    void Add(unsigned long, CNSPc *);    PATCH_MEMBER(void, Add, unsigned long _COMMA CNSPc *, 0x486B60);
    int Delete(unsigned long);    PATCH_MEMBER(int, Delete, unsigned long, 0x486BF0);
    CNSPc * _FindUser(unsigned long);    PATCH_MEMBER(CNSPc *, FindUser, unsigned long, 0x486C90);
    CNSPc * _FindUserId(char *);    PATCH_MEMBER(CNSPc *, FindUserId, char *, 0x486D80);
    CNSObject::Owner<CNSPc> FindUserAlias(char *szUserAlias, int bLoginCheck) { CNSObject::Owner<CNSPc>(_FindUserAlias(szUserAlias, bLoginCheck)); } CNSPc * _FindUserAlias(char *, int);    PATCH_MEMBER(CNSPc *, FindUserAlias, char * _COMMA int, 0x489FE0);
    CNSPc * _FindUserAliasSeq(int, int);    PATCH_MEMBER(CNSPc *, FindUserAliasSeq, int _COMMA int, 0x48A190);
    unsigned long GetUserIdCount(char *);    PATCH_MEMBER(unsigned long, GetUserIdCount, char *, 0x486EB0);
    int ExistUserId(char *);
    unsigned long GetRectInPcCount(unsigned char, unsigned short, unsigned short, unsigned short, unsigned short, unsigned char, unsigned char);    PATCH_MEMBER(unsigned long, GetRectInPcCount, unsigned char _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char _COMMA unsigned char, 0x486FC0);
    unsigned long GetRectInPcAvrLevel(unsigned char, unsigned short, unsigned short, unsigned short, unsigned short, unsigned char);    PATCH_MEMBER(unsigned long, GetRectInPcAvrLevel, unsigned char _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char, 0x487630);
    unsigned long GetRectInSiegeWeaponCount(unsigned short, unsigned short, unsigned short, unsigned short, unsigned short, unsigned char);    PATCH_MEMBER(unsigned long, GetRectInSiegeWeaponCount, unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char, 0x487B20);
    unsigned long HealRectInPersonalSiegeWeapon(unsigned char, unsigned short, unsigned short, unsigned short, unsigned short, unsigned short, unsigned char);    PATCH_MEMBER(unsigned long, HealRectInPersonalSiegeWeapon, unsigned char _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char, 0x487CC0);
    unsigned long GetRectInMyParty(CNSPc *, unsigned short, unsigned short, unsigned short, unsigned short, unsigned char);    PATCH_MEMBER(unsigned long, GetRectInMyParty, CNSPc * _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char, 0x487F20);
    void AddRectInPcRealmPoint(unsigned char, unsigned short, unsigned short, unsigned short, unsigned short, unsigned char, unsigned long);    PATCH_MEMBER(void, AddRectInPcRealmPoint, unsigned char _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char _COMMA unsigned long, 0x4877F0);
    unsigned long AutoRectInPartyJoin(unsigned char, unsigned short, unsigned short, unsigned short, unsigned short, unsigned char);    PATCH_MEMBER(unsigned long, AutoRectInPartyJoin, unsigned char _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char, 0x4880B0);
    void AttackRectInPc(unsigned char, unsigned char, unsigned short, unsigned short, unsigned short, unsigned short, unsigned short, unsigned char);    PATCH_MEMBER(void, AttackRectInPc, unsigned char _COMMA unsigned char _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char, 0x488570);
    void LevelUpRectInPc(unsigned short, unsigned short, unsigned short, unsigned short, unsigned char, int);    PATCH_MEMBER(void, LevelUpRectInPc, unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char _COMMA int, 0x4872F0);
    void AddRectInPcExpPoint(unsigned char, unsigned char, unsigned char, unsigned short, unsigned short, unsigned short, unsigned short, unsigned char, unsigned long);    PATCH_MEMBER(void, AddRectInPcExpPoint, unsigned char _COMMA unsigned char _COMMA unsigned char _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char _COMMA unsigned long, 0x487970);
    unsigned long AddRectInPcItem(unsigned char, unsigned short, unsigned short, unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);    PATCH_MEMBER(unsigned long, AddRectInPcItem, unsigned char _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char _COMMA unsigned short _COMMA unsigned char, 0x487160);
    void Broadcast(CPacket &, unsigned short, unsigned short, unsigned short, unsigned short);    PATCH_MEMBER(void, Broadcast, CPacket & _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short, 0x489570);
    void Broadcast(CPacket &, unsigned char, unsigned char);    PATCH_MEMBER(void, Broadcast, CPacket & _COMMA unsigned char _COMMA unsigned char, 0x488890);
    void BroadcastCh(CPacket &, unsigned char, unsigned short, unsigned char);    PATCH_MEMBER(void, BroadcastCh, CPacket & _COMMA unsigned char _COMMA unsigned short _COMMA unsigned char, 0x488AD0);
    void BroadcastTipMessage(char *);    PATCH_MEMBER(void, BroadcastTipMessage, char *, 0x488A40);
    void CheckZoneChannel();    PATCH_MEMBER(void, CheckZoneChannel, , 0x488CC0);
    void SearchItem(CNSPc *, char *);    PATCH_MEMBER(void, SearchItem, CNSPc * _COMMA char *, 0x4896D0);
    void ChangeUserAlias(char *, char *, unsigned char);    PATCH_MEMBER(void, ChangeUserAlias, char * _COMMA char * _COMMA unsigned char, 0x489270);
    void HitBuff(int, CNSPc *);    PATCH_MEMBER(void, HitBuff, int _COMMA CNSPc *, 0x489800);
    void HitDebuff(int, unsigned char, CNSPc *);    PATCH_MEMBER(void, HitDebuff, int _COMMA unsigned char _COMMA CNSPc *, 0x489AE0);
    void BroadcastBuff(int, unsigned char, unsigned char);    PATCH_MEMBER(void, BroadcastBuff, int _COMMA unsigned char _COMMA unsigned char, 0x489D10);
    void WarpArea(unsigned short, unsigned short, unsigned short, unsigned short, unsigned char, unsigned short, unsigned short, unsigned long);    PATCH_MEMBER(void, WarpArea, unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char _COMMA unsigned short _COMMA unsigned short _COMMA unsigned long, 0x489390);
    void BroadcastEnterMessage_PVPTournamentZone();    PATCH_MEMBER(void, BroadcastEnterMessage_PVPTournamentZone, , 0x489EE0);
    void PartyAdd(unsigned short, CNSPcParty *);    PATCH_MEMBER(void, PartyAdd, unsigned short _COMMA CNSPcParty *, 0x48A310);
    int PartyDelete(unsigned short);    PATCH_MEMBER(int, PartyDelete, unsigned short, 0x48A3A0);
    CNSPcParty * PartyFind(unsigned short);    PATCH_MEMBER(CNSPcParty *, PartyFind, unsigned short, 0x48A440);
    void PartyPrintList(CNSPc *, int);    PATCH_MEMBER(void, PartyPrintList, CNSPc * _COMMA int, 0x488E50);
    void PVPTournamentZonePrintList(CNSPc *);    PATCH_MEMBER(void, PVPTournamentZonePrintList, CNSPc *, 0x489110);
    void GuildAdd(int, CNSGuild *);    PATCH_MEMBER(void, GuildAdd, int _COMMA CNSGuild *, 0x48A520);
    int GuildDelete(int);    PATCH_MEMBER(int, GuildDelete, int, 0x48A5B0);
    CNSObject::Owner<CNSGuild> GuildFind(int nDbSeq) { return CNSObject::Owner<CNSGuild>(_GuildFind(nDbSeq)); } CNSGuild * _GuildFind(int);    PATCH_MEMBER(CNSGuild *, _GuildFind, int, 0x48A650);
    unsigned long GuildSaveAll();    PATCH_MEMBER(unsigned long, GuildSaveAll, , 0x48A740);
    unsigned long DamageCounterAdd(int, CNSPc *);    PATCH_MEMBER(unsigned long, DamageCounterAdd, int _COMMA CNSPc *, 0x48A860);
    void DamageCounterDeleteOld(int);    PATCH_MEMBER(void, DamageCounterDeleteOld, int, 0x48A9B0);
    void DamageCounterGhostCheck();    PATCH_MEMBER(void, DamageCounterGhostCheck, , 0x48AA70);
    int GetUserMax();    PATCH_MEMBER(int, GetUserMax, , 0x4C9490);
    int GetServerPort();    PATCH_MEMBER(int, GetServerPort, , 0x484730);
    int CheckNsChargeTime();    PATCH_MEMBER(int, CheckNsChargeTime, , 0x484C60);
    void DebugPrint();    PATCH_MEMBER(void, DebugPrint, , 0x48AE90);
    CNSCriticalSection * GetLockObject();    PATCH_MEMBER(CNSCriticalSection *, GetLockObject, , 0x484C80);
    void SaveAll();    PATCH_MEMBER(void, SaveAll, , 0x48ABE0);
    void ChannelGhostKiller();    PATCH_MEMBER(void, ChannelGhostKiller, , 0x48ACD0);
    char m_szLog[0xA000];//this+0x10
    void LogAdd(char *, ...);
    char * LogGet();
    void LogClear();
    void SetWarpRaceRegion();    PATCH_MEMBER(void, SetWarpRaceRegion, , 0x4C9410);
    class CNSPcChatChannelList m_ChatChannel;//this+0xA010
    unsigned long m_dwLagTest;//this+0x101B8
    int m_bThreadLoop;//this+0x101BC
    class std::map<unsigned long,CNSPc *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const ,CNSPc *> > > m_mapPc;//this+0x101C0
    class std::map<unsigned short,CNSPcParty *,std::less<unsigned short>,std::allocator<std::pair<unsigned short const ,CNSPcParty *> > > m_mapParty;//this+0x101E0
    class std::map<int,CNSGuild *,std::less<int>,std::allocator<std::pair<int const ,CNSGuild *> > > m_mapGuild;//this+0x10200
    class std::map<int,CNSPcDamageCounter *,std::less<int>,std::allocator<std::pair<int const ,CNSPcDamageCounter *> > > m_mapDamageCounter;//this+0x10220
    class CNSCriticalSection m_csPc;//this+0x10240
    class CNSCriticalSection m_csParty;//this+0x1065C
    class CNSCriticalSection m_csGuild;//this+0x10A78
    class CNSCriticalSection m_csDamageCounter;//this+0x10E94
    int m_nUserMax;//this+0x112B0
    int m_nServerPort;//this+0x112B4
    unsigned short m_wNsChargeHour;//this+0x112B8
    int m_bNsChargeTime;//this+0x112BC
    unsigned short m_wWarpRaceRegionDay;//this+0x112C0
    int m_bWarpRaceRegion;//this+0x112C4
    unsigned long m_dwTickCounter;//this+0x112C8
    unsigned long PcAction(CNSPc *, unsigned long, int, int);    PATCH_MEMBER(unsigned long, PcAction, CNSPc * _COMMA unsigned long _COMMA int _COMMA int, 0x48B210);
    void Process(unsigned long);    PATCH_MEMBER(void, Process, unsigned long, 0x48B360);
    int EventNeoSteamCard(_SYSTEMTIME &);    PATCH_MEMBER(int, EventNeoSteamCard, _SYSTEMTIME &, 0x48B800);
    int EventEveryHour(_SYSTEMTIME &);    PATCH_MEMBER(int, EventEveryHour, _SYSTEMTIME &, 0x48B910);
    CNSPcManager & operator=(const CNSPcManager &);
    //void __local_vftable_ctor_closure();
    //virtual void * __vecDelDtor(unsigned int);

    /*struct _Invoke {
    PATCH_MEMBER_INVOKE(CNSPcManager &, CNSPcManager, Constructor, );
    PATCH_MEMBER_INVOKE(void, CNSPcManager, Destructor, );
    PATCH_MEMBER_INVOKE(void, CNSPcManager, Action, );
    PATCH_MEMBER_INVOKE(int, CNSPcManager, Init, );
    PATCH_MEMBER_INVOKE(void, CNSPcManager, Stop, );
    PATCH_MEMBER_INVOKE(unsigned long, CNSPcManager, GetCount, );
    PATCH_MEMBER_INVOKE(void, CNSPcManager, GetUserCount, unsigned short *);
    PATCH_MEMBER_INVOKE(void, CNSPcManager, Config, int _COMMA int);
    PATCH_MEMBER_INVOKE(void, CNSPcManager, Add, unsigned long _COMMA CNSPc *);
    PATCH_MEMBER_INVOKE(int, CNSPcManager, Delete, unsigned long);
    PATCH_MEMBER_INVOKE(CNSPc *, CNSPcManager, _FindUser, unsigned long);
    PATCH_MEMBER_INVOKE(CNSPc *, CNSPcManager, _FindUserId, char *);
    PATCH_MEMBER_INVOKE(CNSPc *, CNSPcManager, _FindUserAlias, char * _COMMA int);
    PATCH_MEMBER_INVOKE(CNSPc *, CNSPcManager, _FindUserAliasSeq, int _COMMA int);
    PATCH_MEMBER_INVOKE(unsigned long, CNSPcManager, GetUserIdCount, char *);
    PATCH_MEMBER_INVOKE(unsigned long, CNSPcManager, GetRectInPcCount, unsigned char _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char _COMMA unsigned char);
    PATCH_MEMBER_INVOKE(unsigned long, CNSPcManager, GetRectInPcAvrLevel, unsigned char _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char);
    PATCH_MEMBER_INVOKE(unsigned long, CNSPcManager, GetRectInSiegeWeaponCount, unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char);
    PATCH_MEMBER_INVOKE(unsigned long, CNSPcManager, HealRectInPersonalSiegeWeapon, unsigned char _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char);
    PATCH_MEMBER_INVOKE(unsigned long, CNSPcManager, GetRectInMyParty, CNSPc * _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char);
    PATCH_MEMBER_INVOKE(void, CNSPcManager, AddRectInPcRealmPoint, unsigned char _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char _COMMA unsigned long);
    PATCH_MEMBER_INVOKE(unsigned long, CNSPcManager, AutoRectInPartyJoin, unsigned char _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char);
    PATCH_MEMBER_INVOKE(void, CNSPcManager, AttackRectInPc, unsigned char _COMMA unsigned char _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char);
    PATCH_MEMBER_INVOKE(void, CNSPcManager, LevelUpRectInPc, unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char _COMMA int);
    PATCH_MEMBER_INVOKE(void, CNSPcManager, AddRectInPcExpPoint, unsigned char _COMMA unsigned char _COMMA unsigned char _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char _COMMA unsigned long);
    PATCH_MEMBER_INVOKE(unsigned long, CNSPcManager, AddRectInPcItem, unsigned char _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char _COMMA unsigned short _COMMA unsigned char);
    PATCH_MEMBER_INVOKE(void, CNSPcManager, Broadcast, CPacket & _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(void, CNSPcManager, Broadcast, CPacket & _COMMA unsigned char _COMMA unsigned char);
    PATCH_MEMBER_INVOKE(void, CNSPcManager, BroadcastCh, CPacket & _COMMA unsigned char _COMMA unsigned short _COMMA unsigned char);
    PATCH_MEMBER_INVOKE(void, CNSPcManager, BroadcastTipMessage, char *);
    PATCH_MEMBER_INVOKE(void, CNSPcManager, CheckZoneChannel, );
    PATCH_MEMBER_INVOKE(void, CNSPcManager, SearchItem, CNSPc * _COMMA char *);
    PATCH_MEMBER_INVOKE(void, CNSPcManager, ChangeUserAlias, char * _COMMA char * _COMMA unsigned char);
    PATCH_MEMBER_INVOKE(void, CNSPcManager, HitBuff, int _COMMA CNSPc *);
    PATCH_MEMBER_INVOKE(void, CNSPcManager, HitDebuff, int _COMMA unsigned char _COMMA CNSPc *);
    PATCH_MEMBER_INVOKE(void, CNSPcManager, BroadcastBuff, int _COMMA unsigned char _COMMA unsigned char);
    PATCH_MEMBER_INVOKE(void, CNSPcManager, WarpArea, unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char _COMMA unsigned short _COMMA unsigned short _COMMA unsigned long);
    PATCH_MEMBER_INVOKE(void, CNSPcManager, BroadcastEnterMessage_PVPTournamentZone, );
    PATCH_MEMBER_INVOKE(void, CNSPcManager, PartyAdd, unsigned short _COMMA CNSPcParty *);
    PATCH_MEMBER_INVOKE(int, CNSPcManager, PartyDelete, unsigned short);
    PATCH_MEMBER_INVOKE(CNSPcParty *, CNSPcManager, PartyFind, unsigned short);
    PATCH_MEMBER_INVOKE(void, CNSPcManager, PartyPrintList, CNSPc * _COMMA int);
    PATCH_MEMBER_INVOKE(void, CNSPcManager, PVPTournamentZonePrintList, CNSPc *);
    PATCH_MEMBER_INVOKE(void, CNSPcManager, GuildAdd, int _COMMA CNSGuild *);
    PATCH_MEMBER_INVOKE(int, CNSPcManager, GuildDelete, int);
    PATCH_MEMBER_INVOKE(CNSGuild *, CNSPcManager, _GuildFind, int);
    PATCH_MEMBER_INVOKE(unsigned long, CNSPcManager, GuildSaveAll, );
    PATCH_MEMBER_INVOKE(unsigned long, CNSPcManager, DamageCounterAdd, int _COMMA CNSPc *);
    PATCH_MEMBER_INVOKE(void, CNSPcManager, DamageCounterDeleteOld, int);
    PATCH_MEMBER_INVOKE(void, CNSPcManager, DamageCounterGhostCheck, );
    PATCH_MEMBER_INVOKE(int, CNSPcManager, GetUserMax, );
    PATCH_MEMBER_INVOKE(int, CNSPcManager, GetServerPort, );
    PATCH_MEMBER_INVOKE(int, CNSPcManager, CheckNsChargeTime, );
    PATCH_MEMBER_INVOKE(void, CNSPcManager, DebugPrint, );
    PATCH_MEMBER_INVOKE(CNSCriticalSection *, CNSPcManager, GetLockObject, );
    PATCH_MEMBER_INVOKE(void, CNSPcManager, SaveAll, );
    PATCH_MEMBER_INVOKE(void, CNSPcManager, ChannelGhostKiller, );
    PATCH_MEMBER_INVOKE(void, CNSPcManager, SetWarpRaceRegion, );
    PATCH_MEMBER_INVOKE(unsigned long, CNSPcManager, PcAction, CNSPc * _COMMA unsigned long _COMMA int _COMMA int);
    PATCH_MEMBER_INVOKE(void, CNSPcManager, Process, unsigned long);
    PATCH_MEMBER_INVOKE(int, CNSPcManager, EventNeoSteamCard, _SYSTEMTIME &);
    PATCH_MEMBER_INVOKE(int, CNSPcManager, EventEveryHour, _SYSTEMTIME &);
    };*/
};
#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(CNSPcManager::Constructor(), 0x4866B0);
//DEFINE_NAKED_JMP(CNSPcManager::Destructor(), 0x486840);
DEFINE_NAKED_JMP(void CNSPcManager::Action(), 0x48B6C0);
DEFINE_NAKED_JMP(int CNSPcManager::Init(), 0x486920);
DEFINE_NAKED_JMP(void CNSPcManager::Stop(), 0x486950);
DEFINE_NAKED_JMP(unsigned long CNSPcManager::GetCount(), 0x486970);
DEFINE_NAKED_JMP(void CNSPcManager::GetUserCount(unsigned short *), 0x4869F0);
DEFINE_NAKED_JMP(void CNSPcManager::Config(int _COMMA int), 0x486B30);
DEFINE_NAKED_JMP(void CNSPcManager::Add(unsigned long _COMMA CNSPc *), 0x486B60);
DEFINE_NAKED_JMP(int CNSPcManager::Delete(unsigned long), 0x486BF0);
DEFINE_NAKED_JMP(CNSPc * CNSPcManager::_FindUser(unsigned long), 0x486C90);
DEFINE_NAKED_JMP(CNSPc * CNSPcManager::_FindUserId(char *), 0x486D80);
DEFINE_NAKED_JMP(CNSPc * CNSPcManager::_FindUserAlias(char * _COMMA int), 0x489FE0);
DEFINE_NAKED_JMP(CNSPc * CNSPcManager::_FindUserAliasSeq(int _COMMA int), 0x48A190);
DEFINE_NAKED_JMP(unsigned long CNSPcManager::GetUserIdCount(char *), 0x486EB0);
DEFINE_NAKED_JMP(unsigned long CNSPcManager::GetRectInPcCount(unsigned char _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char _COMMA unsigned char), 0x486FC0);
DEFINE_NAKED_JMP(unsigned long CNSPcManager::GetRectInPcAvrLevel(unsigned char _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char), 0x487630);
DEFINE_NAKED_JMP(unsigned long CNSPcManager::GetRectInSiegeWeaponCount(unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char), 0x487B20);
DEFINE_NAKED_JMP(unsigned long CNSPcManager::HealRectInPersonalSiegeWeapon(unsigned char _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char), 0x487CC0);
DEFINE_NAKED_JMP(unsigned long CNSPcManager::GetRectInMyParty(CNSPc * _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char), 0x487F20);
DEFINE_NAKED_JMP(void CNSPcManager::AddRectInPcRealmPoint(unsigned char _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char _COMMA unsigned long), 0x4877F0);
DEFINE_NAKED_JMP(unsigned long CNSPcManager::AutoRectInPartyJoin(unsigned char _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char), 0x4880B0);
DEFINE_NAKED_JMP(void CNSPcManager::AttackRectInPc(unsigned char _COMMA unsigned char _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char), 0x488570);
DEFINE_NAKED_JMP(void CNSPcManager::LevelUpRectInPc(unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char _COMMA int), 0x4872F0);
DEFINE_NAKED_JMP(void CNSPcManager::AddRectInPcExpPoint(unsigned char _COMMA unsigned char _COMMA unsigned char _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char _COMMA unsigned long), 0x487970);
DEFINE_NAKED_JMP(unsigned long CNSPcManager::AddRectInPcItem(unsigned char _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char _COMMA unsigned short _COMMA unsigned char), 0x487160);
DEFINE_NAKED_JMP(void CNSPcManager::Broadcast(CPacket & _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short), 0x489570);
DEFINE_NAKED_JMP(void CNSPcManager::Broadcast(CPacket & _COMMA unsigned char _COMMA unsigned char), 0x488890);
DEFINE_NAKED_JMP(void CNSPcManager::BroadcastCh(CPacket & _COMMA unsigned char _COMMA unsigned short _COMMA unsigned char), 0x488AD0);
DEFINE_NAKED_JMP(void CNSPcManager::BroadcastTipMessage(char *), 0x488A40);
DEFINE_NAKED_JMP(void CNSPcManager::CheckZoneChannel(), 0x488CC0);
DEFINE_NAKED_JMP(void CNSPcManager::SearchItem(CNSPc * _COMMA char *), 0x4896D0);
DEFINE_NAKED_JMP(void CNSPcManager::ChangeUserAlias(char * _COMMA char * _COMMA unsigned char), 0x489270);
DEFINE_NAKED_JMP(void CNSPcManager::HitBuff(int _COMMA CNSPc *), 0x489800);
DEFINE_NAKED_JMP(void CNSPcManager::HitDebuff(int _COMMA unsigned char _COMMA CNSPc *), 0x489AE0);
DEFINE_NAKED_JMP(void CNSPcManager::BroadcastBuff(int _COMMA unsigned char _COMMA unsigned char), 0x489D10);
DEFINE_NAKED_JMP(void CNSPcManager::WarpArea(unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char _COMMA unsigned short _COMMA unsigned short _COMMA unsigned long), 0x489390);
DEFINE_NAKED_JMP(void CNSPcManager::BroadcastEnterMessage_PVPTournamentZone(), 0x489EE0);
DEFINE_NAKED_JMP(void CNSPcManager::PartyAdd(unsigned short _COMMA CNSPcParty *), 0x48A310);
DEFINE_NAKED_JMP(int CNSPcManager::PartyDelete(unsigned short), 0x48A3A0);
//DEFINE_NAKED_JMP(CNSPcParty * CNSPcManager::PartyFind(unsigned short), 0x48A440);
DEFINE_NAKED_JMP(void CNSPcManager::PartyPrintList(CNSPc * _COMMA int), 0x488E50);
DEFINE_NAKED_JMP(void CNSPcManager::PVPTournamentZonePrintList(CNSPc *), 0x489110);
DEFINE_NAKED_JMP(void CNSPcManager::GuildAdd(int _COMMA CNSGuild *), 0x48A520);
DEFINE_NAKED_JMP(int CNSPcManager::GuildDelete(int), 0x48A5B0);
DEFINE_NAKED_JMP(CNSGuild * CNSPcManager::_GuildFind(int), 0x48A650);
DEFINE_NAKED_JMP(unsigned long CNSPcManager::GuildSaveAll(), 0x48A740);
DEFINE_NAKED_JMP(unsigned long CNSPcManager::DamageCounterAdd(int _COMMA CNSPc *), 0x48A860);
DEFINE_NAKED_JMP(void CNSPcManager::DamageCounterDeleteOld(int), 0x48A9B0);
DEFINE_NAKED_JMP(void CNSPcManager::DamageCounterGhostCheck(), 0x48AA70);
DEFINE_NAKED_JMP(int CNSPcManager::GetUserMax(), 0x4C9490);
DEFINE_NAKED_JMP(int CNSPcManager::GetServerPort(), 0x484730);
DEFINE_NAKED_JMP(int CNSPcManager::CheckNsChargeTime(), 0x484C60);
DEFINE_NAKED_JMP(void CNSPcManager::DebugPrint(), 0x48AE90);
DEFINE_NAKED_JMP(CNSCriticalSection * CNSPcManager::GetLockObject(), 0x484C80);
DEFINE_NAKED_JMP(void CNSPcManager::SaveAll(), 0x48ABE0);
DEFINE_NAKED_JMP(void CNSPcManager::ChannelGhostKiller(), 0x48ACD0);
DEFINE_NAKED_JMP(void CNSPcManager::SetWarpRaceRegion(), 0x4C9410);
DEFINE_NAKED_JMP(unsigned long CNSPcManager::PcAction(CNSPc * _COMMA unsigned long _COMMA int _COMMA int), 0x48B210);
DEFINE_NAKED_JMP(void CNSPcManager::Process(unsigned long), 0x48B360);
DEFINE_NAKED_JMP(int CNSPcManager::EventNeoSteamCard(_SYSTEMTIME &), 0x48B800);
DEFINE_NAKED_JMP(int CNSPcManager::EventEveryHour(_SYSTEMTIME &), 0x48B910);
#endif





#endif