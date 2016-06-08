#ifndef NSHEADER_NS_PC_H_
#define NSHEADER_NS_PC_H_

#include "ns_header/ns_character.h"
#include "ns_header/ns_pc_exchage.h"
#include "ns_header/ns_quest.h"
#include "ns_header/ns_product.h"
#include "ns_header/ns_pc_teleport.h"
#include "ns_header/ns_friend_list.h"
#include "ns_header/ns_pc_shop.h"
#include "ns_header/ns_ware_house.h"
#include "ns_header/ns_pc_premium_use_list.h"
#include "ns_header/ns_pc_set_item_list.h"
#include "ns_header/ns_pc_title.h"
#include "ns_header/ns_pc_party.h"
#include "ns_header/ns_db_manager.h"
#include "ns_header/ns_pc_state.h"

class CNSNpc;


class CNSPc : public CNSCharacter {
public:
    static const unsigned int _size = 0x1f870;

    enum RACETYPE {
        RaceType_NULL = 0x0,
        RaceType_MysteryHumanMan = 0x1,
        RaceType_MysteryHumanWoman = 0x2,
        RaceType_MysteryBeastMan = 0x3,
        RaceType_MysteryBeastWoman = 0x4,
        RaceType_MysteryElfMan = 0x5,
        RaceType_MysteryElfWoman = 0x6,
        RaceType_MysteryPomMan = 0x7,
        RaceType_MysteryPomWoman = 0x8,
        RaceType_MysteryNHumanMan = 0x9,
        RaceType_MysteryNHumanWoman = 0xA,
        RaceType_MysteryNBeastMan = 0xB,
        RaceType_MysteryNBeastWoman = 0xC,
        RaceType_TechnicHumanMan = 0x21,
        RaceType_TechnicHumanWoman = 0x22,
        RaceType_TechnicBeastMan = 0x23,
        RaceType_TechnicBeastWoman = 0x24,
        RaceType_TechnicElfMan = 0x25,
        RaceType_TechnicElfWoman = 0x26,
        RaceType_TechnicPomMan = 0x27,
        RaceType_TechnicPomWoman = 0x28,
        RaceType_TechnicNHumanMan = 0x29,
        RaceType_TechnicNHumanWoman = 0x2A,
        RaceType_TechnicNBeastMan = 0x2B,
        RaceType_TechnicNBeastWoman = 0x2C,
        RaceType_NatureHumanMan = 0x41,
        RaceType_NatureHumanWoman = 0x42,
        RaceType_NatureBeastMan = 0x43,
        RaceType_NatureBeastWoman = 0x44,
        RaceType_NatureElfMan = 0x45,
        RaceType_NatureElfWoman = 0x46,
        RaceType_NaturePomMan = 0x47,
        RaceType_NaturePomWoman = 0x48,
        RaceType_Mystery = 0xA1,
        RaceType_MysteryHuman = 0xA2,
        RaceType_MysteryBeast = 0xA3,
        RaceType_MysteryElf = 0xA4,
        RaceType_MysteryPom = 0xA5,
        RaceType_Technic = 0xB1,
        RaceType_TechnicHuman = 0xB2,
        RaceType_TechnicBeast = 0xB3,
        RaceType_TechnicElf = 0xB4,
        RaceType_TechnicPom = 0xB5,
        RaceType_Nature = 0xC1,
        RaceType_NatureHuman = 0xC2,
        RaceType_NatureBeast = 0xC3,
        RaceType_NatureElf = 0xC4,
        RaceType_NaturePom = 0xC5,
    };

    enum JOBTYPE {
        JobType_NULL = 0x0,
        JobType_Fighter = 0x1,
        JobType_Warrior = 0x2,
        JobType_Paladin = 0x3,
        JobType_Magician = 0x21,
        JobType_Wizard = 0x22,
        JobType_Summoner = 0x23,
        JobType_Technician = 0x41,
        JobType_Engineer = 0x42,
        JobType_Blacksmith = 0x43,
        JobType_Rogue = 0x61,
        JobType_Hunter = 0x62,
        JobType_Thief = 0x63,
    };

    enum PETTYPE {
        PetType_Pet = 0x0,
        PetType_Tame = 0x1,
        PetType_Summon = 0x2,
        PetType_Block = 0x3,
        PetType_End = 0x4,
    };

    enum PSWTYPE {
        PswType_NULL = 0x0,
        PswType_Proto = 0x1,
        PswType_Melee = 0x2,
        PswType_Range = 0x3,
        PswType_LongRange = 0x4,
    };

    enum REALMPOS {
        RealmPos_MCastleX = 0x6A2C,
        RealmPos_MCastleY = 0x75DA,
        RealmPos_TCastleX = 0x7530,
        RealmPos_TCastleY = 0x17C0,
    };

    class CNCPetInfo {
    public:
        static const unsigned int _size = 0x28;

        unsigned long dwSeq;//this+0x0
        unsigned char btPetKind;//this+0x4
        unsigned char btLevel;//this+0x5
        unsigned char btGrade;//this+0x6
        unsigned long dwExp;//this+0x8
        unsigned short wSta;//this+0xC
        char szPetName[0x19];//this+0xE
    };

    class CNSPc::CNCPetInfo m_PetInfo;//this+0x4430
    class CNSTameInfo {
    public:
        static const unsigned int _size = 0x20;

        unsigned short wNpcId;//this+0x0
        char szNpcName[0x19];//this+0x2
        unsigned short wHp;//this+0x1C
        unsigned short wSta;//this+0x1E
    };

    class CNSPc::CNSTameInfo m_TameInfo;//this+0x4458
    struct _BuffTime {
        static const unsigned int _size = 0x8;

        unsigned char btBuffId;//this+0x0
        unsigned short wSkillId;//this+0x1
        unsigned char btLevel;//this+0x3
        unsigned short wValue;//this+0x4
        unsigned short wRemainTime;//this+0x6
    };

    struct BuffTime {
        static const unsigned int _size = 0x8;

        unsigned char btBuffId;//this+0x0
        unsigned short wSkillId;//this+0x1
        unsigned char btLevel;//this+0x3
        unsigned short wValue;//this+0x4
        unsigned short wRemainTime;//this+0x6
    };

