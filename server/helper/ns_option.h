#ifndef SERVER_HELPER_NS_OPTION_H_
#define SERVER_HELPER_NS_OPTION_H_

#include "server/ext/ns_ext.h"


class NSOption {
public:
	static void Init();

	static CNSItem::Option m_Mythic[10][10];

	static void GetDescription(CNSItem::Option option[10], char *description);
};



#endif