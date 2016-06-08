#ifndef NSHEADER_NS_DB_LOG_MANAGER_H_
#define NSHEADER_NS_DB_LOG_MANAGER_H_

#include "ns_header/ns_thread.h"
#include "ns_header/ns_ch_socket.h"
#include "ns_header/ns_odbc.h"
#include <queue>
#include <sqltypes.h>


class CNSSessionPc;
class CNSDbLogManager;

template <>
class CSingleton<CNSDbLogManager> {
public:
	static const unsigned int _size = 0x1;

	static CNSDbLogManager * GetInstance();    PATCH_STATIC(CNSDbLogManager *, GetInstance, , 0x403860);
	static void ReleaseInstance();
	static class CNSDbLogManager * m_selfInstance;//[0x559E28]  [00159E28:0003:00039E28]

	/*struct _Invoke {
	PATCH_STATIC_INVOKE(CNSDbLogManager *, GetInstance, );
	};*/
};
#ifdef DEFINE_NS_CPP
DEFINE_NAKED_JMP(CNSDbLogManager * CSingleton<CNSDbLogManager>::GetInstance(), 0x403860);
#endif

class CNSDbLogManager : public CThread, public CSingleton<CNSDbLogManager>  {
public:
	static const unsigned int _size = 0x85c;

	CNSDbLogManager(const CNSDbLogManager &);
	CNSDbLogManager();    PATCH_MEMBER(CNSDbLogManager &, Constructor, , 0x42BA30);
	virtual ~CNSDbLogManager();    PATCH_MEMBER(void, Destructor, , 0x42BB70);
	virtual void Action();    PATCH_MEMBER(void, Action, , 0x42C480);
	int Init();    PATCH_MEMBER(int, Init, , 0x42BC20);
	void Stop();    PATCH_MEMBER(void, Stop, , 0x42BD60);
	SteamEngine::Win32::DB::COdbc * GetDb();    PATCH_MEMBER(COdbc *, GetDb, , 0x406500);
	void ConfigDb(char *, char *, char *, char *);    PATCH_MEMBER(void, ConfigDb, char * _COMMA char * _COMMA char * _COMMA char *, 0x42BD80);
	int GetDbCheck();    PATCH_MEMBER(int, GetDbCheck, , 0x4C94B0);
	void AddItemLog(char, char *, int, unsigned short, unsigned char, int, unsigned char, NSPOINT2 &, unsigned long);    PATCH_MEMBER(void, AddItemLog, char _COMMA char * _COMMA int _COMMA unsigned short _COMMA unsigned char _COMMA int _COMMA unsigned char _COMMA NSPOINT2 & _COMMA unsigned long, 0x42BE00);
	int m_bThreadLoop;//this+0x10
	class COdbc * m_pDb;//this+0x14
	struct _ItemLog {
		static const unsigned int _size = 0x24;

		char cMode;//this+0x0
		char szAction[0x5];//this+0x1
		int nItemSeq;//this+0x8
		int wItemId;//this+0xC
		unsigned char btCount;//this+0x10
		int nAliasSeq;//this+0x14
		unsigned char btRegion;//this+0x18
		class NSPOINT2 cell;//this+0x1A
		unsigned long dwOptionValue;//this+0x20
		_ItemLog();    PATCH_MEMBER(CNSDbLogManager::_ItemLog &, Constructor, , 0x42C560);

		/*struct _Invoke {
		PATCH_MEMBER_INVOKE(CNSDbLogManager::_ItemLog &, CNSDbLogManager::_ItemLog, Constructor, );
		};*/

#ifdef DEFINE_NS_CPP
		//DEFINE_NAKED_JMP(CNSDbLogManager::_ItemLog::Constructor(), 0x42C560);
#endif
	};


