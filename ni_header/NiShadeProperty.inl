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
//  NiShadeProperty inline functions

//---------------------------------------------------------------------------
inline NiShadeProperty::NiShadeProperty()
{
    m_uFlags = 0;
    SetSmooth(true);
}
//---------------------------------------------------------------------------
inline void NiShadeProperty::SetSmooth(bool bSmooth)
{
    SetBit(bSmooth, SMOOTH_MASK);
}
//---------------------------------------------------------------------------
inline bool NiShadeProperty::GetSmooth() const
{
    return GetBit(SMOOTH_MASK);
}
//---------------------------------------------------------------------------
inline bool NiShadeProperty::IsEqualFast(const NiShadeProperty& kProp) const
{
    return m_uFlags == kProp.m_uFlags;
}
//---------------------------------------------------------------------------
inline int NiShadeProperty::Type() const
{
    return NiProperty::SHADE;
}
//---------------------------------------------------------------------------
inline int NiShadeProperty::GetType()
{
    return NiProperty::SHADE;
}
//---------------------------------------------------------------------------
inline NiShadeProperty* NiShadeProperty::GetDefault()
{
    return ms_spDefault;
}
//---------------------------------------------------------------------------
