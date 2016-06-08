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

#ifndef NSBSHADER_H
#define NSBSHADER_H

#include "NiBinaryShaderLibLibType.h"
#include "NSBAttributeTable.h"
#include "NSBPackingDef.h"
#include "NSBImplementation.h"
#include "NSBUserDefinedDataSet.h"

#include <NiRefObject.h>
#include <NiSmartPointer.h>

class NiBinaryShader;
NiSmartPointer(NiShaderDesc);

class NIBINARYSHADERLIB_ENTRY NSBShader : public NiRefObject
{
protected:
    enum
    {
        MAGIC_NUMBER    = 0x0062736E,   //NSB0
        // 100403 - Bumped version number to 1.1 to reflect addition of
        //          UsesNiLightState requirement. (Shipped in 1.0.1)
        // 141003 - Bumped version to 1.2 to add shader targets, shader 
        //          entry points, and variable names
        // 231003 - Bumped version to 1.3 to add software vertex processing
        // 300304 - Bumped version to 1.4 to add streaming of 
        //          platform-specific constant map entries
        // 310304 - Bumped version to 1.5 to add streaming of a
        //          user-defined class name for implementations.
        // 010404 - Bumped version to 1.6 to add UserDefinedDataBlocks
        // 020404 - Bumped version to 1.7 to improve software vertex processing
        NSB_VERSION     = 0x00010007    // 1.7
    };

public:
    NSBShader();
    ~NSBShader();

    // This will allow for customers to derived their own 
    // NiBinaryShader-based classes, allowing them to extend the 
    // functionality while still gaining the benefit of having the
    // default NSF parsing do the file handling.
    //
    // This is the prototype of the CreateNiBinaryShaderFunction
    typedef NiBinaryShader* (*CREATENIBINARYSHADER)(
        const char* pacClassName);

    static CREATENIBINARYSHADER SetCreateNiBinaryShaderCallback(
        CREATENIBINARYSHADER pfnCallback);
    static CREATENIBINARYSHADER GetCreateNiBinaryShaderCallback();
    
    static NiBinaryShader* DefaultCreateNiBinaryShader(
        const char* pacClassName);

    // Name
    const char* GetName();
    const char* GetDescription();

    // Shader Versions
    unsigned int GetMinPixelShaderVersion();
    unsigned int GetMaxPixelShaderVersion();
    unsigned int GetMinVertexShaderVersion();
    unsigned int GetMaxVertexShaderVersion();
    unsigned int GetMinUserVersion();
    unsigned int GetMaxUserVersion();
    unsigned int GetPlatform();

    // Access to the attribute table
    NSBAttributeTable* GetGlobalAttributeTable();
    NSBAttributeTable* GetAttributeTable();
    // The packing definitions
    unsigned int GetPackingDefCount();
    NSBPackingDef* GetPackingDef(const char* pszName, bool bCreate = false);
    // The implementations
    unsigned int GetImplementationCount();
    NSBImplementation* GetImplementation(const char* pszName, 
        bool bCreate = false, unsigned int uiNextIndex = 0);
    NSBImplementation* GetImplementationByName(const char* pszName);
    NSBImplementation* GetImplementationByIndex(unsigned int uiIndex);

    void SetMinPixelShaderVersionRequest(unsigned int uiVersion);
    void SetMaxPixelShaderVersionRequest(unsigned int uiVersion);
    void SetMinVertexShaderVersionRequest(unsigned int uiVersion);
    void SetMaxVertexShaderVersionRequest(unsigned int uiVersion);
    void SetMinUserVersionRequest(unsigned int uiVersion);
    void SetMaxUserVersionRequest(unsigned int uiVersion);
    void SetPlatformRequest(unsigned int uiPlatform);
    
    // Get the BINARY shader
    NiBinaryShader* GetD3DShader(NiD3DRenderer* pkRenderer, 
        unsigned int uiImplementation = NiShader::DEFAULT_IMPLEMENTATION);

    // *** begin NDL internal use only
    // User defined data set
    NSBUserDefinedDataSet* GetUserDefinedDataSet();
    void SetUserDefinedDataSet(NSBUserDefinedDataSet* pkUDDSet);

    NiShaderDesc* GetShaderDesc();
    // These functions are used during the creation
    void SetName(const char* pszName);
    void SetDescription(const char* pszDescription);

