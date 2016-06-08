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

#ifndef NIDYNAMICGEOMETRYGROUP_H
#define NIDYNAMICGEOMETRYGROUP_H

#include "NiGeometryGroup.h"
#include <NiSkinPartition.h>
class NiGeometryData;
class NiVBDynamicSet;
class NiVBChip;
#if defined(_XBOX) && !defined(_XENON)
    class NiXBoxVBCache;
#endif  //#if defined(_XBOX) && !defined(_XENON)

class NID3D_ENTRY NiDynamicGeometryGroup : public NiGeometryGroup
{
public:
    virtual ~NiDynamicGeometryGroup();

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

    enum 
    {
        INDEX_MASK_STRIDE       = 0x80000000
    };

    NiDynamicGeometryGroup();

    NiTPointerMap<unsigned int, NiVBDynamicSet*> m_kSets;
    NiTPointerMap<unsigned int, NiVBChip*> m_kChips;

    NiTArray<NiVBDynamicSet*> m_kMultiStreamSets;
    NiTArray<NiVBChip*> m_kMultiStreamChips;
    unsigned int m_uiNextIndex;
#if defined(_XBOX) && !defined(_XENON)
    enum
    {
        // There are a max of 16 streams supported on Xbox
        XBOX_DYNAMIC_MAX_STREAMS    = 16, 
        // Default buffer size of 2k
        XBOX_DYNAMIC_DEFAULT_SIZE   = 2048,
        // Default number of entries is 10
        XBOX_DYNAMIC_DEFAULT_QUEUE  = 10,
        // Default storage for dynamic objects with 2 streams
        XBOX_DYNAMIC_DEFAULT_COUNT  = 2,
        // Default dynamic quad entry count
        XBOX_DYNAMIC_QUAD_DEFAULT_QUEUE = 10,
        // Default size of dynamic quad buffers
        XBOX_DYNAMIC_QUAD_DEFAULT_SIZE = 2048
    };

    static unsigned int ms_uiDynamicQueueCount;
    static unsigned int ms_uiDynamicQueueSize;
    static unsigned int ms_uiDynamicQueueStreamCount;
    // This variable holds the number of queue entries per stream
    static unsigned int 
        ms_auiDynamicQueueStreamEntries[XBOX_DYNAMIC_MAX_STREAMS];
    // This variable holds the size of queue entries per stream
    static unsigned int 
        ms_auiDynamicQueueStreamSizes[XBOX_DYNAMIC_MAX_STREAMS];
    
    static unsigned int ms_uiDynamicQuadQueueCount;
    static unsigned int ms_uiDynamicQuadQueueSize;

    unsigned int m_uiDynamicQueueStreamCount;
    unsigned int* m_puiDynamicQueueStreamEntries;
    unsigned int* m_puiDynamicQueueStreamSizes;
    NiVBChip** m_ppkDynamicArray;
    NiVBChip** m_ppkCurrDynamic;

    unsigned int m_uiDynamicQuadQueueCount;
    unsigned int m_uiDynamicQuadQueueSize;
    NiVBChip** m_ppkDynamicQuadArray;
    NiVBChip* m_pkCurrDynamicQuad;
    NiXBoxVBCache* m_pkVBCache;

    void AllocateDynamicArray();
    void ReleaseDynamicArray();
public:
    void SetDynamicFence();
    void SetDynamicQuadFence();

    static void SetDynamicQueueInfo(unsigned int uiDynamicQueueCount, 
        unsigned int uiDynamicQueueSize);

    static void SetDynamicQueueCountAndStreamInfo(unsigned int uiStreamCount, 
        unsigned int uiDefaultQueueEntries, unsigned int uiDefaultQueueSize);
    static void SetDynamicQueueStreamInfo(unsigned int uiStream, 
        unsigned int uiQueueEntries, unsigned int uiQueueSize);
#endif  //#if defined(_XBOX) && !defined(_XENON)

    static NiDynamicGeometryGroup* ms_pkGroup;
};

#endif // NIDYNAMICGEOMETRYGROUP_H
