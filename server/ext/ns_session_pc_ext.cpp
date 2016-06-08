#include "server/server_pch.h"

#include "server/ext/ns_session_pc_ext.h"




void CNSSessionPcExt::ProcessInit(pfnProcess fn) {
	for (unsigned int i = 0; i < 0xFFFF; ++i) {
		ms_pProcessArray()[i] = fn;
	}	
}

void CNSSessionPcExt::SendDbMessageQueue() {
    if (!this->m_bCloseConnection && this->m_QueueBuffer.m_dwQueueBytes) {
        //LOGINFO("Length:%u Count:%u", this->m_QueueBuffer.m_dwQueueBytes, this->m_QueueBuffer.m_dwCount);
        this->_SendMessage(this->m_QueueBuffer.m_cQueueBuffer, this->m_QueueBuffer.m_dwQueueBytes);
        this->m_QueueBuffer.Clear();
    }
}