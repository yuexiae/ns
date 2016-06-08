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

#ifndef NIBOXBV_H
#define NIBOXBV_H

#include "NiBoundingVolume.h"
#include "NiBox.h"
#include "NiPoint3.h"
#include "NiCollisionGroup.h"

class NICOLLISION_ENTRY NiBoxBV : public NiBoundingVolume
{
    NiDeclareBVStream;
public:
    NiBoxBV(const NiPoint3& kExtent = NiPoint3::UNIT_ALL, 
        const NiPoint3& kCenter = NiPoint3::ZERO, 
        const NiPoint3& kXAxis = NiPoint3::UNIT_X,
        const NiPoint3& kYAxis = NiPoint3::UNIT_Y,
        const NiPoint3& kZAxis = NiPoint3::UNIT_Z);
    NiBoxBV(const NiBoxBV& kABV);
    
    void SetCenter(const NiPoint3& kCenter);
    const NiPoint3& GetCenter() const;
    
    void SetAxis(int iWhich, const NiPoint3& kAxis);
    const NiPoint3& GetAxis(int iWhich) const;
    const NiPoint3* GetAxes() const;
    
    void SetExtent(int iWhich, float fExtent);
    float GetExtent(int iWhich) const;
    const float* GetExtents() const;
    
    // run-time type information
    virtual int Type() const;

    
    // *** begin NDL internal use only ***
    
    void SetBox(const NiBox& kBox);
    const NiBox& GetBox() const;

    virtual void UpdateWorldData(const NiBoundingVolume& kModelABV,
        const NiTransform &kWorld);

    virtual NiBoundingVolume* Create() const;
    virtual void Copy(const NiBoundingVolume& kABV);

    // cloning
    virtual NiBoundingVolume* Clone() const;

    // comparison
    virtual bool operator==(const NiBoundingVolume& kABV) const;
    virtual bool operator!=(const NiBoundingVolume& kABV) const;

    // 'test' functions
    static bool BoxSphereTestIntersect(float fTime,
        const NiBoundingVolume& kABV0, const NiPoint3& kV0, 
        const NiBoundingVolume& kABV1, const NiPoint3& kV1);
    
    static bool BoxBoxTestIntersect(float fTime,
        const NiBoundingVolume& kABV0, const NiPoint3& kV0, 
        const NiBoundingVolume& kABV1, const NiPoint3& kV1);
    
    static NiCollisionGroup::Intersect ms_kBoxCapIntrData;
    static int BoxCapsuleCallback(NiCollisionGroup::Intersect& kIntr);
    static bool BoxCapsuleTestIntersect(float fTime,
        const NiBoundingVolume& kABV0, const NiPoint3& kV0, 
        const NiBoundingVolume& kABV1, const NiPoint3& kV1);
         
    static bool BoxTriTestIntersect(float fTime,
        const NiBoundingVolume& kABV0, const NiPoint3& kV0, 
        const NiPoint3& kVert0, const NiPoint3& kVert1, 
        const NiPoint3& kVert2, const NiPoint3& kV1);

    // 'find' functions
    static bool BoxSphereFindIntersect(float fTime,
        const NiBoundingVolume& kABV0, const NiPoint3& kV0, 
        const NiBoundingVolume& kABV1, const NiPoint3& kV1,
        float& fIntrTime, NiPoint3& kIntrPt, bool bCalcNormals,
        NiPoint3& kNormal0, NiPoint3& kNormal1);
    
    static bool BoxBoxFindIntersect(float fTime,
        const NiBoundingVolume& kABV0, const NiPoint3& kV0, 
        const NiBoundingVolume& kABV1, const NiPoint3& kV1,
        float& fIntrTime, NiPoint3& kIntrPt, bool bCalcNormals,
        NiPoint3& kNormal0, NiPoint3& kNormal1);
    
    static bool BoxCapsuleFindIntersect(float fTime,
        const NiBoundingVolume& kABV0, const NiPoint3& kV0, 
        const NiBoundingVolume& kABV1, const NiPoint3& kV1,
        float& fIntrTime, NiPoint3& kIntrPt, bool bCalcNormals,
        NiPoint3& kNormal0, NiPoint3& kNormal1);
        
    static bool BoxTriFindIntersect(float fTime,
        const NiBoundingVolume& kABV0, const NiPoint3& kV0, 
        const NiPoint3& kVert0, const NiPoint3& kVert1, 
        const NiPoint3& kVert2, const NiPoint3& kV1,
        float& fIntrTime, NiPoint3& kIntrPt, bool bCalcNormals,
        NiPoint3& kNormal0, NiPoint3& kNormal1);
    
    // For printing of ABV types
    virtual void AddViewerStrings(const char* pcPrefix, 
        NiTArray<char*>* pkStrings) const;

    // *** end NDL internal use only ***

protected:
    // support for normal calculations at intersection points
    NiPoint3 GetNormal(int iSign0, int iSign1, int iSign2) const;
    NiPoint3 GetNormal(int iSign0, int iSign1, int iSign2,
                       const NiPoint3 kOrientation) const;
    NiPoint3 GetNormal(NiPoint3 kNormal, const NiPoint3 kRelVel,
        const NiBoxBV& kBBV) const;

    // Support accurate intersection point detection ofr Box/Box collisions
    static void RefinePoint(float fTime, const NiBoxBV* pkBV0, 
        const NiPoint3* pkV0, const NiBoxBV* pkBV1, const NiPoint3* pkV1, 
        float& fIntrTime, NiPoint3& kIntrPt);

    // support for intersection of kBox and sphere
    static float PseudoDistanceBS(float fT, void* pvData);

    // support for intersection of kBox and capsule
    static float PseudoDistanceBC(float fT, void* pvData);

    NiBox m_kBox;
};


#include "NiBoxBV.inl"

#endif
