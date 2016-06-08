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
#ifndef NIDX8RENDERER_H
#define NIDX8RENDERER_H

#include "NiDX8Headers.h"
#include "NiDX8RendererLibType.h"

#include "NiGeometryBufferData.h"
#include "NiDX8Error.h"
#include "NiDX8LightManager.h"
#include "NiDX8PixelFormat.h"
#include "NiDX8RendererSDM.h"
#include "NiDX8RenderState.h"
#include "NiDX8RenderTarget.h"
#include "NiDX8ShaderDeclaration.h"
#include "NiD3DDefaultShader.h"
#include "NiD3DShaderInterface.h"
#include "NiD3DShaderLibraryVersion.h"
#include "NiD3DUtils.h"

#include <NiUniversalTypes.h>
#include <NiAccumulator.h>
#include <NiBool.h>
#include <NiColor.h>
#include <NiTexture.h>
#include <NiDynamicEffect.h>
#include <NiDynamicEffectState.h>
#include <NiPropertyState.h>
#include <NiRect.h>
#include <NiRenderer.h>
#include <NiSkinInstance.h>
#include <NiTPointerList.h>

class NiAVObject;
class NiBound;
class NiPoint3;
class NiPoint2;
class NiPlane;
class NiCamera;
class NiFrustum;
class NiGeometryData;
class NiTriShapeData;
class NiTriStripsData;
class NiParticlesData;
class NiLinesData;
class NiTexture;
NiSmartPointer(NiPixelData);

//  DX8 Specific classes
class NiDX8AdapterDesc;
class NiDX8DeviceDesc;
class NiDX8SystemDesc;
class NiDX8VertexBufferManager;
class NiDX8IndexBufferManager;
class NiDX8TextureManager;
class NiDX8TextureStage;
class NiDX8TexturePass;
class NiDX8BltSourceData;
class NiDX8ConfigurableTexturePipeline;
class NiDX8TextureData;
class NiDX8SourceTextureData;
class NiDX8RenderedCubeMapData;
class NiDX8RenderedTextureData;
class NiRendererExtraData;
class NiDynamicGeometryGroup;
class NiUnsharedGeometryGroup;
class NiD3DGeometryGroupManager;
class NiVBBlock;

// DX8 ID Number (Must be unique to all renderers).
enum { NI_DX8_RENDER_ID = 7 };

typedef IDirect3D8* (CALLBACK *NILPD3DCREATE) (unsigned int);

class NIDX8RENDERER_ENTRY NiDX8Renderer : public NiRenderer
{
    NiDeclareRTTI;

public:
    //  Misc flags for creation options.
    enum FlagType
    {
        USE_NOFLAGS                      = 0x00000000,
        USE_MANUALDEPTHSTENCIL           = 0x00000001,
        USE_FORCE_MULTIPASS_MULTITEXTURE = 0x00000002,
        USE_FULLSCREEN                   = 0x00000004,
        USE_STENCIL                      = 0x00000008,
        USE_16BITBUFFERS                 = 0x00000010,
        USE_MULTITHREADED                = 0x00000020,
        USE_FPU_PRESERVE                 = 0x00000040
    };

    enum SwapEffect
    {
        SWAPEFFECT_DEFAULT,
        SWAPEFFECT_DISCARD,
        SWAPEFFECT_FLIP,
        SWAPEFFECT_COPY,
        SWAPEFFECT_COPY_VSYNC,
        SWAPEFFECT_NUM
    };

    enum DeviceDesc
    {
        DEVDESC_PURE,
        DEVDESC_HAL_HWVERTEX,
        DEVDESC_HAL_MIXEDVERTEX,
        DEVDESC_HAL_SWVERTEX,
        DEVDESC_REF,
        DEVDESC_NUM
    };

    //  DX8 supported refresh rate defines
    enum RefreshRate
    {
        REFRESHRATE_DEFAULT   = 0,
        REFRESHRATE_UNLIMITED = 0xFFFFFFFF
    };

    enum PresentationInterval
    {
        PRESENT_INTERVAL_IMMEDIATE = 0,
        PRESENT_INTERVAL_ONE = 1,
        PRESENT_INTERVAL_TWO = 2,
        PRESENT_INTERVAL_THREE = 3,
        PRESENT_INTERVAL_FOUR = 4,
        PRESENT_INTERVAL_NUM
    };

    enum FramebufferMode
    {
        FBMODE_DEFAULT,
        FBMODE_LOCKABLE,
        FBMODE_MULTISAMPLES_2,
        FBMODE_MULTISAMPLES_3,
        FBMODE_MULTISAMPLES_4,
        FBMODE_MULTISAMPLES_5,
        FBMODE_MULTISAMPLES_6,
        FBMODE_MULTISAMPLES_7,
        FBMODE_MULTISAMPLES_8,
        FBMODE_MULTISAMPLES_9,
        FBMODE_MULTISAMPLES_10,
        FBMODE_MULTISAMPLES_11,
        FBMODE_MULTISAMPLES_12,
        FBMODE_MULTISAMPLES_13,
        FBMODE_MULTISAMPLES_14,
        FBMODE_MULTISAMPLES_15,
        FBMODE_MULTISAMPLES_16,
        FBMODE_NUM
    };

