#ifndef NSHEADER_NS_VR_BLOCK_MANAGER_H_
#define NSHEADER_NS_VR_BLOCK_MANAGER_H_

template <typename T, typename Y> class NSVrBlock;


template <>
class NSVrBlock<unsigned long,CNSPc *> {
public:
    static const unsigned int _size = 0x43c;

    class CNSCriticalSection m_cs;//this+0x0
    class std::map<unsigned long,CNSPc *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const ,CNSPc *> > > m_mapObject;//this+0x41C
    NSVrBlock<unsigned long,CNSPc *>(const NSVrBlock<unsigned long,CNSPc *> &);
    NSVrBlock<unsigned long,CNSPc *>();    PATCH_MEMBER(NSVrBlock<unsigned long _COMMA CNSPc *> &, Constructor, , 0x4DF4A0);
    ~NSVrBlock<unsigned long,CNSPc *>();    PATCH_MEMBER(void, Destructor, , 0x4DF500);
    int Add(unsigned long, CNSPc *);    PATCH_MEMBER(int, Add, unsigned long _COMMA CNSPc *, 0x4DF570);
    int Remove(unsigned long);    PATCH_MEMBER(int, Remove, unsigned long, 0x4DF600);
    CNSPc * Find(unsigned long);    PATCH_MEMBER(CNSPc *, Find, unsigned long, 0x4DF6A0);
    void Lock();
    void Unlock();
    unsigned int GetCount();    PATCH_MEMBER(unsigned int, GetCount, , 0x4DF480);
    NSVrBlock<unsigned long,CNSPc *> & operator=(const NSVrBlock<unsigned long,CNSPc *> &);
    //void * __vecDelDtor(unsigned int);

/*struct _Invoke {
PATCH_MEMBER_INVOKE(NSVrBlock<unsigned long,CNSPc *> &, NSVrBlock<unsigned long,CNSPc *>, Constructor, );
PATCH_MEMBER_INVOKE(void, NSVrBlock<unsigned long,CNSPc *>, Destructor, );
PATCH_MEMBER_INVOKE(int, NSVrBlock<unsigned long,CNSPc *>, Add, unsigned long _COMMA CNSPc *);
PATCH_MEMBER_INVOKE(int, NSVrBlock<unsigned long,CNSPc *>, Remove, unsigned long);
PATCH_MEMBER_INVOKE(CNSPc *, NSVrBlock<unsigned long,CNSPc *>, Find, unsigned long);
PATCH_MEMBER_INVOKE(std::_Tree<std::_Tmap_traits<unsigned long _COMMA CNSPc * _COMMA std::less<unsigned long> _COMMA std::allocator<std::pair<unsigned long const  _COMMA CNSPc *> > _COMMA 0> >::iterator, NSVrBlock<unsigned long,CNSPc *>, Begin, );
PATCH_MEMBER_INVOKE(std::_Tree<std::_Tmap_traits<unsigned long _COMMA CNSPc * _COMMA std::less<unsigned long> _COMMA std::allocator<std::pair<unsigned long const  _COMMA CNSPc *> > _COMMA 0> >::iterator, NSVrBlock<unsigned long,CNSPc *>, End, );
PATCH_MEMBER_INVOKE(unsigned int, NSVrBlock<unsigned long,CNSPc *>, GetCount, );
};*/
};
#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(NSVrBlock<unsigned long,CNSPc *>::Constructor(), 0x4DF4A0);
//DEFINE_NAKED_JMP(NSVrBlock<unsigned long,CNSPc *>::Destructor(), 0x4DF500);
//DEFINE_NAKED_JMP(int NSVrBlock<unsigned long,CNSPc *>::Add(unsigned long _COMMA CNSPc *), 0x4DF570);
//DEFINE_NAKED_JMP(int NSVrBlock<unsigned long,CNSPc *>::Remove(unsigned long), 0x4DF600);
DEFINE_NAKED_JMP(CNSPc * NSVrBlock<unsigned long _COMMA CNSPc *>::Find(unsigned long), 0x4DF6A0);
//DEFINE_NAKED_JMP(unsigned int NSVrBlock<unsigned long,CNSPc *>::GetCount(), 0x4DF480);
#endif


template <>
class NSVrBlock<unsigned long,CNSObject *> {
public:
    static const unsigned int _size = 0x43c;

