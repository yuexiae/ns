#include "server/server_pch.h"

#include "server/ext/ns_guild_ext.h"
#include "server/db/game_db.h"

void CNSGuildExt::LoadGuildBase() {
    static NSPOINT2 guildStoneCell[2][20] = {
        { NSPOINT2(28854, 30170), NSPOINT2(27651, 30162), NSPOINT2(27399, 31171), NSPOINT2(27398, 29171), NSPOINT2(26568, 29000),
        NSPOINT2(25819, 29167), NSPOINT2(25264, 29122), NSPOINT2(26613, 31278), NSPOINT2(26017, 31365), NSPOINT2(25568, 31299) },
        
        { NSPOINT2(31422, 6240), NSPOINT2(30521, 6529), NSPOINT2(31021, 5969), NSPOINT2(29433, 5239), NSPOINT2(29206, 5857),
        NSPOINT2(29709, 5598), NSPOINT2(29034, 6863), NSPOINT2(29695, 7154), NSPOINT2(30554, 7113), NSPOINT2(31103, 6742) }
    };

    CNSWorldManager *worldManager = CNSWorldManager::GetInstance();


    if (worldManager->m_btRegion != RegionType_Mystery && worldManager->m_btRegion != RegionType_Technic) {
        return;
    }

    std::vector<int> guildRankList;
    if (!GameDb::GetSingleton()->DBGuildRankLoad(worldManager->m_btRegion, guildRankList)) {
        LOGERROR("load guild rank info error(region:%d)", worldManager->m_btRegion);
        return;
    }

    unsigned int totalCount = 0;
    for (int i = 1; i <= 10; ++i)  {
        //stone
        CNSObject::Owner<CNSNpcExt> stoneNpc = CNSNpcManagerExt::GetInstance()->CallMobExt(5284 + worldManager->m_btRegion - 1, guildStoneCell[worldManager->m_btRegion - 1][i - 1], 0);
        if (stoneNpc) {
            stoneNpc->m_BuffList.Add(
                stoneNpc->m_dwObjectId,
                CNSBuff::BuffType_Summon,
                0,
                1,
                0,
                0xFFFF,
                timeGetTime(),
                0);

            stoneNpc->m_nGuildBaseSeq = guildRankList[i - 1];

            ++totalCount;
        }

        //base manager
        BaseCell baseCell;
        if (GetGuildBaseCell(worldManager->m_btRegion, i, baseCell)) {
            CNSObject::Owner<CNSNpcExt> baseNpc = CNSNpcManagerExt::GetInstance()->CallMobExt(5286 + worldManager->m_btRegion - 1,
                baseCell.npc,
                NSPOINT2::GetAngle(baseCell.enter, baseCell.npc));

            if (baseNpc) {
                baseNpc->m_BuffList.Add(
                    baseNpc->m_dwObjectId,
                    CNSBuff::BuffType_Summon,
                    0,
                    1,
                    0,
                    0xFFFF,
                    timeGetTime(),
                    0);

                baseNpc->m_nGuildBaseSeq = guildRankList[i - 1];

                ++totalCount;
            }
        }

        if (guildRankList[i - 1]) {
            Owner<CNSGuild> guild = CNSPcManager::GetInstance()->GuildFind(guildRankList[i - 1]);
            if (!guild) {
                GameDb::GetSingleton()->DBGuildLoad(guildRankList[i - 1]);
            }
        }
    }

    GameUtil::Output("GuildNpc Total = %u", totalCount);

}

