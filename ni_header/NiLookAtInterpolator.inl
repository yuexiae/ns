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
inline NiAVObject* NiLookAtInterpolator::GetLookAt() const
{
    return m_pkLookAt;
}
//---------------------------------------------------------------------------
inline void NiLookAtInterpolator::SetLookAt(NiAVObject* pkLookAt)
{
    m_pkLookAt = pkLookAt;
    SetLookAtName(NULL);
}
//---------------------------------------------------------------------------
inline bool NiLookAtInterpolator::GetFlip() const
{
    return GetBit(FLIP_MASK);
}
//---------------------------------------------------------------------------
inline void NiLookAtInterpolator::SetFlip(bool bFlip)
{
    SetBit(bFlip,FLIP_MASK);
}
//---------------------------------------------------------------------------
inline NiLookAtInterpolator::Axis NiLookAtInterpolator::GetAxis() const
{
    return (Axis)GetField(AXIS_MASK, AXIS_POS);
}
//---------------------------------------------------------------------------
inline void NiLookAtInterpolator::SetAxis(Axis eAxis)
{
    SetField(eAxis, AXIS_MASK, AXIS_POS);
}
//---------------------------------------------------------------------------
inline void NiLookAtInterpolator::SetTranslateInterpolator(
    NiInterpolator* pkInterp)
{
    if (pkInterp)
    {
        assert(pkInterp->IsPoint3ValueSupported());
        m_aspInterpolators[0] = pkInterp;
    }
    else
    {
        m_aspInterpolators[0] = NULL;
    }
}
//---------------------------------------------------------------------------
inline void NiLookAtInterpolator::SetRollInterpolator(
    NiInterpolator* pkInterp)
{
    if (pkInterp)
    {
        assert(pkInterp->IsFloatValueSupported());
        m_aspInterpolators[1] = pkInterp;
    }
    else
    {
        m_aspInterpolators[1] = NULL;
    }
}
//---------------------------------------------------------------------------
inline void NiLookAtInterpolator::SetScaleInterpolator(
    NiInterpolator* pkInterp)
{
    if (pkInterp)
    {
        assert(pkInterp->IsFloatValueSupported());
        m_aspInterpolators[2] = pkInterp;
    }
    else
    {
        m_aspInterpolators[2] = NULL;
    }
}
//---------------------------------------------------------------------------
inline NiInterpolator* 
NiLookAtInterpolator::GetTranslateInterpolator()
{
    return m_aspInterpolators[0];
}
//---------------------------------------------------------------------------
inline NiInterpolator* 
NiLookAtInterpolator::GetRollInterpolator()
{
    return m_aspInterpolators[1];
}
//---------------------------------------------------------------------------
inline NiInterpolator* 
NiLookAtInterpolator::GetScaleInterpolator()
{
    return m_aspInterpolators[2];
}
//---------------------------------------------------------------------------