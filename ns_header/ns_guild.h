#ifndef NSHEADER_NS_GUILD_H_
#define NSHEADER_NS_GUILD_H_



class CNSGuild : public CNSObject {
public:
    static const unsigned int _size = 0xef8;

    enum GUILDRANK {
        GuildRank_Normal = 0x0,
        GuildRank_Full = 0x1,
        GuildRank_SubMaster = 0xFE,
        GuildRank_Master = 0xFF,
    };

    enum GUILDLOG {
        GuildLog_All = 0x0,
        GuildLog_Point = 0x1,
        GuildLog_Warehouse = 0x2,
    };

    struct GuildMember {
        static const unsigned int _size = 0x28;

        int bStatus;//this+0x0
        char szUserAlias[0x19];//this+0x4
        unsigned char btRank;//this+0x1D
        unsigned long dwObjectId;//this+0x20
        int nAliasSeq;//this+0x24
    };

    struct GuildInfo {
        static const unsigned int _size = 0x148;

        char szGuildMaster[0x19];//this+0x0
        unsigned char btRealm;//this+0x19
        char szGuildName[0x19];//this+0x1A
        unsigned char btLevel;//this+0x33
        int nPoint;//this+0x34
        unsigned long dwMark;//this+0x38
        unsigned long dwRank;//this+0x3C
        unsigned long dwRankPoint;//this+0x40
        unsigned long dwRankMonth;//this+0x44
        char szComment[0x100];//this+0x48
    };

