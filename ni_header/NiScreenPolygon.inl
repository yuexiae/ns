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
//  NiScreenPolygon inline functions

//---------------------------------------------------------------------------
inline NiScreenPolygon::NiScreenPolygon()
{
    m_usVertices = 0;
    m_pkVertex = 0;
    m_pkTexture = 0;
    m_pkColor = 0;
    m_usDirtyFlags = 0;

#if defined(WIN32) || defined(_XBOX)
    m_pkBuffData = 0;
#elif defined(PS2)
    m_ucIndex = 0;
#endif
}
//---------------------------------------------------------------------------
inline NiPropertyState* NiScreenPolygon::GetPropertyState() const
{
    return m_spPropertyState;
}
//---------------------------------------------------------------------------
inline void NiScreenPolygon::AttachProperty(NiProperty* pProperty)
{
    m_spPropertyState->SetProperty(pProperty);
}
//---------------------------------------------------------------------------
inline void NiScreenPolygon::DetachAllProperties()
{
    m_spPropertyState->Reset();
}
//---------------------------------------------------------------------------
inline unsigned short NiScreenPolygon::GetVertexCount() const
{
    return m_usVertices;
}
//---------------------------------------------------------------------------
inline const NiPoint3* NiScreenPolygon::GetVertices() const
{ 
    return m_pkVertex; 
}
//---------------------------------------------------------------------------
inline const NiPoint2* NiScreenPolygon::GetTextures() const
{ 
    return m_pkTexture; 
}
//---------------------------------------------------------------------------
inline const NiColorA* NiScreenPolygon::GetColors() const
{ 
    return m_pkColor; 
}
//---------------------------------------------------------------------------
inline NiPoint3* NiScreenPolygon::GetVertices()
{ 
    return m_pkVertex; 
}
//---------------------------------------------------------------------------
inline NiPoint2* NiScreenPolygon::GetTextures()
{ 
    return m_pkTexture; 
}
//---------------------------------------------------------------------------
inline NiColorA* NiScreenPolygon::GetColors()
{ 
    return m_pkColor; 
}
//---------------------------------------------------------------------------
inline void NiScreenPolygon::MarkAsChanged(unsigned short usFlags)
{
    m_usDirtyFlags |= usFlags;
}
//---------------------------------------------------------------------------
inline void NiScreenPolygon::ClearRevisionID()
{
    m_usDirtyFlags = 0;
}
//---------------------------------------------------------------------------
inline unsigned short NiScreenPolygon::GetRevisionID() const
{
    return m_usDirtyFlags;
}
//---------------------------------------------------------------------------
#if defined(PS2)
inline unsigned char& NiScreenPolygon::GetRendererIndex()
{
    return m_ucIndex;
}
//---------------------------------------------------------------------------
inline NiScreenPolygon::PS2Data& NiScreenPolygon::GetRendererData(
    unsigned int i)
{
    return m_akRendererData[i];
}
//---------------------------------------------------------------------------
inline NiScreenPolygon::PS2Data::PS2Data()
{
    m_puqData = NULL;
    m_uiStamp = ~0;
}
//---------------------------------------------------------------------------
#elif defined(WIN32) || defined(_XBOX)
inline NiGeometryBufferData* NiScreenPolygon::GetRendererData() const
{
    return m_pkBuffData;
}
//---------------------------------------------------------------------------
inline void NiScreenPolygon::SetRendererData(NiGeometryBufferData* pkBuffData)
{
    m_pkBuffData = pkBuffData;
}
//---------------------------------------------------------------------------
#elif defined(NGC)
//---------------------------------------------------------------------------
inline void* NiScreenPolygon::GetRendererData() const
{
    return m_pvBufferData;
}
//---------------------------------------------------------------------------
inline void NiScreenPolygon::SetRendererData(void* pvData)
{
    m_pvBufferData = pvData;
}
//---------------------------------------------------------------------------
#endif 
