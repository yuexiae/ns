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

#ifndef NISYSTEM_H
#define NISYSTEM_H

#include "NiRTLib.h"
#include "NiOS.h"
#include "NiFile.h"
#include "NiLog.h"
#include "NiSystemSDM.h"
#include "NiCriticalSection.h"
#include "NiMessageBox.h"

// Routines whose implementation depends on system
NISYSTEM_ENTRY int NiStricmp(const char* s1, const char* s2);
NISYSTEM_ENTRY int NiStrnicmp(const char* s1, const char* s2, size_t n);
NISYSTEM_ENTRY unsigned int NiRotr(unsigned int x, int n);
NISYSTEM_ENTRY void NiSleep(unsigned int uiMilliseconds);

// Routines that query the system
NISYSTEM_ENTRY float NiGetCurrentTimeInSec();
NISYSTEM_ENTRY void NiStandardizeFilePath(char* tmpPath);
NISYSTEM_ENTRY unsigned int NiGetFileSize (const char* pFilename);
NISYSTEM_ENTRY unsigned int NiGetPerformanceCounter(); // unit may vary with platform

// Routines that return information to user/programmer
#if !defined(NDEBUG)
NISYSTEM_ENTRY void NiWriteToStdErr(char* pText);
#if !defined(REPLACE_NIOUTPUTDEBUGSTRING_WITH_NILOG)
NISYSTEM_ENTRY void NiOutputDebugString(const char* pcOut);
#endif //#if !defined(REPLACE_NIOUTPUTDEBUGSTRING_WITH_NILOG)
#else //#if !defined(NDEBUG)
#define NiWriteToStdErr(x) ((void)0)
#define NiOutputDebugString(x) ((void)0)
#endif //#if !defined(NDEBUG)

#if defined(WIN32)
#define NI_MAX_PATH _MAX_PATH
#else //#if defined(WIN32)
#define NI_MAX_PATH 260
#endif //#if defined(WIN32)

#include "NiSystem.inl"

#endif
