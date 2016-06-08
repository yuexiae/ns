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
inline const NiPoint3& NiPSysGravityFieldModifier::GetDirection() const
{
    return m_kDirection;
}
//---------------------------------------------------------------------------
inline void NiPSysGravityFieldModifier::SetDirection(const NiPoint3& kDirection)
{
    m_kDirection = kDirection;

    // Build the Unitized Direction
    m_kUnitDirection = kDirection;
    m_kUnitDirection.Unitize();

    // Check for Near Zero
    assert(m_kUnitDirection != NiPoint3::ZERO);
    if (m_kUnitDirection == NiPoint3::ZERO)
        m_kUnitDirection == -NiPoint3::UNIT_Y;
}
//---------------------------------------------------------------------------
