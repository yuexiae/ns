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
//---------------------------------------------------------------------------

#ifndef NISEARCHPATH_H
#define NISEARCHPATH_H

#include "NiSystem.h"
#include "NiSystemLibType.h"

class NISYSTEM_ENTRY NiSearchPath
{
public:
    NiSearchPath();
    virtual ~NiSearchPath();
    void SetFilePath(const char* pcFilePath);
    void SetReferencePath(const char* pcReferencePath);
    
    virtual void Reset();
    virtual bool GetNextSearchPath(char* pcPath);

    static void SetDefaultPath(const char* pcPath);
    static const char* GetDefaultPath();

protected:
    unsigned int m_uiNextPath;

    char m_acFilePath[NI_MAX_PATH];
    char m_acReferencePath[NI_MAX_PATH];

    static char ms_acDefPath[NI_MAX_PATH];
};

#include "NiSearchPath.inl"

#endif