    class CNSCriticalSection m_cs;//this+0x0
    class std::map<unsigned long,CNSObject *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const ,CNSObject *> > > m_mapObject;//this+0x41C
    NSVrBlock<unsigned long,CNSObject *>(const NSVrBlock<unsigned long,CNSObject *> &);
    NSVrBlock<unsigned long,CNSObject *>();    PATCH_MEMBER(NSVrBlock<unsigned long _COMMA CNSObject *> &, Constructor, , 0x4DF750);
    ~NSVrBlock<unsigned long,CNSObject *>();    PATCH_MEMBER(void, Destructor, , 0x4DF7B0);
    int Add(unsigned long, CNSObject *);    PATCH_MEMBER(int, Add, unsigned long _COMMA CNSObject *, 0x4DF820);
    int Remove(unsigned long);    PATCH_MEMBER(int, Remove, unsigned long, 0x4DF8B0);
    CNSObject * Find(unsigned long);    PATCH_MEMBER(CNSObject *, Find, unsigned long, 0x4DF6A0);
    void Lock();
    void Unlock();
    unsigned int GetCount();    PATCH_MEMBER(unsigned int, GetCount, , 0x4DF480);
    NSVrBlock<unsigned long,CNSObject *> & operator=(const NSVrBlock<unsigned long,CNSObject *> &);
    //void * __vecDelDtor(unsigned int);

/*struct _Invoke {
PATCH_MEMBER_INVOKE(NSVrBlock<unsigned long,CNSObject *> &, NSVrBlock<unsigned long,CNSObject *>, Constructor, );
PATCH_MEMBER_INVOKE(void, NSVrBlock<unsigned long,CNSObject *>, Destructor, );
PATCH_MEMBER_INVOKE(int, NSVrBlock<unsigned long,CNSObject *>, Add, unsigned long _COMMA CNSObject *);
PATCH_MEMBER_INVOKE(int, NSVrBlock<unsigned long,CNSObject *>, Remove, unsigned long);
PATCH_MEMBER_INVOKE(CNSObject *, NSVrBlock<unsigned long,CNSObject *>, Find, unsigned long);
PATCH_MEMBER_INVOKE(unsigned int, NSVrBlock<unsigned long,CNSObject *>, GetCount, );
};*/
};
#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(NSVrBlock<unsigned long,CNSObject *>::Constructor(), 0x4DF750);
//DEFINE_NAKED_JMP(NSVrBlock<unsigned long,CNSObject *>::Destructor(), 0x4DF7B0);
//DEFINE_NAKED_JMP(int NSVrBlock<unsigned long,CNSObject *>::Add(unsigned long _COMMA CNSObject *), 0x4DF820);
//DEFINE_NAKED_JMP(int NSVrBlock<unsigned long,CNSObject *>::Remove(unsigned long), 0x4DF8B0);
DEFINE_NAKED_JMP(CNSObject * NSVrBlock<unsigned long _COMMA CNSObject *>::Find(unsigned long), 0x4DF6A0);
//DEFINE_NAKED_JMP(std::_Tree<std::_Tmap_traits<unsigned long _COMMA CNSObject * _COMMA std::less<unsigned long> _COMMA std::allocator<std::pair<unsigned long const  _COMMA CNSObject *> > _COMMA 0> >::iterator NSVrBlock<unsigned long,CNSObject *>::Begin(), 0x4DF420);
//DEFINE_NAKED_JMP(std::_Tree<std::_Tmap_traits<unsigned long _COMMA CNSObject * _COMMA std::less<unsigned long> _COMMA std::allocator<std::pair<unsigned long const  _COMMA CNSObject *> > _COMMA 0> >::iterator NSVrBlock<unsigned long,CNSObject *>::End(), 0x4DF450);
//DEFINE_NAKED_JMP(unsigned int NSVrBlock<unsigned long,CNSObject *>::GetCount(), 0x4DF480);
#endif


class NSVrBlockPc : public NSVrBlock<unsigned long,CNSPc *> {
public:
    static const unsigned int _size = 0x43c;

