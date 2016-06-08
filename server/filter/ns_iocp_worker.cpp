#include "server/server_pch.h"

#include "server/ext/ns_ext.h"


class CIOCompletionWorkerFilter : public CIOCompletionWorker {
public:
    void ActionFilter() {
        //not check
        //not impl exception
        

        DWORD dwCompletionKey, dwReadBytes;
        OVERLAPPED *overlapped;

        this->m_dwStartTick = GetTickCount();

        while (*this->m_bThreadLoop()) {
        
            CIOCompletionHandler::GetInstance()->GetIOCP()->GetStatus(&dwCompletionKey, &dwReadBytes, &overlapped);

            if (dwCompletionKey && dwReadBytes && overlapped) {
                reinterpret_cast<CSession *>(dwCompletionKey)->Dispatch(dwReadBytes, overlapped);
                GameUtil::Output("flags:%u", static_cast<CSession::OVERLAPPED2_SEND *>(overlapped)->flags);
                ++this->m_dwDispatchCount;
                this->m_dwReadBytes += dwReadBytes;
            } else if ( dwCompletionKey ) {
                CSingleton<CSessionManager>::GetInstance()->RemoveSession(reinterpret_cast<CSession *>(dwCompletionKey));
            }
        }
    }
};



bool CIOCompletionWorkerFilterInit() {
    return true;
}