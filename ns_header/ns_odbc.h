#ifndef NSHEADER_NS_ODBC_H_
#define NSHEADER_NS_ODBC_H_

#include "ns_header/ns_critical_section.h"

namespace SteamEngine { namespace Win32 { namespace DB {
class COdbc {
public:
	static const unsigned int _size = 0x2c;

	COdbc(const COdbc &);
	COdbc();    PATCH_MEMBER(COdbc &, Constructor, , 0x40E680);
	virtual ~COdbc();    PATCH_MEMBER(void, Destructor, , 0x40E6C0);
	void Open(char *, char *, char *, int);    PATCH_MEMBER(void, Open, char * _COMMA char * _COMMA char * _COMMA int, 0x40E720);
	void OpenDirect(char *, char *, char *, char *, int);    PATCH_MEMBER(void, OpenDirect, char * _COMMA char * _COMMA char * _COMMA char * _COMMA int, 0x40E8B0);
	void AutoCommit(int);    PATCH_MEMBER(void, AutoCommit, int, 0x40EAC0);
	void Close();    PATCH_MEMBER(void, Close, , 0x40EB50);
	void SQLExecute(char *);    PATCH_MEMBER(void, SQLExecute, char *, 0x40EBA0);
	void SQLExecute2(void *, char *);    PATCH_MEMBER(void, SQLExecute2, void * _COMMA char *, 0x40ED30);
	void SQLExecuteReturnId(char *, char *, int &);    PATCH_MEMBER(void, SQLExecuteReturnId, char * _COMMA char * _COMMA int &, 0x40EFD0);
	long SQLExecuteReturnRowCount(char *);    PATCH_MEMBER(long, SQLExecuteReturnRowCount, char *, 0x40EE10);
	int SQLExecuteSP(char *);    PATCH_MEMBER(int, SQLExecuteSP, char *, 0x40F270);
	int SQLExecuteSP2(char *);
	static void SQLLogErrorMessage(short, void *);    PATCH_STATIC(void, SQLLogErrorMessage, short _COMMA void *, 0x40F470);
	void SQLCommit();    PATCH_MEMBER(void, SQLCommit, , 0x4064A0);
	void SQLRollback();    PATCH_MEMBER(void, SQLRollback, , 0x450430);
	void SQLCloseCursor(void *);
	void SQLFreeHandleEnv();    PATCH_MEMBER(void, SQLFreeHandleEnv, , 0x40F640);
	void SQLFreeHandleDbc();    PATCH_MEMBER(void, SQLFreeHandleDbc, , 0x40F670);
	void SQLAllocHandleStmt(void * *);    PATCH_MEMBER(void, SQLAllocHandleStmt, void * *, 0x406350);
	void SQLFreeHandleStmt(void *);    PATCH_MEMBER(void, SQLFreeHandleStmt, void *, 0x406470);
	void Lock();    PATCH_MEMBER(void, Lock, , 0x410670);
	void Unlock();    PATCH_MEMBER(void, Unlock, , 0x4106C0);
	class SteamEngine::Win32::System::CCriticalSection m_cs;//this+0x4
	int m_bConnected;//this+0x20
	void * m_hEnv;//this+0x24
	void * m_hDbc;//this+0x28
	COdbc & operator=(const COdbc &);
	//void __local_vftable_ctor_closure();
	//virtual void * __vecDelDtor(unsigned int);

