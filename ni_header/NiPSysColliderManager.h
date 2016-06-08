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

#ifndef NIPSYSCOLLIDERMANAGER_H
#define NIPSYSCOLLIDERMANAGER_H

#include "NiPSysModifier.h"
#include "NiPSysCollider.h"

class NIPARTICLE_ENTRY NiPSysColliderManager : public NiPSysModifier
{
    NiDeclareRTTI;
    NiDeclareClone(NiPSysColliderManager);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiPSysColliderManager(const char* pcName,
        NiPSysCollider* pkColliders = NULL);

    virtual void Update(float fTime, NiPSysData* pkData);

    NiPSysCollider* GetColliders();
    void SetColliders(NiPSysCollider* pkColliders);

    void AddCollider(NiPSysCollider* pkCollider);
    void RemoveCollider(NiPSysCollider* pkCollider);

    // *** begin NDL internal use only ***
    void ProcessClone(NiCloningProcess& kCloning);
    // *** end NDL internal use only ***

protected:
    // For cloning and streaming only.
    NiPSysColliderManager();

    NiPSysColliderPtr m_spColliders;
};

NiSmartPointer(NiPSysColliderManager);

#include "NiPSysColliderManager.inl"

#endif  // #ifndef NIPSYSCOLLIDERMANAGER_H