    int BroadcastPc(CNSCharacter *, CPacket &, std::_Tree<std::_Tmap_traits<unsigned long,CNSPc *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const ,CNSPc *> >,0> >::iterator &, unsigned short, unsigned short, unsigned short, unsigned short, int);    PATCH_MEMBER(int, BroadcastPc, CNSCharacter * _COMMA CPacket & _COMMA std::_Tree<std::_Tmap_traits<unsigned long _COMMA CNSPc * _COMMA std::less<unsigned long> _COMMA std::allocator<std::pair<unsigned long const  _COMMA CNSPc *> > _COMMA 0> >::iterator & _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA int, 0x4E0190);
    void Broadcast(CNSCharacter *, CPacket &, unsigned short, unsigned short, unsigned short, unsigned short, int);    PATCH_MEMBER(void, Broadcast, CNSCharacter * _COMMA CPacket & _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA int, 0x4E06A0);
    int ObjectInfo(std::vector<CNSObject *,std::allocator<CNSObject *> > &, std::_Tree<std::_Tmap_traits<unsigned long,CNSPc *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const ,CNSPc *> >,0> >::iterator &, unsigned short, unsigned short, unsigned short, unsigned short);    PATCH_MEMBER(int, ObjectInfo, std::vector<CNSObject * _COMMA std::allocator<CNSObject *> > & _COMMA std::_Tree<std::_Tmap_traits<unsigned long _COMMA CNSPc * _COMMA std::less<unsigned long> _COMMA std::allocator<std::pair<unsigned long const  _COMMA CNSPc *> > _COMMA 0> >::iterator & _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short, 0x4E07E0);
    void BlockInfo(std::vector<CNSObject *,std::allocator<CNSObject *> > &, unsigned short, unsigned short, unsigned short, unsigned short);    PATCH_MEMBER(void, BlockInfo, std::vector<CNSObject * _COMMA std::allocator<CNSObject *> > & _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short, 0x4E0940);
    NSVrBlockPc(const NSVrBlockPc &);
    NSVrBlockPc();    PATCH_MEMBER(NSVrBlockPc &, Constructor, , 0x4DF180);
    ~NSVrBlockPc();    PATCH_MEMBER(void, Destructor, , 0x4DF140);
    NSVrBlockPc & operator=(const NSVrBlockPc &);
    //void * __vecDelDtor(unsigned int);

/*struct _Invoke {
PATCH_MEMBER_INVOKE(int, NSVrBlockPc, BroadcastPc, CNSCharacter * _COMMA CPacket & _COMMA std::_Tree<std::_Tmap_traits<unsigned long _COMMA CNSPc * _COMMA std::less<unsigned long> _COMMA std::allocator<std::pair<unsigned long const  _COMMA CNSPc *> > _COMMA 0> >::iterator & _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA int);
PATCH_MEMBER_INVOKE(void, NSVrBlockPc, Broadcast, CNSCharacter * _COMMA CPacket & _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA int);
PATCH_MEMBER_INVOKE(int, NSVrBlockPc, ObjectInfo, std::vector<CNSObject * _COMMA std::allocator<CNSObject *> > & _COMMA std::_Tree<std::_Tmap_traits<unsigned long _COMMA CNSPc * _COMMA std::less<unsigned long> _COMMA std::allocator<std::pair<unsigned long const  _COMMA CNSPc *> > _COMMA 0> >::iterator & _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short);
PATCH_MEMBER_INVOKE(void, NSVrBlockPc, BlockInfo, std::vector<CNSObject * _COMMA std::allocator<CNSObject *> > & _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short);
PATCH_MEMBER_INVOKE(NSVrBlockPc &, NSVrBlockPc, Constructor, );
PATCH_MEMBER_INVOKE(void, NSVrBlockPc, Destructor, );
};*/
};
#ifdef DEFINE_NS_CPP
DEFINE_NAKED_JMP(int NSVrBlockPc::BroadcastPc(CNSCharacter * _COMMA CPacket & _COMMA std::_Tree<std::_Tmap_traits<unsigned long _COMMA CNSPc * _COMMA std::less<unsigned long> _COMMA std::allocator<std::pair<unsigned long const  _COMMA CNSPc *> > _COMMA 0> >::iterator & _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA int), 0x4E0190);
DEFINE_NAKED_JMP(void NSVrBlockPc::Broadcast(CNSCharacter * _COMMA CPacket & _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA int), 0x4E06A0);
//DEFINE_NAKED_JMP(int NSVrBlockPc::ObjectInfo(std::vector<CNSObject * _COMMA std::allocator<CNSObject *> > & _COMMA std::_Tree<std::_Tmap_traits<unsigned long _COMMA CNSPc * _COMMA std::less<unsigned long> _COMMA std::allocator<std::pair<unsigned long const  _COMMA CNSPc *> > _COMMA 0> >::iterator & _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short), 0x4E07E0);
//DEFINE_NAKED_JMP(void NSVrBlockPc::BlockInfo(std::vector<CNSObject * _COMMA std::allocator<CNSObject *> > & _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short), 0x4E0940);
//DEFINE_NAKED_JMP(NSVrBlockPc::Constructor(), 0x4DF180);
//DEFINE_NAKED_JMP(NSVrBlockPc::Destructor(), 0x4DF140);
#endif

