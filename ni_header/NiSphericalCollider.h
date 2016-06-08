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

#ifndef NISPHERICALCOLLIDER_H
#define NISPHERICALCOLLIDER_H

#include "NiParticleCollider.h"
#include <NiPoint3.h>

class NIOLDPARTICLE_ENTRY NiSphericalCollider : public NiParticleCollider
{
    NiDeclareRTTI;
    NiDeclareClone(NiSphericalCollider);
    NiDeclareStream;
public:
    // construction
    NiSphericalCollider ();
    
    // attributes
    void SetRadius(float fRadius);
    float GetRadius() const;

    void SetPos(const NiPoint3& kPos);
    const NiPoint3& GetPos() const;
    
    // *** begin NDL internal use only ***

    virtual NiParticleCollider* Resolve(float fInitialTime, 
        float& fCollisionTime, NiPerParticleData* pkCurrentParticle);

    virtual bool Update(float fTime, NiPerParticleData* pkCurrentParticle);

    // *** end NDL internal use only ***

protected:
    float m_fRadius;
    float m_fRadiusSq;
    NiPoint3 m_kPosition;
};

//---------------------------------------------------------------------------
#include "NiSphericalCollider.inl"

//---------------------------------------------------------------------------
#endif
