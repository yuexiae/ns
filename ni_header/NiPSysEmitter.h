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

#ifndef NIPSYSEMITTER_H
#define NIPSYSEMITTER_H

#include "NiPSysModifier.h"
#include <NiPoint3.h>
#include <NiColor.h>

class NiParticleInfo;

class NIPARTICLE_ENTRY NiPSysEmitter : public NiPSysModifier
{
    NiDeclareRTTI;
    NiDeclareAbstractClone(NiPSysEmitter);
    NiDeclareAbstractStream;
    NiDeclareViewerStrings;

public:
    virtual void Update(float fTime, NiPSysData* pkData);

    virtual void EmitParticles(float fTime, unsigned short usNumParticles,
        const float* pfAges);

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

    NiColorA GetInitialColor() const;
    void SetInitialColor(const NiColorA& kInitialColor);

    float GetInitialRadius() const;
    void SetInitialRadius(float fInitialRadius);

    float GetLifeSpan() const;
    void SetLifeSpan(float fLifeSpan);

    float GetLifeSpanVar() const;
    void SetLifeSpanVar(float fLifeSpanVar);

protected:
    NiPSysEmitter(const char* pcName, unsigned int uiOrder, float fSpeed,
        float fSpeedVar, float fDeclination, float fDeclinationVar,
        float fPlanarAngle, float fPlanarAngleVar, NiColorA kInitialColor,
        float fInitialRadius, float fLifeSpan, float fLifeSpanVar);

    // For cloning and streaming only.
    NiPSysEmitter();

    virtual void ComputeInitialPositionAndVelocity(
        NiPoint3& kPosition, NiPoint3& kVelocity) = 0;

    // Initial values for particles.
    float m_fSpeed;
    float m_fSpeedVar;
    float m_fDeclination;
    float m_fDeclinationVar;
    float m_fPlanarAngle;
    float m_fPlanarAngleVar;
    NiColorA m_kInitialColor;
    float m_fInitialRadius;
    float m_fLifeSpan;
    float m_fLifeSpanVar;
};

NiSmartPointer(NiPSysEmitter);

#include "NiPSysEmitter.inl"

#endif  // #ifndef NIPSYSEMITTER_H