    static unsigned char GetSimpleJob(unsigned char);    PATCH_STATIC(unsigned char, GetSimpleJob, unsigned char, 0x423700);
    static unsigned char GetBasicJob(unsigned char);    PATCH_STATIC(unsigned char, GetBasicJob, unsigned char, 0x4D77A0);
    static int GetStartRegion(unsigned char, unsigned char, unsigned char &, NSPOINT2 &);    PATCH_STATIC(int, GetStartRegion, unsigned char _COMMA unsigned char _COMMA unsigned char & _COMMA NSPOINT2 &, 0x484760);
    static unsigned char ConvertRaceToRegion(unsigned char);    PATCH_STATIC(unsigned char, ConvertRaceToRegion, unsigned char, 0x484460);
    static int IsTargetOtherRealm(CNSCharacter *, CNSCharacter *);    PATCH_STATIC(int, IsTargetOtherRealm, CNSCharacter * _COMMA CNSCharacter *, 0x4841E0);
    static int IsMineRider(unsigned short);    PATCH_STATIC(int, IsMineRider, unsigned short, 0x484C10);
    DEFINE_STATIC_MEMBER(CNSSessionPc *, m_DummySession, 0x571B10);//static class CNSSessionPc m_DummySession;//[0x571B10]  [00171B10:0003:00051B10]
    int m_nUserSeq;//this+0x4478
    int m_nAliasSeq;//this+0x447C
    char m_szUserId[0x33];//this+0x4480
    char m_szUserAlias[0x19];//this+0x44B3
    unsigned long m_dwShotCount;//this+0x44CC
    int m_bAutoRunMode;//this+0x44D0
    unsigned short m_wAutoRunAngle;//this+0x44D4
    unsigned long m_dwNextExp;//this+0x44D8
    unsigned char m_btRace;//this+0x44DC
    unsigned char m_btJob;//this+0x44DD
    unsigned char m_btBody;//this+0x44DE
    unsigned short m_wNsTank;//this+0x44E0
    unsigned short m_wNsCharge;//this+0x44E2
    unsigned char m_btRank;//this+0x44E4
    unsigned long m_dwRealmPoint;//this+0x44E8
    unsigned short m_wTitleId;//this+0x44EC
    unsigned char m_btRaceRegion;//this+0x44EE
    unsigned char m_btBindRegion;//this+0x44EF
    class NSPOINT2 m_cellBind;//this+0x44F0
    unsigned char m_btTransRegion;//this+0x44F4
    class NSPOINT2 m_cellTrans;//this+0x44F6
    unsigned long m_dwRecoveryTime;//this+0x44FC
    class CNSEquipment m_Equip;//this+0x4500
    class CNSPcExchange m_Exchange;//this+0x4614
    class CNSQuestList m_QuestList;//this+0x46C8
    class CNSProductList m_ProductList;//this+0x1CD74
    class CNSPcTeleportList m_TeleportList;//this+0x1E98C
    class CNSPcFriendList m_FriendList;//this+0x1EB00
    class CNSPcShop m_Shop;//this+0x1EF40
    class CNSWareHouse m_WareHouse;//this+0x1F008
    class CNSPcPremiumUseList m_PremiumUseList;//this+0x1F354
    class CNSPcSetItemList m_SetItemList;//this+0x1F4E8
    class CNSPcTitleList m_TitleList;//this+0x1F5B0
    unsigned long m_dwQuickBarArray[0x32];//this+0x1F5D8
    unsigned long m_dwQuickBarArrayDb[0x32];//this+0x1F6A0
    int m_bPartyEnableMember;//this+0x1F768
    int m_bShiftMode;//this+0x1F76C
    int m_bSessionLogoutMode;//this+0x1F770
    unsigned short m_wLogSp;//this+0x1F774
    class CNSSessionPcExt * m_pSession;//this+0x1F778
    CNSPc(const CNSPc &);
    CNSPc(CNSSessionPc *);    PATCH_MEMBER(CNSPc &, Constructor, CNSSessionPc *, 0x45D000);
    virtual ~CNSPc();    PATCH_MEMBER(void, Destructor, , 0x45D6D0);
    void Clear(int);    PATCH_MEMBER(void, Clear, int, 0x45D4B0);
    int OnGameEnter();    PATCH_MEMBER(int, OnGameEnter, , 0x45DBF0);
    virtual void OnBuff(unsigned long, int);    PATCH_MEMBER(void, OnBuff, unsigned long _COMMA int, 0x45DE70);
    void OnLogOut(int);    PATCH_MEMBER(void, OnLogOut, int, 0x45DFC0);
    void OnSessionMode();    PATCH_MEMBER(void, OnSessionMode, , 0x45E230);
    void OnMoveServer(unsigned char, NSPOINT2);    PATCH_MEMBER(void, OnMoveServer, unsigned char _COMMA NSPOINT2, 0x45E250);
    void OnDisconnect();    PATCH_MEMBER(void, OnDisconnect, , 0x45E320);
    virtual void OnHitLastDamage(CNSCharacter *);    PATCH_MEMBER(void, OnHitLastDamage, CNSCharacter *, 0x45E3F0);
    void GetPswInfo(CNSPc::PSWTYPE &, unsigned char &, unsigned char &, unsigned char &);    PATCH_MEMBER(void, GetPswInfo, CNSPc::PSWTYPE & _COMMA unsigned char & _COMMA unsigned char & _COMMA unsigned char &, 0x464410);
    void Reset(int);    PATCH_MEMBER(void, Reset, int, 0x464890);
    int ResetSiegeWeapon(int, unsigned short, int);    PATCH_MEMBER(int, ResetSiegeWeapon, int _COMMA unsigned short _COMMA int, 0x464560);
    void Login();    PATCH_MEMBER(void, Login, , 0x460260);
    void LogOut();
    virtual unsigned short HitDamage(CNSCharacter *, unsigned short, CNSObject::HITTYPE, int);    PATCH_MEMBER(unsigned short, HitDamage, CNSCharacter * _COMMA unsigned short _COMMA CNSObject::HITTYPE _COMMA int, 0x481EC0);
    int IsLogin();    PATCH_MEMBER(int, IsLogin, , 0x44C430);
    int IsPartyEnableMember();    PATCH_MEMBER(int, IsPartyEnableMember, , 0x42B790);
    int IsItemFreeze();    PATCH_MEMBER(int, IsItemFreeze, , 0x4C80C0);
    int IsPcBang();    PATCH_MEMBER(int, IsPcBang, , 0x43EE10);
    int IsSessionGameMode();    PATCH_MEMBER(int, IsSessionGameMode, , 0x45D960);
    int IsExistTameMob();    PATCH_MEMBER(int, IsExistTameMob, , 0x484990);
    void ToggleSuperMode();    PATCH_MEMBER(void, ToggleSuperMode, , 0x4C93B0);
    void ToggleGhost();    PATCH_MEMBER(void, ToggleGhost, , 0x4C93E0);
    void SetGuildId(unsigned long);    PATCH_MEMBER(void, SetGuildId, unsigned long, 0x4365A0);
    void SetPartyId(unsigned long);    PATCH_MEMBER(void, SetPartyId, unsigned long, 0x492540);
    void SetUserId(int, char *);    PATCH_MEMBER(void, SetUserId, int _COMMA char *, 0x406260);
    void SetUserAlias(char *);    PATCH_MEMBER(void, SetUserAlias, char *, 0x4062E0);
    int GetUserSeq();    PATCH_MEMBER(int, GetUserSeq, , 0x485570);
    void SetStickObjectId(unsigned long);    PATCH_MEMBER(void, SetStickObjectId, unsigned long, 0x484390);
    unsigned long GetStickObjectId();    PATCH_MEMBER(unsigned long, GetStickObjectId, , 0x4C7FF0);
    int GetStickDestination(NSPOINT2 &);    PATCH_MEMBER(int, GetStickDestination, NSPOINT2 &, 0x45DA00);
    void CancelStickPc();    PATCH_MEMBER(void, CancelStickPc, , 0x482530);
    void SetDeadTimeClear();
    void SetDeadTime(unsigned long);    PATCH_MEMBER(void, SetDeadTime, unsigned long, 0x4D73B0);
    void SetLeaveTime();    PATCH_MEMBER(void, SetLeaveTime, , 0x4C7EB0);
    void SetDisconnectTime();    PATCH_MEMBER(void, SetDisconnectTime, , 0x4B48D0);
    int SetTitle(unsigned short);    PATCH_MEMBER(int, SetTitle, unsigned short, 0x4C84A0);
    int IsAutoRunMode();    PATCH_MEMBER(int, IsAutoRunMode, , 0x483860);
    void StartAutoRunMode();    PATCH_MEMBER(void, StartAutoRunMode, , 0x4C8010);
    void EndAutoRunMode();    PATCH_MEMBER(void, EndAutoRunMode, , 0x483880);
    char * GetUserId();    PATCH_MEMBER(char *, GetUserId, , 0x42E150);
    char * GetUserAlias();    PATCH_MEMBER(char *, GetUserAlias, , 0x42B7C0);
    int GetUserAliasSeq();    PATCH_MEMBER(int, GetUserAliasSeq, , 0x43EE30);
    unsigned long GetGuildId();    PATCH_MEMBER(unsigned long, GetGuildId, , 0x482750);
    unsigned long GetPartyId();    PATCH_MEMBER(unsigned long, GetPartyId, , 0x42B7E0);
    unsigned char GetRank();    PATCH_MEMBER(unsigned char, GetRank, , 0x44A970);
    unsigned long GetDeadExp();    PATCH_MEMBER(unsigned long, GetDeadExp, , 0x4843B0);
    virtual unsigned short GetNs();    PATCH_MEMBER(unsigned short, GetNs, , 0x481E70);
    unsigned short GetNsMaxCharge();    PATCH_MEMBER(unsigned short, GetNsMaxCharge, , 0x45EA50);
    unsigned short GetNsCharge();    PATCH_MEMBER(unsigned short, GetNsCharge, , 0x4B0830);
    void SetTransPos();    PATCH_MEMBER(void, SetTransPos, , 0x4C7F20);
    virtual unsigned short UseMp(unsigned short);    PATCH_MEMBER(unsigned short, UseMp, unsigned short, 0x4822E0);
    virtual unsigned short UseSta(unsigned short);    PATCH_MEMBER(unsigned short, UseSta, unsigned short, 0x482330);
    unsigned char GetRace();    PATCH_MEMBER(unsigned char, GetRace, , 0x43F950);
    unsigned char GetRaceRegion();    PATCH_MEMBER(unsigned char, GetRaceRegion, , 0x436630);
    unsigned char GetJob();    PATCH_MEMBER(unsigned char, GetJob, , 0x4236E0);
    unsigned char GetBindRegion();    PATCH_MEMBER(unsigned char, GetBindRegion, , 0x4B0850);
    NSPOINT2 GetBindCell();    PATCH_MEMBER(NSPOINT2, GetBindCell, , 0x4B0870);
    unsigned char GetTransRegion();    PATCH_MEMBER(unsigned char, GetTransRegion, , 0x4C7F50);
    unsigned long GetLastDeadExp();    PATCH_MEMBER(unsigned long, GetLastDeadExp, , 0x4D73D0);
    void SetLastDeadExp(unsigned long);    PATCH_MEMBER(void, SetLastDeadExp, unsigned long, 0x4C7F00);
    unsigned char GetEquipMaxSpecialGrade();    PATCH_MEMBER(unsigned char, GetEquipMaxSpecialGrade, , 0x44A5D0);
    int GetEquipMaxSpecialGradePer();    PATCH_MEMBER(int, GetEquipMaxSpecialGradePer, , 0x44A590);
    CNSSessionPc * GetSession();    PATCH_MEMBER(CNSSessionPc *, GetSession, , 0x44A990);
    int CloseConnection();    PATCH_MEMBER(int, CloseConnection, , 0x45D840);
    void SetNpcTalkObjectId(unsigned long);    PATCH_MEMBER(void, SetNpcTalkObjectId, unsigned long, 0x4C81B0);
    unsigned long GetNpcTalkObjectId();
    unsigned long CheckInstantKey(unsigned char);    PATCH_MEMBER(unsigned long, CheckInstantKey, unsigned char, 0x46FE90);
    CNSNpc * PetAdd(CNSPc::PETTYPE, unsigned short, NSPOINT2 &, unsigned short, unsigned char, unsigned short, unsigned long, char *, unsigned short, unsigned short, unsigned char);    PATCH_MEMBER(CNSNpc *, PetAdd, CNSPc::PETTYPE _COMMA unsigned short _COMMA NSPOINT2 & _COMMA unsigned short _COMMA unsigned char _COMMA unsigned short _COMMA unsigned long _COMMA char * _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char, 0x466CD0);
    int PetTaming(unsigned long, unsigned short, unsigned char, unsigned short, unsigned long);    PATCH_MEMBER(int, PetTaming, unsigned long _COMMA unsigned short _COMMA unsigned char _COMMA unsigned short _COMMA unsigned long, 0x4670E0);
    CNSNpc * PetSummoning(unsigned short, unsigned short, unsigned char, unsigned short, unsigned long);    PATCH_MEMBER(CNSNpc *, PetSummoning, unsigned short _COMMA unsigned short _COMMA unsigned char _COMMA unsigned short _COMMA unsigned long, 0x4671E0);
    int PetTameMobLoad(unsigned short, char *, unsigned short, unsigned short);    PATCH_MEMBER(int, PetTameMobLoad, unsigned short _COMMA char * _COMMA unsigned short _COMMA unsigned short, 0x4672D0);
    CNSNpc * PetLoad(unsigned char, unsigned char, unsigned char, char *, unsigned short);    PATCH_MEMBER(CNSNpc *, PetLoad, unsigned char _COMMA unsigned char _COMMA unsigned char _COMMA char * _COMMA unsigned short, 0x4673A0);
    CNSNpc * PetLoad();    PATCH_MEMBER(CNSNpc *, PetLoad, , 0x4824C0);
    int PetUpgrade(unsigned char);    PATCH_MEMBER(int, PetUpgrade, unsigned char, 0x4667C0);
    int PetChangeLevel(unsigned char);    PATCH_MEMBER(int, PetChangeLevel, unsigned char, 0x466790);
    int PetRebirth(unsigned char);    PATCH_MEMBER(int, PetRebirth, unsigned char, 0x4B0890);
    int PetDelete(unsigned long);    PATCH_MEMBER(int, PetDelete, unsigned long, 0x4675F0);
    void PetDeleteAll(int);    PATCH_MEMBER(void, PetDeleteAll, int, 0x467690);
    int PetExist();
    int PetStateChange(CNSNpc *, unsigned char);    PATCH_MEMBER(int, PetStateChange, CNSNpc * _COMMA unsigned char, 0x4677D0);
    int PetAttack(CNSNpc *, CNSCharacter *);    PATCH_MEMBER(int, PetAttack, CNSNpc * _COMMA CNSCharacter *, 0x467890);
    int PetChange(unsigned char, unsigned char, unsigned char, int);    PATCH_MEMBER(int, PetChange, unsigned char _COMMA unsigned char _COMMA unsigned char _COMMA int, 0x466650);
    int PetFood(unsigned long);    PATCH_MEMBER(int, PetFood, unsigned long, 0x466800);
    unsigned char PetGetKind();
    void PetAddExpPoint(CNSNpc *, unsigned short);    PATCH_MEMBER(void, PetAddExpPoint, CNSNpc * _COMMA unsigned short, 0x467AA0);
    float PetGetExpPercent(unsigned long);    PATCH_MEMBER(float, PetGetExpPercent, unsigned long, 0x4678E0);
    unsigned char PetGetExpPercent();    PATCH_MEMBER(unsigned char, PetGetExpPercent, , 0x467970);
    void PetSetExpPercent(unsigned char);    PATCH_MEMBER(void, PetSetExpPercent, unsigned char, 0x467A20);
    void PetDebugExp();    PATCH_MEMBER(void, PetDebugExp, , 0x467D30);
    void PetDebugKill();    PATCH_MEMBER(void, PetDebugKill, , 0x467D70);
    void PetSetName(CNSNpc *, char *);    PATCH_MEMBER(void, PetSetName, CNSNpc * _COMMA char *, 0x467DB0);
    void PetInfoSave();    PATCH_MEMBER(void, PetInfoSave, , 0x4777A0);
    unsigned long PetTameInfoSave();    PATCH_MEMBER(unsigned long, PetTameInfoSave, , 0x477820);
    void PetHide();    PATCH_MEMBER(void, PetHide, , 0x467770);
    CNSObject::Owner<CNSNpc> PetGetObject() { return CNSObject::Owner<CNSNpc>(_PetGetObject()); } CNSNpc * _PetGetObject();    PATCH_MEMBER(CNSNpc *, _PetGetObject, , 0x43EE50);
    CNSObject::Owner<CNSNpc> PetGetMobObject() { return CNSObject::Owner<CNSNpc>(_PetGetMobObject()); } CNSNpc * _PetGetMobObject();    PATCH_MEMBER(CNSNpc *, _PetGetMobObject, , 0x43EEB0);
    CNSPc::PETTYPE PetGetType(unsigned long);    PATCH_MEMBER(CNSPc::PETTYPE, PetGetType, unsigned long, 0x4675A0);
    unsigned long PetGetObjectId(CNSPc::PETTYPE);    PATCH_MEMBER(unsigned long, PetGetObjectId, CNSPc::PETTYPE, 0x43EE90);
    void PetSetObjectId(CNSPc::PETTYPE, unsigned long);    PATCH_MEMBER(void, PetSetObjectId, CNSPc::PETTYPE _COMMA unsigned long, 0x483190);
    unsigned long ItemList(CPacket &, int);    PATCH_MEMBER(unsigned long, ItemList, CPacket & _COMMA int, 0x467DE0);
    unsigned char ItemEquipDescription(CNSItem *, CNSItem * *);    PATCH_MEMBER(unsigned char, ItemEquipDescription, CNSItem * _COMMA CNSItem * *, 0x467EE0);
    unsigned long _ItemAdd(unsigned short, unsigned char, char *, unsigned long, int);    PATCH_MEMBER(unsigned long, _ItemAdd, unsigned short _COMMA unsigned char _COMMA char * _COMMA unsigned long _COMMA int, 0x468340);
    int ItemAdd(unsigned short, unsigned char, char *, unsigned long, int);    PATCH_MEMBER(int, ItemAdd, unsigned short _COMMA unsigned char _COMMA char * _COMMA unsigned long _COMMA int, 0x43EF00);
    int ItemAddToUserAlias(unsigned short, unsigned char, char *);    PATCH_MEMBER(int, ItemAddToUserAlias, unsigned short _COMMA unsigned char _COMMA char *, 0x468280);
    int ItemPickup(unsigned long, unsigned long);    PATCH_MEMBER(int, ItemPickup, unsigned long _COMMA unsigned long, 0x468690);
    void ItemPickupAll(CNSNpc *);    PATCH_MEMBER(void, ItemPickupAll, CNSNpc *, 0x468710);
    int ItemMove(unsigned long, unsigned long, int);    PATCH_MEMBER(int, ItemMove, unsigned long _COMMA unsigned long _COMMA int, 0x469880);
    int ItemEquipCheck(CNSItem *);    PATCH_MEMBER(int, ItemEquipCheck, CNSItem *, 0x468790);
    int ItemEquipCheck2(CNSEquipment::EQUIPMENTTYPE, CNSItem *);    PATCH_MEMBER(int, ItemEquipCheck2, CNSEquipment::EQUIPMENTTYPE _COMMA CNSItem *, 0x4688D0);
    CNSEquipment::EQUIPMENTTYPE ItemEquipRemove(CNSItem *);    PATCH_MEMBER(CNSEquipment::EQUIPMENTTYPE, ItemEquipRemove, CNSItem *, 0x468A70);
    int ItemEquip(CNSEquipment::EQUIPMENTTYPE, unsigned long);    PATCH_MEMBER(int, ItemEquip, CNSEquipment::EQUIPMENTTYPE _COMMA unsigned long, 0x469750);
    int ItemUse(unsigned short);    PATCH_MEMBER(int, ItemUse, unsigned short, 0x46A240);
    int ItemUse(unsigned long, unsigned char &, unsigned char);    PATCH_MEMBER(int, ItemUse, unsigned long _COMMA unsigned char & _COMMA unsigned char, 0x469C80);
    int ItemUseDb(CNSItem *, char, char *);    PATCH_MEMBER(int, ItemUseDb, CNSItem * _COMMA char _COMMA char *, 0x46A3C0);
    int ItemUseDb(unsigned short, unsigned char);    PATCH_MEMBER(int, ItemUseDb, unsigned short _COMMA unsigned char, 0x46A2D0);
    int ItemDelete(unsigned long, unsigned char);    PATCH_MEMBER(int, ItemDelete, unsigned long _COMMA unsigned char, 0x46A490);
    int ItemCombine(unsigned long, unsigned long, unsigned char &, unsigned char &);    PATCH_MEMBER(int, ItemCombine, unsigned long _COMMA unsigned long _COMMA unsigned char & _COMMA unsigned char &, 0x46A6A0);
    int ItemDivide(unsigned long, unsigned char, unsigned long &);    PATCH_MEMBER(int, ItemDivide, unsigned long _COMMA unsigned char _COMMA unsigned long &, 0x46A840);
    int ItemUpgrade(unsigned long, unsigned long, unsigned long, int, int);    PATCH_MEMBER(int, ItemUpgrade, unsigned long _COMMA unsigned long _COMMA unsigned long _COMMA int _COMMA int, 0x46AF90);
    int ItemCoreDivide(CNSItem *, CNSItem *, int);    PATCH_MEMBER(int, ItemCoreDivide, CNSItem * _COMMA CNSItem * _COMMA int, 0x46ABE0);
    void ItemPrintPremium(int);    PATCH_MEMBER(void, ItemPrintPremium, int, 0x46C090);
    void ItemCheckPremium();    PATCH_MEMBER(void, ItemCheckPremium, , 0x46C3E0);
    void EventItemAdd(unsigned short, unsigned char, unsigned long);    PATCH_MEMBER(void, EventItemAdd, unsigned short _COMMA unsigned char _COMMA unsigned long, 0x48BEE0);
    int GetItemRecombinationExpense(unsigned long, unsigned long &, unsigned short &, unsigned char &);    PATCH_MEMBER(int, GetItemRecombinationExpense, unsigned long _COMMA unsigned long & _COMMA unsigned short & _COMMA unsigned char &, 0x46C700);
    int ItemRecombination(unsigned long, int);    PATCH_MEMBER(int, ItemRecombination, unsigned long _COMMA int, 0x46CA20);
    int ItemSwap(unsigned long, int);    PATCH_MEMBER(int, ItemSwap, unsigned long _COMMA int, 0x46D120);
    int ItemDeleteAll();    PATCH_MEMBER(int, ItemDeleteAll, , 0x46D140);
    int ItemGathering(unsigned long, unsigned long, unsigned long, int);    PATCH_MEMBER(int, ItemGathering, unsigned long _COMMA unsigned long _COMMA unsigned long _COMMA int, 0x46A920);
    int ItemMining(unsigned long, unsigned long, unsigned long, int);    PATCH_MEMBER(int, ItemMining, unsigned long _COMMA unsigned long _COMMA unsigned long _COMMA int, 0x46A9F0);
    int ItemUnlock(unsigned long, unsigned long, unsigned long);    PATCH_MEMBER(int, ItemUnlock, unsigned long _COMMA unsigned long _COMMA unsigned long, 0x46AB20);
    int PremiumItemSell(unsigned short);    PATCH_MEMBER(int, PremiumItemSell, unsigned short, 0x46D170);
    unsigned long SkillList(CPacket &);    PATCH_MEMBER(unsigned long, SkillList, CPacket &, 0x46D3C0);
    void DebugSkillList();    PATCH_MEMBER(void, DebugSkillList, , 0x46D5A0);
    int SkillCast(unsigned short, unsigned long);    PATCH_MEMBER(int, SkillCast, unsigned short _COMMA unsigned long, 0x46D740);
    int SkillUse();    PATCH_MEMBER(int, SkillUse, , 0x46D850);
    void SkillCancel();    PATCH_MEMBER(void, SkillCancel, , 0x46D8A0);
    int SkillStudy(unsigned short);    PATCH_MEMBER(int, SkillStudy, unsigned short, 0x46D8D0);
    int SkillScroll(unsigned long, unsigned char);    PATCH_MEMBER(int, SkillScroll, unsigned long _COMMA unsigned char, 0x46D8F0);
    int SkillBlockCall(unsigned long, unsigned short);    PATCH_MEMBER(int, SkillBlockCall, unsigned long _COMMA unsigned short, 0x46E850);
    int CheckBlock();    PATCH_MEMBER(int, CheckBlock, , 0x46E6D0);
    CNSPcParty * PartyCreate(char *, char *, CNSPcParty::LOOTMODE);    PATCH_MEMBER(CNSPcParty *, PartyCreate, char * _COMMA char * _COMMA CNSPcParty::LOOTMODE, 0x46EA10);
    int MoveTo(unsigned char, NSPOINT2 &, NSPOINT2 &);    PATCH_MEMBER(int, MoveTo, unsigned char _COMMA NSPOINT2 & _COMMA NSPOINT2 &, 0x46F4A0);
    int MoveTo(NSPOINT2 &);    PATCH_MEMBER(int, MoveTo, NSPOINT2 &, 0x482600);
    void _Stop(unsigned long);    PATCH_MEMBER(void, _Stop, unsigned long, 0x482570);
    virtual void Stop(unsigned long);    PATCH_MEMBER(void, Stop, unsigned long, 0x46D6A0);
    void Stand();    PATCH_MEMBER(void, Stand, , 0x46D6D0);
    int Warp(unsigned short, unsigned short, unsigned char);    PATCH_MEMBER(int, Warp, unsigned short _COMMA unsigned short _COMMA unsigned char, 0x46F5C0);
    void WarpParty(unsigned short, unsigned short, unsigned char);    PATCH_MEMBER(void, WarpParty, unsigned short _COMMA unsigned short _COMMA unsigned char, 0x46F930);
    void WarpGuild(unsigned short, unsigned short, unsigned char);    PATCH_MEMBER(void, WarpGuild, unsigned short _COMMA unsigned short _COMMA unsigned char, 0x46FA20);
    int WarpInstant(unsigned char, unsigned short, unsigned short);    PATCH_MEMBER(int, WarpInstant, unsigned char _COMMA unsigned short _COMMA unsigned short, 0x46FB60);
    void WarpRaceRegion();    PATCH_MEMBER(void, WarpRaceRegion, , 0x46FDE0);
    static void DBWarpRaceRegion();    PATCH_STATIC(void, DBWarpRaceRegion, , 0x474400);
    int AttackCheck(CNSCharacter *);    PATCH_MEMBER(int, AttackCheck, CNSCharacter *, 0x46FF00);
    void Attack(CNSCharacter *, unsigned long);    PATCH_MEMBER(void, Attack, CNSCharacter * _COMMA unsigned long, 0x470220);
    unsigned short AttackSiegeWeaponMode(CNSCharacter *, unsigned short);    PATCH_MEMBER(unsigned short, AttackSiegeWeaponMode, CNSCharacter * _COMMA unsigned short, 0x484220);
    void Rebirth(unsigned char);    PATCH_MEMBER(void, Rebirth, unsigned char, 0x471D20);
    void Rebirth2();    PATCH_MEMBER(void, Rebirth2, , 0x472580);
    void UsePhoenix(unsigned short);    PATCH_MEMBER(void, UsePhoenix, unsigned short, 0x472470);
    int IsEquipRemoveAll();    PATCH_MEMBER(int, IsEquipRemoveAll, , 0x45F580);
    int ChangeRace(unsigned char);    PATCH_MEMBER(int, ChangeRace, unsigned char, 0x45F730);
    int ChangeBindPos(unsigned char, unsigned short, unsigned short);    PATCH_MEMBER(int, ChangeBindPos, unsigned char _COMMA unsigned short _COMMA unsigned short, 0x4600D0);
    int DBChangeJob(unsigned char);    PATCH_MEMBER(int, DBChangeJob, unsigned char, 0x45F220);
    int DBSkillMake60();    PATCH_MEMBER(int, DBSkillMake60, , 0x45F920);
    int DBLevelUp100();    PATCH_MEMBER(int, DBLevelUp100, , 0x45FA70);
    int DBPSWFactory(unsigned short);    PATCH_MEMBER(int, DBPSWFactory, unsigned short, 0x45FC50);
    int LoadPath(unsigned short);    PATCH_MEMBER(int, LoadPath, unsigned short, 0x460110);
    int MoveTranferManchine(unsigned short);    PATCH_MEMBER(int, MoveTranferManchine, unsigned short, 0x460180);
    void RestoreCell();    PATCH_MEMBER(void, RestoreCell, , 0x482770);
    void AddGold(unsigned long);    PATCH_MEMBER(void, AddGold, unsigned long, 0x482BB0);
    unsigned long AddExpPoint(unsigned long, int);    PATCH_MEMBER(unsigned long, AddExpPoint, unsigned long _COMMA int, 0x470FA0);
    unsigned short AddNsPoint(unsigned short, int);    PATCH_MEMBER(unsigned short, AddNsPoint, unsigned short _COMMA int, 0x482F20);
    unsigned short SuctionNsPoint(unsigned short);    PATCH_MEMBER(unsigned short, SuctionNsPoint, unsigned short, 0x482BF0);
    unsigned short SuctionGold(unsigned long);    PATCH_MEMBER(unsigned short, SuctionGold, unsigned long, 0x482E50);
    void AddTotalExp(unsigned char, unsigned long, unsigned long, unsigned short, int);    PATCH_MEMBER(void, AddTotalExp, unsigned char _COMMA unsigned long _COMMA unsigned long _COMMA unsigned short _COMMA int, 0x4658A0);
    int GiveNsPoint(unsigned short);    PATCH_MEMBER(int, GiveNsPoint, unsigned short, 0x4837E0);
    unsigned long GetRealmPoint();    PATCH_MEMBER(unsigned long, GetRealmPoint, , 0x4B0810);
    unsigned long AddRealmPoint(unsigned long, CNSCharacter *);    PATCH_MEMBER(unsigned long, AddRealmPoint, unsigned long _COMMA CNSCharacter *, 0x470E00);
    int GiveRealmPoint(unsigned long);    PATCH_MEMBER(int, GiveRealmPoint, unsigned long, 0x470F20);
    static CNSObject::Owner<CNSPc> GetOriginalPcObject(CNSCharacter *pChar) { CNSObject::Owner<CNSPc>(_GetOriginalPcObject(pChar)); } static CNSPc * _GetOriginalPcObject(CNSCharacter *);    PATCH_STATIC(CNSPc *, _GetOriginalPcObject, CNSCharacter *, 0x429AD0);
    unsigned long m_dwSkillExp;//this+0x1F77C
    unsigned long GetSkillExp();    PATCH_MEMBER(unsigned long, GetSkillExp, , 0x4D75E0);
    void AddSkillExpPoint(unsigned long, int);    PATCH_MEMBER(void, AddSkillExpPoint, unsigned long _COMMA int, 0x45EC00);
    void UseSkillExpPoint(unsigned long);    PATCH_MEMBER(void, UseSkillExpPoint, unsigned long, 0x45EE20);
    int TeleportAdd(unsigned short, char *);    PATCH_MEMBER(int, TeleportAdd, unsigned short _COMMA char *, 0x46EB00);
    int TeleportDelete(unsigned short, int);    PATCH_MEMBER(int, TeleportDelete, unsigned short _COMMA int, 0x46EBE0);
    int FriendAdd(char *);    PATCH_MEMBER(int, FriendAdd, char *, 0x46EC20);
    int FriendDelete(char *);    PATCH_MEMBER(int, FriendDelete, char *, 0x46ECE0);
    int GuildCreate(char *, char *);    PATCH_MEMBER(int, GuildCreate, char * _COMMA char *, 0x46ED30);
    int GuildAddLevelUpPoint();    PATCH_MEMBER(int, GuildAddLevelUpPoint, , 0x46EF40);
    int GuildAddConnectPoint();    PATCH_MEMBER(int, GuildAddConnectPoint, , 0x46F100);
    static float CalcRealmPoint(unsigned char, unsigned char, CNSCharacter *);    PATCH_STATIC(float, CalcRealmPoint, unsigned char _COMMA unsigned char _COMMA CNSCharacter *, 0x46F2D0);
    void LevelUp();    PATCH_MEMBER(void, LevelUp, , 0x470C10);
    unsigned long LevelSetup();    PATCH_MEMBER(unsigned long, LevelSetup, , 0x470C50);
    static int CheckDoubleConnect(char *);    PATCH_STATIC(int, CheckDoubleConnect, char *, 0x472620);
    static int CheckDoubleConnect2(char *);    PATCH_STATIC(int, CheckDoubleConnect2, char *, 0x4726A0);
    static int CheckDoubleConnect3(char *, unsigned char);    PATCH_STATIC(int, CheckDoubleConnect3, char * _COMMA unsigned char, 0x472730);
    static void LastServerClear(char *);    PATCH_STATIC(void, LastServerClear, char *, 0x472800);
    unsigned short GetChatChannel(int);    PATCH_MEMBER(unsigned short, GetChatChannel, int, 0x4C8040);
    int GetChatChannelIndex(unsigned short);    PATCH_MEMBER(int, GetChatChannelIndex, unsigned short, 0x4C8070);
    int ChatChannelJoin(char *);    PATCH_MEMBER(int, ChatChannelJoin, char *, 0x480230);
    int ChatChannelQuit(char *);    PATCH_MEMBER(int, ChatChannelQuit, char *, 0x480320);
    void ChatChannelList();    PATCH_MEMBER(void, ChatChannelList, , 0x4803E0);
    int DBLoad();    PATCH_MEMBER(int, DBLoad, , 0x472870);
    int DBSave(CNSDbManager::SAVEPCMODE);    PATCH_MEMBER(int, DBSave, CNSDbManager::SAVEPCMODE, 0x4733A0);
    int DBMainUserSeq(char *);    PATCH_MEMBER(int, DBMainUserSeq, char *, 0x473CA0);
    static int DBMainLastServerLoad(char *, unsigned char *, int &);    PATCH_STATIC(int, DBMainLastServerLoad, char * _COMMA unsigned char * _COMMA int &, 0x473EE0);
    static int DBMainLastServerSave(char *);    PATCH_STATIC(int, DBMainLastServerSave, char *, 0x4740F0);
    static int DBMainLastServerClear(char *);    PATCH_STATIC(int, DBMainLastServerClear, char *, 0x4742A0);
    int DBAliasRename(char *);    PATCH_MEMBER(int, DBAliasRename, char *, 0x475A80);
    int DBAliasMake(char *, unsigned char, unsigned char, unsigned char);    PATCH_MEMBER(int, DBAliasMake, char * _COMMA unsigned char _COMMA unsigned char _COMMA unsigned char, 0x475ED0);
    int DBAliasCount(int &, unsigned char &);    PATCH_MEMBER(int, DBAliasCount, int & _COMMA unsigned char &, 0x474D70);
    unsigned long DBAliasList(CPacket &);    PATCH_MEMBER(unsigned long, DBAliasList, CPacket &, 0x474730);
    int DBAliasInsert(char *, unsigned char, unsigned char, unsigned char);    PATCH_MEMBER(int, DBAliasInsert, char * _COMMA unsigned char _COMMA unsigned char _COMMA unsigned char, 0x4762D0);
    int DBAliasDelete(char *);    PATCH_MEMBER(int, DBAliasDelete, char *, 0x4765E0);
    int DBAliasSeq(char *, int &);    PATCH_MEMBER(int, DBAliasSeq, char * _COMMA int &, 0x475160);
    int DBAliasLog(char, char *, int);    PATCH_MEMBER(int, DBAliasLog, char _COMMA char * _COMMA int, 0x476B90);
    int DBPcSave();    PATCH_MEMBER(int, DBPcSave, , 0x476920);
    int DBStatusUpdate();    PATCH_MEMBER(int, DBStatusUpdate, , 0x476E70);
    int DBJobUpdate();    PATCH_MEMBER(int, DBJobUpdate, , 0x477000);
    int DBRaceUpdate();    PATCH_MEMBER(int, DBRaceUpdate, , 0x477150);
    int DBGoldUpdate();    PATCH_MEMBER(int, DBGoldUpdate, , 0x4772B0);
    int DBBindPosUpdate();    PATCH_MEMBER(int, DBBindPosUpdate, , 0x477400);
    int DBTameMobSave(unsigned long);    PATCH_MEMBER(int, DBTameMobSave, unsigned long, 0x477940);
    int DBTameMobLoad();    PATCH_MEMBER(int, DBTameMobLoad, , 0x477570);
    int DBTameMobInsert(unsigned short);    PATCH_MEMBER(int, DBTameMobInsert, unsigned short, 0x477B90);
    int DBPetCreate();    PATCH_MEMBER(int, DBPetCreate, , 0x47B0B0);
    int DBPetCreate2();    PATCH_MEMBER(int, DBPetCreate2, , 0x47B220);
    int DBPetLoad();    PATCH_MEMBER(int, DBPetLoad, , 0x47B340);
    int DBPetSave();    PATCH_MEMBER(int, DBPetSave, , 0x47B5A0);
    unsigned long DBItemCount(unsigned short);    PATCH_MEMBER(unsigned long, DBItemCount, unsigned short, 0x477E00);
    int DBItemLoad();    PATCH_MEMBER(int, DBItemLoad, , 0x477F70);
    int DBItemInsert(CNSItem *, int);    PATCH_MEMBER(int, DBItemInsert, CNSItem * _COMMA int, 0x478730);
    int DBItemUpdate(CNSItem *);    PATCH_MEMBER(int, DBItemUpdate, CNSItem *, 0x479040);
    int DBItemUpdatePos(CNSItem *);    PATCH_MEMBER(int, DBItemUpdatePos, CNSItem *, 0x478B90);
    int DBItemUpdateCount(CNSItem *);    PATCH_MEMBER(int, DBItemUpdateCount, CNSItem *, 0x478D10);
    int DBItemUpdatePosCount(CNSItem *);    PATCH_MEMBER(int, DBItemUpdatePosCount, CNSItem *, 0x478E90);
    int DBItemLog(char, char *, unsigned long, int, unsigned short, unsigned char, int);    PATCH_MEMBER(int, DBItemLog, char _COMMA char * _COMMA unsigned long _COMMA int _COMMA unsigned short _COMMA unsigned char _COMMA int, 0x478A30);
    int DBItemDelete(int);    PATCH_MEMBER(int, DBItemDelete, int, 0x4792D0);
    int DBItemDeleteAll();    PATCH_MEMBER(int, DBItemDeleteAll, , 0x479420);
    int DBItemBasicInsert(unsigned char, unsigned char);    PATCH_MEMBER(int, DBItemBasicInsert, unsigned char _COMMA unsigned char, 0x479560);
    int DBItemCreateAdd(unsigned short, unsigned char);    PATCH_MEMBER(int, DBItemCreateAdd, unsigned short _COMMA unsigned char, 0x4785C0);
    int DBItemCreateEquip(CNSEquipment::EQUIPMENTTYPE, unsigned short);    PATCH_MEMBER(int, DBItemCreateEquip, CNSEquipment::EQUIPMENTTYPE _COMMA unsigned short, 0x478630);
    int DBSkillLoad();    PATCH_MEMBER(int, DBSkillLoad, , 0x479BA0);
    int DBSkillInsert(CNSSkill *);    PATCH_MEMBER(int, DBSkillInsert, CNSSkill *, 0x479EB0);
    int DBSkillUpdate(CNSSkill *);    PATCH_MEMBER(int, DBSkillUpdate, CNSSkill *, 0x47A190);
    int DBSkillDelete(CNSSkill *);    PATCH_MEMBER(int, DBSkillDelete, CNSSkill *, 0x47A040);
    int DBProductLoad();    PATCH_MEMBER(int, DBProductLoad, , 0x47A330);
    int DBProductInsert(unsigned short);    PATCH_MEMBER(int, DBProductInsert, unsigned short, 0x47A540);
    int DBQuestLoad();    PATCH_MEMBER(int, DBQuestLoad, , 0x47A690);
    int DBQuestInsert(unsigned short);    PATCH_MEMBER(int, DBQuestInsert, unsigned short, 0x47AC20);
    int DBQuestInsert2(CNSQuest *);    PATCH_MEMBER(int, DBQuestInsert2, CNSQuest *, 0x47AA00);
    int DBQuestUpdate(CNSQuest *);    PATCH_MEMBER(int, DBQuestUpdate, CNSQuest *, 0x47AD70);
    int DBQuestDelete(unsigned short);    PATCH_MEMBER(int, DBQuestDelete, unsigned short, 0x47AF60);
    int DBQuickBarCreate(unsigned char, unsigned char);    PATCH_MEMBER(int, DBQuickBarCreate, unsigned char _COMMA unsigned char, 0x47B790);
    int DBQuickBarLoad();    PATCH_MEMBER(int, DBQuickBarLoad, , 0x47BB30);
    int DBQuickBarSave();    PATCH_MEMBER(int, DBQuickBarSave, , 0x47BD20);
    int DBCoolTimeCreate();    PATCH_MEMBER(int, DBCoolTimeCreate, , 0x47BF20);
    int DBCoolTimeLoad();    PATCH_MEMBER(int, DBCoolTimeLoad, , 0x47C060);
    int DBCoolTimeSave();    PATCH_MEMBER(int, DBCoolTimeSave, , 0x47C520);
    int DBTeleportLoad();    PATCH_MEMBER(int, DBTeleportLoad, , 0x47CBC0);
    int DBTeleportInsert(CNSPcTeleportList::Teleport &);    PATCH_MEMBER(int, DBTeleportInsert, CNSPcTeleportList::Teleport &, 0x47CE30);
    int DBTeleportDelete(int);    PATCH_MEMBER(int, DBTeleportDelete, int, 0x47CFB0);
    int DBTeleportDeleteAll();    PATCH_MEMBER(int, DBTeleportDeleteAll, , 0x47D0F0);
    int DBFriendLoad();    PATCH_MEMBER(int, DBFriendLoad, , 0x47D230);
    int DBFriendInsert(char *, int &);    PATCH_MEMBER(int, DBFriendInsert, char * _COMMA int &, 0x47D440);
    int DBFriendDelete(int);    PATCH_MEMBER(int, DBFriendDelete, int, 0x47D620);
    int DbFellowList();    PATCH_MEMBER(int, DbFellowList, , 0x47D760);
    int DbFellowDelete(char *);    PATCH_MEMBER(int, DbFellowDelete, char *, 0x47D960);
    int DBGuildLoad();    PATCH_MEMBER(int, DBGuildLoad, , 0x47DAE0);
    int DBEquipList(int, unsigned short *);    PATCH_MEMBER(int, DBEquipList, int _COMMA unsigned short *, 0x475300);
    int DBLoginLog();    PATCH_MEMBER(int, DBLoginLog, , 0x47DCD0);
    int DBLogoutLog();    PATCH_MEMBER(int, DBLogoutLog, , 0x47DEA0);
    int DBExpLog();    PATCH_MEMBER(int, DBExpLog, , 0x476CE0);
    static int DBMemoWrite(CNSPc *, int, int, char *);    PATCH_STATIC(int, DBMemoWrite, CNSPc * _COMMA int _COMMA int _COMMA char *, 0x47E310);
    static int DBMemoWrite(CNSPc *, int, char *, char *);    PATCH_STATIC(int, DBMemoWrite, CNSPc * _COMMA int _COMMA char * _COMMA char *, 0x47E1D0);
    int DBMemoWrite(char *, char *);    PATCH_MEMBER(int, DBMemoWrite, char * _COMMA char *, 0x47E000);
    int DBMemoRead();    PATCH_MEMBER(int, DBMemoRead, , 0x47E450);
    int DBBillGetGearInfo();    PATCH_MEMBER(int, DBBillGetGearInfo, , 0x47E6D0);
    int DBBillReqBuyItem(unsigned short, char *, int, char *, char *);    PATCH_MEMBER(int, DBBillReqBuyItem, unsigned short _COMMA char * _COMMA int _COMMA char * _COMMA char *, 0x47E840);
    int DBBillAuctionBuyGear(int, int, int);    PATCH_MEMBER(int, DBBillAuctionBuyGear, int _COMMA int _COMMA int, 0x47E9C0);
    int DBDebugBillGetGear();    PATCH_MEMBER(int, DBDebugBillGetGear, , 0x47EAF0);
    int DBDebugBillIncGear(int);    PATCH_MEMBER(int, DBDebugBillIncGear, int, 0x47EC10);
    int DBDebugBillDecGear(int);    PATCH_MEMBER(int, DBDebugBillDecGear, int, 0x47ED40);
    int DBDebugBillAuctionBuyGear(int, int, int);    PATCH_MEMBER(int, DBDebugBillAuctionBuyGear, int _COMMA int _COMMA int, 0x47EE70);
    int DBDebugRankChange(unsigned char);    PATCH_MEMBER(int, DBDebugRankChange, unsigned char, 0x47EFA0);
    int DBNeoSlotCoinAdd(unsigned long);    PATCH_MEMBER(int, DBNeoSlotCoinAdd, unsigned long, 0x47F290);
    unsigned long DBNeoSlotCoinCount();    PATCH_MEMBER(unsigned long, DBNeoSlotCoinCount, , 0x47F100);
    int DBOfflineAutoSkillLoad(int &, int &, char *);    PATCH_MEMBER(int, DBOfflineAutoSkillLoad, int & _COMMA int & _COMMA char *, 0x47F450);
    int DBOfflineAutoSkillInsert();    PATCH_MEMBER(int, DBOfflineAutoSkillInsert, , 0x47F600);
    int DBOfflineAutoSkillDelete();    PATCH_MEMBER(int, DBOfflineAutoSkillDelete, , 0x47F720);
    unsigned long DBPremiumShopLimitCount(unsigned char, unsigned char);    PATCH_MEMBER(unsigned long, DBPremiumShopLimitCount, unsigned char _COMMA unsigned char, 0x47F830);
    int DBPremiumShopLimitIncCount(unsigned char, unsigned char);    PATCH_MEMBER(int, DBPremiumShopLimitIncCount, unsigned char _COMMA unsigned char, 0x47F9A0);
    int BillGetGearInfo();    PATCH_MEMBER(int, BillGetGearInfo, , 0x47FAB0);
    int BillReqBuyItem(unsigned short, char *, int);    PATCH_MEMBER(int, BillReqBuyItem, unsigned short _COMMA char * _COMMA int, 0x47FB30);
    int BillAuctionBuyGear(int, int, int);    PATCH_MEMBER(int, BillAuctionBuyGear, int _COMMA int _COMMA int, 0x47FBE0);
    static int AliasCheck(char *);    PATCH_STATIC(int, AliasCheck, char *, 0x475970);
    void OnCloseSession();    PATCH_MEMBER(void, OnCloseSession, , 0x4B4900);
    int SendMessageA(CPacket &, int);    PATCH_MEMBER(int, SendMessageA, CPacket & _COMMA int, 0x4602D0);
    void PacketAliasListMessage(CPacket &);    PATCH_MEMBER(void, PacketAliasListMessage, CPacket &, 0x460480);
    void PacketItemListMessage(CPacket &);    PATCH_MEMBER(void, PacketItemListMessage, CPacket &, 0x460300);
    void PacketEnterMessage(CPacket &);    PATCH_MEMBER(void, PacketEnterMessage, CPacket &, 0x460D90);
    void PacketSystemMessage(CPacket &, int, ...);    PATCH_MEMBER(void, PacketSystemMessage, CPacket & _COMMA int _COMMA ..., 0x4603A0);
    virtual void SendEnterMessage(int);    PATCH_MEMBER(void, SendEnterMessage, int, 0x4634E0);
    virtual void SendRecoveryMessage(int, int);    PATCH_MEMBER(void, SendRecoveryMessage, int _COMMA int, 0x462B40);
    virtual void SendMoveMessage(unsigned long, int);    PATCH_MEMBER(void, SendMoveMessage, unsigned long _COMMA int, 0x462D40);
    void SendStatusMessage(int);    PATCH_MEMBER(void, SendStatusMessage, int, 0x4614E0);
    virtual void SendLeaveMessage();    PATCH_MEMBER(void, SendLeaveMessage, , 0x463560);
    int SendChatActionMessage(unsigned long, int);    PATCH_MEMBER(int, SendChatActionMessage, unsigned long _COMMA int, 0x460670);
    void SendChatActionMessage(unsigned long);    PATCH_MEMBER(void, SendChatActionMessage, unsigned long, 0x460520);
    void SendChatMessage(int, unsigned short, char *, ...);    PATCH_MEMBER(void, SendChatMessage, int _COMMA unsigned short _COMMA char * _COMMA ..., 0x460720);
    void SendTipMessage(char *);    PATCH_MEMBER(void, SendTipMessage, char *, 0x4605E0);
    void SendNotifyMessageA(int, unsigned short, char *, ...);    PATCH_MEMBER(void, SendNotifyMessageA, int _COMMA unsigned short _COMMA char * _COMMA ..., 0x460810);
    void SendWarpMessage(unsigned char, unsigned short, unsigned short);    PATCH_MEMBER(void, SendWarpMessage, unsigned char _COMMA unsigned short _COMMA unsigned short, 0x460920);
    void SendPetEnterMessage(unsigned long);    PATCH_MEMBER(void, SendPetEnterMessage, unsigned long, 0x4635E0);
    void SendPetLeaveMessage(unsigned long);    PATCH_MEMBER(void, SendPetLeaveMessage, unsigned long, 0x463670);
    void SendPetStatusMessage();    PATCH_MEMBER(void, SendPetStatusMessage, , 0x460C30);
    void SendSystemMessage(char *, ...);    PATCH_MEMBER(void, SendSystemMessage, char * _COMMA ..., 0x461A00);
    void SendSystemMessage(int, ...);    PATCH_MEMBER(void, SendSystemMessage, int _COMMA ..., 0x4618F0);
    void SendCenterMessage(unsigned char, char *, ...);    PATCH_MEMBER(void, SendCenterMessage, unsigned char _COMMA char * _COMMA ..., 0x461CF0);
    void SendCenterMessage(unsigned char, int, ...);    PATCH_MEMBER(void, SendCenterMessage, unsigned char _COMMA int _COMMA ..., 0x461AD0);
    void SendCenterMessageEx(unsigned char, unsigned char, int, ...);    PATCH_MEMBER(void, SendCenterMessageEx, unsigned char _COMMA unsigned char _COMMA int _COMMA ..., 0x461BE0);
    void SendPetNotifyMessage();    PATCH_MEMBER(void, SendPetNotifyMessage, , 0x460A20);
    void SendStartMessage();    PATCH_MEMBER(void, SendStartMessage, , 0x460A70);
    void SendPetMessage(int, int, ...);    PATCH_MEMBER(void, SendPetMessage, int _COMMA int _COMMA ..., 0x461DC0);
    void SendPetMessage(int, char *, ...);    PATCH_MEMBER(void, SendPetMessage, int _COMMA char * _COMMA ..., 0x461FF0);
    void SendLevelUpMessage(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);    PATCH_MEMBER(void, SendLevelUpMessage, unsigned char _COMMA unsigned char _COMMA unsigned char _COMMA unsigned char _COMMA unsigned char, 0x462190);
    void SendSkillListMessage();    PATCH_MEMBER(void, SendSkillListMessage, , 0x462260);
    void SendSkillExpMessage(unsigned long);    PATCH_MEMBER(void, SendSkillExpMessage, unsigned long, 0x45EB70);
    void SendSkillExpMessage(unsigned short, unsigned short);    PATCH_MEMBER(void, SendSkillExpMessage, unsigned short _COMMA unsigned short, 0x462390);
    void SendSkillLevelUpMessage(unsigned short, unsigned char);    PATCH_MEMBER(void, SendSkillLevelUpMessage, unsigned short _COMMA unsigned char, 0x462430);
    void SendQuestListMessage();    PATCH_MEMBER(void, SendQuestListMessage, , 0x4624D0);
    void SendTeleportListMessage(unsigned short);    PATCH_MEMBER(void, SendTeleportListMessage, unsigned short, 0x4625A0);
    void SendFriendListMessage(int);    PATCH_MEMBER(void, SendFriendListMessage, int, 0x462680);
    void SendQuickBarListMessage();    PATCH_MEMBER(void, SendQuickBarListMessage, , 0x462AC0);
    void SendMoveSyncMessage(unsigned long);    PATCH_MEMBER(void, SendMoveSyncMessage, unsigned long, 0x462EC0);
    void SendAutoRunStopMessage();    PATCH_MEMBER(void, SendAutoRunStopMessage, , 0x463020);
    void SendAttackMessage(unsigned long, unsigned char, unsigned short, unsigned char, unsigned long);    PATCH_MEMBER(void, SendAttackMessage, unsigned long _COMMA unsigned char _COMMA unsigned short _COMMA unsigned char _COMMA unsigned long, 0x4630E0);
    void SendExpMessage(unsigned long, unsigned long, unsigned short);    PATCH_MEMBER(void, SendExpMessage, unsigned long _COMMA unsigned long _COMMA unsigned short, 0x4632F0);
    void SendExpMessage_Exp2(unsigned long, unsigned long, unsigned short);    PATCH_MEMBER(void, SendExpMessage_Exp2, unsigned long _COMMA unsigned long _COMMA unsigned short, 0x463200);
    void SendDeadMessage();    PATCH_MEMBER(void, SendDeadMessage, , 0x463700);
    void SendItemAddMessage(CNSItem *);    PATCH_MEMBER(void, SendItemAddMessage, CNSItem *, 0x463780);
    void SendItemDeleteMessage(unsigned long);    PATCH_MEMBER(void, SendItemDeleteMessage, unsigned long, 0x463810);
    void SendItemUpdateMessage(CNSItem *);    PATCH_MEMBER(void, SendItemUpdateMessage, CNSItem *, 0x4638A0);
    void SendItemPickupMessage(unsigned long, CNSItem *);    PATCH_MEMBER(void, SendItemPickupMessage, unsigned long _COMMA CNSItem *, 0x463930);
    void SendSkillAddMessage(CNSSkill *);    PATCH_MEMBER(void, SendSkillAddMessage, CNSSkill *, 0x463B30);
    void SendSkillDeleteMessage(CNSSkill *);    PATCH_MEMBER(void, SendSkillDeleteMessage, CNSSkill *, 0x463CF0);
    void SendSkillUpdateMessage(CNSSkill *);    PATCH_MEMBER(void, SendSkillUpdateMessage, CNSSkill *, 0x463D90);
    void SendGoldChangeMessage();    PATCH_MEMBER(void, SendGoldChangeMessage, , 0x463A10);
    void SendRealmPointChangeMessage();    PATCH_MEMBER(void, SendRealmPointChangeMessage, , 0x463AA0);
    void SendItemListMessage();    PATCH_MEMBER(void, SendItemListMessage, , 0x463F50);
    void SendProductListMessage(unsigned char, unsigned long);    PATCH_MEMBER(void, SendProductListMessage, unsigned char _COMMA unsigned long, 0x463FB0);
    void SendMaterialListMessage(unsigned char, unsigned long);    PATCH_MEMBER(void, SendMaterialListMessage, unsigned char _COMMA unsigned long, 0x464210);
    void SendProductDescriptionMessage(unsigned short);    PATCH_MEMBER(void, SendProductDescriptionMessage, unsigned short, 0x464350);
    void SendPcShopListMessage(int);    PATCH_MEMBER(void, SendPcShopListMessage, int, 0x462750);
    void SendGuildListMessage(unsigned long, int);    PATCH_MEMBER(void, SendGuildListMessage, unsigned long _COMMA int, 0x462850);
    void SendGuildInfoMessage();    PATCH_MEMBER(void, SendGuildInfoMessage, , 0x462930);
    void SendCashInfoMessage();    PATCH_MEMBER(void, SendCashInfoMessage, , 0x464290);
    void SendTitleListMessage();    PATCH_MEMBER(void, SendTitleListMessage, , 0x4629F0);
    void SendDelayedMessage();    PATCH_MEMBER(void, SendDelayedMessage, , 0x484B60);
    void OnTrace(CNSCharacter *);    PATCH_MEMBER(void, OnTrace, CNSCharacter *, 0x45DF00);
    void OnDead(unsigned long);    PATCH_MEMBER(void, OnDead, unsigned long, 0x4716F0);
    virtual void OnStart(unsigned long);    PATCH_MEMBER(void, OnStart, unsigned long, 0x47FC00);
    virtual void OnStop(unsigned long);    PATCH_MEMBER(void, OnStop, unsigned long, 0x47FC50);
    int TraceTarget(CNSCharacter *, unsigned short, unsigned long);    PATCH_MEMBER(int, TraceTarget, CNSCharacter * _COMMA unsigned short _COMMA unsigned long, 0x45EE80);
    unsigned long TraceLootTarget();    PATCH_MEMBER(unsigned long, TraceLootTarget, , 0x45EF30);
    int PartyQuit();    PATCH_MEMBER(int, PartyQuit, , 0x45F120);
    void Action();    PATCH_MEMBER(void, Action, , 0x4805F0);
    CNSNpc * _CallMob(unsigned short, unsigned short);    PATCH_MEMBER(CNSNpc *, CallMob, unsigned short _COMMA unsigned short, 0x480000);
    CNSNpc * _CallMob(unsigned short, unsigned short, unsigned short, unsigned short, unsigned short);    PATCH_MEMBER(CNSNpc *, CallMob, unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short, 0x47FF40);
    CNSNpc * _CallNpc(unsigned short, unsigned short);    PATCH_MEMBER(CNSNpc *, CallNpc, unsigned short _COMMA unsigned short, 0x4800F0);
    int DebugCallNpc(unsigned short, unsigned short);    PATCH_MEMBER(int, DebugCallNpc, unsigned short _COMMA unsigned short, 0x47FE40);
    int DebugGiveItem(unsigned short, unsigned char);    PATCH_MEMBER(int, DebugGiveItem, unsigned short _COMMA unsigned char, 0x480460);
    void DebugResetLevel();    PATCH_MEMBER(void, DebugResetLevel, , 0x4804C0);
    void DebugInvenList();    PATCH_MEMBER(void, DebugInvenList, , 0x480570);
    class CNSPcStateGlobal m_ActionGlobal;//this+0x1F780
    class CNSPcStateAttack m_ActionAttack;//this+0x1F79C
    unsigned long m_dwGuildId;//this+0x1F7B8
    unsigned long m_dwPartyId;//this+0x1F7BC
    unsigned long m_dwStickObjectId;//this+0x1F7C0
    unsigned long m_dwPetObjectId;//this+0x1F7C4
    unsigned long m_dwTalkNpcObjectId;//this+0x1F7C8
    unsigned long m_dwPetObjectIdArray[0x4];//this+0x1F7CC
    int m_bLogin;//this+0x1F7DC
    int m_bCheckDoubleConnect;//this+0x1F7E0
    int m_nLoginSeq;//this+0x1F7E4
    unsigned long m_dwLoginTime;//this+0x1F7E8
    unsigned long m_dwLastSaveTime;//this+0x1F7EC
    unsigned long m_dwCloseSessionTime;//this+0x1F7F0
    unsigned long m_dwDeadTime;//this+0x1F7F4
    unsigned long m_dwLastHourTime;//this+0x1F7F8
    unsigned long m_dwLoginCheckTime;//this+0x1F7FC
    int m_nLoginCheckCount;//this+0x1F800
    unsigned long m_dwLeaveTime;//this+0x1F804
    unsigned long m_dwLeaveCheckTime;//this+0x1F808
    unsigned long m_dwDisconnectTime;//this+0x1F80C
    unsigned long m_dwTickCount;//this+0x1F810
    unsigned long m_dwInstantKey;//this+0x1F814
    unsigned long m_btPrevMapAttr;//this+0x1F818
    unsigned long m_dwLastAttacker;//this+0x1F81C
    int m_bGhostMode;//this+0x1F820
    int m_bSuperMode;//this+0x1F824
    unsigned long m_dwLogExp;//this+0x1F828
    unsigned long m_dwLogGold;//this+0x1F82C
    unsigned long m_dwLogNs;//this+0x1F830
    unsigned long m_dwLastDeadExp;//this+0x1F834
    unsigned long m_dwLastSkillStudy;//this+0x1F838
    int m_bPcBangCheck;//this+0x1F83C
    struct tagTIMESTAMP_STRUCT m_tsRegDate;//this+0x1F840
    class NSPOINT2 m_cellSave;//this+0x1F850
    class NSPOINT2 m_cellNotStuck;//this+0x1F854
    unsigned short m_wChatChannelArray[0xA];//this+0x1F858
    int m_bCheckStatusData;//this+0x1F86C
    static void * operator new(unsigned int);    //PATCH_STATIC(void *, operator new, unsigned int, 0x406230);
    static void operator delete(void *, unsigned int);    //PATCH_STATIC(void, operator delete, void * _COMMA unsigned int, 0x406240);
    CNSPc & operator=(const CNSPc &);
    //virtual void * __vecDelDtor(unsigned int);

