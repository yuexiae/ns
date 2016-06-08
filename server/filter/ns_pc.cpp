#include "server/server_pch.h"

#include "server/ext/ns_ext.h"
#include "server/db/auth_db.h"
#include "server/db/game_db.h"
#include "server/db/log_db.h"
#include "base/util.h"

class CNSPcFilter : public CNSPcExt {
public:
    static CNSPc::_Invoke invoke_;

    CNSPc& ConstructorFilter(CNSSessionPc *pSession) {
        (this->*invoke_.Constructor)(pSession);
        this->CNSPcExtImpl::CNSPcExtImpl(this);
        return *this;
    }

    void DestructorFilter() {
        this->CNSPcExtImpl::~CNSPcExtImpl();
        (this->*invoke_.Destructor)();
    }

    void ClearFilter(int bFullClear) {
        (this->*invoke_.Clear)(bFullClear);
        this->ClearExt(bFullClear);
    }

    

    BOOL OnGameEnterFilter() {
        if (this->m_pSession->GetSessionLevel() != CNSSessionPc::SessionLevel_Session || this->DBLoad()) {
            this->m_dwDeadTime = timeGetTime();

            this->m_pSession->SetSessionLevel(CNSSessionPc::SessionLevel_Game);
            this->Login();

            this->SetCellDest(this->m_cell);

            this->m_BuffList.Add(this->m_dwObjectId, CNSBuff::BuffType_Clarity, 0x60Bu, 0, 0, 0xFu, timeGetTime(), 0);

            if (!strncmp(this->m_szUserAlias, "[GM]", 4u)) {
                this->m_BuffList.Add(this->m_dwObjectId, CNSBuff::BuffType_ClarityEx, 0, 1, 0, 0xFFFFu, 0, 0);
            }

            this->OnEnter();//((void (__thiscall *)(CNSPc *))this->vfptr[1].__vecDelDtor)(this);

            this->PetLoad();
            this->SendStatusMessage(1);
            this->SendItemListMessage();
            this->SendSkillListMessage();
            this->SendQuestListMessage();
            this->SendQuickBarListMessage();
            this->SendTitleListMessage();

            if ( CSingleton<CNSWorldManager>::GetInstance()->IsMainServer(this->m_btRealm)) {
                this->SendFriendListMessage(0);
            }

            this->SendEnterMessage(1);//this->vfptr[20].__vecDelDtor((CNSObject *)this, 1u);
            this->SendPetNotifyMessage();
            this->SendStartMessage();

            this->SummonLoad();

            if (this->m_btLevel == 1) {
                CPacket packet(0x3501u);
                packet.WriteString("notice");
                packet.Format("%s\n%s", CSingleton<CNSMsgParams>::GetInstance()->GetObjectA(NS_MSG_NOTICE_LEVEL_01_01),
                    CSingleton<CNSMsgParams>::GetInstance()->GetObjectA(NS_MSG_NOTICE_LEVEL_01_02));
                this->SendMessageA(packet, 1);
            }
            return TRUE;
        } else {
            return FALSE;
        }
    }
    void ResetFilter(int bFullReset) {
        /*(this->*invoke_.Reset)(bFullReset);

        char *data = new char[sizeof(CNSPc)];
        memcpy(data, this, sizeof(CNSPc));*/

        this->ResetNew(bFullReset);

        /*if (memcmp(data, this, sizeof(CNSPc)) != 0) {
            GameUtil::Output("ERROR:memcmp(data, this, sizeof(CNSPc) != 0");
        } else {
            GameUtil::Output("INFO:memcmp(data, this, sizeof(CNSPc) == 0");
        }
        delete []data;*/
    }

