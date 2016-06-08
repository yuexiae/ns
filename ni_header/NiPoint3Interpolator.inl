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
inline NiPosData* NiPoint3Interpolator::GetPoint3Data() const
{
    return m_spPoint3Data;
}
//---------------------------------------------------------------------------
inline void NiPoint3Interpolator::SetPoint3Data(NiPosData* pkPoint3Data)
{
    m_spPoint3Data = pkPoint3Data;
}
//---------------------------------------------------------------------------
inline NiPosKey* NiPoint3Interpolator::GetKeys(unsigned int& uiNumKeys,
    NiPosKey::KeyType& eType, unsigned char& ucSize) const
{
    if (m_spPoint3Data)
    {
        return m_spPoint3Data->GetAnim(uiNumKeys, eType, ucSize);
    }

    uiNumKeys = 0;
    eType = NiPosKey::NOINTERP;
    ucSize = 0;
    return NULL;
}
//---------------------------------------------------------------------------
inline void NiPoint3Interpolator::ReplaceKeys(NiPosKey* pkKeys,
    unsigned int uiNumKeys, NiPosKey::KeyType eType)
{
    if (uiNumKeys > 0)
    {
        if (!m_spPoint3Data)
        {
            m_spPoint3Data = new NiPosData;
        }

        m_spPoint3Data->ReplaceAnim(pkKeys, uiNumKeys, eType);
        m_uiLastIdx = 0;
    }
    else if (m_spPoint3Data)
    {
        m_spPoint3Data->ReplaceAnim(NULL, 0, NiAnimationKey::NOINTERP);
    }
}
//---------------------------------------------------------------------------
inline void NiPoint3Interpolator::SetKeys(NiPosKey* pkKeys,
    unsigned int uiNumKeys, NiPosKey::KeyType eType)
{
    if (uiNumKeys > 0)
    {
        if (!m_spPoint3Data)
        {
            m_spPoint3Data = new NiPosData;
        }

        m_spPoint3Data->SetAnim(pkKeys, uiNumKeys, eType);
        m_uiLastIdx = 0;
    }
    else if (m_spPoint3Data)
    {
        m_spPoint3Data->SetAnim(NULL, 0, NiAnimationKey::NOINTERP);
    }
}
//---------------------------------------------------------------------------
