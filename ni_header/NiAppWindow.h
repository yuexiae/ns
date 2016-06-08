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

#ifndef NIAPPWINDOW_H
#define NIAPPWINDOW_H

#include <NiUniversalTypes.h>
#include <NiMemManager.h>

//---------------------------------------------------------------------------
class NiAppWindow 
{    
public:
    NiAppWindow
    (
        const char* pcWindowCaption,       // caption of window
        unsigned int uiWidth,              // client window width
        unsigned int uiHeight,             // client window height
        unsigned int uiNumStatusPanes = 0, // number of panes in status window
        unsigned long ulWindowStyle =      // client window style
                WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX
    );
    ~NiAppWindow();
    
    void SetWindowReference(NiWindowRef pWnd);
    NiWindowRef GetWindowReference();
    void SetRenderWindowReference(NiWindowRef pWnd);
    NiWindowRef GetRenderWindowReference();

    static const char* GetWindowClassName();
    unsigned long GetWindowStyle();
    void SetWindowStyle(unsigned long ulWindowStyle);

    // window caption
    void SetWindowCaption(char* pcCaption);
    const char* GetWindowCaption() const;

    // window size
    void SetWidth(unsigned int uiWidth);
    unsigned int GetWidth() const;
    void SetHeight(unsigned int uiHeight);
    unsigned int GetHeight() const;

    void SetParentWidth(unsigned int uiWidth);
    unsigned int GetParentWidth() const;
    void SetParentHeight(unsigned int uiHeight);
    unsigned int GetParentHeight() const;

    // status window
    void SetStatusWindowReference(NiStatusWindowRef pWnd, 
        unsigned int uiPane);
    NiStatusWindowRef GetStatusWindowReference(unsigned int uiPane) 
        const;
    bool GetStatusPanesExist() const;
    unsigned int GetNumStatusPanes() const;
    void StatusWindowCreate();
    void WriteToStatusWindow(unsigned int uiPane, char* pcMsg) const;
    void StatusWindowDestroy();

    // Window creation
    virtual NiWindowRef CreateMainWindow(int iWinMode, 
        NiWindowRef hWnd = NULL);

protected:
    NiWindowRef m_pWnd;
    NiWindowRef m_pRenderWnd;
    NiStatusWindowRef* m_ppStatusWnd;

    static char ms_acWindowClassName[];

    char* m_pcWindowCaption;
    unsigned int m_uiWidth;
    unsigned int m_uiParentWidth;
    unsigned int m_uiHeight;
    unsigned int m_uiParentHeight;
    unsigned int m_uiNumStatusPanes;
    bool m_bStatusPanes;
    unsigned long m_ulWindowStyle;
};
//---------------------------------------------------------------------------

#include "NiAppWindow.inl"

#endif // NIAPPWINDOW_H