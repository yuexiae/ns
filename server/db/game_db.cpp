#include "server/server_pch.h"

#include "server/db/game_db.h"
#include "redis/redis.h"
#include "base/util.h"

bool GameDb::ScriptHashInit() {
    redis::Connector &conn = GetConnector();

    try {
        conn.script_load(".\\dbscript\\alias_rename.lua", script_alias_rename_);
        conn.script_load(".\\dbscript\\alias_load.lua", script_alias_load_);
        conn.script_load(".\\dbscript\\alias_make.lua", script_alias_make_);
        conn.script_load(".\\dbscript\\alias_count.lua", script_alias_count_);
        conn.script_load(".\\dbscript\\alias_list.lua", script_alias_list_);
        conn.script_load(".\\dbscript\\alias_delete.lua", script_alias_delete_);
        conn.script_load(".\\dbscript\\item_insert.lua", script_item_insert_);
        conn.script_load(".\\dbscript\\item_delete.lua", script_item_delete_);
        conn.script_load(".\\dbscript\\item_update_pos_count.lua", script_item_update_pos_count_);
        conn.script_load(".\\dbscript\\friend_insert.lua", script_friend_insert_);
        conn.script_load(".\\dbscript\\ware_gold_load.lua", script_ware_gold_load_);
        conn.script_load(".\\dbscript\\ware_item_in.lua", script_ware_item_in_);
        conn.script_load(".\\dbscript\\ware_item_out.lua", script_ware_item_out_);
        conn.script_load(".\\dbscript\\ware_item_load.lua", script_ware_item_load_);
        conn.script_load(".\\dbscript\\guild_load.lua", script_guild_load_);
        conn.script_load(".\\dbscript\\guild_delete.lua", script_guild_delete_);
        conn.script_load(".\\dbscript\\guild_insert.lua", script_guild_insert_);
        conn.script_load(".\\dbscript\\guild_update.lua", script_guild_update_);
        conn.script_load(".\\dbscript\\guild_member_insert.lua", script_guild_member_insert_);
        conn.script_load(".\\dbscript\\guild_member_update.lua", script_guild_member_update_);
        conn.script_load(".\\dbscript\\guild_member_delete.lua", script_guild_member_delete_);
        conn.script_load(".\\dbscript\\guild_member_load.lua", script_guild_member_load_);
        conn.script_load(".\\dbscript\\guild_member_level.lua", script_guild_member_level_);
        conn.script_load(".\\dbscript\\guild_rank_load.lua", script_guild_rank_load_);

    } catch (redis::Exception &ex) {
        LOGERROR("'%s' ", ex.what());
        return false;
    }

    return true;
}

BOOL GameDb::DBChangeJob(CNSPcExt *pc, unsigned char btJob) {
    redis::Connector &conn = GetConnector();
    try {
        CNSPcParams::_Status *pc_params = CNSPcParams::GetInstance()->GetStatus(pc->m_btRace, btJob, pc->m_btLevel);
        if (pc_params == NULL) {
            LOGERROR("CNSPcParams::GetInstance()->GetStatus(%d,%d,%d) failed(%d)", pc->m_btRace, btJob, pc->m_btLevel, pc->m_nAliasSeq);
            return FALSE;
        }

        conn.hset(redis::UniqueKey("UserAliasList", pc->m_nAliasSeq), "Job", btJob);

        pc->m_btJob = btJob;

        if (!pc->m_SkillList.DBSkillListBuild(pc->m_btRaceRegion, btJob)) {
            LOGERROR("DBSkillListBuild failed(%d)", pc->m_nAliasSeq);
            return FALSE;
        }

        pc->DBSkillLoad();

        pc->m_BasicParam.btStr = pc_params->btStr;
        pc->m_BasicParam.btCon = pc_params->btCon;
        pc->m_BasicParam.btDex = pc_params->btDex;
        pc->m_BasicParam.btInt = pc_params->btInt;
        pc->Reset(1);

        CPacket packet(0x2269u);
        packet.WriteULong(pc->m_dwObjectId);
        packet.WriteUChar(pc->m_btJob);
        packet.WriteUShort(pc->m_BasicParam.btStr);
        packet.WriteUShort(pc->m_BasicParam.btCon);
        packet.WriteUShort(pc->m_BasicParam.btDex);
        packet.WriteUShort(pc->m_BasicParam.btInt);

        pc->Broadcast(packet, 0, 0x258u);
        pc->SendStatusMessage(1);
        pc->SendSkillListMessage();

        return TRUE;
    } catch (redis::Exception &ex) {
        LOGERROR("'%s' seq:'%d'", ex.what(), pc->m_nAliasSeq);
    }

    return FALSE;
}

int GameDb::DBLoad(CNSPcExt *pc) {
    redis::Connector &conn = GetConnector();

    CNSWorldManager *world_manager = CNSWorldManager::GetInstance();
    NSPOINT2 db_cell(0, 0);

    try {
        base::CalcHighTimeRange calc_time("DBLoad");

        redis::Reply reply = conn.evalsha(script_alias_load_,
            pc->m_szUserAlias,
            pc->m_szUserId,
            pc->m_nUserSeq,
            world_manager->m_btRegion,
            world_manager->IsMainServer(pc->m_btRaceRegion) ? 1 : 0);

        redis::Reply& reply_pc = reply[0];
        pc->m_nAliasSeq = reply_pc[3].convert<int32_t>();
        pc->m_btRace = reply_pc[4].convert<uint8_t>();
        pc->m_btJob = reply_pc[5].convert<uint8_t>();
        pc->m_btBody = reply_pc[6].convert<uint8_t>();
        pc->m_btRank = reply_pc[7].convert<uint8_t>();
        pc->m_btLevel = reply_pc[8].convert<uint8_t>();
        pc->m_dwExp = reply_pc[9].convert<uint32_t>();
        pc->m_btSp = reply_pc[10].convert<uint8_t>();
        pc->m_dwSkillExp = reply_pc[11].convert<uint32_t>();
        pc->m_dwGold = reply_pc[12].convert<uint32_t>();
        pc->m_dwRealmPoint = reply_pc[13].convert<uint32_t>();
        pc->m_dwLastDeadExp = reply_pc[14].convert<uint32_t>();
        pc->m_wNs = reply_pc[15].convert<uint16_t>();
        pc->m_wNsCharge = reply_pc[16].convert<uint16_t>();
        pc->m_fHp = reply_pc[17].convert<uint16_t>();
        pc->m_fSta = reply_pc[18].convert<uint16_t>();
        pc->m_fMp = reply_pc[19].convert<uint16_t>();
        pc->m_wTitleId = reply_pc[20].convert<uint16_t>();
        pc->m_btRegion = reply_pc[21].convert<uint8_t>();
        pc->m_cell.x = reply_pc[22].convert<uint16_t>();
        pc->m_cell.y = reply_pc[23].convert<uint16_t>();
        pc->m_btBindRegion = reply_pc[24].convert<uint8_t>();
        pc->m_cellBind.x = reply_pc[25].convert<uint16_t>();
        pc->m_cellBind.y = reply_pc[26].convert<uint16_t>();
        pc->m_btTransRegion = reply_pc[27].convert<uint8_t>();
        pc->m_cellTrans.x = reply_pc[28].convert<uint16_t>();
        pc->m_cellTrans.y = reply_pc[29].convert<uint16_t>();
        pc->m_wLogSp = reply_pc[30].convert<uint16_t>();

        pc->LevelSetup();

        if (CNSPc::ConvertRaceToRegion(pc->m_btRace) != pc->m_btRaceRegion) {
            LOGERROR("ConvertRaceToRegion error:%d,%d", pc->m_btRace, pc->m_btRaceRegion);
            return 0;
        }

        pc->m_btRealm = pc->m_btRaceRegion;
        

        if (pc->CheckDoubleConnect(pc->m_szUserId)) {
            return 0;
        }

        if (!pc->DBMainLastServerSave(pc->m_szUserId)) {
            return 0;
        }

        pc->DBLoginLog();
        
        pc->m_dwGuildId = 0;
        int guild_seq = reply_pc[31].convert<int32_t>();
        if (guild_seq > 0) {
            CNSObject::Owner<CNSGuild> guild = CNSPcManager::GetInstance()->GuildFind(guild_seq);
            if (guild) {
                pc->m_dwGuildId = guild->m_dwObjectId;
                guild->Login(pc);
            } else {
                CNSGuild *load_guild = DBGuildLoad(guild_seq);
                if (load_guild) {
                    pc->m_dwGuildId = load_guild->m_dwObjectId;
                    load_guild->Login(pc);
                }
            }
        }

        LoadFriend(pc, reply[1]);

        if (reply.Count() == 2) {
            pc->OnMoveServer(pc->m_btRegion, pc->m_cell);
            pc->Login();
            return 2;
        }

        //quick bar load
        memset(pc->m_dwQuickBarArray, 0, sizeof(pc->m_dwQuickBarArray));
        reply_pc[32].assgin_raw_eq(pc->m_dwQuickBarArray, sizeof(pc->m_dwQuickBarArray));

        //pet load
        if (!LoadPet(pc, reply_pc[33])) {
            LOGERROR("load pet error AliasSeq:'%d'", pc->m_nAliasSeq);
            return 0;
        }

        pc->m_SkillList.Clear();
        if (!LoadSkill(pc, reply[2]) || !pc->m_SkillList.SkillPointSetup()) {
            return 0;
        }

        //pc->RestoreSummonState();
        if (!LoadSkillBuffArray(pc, reply_pc[34])) {
            LOGERROR("load buff skill array error:%d", pc->m_nAliasSeq);//after this->SkillLoad(pc)
            return 0;
        }

        if (!LoadTeleport(pc, reply_pc[35])) {
            LOGERROR("load teleport array error:%d", pc->m_nAliasSeq);
            return 0;
        }

        if (!LoadTeleport(pc, reply_pc[35])) {
            LOGERROR("load teleport array error:%d", pc->m_nAliasSeq);
            return 0;
        }

        reply_pc[36].assgin_sbuffer_stack<256>(pc->m_SummonState);

        if (!LoadTameMob(pc, reply_pc[37])) {
            LOGERROR("load tame mob array error:%d", pc->m_nAliasSeq);
            return 0;
        }

        if (!LoadItem(pc, reply[3])
            || !LoadQuest(pc, reply[4])
            || !LoadTitle(pc, reply[5]) ) {
                return 0;
        }


        pc->m_QuestList.CheckItemAll();

        //no load PremiumUseList

        pc->Reset(1);

        if (pc->m_btLevel == 1 && pc->m_dwExp == 0) {
            pc->m_fHp = (float)pc->m_dwMaxHp;
            pc->m_fSta = (float)pc->m_wMaxSta;
            pc->m_fMp = (float)pc->m_wMaxMp;
        }

        pc->m_cellNotStuck.y = 0;
        pc->m_cellNotStuck.x = 0;
        return 1;

    } catch (redis::Exception &ex) {
        LOGERROR("'%s' userid:%s,%s", ex.what(), pc->m_szUserId, pc->m_szUserAlias);
    }

    return 0;
}

