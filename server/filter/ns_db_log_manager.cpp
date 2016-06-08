#include "server/server_pch.h"

#include "server/ext/ns_ext.h"


class CNSDbLogManagerFilter : public CNSDbLogManager {
public:
    BOOL InitFilter() {
        return TRUE;
    }
};



bool CNSDbLogManagerFilterInit() {
	return CNSDbLogManager::_PatchInit(&CNSDbLogManagerFilter::InitFilter);
}