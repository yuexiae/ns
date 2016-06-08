// NUMERICAL DESIGN LIMITED PROPRIETARY INFORMATION
//
// This software is supplied under the terms of a license agreement or
// nondisclosure agreement with Numerical Design Limited and may not 
// be copied or disclosed except in accordance with the terms of that 
// agreement.
//
//      Copyright (c) 1996-2004 Numerical Design Limited.
//      All Rights Reserved.
//
// Numerical Design Limited, Chapel Hill, North Carolina 27514
// http://www.ndl.com

#ifndef NILOG_H
#define NILOG_H

#include <NiSystem.h>
#include "NiLogBehavior.h"
#include "NiSystemLibType.h"

//---------------------------------------------------------------------------
// The NiLogger build configurations are:
// 1) Normal Debug mode -- NiLogger is enabled, NILOG, and NILOGDIRECT 
//    calls are compiled in.
// 2) Normal Release mode -- NiLogger is enabled, but NILOG, and 
//    NILOGDIRECT calls are optimized out.
// 3) Release mode with NI_RELEASE_MODE_LOGGING defined -- NiLogger behaves
//    same as in Normal Debug mode.
// 4) NI_LOGGER_DISABLE defined -- NiLogger is disabled, NILOG, and 
//    NILOGDIRECT calls are optimized out.  Any references to NiLogger are 
//    undefined.

// Message types are defined here.  Note, the types are #define's
// instead of NiLogger enums so that when logging is disabled, 
// NILOG calls will compile but be optimized out.
#define NIMESSAGE_GENERAL_0 0
#define NIMESSAGE_GENERAL_1 1
#define NIMESSAGE_GENERAL_2 2 
#define NIMESSAGE_PROFILE_0 3
#define NIMESSAGE_PROFILE_1 4
#define NIMESSAGE_PROFILE_2 5
#define NIMESSAGE_MEMORY_0 6
#define NIMESSAGE_MEMORY_1 7
#define NIMESSAGE_MEMORY_2 8
#define NIMESSAGE_MEMORY_TIMESTAMP 9
#define NIMESSAGE_RESERVED_FOR_LOGDIRECT 10
#define NIMESSAGE_MAX_INTERNAL_INDEX NIMESSAGE_RESERVED_FOR_LOGDIRECT
#define NIMESSAGE_MAX_TYPES 32
// user-defined types should start at NIMESSAGE_MAX_INTERNAL_INDEX+1
// and be less than NIMESSAGE_MAX_TYPES.

// The following macros aren't pretty, but they make the syntax for using 
// the log system much easier.  The only ones that should be used directly
// are NILOG and NILOGDIRECT.
// IMPORTANT NOTE: These macros do not expand properly if compiled with
// Visual Studio's Edit And Continue enabled (/ZI compiler option).
#define CONCAT2(name, l) name##l
#define CONCAT1(name, l) CONCAT2(name, l)
#define INSERT_UNIQUE_NAME(name) CONCAT1(name,__LINE__)

// In release mode, NiOutputDebugString is defined as a ((void)0) macro.
// In debug mode, replace NiOutputDebugString calls with NILOG equivalents.
#ifndef NDEBUG
    #define REPLACE_NIOUTPUTDEBUGSTRING_WITH_NILOG
#endif

//Because profile builds are essentially worthless without logging enabled
//we ensure that NI_RELEASE_MODE_LOGGING is defined in the presence of
//NIPROFILE.
#if defined(NIPROFILE) && !defined(NI_RELEASE_MODE_LOGGING)
#define NI_RELEASE_MODE_LOGGING
#endif

#if !defined NI_LOGGER_DISABLE && (!defined(NDEBUG) || defined(NI_RELEASE_MODE_LOGGING))
    #ifdef __GNUC__
        #define NILOG NiLogger __attribute__ ((__unused__)) INSERT_UNIQUE_NAME(xx_Log_)
        #define NILOGDIRECT NiLoggerDirect __attribute__ ((__unused__)) INSERT_UNIQUE_NAME(xx_Log_)
    #else
        #define NILOG NiLogger INSERT_UNIQUE_NAME(xx_Log_)
        #define NILOGDIRECT NiLoggerDirect INSERT_UNIQUE_NAME(xx_Log_)
    #endif // #ifdef __GNUC__

    #ifdef REPLACE_NIOUTPUTDEBUGSTRING_WITH_NILOG
        #define NiOutputDebugString(x) NILOG(NIMESSAGE_GENERAL_0, x)
    #endif // #ifdef REPLACE_NIOUTPUTDEBUGSTRING_WITH_NILOG
