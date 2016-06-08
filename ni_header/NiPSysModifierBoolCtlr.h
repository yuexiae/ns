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

#ifndef NIPSYSMODIFIERBOOLCTLR_H
#define NIPSYSMODIFIERBOOLCTLR_H

#include "NiPSysModifierCtlr.h"

class NIPARTICLE_ENTRY NiPSysModifierBoolCtlr : public NiPSysModifierCtlr
{
    NiDeclareRTTI;
    NiDeclareAbstractClone(NiPSysModifierBoolCtlr);
    NiDeclareAbstractStream;
    NiDeclareViewerStrings;

public:

    virtual void Update(float fTime);

    // *** begin NDL internal use only ***
    virtual NiInterpolator* CreatePoseInterpolator(unsigned short usIndex = 0);
    virtual void SynchronizePoseInterpolator(NiInterpolator* pkInterp, 
        unsigned short usIndex = 0);
    virtual NiBlendInterpolator* CreateBlendInterpolator(
        unsigned short usIndex = 0, bool bManagerControlled = false, 
        bool bAccumulateAnimations = false, float fWeightThreshold = 0.0f, 
        unsigned char ucArraySize = 2) const;
    // *** end NDL internal use only ***
protected:
    NiPSysModifierBoolCtlr(const char* pcModifierName);

    // For cloning and streaming only.
    NiPSysModifierBoolCtlr();

    // Virtual function overrides from base classes.
    virtual bool InterpolatorIsCorrectType(NiInterpolator* pkInterpolator,
        unsigned short usIndex) const;

    virtual void GetTargetBoolValue(bool& bValue) = 0;
    virtual void SetTargetBoolValue(bool bValue) = 0;
};

NiSmartPointer(NiPSysModifierBoolCtlr);

#include "NiPSysModifierBoolCtlr.inl"

#endif  // #ifndef NIPSYSMODIFIERBOOLCTLR_H