    struct _Invoke {
        //PATCH_STATIC_INVOKE(unsigned char, GetSimpleJob, unsigned char);
        //PATCH_STATIC_INVOKE(unsigned char, GetBasicJob, unsigned char);
        //PATCH_STATIC_INVOKE(int, GetStartRegion, unsigned char _COMMA unsigned char _COMMA unsigned char & _COMMA NSPOINT2 &);
        //PATCH_STATIC_INVOKE(unsigned char, ConvertRaceToRegion, unsigned char);
        //PATCH_STATIC_INVOKE(int, IsTargetOtherRealm, CNSCharacter * _COMMA CNSCharacter *);
        //PATCH_STATIC_INVOKE(int, IsMineRider, unsigned short);
        PATCH_MEMBER_INVOKE(CNSPc &, CNSPc, Constructor, CNSSessionPc *);
        PATCH_MEMBER_INVOKE(void, CNSPc, Destructor, );
        PATCH_MEMBER_INVOKE(void, CNSPc, Clear, int);
        //PATCH_MEMBER_INVOKE(int, CNSPc, OnGameEnter, );
        //PATCH_MEMBER_INVOKE(void, CNSPc, OnBuff, unsigned long _COMMA int);
        //PATCH_MEMBER_INVOKE(void, CNSPc, OnLogOut, int);
        //PATCH_MEMBER_INVOKE(void, CNSPc, OnSessionMode, );
        //PATCH_MEMBER_INVOKE(void, CNSPc, OnMoveServer, unsigned char _COMMA NSPOINT2);
        //PATCH_MEMBER_INVOKE(void, CNSPc, OnDisconnect, );
        //PATCH_MEMBER_INVOKE(void, CNSPc, OnHitLastDamage, CNSCharacter *);
        //PATCH_MEMBER_INVOKE(void, CNSPc, GetPswInfo, CNSPc::PSWTYPE & _COMMA unsigned char & _COMMA unsigned char & _COMMA unsigned char &);
        PATCH_MEMBER_INVOKE(void, CNSPc, Reset, int);
        //PATCH_MEMBER_INVOKE(int, CNSPc, ResetSiegeWeapon, int _COMMA unsigned short _COMMA int);
        //PATCH_MEMBER_INVOKE(void, CNSPc, Login, );
        //PATCH_MEMBER_INVOKE(unsigned short, CNSPc, HitDamage, CNSCharacter * _COMMA unsigned short _COMMA CNSObject::HITTYPE _COMMA int);
        //PATCH_MEMBER_INVOKE(int, CNSPc, IsLogin, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, IsPartyEnableMember, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, IsItemFreeze, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, IsPcBang, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, IsSessionGameMode, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, IsExistTameMob, );
        //PATCH_MEMBER_INVOKE(void, CNSPc, ToggleSuperMode, );
        //PATCH_MEMBER_INVOKE(void, CNSPc, ToggleGhost, );
        //PATCH_MEMBER_INVOKE(void, CNSPc, SetGuildId, unsigned long);
        //PATCH_MEMBER_INVOKE(void, CNSPc, SetPartyId, unsigned long);
        //PATCH_MEMBER_INVOKE(void, CNSPc, SetUserId, int _COMMA char *);
        //PATCH_MEMBER_INVOKE(void, CNSPc, SetUserAlias, char *);
        //PATCH_MEMBER_INVOKE(int, CNSPc, GetUserSeq, );
        //PATCH_MEMBER_INVOKE(void, CNSPc, SetStickObjectId, unsigned long);
        //PATCH_MEMBER_INVOKE(unsigned long, CNSPc, GetStickObjectId, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, GetStickDestination, NSPOINT2 &);
        //PATCH_MEMBER_INVOKE(void, CNSPc, CancelStickPc, );
        //PATCH_MEMBER_INVOKE(void, CNSPc, SetDeadTime, unsigned long);
        //PATCH_MEMBER_INVOKE(void, CNSPc, SetLeaveTime, );
        //PATCH_MEMBER_INVOKE(void, CNSPc, SetDisconnectTime, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, SetTitle, unsigned short);
        //PATCH_MEMBER_INVOKE(int, CNSPc, IsAutoRunMode, );
        //PATCH_MEMBER_INVOKE(void, CNSPc, StartAutoRunMode, );
        //PATCH_MEMBER_INVOKE(void, CNSPc, EndAutoRunMode, );
        //PATCH_MEMBER_INVOKE(char *, CNSPc, GetUserId, );
        //PATCH_MEMBER_INVOKE(char *, CNSPc, GetUserAlias, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, GetUserAliasSeq, );
        //PATCH_MEMBER_INVOKE(unsigned long, CNSPc, GetGuildId, );
        //PATCH_MEMBER_INVOKE(unsigned long, CNSPc, GetPartyId, );
        //PATCH_MEMBER_INVOKE(unsigned char, CNSPc, GetRank, );
        //PATCH_MEMBER_INVOKE(unsigned long, CNSPc, GetDeadExp, );
        //PATCH_MEMBER_INVOKE(unsigned short, CNSPc, GetNs, );
        //PATCH_MEMBER_INVOKE(unsigned short, CNSPc, GetNsMaxCharge, );
        //PATCH_MEMBER_INVOKE(unsigned short, CNSPc, GetNsCharge, );
        //PATCH_MEMBER_INVOKE(void, CNSPc, SetTransPos, );
        //PATCH_MEMBER_INVOKE(unsigned short, CNSPc, UseMp, unsigned short);
        //PATCH_MEMBER_INVOKE(unsigned short, CNSPc, UseSta, unsigned short);
        //PATCH_MEMBER_INVOKE(unsigned char, CNSPc, GetRace, );
        //PATCH_MEMBER_INVOKE(unsigned char, CNSPc, GetRaceRegion, );
        //PATCH_MEMBER_INVOKE(unsigned char, CNSPc, GetJob, );
        //PATCH_MEMBER_INVOKE(unsigned char, CNSPc, GetBindRegion, );
        //PATCH_MEMBER_INVOKE(NSPOINT2, CNSPc, GetBindCell, );
        //PATCH_MEMBER_INVOKE(unsigned char, CNSPc, GetTransRegion, );
        //PATCH_MEMBER_INVOKE(unsigned long, CNSPc, GetLastDeadExp, );
        //PATCH_MEMBER_INVOKE(void, CNSPc, SetLastDeadExp, unsigned long);
        //PATCH_MEMBER_INVOKE(unsigned char, CNSPc, GetEquipMaxSpecialGrade, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, GetEquipMaxSpecialGradePer, );
        //PATCH_MEMBER_INVOKE(CNSSessionPc *, CNSPc, GetSession, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, CloseConnection, );
        //PATCH_MEMBER_INVOKE(void, CNSPc, SetNpcTalkObjectId, unsigned long);
        //PATCH_MEMBER_INVOKE(unsigned long, CNSPc, CheckInstantKey, unsigned char);
        PATCH_MEMBER_INVOKE(CNSNpc *, CNSPc, PetAdd, CNSPc::PETTYPE _COMMA unsigned short _COMMA NSPOINT2 & _COMMA unsigned short _COMMA unsigned char _COMMA unsigned short _COMMA unsigned long _COMMA char * _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char);
        //PATCH_MEMBER_INVOKE(int, CNSPc, PetTaming, unsigned long _COMMA unsigned short _COMMA unsigned char _COMMA unsigned short _COMMA unsigned long);
        //PATCH_MEMBER_INVOKE(CNSNpc *, CNSPc, PetSummoning, unsigned short _COMMA unsigned short _COMMA unsigned char _COMMA unsigned short _COMMA unsigned long);
        //PATCH_MEMBER_INVOKE(int, CNSPc, PetTameMobLoad, unsigned short _COMMA char * _COMMA unsigned short _COMMA unsigned short);
        //PATCH_MEMBER_INVOKE(CNSNpc *, CNSPc, PetLoad, unsigned char _COMMA unsigned char _COMMA unsigned char _COMMA char * _COMMA unsigned short);
        //PATCH_MEMBER_INVOKE(CNSNpc *, CNSPc, PetLoad, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, PetUpgrade, unsigned char);
        //PATCH_MEMBER_INVOKE(int, CNSPc, PetChangeLevel, unsigned char);
        //PATCH_MEMBER_INVOKE(int, CNSPc, PetRebirth, unsigned char);
        //PATCH_MEMBER_INVOKE(int, CNSPc, PetDelete, unsigned long);
        //PATCH_MEMBER_INVOKE(void, CNSPc, PetDeleteAll, int);
        //PATCH_MEMBER_INVOKE(int, CNSPc, PetStateChange, CNSNpc * _COMMA unsigned char);
        //PATCH_MEMBER_INVOKE(int, CNSPc, PetAttack, CNSNpc * _COMMA CNSCharacter *);
        //PATCH_MEMBER_INVOKE(int, CNSPc, PetChange, unsigned char _COMMA unsigned char _COMMA unsigned char _COMMA int);
        //PATCH_MEMBER_INVOKE(int, CNSPc, PetFood, unsigned long);
        //PATCH_MEMBER_INVOKE(void, CNSPc, PetAddExpPoint, CNSNpc * _COMMA unsigned short);
        //PATCH_MEMBER_INVOKE(float, CNSPc, PetGetExpPercent, unsigned long);
        //PATCH_MEMBER_INVOKE(unsigned char, CNSPc, PetGetExpPercent, );
        //PATCH_MEMBER_INVOKE(void, CNSPc, PetSetExpPercent, unsigned char);
        //PATCH_MEMBER_INVOKE(void, CNSPc, PetDebugExp, );
        //PATCH_MEMBER_INVOKE(void, CNSPc, PetDebugKill, );
        //PATCH_MEMBER_INVOKE(void, CNSPc, PetSetName, CNSNpc * _COMMA char *);
        //PATCH_MEMBER_INVOKE(void, CNSPc, PetInfoSave, );
        //PATCH_MEMBER_INVOKE(unsigned long, CNSPc, PetTameInfoSave, );
        //PATCH_MEMBER_INVOKE(void, CNSPc, PetHide, );
        //PATCH_MEMBER_INVOKE(CNSNpc *, CNSPc, PetGetObject, );
        //PATCH_MEMBER_INVOKE(CNSNpc *, CNSPc, PetGetMobObject, );
        //PATCH_MEMBER_INVOKE(CNSPc::PETTYPE, CNSPc, PetGetType, unsigned long);
        //PATCH_MEMBER_INVOKE(unsigned long, CNSPc, PetGetObjectId, CNSPc::PETTYPE);
        //PATCH_MEMBER_INVOKE(void, CNSPc, PetSetObjectId, CNSPc::PETTYPE _COMMA unsigned long);
        //PATCH_MEMBER_INVOKE(unsigned long, CNSPc, ItemList, CPacket & _COMMA int);
        //PATCH_MEMBER_INVOKE(unsigned char, CNSPc, ItemEquipDescription, CNSItem * _COMMA CNSItem * *);
        //PATCH_MEMBER_INVOKE(unsigned long, CNSPc, _ItemAdd, unsigned short _COMMA unsigned char _COMMA char * _COMMA unsigned long _COMMA int);
        //PATCH_MEMBER_INVOKE(int, CNSPc, ItemAdd, unsigned short _COMMA unsigned char _COMMA char * _COMMA unsigned long _COMMA int);
        //PATCH_MEMBER_INVOKE(int, CNSPc, ItemAddToUserAlias, unsigned short _COMMA unsigned char _COMMA char *);
        //PATCH_MEMBER_INVOKE(int, CNSPc, ItemPickup, unsigned long _COMMA unsigned long);
        //PATCH_MEMBER_INVOKE(void, CNSPc, ItemPickupAll, CNSNpc *);
        //PATCH_MEMBER_INVOKE(int, CNSPc, ItemMove, unsigned long _COMMA unsigned long _COMMA int);
        //PATCH_MEMBER_INVOKE(int, CNSPc, ItemEquipCheck, CNSItem *);
        //PATCH_MEMBER_INVOKE(int, CNSPc, ItemEquipCheck2, CNSEquipment::EQUIPMENTTYPE _COMMA CNSItem *);
        //PATCH_MEMBER_INVOKE(CNSEquipment::EQUIPMENTTYPE, CNSPc, ItemEquipRemove, CNSItem *);
        //PATCH_MEMBER_INVOKE(int, CNSPc, ItemEquip, CNSEquipment::EQUIPMENTTYPE _COMMA unsigned long);
        //PATCH_MEMBER_INVOKE(int, CNSPc, ItemUse, unsigned short);
        //PATCH_MEMBER_INVOKE(int, CNSPc, ItemUse, unsigned long _COMMA unsigned char & _COMMA unsigned char);
        //PATCH_MEMBER_INVOKE(int, CNSPc, ItemUseDb, CNSItem * _COMMA char _COMMA char *);
        //PATCH_MEMBER_INVOKE(int, CNSPc, ItemUseDb, unsigned short _COMMA unsigned char);
        //PATCH_MEMBER_INVOKE(int, CNSPc, ItemDelete, unsigned long _COMMA unsigned char);
        //PATCH_MEMBER_INVOKE(int, CNSPc, ItemCombine, unsigned long _COMMA unsigned long _COMMA unsigned char & _COMMA unsigned char &);
        //PATCH_MEMBER_INVOKE(int, CNSPc, ItemDivide, unsigned long _COMMA unsigned char _COMMA unsigned long &);
        //PATCH_MEMBER_INVOKE(int, CNSPc, ItemUpgrade, unsigned long _COMMA unsigned long _COMMA unsigned long _COMMA int _COMMA int);
        //PATCH_MEMBER_INVOKE(int, CNSPc, ItemCoreDivide, CNSItem * _COMMA CNSItem * _COMMA int);
        //PATCH_MEMBER_INVOKE(void, CNSPc, ItemPrintPremium, int);
        //PATCH_MEMBER_INVOKE(void, CNSPc, ItemCheckPremium, );
        //PATCH_MEMBER_INVOKE(void, CNSPc, EventItemAdd, unsigned short _COMMA unsigned char _COMMA unsigned long);
        //PATCH_MEMBER_INVOKE(int, CNSPc, GetItemRecombinationExpense, unsigned long _COMMA unsigned long & _COMMA unsigned short & _COMMA unsigned char &);
        //PATCH_MEMBER_INVOKE(int, CNSPc, ItemRecombination, unsigned long _COMMA int);
        //PATCH_MEMBER_INVOKE(int, CNSPc, ItemSwap, unsigned long _COMMA int);
        //PATCH_MEMBER_INVOKE(int, CNSPc, ItemDeleteAll, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, ItemGathering, unsigned long _COMMA unsigned long _COMMA unsigned long _COMMA int);
        //PATCH_MEMBER_INVOKE(int, CNSPc, ItemMining, unsigned long _COMMA unsigned long _COMMA unsigned long _COMMA int);
        //PATCH_MEMBER_INVOKE(int, CNSPc, ItemUnlock, unsigned long _COMMA unsigned long _COMMA unsigned long);
        //PATCH_MEMBER_INVOKE(int, CNSPc, PremiumItemSell, unsigned short);
        //PATCH_MEMBER_INVOKE(unsigned long, CNSPc, SkillList, CPacket &);
        //PATCH_MEMBER_INVOKE(void, CNSPc, DebugSkillList, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, SkillCast, unsigned short _COMMA unsigned long);
        //PATCH_MEMBER_INVOKE(int, CNSPc, SkillUse, );
        //PATCH_MEMBER_INVOKE(void, CNSPc, SkillCancel, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, SkillStudy, unsigned short);
        PATCH_MEMBER_INVOKE(int, CNSPc, SkillScroll, unsigned long _COMMA unsigned char);
        //PATCH_MEMBER_INVOKE(int, CNSPc, SkillBlockCall, unsigned long _COMMA unsigned short);
        //PATCH_MEMBER_INVOKE(int, CNSPc, CheckBlock, );
        //PATCH_MEMBER_INVOKE(CNSPcParty *, CNSPc, PartyCreate, char * _COMMA char * _COMMA CNSPcParty::LOOTMODE);
        //PATCH_MEMBER_INVOKE(int, CNSPc, MoveTo, unsigned char _COMMA NSPOINT2 & _COMMA NSPOINT2 &);
        //PATCH_MEMBER_INVOKE(int, CNSPc, MoveTo, NSPOINT2 &);
        //PATCH_MEMBER_INVOKE(void, CNSPc, _Stop, unsigned long);
        //PATCH_MEMBER_INVOKE(void, CNSPc, Stop, unsigned long);
        //PATCH_MEMBER_INVOKE(void, CNSPc, Stand, );
        PATCH_MEMBER_INVOKE(int, CNSPc, Warp, unsigned short _COMMA unsigned short _COMMA unsigned char);
        //PATCH_MEMBER_INVOKE(void, CNSPc, WarpParty, unsigned short _COMMA unsigned short _COMMA unsigned char);
        //PATCH_MEMBER_INVOKE(void, CNSPc, WarpGuild, unsigned short _COMMA unsigned short _COMMA unsigned char);
        //PATCH_MEMBER_INVOKE(int, CNSPc, WarpInstant, unsigned char _COMMA unsigned short _COMMA unsigned short);
        //PATCH_MEMBER_INVOKE(void, CNSPc, WarpRaceRegion, );
        //PATCH_STATIC_INVOKE(void, DBWarpRaceRegion, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, AttackCheck, CNSCharacter *);
        //PATCH_MEMBER_INVOKE(void, CNSPc, Attack, CNSCharacter * _COMMA unsigned long);
        //PATCH_MEMBER_INVOKE(unsigned short, CNSPc, AttackSiegeWeaponMode, CNSCharacter * _COMMA unsigned short);
        //PATCH_MEMBER_INVOKE(void, CNSPc, Rebirth, unsigned char);
        //PATCH_MEMBER_INVOKE(void, CNSPc, Rebirth2, );
        //PATCH_MEMBER_INVOKE(void, CNSPc, UsePhoenix, unsigned short);
        //PATCH_MEMBER_INVOKE(int, CNSPc, IsEquipRemoveAll, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, ChangeRace, unsigned char);
        //PATCH_MEMBER_INVOKE(int, CNSPc, ChangeBindPos, unsigned char _COMMA unsigned short _COMMA unsigned short);
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBChangeJob, unsigned char);
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBSkillMake60, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBLevelUp100, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBPSWFactory, unsigned short);
        //PATCH_MEMBER_INVOKE(int, CNSPc, LoadPath, unsigned short);
        //PATCH_MEMBER_INVOKE(int, CNSPc, MoveTranferManchine, unsigned short);
        //PATCH_MEMBER_INVOKE(void, CNSPc, RestoreCell, );
        //PATCH_MEMBER_INVOKE(void, CNSPc, AddGold, unsigned long);
        //PATCH_MEMBER_INVOKE(unsigned long, CNSPc, AddExpPoint, unsigned long _COMMA int);
        //PATCH_MEMBER_INVOKE(unsigned short, CNSPc, AddNsPoint, unsigned short _COMMA int);
        //PATCH_MEMBER_INVOKE(unsigned short, CNSPc, SuctionNsPoint, unsigned short);
        //PATCH_MEMBER_INVOKE(unsigned short, CNSPc, SuctionGold, unsigned long);
        //PATCH_MEMBER_INVOKE(void, CNSPc, AddTotalExp, unsigned char _COMMA unsigned long _COMMA unsigned long _COMMA unsigned short _COMMA int);
        //PATCH_MEMBER_INVOKE(int, CNSPc, GiveNsPoint, unsigned short);
        //PATCH_MEMBER_INVOKE(unsigned long, CNSPc, GetRealmPoint, );
        //PATCH_MEMBER_INVOKE(unsigned long, CNSPc, AddRealmPoint, unsigned long _COMMA CNSCharacter *);
        //PATCH_MEMBER_INVOKE(int, CNSPc, GiveRealmPoint, unsigned long);
        //PATCH_STATIC_INVOKE(CNSPc *, GetOriginalPcObject, CNSCharacter *);
        //PATCH_MEMBER_INVOKE(unsigned long, CNSPc, GetSkillExp, );
        //PATCH_MEMBER_INVOKE(void, CNSPc, AddSkillExpPoint, unsigned long _COMMA int);
        //PATCH_MEMBER_INVOKE(void, CNSPc, UseSkillExpPoint, unsigned long);
        //PATCH_MEMBER_INVOKE(int, CNSPc, TeleportAdd, unsigned short _COMMA char *);
        //PATCH_MEMBER_INVOKE(int, CNSPc, TeleportDelete, unsigned short _COMMA int);
        //PATCH_MEMBER_INVOKE(int, CNSPc, FriendAdd, char *);
        //PATCH_MEMBER_INVOKE(int, CNSPc, FriendDelete, char *);
        //PATCH_MEMBER_INVOKE(int, CNSPc, GuildCreate, char * _COMMA char *);
        //PATCH_MEMBER_INVOKE(int, CNSPc, GuildAddLevelUpPoint, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, GuildAddConnectPoint, );
        //PATCH_STATIC_INVOKE(float, CalcRealmPoint, unsigned char _COMMA unsigned char _COMMA CNSCharacter *);
        //PATCH_MEMBER_INVOKE(void, CNSPc, LevelUp, );
        //PATCH_MEMBER_INVOKE(unsigned long, CNSPc, LevelSetup, );
        //PATCH_STATIC_INVOKE(int, CheckDoubleConnect, char *);
        //PATCH_STATIC_INVOKE(int, CheckDoubleConnect2, char *);
        //PATCH_STATIC_INVOKE(int, CheckDoubleConnect3, char * _COMMA unsigned char);
        PATCH_STATIC_INVOKE(void, LastServerClear, char *);
        //PATCH_MEMBER_INVOKE(unsigned short, CNSPc, GetChatChannel, int);
        //PATCH_MEMBER_INVOKE(int, CNSPc, GetChatChannelIndex, unsigned short);
        //PATCH_MEMBER_INVOKE(int, CNSPc, ChatChannelJoin, char *);
        //PATCH_MEMBER_INVOKE(int, CNSPc, ChatChannelQuit, char *);
        //PATCH_MEMBER_INVOKE(void, CNSPc, ChatChannelList, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBLoad, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBSave, CNSDbManager::SAVEPCMODE);
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBMainUserSeq, char *);
        PATCH_STATIC_INVOKE(int, DBMainLastServerLoad, char * _COMMA unsigned char * _COMMA int &);
        //PATCH_STATIC_INVOKE(int, DBMainLastServerSave, char *);
        //PATCH_STATIC_INVOKE(int, DBMainLastServerClear, char *);
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBAliasRename, char *);
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBAliasMake, char * _COMMA unsigned char _COMMA unsigned char _COMMA unsigned char);
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBAliasCount, int & _COMMA unsigned char &);
        //PATCH_MEMBER_INVOKE(unsigned long, CNSPc, DBAliasList, CPacket &);
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBAliasInsert, char * _COMMA unsigned char _COMMA unsigned char _COMMA unsigned char);
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBAliasDelete, char *);
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBAliasSeq, char * _COMMA int &);
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBAliasLog, char _COMMA char * _COMMA int);
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBPcSave, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBStatusUpdate, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBJobUpdate, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBRaceUpdate, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBGoldUpdate, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBBindPosUpdate, );
        PATCH_MEMBER_INVOKE(int, CNSPc, DBTameMobSave, unsigned long);
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBTameMobLoad, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBTameMobInsert, unsigned short);
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBPetCreate, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBPetCreate2, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBPetLoad, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBPetSave, );
        //PATCH_MEMBER_INVOKE(unsigned long, CNSPc, DBItemCount, unsigned short);
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBItemLoad, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBItemInsert, CNSItem * _COMMA int);
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBItemUpdate, CNSItem *);
        PATCH_MEMBER_INVOKE(int, CNSPc, DBItemUpdatePos, CNSItem *);
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBItemUpdateCount, CNSItem *);
        PATCH_MEMBER_INVOKE(int, CNSPc, DBItemUpdatePosCount, CNSItem *);
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBItemLog, char _COMMA char * _COMMA unsigned long _COMMA int _COMMA unsigned short _COMMA unsigned char _COMMA int);
        PATCH_MEMBER_INVOKE(int, CNSPc, DBItemDelete, int);
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBItemDeleteAll, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBItemBasicInsert, unsigned char _COMMA unsigned char);
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBItemCreateAdd, unsigned short _COMMA unsigned char);
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBItemCreateEquip, CNSEquipment::EQUIPMENTTYPE _COMMA unsigned short);
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBSkillLoad, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBSkillInsert, CNSSkill *);
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBSkillUpdate, CNSSkill *);
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBSkillDelete, CNSSkill *);
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBProductLoad, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBProductInsert, unsigned short);
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBQuestLoad, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBQuestInsert, unsigned short);
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBQuestInsert2, CNSQuest *);
        PATCH_MEMBER_INVOKE(int, CNSPc, DBQuestUpdate, CNSQuest *);
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBQuestDelete, unsigned short);
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBQuickBarCreate, unsigned char _COMMA unsigned char);
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBQuickBarLoad, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBQuickBarSave, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBCoolTimeCreate, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBCoolTimeLoad, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBCoolTimeSave, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBTeleportLoad, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBTeleportInsert, CNSPcTeleportList::Teleport &);
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBTeleportDelete, int);
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBTeleportDeleteAll, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBFriendLoad, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBFriendInsert, char * _COMMA int &);
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBFriendDelete, int);
        //PATCH_MEMBER_INVOKE(int, CNSPc, DbFellowList, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, DbFellowDelete, char *);
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBGuildLoad, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBEquipList, int _COMMA unsigned short *);
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBLoginLog, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBLogoutLog, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBExpLog, );
        //PATCH_STATIC_INVOKE(int, DBMemoWrite, CNSPc * _COMMA int _COMMA int _COMMA char *);
        //PATCH_STATIC_INVOKE(int, DBMemoWrite, CNSPc * _COMMA int _COMMA char * _COMMA char *);
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBMemoWrite, char * _COMMA char *);
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBMemoRead, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBBillGetGearInfo, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBBillReqBuyItem, unsigned short _COMMA char * _COMMA int _COMMA char * _COMMA char *);
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBBillAuctionBuyGear, int _COMMA int _COMMA int);
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBDebugBillGetGear, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBDebugBillIncGear, int);
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBDebugBillDecGear, int);
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBDebugBillAuctionBuyGear, int _COMMA int _COMMA int);
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBDebugRankChange, unsigned char);
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBNeoSlotCoinAdd, unsigned long);
        //PATCH_MEMBER_INVOKE(unsigned long, CNSPc, DBNeoSlotCoinCount, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBOfflineAutoSkillLoad, int & _COMMA int & _COMMA char *);
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBOfflineAutoSkillInsert, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBOfflineAutoSkillDelete, );
        //PATCH_MEMBER_INVOKE(unsigned long, CNSPc, DBPremiumShopLimitCount, unsigned char _COMMA unsigned char);
        //PATCH_MEMBER_INVOKE(int, CNSPc, DBPremiumShopLimitIncCount, unsigned char _COMMA unsigned char);
        //PATCH_MEMBER_INVOKE(int, CNSPc, BillGetGearInfo, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, BillReqBuyItem, unsigned short _COMMA char * _COMMA int);
        //PATCH_MEMBER_INVOKE(int, CNSPc, BillAuctionBuyGear, int _COMMA int _COMMA int);
        //PATCH_STATIC_INVOKE(int, AliasCheck, char *);
        //PATCH_MEMBER_INVOKE(void, CNSPc, OnCloseSession, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, SendMessageA, CPacket & _COMMA int);
        //PATCH_MEMBER_INVOKE(void, CNSPc, PacketAliasListMessage, CPacket &);
        //PATCH_MEMBER_INVOKE(void, CNSPc, PacketItemListMessage, CPacket &);
        //PATCH_MEMBER_INVOKE(void, CNSPc, PacketEnterMessage, CPacket &);
        //PATCH_MEMBER_INVOKE(void, CNSPc, PacketSystemMessage, CPacket & _COMMA int _COMMA ...);
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendEnterMessage, int);
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendRecoveryMessage, int _COMMA int);
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendMoveMessage, unsigned long _COMMA int);
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendStatusMessage, int);
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendLeaveMessage, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, SendChatActionMessage, unsigned long _COMMA int);
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendChatActionMessage, unsigned long);
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendChatMessage, int _COMMA unsigned short _COMMA char * _COMMA ...);
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendTipMessage, char *);
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendNotifyMessageA, int _COMMA unsigned short _COMMA char * _COMMA ...);
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendWarpMessage, unsigned char _COMMA unsigned short _COMMA unsigned short);
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendPetEnterMessage, unsigned long);
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendPetLeaveMessage, unsigned long);
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendPetStatusMessage, );
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendSystemMessage, char * _COMMA ...);
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendSystemMessage, int _COMMA ...);
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendCenterMessage, unsigned char _COMMA char * _COMMA ...);
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendCenterMessage, unsigned char _COMMA int _COMMA ...);
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendCenterMessageEx, unsigned char _COMMA unsigned char _COMMA int _COMMA ...);
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendPetNotifyMessage, );
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendStartMessage, );
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendPetMessage, int _COMMA int _COMMA ...);
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendPetMessage, int _COMMA char * _COMMA ...);
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendLevelUpMessage, unsigned char _COMMA unsigned char _COMMA unsigned char _COMMA unsigned char _COMMA unsigned char);
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendSkillListMessage, );
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendSkillExpMessage, unsigned long);
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendSkillExpMessage, unsigned short _COMMA unsigned short);
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendSkillLevelUpMessage, unsigned short _COMMA unsigned char);
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendQuestListMessage, );
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendTeleportListMessage, unsigned short);
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendFriendListMessage, int);
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendQuickBarListMessage, );
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendMoveSyncMessage, unsigned long);
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendAutoRunStopMessage, );
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendAttackMessage, unsigned long _COMMA unsigned char _COMMA unsigned short _COMMA unsigned char _COMMA unsigned long);
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendExpMessage, unsigned long _COMMA unsigned long _COMMA unsigned short);
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendExpMessage_Exp2, unsigned long _COMMA unsigned long _COMMA unsigned short);
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendDeadMessage, );
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendItemAddMessage, CNSItem *);
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendItemDeleteMessage, unsigned long);
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendItemUpdateMessage, CNSItem *);
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendItemPickupMessage, unsigned long _COMMA CNSItem *);
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendSkillAddMessage, CNSSkill *);
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendSkillDeleteMessage, CNSSkill *);
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendSkillUpdateMessage, CNSSkill *);
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendGoldChangeMessage, );
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendRealmPointChangeMessage, );
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendItemListMessage, );
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendProductListMessage, unsigned char _COMMA unsigned long);
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendMaterialListMessage, unsigned char _COMMA unsigned long);
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendProductDescriptionMessage, unsigned short);
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendPcShopListMessage, int);
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendGuildListMessage, unsigned long _COMMA int);
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendGuildInfoMessage, );
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendCashInfoMessage, );
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendTitleListMessage, );
        //PATCH_MEMBER_INVOKE(void, CNSPc, SendDelayedMessage, );
        //PATCH_MEMBER_INVOKE(void, CNSPc, OnTrace, CNSCharacter *);
        //PATCH_MEMBER_INVOKE(void, CNSPc, OnDead, unsigned long);
        //PATCH_MEMBER_INVOKE(void, CNSPc, OnStart, unsigned long);
        //PATCH_MEMBER_INVOKE(void, CNSPc, OnStop, unsigned long);
        //PATCH_MEMBER_INVOKE(int, CNSPc, TraceTarget, CNSCharacter * _COMMA unsigned short _COMMA unsigned long);
        //PATCH_MEMBER_INVOKE(unsigned long, CNSPc, TraceLootTarget, );
        //PATCH_MEMBER_INVOKE(int, CNSPc, PartyQuit, );
        PATCH_MEMBER_INVOKE(void, CNSPc, Action, );
        //PATCH_MEMBER_INVOKE(CNSNpc *, CNSPc, _CallMob, unsigned short _COMMA unsigned short);
        //PATCH_MEMBER_INVOKE(CNSNpc *, CNSPc, _CallMob, unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short);
        //PATCH_MEMBER_INVOKE(CNSNpc *, CNSPc, _CallNpc, unsigned short _COMMA unsigned short);
        //PATCH_MEMBER_INVOKE(int, CNSPc, DebugCallNpc, unsigned short _COMMA unsigned short);
        //PATCH_MEMBER_INVOKE(int, CNSPc, DebugGiveItem, unsigned short _COMMA unsigned char);
        //PATCH_MEMBER_INVOKE(void, CNSPc, DebugResetLevel, );
        //PATCH_MEMBER_INVOKE(void, CNSPc, DebugInvenList, );
        ////PATCH_STATIC_INVOKE(void *, operator new, unsigned int);
        ////PATCH_STATIC_INVOKE(void, operator delete, void * _COMMA unsigned int);
    };
};
#ifdef DEFINE_NS_CPP
DEFINE_NAKED_JMP(unsigned char CNSPc::GetSimpleJob(unsigned char), 0x423700);
DEFINE_NAKED_JMP(unsigned char CNSPc::GetBasicJob(unsigned char), 0x4D77A0);
DEFINE_NAKED_JMP(int CNSPc::GetStartRegion(unsigned char _COMMA unsigned char _COMMA unsigned char & _COMMA NSPOINT2 &), 0x484760);
DEFINE_NAKED_JMP(unsigned char CNSPc::ConvertRaceToRegion(unsigned char), 0x484460);
//DEFINE_NAKED_JMP(int CNSPc::IsTargetOtherRealm(CNSCharacter * _COMMA CNSCharacter *), 0x4841E0);
//DEFINE_NAKED_JMP(int CNSPc::IsMineRider(unsigned short), 0x484C10);
//DEFINE_NAKED_JMP(CNSPc::Constructor(CNSSessionPc *), 0x45D000);
//DEFINE_NAKED_JMP(CNSPc::Destructor(), 0x45D6D0);
//DEFINE_NAKED_JMP(void CNSPc::Clear(int), 0x45D4B0);
//DEFINE_NAKED_JMP(int CNSPc::OnGameEnter(), 0x45DBF0);
DEFINE_NAKED_JMP(void CNSPc::OnBuff(unsigned long _COMMA int), 0x45DE70);
//DEFINE_NAKED_JMP(void CNSPc::OnLogOut(int), 0x45DFC0);
//DEFINE_NAKED_JMP(void CNSPc::OnSessionMode(), 0x45E230);
DEFINE_NAKED_JMP(void CNSPc::OnMoveServer(unsigned char _COMMA NSPOINT2), 0x45E250);
//DEFINE_NAKED_JMP(void CNSPc::OnDisconnect(), 0x45E320);
//DEFINE_NAKED_JMP(void CNSPc::OnHitLastDamage(CNSCharacter *), 0x45E3F0);
//DEFINE_NAKED_JMP(void CNSPc::GetPswInfo(CNSPc::PSWTYPE & _COMMA unsigned char & _COMMA unsigned char & _COMMA unsigned char &), 0x464410);
DEFINE_NAKED_JMP(void CNSPc::Reset(int), 0x464890);
DEFINE_NAKED_JMP(int CNSPc::ResetSiegeWeapon(int _COMMA unsigned short _COMMA int), 0x464560);
DEFINE_NAKED_JMP(void CNSPc::Login(), 0x460260);
//DEFINE_NAKED_JMP(unsigned short CNSPc::HitDamage(CNSCharacter * _COMMA unsigned short _COMMA CNSObject::HITTYPE _COMMA int), 0x481EC0);
//DEFINE_NAKED_JMP(int CNSPc::IsLogin(), 0x44C430);
DEFINE_NAKED_JMP(int CNSPc::IsPartyEnableMember(), 0x42B790);
//DEFINE_NAKED_JMP(int CNSPc::IsItemFreeze(), 0x4C80C0);
//DEFINE_NAKED_JMP(int CNSPc::IsPcBang(), 0x43EE10);
DEFINE_NAKED_JMP(int CNSPc::IsSessionGameMode(), 0x45D960);
//DEFINE_NAKED_JMP(int CNSPc::IsExistTameMob(), 0x484990);
//DEFINE_NAKED_JMP(void CNSPc::ToggleSuperMode(), 0x4C93B0);
//DEFINE_NAKED_JMP(void CNSPc::ToggleGhost(), 0x4C93E0);
//DEFINE_NAKED_JMP(void CNSPc::SetGuildId(unsigned long), 0x4365A0);
//DEFINE_NAKED_JMP(void CNSPc::SetPartyId(unsigned long), 0x492540);
//DEFINE_NAKED_JMP(void CNSPc::SetUserId(int _COMMA char *), 0x406260);
//DEFINE_NAKED_JMP(void CNSPc::SetUserAlias(char *), 0x4062E0);
//DEFINE_NAKED_JMP(int CNSPc::GetUserSeq(), 0x485570);
//DEFINE_NAKED_JMP(void CNSPc::SetStickObjectId(unsigned long), 0x484390);
//DEFINE_NAKED_JMP(unsigned long CNSPc::GetStickObjectId(), 0x4C7FF0);
//DEFINE_NAKED_JMP(int CNSPc::GetStickDestination(NSPOINT2 &), 0x45DA00);
//DEFINE_NAKED_JMP(void CNSPc::CancelStickPc(), 0x482530);
//DEFINE_NAKED_JMP(void CNSPc::SetDeadTime(unsigned long), 0x4D73B0);
//DEFINE_NAKED_JMP(void CNSPc::SetLeaveTime(), 0x4C7EB0);
//DEFINE_NAKED_JMP(void CNSPc::SetDisconnectTime(), 0x4B48D0);
//DEFINE_NAKED_JMP(int CNSPc::SetTitle(unsigned short), 0x4C84A0);
//DEFINE_NAKED_JMP(int CNSPc::IsAutoRunMode(), 0x483860);
//DEFINE_NAKED_JMP(void CNSPc::StartAutoRunMode(), 0x4C8010);
//DEFINE_NAKED_JMP(void CNSPc::EndAutoRunMode(), 0x483880);
//DEFINE_NAKED_JMP(char * CNSPc::GetUserId(), 0x42E150);
//DEFINE_NAKED_JMP(char * CNSPc::GetUserAlias(), 0x42B7C0);
//DEFINE_NAKED_JMP(int CNSPc::GetUserAliasSeq(), 0x43EE30);
DEFINE_NAKED_JMP(unsigned long CNSPc::GetGuildId(), 0x482750);
DEFINE_NAKED_JMP(unsigned long CNSPc::GetPartyId(), 0x42B7E0);
DEFINE_NAKED_JMP(unsigned char CNSPc::GetRank(), 0x44A970);
//DEFINE_NAKED_JMP(unsigned long CNSPc::GetDeadExp(), 0x4843B0);
//DEFINE_NAKED_JMP(unsigned short CNSPc::GetNs(), 0x481E70);
//DEFINE_NAKED_JMP(unsigned short CNSPc::GetNsMaxCharge(), 0x45EA50);
//DEFINE_NAKED_JMP(unsigned short CNSPc::GetNsCharge(), 0x4B0830);
//DEFINE_NAKED_JMP(void CNSPc::SetTransPos(), 0x4C7F20);
//DEFINE_NAKED_JMP(unsigned short CNSPc::UseMp(unsigned short), 0x4822E0);
//DEFINE_NAKED_JMP(unsigned short CNSPc::UseSta(unsigned short), 0x482330);
DEFINE_NAKED_JMP(unsigned char CNSPc::GetRace(), 0x43F950);
DEFINE_NAKED_JMP(unsigned char CNSPc::GetRaceRegion(), 0x436630);
DEFINE_NAKED_JMP(unsigned char CNSPc::GetJob(), 0x4236E0);
DEFINE_NAKED_JMP(unsigned char CNSPc::GetBindRegion(), 0x4B0850);
DEFINE_NAKED_JMP(NSPOINT2 CNSPc::GetBindCell(), 0x4B0870);
DEFINE_NAKED_JMP(unsigned char CNSPc::GetTransRegion(), 0x4C7F50);
DEFINE_NAKED_JMP(unsigned long CNSPc::GetLastDeadExp(), 0x4D73D0);
DEFINE_NAKED_JMP(void CNSPc::SetLastDeadExp(unsigned long), 0x4C7F00);
DEFINE_NAKED_JMP(unsigned char CNSPc::GetEquipMaxSpecialGrade(), 0x44A5D0);
DEFINE_NAKED_JMP(int CNSPc::GetEquipMaxSpecialGradePer(), 0x44A590);
DEFINE_NAKED_JMP(CNSSessionPc * CNSPc::GetSession(), 0x44A990);
DEFINE_NAKED_JMP(int CNSPc::CloseConnection(), 0x45D840);
DEFINE_NAKED_JMP(void CNSPc::SetNpcTalkObjectId(unsigned long), 0x4C81B0);
DEFINE_NAKED_JMP(unsigned long CNSPc::CheckInstantKey(unsigned char), 0x46FE90);
DEFINE_NAKED_JMP(CNSNpc * CNSPc::PetAdd(CNSPc::PETTYPE _COMMA unsigned short _COMMA NSPOINT2 & _COMMA unsigned short _COMMA unsigned char _COMMA unsigned short _COMMA unsigned long _COMMA char * _COMMA unsigned short _COMMA unsigned short _COMMA unsigned char), 0x466CD0);
DEFINE_NAKED_JMP(int CNSPc::PetTaming(unsigned long _COMMA unsigned short _COMMA unsigned char _COMMA unsigned short _COMMA unsigned long), 0x4670E0);
DEFINE_NAKED_JMP(CNSNpc * CNSPc::PetSummoning(unsigned short _COMMA unsigned short _COMMA unsigned char _COMMA unsigned short _COMMA unsigned long), 0x4671E0);
DEFINE_NAKED_JMP(int CNSPc::PetTameMobLoad(unsigned short _COMMA char * _COMMA unsigned short _COMMA unsigned short), 0x4672D0);
DEFINE_NAKED_JMP(CNSNpc * CNSPc::PetLoad(unsigned char _COMMA unsigned char _COMMA unsigned char _COMMA char * _COMMA unsigned short), 0x4673A0);
DEFINE_NAKED_JMP(CNSNpc * CNSPc::PetLoad(), 0x4824C0);
DEFINE_NAKED_JMP(int CNSPc::PetUpgrade(unsigned char), 0x4667C0);
DEFINE_NAKED_JMP(int CNSPc::PetChangeLevel(unsigned char), 0x466790);
DEFINE_NAKED_JMP(int CNSPc::PetRebirth(unsigned char), 0x4B0890);
DEFINE_NAKED_JMP(int CNSPc::PetDelete(unsigned long), 0x4675F0);
DEFINE_NAKED_JMP(void CNSPc::PetDeleteAll(int), 0x467690);
DEFINE_NAKED_JMP(int CNSPc::PetStateChange(CNSNpc * _COMMA unsigned char), 0x4677D0);
DEFINE_NAKED_JMP(int CNSPc::PetAttack(CNSNpc * _COMMA CNSCharacter *), 0x467890);
DEFINE_NAKED_JMP(int CNSPc::PetChange(unsigned char _COMMA unsigned char _COMMA unsigned char _COMMA int), 0x466650);
DEFINE_NAKED_JMP(int CNSPc::PetFood(unsigned long), 0x466800);
DEFINE_NAKED_JMP(void CNSPc::PetAddExpPoint(CNSNpc * _COMMA unsigned short), 0x467AA0);
DEFINE_NAKED_JMP(float CNSPc::PetGetExpPercent(unsigned long), 0x4678E0);
DEFINE_NAKED_JMP(unsigned char CNSPc::PetGetExpPercent(), 0x467970);
DEFINE_NAKED_JMP(void CNSPc::PetSetExpPercent(unsigned char), 0x467A20);
//DEFINE_NAKED_JMP(void CNSPc::PetDebugExp(), 0x467D30);
//DEFINE_NAKED_JMP(void CNSPc::PetDebugKill(), 0x467D70);
DEFINE_NAKED_JMP(void CNSPc::PetSetName(CNSNpc * _COMMA char *), 0x467DB0);
DEFINE_NAKED_JMP(void CNSPc::PetInfoSave(), 0x4777A0);
DEFINE_NAKED_JMP(unsigned long CNSPc::PetTameInfoSave(), 0x477820);
DEFINE_NAKED_JMP(void CNSPc::PetHide(), 0x467770);
DEFINE_NAKED_JMP(CNSNpc * CNSPc::_PetGetObject(), 0x43EE50);
DEFINE_NAKED_JMP(CNSNpc * CNSPc::_PetGetMobObject(), 0x43EEB0);
DEFINE_NAKED_JMP(CNSPc::PETTYPE CNSPc::PetGetType(unsigned long), 0x4675A0);
DEFINE_NAKED_JMP(unsigned long CNSPc::PetGetObjectId(CNSPc::PETTYPE), 0x43EE90);
DEFINE_NAKED_JMP(void CNSPc::PetSetObjectId(CNSPc::PETTYPE _COMMA unsigned long), 0x483190);
DEFINE_NAKED_JMP(unsigned long CNSPc::ItemList(CPacket & _COMMA int), 0x467DE0);
//DEFINE_NAKED_JMP(unsigned char CNSPc::ItemEquipDescription(CNSItem * _COMMA CNSItem * *), 0x467EE0);
//DEFINE_NAKED_JMP(unsigned long CNSPc::_ItemAdd(unsigned short _COMMA unsigned char _COMMA char * _COMMA unsigned long _COMMA int), 0x468340);
DEFINE_NAKED_JMP(int CNSPc::ItemAdd(unsigned short _COMMA unsigned char _COMMA char * _COMMA unsigned long _COMMA int), 0x43EF00);
DEFINE_NAKED_JMP(int CNSPc::ItemAddToUserAlias(unsigned short _COMMA unsigned char _COMMA char *), 0x468280);
DEFINE_NAKED_JMP(int CNSPc::ItemPickup(unsigned long _COMMA unsigned long), 0x468690);
DEFINE_NAKED_JMP(void CNSPc::ItemPickupAll(CNSNpc *), 0x468710);
DEFINE_NAKED_JMP(int CNSPc::ItemMove(unsigned long _COMMA unsigned long _COMMA int), 0x469880);
DEFINE_NAKED_JMP(int CNSPc::ItemEquipCheck(CNSItem *), 0x468790);
DEFINE_NAKED_JMP(int CNSPc::ItemEquipCheck2(CNSEquipment::EQUIPMENTTYPE _COMMA CNSItem *), 0x4688D0);
DEFINE_NAKED_JMP(CNSEquipment::EQUIPMENTTYPE CNSPc::ItemEquipRemove(CNSItem *), 0x468A70);
DEFINE_NAKED_JMP(int CNSPc::ItemEquip(CNSEquipment::EQUIPMENTTYPE _COMMA unsigned long), 0x469750);
DEFINE_NAKED_JMP(int CNSPc::ItemUse(unsigned short), 0x46A240);
DEFINE_NAKED_JMP(int CNSPc::ItemUse(unsigned long _COMMA unsigned char & _COMMA unsigned char), 0x469C80);
DEFINE_NAKED_JMP(int CNSPc::ItemUseDb(CNSItem * _COMMA char _COMMA char *), 0x46A3C0);
DEFINE_NAKED_JMP(int CNSPc::ItemUseDb(unsigned short _COMMA unsigned char), 0x46A2D0);
//DEFINE_NAKED_JMP(int CNSPc::ItemDelete(unsigned long _COMMA unsigned char), 0x46A490);
//DEFINE_NAKED_JMP(int CNSPc::ItemCombine(unsigned long _COMMA unsigned long _COMMA unsigned char & _COMMA unsigned char &), 0x46A6A0);
//DEFINE_NAKED_JMP(int CNSPc::ItemDivide(unsigned long _COMMA unsigned char _COMMA unsigned long &), 0x46A840);
//DEFINE_NAKED_JMP(int CNSPc::ItemUpgrade(unsigned long _COMMA unsigned long _COMMA unsigned long _COMMA int _COMMA int), 0x46AF90);
//DEFINE_NAKED_JMP(int CNSPc::ItemCoreDivide(CNSItem * _COMMA CNSItem * _COMMA int), 0x46ABE0);
//DEFINE_NAKED_JMP(void CNSPc::ItemPrintPremium(int), 0x46C090);
//DEFINE_NAKED_JMP(void CNSPc::ItemCheckPremium(), 0x46C3E0);
//DEFINE_NAKED_JMP(void CNSPc::EventItemAdd(unsigned short _COMMA unsigned char _COMMA unsigned long), 0x48BEE0);
//DEFINE_NAKED_JMP(int CNSPc::GetItemRecombinationExpense(unsigned long _COMMA unsigned long & _COMMA unsigned short & _COMMA unsigned char &), 0x46C700);
//DEFINE_NAKED_JMP(int CNSPc::ItemRecombination(unsigned long _COMMA int), 0x46CA20);
//DEFINE_NAKED_JMP(int CNSPc::ItemSwap(unsigned long _COMMA int), 0x46D120);
//DEFINE_NAKED_JMP(int CNSPc::ItemDeleteAll(), 0x46D140);
//DEFINE_NAKED_JMP(int CNSPc::ItemGathering(unsigned long _COMMA unsigned long _COMMA unsigned long _COMMA int), 0x46A920);
//DEFINE_NAKED_JMP(int CNSPc::ItemMining(unsigned long _COMMA unsigned long _COMMA unsigned long _COMMA int), 0x46A9F0);
//DEFINE_NAKED_JMP(int CNSPc::ItemUnlock(unsigned long _COMMA unsigned long _COMMA unsigned long), 0x46AB20);
//DEFINE_NAKED_JMP(int CNSPc::PremiumItemSell(unsigned short), 0x46D170);
//DEFINE_NAKED_JMP(unsigned long CNSPc::SkillList(CPacket &), 0x46D3C0);
//DEFINE_NAKED_JMP(void CNSPc::DebugSkillList(), 0x46D5A0);
//DEFINE_NAKED_JMP(int CNSPc::SkillCast(unsigned short _COMMA unsigned long), 0x46D740);
//DEFINE_NAKED_JMP(int CNSPc::SkillUse(), 0x46D850);
//DEFINE_NAKED_JMP(void CNSPc::SkillCancel(), 0x46D8A0);
//DEFINE_NAKED_JMP(int CNSPc::SkillStudy(unsigned short), 0x46D8D0);
//DEFINE_NAKED_JMP(int CNSPc::SkillScroll(unsigned long _COMMA unsigned char), 0x46D8F0);
//DEFINE_NAKED_JMP(int CNSPc::SkillBlockCall(unsigned long _COMMA unsigned short), 0x46E850);
//DEFINE_NAKED_JMP(int CNSPc::CheckBlock(), 0x46E6D0);
//DEFINE_NAKED_JMP(CNSPcParty * CNSPc::PartyCreate(char * _COMMA char * _COMMA CNSPcParty::LOOTMODE), 0x46EA10);
//DEFINE_NAKED_JMP(int CNSPc::MoveTo(unsigned char _COMMA NSPOINT2 & _COMMA NSPOINT2 &), 0x46F4A0);
//DEFINE_NAKED_JMP(int CNSPc::MoveTo(NSPOINT2 &), 0x482600);
//DEFINE_NAKED_JMP(void CNSPc::_Stop(unsigned long), 0x482570);
//DEFINE_NAKED_JMP(void CNSPc::Stop(unsigned long), 0x46D6A0);
//DEFINE_NAKED_JMP(void CNSPc::Stand(), 0x46D6D0);
DEFINE_NAKED_JMP(int CNSPc::Warp(unsigned short _COMMA unsigned short _COMMA unsigned char), 0x46F5C0);
DEFINE_NAKED_JMP(void CNSPc::WarpParty(unsigned short _COMMA unsigned short _COMMA unsigned char), 0x46F930);
DEFINE_NAKED_JMP(void CNSPc::WarpGuild(unsigned short _COMMA unsigned short _COMMA unsigned char), 0x46FA20);
//DEFINE_NAKED_JMP(int CNSPc::WarpInstant(unsigned char _COMMA unsigned short _COMMA unsigned short), 0x46FB60);
DEFINE_NAKED_JMP(void CNSPc::WarpRaceRegion(), 0x46FDE0);
//DEFINE_NAKED_JMP(void CNSPc::DBWarpRaceRegion(), 0x474400);
DEFINE_NAKED_JMP(int CNSPc::AttackCheck(CNSCharacter *), 0x46FF00);
DEFINE_NAKED_JMP(void CNSPc::Attack(CNSCharacter * _COMMA unsigned long), 0x470220);
//DEFINE_NAKED_JMP(unsigned short CNSPc::AttackSiegeWeaponMode(CNSCharacter * _COMMA unsigned short), 0x484220);
DEFINE_NAKED_JMP(void CNSPc::Rebirth(unsigned char), 0x471D20);
DEFINE_NAKED_JMP(void CNSPc::Rebirth2(), 0x472580);
//DEFINE_NAKED_JMP(void CNSPc::UsePhoenix(unsigned short), 0x472470);
//DEFINE_NAKED_JMP(int CNSPc::IsEquipRemoveAll(), 0x45F580);
//DEFINE_NAKED_JMP(int CNSPc::ChangeRace(unsigned char), 0x45F730);
//DEFINE_NAKED_JMP(int CNSPc::ChangeBindPos(unsigned char _COMMA unsigned short _COMMA unsigned short), 0x4600D0);
//DEFINE_NAKED_JMP(int CNSPc::DBChangeJob(unsigned char), 0x45F220);
//DEFINE_NAKED_JMP(int CNSPc::DBSkillMake60(), 0x45F920);
//DEFINE_NAKED_JMP(int CNSPc::DBLevelUp100(), 0x45FA70);
//DEFINE_NAKED_JMP(int CNSPc::DBPSWFactory(unsigned short), 0x45FC50);
//DEFINE_NAKED_JMP(int CNSPc::LoadPath(unsigned short), 0x460110);
//DEFINE_NAKED_JMP(int CNSPc::MoveTranferManchine(unsigned short), 0x460180);
//DEFINE_NAKED_JMP(void CNSPc::RestoreCell(), 0x482770);
//DEFINE_NAKED_JMP(void CNSPc::AddGold(unsigned long), 0x482BB0);
//DEFINE_NAKED_JMP(unsigned long CNSPc::AddExpPoint(unsigned long _COMMA int), 0x470FA0);
//DEFINE_NAKED_JMP(unsigned short CNSPc::AddNsPoint(unsigned short _COMMA int), 0x482F20);
//DEFINE_NAKED_JMP(unsigned short CNSPc::SuctionNsPoint(unsigned short), 0x482BF0);
//DEFINE_NAKED_JMP(unsigned short CNSPc::SuctionGold(unsigned long), 0x482E50);
//DEFINE_NAKED_JMP(void CNSPc::AddTotalExp(unsigned char _COMMA unsigned long _COMMA unsigned long _COMMA unsigned short _COMMA int), 0x4658A0);
//DEFINE_NAKED_JMP(int CNSPc::GiveNsPoint(unsigned short), 0x4837E0);
//DEFINE_NAKED_JMP(unsigned long CNSPc::GetRealmPoint(), 0x4B0810);
//DEFINE_NAKED_JMP(unsigned long CNSPc::AddRealmPoint(unsigned long _COMMA CNSCharacter *), 0x470E00);
//DEFINE_NAKED_JMP(int CNSPc::GiveRealmPoint(unsigned long), 0x470F20);
//DEFINE_NAKED_JMP(CNSPc * CNSPc::_GetOriginalPcObject(CNSCharacter *), 0x429AD0);
DEFINE_NAKED_JMP(unsigned long CNSPc::GetSkillExp(), 0x4D75E0);
DEFINE_NAKED_JMP(void CNSPc::AddSkillExpPoint(unsigned long _COMMA int), 0x45EC00);
DEFINE_NAKED_JMP(void CNSPc::UseSkillExpPoint(unsigned long), 0x45EE20);
DEFINE_NAKED_JMP(int CNSPc::TeleportAdd(unsigned short _COMMA char *), 0x46EB00);
DEFINE_NAKED_JMP(int CNSPc::TeleportDelete(unsigned short _COMMA int), 0x46EBE0);
DEFINE_NAKED_JMP(int CNSPc::FriendAdd(char *), 0x46EC20);
DEFINE_NAKED_JMP(int CNSPc::FriendDelete(char *), 0x46ECE0);
DEFINE_NAKED_JMP(int CNSPc::GuildCreate(char * _COMMA char *), 0x46ED30);
DEFINE_NAKED_JMP(int CNSPc::GuildAddLevelUpPoint(), 0x46EF40);
DEFINE_NAKED_JMP(int CNSPc::GuildAddConnectPoint(), 0x46F100);
DEFINE_NAKED_JMP(float CNSPc::CalcRealmPoint(unsigned char _COMMA unsigned char _COMMA CNSCharacter *), 0x46F2D0);
DEFINE_NAKED_JMP(void CNSPc::LevelUp(), 0x470C10);
DEFINE_NAKED_JMP(unsigned long CNSPc::LevelSetup(), 0x470C50);
DEFINE_NAKED_JMP(int CNSPc::CheckDoubleConnect(char *), 0x472620);
DEFINE_NAKED_JMP(int CNSPc::CheckDoubleConnect2(char *), 0x4726A0);
DEFINE_NAKED_JMP(int CNSPc::CheckDoubleConnect3(char * _COMMA unsigned char), 0x472730);
DEFINE_NAKED_JMP(void CNSPc::LastServerClear(char *), 0x472800);
//DEFINE_NAKED_JMP(unsigned short CNSPc::GetChatChannel(int), 0x4C8040);
//DEFINE_NAKED_JMP(int CNSPc::GetChatChannelIndex(unsigned short), 0x4C8070);
//DEFINE_NAKED_JMP(int CNSPc::ChatChannelJoin(char *), 0x480230);
//DEFINE_NAKED_JMP(int CNSPc::ChatChannelQuit(char *), 0x480320);
//DEFINE_NAKED_JMP(void CNSPc::ChatChannelList(), 0x4803E0);
DEFINE_NAKED_JMP(int CNSPc::DBLoad(), 0x472870);
DEFINE_NAKED_JMP(int CNSPc::DBSave(CNSDbManager::SAVEPCMODE), 0x4733A0);
DEFINE_NAKED_JMP(int CNSPc::DBMainUserSeq(char *), 0x473CA0);
//DEFINE_NAKED_JMP(int CNSPc::DBMainLastServerLoad(char * _COMMA unsigned char * _COMMA int &), 0x473EE0);
DEFINE_NAKED_JMP(int CNSPc::DBMainLastServerSave(char *), 0x4740F0);
//DEFINE_NAKED_JMP(int CNSPc::DBMainLastServerClear(char *), 0x4742A0);
//DEFINE_NAKED_JMP(int CNSPc::DBAliasRename(char *), 0x475A80);
//DEFINE_NAKED_JMP(int CNSPc::DBAliasMake(char * _COMMA unsigned char _COMMA unsigned char _COMMA unsigned char), 0x475ED0);
//DEFINE_NAKED_JMP(int CNSPc::DBAliasCount(int & _COMMA unsigned char &), 0x474D70);
//DEFINE_NAKED_JMP(unsigned long CNSPc::DBAliasList(CPacket &), 0x474730);
//DEFINE_NAKED_JMP(int CNSPc::DBAliasInsert(char * _COMMA unsigned char _COMMA unsigned char _COMMA unsigned char), 0x4762D0);
//DEFINE_NAKED_JMP(int CNSPc::DBAliasDelete(char *), 0x4765E0);
//DEFINE_NAKED_JMP(int CNSPc::DBAliasSeq(char * _COMMA int &), 0x475160);
//DEFINE_NAKED_JMP(int CNSPc::DBAliasLog(char _COMMA char * _COMMA int), 0x476B90);
DEFINE_NAKED_JMP(int CNSPc::DBPcSave(), 0x476920);
//DEFINE_NAKED_JMP(int CNSPc::DBStatusUpdate(), 0x476E70);
//DEFINE_NAKED_JMP(int CNSPc::DBJobUpdate(), 0x477000);
//DEFINE_NAKED_JMP(int CNSPc::DBRaceUpdate(), 0x477150);
//DEFINE_NAKED_JMP(int CNSPc::DBGoldUpdate(), 0x4772B0);
DEFINE_NAKED_JMP(int CNSPc::DBBindPosUpdate(), 0x477400);
DEFINE_NAKED_JMP(int CNSPc::DBTameMobSave(unsigned long), 0x477940);
DEFINE_NAKED_JMP(int CNSPc::DBTameMobLoad(), 0x477570);
//DEFINE_NAKED_JMP(int CNSPc::DBTameMobInsert(unsigned short), 0x477B90);
//DEFINE_NAKED_JMP(int CNSPc::DBPetCreate(), 0x47B0B0);
//DEFINE_NAKED_JMP(int CNSPc::DBPetCreate2(), 0x47B220);
//DEFINE_NAKED_JMP(int CNSPc::DBPetLoad(), 0x47B340);
//DEFINE_NAKED_JMP(int CNSPc::DBPetSave(), 0x47B5A0);
//DEFINE_NAKED_JMP(unsigned long CNSPc::DBItemCount(unsigned short), 0x477E00);
//DEFINE_NAKED_JMP(int CNSPc::DBItemLoad(), 0x477F70);
//DEFINE_NAKED_JMP(int CNSPc::DBItemInsert(CNSItem * _COMMA int), 0x478730);
//DEFINE_NAKED_JMP(int CNSPc::DBItemUpdate(CNSItem *), 0x479040);
DEFINE_NAKED_JMP(int CNSPc::DBItemUpdatePos(CNSItem *), 0x478B90);
//DEFINE_NAKED_JMP(int CNSPc::DBItemUpdateCount(CNSItem *), 0x478D10);
DEFINE_NAKED_JMP(int CNSPc::DBItemUpdatePosCount(CNSItem *), 0x478E90);
//DEFINE_NAKED_JMP(int CNSPc::DBItemLog(char _COMMA char * _COMMA unsigned long _COMMA int _COMMA unsigned short _COMMA unsigned char _COMMA int), 0x478A30);
DEFINE_NAKED_JMP(int CNSPc::DBItemDelete(int), 0x4792D0);
//DEFINE_NAKED_JMP(int CNSPc::DBItemDeleteAll(), 0x479420);
DEFINE_NAKED_JMP(int CNSPc::DBItemBasicInsert(unsigned char _COMMA unsigned char), 0x479560);
//DEFINE_NAKED_JMP(int CNSPc::DBItemCreateAdd(unsigned short _COMMA unsigned char), 0x4785C0);
//DEFINE_NAKED_JMP(int CNSPc::DBItemCreateEquip(CNSEquipment::EQUIPMENTTYPE _COMMA unsigned short), 0x478630);
DEFINE_NAKED_JMP(int CNSPc::DBSkillLoad(), 0x479BA0);
DEFINE_NAKED_JMP(int CNSPc::DBSkillInsert(CNSSkill *), 0x479EB0);
DEFINE_NAKED_JMP(int CNSPc::DBSkillUpdate(CNSSkill *), 0x47A190);
//DEFINE_NAKED_JMP(int CNSPc::DBSkillDelete(CNSSkill *), 0x47A040);
//DEFINE_NAKED_JMP(int CNSPc::DBProductLoad(), 0x47A330);
//DEFINE_NAKED_JMP(int CNSPc::DBProductInsert(unsigned short), 0x47A540);
//DEFINE_NAKED_JMP(int CNSPc::DBQuestLoad(), 0x47A690);
//DEFINE_NAKED_JMP(int CNSPc::DBQuestInsert(unsigned short), 0x47AC20);
//DEFINE_NAKED_JMP(int CNSPc::DBQuestInsert2(CNSQuest *), 0x47AA00);
DEFINE_NAKED_JMP(int CNSPc::DBQuestUpdate(CNSQuest *), 0x47AD70);
//DEFINE_NAKED_JMP(int CNSPc::DBQuestDelete(unsigned short), 0x47AF60);
//DEFINE_NAKED_JMP(int CNSPc::DBQuickBarCreate(unsigned char _COMMA unsigned char), 0x47B790);
//DEFINE_NAKED_JMP(int CNSPc::DBQuickBarLoad(), 0x47BB30);
//DEFINE_NAKED_JMP(int CNSPc::DBQuickBarSave(), 0x47BD20);
//DEFINE_NAKED_JMP(int CNSPc::DBCoolTimeCreate(), 0x47BF20);
//DEFINE_NAKED_JMP(int CNSPc::DBCoolTimeLoad(), 0x47C060);
//DEFINE_NAKED_JMP(int CNSPc::DBCoolTimeSave(), 0x47C520);
//DEFINE_NAKED_JMP(int CNSPc::DBTeleportLoad(), 0x47CBC0);
//DEFINE_NAKED_JMP(int CNSPc::DBTeleportInsert(CNSPcTeleportList::Teleport &), 0x47CE30);
//DEFINE_NAKED_JMP(int CNSPc::DBTeleportDelete(int), 0x47CFB0);
DEFINE_NAKED_JMP(int CNSPc::DBTeleportDeleteAll(), 0x47D0F0);
//DEFINE_NAKED_JMP(int CNSPc::DBFriendLoad(), 0x47D230);
//DEFINE_NAKED_JMP(int CNSPc::DBFriendInsert(char * _COMMA int &), 0x47D440);
//DEFINE_NAKED_JMP(int CNSPc::DBFriendDelete(int), 0x47D620);
//DEFINE_NAKED_JMP(int CNSPc::DbFellowList(), 0x47D760);
//DEFINE_NAKED_JMP(int CNSPc::DbFellowDelete(char *), 0x47D960);
//DEFINE_NAKED_JMP(int CNSPc::DBGuildLoad(), 0x47DAE0);
//DEFINE_NAKED_JMP(int CNSPc::DBEquipList(int _COMMA unsigned short *), 0x475300);
DEFINE_NAKED_JMP(int CNSPc::DBLoginLog(), 0x47DCD0);
DEFINE_NAKED_JMP(int CNSPc::DBLogoutLog(), 0x47DEA0);
DEFINE_NAKED_JMP(int CNSPc::DBExpLog(), 0x476CE0);
//DEFINE_NAKED_JMP(int CNSPc::DBMemoWrite(CNSPc * _COMMA int _COMMA int _COMMA char *), 0x47E310);
//DEFINE_NAKED_JMP(int CNSPc::DBMemoWrite(CNSPc * _COMMA int _COMMA char * _COMMA char *), 0x47E1D0);
//DEFINE_NAKED_JMP(int CNSPc::DBMemoWrite(char * _COMMA char *), 0x47E000);
DEFINE_NAKED_JMP(int CNSPc::DBMemoRead(), 0x47E450);
//DEFINE_NAKED_JMP(int CNSPc::DBBillGetGearInfo(), 0x47E6D0);
//DEFINE_NAKED_JMP(int CNSPc::DBBillReqBuyItem(unsigned short _COMMA char * _COMMA int _COMMA char * _COMMA char *), 0x47E840);
//DEFINE_NAKED_JMP(int CNSPc::DBBillAuctionBuyGear(int _COMMA int _COMMA int), 0x47E9C0);
//DEFINE_NAKED_JMP(int CNSPc::DBDebugBillGetGear(), 0x47EAF0);
//DEFINE_NAKED_JMP(int CNSPc::DBDebugBillIncGear(int), 0x47EC10);
//DEFINE_NAKED_JMP(int CNSPc::DBDebugBillDecGear(int), 0x47ED40);
//DEFINE_NAKED_JMP(int CNSPc::DBDebugBillAuctionBuyGear(int _COMMA int _COMMA int), 0x47EE70);
//DEFINE_NAKED_JMP(int CNSPc::DBDebugRankChange(unsigned char), 0x47EFA0);
//DEFINE_NAKED_JMP(int CNSPc::DBNeoSlotCoinAdd(unsigned long), 0x47F290);
//DEFINE_NAKED_JMP(unsigned long CNSPc::DBNeoSlotCoinCount(), 0x47F100);
//DEFINE_NAKED_JMP(int CNSPc::DBOfflineAutoSkillLoad(int & _COMMA int & _COMMA char *), 0x47F450);
//DEFINE_NAKED_JMP(int CNSPc::DBOfflineAutoSkillInsert(), 0x47F600);
//DEFINE_NAKED_JMP(int CNSPc::DBOfflineAutoSkillDelete(), 0x47F720);
//DEFINE_NAKED_JMP(unsigned long CNSPc::DBPremiumShopLimitCount(unsigned char _COMMA unsigned char), 0x47F830);
//DEFINE_NAKED_JMP(int CNSPc::DBPremiumShopLimitIncCount(unsigned char _COMMA unsigned char), 0x47F9A0);
//DEFINE_NAKED_JMP(int CNSPc::BillGetGearInfo(), 0x47FAB0);
//DEFINE_NAKED_JMP(int CNSPc::BillReqBuyItem(unsigned short _COMMA char * _COMMA int), 0x47FB30);
//DEFINE_NAKED_JMP(int CNSPc::BillAuctionBuyGear(int _COMMA int _COMMA int), 0x47FBE0);
DEFINE_NAKED_JMP(int CNSPc::AliasCheck(char *), 0x475970);
//DEFINE_NAKED_JMP(void CNSPc::OnCloseSession(), 0x4B4900);
DEFINE_NAKED_JMP(int CNSPc::SendMessageA(CPacket & _COMMA int), 0x4602D0);
//DEFINE_NAKED_JMP(void CNSPc::PacketAliasListMessage(CPacket &), 0x460480);
//DEFINE_NAKED_JMP(void CNSPc::PacketItemListMessage(CPacket &), 0x460300);
//DEFINE_NAKED_JMP(void CNSPc::PacketEnterMessage(CPacket &), 0x460D90);
//DEFINE_NAKED_JMP(void CNSPc::PacketSystemMessage(CPacket & _COMMA int _COMMA ...), 0x4603A0);
//DEFINE_NAKED_JMP(void CNSPc::SendEnterMessage(int), 0x4634E0);
//DEFINE_NAKED_JMP(void CNSPc::SendRecoveryMessage(int _COMMA int), 0x462B40);
//DEFINE_NAKED_JMP(void CNSPc::SendMoveMessage(unsigned long _COMMA int), 0x462D40);
DEFINE_NAKED_JMP(void CNSPc::SendStatusMessage(int), 0x4614E0);
DEFINE_NAKED_JMP(void CNSPc::SendLeaveMessage(), 0x463560);
DEFINE_NAKED_JMP(int CNSPc::SendChatActionMessage(unsigned long _COMMA int), 0x460670);
DEFINE_NAKED_JMP(void CNSPc::SendChatActionMessage(unsigned long), 0x460520);
DEFINE_NAKED_JMP(void CNSPc::SendChatMessage(int _COMMA unsigned short _COMMA char * _COMMA ...), 0x460720);
DEFINE_NAKED_JMP(void CNSPc::SendTipMessage(char *), 0x4605E0);
DEFINE_NAKED_JMP(void CNSPc::SendNotifyMessageA(int _COMMA unsigned short _COMMA char * _COMMA ...), 0x460810);
DEFINE_NAKED_JMP(void CNSPc::SendWarpMessage(unsigned char _COMMA unsigned short _COMMA unsigned short), 0x460920);
DEFINE_NAKED_JMP(void CNSPc::SendPetEnterMessage(unsigned long), 0x4635E0);
DEFINE_NAKED_JMP(void CNSPc::SendPetLeaveMessage(unsigned long), 0x463670);
DEFINE_NAKED_JMP(void CNSPc::SendPetStatusMessage(), 0x460C30);
DEFINE_NAKED_JMP(void CNSPc::SendSystemMessage(char * _COMMA ...), 0x461A00);
DEFINE_NAKED_JMP(void CNSPc::SendSystemMessage(int _COMMA ...), 0x4618F0);
DEFINE_NAKED_JMP(void CNSPc::SendCenterMessage(unsigned char _COMMA char * _COMMA ...), 0x461CF0);
DEFINE_NAKED_JMP(void CNSPc::SendCenterMessage(unsigned char _COMMA int _COMMA ...), 0x461AD0);
DEFINE_NAKED_JMP(void CNSPc::SendCenterMessageEx(unsigned char _COMMA unsigned char _COMMA int _COMMA ...), 0x461BE0);
DEFINE_NAKED_JMP(void CNSPc::SendPetNotifyMessage(), 0x460A20);
DEFINE_NAKED_JMP(void CNSPc::SendStartMessage(), 0x460A70);
DEFINE_NAKED_JMP(void CNSPc::SendPetMessage(int _COMMA int _COMMA ...), 0x461DC0);
DEFINE_NAKED_JMP(void CNSPc::SendPetMessage(int _COMMA char * _COMMA ...), 0x461FF0);
DEFINE_NAKED_JMP(void CNSPc::SendLevelUpMessage(unsigned char _COMMA unsigned char _COMMA unsigned char _COMMA unsigned char _COMMA unsigned char), 0x462190);
DEFINE_NAKED_JMP(void CNSPc::SendSkillListMessage(), 0x462260);
DEFINE_NAKED_JMP(void CNSPc::SendSkillExpMessage(unsigned long), 0x45EB70);
DEFINE_NAKED_JMP(void CNSPc::SendSkillExpMessage(unsigned short _COMMA unsigned short), 0x462390);
DEFINE_NAKED_JMP(void CNSPc::SendSkillLevelUpMessage(unsigned short _COMMA unsigned char), 0x462430);
DEFINE_NAKED_JMP(void CNSPc::SendQuestListMessage(), 0x4624D0);
DEFINE_NAKED_JMP(void CNSPc::SendTeleportListMessage(unsigned short), 0x4625A0);
DEFINE_NAKED_JMP(void CNSPc::SendFriendListMessage(int), 0x462680);
DEFINE_NAKED_JMP(void CNSPc::SendQuickBarListMessage(), 0x462AC0);
DEFINE_NAKED_JMP(void CNSPc::SendMoveSyncMessage(unsigned long), 0x462EC0);
DEFINE_NAKED_JMP(void CNSPc::SendAutoRunStopMessage(), 0x463020);
DEFINE_NAKED_JMP(void CNSPc::SendAttackMessage(unsigned long _COMMA unsigned char _COMMA unsigned short _COMMA unsigned char _COMMA unsigned long), 0x4630E0);
DEFINE_NAKED_JMP(void CNSPc::SendExpMessage(unsigned long _COMMA unsigned long _COMMA unsigned short), 0x4632F0);
DEFINE_NAKED_JMP(void CNSPc::SendExpMessage_Exp2(unsigned long _COMMA unsigned long _COMMA unsigned short), 0x463200);
DEFINE_NAKED_JMP(void CNSPc::SendDeadMessage(), 0x463700);
DEFINE_NAKED_JMP(void CNSPc::SendItemAddMessage(CNSItem *), 0x463780);
DEFINE_NAKED_JMP(void CNSPc::SendItemDeleteMessage(unsigned long), 0x463810);
DEFINE_NAKED_JMP(void CNSPc::SendItemUpdateMessage(CNSItem *), 0x4638A0);
DEFINE_NAKED_JMP(void CNSPc::SendItemPickupMessage(unsigned long _COMMA CNSItem *), 0x463930);
DEFINE_NAKED_JMP(void CNSPc::SendSkillAddMessage(CNSSkill *), 0x463B30);
DEFINE_NAKED_JMP(void CNSPc::SendSkillDeleteMessage(CNSSkill *), 0x463CF0);
DEFINE_NAKED_JMP(void CNSPc::SendSkillUpdateMessage(CNSSkill *), 0x463D90);
DEFINE_NAKED_JMP(void CNSPc::SendGoldChangeMessage(), 0x463A10);
DEFINE_NAKED_JMP(void CNSPc::SendRealmPointChangeMessage(), 0x463AA0);
DEFINE_NAKED_JMP(void CNSPc::SendItemListMessage(), 0x463F50);
DEFINE_NAKED_JMP(void CNSPc::SendProductListMessage(unsigned char _COMMA unsigned long), 0x463FB0);
DEFINE_NAKED_JMP(void CNSPc::SendMaterialListMessage(unsigned char _COMMA unsigned long), 0x464210);
DEFINE_NAKED_JMP(void CNSPc::SendProductDescriptionMessage(unsigned short), 0x464350);
DEFINE_NAKED_JMP(void CNSPc::SendPcShopListMessage(int), 0x462750);
DEFINE_NAKED_JMP(void CNSPc::SendGuildListMessage(unsigned long _COMMA int), 0x462850);
DEFINE_NAKED_JMP(void CNSPc::SendGuildInfoMessage(), 0x462930);
DEFINE_NAKED_JMP(void CNSPc::SendCashInfoMessage(), 0x464290);
DEFINE_NAKED_JMP(void CNSPc::SendTitleListMessage(), 0x4629F0);
DEFINE_NAKED_JMP(void CNSPc::SendDelayedMessage(), 0x484B60);
//DEFINE_NAKED_JMP(void CNSPc::OnTrace(CNSCharacter *), 0x45DF00);
//DEFINE_NAKED_JMP(void CNSPc::OnDead(unsigned long), 0x4716F0);
//DEFINE_NAKED_JMP(void CNSPc::OnStart(unsigned long), 0x47FC00);
//DEFINE_NAKED_JMP(void CNSPc::OnStop(unsigned long), 0x47FC50);
//DEFINE_NAKED_JMP(int CNSPc::TraceTarget(CNSCharacter * _COMMA unsigned short _COMMA unsigned long), 0x45EE80);
//DEFINE_NAKED_JMP(unsigned long CNSPc::TraceLootTarget(), 0x45EF30);
//DEFINE_NAKED_JMP(int CNSPc::PartyQuit(), 0x45F120);
//DEFINE_NAKED_JMP(void CNSPc::Action(), 0x4805F0);
//DEFINE_NAKED_JMP(CNSNpc * CNSPc::_CallMob(unsigned short _COMMA unsigned short), 0x480000);
//DEFINE_NAKED_JMP(CNSNpc * CNSPc::_CallMob(unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short), 0x47FF40);
//DEFINE_NAKED_JMP(CNSNpc * CNSPc::_CallNpc(unsigned short _COMMA unsigned short), 0x4800F0);
//DEFINE_NAKED_JMP(int CNSPc::DebugCallNpc(unsigned short _COMMA unsigned short), 0x47FE40);
//DEFINE_NAKED_JMP(int CNSPc::DebugGiveItem(unsigned short _COMMA unsigned char), 0x480460);
//DEFINE_NAKED_JMP(void CNSPc::DebugResetLevel(), 0x4804C0);
//DEFINE_NAKED_JMP(void CNSPc::DebugInvenList(), 0x480570);
//DEFINE_NAKED_JMP(void * CNSPc::operator new(unsigned int), 0x406230);
//DEFINE_NAKED_JMP(void CNSPc::operator delete(void * _COMMA unsigned int), 0x406240);
#endif




#endif