    //  DX8 supported frame buffer formats
    enum FrameBufferFormat
    {
        FBFMT_UNKNOWN = 0,
        FBFMT_R8G8B8,
        FBFMT_A8R8G8B8,
        FBFMT_X8R8G8B8,
        FBFMT_R5G6B5,
        FBFMT_X1R5G5B5,
        FBFMT_A1R5G5B5,
        FBFMT_A4R4G4B4,
        FBFMT_R3G3B2,
        FBFMT_A8,
        FBFMT_A8R3G3B2,
        FBFMT_X4R4G4B4,
        FBFMT_NUM
    };

    //  DX8 supported depth/stencil buffer formats
    //  Directly correlated for now
    enum DepthStencilFormat
    {
        DSFMT_UNKNOWN      =   0,
        DSFMT_D16_LOCKABLE =  70,
        DSFMT_D32          =  71,
        DSFMT_D15S1        =  73,
        DSFMT_D24S8        =  75,
        DSFMT_D16          =  80,
        DSFMT_D24X8        =  77,
        DSFMT_D24X4S4      =  79,
    };

    enum TexFormat
    {
        TEX_RGB555      = 0,
        TEX_RGB565      = 1,
        TEX_RGB888      = 2,
        TEX_RGBA5551    = 3,
        TEX_RGBA4444    = 4,
        TEX_RGBA8888    = 5,
        TEX_PAL8        = 6,
        TEX_PALA8       = 7,
        TEX_COMPRESS1   = 8,
        TEX_COMPRESS3   = 9,
        TEX_COMPRESS5   = 10,
        TEX_BUMP88      = 11,
        TEX_BUMPLUMA556 = 12,
        TEX_BUMPLUMA888 = 13,
        TEX_DEFAULT     = 14,
        TEX_NUM         = TEX_DEFAULT
    };

    enum TexUsage
    {
        TEXUSE_TEX,
        TEXUSE_RENDERED_TEX,
        TEXUSE_CUBE,
        TEXUSE_RENDERED_CUBE,
        TEXUSE_NUM
    };

    enum FramebufferStatus
    {
        FBSTATUS_OK,
        FBSTATUS_NOT_FOUND,
        FBSTATUS_NEEDS_RESET
    };

    enum RecreateStatus
    {
        RECREATESTATUS_FAILED,
        RECREATESTATUS_RESTORED,
        RECREATESTATUS_OK,
    };

    enum
    {
        HW_BONE_LIMIT = 4
    };

    // local constants -
    // construction and destruction
    virtual ~NiDX8Renderer();

    static NiDX8Renderer* Create(unsigned int uiWidth, unsigned int uiHeight,
        FlagType eFlags, NiWindowRef kWndDevice, NiWindowRef kWndFocus,         
        unsigned int uiAdapter = D3DADAPTER_DEFAULT, 
        DeviceDesc eDesc = DEVDESC_PURE,
        FrameBufferFormat eFBFormat = FBFMT_UNKNOWN, 
        DepthStencilFormat eDSFormat = DSFMT_UNKNOWN, 
        PresentationInterval ePresentationInterval = PRESENT_INTERVAL_ONE,
        SwapEffect eSwapEffect = SWAPEFFECT_DEFAULT,
        unsigned int uiFBMode = FBMODE_DEFAULT,
        unsigned int uiBackBufferCount = 1, 
        unsigned int uiRefreshRate = REFRESHRATE_DEFAULT);

    RecreateStatus Recreate(unsigned int uiWidth, unsigned int uiHeight,
        FlagType eFlags, NiWindowRef kWndDevice = 0, 
        FrameBufferFormat eFBFormat = FBFMT_UNKNOWN, 
        DepthStencilFormat eDSFormat = DSFMT_UNKNOWN, 
        PresentationInterval ePresentationInterval = PRESENT_INTERVAL_ONE,
        SwapEffect eSwapEffect = SWAPEFFECT_DEFAULT,
        unsigned int uiFBMode = FBMODE_DEFAULT,
        unsigned int uiBackBufferCount = 1, 
        unsigned int uiRefreshRate = REFRESHRATE_DEFAULT);

    RecreateStatus Recreate(unsigned int uiWidth, unsigned int uiHeight);

    bool Recreate();

    typedef bool (*RESETNOTIFYFUNC)(bool bBeforeReset, void* pvData);

    unsigned int AddResetNotificationFunc(RESETNOTIFYFUNC pfnNotify,
        void* pvData);
    bool RemoveResetNotificationFunc(RESETNOTIFYFUNC pfnNotify);
    bool RemoveResetNotificationFunc(unsigned int uiIndex);
    void RemoveAllResetNotificationFuncs();

    bool ChangeResetNotificationFuncData(RESETNOTIFYFUNC pfnNotify,
        void* pvData);
    bool ChangeResetNotificationFuncData(unsigned int uiIndex,
        void* pvData);

    unsigned int GetResetNotificationFuncCount() const;
    unsigned int GetResetNotificationFuncArrayCount() const;
    unsigned int FindResetNotificationFunc(RESETNOTIFYFUNC pfnNotify);
    RESETNOTIFYFUNC GetResetNotificationFunc(unsigned int uiIndex);

