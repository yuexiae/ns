#ifndef SERVER_EXT_NS_VR_BLOCK_MANAGER_EXT_H_
#define SERVER_EXT_NS_VR_BLOCK_MANAGER_EXT_H_

#include "ns_header/ns.h"

class CNSVrBlockManagerExt : public CNSVrBlockManager {
public:
    BOOL BroadcastPcNew(CNSCharacter *pChar, CPacket& packet, CNSPc *pTarget, _NSRANGE& range, int bSendExcept, bool& bEncode);
};




#endif