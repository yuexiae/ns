#include "server/server_pch.h"

#include "server/ext/ns_pc_ext.h"
#include "server/helper/ns_option.h"
#include <msgpack.hpp>

void CNSPcExt::SetDefaultQuickBar(unsigned char region, unsigned char job) {

    memset(this->m_dwQuickBarArray, 0, sizeof(this->m_dwQuickBarArray));
    if (region) {
        if (region == 1) {
            //this->m_dwQuickBarArray[1] = 0x20F01;
            //this->m_dwQuickBarArray[2] = 0x20F02;
            this->m_dwQuickBarArray[7] = 0x2F082;
            this->m_dwQuickBarArray[8] = 0x2F083;
            this->m_dwQuickBarArray[9] = 0x2F085;
        } else if (region == 2) {
            this->m_dwQuickBarArray[7] = 0x2F082;
            this->m_dwQuickBarArray[8] = 0x2F083;
            this->m_dwQuickBarArray[9] = 0x2F085;
        }

        switch (job) {
        case 1:
            this->m_dwQuickBarArray[0] = 0x20101;
            break;
        case 33:
            if (region == 1) {
                this->m_dwQuickBarArray[0] = 0x20410;
            } else if (region == 2) {
                this->m_dwQuickBarArray[0] = 0x20401;
            }
            break;
        case 65:
        case 67:
            this->m_dwQuickBarArray[0] = 0x20301;
            this->m_dwQuickBarArray[0] = 0x20301;
            break;
        default:
            break;
        }
    }
}

void CNSPcExt::SummonLoad() {
    if (this->m_SummonState.size() == 0) {
        return;
    }

    try {
        msgpack::unpacked result;
        msgpack::unpack(result, this->m_SummonState.data(), this->m_SummonState.size());
        msgpack::object obj(result.get());
        if (obj.type != MSGPACK_OBJECT_ARRAY || obj.via.array.size != 10) {
            return;
        }

        unsigned short wNpcId = obj.via.array.ptr[0].as<uint16_t>();
        unsigned short m_wSkillId = obj.via.array.ptr[1].as<uint16_t>();
        unsigned char btLevel = obj.via.array.ptr[2].as<uint8_t>();
        unsigned short wDuration = obj.via.array.ptr[3].as<uint16_t>();
        unsigned short m_wHp = obj.via.array.ptr[4].as<uint16_t>();
        unsigned short m_wSta = obj.via.array.ptr[5].as<uint16_t>();
        unsigned short m_wTendmeleeSkillId = obj.via.array.ptr[6].as<uint16_t>();
        unsigned char btTendmeleeLevel = obj.via.array.ptr[7].as<uint8_t>();
        unsigned short m_wTendrangeSkillId = obj.via.array.ptr[8].as<uint16_t>();
        unsigned char btTendrangeLevel = obj.via.array.ptr[9].as<uint8_t>();

        unsigned dwTime = timeGetTime();

        CNSNpc *pNpc = CNSNpcParams::GetInstance()->GetObjectA(wNpcId);
        if (pNpc) {
            NSPOINT2 cell;
            this->GetMap()->GetFreePos2(this->m_cell, (this->m_wAngle + 320) % 360, pNpc->m_btSize, 0xAu, cell);

            CNSNpc *pSummonNpc = this->PetAdd(CNSPc::PetType_Summon, wNpcId, cell, m_wSkillId, btLevel, wDuration, dwTime, 0, 0, 0, 0);
            if (pSummonNpc) {
                pSummonNpc->Reset(1);
                pSummonNpc->m_fHp = m_wHp;
                pSummonNpc->m_fSta = m_wSta;

                if (m_wTendmeleeSkillId) {
                    pSummonNpc->m_BuffList.Add( this->m_dwObjectId, CNSBuff::BuffType_TendMelee, m_wTendmeleeSkillId, btTendmeleeLevel, 0, wDuration, dwTime, 0);
                }

                if (m_wTendrangeSkillId) {
                    pSummonNpc->m_BuffList.Add( this->m_dwObjectId, CNSBuff::BuffType_TendRange, m_wTendrangeSkillId, btTendrangeLevel, 0, wDuration, dwTime, 0);
                }

                pSummonNpc->SendEnterMessage(1);
                this->SendPetEnterMessage(pSummonNpc->m_dwObjectId);
            }
        }
    } catch (msgpack::type_error& e) {
        LOGERROR("convert error '%s' alias seq:%d", e.what(), this->m_nAliasSeq);
    }

    this->m_SummonState.clear();
}


