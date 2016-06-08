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

#ifndef NIPSYSVOLUMEEMITTER_H
#define NIPSYSVOLUMEEMITTER_H

#include "NiPSysEmitter.h"

class NiTransform;

class NIPARTICLE_ENTRY NiPSysVolumeEmitter : public NiPSysEmitter
{
    NiDeclareRTTI;
    NiDeclareAbstractClone(NiPSysVolumeEmitter);
    NiDeclareAbstractStream;
    NiDeclareViewerStrings;

public:
    NiAVObject* GetEmitterObj() const;
    void SetEmitterObj(NiAVObject* pkEmitterObj);

    // *** begin NDL internal use only ***
    virtual void ProcessClone(NiCloningProcess& kCloning);
    // *** end NDL internal use only ***

protected:
    NiPSysVolumeEmitter(const char* pcName, NiAVObject* pkEmitterObj,
        float fSpeed, float fSpeedVar, 
        float fDeclination, float fDeclinationVar, 
        float fPlanarAngle, float fPlanarAngleVar,
        NiColorA kInitialColor, float fInitialRadius,
        float fLifeSpan, float fLifeSpanVar);

    // For cloning and streaming only.
    NiPSysVolumeEmitter();

    virtual void ComputeInitialPositionAndVelocity(
        NiPoint3& kPosition, NiPoint3& kVelocity);

    virtual void ComputeVolumeInitialPositionAndVelocity( 
        NiTransform& kEmitterToPSys, NiPoint3& kPosition, 
        NiPoint3& kVelocity)=0;

    // Emitter object
    NiAVObject* m_pkEmitterObj;
};

NiSmartPointer(NiPSysVolumeEmitter);

#include "NiPSysVolumeEmitter.inl"

#endif  // #ifndef NIPSYSVOLUMEEMITTER_H
