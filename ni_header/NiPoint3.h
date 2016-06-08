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

#ifndef NIPOINT3_H
#define NIPOINT3_H

#include "NiMath.h"
#include "NiStream.h"

class NIMAIN_ENTRY NiPoint3
{
public:
    float x, y, z;

    NiPoint3 () { /* */ }
    NiPoint3 (float fX, float fY, float fZ);

    float& operator[] (int i) const
    {
        // warning:  safe for 4-byte aligned class member data
        const float* base = &x;
        return (float&) base[i];
    }

    bool operator== (const NiPoint3& pt) const;
    bool operator!= (const NiPoint3& pt) const { return !(*this == pt); }

    NiPoint3 operator+ (const NiPoint3& pt) const;
    NiPoint3 operator- (const NiPoint3& pt) const;
    float operator* (const NiPoint3& pt) const;
    NiPoint3 operator* (float fScalar) const;
    NiPoint3 operator/ (float fScalar) const;
    NiPoint3 operator- () const;
    NIMAIN_ENTRY friend NiPoint3 operator* (float fScalar,
        const NiPoint3& pt);
    static NiPoint3 ComponentProduct (const NiPoint3& p0, const NiPoint3& p1);

    NiPoint3& operator+= (const NiPoint3& pt);
    NiPoint3& operator-= (const NiPoint3& pt);
    NiPoint3& operator*= (float fScalar);
    NiPoint3& operator/= (float fScalar);

    float Length () const;
    float SqrLength () const;
    float Dot (const NiPoint3& pt) const;
    float Unitize ();
    NiPoint3 Cross (const NiPoint3& pt) const;
    NiPoint3 UnitCross (const NiPoint3& pt) const;

    // This finds one of the infinite set of perpendicular vectors
    NiPoint3 Perpendicular () const;

    static const NiPoint3 ZERO;
    static const NiPoint3 UNIT_X;
    static const NiPoint3 UNIT_Y;
    static const NiPoint3 UNIT_Z;
    static const NiPoint3 UNIT_ALL;

    // *** begin NDL internal use only ***

    // streaming
    void LoadBinary (NiStream& stream);
    void SaveBinary (NiStream& stream);
    char* GetViewerString (const char* pPrefix) const;

    static void _SDMInit();
    static void _SDMShutdown();

    // *** end NDL internal use only ***

public:
    // Methods that use fast, but less precise, square root.

    // This algorithm was published as "A High Speed, Low Precision Square
    // Root", by Paul Lalonde and Robert Dawon, Dalhousie University, Halifax,
    // Nova Scotia, Canada, on pp. 424-6 of "Graphics Gems", edited by Andrew
    // Glassner, Academic Press, 1990.

    // WARNING:  These results are generally faster than their full-precision
    // counterparts (except on modern PC hardware), but are only worth 7 bits
    // of binary precision (1 in 128).
    // [A table for 7-bit precision requires 256 entries.]
    static void UnitizeVectors(NiPoint3* pkV, unsigned int uiNum, 
        unsigned int uiStride);
    static void UnitizeVector (NiPoint3& v);
    static float VectorLength (const NiPoint3& v);

    static void PointsPlusEqualFloatTimesPoints(NiPoint3* pkDst, float f,
        const NiPoint3* pkSrc, unsigned int uiVerts);
    static void WeightedPointsPlusWeightedPoints(NiPoint3* pkDst,
        float fWeight, const NiPoint3* pkSrc, unsigned int uiVerts);

protected:
    static unsigned int* InitSqrtTable ();
    static unsigned int* ms_pSqrtTable;
};

//---------------------------------------------------------------------------
//  Inline include
#include "NiPoint3.inl"

//---------------------------------------------------------------------------

#endif

