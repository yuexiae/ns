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
inline unsigned int NiRotData::GetNumKeys() const
{
    return m_uiNumKeys;
}
//---------------------------------------------------------------------------
inline NiRotKey* NiRotData::GetAnim(unsigned int& iNumKeys,
    NiRotKey::KeyType& eType, unsigned char& ucSize) const
{
    iNumKeys = m_uiNumKeys;
    eType = m_eType;
    ucSize = m_ucKeySize;
    return m_pkKeys;
}
//---------------------------------------------------------------------------
