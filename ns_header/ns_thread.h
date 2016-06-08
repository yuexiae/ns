#ifndef NSHEADER_NS_THREAD_H_
#define NSHEADER_NS_THREAD_H_



class CThread {
public:
	static const unsigned int _size = 0x10;

	CThread(const CThread &);
	CThread();    PATCH_MEMBER(CThread &, Constructor, , 0x414A50);
	virtual ~CThread();    PATCH_MEMBER(void, Destructor, , 0x414A80);
	void Start();    PATCH_MEMBER(void, Start, , 0x414AA0);
	virtual void Action();
	int SetPriority(int);    PATCH_MEMBER(int, SetPriority, int, 0x414AF0);
	void * m_hThread;//this+0x4
	int m_bStarted;//this+0x8
	unsigned long m_dwThread;//this+0xC
	static unsigned long HandleActor(void *);    PATCH_STATIC(unsigned long, HandleActor, void *, 0x414B20);
	CThread & operator=(const CThread &);
	//void __local_vftable_ctor_closure();
	//virtual void * __vecDelDtor(unsigned int);

	/*struct _Invoke {
	PATCH_MEMBER_INVOKE(CThread &, CThread, Constructor, );
	PATCH_MEMBER_INVOKE(void, CThread, Destructor, );
	PATCH_MEMBER_INVOKE(void, CThread, Start, );
	PATCH_MEMBER_INVOKE(int, CThread, SetPriority, int);
	PATCH_STATIC_INVOKE(unsigned long, HandleActor, void *);
	};*/
};
#ifdef DEFINE_NS_CPP
//DEFINE_NAKED_JMP(CThread::Constructor(), 0x414A50);
//DEFINE_NAKED_JMP(CThread::Destructor(), 0x414A80);
DEFINE_NAKED_JMP(void CThread::Start(), 0x414AA0);
DEFINE_NAKED_JMP(int CThread::SetPriority(int), 0x414AF0);
DEFINE_NAKED_JMP(unsigned long CThread::HandleActor(void *), 0x414B20);
#endif



#endif