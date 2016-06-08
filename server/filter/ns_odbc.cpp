#include "server/server_pch.h"

#include "server/ext/ns_ext.h"


class COdbcFilter : public SteamEngine::Win32::DB::COdbc {
public:
    void SQLAllocHandleStmtFilter(void **hStmt) {
        __asm int 3;
    }
};

bool COdbcFilterInit() {
    return SteamEngine::Win32::DB::COdbc::_PatchSQLAllocHandleStmt(&COdbcFilter::SQLAllocHandleStmtFilter);
}