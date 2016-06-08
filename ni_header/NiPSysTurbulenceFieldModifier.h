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

#ifndef NIPSYSTURBULENCEFIELDMODIFIER_H
#define NIPSYSTURBULENCEFIELDMODIFIER_H

#include "NiPSysFieldModifier.h"
#include "NiPoint3.h"

class NiAVObject;

class NIPARTICLE_ENTRY NiPSysTurbulenceFieldModifier : public NiPSysFieldModifier
{
    NiDeclareRTTI;
    NiDeclareClone(NiPSysTurbulenceFieldModifier);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiPSysTurbulenceFieldModifier(const char* pcName, NiAVObject* pkFieldObj, 
        float fMagnitude, float fAttenuation, bool bUseMaxDistance,
        float fMaxDistance, float fFrequency);

    virtual void Update(float fTime, NiPSysData* pkData);

    // Turbulence updates per second.
    const float GetFrequency() const;
    void SetFrequency(float fFrequency);

    // *** begin NDL internal use only ***
    virtual void ProcessClone(NiCloningProcess& kCloning);
    // *** end NDL internal use only ***

protected:
    // For cloning and streaming only.
    NiPSysTurbulenceFieldModifier();

    // Optimized Update Functions
    void UpateNoAttenuationNoDistance(float fTime, NiPSysData* pkData);
    void UpateNoAttenuation(float fTime, NiPSysData* pkData);

    // Turbulence updates per second.
    float m_fFrequency;

    // Internal Data
    float m_fFrequencyUpdateTime;
    float m_fLastUpdateTime;
};

NiSmartPointer(NiPSysTurbulenceFieldModifier);

#include "NiPSysTurbulenceFieldModifier.inl"

#endif  // #ifndef NIPSYSTURBULENCEFIELDMODIFIER_H
