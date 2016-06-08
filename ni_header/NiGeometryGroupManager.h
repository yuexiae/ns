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

#ifndef NIGEOMETRYGROUPMANAGER_H
#define NIGEOMETRYGROUPMANAGER_H

#include "NiMainLibType.h"
#include "NiRenderer.h"
#include "NiTSet.h"

class NiGeometryGroup;
class NiGeometryData;
class NiScreenPolygon;
class NiScreenTexture;
class NiSkinInstance;

class NIMAIN_ENTRY NiGeometryGroupManager
{
public:
    virtual ~NiGeometryGroupManager();

    enum RepackingBehavior
    {
        STATIC,
        UNSHARED,
        DYNAMIC
    };

    // Flags - none yet

    virtual NiGeometryGroup* CreateGroup(RepackingBehavior eBehavior,
        unsigned int uiFlags = 0);
    virtual bool DestroyGroup(NiGeometryGroup* pkGroup);
    
    static NiGeometryGroupManager* GetManager();

    virtual bool IsGroupEmpty(NiGeometryGroup* pkGroup) const;

    virtual bool AddObjectToGroup(NiGeometryGroup* pkGroup, 
        NiGeometryData* pkData, NiSkinInstance* pkSkinInstance = NULL, 
        unsigned int uiFlags = 0);
    virtual bool RemoveObjectFromGroup(NiGeometryData* pkData, 
        NiSkinInstance* pkSkinInstance);

    virtual bool AddObjectToGroup(NiGeometryGroup* pkGroup, 
        NiScreenPolygon* pkScreenPoly, unsigned int uiFlags = 0);
    virtual bool RemoveObjectFromGroup(NiScreenPolygon* pkScreenPoly);

    virtual bool AddObjectToGroup(NiGeometryGroup* pkGroup, 
        NiScreenTexture* pkScreenTexture, unsigned int uiFlags = 0);
    virtual bool RemoveObjectFromGroup(NiScreenTexture* pkScreenTexture);

    // *** begin NDL internal use only ***

    // *** end NDL internal use only ***

protected:
    NiGeometryGroupManager();

    static NiGeometryGroupManager* ms_pkManager;
};

#include "NiGeometryGroupManager.inl"

#endif // NIGEOMETRYGROUPMANAGER_H