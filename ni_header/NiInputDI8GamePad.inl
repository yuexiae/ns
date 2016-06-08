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
// NiInputDI8GamePad inline functions
//---------------------------------------------------------------------------
inline const LPDIRECTINPUTDEVICE8 NiInputDI8GamePad::GetDIDevice()
{
    return m_pkDIDevice;
}
//---------------------------------------------------------------------------
inline unsigned int NiInputDI8GamePad::GetMotorCount() const
{
    return 0;
}
//---------------------------------------------------------------------------
inline unsigned int NiInputDI8GamePad::GetRumbleRange(
    unsigned int uiMotor) const
{
    return 0;
}
//---------------------------------------------------------------------------
inline void NiInputDI8GamePad::SetRumbleValue(
    unsigned int uiMotor, unsigned int uiValue, bool bCommit)
{
    return;
}
//---------------------------------------------------------------------------
inline void NiInputDI8GamePad::GetRumbleValue(unsigned int uiMotor, 
    unsigned int& uiValue) const
{
    uiValue = 0;
    return;
}
//---------------------------------------------------------------------------
inline void NiInputDI8GamePad::StartRumble()
{
    return;
}
//---------------------------------------------------------------------------
inline void NiInputDI8GamePad::StopRumble(bool bQuickStop)
{
    return;
}
//---------------------------------------------------------------------------