#else
    #if defined(__GNUC__) || defined(__MWERKS__)
        inline void NiNullFunction(int, const char*,  ...) { }
        #define NILOG NiNullFunction
        #define NILOGDIRECT NiNullFunction
    #elif defined (_MSC_VER) && (_MSC_VER >= 1300)
        #define NILOG __noop
        #define NILOGDIRECT __noop
    #else
        #define NILOG ((void)0)
        #define NILOGDIRECT ((void)0)
    #endif // #ifdef __GNUC__
#endif
// End macro defines.

#ifndef NI_LOGGER_DISABLE

class NISYSTEM_ENTRY NiLogMessageOptions
{
public:
    NiLogMessageOptions();
    bool m_bOutputToDebugWindow;
    int m_iLogID;
    bool m_bPrependTimestamp;
};

class NISYSTEM_ENTRY NiLogger
{
public:
    // don't call this explictly, use the NILOG macro.
    NiLogger(int iMessageType, const char* pcFormat,  ...);
        
    enum OpenMode
    {
        OPEN_APPEND,
        OPEN_OVERWRITE,
        OPEN_UNIQUENAME
    };
    static void _SDMInit();
    static void _SDMShutdown();

    static int OpenLog(const char* pcFilename, OpenMode eOpenMode = OPEN_OVERWRITE, 
        bool bFlushOnWrite = false, bool bCommitToDisk = false);
    static void CloseLog(int iLogID);
    static void CloseAllLogs();
    static void FlushAllLogs();

    // Get/Set MessageBehavior options for each message type
    static void SetOutputToDebugWindow(int iMessageType, bool bOutput);
    static bool GetOutputToDebugWindow(int iMessageType);

    static void SetPrependTimestamp(int iMessageType, bool bTimestamp);
    static bool GetPrependTimestamp(int iMessageType);

    static void SetOutputToLogFile(int iMessageType, int iLogID);
    static int GetOutputToLogFile(int iMessageType);

    // internal use only
    static int UnixToDos(char* pcString);

protected:
    NiLogger() { }
    class NiLogFile
    {
    public:
        char m_acName[256];

#if defined(WIN32) || defined(_XBOX)
        FILE* m_pkFile;
#else
        int m_iFile;
#endif

        NiLogFile(const char* pcName, OpenMode eOpenMode, bool bFlushOnWrite,
            bool bCommitToDisk);
        ~NiLogFile();

        void Log(char* pcMessage);

    protected:
        bool OpenFile(OpenMode eOpenMode, bool bCommitToDisk);
        void CloseFile();
        bool m_bFlushOnWrite;
    };

    enum
    {
        MAX_NUM_LOGFILES = 16
    };

    static unsigned int ms_uiLogFileCount;
    static NiLogFile* ms_apkLogFile[MAX_NUM_LOGFILES];

    enum 
    {
        MAX_OUTPUT_LENGTH = 512
    };

    bool OkayToOutput();
    void FormatOutput(const char* pcFormat, va_list kArgList);
    void LogBuffer();

    static char ms_acBuffer[MAX_OUTPUT_LENGTH]; // for formatting
    static NiLogMessageOptions ms_akMessageOptions[NIMESSAGE_MAX_TYPES];

#ifdef WIN32
    static CRITICAL_SECTION* GetCriticalSection();
#endif

    int m_iMessageType;
    static bool ms_bInitialize;

};

class NISYSTEM_ENTRY NiLoggerDirect : public NiLogger
{
public:
    // don't call this explictly, use the NILOGDIRECT macro.
    NiLoggerDirect(int iLogID, const char* pcFormat,  ...);
};


#include "NiLog.inl"
#endif // #ifndef NI_LOGGER_DISABLE

#endif // #ifndef NILOG_H