BOOL GameDb::DBAliasRename(CNSPcExt *pc, char *szNewAlias) {
    redis::Connector &conn = GetConnector();
    try {
        if (conn.evalsha(script_alias_rename_, pc->m_nAliasSeq, pc->m_szUserAlias, szNewAlias).as<int32_t>() == 1) {
            return TRUE;
        } else {
            return FALSE;
        }
	} catch (redis::Exception &ex) {
		LOGERROR("'%s' (%d)", ex.what(), pc->m_nAliasSeq);
	}
	return FALSE;
}
BOOL GameDb::DBAliasMake(CNSPcExt *pc, char *szUserAlias, unsigned char btRace, unsigned char btJob, unsigned char btBody) {
    redis::Connector &conn = GetConnector();

    if (strlen(szUserAlias) > 24) {
        return FALSE;
    }

    NSPOINT2 start_cell;
    unsigned char start_region = 0;
    if (!pc->GetStartRegion(btRace, btJob, start_region, start_cell)) {
        return FALSE;
    }

    pc->SetDefaultQuickBar(CNSPc::ConvertRaceToRegion(btRace), btJob);

    try {
        base::CalcHighTimeRange calc_time1("DBAliasMake");

        conn.PushCommand("EVALSHA");
        conn.Push(script_alias_make_);
        conn.Push(0);
        conn.Push(szUserAlias);
        conn.Push(pc->m_nUserSeq);
        conn.Push(pc->m_szUserId);
        conn.Push(btRace);
        conn.Push(btJob);
        conn.Push(btBody);
        conn.Push(start_region);
        conn.Push(start_cell.x);
        conn.Push(start_cell.y);
        conn.Push(time(NULL));
        conn.PushRaw(pc->m_dwQuickBarArray, sizeof(pc->m_dwQuickBarArray));

        int result = conn.GetReply().as<int32_t>();
        if (result <= 0) {
            return FALSE;
        }

        pc->m_nAliasSeq = result;
        return TRUE;
    } catch (redis::Exception &ex) {
        LOGERROR("'%s' UserAlias:'%s',UserId:'%s'", ex.what(), szUserAlias, pc->m_szUserId);
        return FALSE;
    }

    return TRUE;
}


BOOL GameDb::DBAliasCount(CNSPcExt *pc, int &nCount, unsigned char &btRaceRegion) {
    redis::Connector &conn = GetConnector();

    btRaceRegion = 0;
    nCount = 0;
    try {
        btRaceRegion = CNSPc::ConvertRaceToRegion(conn.evalsha(script_alias_count_, pc->m_szUserId).as<uint8_t>());
        if (btRaceRegion > 0) {
            nCount = 1;
        }

        pc->m_btRaceRegion = btRaceRegion;
        return TRUE;
    } catch (redis::Exception &ex) {
        LOGERROR("'%s' userid:%s", ex.what(), pc->m_szUserId);
    }

    pc->m_pSession->CloseConnection();
    return FALSE;
}

unsigned long GameDb::DBAliasList(CNSPcExt *pc, CPacket &packet) {
    redis::Connector &conn = GetConnector();

    struct AliasData {
        int alias_seq;
        unsigned char flag;
        char useralias[25];
        unsigned char race;
        unsigned char job;
        unsigned char body;
        unsigned char level;
        unsigned char region;
        unsigned short pos_x;
        unsigned short pos_y;
        unsigned char trans_region;
        unsigned short trans_pos_x;
        unsigned short trans_pos_y;
        unsigned short equip_array[15];
    } data;

    int total_count = 0;
    unsigned char pre_race = 0;

    try {
        base::CalcHighTimeRange calc_time("DBAliasList");

        redis::Reply r = conn.evalsha(script_alias_list_, pc->m_szUserId);
        for (redis::Reply *iter = r.Begin(); iter != r.End(); ++iter) {

            memset(&data, 0, sizeof(AliasData));

            data.alias_seq = (*iter)[0].convert<int32_t>();
            data.flag = (*iter)[1].convert<uint8_t>();
            (*iter)[2].assgin(data.useralias, sizeof(data.useralias));
            data.race = (*iter)[3].convert<uint8_t>();
            data.job = (*iter)[4].convert<uint8_t>();
            data.body = (*iter)[5].convert<uint8_t>();
            data.level = (*iter)[6].convert<uint8_t>();
            data.region = (*iter)[7].convert<uint8_t>();
            data.pos_x = (*iter)[8].convert<uint16_t>();
            data.pos_y = (*iter)[9].convert<uint16_t>();
            data.trans_region = (*iter)[10].convert<uint8_t>();
            data.trans_pos_x = (*iter)[11].convert<uint16_t>();
            data.trans_pos_y = (*iter)[12].convert<uint16_t>();

            if (pre_race && CNSPc::ConvertRaceToRegion(pre_race) != CNSPc::ConvertRaceToRegion(data.race)) {
                continue;
            }
            pre_race = data.race;

            for (redis::Reply *item_iter = (*iter)[13].Begin(); item_iter != (*iter)[13].End(); ++item_iter) {
                unsigned long item_pos_id = item_iter->as<uint32_t>();

                switch (item_pos_id >> 16) {
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                    data.equip_array[(item_pos_id >> 16) - 1] = item_pos_id & 0x0000FFFF;
                    break;
                case 16:
                    data.equip_array[8] = item_pos_id & 0x0000FFFF;
                    break;
                case 17:
                    data.equip_array[9] = item_pos_id & 0x0000FFFF;
                    break;
                case 18:
                    data.equip_array[10] = item_pos_id & 0x0000FFFF;
                    break;
                case 19:
                    data.equip_array[1] = item_pos_id & 0x0000FFFF;
                    break;
                case 20:
                    data.equip_array[5] = item_pos_id & 0x0000FFFF;
                    break;
                default:
                    break;
                }

            }

            packet.WriteString(data.useralias);
            packet.WriteUChar(data.race);
            packet.WriteUChar(data.job);
            packet.WriteUChar(data.body);
            packet.WriteUChar(data.level);
            packet.WriteUShort(0);
            packet.WriteUShort(0);
            packet.WriteUShort(0);
            packet.WriteUShort(0);

            if (data.trans_region) {
                packet.WriteUChar(data.trans_region);
                packet.WriteUShort(data.trans_pos_x);
                packet.WriteUShort(data.trans_pos_y);
            } else {
                packet.WriteUChar(data.region);
                packet.WriteUShort(data.pos_x);
                packet.WriteUShort(data.pos_y);
            }

            for (int j = 0; j < 15; ++j) {
                packet.WriteUShort(data.equip_array[j]);
            }

            ++total_count; 
        }

    } catch (redis::Exception &ex) {
        LOGERROR("'%s' userid:%s", ex.what(), pc->m_szUserId);
        return false;
    }

    return total_count;
}
int GameDb::DBAliasDelete(CNSPcExt *pc, char *szUserAlias) {
    redis::Connector &conn = GetConnector();
	try {
        return conn.evalsha(script_alias_delete_, szUserAlias, pc->m_szUserId).as<int>();
	} catch (redis::Exception &ex) {
		LOGERROR("'%s' AliasDelete(%d)", ex.what(), pc->m_nAliasSeq);
	}
	return 0;
}
BOOL GameDb::DBPcSave(CNSPcExt *pc) {
    //UPDATE UserAliasList SET Job = %u, Level = %u, Exp = %u, Sp = %u, SkillExp = %u, Gold = %u,
    //RealmPoint = %u, LostExp = %u, Ns = %u, NsCharge = %u, Hp = %u, Sta = %u, Mp = %u,
    //Str = %u, Con = %u, Dex = %u, Int = %u, TitleId = %u, Region = %u, PosX = %u, PosY = %u,
    //TransRegion = %u, TransPosX = %u, TransPosY = %u, LogSp = %u, LastDate = GetDate() WHERE AliasSeq = %d
    redis::Connector &conn = GetConnector();

    try {
        if (!conn.exists(redis::UniqueKey("UserAliasList", pc->m_nAliasSeq))) {
            LOGERROR("%s:%d not exist", "UserAliasList", pc->m_nAliasSeq);
            return FALSE;
        }

        msgpack::sbuffer buffer;

        conn.PushCommand("HMSET");
        conn.Push(redis::UniqueKey("UserAliasList", pc->m_nAliasSeq));
        conn.Push("Job", pc->m_btJob);
        conn.Push("Level", pc->m_btLevel);
        conn.Push("Exp", pc->m_dwExp);
        conn.Push("Sp", pc->m_btSp);
        conn.Push("SkillExp", pc->m_dwSkillExp);
        conn.Push("Gold", pc->m_dwGold);
        conn.Push("RealmPoint", pc->m_dwRealmPoint);
        conn.Push("LostExp", pc->m_dwLastDeadExp);
        conn.Push("Ns", pc->m_wNs);
        conn.Push("NsCharge", pc->m_wNsCharge);
        conn.Push("Hp", (unsigned short)pc->m_fHp);
        conn.Push("Sta", (unsigned short)pc->m_fSta);
        conn.Push("Mp", (unsigned short)pc->m_fMp);
        conn.Push("TitleId", pc->m_wTitleId);
        conn.Push("Region", pc->m_btRegion);
        conn.Push("PosX", pc->m_cell.x);
        conn.Push("PosY", pc->m_cell.y);
        conn.Push("TransRegion", pc->m_btTransRegion);
        conn.Push("TransPosX", pc->m_cellTrans.x);
        conn.Push("TransPosY", pc->m_cellTrans.y);
        conn.Push("LogSp", pc->m_wLogSp);
        conn.Push("LastDate", time(NULL));
        conn.PushRaw("QuickBar", pc->m_dwQuickBarArray, sizeof(pc->m_dwQuickBarArray));

        PackPet(pc, buffer);
        conn.Push("PetInfo", buffer);

        PackSkillBuffArray(pc, buffer);
        conn.Push("SkillBuffTime", buffer);

        conn.Push("Summon", pc->m_SummonState);

        PackTameMob(pc, buffer);
        conn.Push("TameMob", buffer);
        
        conn.GetReply().CheckStatusOk();

        return TRUE;
    } catch (redis::Exception &ex) {
        LOGERROR("'%s' UserId:%s,AliasSeq:%d", ex.what(), pc->m_szUserId, pc->m_nAliasSeq);
    }

    return FALSE;
}
BOOL GameDb::DBRaceUpdate(CNSPcExt *pc) {
    redis::Connector &conn = GetConnector();
	try {
        conn.PushCommand("HMSET");
		conn.Push(redis::UniqueKey("UserAliasList", pc->m_nAliasSeq));
		conn.Push("Race", pc->m_btRace);
		conn.Push("Body", pc->m_btBody);
        conn.GetReply().CheckStatusOk();
		return TRUE;
	} catch (redis::Exception &ex) {
        LOGERROR("'%s' AliasSeq:%d", ex.what(), pc->m_nAliasSeq);
	}
	return FALSE;
}
BOOL GameDb::DBGoldUpdate(CNSPcExt *pc) {
    redis::Connector &conn = GetConnector();
	try {
		conn.hset(redis::UniqueKey("UserAliasList", pc->m_nAliasSeq), "Gold", pc->m_dwGold);
		return TRUE;
	} catch (redis::Exception &ex) {
        LOGERROR("'%s' AliasSeq:%d Gold:%u", ex.what(), pc->m_nAliasSeq, pc->m_dwGold);
	}
	return FALSE;
}
BOOL GameDb::DBBindPosUpdate(CNSPcExt *pc) {
    redis::Connector &conn = GetConnector();
	try {
        conn.PushCommand("HMSET");
		conn.Push(redis::UniqueKey("UserAliasList", pc->m_nAliasSeq));
		conn.Push("BindRegion", pc->m_btBindRegion);
		conn.Push("BindPosX", pc->m_cellBind.x);
		conn.Push("BindPosY", pc->m_cellBind.y);
        conn.GetReply().CheckStatusOk();
		return TRUE;
	} catch (redis::Exception &ex) {
		LOGERROR("'%s' AliasBindPosUpdate(%d)", ex.what(), pc->m_nAliasSeq);
	}
	return FALSE;
}

