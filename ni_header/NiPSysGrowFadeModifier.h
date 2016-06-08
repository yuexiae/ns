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

#ifndef NIPSYSGROWFADEMODIFIER_H
#define NIPSYSGROWFADEMODIFIER_H

#include "NiPSysModifier.h"

class NIPARTICLE_ENTRY NiPSysGrowFadeModifier : public NiPSysModifier
{
    NiDeclareRTTI;
    NiDeclareClone(NiPSysGrowFadeModifier);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiPSysGrowFadeModifier(const char* pcName, float fGrowTime = 0.0f,
        unsigned short usGrowGeneration = 0, float fFadeTime = 0.0f,
        unsigned short usFadeGeneration = 0);

    virtual void Update(float fTime, NiPSysData* pkData);

    float GetGrowTime() const;
    void SetGrowTime(float fGrowTime);

    unsigned short GetGrowGeneration() const;
    void SetGrowGeneration(unsigned short usGrowGeneration);

    float GetFadeTime() const;
    void SetFadeTime(float fFadeTime);

    unsigned short GetFadeGeneration() const;
    void SetFadeGeneration(unsigned short usFadeGeneration);

protected:
    // For cloning and streaming only.
    NiPSysGrowFadeModifier();

    float m_fGrowTime;
    unsigned short m_usGrowGeneration;

    float m_fFadeTime;
    unsigned short m_usFadeGeneration;
};

NiSmartPointer(NiPSysGrowFadeModifier);

#include "NiPSysGrowFadeModifier.inl"

#endif  // #ifndef NIPSYSGROWFADEMODIFIER_H
