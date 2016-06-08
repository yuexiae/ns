#ifndef SERVER_DB_AUTH_DB_H_
#define SERVER_DB_AUTH_DB_H_

#include "base/singleton.h"
#include "server/db/memory_db.h"
#include "server/ext/ns_ext.h"

#include <msgpack.hpp>


class AuthDb : public MemoryDb, public base::Singleton<AuthDb> {
public:
    bool ScriptHashInit();

	BOOL DBMainUserSeq(CNSPc *pc, char *szUserId);

	BOOL DBMainLastServerLoad(char *szUserId, unsigned char *btServerIpArray, int &nPort);

	BOOL DBMainLastServerSave(char *szUserId, unsigned long ip, unsigned short port);

    int DBBillGetGearInfo(CNSPcExt *pc);

    int DBBillReqBuyItem(CNSPcExt *pc, unsigned short wItemId, char *szItemName, int nGear, char *szServerIp, char *szClientIp);

private:
    std::string script_bill_req_buy_item_;
};






#endif