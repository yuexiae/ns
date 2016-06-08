#ifndef NSHEADER_NS_PC_CHAT_CHANNEL_LIST_H_
#define NSHEADER_NS_PC_CHAT_CHANNEL_LIST_H_

class CNSPcChatChannelList {
public:
	static const unsigned int _size = 0x61a8;

	CNSPcChatChannelList();    PATCH_MEMBER(CNSPcChatChannelList &, Constructor, , 0x484DF0);
	void Clear();    PATCH_MEMBER(void, Clear, , 0x485080);
	unsigned short Add(char *);    PATCH_MEMBER(unsigned short, Add, char *, 0x484E10);
	int Delete(char *);    PATCH_MEMBER(int, Delete, char *, 0x484F20);
	int Delete(unsigned short);    PATCH_MEMBER(int, Delete, unsigned short, 0x484EC0);
	char * GetName(unsigned short);    PATCH_MEMBER(char *, GetName, unsigned short, 0x484A70);
	unsigned short GetChannel(char *);    PATCH_MEMBER(unsigned short, GetChannel, char *, 0x484F90);
	unsigned long DebugPrint(CNSPc *);    PATCH_MEMBER(unsigned long, DebugPrint, CNSPc *, 0x484FF0);
	char m_szChatChannelArray[1000][25];//this+0x0

	/*struct _Invoke {
	PATCH_MEMBER_INVOKE(CNSPcChatChannelList &, CNSPcChatChannelList, Constructor, );
	PATCH_MEMBER_INVOKE(void, CNSPcChatChannelList, Clear, );
	PATCH_MEMBER_INVOKE(unsigned short, CNSPcChatChannelList, Add, char *);
	PATCH_MEMBER_INVOKE(int, CNSPcChatChannelList, Delete, char *);
	PATCH_MEMBER_INVOKE(int, CNSPcChatChannelList, Delete, unsigned short);
	PATCH_MEMBER_INVOKE(char *, CNSPcChatChannelList, GetName, unsigned short);
	PATCH_MEMBER_INVOKE(unsigned short, CNSPcChatChannelList, GetChannel, char *);
	PATCH_MEMBER_INVOKE(unsigned long, CNSPcChatChannelList, DebugPrint, CNSPc *);
	};*/

#ifdef DEFINE_NS_CPP
	//DEFINE_NAKED_JMP(CNSPcChatChannelList::Constructor(), 0x484DF0);
	//DEFINE_NAKED_JMP(void CNSPcChatChannelList::Clear(), 0x485080);
	//DEFINE_NAKED_JMP(unsigned short CNSPcChatChannelList::Add(char *), 0x484E10);
	//DEFINE_NAKED_JMP(int CNSPcChatChannelList::Delete(char *), 0x484F20);
	//DEFINE_NAKED_JMP(int CNSPcChatChannelList::Delete(unsigned short), 0x484EC0);
	//DEFINE_NAKED_JMP(char * CNSPcChatChannelList::GetName(unsigned short), 0x484A70);
	//DEFINE_NAKED_JMP(unsigned short CNSPcChatChannelList::GetChannel(char *), 0x484F90);
	//DEFINE_NAKED_JMP(unsigned long CNSPcChatChannelList::DebugPrint(CNSPc *), 0x484FF0);
#endif
};





#endif