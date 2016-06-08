#include "server/server_pch.h"

#include "server/ext/ns_ext.h"

class CNSPcManagerFilter : public CNSPcManager {
public:
	void ActionFilter() {
        return;
    }

};

bool CNSPcManagerFilterInit() {
    return CNSPcManager::_PatchAction(&CNSPcManagerFilter::ActionFilter);;
}