    void PetDeleteAllFilter(int bLogoff) {
        for (int i = 0; i < 4; ++i){
            if ((bLogoff || i) && (bLogoff || i != PetType_Block) && this->m_dwPetObjectIdArray[i])  {
                CNSObject::Owner<CNSNpc> pNpc = CNSObjectManagerExt::GetInstance()->Get<CNSNpc>(this->m_dwPetObjectIdArray[i]);
                if (pNpc) {
                    CNSBuff *pBuff = pNpc->m_BuffList.GetBuff(CNSBuff::BuffType_Summon);
                    if (bLogoff && i == PetType_Summon && pBuff) {
                        m_SummonState.clear();
                        msgpack::packer<msgpack::sbuffer> pk(&m_SummonState);
                        pk.pack_array(10);
                        pk.pack_uint16(pNpc->m_wNpcId);
                        pk.pack_uint16(pBuff->m_wSkillId);
                        pk.pack_uint8(pBuff->m_btLevel);
                        pk.pack_uint16(static_cast<unsigned short>(pBuff->GetRemainTime()));
                        pk.pack_uint16(static_cast<unsigned short>(pNpc->m_fHp));
                        pk.pack_uint16(static_cast<unsigned short>(pNpc->m_fSta));

                        CNSBuff *pTendmelee = pNpc->m_BuffList.GetBuff(CNSBuff::BuffType_TendMelee);
                        if (pTendmelee) {
                            pk.pack_uint16(pTendmelee->m_wSkillId);
                            pk.pack_uint8(pTendmelee->m_btLevel);
                        } else {
                            pk.pack_uint16(0);
                            pk.pack_uint8(0);
                        }

                        CNSBuff *Tendrange = pNpc->m_BuffList.GetBuff(CNSBuff::BuffType_TendRange);
                        if (Tendrange) {
                            pk.pack_uint16(Tendrange->m_wSkillId);
                            pk.pack_uint8(Tendrange->m_btLevel);
                        } else {
                            pk.pack_uint16(0);
                            pk.pack_uint8(0);
                        }
                    }

                    this->SendPetLeaveMessage(this->m_dwPetObjectIdArray[i]);
                    pNpc->PetDelete();
                }
                this->m_dwPetObjectIdArray[i] = 0;
            }
        }
    }

    CNSNpc * PetAddFilter(PETTYPE PetType, unsigned short wNpcId, NSPOINT2& cell, unsigned short wSkillId, unsigned char btSkillLevel,
        unsigned short wDurationTime, unsigned long dwTime, char *szPetName, unsigned short wHp, unsigned short wSta, unsigned char btPetGrade) {
        CNSNpc *pNpc = (this->*invoke_.PetAdd)(PetType, wNpcId, cell, wSkillId, btSkillLevel, wDurationTime, dwTime, szPetName, wHp, wSta, btPetGrade);

        if (pNpc && (PetType == PetType_Tame || PetType == PetType_Summon)) {
            pNpc->m_btLevel = this->m_btLevel;
            pNpc->SendEnterMessage(0);
        }

        return pNpc;
    }
    unsigned long AddRealmPointFilter(unsigned long dwRealmPoint, CNSCharacter *pTarget) {
        this->m_dwRealmPoint += dwRealmPoint;
        this->SendRealmPointChangeMessage();
        this->SendSystemMessage(NS_MSG_REALMPOINT, dwRealmPoint);
        LogDb::GetSingleton()->DBRealmLog(this, pTarget, dwRealmPoint);
        return dwRealmPoint;
    }

    BOOL GiveRealmPointFilter(unsigned long dwRealmPoint) {
        if (this->m_dwRealmPoint >= dwRealmPoint) {
            this->m_dwRealmPoint -= dwRealmPoint;
            this->SendRealmPointChangeMessage();
            LogDb::GetSingleton()->DBRealmLog(this, NULL, dwRealmPoint);
            return TRUE;
        } else {
            return FALSE;
        }
    }

    BOOL SkillScrollFilter(unsigned long dwObjectId, unsigned char btOpiton) {
        CNSItem *pItem = this->m_Inven.FindObject(dwObjectId);
        if (pItem == NULL) {
            return FALSE;
        }

        switch (pItem->m_wItemId) {
        case 41740: //´ï¿ËÏ¿ÒÆ¶¯¾íÖá
            if (!CNSWorldManager::GetInstance()->IsMainServer(this->m_btRealm)) {
                this->SendSystemMessage(NS_MSG_ERROR_SUBSERVER);
                return FALSE;
            }

            this->Warp(14060, 5918, 3);
            break;
        case 41730: //ÂÞ¸¥°¢¶ûÒÆ¶¯¾íÖá
        case 41735:
            if (!CNSWorldManager::GetInstance()->IsMainServer(this->m_btRealm)) {
                this->SendSystemMessage(NS_MSG_ERROR_SUBSERVER);
                return FALSE;
            } else if (this->m_btRaceRegion == 1){
                this->Warp(0xD227u, 0x318Du, 4);
            } else if (this->m_btRaceRegion == 2) {
                this->Warp(0x8C0u, 0x14EEu, 4);
            }
            break;
        default:
            return (this->*invoke_.SkillScroll)(dwObjectId, btOpiton);
        }

        this->m_Inven.DeleteItem(this, pItem->m_wItemId, 1, "SKSL", 0);
        return TRUE;
    }

