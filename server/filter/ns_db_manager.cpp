#include "server/server_pch.h"

#include "server/ext/ns_ext.h"
#include "server/db/auth_db.h"
#include "server/db/game_db.h"
#include "server/db/log_db.h"
#include "server/game_config.h"


class CNSDbManagerFilter : public CNSDbManagerExt {
public:
    static CNSDbManager::_Invoke invoke_;

    BOOL InitFilter() {
        BOOL reulst = (this->*invoke_.Init)();

        if (!static_cast<CNSMsgParamsExt *>(CNSMsgParamsExt::GetInstance())->DBLoad()) {
            LOGFATAL("MsgParams load failed");
        }

        return reulst;
    }

    void AddDbSessionFilter(CNSSessionPc *pSession, CPacket &packet) {
        switch (packet.GetId()) {
        case CNSMessageId::ISPVPItemAdd:
        case CNSMessageId::ISTameMobSave:
        case CNSMessageId::ISCheckDoubleConnect:
        case CNSMessageId::ISEventItemAdd:
        case CNSMessageId::ISSkillUse:
        case CNSMessageId::ISQuestMobCheck:
        case CNSMessageId::ISMemoWrite:
        case CNSMessageId::ISGMemoWrite:
        case CNSMessageId::SCPartyInvite:
        case CNSMessageId::SCPartyQuit:
        case CNSMessageId::SCPartyKick:
        case CNSMessageId::SCFriendAddReq:
        case CNSMessageId::SCCmdRename:
        case CNSMessageId::SCNpcTalk:
        case CNSMessageId::SSNpcTalk:
            //if (this->m_dwThread == GetCurrentThreadId()) {
            //    LOGINFO("this->m_dwThread(%x) == GetCurrentThreadId() id:%04x", this->m_dwThread, packet.GetId());
            //    pSession->PacketProcess(packet);
            //    break;
            //}
        case CNSMessageId::SSGameLeave:
        default:
            (this->*invoke_.AddDbSession)(pSession, packet);
            m_WaitableEvent.Signal();
            break;
        }
    }

    void AddDbSavePcFilter(CNSDbManager::SAVEPCMODE mode, CNSPc *pPc) {
        if (this->m_dwThread == GetCurrentThreadId()) {
            pPc->DBSave(mode);
        } else {
            (this->*invoke_.AddDbSavePc)(mode, pPc);
            m_WaitableEvent.Signal();
        }
    }

    void ActionFilter() {
        timeBeginPeriod(1);
        if (GetThreadPriority(GetCurrentThread()) != THREAD_PRIORITY_TIME_CRITICAL) {
            SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_TIME_CRITICAL);
        }

        unsigned int dwConfigSleepTime = GameConfig::GetSingleton()->GetPcManagerSleepTime();

        m_WaitableEvent.Wait();
        GameUtil::Output("CNSDbManager::Action() Signal");

        GameDb::GetSingleton()->SetThreadId();
        AuthDb::GetSingleton()->SetThreadId();
        LogDb::GetSingleton()->SetThreadId();


        unsigned int dwCheckTime = 0;
        while (this->m_bThreadLoop) {
            this->m_dwLastCheckTime = timeGetTime();
            if (m_WaitableEvent.Wait(dwCheckTime > this->m_dwLastCheckTime ? dwCheckTime - this->m_dwLastCheckTime : 0)) {
                CNSWorldManagerExt::m_DbProcessTime.Start();
                int nSession = 0, nSavePc = 0;
                if (!this->m_mapDbSession.empty()) {
                    nSession = this->ProcessDbSession();
                }
                if (!this->m_queueDbSavePc.empty()) {
                    nSavePc = this->ProcessDbSavePc();
                }
                if (this->m_dwLagTest) {
                    Sleep(this->m_dwLagTest);
                    this->m_dwLagTest = 0;
                }
                CNSWorldManagerExt::m_DbProcessTime.End();

                if (nSession || nSavePc) {
                    GameUtil::OutputDefault("DbSession:%d/%d/%dms", nSession, nSavePc, CNSWorldManagerExt::m_DbProcessTime.Get());
                }
            }

            unsigned int dwTime = timeGetTime();
            if (dwCheckTime < dwTime) {
                CNSNpcManager::GetInstance()->ActionNew();
                CNSPcManager::GetInstance()->ActionNew();
                dwCheckTime = dwTime + dwConfigSleepTime;
            }

            
            CNSPcManagerExt::GetInstance()->SendDbQueueMessage();
        }
    }
};

CNSDbManager::_Invoke CNSDbManagerFilter::invoke_;

bool CNSDbManagerFilterInit() {
    return CNSDbManager::_PatchInit(&CNSDbManagerFilter::InitFilter, &CNSDbManagerFilter::invoke_.Init)
        && CNSDbManager::_PatchAddDbSession(&CNSDbManagerFilter::AddDbSessionFilter, &CNSDbManagerFilter::invoke_.AddDbSession)
        && CNSDbManager::_PatchAddDbSavePc(&CNSDbManagerFilter::AddDbSavePcFilter, &CNSDbManagerFilter::invoke_.AddDbSavePc)
        && CNSDbManager::_PatchAction(&CNSDbManagerFilter::ActionFilter);
}