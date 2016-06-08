#ifndef SERVER_EXT_NS_NPC_PARAMS_EXT_H_
#define SERVER_EXT_NS_NPC_PARAMS_EXT_H_

#include "ns_header/ns.h"

class CNSNpcParamsExt : public CNSNpcParams {
public:
    bool ReadNpcScript(unsigned short wNpcId, CNSNpcParams::_NpcScript& script);

    bool ReloadNpcScript(unsigned short wNpcId);
};


#endif