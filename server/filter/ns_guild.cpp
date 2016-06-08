#include "server/server_pch.h"

#include "server/ext/ns_ext.h"
#include "server/db/game_db.h"
#include "server/db/log_db.h"

class CNSGuildFilter : public CNSGuildExt {
public:
    static CNSGuild::_Invoke invoke_;
    
    CNSGuild& ConstructorFilter(int nDbSeq, CNSGuild::GuildInfo &guildInfo) {
        (this->*invoke_.Constructor)(nDbSeq, guildInfo);
        this->CNSGuildExtImpl::CNSGuildExtImpl();
        return *this;
    }

    void DestructorFilter() {
        this->CNSGuildExtImpl::~CNSGuildExtImpl();
        (this->*invoke_.Destructor)();
    }

    static unsigned long DBGuildListFilter(unsigned char, unsigned long, int, CPacket &) {
        return 0;
    }

    static BOOL DBInsertFilter(int nAliasSeq, unsigned char btRealm, char *szGuildName, char *szComment, int& nOutDbSeq) {
        return GameDb::GetSingleton()->DBGuildInsert(nAliasSeq, btRealm, szGuildName, szComment, nOutDbSeq);
    }

    BOOL DBUpdateFilter() {
        return GameDb::GetSingleton()->DBGuildUpdate(this);
    }

    BOOL DBPointUpdateFilter() {
        return GameDb::GetSingleton()->DBGuildPointUpdate(this);
    }

    BOOL DBMarkUpdateFilter() {
        DebugBreak();
        return TRUE;
    }

    BOOL DBDeleteFilter() {
        return GameDb::GetSingleton()->DBGuildDelete(this);
    }

    unsigned short DBGetMemberLevelFilter() {
        return GameDb::GetSingleton()->DBGuildMemberLevel(this);
    }

    int DBLogFilter(char cMode, char *szAction, int nAliasSeq, int nOptionValue1, int nOptionValue2, int nOptionValue3) {
        return LogDb::GetSingleton()->DBGuildLog(this->m_nDbSeq, cMode, szAction, nAliasSeq, nOptionValue1, nOptionValue2, nOptionValue3);
    }

    unsigned long DBLogPrintFilter(CNSPc *, CNSGuild::GUILDLOG, unsigned long);
    int DBPremiumItemAddFilter(unsigned short);
    int DBPremiumItemGetDaysFilter(unsigned short);
    static int DBGetGuildRankMonthNameFilter(unsigned char, int, char *, int);

    BOOL DBMemberInsertFilter(int nAliasSeq, unsigned char btRank) {
        return GameDb::GetSingleton()->DBMemberInsert(this, nAliasSeq, btRank);
    }

    BOOL DBMemberUpdateFilter(char *szUserAlias, unsigned char btRank) {
        return GameDb::GetSingleton()->DBMemberUpdate(this, szUserAlias, btRank);
    }

    BOOL DBMemberUpdateFilter2(int nAliasSeq, unsigned char btRank) {
        return GameDb::GetSingleton()->DBMemberUpdate(this, nAliasSeq, btRank);
    }

    BOOL DBMemberDeleteFilter(char *szUserAlias) {
        return GameDb::GetSingleton()->DBMemberDelete(this, szUserAlias);
    }

    BOOL DBMemberDeleteFilter2(int nAliasSeq) {
        return GameDb::GetSingleton()->DBMemberDelete(this, nAliasSeq);
    }

    BOOL DBMemberRefreshFilter() {
        return GameDb::GetSingleton()->DBGuildRefresh(this)
            && GameDb::GetSingleton()->DBGuildMemberLoad(this);
    }
};

CNSGuild::_Invoke CNSGuildFilter::invoke_;

bool CNSGuildFilterInit() {
    base::HookUtil::PatchULong(0x0046EE5F + 1, sizeof(CNSGuildExt));
    base::HookUtil::PatchULong(0x0048F77D + 1, sizeof(CNSGuildExt));

    GameUtil::Output("modify cnsguild operator new size:0x%04x", sizeof(CNSGuildExt));

    return CNSGuild::_PatchConstructor(&CNSGuildFilter::ConstructorFilter, &CNSGuildFilter::invoke_.Constructor)
        && CNSGuild::_PatchDestructor(&CNSGuildFilter::DestructorFilter, &CNSGuildFilter::invoke_.Destructor)
        && CNSGuild::_PatchDBGuildList(&CNSGuildFilter::DBGuildListFilter)
        && CNSGuild::_PatchDBInsert(&CNSGuildFilter::DBInsertFilter)
        && CNSGuild::_PatchDBUpdate(&CNSGuildFilter::DBUpdateFilter)
        && CNSGuild::_PatchDBPointUpdate(&CNSGuildFilter::DBPointUpdateFilter)
        && CNSGuild::_PatchDBMarkUpdate(&CNSGuildFilter::DBMarkUpdateFilter)
        && CNSGuild::_PatchDBDelete(&CNSGuildFilter::DBDeleteFilter)
        && CNSGuild::_PatchDBLog(&CNSGuildFilter::DBLogFilter)
        && CNSGuild::_PatchDBGetMemberLevel(&CNSGuildFilter::DBGetMemberLevelFilter)
        && CNSGuild::_PatchDBMemberInsert(&CNSGuildFilter::DBMemberInsertFilter)
        && CNSGuild::_PatchDBMemberUpdate(&CNSGuildFilter::DBMemberUpdateFilter)
        && CNSGuild::_PatchDBMemberUpdate(&CNSGuildFilter::DBMemberUpdateFilter2)
        && CNSGuild::_PatchDBMemberDelete(&CNSGuildFilter::DBMemberDeleteFilter)
        && CNSGuild::_PatchDBMemberDelete(&CNSGuildFilter::DBMemberDeleteFilter2)
        && CNSGuild::_PatchDBMemberRefresh(&CNSGuildFilter::DBMemberRefreshFilter);
}