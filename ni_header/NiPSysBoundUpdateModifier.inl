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
inline short NiPSysBoundUpdateModifier::GetUpdateSkip() const
{
    return m_sUpdateSkip;
}
//---------------------------------------------------------------------------
inline void NiPSysBoundUpdateModifier::SetUpdateSkip(short sUpdateSkip)
{
    m_sUpdateSkip = sUpdateSkip;

    delete[] m_pkSkipBounds;

    // Always have at least 1
    sUpdateSkip = NiMax(sUpdateSkip, 1);

    m_pkSkipBounds = new NiBound[sUpdateSkip];

    // Initialize the bounds
    for(int iLoop = 0; iLoop < sUpdateSkip; iLoop++)
    {
        m_pkSkipBounds[iLoop].SetCenterAndRadius(NiPoint3::ZERO, 0.0f);
    }
}
//---------------------------------------------------------------------------
inline void NiPSysBoundUpdateModifier::ResetUpdateSkipBounds()
{
    short sUpdateSkip = NiMax(m_sUpdateSkip, 1);

    // Initialize the bounds
    for(int iLoop = 0; iLoop < sUpdateSkip; iLoop++)
    {
        m_pkSkipBounds[iLoop].SetCenterAndRadius(NiPoint3::ZERO, 0.0f);
    }
}
//---------------------------------------------------------------------------