class NSVrBlockObject : public NSVrBlock<unsigned long,CNSObject *> {
public:
    static const unsigned int _size = 0x43c;

    int ObjectInfo(CNSObject::OBJECTTYPE, std::vector<CNSObject *,std::allocator<CNSObject *> > &, std::_Tree<std::_Tmap_traits<unsigned long,CNSObject *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const ,CNSObject *> >,0> >::iterator &, unsigned short, unsigned short, unsigned short, unsigned short);    PATCH_MEMBER(int, ObjectInfo, CNSObject::OBJECTTYPE _COMMA std::vector<CNSObject * _COMMA std::allocator<CNSObject *> > & _COMMA std::_Tree<std::_Tmap_traits<unsigned long _COMMA CNSObject * _COMMA std::less<unsigned long> _COMMA std::allocator<std::pair<unsigned long const  _COMMA CNSObject *> > _COMMA 0> >::iterator & _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short, 0x4DF950);
    void BlockInfo(CNSObject::OBJECTTYPE, std::vector<CNSObject *,std::allocator<CNSObject *> > &, unsigned short, unsigned short, unsigned short, unsigned short);    PATCH_MEMBER(void, BlockInfo, CNSObject::OBJECTTYPE _COMMA std::vector<CNSObject * _COMMA std::allocator<CNSObject *> > & _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short, 0x4DFAC0);
    NSVrBlockObject(const NSVrBlockObject &);
    NSVrBlockObject();    PATCH_MEMBER(NSVrBlockObject &, Constructor, , 0x4DF1A0);
    ~NSVrBlockObject();    PATCH_MEMBER(void, Destructor, , 0x4DF160);
    NSVrBlockObject & operator=(const NSVrBlockObject &);
    //void * __vecDelDtor(unsigned int);

/*struct _Invoke {
PATCH_MEMBER_INVOKE(int, NSVrBlockObject, ObjectInfo, CNSObject::OBJECTTYPE _COMMA std::vector<CNSObject * _COMMA std::allocator<CNSObject *> > & _COMMA std::_Tree<std::_Tmap_traits<unsigned long _COMMA CNSObject * _COMMA std::less<unsigned long> _COMMA std::allocator<std::pair<unsigned long const  _COMMA CNSObject *> > _COMMA 0> >::iterator & _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short);
PATCH_MEMBER_INVOKE(void, NSVrBlockObject, BlockInfo, CNSObject::OBJECTTYPE _COMMA std::vector<CNSObject * _COMMA std::allocator<CNSObject *> > & _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short);
PATCH_MEMBER_INVOKE(NSVrBlockObject &, NSVrBlockObject, Constructor, );
PATCH_MEMBER_INVOKE(void, NSVrBlockObject, Destructor, );
};*/

#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(int NSVrBlockObject::ObjectInfo(CNSObject::OBJECTTYPE _COMMA std::vector<CNSObject * _COMMA std::allocator<CNSObject *> > & _COMMA std::_Tree<std::_Tmap_traits<unsigned long _COMMA CNSObject * _COMMA std::less<unsigned long> _COMMA std::allocator<std::pair<unsigned long const  _COMMA CNSObject *> > _COMMA 0> >::iterator & _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short), 0x4DF950);
//DEFINE_NAKED_JMP(void NSVrBlockObject::BlockInfo(CNSObject::OBJECTTYPE _COMMA std::vector<CNSObject * _COMMA std::allocator<CNSObject *> > & _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short), 0x4DFAC0);
//DEFINE_NAKED_JMP(NSVrBlockObject::Constructor(), 0x4DF1A0);
//DEFINE_NAKED_JMP(NSVrBlockObject::Destructor(), 0x4DF160);
#endif
};