    void AddPixelShaderVersion(unsigned int uiVersion);
    void AddVertexShaderVersion(unsigned int uiVersion);
    void AddUserVersion(unsigned int uiVersion);
    void AddPlatform(unsigned int uiPlatformFlag);

    bool Save(const char* pszFilename);
    bool SaveBinary(NiBinaryStream& kStream);
    bool Load(const char* pszFilename);
    bool LoadBinary(NiBinaryStream& kStream);

    static unsigned int GetReadVersion();

#if defined(_DEBUG)
    void Dump();
#endif  //#if defined(_DEBUG)
    // *** end NDL internal use only

protected:
    bool RegisterTextureStageGlobals(NiD3DRenderer* pkRenderer, 
        NSBImplementation* pkImplementation);
    bool ReleaseTextureStageGlobals(NiD3DRenderer* pkRenderer, 
        NSBImplementation* pkImplementation);

    NiBinaryShader* GetD3DShader_DX9(NiD3DRenderer* pkRenderer, 
        unsigned int uiImplementation);
    NiBinaryShader* GetD3DShader_DX8(NiD3DRenderer* pkRenderer, 
        unsigned int uiImplementation);
    NiBinaryShader* GetD3DShader_XBox(NiD3DRenderer* pkRenderer, 
        unsigned int uiImplementation);

    NSBImplementation* GetBestImplementation(NiD3DRenderer* pkRenderer);

    enum ValidityFlag
    {
        INVALID = 0,
        VALID = 1,
        VALID_REQUESTED = 2
    };

    class VersionInfo
    {
    public:
        unsigned int m_uiPS_Sys;
        unsigned int m_uiPS_Min;
        unsigned int m_uiPS_Req;
        unsigned int m_uiVS_Sys;
        unsigned int m_uiVS_Min;
        unsigned int m_uiVS_Req;
        unsigned int m_uiUser_Sys;
        unsigned int m_uiUser_Min;
        unsigned int m_uiUser_Req;
        unsigned int m_uiPlatform;
        bool m_bSoftwareVSCapable_Sys;
    };

    void SetupVersionInfo(NiD3DRenderer* pkRenderer, 
        VersionInfo& kVersionInfo);
    ValidityFlag IsImplementationValid(NSBImplementation* pkImplementation,
        VersionInfo& kVersionInfo);

    bool SaveBinaryPackingDefs(NiBinaryStream& kStream);
    bool LoadBinaryPackingDefs(NiBinaryStream& kStream);
    bool SaveBinaryImplementations(NiBinaryStream& kStream);
    bool LoadBinaryImplementations(NiBinaryStream& kStream);

    char* m_pszName;
    char* m_pszDescription;

    unsigned int m_uiMinPixelShaderVersionRequest;
    unsigned int m_uiMaxPixelShaderVersionRequest;
    unsigned int m_uiMinVertexShaderVersionRequest;
    unsigned int m_uiMaxVertexShaderVersionRequest;
    unsigned int m_uiMinUserVersionRequest;
    unsigned int m_uiMaxUserVersionRequest;
    unsigned int m_uiPlatformRequest;

    unsigned int m_uiMinPixelShaderVersion;
    unsigned int m_uiMaxPixelShaderVersion;
    unsigned int m_uiMinVertexShaderVersion;
    unsigned int m_uiMaxVertexShaderVersion;
    unsigned int m_uiMinUserVersion;
    unsigned int m_uiMaxUserVersion;
    unsigned int m_uiPlatform;

    // User defined data set
    NSBUserDefinedDataSetPtr m_spUserDefinedDataSet;

    NSBAttributeTable m_kGlobalAttribTable;
    NSBAttributeTable m_kAttribTable;
    NiTStringPointerMap<NSBPackingDef*> m_kPackingDefMap;
    NiTArray<NSBImplementation*> m_kImplementationArray;

    NiShaderDescPtr m_spShaderDesc;

    static unsigned int ms_uiReadVersion;
    static CREATENIBINARYSHADER ms_pfnCreateNiBinaryShader;
};

typedef NiPointer<NSBShader> NSBShaderPtr;

#include "NSBShader.inl"

#endif  //NSBSHADER_H
