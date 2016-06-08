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
inline NiFloatData* NiFloatInterpolator::GetFloatData() const
{
    return m_spFloatData;
}
//---------------------------------------------------------------------------
inline void NiFloatInterpolator::SetFloatData(NiFloatData* pkFloatData)
{
    m_spFloatData = pkFloatData;
}
//---------------------------------------------------------------------------
inline NiFloatKey* NiFloatInterpolator::GetKeys(unsigned int& uiNumKeys,
    NiFloatKey::KeyType& eType, unsigned char& ucSize) const
{
    if (m_spFloatData)
    {
        return m_spFloatData->GetAnim(uiNumKeys, eType, ucSize);
    }

    uiNumKeys = 0;
    eType = NiFloatKey::NOINTERP;
    ucSize = 0;
    return NULL;
}
//---------------------------------------------------------------------------
inline void NiFloatInterpolator::ReplaceKeys(NiFloatKey* pkKeys,
    unsigned int uiNumKeys, NiFloatKey::KeyType eType)
{
    if (uiNumKeys > 0)
    {
        if (!m_spFloatData)
        {
            m_spFloatData = new NiFloatData;
        }

        m_spFloatData->ReplaceAnim(pkKeys, uiNumKeys, eType);
        m_uiLastIdx = 0;
    }
    else if (m_spFloatData)
    {
        m_spFloatData->ReplaceAnim(NULL, 0, NiAnimationKey::NOINTERP);
    }
}
//---------------------------------------------------------------------------
inline void NiFloatInterpolator::SetKeys(NiFloatKey* pkKeys,
    unsigned int uiNumKeys, NiFloatKey::KeyType eType)
{
    if (uiNumKeys > 0)
    {
        if (!m_spFloatData)
        {
            m_spFloatData = new NiFloatData;
        }

        m_spFloatData->SetAnim(pkKeys, uiNumKeys, eType);
        m_uiLastIdx = 0;
    }
    else if (m_spFloatData)
    {
        m_spFloatData->SetAnim(NULL, 0, NiAnimationKey::NOINTERP);
    }
}
//---------------------------------------------------------------------------
