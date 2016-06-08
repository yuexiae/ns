#ifndef NSHEADER_NS_QUEST_H_
#define NSHEADER_NS_QUEST_H_


class CNSQuest {
public:
    static const unsigned int _size = 0x1f4;

    enum QUESTKIND {
        QuestKind_Tutorial = 0x0,
        QuestKind_Normal = 0x1,
        QuestKind_Main = 0x2,
        QuestKind_Job = 0x3,
        QuestKind_Guild = 0x4,
        QuestKind_Title = 0x5,
    };

    enum QUESTCHECK {
        QuestCheck_NULL = 0x0,
        QuestCheck_Mob = 0x1,
        QuestCheck_Item = 0x2,
    };

    enum QUESTREWARD {
        QuestReward_NULL = 0x0,
        QuestReward_Item = 0x1,
        QuestReward_Gold = 0x2,
        QuestReward_Exp = 0x3,
        QuestReward_Unknown = 0x4,
        QuestReward_RealmPoint = 0x5,
        QuestReward_ExpRandom = 0x6,
        QuestReward_Title = 0x7,
    };

    struct _step {
        static const unsigned int _size = 0x18;

        unsigned char btStep;//this+0x0
        char * szSummary;//this+0x4
        unsigned char btAutoComplete;//this+0x8
        unsigned char btCheckType;//this+0x9
        unsigned short wCheckId;//this+0xA
        unsigned long btCheckCount;//this+0xC
        unsigned char btRegion;//this+0x10
        class NSPOINT2 cell;//this+0x12
        //_step();    PATCH_MEMBER(CNSQuest::_step &, Constructor, , 0x49C540);

        /*struct _Invoke {
        PATCH_MEMBER_INVOKE(CNSQuest::_step &, CNSQuest::_step, Constructor, );
        };*/

#ifdef DEFINE_NS_CPP
        //DEFINE_NAKED_JMP(CNSQuest::_step::Constructor(), 0x49C540);
#endif
    };

    struct _reward {
        static const unsigned int _size = 0xc;

        unsigned char btType;//this+0x0
        unsigned long dwId;//this+0x4
        unsigned char btCount;//this+0x8
    };

    struct _dateTime {
        static const unsigned int _size = 0xc;

        unsigned short wYear;//this+0x0
        unsigned short wMonth;//this+0x2
        unsigned short wDay;//this+0x4
        unsigned short wHour;//this+0x6
        unsigned short wMinute;//this+0x8
        unsigned short wSecond;//this+0xA
    };

    CNSQuest(); CNSQuest& Constructor();   PATCH_MEMBER(CNSQuest &, Constructor, , 0x4996D0);
    char * GetQuestTitle();    PATCH_MEMBER(char *, GetQuestTitle, , 0x48FAB0);
    CNSQuest::QUESTKIND GetQuestKind();    PATCH_MEMBER(CNSQuest::QUESTKIND, GetQuestKind, , 0x43EDF0);
    unsigned short GetRewardTitleId();    PATCH_MEMBER(unsigned short, GetRewardTitleId, , 0x499770);
    unsigned short m_wQuestId;//this+0x0
    unsigned char m_btQuestKind;//this+0x2
    unsigned char m_btQuestLevel;//this+0x3
    unsigned char m_btCompleted;//this+0x4
    unsigned char m_btStep;//this+0x5
    unsigned long m_btCheckCount;//this+0x8
    unsigned char m_btPoint;//this+0xC
    unsigned char m_btCompletedDb;//this+0xD
    unsigned char m_btStepDb;//this+0xE
    unsigned long m_btCheckCountDb;//this+0x10
    unsigned char m_btPointDb;//this+0x14
    unsigned long m_dwTimeOut;//this+0x18
    char * m_szQuestTitle;//this+0x1C
    char * m_szSummary;//this+0x20
    unsigned char m_btStepCount;//this+0x24
    struct CNSQuest::_step m_stepArray[0xF];//this+0x28
    unsigned char m_btRewardCount;//this+0x190
    struct CNSQuest::_reward m_rewardArray[0x8];//this+0x194

