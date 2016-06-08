#include "server/server_pch.h"

#include "server/ext/ns_ext.h"

class CNSMsgParamsFilter : public CNSMsgParamsExt {
public:
    BOOL LoadFilter() {
        return 0;
    }

    char * CNSMsgParamsFilter::GetObjectAFilter(int nMsgId) {
        return CNSMsgParamsExt::GetMsgString(nMsgId);
    }
};

bool CNSMsgParamsFilterInit() {
    return CNSMsgParams::_PatchLoad(&CNSMsgParamsFilter::LoadFilter)
        && CNSMsgParams::_PatchGetObjectA(&CNSMsgParamsFilter::GetObjectAFilter);
}
