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
//  NiTexturingProperty inline functions

//---------------------------------------------------------------------------
inline bool NiTexturingProperty::Map::operator!=(const Map& kObj) const
{
    return !(*this == kObj);
}
//---------------------------------------------------------------------------
inline NiTexture* NiTexturingProperty::Map::GetTexture() const
{ 
    return m_spTexture; 
}
//---------------------------------------------------------------------------
inline void NiTexturingProperty::Map::SetTexture(NiTexture* pkTexture)
{
    m_spTexture = pkTexture;
}
//---------------------------------------------------------------------------
inline NiTexturingProperty::ClampMode
    NiTexturingProperty::Map::GetClampMode() const
{
    return m_eClamp; 
}
//---------------------------------------------------------------------------
inline void NiTexturingProperty::Map::SetClampMode(
    NiTexturingProperty::ClampMode eClampMode)
{
    m_eClamp = eClampMode;
}
//---------------------------------------------------------------------------
inline NiTexturingProperty::FilterMode
    NiTexturingProperty::Map::GetFilterMode() const
{
    return m_eFilter; 
}
//---------------------------------------------------------------------------
inline void NiTexturingProperty::Map::SetFilterMode(
    NiTexturingProperty::FilterMode eFilterMode)
{
    m_eFilter = eFilterMode;
}
//---------------------------------------------------------------------------
inline void NiTexturingProperty::Map::SetL(short sL)
{
    m_sL = sL;
}
//---------------------------------------------------------------------------
inline short NiTexturingProperty::Map::GetL() const
{
    return m_sL;
}
//---------------------------------------------------------------------------
inline void NiTexturingProperty::Map::SetK(short sK)
{
    m_sK = sK;
}
//---------------------------------------------------------------------------
inline short NiTexturingProperty::Map::GetK() const
{
    return m_sK;
}
//---------------------------------------------------------------------------
inline unsigned int NiTexturingProperty::Map::GetTextureIndex() const
{
    return m_uiTexCoord;
}
//---------------------------------------------------------------------------
inline void NiTexturingProperty::Map::SetTextureIndex(
    unsigned int uiIndex)
{
    m_uiTexCoord = uiIndex;
}
//---------------------------------------------------------------------------
inline NiTextureTransform* NiTexturingProperty::Map::GetTextureTransform()
{
    return m_pkTextureTransform;
}
//---------------------------------------------------------------------------
inline const NiTextureTransform* 
    NiTexturingProperty::Map::GetTextureTransform() const
{
    return m_pkTextureTransform;
}
//---------------------------------------------------------------------------
inline void NiTexturingProperty::Map::SetTextureTransform(
    NiTextureTransform* pkTextureTransform)
{
    m_pkTextureTransform = pkTextureTransform;
}
#if defined(PS2)
//---------------------------------------------------------------------------
inline bool NiTexturingProperty::Map::GetSmartMip() const
{
    return m_bSmartMip;
}
//---------------------------------------------------------------------------
inline void NiTexturingProperty::Map::SetSmartMip(bool bSmartMip)
{
    m_bSmartMip = bSmartMip;
}
#endif // PS2
//---------------------------------------------------------------------------
inline NiTexturingProperty::BumpMap::BumpMap() : Map()
{
    m_fLumaScale = 1.0f;
    m_fLumaOffset = 0.0f;
    m_fBumpMat00 = 0.5f;
    m_fBumpMat01 = 0.0f;
    m_fBumpMat10 = 0.0f;
    m_fBumpMat11 = 0.5f;
}
//---------------------------------------------------------------------------
inline NiTexturingProperty::BumpMap::BumpMap(NiTexture* pkTexture, 
    unsigned int uiIndex, ClampMode eClampMode, FilterMode eFilterMode,
    float fLumaScale, float fLumaOffset,
    float fBumpMat00, float fBumpMat01,  
    float fBumpMat10, float fBumpMat11)