    void ActionFilter() {
        (this->*invoke_.Action)();

        unsigned dwTime = timeGetTime();
        if (this->m_dwCheckRandTime < dwTime && this->IsSessionGameMode()) {
            this->GetRand32();
            this->m_dwCheckRandTime = dwTime + rand() % 1000;
        }
    }

    BOOL DBChangeJobFilter(unsigned char btJob) {
        return GameDb::GetSingleton()->DBChangeJob(this, btJob);
    }

    int DBLoadFilter() {
        if (CNSPcManager::GetInstance()->GetUserIdCount(this->m_szUserId) > 1) {
            return FALSE;
        }

        return GameDb::GetSingleton()->DBLoad(this);
    }

    int DBSaveFilter(CNSDbManager::SAVEPCMODE mode) {
        base::CalcHighTimeRange calc_time("DBSave");

        if (mode == CNSDbManager::SavePcMode_Destroy) {
            return TRUE;
        } else if (mode == CNSDbManager::SavePcMode_LimitLogout) {
            CNSPc::LastServerClear(this->m_szUserId);
            return TRUE;
        }

        if (CSingleton<CNSWorldManager>::GetInstance()->IsMainServer(this->m_btRealm)) {
            if (mode == CNSDbManager::SavePcMode_SessionLogout) {
                CNSPc::LastServerClear(this->m_szUserId);
                this->DBLogoutLog();
                return TRUE;
            }

            if (mode == CNSDbManager::SavePcMode_Logout){
                this->DBTameMobSave(0);
                CNSPc::LastServerClear(this->m_szUserId);
                this->DBLogoutLog();
                if (this->IsRegionRVRQuestZone()|| this->IsColosseumZone()){
                    this->m_btRegion = this->m_btBindRegion;
                    this->m_cell = this->m_cellBind;
                }
            } else if ( mode == CNSDbManager::SavePcMode_ServerMove ){
                this->DBTameMobSave(0);
                this->DBLogoutLog();
            }

        } else if (mode == CNSDbManager::SavePcMode_Logout) {
            this->DBTameMobSave(0);
            if (this->m_btRegion == 4) {
                if ( this->IsRVRZone()
                    || this->IsMiniRVRZone(NSPOINT2())
                    || this->IsPVPTournamentZone()
                    || this->IsColosseumZone()) {
                        this->m_btRegion = this->m_btBindRegion;
                        this->m_cell = this->m_cellBind;
                } 

                if (this->m_cell.x >= 4000
                    && this->m_cell.x <= 44000
                    && this->m_cell.y >= 52000
                    && this->m_cell.y <= 60000) {
                        this->m_btRegion = this->m_btBindRegion;
                        this->m_cell = this->m_cellBind;
                }

            } else if (this->m_btRegion == 3){
                if (this->IsUnderworldBossZone()) {
                    this->m_btRegion = this->m_btBindRegion;
                    this->m_cell = this->m_cellBind;
                }
            } else if (this->m_btRealm == 1) {
                this->m_btRegion = 1;
                this->m_cell.x = 10447;
                this->m_cell.y = 14219;
                this->m_btBindRegion = this->m_btRegion;
                this->m_cellBind.x = this->m_cell.x;
                this->m_cellBind.y = this->m_cell.y;
                this->DBBindPosUpdate();
            } else if (this->m_btRealm == 2) {
                this->m_btRegion = 2;
                this->m_cell.x = 54157;
                this->m_cell.y = 6398;
                this->m_btBindRegion = this->m_btRegion;
                this->m_cellBind.x = this->m_cell.x;
                this->m_cellBind.y = this->m_cell.y;
                this->DBBindPosUpdate();
            }
        } else if (mode == CNSDbManager::SavePcMode_ServerMove){
            this->DBTameMobSave(0);
        }

        if (!this->m_cell.x && !this->m_cell.y){
            this->m_btRegion = this->m_btBindRegion;
            this->m_cell = this->m_cellBind;
        }

        //if (mode == CNSDbManager::SavePcMode_Logout) {
        //snapshot item array
        //}

        this->DBPcSave();

        for (int i = 0; i < CNSEquipment::EquipType_End; ++i) {
            CNSItem *pItemb = this->m_Equip.m_ItemArray[i];
            if (pItemb) {
                pItemb->m_wPos = i;
            }
        }

        for (unsigned int i = 0; i < 0x64; ++i) {
            CNSItem *pItemc = this->m_Inven.m_ItemArray[i];
            if (pItemc) {
                pItemc->m_wPos = i + 256;
                if (pItemc->m_btCount == 0) {
                    int nSeq = pItemc->m_nSeq;
                    if (this->m_Inven.DeleteObject(pItemc->m_dwObjectId)) {
                        --i;
                    } else {
                        GameUtil::Output(
                            "Warning: CNSPc::DBSave{Invaild ItemObjectId=%x, ItemSeq=%d, ItemId=%x, pSession=%p}\n",
                            pItemc->m_dwObjectId,
                            nSeq,
                            pItemc->m_wItemId,
                            this->m_pSession);
                    }

                    this->DBItemDelete(nSeq);
                }
            }
        }

        GameDb::GetSingleton()->DBItemUpdateAllPosCount(this);

        for (unsigned int i = 0; i < this->m_SkillList.GetMaxList(); ++i) {
            if (this->m_SkillList.GetSkill(i).m_bUsed && this->m_SkillList.GetSkill(i).m_nDbSeq) {
                this->DBSkillUpdate(&this->m_SkillList.GetSkill(i));
            }
        }

        for (unsigned int i = 0; i < this->m_QuestList.m_dwCount; ++i) {
            if (!this->m_QuestList.m_questList[i].m_btCompleted) {
                this->DBQuestUpdate(&this->m_QuestList.m_questList[i]);
            }
        }

        //this->DBPetSave();
        //this->DBCoolTimeSave();
        //this->DBQuickBarSave();
        //this->DBExpLog();

        if (mode == CNSDbManager::SavePcMode_Auto) {
            this->DBMemoRead();
        }
        return TRUE;
    }

