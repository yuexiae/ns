#ifndef SERVER_EXT_NS_NPC_STATE_MOVE_EXT_H_
#define SERVER_EXT_NS_NPC_STATE_MOVE_EXT_H_

#include "ns_header/ns.h"

class CNSNpcStateMoveExt : public CNSNpcStateMove {
public:
    bool GetPetPickDestination(NSPOINT2& cell);
};






#endif