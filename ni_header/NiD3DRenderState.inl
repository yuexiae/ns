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
// NiD3DRenderState inline functions
//---------------------------------------------------------------------------
inline NiD3DRenderState::NiRenderStateSetting::NiRenderStateSetting() : 
    m_uiCurrValue(0x7FFFFFFF), 
    m_uiPrevValue(0x7FFFFFFF)
{
    //* *//
}
//---------------------------------------------------------------------------
inline void NiD3DRenderState::NiRenderStateSetting::SetValue(
    unsigned int uiValue, bool bSave)
{
    if (bSave)
        m_uiPrevValue = m_uiCurrValue;
    m_uiCurrValue = uiValue;
}
//---------------------------------------------------------------------------
inline void NiD3DRenderState::NiRenderStateSetting::InitValue(
    unsigned int uiValue)
{
    m_uiCurrValue = uiValue;
    m_uiPrevValue = uiValue;
}
//---------------------------------------------------------------------------
inline void NiD3DRenderState::NiRenderStateSetting::SaveValue()
{
    m_uiPrevValue = m_uiCurrValue;
}
//---------------------------------------------------------------------------
inline void NiD3DRenderState::NiRenderStateSetting::RestoreValue()
{
    m_uiCurrValue = m_uiPrevValue;
}
//---------------------------------------------------------------------------
inline unsigned int NiD3DRenderState::NiRenderStateSetting::GetValue() const
{
    return m_uiCurrValue;
}
//---------------------------------------------------------------------------
inline unsigned int NiD3DRenderState::NiRenderStateSetting::GetPrevValue() 
    const
{
    return m_uiPrevValue;
}
//---------------------------------------------------------------------------
inline void NiD3DRenderState::DisableAlpha()
{
    ApplyAlpha(m_spDisabledAlphaProperty);
}
//---------------------------------------------------------------------------
inline unsigned int NiD3DRenderState::GetSrcAlphaCaps()
{
    return m_uiSrcAlphaCaps;
}
//---------------------------------------------------------------------------
inline unsigned int NiD3DRenderState::GetDestAlphaCaps()
{
    return m_uiDestAlphaCaps;
}
//---------------------------------------------------------------------------
inline unsigned int NiD3DRenderState::GetD3DBlendMode(
    NiAlphaProperty::AlphaFunction eBlend)
{
    return m_auiAlphaMapping[eBlend];
}
//---------------------------------------------------------------------------
inline unsigned int NiD3DRenderState::GetD3DTestMode(
    NiAlphaProperty::TestFunction eTest)
{
    return m_auiAlphaTestMapping[eTest];
}
//---------------------------------------------------------------------------
inline void NiD3DRenderState::SetBoneCount(unsigned short usNumBones)
{
#if defined(_XENON)
    // D3DRS_VERTEXBLEND is not supported.
    return;
#endif  //#if defined(_XENON)
    SetRenderState(D3DRS_VERTEXBLEND, m_aD3DVertexBlendMappings[usNumBones]);
}
//---------------------------------------------------------------------------
inline float NiD3DRenderState::GetMaxFogValue()
{
    return m_fMaxFogValue;
}
//---------------------------------------------------------------------------
inline void NiD3DRenderState::SetMaxFogValue(float fFogVal)
{
    if (fFogVal <= 0.0f)
        fFogVal = 1e-5f;

    m_fMaxFogValue = fFogVal;
    m_fMaxFogFactor = 1.0f / fFogVal - 1.0f;
}
//---------------------------------------------------------------------------
inline void NiD3DRenderState::SetCameraNearAndFar(float fNear, float fFar)
{
    m_fCameraNear = fNear;
    m_fCameraFar = fFar;
    m_fCameraDepthRange = fFar - fNear;
}
//---------------------------------------------------------------------------
inline bool NiD3DRenderState::GetLeftHanded()
{
    return m_uiLeftHanded ? true : false;
}
//---------------------------------------------------------------------------
inline void NiD3DRenderState::SetLeftHanded(bool bLeft)
{
    m_uiLeftHanded = bLeft ? 1 : 0;
}
//---------------------------------------------------------------------------
inline void NiD3DRenderState::SetRenderState(D3DRENDERSTATETYPE eState, 
    unsigned int uiValue, bool bSave)
{
    if (m_akRenderStateSettings[eState].GetValue() != uiValue)
        m_pkD3DDevice->SetRenderState(eState, uiValue);
    m_akRenderStateSettings[eState].SetValue(uiValue, bSave);
}
//---------------------------------------------------------------------------
inline unsigned int NiD3DRenderState::GetRenderState(
    D3DRENDERSTATETYPE eState) const
{
    return m_akRenderStateSettings[eState].GetValue();
}
//---------------------------------------------------------------------------
inline void NiD3DRenderState::RestoreRenderState(D3DRENDERSTATETYPE eState)
{
    SetRenderState(eState, m_akRenderStateSettings[eState].GetPrevValue());
}
//---------------------------------------------------------------------------
inline void NiD3DRenderState::SetPixelShader(NiD3DPixelShaderHandle hShader, 
    bool bSave)
{
    if (bSave)
        m_hPreviousPixelShader = m_hCurrentPixelShader;
    if (m_hCurrentPixelShader != hShader)
    {
        m_hCurrentPixelShader = hShader;
        m_pkD3DDevice->SetPixelShader(m_hCurrentPixelShader);
    }
}
//---------------------------------------------------------------------------
inline NiD3DPixelShaderHandle NiD3DRenderState::GetPixelShader() const
{
    return m_hCurrentPixelShader;
}
//---------------------------------------------------------------------------
inline void NiD3DRenderState::RestorePixelShader()
{
    SetPixelShader(m_hPreviousPixelShader);
}
//---------------------------------------------------------------------------
inline void NiD3DRenderState::ClearPixelShader(
    NiD3DPixelShaderHandle hShader)
{
    if (m_hCurrentPixelShader == hShader)
    {
        // We need to clear this!
        m_hCurrentPixelShader = 0;
        m_pkD3DDevice->SetPixelShader(0);
    }

    if (m_hPreviousPixelShader == hShader)
    {
        // This is likely a bad thing to have happening
        // If someone calls restore on this, they will have lost what
        // was happening
        m_hPreviousPixelShader = 0;
    }
}
//---------------------------------------------------------------------------
inline void NiD3DRenderState::SetTextureStageState(unsigned int uiStage, 
    D3DTEXTURESTAGESTATETYPE eState, unsigned int uiValue, bool bSave)
{
    if (m_akTextureStageStateSettings[uiStage][eState].GetValue() != uiValue)
        m_pkD3DDevice->SetTextureStageState(uiStage, eState, uiValue);
    m_akTextureStageStateSettings[uiStage][eState].SetValue(uiValue, 
        bSave);
}
//---------------------------------------------------------------------------
inline unsigned int NiD3DRenderState::GetTextureStageState(unsigned int uiStage, 
    D3DTEXTURESTAGESTATETYPE eState) const
{
    return m_akTextureStageStateSettings[uiStage][eState].GetValue();
}
//---------------------------------------------------------------------------
inline void NiD3DRenderState::RestoreTextureStageState(unsigned int uiStage, 
    D3DTEXTURESTAGESTATETYPE eState)
{
    SetTextureStageState(uiStage, eState, 
        m_akTextureStageStateSettings[uiStage][eState].GetPrevValue());
}
//---------------------------------------------------------------------------
inline void NiD3DRenderState::InitTextures()
{
    for (unsigned int ui = 0; ui < NI_MAX_TEXTURE_STAGES; ui++)
        m_apkTextureStageTextures[ui] = 0;
}
//---------------------------------------------------------------------------
inline void NiD3DRenderState::SetTexture(unsigned int uiStage, 
    D3DBaseTexturePtr pkTexture)
{
    assert(uiStage < NI_MAX_TEXTURE_STAGES);
    if (m_apkTextureStageTextures[uiStage] != pkTexture)
    {
        m_apkTextureStageTextures[uiStage] = pkTexture;
        m_pkD3DDevice->SetTexture(uiStage, pkTexture);
    }
}
//---------------------------------------------------------------------------
inline D3DBaseTexturePtr NiD3DRenderState::GetTexture(unsigned int uiStage)
{
    assert(uiStage < NI_MAX_TEXTURE_STAGES);
    return m_apkTextureStageTextures[uiStage];
}
//---------------------------------------------------------------------------
inline void NiD3DRenderState::ClearTexture(D3DBaseTexturePtr pkTexture)
{
    if (!pkTexture)
        return;
    for (unsigned int uiStage = 0; uiStage < NI_MAX_TEXTURE_STAGES; 
        uiStage++)
    {
        if (m_apkTextureStageTextures[uiStage] == pkTexture)
        {
            m_apkTextureStageTextures[uiStage] = 0;
            m_pkD3DDevice->SetTexture(uiStage, 0);
        }
    }
}
//---------------------------------------------------------------------------
#if defined(_XBOX) && !defined(_XENON)
//---------------------------------------------------------------------------
inline void NiD3DRenderState::InitPalettes()
{
    for (unsigned int ui = 0; ui < NI_MAX_TEXTURE_STAGES; ui++)
        m_apkPalettes[ui] = 0;
}
//---------------------------------------------------------------------------
inline void NiD3DRenderState::SetPalette(unsigned int uiStage, 
    D3DPalettePtr pkPalette)
{
    assert(uiStage < NI_MAX_TEXTURE_STAGES);
    if (m_apkPalettes[uiStage] != pkPalette)
    {
        m_apkPalettes[uiStage] = pkPalette;
        m_pkD3DDevice->SetPalette(uiStage, pkPalette);
    }
}
//---------------------------------------------------------------------------
inline D3DPalettePtr NiD3DRenderState::GetPalette(unsigned int uiStage)
{
    assert(uiStage < NI_MAX_TEXTURE_STAGES);
    return m_apkPalettes[uiStage];
}
//---------------------------------------------------------------------------
inline void NiD3DRenderState::ClearPalette(D3DPalettePtr pkPalette)
{
    if (!pkPalette)
        return;
    for (unsigned int uiStage = 0; uiStage < NI_MAX_TEXTURE_STAGES; uiStage++)
    {
        if (m_apkPalettes[uiStage] == pkPalette)
        {
            m_apkPalettes[uiStage] = 0;
            m_pkD3DDevice->SetPalette(uiStage, 0);
        }
    }
}
//---------------------------------------------------------------------------
inline void NiD3DRenderState::SetStreamSource(unsigned int uiStream, 
    D3DVertexBufferPtr pkStreamSource, unsigned int uiStride)
{
    assert(uiStream < m_uiMaxStreams);

    m_pkStreamSources[uiStream].m_pkVB = pkStreamSource;
    m_pkStreamSources[uiStream].m_uiStride = uiStride;

    m_pkD3DDevice->SetStreamSource(uiStream, pkStreamSource, uiStride);
}
//---------------------------------------------------------------------------
inline D3DVertexBufferPtr NiD3DRenderState::GetStreamSource(
    unsigned int uiStream, unsigned int* puiStride)
{
    assert(uiStream < m_uiMaxStreams);

    if (puiStride)
        *puiStride = m_pkStreamSources[uiStream].m_uiStride;
    return m_pkStreamSources[uiStream].m_pkVB;
}
//---------------------------------------------------------------------------
inline void NiD3DRenderState::ClearStreamSource(
    D3DVertexBufferPtr pkStreamSource)
{
    for (unsigned int uiStream = 0; uiStream < m_uiMaxStreams; uiStream++)
    {
        if (m_pkStreamSources[uiStream].m_pkVB == pkStreamSource)
        {
            m_pkD3DDevice->SetStreamSource(uiStream, 0, 0);
            m_pkStreamSources[uiStream].m_pkVB = 0;
        }
    }
}
//---------------------------------------------------------------------------
#endif  //#if defined(_XBOX) && !defined(_XENON)
//---------------------------------------------------------------------------
inline bool NiD3DRenderState::SetVertexShaderConstantB(
    unsigned int uiStartRegister, const BOOL* pbConstantData, 
    unsigned int uiBoolCount, bool bSave)
{
    return m_spShaderConstantManager->SetVertexShaderConstantB(
        uiStartRegister, pbConstantData, uiBoolCount, bSave);
}
//---------------------------------------------------------------------------
inline bool NiD3DRenderState::GetVertexShaderConstantB(
    unsigned int uiStartRegister, BOOL* pbConstantData, 
    unsigned int uiBoolCount)
{
    return m_spShaderConstantManager->GetVertexShaderConstantB(
        uiStartRegister, pbConstantData, uiBoolCount);
}
//---------------------------------------------------------------------------
inline bool NiD3DRenderState::RestoreVertexShaderConstantB(
    unsigned int uiStartRegister, unsigned int uiBoolCount)
{
    return m_spShaderConstantManager->RestoreVertexShaderConstantB(
        uiStartRegister, uiBoolCount);
}
//---------------------------------------------------------------------------
inline bool NiD3DRenderState::SetVertexShaderConstantF(
    unsigned int uiStartRegister, const float* pfConstantData, 
    unsigned int uiFloat4Count, bool bSave)
{
    return m_spShaderConstantManager->SetVertexShaderConstantF(
        uiStartRegister, pfConstantData, uiFloat4Count, bSave);
}
//---------------------------------------------------------------------------
inline bool NiD3DRenderState::GetVertexShaderConstantF(
    unsigned int uiStartRegister, float* pfConstantData, 
    unsigned int uiFloat4Count)
{
    return m_spShaderConstantManager->GetVertexShaderConstantF(
        uiStartRegister, pfConstantData, uiFloat4Count);
}
//---------------------------------------------------------------------------
inline bool NiD3DRenderState::RestoreVertexShaderConstantF(
    unsigned int uiStartRegister, unsigned int uiFloat4Count)
{
    return m_spShaderConstantManager->RestoreVertexShaderConstantF(
        uiStartRegister, uiFloat4Count);
}
//---------------------------------------------------------------------------
inline bool NiD3DRenderState::SetVertexShaderConstantI(
    unsigned int uiStartRegister, const int* piConstantData, 
    unsigned int uiInt4Count, bool bSave)
{
    return m_spShaderConstantManager->SetVertexShaderConstantI(
        uiStartRegister, piConstantData, uiInt4Count, bSave);
}
//---------------------------------------------------------------------------
inline bool NiD3DRenderState::GetVertexShaderConstantI(
    unsigned int uiStartRegister, int* piConstantData, 
    unsigned int uiInt4Count)
{
    return m_spShaderConstantManager->GetVertexShaderConstantI(
        uiStartRegister, piConstantData, uiInt4Count);
}
//---------------------------------------------------------------------------
inline bool NiD3DRenderState::RestoreVertexShaderConstantI(
    unsigned int uiStartRegister, unsigned int uiInt4Count)
{
    return m_spShaderConstantManager->RestoreVertexShaderConstantI(
        uiStartRegister, uiInt4Count);
}
//---------------------------------------------------------------------------
inline bool NiD3DRenderState::SetVertexShaderConstant(
    unsigned int uiStartRegister, const float* pfConstantData, 
    unsigned int uiFloat4Count, bool bSave)
{
    return m_spShaderConstantManager->SetVertexShaderConstantF(
        uiStartRegister, pfConstantData, uiFloat4Count, bSave);
}
//---------------------------------------------------------------------------
inline bool NiD3DRenderState::GetVertexShaderConstant(
    unsigned int uiStartRegister, float* pfConstantData, 
    unsigned int uiFloat4Count)
{
    return m_spShaderConstantManager->GetVertexShaderConstantF(
        uiStartRegister, pfConstantData, uiFloat4Count);
}
//---------------------------------------------------------------------------
inline bool NiD3DRenderState::RestoreVertexShaderConstant(
    unsigned int uiStartRegister, unsigned int uiFloat4Count)
{
    return m_spShaderConstantManager->RestoreVertexShaderConstantF(
        uiStartRegister, uiFloat4Count);
}
//---------------------------------------------------------------------------
inline bool NiD3DRenderState::SetPixelShaderConstantB(
    unsigned int uiStartRegister, const BOOL* pbConstantData, 
    unsigned int uiBoolCount, bool bSave)
{
    return m_spShaderConstantManager->SetPixelShaderConstantB(
        uiStartRegister, pbConstantData, uiBoolCount, bSave);
}
//---------------------------------------------------------------------------
inline bool NiD3DRenderState::GetPixelShaderConstantB(
    unsigned int uiStartRegister, BOOL* pbConstantData, 
    unsigned int uiBoolCount)
{
    return m_spShaderConstantManager->GetPixelShaderConstantB(
        uiStartRegister, pbConstantData, uiBoolCount);
}
//---------------------------------------------------------------------------
inline bool NiD3DRenderState::RestorePixelShaderConstantB(
    unsigned int uiStartRegister, unsigned int uiBoolCount)
{
    return m_spShaderConstantManager->RestorePixelShaderConstantB(
        uiStartRegister, uiBoolCount);
}
//---------------------------------------------------------------------------
inline bool NiD3DRenderState::SetPixelShaderConstantF(
    unsigned int uiStartRegister, const float* pfConstantData, 
    unsigned int uiFloat4Count, bool bSave)
{
    return m_spShaderConstantManager->SetPixelShaderConstantF(
        uiStartRegister, pfConstantData, uiFloat4Count, bSave);
}
//---------------------------------------------------------------------------
inline bool NiD3DRenderState::GetPixelShaderConstantF(
    unsigned int uiStartRegister, float* pfConstantData, 
    unsigned int uiFloat4Count)
{
    return m_spShaderConstantManager->GetPixelShaderConstantF(
        uiStartRegister, pfConstantData, uiFloat4Count);
}
//---------------------------------------------------------------------------
inline bool NiD3DRenderState::RestorePixelShaderConstantF(
    unsigned int uiStartRegister, unsigned int uiFloat4Count)
{
    return m_spShaderConstantManager->RestorePixelShaderConstantF(
        uiStartRegister, uiFloat4Count);
}
//---------------------------------------------------------------------------
inline bool NiD3DRenderState::SetPixelShaderConstantI(
    unsigned int uiStartRegister, const int* piConstantData, 
    unsigned int uiInt4Count, bool bSave)
{
    return m_spShaderConstantManager->SetPixelShaderConstantI(
        uiStartRegister, piConstantData, uiInt4Count, bSave);
}
//---------------------------------------------------------------------------
inline bool NiD3DRenderState::GetPixelShaderConstantI(
    unsigned int uiStartRegister, int* piConstantData, 
    unsigned int uiInt4Count)
{
    return m_spShaderConstantManager->GetPixelShaderConstantI(
        uiStartRegister, piConstantData, uiInt4Count);
}
//---------------------------------------------------------------------------
inline bool NiD3DRenderState::RestorePixelShaderConstantI(
    unsigned int uiStartRegister, unsigned int uiInt4Count)
{
    return m_spShaderConstantManager->RestorePixelShaderConstantI(
        uiStartRegister, uiInt4Count);
}
//---------------------------------------------------------------------------
inline bool NiD3DRenderState::SetPixelShaderConstant(
    unsigned int uiStartRegister, const float* pfConstantData, 
    unsigned int uiFloat4Count, bool bSave)
{
    return m_spShaderConstantManager->SetPixelShaderConstantF(
        uiStartRegister, pfConstantData, uiFloat4Count, bSave);
}
//---------------------------------------------------------------------------
inline bool NiD3DRenderState::GetPixelShaderConstant(
    unsigned int uiStartRegister, float* pfConstantData, 
    unsigned int uiFloat4Count)
{
    return m_spShaderConstantManager->GetPixelShaderConstantF(
        uiStartRegister, pfConstantData, uiFloat4Count);
}
//---------------------------------------------------------------------------
inline bool NiD3DRenderState::RestorePixelShaderConstant(
    unsigned int uiStartRegister, unsigned int uiFloat4Count)
{
    return m_spShaderConstantManager->RestorePixelShaderConstantF(
        uiStartRegister, uiFloat4Count);
}
//---------------------------------------------------------------------------
inline void NiD3DRenderState::CommitShaderConstants()
{
    m_spShaderConstantManager->CommitChanges();
#if defined(_XBOX) && !defined(_XENON)
    m_pkD3DDevice->SetVertexShader(m_hCurrentVertexShader);
#endif  //#if defined(_XBOX) && !defined(_XENON)
}
//---------------------------------------------------------------------------
inline const unsigned int NiD3DRenderState::GetFlags()
{
    return m_uiFlags;
}
//---------------------------------------------------------------------------
inline void NiD3DRenderState::ClearFlags()
{
    m_uiFlags = 0x0;
}
//---------------------------------------------------------------------------
inline void NiD3DRenderState::ClearFlag(unsigned int uiFlag)
{
    m_uiFlags &= ~uiFlag;
}
//---------------------------------------------------------------------------
inline void NiD3DRenderState::SetFlag(unsigned int uiFlag)
{
    m_uiFlags |= uiFlag;
}
//---------------------------------------------------------------------------
inline void NiD3DRenderState::ToggleFlag(unsigned int uiFlag)
{
    m_uiFlags ^= uiFlag;
}
//---------------------------------------------------------------------------
inline void NiD3DRenderState::CopyFlag(unsigned int uiFlag, bool bSet)
{
    if(bSet)
        m_uiFlags |= uiFlag;
    else
        m_uiFlags &= ~uiFlag;
}
//---------------------------------------------------------------------------
inline bool NiD3DRenderState::IsFlag(unsigned int uiFlag)
{
    return (uiFlag & m_uiFlags) ? true : false;
}
//---------------------------------------------------------------------------
inline bool NiD3DRenderState::IsNotFlag(unsigned int uiFlag)
{
    return (uiFlag & m_uiFlags) ? false : true;
}
//---------------------------------------------------------------------------
inline void NiD3DRenderState::SetForceNormalizeNormals(bool bSet)
{
    m_bForceNormalizeNormals = bSet;
}
//---------------------------------------------------------------------------
inline bool NiD3DRenderState::GetForceNormalizeNormals() const
{
    return m_bForceNormalizeNormals;
}
//---------------------------------------------------------------------------
inline void NiD3DRenderState::SetInternalNormalizeNormals(bool bSet)
{
    m_bInternalNormalizeNormals = bSet;
}
//---------------------------------------------------------------------------
inline bool NiD3DRenderState::GetInternalNormalizeNormals() const
{
    return m_bInternalNormalizeNormals;
}
//---------------------------------------------------------------------------
