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

#ifndef NITCBROTKEY_H
#define NITCBROTKEY_H

#include "NiRotKey.h"

class NIANIMATION_ENTRY NiTCBRotKey : public NiRotKey
{
    NiDeclareAnimationStream;
public:
    // construction
    NiTCBRotKey ();
    NiTCBRotKey (float fTime, float fAngle, const NiPoint3& axis);
    NiTCBRotKey (float fTime, const NiQuaternion& quat);
    
    // attributes
    void SetTension (float fTension);
    void SetContinuity (float fContinuity);
    void SetBias (float fBias);
    float GetTension () const;
    float GetContinuity () const;
    float GetBias () const;
    
protected:
    // interpolation
    void CalculateDVals (const NiTCBRotKey* pPrev, const NiTCBRotKey* pNext);

    float m_fTension;
    float m_fContinuity;
    float m_fBias;

    // Intermediate quaternion values and angles used for interpolation.
    NiQuaternion m_A;
    NiQuaternion m_B;
};

NiRegisterAnimationStream(NiTCBRotKey);

#include "NiTCBRotKey.inl"

#endif

