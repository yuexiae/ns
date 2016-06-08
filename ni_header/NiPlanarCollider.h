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

#ifndef NIPLANARCOLLIDER_H
#define NIPLANARCOLLIDER_H

#include "NiParticleCollider.h"
#include <NiPoint3.h>
#include <NiPlane.h>

class NIOLDPARTICLE_ENTRY NiPlanarCollider : public NiParticleCollider
{
    NiDeclareRTTI;
    NiDeclareClone(NiPlanarCollider);
    NiDeclareStream;
public:
    // construction
    NiPlanarCollider();
    
    // attributes
    void SetHeight(float fHeight);
    float GetHeight() const;

    void SetWidth(float fWidth);
    float GetWidth() const;

    void SetPos(const NiPoint3& kPos);
    const NiPoint3& GetPos() const;

    void SetPlane(const NiPoint3& kNorm, float fD);
    void SetXVec(const NiPoint3& kXVec);
    void SetYVec(const NiPoint3& kYVec);
    const NiPoint3& GetXVec() const;
    const NiPoint3& GetYVec() const;
    
    float GetD() const;
    const NiPoint3& GetNorm() const;
    
    // *** begin NDL internal use only ***

    virtual NiParticleCollider* Resolve(float fInitialTime, 
        float& fCollisionTime, NiPerParticleData* pkCurrentParticle);

    virtual bool Update(float fTime, NiPerParticleData* pkCurrentParticle);

    // *** end NDL internal use only ***

protected:
    float m_fHeight;
    float m_fWidth;

    NiPlane m_kPlane;

    NiPoint3 m_kPosition;
    NiPoint3 m_kXAxis;
    NiPoint3 m_kYAxis;
};

//---------------------------------------------------------------------------
#include "NiPlanarCollider.inl"

//---------------------------------------------------------------------------
#endif
