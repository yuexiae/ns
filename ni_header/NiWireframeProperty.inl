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
//  NiWireframeProperty inline functions

//---------------------------------------------------------------------------
inline NiWireframeProperty::NiWireframeProperty()
{
    m_uFlags = 0;
    SetWireframe(false);
}
//---------------------------------------------------------------------------
inline void NiWireframeProperty::SetWireframe(bool bWireframe)
{
    SetBit(bWireframe, WIREFRAME_MASK);
}
//---------------------------------------------------------------------------
inline bool NiWireframeProperty::GetWireframe() const
{
    return GetBit(WIREFRAME_MASK);
}
//---------------------------------------------------------------------------
inline bool NiWireframeProperty::IsEqualFast(const NiWireframeProperty& kProp)
    const
{
    return m_uFlags == kProp.m_uFlags;
}
//---------------------------------------------------------------------------
inline int NiWireframeProperty::Type() const
{
    return NiProperty::WIREFRAME;
}
//---------------------------------------------------------------------------
inline int NiWireframeProperty::GetType()
{
    return NiProperty::WIREFRAME;
}
//---------------------------------------------------------------------------
inline NiWireframeProperty* NiWireframeProperty::GetDefault()
{
    return ms_spDefault;
}
//---------------------------------------------------------------------------
