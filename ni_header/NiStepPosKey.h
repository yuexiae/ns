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

#ifndef NISTEPPOSKEY_H
#define NISTEPPOSKEY_H

#include "NiPosKey.h"

class NIANIMATION_ENTRY NiStepPosKey : public NiPosKey
{
    NiDeclareAnimationStream;
public:
    // construction
    NiStepPosKey ();
    NiStepPosKey (float fTime, const NiPoint3& pos);
};

NiRegisterAnimationStream(NiStepPosKey);

#include "NiStepPosKey.inl"

#endif


