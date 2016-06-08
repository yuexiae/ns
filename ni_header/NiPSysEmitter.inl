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
inline float NiPSysEmitter::GetSpeed() const
{
    return m_fSpeed;
}
//---------------------------------------------------------------------------
inline void NiPSysEmitter::SetSpeed(float fSpeed)
{
    m_fSpeed = fSpeed;
}
//---------------------------------------------------------------------------
inline float NiPSysEmitter::GetSpeedVar() const
{
    return m_fSpeedVar;
}
//---------------------------------------------------------------------------
inline void NiPSysEmitter::SetSpeedVar(float fSpeedVar)
{
    m_fSpeedVar = fSpeedVar;
}
//---------------------------------------------------------------------------
inline float NiPSysEmitter::GetDeclination() const
{
    return m_fDeclination;
}
//---------------------------------------------------------------------------
inline void NiPSysEmitter::SetDeclination(float fDeclination)
{
    m_fDeclination = fDeclination;
}
//---------------------------------------------------------------------------
inline float NiPSysEmitter::GetDeclinationVar() const
{
    return m_fDeclinationVar;
}
//---------------------------------------------------------------------------
inline void NiPSysEmitter::SetDeclinationVar(float fDeclinationVar)
{
    m_fDeclinationVar = fDeclinationVar;
}
//---------------------------------------------------------------------------
inline float NiPSysEmitter::GetPlanarAngle() const
{
    return m_fPlanarAngle;
}
//---------------------------------------------------------------------------
inline void NiPSysEmitter::SetPlanarAngle(float fPlanarAngle)
{
    m_fPlanarAngle = fPlanarAngle;
}
//---------------------------------------------------------------------------
inline float NiPSysEmitter::GetPlanarAngleVar() const
{
    return m_fPlanarAngleVar;
}
//---------------------------------------------------------------------------
inline void NiPSysEmitter::SetPlanarAngleVar(float fPlanarAngleVar)
{
    m_fPlanarAngleVar = fPlanarAngleVar;
}
//---------------------------------------------------------------------------
inline NiColorA NiPSysEmitter::GetInitialColor() const
{
    return m_kInitialColor;
}
//---------------------------------------------------------------------------
inline void NiPSysEmitter::SetInitialColor(
    const NiColorA& kInitialColor)
{
    m_kInitialColor = kInitialColor;
}
//---------------------------------------------------------------------------
inline float NiPSysEmitter::GetInitialRadius() const
{
    return m_fInitialRadius;
}
//---------------------------------------------------------------------------
inline void NiPSysEmitter::SetInitialRadius(float fInitialRadius)
{
    m_fInitialRadius = fInitialRadius;
}
//---------------------------------------------------------------------------
inline float NiPSysEmitter::GetLifeSpan() const
{
    return m_fLifeSpan;
}
//---------------------------------------------------------------------------
inline void NiPSysEmitter::SetLifeSpan(float fLifeSpan)
{
    m_fLifeSpan = fLifeSpan;
}
//---------------------------------------------------------------------------
inline float NiPSysEmitter::GetLifeSpanVar() const
{
    return m_fLifeSpanVar;
}
//---------------------------------------------------------------------------
inline void NiPSysEmitter::SetLifeSpanVar(float fLifeSpanVar)
{
    m_fLifeSpanVar = fLifeSpanVar;
}
//---------------------------------------------------------------------------
