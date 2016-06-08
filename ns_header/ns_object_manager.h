#ifndef NSHADER_NS_OBJECT_MANAGER_H_
#define NSHADER_NS_OBJECT_MANAGER_H_

class CNSObjectManagerExt;

class CNSObjectManager {
public:
    static const unsigned int _size = 0x4bc;
    
    static CNSObjectManagerExt * GetInstance();    PATCH_STATIC(CNSObjectManager *, GetInstance, , 0x45B1E0);
    static void ReleaseInstance();    PATCH_STATIC(void, ReleaseInstance, , 0x45B270);
    unsigned long Add(CNSObject::OBJECTTYPE, unsigned long, CNSObject *);    PATCH_MEMBER(unsigned long, Add, CNSObject::OBJECTTYPE _COMMA unsigned long _COMMA CNSObject *, 0x45B370);
    unsigned long Add(CNSObject::OBJECTTYPE, CNSObject *);    PATCH_MEMBER(unsigned long, Add, CNSObject::OBJECTTYPE _COMMA CNSObject *, 0x45B2C0);
    void Delete(unsigned long);    PATCH_MEMBER(void, Delete, unsigned long, 0x45B430);
    void * Find(unsigned long);    PATCH_MEMBER(void *, Find, unsigned long, 0x45B4C0);
    CNSObject * _GetObjectA(CNSObject::OBJECTTYPE, unsigned long);    PATCH_MEMBER(CNSObject *, GetObjectA, CNSObject::OBJECTTYPE _COMMA unsigned long, 0x427550);
    CNSObject * _GetObjectA(unsigned long);    PATCH_MEMBER(CNSObject *, GetObjectA, unsigned long, 0x45B580);
    unsigned long FillObjectId(CNSObject::OBJECTTYPE, unsigned long *, unsigned long);    PATCH_MEMBER(unsigned long, FillObjectId, CNSObject::OBJECTTYPE _COMMA unsigned long * _COMMA unsigned long, 0x45B650);
    void GetObjectCount(unsigned long &, unsigned long &, unsigned long &, unsigned long &, unsigned long &, unsigned long &, unsigned long &);    PATCH_MEMBER(void, GetObjectCount, unsigned long & _COMMA unsigned long & _COMMA unsigned long & _COMMA unsigned long & _COMMA unsigned long & _COMMA unsigned long & _COMMA unsigned long &, 0x45BA10);
    void DebugPrint();    PATCH_MEMBER(void, DebugPrint, , 0x45BBF0);
    void DebugGuildList(CNSPc *);    PATCH_MEMBER(void, DebugGuildList, CNSPc *, 0x45C2C0);
    void AddFreeItem(void *);    PATCH_MEMBER(void, AddFreeItem, void *, 0x41A0D0);
    void * GetFreeItem();    PATCH_MEMBER(void *, GetFreeItem, , 0x41A000);
    unsigned long GetFreeItemCount();    PATCH_MEMBER(unsigned long, GetFreeItemCount, , 0x402230);
    static class CNSObjectManager * m_selfInstance;//[0x55CC74]  [0015CC74:0003:0003CC74]
    CNSObjectManager(const CNSObjectManager &);
    CNSObjectManager();    PATCH_MEMBER(CNSObjectManager &, Constructor, , 0x45B060);
    virtual ~CNSObjectManager();    PATCH_MEMBER(void, Destructor, , 0x45B110);
    class std::map<unsigned long,CNSObject *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const ,CNSObject *> > > m_mapObject;//this+0x4
    class std::map<unsigned long,unsigned long,std::less<unsigned long>,std::allocator<std::pair<unsigned long const ,unsigned long> > > m_mapMaxIndex;//this+0x24
    class std::map<unsigned long,unsigned long,std::less<unsigned long>,std::allocator<std::pair<unsigned long const ,unsigned long> > > m_mapFreeIndex;//this+0x44
    class CNSCriticalSection m_cs;//this+0x64
    //Typedef        : class std::deque<void *,std::allocator<void *> >
    class std::deque<void *,std::allocator<void *> > m_dequeFreeItem;//this+0x480
    class SteamEngine::Win32::System::CCriticalSection m_csDequeFreeItem;//this+0x4A0
    unsigned long FindEmptyId(CNSObject::OBJECTTYPE);    PATCH_MEMBER(unsigned long, FindEmptyId, CNSObject::OBJECTTYPE, 0x45B790);
    unsigned long FindEmptyIndex(CNSObject::OBJECTTYPE, unsigned long);    PATCH_MEMBER(unsigned long, FindEmptyIndex, CNSObject::OBJECTTYPE _COMMA unsigned long, 0x45B8C0);
    CNSObjectManager & operator=(const CNSObjectManager &);
    //void __local_vftable_ctor_closure();
    //virtual void * __vecDelDtor(unsigned int);

/*struct _Invoke {
PATCH_STATIC_INVOKE(CNSObjectManager *, GetInstance, );
PATCH_STATIC_INVOKE(void, ReleaseInstance, );
PATCH_MEMBER_INVOKE(unsigned long, CNSObjectManager, Add, CNSObject::OBJECTTYPE _COMMA unsigned long _COMMA CNSObject *);
PATCH_MEMBER_INVOKE(unsigned long, CNSObjectManager, Add, CNSObject::OBJECTTYPE _COMMA CNSObject *);
PATCH_MEMBER_INVOKE(void, CNSObjectManager, Delete, unsigned long);
PATCH_MEMBER_INVOKE(void *, CNSObjectManager, Find, unsigned long);
PATCH_MEMBER_INVOKE(CNSObject *, CNSObjectManager, GetObjectA, CNSObject::OBJECTTYPE _COMMA unsigned long);
PATCH_MEMBER_INVOKE(CNSObject *, CNSObjectManager, GetObjectA, unsigned long);
PATCH_MEMBER_INVOKE(unsigned long, CNSObjectManager, FillObjectId, CNSObject::OBJECTTYPE _COMMA unsigned long * _COMMA unsigned long);
PATCH_MEMBER_INVOKE(void, CNSObjectManager, GetObjectCount, unsigned long & _COMMA unsigned long & _COMMA unsigned long & _COMMA unsigned long & _COMMA unsigned long & _COMMA unsigned long & _COMMA unsigned long &);
PATCH_MEMBER_INVOKE(void, CNSObjectManager, DebugPrint, );
PATCH_MEMBER_INVOKE(void, CNSObjectManager, DebugGuildList, CNSPc *);
PATCH_MEMBER_INVOKE(void, CNSObjectManager, AddFreeItem, void *);
PATCH_MEMBER_INVOKE(void *, CNSObjectManager, GetFreeItem, );
PATCH_MEMBER_INVOKE(unsigned long, CNSObjectManager, GetFreeItemCount, );
PATCH_MEMBER_INVOKE(CNSObjectManager &, CNSObjectManager, Constructor, );
PATCH_MEMBER_INVOKE(void, CNSObjectManager, Destructor, );
PATCH_MEMBER_INVOKE(unsigned long, CNSObjectManager, FindEmptyId, CNSObject::OBJECTTYPE);
PATCH_MEMBER_INVOKE(unsigned long, CNSObjectManager, FindEmptyIndex, CNSObject::OBJECTTYPE _COMMA unsigned long);
};*/
};
#ifdef DEFINE_NS_CPP
DEFINE_NAKED_JMP(CNSObjectManagerExt * CNSObjectManager::GetInstance(), 0x45B1E0);
//DEFINE_NAKED_JMP(void CNSObjectManager::ReleaseInstance(), 0x45B270);
//DEFINE_NAKED_JMP(unsigned long CNSObjectManager::Add(CNSObject::OBJECTTYPE _COMMA unsigned long _COMMA CNSObject *), 0x45B370);
//DEFINE_NAKED_JMP(unsigned long CNSObjectManager::Add(CNSObject::OBJECTTYPE _COMMA CNSObject *), 0x45B2C0);
//DEFINE_NAKED_JMP(void CNSObjectManager::Delete(unsigned long), 0x45B430);
//DEFINE_NAKED_JMP(void * CNSObjectManager::Find(unsigned long), 0x45B4C0);
DEFINE_NAKED_JMP(CNSObject * CNSObjectManager::_GetObjectA(CNSObject::OBJECTTYPE _COMMA unsigned long), 0x427550);
DEFINE_NAKED_JMP(CNSObject * CNSObjectManager::_GetObjectA(unsigned long), 0x45B580);
//DEFINE_NAKED_JMP(unsigned long CNSObjectManager::FillObjectId(CNSObject::OBJECTTYPE _COMMA unsigned long * _COMMA unsigned long), 0x45B650);
//DEFINE_NAKED_JMP(void CNSObjectManager::GetObjectCount(unsigned long & _COMMA unsigned long & _COMMA unsigned long & _COMMA unsigned long & _COMMA unsigned long & _COMMA unsigned long & _COMMA unsigned long &), 0x45BA10);
//DEFINE_NAKED_JMP(void CNSObjectManager::DebugPrint(), 0x45BBF0);
//DEFINE_NAKED_JMP(void CNSObjectManager::DebugGuildList(CNSPc *), 0x45C2C0);
//DEFINE_NAKED_JMP(void CNSObjectManager::AddFreeItem(void *), 0x41A0D0);
//DEFINE_NAKED_JMP(void * CNSObjectManager::GetFreeItem(), 0x41A000);
//DEFINE_NAKED_JMP(unsigned long CNSObjectManager::GetFreeItemCount(), 0x402230);
//DEFINE_NAKED_JMP(CNSObjectManager::Constructor(), 0x45B060);
//DEFINE_NAKED_JMP(CNSObjectManager::Destructor(), 0x45B110);
//DEFINE_NAKED_JMP(unsigned long CNSObjectManager::FindEmptyId(CNSObject::OBJECTTYPE), 0x45B790);
//DEFINE_NAKED_JMP(unsigned long CNSObjectManager::FindEmptyIndex(CNSObject::OBJECTTYPE _COMMA unsigned long), 0x45B8C0);
#endif




#endif