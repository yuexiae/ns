#include "server/server_pch.h"

#include "server/ext/ns_ext.h"


class CMsgCounterFilter : public CMsgCounter {
public:
    void AddCountFilter(int, unsigned long) {
        return;
    }

    void PrintLogFilter(int, int) {
        return;
    }
};


bool CMsgCounterFilterInit() {
    return CMsgCounter::_PatchAddCount(&CMsgCounterFilter::AddCountFilter)
        && CMsgCounter::_PatchPrintLog(&CMsgCounterFilter::PrintLogFilter);
}