    CNSGuild(const CNSGuild &);
    CNSGuild(int, CNSGuild::GuildInfo &); CNSGuild& Constructor(int, CNSGuild::GuildInfo &);   PATCH_MEMBER(CNSGuild &, Constructor, int _COMMA CNSGuild::GuildInfo &, 0x431E60);
    virtual ~CNSGuild();    PATCH_MEMBER(void, Destructor, , 0x431FE0);
    void Clear();    PATCH_MEMBER(void, Clear, , 0x436600);
    int CloseGuild(CNSPc *);    PATCH_MEMBER(int, CloseGuild, CNSPc *, 0x432CF0);
    int IsFull();    PATCH_MEMBER(int, IsFull, , 0x4365C0);
    int IsFullSubMaster();    PATCH_MEMBER(int, IsFullSubMaster, , 0x432280);
    int IsMaster(char *);    PATCH_MEMBER(int, IsMaster, char *, 0x436570);
    int IsSubMaster(char *);    PATCH_MEMBER(int, IsSubMaster, char *, 0x432580);
    int IsFullMember(char *);    PATCH_MEMBER(int, IsFullMember, char *, 0x4324A0);
    int IsNormalMember(char *);    PATCH_MEMBER(int, IsNormalMember, char *, 0x4323C0);
    int IsMember(char *);    PATCH_MEMBER(int, IsMember, char *, 0x4321B0);
    int GetMemberRank(char *);    PATCH_MEMBER(int, GetMemberRank, char *, 0x4320D0);
    unsigned char GetRealm();    PATCH_MEMBER(unsigned char, GetRealm, , 0x45C500);
    unsigned long GetCount();    PATCH_MEMBER(unsigned long, GetCount, , 0x4B08F0);
    void SetGuildInfo(char *, char *, unsigned char, char *, unsigned long);    PATCH_MEMBER(void, SetGuildInfo, char * _COMMA char * _COMMA unsigned char _COMMA char * _COMMA unsigned long, 0x432060);
    int GetGuildSeq();    PATCH_MEMBER(int, GetGuildSeq, , 0x48FAB0);
    unsigned char GetGuildLevel();    PATCH_MEMBER(unsigned char, GetGuildLevel, , 0x4B08D0);
    char * GetGuildMaster();
    char * GetGuildName();    PATCH_MEMBER(char *, GetGuildName, , 0x45C520);
    unsigned short GetGuildMemberLevel();
    unsigned long GetGuildRank();    PATCH_MEMBER(unsigned long, GetGuildRank, , 0x45C540);
    unsigned long GetGuildMark();    PATCH_MEMBER(unsigned long, GetGuildMark, , 0x4828E0);
    unsigned long GetGuildRankMonth();    PATCH_MEMBER(unsigned long, GetGuildRankMonth, , 0x4B0950);
    int Add(CNSPc *, unsigned char);    PATCH_MEMBER(int, Add, CNSPc * _COMMA unsigned char, 0x433130);
    int Add(int, char *, unsigned char);    PATCH_MEMBER(int, Add, int _COMMA char * _COMMA unsigned char, 0x436650);
    int Update(char *, unsigned char);    PATCH_MEMBER(int, Update, char * _COMMA unsigned char, 0x433240);
    int Delete(char *);    PATCH_MEMBER(int, Delete, char *, 0x4332B0);
    CNSGuild::GuildMember * Find(int);    PATCH_MEMBER(CNSGuild::GuildMember *, Find, int, 0x4326D0);
    CNSGuild::GuildMember * Find(char *);    PATCH_MEMBER(CNSGuild::GuildMember *, Find, char *, 0x432660);
    void JoinMaster(CNSPc *);    PATCH_MEMBER(void, JoinMaster, CNSPc *, 0x4333E0);
    int Join(CNSPc *, CNSPc *);    PATCH_MEMBER(int, Join, CNSPc * _COMMA CNSPc *, 0x433460);
    int Quit(char *);    PATCH_MEMBER(int, Quit, char *, 0x4335E0);
    void LoginAll();    PATCH_MEMBER(void, LoginAll, , 0x4336E0);
    int Login(CNSPc *);    PATCH_MEMBER(int, Login, CNSPc *, 0x4337C0);
    int Logout(unsigned long);    PATCH_MEMBER(int, Logout, unsigned long, 0x4338B0);
    int AddPoint(int);    PATCH_MEMBER(int, AddPoint, int, 0x483F80);
    int GivePoint(int);    PATCH_MEMBER(int, GivePoint, int, 0x4B0910);
    int GetPoint();    PATCH_MEMBER(int, GetPoint, , 0x45C560);
    void Broadcast(CPacket &);    PATCH_MEMBER(void, Broadcast, CPacket &, 0x433980);
    unsigned long PacketInfo(CPacket &);    PATCH_MEMBER(unsigned long, PacketInfo, CPacket &, 0x432E50);
    void SendMemo(CNSPc *, char *);    PATCH_MEMBER(void, SendMemo, CNSPc * _COMMA char *, 0x433AA0);
    int ChangeGuildName(CNSPc *, char *);    PATCH_MEMBER(int, ChangeGuildName, CNSPc * _COMMA char *, 0x4327A0);
    int ChangeLevel(unsigned char);    PATCH_MEMBER(int, ChangeLevel, unsigned char, 0x432880);
    int ChangeMark(unsigned long);    PATCH_MEMBER(int, ChangeMark, unsigned long, 0x4328B0);
    int ChangeComment(CNSPc *, char *);    PATCH_MEMBER(int, ChangeComment, CNSPc * _COMMA char *, 0x4328E0);
    int ChangeMaster(CNSPc *, char *);    PATCH_MEMBER(int, ChangeMaster, CNSPc * _COMMA char *, 0x432A90);
    int ChangeMemberRank(CNSPc *, char *, unsigned char);    PATCH_MEMBER(int, ChangeMemberRank, CNSPc * _COMMA char * _COMMA unsigned char, 0x432950);
    int ChangeUserAlias(char *, char *);    PATCH_MEMBER(int, ChangeUserAlias, char * _COMMA char *, 0x432730);
    static unsigned long DBGuildList(unsigned char, unsigned long, int, CPacket &);    PATCH_STATIC(unsigned long, DBGuildList, unsigned char _COMMA unsigned long _COMMA int _COMMA CPacket &, 0x434E80);
    static int DBInsert(int, unsigned char, char *, char *, int &);    PATCH_STATIC(int, DBInsert, int _COMMA unsigned char _COMMA char * _COMMA char * _COMMA int &, 0x433CC0);
    int DBUpdate();    PATCH_MEMBER(int, DBUpdate, , 0x433DF0);
    int DBPointUpdate();    PATCH_MEMBER(int, DBPointUpdate, , 0x433F30);
    int DBMarkUpdate();    PATCH_MEMBER(int, DBMarkUpdate, , 0x434050);
    int DBDelete();    PATCH_MEMBER(int, DBDelete, , 0x434170);
    unsigned short DBGetMemberLevel();    PATCH_MEMBER(unsigned short, DBGetMemberLevel, , 0x435200);
    int DBLog(char, char *, int, int, int, int);    PATCH_MEMBER(int, DBLog, char _COMMA char * _COMMA int _COMMA int _COMMA int _COMMA int, 0x435560);
    unsigned long DBLogPrint(CNSPc *, CNSGuild::GUILDLOG, unsigned long);    PATCH_MEMBER(unsigned long, DBLogPrint, CNSPc * _COMMA CNSGuild::GUILDLOG _COMMA unsigned long, 0x4356A0);
    int DBPremiumItemAdd(unsigned short);    PATCH_MEMBER(int, DBPremiumItemAdd, unsigned short, 0x435CB0);
    int DBPremiumItemGetDays(unsigned short);    PATCH_MEMBER(int, DBPremiumItemGetDays, unsigned short, 0x435EB0);
    static int DBGetGuildRankMonthName(unsigned char, int, char *, int);    PATCH_STATIC(int, DBGetGuildRankMonthName, unsigned char _COMMA int _COMMA char * _COMMA int, 0x4353B0);
    void Enter();
    void Leave();
    void OnActiveCheck(char *, char *, char *);    PATCH_MEMBER(void, OnActiveCheck, char * _COMMA char * _COMMA char *, 0x433B70);
    void DebugMemberPrint(CNSPc *);    PATCH_MEMBER(void, DebugMemberPrint, CNSPc *, 0x436090);
    int m_nDbSeq;//this+0x1C
    unsigned char m_btRealm;//this+0x20
    unsigned char m_btLevel;//this+0x21
    int m_nPoint;//this+0x24
    unsigned long m_dwCount;//this+0x28
    unsigned long m_dwMark;//this+0x2C
    unsigned long m_dwRank;//this+0x30
    unsigned long m_dwRankPoint;//this+0x34
    unsigned long m_dwRankMonth;//this+0x38
    unsigned long m_dwAllianceGuildId;//this+0x3C
    char m_szGuildName[0x19];//this+0x40
    char m_szGuildMaster[0x19];//this+0x59
    char m_szComment[0x100];//this+0x72
    struct CNSGuild::GuildMember m_GuildMember[0x3C];//this+0x174
    class CNSCriticalSection m_cs;//this+0xAD4
    unsigned short m_wGuildMemberLevel;//this+0xEF0
    unsigned long m_dwLastGuildMemberLevelTime;//this+0xEF4
    int DBMemberInsert(int, unsigned char);    PATCH_MEMBER(int, DBMemberInsert, int _COMMA unsigned char, 0x434290);
    int DBMemberUpdate(char *, unsigned char);    PATCH_MEMBER(int, DBMemberUpdate, char * _COMMA unsigned char, 0x4344E0);
    int DBMemberUpdate(int, unsigned char);    PATCH_MEMBER(int, DBMemberUpdate, int _COMMA unsigned char, 0x4343C0);
    int DBMemberDelete(char *);    PATCH_MEMBER(int, DBMemberDelete, char *, 0x434720);
    int DBMemberDelete(int);    PATCH_MEMBER(int, DBMemberDelete, int, 0x434600);
    int DBMemberRefresh();    PATCH_MEMBER(int, DBMemberRefresh, , 0x434840);
    void SendSyncGuildUpdateMessage();    PATCH_MEMBER(void, SendSyncGuildUpdateMessage, , 0x436170);
    void SendSyncGuildCloseMessage();    PATCH_MEMBER(void, SendSyncGuildCloseMessage, , 0x436280);
    void SendSyncMemberJoinMessage(char *);    PATCH_MEMBER(void, SendSyncMemberJoinMessage, char *, 0x436320);
    void SendSyncMemberUpdateMessage(char *, unsigned char);    PATCH_MEMBER(void, SendSyncMemberUpdateMessage, char * _COMMA unsigned char, 0x4363D0);
    void SendSyncMemberQuitMessage(char *);    PATCH_MEMBER(void, SendSyncMemberQuitMessage, char *, 0x436490);
    CNSGuild & operator=(const CNSGuild &);
    //virtual void * __vecDelDtor(unsigned int);

