#include "server/server_pch.h"

#include "server/ext/ns_ext.h"
#include "server/db/game_db.h"

class CNSPcParamsFilter : public CNSPcParams {
public:
    BOOL LoadGuildMemberFilter(CNSGuild *pGuild) {
        return GameDb::GetSingleton()->DBGuildMemberLoad(pGuild);
    }
};


bool CNSPcParamsFilterInit() {
	return CNSPcParamsFilter::_PatchLoadGuildMember(&CNSPcParamsFilter::LoadGuildMemberFilter);
}