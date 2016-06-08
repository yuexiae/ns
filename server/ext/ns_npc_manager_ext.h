#ifndef SERVER_EXT_NS_NPC_MANAGER_EXT_H_
#define SERVER_EXT_NS_NPC_MANAGER_EXT_H_


#include "ns_header/ns.h"

class CNSNpcManagerExt : public CNSNpcManager {
public:
	void ProcessNew();

	void ActionNew();

    CNSObject::Owner<CNSNpcExt> CallMobExt(unsigned short wNpcId, NSPOINT2& cell, unsigned short wAngle) {
        return CallMob(wNpcId, cell.x, cell.y, 0, wAngle, 0).Convert<CNSNpcExt>();
    }
};









#endif