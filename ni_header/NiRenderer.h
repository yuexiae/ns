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

#ifndef NIRENDERER_H
#define NIRENDERER_H

#include "NiAccumulator.h"
#include "NiAVObject.h"
#include "NiBool.h"
#include "NiColor.h"
#include "NiDynamicEffectState.h"
#include "NiPropertyState.h"
#include "NiRect.h"
#include "NiRTLib.h"
#include "NiTexture.h"
#include "NiTList.h"

class NiBound;
class NiBltSource;
class NiDynamicEffect;
class NiPoint2;
class NiPoint3;
class NiPlane;
class NiCamera;
class NiFrustum;
class NiGeometry;
class NiGeometryData;
class NiPalette;
class NiTransform;
class NiTriShape;
class NiTriShapeData;
class NiTriStrips;
class NiTriStripsData;
class NiParticles;
class NiParticlesData;
class NiLines;
class NiLinesData;
class NiSkinInstance;
class NiSourceCubeMap;
class NiSourceTexture;
class NiScreenPolygon;
class NiScreenTexture;
class NiRenderedCubeMap;
class NiRenderedTexture;
class NiSkinPartition;

class NIMAIN_ENTRY NiRenderer : public NiObject 
{
    NiDeclareRTTI;
    NiDeclareViewerStrings;
public:
    // local constants -
    // return flags from GetFlags:
    enum
    {
        // indicates that renderer supports mipmaps
        CAPS_MIPMAP             = 0x00000001,
        // indicates renderer requires square textures
        CAPS_SQ_TEXT            = 0x00000002,
        // indicates renderer requires textures with power-of-2 dimensions
        CAPS_POW2_TEXT          = 0x00000004,
        // indicates renderer is hardware accelerated
        CAPS_HARDWARE           = 0x00000008,
        // indicates renderer is ramped - only supports 8-bit
        // palettized textures on the global palette
        CAPS_RAMP               = 0x00000010,
        // indicates that renderer supports palettized textures
        CAPS_PALETTIZED         = 0x00000020,
        // indicates that renderer supports "significant" alpha blending
        CAPS_ALPHA              = 0x00000040,
        // indicates that the renderer has a stencil buffer
        CAPS_STENCIL            = 0x00000080,
        // indicates renderer supports w-buffering
        CAPS_WBUFFER            = 0x00000100, 
        // indicates renderer supports hardware skinning
        CAPS_HARDWARESKINNING   = 0x00000200,

        CAPS_MAX                = 0x00000200
    };
      
    // OR'ed flag return from GetTextureManagerStatus
    enum
    {
        TEXTURE_MANAGER_NO_MANAGEMENT   = 0x00000000,
        TEXTURE_MANAGER_MANAGEMENT_ON   = 0x00000001,
        TEXTURE_MANAGER_COOPTED         = 0x00000002,
        TEXTURE_MANAGER_REPLACED        = 0x00000004,
        TEXTURE_MANAGER_COOPTED_IN_FRAME= 0x00000008,
        TEXTURE_MANAGER_PURGED_IN_FRAME = 0x00000010,
        TEXTURE_MANAGER_FAILURE         = 0x00000020
    };

    enum ClearFlags
    {
        CLEAR_BACKBUFFER = 0x1,
        CLEAR_STENCIL = 0x2,
        CLEAR_ZBUFFER = 0x4
    }; 

    // construction and destruction
    NiRenderer();
    virtual ~NiRenderer();

    // String describing renderer
    virtual const char* GetDriverInfo() = 0;

    // Renderer capabilities
    virtual unsigned int GetFlags() = 0;
    virtual const NiPixelFormat* 
        FindClosestPixelFormat(NiTexture::FormatPrefs& kFmtPrefs) = 0;

    // Buffer access and management methods
    virtual bool SetRenderTarget(NiRenderedTexture* pkBuffer = NULL) = 0;
    virtual void SwapBuffers() = 0;
    virtual void ClearBuffer(const NiRect<float>* pkR, 
        unsigned int uiMode) = 0;
    virtual bool GetLeftRightSwap() { return false; }
    virtual bool SetLeftRightSwap(bool bSwap) { return false; }

    virtual bool SetUseWBuffer(bool bWBuffer) { return !bWBuffer; }

    virtual unsigned int GetBackbufferWidth() = 0;
    virtual unsigned int GetBackbufferHeight() = 0;
    virtual unsigned int GetBackbufferBitsPerPixel() = 0;

