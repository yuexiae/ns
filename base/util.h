#ifndef BASE_UTIL_H_
#define BASE_UTIL_H_

#include <windows.h>
#include <MMSystem.h>
#include <string>
#include "base/logging.h"


#if defined(_MSC_VER) && _MSC_VER < 1600
    typedef __int8 int8_t;
    typedef unsigned __int8 uint8_t;
    typedef __int16 int16_t;
    typedef unsigned __int16 uint16_t;
    typedef __int32 int32_t;
    typedef unsigned __int32 uint32_t;
    typedef __int64 int64_t;
    typedef unsigned __int64 uint64_t;
#elif defined(_MSC_VER)  // && _MSC_VER >= 1600
#   include <stdint.h>
#else
#   include <stdint.h>
#   include <stdbool.h>
#endif

namespace base {



class Util {
public:
	static std::string Format(const char *format, ...) {
		std::string str;

		va_list args;
		va_start(args, format);

		int size = strlen(format) * 2 + 128;
		str.resize(size);

		while (true) {
			int n = vsnprintf((char *)str.data(), size, format, args);
			if (n > -1 && n < size) {
				str.resize(n);
				return str;
			}

			if (n > -1) {
				size = n + 1;
			} else {
				size *= 2;
			}

			str.resize(size);
		}

		va_end(args);
		return str;
	}

	static std::string Format(std::string &str, const char *format, ...) {
		va_list args;
		va_start(args, format);

		int size = strlen(format) * 2 + 128;

		if ((int)str.size() < size) {
			str.resize(size);
		}

		while (true) {
			int n = vsnprintf((char *)str.data(), size, format, args);
			if (n > -1 && n < size) {
				str.resize(n);
				return str;
			}

			if (n > -1) {
				size = n + 1;
			} else {
				size *= 2;
			}

			str.resize(size);
		}

		va_end(args);
		return str;
	}

};

class CalcHighTime {
public:
	static void ThreadInit() { 
		SetThreadAffinityMask(GetCurrentThread(), 1);
	}

	CalcHighTime() {
		Start();
	}

	LONGLONG Get() {
		LARGE_INTEGER end;
		QueryPerformanceCounter(&end);
		return (end.QuadPart - time_.QuadPart) * 1000000 / GetFrequency().QuadPart;
	}

	double GetMilliSecond() {
		return (double)Get() / 1000;
	}

	void Start() {
		QueryPerformanceCounter(&time_);
	}

	static LARGE_INTEGER GetFrequency() {
		static LARGE_INTEGER frequency = {0, 0};
		if (frequency.QuadPart == 0) {
			QueryPerformanceFrequency(&frequency);
		}
		return frequency;
	}

private:
	LARGE_INTEGER time_;
};

class CalcHighTimeRange : public CalcHighTime {
public:
	CalcHighTimeRange() {}

	CalcHighTimeRange(const char *name)  : name_(name) {}

	~CalcHighTimeRange(){
		LOGINFO("[%s]elpase time:%lf", name_.c_str(), GetMilliSecond());
	}


	std::string name_;
};

class TimeElapse {
public:
    TimeElapse() { Start(); }

    void Start() { start_ = timeGetTime(); }
    void End() { value_ = timeGetTime() - start_; }
    unsigned int Get() { return value_; }

private:
	unsigned int start_;
    unsigned int value_;
};


class TimeElapseHigh {
public:
    TimeElapseHigh() { Start(); }

    void Start() { QueryPerformanceCounter(&start_); }
    void End() {
        static LARGE_INTEGER frequency = {0, 0};
		if (frequency.QuadPart == 0) {
			QueryPerformanceFrequency(&frequency);
		}

        LARGE_INTEGER end;
        QueryPerformanceCounter(&end);
        value_ = (end.QuadPart - start_.QuadPart) * 1000000 / frequency.QuadPart;
    }

    double GetMilliSecond() {
		return (double)value_ / 1000;
	}

    double CalcMilliSecond() {
        End();
		return (double)value_ / 1000;
	}

private:
    LARGE_INTEGER start_;
    LONGLONG value_;
};


template <class T>
__declspec(naked) T * __stdcall GetPreviousFunctionArg(int number) {
	__asm {
		push ecx
		mov ecx, dword ptr[ebp]
		mov eax, [esp + 0x08]
		shl eax, 2
		mov eax, dword ptr[ecx + 0x08 + eax]
		pop ecx
		ret 4
	}
}





}

#endif