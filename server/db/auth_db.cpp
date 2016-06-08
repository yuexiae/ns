#include "server/server_pch.h"

#include "server/db/auth_db.h"
#include "redis/redis.h"
#include "base/logging.h"
#include "base/util.h"

bool AuthDb::ScriptHashInit() {
    redis::Connector &conn = GetConnector();
    try {
        conn.script_load(".\\dbscript\\bill_req_buy_item.lua", script_bill_req_buy_item_);
    } catch (redis::Exception &ex) {
        LOGERROR("'%s' ", ex.what());
        return false;
    }
    return true;
}
int AuthDb::DBMainUserSeq(CNSPc *pc, char *szUserId) {

    redis::Connector &conn = GetConnector();

	pc->m_nUserSeq = -1;
	pc->m_bPcBangCheck = 0;

	try {
		base::CalcHighTimeRange test_time("DBMainUserSeq");

		if (!conn.exists(redis::UniqueKey("UserList", szUserId))) {
			LOGERROR("UserList:%s not exist", szUserId);
			return FALSE;
		}

        redis::Reply reply = conn.hmget(redis::UniqueKey("UserList", szUserId), "Seq RegDate PcBangCheck");;
		
		pc->m_nUserSeq = reply[0].convert<int32_t>();
		GameUtil::ConvertTime(pc->m_tsRegDate, reply[1].convert<__time32_t>()); 
		pc->m_bPcBangCheck = reply[2].convert<int32_t>();
		
		return TRUE;
	} catch (redis::Exception &ex) {
        LOGERROR("'%s' UserId:'%s'", ex.what(), szUserId);
	}

	return FALSE;
}

BOOL AuthDb::DBMainLastServerLoad(char *szUserId, unsigned char *btServerIpArray, int &nPort) {
	redis::Connector &conn = GetConnector();
	try {
		if (!conn.exists(redis::UniqueKey("UserList", szUserId))) {
			LOGERROR("UserList:%s not exist", szUserId);
			return FALSE;
		}

		redis::Reply reply = conn.hget(redis::UniqueKey("UserList", szUserId), "ConnData");

		ULARGE_INTEGER ip_port;
		ip_port.QuadPart = reply.convert<uint64_t>();

		*reinterpret_cast<uint32_t *>(btServerIpArray) = ip_port.HighPart;
		nPort = ip_port.LowPart & 0x0000FFFF;

		return TRUE;
	} catch (redis::Exception &ex) {
        LOGERROR("'%s' UserId:'%s'", ex.what(), szUserId);
	}

	return FALSE;
}

BOOL AuthDb::DBMainLastServerSave(char *szUserId, unsigned long ip, unsigned short port) {
	redis::Connector &conn = GetConnector();
	try {
		if (!conn.exists(redis::UniqueKey("UserList", szUserId))) {
			LOGERROR("UserList:%s not exist", szUserId);
			return FALSE;
		}

		ULARGE_INTEGER ip_port = {port, ip};
		conn.hset(redis::UniqueKey("UserList", szUserId), "ConnData", ip_port.QuadPart);

		return TRUE;
	} catch (redis::Exception &ex) {
		LOGERROR("'%s' UserList(%s)", ex.what(), szUserId);
	}

	return FALSE;
}

int AuthDb::DBBillGetGearInfo(CNSPcExt *pc) {
    redis::Connector &conn = GetConnector();
	try {
        return conn.hget(redis::UniqueKey("UserList", pc->m_szUserId), "Gear").convert<int32_t>();
	} catch (redis::Exception &ex) {
		LOGERROR("'%s' UserList(%s)", ex.what(), pc->m_szUserId);
	}

	return 0;
}

int AuthDb::DBBillReqBuyItem(CNSPcExt *pc, unsigned short wItemId, char *szItemName, int nGear, char *szServerIp, char *szClientIp) {
    redis::Connector &conn = GetConnector();
	try {
        return conn.evalsha(script_bill_req_buy_item_, pc->m_szUserId, nGear).as<int32_t>();
	} catch (redis::Exception &ex) {
		LOGERROR("'%s' UserList(%s,%d)", ex.what(), pc->m_szUserId, nGear);
	}
	return -102;
}