    BOOL DBMainUserSeqFilter(char *szUserId) {
        return AuthDb::GetSingleton()->DBMainUserSeq(this, szUserId);
    }

    static BOOL DBMainLastServerLoadFilter(char *szUserId, unsigned char *btServerIpArray, int &nPort) {
        return AuthDb::GetSingleton()->DBMainLastServerLoad(szUserId, btServerIpArray, nPort);
    }

    static BOOL DBMainLastServerSaveFilter(char *szUserId) {
        return AuthDb::GetSingleton()->DBMainLastServerSave(
            szUserId, CNSSessionPcExt::GetServerIp(), CSingleton<CNSPcManager>::GetInstance()->m_nServerPort);
    }

    static BOOL DBMainLastServerClearFilter(char *szUserId) {
        return AuthDb::GetSingleton()->DBMainLastServerSave(szUserId, 0, 0);
    }

    BOOL DBAliasRenameFilter(char *szNewAlias) {
        if (!this->m_Inven.CheckItem(0xAA01u) && !this->m_Inven.CheckItem(0xAA05u)) {
            this->SendSystemMessage(NS_MSG_RENAME_ERROR_ITEM);
            return FALSE;
        }

        if (!strcmp(szNewAlias, this->m_szUserAlias))  {
            this->SendSystemMessage(NS_MSG_RENAME_ERROR_SAME_NAME);
            return FALSE;
        } else if (!CNSPc::AliasCheck(szNewAlias) || strlen(szNewAlias) > 24) {
            CNSPc::SendSystemMessage(NS_MSG_RENAME_ERROR_NAME);
            return FALSE;
        }

        if (!GameDb::GetSingleton()->DBAliasRename(this, szNewAlias)) {
            CNSPc::SendSystemMessage(NS_MSG_RENAME_ERROR_DUPLICATE);
            return FALSE;
        }

        if (!this->ItemUseDb(0xAA05u, 1)) {
            this->ItemUseDb(0xAA01u, 1);
        }

        LogDb::GetSingleton()->DBAliasNameLog(this, szNewAlias);

        char old_useralias[25];
        strcpy(old_useralias, this->m_szUserAlias);
        strcpy(this->m_szUserAlias, szNewAlias);
        this->SendEnterMessage(1);
        CNSPcManager::GetInstance()->ChangeUserAlias(old_useralias, szNewAlias, this->m_btRaceRegion);

        CNSObject::Owner<CNSPcParty> party = CNSObjectManager::GetInstance()->Get<CNSPcParty>(ObjectType_Party, this->m_dwPartyId);
        if (party) {
            if (party->ChangeUserAlias(old_useralias, szNewAlias) == 1) {
                CPacket packet(0x3131u);
                party->PacketPartyInfo(packet);
                party->Broadcast(packet, 0);
            }
        }

        CNSObject::Owner<CNSGuild> guild = CNSObjectManager::GetInstance()->Get<CNSGuild>(ObjectType_Guild, this->m_dwGuildId);
        if (guild) {
            if (guild->ChangeUserAlias(old_useralias, szNewAlias) == 1) {
                CPacket packet(0x3317u);
                packet.WriteUChar(1);
                guild->PacketInfo(packet);
                this->SendMessageA(packet, 1);
            }
        }

        CNSPc::SendSystemMessage(NS_MSG_RENAME_SUCCESS);
        return TRUE;
    }

