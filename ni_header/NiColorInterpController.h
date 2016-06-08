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

#ifndef NICOLORINTERPCONTROLLER_H
#define NICOLORINTERPCONTROLLER_H

#include "NiSingleInterpController.h"
class NiColorA;

class NIANIMATION_ENTRY NiColorInterpController :
    public NiSingleInterpController
{
    NiDeclareRTTI;
    NiDeclareAbstractClone(NiColorInterpController);
    NiDeclareAbstractStream;
    NiDeclareViewerStrings;

public:
    
    // *** begin NDL internal use only ***
    virtual NiInterpolator* GetPoseInterpolator(unsigned short usIndex = 0);
    virtual void SynchronizePoseInterpolator(NiInterpolator* pkInterp, 
        unsigned short usIndex = 0);
    virtual NiBlendInterpolator* CreateBlendInterpolator(
        unsigned short usIndex = 0, bool bManagerControlled = false, 
        bool bAccumulateAnimations = false, float fWeightThreshold = 0.0f,
        unsigned char ucArraySize = 2) 
        const;
    // *** begin NDL internal use only ***

protected:
    NiColorInterpController();
    
    // Virtual function overrides from base classes.
    virtual bool InterpolatorIsCorrectType(NiInterpolator* pkInterpolator,
        unsigned short usIndex) const;

    virtual void GetTargetColorValue(NiColorA& kValue) = 0;
};

NiSmartPointer(NiColorInterpController);

#endif  // #ifndef NICOLORINTERPCONTROLLER_H