    virtual NiPixelData* TakeScreenShot(
        const NiRect<unsigned int>* pkScreenRect) = 0;

    virtual void ImageBlt(NiBltSource* pkBlt,
        const NiRect<unsigned int>* pkSrc, 
        unsigned int uiDestX, unsigned int uiDestY) = 0;

    // Buffer clear values
    virtual void SetDepthClear(const float fZClear) { /* */ }
    virtual void SetBackgroundColor(const NiColor& kColor) = 0;
    virtual void SetBackgroundColor(const NiColorA& kColor) = 0;
    virtual void GetBackgroundColor(NiColorA& kColor) = 0;
    virtual void SetStencilClear(unsigned int uiClear) { /* */ }

    // Global fog settings
    // This base version signals that changing the value is not supported
    // Subclasses may overide this to indicate that changing the value is
    // supported
    virtual float GetMaxFogValue(); 
    virtual void SetMaxFogValue(float fFogVal) { /* */ }

    // Sorting
    void SetSorter(NiAccumulator* pkAccum);
    NiAccumulator* GetSorter();

    // Texture memory management precaching and purgeing    
    virtual bool PrecacheTexture(NiTexture* pkTexture, 
        bool bForceLoad = false, bool bLocked = false) = 0;
    virtual bool PurgeAllTextures(bool bPurgeLocked) = 0;
    virtual bool PurgeTexture(NiTexture* pkTexture) = 0;

    // Texture memory management statistics
    virtual bool GetTextureMemoryStats(unsigned int& uiTotal,
        unsigned int& uiAvail);
    virtual bool GetTextureStats(unsigned int& uiLoadedTextures,
        unsigned int& uiUsedTextures, unsigned int& uiStateChanges,
        unsigned int& uiNewTextures, unsigned int& uiEvictedTextures,
        unsigned int& uiBytesTransferred);
    virtual unsigned int GetTextureManagerStatus();

    // Texture mipmap skip level
    virtual bool SetMipmapSkipLevel(unsigned int uiSkip) = 0;
    virtual unsigned int GetMipmapSkipLevel() = 0;

    // PrecacheGeometry flags
    enum
    {
        // WRAP flags tell renderer it can bias texture coordinates towards 0
        // to minimize problems with texture coordinate precision.
        VERTEX_FLAG_WRAP_TEXTURE0 = 0x01,
        VERTEX_FLAG_WRAP_TEXTURE1 = 0x02,
        VERTEX_FLAG_WRAP_TEXTURE2 = 0x04,
        VERTEX_FLAG_WRAP_TEXTURE3 = 0x08,
        VERTEX_FLAG_WRAP_TEXTURE4 = 0x10,
        VERTEX_FLAG_WRAP_TEXTURE5 = 0x20,
        VERTEX_FLAG_WRAP_TEXTURE6 = 0x40,
        VERTEX_FLAG_WRAP_TEXTURE7 = 0x80,
        VERTEX_FLAG_WRAP_ALL      = 0xff,

        // PRECACHE_FLAG_FREE_BIT_POS should not be used by apps. It tells
        // derived classes what bit position to start with for 
        // platform-specific precache flags.
        PRECACHE_FLAG_FREE_BIT_POS = 0x100
    };
    virtual bool PrecacheGeometry(NiGeometry* pkGeometry, unsigned int uiFlags,
        void* pvExtraData, unsigned int uiBonesPerPartition = 0, 
        unsigned int uiBonesPerVertex = 0);

    // Examine texture coordinate wrapping modes for each texture map in
    // pkTexProp and return flags consisting of VERTEX_FLAG_WRAP_TEXTURE0,
    // VERTEX_FLAG_WRAP_TEXTURE1, etc. that can be OR'd into the flags that
    // are passed to PrecacheGeometry.
    static unsigned int GetPrecacheFlags(const NiTexturingProperty* pkTexProp);

    virtual void GetGeometryStats(NiGeometryData* pkGeomData, 
        unsigned int& uiFlags);

    // Batch rendering
    virtual void BeginBatch(NiPropertyState* pkPropertyState,
        NiDynamicEffectState* pkEffectState);
    virtual void EndBatch();
    virtual void BatchRenderShape(NiTriShape* pkTriShape);
    virtual void BatchRenderStrips(NiTriStrips* pkTriStrips);
    bool GetBatchRendering() const;

    // Error status
    static const char* GetLastErrorString();
    static void ClearLastErrorString();

    // *** begin NDL internal use only ***

