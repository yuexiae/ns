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

#ifndef NIPSYSBOXEMITTER_H
#define NIPSYSBOXEMITTER_H

#include "NiPSysVolumeEmitter.h"

class NIPARTICLE_ENTRY NiPSysBoxEmitter : public NiPSysVolumeEmitter
{
    NiDeclareRTTI;
    NiDeclareClone(NiPSysBoxEmitter);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiPSysBoxEmitter(const char* pcName, NiAVObject* pkEmitterObj,
        float fEmitterWidth = 0.0f, float fEmitterHeight = 0.0f,
        float fEmitterDepth = 0.0f, float fSpeed = 0.0f,
        float fSpeedVar = 0.0f, float fDeclination = 0.0f,
        float fDeclinationVar = 0.0f, float fPlanarAngle = 0.0f,
        float fPlanarAngleVar = 0.0f,
        NiColorA kInitialColor = NiColorA::WHITE, float fInitialRadius = 1.0f,
        float fLifeSpan = 0.0f, float fLifeSpanVar = 0.0f);

    float GetEmitterWidth() const;
    void SetEmitterWidth(float fEmitterWidth);

    float GetEmitterHeight() const;
    void SetEmitterHeight(float fEmitterHeight);

    float GetEmitterDepth() const;
    void SetEmitterDepth(float fEmitterDepth);

    // *** begin NDL internal use only ***
    virtual void ProcessClone(NiCloningProcess& kCloning);
    // *** end NDL internal use only ***

protected:
    // For cloning and streaming only.
    NiPSysBoxEmitter();

    virtual void ComputeVolumeInitialPositionAndVelocity(
        NiTransform& kEmitterToPSys, NiPoint3& kPosition, 
        NiPoint3& kVelocity);

    // Emitter size.
    float m_fEmitterWidth;
    float m_fEmitterHeight;
    float m_fEmitterDepth;
};

NiSmartPointer(NiPSysBoxEmitter);

#include "NiPSysBoxEmitter.inl"

#endif  // #ifndef NIPSYSBoxEMITTER_H