    int DBAliasMakeFilter(char *szUserAlias, unsigned char btRace, unsigned char btJob, unsigned char btBody) {
        if ((btRace < RaceType_MysteryHumanMan || btRace > RaceType_NaturePomWoman )
            || (btJob != JobType_Fighter && btJob != JobType_Magician && btJob != JobType_Technician && btJob != JobType_Rogue)) {
                return 0;
        }

        if (!this->AliasCheck(szUserAlias)) {       
            return 2;
        }

        if (this->m_btRaceRegion && this->m_btRaceRegion != CNSPc::ConvertRaceToRegion(btRace)) {
            return 0;
        }

        if (this->m_nUserSeq != -1 || CNSPc::DBMainUserSeq(this->m_szUserId)) {

            if (!GameDb::GetSingleton()->DBAliasMake(this, szUserAlias, btRace, btJob, btBody)) {
                return 3;
            }

            LogDb::GetSingleton()->DBAliasNameLog(this, szUserAlias);

            if (!this->m_SkillList.DBSkillListBuild(CNSPc::ConvertRaceToRegion(btRace), btJob)) {
                this->m_SkillList.Clear();
                return 0;
            }
            this->m_SkillList.Clear();


            if (!this->DBItemBasicInsert(btRace, btJob)) {
                return 0;
            }

            this->m_btRaceRegion = CNSPc::ConvertRaceToRegion(btRace);

            return 1;
        }


        return 0;
    }

    BOOL DBAliasCountFilter(int &nCount, unsigned char &btRaceRegion) {
        return GameDb::GetSingleton()->DBAliasCount(this, nCount, btRaceRegion);
    }

    unsigned long DBAliasListFilter(CPacket &packet) {
        return GameDb::GetSingleton()->DBAliasList(this, packet);
    }

    int DBAliasInsertFilter(char *, unsigned char, unsigned char, unsigned char);
    BOOL DBAliasDeleteFilter(char *szUserAlias) {
        return GameDb::GetSingleton()->DBAliasDelete(this, szUserAlias); 
    }

    BOOL DBPcSaveFilter() {
        return GameDb::GetSingleton()->DBPcSave(this);
    }

    BOOL DBRaceUpdateFilter() {
        return GameDb::GetSingleton()->DBRaceUpdate(this);
    }

    BOOL DBGoldUpdateFilter() {
        return GameDb::GetSingleton()->DBGoldUpdate(this);
    }

    BOOL DBBindPosUpdateFilter() {
        return GameDb::GetSingleton()->DBBindPosUpdate(this);
    }

    BOOL DBTameMobSaveFilter(unsigned long dwObjectId) {
        if(this->m_TameInfo.wNpcId) {
            memcpy(&this->m_TameState, &this->m_TameInfo, sizeof(CNSTameInfo));
        }

        if (dwObjectId) {
            this->PetDelete(dwObjectId);
        }
        return TRUE;
    }
    BOOL DBTameMobLoadFilter() {
        if (this->m_TameState.wNpcId) {
            return this->PetTameMobLoad(this->m_TameState.wNpcId, this->m_TameState.szNpcName, this->m_TameState.wHp, this->m_TameState.wSta);
        } else {
            return FALSE;
        }
    }
    BOOL DBTameMobInsertFilter(unsigned short wNpcId) {
        CNSNpc *pNpc = CNSNpcParams::GetInstance()->GetObjectA(wNpcId);
        if (pNpc == NULL) {
            return FALSE;
        }

        this->m_TameState.wNpcId = pNpc->m_wNpcId;
        this->m_TameState.wHp = static_cast<unsigned short>(pNpc->m_fHp);
        this->m_TameState.wSta = static_cast<unsigned short>(pNpc->m_fSta);
        strcpy(this->m_TameState.szNpcName, pNpc->m_szNpcName);
        return TRUE;
    }
    BOOL DBItemInsertFilter(CNSItem *pItem, int nAliasSeq) {
        return GameDb::GetSingleton()->DBItemInsert(this, reinterpret_cast<CNSItemExt *>(pItem), nAliasSeq);
    }

