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

#ifndef NIPSYSROTATIONMODIFIER_H
#define NIPSYSROTATIONMODIFIER_H

#include "NiPSysModifier.h"
#include <NiPoint3.h>

class NIPARTICLE_ENTRY NiPSysRotationModifier : public NiPSysModifier
{
    NiDeclareRTTI;
    NiDeclareClone(NiPSysRotationModifier);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiPSysRotationModifier(const char* pcName, float fRotationSpeed = 0.0f,
        bool bRandomInitialAxis = true,
        NiPoint3 kInitialAxis = NiPoint3::UNIT_X);

    virtual void Update(float fTime, NiPSysData* pkData);
    virtual void Initialize(NiPSysData* pkData, unsigned short usNewParticle);

    float GetRotationSpeed() const;
    void SetRotationSpeed(float fRotationSpeed);

    bool GetRandomInitialAxis() const;
    void SetRandomInitialAxis(bool bRandomInitialAxis);

    const NiPoint3& GetInitialAxis() const;
    void SetInitialAxis(const NiPoint3& kInitialAxis);

protected:
    // For cloning and streaming only.
    NiPSysRotationModifier();

    float m_fRotationSpeed;
    bool m_bRandomInitialAxis;
    NiPoint3 m_kInitialAxis;
};

NiSmartPointer(NiPSysRotationModifier);

#include "NiPSysRotationModifier.inl"

#endif  // #ifndef NIPSYSROTATIONMODIFIER_H
