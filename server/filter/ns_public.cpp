#include "server/server_pch.h"

#include "server/ext/ns_ext.h"

static const char* g_szRegionArray[] = {"DEBUG", "M", "T", "N", "PVP"};

class NSPublicFilter {
public:
    static void PrintConsoleTitleFilter() {
        static unsigned int dwCount = 0;
        static unsigned int dwStartUpTime = timeGetTime();
        static unsigned int dwProcessId = GetProcessId(GetCurrentProcess());
        static double dTotalNpcProcessTime = 0;
        static double dAvgNpcProcessTime = 0;

        if (dwCount / 50 > 0) {
            dAvgNpcProcessTime = dTotalNpcProcessTime / dwCount;
            dTotalNpcProcessTime = 0;
            dwCount = 0;
        } else {
            dTotalNpcProcessTime += CNSWorldManagerExt::m_NpcProcessTime.GetMilliSecond();
        }

        char szTitle[1024];
        sprintf(szTitle,
            "[%c] NSGS(%s/%u):%d - SS:%u/PC:%u(%.3lfms)/NPC:%u(%.3lfms/%.3lfms)/DB:%u(%ums)/UP:%u m",
            dwCount % 2 ?  '.' : ':',
            g_szRegionArray[CSingleton<CNSWorldManager>::GetInstance()->m_btRegion],
            dwProcessId,
            CSingleton<CNSGameServerParams>::GetInstance()->m_nServerPort,
            CSingleton<CSessionManager>::GetInstance()->m_listSession->size(),
            CSingleton<CNSPcManager>::GetInstance()->m_mapPc.size(),
            CNSWorldManagerExt::m_PcProcessTime.GetMilliSecond(),
            CNSNpcManager::GetInstance()->m_mapNpc.size(),
            CNSWorldManagerExt::m_NpcProcessTime.GetMilliSecond(),
            dAvgNpcProcessTime,
            CNSDbManager::GetInstance()->m_mapDbSession.size(),
            CNSWorldManagerExt::m_DbProcessTime.Get(),
            (timeGetTime() - dwStartUpTime) / 0xEA60);

        //CNSObjectManager::GetFreeItemCount(v28);

        SetConsoleTitleA(szTitle);
        ++dwCount;
    }
};



bool NSPublicFilterInit() {
    return NSPublic::_PatchPrintConsoleTitle(&NSPublicFilter::PrintConsoleTitleFilter);
}