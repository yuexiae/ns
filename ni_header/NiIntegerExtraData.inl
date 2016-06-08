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
//  NiIntegerExtraData inline functions

//---------------------------------------------------------------------------
inline NiIntegerExtraData::NiIntegerExtraData()
{
    m_iValue = 0;
}
//---------------------------------------------------------------------------
inline NiIntegerExtraData::NiIntegerExtraData (const int iValue)
{
    m_iValue = iValue;
}
//---------------------------------------------------------------------------
inline NiIntegerExtraData::~NiIntegerExtraData()
{
}
//---------------------------------------------------------------------------
inline int NiIntegerExtraData::GetValue() const
{
    return m_iValue;
}
//---------------------------------------------------------------------------
inline void NiIntegerExtraData::SetValue(const int iValue)
{
    m_iValue = iValue;
}