void CNSPcExt::ResetNew(int bFullReset) {
    unsigned long dwAvrGrade = 0;
    unsigned long dwGrade = 0;
    BOOL bPswBuff = FALSE;
    CNSItem *pItemEquip[CNSEquipment::EquipType_End];
    memset(pItemEquip, 0, sizeof(pItemEquip));

    unsigned short wSiegeSkillId = this->m_BuffList.GetBuffSkillId(CNSBuff::BuffType_SiegeWeapon);
    if (!wSiegeSkillId) {
        wSiegeSkillId = this->m_BuffList.GetBuffSkillId(CNSBuff::BuffType_PersonalSiegeWeapon);
        if (wSiegeSkillId) {
            bPswBuff = TRUE;
        }
    }

    if (!wSiegeSkillId || this->ResetSiegeWeapon(bFullReset, wSiegeSkillId, bPswBuff) != TRUE) {
        this->m_btSize = 5;
        this->m_wSight = 100;
        this->m_btMoveSpeed = 50;
        CNSCharacter::Reset();

        if (this->m_SkillList.GetSkillLevel(0xF223u)) {
            this->m_btMoveSpeed = static_cast<unsigned char>(floor(this->m_btMoveSpeed * 1.15));
        }

        unsigned char m_btBasicMoveSpeed = this->m_btMoveSpeed;
        this->m_wAttackMinDamage = 0;
        this->m_wAttackMaxDamage = 0;
        this->m_btAttackSpeed = 15;
        this->m_wAttackDistance = 10;
        this->m_wDefenseDamage = 0;
        this->m_wNsTank = 0;

        CNSItem *pItemLeftHand = NULL;
        int nValueLeft = 0;


        this->m_SetItemList.Clear();

        for (int i = 1; i < CNSEquipment::EquipType_End; ++i){
            CNSItem *pItem = this->m_Equip.Get((CNSEquipment::EQUIPMENTTYPE)i);
            if (pItem) {
                if (pItem->GetPremiumAbleDays()){
                    if (pItem->GetPremiumAbleMinutes()) {
                        if (this->m_btRank >= pItem->GetOptionValue(CNSItem::OptionType_Rank) && pItem->GetRare() != CNSItem::RareType_Costume) {
                            pItemEquip[i] = pItem;
                            if (pItem->GetOptionValue(CNSItem::OptionType_Set)) {
                                this->m_SetItemList.AddSet(pItem->GetOptionValue(CNSItem::OptionType_Set), pItem->GetItemId());
                            }
                            if (i != CNSEquipment::EquipType_LeftHand && i != CNSEquipment::EquipType_RightHand) {
                                dwGrade += pItem->GetGrade();
                            }
                        }
                    }
                }
            }
        }

        if (dwGrade) {
            if (CNSPc::GetSimpleJob(this->m_btJob) == JobType_Magician) {
                dwGrade = static_cast<unsigned long>(dwGrade * 1.25);
            }
            dwAvrGrade = dwGrade / 5;
        }

        for (int i = 1; i < CNSEquipment::EquipType_End; ++i) {
            CNSItem *pItema = pItemEquip[i];
            if (pItema) {
                if (i == CNSEquipment::EquipType_LeftHand && pItema->m_wAttackMaxDamage) {
                    pItemLeftHand = pItemEquip[i];
                    nValueLeft = pItema->GetGradeValue();
                }

                int nValue = pItema->GetGradeValue();
                if (i == CNSEquipment::EquipType_RightHand) {
                    if (pItemLeftHand) {
                        this->m_wAttackMinDamage += static_cast<unsigned short>(floor(((nValueLeft + nValue + pItemLeftHand->m_wAttackMinDamage + pItema->m_wAttackMinDamage) >> 1) * 1.5));
                        this->m_wAttackMaxDamage += static_cast<unsigned short>(floor(((nValueLeft + nValue + pItemLeftHand->m_wAttackMaxDamage + pItema->m_wAttackMaxDamage) >> 1) * 1.5));
                        this->m_btAttackSpeed = (pItema->m_btAttackSpeed + pItemLeftHand->m_btAttackSpeed) >> 1;
                        this->m_wAttackDistance = (pItema->m_btAttackDistance + pItemLeftHand->m_btAttackDistance) >> 1;
                    }  else {
                        if (pItema->GetItemType() == CNSItem::ItemType_TwoHanded_Staff) {
                            this->m_wWpMa += nValue + pItema->m_wAttackMaxDamage;
                        } else {
                            this->m_wAttackMinDamage += nValue + pItema->m_wAttackMinDamage;
                            this->m_wAttackMaxDamage += nValue + pItema->m_wAttackMaxDamage;
                        }
                        this->m_btAttackSpeed = pItema->m_btAttackSpeed;
                        this->m_wAttackDistance = pItema->m_btAttackDistance;
                    }
                }
                if (pItema->m_btDefenseDamage) {
                    this->m_wDefenseDamage += nValue + pItema->m_btDefenseDamage;
                }
                pItema->CalcOption(this);
            }
        }

        for (int i = 0; i < 5; ++i) {
            if ( this->m_SetItemList.m_SetItemArray[i].wSetId && this->m_SetItemList.m_SetItemArray[i].pItem) {
                this->m_SetItemList.m_SetItemArray[i].pItem->CalcOption(this);
            }
        }

        this->m_BuffList.CalcBuff(this);
        this->m_TitleList.CalcOption();
        this->CalcOptionNew(kResetBase);

        if (this->m_SkillList.GetSkillLevel(0xF244u) > 0
            && (this->m_BuffList.IsEnable(CNSBuff::BuffType_Rider)
            || this->m_BuffList.IsEnable(CNSBuff::BuffType_SiegeWeapon))) {
                NS::SafeValue(this->m_btMoveSpeed, (float)(this->m_btMoveSpeed * 1.1));
        }

        this->m_wRs = static_cast<unsigned short>(floor(this->m_btInt * 1.2));

        if (3 * m_btBasicMoveSpeed < this->m_btMoveSpeed) {
            this->m_btMoveSpeed = 3 * m_btBasicMoveSpeed;
        }

        CNSCharacter::Reset2();
        for (int i = 1; i < CNSEquipment::EquipType_End; ++i) {
            CNSItem *pItemb = pItemEquip[i];
            if (pItemb) {
                pItemb->CalcOption2(this);
            }
        }

        if (this->m_SkillList.GetSkillLevel(0xF214u) > 0) {
            NS::SafeValue(this->m_btAttackSpeed, this->m_btAttackSpeed - this->m_btAttackSpeed * 0.2f);
        }

        for (int i = 0; i < 5; ++i ){
            if (this->m_SetItemList.m_SetItemArray[i].wSetId && this->m_SetItemList.m_SetItemArray[i].pItem) {
                this->m_SetItemList.m_SetItemArray[i].pItem->CalcOption2(this);
            }
        }

        this->m_BuffList.CalcBuff2(this);
        this->m_TitleList.CalcOption2();
        this->CalcOptionNew(kResetParam);

        CNSBuff *pBuff = this->m_BuffList.GetBuff(CNSBuff::BuffType_MaxHpExpand);
        if (pBuff) {
            this->m_dwMaxHp += pBuff->GetLevel() * pBuff->GetValue();
        }

        CNSCharacter::Reset3(bFullReset);
        for (int i = 1; i < CNSEquipment::EquipType_End; ++i) {
            CNSItem *pItemc = pItemEquip[i];
            if (pItemc) {
                pItemc->CalcOption3(this);
            }
        }

        for (int i = 0; i < 5; ++i) {
            if (this->m_SetItemList.m_SetItemArray[i].wSetId && this->m_SetItemList.m_SetItemArray[i].pItem) {
                this->m_SetItemList.m_SetItemArray[i].pItem->CalcOption3(this);
            }
        }

        this->m_TitleList.CalcOption3();
        this->CalcOptionNew(kResetRegen);

        if (this->m_SkillList.GetSkillLevel(0xF264u) > 0 ) {
            this->m_wNsTank = static_cast<unsigned short>(floor(this->m_wNsTank * 1.1));
        }

        unsigned char btSkillLevel = this->m_SkillList.GetSkillLevel(0xB201u);
        if (btSkillLevel > 0) {
            CNSItem *pItemd = this->m_Equip.Get(CNSEquipment::EquipType_RightHand);
            if (pItemd) {
                if (pItemd->GetItemType() == CNSItem::ItemType_Sword || pItemd->GetItemType() == CNSItem::ItemType_TwoHanded_Sword)
                {
                    this->m_wAttackMinDamage = static_cast<unsigned short>(floor((btSkillLevel * 0.05 + 1.0) * this->m_wAttackMinDamage));
                    this->m_wAttackMaxDamage = static_cast<unsigned short>(floor((btSkillLevel * 0.05 + 1.0) * this->m_wAttackMaxDamage));
                }
            }
        }

        unsigned char btSkillLevela = this->m_SkillList.GetSkillLevel(0xB202u);
        if (btSkillLevela > 0) {
            CNSItem *pIteme = this->m_Equip.Get(CNSEquipment::EquipType_RightHand);
            if (pIteme) {
                if (pIteme->GetItemType() == CNSItem::ItemType_Blunt || pIteme->GetItemType() == CNSItem::ItemType_TwoHanded_Blunt) {
                    this->m_wAttackMinDamage = static_cast<unsigned short>(floor((btSkillLevela * 0.05 + 1.0) * this->m_wAttackMinDamage));
                    this->m_wAttackMaxDamage = static_cast<unsigned short>(floor((btSkillLevela * 0.05 + 1.0) * this->m_wAttackMaxDamage));
                }
            }
        }

        unsigned char btSkillLevelb = this->m_SkillList.GetSkillLevel(0xB203u);
        if (btSkillLevelb > 0) {
            CNSItem *pItemf = this->m_Equip.Get(CNSEquipment::EquipType_RightHand);
            if (pItemf) 
                if (pItemf->GetItemType() == CNSItem::ItemType_TwoHanded_Staff) {
                    this->m_wWpMa = static_cast<unsigned short>(floor((btSkillLevelb * 0.05 + 1.0) * this->m_wWpMa));
                }
        }

        unsigned char btSkillLevelc = this->m_SkillList.GetSkillLevel(0xB204u);
        if (btSkillLevelc > 0){
            CNSItem *pItemg = this->m_Equip.Get(CNSEquipment::EquipType_RightHand);
            if (pItemg) {
                if (pItemg->GetItemType() == CNSItem::ItemType_TwoHanded_Spear){
                    this->m_wAttackMinDamage = static_cast<unsigned short>(floor((btSkillLevelc * 0.05 + 1.0) * this->m_wAttackMinDamage));
                    this->m_wAttackMaxDamage = static_cast<unsigned short>(floor((btSkillLevelc * 0.05 + 1.0) * this->m_wAttackMaxDamage));
                }
            }
        }

        unsigned char btSkillLeveld = this->m_SkillList.GetSkillLevel(0xB205u);
        if (btSkillLeveld > 0 ) {
            CNSItem *pItemh = this->m_Equip.Get(CNSEquipment::EquipType_RightHand);
            if (pItemh) {
                if (pItemh->GetItemType() == CNSItem::ItemType_TwoHanded_Bow) {
                    this->m_wAttackMinDamage = static_cast<unsigned short>(floor((btSkillLeveld * 0.05 + 1.0) * this->m_wAttackMinDamage));
                    this->m_wAttackMaxDamage = static_cast<unsigned short>(floor((btSkillLeveld * 0.05 + 1.0) * this->m_wAttackMaxDamage));
                }
            }
        }

        unsigned char btSkillLevele = this->m_SkillList.GetSkillLevel(0xB206u);
        if (btSkillLevele > 0) {
            CNSItem *pItemi = this->m_Equip.Get(CNSEquipment::EquipType_RightHand);
            if (pItemi) {
                if (pItemi->GetItemType() == CNSItem::ItemType_TwoHanded_Gun) {
                    this->m_wAttackMinDamage = static_cast<unsigned short>(floor((btSkillLevele * 0.05 + 1.0) * this->m_wAttackMinDamage));
                    this->m_wAttackMaxDamage = static_cast<unsigned short>(floor((btSkillLevele * 0.05 + 1.0) * this->m_wAttackMaxDamage));
                }
            }
        }

        if (dwAvrGrade) {
            this->m_btDpPer = static_cast<unsigned char>(this->m_btDpPer / 2.0  + (this->m_btDpPer * (dwAvrGrade / 20.0)));
        } else {
            this->m_btDpPer = static_cast<unsigned char>(floor(this->m_btDpPer / 2.0));
        }
    }
}

