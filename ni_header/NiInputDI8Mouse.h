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

#ifndef NIINPUTDI8MOUSE_H
#define NIINPUTDI8MOUSE_H

#include "NiInputMouse.h"
#include "NiDI8Headers.h"

class NIINPUT_ENTRY NiInputDI8Mouse : public NiInputMouse
{
    NiDeclareRTTI;

public:
    // construction
    NiInputDI8Mouse(NiInputDevice::Description* pkDescription,
        LPDIRECTINPUTDEVICE8 pkDIDevice, unsigned int uiUsage);
    // destruction
    ~NiInputDI8Mouse();

    //
    virtual NiInputErr UpdateDevice();
    virtual NiInputErr HandleRemoval();
    virtual NiInputErr HandleInsertion();

    // *** begin NDL internal use only ***
    const LPDIRECTINPUTDEVICE8 GetDIDevice();
    // *** end NDL internal use only ***

protected:
    void FlushBuffer();
    void UpdateImmediateData(DWORD dwData, unsigned int uiBtnOffset);
    void UpdateImmediatePositionData(int iX, int iY, int iZ);

    LPDIRECTINPUTDEVICE8 m_pkDIDevice;
    unsigned int m_uiBufferSize;

    unsigned int m_uiButtonTouchMask;
};

NiSmartPointer(NiInputDI8Mouse);

#include "NiInputDI8Mouse.inl"

#endif  //#ifndef NIINPUTDI8MOUSE_H
