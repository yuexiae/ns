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

#ifndef NID3DRENDERSTATE_H
#define NID3DRENDERSTATE_H

#include "NiD3DDefines.h"

#if defined(_XENON)
    #if defined(D3DCOMPILE_USEFIXEDFUNCTION)
        #pragma message("NiD3DRenderState> D3DCOMPILE_USEFIXEDFUNCTION "\
            "is defined")
    #else   //#if defined(D3DCOMPILE_USEFIXEDFUNCTION)
        #pragma message("NiD3DRenderState> D3DCOMPILE_USEFIXEDFUNCTION "\
            "is not defined")
    #endif  //#if defined(D3DCOMPILE_USEFIXEDFUNCTION)
    #include "NiXenonMaterialManager.h"
#elif defined(_XBOX)
    #include "NiXBoxMaterialManager.h"
#elif defined(_DX9)
    #include "NiDX9MaterialManager.h"
#elif defined(_DX8)
    #include "NiDX8MaterialManager.h"
#else
    #error _XENON, _XBOX, _DX9, or _DX8 must be specified
#endif

#include "NiD3DShaderConstantManager.h"

#include <NiPropertyState.h>
#include <NiAlphaProperty.h>
#include <NiStencilProperty.h>
#include <NiSmartPointer.h>
#include <NiRefObject.h>
#include <NiZBufferProperty.h>
#include <NiColor.h>

class NiMatrix3;
class NiPoint3;
class NiFogProperty;
class NiDitherProperty;
class NiMaterialProperty;
class NiShadeProperty;
class NiSpecularProperty;
class NiTransform;
class NiWireframeProperty;

class NID3D_ENTRY NiD3DRenderState : public NiRefObject
{
    // *** begin NDL internal use only ***
public:
    void SetD3DDevice(D3DDevicePtr pkD3DDevice);
    void SetD3DRenderer(NiD3DRenderer* pkD3DRenderer);
    // *** end NDL internal use only ***

public:
    enum NiD3DRenderStateCaps
    {
        CAPS_TABLE_FOG      = 0x00000001,
        CAPS_HW             = 0x00000002,
        CAPS_STENCIL        = 0x00000004,
        CAPS_ZBUFFER        = 0x00000008,
        CAPS_WBUFFER        = 0x00000010,
        CAPS_IND_UV_WRAP    = 0x00000020
    };

    enum NiD3DSamplerState
    {
        NISAMP_INVALID          = -1,
        NISAMP_ADDRESSU         = 0, 
        NISAMP_ADDRESSV, 
        NISAMP_ADDRESSW, 
        NISAMP_BORDERCOLOR, 
        NISAMP_MAGFILTER, 
        NISAMP_MINFILTER, 
        NISAMP_MIPFILTER, 
        NISAMP_MIPMAPLODBIAS, 
        NISAMP_MAXMIPLEVEL, 
        NISAMP_MAXANISOTROPY, 
        //*** DX9-only start
        NISAMP_SRGBTEXTURE, 
        NISAMP_ELEMENTINDEX, 
        NISAMP_DMAPOFFSET, 
        //*** DX9-only end
        //*** Xbox-only start
        NISAMP_ALPHAKILL, 
        NISAMP_COLORKEYOP, 
        NISAMP_COLORSIGN, 
        NISAMP_COLORKEYCOLOR,
        //*** Xbox-only end
        // New ones go ABOVE here
        NISAMP_TOTAL_COUNT,
    };

protected:
    NiD3DRenderState(NiD3DRenderer* pkD3DRenderer);

public:
    virtual ~NiD3DRenderState();

    // Update render states according to the given property
    virtual void UpdateRenderState(const NiPropertyState* pkNew);

    // public to allow TexturePipeline to override for multipass
    virtual void ApplyAlpha(const NiAlphaProperty* pkNew);
    virtual void ApplyDitherMode(const NiDitherProperty* pkNew);
    virtual void ApplyFog(const NiFogProperty* pkNew);
    virtual void ApplyMaterial(NiMaterialProperty* pkNew);
    virtual void ApplyShading(const NiShadeProperty* pkNew);
    virtual void ApplySpecular(const NiSpecularProperty* pkNew);
    virtual void ApplyStencil(const NiStencilProperty* pkNew);
    virtual void ApplyWireframe(const NiWireframeProperty* pkNew);
    virtual void ApplyZBuffer(const NiZBufferProperty* pkNew);