	/*struct _Invoke {
	PATCH_MEMBER_INVOKE(COdbc &, COdbc, Constructor, );
	PATCH_MEMBER_INVOKE(void, COdbc, Destructor, );
	PATCH_MEMBER_INVOKE(void, COdbc, Open, char * _COMMA char * _COMMA char * _COMMA int);
	PATCH_MEMBER_INVOKE(void, COdbc, OpenDirect, char * _COMMA char * _COMMA char * _COMMA char * _COMMA int);
	PATCH_MEMBER_INVOKE(void, COdbc, AutoCommit, int);
	PATCH_MEMBER_INVOKE(void, COdbc, Close, );
	PATCH_MEMBER_INVOKE(void, COdbc, SQLExecute, char *);
	PATCH_MEMBER_INVOKE(void, COdbc, SQLExecute2, void * _COMMA char *);
	PATCH_MEMBER_INVOKE(void, COdbc, SQLExecuteReturnId, char * _COMMA char * _COMMA int &);
	PATCH_MEMBER_INVOKE(long, COdbc, SQLExecuteReturnRowCount, char *);
	PATCH_MEMBER_INVOKE(int, COdbc, SQLExecuteSP, char *);
	PATCH_STATIC_INVOKE(void, SQLLogErrorMessage, short _COMMA void *);
	PATCH_MEMBER_INVOKE(void, COdbc, SQLCommit, );
	PATCH_MEMBER_INVOKE(void, COdbc, SQLRollback, );
	PATCH_MEMBER_INVOKE(void, COdbc, SQLFreeHandleEnv, );
	PATCH_MEMBER_INVOKE(void, COdbc, SQLFreeHandleDbc, );
	PATCH_MEMBER_INVOKE(void, COdbc, SQLAllocHandleStmt, void * *);
	PATCH_MEMBER_INVOKE(void, COdbc, SQLFreeHandleStmt, void *);
	PATCH_MEMBER_INVOKE(void, COdbc, Lock, );
	PATCH_MEMBER_INVOKE(void, COdbc, Unlock, );
	};*/
};
#ifdef DEFINE_NS_CPP
	//DEFINE_NAKED_JMP(COdbc::Constructor(), 0x40E680);
	//DEFINE_NAKED_JMP(COdbc::Destructor(), 0x40E6C0);
	//DEFINE_NAKED_JMP(void COdbc::Open(char * _COMMA char * _COMMA char * _COMMA int), 0x40E720);
	//DEFINE_NAKED_JMP(void COdbc::OpenDirect(char * _COMMA char * _COMMA char * _COMMA char * _COMMA int), 0x40E8B0);
	//DEFINE_NAKED_JMP(void COdbc::AutoCommit(int), 0x40EAC0);
	DEFINE_NAKED_JMP(void COdbc::Close(), 0x40EB50);
	//DEFINE_NAKED_JMP(void COdbc::SQLExecute(char *), 0x40EBA0);
	//DEFINE_NAKED_JMP(void COdbc::SQLExecute2(void * _COMMA char *), 0x40ED30);
	//DEFINE_NAKED_JMP(void COdbc::SQLExecuteReturnId(char * _COMMA char * _COMMA int &), 0x40EFD0);
	//DEFINE_NAKED_JMP(long COdbc::SQLExecuteReturnRowCount(char *), 0x40EE10);
	//DEFINE_NAKED_JMP(int COdbc::SQLExecuteSP(char *), 0x40F270);
	//DEFINE_NAKED_JMP(void COdbc::SQLLogErrorMessage(short _COMMA void *), 0x40F470);
	//DEFINE_NAKED_JMP(void COdbc::SQLCommit(), 0x4064A0);
	//DEFINE_NAKED_JMP(void COdbc::SQLRollback(), 0x450430);
	//DEFINE_NAKED_JMP(void COdbc::SQLFreeHandleEnv(), 0x40F640);
	//DEFINE_NAKED_JMP(void COdbc::SQLFreeHandleDbc(), 0x40F670);
	//DEFINE_NAKED_JMP(void COdbc::SQLAllocHandleStmt(void * *), 0x406350);
	//DEFINE_NAKED_JMP(void COdbc::SQLFreeHandleStmt(void *), 0x406470);
	//DEFINE_NAKED_JMP(void COdbc::Lock(), 0x410670);
	//DEFINE_NAKED_JMP(void COdbc::Unlock(), 0x4106C0);
#endif


class COdbcBindColumn {
public:
    static const unsigned int _size = 0x418;
    
