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

//---------------------------------------------------------------------------
inline bool NiParticleSystemController::GetComputeDynamicBoundPerFrame() const
{
    return(m_bStaticBound == false);
}
//---------------------------------------------------------------------------
inline void NiParticleSystemController::
    SetComputeDynamicBoundPerFrame(bool bCompute)
{
    m_bStaticBound = !bCompute;
}
//---------------------------------------------------------------------------
inline float NiParticleSystemController::GetSpeed() const
{
    return m_fSpeed;
}
//---------------------------------------------------------------------------
inline void NiParticleSystemController::SetSpeed(float fSpeed)
{
    m_fSpeed = fSpeed;
}
//---------------------------------------------------------------------------
inline float NiParticleSystemController::GetSpeedVar() const
{
    return m_fSpeedVar;
}
//---------------------------------------------------------------------------
inline void NiParticleSystemController::SetSpeedVar(float fSpeedVar)
{
    m_fSpeedVar = fSpeedVar;
}
//---------------------------------------------------------------------------
inline float NiParticleSystemController::GetDeclination() const
{
    return m_fDirDeclination;
}
//---------------------------------------------------------------------------
inline void NiParticleSystemController::SetDeclination(float fDeclination)
{
    m_fDirDeclination = fDeclination;
}
//---------------------------------------------------------------------------
inline float NiParticleSystemController::GetDeclinationVar() const
{
    return m_fDirDeclinationVar;
}
//---------------------------------------------------------------------------
inline void NiParticleSystemController::SetDeclinationVar(float fDeclinationVar)
{
    m_fDirDeclinationVar = fDeclinationVar;
}
//---------------------------------------------------------------------------
inline float NiParticleSystemController::GetPlanarAngle() const
{
    return m_fDirPlanarAngle;
}
//---------------------------------------------------------------------------
inline void NiParticleSystemController::SetPlanarAngle(float fPlanarAngle)
{
    m_fDirPlanarAngle = fPlanarAngle;
}
//---------------------------------------------------------------------------
inline float NiParticleSystemController::GetPlanarAngleVar() const
{
    return m_fDirPlanarAngleVar;
}
//---------------------------------------------------------------------------
inline void NiParticleSystemController::SetPlanarAngleVar(float fPlanarAngleVar)
{
    m_fDirPlanarAngleVar = fPlanarAngleVar;
}
//---------------------------------------------------------------------------
inline NiPoint3 NiParticleSystemController::GetInitialNormal() const
{
    return m_kInitialNormal;
}
//---------------------------------------------------------------------------
inline void NiParticleSystemController::SetInitialNormal(NiPoint3& kNormal)
{
    m_kInitialNormal = kNormal;
}
//---------------------------------------------------------------------------
inline NiColorA NiParticleSystemController::GetInitialColor() const
{
    return m_kInitialColor;
}
//---------------------------------------------------------------------------
inline void NiParticleSystemController::SetInitialColor(NiColorA& kColor)
{
    m_kInitialColor = kColor;
}
//---------------------------------------------------------------------------
inline float NiParticleSystemController::GetInitialSize() const
{
    return m_fInitialSize;
}
//---------------------------------------------------------------------------
inline void NiParticleSystemController::SetInitialSize(float fSize,
    bool bApplyToExistingParticles)
{
    m_fInitialSize = fSize;

    if (bApplyToExistingParticles)
    {
        // Set existing particle radii.
        float* pfRadii = ((NiParticles*) m_pTarget)->GetRadii();
        for (unsigned short us = 0;
            us < ((NiParticles*) m_pTarget)->GetVertexCount(); us++)
        {
            pfRadii[us] = m_fInitialSize;
        }
    }
}
//---------------------------------------------------------------------------
inline float NiParticleSystemController::GetEmitStart() const
{
    return m_fEmitStart;
}
//---------------------------------------------------------------------------
inline void NiParticleSystemController::SetEmitStart(float fEmitStart)
{
    m_fEmitStart = fEmitStart;
}
//---------------------------------------------------------------------------
inline float NiParticleSystemController::GetEmitStop() const
{
    return m_fEmitStop;
}
//---------------------------------------------------------------------------
inline void NiParticleSystemController::SetEmitStop(float fEmitStop)
{
    m_fEmitStop = fEmitStop;
}
//---------------------------------------------------------------------------
inline bool NiParticleSystemController::GetResetParticleSystem() const
{
    return m_bReset;
}
//---------------------------------------------------------------------------
inline void NiParticleSystemController::SetResetParticleSystem(bool bReset)
{
    m_bReset = bReset;
}
//---------------------------------------------------------------------------
inline float NiParticleSystemController::GetBirthRate() const
{
    return m_fBirthRate;
}
//---------------------------------------------------------------------------
inline void NiParticleSystemController::SetBirthRate(float fBirthRate)
{
    m_fBirthRate = fBirthRate;
}
//---------------------------------------------------------------------------
inline float NiParticleSystemController::GetLifeSpan() const
{
    return m_fLifeSpan;
}
//---------------------------------------------------------------------------
inline void NiParticleSystemController::SetLifeSpan(float fLifeSpan)
{
    m_fLifeSpan = fLifeSpan;
}
//---------------------------------------------------------------------------
inline float NiParticleSystemController::GetLifeSpanVar() const
{
    return m_fLifeSpanVar;
}
//---------------------------------------------------------------------------
inline void NiParticleSystemController::SetLifeSpanVar(float fLifeSpanVar)
{
    m_fLifeSpanVar = fLifeSpanVar;
}
//---------------------------------------------------------------------------
inline bool NiParticleSystemController::GetUseBirthRate() const
{
    return m_bUseBirthRate;
}
//---------------------------------------------------------------------------
inline void NiParticleSystemController::SetUseBirthRate(bool bUseBirthRate)
{
    m_bUseBirthRate = bUseBirthRate;
}
//---------------------------------------------------------------------------
inline bool NiParticleSystemController::GetSpawnOnDeath() const
{
    return m_bSpawnOnDeath;
}
//---------------------------------------------------------------------------
inline void NiParticleSystemController::SetSpawnOnDeath(bool bSpawn)
{
    m_bSpawnOnDeath = bSpawn;
}
//---------------------------------------------------------------------------
inline float NiParticleSystemController::GetEmitterWidth() const
{
    return m_fEmitterWidth;
}
//---------------------------------------------------------------------------
inline void NiParticleSystemController::SetEmitterWidth(float fEmitterWidth)
{
    m_fEmitterWidth = fEmitterWidth;
}
//---------------------------------------------------------------------------
inline float NiParticleSystemController::GetEmitterHeight() const
{
    return m_fEmitterHeight;
}
//---------------------------------------------------------------------------
inline void NiParticleSystemController::SetEmitterHeight(float fEmitterHeight)
{
    m_fEmitterHeight = fEmitterHeight;
}
//---------------------------------------------------------------------------
inline float NiParticleSystemController::GetEmitterDepth() const
{
    return m_fEmitterDepth;
}
//---------------------------------------------------------------------------
inline void NiParticleSystemController::SetEmitterDepth(float fEmitterDepth)
{
    m_fEmitterDepth = fEmitterDepth;
}
//---------------------------------------------------------------------------
inline NiAVObject* NiParticleSystemController::GetEmitter() const
{
    return m_pkEmitter;
}
//---------------------------------------------------------------------------
inline void NiParticleSystemController::SetEmitter(NiAVObject* pkEmitter)
{
    m_pkEmitter = pkEmitter;
}
//---------------------------------------------------------------------------
inline unsigned short NiParticleSystemController::GetNumSpawnGenerations() 
    const
{
    return m_usNumGenerations;
}
//---------------------------------------------------------------------------
inline void NiParticleSystemController::SetNumSpawnGenerations(
    unsigned short usNumGenerations)
{
    m_usNumGenerations = usNumGenerations;
}
//---------------------------------------------------------------------------
inline float NiParticleSystemController::GetPercentageSpawned() const
{
    return m_fPercentageSpawned;
}
//---------------------------------------------------------------------------
inline void NiParticleSystemController::SetPercentageSpawned(
    float fPercentageSpawned)
{
    m_fPercentageSpawned = fPercentageSpawned;
}
//---------------------------------------------------------------------------
inline unsigned short NiParticleSystemController::GetSpawnMultiplier() const
{
    return m_usMultiplier;
}
//---------------------------------------------------------------------------
inline void NiParticleSystemController::SetSpawnMultiplier(
    unsigned short usMultiplier)
{
    m_usMultiplier = usMultiplier;
}
//---------------------------------------------------------------------------
inline float NiParticleSystemController::GetSpawnedSpeedChaos() const
{
    return m_fSpeedChaos;
}
//---------------------------------------------------------------------------
inline void NiParticleSystemController::SetSpawnedSpeedChaos(float fSpeedChaos)
{
    m_fSpeedChaos = fSpeedChaos;
}
//---------------------------------------------------------------------------
inline float NiParticleSystemController::GetSpawnedDirChaos() const
{
    return m_fDirChaos;
}
//---------------------------------------------------------------------------
inline void NiParticleSystemController::SetSpawnedDirChaos(float fDirChaos)
{
    m_fDirChaos = fDirChaos;
}
//---------------------------------------------------------------------------
inline NiPoint3* NiParticleSystemController::GetParticlePosition(
    unsigned short usIndex)
{
    return ((NiParticles*)m_pTarget)->GetModelData()->GetVertices() + usIndex;
}
//---------------------------------------------------------------------------
inline bool NiParticleSystemController::IsVertexController() const
{
    return true;
}
//---------------------------------------------------------------------------
inline bool NiParticleSystemController::TargetIsRequiredType () const
{
    return NiIsKindOf(NiParticles,m_pTarget);
}
//---------------------------------------------------------------------------
inline NiEmitterModifier* NiParticleSystemController::GetEmitterModifiers()
{
    return m_spEmitterModifiers;
}
//---------------------------------------------------------------------------
inline NiParticleModifier* NiParticleSystemController::GetParticleModifiers()
{
    return m_spParticleModifiers;
}
//---------------------------------------------------------------------------
inline NiParticleCollider* NiParticleSystemController::GetParticleColliders()
{
    return m_spParticleColliders;
}
//---------------------------------------------------------------------------