: Map(pkTexture, uiIndex, eClampMode, eFilterMode)
{
    m_fLumaScale = fLumaScale;
    m_fLumaOffset = fLumaOffset;
    m_fBumpMat00 = fBumpMat00;
    m_fBumpMat01 = fBumpMat01;
    m_fBumpMat10 = fBumpMat10;
    m_fBumpMat11 = fBumpMat11;
}
//---------------------------------------------------------------------------
inline NiTexturingProperty::BumpMap::~BumpMap()
{
    /* */
}
//---------------------------------------------------------------------------
inline float NiTexturingProperty::BumpMap::GetLumaScale() const
{
    return m_fLumaScale;
}
//---------------------------------------------------------------------------
inline void NiTexturingProperty::BumpMap::SetLumaScale(float fVal)
{
    m_fLumaScale = fVal;
}
//---------------------------------------------------------------------------
inline float NiTexturingProperty::BumpMap::GetLumaOffset() const
{
    return m_fLumaOffset;
}
//---------------------------------------------------------------------------
inline void NiTexturingProperty::BumpMap::SetLumaOffset(float fVal)
{
    m_fLumaOffset = fVal;
}
//---------------------------------------------------------------------------
inline float NiTexturingProperty::BumpMap::GetBumpMat00() const
{
    return m_fBumpMat00;
}
//---------------------------------------------------------------------------
inline void NiTexturingProperty::BumpMap::SetBumpMat00(float fVal)
{
    m_fBumpMat00 = fVal;
}
//---------------------------------------------------------------------------
inline float NiTexturingProperty::BumpMap::GetBumpMat01() const
{
    return m_fBumpMat01;
}
//---------------------------------------------------------------------------
inline void NiTexturingProperty::BumpMap::SetBumpMat01(float fVal)
{
    m_fBumpMat01 = fVal;
}
//---------------------------------------------------------------------------
inline float NiTexturingProperty::BumpMap::GetBumpMat10() const
{
    return m_fBumpMat10;
}
//---------------------------------------------------------------------------
inline void NiTexturingProperty::BumpMap::SetBumpMat10(float fVal)
{
    m_fBumpMat10 = fVal;
}
//---------------------------------------------------------------------------
inline float NiTexturingProperty::BumpMap::GetBumpMat11() const
{
    return m_fBumpMat11;
}
//---------------------------------------------------------------------------
inline void NiTexturingProperty::BumpMap::SetBumpMat11(float fVal)
{
    m_fBumpMat11 = fVal;
}
//---------------------------------------------------------------------------
inline NiTexturingProperty::ShaderMap::ShaderMap() : Map()
{
    m_uiID = 0;
}
//---------------------------------------------------------------------------
inline NiTexturingProperty::ShaderMap::ShaderMap(NiTexture* pkTexture, 
    unsigned int uiIndex, ClampMode eClampMode, FilterMode eFilterMode,
    unsigned int uiID)
