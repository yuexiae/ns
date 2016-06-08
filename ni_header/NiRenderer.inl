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
//  NiRenderer inline functions
//---------------------------------------------------------------------------
inline float NiRenderer::GetMaxFogValue() 
{ 
    return 1.0f; 
}
//---------------------------------------------------------------------------
inline bool NiRenderer::PrecacheGeometry(NiGeometry*, unsigned int, void*, 
    unsigned int, unsigned int)
{
    return false;
}
//---------------------------------------------------------------------------
inline const char* NiRenderer::GetLastErrorString() 
{ 
    return ms_pcErrorString; 
}
//---------------------------------------------------------------------------
inline void NiRenderer::ClearLastErrorString() 
{ 
    SetLastErrorString(0); 
}
//---------------------------------------------------------------------------
inline void NiRenderer::SetLastErrorString(const char* pcStr)
{
    if (pcStr)
        strncpy(ms_pcErrorString, pcStr, 255);
    else
        ms_pcErrorString[0] = '\0';
}
//---------------------------------------------------------------------------
inline void NiRenderer::SetSorter(NiAccumulator* pkAccum)
{
    m_spAccum = pkAccum;
}
//---------------------------------------------------------------------------
inline NiAccumulator* NiRenderer::GetSorter()
{
    return m_spAccum;
}
//---------------------------------------------------------------------------
inline bool NiRenderer::GetTextureMemoryStats(unsigned int&, unsigned int&) 
{
    return false;
}
//---------------------------------------------------------------------------
inline bool NiRenderer::GetTextureStats(unsigned int&, unsigned int&,
    unsigned int&, unsigned int&, unsigned int&, unsigned int&)
{
    return false;
}
//---------------------------------------------------------------------------
inline unsigned int NiRenderer::GetTextureManagerStatus()
{
    return TEXTURE_MANAGER_NO_MANAGEMENT;
}
//---------------------------------------------------------------------------
inline NiDynamicEffectState* NiRenderer::GetEffectState()
{
    return m_pkCurrEffects;
}
//---------------------------------------------------------------------------
inline void NiRenderer::SetEffectState(NiDynamicEffectState* pkState)
{
    m_pkCurrEffects = pkState;
}
//---------------------------------------------------------------------------
inline NiPropertyState* NiRenderer::GetPropertyState()
{
    return m_pkCurrProp;
}
//---------------------------------------------------------------------------
inline void NiRenderer::SetPropertyState(NiPropertyState* pkState)
{
    m_pkCurrProp = pkState;
}
//---------------------------------------------------------------------------
inline NiRenderer* NiRenderer::GetRenderer()
{
    return ms_pkRenderer;
}
//---------------------------------------------------------------------------
inline bool NiRenderer::PreloadTexture(NiTexture* pkTexture) 
{ 
    return true; 
}
//---------------------------------------------------------------------------
inline void NiRenderer::UseClipPlanes(unsigned int uiFrustumFlags)
{
    m_uiClipPlaneFlags = uiFrustumFlags;
}
//---------------------------------------------------------------------------
inline void NiRenderer::LockSourceDataCriticalSection()
{
    m_kSourceDataCriticalSection.Lock();
}
//---------------------------------------------------------------------------
inline void NiRenderer::UnlockSourceDataCriticalSection()
{
    m_kSourceDataCriticalSection.Unlock();
}
//---------------------------------------------------------------------------
inline bool NiRenderer::GetBatchRendering() const
{
    return m_bBatchRendering;
}
//---------------------------------------------------------------------------
inline void NiRenderer::BeginPaint()
{
}
//---------------------------------------------------------------------------
inline void NiRenderer::EndPaint()
{
}
//---------------------------------------------------------------------------
