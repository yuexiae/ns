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
inline const bool NiPSysDragFieldModifier::GetUseDirection() const
{
    return m_bUseDirection;
}
//---------------------------------------------------------------------------
inline void NiPSysDragFieldModifier::SetUseDirection(bool bUseDirection)
{
    m_bUseDirection = bUseDirection;
}
//---------------------------------------------------------------------------
inline const NiPoint3& NiPSysDragFieldModifier::GetDirection() const
{
    return m_kDirection;
}
//---------------------------------------------------------------------------
inline void NiPSysDragFieldModifier::SetDirection(const NiPoint3& kDirection)
{
    m_kDirection = kDirection;
}
//---------------------------------------------------------------------------
