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

#ifndef NIPSYSAGEDEATHMODIFIER_H
#define NIPSYSAGEDEATHMODIFIER_H

#include "NiPSysModifier.h"

class NiPSysSpawnModifier;

class NIPARTICLE_ENTRY NiPSysAgeDeathModifier : public NiPSysModifier
{
    NiDeclareRTTI;
    NiDeclareClone(NiPSysAgeDeathModifier);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiPSysAgeDeathModifier(const char* pcName, bool bSpawnOnDeath = false,
        NiPSysSpawnModifier* pkSpawnModifier = NULL);

    virtual void Update(float fTime, NiPSysData* pkData);

    bool GetSpawnOnDeath() const;
    void SetSpawnOnDeath(bool bSpawnOnDeath);

    NiPSysSpawnModifier* GetSpawnModifier() const;
    void SetSpawnModifier(NiPSysSpawnModifier* pkSpawnModifier);

    // *** begin NDL internal use only ***
    virtual void ProcessClone(NiCloningProcess& kCloning);
    // *** end NDL internal use only ***

protected:
    // For cloning and streaming only.
    NiPSysAgeDeathModifier();

    bool m_bSpawnOnDeath;
    NiPSysSpawnModifier* m_pkSpawnModifier;
};

NiSmartPointer(NiPSysAgeDeathModifier);

#include "NiPSysAgeDeathModifier.inl"

#endif  // #ifndef NIPSYSAGEDEATHMODIFIER_H
