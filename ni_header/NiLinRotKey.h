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

#ifndef NILINROTKEY_H
#define NILINROTKEY_H

#include "NiRotKey.h"

class NIANIMATION_ENTRY NiLinRotKey : public NiRotKey
{
    NiDeclareAnimationStream;
public:
    // construction
    NiLinRotKey ();
    NiLinRotKey (float fTime, const NiQuaternion& quat);
    NiLinRotKey (float fTime, float fAngle, const NiPoint3& axis);
};

NiRegisterAnimationStream(NiLinRotKey);

#include "NiLinRotKey.inl"

#endif

