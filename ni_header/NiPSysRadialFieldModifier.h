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

#ifndef NIPSYSRADIALFIELDMODIFIER_H
#define NIPSYSRADIALFIELDMODIFIER_H

#include "NiPSysFieldModifier.h"
#include "NiPoint3.h"

class NiAVObject;

class NIPARTICLE_ENTRY NiPSysRadialFieldModifier : public NiPSysFieldModifier
{
    NiDeclareRTTI;
    NiDeclareClone(NiPSysRadialFieldModifier);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiPSysRadialFieldModifier(const char* pcName, NiAVObject* pkFieldObj, 
        float fMagnitude, float fAttenuation, bool bUseMaxDistance,
        float fMaxDistance, float fRadialType);

    virtual void Update(float fTime, NiPSysData* pkData);

    float GetRadialType() const;
    void SetRadialType(float fRadialType);

    // *** begin NDL internal use only ***
    virtual void ProcessClone(NiCloningProcess& kCloning);
    // *** end NDL internal use only ***

protected:
    // For cloning and streaming only.
    NiPSysRadialFieldModifier();

    // Optimized Update Functions
    void UpdateNoAttenuationNoDirNoDist(float fTime, NiPSysData* pkData);

    float m_fRadialType;

};

NiSmartPointer(NiPSysRadialFieldModifier);

#include "NiPSysRadialFieldModifier.inl"

#endif  // #ifndef NIPSYSRADIALFIELDMODIFIER_H
