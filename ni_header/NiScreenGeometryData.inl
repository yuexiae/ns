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
inline unsigned short NiScreenGeometryData::ScreenElement::GetVertexCount() 
    const
{
    return m_usNumVerts;
}
//---------------------------------------------------------------------------
inline const NiPoint2* NiScreenGeometryData::ScreenElement::GetVertices() 
    const
{
    return m_pkVerts;
}
//---------------------------------------------------------------------------
inline const NiPoint2* NiScreenGeometryData::ScreenElement::GetVertex(
    unsigned int uiIndex) const
{
    if (uiIndex < m_usNumVerts)
        return &m_pkVerts[uiIndex];
    return NULL;
}
//---------------------------------------------------------------------------
inline void NiScreenGeometryData::ScreenElement::SetVertex(
    unsigned int uiIndex, const NiPoint2& kVertex)
{
    if (uiIndex < m_usNumVerts)
        m_pkVerts[uiIndex] = kVertex;
}
//---------------------------------------------------------------------------
inline const NiColorA* NiScreenGeometryData::ScreenElement::GetColors() const
{
    return m_pkColors;
}
//---------------------------------------------------------------------------
inline const NiColorA* NiScreenGeometryData::ScreenElement::GetColor(
    unsigned int uiIndex) const
{
    if (uiIndex < m_usNumVerts)
        return &m_pkColors[uiIndex];
    return NULL;
}
//---------------------------------------------------------------------------
inline void NiScreenGeometryData::ScreenElement::SetColor(
    unsigned int uiIndex, const NiColorA& kColor)
{
    if (uiIndex < m_usNumVerts)
        m_pkColors[uiIndex] = kColor;
}
//---------------------------------------------------------------------------
inline unsigned short NiScreenGeometryData::ScreenElement::GetTextureSets() 
    const
{
    return m_usNumTexCoordSets;
}
//---------------------------------------------------------------------------
inline const NiPoint2* NiScreenGeometryData::ScreenElement::GetTextures() 
    const
{
    return m_pkTexCoords;
}
//---------------------------------------------------------------------------
inline const NiPoint2* NiScreenGeometryData::ScreenElement::GetTextureSet(
    unsigned short usSet) const
{
    if (usSet < m_usNumTexCoordSets)
        return &m_pkTexCoords[usSet * m_usNumVerts];
    return NULL;
}
//---------------------------------------------------------------------------
inline const NiPoint2* NiScreenGeometryData::ScreenElement::GetTextureCoord(
    unsigned short usSet, unsigned int uiIndex) const
{
    if (uiIndex < m_usNumVerts && usSet < m_usNumTexCoordSets)
        return &m_pkTexCoords[usSet * m_usNumVerts + uiIndex];
    return NULL;
}
//---------------------------------------------------------------------------
inline void NiScreenGeometryData::ScreenElement::SetTextureCoord(
    unsigned short usSet, unsigned int uiIndex, const NiPoint2& kTexCoord)
{
    if (uiIndex < m_usNumVerts && usSet < m_usNumTexCoordSets)
        m_pkTexCoords[usSet * m_usNumVerts + uiIndex] = kTexCoord;
}
//---------------------------------------------------------------------------
inline unsigned short NiScreenGeometryData::GetActiveVertexCount() const
{
    return m_usActiveVerts;
}
//---------------------------------------------------------------------------
inline bool NiScreenGeometryData::GetPixelAccurate() const
{
    return m_bPixelAccurate;
}
//---------------------------------------------------------------------------
inline void NiScreenGeometryData::SetPixelAccurate(bool bAccurate)
{
    m_bPixelAccurate = bAccurate;
}
//---------------------------------------------------------------------------
inline bool NiScreenGeometryData::GetUnorderedElements() const
{
    return m_bPixelAccurate;
}
//---------------------------------------------------------------------------
inline void NiScreenGeometryData::SetUnorderedElements(bool bUnordered)
{
    m_bUnorderedElements = bUnordered;
}
//---------------------------------------------------------------------------