bool CNSGuildExt::GetGuildBaseCell(unsigned char btRegion, int nRank, BaseCell& cell) {
	if (btRegion == 1) {
		switch (nRank) {
		case 1:
			///debug warp 11000 4820  11-4
			cell.enter.x = 11000;
			cell.enter.y = 4820;
			cell.npc.x = 10772;
			cell.npc.y = 5153;
			cell.mob.x = 10999;
			cell.mob.y = 5078;
			break;
		case 2:
			///debug warp 8240 7595   8-7
			cell.enter.x = 8240;
			cell.enter.y = 7595;
			cell.npc.x = 8239;
			cell.npc.y = 7884;
			cell.mob.x = 8238;
			cell.mob.y = 7771;
			break;
		case 3:
			///debug warp 9720 7600   9-7
			cell.enter.x = 9720;
			cell.enter.y = 7600;
			cell.npc.x = 9718;
			cell.npc.y = 7887;
			cell.mob.x = 9724;
			cell.mob.y = 7749;
			break;
		case 4:
			///debug warp 11200 7600  11-7
			cell.enter.x = 11200;
			cell.enter.y = 7600;
			cell.npc.x = 11200;
			cell.npc.y = 7889;
			cell.mob.x = 11198;
			cell.mob.y = 7772;
			break;
		case 5:
			///debug warp 8300 6290   8-6
			cell.enter.x = 8300;
			cell.enter.y = 6290;
			cell.npc.x = 8040;
			cell.npc.y = 6332;
			cell.mob.x = 8239;
			cell.mob.y = 6455;
			break;
		case 6:
			///debug warp 9500 6290   9-6
			cell.enter.x = 9500;
			cell.enter.y = 6290;
			cell.npc.x = 9238;
			cell.npc.y = 6333;
			cell.mob.x = 9435;
			cell.mob.y = 6464;
			break;
		case 7:
			///debug warp 10740 6290  10-6
			cell.enter.x = 10740;
			cell.enter.y = 6290;
			cell.npc.x = 10478;
			cell.npc.y = 6332;
			cell.mob.x = 10677;
			cell.mob.y = 6467;
			break;
		case 8:
			///debug warp 8300 5005   8-5
			cell.enter.x = 8300;
			cell.enter.y = 5005;
			cell.npc.x = 8038;
			cell.npc.y = 5053;
			cell.mob.x = 8238;
			cell.mob.y = 5184;
			break;
		case 9:
			///debug warp 9500 5005   9-5
			cell.enter.x = 9500;
			cell.enter.y = 5005;
			cell.npc.x = 9238;
			cell.npc.y = 5049;
			cell.mob.x = 9442;
			cell.mob.y = 5178;
			break;
		case 10:
			///debug warp 11942 6290  11-7
			cell.enter.x = 11942;
			cell.enter.y = 6290;
			cell.npc.x = 11678;
			cell.npc.y = 6331;
			cell.mob.x = 11878;
			cell.mob.y = 6460;
			break;
		default:
			cell.enter.x = 0;
			cell.enter.y = 0;
			cell.npc.x = 0;
			cell.npc.y = 0;
			cell.mob.x = 0;
			cell.mob.y = 0;
			return false;
		}
	} else if (btRegion == 2) {
		switch (nRank)
		{
		case 1:
			///debug warp 19035 28930     19-28
			cell.enter.x = 19035;
			cell.enter.y = 28930;
			cell.npc.x = 18822;
			cell.npc.y = 29293;
			cell.mob.x = 19037;
			cell.mob.y = 29199;
			break;
		case 2:
			///debug warp 19200 31600     19-31
			cell.enter.x = 19200;
			cell.enter.y = 31600;
			cell.npc.x = 19201;
			cell.npc.y = 31885;
			cell.mob.x = 19199;
			cell.mob.y = 31773;
			break;
		case 3:
			///debug warp 17720 31600     17-31
			cell.enter.x = 17720;
			cell.enter.y = 31600;
			cell.npc.x = 17718;
			cell.npc.y = 31886;
			cell.mob.x = 17719;
			cell.mob.y = 31770;
			break;
		case 4:
			///debug warp 16240 31600    16-31
			cell.enter.x = 16240;
			cell.enter.y = 31600;
			cell.npc.x = 16243;
			cell.npc.y = 31882;
			cell.mob.x = 16239;
			cell.mob.y = 31766;
			break;
		case 5:
			///debug warp 19940 30290     19-30
			cell.enter.x = 19940;
			cell.enter.y = 30290;
			cell.npc.x = 19684;
			cell.npc.y = 30334;
			cell.mob.x = 19878;
			cell.mob.y = 30463;
			break;
		case 6:
			///debug warp 17500 29010     17-29
			cell.enter.x = 17500;
			cell.enter.y = 29010;
			cell.npc.x = 17237;
			cell.npc.y = 29055;
			cell.mob.x = 17430;
			cell.mob.y = 29184;
			break;
		case 7:
			///debug warp 17500 30290     17-30
			cell.enter.x = 17500;
			cell.enter.y = 30290;
			cell.npc.x = 17240;
			cell.npc.y = 30332;
			cell.mob.x = 17438;
			cell.mob.y = 30460;
			break;
		case 8:
			///debug warp 16300 29010    16-29
			cell.enter.x = 16300;
			cell.enter.y = 29010;
			cell.npc.x = 16040;
			cell.npc.y = 29054;
			cell.mob.x = 16241;
			cell.mob.y = 29186;
			break;
		case 9:
			///debug warp 16300 30290    16-30
			cell.enter.x = 16300;
			cell.enter.y = 30290;
			cell.npc.x = 16037;
			cell.npc.y = 30333;
			cell.mob.x = 16239;
			cell.mob.y = 30466;
			break;
		case 10:
			///debug warp 18740 30290     18-30
			cell.enter.x = 18740;
			cell.enter.y = 30290;
			cell.npc.x = 18478;
			cell.npc.y = 30331;
			cell.mob.x = 18673;
			cell.mob.y = 30462;
			break;
		default:
			cell.enter.x = 0;
			cell.enter.y = 0;
			cell.npc.x = 0;
			cell.npc.y = 0;
			cell.mob.x = 0;
			cell.mob.y = 0;
			return false;
		}
	} else {
		cell.enter.x = 0;
		cell.enter.y = 0;
		cell.npc.x = 0;
		cell.npc.y = 0;
		cell.mob.x = 0;
		cell.mob.y = 0;
		return false;
	}

	return true;
}
