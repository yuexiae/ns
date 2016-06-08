#ifndef SERVER_EXT_NS_MSG_PARAMS_EXT_H_
#define SERVER_EXT_NS_MSG_PARAMS_EXT_H_

#include "ns_header/ns.h"

class CNSMsgParamsExt : public CNSMsgParams {
public:
	bool DBLoad();

    static char * GetMsgString(int nMsgId);
};


#endif