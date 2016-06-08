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

#ifndef NICAPSULEBV_H
#define NICAPSULEBV_H

#include "NiBoundingVolume.h"
#include "NiCapsule.h"
#include "NiPoint3.h"

class NICOLLISION_ENTRY NiCapsuleBV : public NiBoundingVolume
{
    NiDeclareBVStream;
public:
    NiCapsuleBV(float fRadius = 1.0f, float fExtent = 1.0f, 
        NiPoint3 kCenter = NiPoint3::ZERO, NiPoint3 kAxis = NiPoint3::UNIT_X);
    NiCapsuleBV(const NiCapsuleBV& kABV);
    
    void SetCenter(const NiPoint3& kCenter);
    const NiPoint3& GetCenter() const;
    
    void SetAxis(const NiPoint3& kAxis);
    const NiPoint3& GetAxis() const;

    void SetExtent(const float fExtent);
    float GetExtent() const;
    
    void SetRadius(const float fRadius);
    float GetRadius() const;

    // run-time type information
    virtual int Type() const;


    // *** begin NDL internal use only ***

    // capsule access functions
    const NiCapsule& GetCapsule() const;
    const NiSegment& GetSegment() const;
    const NiPoint3& GetOrigin() const;
    const NiPoint3& GetDirection() const;
    
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
    static bool CapsuleSphereTestIntersect(float fTime,
        const NiBoundingVolume& kABV0, const NiPoint3& kV0, 
        const NiBoundingVolume& kABV1, const NiPoint3& kV1);
    
    static bool CapsuleCapsuleTestIntersect(float fTime,
        const NiBoundingVolume& kABV0, const NiPoint3& kV0, 
        const NiBoundingVolume& kABV1, const NiPoint3& kV1);
           
    static bool CapsuleTriTestIntersect(float fTime,
        const NiBoundingVolume& kABV0, const NiPoint3& kV0, 
        const NiPoint3& kVert0, const NiPoint3& kVert1, 
        const NiPoint3& kVert2, const NiPoint3& kV1);

    // 'find' functions
    static bool CapsuleSphereFindIntersect(float fTime,
        const NiBoundingVolume& kABV0, const NiPoint3& kV0, 
        const NiBoundingVolume& pBV1, const NiPoint3& kV1,
        float& fIntrTime, NiPoint3& kIntrPt, bool bCalcNormals,
        NiPoint3& kNormal0, NiPoint3& kNormal1);
    
    static bool CapsuleCapsuleFindIntersect(float fTime,
        const NiBoundingVolume& kABV0, const NiPoint3& kV0, 
        const NiBoundingVolume& pBV1, const NiPoint3& kV1,
        float& fIntrTime, NiPoint3& kIntrPt, bool bCalcNormals,
        NiPoint3& kNormal0, NiPoint3& kNormal1);
    
    static bool CapsuleTriFindIntersect(float fTime,
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
    // support for intersection of sphere and triangle
    static float PseudoDistance(float fT, void* pvData);
    void CalculateCapsule();

    NiPoint3 m_kCenter;
    NiPoint3 m_kAxis;
    float m_fExtent;

    NiCapsule m_kCapsule;
};

#include "NiCapsuleBV.inl"

#endif

