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

#ifndef NITRANSFORMCONTROLLER_H
#define NITRANSFORMCONTROLLER_H

#include "NiSingleInterpController.h"

class NIANIMATION_ENTRY NiTransformController :
    public NiSingleInterpController
{
    NiDeclareRTTI;
    NiDeclareClone(NiTransformController);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiTransformController();

    virtual void Update(float fTime);
    
    // *** begin NDL internal use only ***
    virtual bool IsTransformController() const;
    virtual NiInterpolator* CreatePoseInterpolator(unsigned short usIndex = 0);
    virtual void SynchronizePoseInterpolator(NiInterpolator* pkInterp, 
        unsigned short usIndex = 0);
    virtual NiBlendInterpolator* CreateBlendInterpolator(
        unsigned short usIndex = 0, bool bManagerControlled = false, 
        bool bAccumulateAnimations = false, float fWeightThreshold = 0.0f, 
        unsigned char ucArraySize = 2)
        const;
    // *** end NDL internal use only ***

protected:
    // Virtual function overrides from base classes.
    virtual bool InterpTargetIsCorrectType(NiObjectNET* pkTarget) const;
    virtual bool InterpolatorIsCorrectType(NiInterpolator* pkInterpolator,
        unsigned short usIndex) const;
};

NiSmartPointer(NiTransformController);

#endif  // #ifndef NITRANSFORMCONTROLLER_H
