#ifndef SERVER_EXT_NS_PC_EXT_H_
#define SERVER_EXT_NS_PC_EXT_H_

#include "ns_header/ns.h"
#include "server/helper/ns_pc_command.h"


namespace internal {
class CNSPcExtImpl {
public:
    CNSPcExtImpl(CNSPcExt *pParent) : m_SummonState(0) {
        m_Command.Init(reinterpret_cast<CNSPcExt *>(pParent));
        ClearExt(TRUE);
        m_nSentBytes = 0;
    }

    ~CNSPcExtImpl() {
    }

    unsigned long m_PremiumShopLimitChecksum;
    unsigned long m_dwCheckMoveTime;
    unsigned long m_dwCheckRandTime;
    std::vector<unsigned int> m_NpcMenuKey;
    NSPcCommand m_Command;
    volatile LONG m_nSentBytes;
    msgpack::sbuffer m_SummonState;
    CNSPc::CNSTameInfo m_TameState;
protected:
    void ClearExt(BOOL bFullClear) {
        m_PremiumShopLimitChecksum = 0;
        m_dwCheckMoveTime = 0;
        m_dwCheckRandTime = 0;
        m_NpcMenuKey.clear();
        m_SummonState.clear();
        memset(&m_TameState, 0, sizeof(m_TameState));
    }
};
}


class CNSPcExt : public CNSPc, public internal::CNSPcExtImpl {
public:
    enum ResetType {
		kResetBase = 0,
		kResetParam,
		kResetRegen
	};

    void SetDefaultQuickBar(unsigned char region, unsigned char job);

    void SummonLoad();

    int GetAdminLevel() {
		return CNSAdminParams::GetInstance()->GetAdminLevel(this->m_szUserId); 
	}

    unsigned char GetDefaultLimitSkillLevel() {
		unsigned char level = this->m_btLevel / 10 + (this->m_btLevel % 10 != 0) + 1;
		return level <= 10 ? level : 10;
	}

    void ResetNew(int bFullReset);

    void CalcOptionNew(ResetType type);

    void CalcOption(const CNSItem::Option option[10], ResetType type);
};




#endif