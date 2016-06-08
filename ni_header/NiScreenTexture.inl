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
inline const NiScreenTexture::ScreenRect& NiScreenTexture::GetScreenRect(
    unsigned int uiIndex) const
{
    assert(uiIndex < m_kScreenRects.GetSize());

    return m_kScreenRects.GetAt(uiIndex);
}
//---------------------------------------------------------------------------
inline NiScreenTexture::ScreenRect& NiScreenTexture::GetScreenRect(
    unsigned int uiIndex)
{
    assert(uiIndex < m_kScreenRects.GetSize());

    return m_kScreenRects.GetAt(uiIndex);
}
//---------------------------------------------------------------------------
inline unsigned int NiScreenTexture::GetNumScreenRects() const
{
    return m_kScreenRects.GetSize();
}
//---------------------------------------------------------------------------
inline NiTexture* NiScreenTexture::GetTexture() const
{
    return m_spTexProp->GetBaseTexture();
}
//---------------------------------------------------------------------------
inline void NiScreenTexture::SetTexture(NiTexture* pkTexture)
{
    m_spTexProp->SetBaseTexture(pkTexture);
}
//---------------------------------------------------------------------------
inline NiTexturingProperty::ClampMode NiScreenTexture::GetClampMode() const
{
    return m_spTexProp->GetBaseClampMode();
}
//---------------------------------------------------------------------------
inline void NiScreenTexture::SetClampMode(
    NiTexturingProperty::ClampMode eClampMode)
{
    m_spTexProp->SetBaseClampMode(eClampMode);
}
//---------------------------------------------------------------------------
inline NiTexturingProperty::ApplyMode NiScreenTexture::GetApplyMode() const
{
    return m_spTexProp->GetApplyMode();
}
//---------------------------------------------------------------------------
inline void NiScreenTexture::SetApplyMode(
    NiTexturingProperty::ApplyMode eApplyMode)
{
    m_spTexProp->SetApplyMode(eApplyMode);
}
//---------------------------------------------------------------------------
inline unsigned short NiScreenTexture::GetRevisionID() const
{
    return m_usDirtyFlags;
}
//---------------------------------------------------------------------------
inline void NiScreenTexture::MarkAsChanged(unsigned short usFlags)
{
    m_usDirtyFlags |= usFlags;
}
//---------------------------------------------------------------------------
inline void NiScreenTexture::ClearRevisionID()
{
    m_usDirtyFlags = 0;
}
//---------------------------------------------------------------------------
inline NiTexturingProperty* NiScreenTexture::GetTexturingProperty() const
{
    return m_spTexProp;
}
//---------------------------------------------------------------------------
#if defined(WIN32) || defined(_XBOX)
inline NiGeometryBufferData* NiScreenTexture::GetRendererData() const
{
    return m_pkBuffData;
}
//---------------------------------------------------------------------------
inline void NiScreenTexture::SetRendererData(
    NiGeometryBufferData* pkRendererData)
{
    m_pkBuffData = pkRendererData;
}
//---------------------------------------------------------------------------
#endif // defined(WIN32) || defined(_XBOX)

#ifdef PS2
//---------------------------------------------------------------------------
inline NiScreenTexture::PS2Data&
NiScreenTexture::GetRendererData(unsigned int i)
{
    return m_akRendererData[i];
}
//---------------------------------------------------------------------------
inline unsigned char& NiScreenTexture::GetRendererIndex()
{
    return m_ucIndex;
}
//---------------------------------------------------------------------------
inline NiScreenTexture::PS2Data::PS2Data()
{
    m_puqData = NULL;
    m_uiStamp = ~0;
}
#endif
