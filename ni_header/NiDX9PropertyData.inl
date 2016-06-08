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
//  NiDX9PropertyData Inline Functions
//---------------------------------------------------------------------------
inline NiDX9PropertyData::NiDX9PropertyData()
{ /* */ }
//---------------------------------------------------------------------------
inline NiDX9PropertyData::~NiDX9PropertyData()
{ /* */ }
//---------------------------------------------------------------------------
inline unsigned int NiDX9PropertyData::GetRendererTypeID() const
{
    return NI_DX9_RENDER_ID;
}
//---------------------------------------------------------------------------
inline NiRendererExtraData* NiDX9PropertyData::GetExtraData() const
{
    return m_spExtraData;
}
//---------------------------------------------------------------------------
inline void NiDX9PropertyData::SetExtraData(
    NiRendererExtraData* pExtraData)
{
    if (m_spExtraData != pExtraData)
        m_spExtraData = pExtraData;
}
//---------------------------------------------------------------------------
inline NiRendererSpecificProperty::RendererData* 
    NiDX9PropertyData::CreateClone(
        NiCloningProcess& kCloning) const
{
    NiDX9PropertyData* pkDest = new NiDX9PropertyData;
    CopyMembers(pkDest, kCloning);
    return pkDest;
}
//---------------------------------------------------------------------------
inline void NiDX9PropertyData::CopyMembers(NiDX9PropertyData* pkDest,
    NiCloningProcess& kCloning) const
{
    pkDest->m_spExtraData = m_spExtraData;
}
//---------------------------------------------------------------------------
