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
inline void NiPlanarCollider::SetHeight(float fHeight)
{
    m_fHeight = fHeight;
}
//---------------------------------------------------------------------------
inline float NiPlanarCollider::GetHeight() const
{
    return m_fHeight;
}
//---------------------------------------------------------------------------
inline void NiPlanarCollider::SetWidth(float fWidth)
{
    m_fWidth = fWidth;
}
//---------------------------------------------------------------------------
inline float NiPlanarCollider::GetWidth() const
{
    return m_fWidth;
}
//---------------------------------------------------------------------------
inline void NiPlanarCollider::SetPos(const NiPoint3& kPos)
{
    m_kPosition = kPos;
}
//---------------------------------------------------------------------------
inline const NiPoint3& NiPlanarCollider::GetPos() const
{
    return m_kPosition;
}
//---------------------------------------------------------------------------
inline void NiPlanarCollider::SetPlane(const NiPoint3 &kNorm, float fD)
{
    m_kPlane.SetConstant(fD);
    m_kPlane.SetNormal(kNorm);
}
//---------------------------------------------------------------------------
inline void NiPlanarCollider::SetXVec(const NiPoint3& kXVec)
{
    m_kXAxis = kXVec; 
}
//---------------------------------------------------------------------------
inline void NiPlanarCollider::SetYVec(const NiPoint3& kYVec)
{
    m_kYAxis = kYVec;
}
//---------------------------------------------------------------------------
inline const NiPoint3& NiPlanarCollider::GetXVec() const
{
    return m_kXAxis;
}
//---------------------------------------------------------------------------
inline const NiPoint3& NiPlanarCollider::GetYVec() const
{
    return m_kYAxis;
}
//---------------------------------------------------------------------------
inline float NiPlanarCollider::GetD() const
{
    return m_kPlane.GetConstant();
}
//---------------------------------------------------------------------------
inline const NiPoint3& NiPlanarCollider::GetNorm() const
{
    return m_kPlane.GetNormal();
}
//---------------------------------------------------------------------------
