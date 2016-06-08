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

#ifndef NIREGISTRY_H
#define NIREGISTRY_H

#if !defined(WIN32)
#error Win32-specific source code!
#endif  //#if !defined(WIN32)

#include <windows.h>

// NiRegistry is intended to provide a simple interface to the Windows
// registry for storage of application information that is intended to
// be shared. Currently, the class is just intended for opening a single
// key, accessing it, then closing it. It will NOT handle looking at
// multiple keys at once.

#include "NiString.h"

class NIPLUGINTOOLKIT_ENTRY NiRegistry
{
protected:
    NiRegistry();
public:
    ~NiRegistry();

    static NiRegistry* Create(const char* pcAppPath);

    bool SetAppPath(NiString strAppPath);
    bool OpenKey();
    bool CloseKey();

    void SetBool(const char* pcSubKey, BOOL dwValue); 
    void SetDWORD(const char* pcSubKey, DWORD dwValue); 
    void SetString(const char* pcSubKey, const char* pcValue); 
    void SetGUID(const char* pcSubKey, GUID* pkGUID); 


    bool QueryBool(const char* pcSubKey, bool& bValue); 
    bool QueryDWORD(const char* pcSubKey, unsigned int& uiValue); 
    bool QueryString(const char* pcSubKey, NiString& strValue); 
    bool QueryGUID(const char* pcSubKey, GUID* pkGUID); 

protected:
    NiString m_strAppPath;
    HKEY m_hTopLevelKey;
    HKEY m_hRootKey;
    HKEY m_hAppKey;
    HKEY m_hkey;
};

#endif  //#ifndef NIREGISTRY_H
