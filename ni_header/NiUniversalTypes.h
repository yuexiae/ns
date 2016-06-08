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

#ifndef NIUNIVERSALTYPES_H
#define NIUNIVERSALTYPES_H

#include <NiOS.h>

typedef HWND NiWindowRef;
typedef HWND NiStatusWindowRef;
typedef HDC NiContextRef;
typedef HGLRC NiOglRenderContextRef;
typedef HINSTANCE NiInstanceRef;
typedef HACCEL NiAcceleratorRef;
typedef struct 
{
    HWND hWnd;
    UINT uiMsg;
    WPARAM wParam;
    LPARAM lParam;
} NiEventRecord, *NiEventRef;
typedef LPCREATESTRUCT NiCreateStructRef;
typedef HMENU NiMenuRef;

#endif // NIUNIVERSALTYPES_H