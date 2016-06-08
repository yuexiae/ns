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
inline NiScreenGeometry::~NiScreenGeometry()
{/* */}
//---------------------------------------------------------------------------
inline unsigned int NiScreenGeometry::AddScreenElement(
    unsigned int uiNumVerts, NiPoint2* pkVertex, NiColorA* pkColor, 
    NiPoint2* pkTexture, unsigned short usNumTextureSets)
{
    NiScreenGeometryData* pkData = 
        NiSmartPointerCast(NiScreenGeometryData, m_spModelData);
    assert (pkData);
    return pkData->AddScreenElement(uiNumVerts, pkVertex, pkColor, pkTexture, 
        usNumTextureSets);
}
//---------------------------------------------------------------------------
inline unsigned int NiScreenGeometry::AddScreenElement(
    unsigned int uiNumVerts, short* psHorz, short* psVert, NiColorA* pkColor, 
    NiPoint2* pkTexture, unsigned short usNumTextureSets)
{
    NiScreenGeometryData* pkData = 
        NiSmartPointerCast(NiScreenGeometryData, m_spModelData);
    assert (pkData);
    return pkData->AddScreenElement(uiNumVerts, psHorz, psVert, pkColor, 
        pkTexture, usNumTextureSets);
}
//---------------------------------------------------------------------------
inline unsigned int NiScreenGeometry::AddScreenElementRect(float fLeft, 
    float fTop, float fWidth, float fHeight, NiColorA* pkColor, 
    NiPoint2* pkTexture, unsigned short usNumTextureSets)
{
    NiScreenGeometryData* pkData = 
        NiSmartPointerCast(NiScreenGeometryData, m_spModelData);
    assert (pkData);
    return pkData->AddScreenElementRect(fLeft, fTop, fWidth, fHeight, 
        pkColor, pkTexture, usNumTextureSets);
}
//---------------------------------------------------------------------------
inline unsigned int NiScreenGeometry::GetNumScreenElements() const
{
    NiScreenGeometryData* pkData = 
        NiSmartPointerCast(NiScreenGeometryData, m_spModelData);
    assert (pkData);
    return pkData->GetNumScreenElements();
}
//---------------------------------------------------------------------------
inline unsigned int NiScreenGeometry::GetScreenElementArraySize() const
{
    NiScreenGeometryData* pkData = 
        NiSmartPointerCast(NiScreenGeometryData, m_spModelData);
    assert (pkData);
    return pkData->GetScreenElementArraySize();
}
//---------------------------------------------------------------------------
inline NiScreenGeometryData::ScreenElement* NiScreenGeometry::GetScreenElement(
    unsigned int uiIndex) const
{
    NiScreenGeometryData* pkData = 
        NiSmartPointerCast(NiScreenGeometryData, m_spModelData);
    assert (pkData);
    return pkData->GetScreenElement(uiIndex);
}
//---------------------------------------------------------------------------
inline void NiScreenGeometry::SetScreenElement(unsigned int uiIndex, 
    NiScreenGeometryData::ScreenElement* pkElement)
{
    NiScreenGeometryData* pkData = 
        NiSmartPointerCast(NiScreenGeometryData, m_spModelData);
    assert (pkData);
    pkData->SetScreenElement(uiIndex, pkElement);
}
//---------------------------------------------------------------------------
inline bool NiScreenGeometry::RemoveScreenElement(unsigned int uiIndex)
{
    NiScreenGeometryData* pkData = 
        NiSmartPointerCast(NiScreenGeometryData, m_spModelData);
    assert (pkData);
    return pkData->RemoveScreenElement(uiIndex);
}
//---------------------------------------------------------------------------
inline void NiScreenGeometry::RemoveAllScreenElements()
{
    NiScreenGeometryData* pkData = 
        NiSmartPointerCast(NiScreenGeometryData, m_spModelData);
    assert (pkData);
    pkData->RemoveAllScreenElements();
}
//---------------------------------------------------------------------------
inline void NiScreenGeometry::UpdateGeometryData()
{
    NiScreenGeometryData* pkData = 
        NiSmartPointerCast(NiScreenGeometryData, m_spModelData);
    assert (pkData);
    pkData->UpdateGeometryData();
}
//---------------------------------------------------------------------------
inline bool NiScreenGeometry::GetPixelAccurate() const
{
    NiScreenGeometryData* pkData = 
        NiSmartPointerCast(NiScreenGeometryData, m_spModelData);
    assert (pkData);
    return pkData->GetPixelAccurate();
}
//---------------------------------------------------------------------------
inline void NiScreenGeometry::SetPixelAccurate(bool bAccurate)
{
    NiScreenGeometryData* pkData = 
        NiSmartPointerCast(NiScreenGeometryData, m_spModelData);
    assert (pkData);
    pkData->SetPixelAccurate(bAccurate);
}
//---------------------------------------------------------------------------
inline bool NiScreenGeometry::GetUnorderedElements() const
{
    NiScreenGeometryData* pkData = 
        NiSmartPointerCast(NiScreenGeometryData, m_spModelData);
    assert (pkData);
    return pkData->GetUnorderedElements();
}
//---------------------------------------------------------------------------
inline void NiScreenGeometry::SetUnorderedElements(bool bUnordered)
{
    NiScreenGeometryData* pkData = 
        NiSmartPointerCast(NiScreenGeometryData, m_spModelData);
    assert (pkData);
    pkData->SetUnorderedElements(bUnordered);
}
//---------------------------------------------------------------------------

