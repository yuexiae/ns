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

#ifndef NIBLENDBOOLINTERPOLATOR_H
#define NIBLENDBOOLINTERPOLATOR_H

#include "NiBlendInterpolator.h"

class NIANIMATION_ENTRY NiBlendBoolInterpolator : public NiBlendInterpolator
{
    NiDeclareRTTI;
    NiDeclareClone(NiBlendBoolInterpolator);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiBlendBoolInterpolator(bool bManagerControlled, float fWeightThreshold,
        unsigned char ucArraySize);

    // Virtual function overrides from base class.
    virtual bool Update(float fTime, NiObjectNET* pkInterpTarget, bool& bValue);
    virtual bool IsBoolValueSupported() const;

protected:
    // For cloning and streaming only.
    NiBlendBoolInterpolator();

    // Virtual function overrides from base class.
    virtual bool InterpolatorIsCorrectType(NiInterpolator* pkInterpolator)
        const;

    bool StoreSingleValue(float fTime, NiObjectNET* pkInterpTarget, bool& bValue);
    bool BlendValues(float fTime, NiObjectNET* pkInterpTarget, bool& bValue);

    NiBool m_bBoolValue;
};

NiSmartPointer(NiBlendBoolInterpolator);

#endif  // #ifndef NIBLENDBOOLINTERPOLATOR_H
