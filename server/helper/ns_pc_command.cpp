#include "server/server_pch.h"

#include "server/helper/ns_pc_command.h"
#include "server/ext/ns_ext.h"
#include "base/string_split.h"

bool NSPcCommand::OnCommand(const char *szCommand) {
	if (m_pParent->GetAdminLevel() < 3) {
		return false;
	}

	base::StringSplit param(10, szCommand, " ");
	if (param.Count() == 0) {
		return false;
	}

	param.Get<const char *>(1);

#define COMMAND_CHECK_0(command) \
	do {if (param.Icmp(0, #command)) {if (param.Count() == 1){ On##command();return true;}}} while (0)
#define COMMAND_CHECK_1(command, arg0) \
	do {if (param.Icmp(0, #command)) {if (param.Count() == 2){ On##command(param.Get<arg0>(1));return true;}}} while (0)
#define COMMAND_CHECK_2(command, arg0, arg1) \
	do {if (param.Icmp(0, #command)) {if (param.Count() == 3){ On##command(param.Get<arg0>(1),param.Get<arg1>(2));return true;}}} while (0)
#define COMMAND_CHECK_3(command, arg0, arg1, arg2) \
	do {if (param.Icmp(0, #command)) {if (param.Count() == 4){ On##command(param.Get<arg0>(1),param.Get<arg1>(2),param.Get<arg2>(3));return true;}}} while (0)


	COMMAND_CHECK_1(GoldAdd, unsigned long);
	COMMAND_CHECK_2(BuffAdd, int, unsigned short);
	COMMAND_CHECK_1(ItemAdd, unsigned short);
	COMMAND_CHECK_2(ItemAdd, unsigned short, unsigned char);
	COMMAND_CHECK_2(ItemMake, unsigned short, unsigned char);
	COMMAND_CHECK_1(ItemFind, const char *);
	COMMAND_CHECK_1(NpcTalkTest, const char *);
	COMMAND_CHECK_0(GuildCreate);
    COMMAND_CHECK_2(MsgTest, const char *, unsigned long);
	
	m_pParent->SendSystemMessage("unknow(%s,%d)", param.Get<const char *>(0), param.Count());

	return true;
}

void NSPcCommand::OnGoldAdd(unsigned long dwGold) {
	m_pParent->IncGold(dwGold);
	m_pParent->SendGoldChangeMessage();
	m_pParent->SendSystemMessage("addgold(%u) success", dwGold);
}

void NSPcCommand::OnBuffAdd(int nBuffId, unsigned short wSecond) {
	m_pParent->m_BuffList.Add(m_pParent->m_dwObjectId, (CNSBuff::BUFFTYPE)nBuffId, 0, 0, 0, wSecond, timeGetTime(), 0);
}

void NSPcCommand::OnItemAdd(unsigned short wItemId) {
	if (m_pParent->ItemAdd(wItemId, 1, "DBUG", 0, 0)) {
		m_pParent->SendSystemMessage("itemadd(%u,%u) success", wItemId, 1);
	} else {
		m_pParent->SendSystemMessage("itemadd(%u,%u) failure", wItemId, 1);
	}
}

void NSPcCommand::OnItemAdd(unsigned short wItemId, unsigned char btCount) {
	if (m_pParent->ItemAdd(wItemId, btCount, "DBUG", 0, 0)) {
		m_pParent->SendSystemMessage("itemadd(%u,%u) success", wItemId, btCount);
	} else {
		m_pParent->SendSystemMessage("itemadd(%u,%u) failure", wItemId, btCount);
	}
}

void NSPcCommand::OnItemMake(unsigned short wItemId, unsigned char btSeed) {
	if (m_pParent->ItemAdd(wItemId, 1, "DBUG", 0, btSeed)) {
		m_pParent->SendSystemMessage("itemmake(%u,%u) success", wItemId, 1);
	} else {
		m_pParent->SendSystemMessage("itemmake(%u,%u) failure", wItemId, 1);
	}
}

void NSPcCommand::OnItemFind(const char *szItemName) {
	CNSItemParams *itemparams = CNSItemParams::GetInstance();
	for (std::map<unsigned short, CNSItem *>::iterator iter = itemparams->m_mapItem.begin();
		iter != itemparams->m_mapItem.end();
		++iter) {
		if (strstr(iter->second->m_szItemName, szItemName) > 0) {
            m_pParent->SendSystemMessage("%u:%x:%s quest:%u kind:%0f gold:%u",
				iter->second->m_wItemId, iter->second->m_wItemId, iter->second->m_szItemName, iter->second->m_wQuestId, iter->second->m_btKind, iter->second->m_dwGold);
		}
	}
}

void NSPcCommand::OnNpcTalkTest(const char *szMenu) {
	CPacket packet(CNSMessageId::SCNpcTalk);
	packet.WriteULong(m_pParent->m_dwTalkNpcObjectId);
	packet.WriteString(szMenu);

	CNSDbManager::GetInstance()->AddDbSession(m_pParent->m_pSession, packet);
	m_pParent->SendSystemMessage("sucesss(%s)", szMenu);
}


void NSPcCommand::OnGuildCreate() {
	CPacket packet(CNSMessageId::CSGuildCreate);
	packet.WriteUChar(1);
	m_pParent->SendMessageA(packet, 1);
}


void NSPcCommand::OnMsgTest(const char *szText, unsigned long dwCount) {
    CPacket packet;
    for (unsigned long i = 0; i < dwCount; ++i) {
        packet.Clear(0x2000);
        packet.SetId(0x3011);
        packet.WriteUChar(99);

        char head[32];
        sprintf(head, "%d:", i);
        packet.WriteData(head, strlen(head));
        packet.WriteString(szText);
        m_pParent->SendMessageA(packet, 1);
    }
    LOGINFO("Done");
}