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

#ifndef NIINPUT_H
#define NIINPUT_H

// This must be first... Otherwise the keyboard/mouse defines will not be
// present when the Xbox.h file is included!
#if defined(_XENON)
    #include "NiInput_Xenon.h"
#elif defined(_XBOX)
    #include "NiInput_XBox.h"
#endif  //#if defined(_XBOX)

#include <NiSystem.h>
#include <NiSmartPointer.h>

#include "NiInputLibType.h"
#include "NiInputDevice.h"
#include "NiInputGamePad.h"
#include "NiInputKeyboard.h"
#include "NiInputMouse.h"
#include "NiInputErr.h"
#include "NiInputSystem.h"

#include "NiAction.h"
#include "NiActionData.h"
#include "NiActionMap.h"

#if defined(PS2)
#include "NiInput_PS2.h"
#elif defined(NGC)
#include "NiInput_NGC.h"
#elif defined(_XBOX)
#else
#include "NiInput_DI8.h"
#endif

#endif  //#ifndef NIINPUT_H
