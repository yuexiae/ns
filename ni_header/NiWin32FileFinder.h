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

#ifndef NIWIN32FILEFINDER_H
#define NIWIN32FILEFINDER_H
#include <NiTArray.h>

#include "NiShaderToolkitLibType.h"

class NISHADERTOOLKIT_ENTRY NiWin32FoundFile
{
public:
    NiWin32FoundFile() 
    {
        m_strPath[0] ='\0';
        m_uiSize = 0;
    };
    char m_strPath[MAX_PATH];
    unsigned int m_uiSize;
    FILETIME ftLastWriteTime;
};

class NISHADERTOOLKIT_ENTRY NiWin32FileFinder
{
public:
    NiWin32FileFinder(const char* strPath, bool bRecurseSubDirs = true, 
        const char* pcExtension = "\0"); 

    NiWin32FoundFile* GetNextFile();

    bool HasMoreFiles();

    void ResetIterator();

    ~NiWin32FileFinder();

protected:
    void AddFile(const char* strPath, unsigned int uiSize, FILETIME kLastWriteTime);
    void Find(const char* strPath, bool bRecurseSubDirs, 
        const char* pcExtension);

    NiTArray<NiWin32FoundFile*> m_kFoundFiles;
    unsigned int m_uiIterator;
};

#endif //NIWIN32FILEFINDER_H