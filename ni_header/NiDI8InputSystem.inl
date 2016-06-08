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
// NiDI8InputSystem inline functions
//---------------------------------------------------------------------------
// DI8CreateParams
//---------------------------------------------------------------------------
inline NiDI8InputSystem::DI8CreateParams::DI8CreateParams() :
    NiInputSystem::CreateParams(0, false, false, MAX_GAMEPADS),
    m_hOwnerInst(0), 
    m_hOwnerWnd(0) 
{
    //*** SAS START - 040216 - Adding to allow for additional axes
    for (unsigned int ui = 0; ui < DEFACTION_COUNT; ui++)
        m_apacMappingNames[ui] = 0;
    //*** SAS END - 040216
}
//---------------------------------------------------------------------------
inline NiDI8InputSystem::DI8CreateParams::DI8CreateParams(
    NiRenderer* pkRenderer, HINSTANCE hInst, HWND hWnd, 
    NiActionMap* pkActionMap, unsigned int uiKeyboard, unsigned int uiMouse, 
    unsigned int uiGamePads, int iAxisRangeLow, int iAxisRangeHigh) :
    NiInputSystem::CreateParams(pkRenderer, pkActionMap, uiKeyboard, 
        uiMouse, uiGamePads, iAxisRangeLow, iAxisRangeHigh),
    m_hOwnerInst(hInst), 
    m_hOwnerWnd(hWnd)
{
}
//---------------------------------------------------------------------------
inline const HINSTANCE NiDI8InputSystem::DI8CreateParams::GetOwnerInstance() 
    const
{
    return m_hOwnerInst;
}
//---------------------------------------------------------------------------
inline const HWND NiDI8InputSystem::DI8CreateParams::GetOwnerWindow() const
{
    return m_hOwnerWnd;
}
//---------------------------------------------------------------------------
inline const LPDIRECTINPUT8 NiDI8InputSystem::GetDirectInput8() const
{
    return m_pkDirectInput8;
}
//---------------------------------------------------------------------------
inline void NiDI8InputSystem::DI8CreateParams::SetOwnerInstance(
    HINSTANCE hInst)
{
    m_hOwnerInst = hInst;
}
//---------------------------------------------------------------------------
inline void NiDI8InputSystem::DI8CreateParams::SetOwnerWindow(HWND hWnd)
{
    m_hOwnerWnd = hWnd;
}
//---------------------------------------------------------------------------
// DI8Description
//---------------------------------------------------------------------------
inline NiDI8InputSystem::DI8Description::DI8Description() :
    NiInputDevice::Description()
{
    SetGUIDInstance(0);
}
//---------------------------------------------------------------------------
inline NiDI8InputSystem::DI8Description::DI8Description(
    NiInputDevice::Type eType, unsigned int uiPort, unsigned int uiSlot, 
    const char* pacName, const GUID* pkGUIDInstance) :
    NiInputDevice::Description(eType, uiPort, uiSlot, pacName)
{
    SetGUIDInstance(pkGUIDInstance);
}
//---------------------------------------------------------------------------
inline NiDI8InputSystem::DI8Description::~DI8Description()
{
}
//---------------------------------------------------------------------------
inline const GUID* NiDI8InputSystem::DI8Description::GetGUIDInstance() const
{
    return &m_kGUIDInstance;
}
//---------------------------------------------------------------------------
inline void NiDI8InputSystem::DI8Description::SetGUIDInstance(
    const GUID* pkGUID)
{
    if (pkGUID)
        memcpy((void*)&m_kGUIDInstance, (const void*)pkGUID, sizeof(GUID));
    else
        memset((void*)&m_kGUIDInstance, 0, sizeof(GUID));
}
//---------------------------------------------------------------------------
inline HINSTANCE NiDI8InputSystem::GetOwnerInstance()
{
    return ms_hOwnerInst;
}
//---------------------------------------------------------------------------
inline HWND NiDI8InputSystem::GetOwnerWindow()
{
    return ms_hOwnerWnd;
}
//---------------------------------------------------------------------------
inline HINSTANCE NiDI8InputSystem::GetLibraryInstance()
{
    return ms_hLibInst;
}
//---------------------------------------------------------------------------
inline void NiDI8InputSystem::SetOwnerInstance(HINSTANCE hInst)
{
    ms_hOwnerInst = hInst;
}
//---------------------------------------------------------------------------
inline void NiDI8InputSystem::SetOwnerWindow(HWND hWnd)
{
    ms_hOwnerWnd = hWnd;
}
//---------------------------------------------------------------------------
inline unsigned int NiDI8InputSystem::GetDefaultActionBufferSize()
{
    return ms_uiDefaultActionBufferSize;
}
//---------------------------------------------------------------------------
