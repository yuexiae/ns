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
//  NiFloatsExtraData inline functions

//---------------------------------------------------------------------------
inline NiFloatsExtraData::NiFloatsExtraData()
{
    m_pfValue = NULL;
    m_uiSize = 0;
}
//---------------------------------------------------------------------------
inline NiFloatsExtraData::~NiFloatsExtraData()
{
    delete[] m_pfValue;
    m_pfValue = NULL;
}
//---------------------------------------------------------------------------
inline void NiFloatsExtraData::GetArray(unsigned int &uiSize,
                                        float* &pfValue) const
{
    uiSize = m_uiSize;
    pfValue = m_pfValue;
}
//---------------------------------------------------------------------------
