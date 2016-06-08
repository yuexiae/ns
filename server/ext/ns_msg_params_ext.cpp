#include "server/server_pch.h"

#include "server/ext/ns_msg_params_ext.h"

namespace internal {
static int msg_count_ = 0;
static char *msg_string_[1024] = {0};
}


bool CNSMsgParamsExt::DBLoad() {
	COdbcBindColumn odbc(CNSDbManager::GetInstance()->GetDb());

	try {
        long len;
        CNSMsgParams::_NSMsg temp;

		odbc.BindInt(&temp.nMsgId, &len);
		odbc.BindString(temp.szMsg, 255, &len);
		odbc.Execute("SELECT [Id], [Data] FROM [MsgParams] ORDER BY [Id] ASC");
		
		while (odbc.Fetch() && internal::msg_count_ < 1024) {
			if (temp.nMsgId != internal::msg_count_) {
				GameUtil::Output("Error: DBLoad MsgParams id:%d", internal::msg_count_);
				return false;
			}

            internal::msg_string_[internal::msg_count_++] = _strdup(temp.szMsg);
		}

		if (internal::msg_count_ != NS_MSG_END) {
			GameUtil::Output("Error: MsgParams(%u!=%u)", NS_MSG_END, internal::msg_count_);
			return false;
		}

		GameUtil::Output("MsgParams Total = %u", internal::msg_count_);
		return true;

	} catch (SteamEngine::Win32::System::CException& e) {
        LOGERROR("sqlexec error(%s)", e.GetMessageA());
	}

	return false;
}

char * CNSMsgParamsExt::GetMsgString(int nMsgId) {
    if (nMsgId < internal::msg_count_) {
        return internal::msg_string_[nMsgId];
    } else if (nMsgId == NS_MSG_CHANNEL_RVR_NAME) {
        return "RVR";
    } else {
        LOGERROR("Error:get message text failed id:%d", nMsgId);
        return NULL;
    }
}