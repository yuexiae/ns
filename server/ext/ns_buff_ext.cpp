#include "server/server_pch.h"

#include "server/ext/ns_buff_ext.h"



bool CNSBuffExt::IsCanSave() {
	switch (this->m_buffType) {
	case BuffType_Dp:			//"防御力上升"
	case BuffType_Ap:			//"攻击力上升"
	case BuffType_Speed:		//"移动速度提升"
	case BuffType_MaxHp:		//"生命值上升"
	case BuffType_Rs:			//"魔法防御力上升"
	case BuffType_Ma:			//"魔法攻击力上升"
	case BuffType_Ar:			//"命中率上升"
	//case BuffType_Glory:		//UNKNOW
	case BuffType_Berserker:	//"狂暴"
	case BuffType_Dump:			//"神圣之盾"
	case BuffType_Thorn:		//"荆棘反弹"
	case BuffType_LowCounter:	//"反击"
	case BuffType_SaveExp:		//"自然守护"
	case BuffType_Clarity:		//"潜行"
	case BuffType_ClarityEx:	//"潜行EX"
	//case BuffType_Pet:
	//case BuffType_Tame:
	//case BuffType_Summon:
	case BuffType_RangeBlock:	//"远程攻击防御"
	case BuffType_FullSwine:	//"绿葡萄酒"
	//case BuffType_TendMelee:
	//case BuffType_TendRange:
	case BuffType_MythicBone:	//"神话之骨"
	case BuffType_MythicOcean:	//"神话之海"
	case BuffType_MythicForce:	//"神话之力"
	case BuffType_HpDrain:		//"吸收生命值"
	case BuffType_Ac:			//"防御力上升"
	case BuffType_WeaponStick:	//"无法解除武器"
	//case BuffType_Transfer:
	//case BuffType_Rider:
	case BuffType_DwellDeity:	//"战神之盾"
	case BuffType_DwellGoat:	//"山羊"
	case BuffType_BloodOcean:	//"活力无限"
	case BuffType_HolyDefense:	//"神之防御"
	//case BuffType_ImmunDebuff:
	case BuffType_FullBarrel:	//"节能"
	//case BuffType_Inspiration://"灵感之术"
	case BuffType_NeedleCounter://"反击中毒术"
	case BuffType_NobleShield:	//"防御强化之盾"
	case BuffType_DwellHero:	//"攻击加强"
	case BuffType_ImmunSleep:	//"睡眠免疫"
	case BuffType_ImmunSlow:	//"减速免疫"
	case BuffType_ImmunRoot:	//"缠绕免疫"
	case BuffType_ImmunRage:	//"减缓免疫
	case BuffType_ImmunPoison:	//"中毒免疫"
	case BuffType_ImmunStun:	//"眩晕免疫"
	case BuffType_AspecVolition://"守护"	
	case BuffType_PowerStaff:	//"力量之杖"
	case BuffType_MachineShield://"机械盾"
	case BuffType_MachineProtecter://"机械防护"
	//case BuffType_AutoSkill:
	//case BuffType_ExpUp:			//"经验值上升"
	//case BuffType_ExpUpParty:		//"经验值上升[队伍]"
	//case BuffType_MiningUp:		//"采矿量上升"
	case BuffType_AmuletProperty:	//"护身符佑护"
	//case BuffType_InvenExpand:
	//case BuffType_WareHouseExpand:
	//case BuffType_ExpUpExpand:
	//case BuffType_SiegeWeapon:
	case BuffType_WpMa:				//"魔法攻击力"
	case BuffType_DpPerSkill:		//"伤害减少"
	//case BuffType_DpPerPremium:	//"伤害减少"
	case BuffType_Dr:				//"防御成功率上升"
	case BuffType_DpBeast:			//"防御力增加"
	case BuffType_ApBeast:			//"攻击力增加"
	case BuffType_Hidden:			//"瞬间威胁值减少"
	case BuffType_RsPer:			//"魔法防御力增加"
	case BuffType_NSTank:			//"新蒸汽容器储存量增加"
	case BuffType_SpeedBeast:		//"移动速度增加"
	//case BuffType_AutoMining:
	//case BuffType_TpUp:			//"技能历练增加"
	case BuffType_Dash:				//"瞬间移动速度增加" 
	//case BuffType_CrushDivision:	//"碾压风暴"
	//case BuffType_SummonMaster:	//"王者召唤"
	case BuffType_ProtectField:		//"绝对防御"
	case BuffType_AbsolutPower:		//"绝对力量"
	//case BuffType_MaxHpExpand:	//"强化药水"
	//case BuffType_Reflection:		//UNKNOW
	//case BuffType_ExpUpShort:		//"经验达人"
	//case BuffType_ExpPenalty:		//"经验惩罚"
	//case BuffType_RearlandKill:
	//case BuffType_NoviceSheild:	//"新手保护"
	//case BuffType_OverlapExpUp1:	//"重叠经验增加1"
	//case BuffType_OverlapExpUp2:
	//case BuffType_OverlapExpUp3:
	//case BuffType_OverlapExpUp4:
	//case BuffType_OverlapExpUp5:
	//case BuffType_OverlapExpUp6:
	//case BuffType_OverlapExpUp7:
	//case BuffType_OverlapExpUp8:
	//case BuffType_OverlapExpUp9:
	//case BuffType_OverlapExpUp10:
	//case BuffType_PersonalSiegeWeapon:
	//case BuffType_SiegeMode:
	//case BuffType_OverlapGoldUp1:
	//case BuffType_OverlapGoldUp2:
	//case BuffType_OverlapGoldUp3:
	//case BuffType_OverlapGoldUp4:
	//case BuffType_OverlapGoldUp5:
	//case BuffType_OverlapGoldUp6:
	//case BuffType_OverlapGoldUp7:
	//case BuffType_OverlapGoldUp8:
	//case BuffType_OverlapGoldUp9:
	//case BuffType_OverlapGoldUp10:
	case BuffType_ImmunPoisonEx:	//中毒免疫Ex
	case BuffType_DutyFront:		//"冲刺"
	case BuffType_MaxStaMp:			//"最大耐力生命值增加"
	case BuffType_NeoSteamShield:	//"蒸汽护盾"
	case BuffType_NeoSteamDecrease:	//"蒸汽消耗降低"
	case BuffType_DevineShield:		//"神圣保护"
	case BuffType_ImmunIncrease:	//"免疫增加"
	case BuffType_RecoveryStun:		//"眩晕恢复"
	//case BuffType_ImmunDebuffPK:
	//case BuffType_ImmunDebuff3:
	return true;

	case BuffType_Poison:			//"中毒"
	case BuffType_Slow:				//"减速"
	case BuffType_Rage:				//"狂暴"
	case BuffType_Root:				//"缠绕"
	case BuffType_Stun:				//"眩晕"
	case BuffType_Sleep:			//"睡眠"
	case BuffType_Chaos:			//"混乱术"
	case BuffType_Curse:			//"诅咒"
	case BuffType_WeaponBreak:		//"破坏武器"
	case BuffType_ArmorBreak:		//"破甲"
	case BuffType_Kilgician:		//"不可使用的技能"
	case BuffType_BoneBreak:		//"解除武器"
	case BuffType_Tranquil:			//"平静"
	case BuffType_BrainShock:		//"惊人智慧"
	//case BuffType_Tired:			
	case BuffType_InsertCoal:		//"炸弹镶嵌"
	case BuffType_SignTarget:		//"弱点侦测"
	case BuffType_DelayAttack:		//"内伤"
	case BuffType_RedPowder:		//"红色粉末"
	case BuffType_WeaveIllusion:	//"幻影"
	case BuffType_DpBreak:			//"防御力下降"
	case BuffType_Taunt:			//"辱骂"
	//case BuffType_Battle:			//"战争状态"
	case BuffType_LimitHpRecovery:	//"无法恢复HP"
	case BuffType_CurseProperty:	//"咒道具术"
	case BuffType_Fire:				//"火焰伤害"
	case BuffType_DeathHealing:		//"死亡治愈"
	//case BuffType_Vertigo:
	//case BuffType_VitalAttack:	//"致命攻击"
	//case BuffType_PSWLimit:
		if (this->m_wSkillId != 0xFFFF) {
			return true;
		}
	}

	return false;
}