    COdbcBindColumn(const SteamEngine::Win32::DB::COdbcBindColumn &);
	COdbcBindColumn(SteamEngine::Win32::DB::COdbc *pOdbc) { Constructor(pOdbc); } COdbcBindColumn& Constructor(COdbc *);    PATCH_MEMBER(SteamEngine::Win32::DB::COdbcBindColumn &, Constructor, SteamEngine::Win32::DB::COdbc *, 0x40F6A0);
    virtual ~COdbcBindColumn() { Destructor(); } void Destructor();   PATCH_MEMBER(void, Destructor, , 0x40F7E0);
    void * GetHandle();
    void BindTinyInt(void *, long *);    PATCH_MEMBER(void, BindTinyInt, void * _COMMA long *, 0x40F860);
    void BindUSmallInt(void *, long *);    PATCH_MEMBER(void, BindUSmallInt, void * _COMMA long *, 0x40F8F0);
    void BindSmallInt(void *, long *);    PATCH_MEMBER(void, BindSmallInt, void * _COMMA long *, 0x40F980);
    void BindWORD(void *, long *);    PATCH_MEMBER(void, BindWORD, void * _COMMA long *, 0x40FA10);
    void BindInt(void *, long *);    PATCH_MEMBER(void, BindInt, void * _COMMA long *, 0x40FAA0);
    void BindDateTime(void *, long *);    PATCH_MEMBER(void, BindDateTime, void * _COMMA long *, 0x40FB30);
    void BindString(void *, long, long *);    PATCH_MEMBER(void, BindString, void * _COMMA long _COMMA long *, 0x40FBC0);
    void BindBinary(void *, long, long *);    PATCH_MEMBER(void, BindBinary, void * _COMMA long _COMMA long *, 0x40FC50);
    void Execute(char *);    PATCH_MEMBER(void, Execute, char *, 0x40FCE0);
    int Fetch();    PATCH_MEMBER(int, Fetch, , 0x40FD60);
    class SteamEngine::Win32::DB::COdbc * m_pOdbc;//this+0x4
    void * m_hStmt;//this+0x8
    int m_nBindCount;//this+0xC
    unsigned long m_dwTime;//this+0x10
    unsigned long m_dwCount;//this+0x14
    char m_szSqlStatement[0x400];//this+0x18
    SteamEngine::Win32::DB::COdbcBindColumn & operator=(const SteamEngine::Win32::DB::COdbcBindColumn &);
    //virtual void * __vecDelDtor(unsigned int);

/*struct _Invoke {
PATCH_MEMBER_INVOKE(SteamEngine::Win32::DB::COdbcBindColumn &, SteamEngine::Win32::DB::COdbcBindColumn, Constructor, SteamEngine::Win32::DB::COdbc *);
PATCH_MEMBER_INVOKE(void, SteamEngine::Win32::DB::COdbcBindColumn, Destructor, );
PATCH_MEMBER_INVOKE(void, SteamEngine::Win32::DB::COdbcBindColumn, BindTinyInt, void * _COMMA long *);
PATCH_MEMBER_INVOKE(void, SteamEngine::Win32::DB::COdbcBindColumn, BindUSmallInt, void * _COMMA long *);
PATCH_MEMBER_INVOKE(void, SteamEngine::Win32::DB::COdbcBindColumn, BindSmallInt, void * _COMMA long *);
PATCH_MEMBER_INVOKE(void, SteamEngine::Win32::DB::COdbcBindColumn, BindWORD, void * _COMMA long *);
PATCH_MEMBER_INVOKE(void, SteamEngine::Win32::DB::COdbcBindColumn, BindInt, void * _COMMA long *);
PATCH_MEMBER_INVOKE(void, SteamEngine::Win32::DB::COdbcBindColumn, BindDateTime, void * _COMMA long *);
PATCH_MEMBER_INVOKE(void, SteamEngine::Win32::DB::COdbcBindColumn, BindString, void * _COMMA long _COMMA long *);
PATCH_MEMBER_INVOKE(void, SteamEngine::Win32::DB::COdbcBindColumn, BindBinary, void * _COMMA long _COMMA long *);
PATCH_MEMBER_INVOKE(void, SteamEngine::Win32::DB::COdbcBindColumn, Execute, char *);
PATCH_MEMBER_INVOKE(int, SteamEngine::Win32::DB::COdbcBindColumn, Fetch, );
};*/
};
#ifdef DEFINE_NS_CPP
DEFINE_NAKED_JMP(COdbcBindColumn& SteamEngine::Win32::DB::COdbcBindColumn::Constructor(SteamEngine::Win32::DB::COdbc *), 0x40F6A0);
DEFINE_NAKED_JMP(void SteamEngine::Win32::DB::COdbcBindColumn::Destructor(), 0x40F7E0);
DEFINE_NAKED_JMP(void SteamEngine::Win32::DB::COdbcBindColumn::BindTinyInt(void * _COMMA long *), 0x40F860);
DEFINE_NAKED_JMP(void SteamEngine::Win32::DB::COdbcBindColumn::BindUSmallInt(void * _COMMA long *), 0x40F8F0);
DEFINE_NAKED_JMP(void SteamEngine::Win32::DB::COdbcBindColumn::BindSmallInt(void * _COMMA long *), 0x40F980);
DEFINE_NAKED_JMP(void SteamEngine::Win32::DB::COdbcBindColumn::BindWORD(void * _COMMA long *), 0x40FA10);
DEFINE_NAKED_JMP(void SteamEngine::Win32::DB::COdbcBindColumn::BindInt(void * _COMMA long *), 0x40FAA0);
DEFINE_NAKED_JMP(void SteamEngine::Win32::DB::COdbcBindColumn::BindDateTime(void * _COMMA long *), 0x40FB30);
DEFINE_NAKED_JMP(void SteamEngine::Win32::DB::COdbcBindColumn::BindString(void * _COMMA long _COMMA long *), 0x40FBC0);
DEFINE_NAKED_JMP(void SteamEngine::Win32::DB::COdbcBindColumn::BindBinary(void * _COMMA long _COMMA long *), 0x40FC50);
DEFINE_NAKED_JMP(void SteamEngine::Win32::DB::COdbcBindColumn::Execute(char *), 0x40FCE0);
DEFINE_NAKED_JMP(int SteamEngine::Win32::DB::COdbcBindColumn::Fetch(), 0x40FD60);
#endif

}}}//namespace SteamEngine { namespace Win32 { namespace DB {

typedef SteamEngine::Win32::DB::COdbc COdbc;
typedef SteamEngine::Win32::DB::COdbcBindColumn COdbcBindColumn;

#endif