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

#ifndef NIFILENAME_H
#define NIFILENAME_H

#include "NiRTLib.h"
#include "NiSystemLibType.h"

class NISYSTEM_ENTRY NiFilename
{
public:
    NiFilename(const char* pFullPath);

    void SetDir(const char* pDir);
    void SetDrive(const char* pDrive);
    void SetExt(const char* pExt);
    void SetFilename(const char* pFname);
    void SetPlatformSubDir(const char* pSubDir);

    const char* GetDir() const;
    const char* GetDrive() const;
    const char* GetExt() const;
    const char* GetFilename() const;
    const char* GetPlatformSubDir() const;

    void GetFullPath(char *pFullPath) const;


private:
    void Splitpath(const char* pStr);
    void Makepath(char* pStr) const;

#ifdef WIN32
    char m_acDir[_MAX_DIR]; 
    char m_acDrive[_MAX_DRIVE]; 
    char m_acExt[_MAX_EXT];
    char m_acFname[_MAX_FNAME]; 
    char m_acSubDir[_MAX_DIR]; 
#else
    char m_acDir[256]; 
    char m_acDrive[3]; 
    char m_acExt[256];
    char m_acFname[256]; 
    char m_acSubDir[256]; 
#endif
};

//---------------------------------------------------------------------------
inline void NiFilename::SetDir(const char *pDir)
{
    strcpy(m_acDir, pDir);
}
//---------------------------------------------------------------------------
inline void NiFilename::SetDrive(const char *pDrive)
{
    strcpy(m_acDrive, pDrive);
}
//---------------------------------------------------------------------------
inline void NiFilename::SetExt(const char *pExt)
{
    strcpy(m_acExt, pExt);
}
//---------------------------------------------------------------------------
inline void NiFilename::SetFilename(const char *pFname)
{
    strcpy(m_acFname, pFname);
}
//---------------------------------------------------------------------------
inline void NiFilename::SetPlatformSubDir(const char* pSubDir)
{
    strcpy(m_acSubDir, pSubDir);
}
//---------------------------------------------------------------------------
inline const char* NiFilename::GetDir() const
{
    return m_acDir;
}
//---------------------------------------------------------------------------
inline const char* NiFilename::GetDrive() const
{
    return m_acDrive;
}
//---------------------------------------------------------------------------
inline const char* NiFilename::GetExt() const
{
    return m_acExt;
}
//---------------------------------------------------------------------------
inline const char* NiFilename::GetFilename() const
{
    return m_acFname;
}
//---------------------------------------------------------------------------
inline const char* NiFilename::GetPlatformSubDir() const
{
    return m_acSubDir;
}
//---------------------------------------------------------------------------

#endif // NIFILENAME_H
