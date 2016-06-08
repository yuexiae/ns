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
inline NiCommand* NiApplication::GetCommand()
{
    return ms_pkCommand;
}
//---------------------------------------------------------------------------
inline void NiApplication::SetInstanceReference(NiInstanceRef pInstance)
{
    ms_pInstance = pInstance;
}
//---------------------------------------------------------------------------
inline NiInstanceRef NiApplication::GetInstanceReference()
{
    return ms_pInstance;
}
//---------------------------------------------------------------------------
inline void NiApplication::SetAcceleratorReference(NiAcceleratorRef pAccel)
{
    ms_pAccel = pAccel;
}
//---------------------------------------------------------------------------
inline NiAcceleratorRef NiApplication::GetAcceleratorReference()
{
    return ms_pAccel;
}
//---------------------------------------------------------------------------
inline void NiApplication::SetFullscreen(bool bOn)
{
    m_bFullscreen = bOn;
}
//---------------------------------------------------------------------------
inline bool NiApplication::GetFullscreen() const
{
    return m_bFullscreen;
}
//---------------------------------------------------------------------------
inline void NiApplication::SetStencil(bool bOn)
{
    m_bStencil = bOn;
}
//---------------------------------------------------------------------------
inline bool NiApplication::GetStencil() const
{
    return m_bStencil;
}
//---------------------------------------------------------------------------
inline void NiApplication::SetRendererDialog(bool bOn)
{
    m_bRendererDialog = bOn;
}
//---------------------------------------------------------------------------
inline bool NiApplication::GetRendererDialog() const
{
    return m_bRendererDialog;
}
//---------------------------------------------------------------------------
inline float NiApplication::GetMaxFrameRate()
{
    return 1.0f / m_fMinFramePeriod;    
}
//---------------------------------------------------------------------------
inline void NiApplication::SetMaxFrameRate(float fMax)
{
    // convert from rate to period - if a bogus max framerate is passed in,
    // disable framerate limitation
    if(fMax < 1e-5f)
        m_fMinFramePeriod = 1e-5f;    
    else
        m_fMinFramePeriod = 1.0f / fMax;    
}
//---------------------------------------------------------------------------
inline NiAppWindow* NiApplication::GetAppWindow() const
{
    return m_pkAppWindow;
}
//---------------------------------------------------------------------------
inline unsigned int NiApplication::GetMenuID() const
{
    return m_uiMenuID;
}
//---------------------------------------------------------------------------
inline NiWindowRef NiApplication::CreateMainWindow(int iWinMode,
    NiWindowRef hWnd) const
{
    return m_pkAppWindow->CreateMainWindow(iWinMode, hWnd);
}
//---------------------------------------------------------------------------
inline NiWindowRef NiApplication::GetWindowReference() const
{
    return m_pkAppWindow->GetWindowReference();
}
//---------------------------------------------------------------------------
inline NiWindowRef NiApplication::GetRenderWindowReference() const
{
    return m_pkAppWindow->GetRenderWindowReference();
}
//---------------------------------------------------------------------------
inline float NiApplication::GetCurrentTime() 
{ 
    return m_fCurrentTime; 
};
//---------------------------------------------------------------------------
inline float NiApplication::GetLastTime() 
{ 
    return m_fLastTime; 
};
//---------------------------------------------------------------------------
inline float NiApplication::GetDeltaTime() 
{ 
    return m_fDeltaTime; 
};
//---------------------------------------------------------------------------
inline float NiApplication::GetAccumTime() 
{ 
    return m_fAccumTime; 
};
//---------------------------------------------------------------------------
inline NiInputSystem* NiApplication::GetInputSystem()
{
    return m_spInputSystem;
}


#if defined(PS2)
//---------------------------------------------------------------------------
inline void NiApplication::SetMedia(int iMedia)
{
    ms_iMedia = iMedia;
}
//---------------------------------------------------------------------------
inline int NiApplication::GetMedia()
{
    return ms_iMedia;
}
//---------------------------------------------------------------------------
#endif
