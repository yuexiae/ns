#ifndef SERVER_EXT_NS_NPC_EXT_H_
#define SERVER_EXT_NS_NPC_EXT_H_

#include "ns_header/ns.h"

namespace internal {
class CNSNpcExtImpl {
public:
    CNSNpcExtImpl() {
        m_bNpcEnter = false;
        m_bScriptIdle = true;
        m_bScriptQuestCheck = true;
        m_bReloadScript = false;
        m_bPetPickFlag = false;
        m_nGuildBaseSeq = 0;
        m_dwCheckMoveTime = 0;
    }

    ~CNSNpcExtImpl() {
    }

    bool m_bNpcEnter;
    bool m_bScriptIdle;
    bool m_bScriptQuestCheck;
    bool m_bReloadScript;
    bool m_bPetPickFlag;
    int m_nGuildBaseSeq;
    unsigned long m_dwCheckMoveTime;
};
}


class CNSNpcExt : public CNSNpc, public internal::CNSNpcExtImpl {
public:
	void ActionNew();

    void PacketMoveMessage(CPacket& packet);

    BOOL NpcScriptIdleNew(CNSPc *pCaller);
    BOOL NpcScriptQuestCheckNew(CNSPc *pCaller);
    

    static CNSNpcExt * New() {
        return reinterpret_cast<CNSNpcExt *>(&reinterpret_cast<CNSNpcExt *>(CNSNpc::operator new(sizeof(CNSNpcExt)))->Constructor());
    }
};


#endif