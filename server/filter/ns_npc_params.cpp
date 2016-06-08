#include "server/server_pch.h"

#include "server/ext/ns_ext.h"
#include "server/game_config.h"
#include "base/util.h"

class CNSNpcParamsFilter : public CNSNpcParamsExt {
public:
    BOOL LoadNpcFilter() {
        if (!GameConfig::GetSingleton()->IsLoadNpcData()) {
            GameUtil::Output("NpcParams IsLoadNpcData = false");
            return TRUE;
        }

        CNSObject::Owner<CNSNpc> owner_npc(CNSNpcExt::New());
        if (owner_npc == NULL) {
            return FALSE;
        }

        COdbcBindColumn odbc(CNSDbManager::GetInstance()->GetDb());

        try {
            long len;
            odbc.BindUSmallInt(&owner_npc->m_wNpcId, &len);
            odbc.BindString(owner_npc->m_szNpcName, 25, &len);
            odbc.BindTinyInt(&owner_npc->m_btNpcGroup, &len);
            odbc.BindTinyInt(&owner_npc->m_btLevel, &len);
            odbc.BindInt(&owner_npc->m_dwExp, &len);
            odbc.BindUSmallInt(&owner_npc->m_wNs, &len);
            odbc.BindInt(&owner_npc->m_dwMaxHp, &len);
            odbc.BindUSmallInt(&owner_npc->m_BasicParam.btStr, &len);
            odbc.BindUSmallInt(&owner_npc->m_BasicParam.btCon, &len);
            odbc.BindUSmallInt(&owner_npc->m_BasicParam.btDex, &len);
            odbc.BindUSmallInt(&owner_npc->m_BasicParam.btInt, &len);
            odbc.BindUSmallInt(&owner_npc->m_wRs, &len);
            odbc.BindUSmallInt(&owner_npc->m_wSight, &len);
            odbc.BindTinyInt(&owner_npc->m_btSize, &len);
            odbc.BindUSmallInt(&owner_npc->m_wAttackMinDamage, &len);
            odbc.BindUSmallInt(&owner_npc->m_wAttackMaxDamage, &len);
            odbc.BindTinyInt(&owner_npc->m_btAttackSpeed, &len);
            odbc.BindUSmallInt(&owner_npc->m_wAttackDistance, &len);
            odbc.BindUSmallInt(&owner_npc->m_wDefenseDamage, &len);
            odbc.BindTinyInt(&owner_npc->m_btAttackType, &len);
            odbc.BindTinyInt(&owner_npc->m_btMoveType, &len);
            odbc.BindTinyInt(&owner_npc->m_btMoveSpeed, &len);
            odbc.BindTinyInt(&owner_npc->m_btSkillGroup, &len);
            odbc.BindUSmallInt(&owner_npc->m_wLimitMoveScope, &len);
            odbc.BindTinyInt(&owner_npc->m_btAttribute, &len);
            odbc.BindTinyInt(&owner_npc->m_btAttributeLevel, &len);

            odbc.Execute("SELECT NpcId, NpcName, NpcGroup, Level, Exp, Ns, Hp, Str, Con, Dex, Int,"\
                "Rs, Sight, Size, AttackMinDamage, AttackMaxDamage, AttackSpeed, AttackDistance,"\
                "DefenseDamage, AttackType, MoveType, MoveSpeed, SkillGroup, LimitMoveScope, Attribute,"\
                "AttributeLevel FROM NpcParams2 ORDER BY NpcId");

            while (odbc.Fetch()) {
                CNSNpc *pNpc = CNSNpcExt::New();
                if (pNpc) {
                    *pNpc = *owner_npc;
                    this->m_mapNpc.insert(std::make_pair(pNpc->m_wNpcId, pNpc));
                }
            }

            GameUtil::Output("NpcParams Total = %u", this->m_mapNpc.size());
            return TRUE;
        } catch (SteamEngine::Win32::System::CException& e) {
			LOGERROR("sqlexec error(%s)", e.GetMessageA());
		}

        return FALSE;
    }

