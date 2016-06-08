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

#ifndef NITEXTURESWIZZLE_H
#define NITEXTURESWIZZLE_H

#include "NiTextureSwizzleLibType.h"

class NiAVObject;
class NiPixelData;
class NiTexture;
class NiTimeController;

class NITEXTURESWIZZLE_ENTRY NiTextureSwizzle
{
public:
    static void SwizzlePS2(NiAVObject* pkScene);
    static void SwizzlePS2(NiPixelData* pkPixelData);
    
protected:
    typedef void (*SwizzleFunc)(NiPixelData*);

    static void Swizzle(NiAVObject* pkScene, SwizzleFunc pfnSwizzle);
    static void Swizzle(NiTexture* pkTexture, SwizzleFunc pfnSwizzle);
    static void Swizzle(NiTimeController* pkControl, SwizzleFunc pfnSwizzle);
};

#endif // NITEXTURESWIZZLE_H