    BOOL DBItemUpdateFilter(CNSItem *pItem) {
        return GameDb::GetSingleton()->DBItemUpdate(this, reinterpret_cast<CNSItemExt *>(pItem));
    }

    BOOL DBItemUpdatePosFilter(CNSItem *pItem) {
        return GameDb::GetSingleton()->DBItemUpdatePosCount(this, reinterpret_cast<CNSItemExt *>(pItem));
    }

    BOOL DBItemUpdateCountFilter(CNSItem *pItem){
        return GameDb::GetSingleton()->DBItemUpdatePosCount(this, reinterpret_cast<CNSItemExt *>(pItem));
    }

    BOOL DBItemUpdatePosCountFilter(CNSItem *pItem) {
        return GameDb::GetSingleton()->DBItemUpdatePosCount(this, reinterpret_cast<CNSItemExt *>(pItem));
    }

    BOOL DBItemLogFilter(char cMode, char *szAction, unsigned long dwOptionValue, int nItemSeq, unsigned short wItemId, unsigned char btCount, int nAliasSeq) {
        if (nAliasSeq == -1) {
            nAliasSeq = this->m_nAliasSeq;
        }
        return LogDb::GetSingleton()->DBItemLog(cMode, szAction, dwOptionValue, nItemSeq, wItemId, btCount, nAliasSeq);
    }

    BOOL DBItemDeleteFilter(int nItemSeq) {
        return GameDb::GetSingleton()->DBItemDelete(this, nItemSeq);
    }

    BOOL DBSkillLoadFilter() {
        return GameDb::GetSingleton()->DBSkillLoad(this);
    }

    BOOL DBSkillInsertFilter(CNSSkill *pSkill) {
        return GameDb::GetSingleton()->DBSkillInsert(this, pSkill);
    }

    int DBSkillUpdateFilter(CNSSkill *pSkill) {
        return GameDb::GetSingleton()->DBSkillUpdate(this, pSkill);
    }

    BOOL DBQuestInsertFilter(unsigned short wQuestId) {
        return GameDb::GetSingleton()->DBQuestInsert(this, wQuestId, NULL);
    }

    BOOL DBQuestInsertFilter2(CNSQuest *pQuest) {
        return GameDb::GetSingleton()->DBQuestInsert(this, pQuest->m_wQuestId, pQuest);
    }

    BOOL DBQuestUpdateFilter(CNSQuest *pQuest) {
        return GameDb::GetSingleton()->DBQuestUpdate(this, pQuest);
    }

    BOOL DBQuestDeleteFilter(unsigned short wQuestId) {
        return GameDb::GetSingleton()->DBQuestDelete(this, wQuestId);
    }

    BOOL DBTeleportInsertFilter(CNSPcTeleportList::Teleport &teleport) {
        return GameDb::GetSingleton()->DBTeleportUpdate(this, &teleport);
    }

    BOOL DBTeleportDeleteFilter(int) {
        return GameDb::GetSingleton()->DBTeleportUpdate(this, NULL);
    }

    BOOL DBTeleportDeleteAllFilter() {
        return GameDb::GetSingleton()->DBTeleportUpdate(this, NULL);
    }

    BOOL DBFriendInsertFilter(char *szUserAlias, int &nDbSeq) {
        return GameDb::GetSingleton()->DBFriendInsert(this, szUserAlias, nDbSeq);
    }

    BOOL DBFriendDeleteFilter(int nDbSeq) {
        return GameDb::GetSingleton()->DBFriendDelete(this, nDbSeq);
    }

    BOOL DbFellowListFilter() {
        this->SendSystemMessage("Not impl");
        return TRUE;
    }

    BOOL DbFellowDeleteFilter(char *) {
        this->SendSystemMessage("Not impl");
        return TRUE;
    }

