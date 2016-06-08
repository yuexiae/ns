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
//  NiBooleanExtraData inline functions

//---------------------------------------------------------------------------
inline NiBooleanExtraData::NiBooleanExtraData ()
{
    m_bValue = false;
}
//---------------------------------------------------------------------------
inline NiBooleanExtraData::NiBooleanExtraData (const bool bValue)
{
    m_bValue = bValue;
}
//---------------------------------------------------------------------------
inline NiBooleanExtraData::~NiBooleanExtraData ()
{
}
//---------------------------------------------------------------------------
inline bool NiBooleanExtraData::GetValue() const
{
    return m_bValue;
}
//---------------------------------------------------------------------------
inline void NiBooleanExtraData::SetValue(const bool bValue)
{
    m_bValue = bValue;
}
