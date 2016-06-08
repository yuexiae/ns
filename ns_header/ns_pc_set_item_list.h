#ifndef NSHEADER_NS_PC_SET_ITEM_LIST_H_
#define NSHEADER_NS_PC_SET_ITEM_LIST_H_


class CNSPcSetItemList {
public:
    static const unsigned int _size = 0xc8;

    struct SetItem {
        static const unsigned int _size = 0xc;

        unsigned short wSetId;//this+0x0
        unsigned long dwCount;//this+0x4
        class CNSItem * pItem;//this+0x8
    };

    struct CNSPcSetItemList::SetItem m_SetItemArray[0x5];//this+0x0
    CNSPcSetItemList();    PATCH_MEMBER(CNSPcSetItemList &, Constructor, , 0x492C50);
    void Clear();    PATCH_MEMBER(void, Clear, , 0x482420);
    void SetParent(CNSPc *);    PATCH_MEMBER(void, SetParent, CNSPc *, 0x481E30);
    int AddSet(unsigned short, unsigned short);    PATCH_MEMBER(int, AddSet, unsigned short _COMMA unsigned short, 0x492CE0);
    int CheckItemId(unsigned short);    PATCH_MEMBER(int, CheckItemId, unsigned short, 0x492C70);
    CNSItem * GetSetItem(unsigned short);    PATCH_MEMBER(CNSItem *, GetSetItem, unsigned short, 0x492E40);
    unsigned long GetSetCount(unsigned short);    PATCH_MEMBER(unsigned long, GetSetCount, unsigned short, 0x492E90);
    class CNSPc * m_pParent;//this+0x3C
    unsigned short m_wItemIdArray[0x43];//this+0x40

    /*struct _Invoke {
    PATCH_MEMBER_INVOKE(CNSPcSetItemList &, CNSPcSetItemList, Constructor, );
    PATCH_MEMBER_INVOKE(void, CNSPcSetItemList, Clear, );
    PATCH_MEMBER_INVOKE(void, CNSPcSetItemList, SetParent, CNSPc *);
    PATCH_MEMBER_INVOKE(int, CNSPcSetItemList, AddSet, unsigned short _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(int, CNSPcSetItemList, CheckItemId, unsigned short);
    PATCH_MEMBER_INVOKE(CNSItem *, CNSPcSetItemList, GetSetItem, unsigned short);
    PATCH_MEMBER_INVOKE(unsigned long, CNSPcSetItemList, GetSetCount, unsigned short);
    };*/
};
#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(CNSPcSetItemList::Constructor(), 0x492C50);
DEFINE_NAKED_JMP(void CNSPcSetItemList::Clear(), 0x482420);
DEFINE_NAKED_JMP(void CNSPcSetItemList::SetParent(CNSPc *), 0x481E30);
DEFINE_NAKED_JMP(int CNSPcSetItemList::AddSet(unsigned short _COMMA unsigned short), 0x492CE0);
DEFINE_NAKED_JMP(int CNSPcSetItemList::CheckItemId(unsigned short), 0x492C70);
DEFINE_NAKED_JMP(CNSItem * CNSPcSetItemList::GetSetItem(unsigned short), 0x492E40);
DEFINE_NAKED_JMP(unsigned long CNSPcSetItemList::GetSetCount(unsigned short), 0x492E90);
#endif






#endif