    typedef bool (*LOSTDEVICENOTIFYFUNC)(void* pvData);

    unsigned int AddLostDeviceNotificationFunc(LOSTDEVICENOTIFYFUNC pfnNotify,
        void* pvData);
    bool RemoveLostDeviceNotificationFunc(LOSTDEVICENOTIFYFUNC pfnNotify);
    bool RemoveLostDeviceNotificationFunc(unsigned int uiIndex);
    void RemoveAllLostDeviceNotificationFuncs();

    bool ChangeLostDeviceNotificationFuncData(LOSTDEVICENOTIFYFUNC pfnNotify,
        void* pvData);
    bool ChangeLostDeviceNotificationFuncData(unsigned int uiIndex,
        void* pvData);

    unsigned int GetLostDeviceNotificationFuncCount() const;
    unsigned int GetLostDeviceNotificationFuncArrayCount() const;
    unsigned int FindLostDeviceNotificationFunc(
        LOSTDEVICENOTIFYFUNC pfnNotify);
    LOSTDEVICENOTIFYFUNC GetLostDeviceNotificationFunc(unsigned int uiIndex);

    void GetCreationParameters(unsigned int& uiWidth, unsigned int& uiHeight,
        FlagType& eFlags, NiWindowRef& kWndDevice, NiWindowRef& kWndFocus,         
        unsigned int& uiAdapter, DeviceDesc& eDesc, 
        FrameBufferFormat& eFBFormat, DepthStencilFormat& eDSFormat, 
        PresentationInterval& ePresentationInterval, SwapEffect& eSwapEffect,
        unsigned int& uiFBMode, unsigned int& uiBackBufferCount, 
        unsigned int& uiRefreshRate) const;

    bool CreateWindowedFramebuffer(FlagType eFlags, NiWindowRef kWndDevice, 
        FrameBufferFormat eFBFormat = FBFMT_UNKNOWN, 
        DepthStencilFormat eDSFormat = DSFMT_UNKNOWN, 
        PresentationInterval ePresentationInterval = PRESENT_INTERVAL_ONE,
        SwapEffect eSwapEffect = SWAPEFFECT_DEFAULT,
        unsigned int uiFBMode = FBMODE_DEFAULT,
        unsigned int uiBackBufferCount = 1, 
        unsigned int uiRefreshRate = REFRESHRATE_DEFAULT);
    void DestroyWindowedFramebuffer(NiWindowRef kWndDevice);

    // String describing renderer
    virtual const char* GetDriverInfo();
    virtual const NiPixelFormat* 
        FindClosestPixelFormat(NiTexture::FormatPrefs& kFmtPrefs);

    // Renderer capabilities
    virtual unsigned int GetFlags();
    virtual bool IsTextureFormatAvailable(NiPixelFormat& kPixelFmt);

    // Buffer access and management methods
    virtual bool SetRenderTarget(NiRenderedTexture* pkBuffer = NULL);
    FramebufferStatus UseWindowedFramebuffer(NiWindowRef kWndDevice);

    bool SetRenderDepthTarget(NiDX8RenderTarget* pkRenderTarget);

    virtual void SwapBuffers();
    virtual void ClearBuffer(const NiRect<float>* pkR, unsigned int uiMode);

    virtual bool GetLeftRightSwap();
    virtual bool SetLeftRightSwap(bool bSwap);
    virtual bool SetUseWBuffer(bool bWBuffer);

    virtual unsigned int GetBackbufferWidth();
    virtual unsigned int GetBackbufferHeight();
    virtual unsigned int GetBackbufferBitsPerPixel();
    const NiDX8PixelFormat* GetBackbufferPixelFormat();

    virtual NiPixelData* TakeScreenShot(
        const NiRect<unsigned int>* pkScreenRect);

    virtual void ImageBlt(NiBltSource* pkBlt,
        const NiRect<unsigned int>* pkSrc, 
        unsigned int uiDestX, unsigned int uiDestY);

    // Buffer clear values
    virtual void SetDepthClear(const float fZClear);
    virtual void SetBackgroundColor(const NiColor& kColor);
    virtual void SetBackgroundColor(const NiColorA& kColor);
    virtual void GetBackgroundColor(NiColorA& kColor);
    virtual void SetStencilClear(unsigned int uiClear);

    //  ZBiasing
    unsigned int GetZBias();
    void SetZBias(unsigned int uiZBias);

    void UseQuickDecals(bool bQuickDecals);

    // Global fog settings
    // This base version signals that changing the value is not supported
    // Subclasses may overide this to indicate that changing the value is
    // supported
    virtual float GetMaxFogValue();
    virtual void SetMaxFogValue(float fFogVal);

    // Texture memory management precaching and purgeing    
    virtual bool PrecacheTexture(NiTexture* pkIm, bool bForceLoad = false, 
        bool bLocked = false);
    virtual bool PurgeAllTextures(bool bPurgeLocked);
    virtual bool PurgeTexture(NiTexture* pkIm);

