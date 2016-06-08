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
//  NiDitherProperty inline functions

//---------------------------------------------------------------------------
inline NiDitherProperty::NiDitherProperty()
{
    m_uFlags = 0;
    SetDithering(false);
}
//---------------------------------------------------------------------------
inline void NiDitherProperty::SetDithering(bool bDither)
{
    SetBit(bDither, DITHER_MASK);
}
//---------------------------------------------------------------------------
inline bool NiDitherProperty::GetDithering() const
{
    return GetBit(DITHER_MASK);
}
//---------------------------------------------------------------------------
inline bool NiDitherProperty::IsEqualFast(const NiDitherProperty& kProp) const
{
    return m_uFlags == kProp.m_uFlags;
}
//---------------------------------------------------------------------------
inline int NiDitherProperty::Type() const
{
    return NiProperty::DITHER;
}
//---------------------------------------------------------------------------
inline int NiDitherProperty::GetType()
{
    return NiProperty::DITHER;
}
//---------------------------------------------------------------------------
inline NiDitherProperty* NiDitherProperty::GetDefault()
{
    return ms_spDefault;
}
//---------------------------------------------------------------------------
