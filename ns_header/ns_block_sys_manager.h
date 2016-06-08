#ifndef NSHEADER_NS_BLOCK_SYS_MANAGER_H_
#define NSHEADER_NS_BLOCK_SYS_MANAGER_H_


class CNSBlockSysManager;

template <>
class CSingleton<CNSBlockSysManager> {
public:
    static const unsigned int _size = 0x1;

    static CNSBlockSysManager * GetInstance();    PATCH_STATIC(CNSBlockSysManager *, GetInstance, , 0x443760);
    static void ReleaseInstance();
    static class CNSBlockSysManager * m_selfInstance;//[0x55C720]  [0015C720:0003:0003C720]

/*struct _Invoke {
PATCH_STATIC_INVOKE(CNSBlockSysManager *, GetInstance, );
};*/
};
#ifdef DEFINE_NS_CPP
DEFINE_NAKED_JMP(CNSBlockSysManager * CSingleton<CNSBlockSysManager>::GetInstance(), 0x443760);
#endif

class CNSBlockSysManager : public CSingleton<CNSBlockSysManager> {
public:
    static const unsigned int _size = 0x964;

    
    CNSBlockSysManager(const CNSBlockSysManager &);
    CNSBlockSysManager();    PATCH_MEMBER(CNSBlockSysManager &, Constructor, , 0x41AC70);
    virtual ~CNSBlockSysManager();    PATCH_MEMBER(void, Destructor, , 0x41ACC0);
    virtual int Init();    PATCH_MEMBER(int, Init, , 0x41ACE0);
    void Add(unsigned long, unsigned char, NSPOINT2 &, unsigned char);    PATCH_MEMBER(void, Add, unsigned long _COMMA unsigned char _COMMA NSPOINT2 & _COMMA unsigned char, 0x41ACF0);
    int Delete(unsigned long);    PATCH_MEMBER(int, Delete, unsigned long, 0x41ADC0);
    int IsExist(unsigned char, unsigned short, unsigned short);    PATCH_MEMBER(int, IsExist, unsigned char _COMMA unsigned short _COMMA unsigned short, 0x41AE10);
    struct _Block {
        static const unsigned int _size = 0xc;

        unsigned long dwObjectId;//this+0x0
        unsigned char btRegion;//this+0x4
        class NSPOINT2 cell;//this+0x6
        unsigned char btSize;//this+0xA
        _Block();    PATCH_MEMBER(CNSBlockSysManager::_Block &, Constructor, , 0x41AF70);

/*struct _Invoke {
PATCH_MEMBER_INVOKE(CNSBlockSysManager::_Block &, CNSBlockSysManager::_Block, Constructor, );
};*/

#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(CNSBlockSysManager::_Block::Constructor(), 0x41AF70);
#endif
    };


    struct CNSBlockSysManager::_Block m_BlockArray[0xC8];//this+0x4
    int FindIndex(unsigned long);    PATCH_MEMBER(int, FindIndex, unsigned long, 0x41AEF0);
    CNSBlockSysManager & operator=(const CNSBlockSysManager &);
    //void __local_vftable_ctor_closure();
    //virtual void * __vecDelDtor(unsigned int);

/*struct _Invoke {
PATCH_MEMBER_INVOKE(CNSBlockSysManager &, CNSBlockSysManager, Constructor, );
PATCH_MEMBER_INVOKE(void, CNSBlockSysManager, Destructor, );
PATCH_MEMBER_INVOKE(int, CNSBlockSysManager, Init, );
PATCH_MEMBER_INVOKE(void, CNSBlockSysManager, Add, unsigned long _COMMA unsigned char _COMMA NSPOINT2 & _COMMA unsigned char);
PATCH_MEMBER_INVOKE(int, CNSBlockSysManager, Delete, unsigned long);
PATCH_MEMBER_INVOKE(int, CNSBlockSysManager, IsExist, unsigned char _COMMA unsigned short _COMMA unsigned short);
PATCH_MEMBER_INVOKE(int, CNSBlockSysManager, FindIndex, unsigned long);
};*/
};
#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(CNSBlockSysManager::Constructor(), 0x41AC70);
//DEFINE_NAKED_JMP(CNSBlockSysManager::Destructor(), 0x41ACC0);
//DEFINE_NAKED_JMP(int CNSBlockSysManager::Init(), 0x41ACE0);
DEFINE_NAKED_JMP(void CNSBlockSysManager::Add(unsigned long _COMMA unsigned char _COMMA NSPOINT2 & _COMMA unsigned char), 0x41ACF0);
DEFINE_NAKED_JMP(int CNSBlockSysManager::Delete(unsigned long), 0x41ADC0);
DEFINE_NAKED_JMP(int CNSBlockSysManager::IsExist(unsigned char _COMMA unsigned short _COMMA unsigned short), 0x41AE10);
DEFINE_NAKED_JMP(int CNSBlockSysManager::FindIndex(unsigned long), 0x41AEF0);
#endif


#endif