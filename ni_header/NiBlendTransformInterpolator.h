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

#ifndef NIBLENDTRANSFORMINTERPOLATOR_H
#define NIBLENDTRANSFORMINTERPOLATOR_H

#include "NiBlendInterpolator.h"
#include "NiQuatTransform.h"

class NIANIMATION_ENTRY NiBlendTransformInterpolator :
    public NiBlendInterpolator
{
    NiDeclareRTTI;
    NiDeclareClone(NiBlendTransformInterpolator);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiBlendTransformInterpolator(bool bManagerControlled,
        float fWeightThreshold, unsigned char ucArraySize);

    // Virtual function overrides from base class.
    virtual bool Update(float fTime, NiObjectNET* pkInterpTarget, NiQuatTransform& kValue);
    virtual bool IsTransformValueSupported() const;

    // *** begin NDL internal use only ***
    void CreateCloneInPlace(NiBlendTransformInterpolator* pkClone, 
        NiCloningProcess& kCloning);

    // For cloning and streaming only.
    NiBlendTransformInterpolator();
    // *** end NDL internal use only ***

protected:
    // Virtual function overrides from base class.
    virtual bool InterpolatorIsCorrectType(NiInterpolator* pkInterpolator)
        const;
    bool StoreSingleValue(float fTime, NiObjectNET* pkInterpTarget, NiQuatTransform& kValue);
    bool BlendValues(float fTime, NiObjectNET* pkInterpTarget, NiQuatTransform& kValue);
};

NiSmartPointer(NiBlendTransformInterpolator);

#endif  // #ifndef NIBLENDTRANSFORMINTERPOLATOR_H