    // Texture memory management statistics
    virtual bool GetTextureMemoryStats(unsigned int& uiTotal,
        unsigned int& uiAvail);
    virtual bool GetTextureStats(unsigned int& uiLoadedTextures,
        unsigned int& uiUsedTextures,
        unsigned int& uiStateChanges,
        unsigned int& uiNewTextures,
        unsigned int& uiEvictedTextures);
    virtual unsigned int GetTextureManagerStatus();

    // Texture mipmap skip level
    virtual bool SetMipmapSkipLevel(unsigned int uiSkip);
    virtual unsigned int GetMipmapSkipLevel();

    const NiDX8PixelFormat& GetScreenPixelFormat();

    // Precaching geometry
    virtual bool PrecacheGeometry(NiGeometry* pkGeometry, 
        unsigned int uiFlags, void* pvExtraData, 
        unsigned int uiBonesPerPartition = 0, 
        unsigned int uiBonesPerVertex = 0);

    void PerformPrecache();

    // Creating a shader declaration
    NiDX8ShaderDeclaration* Create(bool bFixedFunction, 
        unsigned int uiMaxStreamEntryCount, unsigned int uiStreamCount = 1);
    // Wrapping an NiTexture around an IDirect3DBaseTexture8
    NiTexturePtr CreateNiTextureFromD3DTexture(
        LPDIRECT3DBASETEXTURE8 pkD3DTexture);
    bool RecreateNiTextureFromD3DTexture(NiTexture* pkTexture,
        LPDIRECT3DBASETEXTURE8 pkD3DTexture);


    // *** begin NDL internal use only ***

    static int NiUseDX8();

    // Rendering start/end
    virtual void BeginPaint();
    virtual void EndPaint();
    bool GetSceneOpen() const;

    // Camera state
    virtual void SetCameraData (const NiPoint3& kLoc,
        const NiPoint3& kDir, const NiPoint3& kUp, const NiPoint3& kRight,
        const NiFrustum& kFrustum, const NiRect<float>& kPort);

    // Model state
    void SetModelTransform(const NiTransform& kXform, 
        bool bPushToDevice = true);
    void SetSkinnedModelTransforms(const NiSkinInstance* pkSkin,
        const NiSkinPartition::Partition* pkPartition,
        const NiTransform& kWorld);
    void CalculateBoneMatrices(const NiSkinInstance* pkSkinInstance, 
        const NiTransform& kWorld, bool bTranspose = false, 
        unsigned int uiBoneMatrixRegisters = 4, 
        bool bPalettizedBones = false);

    // Deprecated; use new CalculateBoneMatrices instead.
    void CalculatePalettizedBoneMatrices(
        const NiSkinInstance* pkSkinInstance, const NiTransform& kWorld, 
        unsigned int uiBoneMatrixRegisters);

    // Primitive rendering
    virtual void RenderShape(NiTriShape* pkTriShape);
    virtual void RenderTristrips(NiTriStrips* pkTriStrips);
    virtual void RenderPoints(NiParticles* pkParticles);
    virtual void RenderLines(NiLines* pkLines);
    virtual void RenderScreenPoly(NiScreenPolygon* pkPoly);
    virtual void RenderScreenTexture(NiScreenTexture* pkScreenTexture);

    // Batch rendering
    virtual void BeginBatch(NiPropertyState* pkPropertyState,
        NiDynamicEffectState* pkEffectState);
    virtual void EndBatch();
    virtual void BatchRenderShape(NiTriShape* pkTriShape);
    virtual void BatchRenderStrips(NiTriStrips* pkTriStrips);

    void DrawPrimitive(NiGeometry* pkGeometry, NiGeometryData* pkData, 
        NiSkinInstance* pkSkinInstance, const NiTransform& kWorld, 
        const NiBound& kWorldBound, NiGeometryBufferData* pkBuffData);
    void DrawSkinnedPrimitive(NiGeometry* pkGeometry, NiGeometryData* pkData, 
        const NiSkinInstance* pkSkinInstance, const NiTransform& kWorld, 
        const NiBound& kWorldBound);

    // Vertex description
    enum
    {
        VERTEX_FLAG_DX_TEXTUREMASK              = 0xFF000000,
        VERTEX_FLAG_DX_TEXTURESHIFT             = 24,
        VERTEX_FLAG_DX_HASNORMALS               = 0x00800000
    };

    static bool GetHasNormalsFromFlags(unsigned int uiFlags);
    static void SetHasNormalsFromFlags(bool bHasNormals, 
        unsigned int& uiFlags);
    static unsigned int GetNumUVsFromFlags(unsigned int uiFlags);
    static void SetNumUVsInFlags(unsigned int uiUVCount, 
        unsigned int& uiFlags);

    // Free data once packed
    void FreeGeometricData(unsigned int uiFlags, NiGeometryData* pkData, 
        NiSkinInstance* pkSkin, NiSkinPartition::Partition* pkPartition);

    // cached geometry data handling
    virtual void PurgeEffect(NiDynamicEffect* pkEffect);
    virtual void PurgeGeometryData(NiGeometryData* pkData);
    virtual void PurgeMaterial(NiMaterialProperty* pkMaterial);
    virtual void PurgeScreenTextureRendererData(
        NiScreenTexture* pkScreenTexture);
    virtual void PurgeSkinPartitionRendererData(
        NiSkinPartition* pkSkinPartition);
    virtual void PurgeScreenPolygon(NiScreenPolygon* pkPoly);
    virtual void PurgeSkinInstance(NiSkinInstance* pkSkinInstance);

