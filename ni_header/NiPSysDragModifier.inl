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
inline NiAVObject* NiPSysDragModifier::GetDragObj() const
{
    return m_pkDragObj;
}
//---------------------------------------------------------------------------
inline void NiPSysDragModifier::SetDragObj(NiAVObject* pkDragObj)
{
    m_pkDragObj = pkDragObj;
}
//---------------------------------------------------------------------------
inline const NiPoint3& NiPSysDragModifier::GetDragAxis() const
{
    return m_kDragAxis;
}
//---------------------------------------------------------------------------
inline void NiPSysDragModifier::SetDragAxis(const NiPoint3& kDragAxis)
{
    m_kDragAxis = kDragAxis;
}
//---------------------------------------------------------------------------
inline float NiPSysDragModifier::GetPercentage() const
{
    return m_fPercentage;
}
//---------------------------------------------------------------------------
inline void NiPSysDragModifier::SetPercentage(float fPercentage)
{
    m_fPercentage = fPercentage;
}
//---------------------------------------------------------------------------
inline float NiPSysDragModifier::GetRange() const
{
    return m_fRange;
}
//---------------------------------------------------------------------------
inline void NiPSysDragModifier::SetRange(float fRange)
{
    m_fRange = fRange;
}
//---------------------------------------------------------------------------
inline float NiPSysDragModifier::GetRangeFalloff() const
{
    return m_fFalloff;
}
//---------------------------------------------------------------------------
inline void NiPSysDragModifier::SetRangeFalloff(float fFalloff)
{
    m_fFalloff = fFalloff;
}
//---------------------------------------------------------------------------
