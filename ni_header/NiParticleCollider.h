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

#ifndef NIPARTICLECOLLIDER_H
#define NIPARTICLECOLLIDER_H

#include "NiParticleModifier.h"

NiSmartPointer(NiParticleCollider);

class NIOLDPARTICLE_ENTRY NiParticleCollider : public NiParticleModifier
{
    NiDeclareRTTI;
    NiDeclareAbstractClone(NiParticleCollider);
    NiDeclareAbstractStream;
public:
    // construction
    NiParticleCollider ();
    
    // attributes
    float GetBounce() const;
    void SetBounce(float fBounce);

    bool GetSpawnOnCollide() const;
    void SetSpawnOnCollide(bool bSpawn);

    bool GetDieOnCollide() const;
    void SetDieOnCollide(bool bDie);
    
    // *** begin NDL internal use only ***

    virtual void AddToTarget(NiParticleSystemController* pkTarget);
    virtual void RemoveFromTarget(NiParticleSystemController* pkTarget);

    virtual NiParticleCollider* Resolve(float fInitialTime, 
        float& fCollisionTime, NiPerParticleData* pkCurrentParticle) = 0;

    virtual bool Update(float fTime,NiPerParticleData* pkCurrentParticle);

    // Colliders should not initialize anything
    virtual void Initialize(NiPerParticleData* pkCurrentParticle) {/**/};

    // *** end NDL internal use only ***

protected:
    float m_fBounce;

    bool m_bSpawnOnCollide;
    bool m_bDieOnCollide;
    
    NiPoint3 m_kCollisionPoint;
    float m_fCollisionTime;
};

#include "NiParticleCollider.inl"

#endif // NIPARTICLECOLLIDER_H