    virtual void PurgeVertexShader(NiD3DVertexShader* pkShader);
    virtual void PurgePixelShader(NiD3DPixelShader* pkShader);

    virtual void RegisterD3DShader(NiD3DShaderInterface* pkD3DShader);
    virtual void ReleaseD3DShader(NiD3DShaderInterface* pkD3DShader);
    virtual void PurgeD3DShader(NiD3DShaderInterface* pkD3DShader);

    static void PrepareForStreaming(NiObjectNET* pkRoot);
    static void RestoreAfterStreaming();

    virtual void PurgeAllD3DShaders();

    LPDIRECT3DDEVICE8 GetD3DDevice8();
    LPDIRECT3DDEVICE8 GetD3DDevice();
    NiDX8RenderState* GetRenderState();
    NiDX8VertexBufferManager* GetVBManager();

    unsigned int GetMaxStreams() const;
    unsigned int GetPixelShaderVersion() const;
    unsigned int GetVertexShaderVersion() const;
    bool GetMipmapCubeMaps() const;

    bool GetSWVertexCapable() const;
    bool GetSWVertexSwitchable() const;

    // Renderer specific data for textures and palettes
    virtual bool CreateSourceTextureRendererData(NiSourceTexture* pkTexture);
    virtual bool CreateRenderedTextureRendererData(
        NiRenderedTexture* pkTexture);
    virtual bool CreateRenderedCubeMapRendererData(
        NiRenderedCubeMap* pkTexture);
    virtual bool CreateSourceCubeMapRendererData(
        NiSourceCubeMap* pkTexture);
    virtual void CreatePaletteRendererData(NiPalette* pkPalette);
    virtual bool CreateBltSourceRendererData(NiBltSource* pkBlt);

    void RemoveRenderedCubeMapData(NiRenderedCubeMap* pkCubeMap);
    void RemoveRenderedTextureData(NiRenderedTexture* pkTexture);

    static unsigned char GetD3DFormatSize(D3DFORMAT eFormat);
    static D3DFORMAT GetD3DFormat(FrameBufferFormat eFBFormat);
    static NiDX8Renderer::FrameBufferFormat GetNiFBFormat(
        D3DFORMAT kFormat);
    static D3DFORMAT GetD3DFormat(DepthStencilFormat eDSFormat);
    static NiDX8Renderer::DepthStencilFormat GetNiDSFormat(
        D3DFORMAT kFormat);
    static bool Is16BitDepthFormat(DepthStencilFormat eFormat);
    static D3DMULTISAMPLE_TYPE GetMultiSampleType(unsigned int uiMode);
    static D3DSWAPEFFECT GetSwapEffect(SwapEffect eMode, 
        unsigned int uiFBMode, FlagType eFlags);
    static unsigned int GetRefreshRate(unsigned int uiRefreshRateHz);
    static unsigned int GetPresentInterval(
        PresentationInterval ePresentationInterval);

    NiDX8RenderState* GetRenderState() const;
    NiDX8TextureManager* GetTextureManager() const;
    NiDX8LightManager* GetLightManager() const;

    NiDX8PixelFormat** GetTextureFormatArray(TexUsage eUse);
    NiDX8PixelFormat* GetDefaultTextureFormat(TexUsage eUse);
    NiPixelData* GetDefaultTextureData(TexUsage eUse);
    DepthStencilFormat GetTextureDepthStencil(TexFormat eFmt);

    TexFormat GetReplacementDataFormat() const;

    NiTexture* GetClipperTexture();

    unsigned int GetAdapter();
    D3DDEVTYPE GetDevType();
    D3DPRESENT_PARAMETERS* GetPresentParams();
    static const NiDX8SystemDesc* GetSystemDesc();
    static LPDIRECT3D8 GetDirect3D();
    const NiDX8AdapterDesc* GetAdapterDesc() const;
    const NiDX8DeviceDesc* GetDeviceDesc() const;

    const D3DCAPS8* GetDeviceCaps() const;

    const D3DMATRIX& GetD3DMat() const;
    const D3DMATRIX& GetD3DView() const;
    const D3DMATRIX& GetD3DProj() const;
    const D3DMATRIX& GetInvView() const;

    // This is to be considered 'internal only'
    D3DXALIGNEDMATRIX* GetD3DWorld();

    unsigned int GetResetCounter() const;
    bool IsDeviceLost() const;

    // Shader version information
    void SetMinPixelShaderVersion(unsigned int uiMaj, unsigned int uiMin);
    void SetPixelShaderVersionRequest(unsigned int uiMaj, 
        unsigned int uiMin);
    void SetMinVertexShaderVersion(unsigned int uiMaj, unsigned int uiMin);
    void SetVertexShaderVersionRequest(unsigned int uiMaj, 
        unsigned int uiMin);
    void SetSystemUserVersion(unsigned int uiMaj, unsigned int uiMin);
    void SetMinUserVersion(unsigned int uiMaj, unsigned int uiMin);
    void SetUserVersionRequest(unsigned int uiMaj, unsigned int uiMin);
    unsigned int GetMinPixelShaderVersion();
    unsigned int GetPixelShaderVersionRequest();
    unsigned int GetMinVertexShaderVersion();
    unsigned int GetVertexShaderVersionRequest();
    unsigned int GetMinUserVersion();
    unsigned int GetUserVersionRequest();

