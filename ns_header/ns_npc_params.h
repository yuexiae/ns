#ifndef NSHEADER_NPC_PARAMS_H_
#define NSHEADER_NPC_PARAMS_H_

class CNSNpcParams;
class CNSNpcParamsExt;

template<>
class CSingleton<CNSNpcParams> {
public:
    static const unsigned int _size = 0x1;

    static CNSNpcParamsExt * GetInstance();    PATCH_STATIC(CNSNpcParams *, GetInstance, , 0x403400);
    static void ReleaseInstance();    PATCH_STATIC(void, ReleaseInstance, , 0x403490);
    static class CNSNpcParams * m_selfInstance;//[0x559E14]  [00159E14:0003:00039E14]

/*struct _Invoke {
PATCH_STATIC_INVOKE(CNSNpcParams *, GetInstance, );
PATCH_STATIC_INVOKE(void, ReleaseInstance, );
};*/
};
#ifdef DEFINE_NS_CPP
DEFINE_NAKED_JMP(CNSNpcParamsExt * CSingleton<CNSNpcParams>::GetInstance(), 0x403400);
//DEFINE_NAKED_JMP(void CSingleton<CNSNpcParams>::ReleaseInstance(), 0x403490);
#endif




class CNSNpcParams : public CSingleton<CNSNpcParams> {
public:
    static const unsigned int _size = 0xe4;

    struct _NpcArrange {
        static const unsigned int _size = 0x20;

        int nSeq;//this+0x0
        unsigned char btRegion;//this+0x4
        unsigned long dwInstantKey;//this+0x8
        class NSPOINT2 cellPos;//this+0xC
        unsigned short wAngle;//this+0x10
        unsigned short wScope;//this+0x12
        unsigned short wNpcId;//this+0x14
        unsigned char btNpcCount;//this+0x16
        unsigned short wRespawnSecond;//this+0x18
        unsigned short wLimitMoveScope;//this+0x1A
        unsigned short wPathId;//this+0x1C
        //_NpcArrange();    PATCH_MEMBER(CNSNpcParams::_NpcArrange &, Constructor, , 0x454130);

/*struct _Invoke {
PATCH_MEMBER_INVOKE(CNSNpcParams::_NpcArrange &, CNSNpcParams::_NpcArrange, Constructor, );
};*/

#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(CNSNpcParams::_NpcArrange::Constructor(), 0x454130);
#endif
    };

    struct _NpcDropItem {
        static const unsigned int _size = 0x128;

        unsigned short wNpcId;//this+0x0
        unsigned long dwGold;//this+0x4
        unsigned long dwProArray[0x30];//this+0x8
        unsigned short wItemArray[0x30];//this+0xC8
    };

    struct _NpcScript {
        static const unsigned int _size = 0x8;

        unsigned short wNpcId;//this+0x0
        char * szScript;//this+0x4
    };

    struct _NpcPath {
        static const unsigned int _size = 0x58;

        unsigned short wNpcId;//this+0x0
        unsigned long dwCount;//this+0x4
        class NSPOINT2 cell[0x14];//this+0x8
        _NpcPath();    PATCH_MEMBER(CNSNpcParams::_NpcPath &, Constructor, , 0x454150);

/*struct _Invoke {
PATCH_MEMBER_INVOKE(CNSNpcParams::_NpcPath &, CNSNpcParams::_NpcPath, Constructor, );
};*/

#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(CNSNpcParams::_NpcPath::Constructor(), 0x454150);
#endif
    };

    struct _NpcArrangePath {
        static const unsigned int _size = 0x58;

        unsigned short wPathId;//this+0x0
        unsigned long dwCount;//this+0x4
        class NSPOINT2 cell[0x14];//this+0x8
        _NpcArrangePath();    PATCH_MEMBER(CNSNpcParams::_NpcArrangePath &, Constructor, , 0x454150);

/*struct _Invoke {
PATCH_MEMBER_INVOKE(CNSNpcParams::_NpcArrangePath &, CNSNpcParams::_NpcArrangePath, Constructor, );
};*/

#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(CNSNpcParams::_NpcArrangePath::Constructor(), 0x454150);
#endif
    };

    struct _PetMsg {
        static const unsigned int _size = 0x202;

        unsigned char btRegion;//this+0x0
        unsigned char btLevel;//this+0x1
        char szMsg[0x200];//this+0x2
    };


