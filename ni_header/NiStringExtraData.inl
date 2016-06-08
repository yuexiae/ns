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
//  NiStringExtraData inline functions

//---------------------------------------------------------------------------
inline NiStringExtraData::NiStringExtraData()
{
    m_pString = NULL;
}
//---------------------------------------------------------------------------
inline NiStringExtraData::~NiStringExtraData()
{
    delete[] m_pString;
    m_pString = NULL;
}
//---------------------------------------------------------------------------
inline const char* NiStringExtraData::GetValue() const
{
    return m_pString;
}
//---------------------------------------------------------------------------