    //*** Helper functions
    // Alpha
    virtual void DisableAlpha();
    unsigned int GetSrcAlphaCaps();
    unsigned int GetDestAlphaCaps();
    unsigned int GetD3DBlendMode(NiAlphaProperty::AlphaFunction eBlend);
    unsigned int GetD3DTestMode(NiAlphaProperty::TestFunction eTest);

    // Transformation relative
    virtual void SetBoneCount(unsigned short usNumBones);
    virtual void SetModelTransform(const NiTransform& kXform);

    // Z Bias
    virtual unsigned int GetZBias();
    virtual void SetZBias(unsigned int uiZBias);

    // 
    virtual void SetAntiAlias(bool bOn);
    virtual void SetWBuffer(bool bOn);

    // Fog
    virtual float GetMaxFogValue();
    virtual void SetMaxFogValue(float fFogVal);

    // Camera
    virtual void SetCameraNearAndFar(float fNear, float fFar);
    virtual bool GetLeftHanded();
    virtual void SetLeftHanded(bool bLeft);

    // Purge a material from the system
    virtual void PurgeMaterial(NiMaterialProperty* pkMaterial);

    // Render State management
    virtual void InitRenderState();
    virtual void SaveRenderState();
    virtual void RestoreRenderState();

    virtual void SetRenderState(D3DRENDERSTATETYPE eState, 
        unsigned int uiValue, bool bSave = false);
    virtual unsigned int GetRenderState(D3DRENDERSTATETYPE eState) const;
    virtual void RestoreRenderState(D3DRENDERSTATETYPE eState);

    // Shader program management
    virtual void InitShaderState();
    virtual void SaveShaderState();
    virtual void RestoreShaderState();

    virtual void SetPixelShader(NiD3DPixelShaderHandle hShader, 
        bool bSave = false);
    virtual NiD3DPixelShaderHandle GetPixelShader() const;
    virtual void RestorePixelShader();
    virtual void ClearPixelShader(NiD3DPixelShaderHandle hShader);

    virtual void SetVertexShader(NiD3DVertexShaderHandle hShader, 
        bool bSave = false) = 0;
    virtual NiD3DVertexShaderHandle GetVertexShader() const = 0;
    virtual void RestoreVertexShader() = 0;
    virtual void ClearVertexShader(NiD3DVertexShaderHandle hShader) = 0;

    virtual void SetFVF(unsigned int uiFVF, bool bSave = false) = 0;
    virtual unsigned int GetFVF() const = 0;
    virtual void RestoreFVF() = 0;
    virtual void ClearFVF(unsigned int uiFVF) = 0;

    virtual void SetDeclaration(NiD3DVertexDeclaration hDeclaration, 
        bool bSave = false) = 0;
    virtual NiD3DVertexDeclaration GetDeclaration() const = 0;
    virtual void RestoreDeclaration() = 0;
    virtual void ClearDeclaration(NiD3DVertexDeclaration hDeclaration) = 0;

    // Texture Stage and Sampler State management
    virtual void InitTextureStageState();
    virtual void SaveTextureStageState();
    virtual void RestoreTextureStageState();

    virtual void SetTextureStageState(unsigned int uiStage, 
        D3DTEXTURESTAGESTATETYPE eState, unsigned int uiValue, 
        bool bSave = false);
    virtual unsigned int GetTextureStageState(unsigned int uiStage, 
        D3DTEXTURESTAGESTATETYPE eState) const;
    virtual void RestoreTextureStageState(unsigned int uiStage, 
        D3DTEXTURESTAGESTATETYPE eState);

    virtual void SetSamplerState(unsigned int uiStage, 
        NiD3DSamplerState eState, unsigned int uiValue, 
        bool bSave = false) = 0;
    virtual unsigned int GetSamplerState(unsigned int uiStage, 
        NiD3DSamplerState eState) = 0;
    virtual void RestoreSamplerState(unsigned int uiStage, 
        NiD3DSamplerState eState) = 0;

