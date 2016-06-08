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

#ifndef NIINPUTMOUSE_H
#define NIINPUTMOUSE_H

#include "NiInputDevice.h"

class NIINPUT_ENTRY NiInputMouse : public NiInputDevice
{
    NiDeclareRTTI;

public:
    enum Axes
    {
        NIM_AXIS_X  = 0,
        NIM_AXIS_Y,
        NIM_AXIS_Z,     // Mouse Wheel
        NIM_AXIS_COUNT
    };

    // to be used as the input side index of the device 
    // mapping array
    enum Button
    {
        NIM_NONE   = -1,
        NIM_LEFT,       // The 0 button
        NIM_RIGHT,      // The 1 button
        NIM_MIDDLE,     // The 2 button
        // Newer mice have multiple buttons. We will support an additional
        // 5 buttons for a total of 8.
        NIM_X1,
        NIM_X2,
        NIM_X3,
        NIM_X4,
        NIM_X5,
        NIM_NUM_BUTTONS
    };

    enum Modifiers
    { 
        MMOD_NONE      = 0x00000000,
        // Mouse buttons
        MMOD_LEFT      = 1 << NIM_LEFT,
        MMOD_RIGHT     = 1 << NIM_RIGHT,
        MMOD_MIDDLE    = 1 << NIM_MIDDLE,
        MMOD_X1        = 1 << NIM_X1,
        MMOD_X2        = 1 << NIM_X2,
        MMOD_X3        = 1 << NIM_X3,
        MMOD_X4        = 1 << NIM_X4,
        MMOD_X5        = 1 << NIM_X5,
        // Keyboard modifiers
        MMOD_LCONTROL  = 0x00000100,
        MMOD_RCONTROL  = 0x00000200,
        MMOD_LMENU     = 0x00000400,
        MMOD_RMENU     = 0x00000800,
        MMOD_LWIN      = 0x00001000,
        MMOD_RWIN      = 0x00002000,
        MMOD_LSHIFT    = 0x00004000,
        MMOD_RSHIFT    = 0x00008000,
        MMOD_CAPS_LOCK = 0x00010000
    };

public:
    // *** begin NDL internal use only ***
    NiInputMouse(NiInputDevice::Description* pkDescription);
    // *** end NDL internal use only ***

public:
    // destruction
    ~NiInputMouse();

    //
    virtual NiInputErr UpdateDevice();
    virtual NiInputErr UpdateActionMappedDevice(
        NiInputSystem* pkInputSystem);
    virtual NiInputErr HandleRemoval();
    virtual NiInputErr HandleInsertion();

    // Query state of mouse
    const bool ButtonIsDown(Button eButton, 
        unsigned int& uiModifiers) const;
    const bool ButtonIsDown(Button eButton) const;

    const bool ButtonWasPressed(Button eButton, 
        unsigned int& uiModifiers) const;
    const bool ButtonWasPressed(Button eButton) const;

    const bool ButtonWasReleased(Button eButton, 
        unsigned int& uiModifiers) const;
    const bool ButtonWasReleased(Button eButton) const;

    bool GetPositionDelta(unsigned int uiAxis, int& iDelta);
    bool GetPositionDelta(int& iX, int& iY, int& iZ);

    // *** begin NDL internal use only ***
    // Keep track of state of mouse
    void RecordButtonPress(Button eButton);
    void RecordButtonRelease(Button eButton);
    void RecordPositionChange(unsigned int uiAxis, int iDelta);
    void RecordPositionChange(int iX, int iY, int iZ);

    virtual void TouchAllInputValues();

    virtual bool IsControlMapped(unsigned int uiControl, 
        unsigned int uiSemantic, bool bUseModifiers, 
        unsigned int uiModifiers, bool bUseRange = false,
        int iRangeLow = 0, int iRangeHigh = 0);
    // *** end NDL internal use only ***

protected:
    // These UpdateMapped* functions are just to make the code easier
    // to follow.
    virtual bool UpdateMappedButtons(NiInputSystem* pkInputSystem);
    virtual bool UpdateMappedSticks(NiInputSystem* pkInputSystem);

    // Axis - RELATIVE change.
    NiInputDevice::Axis m_akAxes[NIM_AXIS_COUNT];
    // Buttons
    NiInputDevice::Button m_akButtons[NIM_NUM_BUTTONS];
};

NiSmartPointer(NiInputMouse);

#include "NiInputMouse.inl"

#endif  //#ifndef NIINPUTMOUSE_H