BOOL GameDb::DBItemInsert(CNSPcExt *pc, CNSItemExt *pItem, int nAliasSeq) {
    redis::Connector &conn = GetConnector();

    if (nAliasSeq == -1) {
        nAliasSeq = pc->m_nAliasSeq;
    }

    try {
        base::CalcHighTimeRange calc_time1("ItemInsert");

        conn.PushCommand("EVALSHA");
        conn.Push(script_item_insert_);
        conn.Push(0);
        conn.Push(nAliasSeq);
        conn.Push(pItem->m_wItemId);
        conn.Push(pItem->m_szItemName);
        conn.Push(pItem->m_wPos);
        conn.Push(pItem->m_btRare);
        conn.Push(pItem->m_btCount);
        conn.Push(pItem->m_wAttackMinDamage);
        conn.Push(pItem->m_wAttackMaxDamage);
        conn.Push(pItem->m_btDefenseDamage);
        conn.Push(pItem->m_nUniqueSeq);
        conn.PushRaw(pItem->m_Option, pItem->GetOptionSize());
        int result = conn.GetReply().as<int32_t>();

        if (!pItem->m_nUniqueSeq) {
            pItem->m_nUniqueSeq = result;
        }

        pItem->m_nSeq = result;
        pItem->m_wPosDb = pItem->m_wPos;
        pItem->m_btCountDb = pItem->m_btCount;

        return TRUE;

    } catch (redis::Exception &ex) {
        LOGERROR("'%s' ItemInsert(%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d)",
            ex.what(),
            nAliasSeq,
            pItem->m_wPos,
            pItem->m_wItemId,
            pItem->m_btRare,
            pItem->m_btCount,
            pItem->m_wAttackMinDamage,
            pItem->m_wAttackMaxDamage,
            pItem->m_btDefenseDamage,
            pItem->m_Option[0].btParam,
            pItem->m_Option[0].wValue,
            pItem->m_Option[1].btParam,
            pItem->m_Option[1].wValue,
            pItem->m_Option[2].btParam,
            pItem->m_Option[2].wValue,
            pItem->m_Option[3].btParam,
            pItem->m_Option[3].wValue,
            pItem->m_Option[4].btParam,
            pItem->m_Option[4].wValue,
            pItem->m_Option[5].btParam,
            pItem->m_Option[5].wValue,
            pItem->m_Option[6].btParam,
            pItem->m_Option[6].wValue,
            pItem->m_Option[7].btParam,
            pItem->m_Option[7].wValue,
            pItem->m_Option[8].btParam,
            pItem->m_Option[8].wValue,
            pItem->m_Option[9].btParam,
            pItem->m_Option[9].wValue,
            pItem->m_nUniqueSeq);
    }

    return FALSE;
}

BOOL GameDb::DBItemUpdate(CNSPcExt *pc, CNSItemExt *pItem) {
    redis::Connector &conn = GetConnector();

	if (pItem->m_nSeq == -1) {
		return FALSE;
	}

	try {
		if (!conn.exists(redis::UniqueKey("ItemList", pItem->m_nSeq))) {
			LOGERROR("ItemList not exist(%d)", pItem->m_nSeq);
			return FALSE;
		}

		conn.PushCommand("HMSET");
		conn.Push(redis::UniqueKey("ItemList", pItem->m_nSeq));
		conn.Push("ItemName", pItem->m_szItemName);
		conn.Push("Rare", pItem->m_btRare);
		conn.Push("Count", pItem->m_btCount);
		conn.Push("AttackMinDamage", pItem->m_wAttackMinDamage);
		conn.Push("AttackMaxDamage", pItem->m_wAttackMaxDamage);
		conn.Push("DefenseDamage", pItem->m_btDefenseDamage);
		conn.PushRaw("Option", pItem->m_Option, pItem->GetOptionSize());
        conn.GetReply().CheckStatusOk();

		return TRUE;
	} catch (redis::Exception &ex) {
		LOGERROR("'%s' ItemUpdate(%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d)",
			ex.what(),
			pc->m_nAliasSeq,
			pItem->m_wPos,
			pItem->m_wItemId,
			pItem->m_btRare,
			pItem->m_btCount,
			pItem->m_wAttackMinDamage,
			pItem->m_wAttackMaxDamage,
			pItem->m_btDefenseDamage,
			pItem->m_Option[0].btParam,
			pItem->m_Option[0].wValue,
			pItem->m_Option[1].btParam,
			pItem->m_Option[1].wValue,
			pItem->m_Option[2].btParam,
			pItem->m_Option[2].wValue,
			pItem->m_Option[3].btParam,
			pItem->m_Option[3].wValue,
			pItem->m_Option[4].btParam,
			pItem->m_Option[4].wValue,
			pItem->m_Option[5].btParam,
			pItem->m_Option[5].wValue,
			pItem->m_Option[6].btParam,
			pItem->m_Option[6].wValue,
			pItem->m_Option[7].btParam,
			pItem->m_Option[7].wValue,
			pItem->m_Option[8].btParam,
			pItem->m_Option[8].wValue,
			pItem->m_Option[9].btParam,
			pItem->m_Option[9].wValue,
			pItem->m_nUniqueSeq);
	}

	return FALSE;
}

BOOL GameDb::DBItemUpdatePosCount(CNSPcExt *pc, CNSItemExt *pItem) {
    redis::Connector &conn = GetConnector();

	if (pItem->m_nSeq == -1) {
		return FALSE;
	}

	if (pItem->m_wPosDb == pItem->m_wPos 
        && pItem->m_btCountDb == pItem->m_btCount) {
		return TRUE;
	}

	try {
		if (!conn.exists(redis::UniqueKey("ItemList", pItem->m_nSeq))) {
			LOGERROR("ItemList not exist(%d)", pItem->m_nSeq);
			return FALSE;
		}

        conn.PushCommand("HMSET");
		conn.Push(redis::UniqueKey("ItemList", pItem->m_nSeq));
		conn.Push("Pos", pItem->m_wPos);
		conn.Push("Count", pItem->m_btCount);
        conn.GetReply().CheckStatusOk();

		pItem->m_wPosDb = pItem->m_wPos;
		pItem->m_btCountDb = pItem->m_btCount;

		return TRUE;
	} catch (redis::Exception &ex) {
		LOGERROR("'%s' ItemUpdate(%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d)",
			ex.what(),
			pc->m_nAliasSeq,
			pItem->m_wPos,
			pItem->m_wItemId,
			pItem->m_btRare,
			pItem->m_btCount,
			pItem->m_wAttackMinDamage,
			pItem->m_wAttackMaxDamage,
			pItem->m_btDefenseDamage,
			pItem->m_Option[0].btParam,
			pItem->m_Option[0].wValue,
			pItem->m_Option[1].btParam,
			pItem->m_Option[1].wValue,
			pItem->m_Option[2].btParam,
			pItem->m_Option[2].wValue,
			pItem->m_Option[3].btParam,
			pItem->m_Option[3].wValue,
			pItem->m_Option[4].btParam,
			pItem->m_Option[4].wValue,
			pItem->m_Option[5].btParam,
			pItem->m_Option[5].wValue,
			pItem->m_Option[6].btParam,
			pItem->m_Option[6].wValue,
			pItem->m_Option[7].btParam,
			pItem->m_Option[7].wValue,
			pItem->m_Option[8].btParam,
			pItem->m_Option[8].wValue,
			pItem->m_Option[9].btParam,
			pItem->m_Option[9].wValue,
			pItem->m_nUniqueSeq);
	}

	return FALSE;
}
BOOL GameDb::DBItemUpdateAllPosCount(CNSPcExt *pc) {
    redis::Connector &conn = GetConnector();
	try {
        for (int i = 0; i < CNSEquipment::EquipType_End; ++i) {
            CNSItem *pItem = pc->m_Equip.m_ItemArray[i];
            if (pItem) {
                if (pItem->m_nSeq == -1
                    || (pItem->m_wPosDb == pItem->m_wPos 
                    && pItem->m_btCountDb == pItem->m_btCount)) {
                        continue;
                }

                conn.PushCommand("EVALSHA");
                conn.Push(script_item_update_pos_count_);
                conn.Push(0);
                conn.Push(pItem->m_nSeq);
                conn.Push(pItem->m_wPos);
                conn.Push(pItem->m_btCount);
            }
        }

        for (unsigned int i = 0; i < 0x64; ++i) {
            CNSItem *pItem = pc->m_Inven.m_ItemArray[i];
            if (pItem) {
                if (pItem->m_nSeq == -1
                    || (pItem->m_wPosDb == pItem->m_wPos 
                    && pItem->m_btCountDb == pItem->m_btCount)) {
                        continue;
                }

                conn.PushCommand("EVALSHA");
                conn.Push(script_item_update_pos_count_);
                conn.Push(0);
                conn.Push(pItem->m_nSeq);
                conn.Push(pItem->m_wPos);
                conn.Push(pItem->m_btCount);
            }
        }

        if (conn.GetCommandCount()) {
            redis::Reply reply = conn.GetAllReply();
            for (redis::Reply *iter = reply.Begin(); iter != reply.End(); ++iter) {
                iter->CheckStatusOk();
            }

            for (int i = 0; i < CNSEquipment::EquipType_End; ++i) {
                CNSItem *pItem = pc->m_Equip.m_ItemArray[i];
                if (pItem) {
                    if (pItem->m_nSeq == -1
                        || (pItem->m_wPosDb == pItem->m_wPos 
                        && pItem->m_btCountDb == pItem->m_btCount)) {
                            continue;
                    }

                    pItem->m_wPosDb = pItem->m_wPos;
                    pItem->m_btCountDb = pItem->m_btCount;
                }
            }

            for (unsigned int i = 0; i < 0x64; ++i) {
                CNSItem *pItem = pc->m_Inven.m_ItemArray[i];
                if (pItem) {
                    if (pItem->m_nSeq == -1
                        || (pItem->m_wPosDb == pItem->m_wPos 
                        && pItem->m_btCountDb == pItem->m_btCount)) {
                            continue;
                    }

                    pItem->m_wPosDb = pItem->m_wPos;
                    pItem->m_btCountDb = pItem->m_btCount;
                }
            }
        }
		return TRUE;
	} catch (redis::Exception &ex) {
		LOGERROR("'%s'", ex.what());
	}

	return FALSE;
}
BOOL GameDb::DBItemDelete(CNSPcExt *pc, int nItemSeq) {
    redis::Connector &conn = GetConnector();

	if (nItemSeq == -1) {
		return FALSE;
	}

	try {
        if (conn.evalsha(script_item_delete_, pc->m_nAliasSeq, nItemSeq).as<int64_t>() != 1) {
            LOGERROR("error ItemDelete(%d, %d)", pc->m_nAliasSeq, nItemSeq);
        }

		return TRUE;
	}
	catch (redis::Exception &ex) {
		LOGERROR("'%s' ItemDelete(%d, %d)", ex.what(), pc->m_nAliasSeq, nItemSeq);
	}

	return FALSE;
}

