#include "server/server_pch.h"

#include "server/ext/ns_ext.h"


class CNSSkillParamsFilter : public CNSSkillParams {
public:
	BOOL LoadFilter() {
		COdbcBindColumn odbc(CNSDbManager::GetInstance()->GetDb());

        CNSSkill *skill = CNSSkillExt::New();

		try {
			long len;

			char skill_name[0x100] = { 0 };
			char skill_type[2][256] = { 0 };
			char skill_option[2][256] = { 0 };
			char range_type[256] = { 0 };
			char comment[0x400] = { 0 };

			odbc.BindUSmallInt(&skill->m_wSkillId, &len);
			odbc.BindTinyInt(&skill->m_btLimitJob, &len);
			odbc.BindString(skill_name, 0x100, &len);
			odbc.BindTinyInt(&skill->m_btUseSkillPoint, &len);
			odbc.BindTinyInt(&skill->m_btUseSkillPoint2, &len);
			odbc.BindTinyInt(&skill->m_btLimitLevel, &len);
			odbc.BindTinyInt(&skill->m_btUseKind, &len);
			odbc.BindUSmallInt(&skill->m_wUsePoint, &len);
			odbc.BindString(skill_type[0], 256, &len);
			odbc.BindString(skill_option[0], 256, &len);
			odbc.BindUSmallInt(&skill->m_wSkillValue[0], &len);
			odbc.BindString(skill_type[1], 256, &len);
			odbc.BindString(skill_option[1], 256, &len);
			odbc.BindUSmallInt(&skill->m_wSkillValue[1], &len);
			odbc.BindString(&range_type, 256, &len);
			odbc.BindUSmallInt(&skill->m_wRangeValue, &len);
			odbc.BindTinyInt(&skill->m_btCastTime, &len);
			odbc.BindUSmallInt(&skill->m_wCoolTime, &len);
			odbc.BindTinyInt(&skill->m_btAttackSpeed, &len);
			odbc.BindUSmallInt(&skill->m_wDurationTimeSeed, &len);
			odbc.BindUSmallInt(&skill->m_wDurationTime, &len);
			odbc.BindString(comment, 0x400, &len);

			odbc.Execute("SELECT [SkillId],[Job],[SkillName],[SkillPoint],[SkillPoint2],[LimitLevel],[UseKind],[UsePoint],"\
				"[SkillType1],[SkillOption1],[SkillValue1],[SkillType2],[SkillOption2],[SkillValue2],[RangeType],[RangeValue],"\
				"[CastTime],[CoolTime],[AttackSpeed],[DurationTimeSeed],[DurationTime],[Comment]  FROM [SkillParams] ORDER BY [SkillId] ASC");

			while (odbc.Fetch()) {
				skill->m_szSkillName = _strdup(skill_name);

				skill->m_btSkillType[0] = this->ConvertSkillTypeString(skill_type[0]);
				skill->m_btSkillType[1] = this->ConvertSkillTypeString(skill_type[1]);

				skill->m_btSkillOption[0] = this->ConvertSkillOptionString(skill_option[0]);
				skill->m_btSkillOption[1] = this->ConvertSkillOptionString(skill_option[1]);

				skill->m_btRangeType = this->ConvertRangeTypeString(range_type);

				skill->m_szComment = _strdup(ConvertCommentString(comment));

                CNSSkill *new_skill = CNSSkillExt::New();
			    *new_skill = *skill;
				this->m_mapSkill.insert(std::make_pair(new_skill->m_wSkillId | (new_skill->m_btLimitJob << 16), new_skill));
			}

			GameUtil::Output("SkillParams Total = %d", this->m_mapSkill.size());
            delete skill;
			return TRUE;
		} catch (SteamEngine::Win32::System::CException& e) {
			LOGERROR("sqlexec error(%s)", e.GetMessageA());
		}

        delete skill;
		return FALSE;
	}

    const char * ConvertCommentString(char *str) {
        char *p = str;
        if (*p++ != '\0') {
            while (*p++) {
                if (*(p - 1) == '\\' && *p == 'n') {
                    *(p - 1) = '\r';
                    *p = '\n';
                }
            }
        }
        return str;
    }
};



bool CNSSkillParamsFilterInit() {
	return CNSSkillParams::_PatchLoad(&CNSSkillParamsFilter::LoadFilter);
}