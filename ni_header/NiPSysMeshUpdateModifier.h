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

#ifndef NIPSYSMESHUPDATEMODIFIER_H
#define NIPSYSMESHUPDATEMODIFIER_H

#include "NiPSysModifier.h"
#include <NiAVObject.h>

class NIPARTICLE_ENTRY NiPSysMeshUpdateModifier : public NiPSysModifier
{
    NiDeclareRTTI;
    NiDeclareClone(NiPSysMeshUpdateModifier);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiPSysMeshUpdateModifier(const char* pcName);

    virtual void Update(float fTime, NiPSysData* pkData);
    virtual void Initialize(NiPSysData* pkData, unsigned short usNewParticle);

    NiAVObject* GetMeshAt(unsigned int uiIndex) const;
    NiAVObjectPtr SetMeshAt(unsigned int uiIndex, NiAVObject* pkMesh);

    unsigned int GetMeshCount() const;

    // *** begin NDL internal use only ***
    void ProcessClone(NiCloningProcess& kCloning);

    // Streaming
    void PostLinkObject(NiStream& kStream);

    // *** end NDL internal use only ***

protected:
    // For cloning and streaming only.
    NiPSysMeshUpdateModifier();


    NiTArray<NiAVObjectPtr> m_kMeshes;
};

NiSmartPointer(NiPSysMeshUpdateModifier);

#include "NiPSysMeshUpdateModifier.inl"

#endif  // #ifndef NIPSYSMESHUPDATEMODIFIER_H
