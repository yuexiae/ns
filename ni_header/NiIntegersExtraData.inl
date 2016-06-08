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
//  NiIntegersExtraData inline functions

//---------------------------------------------------------------------------
inline NiIntegersExtraData::NiIntegersExtraData()
{
    m_piValue = NULL;
    m_uiSize = 0;
}
//---------------------------------------------------------------------------
inline NiIntegersExtraData::~NiIntegersExtraData()
{
    delete[] m_piValue;
    m_piValue = NULL;
}
//---------------------------------------------------------------------------
inline void NiIntegersExtraData::GetArray(unsigned int &uiSize,
                                                int* &piValue) const
{
    uiSize = m_uiSize;
    piValue = m_piValue;
}
//---------------------------------------------------------------------------
