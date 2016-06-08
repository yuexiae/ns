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

#ifndef NISPHEREBV_H
#define NISPHEREBV_H

#include "NiBoundingVolume.h"
#include "NiSphere.h"
#include "NiPoint3.h"

class NICOLLISION_ENTRY NiSphereBV : public NiBoundingVolume
{
    NiDeclareBVStream;
public:

    NiSphereBV(const float fRadius = 1.0f, const NiPoint3& kCenter = 
        NiPoint3::ZERO);
    NiSphereBV(const NiSphereBV& kABV);
    
    void SetSphere(const NiSphere& kSphere);
    const NiSphere& GetSphere() const;
    
    void SetCenter(const NiPoint3& kCenter);
    const NiPoint3& GetCenter() const;
    
    void SetRadius(float fRadius);
    float GetRadius() const;
    
    // run-time type information
    virtual int Type() const;

    // *** begin NDL internal use only ***
    static NiBoundingVolume* ConvertLozengeToSphereBoundingVolume(
        NiStream& kStream);

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
    static bool SphereSphereTestIntersect(float fTime,
        const NiBoundingVolume& kABV0, const NiPoint3& kV0, 
        const NiBoundingVolume& kABV1, const NiPoint3& kV1);

    static bool SphereTriTestIntersect(float fTime,
        const NiBoundingVolume& kABV0, const NiPoint3& kV0, 
        const NiPoint3& kVert0, const NiPoint3& kVert1, 
        const NiPoint3& kVert2, const NiPoint3& kV1);

    // 'find' functions
    static bool SphereSphereFindIntersect(float fTime,
        const NiBoundingVolume& kABV0, const NiPoint3& kV0, 
        const NiBoundingVolume& pBV1, const NiPoint3& kV1,
        float& fIntrTime, NiPoint3& kIntrPt, bool bCalcNormals,
        NiPoint3& kNormal0, NiPoint3& kNormal1);

    static bool SphereTriFindIntersect(float fTime,
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
    // support for intersection of kSphere and triangle
    static float PseudoDistance(float fT, void* pvData);

    NiSphere m_kSphere;
};

#include "NiSphereBV.inl"

#endif

