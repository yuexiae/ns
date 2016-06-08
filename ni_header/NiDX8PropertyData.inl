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
//  NiDX8PropertyData Inline Functions
//---------------------------------------------------------------------------
inline NiDX8PropertyData::NiDX8PropertyData()
{ /* */}
//---------------------------------------------------------------------------
inline NiDX8PropertyData::~NiDX8PropertyData()
{ /* */ }
//---------------------------------------------------------------------------
inline unsigned int NiDX8PropertyData::GetRendererTypeID() const
{
    return NI_DX8_RENDER_ID;
}
//---------------------------------------------------------------------------
inline NiRendererExtraData* NiDX8PropertyData::GetExtraData() const
{
    return m_spExtraData;
}
//---------------------------------------------------------------------------
inline void NiDX8PropertyData::SetExtraData(
    NiRendererExtraData* pExtraData)
{
    if (m_spExtraData != pExtraData)
        m_spExtraData = pExtraData;
}
//---------------------------------------------------------------------------
inline NiRendererSpecificProperty::RendererData* 
    NiDX8PropertyData::CreateClone(
        NiCloningProcess& kCloning) const
{
    NiDX8PropertyData* pkDest = new NiDX8PropertyData;
    CopyMembers(pkDest, kCloning);
    return pkDest;
}
//---------------------------------------------------------------------------
inline void NiDX8PropertyData::CopyMembers(NiDX8PropertyData* pkDest,
    NiCloningProcess& kCloning) const
{
    pkDest->m_spExtraData = m_spExtraData;
}
//---------------------------------------------------------------------------