    NiD3DShaderLibraryVersion* GetShaderLibraryVersion();

    //  Message/Warning/Error reporting functions
    static void Message(const char* pcFormat, ...);
    static void Warning(const char* pcFormat, ...);
    static void Error(const char* pcFormat, ...);

    static void _SDMShutdown();

    bool PackGeometryBuffer(NiGeometryBufferData* pkBuffData,
        NiGeometryData* pkData, NiSkinInstance* pkSkinInstance = 0,
        NiD3DShaderDeclaration* pkShaderDecl = 0,
        NiRendererExtraData* pkExtraData = 0, bool bForce = false);
    bool PackSkinnedGeometryBuffer(NiGeometryBufferData* pkBuffData, 
        NiGeometryData* pkData, const NiSkinInstance* pkSkin, 
        NiSkinPartition::Partition* pkPartition, 
        NiD3DShaderDeclaration* pkShaderDecl = 0, 
        NiRendererExtraData* pkExtraData = 0, bool bForce = false);

    typedef struct 
    {
        D3DTEXTUREADDRESS m_eU;
        D3DTEXTUREADDRESS m_eV;
    } AddressSettings;

    class FilterSettings 
    {
    public:
        D3DTEXTUREFILTERTYPE m_eMin;
        D3DTEXTUREFILTERTYPE m_eMag;
        D3DTEXTUREFILTERTYPE m_eMip;
    };

    static AddressSettings GetD3DClampMode(
        NiTexturingProperty::ClampMode eClamp);
    static FilterSettings GetD3DFilterMode(
        NiTexturingProperty::FilterMode eFilter);
    static unsigned int GetProjectedTextureFlags();

    // *** end NDL internal use only ***

protected:
    enum { SimpleLineVertexFVF = D3DFVF_XYZ };
    typedef struct
    {
        float x;
        float y;
        float z;
    } SimpleLineVertex;

    enum { TexturedLineVertexFVF = D3DFVF_XYZ | D3DFVF_TEXCOORDSIZE2(0) | 
        D3DFVF_TEX1 };
    typedef struct
    {
        float x;
        float y;
        float z;
        float tu;
        float tv;
    } TexturedLineVertex;

    enum { ColoredLineVertexFVF = D3DFVF_XYZ | D3DFVF_DIFFUSE };
    typedef struct
    {
        float x;
        float y;
        float z;
        D3DCOLOR color;
    } ColoredLineVertex;


    enum { SourceVertexFVF = D3DFVF_XYZ | D3DFVF_DIFFUSE | 
        D3DFVF_TEXCOORDSIZE2(0) | D3DFVF_TEX1 };
    typedef struct
    {
        float x;
        float y;
        float z;
        D3DCOLOR color;
        float tu;
        float tv;
    } SourceVertex;

    enum { SourceNormalVertexFVF = D3DFVF_XYZ | D3DFVF_NORMAL | 
        D3DFVF_DIFFUSE | D3DFVF_TEXCOORDSIZE2(0) | D3DFVF_TEX1 };
    typedef struct
    {
        float x;
        float y;
        float z;
        float nx;
        float ny;
        float nz;
        D3DCOLOR color;
        float tu;
        float tv;
    } SourceNormalVertex;

    //  Start-up and shutdown related functions...
    NiDX8Renderer();
    bool Initialize(unsigned int uiWidth, unsigned int uiHeight,
        FlagType eFlags, NiWindowRef kWndDevice, NiWindowRef kWndFocus, 
        unsigned int uiAdapter, DeviceDesc eDesc,
        FrameBufferFormat eFBFormat, DepthStencilFormat eDSFormat, 
        PresentationInterval ePresentationInterval, SwapEffect eSwapEffect,
        unsigned int uiFBMode, unsigned int uiBackBufferCount,
        unsigned int uiRefreshRate);

    void InitToDefault();
    static bool IsD3D8Create();
    static int CreateDirect3D8();

    //  LostDevice handler
    bool LostDeviceRestore();

    //  'Check' functions
    bool InitializePresentParams(NiWindowRef kWndDevice, unsigned int uiWidth, 
        unsigned int uiHeight, FlagType eFlags, unsigned int uiFBMode, 
        FrameBufferFormat eFBFormat, DepthStencilFormat eDSFormat,
        unsigned int uiBackBufferCount, SwapEffect eSwapEffect, 
        unsigned int uiRefreshRate, 
        PresentationInterval ePresentationInterval,
        D3DPRESENT_PARAMETERS& kD3DPresentParams) const;

    bool InitializeTextureDefaults();
    bool InitializeDeviceCaps(const D3DPRESENT_PARAMETERS& kPresentParams);

    //  Conversion routines
    char* GetDevTypeString();
    char* GetBehaviorString();

    static bool ExpandDeviceType(DeviceDesc eDesc, D3DDEVTYPE& eDevType,
        unsigned int& uiBehaviorFlags);

