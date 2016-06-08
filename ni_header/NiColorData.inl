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
inline NiColorData::NiColorData ()
{
    m_uiNumKeys = 0;
    m_pkKeys = 0;
    m_eType = NiAnimationKey::NOINTERP;
}
//---------------------------------------------------------------------------
inline unsigned int NiColorData::GetNumKeys () const
{
    return m_uiNumKeys;
}
//---------------------------------------------------------------------------
inline NiColorKey* NiColorData::GetAnim (unsigned int& uiNumKeys,
    NiColorKey::KeyType& eType, unsigned char& ucSize) const
{
    uiNumKeys = m_uiNumKeys;
    eType = m_eType;
    ucSize = m_ucKeySize;
    return m_pkKeys;
}
//---------------------------------------------------------------------------
