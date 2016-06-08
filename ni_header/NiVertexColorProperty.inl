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
//  NiVertexColorProperty inline functions

//---------------------------------------------------------------------------
inline NiVertexColorProperty::NiVertexColorProperty ()
{
    m_uFlags = 0;
    m_eSource = SOURCE_IGNORE;
    m_eLighting = LIGHTING_E_A_D;
}
//---------------------------------------------------------------------------
inline void NiVertexColorProperty::SetSourceMode (SourceVertexMode eSource)
{
    m_eSource = eSource;
}
//---------------------------------------------------------------------------
inline NiVertexColorProperty::SourceVertexMode 
    NiVertexColorProperty::GetSourceMode () const
{
    return m_eSource;
}
//---------------------------------------------------------------------------
inline void NiVertexColorProperty::SetLightingMode (LightingMode eLighting)
{
    m_eLighting = eLighting;
}
//---------------------------------------------------------------------------
inline NiVertexColorProperty::LightingMode 
    NiVertexColorProperty::GetLightingMode () const
{
    return m_eLighting;
}
//---------------------------------------------------------------------------
inline bool NiVertexColorProperty::IsEqualFast (
    const NiVertexColorProperty& prop) const
{
    return (m_eSource == prop.m_eSource && m_eLighting == prop.m_eLighting);
}
//---------------------------------------------------------------------------
inline int NiVertexColorProperty::Type () const
{
    return NiProperty::VERTEX_COLOR;
}
//---------------------------------------------------------------------------
inline int NiVertexColorProperty::GetType ()
{
    return NiProperty::VERTEX_COLOR;
}
//---------------------------------------------------------------------------
inline NiVertexColorProperty *NiVertexColorProperty::GetDefault ()
{
    return ms_spDefault;
}
//---------------------------------------------------------------------------
