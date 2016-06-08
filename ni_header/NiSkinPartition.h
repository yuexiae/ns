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

#ifndef NISKINPARTITION_H
#define NISKINPARTITION_H

#include "NiMainLibType.h"
#include "NiTSet.h"
#include "NiObject.h"
#include "NiSmartPointer.h"
#include "NiStream.h"

#ifdef PS2
class NiPS2PrePackedBuffers;
#elif defined(WIN32) || defined(_XBOX)
class NiGeometryBufferData;
#endif

class NiTriBasedGeomData;
class NiSkinData;

class NIMAIN_ENTRY NiSkinPartition : public NiObject
{
    NiDeclareRTTI;
    NiDeclareStream;

protected:
    class Interaction;
    class VertexInteractions;
    class BoneSet;
    class BoneSetMerger;
    class TriangleSet;

public:
    class NIMAIN_ENTRY Partition
    {
    public:
        Partition();
        virtual ~Partition();

        unsigned short* m_pusBones;
        float* m_pfWeights;
        unsigned short* m_pusVertexMap;
        unsigned char* m_pucBonePalette;
        unsigned short* m_pusTriList;
        unsigned short* m_pusStripLengths;

        unsigned short m_usVertices;
        unsigned short m_usTriangles;
        unsigned short m_usBones;
        unsigned short m_usStrips;
        unsigned short m_usBonesPerVertex;
#if defined(WIN32) || defined(_XBOX)
        NiGeometryBufferData* m_pkBuffData;
#endif // defined(WIN32) || defined(_XBOX)

        // *** begin NDL internal use only ***
        void Create(const TriangleSet& kTriangles,
            const BoneSet& kBones, const NiTriBasedGeomData* pkTriData,
            const VertexInteractions* pkVertexInteraction,
            bool bNeedPalette, bool bForcePalette,
            unsigned char ucBonesPerVertex, unsigned int uiMaxBones);
        void LoadBinary(NiStream& kStream);
        void SaveBinary(NiStream& kStream);
        bool IsEqual(const Partition& kPartition);
        void PostPrecache();
        // *** end NDL internal use only ***

    protected:
        unsigned short* CreateVertexMap(const TriangleSet& kTriangles,
            const NiTriBasedGeomData* pkTriData);
        void CreateTriangleList(const TriangleSet& kTriangles,
            const NiTriBasedGeomData* pkTriData,
            const unsigned short* pusVertexPartitionIndex);
        unsigned int GetStripLengthSum() const;
    };

    NiSkinPartition();
    ~NiSkinPartition();

    bool MakePartitions(const NiTriBasedGeomData* pkTriData,
        const NiSkinData* pkSkinData, unsigned char ucBonesPerPartition,
        unsigned char ucBonesPerVertex, bool bForcePalette);

    void ReplacePartitions(Partition* pkPartitions, unsigned int uiPartitions);

    unsigned int GetPartitionCount() const;
    Partition* GetPartitions();
    const Partition* GetPartitions() const;

protected:
    void MakeBoneSets(const NiTriBasedGeomData* pkTriData, 
        const NiSkinData* pkSkinData, unsigned char ucBonesPerPartition,
        VertexInteractions* pkVertexInteraction, NiTSet<BoneSet*>& kBoneSets,
        unsigned int*& puiTriangleToPartition);
    VertexInteractions* CreateVertexInteractions(unsigned int uiVertices, 
        const NiSkinData* pSkinData);
    bool RemoveExcessInteractions(const NiTriBasedGeomData* pkTriData,
        unsigned char ucBonesPerPartition, unsigned char ucBonesPerVertex,
        VertexInteractions* pkVertexInteraction);
    void CreateInitialBoneSets(const NiTriBasedGeomData* pkTriData,
        VertexInteractions* pkVertexInteraction,
        NiTSet<BoneSet*>& kBoneSets);
    void MergeBoneSets(unsigned char ucBonesPerPartition,
        NiTSet<BoneSet*>& kBoneSets);
    void MakeBoneMap(NiTPointerMap<unsigned int, float>& kMap,
        const unsigned short* pusTriangle,
        const VertexInteractions* pkVertexInteraction);
    static int AssignTriangle(NiTSet<BoneSet*>& kBoneSets,
        const unsigned short* pusTriangle,
        VertexInteractions* pkVertexInteraction, bool* pbAssigned,
        bool bAssign);

    unsigned int m_uiPartitions;
    Partition* m_pkPartitions;

#ifdef PS2
public:
    NiPS2PrePackedBuffers* GetRendererData(unsigned int i) const;
    void SetRendererData(NiPS2PrePackedBuffers* pkBuffers, unsigned int i);
    unsigned char& GetRendererIndex();
protected:
    unsigned char m_ucIndex;
    NiPS2PrePackedBuffers* m_apkBuffers[2];
#endif
};

NiSmartPointer(NiSkinPartition);

#include "NiSkinPartition.inl"

#endif // NISKINPARTITION_H
