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

#ifndef NID3DSHADERFACTORY_H
#define NID3DSHADERFACTORY_H

#include <NiShaderFactory.h>
#include "NiD3DDefines.h"
#include "NiD3DError.h"
#include "NiD3DGlobalConstantEntry.h"

class NiD3DShaderLibrary;
class NiRenderer;

// NiD3DShaderFactory
class NID3D_ENTRY NiD3DShaderFactory : public NiShaderFactory
{
protected:
    NiD3DShaderFactory();

public:
    virtual ~NiD3DShaderFactory();

    // Global shader constant mappings
    static bool RegisterGlobalShaderConstant(const char* pcKey, 
        NiShaderAttributeDesc::AttributeType eType,
        unsigned int uiDataSize, void* pvInitialData);
    static bool ReleaseGlobalShaderConstant(const char* pcKey);
    static bool RetrieveGlobalShaderConstant(const char* pcKey,
        unsigned int& uiDataSize, void*& pvData);
    static bool UpdateGlobalShaderConstant(const char* pcKey,
        unsigned int uiDataSize, void* pvData);

    // *** begin NDL internal use only ***
    virtual void SetRenderer(NiD3DRenderer* pkRenderer);

    virtual bool Geometry_AttachShader(NiGeometry* pkGeometry, 
        const char* pcName, unsigned int uiImplementation);
    virtual bool Geometry_AttachShader(NiGeometry* pkGeometry, 
        NiShader* pkShader);
    virtual bool Geometry_DetachShader(NiGeometry* pkGeometry);

    virtual NiShader* RetrieveShader(const char* pcName, 
        unsigned int uiImplementation, bool bReportNotFound = true);
    virtual void InsertShader(NiShader* pkShader, 
        unsigned int uiImplementation);
    virtual NiShader* FindShader(const char* pcName, 
        unsigned int uiImplementation);
    virtual void RemoveShader(const char* pcName,
        unsigned int uiImplementation);
    virtual void RemoveAllShaders();

    virtual void InsertLibrary(NiShaderLibrary* pkLibrary);
    virtual NiShaderLibrary* FindLibrary(const char* pcName);
    virtual void RemoveLibrary(const char* pcName);
    virtual void RemoveAllLibraries();
    virtual NiShaderLibrary* GetFirstLibrary();
    virtual NiShaderLibrary* GetNextLibrary();

    virtual void PurgeAllShaderRendererData();
    virtual void RestoreAllShaderRendererData();

    static void _SDMInit();
    static void _SDMShutdown();

    static NiShaderFactory* Create();
    static void Destroy();

    NiD3DGlobalConstantEntry* GetGlobalShaderConstantEntry(
        const char* pcKey);

    virtual const unsigned int GetMinorPixelShaderVersion(
        const unsigned int uiVersion);
    virtual const unsigned int GetMajorPixelShaderVersion(
        const unsigned int uiVersion);
    virtual const unsigned int CreatePixelShaderVersion(
        const unsigned int uiMajorVersion, const unsigned int uiMinorVersion);
    virtual const unsigned int GetMinorVertexShaderVersion(
        const unsigned int uiVersion) ;
    virtual const unsigned int GetMajorVertexShaderVersion(
        const unsigned int uiVersion) ;
    virtual const unsigned int CreateVertexShaderVersion(
        const unsigned int uiMajorVersion, const unsigned int uiMinorVersion);

    bool SetAsActiveFactory();
    bool IsActiveFactory();
    static NiD3DShaderFactory* GetD3DShaderFactory();

    virtual const char* GetRendererString() const;
    // *** end NDL internal use only ***

protected:
    virtual const char* GetFirstProgramDirectory(NiTListIterator& kIter);
    virtual const char* GetNextProgramDirectory(NiTListIterator& kIter);
    virtual void AddProgramDirectory(const char* pacDirectory);
    virtual void RemoveProgramDirectory(const char* pacDirectory);
    virtual void RemoveAllProgramDirectories();

    static const char* GetCompilerName(unsigned int uiVersion);

    NiD3DRenderer* m_pkRenderer;

    NiTStringPointerMap<NiShader*>* m_pkShaderMap;
    NiTMapIterator m_kLibraryIter;
    NiTStringPointerMap<NiShaderLibraryPtr>* m_pkLibraryMap;
    NiTStringMap<NiD3DGlobalConstantEntry*> m_kGlobalConstantMap;

    static unsigned int ms_uiNewShaderValue;

#if defined(_USRDLL)
    // Default Class Creation and RunParser functions for use
    // with DLL builds
    static bool DefaultDLLCreateClass(const char* pcLibName, 
        NiRenderer* pkRenderer, int iDirectoryCount, char* apcDirectories[], 
        bool bRecurseSubFolders, NiShaderLibrary** ppkLibrary);
    static unsigned int DefaultDLLRunParser(const char* pcLibName, 
        NiRenderer* pkRenderer, const char* pcDirectory, 
        bool bRecurseSubFolders);

    NiTStringMap<HMODULE> m_kLoadedShaderLibDLLs;
#endif //#if defined(_USRDLL)

    static NiD3DShaderFactory* ms_pkD3DShaderFactory;
};

typedef NiPointer<NiD3DShaderFactory> NiD3DShaderFactoryPtr;

#endif  //#ifndef NID3DSHADERFACTORY_H
