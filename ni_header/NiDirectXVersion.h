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

#ifndef NIDIRECTXVERSION_H
#define NIDIRECTXVERSION_H

#if defined(WIN32) && !defined(_XBOX)

// Specify which DirectX version to use as the DX renderer

// ***WARNING***
// Only one of these can be active at a time
#if !defined (_DX8) && !defined(_DX9)
//#define _DX8
#define _DX9
#endif //#if !defined (_DX8) && !defined(_DX9)

#endif //#if defined(WIN32) && !defined(_XBOX)

#if defined (_DX9) && defined(_DEBUG)
    #define D3D_DEBUG_INFO
#endif //#if defined (_DX9) and defined(_DEBUG)

#endif //NIDIRECTXVERSION_H
