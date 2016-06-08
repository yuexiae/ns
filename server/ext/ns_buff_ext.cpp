#include "server/server_pch.h"

#include "server/ext/ns_buff_ext.h"



bool CNSBuffExt::IsCanSave() {
	switch (this->m_buffType) {
	case BuffType_Dp:			//"����������"
	case BuffType_Ap:			//"����������"
	case BuffType_Speed:		//"�ƶ��ٶ�����"
	case BuffType_MaxHp:		//"����ֵ����"
	case BuffType_Rs:			//"ħ������������"
	case BuffType_Ma:			//"ħ������������"
	case BuffType_Ar:			//"����������"
	//case BuffType_Glory:		//UNKNOW
	case BuffType_Berserker:	//"��"
	case BuffType_Dump:			//"��ʥ֮��"
	case BuffType_Thorn:		//"��������"
	case BuffType_LowCounter:	//"����"
	case BuffType_SaveExp:		//"��Ȼ�ػ�"
	case BuffType_Clarity:		//"Ǳ��"
	case BuffType_ClarityEx:	//"Ǳ��EX"
	//case BuffType_Pet:
	//case BuffType_Tame:
	//case BuffType_Summon:
	case BuffType_RangeBlock:	//"Զ�̹�������"
	case BuffType_FullSwine:	//"�����Ѿ�"
	//case BuffType_TendMelee:
	//case BuffType_TendRange:
	case BuffType_MythicBone:	//"��֮��"
	case BuffType_MythicOcean:	//"��֮��"
	case BuffType_MythicForce:	//"��֮��"
	case BuffType_HpDrain:		//"��������ֵ"
	case BuffType_Ac:			//"����������"
	case BuffType_WeaponStick:	//"�޷��������"
	//case BuffType_Transfer:
	//case BuffType_Rider:
	case BuffType_DwellDeity:	//"ս��֮��"
	case BuffType_DwellGoat:	//"ɽ��"
	case BuffType_BloodOcean:	//"��������"
	case BuffType_HolyDefense:	//"��֮����"
	//case BuffType_ImmunDebuff:
	case BuffType_FullBarrel:	//"����"
	//case BuffType_Inspiration://"���֮��"
	case BuffType_NeedleCounter://"�����ж���"
	case BuffType_NobleShield:	//"����ǿ��֮��"
	case BuffType_DwellHero:	//"������ǿ"
	case BuffType_ImmunSleep:	//"˯������"
	case BuffType_ImmunSlow:	//"��������"
	case BuffType_ImmunRoot:	//"��������"
	case BuffType_ImmunRage:	//"��������
	case BuffType_ImmunPoison:	//"�ж�����"
	case BuffType_ImmunStun:	//"ѣ������"
	case BuffType_AspecVolition://"�ػ�"	
	case BuffType_PowerStaff:	//"����֮��"
	case BuffType_MachineShield://"��е��"
	case BuffType_MachineProtecter://"��е����"
	//case BuffType_AutoSkill:
	//case BuffType_ExpUp:			//"����ֵ����"
	//case BuffType_ExpUpParty:		//"����ֵ����[����]"
	//case BuffType_MiningUp:		//"�ɿ�������"
	case BuffType_AmuletProperty:	//"������ӻ�"
	//case BuffType_InvenExpand:
	//case BuffType_WareHouseExpand:
	//case BuffType_ExpUpExpand:
	//case BuffType_SiegeWeapon:
	case BuffType_WpMa:				//"ħ��������"
	case BuffType_DpPerSkill:		//"�˺�����"
	//case BuffType_DpPerPremium:	//"�˺�����"
	case BuffType_Dr:				//"�����ɹ�������"
	case BuffType_DpBeast:			//"����������"
	case BuffType_ApBeast:			//"����������"
	case BuffType_Hidden:			//"˲����вֵ����"
	case BuffType_RsPer:			//"ħ������������"
	case BuffType_NSTank:			//"��������������������"
	case BuffType_SpeedBeast:		//"�ƶ��ٶ�����"
	//case BuffType_AutoMining:
	//case BuffType_TpUp:			//"������������"
	case BuffType_Dash:				//"˲���ƶ��ٶ�����" 
	//case BuffType_CrushDivision:	//"��ѹ�籩"
	//case BuffType_SummonMaster:	//"�����ٻ�"
	case BuffType_ProtectField:		//"���Է���"
	case BuffType_AbsolutPower:		//"��������"
	//case BuffType_MaxHpExpand:	//"ǿ��ҩˮ"
	//case BuffType_Reflection:		//UNKNOW
	//case BuffType_ExpUpShort:		//"�������"
	//case BuffType_ExpPenalty:		//"����ͷ�"
	//case BuffType_RearlandKill:
	//case BuffType_NoviceSheild:	//"���ֱ���"
	//case BuffType_OverlapExpUp1:	//"�ص���������1"
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
	case BuffType_ImmunPoisonEx:	//�ж�����Ex
	case BuffType_DutyFront:		//"���"
	case BuffType_MaxStaMp:			//"�����������ֵ����"
	case BuffType_NeoSteamShield:	//"��������"
	case BuffType_NeoSteamDecrease:	//"�������Ľ���"
	case BuffType_DevineShield:		//"��ʥ����"
	case BuffType_ImmunIncrease:	//"��������"
	case BuffType_RecoveryStun:		//"ѣ�λָ�"
	//case BuffType_ImmunDebuffPK:
	//case BuffType_ImmunDebuff3:
	return true;

	case BuffType_Poison:			//"�ж�"
	case BuffType_Slow:				//"����"
	case BuffType_Rage:				//"��"
	case BuffType_Root:				//"����"
	case BuffType_Stun:				//"ѣ��"
	case BuffType_Sleep:			//"˯��"
	case BuffType_Chaos:			//"������"
	case BuffType_Curse:			//"����"
	case BuffType_WeaponBreak:		//"�ƻ�����"
	case BuffType_ArmorBreak:		//"�Ƽ�"
	case BuffType_Kilgician:		//"����ʹ�õļ���"
	case BuffType_BoneBreak:		//"�������"
	case BuffType_Tranquil:			//"ƽ��"
	case BuffType_BrainShock:		//"�����ǻ�"
	//case BuffType_Tired:			
	case BuffType_InsertCoal:		//"ը����Ƕ"
	case BuffType_SignTarget:		//"�������"
	case BuffType_DelayAttack:		//"����"
	case BuffType_RedPowder:		//"��ɫ��ĩ"
	case BuffType_WeaveIllusion:	//"��Ӱ"
	case BuffType_DpBreak:			//"�������½�"
	case BuffType_Taunt:			//"����"
	//case BuffType_Battle:			//"ս��״̬"
	case BuffType_LimitHpRecovery:	//"�޷��ָ�HP"
	case BuffType_CurseProperty:	//"�������"
	case BuffType_Fire:				//"�����˺�"
	case BuffType_DeathHealing:		//"��������"
	//case BuffType_Vertigo:
	//case BuffType_VitalAttack:	//"��������"
	//case BuffType_PSWLimit:
		if (this->m_wSkillId != 0xFFFF) {
			return true;
		}
	}

	return false;
}