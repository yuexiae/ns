#ifndef NSHEADER_NS_ITEM_PARAMS_H_
#define NSHEADER_NS_ITEM_PARAMS_H_

#include "ns_header/ns_item.h"

class CNSItemParams;

template <>
class CSingleton<CNSItemParams> {
public:
    static const unsigned int _size = 0x1;

    static CNSItemParams * GetInstance();    PATCH_STATIC(CNSItemParams *, GetInstance, , 0x402FB0);
    static void ReleaseInstance();    PATCH_STATIC(void, ReleaseInstance, , 0x403040);
    static class CNSItemParams * m_selfInstance;//[0x559DFC]  [00159DFC:0003:00039DFC]

/*struct _Invoke {
PATCH_STATIC_INVOKE(CNSItemParams *, GetInstance, );
PATCH_STATIC_INVOKE(void, ReleaseInstance, );
};*/
};
#ifdef DEFINE_NS_CPP
DEFINE_NAKED_JMP(CNSItemParams * CSingleton<CNSItemParams>::GetInstance(), 0x402FB0);
//DEFINE_NAKED_JMP(void CSingleton<CNSItemParams>::ReleaseInstance(), 0x403040);
#endif

class CNSItemParams : public CSingleton<CNSItemParams> {
public:
    static const unsigned int _size = 0x4890;
    
    struct _ItemExt {
        static const unsigned int _size = 0x30;

        unsigned short wItemId;//this+0x0
        unsigned char btSeq;//this+0x2
        unsigned short wAttackMinDamage;//this+0x4
        unsigned short wAttackMaxDamage;//this+0x6
        struct _Option {
            static const unsigned int _size = 0x4;

            unsigned char btParam;//this+0x0
            unsigned short wValue;//this+0x2
        };

        struct CNSItemParams::_ItemExt::_Option Option[0xA];//this+0x8
    };

    struct _PremiumItem {
        static const unsigned int _size = 0x3c;

        unsigned char btCategory;//this+0x0
        unsigned char btSeq;//this+0x1
        char szGoodName[0x29];//this+0x2
        unsigned short wItemId;//this+0x2C
        unsigned char btItemCount;//this+0x2E
        int nGoodLimitCount;//this+0x30
        unsigned long dwGoodSellCount;//this+0x34
        unsigned long dwCash;//this+0x38
    };

    struct _SetItem {
        static const unsigned int _size = 0x734;

        unsigned long dwFullSet;//this+0x0
        class CNSItem itemArray[0xA];//this+0x4
        _SetItem(const CNSItemParams::_SetItem &);
        _SetItem();    PATCH_MEMBER(CNSItemParams::_SetItem &, Constructor, , 0x441DC0);
        ~_SetItem();    PATCH_MEMBER(void, Destructor, , 0x441DF0);
        CNSItemParams::_SetItem & operator=(const CNSItemParams::_SetItem &);
        //void * __vecDelDtor(unsigned int);

/*struct _Invoke {
PATCH_MEMBER_INVOKE(CNSItemParams::_SetItem &, CNSItemParams::_SetItem, Constructor, );
PATCH_MEMBER_INVOKE(void, CNSItemParams::_SetItem, Destructor, );
};*/

#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(CNSItemParams::_SetItem::Constructor(), 0x441DC0);
//DEFINE_NAKED_JMP(CNSItemParams::_SetItem::Destructor(), 0x441DF0);
#endif
    };

    struct _RandomItem {
        static const unsigned int _size = 0x50;

        struct _Item {
            static const unsigned int _size = 0x8;

            int nPro;//this+0x0
            unsigned short wItemId;//this+0x4
            unsigned char btItemCount;//this+0x6
        };

        struct CNSItemParams::_RandomItem::_Item Item[0xA];//this+0x0
    };

