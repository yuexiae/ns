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

#ifndef NIINPUT_D3DHEADERS_H
#define NIINPUT_D3DHEADERS_H

#include <NiDirectXVersion.h>

#if defined(_USRDLL)
    #if defined(_DX9)
        #define NIDX9RENDERER_IMPORT
    #elif defined(_DX8)
        #define NIDX8RENDERER_IMPORT
    #endif  //
#endif  //#if defined(_USRDLL)

#include <NiD3DRendererHeaders.h>

#endif  //#ifndef NIINPUT_D3DHEADERS_H
