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
inline NiLookAtController::NiLookAtController()
{
    m_uFlags = 0;
    m_pkLookAt = 0; 
    SetFlip(false);
    SetAxis(X);
    m_bComputeScaledTime = false;
}
//---------------------------------------------------------------------------
inline void NiLookAtController::SetLookAt(NiAVObject* pkLookAt)
{
    m_pkLookAt = pkLookAt;
}
//---------------------------------------------------------------------------
inline NiAVObject* NiLookAtController::GetLookAt() const
{
    return m_pkLookAt;
}
//---------------------------------------------------------------------------
inline void NiLookAtController::SetAxis(Axis eAxis)
{
    SetField(eAxis, AXIS_MASK, AXIS_POS);
}
//---------------------------------------------------------------------------
inline NiLookAtController::Axis NiLookAtController::GetAxis() const
{
    return (Axis)GetField(AXIS_MASK, AXIS_POS);
}
//---------------------------------------------------------------------------
inline void NiLookAtController::SetFlip(bool bFlip)
{
    SetBit(bFlip,FLIP_MASK);
}
//---------------------------------------------------------------------------
inline bool NiLookAtController::GetFlip() const
{
    return GetBit(FLIP_MASK);
}
//---------------------------------------------------------------------------
inline bool NiLookAtController::TargetIsRequiredType() const
{
    return NiIsKindOf(NiAVObject, m_pTarget);
}
//---------------------------------------------------------------------------
inline bool NiLookAtController::IsTransformController() const
{
    return true;
}
//---------------------------------------------------------------------------
