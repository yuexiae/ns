#include "server/server_pch.h"

#include "server/ext/ns_ext.h"


class CSessionFilter : public CSession {
public:
    void DispatchFilter(unsigned long dwRecvBytes, OVERLAPPED *ov) {
        if (dwRecvBytes) {
            if (static_cast<OVERLAPPED2 *>(ov)->flags == 2) {
                this->m_dwCheckTime = timeGetTime();
                this->DispatchReceive(this->m_dwCheckTime, dwRecvBytes);
                ++this->m_dwRecvCount;
            } else if (static_cast<OVERLAPPED2 *>(ov)->flags == 1){
                CNSSessionPcExt *pSessionPc = reinterpret_cast<CNSSessionPcExt *>(this);
                if (pSessionPc != CNSPc::m_DummySession()) {
                    ::InterlockedDecrement(&reinterpret_cast<CNSSessionPcExt *>(pSessionPc)->m_nSentBytes);
                    if (pSessionPc->m_nSentBytes > 8192) {
                        LOGERROR("pSessionPc->m_nSentBytes = %u", pSessionPc->m_nSentBytes);
                    }
                }
            }
        }
    }

    static BOOL _SendMessageFilter(CSession *pSession, unsigned int socket, void *pBuff, unsigned long dwLength, unsigned long dwRetryCount) {
        if (socket == -1) {
            return FALSE;
        }

        unsigned long dwWrittenBytes = 0;
        memset(&pSession->m_overlappedSend, 0, 0x18u);
        pSession->m_overlappedSend.flags = 1;

        if (!::WriteFile(reinterpret_cast<HANDLE>(socket), pBuff, dwLength, &dwWrittenBytes, &pSession->m_overlappedSend)) {
            DWORD dwLastError = GetLastError();
            if (dwLastError != ERROR_IO_PENDING) {
                LOGERROR("Error: SendMessage(1 / Socket: %d / LastError: %u)\n", socket, dwLastError);
                CIOCompletionHandler::GetInstance()->GetIOCP()->PostStatus(reinterpret_cast<unsigned long>(pSession), 0, 0);
                return FALSE;
            }
        }

        if (pSession != CNSPc::m_DummySession()) {
            ::InterlockedIncrement(&reinterpret_cast<CNSSessionPcExt *>(pSession)->m_nSentBytes);
        }

        CSessionManager *pSessionManager = CSessionManager::GetInstance();
        ++pSessionManager->m_dwSendCount;
        pSessionManager->m_dwWriteBytes += dwLength;
        return TRUE;
    }
};



bool CSessionFilterInit() {
    return CSession::_PatchDispatch(&CSessionFilter::DispatchFilter)
        && CSession::_Patch_SendMessage(&CSessionFilter::_SendMessageFilter);
}