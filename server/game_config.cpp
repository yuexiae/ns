#include "server/server_pch.h"

#include "server/game_config.h"
#include "server/game_util.h"

#define APP_NAME	"Config"

GameConfig::GameConfig() {
	check_sync_pos_ = 400;
	is_load_npc_data_ = true;
	pcmanager_sleep_time_ = 0;
}

void GameConfig::ReadConfig(const char *filepath) {
	check_sync_pos_ = ::GetPrivateProfileIntA(APP_NAME, "CheckSyncPos", 400, filepath);
	LOGINFO("[Config]CheckSyncPos:%d", check_sync_pos_);

	is_load_npc_data_ = 1 == ::GetPrivateProfileIntA(APP_NAME, "LoadNpcData", 1, filepath);
	LOGINFO("[Config]Load Npc Data:%s", is_load_npc_data_ ? "true" : "false");

	pcmanager_sleep_time_ = ::GetPrivateProfileIntA(APP_NAME, "PcManagerSleepTime", 0, filepath);
	LOGINFO("[Config]PcManager sleep time:%d", pcmanager_sleep_time_);
}