BOOL GameDb::DBSkillLoad(CNSPcExt *pc) {
    redis::Connector &conn = GetConnector();
    pc->m_SkillList.Clear();
    try {
        redis::Reply reply = conn.hgetall(redis::UniqueKey("SkillList", pc->m_nAliasSeq));
        if (LoadSkill(pc, reply)) {
            return TRUE;
        } else {
            return FALSE;
        }
    } catch (redis::Exception &ex) {
        LOGERROR("'%s' AliasSeq:%d", ex.what(), pc->m_nAliasSeq);
    }
    return FALSE;
}

BOOL GameDb::DBSkillInsert(CNSPcExt *pc, CNSSkill *pSkill) {
    redis::Connector &conn = GetConnector();
    try {
        if (conn.hsetnx(redis::UniqueKey("SkillList", pc->m_nAliasSeq), pSkill->m_wSkillId, pSkill->m_btSkillLevel)) {
            pSkill->m_nDbSeq = -1;
            pSkill->m_btSkillLevelDb = pSkill->m_btSkillLevel;
            pSkill->m_wSkillExpDb = pSkill->m_wSkillExp;
            return TRUE;
        } else {
            LOGERROR("AliasSeq:%d,SkillId:%u exist", pc->m_nAliasSeq, pSkill->m_wSkillId);
            return FALSE;
        }

    } catch (redis::Exception &ex) {
        LOGERROR("'%s' AliasSeq:%d,SkillId:%u", ex.what(), pc->m_nAliasSeq, pSkill->m_wSkillId);
    }

    return FALSE;
}

BOOL GameDb::DBSkillUpdate(CNSPcExt *pc, CNSSkill *pSkill) {
	if (pSkill->m_btSkillLevelDb == pSkill->m_btSkillLevel 
        && pSkill->m_wSkillExpDb == pSkill->m_wSkillExp) {
		return TRUE;
	}

    redis::Connector &conn = GetConnector();
	try {
        if (!conn.hexists(redis::UniqueKey("SkillList", pc->m_nAliasSeq), pSkill->m_wSkillId)) {
            LOGERROR("AliasSeq:%d,SkillId:%u not exist", pc->m_nAliasSeq, pSkill->m_wSkillId);
            return FALSE;
        }

		conn.hset(redis::UniqueKey("SkillList", pc->m_nAliasSeq), pSkill->m_wSkillId, pSkill->m_btSkillLevel);

		pSkill->m_btSkillLevelDb = pSkill->m_btSkillLevel;
		pSkill->m_wSkillExpDb = pSkill->m_wSkillExp;
		return TRUE;

	} catch (redis::Exception &ex) {
		LOGERROR("'%s' AliasSeq:%d,SkillId:%u", ex.what(), pc->m_nAliasSeq, pSkill->m_wSkillId);
	}

	return FALSE;
}
BOOL GameDb::DBQuestInsert(CNSPcExt *pc, unsigned short wQuestId, CNSQuest *pQuest) {
    redis::Connector &conn = GetConnector();
    try {
        CNSQuestExt::QuestData data;
        data.wQuestId = wQuestId;
        data.btCompleted = 0;
        data.btStep = 1;
        data.btCheckCount = 0;
        data.btPoint = 0;
        data.dwRegdate = time(NULL);

        msgpack::sbuffer buffer;
        msgpack::pack(buffer, data);

        if (!conn.hsetnx(redis::UniqueKey("QuestList", pc->m_nAliasSeq), wQuestId, buffer)) {
            LOGERROR("QuestId exist(AliasSeq:%d,QuestId:%u)", pc->m_nAliasSeq, wQuestId);
            return FALSE;
        }

        if (pQuest) {
            pQuest->m_btCompletedDb = pQuest->m_btCompleted;
            pQuest->m_btStepDb = pQuest->m_btStep;
            pQuest->m_btCheckCountDb = pQuest->m_btCheckCount;
            pQuest->m_btPointDb = pQuest->m_btPoint;
        }

        return TRUE;
    } catch (redis::Exception &ex) {
        LOGERROR("'%s' AliasSeq:%d,QuestId:%u", ex.what(), pc->m_nAliasSeq, wQuestId);
    }
    return FALSE;
}
BOOL GameDb::DBQuestUpdate(CNSPcExt *pc, CNSQuest *pQuest) {
    if (pQuest->m_btCompletedDb == pQuest->m_btCompleted
        && pQuest->m_btStepDb == pQuest->m_btStep
        && pQuest->m_btCheckCountDb == pQuest->m_btCheckCount
        && pQuest->m_btPointDb == pQuest->m_btPoint) {
            return TRUE;
    }

    redis::Connector &conn = GetConnector();
    try {
		if (!conn.hexists(redis::UniqueKey("QuestList", pc->m_nAliasSeq), pQuest->m_wQuestId)) {
			LOGERROR("QuestId not exist(AliasSeq:%d,QuestId:%u)", pc->m_nAliasSeq, pQuest->m_wQuestId);
			return FALSE;
		}

        CNSQuestExt::QuestData data;
        data.wQuestId = pQuest->m_wQuestId;
        data.btCompleted = pQuest->m_btCompleted;
        data.btStep = pQuest->m_btStep;
        data.btCheckCount = pQuest->m_btCheckCount;
        data.btPoint = pQuest->m_btPoint;
        data.dwRegdate = time(NULL);

        msgpack::sbuffer buffer;
        msgpack::pack(buffer, data);

		conn.hset(redis::UniqueKey("QuestList", pc->m_nAliasSeq), pQuest->m_wQuestId, buffer);

		pQuest->m_btCompletedDb = pQuest->m_btCompleted;
		pQuest->m_btStepDb = pQuest->m_btStep;
		pQuest->m_btCheckCountDb = pQuest->m_btCheckCount;
        pQuest->m_btPointDb = pQuest->m_btPoint;

        return TRUE;
    } catch (redis::Exception &ex) {
        LOGERROR("'%s' AliasSeq:%d,QuestId:%u", ex.what(), pc->m_nAliasSeq, pQuest->m_wQuestId);
    }
	return FALSE;
}

BOOL GameDb::DBQuestDelete(CNSPcExt *pc, unsigned short wQuestId) {
    redis::Connector &conn = GetConnector();
	try {
		if (!conn.hdel(redis::UniqueKey("QuestList", pc->m_nAliasSeq), wQuestId)) {
			LOGERROR("QuestId not exist(AliasSeq:%d,QuestId:%u)", pc->m_nAliasSeq, wQuestId);
			return 0;
		}
		return TRUE;
	} catch (redis::Exception &ex) {
		LOGERROR("'%s' AliasSeq:%d,QuestId:%u", ex.what(), pc->m_nAliasSeq, wQuestId);
	}
	return FALSE;
}
BOOL GameDb::DBTeleportUpdate(CNSPcExt *pc, CNSPcTeleportList::Teleport *teleport) {
	redis::Connector &conn = GetConnector();

	msgpack::sbuffer buffer;
	msgpack::packer<msgpack::sbuffer> pk(&buffer);
	for (unsigned int i = 0; i < pc->m_TeleportList.m_dwCount; ++i) {
        pk.pack_array(4);
        pk.pack(pc->m_TeleportList.m_TeleportArray[i].szName);
        pk.pack(pc->m_TeleportList.m_TeleportArray[i].btRegion);
        pk.pack(pc->m_TeleportList.m_TeleportArray[i].wPosX);
        pk.pack(pc->m_TeleportList.m_TeleportArray[i].wPosY);
	}

	if (teleport) {
		pk.pack_array(4);
        pk.pack(teleport->szName);
        pk.pack(teleport->btRegion);
        pk.pack(teleport->wPosX);
        pk.pack(teleport->wPosY);
	}

	try {
		conn.hset(redis::UniqueKey("UserAliasList", pc->m_nAliasSeq), "Teleport", buffer);
		return TRUE;
	} catch (redis::Exception &ex) {
		LOGERROR("'%s' AliasSeq:%d", ex.what(), pc->m_nAliasSeq);
	}
	return FALSE;
	
}
BOOL GameDb::DBFriendInsert(CNSPcExt *pc, char *szUserAlias, int &nDbSeq) {
    redis::Connector &conn = GetConnector();
    try {
        nDbSeq = conn.evalsha(script_friend_insert_, pc->m_nAliasSeq, szUserAlias).as<int32_t>();
        return TRUE;
    } catch (redis::Exception &ex) {
        LOGERROR("'%s' AliasSeq:%d,target:%s", ex.what(), pc->m_nAliasSeq, szUserAlias);
    }
    return TRUE;
}

