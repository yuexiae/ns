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

#ifndef NID3DTEXTURESTAGE_H
#define NID3DTEXTURESTAGE_H

#include "NiD3DDefines.h"
#include "NiD3DRenderState.h"
#include "NiD3DTextureStageGroup.h"
#include "NiD3DGlobalConstantEntry.h"
#include <NiTexturingProperty.h>

NiSmartPointer(NiD3DTextureStage);

class NiD3DPass;

// NiD3DTextureStage
// The texture stage class represents a single stage within a texture pass.
// 

class NID3D_ENTRY NiD3DTextureStage
{
protected:
    // Do not set these to anything. Use them only for accessing required
    // functionality. You may assume they will ALWAYS be valid.
    static D3DDevicePtr ms_pkD3DDevice;
    static NiD3DRenderer* ms_pkD3DRenderer;
    static NiD3DRenderState* ms_pkD3DRenderState;

    // *** begin NDL internal use only ***
    static void SetD3DDevice(D3DDevicePtr pkD3DDevice);
    static void SetD3DRenderState(NiD3DRenderState* pkRS);

public:
    static void SetD3DRenderer(NiD3DRenderer* pkD3DRenderer);
    // *** end NDL internal use only ***

public:
    enum TSTextureFlags
    {
        TSTF_IGNORE         = 0x00000000,
        // NDL Texturing Property Map to use
        TSTF_NONE           = 0x00100000,
        TSTF_NDL_BASE       = 0x00200000,
        TSTF_NDL_DARK       = 0x00300000,
        TSTF_NDL_DETAIL     = 0x00400000,
        TSTF_NDL_GLOSS      = 0x00500000,
        TSTF_NDL_GLOW       = 0x00600000,
        TSTF_NDL_BUMP       = 0x00700000,
        TSTF_NDL_TYPEMASK   = 0x00F00000,
        // Flags for map to use
        TSTF_MAP_DECAL      = 0x01000000,
        TSTF_MAP_SHADER     = 0x02000000,
        TSTF_MAP_MASK       = 0x0F000000,
        // Flag to indicate usage
        TSTF_MAP_USE_INDEX  = 0x10000000,
        TSTF_MAP_USE_MASK   = 0xF0000000,
        // Index for decals and shader maps
        TSTF_INDEX_MASK     = 0x0000FFFF,
    };

    enum TSTextureTransformFlags
    {
        TSTTF_IGNORE                = 0x00000000,
        TSTTF_GLOBAL                = 0x10000000,
        TSTTF_CONSTANT              = 0x20000000,
        TSTTF_SOURCE_MASK           = 0xf0000000,
        TSTTF_NI_NO_CALC            = 0x00000000,
        TSTTF_NI_WORLD_PARALLEL     = 0x00000001,
        TSTTF_NI_WORLD_PERSPECTIVE  = 0x00000002,
        TSTTF_NI_WORLD_SPHERE_MAP   = 0x00000003,
        TSTTF_NI_CAMERA_SPHERE_MAP  = 0x00000004,
        TSTTF_NI_SPECULAR_CUBE_MAP  = 0x00000005,
        TSTTF_NI_DIFFUSE_CUBE_MAP   = 0x00000006
    };

    NiD3DTextureStage();
    ~NiD3DTextureStage();

    static NiD3DTextureStagePtr CreateNewStage();

    //*** Access functions
    unsigned int GetStage();
    NiTexturePtr GetTexture();
    unsigned int GetTextureFlags();
    unsigned int GetTextureTransformFlags();
    bool GetUseIndexFromMap();

    NiD3DTextureStageGroup* GetTextureStageGroup();

    D3DMATRIX& GetTextureTransformation();

    void SetStage(unsigned int uiStage);
    void SetTexture(NiTexture* pkTexture);
    void SetTextureTransformFlags(unsigned int uiFlags, 
        const char* pszGlobalName = 0);
    void SetNDLMap(unsigned int uiNDLMap);
    void SetDecalMap(unsigned int uiDecal);
    void SetShaderMap(unsigned int uiShaderMap);
    void SetUseIndexFromMap(bool bUse);

    void SetStageState(unsigned int uiState, unsigned int uiValue,
        bool bSave = false);
    void SetSamplerState(unsigned int uiState, unsigned int uiValue,
        bool bSave = false);

    void RemoveStageState(unsigned int uiState);
    void RemoveSamplerState(unsigned int uiState);

    void SetTextureTransformation(D3DMATRIX& kD3DMat);
    void SetTextureTransformation(bool bUseTransform);
    bool IsTextureTransformation() const;

    // These will override the values in the NiD3DTextureStageGroup,
    // not necessarily on the device
    void SetClampMode(NiTexturingProperty::ClampMode eClamp);
    void SetFilterMode(NiTexturingProperty::FilterMode eFilter);

    //*** Pipeline Functions
    bool ConfigureStage(NiD3DPass* pkParentPass, 
        const NiTexturingProperty* pkTexProp);
    void DisableStage();
    static void DisableStage(unsigned int uiStage);

    // Apply functions
    void ApplyTexture(const NiTexturingProperty* pkTexProp);
    void ApplyTextureTransform();

    // *** begin NDL internal use only ***
    void SetTextureFlags(unsigned int uiFlags);

    void SetRendererOwned();
    bool IsRendererOwned() const;

    static void InitializePools();
    static void ShutdownPools();

    // For use with NiSmartPointers
    void IncRefCount();
    void DecRefCount();

    // *** end NDL internal use only ***

protected:
    bool CalculateTransformationMatrix(unsigned int uiCalculationMethod, 
        const D3DMATRIX* pkD3DMatSource);

    void ReturnStageToPool();

    // This will change the values on the device
    void ModifyFilterMode(bool bMipmap, bool bAllowMiplerp);

    unsigned int m_uiStage;
    NiTexturePtr m_spTexture;       //  Texture image (if used)
    unsigned int m_uiTextureFlags;

    NiD3DTextureStageGroup* m_pkTextureStageGroup;

    // Texture coordinate index
    unsigned int m_uiTexCoordIndex;
    bool m_bSaveTexCoordIndex;

    // Texture transformation members
    unsigned int m_uiTextureTransformFlags;
    NiD3DGlobalConstantEntry* m_pkGlobalEntry;
    D3DMATRIX m_kTextureTransformation;
    static D3DXMATRIX ms_kCalculatedTextureTransformation;

    // Internal flags
    bool m_bTextureTransform;
    bool m_bRendererOwned;
    unsigned int m_uiRefCount;

    static NiTPool<NiD3DTextureStage>* ms_pkTextureStagePool;
};

#include "NiD3DTextureStage.inl"

#endif  //#ifndef NID3DTEXTURESTAGE_H
