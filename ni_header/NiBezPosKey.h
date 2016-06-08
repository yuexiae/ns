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

#ifndef NIBEZPOSKEY_H
#define NIBEZPOSKEY_H

#include "NiPosKey.h"

class NIANIMATION_ENTRY NiBezPosKey : public NiPosKey
{
    NiDeclareAnimationStream;
public:
    // construction
    NiBezPosKey ();
    NiBezPosKey (float fTime, const NiPoint3& pos, const NiPoint3& inTan,
        const NiPoint3& outTan);

    // attributes
    void SetInTan (const NiPoint3& inTan);
    void SetOutTan (const NiPoint3& outTan);
    const NiPoint3& GetInTan () const;
    const NiPoint3& GetOutTan () const;
    
protected:
    NiPoint3 m_InTan;
    NiPoint3 m_OutTan;

    // A & B are calculated and stored for use with this interpolant
    // and the interpolant to the "right", i.e. the next interpolant 
    // specified at a non-decreasing time value.  In doing this, A & B
    // can be calculated once, rather than each time interpolation
    // is done using the two keys in question.
    NiPoint3 m_A;
    NiPoint3 m_B;
};

NiRegisterAnimationStream(NiBezPosKey);

#include "NiBezPosKey.inl"

#endif
