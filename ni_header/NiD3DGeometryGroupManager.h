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

#ifndef NID3DGEOMETRYGROUPMANAGER_H
#define NID3DGEOMETRYGROUPMANAGER_H

#include "NiD3DDefines.h"
#include <NiGeometryGroupManager.h>
#include <NiTSet.h>

class NiGeometryBufferManager;
class NiGeometryBufferData;

class NID3D_ENTRY NiD3DGeometryGroupManager : 
    public NiGeometryGroupManager
{
public:
    virtual ~NiD3DGeometryGroupManager();

    virtual NiGeometryGroup* CreateGroup(RepackingBehavior eBehavior,
        unsigned int uiFlags = 0);
    virtual bool DestroyGroup(NiGeometryGroup* pkGroup);
    
    virtual bool IsGroupEmpty(NiGeometryGroup* pkGroup) const;

    virtual bool AddObjectToGroup(NiGeometryGroup* pkGroup, 
        NiGeometryData* pkData, NiSkinInstance* pkSkinInstance = NULL,
        unsigned int uiFlags = 0);
    virtual bool RemoveObjectFromGroup(NiGeometryData* pkData, 
        NiSkinInstance* pkSkinInstance = NULL);

    virtual bool AddObjectToGroup(NiGeometryGroup* pkGroup, 
        NiScreenPolygon* pkScreenPoly, unsigned int uiFlags = 0);
    virtual bool RemoveObjectFromGroup(NiScreenPolygon* pkScreenPoly);

    virtual bool AddObjectToGroup(NiGeometryGroup* pkGroup, 
        NiScreenTexture* pkScreenTexture, unsigned int uiFlags = 0);
    virtual bool RemoveObjectFromGroup(NiScreenTexture* pkScreenTexture);

    // *** begin NDL internal use only ***

    static NiD3DGeometryGroupManager* Create(D3DDevicePtr pkD3DDevice,
        NiD3DVBManager* pkVBManager);

    // More useful D3D-specific AddObjectToGroup
    bool AddObjectToGroup(NiGeometryGroup* pkGroup, 
        NiGeometryData* pkData, NiSkinInstance* pkSkinInstance, 
        unsigned int uiFlags, bool bHWSkinning, 
        unsigned int uiBonesPerPartition, unsigned int uiBonesPerVertex);

    bool RemoveSkinPartitionFromGroup(NiSkinPartition* pkSkinPartition);

    void SetHWSkinning(bool bHWSkinning);

    // *** end NDL internal use only ***

protected:
    NiD3DGeometryGroupManager();

    NiTSet<NiGeometryGroup*> m_kGroups;

    D3DDevicePtr m_pkD3DDevice;
    NiD3DVBManager* m_pkVBManager;
    bool m_bHWSkinning;
};

#endif // NID3DGEOMETRYGROUPMANAGER_H