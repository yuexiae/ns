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

#ifndef NIPOINT2_H
#define NIPOINT2_H

#include "NiMath.h"
#include "NiStream.h"

class NIMAIN_ENTRY NiPoint2
{
public:
    float x, y;

    NiPoint2 () { /**/ }
    NiPoint2 (float fX, float fY);

    float& operator[] (int i) const
    {
        // warning:  safe for 4-byte aligned class member data
        const float* base = &x;
        return (float&) base[i];
    }

    bool operator== (const NiPoint2& pt) const;
    bool operator!= (const NiPoint2& pt) const;

    NiPoint2 operator+ (const NiPoint2& pt) const;
    NiPoint2 operator- (const NiPoint2& pt) const;
    float operator* (const NiPoint2& pt) const;
    NiPoint2 operator* (float fScalar) const;
    NiPoint2 operator/ (float fScalar) const;
    NiPoint2 operator- () const;
    NIMAIN_ENTRY friend NiPoint2 operator* (float fScalar,
        const NiPoint2& pt);
    static NiPoint2 ComponentProduct (const NiPoint2& p0, const NiPoint2& p1);

    NiPoint2& operator+= (const NiPoint2& pt);
    NiPoint2& operator-= (const NiPoint2& pt);
    NiPoint2& operator*= (float fScalar);
    NiPoint2& operator/= (float fScalar);

    float Length () const;
    float SqrLength () const;
    float Dot (const NiPoint2& pt) const;
    float Unitize ();

    static const NiPoint2 ZERO;
    static const NiPoint2 UNIT_X;
    static const NiPoint2 UNIT_Y;

    // *** begin NDL internal use only ***

    // streaming
    void LoadBinary (NiStream& stream);
    void SaveBinary (NiStream& stream);
    char* GetViewerString (const char* pPrefix) const;

    // *** end NDL internal use only ***
};

//---------------------------------------------------------------------------
#include "NiRTLib.h"

//---------------------------------------------------------------------------
//  Inline include
#include "NiPoint2.inl"

//---------------------------------------------------------------------------

#endif