    BOOL DBLoginLogFilter() {
        return LogDb::GetSingleton()->DBLoginLog(this);
    }

    BOOL DBLogoutLogFilter() {
        return TRUE;
    }

    static int DBMemoWriteFilter(CNSPc *, int, int, char *);
    static int DBMemoWriteFilter(CNSPc *, int, char *, char *);
    int DBMemoWriteFilter(char *, char *);
    BOOL DBMemoReadFilter() {
        return TRUE;
    }

    int DBBillGetGearInfoFilter() {
        return AuthDb::GetSingleton()->DBBillGetGearInfo(this);
    }
    int DBBillReqBuyItemFilter(unsigned short wItemId, char *szItemName, int nGear, char *szServerIp, char *szClientIp) {
        return AuthDb::GetSingleton()->DBBillReqBuyItem(this, wItemId, szItemName, nGear, szServerIp, szClientIp);
    }

    unsigned long DBPremiumShopLimitCountFilter(unsigned char btCategory, unsigned char btSeq) {
        return GameDb::GetSingleton()->DBPremiumShopLimitCount(btCategory, btSeq);
    }

    BOOL DBPremiumShopLimitIncCountFilter(unsigned char btCategory, unsigned char btSeq) {
        return GameDb::GetSingleton()->DBPremiumShopLimitIncCount(btCategory, btSeq);
    }
};

CNSPc::_Invoke CNSPcFilter::invoke_;

