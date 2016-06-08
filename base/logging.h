#ifndef BASE_LOGGING_H_
#define BASE_LOGGING_H_

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <stdarg.h>
#include "base/singleton.h"

#if _MSC_VER
#define snprintf _snprintf
#endif



#define LOG_IMPL(log, level, format, ...) \
	LOG_IS_ON((log), level) ? \
		base::Logging::LogHandle(log, level, __FUNCTION__, __LINE__, format, __VA_ARGS__) \
			: (void) 0

#define LOGVERBOSEP(log, format, ...) \
	LOG_IMPL(log, base::Logging::kLogVerbose, format, __VA_ARGS__)

#define LOGINFOP(log, format, ...) \
	LOG_IMPL(log, base::Logging::kLogInfo, format, __VA_ARGS__)

#define LOGWARNINGP(log, format, ...) \
	LOG_IMPL(log, base::Logging::kLogWarning, format, __VA_ARGS__)

#define LOGERRORP(log, format, ...) \
	LOG_IMPL(log, base::Logging::kLogError, format, __VA_ARGS__)

#define LOGFATALP(log, format, ...) \
	LOG_IMPL(log, base::Logging::kLogFatal, format, __VA_ARGS__)

#define LOGVERBOSE(format, ...) \
	LOG_IMPL(base::Logging::DefualtLogging(), base::Logging::kLogVerbose, format, __VA_ARGS__)

#define LOGINFO(format, ...) \
	LOG_IMPL(base::Logging::DefualtLogging(), base::Logging::kLogInfo, format, __VA_ARGS__)

#define LOGWARNING(format, ...) \
	LOG_IMPL(base::Logging::DefualtLogging(), base::Logging::kLogWarning, format, __VA_ARGS__)

#define LOGERROR(format, ...) \
	LOG_IMPL(base::Logging::DefualtLogging(), base::Logging::kLogError, format, __VA_ARGS__)

#define LOGFATAL(format, ...) \
	LOG_IMPL(base::Logging::DefualtLogging(), base::Logging::kLogFatal, format, __VA_ARGS__)



#ifdef _DEBUG
#define DLOGVERBOSEP(log, format, ...) \
	LOG_IMPL(log, base::Logging::kLogVerbose, format, __VA_ARGS__)

#define DLOGINFOP(log, format, ...) \
	LOG_IMPL(log, base::Logging::kLogInfo, format, __VA_ARGS__)

#define DLOGWARNINGP(log, format, ...) \
	LOG_IMPL(log, base::Logging::kLogWarning, format, __VA_ARGS__)

#define DLOGERRORP(log, format, ...) \
	LOG_IMPL(log, base::Logging::kLogError, format, __VA_ARGS__)

#define DLOGFATALP(log, format, ...) \
	LOG_IMPL(log, base::Logging::kLogFatal, format, __VA_ARGS__)

#define DLOGVERBOSE(format, ...) \
	LOG_IMPL(base::Logging::DefualtLogging(), base::Logging::kLogVerbose, format, __VA_ARGS__)

#define DLOGINFO(format, ...) \
	LOG_IMPL(base::Logging::DefualtLogging(), base::Logging::kLogInfo, format, __VA_ARGS__)

#define DLOGWARNING(format, ...) \
	LOG_IMPL(base::Logging::DefualtLogging(), base::Logging::kLogWarning, format, __VA_ARGS__)

#define DLOGERROR(format, ...) \
	LOG_IMPL(base::Logging::DefualtLogging(), base::Logging::kLogError, format, __VA_ARGS__)

#define DLOGFATAL(format, ...) \
	LOG_IMPL(base::Logging::DefualtLogging(), base::Logging::kLogFatal, format, __VA_ARGS__)
#else
#define DLOGVERBOSEP(log, format, ...)
#define DLOGINFOP(log, format, ...)
#define DLOGWARNINGP(log, format, ...)
#define DLOGERRORP(log, format, ...)
#define DLOGFATALP(log, format, ...)

#define DLOGVERBOSE(format, ...)
#define DLOGINFO(format, ...)
#define DLOGWARNING(format, ...)
#define DLOGERROR(format, ...)
#define DLOGFATAL(format, ...)
#endif

#define LOG_IS_ON(log, level) \
	 (level >= log->GetLevel())

#define LOG_MESSAGE_MAX_LEN		1024

#define LOGASSERT(exp) (!(exp)) ? LOGFATAL("assert failed:'%s'", "" # exp) : void (0)

namespace base {

class Logging
{
public:
	enum LogLevel
	{
		kLogVerbose = 0,
		kLogInfo,
		kLogWarning,
		kLogError,
		kLogFatal
	};

	typedef void (*LogMessageHandler)(LogLevel severity, const char *message);
	
	int GetLevel() { return level_; }

	void ConfigLevel(LogLevel level) { level_ = level; }

	void ConfigStderr() { destination_stderr = true; }

	void ConfigHandler(LogMessageHandler handler) { handler_ = handler; }

	void ConfigFilename(const char *filename) { filename_.assign(filename); }

	static void LogHandle(Logging *logging, LogLevel level, const char* function, int line,
		const char *format, ...) {

		static const char* log_severity_names[] = {
			"INFO", "INFO", "WARNING", "ERROR", "FATAL" };

		if (logging->destination_stderr == false
			&& logging->filename_.size() == 0
			&& logging->handler_ == NULL) {
			return;
		}

		char message[LOG_MESSAGE_MAX_LEN + 255];

		time_t t = time(NULL);
		struct tm local_time = { 0 };
#if _MSC_VER >= 1400
		localtime_s(&local_time, &t);
#else
		localtime_r(&t, &local_time);
#endif

		int ret = snprintf(message,
			LOG_MESSAGE_MAX_LEN,
			"[%02u%02u/%02u%02u%02u|%s|%s:%d]:",
			local_time.tm_mon + 1,
			local_time.tm_mday,
			local_time.tm_hour,
			local_time.tm_min,
			local_time.tm_sec,
			log_severity_names[level],
			function,
			line);

		if (ret > 0) {
			va_list	ap;
			va_start(ap, format);
			ret = vsnprintf(message + ret, LOG_MESSAGE_MAX_LEN - ret, format, ap);
			va_end(ap);
		}

		if (ret < 0) {
			sprintf(message, "[LogError] %200s:%d overflow", function, line);
		}

		if (logging->handler_) {
			logging->handler_(level, message);
		}

		if (logging->destination_stderr)
		{
			fprintf(stderr, "%s\n", message);
		}

		if (logging->filename_.size() > 0)
		{
			FILE *fp = fopen(logging->filename_.c_str(), "a+");
			if (fp)
			{
				fprintf(fp, "%s\n", message);
				fclose(fp);
			}
		}
	}

	static Logging* DefualtLogging() {
		static Logging log;
		return &log;
	}

private:

	bool destination_stderr;
	LogLevel level_;
	std::string filename_;
	LogMessageHandler handler_;
};

} //namespace base


#endif //BASE_LOGGING_H_