BOOL GameDb::DBFriendDelete(CNSPcExt *pc, int nDbSeq) {
    redis::Connector &conn = GetConnector();
	try {
		if (!conn.srem(redis::UniqueKey("FriendList", pc->m_nAliasSeq), nDbSeq)) {
			LOGERROR("friend not exist(AliasSeq:%d,target AliasSeq:%u)", pc->m_nAliasSeq, nDbSeq);
			return FALSE;
		}

		return TRUE;
	} catch (redis::Exception &ex) {
		LOGERROR("'%s' AliasSeq:%d,target AliasSeq:%u", ex.what(), pc->m_nAliasSeq, nDbSeq);
	}
	return FALSE;
}

BOOL GameDb::DbTitleAdd(CNSPcExt *pc, unsigned short wTitleId) {
    redis::Connector &conn = GetConnector();
	try {
		if (!conn.sadd(redis::UniqueKey("TitleList", pc->m_nAliasSeq), wTitleId)) {
			LOGERROR("TitleId exist(AliasSeq:%d,TitleId:%u)", pc->m_nAliasSeq, wTitleId);
			return FALSE;
        } else {
            return TRUE;
        }
	} catch (redis::Exception &ex) {
        LOGERROR("'%s' AliasSeq:%d,TitleId:%u", ex.what(), pc->m_nAliasSeq, wTitleId);
    }
    return FALSE;
}

unsigned long GameDb::DBPremiumShopLimitCount(unsigned char btCategory, unsigned char btSeq) {
    redis::Connector &conn = GetConnector();
	try {
        if (conn.hexists(redis::UniqueKey("PremiumShopLimit", btCategory), btSeq)) {
            return conn.hget(redis::UniqueKey("PremiumShopLimit", btCategory), btSeq).convert<uint32_t>();
        } else {
            return 0;
        }
	} catch (redis::Exception &ex) {
        LOGERROR("'%s' Category:%d,Seq:%u", ex.what(), btCategory, btSeq);
    }
    return 0;
}

BOOL GameDb::DBPremiumShopLimitIncCount(unsigned char btCategory, unsigned char btSeq) {
    redis::Connector &conn = GetConnector();
	try {
        conn.hincrby(redis::UniqueKey("PremiumShopLimit", btCategory), btSeq, 1);
        return TRUE;
	} catch (redis::Exception &ex) {
        LOGERROR("'%s' Category:%d,Seq:%u", ex.what(), btCategory, btSeq);
    }
    return FALSE;
}

void GameDb::DBFortressSave(CNSWorldManager *pWorldManager) {
	redis::Connector &conn = GetConnector();
	try {
		conn.set("FortressList", *reinterpret_cast<unsigned long *>(pWorldManager->m_btFortressArray));
	} catch (redis::Exception &ex) {
		LOGERROR("'%s'", ex.what());
	}
}

BOOL GameDb::DBFortressLoad(CNSWorldManager *pWorldManager) {
	redis::Connector &conn = GetConnector();
	try {
		if (!conn.exists("FortressList")) {
			return FALSE;
		}

		redis::Reply reply = conn.get("FortressList");

		*reinterpret_cast<unsigned long *>(pWorldManager->m_btFortressArray) = reply.convert<unsigned long>();
        pWorldManager->m_dwFortressCount = 4;

		return TRUE;
	} catch (redis::Exception &ex) {
		LOGERROR("'%s'", ex.what());
	}
	return FALSE;
}

void GameDb::DBBlockSave(CNSNpcManager *pNpcManager) {
	redis::Connector &conn = GetConnector();

	if (pNpcManager->m_dwBlockObjectCount == 0) {
		return;
	}

	msgpack::sbuffer buffer;
	msgpack::packer<msgpack::sbuffer> pk(&buffer);
	for (unsigned int i = 0; i < pNpcManager->m_dwBlockObjectCount; ++i) {
		pk.pack_array(4);
		pk.pack_uint16(pNpcManager->m_blockObjectArray[i].wNpcId);
		pk.pack_uint16(pNpcManager->m_blockObjectArray[i].cell.x);
		pk.pack_uint16(pNpcManager->m_blockObjectArray[i].cell.y);
		pk.pack_uint16(pNpcManager->m_blockObjectArray[i].wAngle);
	}

	try {
		conn.set("BlockData", buffer);
	} catch (redis::Exception &ex) {
		LOGERROR("'%s'", ex.what());
	}
}

BOOL GameDb::DBBlockLoad(CNSNpcManager *pNpcManager) {
	redis::Connector &conn = GetConnector();

	pNpcManager->m_dwBlockObjectCount = 0;
	memset(pNpcManager->m_blockObjectArray, 0, sizeof(pNpcManager->m_blockObjectArray));

	try {
		if (!conn.exists("BlockData")) {
			return FALSE;
		}

		redis::Reply reply = conn.get("BlockData");
		
		std::size_t off = 0;
		const char *buffer = reply.GetString();
		std::size_t size = reply.GetLength();

		while (off != size) {
			msgpack::unpacked result;
			msgpack::unpack(result, buffer, size, off);
			msgpack::object obj(result.get());
			if (obj.type != MSGPACK_OBJECT_ARRAY || obj.via.array.size != 4) {
				LOGERROR("obj.type != MSGPACK_OBJECT_ARRAY || obj.via.array.size != 4");
				return FALSE;
			}

			pNpcManager->m_blockObjectArray[pNpcManager->m_dwBlockObjectCount].wNpcId = obj.via.array.ptr[0].as<uint16_t>();
			pNpcManager->m_blockObjectArray[pNpcManager->m_dwBlockObjectCount].cell.x = obj.via.array.ptr[1].as<uint16_t>();
			pNpcManager->m_blockObjectArray[pNpcManager->m_dwBlockObjectCount].cell.y = obj.via.array.ptr[2].as<uint16_t>();
			pNpcManager->m_blockObjectArray[pNpcManager->m_dwBlockObjectCount].wAngle = obj.via.array.ptr[3].as<uint16_t>();
			++pNpcManager->m_dwBlockObjectCount;
		}

		return TRUE;
	} catch (redis::Exception &ex) {
		LOGERROR("'%s'", ex.what());
	}

	return FALSE;
}


BOOL GameDb::DBWareHouseGoldLoad(int nUserSeq, unsigned char btRegion, unsigned long& dwOutGold) {
	redis::Connector &conn = GetConnector();
	try {
        dwOutGold = conn.evalsha(script_ware_gold_load_, nUserSeq, btRegion).as<uint32_t>();
		return TRUE;
	} catch (redis::Exception &ex) {
		LOGERROR("'%s' UserSeq:%d", ex.what(), nUserSeq);
	}

	return FALSE;
}
BOOL GameDb::DBWareHouseGoldIncrment(int nUserSeq, unsigned int dwGold) {
	redis::Connector &conn = GetConnector();
	try {
		conn.hincrby(redis::UniqueKey("UserInfo", nUserSeq), "Gold", dwGold);
		return TRUE;
	} catch (redis::Exception &ex) {
		LOGERROR("'%s' UserSeq:%d", ex.what(), nUserSeq);
	}

	return FALSE;
}

BOOL GameDb::DBWareHouseGoldDecrease(int nUserSeq, unsigned int dwGold) {
	redis::Connector &conn = GetConnector();
	try {
		conn.hincrby(redis::UniqueKey("UserInfo", nUserSeq), "Gold", -(long long)dwGold);
		return TRUE;
	} catch (redis::Exception &ex) {
		LOGERROR("'%s' UserSeq:%d", ex.what(), nUserSeq);
	}

	return FALSE;
}

BOOL GameDb::DBWareItemLoad(CNSWareHouse *pWareHouse) {
	redis::Connector &conn = GetConnector();
    
    int nUserSeq = pWareHouse->m_pParent->m_nUserSeq;
    if (pWareHouse->m_bGuildWareHouse) {
        CNSObject::Owner<CNSGuild> guild = CNSObjectManager::GetInstance()->Get<CNSGuild>(CNSObject::ObjectType_Guild, pWareHouse->m_pParent->m_dwGuildId);
        if (guild) {
            nUserSeq = guild->m_nDbSeq;
            pWareHouse->m_dwGuildRank = guild->m_dwRankMonth;
        }

        if (!nUserSeq) {
            return FALSE;
        } else {
            nUserSeq += 2000000000;
        }
    }

	try {
        redis::Reply result = conn.evalsha(script_ware_item_load_, nUserSeq);

		 for (redis::Reply *iter = result.Begin(); iter != result.End(); ++iter) {
            CNSObject::Owner<CNSItem> item(CNSItemExt::New());
            item->SetOwner(pWareHouse->m_pParent->m_szUserAlias);

            item->m_nSeq = (*iter)[2].convert<int32_t>();
            item->m_wItemId = (*iter)[3].convert<uint16_t>();
            (*iter)[4].assgin(item->m_szItemName, 25);
            item->m_wPos = (*iter)[5].convert<uint16_t>();
            item->m_btRare = (*iter)[6].convert<uint8_t>();
            item->m_btCount = (*iter)[7].convert<uint8_t>();
            item->m_wAttackMinDamage = (*iter)[8].convert<uint16_t>();
            item->m_wAttackMaxDamage = (*iter)[9].convert<uint16_t>();
            item->m_btDefenseDamage = (*iter)[10].convert<uint8_t>();
            item->m_nUniqueSeq = (*iter)[11].convert<int32_t>();
            (*iter)[12].assgin_raw(item->m_Option, sizeof(item->m_Option));

            CNSItem *item_params = CNSItemParams::GetInstance()->GetObjectA(item->m_wItemId);
            if (item_params == NULL) {
                LOGERROR("invailed itemid(%d)", item->m_wItemId);
                return FALSE;
            }

            item->m_wPosDb = item->m_wPos;
            item->m_btCountDb = item->m_btCount;
            item->m_wType = item_params->m_wType;
            item->m_btKind = item_params->m_btKind;
            item->m_dwGold = 0;
            item->m_btLimitLevel = item_params->m_btLimitLevel;
            item->m_btLimitRace = item_params->m_btLimitRace;
            memcpy(item->m_btLimitJob, item_params->m_btLimitJob, sizeof(item->m_btLimitJob));
            item->m_btEquipmentPart = item_params->m_btEquipmentPart;
            item->m_btAttackDistance = item_params->m_btAttackDistance;
            item->m_btAttackSpeed = item_params->m_btAttackSpeed;
            item->m_szDbDescription = item_params->m_szDbDescription;
            item->m_wQuestId = item_params->m_wQuestId;

			pWareHouse->_Add(item);
		}

        static_cast<CNSWareHouseExt*>(pWareHouse)->SortPos();
		return TRUE;
	} catch (redis::Exception &ex) {
		LOGERROR("'%s' UserSeq:'%d'", ex.what(), nUserSeq);
	}
	return FALSE;
}

