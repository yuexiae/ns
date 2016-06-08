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

#ifndef NIPARTICLESYSTEMCONTROLLER_H
#define NIPARTICLESYSTEMCONTROLLER_H

#include "NiOldParticleLibType.h"
#include <NiTimeController.h>
#include <NiBound.h>
#include <NiParticles.h>
#include <NiColor.h>
#include <NiPoint3.h>

#include "NiPerParticleData.h"
#include "NiParticleCollider.h"
#include "NiEmitterModifier.h"

class NIOLDPARTICLE_ENTRY NiParticleSystemController : public NiTimeController
{
    NiDeclareRTTI;
    NiDeclareClone(NiParticleSystemController);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiParticleSystemController();
    virtual ~NiParticleSystemController();

    // control dynamic bound calculation -- default is false
    bool GetComputeDynamicBoundPerFrame() const;
    void SetComputeDynamicBoundPerFrame(bool bCompute);

    // shared data access
    float GetSpeed() const;
    void SetSpeed(float fSpeed);

    float GetSpeedVar() const;
    void SetSpeedVar(float fSpeedVar);

    float GetDeclination() const;
    void SetDeclination(float fDeclination);

    float GetDeclinationVar() const;
    void SetDeclinationVar(float fDeclinationVar);

    float GetPlanarAngle() const;
    void SetPlanarAngle(float fPlanarAngle);

    float GetPlanarAngleVar() const;
    void SetPlanarAngleVar(float fPlanarAngleVar);

    NiPoint3 GetInitialNormal() const;
    void SetInitialNormal(NiPoint3& kNormal);
    
    NiColorA GetInitialColor() const;
    void SetInitialColor(NiColorA& kColor);

    float GetInitialSize() const;
    void SetInitialSize(float fSize, bool bApplyToExistingParticles = false);

    float GetEmitStart() const;
    void SetEmitStart(float fEmitStart);

    float GetEmitStop() const;
    void SetEmitStop(float fEmitStop);

    bool GetResetParticleSystem() const;
    void SetResetParticleSystem(bool bReset);

    float GetBirthRate() const;
    void SetBirthRate(float fBirthRate);

    float GetLifeSpan() const;
    void SetLifeSpan(float fLifeSpan);

    float GetLifeSpanVar() const;
    void SetLifeSpanVar(float fLifeSpanVar);

    bool GetUseBirthRate() const;
    void SetUseBirthRate(bool bUseBirthRate);

    bool GetSpawnOnDeath() const;
    void SetSpawnOnDeath(bool bSpawn);

    float GetEmitterWidth() const;
    void SetEmitterWidth(float fEmitterWidth);

    float GetEmitterHeight() const;
    void SetEmitterHeight(float fEmitterHeight);

    float GetEmitterDepth() const;
    void SetEmitterDepth(float fEmitterDepth);

    NiAVObject* GetEmitter() const;
    void SetEmitter(NiAVObject* pkEmitter);

    unsigned short GetNumSpawnGenerations() const;
    void SetNumSpawnGenerations(unsigned short usNumGenerations);

    float GetPercentageSpawned() const;
    void SetPercentageSpawned(float fPercentageSpawned);

    unsigned short GetSpawnMultiplier() const;
    void SetSpawnMultiplier(unsigned short usMultiplier);
    
    float GetSpawnedSpeedChaos() const;
    void SetSpawnedSpeedChaos(float fSpeedChaos);
    
    float GetSpawnedDirChaos() const;
    void SetSpawnedDirChaos(float fDirChaos);

    // updates
    virtual void Update(float fTime);

    void Reset();

    // *** begin NDL internal use only ***

    virtual void SetTarget(NiObjectNET* pTarget);

    NiPoint3* GetParticlePosition(unsigned short usIndex);

    void ComputeStaticTargetBound();

    virtual void PostLinkObject(NiStream& kStream);

    virtual bool IsVertexController() const;

    NiEmitterModifier* GetEmitterModifiers();
    NiParticleModifier* GetParticleModifiers();
    NiParticleCollider* GetParticleColliders();

    // cloning
    virtual void ProcessClone(NiCloningProcess& kCloning);

    // *** end NDL internal use only ***

protected:
    friend class NiParticleCollider;
    friend class NiParticleModifier;
    friend class NiEmitterModifier;

    NiPerParticleData* GetFirstParticle();
    NiPerParticleData* GetNextParticle();

    void UpdateParticles(float fTime);
    void ParticleUpdate(float fTime, float fTimeModifier, 
        NiPerParticleData* pkCurrentParticle,
        NiParticlesData* pkParticlesData, bool bNewParticle = false);
    void RemoveParticle(NiPerParticleData* pkOldParticle);
    void SpawnParticles(float fTime, float fSpawnTime, 
        NiPerParticleData* pkOldParticle);
    NiPerParticleData* AddNewParticle(float fTime, float fLastTime, 
        const NiMatrix3& kTargetToEmtterRotate, const NiPoint3& kTargetAccum,
        NiPerParticleData* pkOldParticle = NULL);

    float m_fScaledLastTime;

    // Initial speed values for particles
    float m_fSpeed;
    float m_fSpeedVar;
    float m_fDirDeclination;
    float m_fDirDeclinationVar;
    float m_fDirPlanarAngle;
    float m_fDirPlanarAngleVar;

    NiPoint3 m_kInitialNormal;
    NiColorA m_kInitialColor;
    float m_fInitialSize;

    // Emitter times
    float m_fEmitStart;
    float m_fEmitStop;
    bool m_bReset;

    // Particle creation/destruction
    float m_fBirthRate;
    float m_fLifeSpan;
    float m_fLifeSpanVar;
    bool m_bUseBirthRate;
    bool m_bSpawnOnDeath;

    // Emitter size
    float m_fEmitterWidth;
    float m_fEmitterHeight;
    float m_fEmitterDepth;

    NiAVObject* m_pkEmitter;

    // Spawn variables
    unsigned short m_usNumGenerations;
    float m_fPercentageSpawned;
    unsigned short m_usMultiplier;
    float m_fSpeedChaos;
    float m_fDirChaos;

    unsigned short m_usNumParticles;
    unsigned short m_usNumActiveParticles;
    unsigned short m_usCurrentParticle;
    NiPerParticleData* m_pkParticles;

    NiEmitterModifierPtr m_spEmitterModifiers;

    NiParticleModifierPtr m_spParticleModifiers;
    NiParticleColliderPtr m_spParticleColliders;

    NiBool m_bStaticBound;
    NiBound m_kStaticModelBound;

    bool m_bFirstTime;
    float m_fLastEmit;

    static const float ms_fEpsilon;

    // debugging
    virtual bool TargetIsRequiredType() const;
};

NiSmartPointer(NiParticleSystemController);

#include "NiParticleSystemController.inl"

#endif  // #ifndef NIPARTICLESYSTEMCONTROLLER_H
