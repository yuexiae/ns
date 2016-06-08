#ifndef SREVER_GAME_CONFIG_H_
#define SREVER_GAME_CONFIG_H_

#include "base/singleton.h"


class GameConfig : public base::Singleton<GameConfig> {
public:
	GameConfig();

	void ReadConfig(const char *filepath);

	inline int GetCheckSyncPos() { return check_sync_pos_; }

	inline bool IsLoadNpcData() { return is_load_npc_data_; }

	inline unsigned int GetPcManagerSleepTime() { return pcmanager_sleep_time_; }

private:
	int check_sync_pos_;
	bool is_load_npc_data_;
	unsigned int pcmanager_sleep_time_;
};






#endif