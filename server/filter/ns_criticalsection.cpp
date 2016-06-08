#include "server/server_pch.h"

#include "ns_header/ns.h"
#include "server/game_config.h"


class CNSCriticalSectionFilter : public CNSCriticalSection {
public:
    void EnterFilter(int nDelay){
        __try {
            int nCount = 0;
            int nMaxCount = nDelay / 100;
            while (nCount++ < nMaxCount) {
                if (this->TryEnter()) {
                    return;
                } else {
                    Sleep(1);
                }
            }
            throw 0;
        } __except (CMiniDumper::WriteMiniDump(GetExceptionInformation())) {
            GameUtil::Output("Warning: TryEnter('%s')\n=====\n\n",this->m_szMsg);
        }
        
    }
};

bool CNSCriticalSectionFilterInit() {
    return CNSCriticalSection::_PatchEnter(&CNSCriticalSectionFilter::EnterFilter);
}
