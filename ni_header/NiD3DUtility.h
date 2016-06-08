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

#ifndef NID3DUTILITY_H
#define NID3DUTILITY_H

#include "NiD3DDefines.h"

class NiBinaryStream;
class NiGeometry;
class NiTriShape;
class NiTriStrips;
class NiPoint3;
class NiPoint2;

class NID3D_ENTRY NiD3DUtility
{
public:
    NiD3DUtility();
    ~NiD3DUtility();

    // Log
    static void Log(char* pszFmt, ...);
    static bool GetLogEnabled();
    static void SetLogEnabled(bool bEnabled);

    // GetFileXXX
    static bool GetSplitPath(const char* pszFilename, char* pszDrive, 
        char* pszDir, char* pszFname, char* pszExt);
    static bool GetFilePath(const char* pszFilename, char* pszPath,
        unsigned int uiMaxLen);
    static bool GetFileName(const char* pszFilename, char* pszName,
        unsigned int uiMaxLen);
    static bool GetFileExtension(const char* pszFilename, char* pszExt,
        unsigned int uiMaxLen);

    // String setting helper function
    static void SetString(char*& pszDest, const char* pszSrc);

    // Write to stream
    static bool WriteString(NiBinaryStream& kStream, const char* pszString);
    static bool WriteUInt(NiBinaryStream& kStream, unsigned int uiValue);
    static bool WriteUInts(NiBinaryStream& kStream, unsigned int* puiValue, 
        unsigned int uiCount);
    static bool WriteFloat(NiBinaryStream& kStream, float fValue);
    static bool WriteFloats(NiBinaryStream& kStream, float* pfValue, 
        unsigned int uiCount);
    static bool WriteData(NiBinaryStream& kStream, void* pvData,
        unsigned int uiSize);

    // Read from stream
    static bool ReadString(NiBinaryStream& kStream, char* pszString,
        unsigned int& uiMaxLen);
    static bool AllocateAndReadString(NiBinaryStream& kStream, 
        char*& pszString);
    static bool ReadUInt(NiBinaryStream& kStream, unsigned int& uiValue);
    static bool ReadUInts(NiBinaryStream& kStream, unsigned int* puiValue, 
        unsigned int uiCount);
    static bool ReadFloat(NiBinaryStream& kStream, float& fValue);
    static bool ReadFloats(NiBinaryStream& kStream, float* pfValue, 
        unsigned int uiCount);
    static bool ReadData(NiBinaryStream& kStream, void*& pvData,
        unsigned int& uiSize);
    static bool AllocateAndReadData(NiBinaryStream& kStream, void*& pvData);

    // Unicode character conversion
    static bool ConvertCHARToWCHAR(WCHAR* pwDestination, 
        const char* pcSource, unsigned int uiDestChar);
    static bool ConvertWCHARToCHAR(char* pcDestination, 
        const WCHAR* pwSource, unsigned int uiDestChar);
    static bool ConvertTCHARToCHAR(char* pcDestination, 
        const TCHAR* ptSource, unsigned int uiDestChar);
    static bool ConvertTCHARToWCHAR(WCHAR* pwDestination, 
        const TCHAR* ptSource, unsigned int uiDestChar);
    static bool ConvertCHARToTCHAR(TCHAR* ptDestination, 
        const char* pcSource, unsigned int uiDestChar);
    static bool ConvertWCHARToTCHAR(TCHAR* ptDestination, 
        const WCHAR* pwSource, unsigned int uiDestChar);
protected:
    static bool ms_bLogEnabled;
};

#endif  //NID3DUTILITY_H
