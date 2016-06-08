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

#ifndef NISPOTLIGHT_H
#define NISPOTLIGHT_H

#include "NiPointLight.h"

class NIMAIN_ENTRY NiSpotLight : public NiPointLight
{
    NiDeclareRTTI;
    NiDeclareClone(NiSpotLight);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiSpotLight();

    // The model location of the light is (0,0,0).  The world location is
    // the world translation vector.  The model direction of the light is
    // (1,0,0).  The world direction is the first column of the world
    // rotation matrix.
    const NiPoint3& GetWorldDirection() const;

    void SetSpotAngle(float fSpotAngle);
    float GetSpotAngle() const;
    void SetSpotExponent(float fSpotExponent);
    float GetSpotExponent() const;

    virtual EffectType GetEffectType() const;

protected:
    void UpdateWorldData();

    // world direction
    NiPoint3 m_kWorldDir;

    // spot cone values
    float m_fSpotAngle;
    float m_fSpotExponent;
};

typedef NiPointer<NiSpotLight> NiSpotLightPtr;

#include "NiSpotLight.inl"

#endif
