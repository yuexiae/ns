#ifndef NSHEADER_NS_RESERVE_MANAGER_H_
#define NSHEADER_NS_RESERVE_MANAGER_H_


class CNSReserveManager;

template <>
class CSingleton<CNSReserveManager> {
public:
    static const unsigned int _size = 0x1;

    static CNSReserveManager * GetInstance();    PATCH_STATIC(CNSReserveManager *, GetInstance, , 0x48E5B0);
    static void ReleaseInstance();
    static class CNSReserveManager * m_selfInstance;//[0x577FB0]  [00177FB0:0003:00057FB0]

/*struct _Invoke {
PATCH_STATIC_INVOKE(CNSReserveManager *, GetInstance, );
};*/
};
#ifdef DEFINE_NS_CPP
DEFINE_NAKED_JMP(CNSReserveManager * CSingleton<CNSReserveManager>::GetInstance(), 0x48E5B0);
#endif

class CNSReserveManager : public CSingleton<CNSReserveManager> {
public:
    static const unsigned int _size = 0x34d4;

    CNSReserveManager(const CNSReserveManager &);
    CNSReserveManager();    PATCH_MEMBER(CNSReserveManager &, Constructor, , 0x49C9C0);
    virtual ~CNSReserveManager();    PATCH_MEMBER(void, Destructor, , 0x49CA90);
    virtual int Init();    PATCH_MEMBER(int, Init, , 0x49CB10);
    int Start(int, char *, unsigned short, unsigned short);    PATCH_MEMBER(int, Start, int _COMMA char * _COMMA unsigned short _COMMA unsigned short, 0x49CB20);
    void End(int);    PATCH_MEMBER(void, End, int, 0x49CBC0);
    int Add(int, CNSPc *);    PATCH_MEMBER(int, Add, int _COMMA CNSPc *, 0x49CD10);
    int Delete(int, CNSPc *);    PATCH_MEMBER(int, Delete, int _COMMA CNSPc *, 0x49CE40);
    unsigned long Warp(int, unsigned long);    PATCH_MEMBER(unsigned long, Warp, int _COMMA unsigned long, 0x49CF60);
    void Broadcast();    PATCH_MEMBER(void, Broadcast, , 0x49D130);
    int IsStart(int);    PATCH_MEMBER(int, IsStart, int, 0x4B0A20);
    struct _KeyInfo {
        static const unsigned int _size = 0x108;

        int bStart;//this+0x0
        char szComment[0x100];//this+0x4
        class NSPOINT2 cell;//this+0x104
        _KeyInfo();    PATCH_MEMBER(CNSReserveManager::_KeyInfo &, Constructor, , 0x49D310);

/*struct _Invoke {
PATCH_MEMBER_INVOKE(CNSReserveManager::_KeyInfo &, CNSReserveManager::_KeyInfo, Constructor, );
};*/

#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(CNSReserveManager::_KeyInfo::Constructor(), 0x49D310);
#endif
    };

    struct CNSReserveManager::_KeyInfo m_KeyArray[0xA];//this+0x4
    unsigned long m_dwKeySeq[0xA];//this+0xA54
    class std::map<int,unsigned long,std::less<int>,std::allocator<std::pair<int const ,unsigned long> > > m_mapReserveUser[0xA];//this+0xA7C
    class CNSCriticalSection m_cs[0xA];//this+0xBBC
    std::_Tree<std::_Tmap_traits<int,unsigned long,std::less<int>,std::allocator<std::pair<int const ,unsigned long> >,0> >::iterator Find(int, int);    PATCH_MEMBER(std::_Tree<std::_Tmap_traits<int _COMMA unsigned long _COMMA std::less<int> _COMMA std::allocator<std::pair<int const  _COMMA unsigned long> > _COMMA 0> >::iterator, Find, int _COMMA int, 0x49CC40);
    CNSReserveManager & operator=(const CNSReserveManager &);
    //void __local_vftable_ctor_closure();
    //virtual void * __vecDelDtor(unsigned int);

/*struct _Invoke {
PATCH_MEMBER_INVOKE(CNSReserveManager &, CNSReserveManager, Constructor, );
PATCH_MEMBER_INVOKE(void, CNSReserveManager, Destructor, );
PATCH_MEMBER_INVOKE(int, CNSReserveManager, Init, );
PATCH_MEMBER_INVOKE(int, CNSReserveManager, Start, int _COMMA char * _COMMA unsigned short _COMMA unsigned short);
PATCH_MEMBER_INVOKE(void, CNSReserveManager, End, int);
PATCH_MEMBER_INVOKE(int, CNSReserveManager, Add, int _COMMA CNSPc *);
PATCH_MEMBER_INVOKE(int, CNSReserveManager, Delete, int _COMMA CNSPc *);
PATCH_MEMBER_INVOKE(unsigned long, CNSReserveManager, Warp, int _COMMA unsigned long);
PATCH_MEMBER_INVOKE(void, CNSReserveManager, Broadcast, );
PATCH_MEMBER_INVOKE(int, CNSReserveManager, IsStart, int);
PATCH_MEMBER_INVOKE(std::_Tree<std::_Tmap_traits<int _COMMA unsigned long _COMMA std::less<int> _COMMA std::allocator<std::pair<int const  _COMMA unsigned long> > _COMMA 0> >::iterator, CNSReserveManager, Find, int _COMMA int);
};*/
};
#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(CNSReserveManager::Constructor(), 0x49C9C0);
//DEFINE_NAKED_JMP(CNSReserveManager::Destructor(), 0x49CA90);
//DEFINE_NAKED_JMP(int CNSReserveManager::Init(), 0x49CB10);
//DEFINE_NAKED_JMP(int CNSReserveManager::Start(int _COMMA char * _COMMA unsigned short _COMMA unsigned short), 0x49CB20);
//DEFINE_NAKED_JMP(void CNSReserveManager::End(int), 0x49CBC0);
//DEFINE_NAKED_JMP(int CNSReserveManager::Add(int _COMMA CNSPc *), 0x49CD10);
//DEFINE_NAKED_JMP(int CNSReserveManager::Delete(int _COMMA CNSPc *), 0x49CE40);
//DEFINE_NAKED_JMP(unsigned long CNSReserveManager::Warp(int _COMMA unsigned long), 0x49CF60);
DEFINE_NAKED_JMP(void CNSReserveManager::Broadcast(), 0x49D130);
//DEFINE_NAKED_JMP(int CNSReserveManager::IsStart(int), 0x4B0A20);
//DEFINE_NAKED_JMP(std::_Tree<std::_Tmap_traits<int _COMMA unsigned long _COMMA std::less<int> _COMMA std::allocator<std::pair<int const  _COMMA unsigned long> > _COMMA 0> >::iterator CNSReserveManager::Find(int _COMMA int), 0x49CC40);
#endif


#endif