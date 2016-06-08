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
//  NiStringsExtraData inline functions

//---------------------------------------------------------------------------
inline NiStringsExtraData::NiStringsExtraData()
{
    m_ppcValue = NULL;
    m_uiSize = 0;
}
//---------------------------------------------------------------------------
inline NiStringsExtraData::~NiStringsExtraData()
{
    for (unsigned int i=0; i < m_uiSize; i++)
    {
        delete[] m_ppcValue[i];
    }
    delete[] m_ppcValue;
    m_ppcValue = NULL;
}
//---------------------------------------------------------------------------
inline void NiStringsExtraData::GetArray(unsigned int &uiSize,
                                               char** &ppcValue) const
{
    uiSize = m_uiSize;
    ppcValue = m_ppcValue;
}
//---------------------------------------------------------------------------