    CNSItemParams(const CNSItemParams &);
    CNSItemParams();    PATCH_MEMBER(CNSItemParams &, Constructor, , 0x43F9A0);
    virtual ~CNSItemParams();    PATCH_MEMBER(void, Destructor, , 0x43FA70);
    virtual int Init();    PATCH_MEMBER(int, Init, , 0x43FB10);
    int Load();    PATCH_MEMBER(int, Load, , 0x43FD10);
    int LoadItemExt();    PATCH_MEMBER(int, LoadItemExt, , 0x440290);
    int LoadPremiumShopParams();    PATCH_MEMBER(int, LoadPremiumShopParams, , 0x4405F0);
    int LoadRandomItemParams();    PATCH_MEMBER(int, LoadRandomItemParams, , 0x440940);
    CNSItem * GetObjectA(unsigned short);    PATCH_MEMBER(CNSItem *, GetObjectA, unsigned short, 0x440CE0);
    unsigned short GetCoreItemId(unsigned char, unsigned short, unsigned short);    PATCH_MEMBER(unsigned short, GetCoreItemId, unsigned char _COMMA unsigned short _COMMA unsigned short, 0x440D30);
    char * GetName(unsigned short);    PATCH_MEMBER(char *, GetName, unsigned short, 0x441040);
    char * GetDescriptItem(unsigned short);    PATCH_MEMBER(char *, GetDescriptItem, unsigned short, 0x43FCB0);
    CNSItemParams::_PremiumItem * GetPremiumItem(unsigned short);    PATCH_MEMBER(CNSItemParams::_PremiumItem *, GetPremiumItem, unsigned short, 0x441200);
    CNSItemParams::_RandomItem * GetRandomItem(unsigned short);    PATCH_MEMBER(CNSItemParams::_RandomItem *, GetRandomItem, unsigned short, 0x441250);
    int FillExtParams(CNSItem *, int);    PATCH_MEMBER(int, FillExtParams, CNSItem * _COMMA int, 0x441080);
    unsigned short PacketPremiumShopList(CNSPc *, CPacket &);    PATCH_MEMBER(unsigned short, PacketPremiumShopList, CNSPc * _COMMA CPacket &, 0x4412A0);
    unsigned short PacketPremiumShopLimitList(CNSPc *, CPacket &);    PATCH_MEMBER(unsigned short, PacketPremiumShopLimitList, CNSPc * _COMMA CPacket &, 0x441590);
    void InitSetItem();    PATCH_MEMBER(void, InitSetItem, , 0x441900);
    CNSItem * GetSetObject(unsigned short, unsigned long);    PATCH_MEMBER(CNSItem *, GetSetObject, unsigned short _COMMA unsigned long, 0x492EE0);
    unsigned long GetFullSetCount(unsigned short);    PATCH_MEMBER(unsigned long, GetFullSetCount, unsigned short, 0x43F650);
    int DebugEquipItem(CNSPc *, unsigned char, int);    PATCH_MEMBER(int, DebugEquipItem, CNSPc * _COMMA unsigned char _COMMA int, 0x440E40);
    void DebugEquipItemAll(CNSPc *, int);    PATCH_MEMBER(void, DebugEquipItemAll, CNSPc * _COMMA int, 0x440E50);
    class std::map<unsigned short,CNSItem *,std::less<unsigned short>,std::allocator<std::pair<unsigned short const ,CNSItem *> > > m_mapItem;//this+0x4
    class std::map<unsigned long,CNSItemParams::_ItemExt *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const ,CNSItemParams::_ItemExt *> > > m_mapItemExt;//this+0x24
    class std::map<unsigned short,CNSItemParams::_PremiumItem *,std::less<unsigned short>,std::allocator<std::pair<unsigned short const ,CNSItemParams::_PremiumItem *> > > m_mapPremiumItem;//this+0x44
    class std::map<unsigned short,CNSItemParams::_RandomItem *,std::less<unsigned short>,std::allocator<std::pair<unsigned short const ,CNSItemParams::_RandomItem *> > > m_mapRandomItem;//this+0x64
    struct CNSItemParams::_SetItem m_setItemArray[0xA];//this+0x84
    unsigned long m_dwLastPremiumItemLimitTime;//this+0x488C
    CNSItemParams & operator=(const CNSItemParams &);
    //void __local_vftable_ctor_closure();
    //virtual void * __vecDelDtor(unsigned int);

/*struct _Invoke {
PATCH_MEMBER_INVOKE(CNSItemParams &, CNSItemParams, Constructor, );
PATCH_MEMBER_INVOKE(void, CNSItemParams, Destructor, );
PATCH_MEMBER_INVOKE(int, CNSItemParams, Init, );
PATCH_MEMBER_INVOKE(int, CNSItemParams, Load, );
PATCH_MEMBER_INVOKE(int, CNSItemParams, LoadItemExt, );
PATCH_MEMBER_INVOKE(int, CNSItemParams, LoadPremiumShopParams, );
PATCH_MEMBER_INVOKE(int, CNSItemParams, LoadRandomItemParams, );
PATCH_MEMBER_INVOKE(CNSItem *, CNSItemParams, GetObjectA, unsigned short);
PATCH_MEMBER_INVOKE(unsigned short, CNSItemParams, GetCoreItemId, unsigned char _COMMA unsigned short _COMMA unsigned short);
PATCH_MEMBER_INVOKE(char *, CNSItemParams, GetName, unsigned short);
PATCH_MEMBER_INVOKE(char *, CNSItemParams, GetDescriptItem, unsigned short);
PATCH_MEMBER_INVOKE(CNSItemParams::_PremiumItem *, CNSItemParams, GetPremiumItem, unsigned short);
PATCH_MEMBER_INVOKE(CNSItemParams::_RandomItem *, CNSItemParams, GetRandomItem, unsigned short);
PATCH_MEMBER_INVOKE(int, CNSItemParams, FillExtParams, CNSItem * _COMMA int);
PATCH_MEMBER_INVOKE(unsigned short, CNSItemParams, PacketPremiumShopList, CNSPc * _COMMA CPacket &);
PATCH_MEMBER_INVOKE(unsigned short, CNSItemParams, PacketPremiumShopLimitList, CNSPc * _COMMA CPacket &);
PATCH_MEMBER_INVOKE(void, CNSItemParams, InitSetItem, );
PATCH_MEMBER_INVOKE(CNSItem *, CNSItemParams, GetSetObject, unsigned short _COMMA unsigned long);
PATCH_MEMBER_INVOKE(unsigned long, CNSItemParams, GetFullSetCount, unsigned short);
PATCH_MEMBER_INVOKE(int, CNSItemParams, DebugEquipItem, CNSPc * _COMMA unsigned char _COMMA int);
PATCH_MEMBER_INVOKE(void, CNSItemParams, DebugEquipItemAll, CNSPc * _COMMA int);
};*/
};
#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(CNSItemParams::Constructor(), 0x43F9A0);
//DEFINE_NAKED_JMP(CNSItemParams::Destructor(), 0x43FA70);
//DEFINE_NAKED_JMP(int CNSItemParams::Init(), 0x43FB10);
//DEFINE_NAKED_JMP(int CNSItemParams::Load(), 0x43FD10);
//DEFINE_NAKED_JMP(int CNSItemParams::LoadItemExt(), 0x440290);
//DEFINE_NAKED_JMP(int CNSItemParams::LoadPremiumShopParams(), 0x4405F0);
//DEFINE_NAKED_JMP(int CNSItemParams::LoadRandomItemParams(), 0x440940);
DEFINE_NAKED_JMP(CNSItem * CNSItemParams::GetObjectA(unsigned short), 0x440CE0);
DEFINE_NAKED_JMP(unsigned short CNSItemParams::GetCoreItemId(unsigned char _COMMA unsigned short _COMMA unsigned short), 0x440D30);
DEFINE_NAKED_JMP(char * CNSItemParams::GetName(unsigned short), 0x441040);
DEFINE_NAKED_JMP(char * CNSItemParams::GetDescriptItem(unsigned short), 0x43FCB0);
DEFINE_NAKED_JMP(CNSItemParams::_PremiumItem * CNSItemParams::GetPremiumItem(unsigned short), 0x441200);
DEFINE_NAKED_JMP(CNSItemParams::_RandomItem * CNSItemParams::GetRandomItem(unsigned short), 0x441250);
DEFINE_NAKED_JMP(int CNSItemParams::FillExtParams(CNSItem * _COMMA int), 0x441080);
DEFINE_NAKED_JMP(unsigned short CNSItemParams::PacketPremiumShopList(CNSPc * _COMMA CPacket &), 0x4412A0);
DEFINE_NAKED_JMP(unsigned short CNSItemParams::PacketPremiumShopLimitList(CNSPc * _COMMA CPacket &), 0x441590);
DEFINE_NAKED_JMP(void CNSItemParams::InitSetItem(), 0x441900);
DEFINE_NAKED_JMP(CNSItem * CNSItemParams::GetSetObject(unsigned short _COMMA unsigned long), 0x492EE0);
DEFINE_NAKED_JMP(unsigned long CNSItemParams::GetFullSetCount(unsigned short), 0x43F650);
DEFINE_NAKED_JMP(int CNSItemParams::DebugEquipItem(CNSPc * _COMMA unsigned char _COMMA int), 0x440E40);
DEFINE_NAKED_JMP(void CNSItemParams::DebugEquipItemAll(CNSPc * _COMMA int), 0x440E50);
#endif



#endif