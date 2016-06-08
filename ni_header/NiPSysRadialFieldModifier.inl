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
inline float NiPSysRadialFieldModifier::GetRadialType() const
{
    return m_fRadialType;
}
//---------------------------------------------------------------------------
inline void NiPSysRadialFieldModifier::SetRadialType(const float fRadialType)
{
    m_fRadialType = fRadialType;

    // insure the range
    assert((m_fRadialType >= 0.0f) && (m_fRadialType <= 1.0f));

    m_fRadialType = NiMax(0.0f, m_fRadialType);
    m_fRadialType = NiMin(1.0f, m_fRadialType);
}
//---------------------------------------------------------------------------