    CNSNpcParams(const CNSNpcParams &);
    CNSNpcParams();    PATCH_MEMBER(CNSNpcParams &, Constructor, , 0x451530);
    virtual ~CNSNpcParams();    PATCH_MEMBER(void, Destructor, , 0x4515F0);
    virtual int Init();    PATCH_MEMBER(int, Init, , 0x451730);
    int Load();    PATCH_MEMBER(int, Load, , 0x451750);
    CNSNpc * GetObjectA(unsigned short);    PATCH_MEMBER(CNSNpc *, GetObjectA, unsigned short, 0x4517D0);
    char * GetName(unsigned short);    PATCH_MEMBER(char *, GetName, unsigned short, 0x451820);
    CNSNpcParams::_NpcArrange * GetObjectNpcArrange(unsigned long);    PATCH_MEMBER(CNSNpcParams::_NpcArrange *, GetObjectNpcArrange, unsigned long, 0x4518B0);
    CNSNpcParams::_NpcDropItem * GetObjectNpcDropItem(unsigned short);    PATCH_MEMBER(CNSNpcParams::_NpcDropItem *, GetObjectNpcDropItem, unsigned short, 0x451860);
    CNSNpcParams::_NpcPath * GetObjectNpcPath(unsigned short);    PATCH_MEMBER(CNSNpcParams::_NpcPath *, GetObjectNpcPath, unsigned short, 0x451900);
    CNSNpcParams::_NpcArrangePath * GetObjectNpcArrangePath(unsigned short);    PATCH_MEMBER(CNSNpcParams::_NpcArrangePath *, GetObjectNpcArrangePath, unsigned short, 0x451960);
    char * GetObjectNpcScript(unsigned short);    PATCH_MEMBER(char *, GetObjectNpcScript, unsigned short, 0x4519C0);
    char * GetDescriptNpc(unsigned short);    PATCH_MEMBER(char *, GetDescriptNpc, unsigned short, 0x451A20);
    char * GetPetMsg(unsigned char, unsigned char);    PATCH_MEMBER(char *, GetPetMsg, unsigned char _COMMA unsigned char, 0x451A80);
    class std::map<unsigned short,CNSNpc *,std::less<unsigned short>,std::allocator<std::pair<unsigned short const ,CNSNpc *> > > m_mapNpc;//this+0x4
    class std::map<unsigned short,CNSNpcParams::_NpcDropItem *,std::less<unsigned short>,std::allocator<std::pair<unsigned short const ,CNSNpcParams::_NpcDropItem *> > > m_mapNpcDropItem;//this+0x24
    class std::map<unsigned long,CNSNpcParams::_NpcArrange *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const ,CNSNpcParams::_NpcArrange *> > > m_mapNpcArrange;//this+0x44
    class std::map<unsigned long,CNSNpcParams::_NpcScript *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const ,CNSNpcParams::_NpcScript *> > > m_mapNpcScript;//this+0x64
    class std::map<unsigned short,CNSNpcParams::_NpcPath *,std::less<unsigned short>,std::allocator<std::pair<unsigned short const ,CNSNpcParams::_NpcPath *> > > m_mapNpcPath;//this+0x84
    class std::map<unsigned short,CNSNpcParams::_NpcArrangePath *,std::less<unsigned short>,std::allocator<std::pair<unsigned short const ,CNSNpcParams::_NpcArrangePath *> > > m_mapNpcArrangePath;//this+0xA4
    class std::map<unsigned short,CNSNpcParams::_PetMsg *,std::less<unsigned short>,std::allocator<std::pair<unsigned short const ,CNSNpcParams::_PetMsg *> > > m_mapPetMsg;//this+0xC4
    int LoadNpc();    PATCH_MEMBER(int, LoadNpc, , 0x451B00);
    int LoadNpcDropItem();    PATCH_MEMBER(int, LoadNpcDropItem, , 0x452080);
    int LoadNpcArrange();    PATCH_MEMBER(int, LoadNpcArrange, , 0x452400);
    int LoadNpcArrangeFile();    PATCH_MEMBER(int, LoadNpcArrangeFile, , 0x452840);
    int LoadNpcScript(CNSPc *, unsigned short);    PATCH_MEMBER(int, LoadNpcScript, CNSPc * _COMMA unsigned short, 0x453C10);
    int LoadNpcScript();    PATCH_MEMBER(int, LoadNpcScript, , 0x453560);
    int LoadNpcData();    PATCH_MEMBER(int, LoadNpcData, , 0x4530F0);
    int LoadNpcPathFile();    PATCH_MEMBER(int, LoadNpcPathFile, , 0x452A30);
    int LoadNpcArrangePathFile();    PATCH_MEMBER(int, LoadNpcArrangePathFile, , 0x452CA0);
    int LoadPetMsgFile();    PATCH_MEMBER(int, LoadPetMsgFile, , 0x452F10);
    CNSNpcParams & operator=(const CNSNpcParams &);
    //void __local_vftable_ctor_closure();
    //virtual void * __vecDelDtor(unsigned int);

/*struct _Invoke {
PATCH_MEMBER_INVOKE(CNSNpcParams &, CNSNpcParams, Constructor, );
PATCH_MEMBER_INVOKE(void, CNSNpcParams, Destructor, );
PATCH_MEMBER_INVOKE(int, CNSNpcParams, Init, );
PATCH_MEMBER_INVOKE(int, CNSNpcParams, Load, );
PATCH_MEMBER_INVOKE(CNSNpc *, CNSNpcParams, GetObjectA, unsigned short);
PATCH_MEMBER_INVOKE(char *, CNSNpcParams, GetName, unsigned short);
PATCH_MEMBER_INVOKE(CNSNpcParams::_NpcArrange *, CNSNpcParams, GetObjectNpcArrange, unsigned long);
PATCH_MEMBER_INVOKE(CNSNpcParams::_NpcDropItem *, CNSNpcParams, GetObjectNpcDropItem, unsigned short);
PATCH_MEMBER_INVOKE(CNSNpcParams::_NpcPath *, CNSNpcParams, GetObjectNpcPath, unsigned short);
PATCH_MEMBER_INVOKE(CNSNpcParams::_NpcArrangePath *, CNSNpcParams, GetObjectNpcArrangePath, unsigned short);
PATCH_MEMBER_INVOKE(char *, CNSNpcParams, GetObjectNpcScript, unsigned short);
PATCH_MEMBER_INVOKE(char *, CNSNpcParams, GetDescriptNpc, unsigned short);
PATCH_MEMBER_INVOKE(char *, CNSNpcParams, GetPetMsg, unsigned char _COMMA unsigned char);
PATCH_MEMBER_INVOKE(int, CNSNpcParams, LoadNpc, );
PATCH_MEMBER_INVOKE(int, CNSNpcParams, LoadNpcDropItem, );
PATCH_MEMBER_INVOKE(int, CNSNpcParams, LoadNpcArrange, );
PATCH_MEMBER_INVOKE(int, CNSNpcParams, LoadNpcArrangeFile, );
PATCH_MEMBER_INVOKE(int, CNSNpcParams, LoadNpcScript, CNSPc * _COMMA unsigned short);
PATCH_MEMBER_INVOKE(int, CNSNpcParams, LoadNpcScript, );
PATCH_MEMBER_INVOKE(int, CNSNpcParams, LoadNpcData, );
PATCH_MEMBER_INVOKE(int, CNSNpcParams, LoadNpcPathFile, );
PATCH_MEMBER_INVOKE(int, CNSNpcParams, LoadNpcArrangePathFile, );
PATCH_MEMBER_INVOKE(int, CNSNpcParams, LoadPetMsgFile, );
};*/
};
#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(CNSNpcParams::Constructor(), 0x451530);
//DEFINE_NAKED_JMP(CNSNpcParams::Destructor(), 0x4515F0);
//DEFINE_NAKED_JMP(int CNSNpcParams::Init(), 0x451730);
//DEFINE_NAKED_JMP(int CNSNpcParams::Load(), 0x451750);
DEFINE_NAKED_JMP(CNSNpc * CNSNpcParams::GetObjectA(unsigned short), 0x4517D0);
DEFINE_NAKED_JMP(char * CNSNpcParams::GetName(unsigned short), 0x451820);
DEFINE_NAKED_JMP(CNSNpcParams::_NpcArrange * CNSNpcParams::GetObjectNpcArrange(unsigned long), 0x4518B0);
DEFINE_NAKED_JMP(CNSNpcParams::_NpcDropItem * CNSNpcParams::GetObjectNpcDropItem(unsigned short), 0x451860);
DEFINE_NAKED_JMP(CNSNpcParams::_NpcPath * CNSNpcParams::GetObjectNpcPath(unsigned short), 0x451900);
DEFINE_NAKED_JMP(CNSNpcParams::_NpcArrangePath * CNSNpcParams::GetObjectNpcArrangePath(unsigned short), 0x451960);
DEFINE_NAKED_JMP(char * CNSNpcParams::GetObjectNpcScript(unsigned short), 0x4519C0);
DEFINE_NAKED_JMP(char * CNSNpcParams::GetDescriptNpc(unsigned short), 0x451A20);
DEFINE_NAKED_JMP(char * CNSNpcParams::GetPetMsg(unsigned char _COMMA unsigned char), 0x451A80);
//DEFINE_NAKED_JMP(int CNSNpcParams::LoadNpc(), 0x451B00);
//DEFINE_NAKED_JMP(int CNSNpcParams::LoadNpcDropItem(), 0x452080);
//DEFINE_NAKED_JMP(int CNSNpcParams::LoadNpcArrange(), 0x452400);
//DEFINE_NAKED_JMP(int CNSNpcParams::LoadNpcArrangeFile(), 0x452840);
//DEFINE_NAKED_JMP(int CNSNpcParams::LoadNpcScript(CNSPc * _COMMA unsigned short), 0x453C10);
//DEFINE_NAKED_JMP(int CNSNpcParams::LoadNpcScript(), 0x453560);
//DEFINE_NAKED_JMP(int CNSNpcParams::LoadNpcData(), 0x4530F0);
//DEFINE_NAKED_JMP(int CNSNpcParams::LoadNpcPathFile(), 0x452A30);
//DEFINE_NAKED_JMP(int CNSNpcParams::LoadNpcArrangePathFile(), 0x452CA0);
//DEFINE_NAKED_JMP(int CNSNpcParams::LoadPetMsgFile(), 0x452F10);
#endif



#endif