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
inline int NiSphereBV::Type() const
{
    return SPHERE_BV;
}
//---------------------------------------------------------------------------
inline NiSphereBV::NiSphereBV(const NiSphereBV& kABV)
{
    SetSphere(kABV.GetSphere());
}
//---------------------------------------------------------------------------
inline NiBoundingVolume* NiSphereBV::Create() const 
{ 
    return new NiSphereBV; 
}
//---------------------------------------------------------------------------
inline void NiSphereBV::SetSphere(const NiSphere& kSphere)
{
    m_kSphere = kSphere;
}
//---------------------------------------------------------------------------
inline const NiSphere& NiSphereBV::GetSphere() const
{
    return m_kSphere;
}
//---------------------------------------------------------------------------
inline void NiSphereBV::SetCenter(const NiPoint3& kCenter)
{
    m_kSphere.m_kCenter = kCenter;
}
//---------------------------------------------------------------------------
inline const NiPoint3& NiSphereBV::GetCenter() const
{
    return m_kSphere.m_kCenter;
}
//---------------------------------------------------------------------------
inline void NiSphereBV::SetRadius(float fRadius)
{
    m_kSphere.m_fRadius = fRadius;
}
//---------------------------------------------------------------------------
inline float NiSphereBV::GetRadius() const
{
    return m_kSphere.m_fRadius;
}
//---------------------------------------------------------------------------