    /*struct _Invoke {
    PATCH_MEMBER_INVOKE(CNSQuest &, CNSQuest, Constructor, );
    PATCH_MEMBER_INVOKE(char *, CNSQuest, GetQuestTitle, );
    PATCH_MEMBER_INVOKE(CNSQuest::QUESTKIND, CNSQuest, GetQuestKind, );
    PATCH_MEMBER_INVOKE(unsigned short, CNSQuest, GetRewardTitleId, );
    };*/
};
#ifdef DEFINE_NS_CPP
DEFINE_NAKED_JMP(CNSQuest& CNSQuest::Constructor(), 0x4996D0);
//DEFINE_NAKED_JMP(char * CNSQuest::GetQuestTitle(), 0x48FAB0);
//DEFINE_NAKED_JMP(CNSQuest::QUESTKIND CNSQuest::GetQuestKind(), 0x43EDF0);
//DEFINE_NAKED_JMP(unsigned short CNSQuest::GetRewardTitleId(), 0x499770);
#endif



class CNSQuestList {
public:
    static const unsigned int _size = 0x186ac;


    CNSQuestList(const CNSQuestList &);
    CNSQuestList();    PATCH_MEMBER(CNSQuestList &, Constructor, , 0x4997D0);
    virtual ~CNSQuestList();    PATCH_MEMBER(void, Destructor, , 0x499810);
    unsigned long GetCount();    PATCH_MEMBER(unsigned long, GetCount, , 0x402210);
    unsigned long GetProgressTitleCount();    PATCH_MEMBER(unsigned long, GetProgressTitleCount, , 0x49AD10);
    int IsFull();    PATCH_MEMBER(int, IsFull, , 0x49C590);
    void Clear();    PATCH_MEMBER(void, Clear, , 0x499830);
    CNSQuest * Add(unsigned short);    PATCH_MEMBER(CNSQuest *, Add, unsigned short, 0x4999A0);
    CNSQuest * Add(unsigned short, unsigned char, unsigned char, unsigned long, unsigned char, CNSQuest::_dateTime &);    PATCH_MEMBER(CNSQuest *, Add, unsigned short _COMMA unsigned char _COMMA unsigned char _COMMA unsigned long _COMMA unsigned char _COMMA CNSQuest::_dateTime &, 0x4998C0);
    int DbAdd(unsigned short);
    int Delete(unsigned short);    PATCH_MEMBER(int, Delete, unsigned short, 0x499A90);
    CNSQuest * Find(unsigned short);    PATCH_MEMBER(CNSQuest *, Find, unsigned short, 0x499860);
    int GetComplete(unsigned short);    PATCH_MEMBER(int, GetComplete, unsigned short, 0x49A1B0);
    int SetComplete(unsigned short);    PATCH_MEMBER(int, SetComplete, unsigned short, 0x49A1F0);
    void SetTimeOut(unsigned short, unsigned long);    PATCH_MEMBER(void, SetTimeOut, unsigned short _COMMA unsigned long, 0x49AC30);
    int CheckTimeOut(unsigned short, unsigned long);    PATCH_MEMBER(int, CheckTimeOut, unsigned short _COMMA unsigned long, 0x49AC70);
    void ClearTimeOut(unsigned short);    PATCH_MEMBER(void, ClearTimeOut, unsigned short, 0x49ABA0);
    int IsTimeOut(unsigned short);    PATCH_MEMBER(int, IsTimeOut, unsigned short, 0x49ABF0);
    int GetRemainTime(unsigned short);    PATCH_MEMBER(int, GetRemainTime, unsigned short, 0x49ACB0);
    unsigned char GetStep(unsigned short);    PATCH_MEMBER(unsigned char, GetStep, unsigned short, 0x49A320);
    int CheckCompleteStep(unsigned short);    PATCH_MEMBER(int, CheckCompleteStep, unsigned short, 0x49A350);
    int SetNextStep(unsigned short, unsigned char);    PATCH_MEMBER(int, SetNextStep, unsigned short _COMMA unsigned char, 0x49A3C0);
    int SetStep(unsigned short, unsigned char);    PATCH_MEMBER(int, SetStep, unsigned short _COMMA unsigned char, 0x49A4B0);
    int SetClear(unsigned short);    PATCH_MEMBER(int, SetClear, unsigned short, 0x49A570);
    void OnChangeStep(CNSQuest *);    PATCH_MEMBER(void, OnChangeStep, CNSQuest *, 0x49C5B0);
    int AddPoint(unsigned short, int);    PATCH_MEMBER(int, AddPoint, unsigned short _COMMA int, 0x49A610);
    unsigned char GetPoint(unsigned short);    PATCH_MEMBER(unsigned char, GetPoint, unsigned short, 0x49A680);
    void CheckMob(unsigned short);    PATCH_MEMBER(void, CheckMob, unsigned short, 0x49A950);
    int CheckItem(unsigned short, int);    PATCH_MEMBER(int, CheckItem, unsigned short _COMMA int, 0x49AF50);
    void CheckItemAll();    PATCH_MEMBER(void, CheckItemAll, , 0x49AD80);
    int Reward(unsigned short);    PATCH_MEMBER(int, Reward, unsigned short, 0x49A6B0);
    int GetSummary(unsigned short, char *);    PATCH_MEMBER(int, GetSummary, unsigned short _COMMA char *, 0x499C00);
    void SetParent(CNSPc *);    PATCH_MEMBER(void, SetParent, CNSPc *, 0x481CD0);
    unsigned long PacketList(CPacket &);    PATCH_MEMBER(unsigned long, PacketList, CPacket &, 0x49B1B0);
    void SendQuestAddMessage(CNSQuest *);    PATCH_MEMBER(void, SendQuestAddMessage, CNSQuest *, 0x49B320);
    void SendQuestUpdateMessage(CNSQuest *, unsigned char);    PATCH_MEMBER(void, SendQuestUpdateMessage, CNSQuest * _COMMA unsigned char, 0x49B4B0);
    class CNSPc * m_pParent;//this+0x4
    unsigned long m_dwCount;//this+0x8
    class CNSQuest m_questList[0xC8];//this+0xC
    unsigned char GetProgressPer(CNSQuest *);    PATCH_MEMBER(unsigned char, GetProgressPer, CNSQuest *, 0x49C600);
    unsigned char GetRegion(CNSQuest *);    PATCH_MEMBER(unsigned char, GetRegion, CNSQuest *, 0x49C6C0);
    unsigned short GetPosX(CNSQuest *);    PATCH_MEMBER(unsigned short, GetPosX, CNSQuest *, 0x49C6F0);
    unsigned short GetPosY(CNSQuest *);    PATCH_MEMBER(unsigned short, GetPosY, CNSQuest *, 0x49C720);
    CNSQuestList & operator=(const CNSQuestList &);
    //void __local_vftable_ctor_closure();
    //virtual void * __vecDelDtor(unsigned int);

