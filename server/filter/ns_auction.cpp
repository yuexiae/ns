#include "server/server_pch.h"

#include "server/ext/ns_ext.h"


class CNSAuctionFilter : public CNSAuction {
public:
    BOOL InitFilter() {
        return TRUE;
    }
};



bool CNSAuctionFilterInit() {
	return CNSAuction::_PatchInit(&CNSAuctionFilter::InitFilter);
}