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

#ifndef NID3DRENDERERHEADERS_H
#define NID3DRENDERERHEADERS_H

#if defined(_XENON)
    #include "NiXenonRendererHeaders.h"
#elif defined(_XBOX)
    #include "NiXBoxRendererHeaders.h"
#elif defined(_DX9)
    #include "NiDX9RendererHeaders.h"
#elif defined(_DX8)
    #include "NiDX8RendererHeaders.h"
#else
    #error _XENON, _XBOX, _DX9, or _DX8 must be specified
#endif

#endif  //#ifndef NID3DRENDERERHEADERS_H
