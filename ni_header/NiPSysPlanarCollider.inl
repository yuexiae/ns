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
inline NiAVObject* NiPSysPlanarCollider::GetColliderObj() const
{
    return m_pkColliderObj;
}
//---------------------------------------------------------------------------
inline void NiPSysPlanarCollider::SetColliderObj(NiAVObject* pkColliderObj)
{
    m_pkColliderObj = pkColliderObj;
}
//---------------------------------------------------------------------------
inline float NiPSysPlanarCollider::GetWidth() const
{
    return m_fWidth;
}
//---------------------------------------------------------------------------
inline void NiPSysPlanarCollider::SetWidth(float fWidth)
{
    m_fWidth = fWidth;
}
//---------------------------------------------------------------------------
inline float NiPSysPlanarCollider::GetHeight() const
{
    return m_fHeight;
}
//---------------------------------------------------------------------------
inline void NiPSysPlanarCollider::SetHeight(float fHeight)
{
    m_fHeight = fHeight;
}
//---------------------------------------------------------------------------
inline const NiPoint3& NiPSysPlanarCollider::GetXAxis() const
{
    return m_kXAxis;
}
//---------------------------------------------------------------------------
inline void NiPSysPlanarCollider::SetXAxis(const NiPoint3& kXAxis)
{
    m_kXAxis = kXAxis;
}
//---------------------------------------------------------------------------
inline const NiPoint3& NiPSysPlanarCollider::GetYAxis() const
{
    return m_kYAxis;
}
//---------------------------------------------------------------------------
inline void NiPSysPlanarCollider::SetYAxis(const NiPoint3& kYAxis)
{
    m_kYAxis = kYAxis;
}
//---------------------------------------------------------------------------