	//Typedef        : class std::queue<CNSDbLogManager::_ItemLog *,std::deque<CNSDbLogManager::_ItemLog *,std::allocator<CNSDbLogManager::_ItemLog *> > >
	class std::queue<CNSDbLogManager::_ItemLog *,std::deque<CNSDbLogManager::_ItemLog *,std::allocator<CNSDbLogManager::_ItemLog *> > > m_queueItemLog;//this+0x18
	class CNSCriticalSection m_csqueueItemLog;//this+0x38
	int m_bDbCheck;//this+0x454
	unsigned long m_dwLastCheckTime;//this+0x458
	char m_szServerName[0x100];//this+0x45C
	char m_szDbName[0x100];//this+0x55C
	char m_szUserId[0x100];//this+0x65C
	char m_szPassword[0x100];//this+0x75C
	int DbCheck();    PATCH_MEMBER(int, DbCheck, , 0x42C3A0);
	int ProcessDbItemLog();    PATCH_MEMBER(int, ProcessDbItemLog, , 0x42BF10);
	CNSDbLogManager & operator=(const CNSDbLogManager &);
	//void __local_vftable_ctor_closure();
	//virtual void * __vecDelDtor(unsigned int);

	/*struct _Invoke {
	PATCH_MEMBER_INVOKE(CNSDbLogManager &, CNSDbLogManager, Constructor, );
	PATCH_MEMBER_INVOKE(void, CNSDbLogManager, Destructor, );
	PATCH_MEMBER_INVOKE(void, CNSDbLogManager, Action, );
	PATCH_MEMBER_INVOKE(int, CNSDbLogManager, Init, );
	PATCH_MEMBER_INVOKE(void, CNSDbLogManager, Stop, );
	PATCH_MEMBER_INVOKE(COdbc *, CNSDbLogManager, GetDb, );
	PATCH_MEMBER_INVOKE(void, CNSDbLogManager, ConfigDb, char * _COMMA char * _COMMA char * _COMMA char *);
	PATCH_MEMBER_INVOKE(int, CNSDbLogManager, GetDbCheck, );
	PATCH_MEMBER_INVOKE(void, CNSDbLogManager, AddItemLog, char _COMMA char * _COMMA int _COMMA unsigned short _COMMA unsigned char _COMMA int _COMMA unsigned char _COMMA NSPOINT2 & _COMMA unsigned long);
	PATCH_MEMBER_INVOKE(int, CNSDbLogManager, DbCheck, );
	PATCH_MEMBER_INVOKE(int, CNSDbLogManager, ProcessDbItemLog, );
	};*/
};
#ifdef DEFINE_NS_CPP
	//DEFINE_NAKED_JMP(CNSDbLogManager::Constructor(), 0x42BA30);
	//DEFINE_NAKED_JMP(CNSDbLogManager::Destructor(), 0x42BB70);
	//DEFINE_NAKED_JMP(void CNSDbLogManager::Action(), 0x42C480);
	//DEFINE_NAKED_JMP(int CNSDbLogManager::Init(), 0x42BC20);
	//DEFINE_NAKED_JMP(void CNSDbLogManager::Stop(), 0x42BD60);
	DEFINE_NAKED_JMP(SteamEngine::Win32::DB::COdbc * CNSDbLogManager::GetDb(), 0x406500);
	//DEFINE_NAKED_JMP(void CNSDbLogManager::ConfigDb(char * _COMMA char * _COMMA char * _COMMA char *), 0x42BD80);
	//DEFINE_NAKED_JMP(int CNSDbLogManager::GetDbCheck(), 0x4C94B0);
	//DEFINE_NAKED_JMP(void CNSDbLogManager::AddItemLog(char _COMMA char * _COMMA int _COMMA unsigned short _COMMA unsigned char _COMMA int _COMMA unsigned char _COMMA NSPOINT2 & _COMMA unsigned long), 0x42BE00);
	//DEFINE_NAKED_JMP(int CNSDbLogManager::DbCheck(), 0x42C3A0);
	//DEFINE_NAKED_JMP(int CNSDbLogManager::ProcessDbItemLog(), 0x42BF10);
#endif

#endif