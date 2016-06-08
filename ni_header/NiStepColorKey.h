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

#ifndef NISTEPCOLORKEY_H
#define NISTEPCOLORKEY_H

#include "NiColorKey.h"


class NIANIMATION_ENTRY NiStepColorKey : public NiColorKey
{
    NiDeclareAnimationStream;
public:
    // construction
    NiStepColorKey ();
    NiStepColorKey (float fTime, const NiColorA& color);
};

NiRegisterAnimationStream(NiStepColorKey);

#include "NiStepColorKey.inl"

#endif


