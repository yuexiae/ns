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

#ifndef NIROLLCONTROLLER_H
#define NIROLLCONTROLLER_H

#include "NiFloatController.h"
NiSmartPointer(NiRollController);

// This class has been deprecated as of Gamebryo 1.2. 
// Equivalent functionality can be found with an NiTransformController
// containing an NiLookAtInterpolator.

class NIANIMATION_ENTRY NiRollController : public NiFloatController
{
    NiDeclareRTTI;
    NiDeclareClone(NiRollController);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    virtual void Update (float fTime);
    virtual bool IsTransformController() const;

protected:
    // Protected constructor to prevent instantiation of this class outside
    // of stream loading.
    NiRollController (NiFloatData* pData = 0);

    // debugging
    virtual bool TargetIsRequiredType () const;
};

typedef NiPointer<NiRollController> NiRollControllerPtr;

#include "NiRollController.inl"

#endif

