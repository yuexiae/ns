#ifndef SERVER_HELPER_NS_PC_COMMAND_H_
#define SERVER_HELPER_NS_PC_COMMAND_H_

class CNSPcExt;

class NSPcCommand {
public:
    NSPcCommand() : m_pParent() {
    }

	void Init(CNSPcExt *pParent) {
		m_pParent = pParent;
	}

	bool OnCommand(const char *szCommand);

	void OnGoldAdd(unsigned long dwGold);

	void OnBuffAdd(int nBuffId, unsigned short wSecond);

	void OnItemAdd(unsigned short wItemId);

	void OnItemAdd(unsigned short wItemId, unsigned char btCount);

	void OnItemMake(unsigned short wItemId, unsigned char btSeed);

	void OnItemFind(const char *szItemName);

	void OnNpcTalkTest(const char *szMenu);

	void OnGuildCreate();

    void OnMsgTest(const char *szText, unsigned long dwCount);

private:
	CNSPcExt *m_pParent;
};




#endif