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

#ifndef NIBLENDPOINT3INTERPOLATOR_H
#define NIBLENDPOINT3INTERPOLATOR_H

#include "NiBlendInterpolator.h"
#include <NiPoint3.h>

class NIANIMATION_ENTRY NiBlendPoint3Interpolator : public NiBlendInterpolator
{
    NiDeclareRTTI;
    NiDeclareClone(NiBlendPoint3Interpolator);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiBlendPoint3Interpolator(bool bManagerControlled, float fWeightThreshold,
        unsigned char ucArraySize);

    // Virtual function overrides from base class.
    virtual bool Update(float fTime, NiObjectNET* pkInterpTarget, NiPoint3& kValue);
    virtual bool IsPoint3ValueSupported() const;

protected:
    // For cloning and streaming only.
    NiBlendPoint3Interpolator();

    // Virtual function overrides from base class.
    virtual bool InterpolatorIsCorrectType(NiInterpolator* pkInterpolator)
        const;
    bool StoreSingleValue(float fTime, NiObjectNET* pkInterpTarget, NiPoint3& kValue);
    bool BlendValues(float fTime, NiObjectNET* pkInterpTarget, NiPoint3& kValue);

    NiPoint3 m_kPoint3Value;
    bool m_bValidValue;
};

NiSmartPointer(NiBlendPoint3Interpolator);

#endif  // #ifndef NIBLENDPOINT3INTERPOLATOR_H
