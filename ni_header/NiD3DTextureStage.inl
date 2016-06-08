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
// NiD3DTextureStage inline functions
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
inline unsigned int NiD3DTextureStage::GetStage()
{
    return m_uiStage;
}
//---------------------------------------------------------------------------
inline NiTexturePtr NiD3DTextureStage::GetTexture()
{
    return m_spTexture;
}
//---------------------------------------------------------------------------
inline unsigned int NiD3DTextureStage::GetTextureFlags()
{
    return m_uiTextureFlags;
}
//---------------------------------------------------------------------------
inline unsigned int NiD3DTextureStage::GetTextureTransformFlags()
{
    return m_uiTextureTransformFlags;
}
//---------------------------------------------------------------------------
inline bool NiD3DTextureStage::GetUseIndexFromMap()
{
    if ((m_uiTextureFlags & TSTF_MAP_USE_MASK) == TSTF_MAP_USE_INDEX)
        return true;
    return false;
}
//---------------------------------------------------------------------------
inline NiD3DTextureStageGroup* NiD3DTextureStage::GetTextureStageGroup()
{
    return m_pkTextureStageGroup;
}
//---------------------------------------------------------------------------
inline D3DMATRIX& NiD3DTextureStage::GetTextureTransformation()
{
    return m_kTextureTransformation;
}
//---------------------------------------------------------------------------
inline void NiD3DTextureStage::SetStage(unsigned int uiStage)
{
    m_uiStage = uiStage;
}
//---------------------------------------------------------------------------
inline void NiD3DTextureStage::SetTexture(NiTexture* pkTexture)
{
    m_spTexture = pkTexture;
}
//---------------------------------------------------------------------------
inline void NiD3DTextureStage::SetNDLMap(unsigned int uiNDLMap)
{
    // Clear the DECAL and SHADER modes
    m_uiTextureFlags &= ~TSTF_MAP_MASK;

    // Set the given map flag
    m_uiTextureFlags |= uiNDLMap;
}
//---------------------------------------------------------------------------
inline void NiD3DTextureStage::SetDecalMap(unsigned int uiDecal)
{
    // Clear the Map and NDL sections
    m_uiTextureFlags &= ~(TSTF_MAP_MASK | TSTF_NDL_TYPEMASK);

    // Set decal mode and index
    m_uiTextureFlags |= (TSTF_MAP_DECAL | uiDecal);
}
//---------------------------------------------------------------------------
inline void NiD3DTextureStage::SetShaderMap(unsigned int uiShaderMap)
{
    // Clear the Map and NDL sections
    m_uiTextureFlags &= ~(TSTF_MAP_MASK | TSTF_NDL_TYPEMASK);

    // Set shader mode and index
    m_uiTextureFlags |= (TSTF_MAP_SHADER | uiShaderMap);
}
//---------------------------------------------------------------------------
inline void NiD3DTextureStage::SetUseIndexFromMap(bool bUse)
{
    if (bUse)
        m_uiTextureFlags |= TSTF_MAP_USE_INDEX;
    else
        m_uiTextureFlags &= ~TSTF_MAP_USE_INDEX;
}
//---------------------------------------------------------------------------
inline void NiD3DTextureStage::SetStageState(unsigned int uiState, 
    unsigned int uiValue, bool bSave)
{
    if (uiState == D3DTSS_TEXCOORDINDEX)
    {
        m_uiTexCoordIndex = uiValue;
        m_bSaveTexCoordIndex = bSave;
        return;
    }
    else if (uiState == D3DTSS_TEXTURETRANSFORMFLAGS)
    {
        if (uiValue != D3DTTFF_DISABLE && uiValue != D3DTTFF_PROJECTED)
            m_bTextureTransform = true;
        else
            m_bTextureTransform = false;
    }
    m_pkTextureStageGroup->SetStageState(uiState, uiValue, bSave);
}
//---------------------------------------------------------------------------
inline void NiD3DTextureStage::SetSamplerState(unsigned int uiState, 
    unsigned int uiValue, bool bSave)
{
    m_pkTextureStageGroup->SetSamplerState(uiState, uiValue, bSave);
}
//---------------------------------------------------------------------------
inline void NiD3DTextureStage::RemoveStageState(unsigned int uiState)
{
    m_pkTextureStageGroup->RemoveStageState(uiState);
}
//---------------------------------------------------------------------------
inline void NiD3DTextureStage::RemoveSamplerState(unsigned int uiState)
{
    m_pkTextureStageGroup->RemoveSamplerState(uiState);
}
//---------------------------------------------------------------------------
inline void NiD3DTextureStage::SetTextureTransformation(D3DMATRIX& kD3DMat)
{
    m_kTextureTransformation = kD3DMat;
}
//---------------------------------------------------------------------------
inline void NiD3DTextureStage::SetTextureTransformation(bool bUseTransform)
{
    m_bTextureTransform = bUseTransform;
}
//---------------------------------------------------------------------------
inline bool NiD3DTextureStage::IsTextureTransformation() const
{
    return m_bTextureTransform;
}
//---------------------------------------------------------------------------
inline void NiD3DTextureStage::SetTextureFlags(unsigned int uiFlags)
{
    m_uiTextureFlags = uiFlags;
}
//---------------------------------------------------------------------------
inline void NiD3DTextureStage::SetRendererOwned()
{
    m_bRendererOwned = true;
}
//---------------------------------------------------------------------------
inline bool NiD3DTextureStage::IsRendererOwned() const
{
    return m_bRendererOwned;
}
//---------------------------------------------------------------------------
inline void NiD3DTextureStage::IncRefCount()
{
    m_uiRefCount++;
}
//---------------------------------------------------------------------------
inline void NiD3DTextureStage::DecRefCount()
{
    m_uiRefCount--;
    if (m_uiRefCount == 0)
    {
        ReturnStageToPool();
    }
}
//---------------------------------------------------------------------------
