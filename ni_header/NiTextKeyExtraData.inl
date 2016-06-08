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
inline NiTextKeyExtraData::NiTextKeyExtraData ()
{
    m_uiNumKeys = 0;
    m_pKeys = 0;
}
//---------------------------------------------------------------------------
inline NiTextKeyExtraData::NiTextKeyExtraData (NiTextKey* pKeys,
    unsigned int uiNumKeys)
{
    m_uiNumKeys = uiNumKeys;
    m_pKeys = pKeys;
}
//---------------------------------------------------------------------------
inline NiTextKeyExtraData::~NiTextKeyExtraData ()
{
    delete[] m_pKeys;
}
//---------------------------------------------------------------------------
inline void NiTextKeyExtraData::SetKeys (NiTextKey* pKeys,
    unsigned int uiNumKeys)
{
    m_uiNumKeys = uiNumKeys;
    m_pKeys = pKeys;
}
//---------------------------------------------------------------------------
inline NiTextKey* NiTextKeyExtraData::GetKeys (unsigned int& uiNumKeys) const
{
    uiNumKeys = m_uiNumKeys;
    return m_pKeys;
}
//---------------------------------------------------------------------------
