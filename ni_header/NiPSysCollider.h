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

#ifndef NIPSYSCOLLIDER_H
#define NIPSYSCOLLIDER_H

#include "NiParticleLibType.h"
#include <NiObject.h>
#include <NiPoint3.h>

class NiPSysData;
class NiPSysSpawnModifier;
class NiPSysColliderManager;

NiSmartPointer(NiPSysCollider);

class NIPARTICLE_ENTRY NiPSysCollider : public NiObject
{
    NiDeclareRTTI;
    NiDeclareAbstractClone(NiPSysCollider);
    NiDeclareAbstractStream;
    NiDeclareViewerStrings;

public:
    virtual NiPSysCollider* Resolve(float fInitialTime, float& fCollisionTime,
        NiPSysData* pkData, unsigned short usCurParticle) = 0;
    virtual void Update(float fTime, NiPSysData* pkData,
        unsigned short usCurParticle);
    virtual void SetResolveConstants() = 0;

    float GetBounce() const;
    void SetBounce(float fBounce);

    bool GetSpawnOnCollide() const;
    void SetSpawnOnCollide(bool bSpawnOnCollide);

    bool GetDieOnCollide() const;
    void SetDieOnCollide(bool bDieOnCollide);

    NiPSysSpawnModifier* GetSpawnModifier() const;
    void SetSpawnModifier(NiPSysSpawnModifier* pkSpawnModifier);

    NiPSysColliderManager* GetManager() const;

    NiPSysCollider* GetNext() const;

    // *** begin NDL internal use only ***
    void SetNext(NiPSysCollider* pkNext);
    void SetManager(NiPSysColliderManager* pkManager);
    void ProcessClone(NiCloningProcess& kCloning);
    // *** end NDL internal use only ***

protected:
    NiPSysCollider(float fBounce, bool bSpawnOnCollide, bool bDieOnCollide,
        NiPSysSpawnModifier* pkSpawnModifier);

    // For streaming and cloning only.
    NiPSysCollider();

    float m_fBounce;
    bool m_bSpawnOnCollide;
    bool m_bDieOnCollide;
    NiPSysSpawnModifier* m_pkSpawnModifier;
    
    NiPoint3 m_kCollisionPoint;
    float m_fCollisionTime;

    NiPSysColliderManager* m_pkManager;
    NiPSysColliderPtr m_spNext;
};

#include "NiPSysCollider.inl"

#endif  // #ifndef NIPSYSCOLLIDER_H
