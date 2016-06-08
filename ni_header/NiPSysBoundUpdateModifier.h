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

#ifndef NIPSYSBOUNDUPDATEMODIFIER_H
#define NIPSYSBOUNDUPDATEMODIFIER_H

#include "NiPSysModifier.h"

class NIPARTICLE_ENTRY NiPSysBoundUpdateModifier : public NiPSysModifier
{
    NiDeclareRTTI;
    NiDeclareClone(NiPSysBoundUpdateModifier);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    enum { AUTO_SKIP_UPDATE = -1 };

    NiPSysBoundUpdateModifier(const char* pcName,
        short sUpdateSkip = AUTO_SKIP_UPDATE);
    ~NiPSysBoundUpdateModifier();

    virtual void Update(float fTime, NiPSysData* pkData);

    short GetUpdateSkip() const;
    void SetUpdateSkip(short sUpdateSkip);
    void ResetUpdateSkipBounds();

protected:
    // For cloning and streaming only.
    NiPSysBoundUpdateModifier();

    void UpdateMeshBounds(float fTime, NiMeshPSysData* pkMeshData);

    short m_sUpdateSkip;

    unsigned short m_usUpdateCount;

    NiBound* m_pkSkipBounds;
};

NiSmartPointer(NiPSysBoundUpdateModifier);

#include "NiPSysBoundUpdateModifier.inl"

#endif  // #ifndef NIPSYSBOUNDUPDATEMODIFIER_H
