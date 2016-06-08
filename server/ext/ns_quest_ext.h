#ifndef SERVER_EXT_NSQUEST_EXT_H_
#define SERVER_EXT_NSQUEST_EXT_H_

#include "ns_header/ns.h"

class CNSQuestExt : public CNSQuest {
public:
    struct QuestData {
		unsigned short wQuestId;
		unsigned char btCompleted;
		unsigned char btStep;
		unsigned int btCheckCount;
		unsigned char btPoint;
		unsigned long dwRegdate;

        MSGPACK_DEFINE(wQuestId, btCompleted, btStep, btCheckCount, btPoint, dwRegdate);
	};

};

class CNSQuestListExt : public CNSQuestList {
public:
    CNSQuest * AddQuest(CNSQuestExt::QuestData& data) {
        tm rtm;
        _localtime32_s(&rtm, (time_t *)&data.dwRegdate);

        CNSQuest::_dateTime d_regdate;
        d_regdate.wYear = rtm.tm_year + 1900;
        d_regdate.wMonth = rtm.tm_mon + 1;
        d_regdate.wDay = rtm.tm_mday;
        d_regdate.wHour = rtm.tm_hour;
        d_regdate.wMinute = rtm.tm_min;
        d_regdate.wSecond = rtm.tm_sec;

        return this->Add(data.wQuestId, data.btCompleted, data.btStep, data.btCheckCount, data.btPoint, d_regdate);
    }
};







#endif