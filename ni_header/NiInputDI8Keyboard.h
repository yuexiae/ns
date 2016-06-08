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

#ifndef NIINPUTDI8KEYBOARD_H
#define NIINPUTDI8KEYBOARD_H

#include "NiInputKeyboard.h"
#include "NiDI8Headers.h"

class NIINPUT_ENTRY NiInputDI8Keyboard : public NiInputKeyboard
{
    NiDeclareRTTI;

    enum
    {
        NIDI8KB_NUM_KEYS = 256
    };

public:
    NiInputDI8Keyboard(NiInputDevice::Description* pkDescription,
        LPDIRECTINPUTDEVICE8 pkDIDevice, unsigned int uiUsage);
    virtual ~NiInputDI8Keyboard();

    //
    virtual NiInputErr UpdateDevice();
    virtual NiInputErr HandleRemoval();
    virtual NiInputErr HandleInsertion();

    // *** begin NDL internal use only ***
    const LPDIRECTINPUTDEVICE8 GetDIDevice();
    // *** end NDL internal use only ***

protected:
    void FillMapping();
    const char* KeyCodeToString(unsigned int uiDIKeyCode);

    LPDIRECTINPUTDEVICE8 m_pkDIDevice;
    char m_acBuffer[NIDI8KB_NUM_KEYS];
    KeyCode m_aeDIToNIIMapping[NIDI8KB_NUM_KEYS];
};

NiSmartPointer(NiInputDI8Keyboard);

#include "NiInputDI8Keyboard.inl"

#endif  //#ifndef NIINPUTDI8KEYBOARD_H
