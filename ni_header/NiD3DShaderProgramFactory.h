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

#ifndef NID3DSHADERPROGRAMFACTORY_H
#define NID3DSHADERPROGRAMFACTORY_H

#include <NiRefObject.h>
#include <NiSMartPointer.h>
#include <NiTStringMap.h>

#include "NiD3DDefines.h"
#include "NiD3DRendererHeaders.h"

NiSmartPointer(NiD3DShaderProgramCreator);
NiSmartPointer(NiD3DVertexShader);
NiSmartPointer(NiD3DPixelShader);

class NID3D_ENTRY NiD3DShaderProgramFactory : public NiRefObject
{
protected:
    static D3DDevicePtr ms_pkD3DDevice;
    static NiD3DRenderer* ms_pkD3DRenderer;
    static NiD3DRenderState* ms_pkD3DRenderState;

    // *** begin NDL internal use only ***
    static void SetD3DDevice(D3DDevicePtr pkD3DDevice);
    static void SetD3DRenderState(NiD3DRenderState* pkRS);

public:
    static void SetD3DRenderer(NiD3DRenderer* pkD3DRenderer);

    static NiD3DShaderProgramFactory* Create();
    // *** end NDL internal use only ***

protected:
    NiD3DShaderProgramFactory();

public:
    virtual ~NiD3DShaderProgramFactory();

    static NiD3DShaderProgramFactory* GetInstance();
    static void Shutdown();

    //*** Helper functions
    // Vertex shader creation
    static NiD3DVertexShader* CreateVertexShaderFromFile(
        const char* pcFileName, const char* pcShaderName, 
        const char* pcEntryPoint, const char* pcShaderTarget, 
        NiD3DVertexDeclaration hDecl, unsigned int uiUsage, 
        bool bSoftwareVP = false);
    static NiD3DVertexShader* CreateVertexShaderFromBuffer(
        const void* pvBuffer, unsigned int uiBufferSize, const char* pcExt, 
        const char* pcShaderName, const char* pcEntryPoint, 
        const char* pcShaderTarget, NiD3DVertexDeclaration hDecl, 
        unsigned int uiUsage, bool bSoftwareVP = false);
    // Pixel  shader creation
    static NiD3DPixelShader* CreatePixelShaderFromFile(
        const char* pcFileName, const char* pcShaderName, 
        const char* pcEntryPoint, const char* pcShaderTarget);
    static NiD3DPixelShader* CreatePixelShaderFromBuffer(const void* pvBuffer, 
        unsigned int uiBufferSize, const char* pcExt, const char* pcShaderName, 
        const char* pcEntryPoint, const char* pcShaderTarget);

    // Shader creation flags - apply to all shaders
    static unsigned int GetUniversalShaderCreationFlags();
    static void SetUniversalShaderCreationFlags(unsigned int uiFlags);

    // Shader recreation
    static bool RecreateVertexShader(NiD3DVertexShader* pkVertexShader);
    static bool RecreatePixelShader(NiD3DPixelShader* pkPixelShader);

    // Shader releasing
    static void ReleaseVertexShader(NiD3DVertexShader* pkShader);
    static void ReleasePixelShader(NiD3DPixelShader* pkShader);

    // *** begin NDL internal use only ***
    const char* GetFirstProgramDirectory(NiTListIterator& kIter);
    const char* GetNextProgramDirectory(NiTListIterator& kIter);
    void AddProgramDirectory(const char* pcDirectory);
    void RemoveProgramDirectory(const char* pcDirectory);
    void RemoveAllProgramDirectories();

    // Find functions
    NiD3DVertexShader* GetVertexShader(const char* pcShaderName); 
    NiD3DPixelShader* GetPixelShader(const char* pcShaderName); 

    // Shader insertion/removal
    void InsertVertexShaderIntoMap(NiD3DVertexShader* pkShader);
    void RemoveVertexShaderFromMap(const char* pcShaderName);
    void InsertPixelShaderIntoMap(NiD3DPixelShader* pkShader);
    void RemovePixelShaderFromMap(const char* pcShaderName);

    static bool NiD3DShaderProgramFactory::ResolveShaderFileName(
        const char* pcOriginalName, char* pcTrueName);

    static bool RegisterShaderCreator(const char* pcExt, 
        NiD3DShaderProgramCreator* pkCreator);
    static void UnregisterShaderCreator(NiD3DShaderProgramCreator* pkCreator);
    static NiD3DShaderProgramCreator* GetShaderCreator(const char* pcFilename);

    static void _SDMInit();
    static void _SDMShutdown();

#if defined(_XBOX) && !defined(_XENON)
    // Used for creating 'fixed-function shaders' (for supporting
    // compressed vertices in the fixed-function pipeline)
    // THESE SHOULD NOT BE CALLED BY AN APPLICATION!
    virtual NiD3DVertexShaderHandle CreateVertexShader(
        NiD3DVertexShaderHandle hOldVS, unsigned int uiDeclEntryCount, 
        unsigned int* puiDeclaration);
    virtual void ReleaseVertexShader(NiD3DVertexShaderHandle hVS);
#endif  //#if defined(_XBOX) && !defined(_XENON)
    // *** end NDL internal use only ***

protected:
    static NiD3DShaderProgramFactory* ms_pkFactory;

    // We are only allowing one directory at this stage
    // TODO. Make this stuff thread safe!!!!
    NiTPointerList<char*> m_kProgramDirectories;

    // Maps for shader program names to shaders.
    NiTStringPointerMap<NiD3DVertexShader*>* m_pkVertexShaderMap;
    NiTStringPointerMap<NiD3DPixelShader*>* m_pkPixelShaderMap;

    static void CreateShaderCreatorMap();
    static NiTStringPointerMap<NiD3DShaderProgramCreator*>* 
        ms_pkShaderCreators;

#if defined(_XBOX)
    // Used for creating 'fixed-function shaders' (for supporting
    // compressed vertices in the fixed-function pipeline)
    // Fixed-function shader information helper class
    class FFShaderInfo
    {
    public:
        FFShaderInfo();
        FFShaderInfo(unsigned int uiDeclarationCount, DWORD* pdwDeclaration, 
            unsigned int uiVSHandle);
        ~FFShaderInfo();

        const unsigned int GetVSHandle() const;
        const unsigned int GetDeclarationCount() const;
        const DWORD* GetDeclaration() const;

        void SetVSHandle(unsigned int uiVSHandle);
        void SetDeclaration(unsigned int uiDeclarationCount, 
            DWORD* pdwDeclaration);

        const int GetRefCount() const;
        int IncRefCount();
        int DecRefCount();

    protected:
        int m_iRefCount;
        unsigned int m_uiVSHandle;
        unsigned int m_uiDeclarationCount;
        DWORD* m_pdwDeclaration;
    };

    // This is a safety-catch function, to free any dangling FFShaders.
    void ClearFFShaderList();

    NiTPointerList<FFShaderInfo*> m_kFFShaderList;

#endif  //#if defined(_XBOX)
};

typedef NiPointer<NiD3DShaderProgramFactory> NiD3DShaderProgramFactoryPtr;

#include "NiD3DShaderProgramFactory.inl"

#endif  //#ifndef NID3DSHADERPROGRAMFACTORY_H