    // Texture management
    virtual void InitTextures();
    virtual void SetTexture(unsigned int uiStage, 
        D3DBaseTexturePtr pkTexture);
    virtual D3DBaseTexturePtr GetTexture(unsigned int uiStage);
    virtual void ClearTexture(D3DBaseTexturePtr pkTexture);

#if defined(_XBOX) && !defined(_XENON)
    virtual void InitPalettes();
    virtual void SetPalette(unsigned int uiStage, D3DPalettePtr pkPalette);
    virtual D3DPalettePtr GetPalette(unsigned int uiStage);
    virtual void ClearPalette(D3DPalettePtr pkPalette);

    // Stream management
    virtual void SetStreamSource(unsigned int uiStream, 
        D3DVertexBufferPtr pkStreamSource, unsigned int uiStride);
    virtual D3DVertexBufferPtr GetStreamSource(unsigned int uiStream, 
        unsigned int* puiStride);
    virtual void ClearStreamSource(D3DVertexBufferPtr pkStreamSource);
#endif  //#if defined(_XBOX) && !defined(_XENON)

    // Shader Constant management
    bool SetVertexShaderConstantB(unsigned int uiStartRegister,
        const BOOL* pbConstantData, unsigned int uiBoolCount, 
        bool bSave = false);
    bool GetVertexShaderConstantB(unsigned int uiStartRegister,
        BOOL* pbConstantData, unsigned int uiBoolCount);
    bool RestoreVertexShaderConstantB(unsigned int uiStartRegister, 
        unsigned int uiBoolCount);
    bool SetVertexShaderConstantF(unsigned int uiStartRegister,
        const float* pfConstantData, unsigned int uiFloat4Count, 
        bool bSave = false);
    bool GetVertexShaderConstantF(unsigned int uiStartRegister,
        float* pfConstantData, unsigned int uiFloat4Count);
    bool RestoreVertexShaderConstantF(unsigned int uiStartRegister, 
        unsigned int uiFloat4Count);
    bool SetVertexShaderConstantI(unsigned int uiStartRegister,
        const int* piConstantData, unsigned int uiInt4Count, 
        bool bSave = false);
    bool GetVertexShaderConstantI(unsigned int uiStartRegister,
        int* piConstantData, unsigned int uiInt4Count);
    bool RestoreVertexShaderConstantI(unsigned int uiStartRegister, 
        unsigned int uiInt4Count);
    bool SetVertexShaderConstant(unsigned int uiStartRegister,
        const float* pfConstantData, unsigned int uiFloat4Count, 
        bool bSave = false);
    bool GetVertexShaderConstant(unsigned int uiStartRegister,
        float* pfConstantData, unsigned int uiFloat4Count);
    bool RestoreVertexShaderConstant(unsigned int uiStartRegister, 
        unsigned int uiFloat4Count);

    bool SetPixelShaderConstantB(unsigned int uiStartRegister,
        const BOOL* pbConstantData, unsigned int uiBoolCount, 
        bool bSave = false);
    bool GetPixelShaderConstantB(unsigned int uiStartRegister,
        BOOL* pbConstantData, unsigned int uiBoolCount);
    bool RestorePixelShaderConstantB(unsigned int uiStartRegister, 
        unsigned int uiBoolCount);
    bool SetPixelShaderConstantF(unsigned int uiStartRegister,
        const float* pfConstantData, unsigned int uiFloat4Count, 
        bool bSave = false);
    bool GetPixelShaderConstantF(unsigned int uiStartRegister,
        float* pfConstantData, unsigned int uiFloat4Count);
    bool RestorePixelShaderConstantF(unsigned int uiStartRegister, 
        unsigned int uiFloat4Count);
    bool SetPixelShaderConstantI(unsigned int uiStartRegister,
        const int* piConstantData, unsigned int uiInt4Count, 
        bool bSave = false);
    bool GetPixelShaderConstantI(unsigned int uiStartRegister,
        int* piConstantData, unsigned int uiInt4Count);
    bool RestorePixelShaderConstantI(unsigned int uiStartRegister, 
        unsigned int uiInt4Count);
    bool SetPixelShaderConstant(unsigned int uiStartRegister,
        const float* pfConstantData, unsigned int uiFloat4Count, 
        bool bSave = false);
    bool GetPixelShaderConstant(unsigned int uiStartRegister,
        float* pfConstantData, unsigned int uiFloat4Count);
    bool RestorePixelShaderConstant(unsigned int uiStartRegister, 
        unsigned int uiFloat4Count);