    void PackScreenPolyGeomBuffer(NiScreenPolygon* pkScreenPoly,
        float fDepthMin, float fDepthRange);
    void PackScreenTextureGeomBuffer(NiScreenTexture* pkScreenTexture);

    void PackScreenTextureBuffers(NiScreenTexture* pkScreenTexture, 
        unsigned short usDirtyFlags);

    //  Prepacking...
    class PrePackObject
    {
    public:
        NiGeometryData* m_pkData;
        NiSkinInstance* m_pkSkin;
        NiSkinPartition::Partition* m_pkPartition;
        unsigned int m_uiFlags;
        void* m_pvExtraData;
        NiD3DShaderDeclaration* m_pkShaderDecl;
        NiRendererExtraData* m_pkExtraData;
        unsigned int m_uiBonesPerPartition;
        unsigned int m_uiBonesPerVertex;

        NiGeometryBufferData* m_pkBuffData;
        unsigned int m_uiStream;
        
        PrePackObject* m_pkNext;
    };

    bool PrePackGeometryBuffer(NiGeometry* pkGeom, NiGeometryData* pkData, 
        unsigned short usTriCount, const unsigned short* pusIndexArray, 
        const unsigned short* pusArrayLengths, unsigned short usArrayCount,
        unsigned int uiFlags, void* pvExtraData, 
        NiD3DShaderDeclaration* pkShaderDecl = 0, 
        NiRendererExtraData* pkExtraData = 0);
    bool PrePackSkinnedGeometryBuffer(NiGeometry* pkGeom, 
        NiGeometryData* pkData, NiSkinInstance* pkSkin, unsigned int uiFlags, 
        void* pvExtraData, NiD3DShaderDeclaration* pkShaderDecl = 0, 
        NiRendererExtraData* pkExtraData = 0, 
        unsigned int uiBonesPerPartition = 0, 
        unsigned int uiBonesPerVertex = 0);

    bool ReservePrepackedBufferSpace(NiGeometryBufferData* pkBuffData,
        NiGeometryData* pkData, NiSkinPartition::Partition* pkPartition, 
        NiD3DShaderDeclaration* pkShaderDecl, unsigned int uiFlags);

    // Batch handling
    void EmptyBatch();
    void RenderBatch();
    void AddToBatch(NiGeometry* pkGeometry);

    bool GenerateDefaultTextureData();

    bool IsHardwareSkinned(const NiGeometry* pkGeometry, 
        const NiD3DShaderInterface* pkShader = NULL);

    static LPDIRECT3D8 ms_pkD3D8;
    LPDIRECT3DDEVICE8 m_pkD3DDevice8;
    D3DCAPS8 m_kD3DCaps8;

    NiWindowRef m_kWndDevice;
    char m_acDriverDesc[512];
    unsigned int m_uiAdapter;
    D3DDEVTYPE m_eDevType;
    NiWindowRef m_kWndFocus;
    unsigned int m_uiBehaviorFlags;
    bool m_bSWVertexCapable;
    bool m_bSWVertexSwitchable;
    
    const static NiDX8SystemDesc* ms_pkSystemDesc;
    const NiDX8AdapterDesc* m_pkAdapterDesc;
    const NiDX8DeviceDesc* m_pkDeviceDesc;

    unsigned int m_uiBackground;
    float m_fZClear;
    unsigned int m_uiStencilClear;
    unsigned int m_uiRendFlags;
    char m_acBehavior[32];

    // Prepacking
    NiTPointerMap<NiVBBlock*, PrePackObject*>m_kPrePackObjects;

    // Batches
    class BatchedObject
    {
    public:
        static BatchedObject* GetNextAvailable();
        void Release();
        static void Purge();

        NiGeometry* m_pkGeometry;
        NiSkinPartition::Partition* m_pkCurrPartition;

        NiGeometryBufferData* m_pkBuffData;
        
        BatchedObject* m_pkNext;
    private:
        static BatchedObject* ms_pkFreeList;
    };

    BatchedObject* m_pkBatchHead;
    BatchedObject* m_pkBatchTail;
    NiPropertyState* m_pkBatchedPropertyState;
    NiDynamicEffectState* m_pkBatchedEffectState;
    NiD3DShaderInterfacePtr m_spBatchedShader;

    // Local copies of camera vectors for points and texture transforms
    NiPoint3 m_kCamRight;
    NiPoint3 m_kCamUp;
    NiPoint3 m_kModelCamRight;
    NiPoint3 m_kModelCamUp;

    NiBound m_kWorldBound;
    const NiBound m_kDefaultBound;
    
    float m_fNearDepth, m_fDepthRange;
    
    D3DMATRIX m_kScreenPolyView;
    D3DMATRIX m_kScreenGeomView;
    D3DMATRIX m_kScreenPolyProj;
    D3DMATRIX m_kD3DIdentity;

    D3DVIEWPORT8 m_kD3dPort; // full framebuffer viewport

    bool m_bSceneOpen;

    unsigned int m_uiHWBones;
    unsigned int m_uiMaxStreams;
    unsigned int m_uiMaxPixelShaderVersion;
    unsigned int m_uiMaxVertexShaderVersion;
    bool m_bMipmapCubeMaps;

