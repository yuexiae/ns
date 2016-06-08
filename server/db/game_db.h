#ifndef SERVER_DB_GAME_DB_H_
#define SERVER_DB_GAME_DB_H_

#include "base/singleton.h"
#include "server/db/memory_db.h"
#include "server/ext/ns_ext.h"
#include "msgpack.hpp"

namespace redis {
class Reply;
}

class GameDb : public MemoryDb, public base::Singleton<GameDb> {
public:
	bool ScriptHashInit();

    BOOL DBChangeJob(CNSPcExt *pc, unsigned char btJob);
	int DBLoad(CNSPcExt *pc);
    BOOL DBAliasRename(CNSPcExt *pc, char *szNewAlias);
	BOOL DBAliasMake(CNSPcExt *pc, char *szUserAlias, unsigned char btRace, unsigned char btJob, unsigned char btBody);
	BOOL DBAliasCount(CNSPcExt *pc, int &nCount, unsigned char &btRaceRegion);
	unsigned long DBAliasList(CNSPcExt *pc, CPacket &packet);
    int DBAliasDelete(CNSPcExt *pc, char *szUserAlias);
	BOOL DBPcSave(CNSPcExt *pc);
    BOOL DBRaceUpdate(CNSPcExt *pc);
    BOOL DBGoldUpdate(CNSPcExt *pc);
    BOOL DBBindPosUpdate(CNSPcExt *pc);
	BOOL DBItemInsert(CNSPcExt *pc, CNSItemExt *pItem, int nAliasSeq);
    BOOL DBItemUpdate(CNSPcExt *pc, CNSItemExt *pItem);
    BOOL DBItemUpdatePosCount(CNSPcExt *pc, CNSItemExt *pItem);
    BOOL DBItemUpdateAllPosCount(CNSPcExt *pc);
    BOOL DBItemDelete(CNSPcExt *pc, int nItemSeq);
    BOOL DBSkillLoad(CNSPcExt *pc);
	BOOL DBSkillInsert(CNSPcExt *pc, CNSSkill *pSkill);
    BOOL DBSkillUpdate(CNSPcExt *pc, CNSSkill *pSkill);
	BOOL DBQuestInsert(CNSPcExt *pc, unsigned short wQuestId, CNSQuest *pQuest);
    BOOL DBQuestUpdate(CNSPcExt *pc, CNSQuest *pQuest);
    BOOL DBQuestDelete(CNSPcExt *pc, unsigned short wQuestId);
    BOOL DBTeleportUpdate(CNSPcExt *pc, CNSPcTeleportList::Teleport *teleport);
    BOOL DBFriendInsert(CNSPcExt *pc, char *szUserAlias, int &nDbSeq);
    BOOL DBFriendDelete(CNSPcExt *pc, int nDbSeq);
    BOOL DbTitleAdd(CNSPcExt *pc, unsigned short wTitleId); 
    unsigned long DBPremiumShopLimitCount(unsigned char btCategory, unsigned char btSeq);
    BOOL DBPremiumShopLimitIncCount(unsigned char btCategory, unsigned char btSeq);

   
	void DBFortressSave(CNSWorldManager *pWorldManager);
	BOOL DBFortressLoad(CNSWorldManager *pWorldManager);

	void DBBlockSave(CNSNpcManager *pNpcManager);
	BOOL DBBlockLoad(CNSNpcManager *pNpcManager);

    BOOL DBWareHouseGoldLoad(int nUserSeq, unsigned char btRegion, unsigned long& dwOutGold);
    BOOL DBWareHouseGoldIncrment(int nUserSeq, unsigned int dwGold);
    BOOL DBWareHouseGoldDecrease(int nUserSeq, unsigned int dwGold);
    BOOL DBWareItemLoad(CNSWareHouse *pWareHous);
    BOOL DBWareItemIn(CNSItem *pItem, int nUserSeq, int nAliasSeq);
    BOOL DBWareItemOut(CNSItem *pItem, int nUserSeq, int nAliasSeq);

    CNSGuild* DBGuildLoad(int nDbSeq);
    BOOL DBGuildInsert(int nAliasSeq, unsigned char btRealm, char *szGuildName, char *szComment, int& nOutDbSeq);
    BOOL DBGuildDelete(CNSGuild *pGuild);
    BOOL DBGuildUpdate(CNSGuild *pGuild);
    BOOL DBGuildPointUpdate(CNSGuild *pGuild);
    BOOL DBGuildRefresh(CNSGuild *pGuild);
    BOOL DBGuildRankLoad(unsigned char realm, std::vector<int>& list);
    BOOL DBMemberInsert(CNSGuild *pGuild, int nAliasSeq, unsigned char btRank);
    BOOL DBMemberUpdate(CNSGuild *pGuild, char *szUserAlias, unsigned char btRank);
    BOOL DBMemberUpdate(CNSGuild *pGuild, int nAliasSeq, unsigned char btRank);
    BOOL DBMemberDelete(CNSGuild *pGuild, char *szUserAlias);
    BOOL DBMemberDelete(CNSGuild *pGuild, int nAliasSeq);
    BOOL DBGuildMemberLoad(CNSGuild *pGuild);
    unsigned short DBGuildMemberLevel(CNSGuild *pGuild);

private:
    bool LoadSkill(CNSPcExt *pc, redis::Reply &result);
    bool LoadPet(CNSPcExt *pc, redis::Reply &result);
    bool LoadSkillBuffArray(CNSPcExt *pc, redis::Reply &result);
    bool LoadTeleport(CNSPcExt *pc, redis::Reply &result);
    bool LoadItem(CNSPcExt *pc, redis::Reply &result);
    bool LoadQuest(CNSPcExt *pc, redis::Reply &result);
    bool LoadFriend(CNSPcExt *pc, redis::Reply &result);
    bool LoadTitle(CNSPcExt *pc, redis::Reply &result);
    bool LoadTameMob(CNSPcExt *pc, redis::Reply &result);
    void PackPet(CNSPcExt *pc, msgpack::sbuffer& buffer);
    void PackSkillBuffArray(CNSPcExt *pc, msgpack::sbuffer& buffer);
    void PackTameMob(CNSPcExt *pc, msgpack::sbuffer& buffer);

    std::string script_alias_rename_;
	std::string script_alias_load_;
	std::string script_alias_make_;
	std::string script_alias_count_;
	std::string script_alias_list_;
    std::string script_alias_delete_;
	std::string script_item_insert_;
    std::string script_item_update_;
    std::string script_item_update_pos_count_;
    std::string script_item_delete_;
    std::string script_friend_insert_;
    std::string script_ware_gold_load_;
	std::string script_ware_item_in_;
    std::string script_ware_item_out_;
    std::string script_ware_item_load_;
    std::string script_guild_load_;
    std::string script_guild_delete_;
    std::string script_guild_insert_;
    std::string script_guild_update_;
    std::string script_guild_member_insert_;
    std::string script_guild_member_update_;
    std::string script_guild_member_delete_;
    std::string script_guild_member_load_;
    std::string script_guild_member_level_;
    std::string script_guild_rank_load_;
};






#endif