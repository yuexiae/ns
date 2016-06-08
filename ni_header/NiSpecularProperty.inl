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
//  NiSpecularProperty inline functions

//---------------------------------------------------------------------------
inline NiSpecularProperty::NiSpecularProperty()
{
    m_uFlags = 0;
    SetSpecular(false);
}
//---------------------------------------------------------------------------
inline void NiSpecularProperty::SetSpecular(bool bSpec)
{
    SetBit(bSpec, SPEC_MASK);
}
//---------------------------------------------------------------------------
inline bool NiSpecularProperty::GetSpecular() const
{
    return GetBit(SPEC_MASK);
}
//---------------------------------------------------------------------------
inline bool NiSpecularProperty::IsEqualFast(const NiSpecularProperty& kProp)
    const
{
    return m_uFlags == kProp.m_uFlags;
}
//---------------------------------------------------------------------------
inline int NiSpecularProperty::Type() const
{
    return NiProperty::SPECULAR;
}
//---------------------------------------------------------------------------
inline int NiSpecularProperty::GetType()
{
    return NiProperty::SPECULAR;
}
//---------------------------------------------------------------------------
inline NiSpecularProperty* NiSpecularProperty::GetDefault()
{
    return ms_spDefault;
}
//---------------------------------------------------------------------------
