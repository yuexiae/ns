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

#ifndef NIBLENDACCUMTRANSFORMINTERPOLATOR_H
#define NIBLENDACCUMTRANSFORMINTERPOLATOR_H

#include "NiBlendInterpolator.h"
#include "NiQuatTransform.h"

class NIANIMATION_ENTRY NiBlendAccumTransformInterpolator :
    public NiBlendInterpolator
{
    NiDeclareRTTI;
    NiDeclareClone(NiBlendAccumTransformInterpolator);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiBlendAccumTransformInterpolator(bool bManagerControlled,
        float fWeightThreshold, unsigned char ucArraySize);
    virtual ~NiBlendAccumTransformInterpolator();

    // Virtual function overrides from base class.
    virtual bool Update(float fTime, NiObjectNET* pkInterpTarget, NiQuatTransform& kValue);
    virtual bool GetValue(NiQuatTransform& kValue) const;
    virtual bool IsTransformValueSupported() const;
    virtual unsigned char AddInterpInfo(NiInterpolator* pkInterpolator,
        float fWeight, char cPriority = 0, float fEaseSpinner = 1.0f);
    virtual NiInterpolatorPtr RemoveInterpInfo(unsigned char ucIndex);
    
    void ClearAccumulatedTransform();
    void SetAccumulatedTransform(const NiQuatTransform& kTransform);

protected:
    // For cloning and streaming only.
    NiBlendAccumTransformInterpolator();

    // Virtual function overrides from base class.
    virtual bool InterpolatorIsCorrectType(NiInterpolator* pkInterpolator)
        const;

    bool StoreSingleValue(float fTime, NiObjectNET* pkInterpTarget, NiQuatTransform& kValue);
    bool BlendValues(float fTime, NiObjectNET* pkInterpTarget, NiQuatTransform& kValue);

    virtual bool ReallocateArrays();
    
    void CalculateSingleValue(float fTime, NiObjectNET* pkInterpTarget);
    void CalculateValue(unsigned char ucIndex, float fTime, 
        NiObjectNET* pkInterpTarget);
    
    struct AccumArrayItem
    {
        AccumArrayItem();

        void ClearValues();

        void LoadBinary(NiStream& kStream);
        void SaveBinary(NiStream& kStream);

        float m_fLastTime;
        NiQuatTransform m_kLastValue;
        NiQuatTransform m_kDeltaValue;
        NiMatrix3 m_kRefFrame;
    };

    NiQuatTransform m_kAccumulatedTransformValue;
    AccumArrayItem* m_pkAccumArray;
    bool m_bReset;
};

NiSmartPointer(NiBlendAccumTransformInterpolator);

#include "NiBlendAccumTransformInterpolator.inl"

#endif  // #ifndef NIBLENDTRANSFORMINTERPOLATOR_H