    BOOL LoadNpcArrangeFileFilter() {
        if (!GameConfig::GetSingleton()->IsLoadNpcData()) {
            GameUtil::Output("NpcArrageParams IsLoadNpcData = false");
            return TRUE;
        }

        CNSWorldManager *pWorldManager = CNSWorldManager::GetInstance();
        COdbcBindColumn odbc(CNSDbManager::GetInstance()->GetDb());

        try {
            CNSNpcParams::_NpcArrange npcArrange;
            memset(&npcArrange, 0, sizeof(CNSNpcParams::_NpcArrange));

            long len;
            odbc.BindInt(&npcArrange.nSeq, &len);
            odbc.BindUSmallInt(&npcArrange.wNpcId, &len);
            odbc.BindTinyInt(&npcArrange.btNpcCount, &len);
            odbc.BindTinyInt(&npcArrange.btRegion, &len);
            odbc.BindUSmallInt(&npcArrange.cellPos.x, &len);
            odbc.BindUSmallInt(&npcArrange.cellPos.y, &len);
            odbc.BindUSmallInt(&npcArrange.wScope, &len);
            odbc.BindUSmallInt(&npcArrange.wRespawnSecond, &len);
            odbc.BindUSmallInt(&npcArrange.wAngle, &len);
            odbc.BindUSmallInt(&npcArrange.wLimitMoveScope, &len);
            odbc.BindUSmallInt(&npcArrange.wPathId, &len);

            odbc.Execute("SELECT [Seq], [NpcId], [NpcCount], [Region], [CellX], [CellY], [Scope], "\
                "[RespawnSecond], [Angle], [LimitMoveScope], [PathId] "\
                "FROM [NpcArrageParams]");

            unsigned long count = 0;
            while (odbc.Fetch()) {
                if (!pWorldManager->m_btRegion
                    || pWorldManager->m_btRegion >= 80
                    || pWorldManager->m_btRegion == npcArrange.btRegion) {
                        CNSNpcParams::_NpcArrange *insert = new CNSNpcParams::_NpcArrange();
                        memcpy(insert, &npcArrange, sizeof(CNSNpcParams::_NpcArrange));
                        this->m_mapNpcArrange.insert(std::make_pair(count, insert));
                        ++count;
                }
            }

            GameUtil::Output("NpcArrageParams Total = %u", this->m_mapNpcArrange.size());
            return TRUE;
        } catch (SteamEngine::Win32::System::CException& e) {
			LOGERROR("sqlexec error(%s)", e.GetMessageA());
		}

        return FALSE;
    }

    BOOL LoadNpcDataFilter() {
        if (!GameConfig::GetSingleton()->IsLoadNpcData()) {
            GameUtil::Output("NpcDataParams IsLoadNpcData = false");
            return TRUE;
        }

        CNSNpcParams::_NpcScript script;
        for (std::map<unsigned short, CNSNpc *>::iterator iter = this->m_mapNpc.begin();
            iter != this->m_mapNpc.end();
            ++iter) {
                if (ReadNpcScript(iter->first, script))	{
                    CNSNpcParams::_NpcScript *insert = new CNSNpcParams::_NpcScript();
                    memcpy(insert, &script, sizeof(CNSNpcParams::_NpcScript));
                    this->m_mapNpcScript.insert(std::make_pair(iter->first, insert));
                }
        }

        GameUtil::Output("NpcDataParams Total = %u", this->m_mapNpcScript.size());
        return TRUE;
    }

};

bool CNSNpcParamsFilterInit() {
    return CNSNpcParams::_PatchLoadNpc(&CNSNpcParamsFilter::LoadNpcFilter)
        && CNSNpcParams::_PatchLoadNpcArrangeFile(&CNSNpcParamsFilter::LoadNpcArrangeFileFilter)
        && CNSNpcParams::_PatchLoadNpcData(&CNSNpcParamsFilter::LoadNpcDataFilter);
}