bool CNSPcFilterInit() {
    base::HookUtil::PatchULong(0x00403C67 + 1, sizeof(CNSPcExt));
    base::HookUtil::PatchULong(0x004E0259 + 1, sizeof(CNSPcExt));
    base::HookUtil::PatchULong(0x0048B02F + 1, sizeof(CNSPcExt));
    base::HookUtil::PatchULong(0x0042D56D + 1, sizeof(CNSPcExt));
    base::HookUtil::PatchULong(0x0042D296 + 1, sizeof(CNSPcExt));
    GameUtil::Output("modify cnspc memory pool size:0x%04x ok", sizeof(CNSPcExt));

    return CNSPc::_PatchConstructor(&CNSPcFilter::ConstructorFilter, &CNSPcFilter::invoke_.Constructor)
        && CNSPc::_PatchDestructor(&CNSPcFilter::DestructorFilter, &CNSPcFilter::invoke_.Destructor)
        && CNSPc::_PatchClear(&CNSPcFilter::ClearFilter, &CNSPcFilter::invoke_.Clear)
        && CNSPc::_PatchOnGameEnter(&CNSPcFilter::OnGameEnterFilter)
        && CNSPc::_PatchReset(&CNSPcFilter::ResetFilter, &CNSPcFilter::invoke_.Reset)
        && CNSPc::_PatchPetDeleteAll(&CNSPcFilter::PetDeleteAllFilter)
        && CNSPc::_PatchPetAdd(&CNSPcFilter::PetAddFilter, &CNSPcFilter::invoke_.PetAdd)
        && CNSPc::_PatchAddRealmPoint(&CNSPcFilter::AddRealmPointFilter)
        && CNSPc::_PatchGiveRealmPoint(&CNSPcFilter::GiveRealmPointFilter)
        && CNSPc::_PatchSkillScroll(&CNSPcFilter::SkillScrollFilter, &CNSPcFilter::invoke_.SkillScroll)
        && CNSPc::_PatchAction(&CNSPcFilter::ActionFilter, &CNSPcFilter::invoke_.Action)
        && CNSPc::_PatchDBChangeJob(&CNSPcFilter::DBChangeJobFilter)
        && CNSPc::_PatchDBLoad(&CNSPcFilter::DBLoadFilter)
        && CNSPc::_PatchDBSave(&CNSPcFilter::DBSaveFilter)
        && CNSPc::_PatchDBMainUserSeq(&CNSPcFilter::DBMainUserSeqFilter)
        && CNSPc::_PatchDBAliasRename(&CNSPcFilter::DBAliasRenameFilter)
        && CNSPc::_PatchDBMainLastServerLoad(&CNSPcFilter::DBMainLastServerLoadFilter)
        && CNSPc::_PatchDBMainLastServerSave(&CNSPcFilter::DBMainLastServerSaveFilter)
        && CNSPc::_PatchDBMainLastServerClear(&CNSPcFilter::DBMainLastServerClearFilter)
        && CNSPc::_PatchDBAliasMake(&CNSPcFilter::DBAliasMakeFilter)
        && CNSPc::_PatchDBAliasCount(&CNSPcFilter::DBAliasCountFilter)
        && CNSPc::_PatchDBAliasList(&CNSPcFilter::DBAliasListFilter)
        && CNSPc::_PatchDBAliasDelete(&CNSPcFilter::DBAliasDeleteFilter)
        && CNSPc::_PatchDBPcSave(&CNSPcFilter::DBPcSaveFilter)
        && CNSPc::_PatchDBRaceUpdate(&CNSPcFilter::DBRaceUpdateFilter)
        && CNSPc::_PatchDBGoldUpdate(&CNSPcFilter::DBGoldUpdateFilter)
        && CNSPc::_PatchDBBindPosUpdate(&CNSPcFilter::DBBindPosUpdateFilter)
        && CNSPc::_PatchDBTameMobSave(&CNSPcFilter::DBTameMobSaveFilter)
        && CNSPc::_PatchDBTameMobLoad(&CNSPcFilter::DBTameMobLoadFilter)
        && CNSPc::_PatchDBTameMobInsert(&CNSPcFilter::DBTameMobInsertFilter)
        && CNSPc::_PatchDBItemInsert(&CNSPcFilter::DBItemInsertFilter)
        && CNSPc::_PatchDBItemUpdate(&CNSPcFilter::DBItemUpdateFilter)
        && CNSPc::_PatchDBItemUpdatePos(&CNSPcFilter::DBItemUpdatePosFilter)
        && CNSPc::_PatchDBItemUpdateCount(&CNSPcFilter::DBItemUpdateCountFilter)
        && CNSPc::_PatchDBItemUpdatePosCount(&CNSPcFilter::DBItemUpdatePosCountFilter)
        && CNSPc::_PatchDBItemLog(&CNSPcFilter::DBItemLogFilter)
        && CNSPc::_PatchDBItemDelete(&CNSPcFilter::DBItemDeleteFilter)
        && CNSPc::_PatchDBSkillLoad(&CNSPcFilter::DBSkillLoadFilter)
        && CNSPc::_PatchDBSkillInsert(&CNSPcFilter::DBSkillInsertFilter)
        && CNSPc::_PatchDBSkillUpdate(&CNSPcFilter::DBSkillUpdateFilter)
        && CNSPc::_PatchDBQuestInsert(&CNSPcFilter::DBQuestInsertFilter)
        && CNSPc::_PatchDBQuestInsert2(&CNSPcFilter::DBQuestInsertFilter2)
        && CNSPc::_PatchDBQuestUpdate(&CNSPcFilter::DBQuestUpdateFilter)
        && CNSPc::_PatchDBQuestDelete(&CNSPcFilter::DBQuestDeleteFilter)
        && CNSPc::_PatchDBTeleportInsert(&CNSPcFilter::DBTeleportInsertFilter)
        && CNSPc::_PatchDBTeleportDelete(&CNSPcFilter::DBTeleportDeleteFilter)
        && CNSPc::_PatchDBTeleportDeleteAll(&CNSPcFilter::DBTeleportDeleteAllFilter)
        && CNSPc::_PatchDBFriendInsert(&CNSPcFilter::DBFriendInsertFilter)
        && CNSPc::_PatchDBFriendDelete(&CNSPcFilter::DBFriendDeleteFilter)
        && CNSPc::_PatchDbFellowList(&CNSPcFilter::DbFellowListFilter)
        && CNSPc::_PatchDbFellowDelete(&CNSPcFilter::DbFellowDeleteFilter)
        && CNSPc::_PatchDBLoginLog(&CNSPcFilter::DBLoginLogFilter)
        && CNSPc::_PatchDBLogoutLog(&CNSPcFilter::DBLogoutLogFilter)
        && CNSPc::_PatchDBMemoRead(&CNSPcFilter::DBMemoReadFilter)
        && CNSPc::_PatchDBBillGetGearInfo(&CNSPcFilter::DBBillGetGearInfoFilter)
        && CNSPc::_PatchDBBillReqBuyItem(&CNSPcFilter::DBBillReqBuyItemFilter)
        && CNSPc::_PatchDBPremiumShopLimitCount(&CNSPcFilter::DBPremiumShopLimitCountFilter)
        && CNSPc::_PatchDBPremiumShopLimitIncCount(&CNSPcFilter::DBPremiumShopLimitIncCountFilter);
}