BOOL GameDb::DBWareItemIn(CNSItem *pItem, int nUserSeq, int nAliasSeq) {
	redis::Connector &conn = GetConnector();

	if (nUserSeq <= 0 || pItem->m_nSeq <= 0) {
		LOGERROR("invaild userseq");
		return FALSE;
	}

	try {
        conn.PushCommand("EVALSHA");
        conn.Push(script_ware_item_in_);
        conn.Push(0);
        conn.Push(nAliasSeq);
        conn.Push(nUserSeq);
        conn.Push(pItem->m_nSeq);
        conn.Push(pItem->m_wPos);
        conn.Push(pItem->m_btCount);
        conn.GetReply().CheckStatusOk();
		
		return TRUE;
	} catch (redis::Exception &ex) {
		LOGERROR("'%s' UserSeq:%d", ex.what(), nUserSeq);
	}

	return FALSE;
}

BOOL GameDb::DBWareItemOut(CNSItem *pItem, int nUserSeq, int nAliasSeq) {
	redis::Connector &conn = GetConnector();

	if (nUserSeq <= 0 || pItem->m_nSeq <= 0) {
		LOGERROR("invaild userseq");
		return false;
	}

	try {
        conn.PushCommand("EVALSHA");
        conn.Push(script_ware_item_out_);
        conn.Push(0);
        conn.Push(nAliasSeq);
        conn.Push(nUserSeq);
        conn.Push(pItem->m_nSeq);
        conn.Push(pItem->m_wPos);
        conn.GetReply().CheckStatusOk();
		return TRUE;
	} catch (redis::Exception &ex) {
		LOGERROR("'%s' UserSeq:%d", ex.what(), nUserSeq);
	}

	return FALSE;
}

CNSGuild* GameDb::DBGuildLoad(int nDbSeq) {
	redis::Connector &conn = GetConnector();
	try {
        redis::Reply reply = conn.evalsha(script_guild_load_, nDbSeq);

		CNSGuild::GuildInfo guild_info;
        reply[0].assgin(guild_info.szGuildMaster, sizeof(guild_info.szGuildMaster));
        guild_info.btRealm = reply[1].convert<uint8_t>();
		reply[2].assgin(guild_info.szGuildName, sizeof(guild_info.szGuildName));
		reply[3].assgin(guild_info.szComment, sizeof(guild_info.szComment));
		guild_info.btLevel = reply[4].convert<uint8_t>();
		guild_info.nPoint = reply[5].convert<int32_t>();
		guild_info.dwRankMonth = reply[6].convert<uint32_t>();
		guild_info.dwMark = reply[7].convert<uint32_t>();
		guild_info.dwRank = reply[8].convert<uint32_t>();
		guild_info.dwRankPoint = reply[9].convert<uint32_t>();

		CNSGuildExt *pGuild = CNSGuildExt::New(nDbSeq, guild_info);
		if (pGuild) {
			CNSPcParams::GetInstance()->LoadGuildMember(pGuild);
            pGuild->LoginAll();
		}

		//if (guild->m_dwMark == 81 && set[10].Len() > 0 
		//	&& set[10].Len() <= CNSGuildExt::MarkData::max_mark_size) {
		//	guild->UpdateMarkData(set[10].GetString(), set[10].Len(), 0, true);
		//}

		return pGuild;

	} catch (redis::Exception &ex) {
		LOGERROR("'%s' nDbSeq:%d", ex.what(), nDbSeq);
	}

	return NULL;
}
BOOL GameDb::DBGuildInsert(int nAliasSeq, unsigned char btRealm, char *szGuildName, char *szComment, int& nOutDbSeq) {
    redis::Connector &conn = GetConnector();
    try {
        nOutDbSeq = conn.evalsha(script_guild_insert_, nAliasSeq, btRealm, szGuildName, szComment).as<int32_t>();
        return TRUE;
    } catch (redis::Exception &ex) {
        LOGERROR("'%s' AliasSeq:%d,btRealm:%u,GuildName:%s", ex.what(), nAliasSeq, btRealm, szGuildName);
    }
    return FALSE;
}

BOOL GameDb::DBGuildDelete(CNSGuild *pGuild) {
    redis::Connector &conn = GetConnector();
    try {
        conn.evalsha(script_guild_delete_, pGuild->m_nDbSeq).CheckStatusOk();
        return TRUE;
    } catch (redis::Exception &ex) {
        LOGERROR("'%s' nDbSeq:%d", ex.what(), pGuild->m_nDbSeq);
    }
    return FALSE;
}

BOOL GameDb::DBGuildUpdate(CNSGuild *pGuild) {
    redis::Connector &conn = GetConnector();

	try {
        conn.evalsha(script_guild_update_,
            pGuild->m_nDbSeq,
            pGuild->m_szGuildMaster,
            pGuild->m_szGuildName,
            pGuild->m_szComment,
            pGuild->m_btLevel).CheckStatusOk();
		return TRUE;
	}
	catch (redis::Exception &ex) {
		LOGERROR("'%s' nDbSeq:%d", ex.what(), pGuild->m_nDbSeq);
	}

	return FALSE;
}

BOOL GameDb::DBGuildPointUpdate(CNSGuild *pGuild) {
    redis::Connector &conn = GetConnector();
	try {
		if (!conn.exists(redis::UniqueKey("GuildList", pGuild->m_nDbSeq))) {
            LOGERROR("GuildList:%d not exist", pGuild->m_nDbSeq);
			return FALSE;
		}

		conn.hset(redis::UniqueKey("GuildList", pGuild->m_nDbSeq), "Point", pGuild->m_nPoint);
		return TRUE;
	}

	catch (redis::Exception &ex) {
		LOGERROR("'%s' nDbSeq:%d,nPoint:%d", ex.what(), pGuild->m_nDbSeq, pGuild->m_nPoint);
	}
	return TRUE;
}

BOOL GameDb::DBGuildRefresh(CNSGuild *pGuild) {
    redis::Connector &conn = GetConnector();
	try {
        redis::Reply reply = conn.evalsha(script_guild_load_, pGuild->m_nDbSeq);

        reply[0].assgin(pGuild->m_szGuildMaster, sizeof(pGuild->m_szGuildMaster));
		reply[2].assgin(pGuild->m_szGuildName, sizeof(pGuild->m_szGuildName));
        pGuild->m_btLevel = reply[4].convert<uint8_t>();
		reply[3].assgin(pGuild->m_szComment, sizeof(pGuild->m_szComment));
        return TRUE;
	} catch (redis::Exception &ex) {
		LOGERROR("'%s' nDbSeq:%d", ex.what(), pGuild->m_nDbSeq);
	}

	return FALSE;
}

BOOL GameDb::DBGuildRankLoad(unsigned char realm, std::vector<int>& list) {
	redis::Connector &conn = GetConnector();
	try {
        redis::Reply result = conn.evalsha(script_guild_rank_load_, realm);
		for (redis::Reply *iter = result.Begin(); iter != result.End(); ++iter) {
            list.push_back(iter->as<int>());
		}

		return TRUE;
	} catch (redis::Exception &ex) {
		LOGERROR("'%s'", ex.what());
	}

	return FALSE;
}


