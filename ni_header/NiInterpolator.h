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

#ifndef NIINTERPOLATOR_H
#define NIINTERPOLATOR_H

#include <NiObject.h>
#include "NiAnimationLibType.h"
#include <NiAVObjectPalette.h>
#include <NiBool.h>

class NiQuaternion;
class NiPoint3;
class NiColorA;
class NiQuatTransform;
class NiObjectNET;

class NIANIMATION_ENTRY NiInterpolator : public NiObject
{
    NiDeclareRTTI;
    NiDeclareAbstractClone(NiInterpolator);
    NiDeclareAbstractStream;
    NiDeclareViewerStrings;

public:
    virtual ~NiInterpolator();

    virtual bool Update(float fTime, NiObjectNET* pkInterpTarget, bool& bValue);
    virtual bool Update(float fTime, NiObjectNET* pkInterpTarget, float& fValue);
    virtual bool Update(float fTime, NiObjectNET* pkInterpTarget, NiQuaternion& kValue);
    virtual bool Update(float fTime, NiObjectNET* pkInterpTarget, NiPoint3& kValue);
    virtual bool Update(float fTime, NiObjectNET* pkInterpTarget, NiColorA& kValue);
    virtual bool Update(float fTime, NiObjectNET* pkInterpTarget, NiQuatTransform& kValue);

    // For debug only.
    virtual bool IsBoolValueSupported() const;
    virtual bool IsFloatValueSupported() const;
    virtual bool IsQuaternionValueSupported() const;
    virtual bool IsPoint3ValueSupported() const;
    virtual bool IsColorAValueSupported() const;
    virtual bool IsTransformValueSupported() const;

    // For use in reducing the memory footprint of an interpolator 
    virtual void Collapse();

    // *** begin NDL internal use only ***
    virtual void GetActiveTimeRange(float& fBeginKeyTime, float& fEndKeyTime)
        const;
    virtual void GuaranteeTimeRange(float fStartTime, float fEndTime);
    virtual NiInterpolator* GetSequenceInterpolator(float fStartTime,
        float fEndTime);

    // This method is used to resolve any dependencies that might
    // be broken by storing the interpolator in a sequence.
    // The default implementation returns true
    virtual bool ResolveDependencies(NiAVObjectPalette* pkPalette);
    virtual bool SetUpDependencies();

    static const NiBool INVALID_BOOL;
    static const float INVALID_FLOAT;
    static const NiQuaternion INVALID_QUATERNION;
    static const NiPoint3 INVALID_POINT3;
    static const NiColorA INVALID_COLORA;

    virtual bool AlwaysUpdate() const;
    // *** end NDL internal use only ***

protected:
    NiInterpolator();

    bool TimeHasChanged(float fTime);

    float m_fLastTime;
};

NiSmartPointer(NiInterpolator);

#include "NiInterpolator.inl"

#endif  // #ifndef NIINTERPOLATOR_H
