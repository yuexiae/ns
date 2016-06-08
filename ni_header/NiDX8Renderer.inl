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
// NiDX8Renderer.inl
//---------------------------------------------------------------------------
inline int NiDX8Renderer::NiUseDX8()
{ 
    return NI_DX8_RENDER_ID;
}
//---------------------------------------------------------------------------
inline unsigned int NiDX8Renderer::AddResetNotificationFunc(
    RESETNOTIFYFUNC pfnNotify, void* pvData)
{
    unsigned int uiReturn = m_kResetNotifyFuncs.Add(pfnNotify);
    m_kResetNotifyFuncData.SetAtGrow(uiReturn, pvData);

    return uiReturn;
}
//---------------------------------------------------------------------------
inline bool NiDX8Renderer::RemoveResetNotificationFunc(
    RESETNOTIFYFUNC pfnNotify)
{
    unsigned int uiIndex = FindResetNotificationFunc(pfnNotify);
    if (uiIndex == UINT_MAX)
        return false;

    m_kResetNotifyFuncs.RemoveAt(uiIndex);
    m_kResetNotifyFuncData.RemoveAt(uiIndex);
    return true;
}
//---------------------------------------------------------------------------
inline bool NiDX8Renderer::RemoveResetNotificationFunc(unsigned int uiIndex)
{
    if (m_kResetNotifyFuncs.GetAt(uiIndex) == 0)
        return false;

    m_kResetNotifyFuncs.RemoveAt(uiIndex);
    m_kResetNotifyFuncData.RemoveAt(uiIndex);
    return true;
}
//---------------------------------------------------------------------------
inline void NiDX8Renderer::RemoveAllResetNotificationFuncs()
{
    m_kResetNotifyFuncs.RemoveAll();
    m_kResetNotifyFuncData.RemoveAll();
}
//---------------------------------------------------------------------------
inline bool NiDX8Renderer::ChangeResetNotificationFuncData(
    RESETNOTIFYFUNC pfnNotify, void* pvData)
{
    unsigned int uiIndex = FindResetNotificationFunc(pfnNotify);
    if (uiIndex == UINT_MAX)
        return false;

    assert (m_kResetNotifyFuncData.GetSize() > uiIndex);
    m_kResetNotifyFuncData.SetAt(uiIndex, pvData);
    return true;
}
//---------------------------------------------------------------------------
inline bool NiDX8Renderer::ChangeResetNotificationFuncData(
    unsigned int uiIndex, void* pvData)
{
    if (m_kResetNotifyFuncs.GetAt(uiIndex) == 0)
        return false;

    assert (m_kResetNotifyFuncData.GetSize() > uiIndex);
    m_kResetNotifyFuncData.SetAt(uiIndex, pvData);
    return true;
}
//---------------------------------------------------------------------------
inline unsigned int NiDX8Renderer::GetResetNotificationFuncCount() const
{
    return m_kResetNotifyFuncs.GetEffectiveSize();
}
//---------------------------------------------------------------------------
inline unsigned int NiDX8Renderer::GetResetNotificationFuncArrayCount() const
{
    return m_kResetNotifyFuncs.GetSize();
}
//---------------------------------------------------------------------------
inline unsigned int NiDX8Renderer::FindResetNotificationFunc(
    RESETNOTIFYFUNC pfnNotify)
{
    for (unsigned int i = 0; i < m_kResetNotifyFuncs.GetSize(); i++)
    {
        if (m_kResetNotifyFuncs.GetAt(i) == pfnNotify)
            return i;
    }
    return UINT_MAX;
}
//---------------------------------------------------------------------------
inline NiDX8Renderer::RESETNOTIFYFUNC NiDX8Renderer::GetResetNotificationFunc(
    unsigned int uiIndex)
{
    return m_kResetNotifyFuncs.GetAt(uiIndex);
}
//---------------------------------------------------------------------------
inline unsigned int NiDX8Renderer::AddLostDeviceNotificationFunc(
    LOSTDEVICENOTIFYFUNC pfnNotify, void* pvData)
{
    unsigned int uiReturn = m_kLostDeviceNotifyFuncs.Add(pfnNotify);
    m_kLostDeviceNotifyFuncData.SetAtGrow(uiReturn, pvData);

    return uiReturn;
}
//---------------------------------------------------------------------------
inline bool NiDX8Renderer::RemoveLostDeviceNotificationFunc(
    LOSTDEVICENOTIFYFUNC pfnNotify)
{
    unsigned int uiIndex = FindLostDeviceNotificationFunc(pfnNotify);
    if (uiIndex == UINT_MAX)
        return false;

    m_kLostDeviceNotifyFuncs.RemoveAt(uiIndex);
    m_kLostDeviceNotifyFuncData.RemoveAt(uiIndex);
    return true;
}
//---------------------------------------------------------------------------
inline bool NiDX8Renderer::RemoveLostDeviceNotificationFunc(
    unsigned int uiIndex)
{
    if (m_kLostDeviceNotifyFuncs.GetAt(uiIndex) == 0)
        return false;

    m_kLostDeviceNotifyFuncs.RemoveAt(uiIndex);
    m_kLostDeviceNotifyFuncData.RemoveAt(uiIndex);
    return true;
}
//---------------------------------------------------------------------------
inline void NiDX8Renderer::RemoveAllLostDeviceNotificationFuncs()
{
    m_kLostDeviceNotifyFuncs.RemoveAll();
    m_kLostDeviceNotifyFuncData.RemoveAll();
}
//---------------------------------------------------------------------------
inline bool NiDX8Renderer::ChangeLostDeviceNotificationFuncData(
    LOSTDEVICENOTIFYFUNC pfnNotify, void* pvData)
{
    unsigned int uiIndex = FindLostDeviceNotificationFunc(pfnNotify);
    if (uiIndex == UINT_MAX)
        return false;

    assert (m_kLostDeviceNotifyFuncData.GetSize() > uiIndex);
    m_kLostDeviceNotifyFuncData.SetAt(uiIndex, pvData);
    return true;
}
//---------------------------------------------------------------------------
inline bool NiDX8Renderer::ChangeLostDeviceNotificationFuncData(
    unsigned int uiIndex, void* pvData)
{
    if (m_kLostDeviceNotifyFuncs.GetAt(uiIndex) == 0)
        return false;

    assert (m_kLostDeviceNotifyFuncData.GetSize() > uiIndex);
    m_kLostDeviceNotifyFuncData.SetAt(uiIndex, pvData);
    return true;
}
//---------------------------------------------------------------------------
inline unsigned int NiDX8Renderer::GetLostDeviceNotificationFuncCount() const
{
    return m_kLostDeviceNotifyFuncs.GetEffectiveSize();
}
//---------------------------------------------------------------------------
inline unsigned int NiDX8Renderer::GetLostDeviceNotificationFuncArrayCount()
    const
{
    return m_kLostDeviceNotifyFuncs.GetSize();
}
//---------------------------------------------------------------------------
inline unsigned int NiDX8Renderer::FindLostDeviceNotificationFunc(
    LOSTDEVICENOTIFYFUNC pfnNotify)
{
    for (unsigned int i = 0; i < m_kLostDeviceNotifyFuncs.GetSize(); i++)
    {
        if (m_kLostDeviceNotifyFuncs.GetAt(i) == pfnNotify)
            return i;
    }
    return UINT_MAX;
}
//---------------------------------------------------------------------------
inline NiDX8Renderer::LOSTDEVICENOTIFYFUNC 
    NiDX8Renderer::GetLostDeviceNotificationFunc(unsigned int uiIndex)
{
    return m_kLostDeviceNotifyFuncs.GetAt(uiIndex);
}
//---------------------------------------------------------------------------
inline bool NiDX8Renderer::GetSceneOpen() const
{
    return m_bSceneOpen;
}
//---------------------------------------------------------------------------
inline const NiDX8PixelFormat& NiDX8Renderer::GetScreenPixelFormat()
{
    return m_pkCurrOnscreenRenderTarget->GetPixelFormat();
}
//---------------------------------------------------------------------------
inline LPDIRECT3DDEVICE8 NiDX8Renderer::GetD3DDevice8()
{
    return m_pkD3DDevice8;
}
//---------------------------------------------------------------------------
inline LPDIRECT3DDEVICE8 NiDX8Renderer::GetD3DDevice()
{
    return m_pkD3DDevice8;
}
//---------------------------------------------------------------------------
inline NiDX8RenderState* NiDX8Renderer::GetRenderState()
{
    return m_pkRenderState;
}
//---------------------------------------------------------------------------
inline NiDX8VertexBufferManager* NiDX8Renderer::GetVBManager()
{
   return m_pkVBManager;
}
//---------------------------------------------------------------------------
inline NiDX8ShaderDeclaration* NiDX8Renderer::Create(bool bFixedFunction, 
    unsigned int uiMaxStreamEntryCount, unsigned int uiStreamCount)
{
    return NiDX8ShaderDeclaration::Create(this, bFixedFunction,
        uiMaxStreamEntryCount, uiStreamCount);
}
//---------------------------------------------------------------------------
inline unsigned int NiDX8Renderer::GetMaxStreams() const
{
    return m_uiMaxStreams;
}
//---------------------------------------------------------------------------
inline unsigned int NiDX8Renderer::GetPixelShaderVersion() const
{
    return m_uiMaxPixelShaderVersion;
}
//---------------------------------------------------------------------------
inline unsigned int NiDX8Renderer::GetVertexShaderVersion() const
{
    return m_uiMaxVertexShaderVersion;
}
//---------------------------------------------------------------------------
inline bool NiDX8Renderer::GetMipmapCubeMaps() const
{
    return m_bMipmapCubeMaps;
}
//---------------------------------------------------------------------------
inline bool NiDX8Renderer::GetSWVertexCapable() const
{
    return m_bSWVertexCapable;
}
//---------------------------------------------------------------------------
inline bool NiDX8Renderer::GetSWVertexSwitchable() const
{
    return m_bSWVertexSwitchable;
}
//---------------------------------------------------------------------------
inline void NiDX8Renderer::SetDepthClear(const float fZClear)
{
    m_fZClear = fZClear;
}
//---------------------------------------------------------------------------
inline void NiDX8Renderer::UseQuickDecals(bool bQuickDecals)
{
    if (m_spDefaultShader)
        m_spDefaultShader->UseQuickDecals(bQuickDecals);
}
//---------------------------------------------------------------------------
inline void NiDX8Renderer::SetBackgroundColor(const NiColor& kColor)
{
    unsigned char ucR = (unsigned char)(kColor.r * 255.0f);
    unsigned char ucG = (unsigned char)(kColor.g * 255.0f);
    unsigned char ucB = (unsigned char)(kColor.b * 255.0f);
    m_uiBackground = D3DCOLOR_XRGB(ucR, ucG, ucB);
}
//---------------------------------------------------------------------------
inline void NiDX8Renderer::SetBackgroundColor(const NiColorA& kColor)
{
    unsigned char ucR = (unsigned char)(kColor.r * 255.0f);
    unsigned char ucG = (unsigned char)(kColor.g * 255.0f);
    unsigned char ucB = (unsigned char)(kColor.b * 255.0f);
    unsigned char ucA = (unsigned char)(kColor.a * 255.0f);
    m_uiBackground = D3DCOLOR_ARGB(ucA, ucR, ucG, ucB);
}
//---------------------------------------------------------------------------
inline void NiDX8Renderer::GetBackgroundColor(NiColorA& kColor)
{
    const float fConstant = 1.0f / 255.0f;
    kColor.a = ((m_uiBackground >> 24) & 0xff) * fConstant;
    kColor.r = ((m_uiBackground >> 16) & 0xff) * fConstant;
    kColor.g = ((m_uiBackground >> 8) & 0xff) * fConstant;
    kColor.b = (m_uiBackground & 0xff) * fConstant;
}
//---------------------------------------------------------------------------
inline void NiDX8Renderer::SetStencilClear(unsigned int uiClear)
{
    m_uiStencilClear = uiClear;
}
//---------------------------------------------------------------------------
inline bool NiDX8Renderer::GetHasNormalsFromFlags(unsigned int uiFlags)
{
    if (uiFlags & VERTEX_FLAG_DX_HASNORMALS)
        return true;
    return false;
}
//---------------------------------------------------------------------------
inline void NiDX8Renderer::SetHasNormalsFromFlags(bool bHasNormals,
    unsigned int& uiFlags)
{
    if (bHasNormals)
        uiFlags |= VERTEX_FLAG_DX_HASNORMALS;
    else
        uiFlags &= ~VERTEX_FLAG_DX_HASNORMALS;
}
//---------------------------------------------------------------------------
inline unsigned int NiDX8Renderer::GetNumUVsFromFlags(unsigned int uiFlags)
{
    return (uiFlags & VERTEX_FLAG_DX_TEXTUREMASK) >> 
        VERTEX_FLAG_DX_TEXTURESHIFT;
}
//---------------------------------------------------------------------------
inline void NiDX8Renderer::SetNumUVsInFlags(unsigned int uiUVCount, 
    unsigned int& uiFlags)
{
    uiFlags = (uiFlags & ~VERTEX_FLAG_DX_TEXTUREMASK) | 
        (uiUVCount << VERTEX_FLAG_DX_TEXTURESHIFT);
}
//---------------------------------------------------------------------------
inline char* NiDX8Renderer::GetDevTypeString()
{
    switch (m_eDevType)
    {
    case D3DDEVTYPE_HAL:
        return "HAL";
    case D3DDEVTYPE_REF:
        return "REF";
    case D3DDEVTYPE_SW:
        return "SW";
    }

    return "???";
}
//---------------------------------------------------------------------------
inline char* NiDX8Renderer::GetBehaviorString()
{
    strcpy(m_acBehavior, "");

    if (m_uiBehaviorFlags & D3DCREATE_PUREDEVICE)
        strcat(m_acBehavior, "PURE");
    if (m_uiBehaviorFlags & D3DCREATE_MULTITHREADED)
        strcat(m_acBehavior, " MT");
    if (m_uiBehaviorFlags & D3DCREATE_HARDWARE_VERTEXPROCESSING)
        strcat(m_acBehavior, " HWVP");
    if (m_uiBehaviorFlags & D3DCREATE_MIXED_VERTEXPROCESSING)
        strcat(m_acBehavior, " MIXVP");
    if (m_uiBehaviorFlags & D3DCREATE_SOFTWARE_VERTEXPROCESSING)
        strcat(m_acBehavior, " SWVP");

    return m_acBehavior;
}
//---------------------------------------------------------------------------
inline D3DFORMAT NiDX8Renderer::GetD3DFormat(
    NiDX8Renderer::FrameBufferFormat eFBFormat)
{
    switch (eFBFormat)
    {
    case FBFMT_UNKNOWN:
        return D3DFMT_UNKNOWN;
    case FBFMT_R8G8B8:
        return D3DFMT_R8G8B8;
    case FBFMT_A8R8G8B8:
        return D3DFMT_A8R8G8B8;
    case FBFMT_X8R8G8B8:
        return D3DFMT_X8R8G8B8;
    case FBFMT_R5G6B5:
        return D3DFMT_R5G6B5;
    case FBFMT_X1R5G5B5:
        return D3DFMT_X1R5G5B5;
    case FBFMT_A1R5G5B5:
        return D3DFMT_A1R5G5B5;
    case FBFMT_A4R4G4B4:
        return D3DFMT_A4R4G4B4;
    case FBFMT_R3G3B2:
        return D3DFMT_R3G3B2;
    case FBFMT_A8:
        return D3DFMT_A8;
    case FBFMT_A8R3G3B2:
        return D3DFMT_A8R3G3B2;
    case FBFMT_X4R4G4B4:
        return D3DFMT_X4R4G4B4;
    }

    return D3DFMT_UNKNOWN;
}
//---------------------------------------------------------------------------
inline NiDX8Renderer::FrameBufferFormat NiDX8Renderer::GetNiFBFormat(
    D3DFORMAT eFormat)
{
    switch (eFormat)
    {
    case D3DFMT_UNKNOWN:
        return FBFMT_UNKNOWN;
    case D3DFMT_R8G8B8:
        return FBFMT_R8G8B8;
    case D3DFMT_A8R8G8B8:
        return FBFMT_A8R8G8B8;
    case D3DFMT_X8R8G8B8:
        return FBFMT_X8R8G8B8;
    case D3DFMT_R5G6B5:
        return FBFMT_R5G6B5;
    case D3DFMT_X1R5G5B5:
        return FBFMT_X1R5G5B5;
    case D3DFMT_A1R5G5B5:
        return FBFMT_A1R5G5B5;
    case D3DFMT_A4R4G4B4:
        return FBFMT_A4R4G4B4;
    case D3DFMT_R3G3B2:
        return FBFMT_R3G3B2;
    case D3DFMT_A8:
        return FBFMT_A8;
    case D3DFMT_A8R3G3B2:
        return FBFMT_A8R3G3B2;
    case D3DFMT_X4R4G4B4:
        return FBFMT_X4R4G4B4;
    }

    return FBFMT_UNKNOWN;
}
//---------------------------------------------------------------------------
inline D3DFORMAT NiDX8Renderer::GetD3DFormat(DepthStencilFormat eDSFormat)
{
    //  For now, this is a straight conversion.
    //  This function is provided for future changes
    return (D3DFORMAT)eDSFormat;
}
//---------------------------------------------------------------------------
inline NiDX8Renderer::DepthStencilFormat NiDX8Renderer::GetNiDSFormat(
    D3DFORMAT eFormat)
{
    //  For now, this is a straight conversion.
    //  This function is provided for future changes
    return (NiDX8Renderer::DepthStencilFormat)eFormat;
}
//---------------------------------------------------------------------------
inline bool NiDX8Renderer::Is16BitDepthFormat(
    NiDX8Renderer::DepthStencilFormat eFormat)
{
    switch (eFormat)
    {
    case DSFMT_D16_LOCKABLE:
    case DSFMT_D15S1:
    case DSFMT_D16:
        return true;
        break;
    case DSFMT_D32:
    case DSFMT_D24S8:
    case DSFMT_D24X8:
    case DSFMT_D24X4S4:
        return false;
        break;
    default:
        assert (false);
        return false;
        break;
    }
}
//---------------------------------------------------------------------------
inline D3DMULTISAMPLE_TYPE NiDX8Renderer::GetMultiSampleType(
    unsigned int uiMode)
{
    switch (uiMode)
    {
    case FBMODE_MULTISAMPLES_2:
        return D3DMULTISAMPLE_2_SAMPLES;
    case FBMODE_MULTISAMPLES_3:
        return D3DMULTISAMPLE_3_SAMPLES;
    case FBMODE_MULTISAMPLES_4:
        return D3DMULTISAMPLE_4_SAMPLES;
    case FBMODE_MULTISAMPLES_5:
        return D3DMULTISAMPLE_5_SAMPLES;
    case FBMODE_MULTISAMPLES_6:
        return D3DMULTISAMPLE_6_SAMPLES;
    case FBMODE_MULTISAMPLES_7:
        return D3DMULTISAMPLE_7_SAMPLES;
    case FBMODE_MULTISAMPLES_8:
        return D3DMULTISAMPLE_8_SAMPLES;
    case FBMODE_MULTISAMPLES_9:
        return D3DMULTISAMPLE_9_SAMPLES;
    case FBMODE_MULTISAMPLES_10:
        return D3DMULTISAMPLE_10_SAMPLES;
    case FBMODE_MULTISAMPLES_11:
        return D3DMULTISAMPLE_11_SAMPLES;
    case FBMODE_MULTISAMPLES_12:
        return D3DMULTISAMPLE_12_SAMPLES;
    case FBMODE_MULTISAMPLES_13:
        return D3DMULTISAMPLE_13_SAMPLES;
    case FBMODE_MULTISAMPLES_14:
        return D3DMULTISAMPLE_14_SAMPLES;
    case FBMODE_MULTISAMPLES_15:
        return D3DMULTISAMPLE_15_SAMPLES;
    case FBMODE_MULTISAMPLES_16:
        return D3DMULTISAMPLE_16_SAMPLES;
    case FBMODE_DEFAULT:
    case FBMODE_LOCKABLE:
        return D3DMULTISAMPLE_NONE;
    default:
        assert (false);
    }

    return D3DMULTISAMPLE_NONE;
}
//---------------------------------------------------------------------------
inline D3DSWAPEFFECT NiDX8Renderer::GetSwapEffect(
    SwapEffect eMode, unsigned int uiFBMode, FlagType eFlags)
{
    // Must use discard with a multisampled framebuffer
    if ((uiFBMode != FBMODE_DEFAULT) && (uiFBMode != FBMODE_LOCKABLE))
        return D3DSWAPEFFECT_DISCARD;

    switch (eMode)
    {
    case SWAPEFFECT_DISCARD:
        return D3DSWAPEFFECT_DISCARD;
    case SWAPEFFECT_FLIP:
        return D3DSWAPEFFECT_FLIP;
    case SWAPEFFECT_COPY:
        return D3DSWAPEFFECT_COPY;
    case SWAPEFFECT_COPY_VSYNC:
        return D3DSWAPEFFECT_COPY_VSYNC;
    default:
        return D3DSWAPEFFECT_DISCARD;
    }
}
//---------------------------------------------------------------------------
inline unsigned int NiDX8Renderer::GetRefreshRate(
    unsigned int uiRefreshRateHz)
{
    switch (uiRefreshRateHz)
    {
    case REFRESHRATE_DEFAULT:
        return D3DPRESENT_RATE_DEFAULT;
    case REFRESHRATE_UNLIMITED:
        return D3DPRESENT_RATE_UNLIMITED;
    }

    return uiRefreshRateHz;
}
//---------------------------------------------------------------------------
inline unsigned int NiDX8Renderer::GetPresentInterval(
    NiDX8Renderer::PresentationInterval ePresentationInterval)
{
    switch (ePresentationInterval)
    {
    case PRESENT_INTERVAL_IMMEDIATE:
        return D3DPRESENT_INTERVAL_IMMEDIATE;
    case PRESENT_INTERVAL_ONE:
        return D3DPRESENT_INTERVAL_ONE;
    case PRESENT_INTERVAL_TWO:
        return D3DPRESENT_INTERVAL_TWO;
    case PRESENT_INTERVAL_THREE:
        return D3DPRESENT_INTERVAL_THREE;
    case PRESENT_INTERVAL_FOUR:
        return D3DPRESENT_INTERVAL_FOUR;
    }

    return D3DPRESENT_INTERVAL_DEFAULT;
}
//---------------------------------------------------------------------------
inline unsigned int NiDX8Renderer::GetFlags()
{
    return m_uiRendFlags;
}
//---------------------------------------------------------------------------
inline unsigned int NiDX8Renderer::GetAdapter()
{
    return m_uiAdapter;
}
//---------------------------------------------------------------------------
inline D3DDEVTYPE NiDX8Renderer::GetDevType()
{
    return m_eDevType;
}
//---------------------------------------------------------------------------
inline D3DPRESENT_PARAMETERS* NiDX8Renderer::GetPresentParams()
{
    return &m_pkCurrOnscreenRenderTarget->GetPresentParams();
}
//---------------------------------------------------------------------------
inline NiDX8PixelFormat** NiDX8Renderer::GetTextureFormatArray(
    TexUsage eUse)    
{
    return m_aapkTextureFormats[eUse];
}
//---------------------------------------------------------------------------
inline NiDX8PixelFormat* NiDX8Renderer::GetDefaultTextureFormat(
    TexUsage eUse)
{
    return m_apkDefaultTextureFormat[eUse];
}
//---------------------------------------------------------------------------
inline NiDX8Renderer::TexFormat NiDX8Renderer::GetReplacementDataFormat() 
    const
{
    return m_eReplacementDataFormat;
}
//---------------------------------------------------------------------------
inline NiPixelData* NiDX8Renderer::GetDefaultTextureData(TexUsage eUse)
{
    return m_aspDefaultTextureData[eUse];
}
//---------------------------------------------------------------------------
inline NiTexture* NiDX8Renderer::GetClipperTexture()
{
    return m_spClipperImage;
}
//---------------------------------------------------------------------------
inline NiDX8Renderer::DepthStencilFormat 
    NiDX8Renderer::GetTextureDepthStencil(TexFormat eFmt)
{
    return m_aeTextureDepthStencil[eFmt];
}
//---------------------------------------------------------------------------
inline const NiDX8AdapterDesc* NiDX8Renderer::GetAdapterDesc() const
{
    return m_pkAdapterDesc;
}
//---------------------------------------------------------------------------
inline const NiDX8DeviceDesc* NiDX8Renderer::GetDeviceDesc() const
{
    return m_pkDeviceDesc;
}
//---------------------------------------------------------------------------
inline NiDX8RenderState* NiDX8Renderer::GetRenderState() const
{
    return m_pkRenderState;
}
//---------------------------------------------------------------------------
inline NiDX8TextureManager* NiDX8Renderer::GetTextureManager() const
{
    return m_pkTextureManager;
}
//---------------------------------------------------------------------------
inline NiDX8LightManager* NiDX8Renderer::GetLightManager() const
{
    return m_pkLightManager;
}
//---------------------------------------------------------------------------
inline const D3DMATRIX& NiDX8Renderer::GetD3DMat() const
{
    return m_kD3dMat;
}
//---------------------------------------------------------------------------
inline const D3DMATRIX& NiDX8Renderer::GetD3DView() const
{
    return m_kD3dView;
}
//---------------------------------------------------------------------------
inline const D3DMATRIX& NiDX8Renderer::GetD3DProj() const
{
    return m_kD3dProj;
}
//---------------------------------------------------------------------------
inline const D3DMATRIX& NiDX8Renderer::GetInvView() const
{
    return m_kInvView;
}
//---------------------------------------------------------------------------
inline D3DXALIGNEDMATRIX* NiDX8Renderer::GetD3DWorld()
{
    return &m_kD3dMat;
}
//---------------------------------------------------------------------------
inline unsigned int NiDX8Renderer::GetResetCounter() const
{
    return m_uiResetCounter;
}
//---------------------------------------------------------------------------
inline bool NiDX8Renderer::IsDeviceLost() const
{
    return m_bDeviceLost;
}
//---------------------------------------------------------------------------
// Shader version information
//---------------------------------------------------------------------------
inline void NiDX8Renderer::SetMinPixelShaderVersion(unsigned int uiMaj, 
    unsigned int uiMin)
{
    m_kShaderLibraryVersion.SetMinPixelShaderVersion(
        D3DPS_VERSION(uiMaj, uiMin));
}
//---------------------------------------------------------------------------
inline void NiDX8Renderer::SetPixelShaderVersionRequest(unsigned int uiMaj, 
    unsigned int uiMin)
{
    m_kShaderLibraryVersion.SetPixelShaderVersionRequest(
        D3DPS_VERSION(uiMaj, uiMin));
}
//---------------------------------------------------------------------------
inline void NiDX8Renderer::SetMinVertexShaderVersion(unsigned int uiMaj, 
    unsigned int uiMin)
{
    m_kShaderLibraryVersion.SetMinVertexShaderVersion(
        D3DVS_VERSION(uiMaj, uiMin));
}
//---------------------------------------------------------------------------
inline void NiDX8Renderer::SetVertexShaderVersionRequest(unsigned int uiMaj, 
    unsigned int uiMin)
{
    m_kShaderLibraryVersion.SetVertexShaderVersionRequest(
        D3DVS_VERSION(uiMaj, uiMin));
}
//---------------------------------------------------------------------------
inline void NiDX8Renderer::SetSystemUserVersion(unsigned int uiMaj, 
    unsigned int uiMin)
{
    m_kShaderLibraryVersion.SetSystemUserVersion(
        D3DVS_VERSION(uiMaj, uiMin));
}
//---------------------------------------------------------------------------
inline void NiDX8Renderer::SetMinUserVersion(unsigned int uiMaj, 
    unsigned int uiMin)
{
    m_kShaderLibraryVersion.SetMinUserVersion(D3DVS_VERSION(uiMaj, uiMin));
}
//---------------------------------------------------------------------------
inline void NiDX8Renderer::SetUserVersionRequest(unsigned int uiMaj, 
    unsigned int uiMin)
{
    m_kShaderLibraryVersion.SetUserVersionRequest(
        D3DVS_VERSION(uiMaj, uiMin));
}
//---------------------------------------------------------------------------
inline unsigned int NiDX8Renderer::GetMinPixelShaderVersion()
{
    return m_kShaderLibraryVersion.GetMinPixelShaderVersion();
}
//---------------------------------------------------------------------------
inline unsigned int NiDX8Renderer::GetPixelShaderVersionRequest()
{
    return m_kShaderLibraryVersion.GetPixelShaderVersionRequest();
}
//---------------------------------------------------------------------------
inline unsigned int NiDX8Renderer::GetMinVertexShaderVersion()
{
    return m_kShaderLibraryVersion.GetMinVertexShaderVersion();
}
//---------------------------------------------------------------------------
inline unsigned int NiDX8Renderer::GetVertexShaderVersionRequest()
{
    return m_kShaderLibraryVersion.GetVertexShaderVersionRequest();
}
//---------------------------------------------------------------------------
inline unsigned int NiDX8Renderer::GetMinUserVersion()
{
    return m_kShaderLibraryVersion.GetMinUserVersion();
}
//---------------------------------------------------------------------------
inline unsigned int NiDX8Renderer::GetUserVersionRequest()
{
    return m_kShaderLibraryVersion.GetUserVersionRequest();
}
//---------------------------------------------------------------------------
inline NiD3DShaderLibraryVersion* NiDX8Renderer::GetShaderLibraryVersion()
{
    return &m_kShaderLibraryVersion;
}
//---------------------------------------------------------------------------