BOOL GameDb::DBMemberInsert(CNSGuild *pGuild, int nAliasSeq, unsigned char btRank) {
    redis::Connector &conn = GetConnector();
	try {
        conn.evalsha(script_guild_member_insert_, pGuild->m_nDbSeq, nAliasSeq, btRank).CheckStatusOk();
        return TRUE;
	} catch (redis::Exception &ex) {
		LOGERROR("'%s' nDbSeq:%d,nAliasSeq:%d btRank:%u", ex.what(), pGuild->m_nDbSeq, nAliasSeq, btRank);
	}
	return FALSE;
}
BOOL GameDb::DBMemberUpdate(CNSGuild *pGuild, char *szUserAlias, unsigned char btRank) {
    redis::Connector &conn = GetConnector();
	try {
        conn.evalsha(script_guild_member_update_, 0, szUserAlias, btRank);
		return TRUE;
	}
	catch (redis::Exception &ex) {
		LOGERROR("'%s' nDbSeq:%d,UserAlias:%s", ex.what(), pGuild->m_nDbSeq, szUserAlias);
	}
	return FALSE;
}
BOOL GameDb::DBMemberUpdate(CNSGuild *pGuild, int nAliasSeq, unsigned char btRank) {
    redis::Connector &conn = GetConnector();
	try {
        conn.evalsha(script_guild_member_update_, 1, nAliasSeq, btRank);
		return TRUE;
	} 
	catch (redis::Exception &ex) {
		LOGERROR("'%s' nDbSeq:%d,nAliasSeq:%d", ex.what(), pGuild->m_nDbSeq, nAliasSeq);
	}
	return FALSE;
}
BOOL GameDb::DBMemberDelete(CNSGuild *pGuild, char *szUserAlias) {
    redis::Connector &conn = GetConnector();
	try {
        conn.evalsha(script_guild_member_delete_, 0, szUserAlias, pGuild->m_nDbSeq);
		return TRUE;
	} catch (redis::Exception &ex) {
		LOGERROR("'%s' nDbSeq:%d,nUserAlias:%s", ex.what(), pGuild->m_nDbSeq, szUserAlias);
	}
	return FALSE;
}
BOOL GameDb::DBMemberDelete(CNSGuild *pGuild, int nAliasSeq) {
    redis::Connector &conn = GetConnector();
	try {
        conn.evalsha(script_guild_member_delete_, 1, nAliasSeq, pGuild->m_nDbSeq);
		return TRUE;
	} catch (redis::Exception &ex) {
		LOGERROR("'%s' nDbSeq:%d,nAliasSeq:%d", ex.what(), pGuild->m_nDbSeq, nAliasSeq);
	}
	return FALSE;
}
BOOL GameDb::DBGuildMemberLoad(CNSGuild *pGuild) {
    redis::Connector &conn = GetConnector();

	pGuild->Clear();
	char useralias[25];

	try {
        base::CalcHighTimeRange calc_time("DBGuildMemberLoad");

        redis::Reply reply = conn.evalsha(script_guild_member_load_, pGuild->m_nDbSeq);
        for (redis::Reply *iter = reply.Begin(); iter != reply.End(); ++iter) {
			int alias_seq = (*iter)[0].convert<uint32_t>();
            (*iter)[1].assgin(useralias, sizeof(useralias));
            unsigned char rank = (*iter)[2].convert<uint8_t>();

			pGuild->Add(alias_seq, useralias, rank);
		}
		return TRUE;
	} catch (redis::Exception &ex) {
		LOGERROR("'%s' nDbSeq:%d", ex.what(), pGuild->m_nDbSeq);
	}

	return FALSE;
}
unsigned short GameDb::DBGuildMemberLevel(CNSGuild *pGuild) {
    redis::Connector &conn = GetConnector();
	try {
        base::CalcHighTimeRange time("DBGuildMemberLevel");
        return conn.evalsha(script_guild_member_level_, pGuild->m_nDbSeq).as<uint16_t>();
	} catch (redis::Exception &ex) {
		LOGERROR("'%s' nDbSeq:%d", ex.what(), pGuild->m_nDbSeq);
	}

	return 0;
}



bool GameDb::LoadSkill(CNSPcExt *pc, redis::Reply &result) {
    try {
        for (redis::Reply *iter = result.Begin(); iter + 1 < result.End(); iter += 2) {
            CNSSkill *skill = pc->m_SkillList.Add(pc->m_btRaceRegion, pc->m_btJob, iter[0].convert<uint16_t>(), iter[1].convert<uint8_t>(), 0);
            if (skill) {
                skill->m_nDbSeq = INT_MAX;
                skill->m_btSkillLevelDb = skill->m_btSkillLevel;
                skill->m_wSkillExpDb = skill->m_wSkillExp;
            } else {
                GameUtil::Output("Error: CNSPc::DBSkillLoad{Add(Job=0x%x, SkillId=0x%04x)}\n", pc->m_btJob, iter[0].convert<uint16_t>());
            }
        }
        pc->m_SkillList.SkillDefaultList();
        return true;
    } catch (redis::Exception &ex) {
        LOGERROR("'%s' AliasSeq:%d", ex.what(), pc->m_nAliasSeq);
    }
    return false;
}

bool GameDb::LoadPet(CNSPcExt *pc, redis::Reply &result) {
    const char *buffer = result.GetString();
    size_t size = result.GetLength();

	try {
        if (size > 0) {
            msgpack::unpacked result;
            msgpack::unpack(result, buffer, size);
            msgpack::object obj(result.get());
            if (obj.type != MSGPACK_OBJECT_ARRAY || obj.via.array.size != 6) {
				return false;
			}
            
            pc->m_PetInfo.dwSeq = 0;
            pc->m_PetInfo.btPetKind = obj.via.array.ptr[0].as<uint8_t>();
            pc->m_PetInfo.btLevel = obj.via.array.ptr[1].as<uint8_t>();
            pc->m_PetInfo.btGrade = obj.via.array.ptr[2].as<uint8_t>();
            pc->m_PetInfo.dwExp = obj.via.array.ptr[3].as<uint32_t>();
            pc->m_PetInfo.wSta = obj.via.array.ptr[4].as<uint16_t>();
            if (obj.via.array.ptr[5].type != MSGPACK_OBJECT_STR 
                || obj.via.array.ptr[5].via.str.size > sizeof(pc->m_PetInfo.szPetName) / sizeof(char) - 1)  {
                    throw msgpack::type_error();
            }

            strcpy(pc->m_PetInfo.szPetName, obj.via.array.ptr[5].via.str.ptr);
			
        } else {
            pc->m_PetInfo.dwSeq = 0;
            pc->m_PetInfo.btPetKind = 0;
            pc->m_PetInfo.btLevel = 1;
            pc->m_PetInfo.btGrade = 0;
            pc->m_PetInfo.dwExp = 0;
            pc->m_PetInfo.wSta = 10000;
            memset(pc->m_PetInfo.szPetName, 0, sizeof(pc->m_PetInfo.szPetName));
        }

		return true;
	} catch (msgpack::type_error& e) {
		LOGERROR("convert error '%s' alias seq:%d", e.what(), pc->m_nAliasSeq);
	}

    return false;
}

bool GameDb::LoadSkillBuffArray(CNSPcExt *pc, redis::Reply &result) {
    const char *buffer = result.GetString();
    size_t size = result.GetLength();

	unsigned int time_now = timeGetTime();
	unsigned int unix_time = time(NULL);

	try {
		std::size_t off = 0;

		while (off != size) {
			msgpack::unpacked result;
			msgpack::unpack(result, buffer, size, off);
			msgpack::object obj(result.get());
			if (obj.type != MSGPACK_OBJECT_ARRAY) {
				return false;
			}
 
			if (obj.via.array.size == 2) {
				unsigned short skill_id = obj.via.array.ptr[0].as<uint16_t>();
				unsigned int skill_time = obj.via.array.ptr[1].as<uint32_t>();

				if (skill_time > unix_time) {
					unsigned int last_use_time = time_now + 1000 * (skill_time - unix_time);

					if (time_now + 3600000 * 24 >= last_use_time) {
						if (skill_id >= 0x100) {
							CNSSkill *skill = pc->m_SkillList.Get(skill_id);
							if (skill) {
								skill->m_dwLastUseTime = last_use_time;
							}
						} else {
							pc->m_SkillList.m_dwOverHeatTime[skill_id] = last_use_time;
						}
					} else {
						GameUtil::Output("Error: CoolTime Error - [%u:%04x]", pc->m_nAliasSeq, last_use_time);
					}
				}

			} else if (obj.via.array.size == 5){
				CNSBuff::BUFFTYPE buff_type = static_cast<CNSBuff::BUFFTYPE>(obj.via.array.ptr[0].as<int32_t>());
				unsigned short buff_skill_id = obj.via.array.ptr[1].as<uint16_t>();
				unsigned char buff_level = obj.via.array.ptr[2].as<uint8_t>();
				unsigned short buff_value = obj.via.array.ptr[3].as<uint16_t>();
				unsigned short buff_duration = obj.via.array.ptr[4].as<uint16_t>();

				if (buff_type == CNSBuff::BuffType_ExpPenalty) {
					unsigned int end_time = buff_duration | buff_value << 16;
					if (unix_time >= end_time) {
						continue;
					} else {
						buff_duration = end_time - unix_time;
						buff_value = 0;
					}
				}

				pc->m_BuffList.Add(pc->m_dwObjectId, buff_type, buff_skill_id, buff_level, buff_value, buff_duration, time_now, 0);

			} else {
				return false;
			}
		}

		return true;
	} catch (msgpack::type_error& e) {
        LOGERROR("convert error '%s' alias seq:%d", e.what(), pc->m_nAliasSeq);
	}


	return false;
}
bool GameDb::LoadTeleport(CNSPcExt *pc, redis::Reply &result) {
    const char *buffer = result.GetString();
    size_t size = result.GetLength();

    pc->m_TeleportList.Clear();
    try {
        std::size_t off = 0;
        while (off != size) {
            msgpack::unpacked result;
            msgpack::unpack(result, buffer, size, off);
            msgpack::object obj(result.get());
            if (obj.type != MSGPACK_OBJECT_ARRAY || obj.via.array.size != 4) {
				return false;
			}

            CNSPcTeleportList::Teleport temp;
            temp.nDbSeq = -1;

            if (obj.via.array.ptr[0].type != MSGPACK_OBJECT_STR 
                || obj.via.array.ptr[0].via.str.size > sizeof(temp.szName) / sizeof(char) - 1)  {
                    throw msgpack::type_error();
            }
            strcpy(temp.szName, obj.via.array.ptr[0].via.str.ptr);

            temp.btRegion = obj.via.array.ptr[1].as<uint8_t>();
            temp.wPosX = obj.via.array.ptr[2].as<uint16_t>();
            temp.wPosY = obj.via.array.ptr[3].as<uint16_t>();

            pc->m_TeleportList.Add(temp);
        }

        return true;
    } catch (msgpack::type_error& e) {
        LOGERROR("convert error '%s' alias seq:%d", e.what(), pc->m_nAliasSeq);
    }

    return false;
}

