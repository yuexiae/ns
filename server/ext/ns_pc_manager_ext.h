#ifndef SERVER_EXT_NS_PC_MANAGER_EXT_H_
#define SERVER_EXT_NS_PC_MANAGER_EXT_H_


#include "ns_header/ns.h"

class CNSPcManagerExt : public CNSPcManager {
public:
	void ActionNew();
    void SendDbQueueMessage();
};









#endif