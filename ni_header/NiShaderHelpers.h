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

#ifndef NISHADERHELPERS_H
#define NISHADERHELPERS_H

#include "NiShaderToolkitLibType.h"

#include <NiAVObject.h>
#include <NiTList.h>

class NISHADERTOOLKIT_ENTRY NiShaderHelpers
{
public:
    static bool RegisterShaders(NiAVObject* pkScene, 
        NiRenderer* pkRenderer);
    static bool UnRegisterShaders(NiAVObject* pkScene, 
        NiRenderer* pkRenderer, bool bReplace = false);
    
protected:
    static void RecursivelyRegisterShadersHelper(NiRenderer* pkRenderer, 
        NiAVObject* pkObj, NiTList<const char*>& kErrList);
    static void RecursivelyReleaseShadersHelper(NiRenderer* pkRenderer, 
        NiAVObject* pkObj, bool bReplace);
};
#endif