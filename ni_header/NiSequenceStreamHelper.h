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

#ifndef NISEQUENCESTREAMHELPER_H
#define NISEQUENCESTREAMHELPER_H

#include "NiAnimationLibType.h"
#include <NiObjectNET.h>

// NOTICE: This class is deprecated and is included only to support streaming
//         of KF files from NetImmerse 4.0 or earlier.

class NIANIMATION_ENTRY NiSequenceStreamHelper : public NiObjectNET
{
    NiDeclareRTTI;
    NiDeclareStream;

protected:
    NiSequenceStreamHelper() { /**/ };
};

#endif // NISEQUENCESTREAMHELPER_H
