#include "server/server_pch.h"

#include "server/application.h"
#include "server/ext/ns_ext.h"
#include "server/game_util.h"
#include "server/game_config.h"
#include "base/logging.h"
#include "base/string_split.h"
#include "base/hook_util.h"
#include "base/socket_ptr.h"
#include "server/filter/filter_init.h"
#include "server/db/game_db.h"
#include "server/db/auth_db.h"
#include "server/db/log_db.h"
#include "server/helper/ns_option.h"

/*plan
1.exchange and warehouse bug chek
3.add quit button to alias select screen
5.equipment move bug?
*/

#define FILTER_INIT(name) if (name() == false) { \
		GameUtil::Output("%s init failure", #name);getchar(); \
	} else { \
		GameUtil::Output("%s init", #name); \
	}


#define CLASS_INIT(class) if (class::Initialize() == false) { \
		GameUtil::Output("%s init failure", #class);getchar(); \
	} else { \
		GameUtil::Output("%s init", #class); \
	}



static void LogHandler(base::Logging::LogLevel severity, const char *message) {
    GameUtil::Output(message);
    if (severity == base::Logging::kLogFatal) {
        getchar();
		exit(0);
    }
}

void Application::Initialize() {
    base::SocketPtr::SocketInit();

	base::StringSplit command(2, GetCommandLineA(), " ");
	if (command.Count() != 2) {
		LOGFATAL("application param error");
	}

	char log_filename[MAX_PATH];
	sprintf(log_filename, ".\\gamelog_%s.txt", command.GetString(1));

	base::Logging *logger = base::Logging::DefualtLogging();
	logger->ConfigFilename(log_filename);
	logger->ConfigHandler(LogHandler);

	GameConfig::GetSingleton()->ReadConfig(".\\nsdll.ini");

	ModifyConfigFile(command.GetString(1));
	ModifyLoginKey();
	ModifyConnectString();
    NSOption::Init();

	NSStructCheck::Check();
	FILTER_INIT(CPacketFilterInit);
	FILTER_INIT(NSSessionPcProcessFilterInit);
	FILTER_INIT(CNSSessionPcFilterInit);
	FILTER_INIT(CNSDbManagerFilterInit);
	FILTER_INIT(CNSPcFilterInit);
    FILTER_INIT(CNSQuestParamsFilterInit);
	FILTER_INIT(CNSCriticalSectionFilterInit);
	FILTER_INIT(CNSWorldManagerFilterInit);
	FILTER_INIT(CNSNpcManagerFilterInit);
	FILTER_INIT(CNSSkillParamsFilterInit);
    FILTER_INIT(CNSAuctionFilterInit);
    FILTER_INIT(CNSMsgParamsFilterInit);
    FILTER_INIT(CNSPcManagerFilterInit);
    FILTER_INIT(CNSDbLogManagerFilterInit);
    FILTER_INIT(CNSWareHouseFilterInit);
    FILTER_INIT(CNSGuildFilterInit);
    FILTER_INIT(CNSPcParamsFilterInit);
    FILTER_INIT(CNSPcTitleListFilterInit);
    FILTER_INIT(CNSNpcParamsFilterInit);
    FILTER_INIT(CNSNpcFilterInit);
    FILTER_INIT(CNSMapManagerFilterInit);
    FILTER_INIT(NSScriptFilterInit);
    FILTER_INIT(NSPublicFilterInit);
    FILTER_INIT(CNSVrBlockManagerFilterInit);
    FILTER_INIT(CNSCharacterFilterInit);
    FILTER_INIT(CNSSkillListFilterInit);
    FILTER_INIT(CIOCompletionWorkerFilterInit);
    FILTER_INIT(CSessionFilterInit);
    FILTER_INIT(CMsgCounterFilterInit);
    FILTER_INIT(CNSSkillFilterInit);
    FILTER_INIT(CNSNpcStateMoveFilterInit);
    FILTER_INIT(COutputFileFilterInit);
    FILTER_INIT(NSUtilityFilterInit);

    GameDb::GetSingleton()->SetThreadId();
    AuthDb::GetSingleton()->SetThreadId();
    LogDb::GetSingleton()->SetThreadId();

	if (!GameDb::GetSingleton()->Init("localhost", 6379, "REDISTESTPWD", 0)
		|| !GameDb::GetSingleton()->ScriptHashInit()) {
		LOGFATAL("GameDb Init failed");
	}

	if (!AuthDb::GetSingleton()->Init("localhost", 6379, "REDISTESTPWD", 2)
        || !AuthDb::GetSingleton()->ScriptHashInit()) {
		LOGFATAL("AuthDb Init failed");
    }

    if (!LogDb::GetSingleton()->Init("localhost", 6379, "REDISTESTPWD", 1)) {
        LOGFATAL("LogDb Init failed");
    }


	/*CLASS_INIT(NSSessionPcProcessFilterInit);
	CLASS_INIT(CPacketFilterInit);
	CLASS_INIT(CPacketFilter);
	CLASS_INIT(CNSMapManagerFilter);
	CLASS_INIT(CNSNpcParamsFilter);
	CLASS_INIT(CNSNpcFilter);
	CLASS_INIT(CNSMsgParamsFilter);
	CLASS_INIT(CNSSkillListFilter);
	CLASS_INIT(CNSPcFilter);
	CLASS_INIT(CNSCharacterFilter);
	CLASS_INIT(NSScriptFilter);
	CLASS_INIT(CNSSessionPcFilter);
	CLASS_INIT(CNSBuffListFilter);
	CLASS_INIT(CNSSkillFilter);
	CLASS_INIT(CNSBuffFilter);
	CLASS_INIT(CNSNpcStateMoveFilter);
	CLASS_INIT(CNSItemFilter);
	CLASS_INIT(CMsgCounterFilter);
	CLASS_INIT(CNSPcManagerFilter);
	CLASS_INIT(CNSSkillParamsFiletr);
	CLASS_INIT(CNSDbManagerFilter);
	CLASS_INIT(CNSDbLogManagerFilter);
	CLASS_INIT(COdbcFilter);
	CLASS_INIT(CNSQuestParamsFilter);
	CLASS_INIT(CNSCriticalSectionFilter);
	CLASS_INIT(CNSPcStateAttackFilter);
	CLASS_INIT(CNSWorldManagerFilter);
	CLASS_INIT(CNSPcTitleListFilter);
	CLASS_INIT(CNSGuildFilter);
	CLASS_INIT(CNSPcParamsFilter);
	CLASS_INIT(CNSWareHouseFilter);
	CLASS_INIT(CNSPcPremiumUseListFilter);
	CLASS_INIT(CNSAuctionFilter);
	CLASS_INIT(CNSNpcManagerFilter);
	CLASS_INIT(CNSNpcSkillFilter);*/
}

void Application::OnMain() {
}

void Application::OnServerMain() {
    CNSDbManager::GetInstance()->GetDb()->Close();
	CNSDbLogManager::GetInstance()->GetDb()->Close();
    FILTER_INIT(COdbcFilterInit);
    CNSDbManagerExt::m_WaitableEvent.Signal();
}

bool Application::ModifyConfigFile(const char *region) {
#define CONFIG_PATH_MAX_LENGTH	0x13

	static unsigned long profile_offset[] = { 0x0050008C, 0x004FFE60, 0x004FFE30, 0x0050035C, 0x004FFF20, 0x004FFE90,
		0x004FFF50, 0x004FFF84, 0x004FFDEC, 0x004FFDC4, 0x004FFD9C, 0x004FFEC0, 0x004FFD70, 0x004FFFB0, 0x004FFFD8,
		0x005000E0, 0x00500004, 0x005000B8, 0x00500038, 0x00500064,
		0x004FFEF0, 0x0050037C };

	char config_name[MAX_PATH];
	sprintf(config_name, ".\\NSGS_%s.ini", region);

	if (strlen(config_name) > CONFIG_PATH_MAX_LENGTH) {
		GameUtil::Output("too long config filename(%s)", config_name);
		getchar();
		exit(0);
	}

	for (int i = 0; i < sizeof(profile_offset) / sizeof(unsigned long); ++i) {
		strcpy((char *)profile_offset[i], config_name);
	}

	GameUtil::Output("modify_config_file(%s) ok", config_name);

	return true;
}

bool Application::ModifyLoginKey() {
	//modify check & login key
#define A_CHECK_KEY_OFFSET	0x005269B0
#define A_LOGIN_KEY_OFFSET	0x0052699C

#define CHECK_KEY			"kld9newnew"
#define	LOGIN_KEY			"d30939d239snewnew"


	base::HookUtil::PatchBytes(A_CHECK_KEY_OFFSET, CHECK_KEY, strlen(CHECK_KEY));
	base::HookUtil::PatchBytes(A_LOGIN_KEY_OFFSET, LOGIN_KEY, strlen(LOGIN_KEY));

	GameUtil::Output("modify check & login key ok");
	return true;
}

bool Application::ModifyConnectString() {


#define A_PUSH_CONNECTSTRING (0x0040EA23 + 1)

	const static char *connection_string_format = "DRIVER={SQL Server Native Client 11.0};"\
            "SERVER=(localdb)\\MSSQLLocalDB;"\
            "AttachDbFilename=D:\\workspace\\NS_TW\\gameserver\\data\\twmain.mdf;"\
            "Integrated Security=True;"\
            "ApplicationIntent=ReadOnly";

	base::HookUtil::PatchULong(A_PUSH_CONNECTSTRING, reinterpret_cast<unsigned long>(connection_string_format));

	GameUtil::Output("modify connect string ok");
	return true;
}