: Map(pkTexture, uiIndex, eClampMode, eFilterMode)
{
    m_uiID = uiID;
}
//---------------------------------------------------------------------------
inline NiTexturingProperty::ShaderMap::~ShaderMap()
{
    /* */
}
//---------------------------------------------------------------------------
inline unsigned int NiTexturingProperty::ShaderMap::GetID() const
{
    return m_uiID;
}
//---------------------------------------------------------------------------
inline void NiTexturingProperty::ShaderMap::SetID(unsigned int uiID)
{
    m_uiID = uiID;
}
//---------------------------------------------------------------------------
inline const NiTexturingProperty::Map* 
    NiTexturingProperty::GetBaseMap() const
{
    return m_kMaps.GetAt(BASE_INDEX);
}
//---------------------------------------------------------------------------
inline NiTexturingProperty::Map* NiTexturingProperty::GetBaseMap()
{
    return m_kMaps.GetAt(BASE_INDEX);
}
//---------------------------------------------------------------------------
inline void NiTexturingProperty::SetBaseMap(Map* pkMap)
{
    Map* pkOld = m_kMaps.GetAt(BASE_INDEX);
    if (pkMap != pkOld)
    {
        delete pkOld;
        m_kMaps.SetAt(BASE_INDEX, pkMap);
    }
}
//---------------------------------------------------------------------------
inline const NiTexturingProperty::Map* 
    NiTexturingProperty::GetDarkMap() const
{
    return m_kMaps.GetAt(DARK_INDEX);
}
//---------------------------------------------------------------------------
inline NiTexturingProperty::Map* NiTexturingProperty::GetDarkMap()
{
    return m_kMaps.GetAt(DARK_INDEX);
}
//---------------------------------------------------------------------------
inline void NiTexturingProperty::SetDarkMap(Map* pkMap)
{
    Map* pkOld = m_kMaps.GetAt(DARK_INDEX);
    if(pkMap != pkOld)
    {
        delete pkOld;
        m_kMaps.SetAt(DARK_INDEX, pkMap);
    }

    SetMultiTexture(pkMap);
}
//---------------------------------------------------------------------------
inline const NiTexturingProperty::Map* 
    NiTexturingProperty::GetDetailMap() const
{
    return m_kMaps.GetAt(DETAIL_INDEX);
}
//---------------------------------------------------------------------------
inline NiTexturingProperty::Map* NiTexturingProperty::GetDetailMap()
{
    return m_kMaps.GetAt(DETAIL_INDEX);
}
//---------------------------------------------------------------------------
inline void NiTexturingProperty::SetDetailMap(Map* pkMap)
{
    Map* pkOld = m_kMaps.GetAt(DETAIL_INDEX);
    if (pkMap != pkOld)
    {
        delete pkOld;
        m_kMaps.SetAt(DETAIL_INDEX, pkMap);
    }

    SetMultiTexture(pkMap);
}
//---------------------------------------------------------------------------
inline const NiTexturingProperty::Map* 
    NiTexturingProperty::GetGlossMap() const
{
    return m_kMaps.GetAt(GLOSS_INDEX);
}
//---------------------------------------------------------------------------
inline NiTexturingProperty::Map* NiTexturingProperty::GetGlossMap()
{
    return m_kMaps.GetAt(GLOSS_INDEX);
}
//---------------------------------------------------------------------------
inline void NiTexturingProperty::SetGlossMap(Map* pkMap)
{
    Map* pkOld = m_kMaps.GetAt(GLOSS_INDEX);
    if (pkMap != pkOld)
    {
        delete pkOld;
        m_kMaps.SetAt(GLOSS_INDEX, pkMap);
    }

    SetMultiTexture(pkMap);
}
//---------------------------------------------------------------------------
inline const NiTexturingProperty::Map* 
    NiTexturingProperty::GetGlowMap() const
{
    return m_kMaps.GetAt(GLOW_INDEX);
}
//---------------------------------------------------------------------------
inline NiTexturingProperty::Map* NiTexturingProperty::GetGlowMap()
{
    return m_kMaps.GetAt(GLOW_INDEX);
}
//---------------------------------------------------------------------------
inline void NiTexturingProperty::SetGlowMap(Map* pkMap)
{
    Map* pkOld = m_kMaps.GetAt(GLOW_INDEX);
    if (pkMap != pkOld)
    {
        delete pkOld;
        m_kMaps.SetAt(GLOW_INDEX, pkMap);
    }

    SetMultiTexture(pkMap);
}
//---------------------------------------------------------------------------
inline const NiTexturingProperty::BumpMap* 
    NiTexturingProperty::GetBumpMap() const
{
    // Item in the BUMP_MAP slot is always of the BumpMap subclass
    return (BumpMap*)(m_kMaps.GetAt(BUMP_INDEX));
}
//---------------------------------------------------------------------------
inline NiTexturingProperty::BumpMap* NiTexturingProperty::GetBumpMap()
{
    // Item in the BUMP_MAP slot is always of the BumpMap subclass
    return (BumpMap*)(m_kMaps.GetAt(BUMP_INDEX));
}
//---------------------------------------------------------------------------
inline void NiTexturingProperty::SetBumpMap(BumpMap* pkMap)
{
    // Item in the BUMP_MAP slot is always of the BumpMap subclass
    BumpMap* pkOld = (BumpMap*)(m_kMaps.GetAt(BUMP_INDEX));
    if (pkMap != pkOld)
    {
        delete pkOld;
        m_kMaps.SetAt(BUMP_INDEX, pkMap);
    }

    SetMultiTexture(pkMap);
}
//---------------------------------------------------------------------------
inline const NiTexturingProperty::Map* 
    NiTexturingProperty::GetDecalMap(unsigned int uiIndex) const
{
    assert((uiIndex + DECAL_BASE) < m_kMaps.GetSize());

    return m_kMaps.GetAt(uiIndex + DECAL_BASE);
}
//---------------------------------------------------------------------------
inline NiTexturingProperty::Map* NiTexturingProperty::GetDecalMap(
    unsigned int uiIndex)
{
    assert((uiIndex + DECAL_BASE) < m_kMaps.GetSize());

    return m_kMaps.GetAt(uiIndex + DECAL_BASE);
}
//---------------------------------------------------------------------------
inline unsigned int NiTexturingProperty::GetDecalArrayCount() const
{
    return m_kMaps.GetSize() - DECAL_BASE;
}
//---------------------------------------------------------------------------
inline unsigned int NiTexturingProperty::GetDecalMapCount() const
{
    return m_uiDecals;
}
//---------------------------------------------------------------------------
inline const NiTexturingProperty::ShaderMap* 
    NiTexturingProperty::GetShaderMap(unsigned int uiIndex) const
{
    if (!m_pkShaderMaps || (uiIndex >= m_pkShaderMaps->GetSize()))
        return 0;

    return m_pkShaderMaps->GetAt(uiIndex);
}
//---------------------------------------------------------------------------
inline NiTexturingProperty::ShaderMap* 
    NiTexturingProperty::GetShaderMap(unsigned int uiIndex)
{    
    if (!m_pkShaderMaps || (uiIndex >= m_pkShaderMaps->GetSize()))
        return 0;

    return m_pkShaderMaps->GetAt(uiIndex);
}
//---------------------------------------------------------------------------
inline unsigned int NiTexturingProperty::GetShaderArrayCount() const
{
    if (!m_pkShaderMaps)
        return 0;

    return m_pkShaderMaps->GetSize();
}
//---------------------------------------------------------------------------
inline unsigned int NiTexturingProperty::GetShaderMapCount() const
{
    if (!m_pkShaderMaps)
        return 0;

    return m_pkShaderMaps->GetEffectiveSize();
}
//---------------------------------------------------------------------------
inline NiTexturingProperty::ApplyMode NiTexturingProperty::GetApplyMode()
    const
{
    return m_eApply;
}
//---------------------------------------------------------------------------
inline void NiTexturingProperty::SetApplyMode(
    NiTexturingProperty::ApplyMode eMode)
{
    m_eApply = eMode;
}
//---------------------------------------------------------------------------
inline bool NiTexturingProperty::IsMultiTexture() const
{
    return m_bMultiTexture;
}
//---------------------------------------------------------------------------
inline int NiTexturingProperty::Type() const
{ 
    return NiProperty::TEXTURING; 
}
//---------------------------------------------------------------------------
inline int NiTexturingProperty::GetType()
{
    return NiProperty::TEXTURING;
}
//---------------------------------------------------------------------------
inline NiTexturingProperty *NiTexturingProperty::GetDefault()
{
    return ms_spDefault;
}
//---------------------------------------------------------------------------
inline bool NiTexturingProperty::IsEqualFast(
    const NiTexturingProperty& kProp) const
{
    // For now, return that any two distinct properties are different.
    return this == &kProp;
}
//---------------------------------------------------------------------------
inline const NiTArray<NiTexturingProperty::Map*>& 
    NiTexturingProperty::GetMaps() const
{
    return m_kMaps;
}
//---------------------------------------------------------------------------
inline NiTexture* NiTexturingProperty::GetBaseTexture() const
{
    Map* pkBaseMap = m_kMaps.GetAt(0);
    if (pkBaseMap)
        return pkBaseMap->GetTexture();
    else
        return 0;
}
//---------------------------------------------------------------------------
inline void NiTexturingProperty::SetBaseTexture(NiTexture* pkTexture)
{
    Map* pkBaseMap = m_kMaps.GetAt(0);
    if (!pkBaseMap)
    {
        pkBaseMap = new Map;
        m_kMaps.SetAt(0, pkBaseMap);
    }

    pkBaseMap->SetTexture(pkTexture);
}
//---------------------------------------------------------------------------
inline NiTexturingProperty::ClampMode NiTexturingProperty::GetBaseClampMode() 
    const
{
    Map* pkBaseMap = m_kMaps.GetAt(0);
    if (pkBaseMap)
        return pkBaseMap->GetClampMode();
    else
        return WRAP_S_WRAP_T;
}
//---------------------------------------------------------------------------
inline void NiTexturingProperty::SetBaseClampMode(
    NiTexturingProperty::ClampMode eMode)
{
    Map* pkBaseMap = m_kMaps.GetAt(0);
    if (!pkBaseMap)
    {
        pkBaseMap = new Map;
        m_kMaps.SetAt(0, pkBaseMap);
    }

    pkBaseMap->SetClampMode(eMode);
}
//---------------------------------------------------------------------------
inline NiTexturingProperty::FilterMode 
    NiTexturingProperty::GetBaseFilterMode() const
{
    Map* pkBaseMap = m_kMaps.GetAt(0);
    if (pkBaseMap)
        return pkBaseMap->GetFilterMode();
    else
        return FILTER_NEAREST;
}
//---------------------------------------------------------------------------
inline void NiTexturingProperty::SetBaseFilterMode(
    NiTexturingProperty::FilterMode eMode)
{
    Map* pkBaseMap = m_kMaps.GetAt(0);
    if (!pkBaseMap)
    {
        pkBaseMap = new Map;
        m_kMaps.SetAt(0, pkBaseMap);
    }

    pkBaseMap->SetFilterMode(eMode);
}
//---------------------------------------------------------------------------
inline short NiTexturingProperty::GetBaseL() const
{
    Map* pkBaseMap = m_kMaps.GetAt(0);
    if (pkBaseMap)
        return pkBaseMap->GetL();
    else
        return 0;
}
//---------------------------------------------------------------------------
inline void NiTexturingProperty::SetBaseL(short sL)
{
    Map* pkBaseMap = m_kMaps.GetAt(0);
    if (!pkBaseMap)
    {
        pkBaseMap = new Map;
        m_kMaps.SetAt(0, pkBaseMap);
    }

    pkBaseMap->SetL(sL);
}
//---------------------------------------------------------------------------
inline short NiTexturingProperty::GetBaseK() const
{
    Map* pkBaseMap = m_kMaps.GetAt(0);
    if (pkBaseMap)
        return pkBaseMap->GetK();
    else
        return 0;
}  
//---------------------------------------------------------------------------
inline void NiTexturingProperty::SetBaseK(short sK)
{
    Map* pkBaseMap = m_kMaps.GetAt(0);
    if (!pkBaseMap)
    {
        pkBaseMap = new Map;
        m_kMaps.SetAt(0, pkBaseMap);
    }

    pkBaseMap->SetK(sK);
}
//---------------------------------------------------------------------------
inline unsigned int NiTexturingProperty::GetBaseTextureIndex() const
{
    Map* pkBaseMap = m_kMaps.GetAt(0);
    if (pkBaseMap)
        return pkBaseMap->GetTextureIndex();
    else
        return 0;
}
//---------------------------------------------------------------------------
inline void NiTexturingProperty::SetBaseTextureIndex(unsigned int uiIndex)
{
    Map* pkBaseMap = m_kMaps.GetAt(0);
    if (!pkBaseMap)
    {
        pkBaseMap = new Map;
        m_kMaps.SetAt(0, pkBaseMap);
    }

    pkBaseMap->SetTextureIndex(uiIndex);
}
//---------------------------------------------------------------------------
inline NiTextureTransform* NiTexturingProperty::GetBaseTextureTransform() 
    const
{
    Map* pkBaseMap = m_kMaps.GetAt(0);
    if (pkBaseMap)
        return pkBaseMap->GetTextureTransform();
    else
        return NULL;
}
//---------------------------------------------------------------------------
inline void NiTexturingProperty::SetBaseTextureTransform(
    NiTextureTransform* pkTransform)
{
    Map* pkBaseMap = m_kMaps.GetAt(0);
    if (!pkBaseMap)
    {
        pkBaseMap = new Map;
        m_kMaps.SetAt(0, pkBaseMap);
    }

    pkBaseMap->SetTextureTransform(pkTransform);
}
//---------------------------------------------------------------------------