void CNSPcExt::CalcOptionNew(ResetType type) {
    if (this->m_SkillList.Get(0xF01)) {
        CalcOption(NSOption::m_Mythic[this->GetDefaultLimitSkillLevel() - 1], type);
    }
}


void CNSPcExt::CalcOption(const CNSItem::Option option[10], ResetType type) {
    switch (type) {
    case kResetBase: {
        for (int i = 0; i < 10 && option[i].btParam; ++i) {
            switch (option[i].btParam) {
            case CNSItem::OptionType_Str:
                NS::SafeValue(this->m_btStr, option[i].wValue + this->m_btStr);
                break;
            case CNSItem::OptionType_Con:
                NS::SafeValue(this->m_btCon, option[i].wValue + this->m_btCon);
                break;
            case CNSItem::OptionType_Dex:
                NS::SafeValue(this->m_btDex, option[i].wValue + this->m_btDex);
                break;
            case CNSItem::OptionType_Int:
                NS::SafeValue(this->m_btInt, option[i].wValue + this->m_btInt);
                break;
            case CNSItem::OptionType_NsTank:
                this->IsPcClass() ? NS::SafeValue(this->m_wNsTank, option[i].wValue + this->m_wNsTank) : void(0);
                break;
            case CNSItem::OptionType_MoveSpeed:
                NS::SafeValue(this->m_btMoveSpeed, static_cast<float>(this->m_btMoveSpeed + this->m_btMoveSpeed * (option[i].wValue / 100.0)));
                break;
            }
        }
    }
    break;
    case kResetParam: {
        for (int i = 0; i < 10 && option[i].btParam; ++i) {
            switch (option[i].btParam) {
            case CNSItem::OptionType_Rs:
				NS::SafeValue(this->m_wRs, option[i].wValue + this->m_wRs);
				break;
			case CNSItem::OptionType_Hp:
				this->m_dwMaxHp += option[i].wValue;
				break;
			case CNSItem::OptionType_Mp:
				NS::SafeValue(this->m_wMaxMp, option[i].wValue + this->m_wMaxMp);
				break;
			case CNSItem::OptionType_Sta:
				NS::SafeValue(this->m_wMaxSta, option[i].wValue + this->m_wMaxSta);
				break;
			case CNSItem::OptionType_Ma:
				NS::SafeValue(this->m_wWpMa, option[i].wValue + this->m_wWpMa);
				break;
			case CNSItem::OptionType_Dp:
				NS::SafeValue(this->m_wDp, option[i].wValue + this->m_wDp);
				break;
			case CNSItem::OptionType_Ap:
				NS::SafeValue(this->m_wAp, option[i].wValue + this->m_wAp);
				break;
			case CNSItem::OptionType_AttackSpeed:
                !this->m_SkillList.GetSkillLevel(0xF214u) ? NS::SafeValue(this->m_btAttackSpeed, static_cast<float>(this->m_btAttackSpeed - this->m_btAttackSpeed * (option[i].wValue / 100.0))) : void(0);
				break;
			case CNSItem::OptionType_DpPer:
				NS::SafeValue(this->m_btDpPer, (float)option[i].wValue + this->m_btDpPer);
				break;
			}
		}
	}
    break;
	case kResetRegen: {
		for (int i = 0; i < 10 && option[i].btParam; ++i) {
			switch (option[i].btParam) {
			case CNSItem::OptionType_HpRegen:
				this->m_fHpRegen = float(this->m_dwMaxHp / 100.0 * (option[i].wValue / 100.0) + this->m_fHpRegen);
				break;
			case CNSItem::OptionType_MpRegen:
				this->m_fMpRegen = float(this->m_fMpRegen + (float)this->m_wMaxMp / 100.0 * (option[i].wValue / 100.0));
				break;
			case CNSItem::OptionType_StaRegen:
				this->m_fStaRegen = float(this->m_fStaRegen + this->m_wMaxSta / 100.0 * (option[i].wValue / 100.0));
				break;
			}
		}
	}
			break;
	}
}