    struct _Invoke {
        PATCH_MEMBER_INVOKE(CNSGuild &, CNSGuild, Constructor, int _COMMA CNSGuild::GuildInfo &);
        PATCH_MEMBER_INVOKE(void, CNSGuild, Destructor, );
        //PATCH_MEMBER_INVOKE(void, CNSGuild, Clear, );
        //PATCH_MEMBER_INVOKE(int, CNSGuild, CloseGuild, CNSPc *);
        //PATCH_MEMBER_INVOKE(int, CNSGuild, IsFull, );
        //PATCH_MEMBER_INVOKE(int, CNSGuild, IsFullSubMaster, );
        //PATCH_MEMBER_INVOKE(int, CNSGuild, IsMaster, char *);
        //PATCH_MEMBER_INVOKE(int, CNSGuild, IsSubMaster, char *);
        //PATCH_MEMBER_INVOKE(int, CNSGuild, IsFullMember, char *);
        //PATCH_MEMBER_INVOKE(int, CNSGuild, IsNormalMember, char *);
        //PATCH_MEMBER_INVOKE(int, CNSGuild, IsMember, char *);
        //PATCH_MEMBER_INVOKE(int, CNSGuild, GetMemberRank, char *);
        //PATCH_MEMBER_INVOKE(unsigned char, CNSGuild, GetRealm, );
        //PATCH_MEMBER_INVOKE(unsigned long, CNSGuild, GetCount, );
        //PATCH_MEMBER_INVOKE(void, CNSGuild, SetGuildInfo, char * _COMMA char * _COMMA unsigned char _COMMA char * _COMMA unsigned long);
        //PATCH_MEMBER_INVOKE(int, CNSGuild, GetGuildSeq, );
        //PATCH_MEMBER_INVOKE(unsigned char, CNSGuild, GetGuildLevel, );
        //PATCH_MEMBER_INVOKE(char *, CNSGuild, GetGuildName, );
        //PATCH_MEMBER_INVOKE(unsigned long, CNSGuild, GetGuildRank, );
        //PATCH_MEMBER_INVOKE(unsigned long, CNSGuild, GetGuildMark, );
        //PATCH_MEMBER_INVOKE(unsigned long, CNSGuild, GetGuildRankMonth, );
        //PATCH_MEMBER_INVOKE(int, CNSGuild, Add, CNSPc * _COMMA unsigned char);
        //PATCH_MEMBER_INVOKE(int, CNSGuild, Add, int _COMMA char * _COMMA unsigned char);
        //PATCH_MEMBER_INVOKE(int, CNSGuild, Update, char * _COMMA unsigned char);
        //PATCH_MEMBER_INVOKE(int, CNSGuild, Delete, char *);
        //PATCH_MEMBER_INVOKE(CNSGuild::GuildMember *, CNSGuild, Find, int);
        //PATCH_MEMBER_INVOKE(CNSGuild::GuildMember *, CNSGuild, Find, char *);
        //PATCH_MEMBER_INVOKE(void, CNSGuild, JoinMaster, CNSPc *);
        //PATCH_MEMBER_INVOKE(int, CNSGuild, Join, CNSPc * _COMMA CNSPc *);
        //PATCH_MEMBER_INVOKE(int, CNSGuild, Quit, char *);
        //PATCH_MEMBER_INVOKE(void, CNSGuild, LoginAll, );
        //PATCH_MEMBER_INVOKE(int, CNSGuild, Login, CNSPc *);
        //PATCH_MEMBER_INVOKE(int, CNSGuild, Logout, unsigned long);
        //PATCH_MEMBER_INVOKE(int, CNSGuild, AddPoint, int);
        //PATCH_MEMBER_INVOKE(int, CNSGuild, GivePoint, int);
        //PATCH_MEMBER_INVOKE(int, CNSGuild, GetPoint, );
        //PATCH_MEMBER_INVOKE(void, CNSGuild, Broadcast, CPacket &);
        //PATCH_MEMBER_INVOKE(unsigned long, CNSGuild, PacketInfo, CPacket &);
        //PATCH_MEMBER_INVOKE(void, CNSGuild, SendMemo, CNSPc * _COMMA char *);
        //PATCH_MEMBER_INVOKE(int, CNSGuild, ChangeGuildName, CNSPc * _COMMA char *);
        //PATCH_MEMBER_INVOKE(int, CNSGuild, ChangeLevel, unsigned char);
        //PATCH_MEMBER_INVOKE(int, CNSGuild, ChangeMark, unsigned long);
        //PATCH_MEMBER_INVOKE(int, CNSGuild, ChangeComment, CNSPc * _COMMA char *);
        //PATCH_MEMBER_INVOKE(int, CNSGuild, ChangeMaster, CNSPc * _COMMA char *);
        //PATCH_MEMBER_INVOKE(int, CNSGuild, ChangeMemberRank, CNSPc * _COMMA char * _COMMA unsigned char);
        //PATCH_MEMBER_INVOKE(int, CNSGuild, ChangeUserAlias, char * _COMMA char *);
       // PATCH_STATIC_INVOKE(unsigned long, DBGuildList, unsigned char _COMMA unsigned long _COMMA int _COMMA CPacket &);
        //PATCH_STATIC_INVOKE(int, DBInsert, int _COMMA unsigned char _COMMA char * _COMMA char * _COMMA int &);
        //PATCH_MEMBER_INVOKE(int, CNSGuild, DBUpdate, );
        //PATCH_MEMBER_INVOKE(int, CNSGuild, DBPointUpdate, );
        //PATCH_MEMBER_INVOKE(int, CNSGuild, DBMarkUpdate, );
        //PATCH_MEMBER_INVOKE(int, CNSGuild, DBDelete, );
        //PATCH_MEMBER_INVOKE(unsigned short, CNSGuild, DBGetMemberLevel, );
        //PATCH_MEMBER_INVOKE(int, CNSGuild, DBLog, char _COMMA char * _COMMA int _COMMA int _COMMA int _COMMA int);
        //PATCH_MEMBER_INVOKE(unsigned long, CNSGuild, DBLogPrint, CNSPc * _COMMA CNSGuild::GUILDLOG _COMMA unsigned long);
        //PATCH_MEMBER_INVOKE(int, CNSGuild, DBPremiumItemAdd, unsigned short);
        //PATCH_MEMBER_INVOKE(int, CNSGuild, DBPremiumItemGetDays, unsigned short);
        //PATCH_STATIC_INVOKE(int, DBGetGuildRankMonthName, unsigned char _COMMA int _COMMA char * _COMMA int);
        //PATCH_MEMBER_INVOKE(void, CNSGuild, OnActiveCheck, char * _COMMA char * _COMMA char *);
        //PATCH_MEMBER_INVOKE(void, CNSGuild, DebugMemberPrint, CNSPc *);
        //PATCH_MEMBER_INVOKE(int, CNSGuild, DBMemberInsert, int _COMMA unsigned char);
        //PATCH_MEMBER_INVOKE(int, CNSGuild, DBMemberUpdate, char * _COMMA unsigned char);
        //PATCH_MEMBER_INVOKE(int, CNSGuild, DBMemberUpdate, int _COMMA unsigned char);
        //PATCH_MEMBER_INVOKE(int, CNSGuild, DBMemberDelete, char *);
        //PATCH_MEMBER_INVOKE(int, CNSGuild, DBMemberDelete, int);
        //PATCH_MEMBER_INVOKE(int, CNSGuild, DBMemberRefresh, );
        //PATCH_MEMBER_INVOKE(void, CNSGuild, SendSyncGuildUpdateMessage, );
        //PATCH_MEMBER_INVOKE(void, CNSGuild, SendSyncGuildCloseMessage, );
        //PATCH_MEMBER_INVOKE(void, CNSGuild, SendSyncMemberJoinMessage, char *);
        //PATCH_MEMBER_INVOKE(void, CNSGuild, SendSyncMemberUpdateMessage, char * _COMMA unsigned char);
        //PATCH_MEMBER_INVOKE(void, CNSGuild, SendSyncMemberQuitMessage, char *);
    };
};
#ifdef DEFINE_NS_CPP
DEFINE_NAKED_JMP(CNSGuild& CNSGuild::Constructor(int _COMMA CNSGuild::GuildInfo &), 0x431E60);
//DEFINE_NAKED_JMP(CNSGuild::Destructor(), 0x431FE0);
DEFINE_NAKED_JMP(void CNSGuild::Clear(), 0x436600);
//DEFINE_NAKED_JMP(int CNSGuild::CloseGuild(CNSPc *), 0x432CF0);
//DEFINE_NAKED_JMP(int CNSGuild::IsFull(), 0x4365C0);
//DEFINE_NAKED_JMP(int CNSGuild::IsFullSubMaster(), 0x432280);
//DEFINE_NAKED_JMP(int CNSGuild::IsMaster(char *), 0x436570);
//DEFINE_NAKED_JMP(int CNSGuild::IsSubMaster(char *), 0x432580);
//DEFINE_NAKED_JMP(int CNSGuild::IsFullMember(char *), 0x4324A0);
//DEFINE_NAKED_JMP(int CNSGuild::IsNormalMember(char *), 0x4323C0);
//DEFINE_NAKED_JMP(int CNSGuild::IsMember(char *), 0x4321B0);
//DEFINE_NAKED_JMP(int CNSGuild::GetMemberRank(char *), 0x4320D0);
//DEFINE_NAKED_JMP(unsigned char CNSGuild::GetRealm(), 0x45C500);
//DEFINE_NAKED_JMP(unsigned long CNSGuild::GetCount(), 0x4B08F0);
//DEFINE_NAKED_JMP(void CNSGuild::SetGuildInfo(char * _COMMA char * _COMMA unsigned char _COMMA char * _COMMA unsigned long), 0x432060);
//DEFINE_NAKED_JMP(int CNSGuild::GetGuildSeq(), 0x48FAB0);
//DEFINE_NAKED_JMP(unsigned char CNSGuild::GetGuildLevel(), 0x4B08D0);
//DEFINE_NAKED_JMP(char * CNSGuild::GetGuildName(), 0x45C520);
//DEFINE_NAKED_JMP(unsigned long CNSGuild::GetGuildRank(), 0x45C540);
//DEFINE_NAKED_JMP(unsigned long CNSGuild::GetGuildMark(), 0x4828E0);
//DEFINE_NAKED_JMP(unsigned long CNSGuild::GetGuildRankMonth(), 0x4B0950);
DEFINE_NAKED_JMP(int CNSGuild::Add(CNSPc * _COMMA unsigned char), 0x433130);
DEFINE_NAKED_JMP(int CNSGuild::Add(int _COMMA char * _COMMA unsigned char), 0x436650);
//DEFINE_NAKED_JMP(int CNSGuild::Update(char * _COMMA unsigned char), 0x433240);
//DEFINE_NAKED_JMP(int CNSGuild::Delete(char *), 0x4332B0);
//DEFINE_NAKED_JMP(CNSGuild::GuildMember * CNSGuild::Find(int), 0x4326D0);
//DEFINE_NAKED_JMP(CNSGuild::GuildMember * CNSGuild::Find(char *), 0x432660);
//DEFINE_NAKED_JMP(void CNSGuild::JoinMaster(CNSPc *), 0x4333E0);
//DEFINE_NAKED_JMP(int CNSGuild::Join(CNSPc * _COMMA CNSPc *), 0x433460);
//DEFINE_NAKED_JMP(int CNSGuild::Quit(char *), 0x4335E0);
DEFINE_NAKED_JMP(void CNSGuild::LoginAll(), 0x4336E0);
DEFINE_NAKED_JMP(int CNSGuild::Login(CNSPc *), 0x4337C0);
//DEFINE_NAKED_JMP(int CNSGuild::Logout(unsigned long), 0x4338B0);
//DEFINE_NAKED_JMP(int CNSGuild::AddPoint(int), 0x483F80);
//DEFINE_NAKED_JMP(int CNSGuild::GivePoint(int), 0x4B0910);
//DEFINE_NAKED_JMP(int CNSGuild::GetPoint(), 0x45C560);
//DEFINE_NAKED_JMP(void CNSGuild::Broadcast(CPacket &), 0x433980);
DEFINE_NAKED_JMP(unsigned long CNSGuild::PacketInfo(CPacket &), 0x432E50);
//DEFINE_NAKED_JMP(void CNSGuild::SendMemo(CNSPc * _COMMA char *), 0x433AA0);
//DEFINE_NAKED_JMP(int CNSGuild::ChangeGuildName(CNSPc * _COMMA char *), 0x4327A0);
//DEFINE_NAKED_JMP(int CNSGuild::ChangeLevel(unsigned char), 0x432880);
//DEFINE_NAKED_JMP(int CNSGuild::ChangeMark(unsigned long), 0x4328B0);
//DEFINE_NAKED_JMP(int CNSGuild::ChangeComment(CNSPc * _COMMA char *), 0x4328E0);
//DEFINE_NAKED_JMP(int CNSGuild::ChangeMaster(CNSPc * _COMMA char *), 0x432A90);
//DEFINE_NAKED_JMP(int CNSGuild::ChangeMemberRank(CNSPc * _COMMA char * _COMMA unsigned char), 0x432950);
DEFINE_NAKED_JMP(int CNSGuild::ChangeUserAlias(char * _COMMA char *), 0x432730);
//DEFINE_NAKED_JMP(unsigned long CNSGuild::DBGuildList(unsigned char _COMMA unsigned long _COMMA int _COMMA CPacket &), 0x434E80);
//DEFINE_NAKED_JMP(int CNSGuild::DBInsert(int _COMMA unsigned char _COMMA char * _COMMA char * _COMMA int &), 0x433CC0);
//DEFINE_NAKED_JMP(int CNSGuild::DBUpdate(), 0x433DF0);
//DEFINE_NAKED_JMP(int CNSGuild::DBPointUpdate(), 0x433F30);
//DEFINE_NAKED_JMP(int CNSGuild::DBMarkUpdate(), 0x434050);
//DEFINE_NAKED_JMP(int CNSGuild::DBDelete(), 0x434170);
//DEFINE_NAKED_JMP(unsigned short CNSGuild::DBGetMemberLevel(), 0x435200);
//DEFINE_NAKED_JMP(int CNSGuild::DBLog(char _COMMA char * _COMMA int _COMMA int _COMMA int _COMMA int), 0x435560);
//DEFINE_NAKED_JMP(unsigned long CNSGuild::DBLogPrint(CNSPc * _COMMA CNSGuild::GUILDLOG _COMMA unsigned long), 0x4356A0);
//DEFINE_NAKED_JMP(int CNSGuild::DBPremiumItemAdd(unsigned short), 0x435CB0);
//DEFINE_NAKED_JMP(int CNSGuild::DBPremiumItemGetDays(unsigned short), 0x435EB0);
//DEFINE_NAKED_JMP(int CNSGuild::DBGetGuildRankMonthName(unsigned char _COMMA int _COMMA char * _COMMA int), 0x4353B0);
//DEFINE_NAKED_JMP(void CNSGuild::OnActiveCheck(char * _COMMA char * _COMMA char *), 0x433B70);
//DEFINE_NAKED_JMP(void CNSGuild::DebugMemberPrint(CNSPc *), 0x436090);
//DEFINE_NAKED_JMP(int CNSGuild::DBMemberInsert(int _COMMA unsigned char), 0x434290);
//DEFINE_NAKED_JMP(int CNSGuild::DBMemberUpdate(char * _COMMA unsigned char), 0x4344E0);
//DEFINE_NAKED_JMP(int CNSGuild::DBMemberUpdate(int _COMMA unsigned char), 0x4343C0);
//DEFINE_NAKED_JMP(int CNSGuild::DBMemberDelete(char *), 0x434720);
//DEFINE_NAKED_JMP(int CNSGuild::DBMemberDelete(int), 0x434600);
//DEFINE_NAKED_JMP(int CNSGuild::DBMemberRefresh(), 0x434840);
//DEFINE_NAKED_JMP(void CNSGuild::SendSyncGuildUpdateMessage(), 0x436170);
//DEFINE_NAKED_JMP(void CNSGuild::SendSyncGuildCloseMessage(), 0x436280);
//DEFINE_NAKED_JMP(void CNSGuild::SendSyncMemberJoinMessage(char *), 0x436320);
//DEFINE_NAKED_JMP(void CNSGuild::SendSyncMemberUpdateMessage(char * _COMMA unsigned char), 0x4363D0);
//DEFINE_NAKED_JMP(void CNSGuild::SendSyncMemberQuitMessage(char *), 0x436490);
#endif




#endif