#include "server/server_pch.h"

#include "server/db/log_db.h"
#include "redis/redis.h"
#include "base/logging.h"
#include "base/util.h"


BOOL LogDb::DBLoginLog(CNSPcExt *pc) {
    redis::Connector &conn = GetConnector();
	try {
		msgpack::sbuffer buffer;
		msgpack::packer<msgpack::sbuffer> pk(&buffer);
		pk.pack(pc->m_nAliasSeq);
		pk.pack(pc->m_btLevel);
		pk.pack(pc->m_dwGold);
		pk.pack(pc->m_pSession->peer.m_dwPeerIp);
		pk.pack(time(NULL));
		conn.lpush("ConnLog", buffer);
        return TRUE;
	} catch (redis::Exception &ex) {
		LOGERROR("'%s'", ex.what());
	}
    return FALSE;
}

BOOL LogDb::DBAliasNameLog(CNSPcExt *pc, char *szUserAlias) {
    redis::Connector &conn = GetConnector();
	try {
		msgpack::sbuffer buffer;
        msgpack::packer<msgpack::sbuffer> pk(&buffer);
        pk.pack(pc->m_nAliasSeq);
        pk.pack(szUserAlias);
        pk.pack(_time32(NULL));
		conn.lpush("AliasLog", buffer);
        return TRUE;
	} catch (redis::Exception &ex) {
		LOGERROR("'%s'", ex.what());
	}
    return FALSE;
}


BOOL LogDb::DBItemLog(char cMode, char *szAction, unsigned int dwOptionValue, int nItemSeq, unsigned short wItemId, unsigned char btCount, int nAliasSeq) {
	redis::Connector &conn = GetConnector();
	try {
		msgpack::sbuffer buffer;
		msgpack::packer<msgpack::sbuffer> pk(&buffer);
		pk.pack(cMode);
		pk.pack(szAction);
		pk.pack(dwOptionValue); 
		pk.pack(nItemSeq); 
		pk.pack(wItemId);
		pk.pack(btCount);
		pk.pack(nAliasSeq); 
		pk.pack(time(NULL));
		conn.lpush("ItemLog", buffer);
        return TRUE;
	} catch (redis::Exception &ex) {
		LOGERROR("'%s'", ex.what());
	}
    return FALSE;
}

BOOL LogDb::DBGuildLog(int nDbSeq, char cMode, char *szAction, int nAliasSeq, int nOptionValue1, int nOptionValue2, int nOptionValue3) {
	redis::Connector &conn = GetConnector();
	try {
		msgpack::sbuffer buffer;
		msgpack::packer<msgpack::sbuffer> pk(&buffer);
		pk.pack(nDbSeq);
		pk.pack(cMode);
		pk.pack(szAction); 
		pk.pack(nAliasSeq); 
		pk.pack(nOptionValue1);
		pk.pack(nOptionValue2);
		pk.pack(nOptionValue3); 
		pk.pack(time(NULL)); //regdate
		conn.lpush("GuildLog", buffer);
        return TRUE;
	} catch (redis::Exception &ex) {
		LOGERROR("'%s' seq:%d", ex.what());
	}
    return FALSE;
}

BOOL LogDb::DBRealmLog(CNSPc *pChar, CNSCharacter *pTarget, unsigned int dwRealmPoint) {
	redis::Connector &conn = GetConnector();
	try {
		msgpack::sbuffer buffer;
		msgpack::packer<msgpack::sbuffer> pk(&buffer);
		pk.pack(pChar->m_szUserAlias);
		pk.pack(pChar->m_btRegion);
		pk.pack(pChar->m_cell.x);
		pk.pack(pChar->m_cell.y);
		
		if (pTarget && pTarget->IsPcClass()) {
			pk.pack(static_cast<CNSPc *>(pTarget)->m_szUserAlias);
		} else {
			pk.pack("NULL");
		}

		pk.pack(dwRealmPoint);
		pk.pack(time(NULL)); //regdate
		conn.lpush("RealmLog", buffer);
        return TRUE;
	} catch (redis::Exception &ex) {
		LOGERROR("'%s'", ex.what());
	}
    return FALSE;
}