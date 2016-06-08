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

#ifndef NIPSYSSPHERICALCOLLIDER_H
#define NIPSYSSPHERICALCOLLIDER_H

#include "NiPSysCollider.h"
#include <NiTransform.h>

class NIPARTICLE_ENTRY NiPSysSphericalCollider : public NiPSysCollider
{
    NiDeclareRTTI;
    NiDeclareClone(NiPSysSphericalCollider);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiPSysSphericalCollider(float fBounce = 1.0f, bool bSpawnOnCollide = false,
        bool bDieOnCollide = false,
        NiPSysSpawnModifier* pkSpawnModifier = NULL,
        NiAVObject* pkColliderObj = NULL, float fRadius = 1.0f);

    virtual NiPSysCollider* Resolve(float fInitialTime, float& fCollisionTime,
        NiPSysData* pkData, unsigned short usCurParticle);
    virtual void Update(float fTime, NiPSysData* pkData,
        unsigned short usCurParticle);
    virtual void SetResolveConstants();


    NiAVObject* GetColliderObj() const;
    void SetColliderObj(NiAVObject* pkColliderObj);

    float GetRadius() const;
    void SetRadius(float fRadius);

    // *** begin NDL internal use only ***
    void ProcessClone(NiCloningProcess& kCloning);
    // *** end NDL internal use only ***

protected:
    NiAVObject* m_pkColliderObj;
    float m_fRadius;

    float m_fScaledRadius;
    float m_fRadiusSq;
    NiPoint3 m_kPosition;

    NiTransform m_kLastColliderTransform;
    NiTransform m_kLastPSysTransform;
};

NiSmartPointer(NiPSysSphericalCollider);

#include "NiPSysSphericalCollider.inl"

#endif  // #ifndef NIPSYSSPHERICALCOLLIDER_H
