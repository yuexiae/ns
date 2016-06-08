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

#ifndef NIBOUND_H
#define NIBOUND_H

#include "NiPoint3.h"
#include "NiStream.h"
#include "NiTArray.h"

class NiNode;
class NiPlane;
class NiTransform;

class NIMAIN_ENTRY NiBound 
{
public:
    // constructor
    NiBound();

    // attributes
    void SetCenter(const NiPoint3& kCenter);
    void SetCenter(float x, float y, float z);
    const NiPoint3& GetCenter() const;
    void SetRadius(float fRadius);
    float GetRadius() const;
    void SetCenterAndRadius(const NiPoint3& kCenter, float fRadius);

    // comparisons
    bool operator==(const NiBound& kBound);
    bool operator!=(const NiBound& kBound);
    bool operator<=(const NiBound& kBound);
    bool operator>=(const NiBound& kBound);

    void ComputeFromData(int iQuantity, const NiPoint3* pkData);

    void Update(const NiBound& kBound, const NiTransform& kXform);

    void ComputeMinimalBound(NiTArray<const NiBound*>& kBound);
    void Merge(const NiBound* pkBound);

    int WhichSide(const NiPlane& kPlane) const;

    static bool TestIntersect(float fTime,
        const NiBound& kB0, const NiPoint3& kV0,
        const NiBound& kB1, const NiPoint3& kV1);

    static bool FindIntersect(float fTime,
        const NiBound& kB0, const NiPoint3& kV0,
        const NiBound& kB1, const NiPoint3& kV1,
        float& fIntrTime, NiPoint3& kIntrPt, bool bCalcNormals,
        NiPoint3& kNormal0, NiPoint3& kNormal1);


    // *** begin NDL internal use only ***

    // streaming
    void LoadBinary(NiStream& kStream);
    void SaveBinary(NiStream& kStream);
    char* GetViewerString(const char* pcPrefix) const;

    // *** end NDL internal use only ***

protected:
    // data specific to bounding spheres
    NiPoint3 m_kCenter;
    float m_fRadius;

private:
    // for bounding sphere containment comparisons
    static float ms_fFuzzFactor;
    static float ms_fTolerance;
} NI_DATA_ALIGMENT(16);

//---------------------------------------------------------------------------
//  Inline include
#include "NiBound.inl"

//---------------------------------------------------------------------------

#endif