class CNSVrBlockManager {
public:
    static const unsigned int _size = 0x438;

    class NSVrBlockPc * * m_ppNSVrBlockPc;//this+0x4
    class NSVrBlockObject * * m_ppNSVrBlockObject;//this+0x8
    class CNSCriticalSection m_cs;//this+0xC
    unsigned long m_nWidth;//this+0x428
    unsigned long m_nHeight;//this+0x42C
    unsigned short m_nBlockSize;//this+0x430
    unsigned short m_nBlockWidth;//this+0x432
    unsigned short m_nBlockHeight;//this+0x434
    unsigned short m_nBlockMaxSight;//this+0x436
    CNSVrBlockManager(const CNSVrBlockManager &);
    CNSVrBlockManager(unsigned long, unsigned long, unsigned short);    PATCH_MEMBER(CNSVrBlockManager &, Constructor, unsigned long _COMMA unsigned long _COMMA unsigned short, 0x4DD150);
    virtual ~CNSVrBlockManager();    PATCH_MEMBER(void, Destructor, , 0x4DD1E0);
    int Init();    PATCH_MEMBER(int, Init, , 0x4DD370);
    int Add(CNSObject *, NSPOINT2 &);    PATCH_MEMBER(int, Add, CNSObject * _COMMA NSPOINT2 &, 0x4DD650);
    int Remove(CNSObject *);    PATCH_MEMBER(int, Remove, CNSObject *, 0x4DD8A0);
    void RemoveAll(CNSObject *);    PATCH_MEMBER(void, RemoveAll, CNSObject *, 0x4DD940);
    int Move(CNSObject *, NSPOINT2 &);    PATCH_MEMBER(int, Move, CNSObject * _COMMA NSPOINT2 &, 0x4DDAA0);
    int IsExist(CNSObject *);    PATCH_MEMBER(int, IsExist, CNSObject *, 0x4DD7E0);
    int GetVrBlockList(NSPOINT2 &, _NSRANGE &, NSVrBlockObject * *);    PATCH_MEMBER(int, GetVrBlockList, NSPOINT2 & _COMMA _NSRANGE & _COMMA NSVrBlockObject * *, 0x4DE0B0);
    int GetVrBlockList(NSPOINT2 &, _NSRANGE &, NSVrBlockPc * *);    PATCH_MEMBER(int, GetVrBlockList, NSPOINT2 & _COMMA _NSRANGE & _COMMA NSVrBlockPc * *, 0x4DDCC0);
    void Broadcast(CNSObject *, CPacket &, int, unsigned short);    PATCH_MEMBER(void, Broadcast, CNSObject * _COMMA CPacket & _COMMA int _COMMA unsigned short, 0x4DE4A0);
    void FieldInfoPc(unsigned short, unsigned short, unsigned short, unsigned short, std::vector<CNSObject *,std::allocator<CNSObject *> > &);    PATCH_MEMBER(void, FieldInfoPc, unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA std::vector<CNSObject * _COMMA std::allocator<CNSObject *> > &, 0x4DE860);
    void FieldInfoPc(CNSObject *, unsigned short, std::vector<CNSObject *,std::allocator<CNSObject *> > &);    PATCH_MEMBER(void, FieldInfoPc, CNSObject * _COMMA unsigned short _COMMA std::vector<CNSObject * _COMMA std::allocator<CNSObject *> > &, 0x4DE710);
    void FieldInfo(unsigned short, unsigned short, unsigned short, unsigned short, std::vector<CNSObject *,std::allocator<CNSObject *> > &);    PATCH_MEMBER(void, FieldInfo, unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA std::vector<CNSObject * _COMMA std::allocator<CNSObject *> > &, 0x4DEAE0);
    void FieldInfo(CNSObject *, unsigned short, CNSObject::OBJECTTYPE, std::vector<CNSObject *,std::allocator<CNSObject *> > &);    PATCH_MEMBER(void, FieldInfo, CNSObject * _COMMA unsigned short _COMMA CNSObject::OBJECTTYPE _COMMA std::vector<CNSObject * _COMMA std::allocator<CNSObject *> > &, 0x4DE990);
    void GetBroadcastRange(NSPOINT2 &, _NSRANGE &, unsigned short);    PATCH_MEMBER(void, GetBroadcastRange, NSPOINT2 & _COMMA _NSRANGE & _COMMA unsigned short, 0x4DF300);
    void CellToBlock(NSPOINT2 &, NSPOINT2 &);    PATCH_MEMBER(void, CellToBlock, NSPOINT2 & _COMMA NSPOINT2 &, 0x4DF1E0);
    int VerifyNSVrBlock(int, int);    PATCH_MEMBER(int, VerifyNSVrBlock, int _COMMA int, 0x4DF2C0);
    int VerifyNSVrBlock(NSPOINT2);    PATCH_MEMBER(int, VerifyNSVrBlock, NSPOINT2, 0x4DF250);
    int VerifyCell(NSPOINT2 &);    PATCH_MEMBER(int, VerifyCell, NSPOINT2 &, 0x44C3F0);
    void Debug_PrintMapStat();    PATCH_MEMBER(void, Debug_PrintMapStat, , 0x4DEC10);
    void Debug_SearchObject(CNSPc *, unsigned long);    PATCH_MEMBER(void, Debug_SearchObject, CNSPc * _COMMA unsigned long, 0x4DEF10);
    static class CNSVrBlockManager ms_VrMapDummy;//[0xBBC9E8]  [007BC9E8:0003:0069C9E8]
    CNSVrBlockManager & operator=(const CNSVrBlockManager &);
    //virtual void * __vecDelDtor(unsigned int);