    // Rendering start/end
    virtual void BeginPaint();
    virtual void EndPaint(); 

    // Property state
    NiPropertyState* GetPropertyState();
    void SetPropertyState (NiPropertyState* pkState);

    // Effect state
    NiDynamicEffectState* GetEffectState();
    void SetEffectState(NiDynamicEffectState* pkState);

    // Camera state
    virtual void SetCameraData (const NiPoint3& kWorldLoc,
        const NiPoint3& kWorldDir, const NiPoint3& kWorldUp, 
        const NiPoint3& kWorldRight, const NiFrustum& kFrustum, 
        const NiRect<float>& kPort) = 0;

    // Primitive rendering
    virtual void RenderShape(NiTriShape* pkTriShape) = 0;
    virtual void RenderTristrips(NiTriStrips* pkTriStrips) = 0;
    virtual void RenderPoints(NiParticles* pkParticles) = 0;
    virtual void RenderLines(NiLines* pkLines) = 0;

    virtual void RenderScreenPoly(NiScreenPolygon* pkPoly) = 0;
    virtual void RenderScreenTexture(NiScreenTexture* pkScreenTexture) = 0;

    // Clipping state
    void UseClipPlanes(unsigned int uiFrustumFlags);

    bool MapWindowPointToBufferPoint(unsigned int uiX, unsigned int uiY, 
        float& fX, float& fY);
    
    virtual bool PreloadTexture(NiTexture* pkTexture);

    static void RemoveEffect(NiDynamicEffect* pkEffect);
    static void RemoveGeometryData(NiGeometryData* pkData);
    static void RemoveMaterial(NiMaterialProperty* pkMaterial);
    static void RemoveScreenTextureRendererData(
        NiScreenTexture* pkScreenTexture);
    static void RemoveSkinPartitionRendererData(
        NiSkinPartition* pkSkinPartition);
    static void RemoveSkinInstance(NiSkinInstance* pkSkinInstance);
    static void RemoveScreenPolygon(NiScreenPolygon* pkPoly);

    // cached geometry data handling
    virtual void PurgeGeometryData(NiGeometryData* pkData) = 0;
    virtual void PurgeMaterial(NiMaterialProperty* pkMaterial) = 0;
    virtual void PurgeEffect(NiDynamicEffect* pLight) = 0;
    virtual void PurgeScreenTextureRendererData(
        NiScreenTexture* pkScreenTexture) = 0;
    virtual void PurgeSkinPartitionRendererData(
        NiSkinPartition* pkSkinPartition) = 0;
    virtual void PurgeSkinInstance(NiSkinInstance* pkSkinInstance) = 0;
    virtual void PurgeScreenPolygon(NiScreenPolygon* pkPoly) = 0;

    void PurgeAllRendererData(NiAVObject* pkScene); 

    static void SetLastErrorString(const char* pcStr);

    // Source renderer data primitive protection methods.
    void LockSourceDataCriticalSection();
    void UnlockSourceDataCriticalSection();

    // List of all renderers
    static NiRenderer* GetRenderer();

    // Renderer specific data for textures and palettes
    virtual bool CreateSourceTextureRendererData(
        NiSourceTexture* pkTexture) = 0;
    virtual bool
        CreateRenderedTextureRendererData(NiRenderedTexture* pkTexture) = 0;
    virtual bool
        CreateRenderedCubeMapRendererData(NiRenderedCubeMap* pkTexture) 
    { return false; }
    virtual bool
        CreateSourceCubeMapRendererData(NiSourceCubeMap* pkTexture) 
    { return false; }
    virtual void
        CreatePaletteRendererData(NiPalette* pkPalette) = 0;
    virtual bool
        CreateBltSourceRendererData(NiBltSource* pkBlt) { return true; }

    static void _SDMShutdown();

    // *** end NDL internal use only ***

protected:
    NiAccumulatorPtr m_spAccum;
    NiPropertyState* m_pkCurrProp;
    NiDynamicEffectState* m_pkCurrEffects;
    NiCriticalSection m_kPrecacheCriticalSection;
    NiCriticalSection m_kSourceDataCriticalSection;
    bool m_bBatchRendering;

    unsigned int m_uiClipPlaneFlags;

    static char ms_pcErrorString[256];
    static NiRenderer* ms_pkRenderer;
};

typedef NiPointer<NiRenderer> NiRendererPtr;

#include "NiRenderer.inl"

#endif // NIRENDERER_H