    /*struct _Invoke {
    PATCH_MEMBER_INVOKE(CNSQuestList &, CNSQuestList, Constructor, );
    PATCH_MEMBER_INVOKE(void, CNSQuestList, Destructor, );
    PATCH_MEMBER_INVOKE(unsigned long, CNSQuestList, GetCount, );
    PATCH_MEMBER_INVOKE(unsigned long, CNSQuestList, GetProgressTitleCount, );
    PATCH_MEMBER_INVOKE(int, CNSQuestList, IsFull, );
    PATCH_MEMBER_INVOKE(void, CNSQuestList, Clear, );
    PATCH_MEMBER_INVOKE(CNSQuest *, CNSQuestList, Add, unsigned short);
    PATCH_MEMBER_INVOKE(CNSQuest *, CNSQuestList, Add, unsigned short _COMMA unsigned char _COMMA unsigned char _COMMA unsigned long _COMMA unsigned char _COMMA CNSQuest::_dateTime &);
    PATCH_MEMBER_INVOKE(int, CNSQuestList, Delete, unsigned short);
    PATCH_MEMBER_INVOKE(CNSQuest *, CNSQuestList, Find, unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSQuestList, GetComplete, unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSQuestList, SetComplete, unsigned short);
    PATCH_MEMBER_INVOKE(void, CNSQuestList, SetTimeOut, unsigned short _COMMA unsigned long);
    PATCH_MEMBER_INVOKE(int, CNSQuestList, CheckTimeOut, unsigned short _COMMA unsigned long);
    PATCH_MEMBER_INVOKE(void, CNSQuestList, ClearTimeOut, unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSQuestList, IsTimeOut, unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSQuestList, GetRemainTime, unsigned short);
    PATCH_MEMBER_INVOKE(unsigned char, CNSQuestList, GetStep, unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSQuestList, CheckCompleteStep, unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSQuestList, SetNextStep, unsigned short _COMMA unsigned char);
    PATCH_MEMBER_INVOKE(int, CNSQuestList, SetStep, unsigned short _COMMA unsigned char);
    PATCH_MEMBER_INVOKE(int, CNSQuestList, SetClear, unsigned short);
    PATCH_MEMBER_INVOKE(void, CNSQuestList, OnChangeStep, CNSQuest *);
    PATCH_MEMBER_INVOKE(int, CNSQuestList, AddPoint, unsigned short _COMMA int);
    PATCH_MEMBER_INVOKE(unsigned char, CNSQuestList, GetPoint, unsigned short);
    PATCH_MEMBER_INVOKE(void, CNSQuestList, CheckMob, unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSQuestList, CheckItem, unsigned short _COMMA int);
    PATCH_MEMBER_INVOKE(void, CNSQuestList, CheckItemAll, );
    PATCH_MEMBER_INVOKE(int, CNSQuestList, Reward, unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSQuestList, GetSummary, unsigned short _COMMA char *);
    PATCH_MEMBER_INVOKE(void, CNSQuestList, SetParent, CNSPc *);
    PATCH_MEMBER_INVOKE(unsigned long, CNSQuestList, PacketList, CPacket &);
    PATCH_MEMBER_INVOKE(void, CNSQuestList, SendQuestAddMessage, CNSQuest *);
    PATCH_MEMBER_INVOKE(void, CNSQuestList, SendQuestUpdateMessage, CNSQuest * _COMMA unsigned char);
    PATCH_MEMBER_INVOKE(unsigned char, CNSQuestList, GetProgressPer, CNSQuest *);
    PATCH_MEMBER_INVOKE(unsigned char, CNSQuestList, GetRegion, CNSQuest *);
    PATCH_MEMBER_INVOKE(unsigned short, CNSQuestList, GetPosX, CNSQuest *);
    PATCH_MEMBER_INVOKE(unsigned short, CNSQuestList, GetPosY, CNSQuest *);
    };*/
};
#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(CNSQuestList::Constructor(), 0x4997D0);
//DEFINE_NAKED_JMP(CNSQuestList::Destructor(), 0x499810);
DEFINE_NAKED_JMP(unsigned long CNSQuestList::GetCount(), 0x402210);
DEFINE_NAKED_JMP(unsigned long CNSQuestList::GetProgressTitleCount(), 0x49AD10);
DEFINE_NAKED_JMP(int CNSQuestList::IsFull(), 0x49C590);
DEFINE_NAKED_JMP(void CNSQuestList::Clear(), 0x499830);
DEFINE_NAKED_JMP(CNSQuest * CNSQuestList::Add(unsigned short), 0x4999A0);
DEFINE_NAKED_JMP(CNSQuest * CNSQuestList::Add(unsigned short _COMMA unsigned char _COMMA unsigned char _COMMA unsigned long _COMMA unsigned char _COMMA CNSQuest::_dateTime &), 0x4998C0);
DEFINE_NAKED_JMP(int CNSQuestList::Delete(unsigned short), 0x499A90);
DEFINE_NAKED_JMP(CNSQuest * CNSQuestList::Find(unsigned short), 0x499860);
DEFINE_NAKED_JMP(int CNSQuestList::GetComplete(unsigned short), 0x49A1B0);
DEFINE_NAKED_JMP(int CNSQuestList::SetComplete(unsigned short), 0x49A1F0);
DEFINE_NAKED_JMP(void CNSQuestList::SetTimeOut(unsigned short _COMMA unsigned long), 0x49AC30);
DEFINE_NAKED_JMP(int CNSQuestList::CheckTimeOut(unsigned short _COMMA unsigned long), 0x49AC70);
DEFINE_NAKED_JMP(void CNSQuestList::ClearTimeOut(unsigned short), 0x49ABA0);
DEFINE_NAKED_JMP(int CNSQuestList::IsTimeOut(unsigned short), 0x49ABF0);
DEFINE_NAKED_JMP(int CNSQuestList::GetRemainTime(unsigned short), 0x49ACB0);
DEFINE_NAKED_JMP(unsigned char CNSQuestList::GetStep(unsigned short), 0x49A320);
DEFINE_NAKED_JMP(int CNSQuestList::CheckCompleteStep(unsigned short), 0x49A350);
DEFINE_NAKED_JMP(int CNSQuestList::SetNextStep(unsigned short _COMMA unsigned char), 0x49A3C0);
DEFINE_NAKED_JMP(int CNSQuestList::SetStep(unsigned short _COMMA unsigned char), 0x49A4B0);
DEFINE_NAKED_JMP(int CNSQuestList::SetClear(unsigned short), 0x49A570);
DEFINE_NAKED_JMP(void CNSQuestList::OnChangeStep(CNSQuest *), 0x49C5B0);
DEFINE_NAKED_JMP(int CNSQuestList::AddPoint(unsigned short _COMMA int), 0x49A610);
DEFINE_NAKED_JMP(unsigned char CNSQuestList::GetPoint(unsigned short), 0x49A680);
DEFINE_NAKED_JMP(void CNSQuestList::CheckMob(unsigned short), 0x49A950);
DEFINE_NAKED_JMP(int CNSQuestList::CheckItem(unsigned short _COMMA int), 0x49AF50);
DEFINE_NAKED_JMP(void CNSQuestList::CheckItemAll(), 0x49AD80);
DEFINE_NAKED_JMP(int CNSQuestList::Reward(unsigned short), 0x49A6B0);
DEFINE_NAKED_JMP(int CNSQuestList::GetSummary(unsigned short _COMMA char *), 0x499C00);
DEFINE_NAKED_JMP(void CNSQuestList::SetParent(CNSPc *), 0x481CD0);
DEFINE_NAKED_JMP(unsigned long CNSQuestList::PacketList(CPacket &), 0x49B1B0);
DEFINE_NAKED_JMP(void CNSQuestList::SendQuestAddMessage(CNSQuest *), 0x49B320);
DEFINE_NAKED_JMP(void CNSQuestList::SendQuestUpdateMessage(CNSQuest * _COMMA unsigned char), 0x49B4B0);
DEFINE_NAKED_JMP(unsigned char CNSQuestList::GetProgressPer(CNSQuest *), 0x49C600);
DEFINE_NAKED_JMP(unsigned char CNSQuestList::GetRegion(CNSQuest *), 0x49C6C0);
DEFINE_NAKED_JMP(unsigned short CNSQuestList::GetPosX(CNSQuest *), 0x49C6F0);
DEFINE_NAKED_JMP(unsigned short CNSQuestList::GetPosY(CNSQuest *), 0x49C720);
#endif






#endif