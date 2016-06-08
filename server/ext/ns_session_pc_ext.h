#ifndef SERVER_EXT_NSSESSION_PC_EXT_H_
#define SERVER_EXT_NSSESSION_PC_EXT_H_

#include "ns_header/ns.h"

namespace internal {
class CNSSessionPcExtImpl {
public:
    template <unsigned long N>
    struct QueueBuffer {
        void Clear() { m_dwQueueBytes = 0; m_dwCount = 0; }

        bool Add(void *buffer, unsigned long size) {
            if (m_dwQueueBytes + size > N) {
                return false;
            } else {
                memcpy(m_cQueueBuffer + m_dwQueueBytes, buffer, size);
                m_dwQueueBytes += size;
                ++m_dwCount;
                return true;
            }
        }

        char m_cQueueBuffer[N];
        unsigned long m_dwQueueBytes;
        unsigned long m_dwCount;
    };

    CNSSessionPcExtImpl() {
        InitExt();
    }

    void InitExt() {
        m_nSentBytes = 0;
        m_QueueBuffer.Clear();
    }

    volatile LONG m_nSentBytes;
    QueueBuffer<1024 *10> m_QueueBuffer;
};
}



class CNSSessionPcExt : public CNSSessionPc, public internal::CNSSessionPcExtImpl {
public:
	static void ProcessInit(pfnProcess fn);

	static unsigned long GetServerIp() {
		return *reinterpret_cast<unsigned long *>(CNSSessionPc::ms_btServerIpArray());
	}

    void SendDbMessageQueue();
};




#endif