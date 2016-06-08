#ifndef SERVER_GAME_UTIL_H_
#define SERVER_GAME_UTIL_H_

#include <windows.h>
#include <mmsystem.h>
#include <sqltypes.h>
#include "base/logging.h"

class GameUtil {
public:
	static void Output(const char *fmt, ...);

	static void OutputDefault(const char *fmt, ...);

	static unsigned int ConvertTime(TIMESTAMP_STRUCT &timestamp);

	static void ConvertTime(TIMESTAMP_STRUCT &dest, __time32_t src);
};



#endif