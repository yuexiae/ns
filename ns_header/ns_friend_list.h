#ifndef NSHEADER_NS_FRIEND_LIST_H_
#define NSHEADER_NS_FRIEND_LIST_H_



class CNSPcFriendList {
public:
	static const unsigned int _size = 0x440;
	struct Friend {
		static const unsigned int _size = 0x24;
		int nDbSeq;//this+0x0
		int bStatus;//this+0x4
		char szUserAlias[0x19];//this+0x8
	};

	struct CNSPcFriendList::Friend m_FriendArray[0x1E];//this+0x0
	CNSPcFriendList();    PATCH_MEMBER(CNSPcFriendList &, Constructor, , 0x485FB0);
	void SetParent(CNSPc *);    PATCH_MEMBER(void, SetParent, CNSPc *, 0x481D30);
	unsigned long GetCount();    PATCH_MEMBER(unsigned long, GetCount, , 0x484B40);
	int IsFull();    PATCH_MEMBER(int, IsFull, , 0x483F40);
	void Clear();    PATCH_MEMBER(void, Clear, , 0x4849E0);
	int Add(int, char *);    PATCH_MEMBER(int, Add, int _COMMA char *, 0x485FD0);
	int Delete(char *);    PATCH_MEMBER(int, Delete, char *, 0x486090);
	unsigned long PacketList(CPacket &, int);    PATCH_MEMBER(unsigned long, PacketList, CPacket & _COMMA int, 0x486350);
	int ChangeUserAlias(char *, char *);    PATCH_MEMBER(int, ChangeUserAlias, char * _COMMA char *, 0x4861A0);
	void OnActiveCheck(char *, char *);    PATCH_MEMBER(void, OnActiveCheck, char * _COMMA char *, 0x486230);
	void SendSyncFriendAddMessage(int, char *);    PATCH_MEMBER(void, SendSyncFriendAddMessage, int _COMMA char *, 0x486520);
	void SendSyncFriendDeleteMessage(char *);    PATCH_MEMBER(void, SendSyncFriendDeleteMessage, char *, 0x4865F0);
	class CNSPc * m_pParent;//this+0x438
	unsigned long m_dwCount;//this+0x43C

	/*struct _Invoke {
	PATCH_MEMBER_INVOKE(CNSPcFriendList &, CNSPcFriendList, Constructor, );
	PATCH_MEMBER_INVOKE(void, CNSPcFriendList, SetParent, CNSPc *);
	PATCH_MEMBER_INVOKE(unsigned long, CNSPcFriendList, GetCount, );
	PATCH_MEMBER_INVOKE(int, CNSPcFriendList, IsFull, );
	PATCH_MEMBER_INVOKE(void, CNSPcFriendList, Clear, );
	PATCH_MEMBER_INVOKE(int, CNSPcFriendList, Add, int _COMMA char *);
	PATCH_MEMBER_INVOKE(int, CNSPcFriendList, Delete, char *);
	PATCH_MEMBER_INVOKE(unsigned long, CNSPcFriendList, PacketList, CPacket & _COMMA int);
	PATCH_MEMBER_INVOKE(int, CNSPcFriendList, ChangeUserAlias, char * _COMMA char *);
	PATCH_MEMBER_INVOKE(void, CNSPcFriendList, OnActiveCheck, char * _COMMA char *);
	PATCH_MEMBER_INVOKE(void, CNSPcFriendList, SendSyncFriendAddMessage, int _COMMA char *);
	PATCH_MEMBER_INVOKE(void, CNSPcFriendList, SendSyncFriendDeleteMessage, char *);
	};*/
};
#ifdef DEFINE_NS_CPP
	//DEFINE_NAKED_JMP(CNSPcFriendList::Constructor(), 0x485FB0);
	//DEFINE_NAKED_JMP(void CNSPcFriendList::SetParent(CNSPc *), 0x481D30);
	//DEFINE_NAKED_JMP(unsigned long CNSPcFriendList::GetCount(), 0x484B40);
	//DEFINE_NAKED_JMP(int CNSPcFriendList::IsFull(), 0x483F40);
	DEFINE_NAKED_JMP(void CNSPcFriendList::Clear(), 0x4849E0);
	DEFINE_NAKED_JMP(int CNSPcFriendList::Add(int _COMMA char *), 0x485FD0);
	//DEFINE_NAKED_JMP(int CNSPcFriendList::Delete(char *), 0x486090);
	//DEFINE_NAKED_JMP(unsigned long CNSPcFriendList::PacketList(CPacket & _COMMA int), 0x486350);
	//DEFINE_NAKED_JMP(int CNSPcFriendList::ChangeUserAlias(char * _COMMA char *), 0x4861A0);
	//DEFINE_NAKED_JMP(void CNSPcFriendList::OnActiveCheck(char * _COMMA char *), 0x486230);
	//DEFINE_NAKED_JMP(void CNSPcFriendList::SendSyncFriendAddMessage(int _COMMA char *), 0x486520);
	//DEFINE_NAKED_JMP(void CNSPcFriendList::SendSyncFriendDeleteMessage(char *), 0x4865F0);
#endif



#endif