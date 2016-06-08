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
//  NiGeometry inline functions

//---------------------------------------------------------------------------
inline NiGeometryData* NiGeometry::GetModelData() const
{
    return m_spModelData;
}
//---------------------------------------------------------------------------
inline unsigned short NiGeometry::GetVertexCount() const
{
    return m_spModelData->GetVertexCount();
}
//---------------------------------------------------------------------------
inline NiPoint3* NiGeometry::GetVertices() const
{
    return m_spModelData->GetVertices();
}
//---------------------------------------------------------------------------
inline void NiGeometry::CreateNormals(bool bInitialize)
{
    m_spModelData->CreateNormals(bInitialize);
}
//---------------------------------------------------------------------------
inline NiPoint3* NiGeometry::GetNormals() const
{
    return m_spModelData->GetNormals();
}
//---------------------------------------------------------------------------
inline NiGeometryData::DataFlags NiGeometry::GetNormalBinormalTangentMethod()
    const
{
    return m_spModelData->GetNormalBinormalTangentMethod();
}
//---------------------------------------------------------------------------
inline void NiGeometry::StoreNormalBinormalTangent(
    NiGeometryData::DataFlags eNBTMethod)
{
    m_spModelData->StoreNormalBinormalTangent(eNBTMethod);
}
//---------------------------------------------------------------------------
inline void NiGeometry::SetModelBound(const NiBound& kBound)
{
    m_spModelData->SetBound(kBound);
}
//---------------------------------------------------------------------------
inline NiBound& NiGeometry::GetModelBound() const
{
    return m_spModelData->GetBound();
}
//---------------------------------------------------------------------------
inline void NiGeometry::CreateColors(bool bInitialize)
{
    m_spModelData->CreateColors(bInitialize);
}
//---------------------------------------------------------------------------
inline NiColorA* NiGeometry::GetColors() const
{
    return m_spModelData->GetColors();
}
//---------------------------------------------------------------------------
inline void NiGeometry::CreateTextures(bool bInitialize,
    unsigned short usSets)
{
    m_spModelData->CreateTextures(bInitialize,usSets);
}
//---------------------------------------------------------------------------
inline unsigned short NiGeometry::GetTextureSets() const
{
    return m_spModelData->GetTextureSets();
}
//---------------------------------------------------------------------------
inline NiPoint2* NiGeometry::GetTextures() const
{
    return m_spModelData->GetTextures();
}
//---------------------------------------------------------------------------
inline NiPoint2* NiGeometry::GetTextureSet(unsigned short usSet) const
{
    return m_spModelData->GetTextureSet(usSet);
}
//---------------------------------------------------------------------------
inline void NiGeometry::AppendTextureSet(NiPoint2* pkSet)
{
    m_spModelData->AppendTextureSet(pkSet);
}
//---------------------------------------------------------------------------
inline NiSkinInstance* NiGeometry::GetSkinInstance() const
{
    return m_spSkinInstance;
}
//---------------------------------------------------------------------------
inline void NiGeometry::SetSkinInstance(NiSkinInstance* pSkinInstance)
{
    m_spSkinInstance = pSkinInstance;
}

//---------------------------------------------------------------------------
#if defined(WIN32) || defined(_XENON) || defined(_XBOX)
//---------------------------------------------------------------------------
inline NiShader* NiGeometry::GetShader() const
{
    return m_spShader;
}
//---------------------------------------------------------------------------
inline void NiGeometry::SetShader(NiShader* pkShader)
{
    m_spShader = pkShader;
}
//---------------------------------------------------------------------------
#endif  //#if defined(WIN32) || defined(_XENON) || defined(_XBOX)
//---------------------------------------------------------------------------
inline void NiGeometry::SetActiveVertexCount(unsigned short usActive)
{
    m_spModelData->SetActiveVertexCount(usActive);
}
//---------------------------------------------------------------------------
inline unsigned short NiGeometry::GetActiveVertexCount() const
{
    return m_spModelData->GetActiveVertexCount();
}
//---------------------------------------------------------------------------
inline NiPropertyStatePtr NiGeometry::GetPropertyState() const
{
    return m_spPropertyState;
}
//---------------------------------------------------------------------------
inline NiDynamicEffectStatePtr NiGeometry::GetEffectState() const
{
    return m_spEffectState;
}
//---------------------------------------------------------------------------
inline void NiGeometry::SetPropertyState(NiPropertyState* pkState)
{
    m_spPropertyState = pkState;
}
//---------------------------------------------------------------------------
inline void NiGeometry::SetEffectState(NiDynamicEffectState* pkState)
{
    m_spEffectState = pkState;
}
//---------------------------------------------------------------------------
inline NiGeometryData::Consistency NiGeometry::GetConsistency() const
{
    return m_spModelData->GetConsistency();
}
//---------------------------------------------------------------------------
inline void NiGeometry::SetConsistency(
    NiGeometryData::Consistency eConsistency)
{
    m_spModelData->SetConsistency(eConsistency);
}
//---------------------------------------------------------------------------
