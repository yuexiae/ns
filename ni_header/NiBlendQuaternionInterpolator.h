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

#ifndef NIBLENDQUATERNIONINTERPOLATOR_H
#define NIBLENDQUATERNIONINTERPOLATOR_H

#include "NiBlendInterpolator.h"
#include <NiQuaternion.h>

class NIANIMATION_ENTRY NiBlendQuaternionInterpolator :
    public NiBlendInterpolator
{
    NiDeclareRTTI;
    NiDeclareClone(NiBlendQuaternionInterpolator);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiBlendQuaternionInterpolator(bool bManagerControlled,
        float fWeightThreshold, unsigned char ucArraySize);

    // Virtual function overrides from base class.
    virtual bool Update(float fTime, NiObjectNET* pkInterpTarget, NiQuaternion& kValue);
    virtual bool IsQuaternionValueSupported() const;

protected:
    // For cloning and streaming only.
    NiBlendQuaternionInterpolator();

    // Virtual function overrides from base class.
    virtual bool InterpolatorIsCorrectType(NiInterpolator* pkInterpolator)
        const;
    bool StoreSingleValue(float fTime, NiObjectNET* pkInterpTarget, NiQuaternion& kValue);
    bool BlendValues(float fTime, NiObjectNET* pkInterpTarget, NiQuaternion& kValue);

    NiQuaternion m_kQuaternionValue;
};

NiSmartPointer(NiBlendQuaternionInterpolator);

#endif  // #ifndef NIBLENDQUATERNIONINTERPOLATOR_H
