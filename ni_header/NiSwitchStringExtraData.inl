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
//  NiSwitchStringExtraData inline functions

//---------------------------------------------------------------------------
inline NiSwitchStringExtraData::NiSwitchStringExtraData()
{
    m_ppcValue = NULL;
    m_uiSize = 0;
    m_iIndex = -1;
}
//---------------------------------------------------------------------------
inline NiSwitchStringExtraData::~NiSwitchStringExtraData()
{
    for (unsigned int i=0; i < m_uiSize; i++)
    {
        delete[] m_ppcValue[i];
    }
    delete[] m_ppcValue;
    m_ppcValue = NULL;
}
//---------------------------------------------------------------------------
inline void NiSwitchStringExtraData::GetValue(unsigned int &uiSize,
                                              char** &ppcValue,
                                              int &iIndex) const
{
    uiSize = m_uiSize;
    ppcValue = m_ppcValue;
    iIndex = m_iIndex;
}
//---------------------------------------------------------------------------
inline void NiSwitchStringExtraData::SetActiveIndex(const int iIndex)
{
    m_iIndex = iIndex;
}
//---------------------------------------------------------------------------
inline const int NiSwitchStringExtraData::GetActiveIndex() const
{
    return m_iIndex;
}
//---------------------------------------------------------------------------
