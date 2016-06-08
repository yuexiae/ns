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
//  NiBound inline functions
#include "NiPlane.h"
//---------------------------------------------------------------------------
inline NiBound::NiBound()
{
}
//---------------------------------------------------------------------------
inline void NiBound::SetCenter(const NiPoint3& kCenter)
{
    m_kCenter = kCenter;
}
//---------------------------------------------------------------------------
inline void NiBound::SetCenter(float x, float y, float z)
{
    m_kCenter = NiPoint3(x, y, z);
}
//---------------------------------------------------------------------------
inline void NiBound::SetRadius(float fRadius)
{
    m_fRadius = fRadius;
}
//---------------------------------------------------------------------------
inline const NiPoint3& NiBound::GetCenter() const
{
    return m_kCenter;
}
//---------------------------------------------------------------------------
inline float NiBound::GetRadius() const
{
    return m_fRadius;
}
//---------------------------------------------------------------------------
inline void NiBound::SetCenterAndRadius(const NiPoint3& kCenter,
    float fRadius)
{
    m_kCenter = kCenter;
    m_fRadius = fRadius;
}
//---------------------------------------------------------------------------
inline bool NiBound::operator!=(const NiBound& kBound)
{
    return !(*this == kBound);
}
//---------------------------------------------------------------------------
inline int NiBound::WhichSide(const NiPlane& kPlane) const
{
    float fDistance = kPlane.Distance(m_kCenter);

    if (fDistance <= -m_fRadius)
        return NiPlane::NEGATIVE_SIDE;
    else if (fDistance >= m_fRadius)
        return NiPlane::POSITIVE_SIDE;
    else
        return NiPlane::NO_SIDE;
}
//---------------------------------------------------------------------------