    virtual void SetSoftwareVertexProcessing(bool bSoftware);
    virtual bool GetSoftwareVertexProcessing() const;

    virtual void SetForceNormalizeNormals(bool bSet);
    virtual bool GetForceNormalizeNormals() const;

    // *** begin NDL internal use only ***
    virtual void SetInternalNormalizeNormals(bool bSet);
    virtual bool GetInternalNormalizeNormals() const;

    virtual void InitRenderModes();
    const unsigned int GetFlags();

    static unsigned int GetSamplerStateMapping(unsigned int uiSamplerState);

    void CommitShaderConstants();

    // *** end NDL internal use only ***

protected:
    // Flag management
    void ClearFlags();
    void ClearFlag(unsigned int uiFlag);
    void SetFlag(unsigned int uiFlag);
    void ToggleFlag(unsigned int uiFlag);
    void CopyFlag(unsigned int uiFlag, bool bSet);
    bool IsFlag(unsigned int uiFlag);
    bool IsNotFlag(unsigned int uiFlag);

    virtual void ReadRenderStateCaps() = 0;

    unsigned int m_uiFlags;
    bool m_bDefaultWBuffer;

    enum VertexBlendModes
    {
#if defined(_XENON)
        NIVBMODES_COUNT = 5
#elif defined(_XBOX)
        NIVBMODES_COUNT = D3DVBF_MAX
#elif defined(DX9)
        NIVBMODES_COUNT = 5
#else   //DX8
        NIVBMODES_COUNT = 5
#endif
    };

    D3DVERTEXBLENDFLAGS m_aD3DVertexBlendMappings[NIVBMODES_COUNT];

    // Alpha Blending Members
    unsigned int m_auiAlphaMapping[NiAlphaProperty::ALPHA_MAX_MODES];
    unsigned int m_auiAlphaTestMapping[NiAlphaProperty::TEST_MAX_MODES];
    unsigned int m_uiSrcAlphaCaps;
    unsigned int m_uiDestAlphaCaps;

    NiAlphaPropertyPtr m_spDisabledAlphaProperty;

    // Fog Members
    float m_fCameraNear;
    float m_fCameraFar;
    float m_fCameraDepthRange;
    float m_fMaxFogFactor;
    float m_fMaxFogValue;
    NiColor m_kCurrentFogColor;
    unsigned int m_uiCurrentFogColor;

    // Stencil Members
    unsigned int m_auiStencilTestMapping[NiStencilProperty::TEST_MAX];
    unsigned int m_auiStencilActionMapping[NiStencilProperty::ACTION_MAX];
    unsigned int m_auiCullModeMapping[NiStencilProperty::DRAW_MAX][2];
    unsigned int m_uiLeftHanded;

    // Material Members
    NiD3DMaterialManager m_kMaterials;

    // Z Buffer Members
    bool m_bWBufferActive;
    unsigned int m_auiZBufferTestMapping[NiZBufferProperty::TEST_MAX_MODES];

    //*** Render state tracking
    class NiRenderStateSetting
    {
    public:
        NiRenderStateSetting();

        // SetValue will attempt to change the render state
        void SetValue(unsigned int uiValue, bool bSave);

        // InitValue only sets m_dwCurrValue - should only be used to
        // initialize value to the default state.
        void InitValue(unsigned int uiValue);

        void SaveValue();
        void RestoreValue();

        unsigned int GetValue() const;
        unsigned int GetPrevValue() const;

    private:
        unsigned int m_uiCurrValue;
        unsigned int m_uiPrevValue;
    };

