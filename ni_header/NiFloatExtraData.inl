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
//  NiFloatExtraData inline functions

//---------------------------------------------------------------------------
inline NiFloatExtraData::NiFloatExtraData ()
{
    m_fValue = 0;
}
//---------------------------------------------------------------------------
inline NiFloatExtraData::NiFloatExtraData (const float fValue)
{
    m_fValue = fValue;
}
//---------------------------------------------------------------------------
inline NiFloatExtraData::~NiFloatExtraData ()
{
}
//---------------------------------------------------------------------------
inline float NiFloatExtraData::GetValue () const
{
    return m_fValue;
}
//---------------------------------------------------------------------------
inline void NiFloatExtraData::SetValue (const float fValue)
{
    m_fValue = fValue;
}
