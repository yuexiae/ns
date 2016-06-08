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

#ifndef NIPSYSMODIFIER_H
#define NIPSYSMODIFIER_H

#include "NiParticleLibType.h"
#include <NiObject.h>

class NiParticleSystem;
class NiPSysData;

class NIPARTICLE_ENTRY NiPSysModifier : public NiObject
{
    NiDeclareRTTI;
    NiDeclareAbstractClone(NiPSysModifier);
    NiDeclareAbstractStream;
    NiDeclareViewerStrings;

public:
    enum
    {
        ORDER_KILLOLDPARTICLES = 0,
        ORDER_EMITTER          = 1000,
        ORDER_SPAWN            = 2000,
        ORDER_GENERAL          = 3000,
        ORDER_FORCE            = 4000,
        ORDER_COLLIDER         = 5000,
        ORDER_POSUPDATE        = 6000,
        ORDER_POSTPOSUPDATE    = 6500,
        ORDER_BOUNDUPDATE      = 7000
    };

    // This function will call Update if m_bActive is true.
    void UpdateModifier(float fTime, NiPSysData* pkData);

    // Override these functions in derived classes, if desired. Update must
    // be overridden.
    virtual void Update(float fTime, NiPSysData* pkData) = 0;
    virtual void Initialize(NiPSysData* pkData, unsigned short usNewParticle);
    virtual void HandleReset();

    const char* GetName() const;
    void SetName(const char* pcName);

    unsigned int GetOrder() const;

    NiParticleSystem* GetSystemPointer() const;

    bool GetActive() const;
    virtual void SetActive(bool bActive);

    // *** begin NDL internal use only ***
    void SetSystemPointer(NiParticleSystem* pkTarget);
    virtual void ProcessClone(NiCloningProcess& kCloning);
    // *** end NDL internal use only ***

protected:
    // For cloning and streaming only.
    NiPSysModifier();

    NiPSysModifier(const char* pcName, unsigned int uiOrder);
    virtual ~NiPSysModifier();

    char* m_pcName;
    unsigned int m_uiOrder;

    NiParticleSystem* m_pkTarget;

    bool m_bActive;

    static const float ms_fEpsilon;
};

NiSmartPointer(NiPSysModifier);

#include "NiPSysModifier.inl"

#endif  // #ifndef NIPSYSMODIFIER_H