    unsigned int m_uiResetCounter;
    bool m_bDeviceLost;

    //  Pixel Format mappings
    NiDX8PixelFormat* m_aapkTextureFormats[TEXUSE_NUM][TEX_NUM];
    NiDX8PixelFormat* m_apkDefaultTextureFormat[TEXUSE_NUM];
    //  Default texture data
    NiPixelDataPtr m_aspDefaultTextureData[TEXUSE_NUM];
    DepthStencilFormat m_aeTextureDepthStencil[TEX_NUM];

    TexFormat m_eReplacementDataFormat;

    void CreatePixelFormatArray(NiDX8PixelFormat** ppkFormatArray,
        unsigned int uiUsage, D3DRESOURCETYPE eType);

    NiDX8RenderTarget* m_pkCurrRenderTarget;
    NiDX8OnscreenRenderTarget* m_pkCurrOnscreenRenderTarget;
    NiTPointerMap<NiWindowRef, NiDX8OnscreenRenderTarget*> 
        m_kOnscreenRenderTargets;

    NiPropertyStatePtr m_spScreenTexturePropertyState;

    //  Geometry Groups
    NiD3DGeometryGroupManager* m_pkGeometryGroupManager;
    NiUnsharedGeometryGroup* m_pkDefaultGroup;
    NiDynamicGeometryGroup* m_pkDynamicGroup;

    //  Managers
    NiDX8RenderState* m_pkRenderState;
    NiDX8VertexBufferManager* m_pkVBManager;
    NiDX8IndexBufferManager* m_pkIBManager;
    NiDX8TextureManager* m_pkTextureManager;
    NiDX8LightManager* m_pkLightManager;
    NiDX8ConfigurableTexturePipeline* m_pkCfgTxtrPipe;

    // Rendered textures and cube maps
    NiTPointerMap<NiRenderedTexture*, NiDX8RenderedTextureData*> 
        m_kRenderedTextures;
    NiTPointerMap<NiRenderedCubeMap*, NiDX8RenderedCubeMapData*> 
        m_kRenderedCubeMaps;

    // Clipper texture
    NiTexturePtr m_spClipperImage;

    NiTPointerList<NiD3DShaderInterface*> m_kD3DShaders;
    NiD3DShaderLibraryVersion m_kShaderLibraryVersion;

    //  Temporary members - used to speed up code
    D3DXALIGNEDMATRIX m_kD3dMat;
    D3DMATRIX m_kD3dView;
    D3DMATRIX m_kD3dProj;
    D3DMATRIX m_kInvView;
    NiPoint2* m_pkScreenTextureVerts;
    NiColorA* m_pkScreenTextureColors;
    NiPoint2* m_pkScreenTextureTexCoords;
    unsigned short* m_pusScreenTextureIndices;
    unsigned short m_usNumScreenTextureVerts;
    unsigned int m_uiNumScreenTextureIndices;

    // Creation parameters
    unsigned int m_uiCreationWidth;
    unsigned int m_uiCreationHeight;
    FlagType m_eCreationFlags;
    NiWindowRef m_kCreationWndDevice;
    NiWindowRef m_kCreationWndFocus;
    unsigned int m_uiCreationAdapter;
    DeviceDesc m_eCreationDesc;
    FrameBufferFormat m_eCreationFBFormat;
    DepthStencilFormat m_eCreationDSFormat;
    PresentationInterval m_eCreationPresentationInterval;
    SwapEffect m_eCreationSwapEffect;
    unsigned int m_uiCreationFBMode;
    unsigned int m_uiCreationBackBufferCount;
    unsigned int m_uiCreationRefreshRate;

    // Default shader
    NiD3DDefaultShaderPtr m_spDefaultShader;

    // Reset notification functions
    NiTArray<RESETNOTIFYFUNC> m_kResetNotifyFuncs;
    NiTArray<void*> m_kResetNotifyFuncData;

    // LostDevice notification functions
    NiTArray<LOSTDEVICENOTIFYFUNC> m_kLostDeviceNotifyFuncs;
    NiTArray<void*> m_kLostDeviceNotifyFuncData;

    static HINSTANCE ms_hDXLib;
    static NILPD3DCREATE ms_pfnD3DCreate8;
    static bool ms_bUseWBuffer;

    // Static flags/values/conversion arrays

    // Map NiTexturingProperty::ClampModes to D3D clamping
    static AddressSettings 
        ms_akD3DAddressMapping[NiTexturingProperty::CLAMP_MAX_MODES];

    // Map NiTexturingProperty::FilterModes to D3D filtering
    static FilterSettings 
        ms_akD3DFilterMapping[NiTexturingProperty::FILTER_MAX_MODES];

        // Map D3DFORMAT to sizes
    enum 
    {
        D3DFORMATSIZECOUNT = 81
    };

    static unsigned char ms_aucD3DFormatSizes[D3DFORMATSIZECOUNT];

    static unsigned int ms_uiProjectedTextureFlags; //  Projected flags
};

typedef NiPointer<NiDX8Renderer> NiDX8RendererPtr;

#include "NiDX8Renderer.inl"

#endif  //#ifndef NIDX8RENDERER_H
