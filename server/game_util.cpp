#include "server/server_pch.h"

#include "server/game_util.h"
#include <time.h>
#include <stdio.h>

void GameUtil::Output(const char *fmt, ...) {
	SYSTEMTIME systime;
	GetLocalTime(&systime);
	printf("%02u/%02u/%02u %02u:%02u:%02u:%03u ",
		systime.wYear % 100,
		systime.wMonth,
		systime.wDay,
		systime.wHour,
		systime.wMinute,
		systime.wSecond,
		systime.wMilliseconds);

	va_list	ap;
	va_start(ap, fmt);

	char buffer[1024];
	vsnprintf(buffer, sizeof(buffer), fmt, ap);

	HANDLE consoleHwnd;
	consoleHwnd = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO ci;
	if (GetConsoleScreenBufferInfo(consoleHwnd, &ci)) {
		SetConsoleTextAttribute(consoleHwnd, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		printf("%s\n", buffer);
		SetConsoleTextAttribute(consoleHwnd, ci.wAttributes);
	} else {
		printf("%s\n", buffer);
	}

	va_end(ap);
}


void GameUtil::OutputDefault(const char *fmt, ...) {
	SYSTEMTIME systime;
	GetLocalTime(&systime);
	printf("%02u/%02u/%02u %02u:%02u:%02u:%03u ",
		systime.wYear % 100,
		systime.wMonth,
		systime.wDay,
		systime.wHour,
		systime.wMinute,
		systime.wSecond,
		systime.wMilliseconds);

	va_list	ap;
	va_start(ap, fmt);

	char buffer[1024];
	vsnprintf(buffer, sizeof(buffer), fmt, ap);

	printf("%s\n", buffer);

	va_end(ap);

}

unsigned int GameUtil::ConvertTime(TIMESTAMP_STRUCT &timestamp) {
	tm tmnow;
	tmnow.tm_year = timestamp.year - 1900;
	tmnow.tm_mon = timestamp.month - 1;
	tmnow.tm_mday = timestamp.day;
	tmnow.tm_hour = timestamp.hour;
	tmnow.tm_min = timestamp.minute;
	tmnow.tm_sec = timestamp.second;
	return _mktime32(&tmnow);
}

void GameUtil::ConvertTime(TIMESTAMP_STRUCT &dest, __time32_t src) {
	tm rtm;
	_localtime32_s(&rtm, &src);

	dest.year		= rtm.tm_year + 1900;
	dest.month	= rtm.tm_mon + 1;
	dest.day		= rtm.tm_mday;
	dest.hour		= rtm.tm_hour;
	dest.minute	= rtm.tm_min;
	dest.second	= rtm.tm_sec;
	dest.fraction = 0;
}