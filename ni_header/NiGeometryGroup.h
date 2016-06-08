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

#ifndef NIGEOMETRYGROUP_H
#define NIGEOMETRYGROUP_H

class NiGeometryBufferData;
class NiScreenPolygon;
class NiScreenTexture;
class NiVBChip;
class NiGeometryData;
class NiSkinInstance;

#include "NiD3DDefines.h"
#include <NiSkinPartition.h>

class NID3D_ENTRY NiGeometryGroup
{
public:
    virtual void Purge() = 0;

    // *** begin NDL internal use only ***

    bool IsEmpty() const;

    virtual void AddObject(NiGeometryData* pkData, 
        NiSkinInstance* pkSkinInstance, 
        NiSkinPartition::Partition* pkPartition, unsigned int uiFlags = 0)
        = 0;
    virtual void RemoveObject(NiGeometryData* pkData) = 0;
    virtual void RemoveObject(NiSkinPartition::Partition* pkPartition) = 0;

    virtual void AddObject(NiScreenPolygon* pkScreenPoly, 
        unsigned int uiFlags = 0) = 0;
    virtual void RemoveObject(NiScreenPolygon* pkScreenPoly) = 0;

    virtual void AddObject(NiScreenTexture* pkScreenTexture, 
        unsigned int uiFlags = 0) = 0;
    virtual void RemoveObject(NiScreenTexture* pkScreenTexture) = 0;

    void SetVertexBufferSize(unsigned int uiVBSize);

    void AddObject(NiGeometryBufferData* pkBuffData, unsigned int uiFlags = 0);
    void RemoveObject(NiGeometryBufferData* pkBuffData);

    virtual NiVBChip* CreateChip(NiGeometryBufferData* pkBuffData, 
        unsigned int uiStream) = 0;
    virtual void ReleaseChip(NiGeometryBufferData* pkBuffData, 
        unsigned int uiStream) = 0;

    virtual bool IsDynamic() = 0;

    // *** end NDL internal use only ***

protected:
    NiGeometryGroup();
    virtual ~NiGeometryGroup();

    unsigned int m_uiRefCount;
    unsigned int m_uiDefaultFlags;

    D3DDevicePtr m_pkD3DDevice;

    friend class NiD3DGeometryGroupManager;

#if !defined(WIN32) && !defined(_XBOX) && !defined(_XENON)
    static NiCriticalSection ms_kCritSec;
#endif
};

#include "NiGeometryGroup.inl"

#endif // NIGEOMETRYGROUP_H