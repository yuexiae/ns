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
inline const float NiPSysTurbulenceFieldModifier::GetFrequency() const
{
    return m_fFrequency;
}
//---------------------------------------------------------------------------
inline void NiPSysTurbulenceFieldModifier::SetFrequency(float fFrequency)
{
    m_fFrequency = fFrequency;

    // Check for near zero frequency
    if (m_fFrequency < 0.0001f)
    {
        m_fFrequencyUpdateTime = 1.0f / 0.0001f;
    }
    else
    {
        m_fFrequencyUpdateTime = 1.0f / m_fFrequency;
    }
}
//---------------------------------------------------------------------------
