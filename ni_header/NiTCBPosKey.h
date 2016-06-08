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

#ifndef NITCBPOSKEY_H
#define NITCBPOSKEY_H

#include "NiPosKey.h"

class NIANIMATION_ENTRY NiTCBPosKey : public NiPosKey
{
    NiDeclareAnimationStream;
public:
    // construction
    NiTCBPosKey ();
    NiTCBPosKey (float fTime, const NiPoint3& pos, float fTension,
        float fContinuity, float fBias);

    // attributes
    void SetTension (float fTension);
    void SetContinuity (float fContinuity);
    void SetBias (float fBias);
    float GetTension () const;
    float GetContinuity () const;
    float GetBias () const;


    // *** begin NDL internal use only ***

    void CalculateDVals (const NiPoint3& ptSub1, const NiPoint3& ptPlus1,
        float fPreLen, float fNextLen);

    // *** end NDL internal use only ***

protected:
    float m_fTension;
    float m_fContinuity;
    float m_fBias;

    // DS and DD hold the first derivative information defined by
    // the tension, continuity, and bias parameters.
    NiPoint3 m_DS;
    NiPoint3 m_DD;

    // A & B are calculated and stored for use with this interpolant
    // and the interpolant to the "right", i.e. the next interpolant 
    // specified at a non-decreasing time value.  In doing this, A & B
    // can be calculated once, rather than each time interpolation
    // is done using the two keys in question.
    NiPoint3 m_A;
    NiPoint3 m_B;
};

NiRegisterAnimationStream(NiTCBPosKey);

#include "NiTCBPosKey.inl"

#endif
