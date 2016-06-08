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

#ifndef NIUNSHAREDGEOMETRYGROUP_H
#define NIUNSHAREDGEOMETRYGROUP_H

#include "NiGeometryGroup.h"
#include <NiSkinPartition.h>
class NiGeometryData;
#if defined(_XBOX)
class NiXBoxVBCache;
#endif  //#if defined(_XBOX)

class NID3D_ENTRY NiUnsharedGeometryGroup : public NiGeometryGroup
{
public:
    virtual ~NiUnsharedGeometryGroup();

    virtual void Purge();

    // *** begin NDL internal use only ***

    static NiGeometryGroup* Create(unsigned int uiFlags);
    
    virtual void AddObject(NiGeometryData* pkData, 
        NiSkinInstance* pkSkinInstance, 
        NiSkinPartition::Partition* pkPartition, unsigned int uiFlags = 0);
    virtual void RemoveObject(NiGeometryData* pkData);
    virtual void RemoveObject(NiSkinPartition::Partition* pkPartition);

    virtual void AddObject(NiScreenPolygon* pkScreenPoly, 
        unsigned int uiFlags = 0);
    virtual void RemoveObject(NiScreenPolygon* pkScreenPoly);

    virtual void AddObject(NiScreenTexture* pkScreenTexture, 
        unsigned int uiFlags = 0);
    virtual void RemoveObject(NiScreenTexture* pkScreenTexture);

    virtual NiVBChip* CreateChip(NiGeometryBufferData* pkBuffData, 
        unsigned int uiStream);
    virtual void ReleaseChip(NiGeometryBufferData* pkBuffData, 
        unsigned int uiStream);

    virtual bool IsDynamic();

    // *** end NDL internal use only ***

protected:
    static NiUnsharedGeometryGroup* ms_pkGroup;

#if defined(_XBOX)
    NiXBoxVBCache* m_pkVBCache;
#endif  //#if defined(_XBOX)
};



#endif // NIUNSHAREDGEOMETRYGROUP_H