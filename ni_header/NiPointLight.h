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

#ifndef NIPOINTLIGHT_H
#define NIPOINTLIGHT_H

#include "NiBool.h"
#include "NiLight.h"
#include "NiPoint3.h"


class NIMAIN_ENTRY NiPointLight : public NiLight
{
    NiDeclareRTTI;
    NiDeclareClone(NiPointLight);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiPointLight();

    // The model location of the light is (0,0,0).  The world location is
    // the world translation vector.
    const NiPoint3& GetWorldLocation() const;

    void SetConstantAttenuation(float fC);
    float GetConstantAttenuation() const;
    void SetLinearAttenuation(float fL);
    float GetLinearAttenuation() const;
    void SetQuadraticAttenuation(float fQ);
    float GetQuadraticAttenuation() const;

    virtual EffectType GetEffectType() const;

protected:
    void UpdateWorldData();

    // attenuation
    float m_fAtten0;
    float m_fAtten1;
    float m_fAtten2;
};


typedef NiPointer<NiPointLight> NiPointLightPtr;

#include "NiPointLight.inl"

#endif