bool GameDb::LoadItem(CNSPcExt *pc, redis::Reply &result) {
    try {
        for (redis::Reply *iter = result.Begin(); iter != result.End(); ++iter) {
            CNSObject::Owner<CNSItem> item(CNSItemExt::New());
            item->SetOwner(pc->m_szUserAlias);

            //AliasSeq = (*iter)[0].convert<int32_t>();
            //UserSeq = (*iter)[1].convert<int32_t>();
            item->m_nSeq = (*iter)[2].convert<int32_t>();
            item->m_wItemId = (*iter)[3].convert<uint16_t>();
            (*iter)[4].assgin(item->m_szItemName, 25);
            item->m_wPos = (*iter)[5].convert<uint16_t>();
            item->m_btRare = (*iter)[6].convert<uint8_t>();
            item->m_btCount = (*iter)[7].convert<uint8_t>();
            item->m_wAttackMinDamage = (*iter)[8].convert<uint16_t>();
            item->m_wAttackMaxDamage = (*iter)[9].convert<uint16_t>();
            item->m_btDefenseDamage = (*iter)[10].convert<uint8_t>();
            item->m_nUniqueSeq = (*iter)[11].convert<int32_t>();
            (*iter)[12].assgin_raw(item->m_Option, sizeof(item->m_Option));

            CNSItem *item_params = CNSItemParams::GetInstance()->GetObjectA(item->m_wItemId);
            if (item_params == NULL) {
                LOGERROR("invailed itemid(%d)", item->m_wItemId);
                return false;
            }

            item->m_wPosDb = item->m_wPos;
            item->m_btCountDb = item->m_btCount;
            item->m_wType = item_params->m_wType;
            item->m_btKind = item_params->m_btKind;
            item->m_dwGold = 0;
            item->m_btLimitLevel = item_params->m_btLimitLevel;
            item->m_btLimitRace = item_params->m_btLimitRace;
            memcpy(item->m_btLimitJob, item_params->m_btLimitJob, sizeof(item->m_btLimitJob));
            item->m_btEquipmentPart = item_params->m_btEquipmentPart;
            item->m_btAttackDistance = item_params->m_btAttackDistance;
            item->m_btAttackSpeed = item_params->m_btAttackSpeed;
            item->m_szDbDescription = item_params->m_szDbDescription;
            item->m_wQuestId = item_params->m_wQuestId;

            if (item->m_wPos > 0 
                && item->m_wPos < CNSEquipment::EquipType_End 
                && !pc->m_Equip.Get((CNSEquipment::EQUIPMENTTYPE)item->m_wPos)) {
                pc->m_Equip.Set((CNSEquipment::EQUIPMENTTYPE)item->m_wPos, item);
            } else if (item->m_wPos < 256) {
                item->m_wPos = 0;
                pc->m_Inven._Add(item);
            } else {
                pc->m_Inven._Add(item);
            }

            unsigned short start_used1 = item->GetOptionValue(CNSItem::OptionType_Date_StartUsed1);
            if (start_used1) {
                item->AddPremiumItemBuff(pc);
            }
        }

        reinterpret_cast<CNSInventoryExt&>(pc->m_Inven).SortPos();
        return true;
    } catch (redis::Exception &ex) {
        LOGERROR("'%s' AliasSeq:%d", ex.what(), pc->m_nAliasSeq);
    }

    return false;
}


bool GameDb::LoadQuest(CNSPcExt *pc, redis::Reply &result) {
    try {
        pc->m_QuestList.Clear();
        for (redis::Reply *iter = result.Begin(); iter != result.End(); ++iter) {
            try {
                CNSQuestExt::QuestData data;
                msgpack::unpacked upk;
                msgpack::unpack(upk, iter->GetString(), iter->GetLength());
                upk.get().convert(data);

                CNSQuest *pQuest = static_cast<CNSQuestListExt&>(pc->m_QuestList).AddQuest(data);
                if (pQuest == NULL) {
                    LOGERROR("Error: CNSPc::DBQuestLoad{Add(AliasSeq:%d QuestId=0x%04x)}\n", pc->m_nAliasSeq, data.wQuestId);
                    return false;
                }

                pQuest->m_btCompletedDb = pQuest->m_btCompleted;
                pQuest->m_btStepDb = pQuest->m_btStep;
                pQuest->m_btCheckCountDb = pQuest->m_btCheckCount;
                pQuest->m_btPointDb = pQuest->m_btPoint;
            } catch (msgpack::type_error& e) {
                LOGERROR("unpack quest error '%s' alias seq:%d", e.what(), pc->m_nAliasSeq);
                return false;
            }
        }

        return true;
    } catch (redis::Exception &ex) {
        LOGERROR("'%s' AliasSeq:%d", ex.what(), pc->m_nAliasSeq);
    }

    return false;
}
bool GameDb::LoadFriend(CNSPcExt *pc, redis::Reply &result) {
    try {
        char target_useralias[25];

        pc->m_FriendList.Clear();
        for (redis::Reply *iter = result.Begin(); iter != result.End(); ++iter) {
            int target_seq = (*iter)[0].convert<int32_t>();
            (*iter)[1].assgin(target_useralias, sizeof(target_useralias));

            if (!pc->m_FriendList.Add(target_seq, target_useralias)) {
                LOGERROR("Add failed(%d, %s)", pc->m_nAliasSeq, target_useralias);
            }
        }

        return true;
    } catch (redis::Exception &ex) {
        LOGERROR("'%s' AliasSeq:%d", ex.what(), pc->m_nAliasSeq);
    }

    return false;
}
bool GameDb::LoadTitle(CNSPcExt *pc, redis::Reply &result) {
    pc->m_TitleList.Clear();
    try {
        for (redis::Reply *iter = result.Begin(); iter != result.End(); ++iter) {
            if (!pc->m_TitleList.Add((*iter).convert<uint32_t>())) {
                LOGERROR("CNSPcTitleList::DbLoad{Add(%d,%d)}", pc->m_nAliasSeq, (*iter).convert<uint32_t>());
                return false;
            }
        }

        if (pc->m_wTitleId) {
            if (!pc->m_TitleList.Select(pc->m_wTitleId)) {
                pc->m_wTitleId = 0;
            }
        }

        return true;
    } catch (redis::Exception &ex) {
        LOGERROR("'%s' AliasSeq:%d", ex.what(), pc->m_nAliasSeq);
    }
    return false;
}
bool GameDb::LoadTameMob(CNSPcExt *pc, redis::Reply &result) {
    const char *buffer = result.GetString();
    size_t size = result.GetLength();

	try {
        if (size > 0) {
            msgpack::unpacked result;
            msgpack::unpack(result, buffer, size);
            msgpack::object obj(result.get());
            if (obj.type != MSGPACK_OBJECT_ARRAY || obj.via.array.size != 4) {
				return false;
			}
            
            pc->m_TameState.wNpcId = obj.via.array.ptr[0].as<uint16_t>();
            pc->m_TameState.wHp = obj.via.array.ptr[1].as<uint16_t>();
            pc->m_TameState.wSta = obj.via.array.ptr[2].as<uint16_t>();
            if (obj.via.array.ptr[3].type != MSGPACK_OBJECT_STR 
                || obj.via.array.ptr[3].via.str.size > sizeof(pc->m_TameState.szNpcName) / sizeof(char) - 1)  {
                    throw msgpack::type_error();
            }

            strcpy(pc->m_TameState.szNpcName, obj.via.array.ptr[3].via.str.ptr);
			
        } else {
            memset(&pc->m_TameState, 0, sizeof(pc->m_TameState));
        }

		return true;
	} catch (msgpack::type_error& e) {
		LOGERROR("convert error '%s' alias seq:%d", e.what(), pc->m_nAliasSeq);
	}

    return false;
}
void GameDb::PackPet(CNSPcExt *pc, msgpack::sbuffer& buffer) {
    buffer.clear();
	msgpack::packer<msgpack::sbuffer> pk(buffer);
    pk.pack_array(6);
    pk.pack_uint8(pc->m_PetInfo.btPetKind);
    pk.pack_uint8(pc->m_PetInfo.btLevel);
    pk.pack_uint8(pc->m_PetInfo.btGrade);
    pk.pack_uint32(pc->m_PetInfo.dwExp);
    pk.pack_uint16(pc->m_PetInfo.wSta);
    pk.pack(pc->m_PetInfo.szPetName);
}
void GameDb::PackSkillBuffArray(CNSPcExt *pc, msgpack::sbuffer& buffer) {
    buffer.clear();
	msgpack::packer<msgpack::sbuffer> pk(buffer);

	unsigned int time_now = timeGetTime();
	unsigned int unix_time = time(NULL);

	for (int i = 0; i < sizeof(pc->m_SkillList.m_dwOverHeatTime) / sizeof(unsigned int); ++i) {
		if (time_now + 1000 < pc->m_SkillList.m_dwOverHeatTime[i]) {
			pk.pack_array(2);
			pk.pack_uint16(i);
			pk.pack_uint32(unix_time + (pc->m_SkillList.m_dwOverHeatTime[i] - time_now) / 0x3E8);
		}
	}

	for (unsigned int i = 0; i < pc->m_SkillList.GetMaxList(); ++i) {
		CNSSkill &skill = pc->m_SkillList.GetSkill(i);
		if (skill.m_bUsed) {
			if (!skill.IsSteamAbility()) {
				if (time_now + 1000 < skill.m_dwLastUseTime && skill.m_wSkillId != 0xFFFF) {
					pk.pack_array(2);
					pk.pack_uint16(skill.m_wSkillId);
					pk.pack_uint32(unix_time + (skill.m_dwLastUseTime - time_now) / 0x3E8);
				}
			}
		}
	}

	for (int i = 0; i < sizeof(pc->m_BuffList.m_buffList) / sizeof(CNSBuff); ++i) {
		if (pc->m_BuffList.m_buffList[i].m_buffType 
			&& pc->m_BuffList.m_buffList[i].m_buffType != CNSBuff::BuffType_End) {

				if (pc->m_BuffList.m_buffList[i].m_wSkillId == 0xE000
					|| reinterpret_cast<CNSBuffExt &>(pc->m_BuffList.m_buffList[i]).IsCanSave()) {
						unsigned int remain_time = pc->m_BuffList.m_buffList[i].GetRemainTime();
						if (remain_time) {
							pk.pack_array(5);
							pk.pack_int32(pc->m_BuffList.m_buffList[i].m_buffType);
							pk.pack_uint16(pc->m_BuffList.m_buffList[i].m_wSkillId);
							pk.pack_uint8(pc->m_BuffList.m_buffList[i].m_btLevel);

							if (pc->m_BuffList.m_buffList[i].m_buffType == CNSBuff::BuffType_ExpPenalty) {
								pk.pack_uint16((remain_time + unix_time) >> 16);
								pk.pack_uint16(remain_time + unix_time);
							} else {
								pk.pack_uint16(pc->m_BuffList.m_buffList[i].m_wValue);

								if (pc->m_BuffList.m_buffList[i].m_wDurationTime == 0xFFFF) {
									pk.pack_uint16(0xFFFF);
								} else {
									pk.pack_uint16(remain_time);
								}
							}
						}
				}
		}
	}
}

void GameDb::PackTameMob(CNSPcExt *pc, msgpack::sbuffer& buffer) {
    buffer.clear();
    if (pc->m_TameState.wNpcId) {
        msgpack::packer<msgpack::sbuffer> pk(buffer);
        pk.pack_array(4);
        pk.pack_uint16(pc->m_TameState.wNpcId);
        pk.pack_uint16(static_cast<unsigned short>(pc->m_TameState.wHp));
        pk.pack_uint16(static_cast<unsigned short>(pc->m_TameState.wSta));
        pk.pack(pc->m_TameState.szNpcName);
    }
}