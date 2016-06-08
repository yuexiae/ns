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
inline unsigned int NiTransformData::GetNumRotKeys () const
{
    return m_uiNumRotKeys;
}
//---------------------------------------------------------------------------
inline NiRotKey* NiTransformData::GetRotAnim (unsigned int& uiNumKeys,
    NiRotKey::KeyType& eType, unsigned char& ucSize) const
{
    uiNumKeys = m_uiNumRotKeys;
    eType = m_eRotType;
    ucSize = m_ucRotSize;
    return m_pkRotKeys;
}
//---------------------------------------------------------------------------
inline unsigned int NiTransformData::GetNumPosKeys () const
{
    return m_uiNumPosKeys;
}
//---------------------------------------------------------------------------
inline NiPosKey* NiTransformData::GetPosAnim (unsigned int& iNumKeys,
    NiPosKey::KeyType& eType, unsigned char& ucSize) const
{
    iNumKeys = m_uiNumPosKeys;
    eType = m_ePosType;
    ucSize = m_ucPosSize;
    return m_pkPosKeys;
}
//---------------------------------------------------------------------------
inline unsigned int NiTransformData::GetNumScaleKeys () const
{
    return m_uiNumScaleKeys;
}
//---------------------------------------------------------------------------
inline NiFloatKey* NiTransformData::GetScaleAnim (unsigned int& uiNumKeys,
    NiFloatKey::KeyType& eType, unsigned char& ucSize) const
{
    uiNumKeys = m_uiNumScaleKeys;
    eType = m_eScaleType;
    ucSize = m_ucScaleSize;
    return m_pkScaleKeys;
}
//---------------------------------------------------------------------------
