#ifndef SERVER_DB_LOG_DB_H_
#define SERVER_DB_LOG_DB_H_

#include "base/singleton.h"
#include "server/db/memory_db.h"
#include "server/ext/ns_ext.h"

#include <msgpack.hpp>


class LogDb : public MemoryDb, public base::Singleton<LogDb> {
public:
    BOOL DBAliasNameLog(CNSPcExt *pc, char *szUserAlias);

    BOOL DBLoginLog(CNSPcExt *pc);

	BOOL DBItemLog(char cMode, char *szAction, unsigned int dwOptionValue, int nItemSeq, unsigned __int16 wItemId, unsigned char  btCount, int nAliasSeq);

	BOOL DBGuildLog(int nDbSeq, char cMode, char *szAction, int nAliasSeq, int nOptionValue1, int nOptionValue2, int nOptionValue3);

	BOOL DBRealmLog(CNSPc *pChar, CNSCharacter *pTarget, unsigned int dwRealmPoint);
};






#endif