    /*struct _Invoke {
    PATCH_MEMBER_INVOKE(CNSVrBlockManager &, CNSVrBlockManager, Constructor, unsigned long _COMMA unsigned long _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(void, CNSVrBlockManager, Destructor, );
    PATCH_MEMBER_INVOKE(int, CNSVrBlockManager, Init, );
    PATCH_MEMBER_INVOKE(int, CNSVrBlockManager, Add, CNSObject * _COMMA NSPOINT2 &);
    PATCH_MEMBER_INVOKE(int, CNSVrBlockManager, Remove, CNSObject *);
    PATCH_MEMBER_INVOKE(void, CNSVrBlockManager, RemoveAll, CNSObject *);
    PATCH_MEMBER_INVOKE(int, CNSVrBlockManager, Move, CNSObject * _COMMA NSPOINT2 &);
    PATCH_MEMBER_INVOKE(int, CNSVrBlockManager, IsExist, CNSObject *);
    PATCH_MEMBER_INVOKE(int, CNSVrBlockManager, GetVrBlockList, NSPOINT2 & _COMMA _NSRANGE & _COMMA NSVrBlockObject * *);
    PATCH_MEMBER_INVOKE(int, CNSVrBlockManager, GetVrBlockList, NSPOINT2 & _COMMA _NSRANGE & _COMMA NSVrBlockPc * *);
    PATCH_MEMBER_INVOKE(void, CNSVrBlockManager, Broadcast, CNSObject * _COMMA CPacket & _COMMA int _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(void, CNSVrBlockManager, FieldInfoPc, unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA std::vector<CNSObject * _COMMA std::allocator<CNSObject *> > &);
    PATCH_MEMBER_INVOKE(void, CNSVrBlockManager, FieldInfoPc, CNSObject * _COMMA unsigned short _COMMA std::vector<CNSObject * _COMMA std::allocator<CNSObject *> > &);
    PATCH_MEMBER_INVOKE(void, CNSVrBlockManager, FieldInfo, unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA std::vector<CNSObject * _COMMA std::allocator<CNSObject *> > &);
    PATCH_MEMBER_INVOKE(void, CNSVrBlockManager, FieldInfo, CNSObject * _COMMA unsigned short _COMMA CNSObject::OBJECTTYPE _COMMA std::vector<CNSObject * _COMMA std::allocator<CNSObject *> > &);
    PATCH_MEMBER_INVOKE(void, CNSVrBlockManager, GetBroadcastRange, NSPOINT2 & _COMMA _NSRANGE & _COMMA unsigned short);
    PATCH_MEMBER_INVOKE(void, CNSVrBlockManager, CellToBlock, NSPOINT2 & _COMMA NSPOINT2 &);
    PATCH_MEMBER_INVOKE(int, CNSVrBlockManager, VerifyNSVrBlock, int _COMMA int);
    PATCH_MEMBER_INVOKE(int, CNSVrBlockManager, VerifyNSVrBlock, NSPOINT2);
    PATCH_MEMBER_INVOKE(int, CNSVrBlockManager, VerifyCell, NSPOINT2 &);
    PATCH_MEMBER_INVOKE(void, CNSVrBlockManager, Debug_PrintMapStat, );
    PATCH_MEMBER_INVOKE(void, CNSVrBlockManager, Debug_SearchObject, CNSPc * _COMMA unsigned long);
    };*/
};
#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(CNSVrBlockManager::Constructor(unsigned long _COMMA unsigned long _COMMA unsigned short), 0x4DD150);
//DEFINE_NAKED_JMP(CNSVrBlockManager::Destructor(), 0x4DD1E0);
DEFINE_NAKED_JMP(int CNSVrBlockManager::Init(), 0x4DD370);
DEFINE_NAKED_JMP(int CNSVrBlockManager::Add(CNSObject * _COMMA NSPOINT2 &), 0x4DD650);
DEFINE_NAKED_JMP(int CNSVrBlockManager::Remove(CNSObject *), 0x4DD8A0);
DEFINE_NAKED_JMP(void CNSVrBlockManager::RemoveAll(CNSObject *), 0x4DD940);
DEFINE_NAKED_JMP(int CNSVrBlockManager::Move(CNSObject * _COMMA NSPOINT2 &), 0x4DDAA0);
DEFINE_NAKED_JMP(int CNSVrBlockManager::IsExist(CNSObject *), 0x4DD7E0);
DEFINE_NAKED_JMP(int CNSVrBlockManager::GetVrBlockList(NSPOINT2 & _COMMA _NSRANGE & _COMMA NSVrBlockObject * *), 0x4DE0B0);
DEFINE_NAKED_JMP(int CNSVrBlockManager::GetVrBlockList(NSPOINT2 & _COMMA _NSRANGE & _COMMA NSVrBlockPc * *), 0x4DDCC0);
DEFINE_NAKED_JMP(void CNSVrBlockManager::Broadcast(CNSObject * _COMMA CPacket & _COMMA int _COMMA unsigned short), 0x4DE4A0);
DEFINE_NAKED_JMP(void CNSVrBlockManager::FieldInfoPc(unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA std::vector<CNSObject * _COMMA std::allocator<CNSObject *> > &), 0x4DE860);
DEFINE_NAKED_JMP(void CNSVrBlockManager::FieldInfoPc(CNSObject * _COMMA unsigned short _COMMA std::vector<CNSObject * _COMMA std::allocator<CNSObject *> > &), 0x4DE710);
DEFINE_NAKED_JMP(void CNSVrBlockManager::FieldInfo(unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA unsigned short _COMMA std::vector<CNSObject * _COMMA std::allocator<CNSObject *> > &), 0x4DEAE0);
DEFINE_NAKED_JMP(void CNSVrBlockManager::FieldInfo(CNSObject * _COMMA unsigned short _COMMA CNSObject::OBJECTTYPE _COMMA std::vector<CNSObject * _COMMA std::allocator<CNSObject *> > &), 0x4DE990);
DEFINE_NAKED_JMP(void CNSVrBlockManager::GetBroadcastRange(NSPOINT2 & _COMMA _NSRANGE & _COMMA unsigned short), 0x4DF300);
DEFINE_NAKED_JMP(void CNSVrBlockManager::CellToBlock(NSPOINT2 & _COMMA NSPOINT2 &), 0x4DF1E0);
DEFINE_NAKED_JMP(int CNSVrBlockManager::VerifyNSVrBlock(int _COMMA int), 0x4DF2C0);
DEFINE_NAKED_JMP(int CNSVrBlockManager::VerifyNSVrBlock(NSPOINT2), 0x4DF250);
DEFINE_NAKED_JMP(int CNSVrBlockManager::VerifyCell(NSPOINT2 &), 0x44C3F0);
DEFINE_NAKED_JMP(void CNSVrBlockManager::Debug_PrintMapStat(), 0x4DEC10);
DEFINE_NAKED_JMP(void CNSVrBlockManager::Debug_SearchObject(CNSPc * _COMMA unsigned long), 0x4DEF10);
#endif









#endif