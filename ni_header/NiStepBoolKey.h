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

#ifndef NISTEPBOOLKEY_H
#define NISTEPBOOLKEY_H

#include "NiBoolKey.h"

class NIANIMATION_ENTRY NiStepBoolKey : public NiBoolKey
{
    NiDeclareAnimationStream;
public:
    // construction
    NiStepBoolKey ();
    NiStepBoolKey (float fTime, const bool bBool);
};

NiRegisterAnimationStream(NiStepBoolKey);

#include "NiStepBoolKey.inl"

#endif


