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

#ifndef NISHADERTOOLKIT_H
#define NISHADERTOOLKIT_H

#pragma warning( disable : 4786)

#include "NiShaderToolkitLibType.h"

#include <NiTStringMap.h>
#include "NiShaderHelpers.h"

class NiShaderLibraryDesc;
class NiShaderDesc;


class NISHADERTOOLKIT_ENTRY NiShaderToolkit
{
public:
    static NiShaderToolkit* CreateToolkit();
    static void DestroyToolkit();
    static NiShaderToolkit* GetToolkit();

    void LoadFromDLL(const char* pcShaderPath);
    void ReIndex();

    static void ReloadShaders();
    static void UnloadShaders();

    NiShaderLibraryDesc* GetLibraryDesc(const char* pcName);
    NiShaderLibraryDesc* GetLibraryDescAt(unsigned int uiWhichLibrary);
    const char* GetLibraryNameAt(unsigned int uiWhichLibrary);
    unsigned int GetLibraryDescCount();

    NiShaderDesc* GetShaderDesc(const char* pcName);
    void DeleteShaderDesc(NiShaderDesc* pkDesc);

    const char* GetAppStringForShaderDesc(const char* pcName);
    bool SetAppStringForShaderDesc(const char* pcName, 
        const char* pcAppDesc);

    void SetShaderDirectory(const char* pcDir, bool bAppend = false);
    static void UpdateShaderDirectory();

protected:

    class NiShaderLibraryContainer
    {
    public:
        NiShaderLibraryContainer();
        ~NiShaderLibraryContainer();

        NiShaderLibraryDesc * m_pkLibraryDesc;
    };

    class NiShaderDescContainer
    {
    public:
        NiShaderDescContainer();
        ~NiShaderDescContainer();
        NiShaderDesc* m_pkDesc;
        char* m_pcApplicationDescription;
    };

    NiShaderToolkit();
    NiShaderToolkit(NiShaderToolkit& kToolkit);
    ~NiShaderToolkit();
    bool ParseNPShaders(const char* pcLibraryPath, 
        const char* pcShaderPath);
    void LoadShaders();
    void UnIndex();

    static NiShaderToolkit* ms_pkThis;
    char* m_pcShaderPath;

    char* m_pcShaderProgramPath;
    bool m_bAppendSubdir;
    bool m_bUpdateShaderProgramDir;

    NiTStringPointerMap<NiShaderLibraryContainer*> m_kLibraries;
    NiTStringPointerMap<NiShaderDescContainer*> m_kShaderDescCache;
};
#endif