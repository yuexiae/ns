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

#ifndef NITCBFLOATKEY_H
#define NITCBFLOATKEY_H

#include "NiFloatKey.h"

class NIANIMATION_ENTRY NiTCBFloatKey : public NiFloatKey
{
    NiDeclareAnimationStream;
public: 
    // construction
    NiTCBFloatKey ();
    NiTCBFloatKey (float fTime, float fValue, float fTension,
        float fContinuity, float fBias);

    // attributes
    void SetTension (float fTension);
    void SetContinuity (float fContinuity);
    void SetBias (float fBias);
    float GetTension () const;
    float GetContinuity () const;
    float GetBias () const;
    
protected:
    static void CalculateDVals (NiTCBFloatKey& result, float fValSub1,
        float fValPlus1, float fPreLen, float fNextLen);

    float m_fTension;
    float m_fContinuity;
    float m_fBias;

    // DS and DD hold the first derivative information defined by
    // the tension, continuity, and bias parameters.
    float m_fDS;
    float m_fDD;
};

NiRegisterAnimationStream(NiTCBFloatKey);

#include "NiTCBFloatKey.inl"

#endif