    // Ensure these value is always greater than the max DX values!
    enum 
    { 
#if defined(_XENON)
        NI_MAX_RENDER_STATES            = D3DRS_MAX,
        NI_MAX_TEXTURE_STAGE_STATES     = D3DTSS_MAX,
        NI_MAX_TEXTURE_SAMPLER_STATES   = D3DSAMP_MAX,
        // This number is not final.
        NI_MAX_TEXTURE_STAGES           = 4,
#elif defined(_XBOX)
        NI_MAX_RENDER_STATES        = D3DRS_MAX,
        NI_MAX_TEXTURE_STAGE_STATES = D3DTSS_MAX,
        NI_MAX_TEXTURE_STAGES       = 4,
#elif defined(_DX9)
        NI_MAX_RENDER_STATES        = 256,
        NI_MAX_TEXTURE_STAGE_STATES = 33,
        NI_MAX_TEXTURE_STAGES       = 16,
#else   //DX8
        NI_MAX_RENDER_STATES        = 256,
        NI_MAX_TEXTURE_STAGE_STATES = 32,
        NI_MAX_TEXTURE_STAGES       = 8,
#endif
    };

    // Initial Values
    // Render States
    class RenderStateInitialValue
    {
    public:
        D3DRENDERSTATETYPE m_eType;
        unsigned int m_uiValue;
    };

    static RenderStateInitialValue 
        ms_akInitialRenderStateSettings[NI_MAX_RENDER_STATES];

    // Texture Stage States
    class TextureStageStateInitialValue
    {
    public:
        D3DTEXTURESTAGESTATETYPE m_eType;
        unsigned int m_uiValue;
    };

    static TextureStageStateInitialValue 
        ms_akInitialTextureStageStateSettings[NI_MAX_TEXTURE_STAGE_STATES];

    // Sampler States
    class SamplerStateInitialValue
    {
    public:
        NiD3DSamplerState m_eType;
        unsigned int m_uiValue;
    };

    static SamplerStateInitialValue 
        ms_akInitialSamplerStateSettings[NISAMP_TOTAL_COUNT];

    // Tracking render states
    NiRenderStateSetting m_akRenderStateSettings[NI_MAX_RENDER_STATES];

    // Texture stage and sampler states
    NiRenderStateSetting m_akTextureStageStateSettings[
        NI_MAX_TEXTURE_STAGES][NI_MAX_TEXTURE_STAGE_STATES];
    NiRenderStateSetting m_akSamplerStateSettings[
        NI_MAX_TEXTURE_STAGES][NISAMP_TOTAL_COUNT];

    // These need to be defined on a platform basis (DX8/Xbox and DX9)
    static unsigned int ms_auiSamplesStateMappings[NISAMP_TOTAL_COUNT];

    // Textures
    D3DBaseTexturePtr m_apkTextureStageTextures[NI_MAX_TEXTURE_STAGES];

    // Shader programs
    NiD3DVertexShaderHandle m_hCurrentVertexShader;
    NiD3DVertexShaderHandle m_hPreviousVertexShader;
    NiD3DPixelShaderHandle m_hCurrentPixelShader;
    NiD3DPixelShaderHandle m_hPreviousPixelShader;

    // Shader Constant Manager
    NiD3DShaderConstantManagerPtr m_spShaderConstantManager;

#if defined(_XBOX) && !defined(_XENON)
    // Palettes
    D3DPalettePtr m_apkPalettes[NI_MAX_TEXTURE_STAGES];

    // Stream Sources
    class NiStreamSource
    {
    public:
        D3DVertexBufferPtr m_pkVB;
        unsigned int m_uiStride;
    };
    unsigned int m_uiMaxStreams;
    NiStreamSource* m_pkStreamSources;
#endif  //#if defined(_XBOX) && !defined(_XENON)

    // Flag to indicate NORMALIZENORMALS should be forced
    bool m_bForceNormalizeNormals;
    // This is the INTERNAL-ONLY version!
    bool m_bInternalNormalizeNormals;

protected:
    D3DDevicePtr m_pkD3DDevice;
    NiD3DRenderer* m_pkD3DRenderer;
};

typedef NiPointer<NiD3DRenderState> NiD3DRenderStatePtr;

#include "NiD3DRenderState.inl"

#endif  //#ifndef NID3DRENDERSTATE_H
