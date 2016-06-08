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
//  NiQuaternion inline functions

//---------------------------------------------------------------------------
inline void NiQuaternion::SetW (float w)
{
    m_fW = w;
}
//---------------------------------------------------------------------------
inline void NiQuaternion::SetX (float x)
{
    m_fX = x;
}
//---------------------------------------------------------------------------
inline void NiQuaternion::SetY (float y)
{
    m_fY = y;
}
//---------------------------------------------------------------------------
inline void NiQuaternion::SetZ (float z)
{
    m_fZ = z;
}
//---------------------------------------------------------------------------
inline float NiQuaternion::GetW () const
{
    return m_fW;
}
//---------------------------------------------------------------------------
inline float NiQuaternion::GetX () const
{
    return m_fX;
}
//---------------------------------------------------------------------------
inline float NiQuaternion::GetY () const
{
    return m_fY;
}
//---------------------------------------------------------------------------
inline float NiQuaternion::GetZ () const
{
    return m_fZ;
}
//---------------------------------------------------------------------------
inline void NiQuaternion::SetValues(float w, float x, float y, float z)
{
    m_fW = w;
    m_fX = x;
    m_fY = y;
    m_fZ = z;
}
//---------------------------------------------------------------------------
inline void NiQuaternion::GetValues(float& w, float& x, float& y, float& z)
    const
{
    w = m_fW;
    x = m_fX;
    y = m_fY;
    z = m_fZ;
}
//---------------------------------------------------------------------------
inline bool NiQuaternion::operator== (const NiQuaternion& q) const
{
    return
    m_fW == q.m_fW && m_fX == q.m_fX && m_fY == q.m_fY && m_fZ == q.m_fZ;
}
//---------------------------------------------------------------------------
inline bool NiQuaternion::operator!= (const NiQuaternion& q) const
{
    return
    m_fW != q.m_fW || m_fX != q.m_fX || m_fY != q.m_fY || m_fZ != q.m_fZ;
}
//---------------------------------------------------------------------------
inline void NiQuaternion::ToRotation (NiMatrix3& rot) const
{
    // operations (*,+,-) = 24

    float tx  = 2.0f*m_fX;
    float ty  = 2.0f*m_fY;
    float tz  = 2.0f*m_fZ;
    float twx = tx*m_fW;
    float twy = ty*m_fW;
    float twz = tz*m_fW;
    float txx = tx*m_fX;
    float txy = ty*m_fX;
    float txz = tz*m_fX;
    float tyy = ty*m_fY;
    float tyz = tz*m_fY;
    float tzz = tz*m_fZ;

    rot.SetCol(0, 1.0f-(tyy+tzz), txy+twz, txz-twy);
    rot.SetCol(1, txy-twz, 1.0f-(txx+tzz), tyz+twx);
    rot.SetCol(2, txz+twy, tyz-twx, 1.0f-(txx+tyy));
}
//---------------------------------------------------------------------------
#ifndef PS2
inline float NiQuaternion::Dot (const NiQuaternion& p, const NiQuaternion& q)
{
    return p.m_fW * q.m_fW + p.m_fX * q.m_fX + 
           p.m_fY * q.m_fY + p.m_fZ * q.m_fZ;
}
#endif
//---------------------------------------------------------------------------
inline void NiQuaternion::FromAngleAxisX(float fAngle)
{
    NiSinCos(fAngle * 0.5f, m_fX, m_fW);
    m_fY = m_fZ = 0.0f;
}
//---------------------------------------------------------------------------
inline void NiQuaternion::FromAngleAxisY(float fAngle)
{
    NiSinCos(fAngle * 0.5f, m_fY, m_fW);
    m_fX = m_fZ = 0.0f;
}
//---------------------------------------------------------------------------
inline void NiQuaternion::FromAngleAxisZ(float fAngle)
{
    NiSinCos(fAngle * 0.5f, m_fZ, m_fW);
    m_fX = m_fY = 0.0f;
}
//---------------------------------------------------------------------------
