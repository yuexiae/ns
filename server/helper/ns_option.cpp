#include "server/server_pch.h"

#include "server/helper/ns_option.h"

CNSItem::Option NSOption::m_Mythic[10][10];

void NSOption::Init() {
	/*str=2,3,4,5,6,6,7,8,9,10
	  con=4,5,6,7,9,10,11,12,13,15
	  int=4,5,6,7,9,10,11,12,13,15
	  str=5,7,8,10,12,13,15,16,18,20
	  hp=280,360,440,520,600,680,760,840,920,1000*/

	memset(m_Mythic, 0, sizeof(m_Mythic));

	for (unsigned char i = 0; i < 10; ++i) {
		m_Mythic[i][0].btParam = CNSItem::OptionType_Con;
		m_Mythic[i][0].wValue = (unsigned short)((i + 1) * 1.2 + 3.0);
		m_Mythic[i][1].btParam = CNSItem::OptionType_Int;
		m_Mythic[i][1].wValue = (unsigned short)((i + 1) * 1.2 + 3.0);
		m_Mythic[i][2].btParam = CNSItem::OptionType_Str;
		m_Mythic[i][2].wValue = (unsigned short)((i + 1) * 1.6 + 4.0 + (i + 1) * 0.8 + 2.0);
		m_Mythic[i][3].btParam = CNSItem::OptionType_Hp;
		m_Mythic[i][3].wValue = (i + 1) * 80 + 200;
	}
}

void NSOption::GetDescription(CNSItem::Option option[10], char *description) {
    for (int i = 0; i < 10 && option[i].btParam; i++) {
        switch (option[i].btParam) {
        case CNSItem::OptionType_Str:
            sprintf(description, "%s\n^[G%s +%d", description, "力量", option[i].wValue);break;
        case CNSItem::OptionType_Con:
            sprintf(description, "%s\n^[G%s +%d", description, "体力", option[i].wValue);break;
        case CNSItem::OptionType_Dex:
            sprintf(description, "%s\n^[G%s +%d", description, "敏捷", option[i].wValue);break;
        case CNSItem::OptionType_Int:
            sprintf(description, "%s\n^[G%s +%d", description, "智力", option[i].wValue);break;
        case CNSItem::OptionType_Hp:
            sprintf(description, "%s\n^[G%s +%d", description, "生命值", option[i].wValue);break;
        case CNSItem::OptionType_Sta:
            sprintf(description, "%s\n^[G%s +%d", description, "耐力", option[i].wValue);break;
        case CNSItem::OptionType_Mp:
            sprintf(description, "%s\n^[G%s +%d", description, "魔法值", option[i].wValue);break;
        case CNSItem::OptionType_Ap:
            sprintf(description, "%s\n^[G%s +%d", description, "魔法攻击力", option[i].wValue);break;
        case CNSItem::OptionType_Dp:
            sprintf(description, "%s\n^[G%s +%d", description, "防御力", option[i].wValue);break;
        case CNSItem::OptionType_Ma:
            sprintf(description, "%s\n^[G%s +%d", description, "魔法攻击力", option[i].wValue);break;
        case CNSItem::OptionType_Rs:
            sprintf(description, "%s\n^[G%s +%d", description, "魔法防御力", option[i].wValue);break;
        case CNSItem::OptionType_HpRegen:
            sprintf(description, "%s\n^[G%s +%d%%", description, "生命值恢复", option[i].wValue);break;
        case CNSItem::OptionType_MpRegen:
            sprintf(description, "%s\n^[G%s +%d%%", description, "魔法值恢复", option[i].wValue);break;
        case CNSItem::OptionType_StaRegen:
            sprintf(description, "%s\n^[G%s +%d%%", description, "耐力值恢复", option[i].wValue);break;
        case CNSItem::OptionType_MoveSpeed:
            sprintf(description, "%s\n^[G%s +%d%%", description, "移动速度", option[i].wValue);break;
        case CNSItem::OptionType_AttackSpeed:
            sprintf(description, "%s\n^[G%s +%d%%", description, "攻击速度", option[i].wValue);break;
        case CNSItem::OptionType_DpPer:
            sprintf(description, "%s\n^[G%s +%d%%", description, "最大伤害减少", option[i].wValue);break;
        case CNSItem::OptionType_NsTank:
            sprintf(description, "%s\n^[G%s +%d", description, "新蒸汽储存容量", option[i].wValue);break;
        default:
            sprintf(description, "%s\n^[G%s +%d", description, "unknow", option[i].wValue);break;
        }
    }
}