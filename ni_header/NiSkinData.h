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

#ifndef NISKINDATA_H
#define NISKINDATA_H

#include "NiBound.h"
#include "NiObject.h"
#include "NiSkinPartition.h"
#include "NiTransform.h"

// NiSkinData contains all the data that can shared by multiple instances of
// the same skinned object.

class NIMAIN_ENTRY NiSkinData : public NiObject
{
    NiDeclareRTTI;
    NiDeclareStream;

public:
    class NIMAIN_ENTRY BoneVertData
    {
    public:
        unsigned short m_usVert;
        float m_fWeight;

        // for qsort:
        static int Compare(const void* pv0, const void* pv1);
    };

    class NIMAIN_ENTRY BoneData
    {
    public:
        void SortAndMerge();

        NiTransform m_kSkinToBone;
        NiBound m_kBound; // calculated by NiSkinData constructor
        BoneVertData* m_pkBoneVertData;
        unsigned short m_usVerts;
    };

    // The NiSkinData class assumes control of the pBoneData array passed to 
    // its constructor. (i.e. Its destructor deletes them.)

    NiSkinData(unsigned int uiBones, BoneData* pkBoneData,
        const NiTransform& kRootParentToSkin, const NiPoint3* pkVerts);
    virtual ~NiSkinData();
    NiSkinPartition* GetSkinPartition(bool bDontAssert = false) const;

    unsigned int GetBoneCount() const;
    BoneData* GetBoneData() const;
    const NiTransform& GetRootParentToSkin() const;

    // *** begin NDL internal use only ***

    void SetSkinPartition(NiSkinPartition* pkSkinPartition, 
        bool bDontAssert = false);

    NiSkinData();
    void RemoveUnusedVertices(const int* piOldToNew);
    void SortAndMergeBoneData();

    void FreeBoneVertData();
    // *** end NDL internal use only ***

protected:
    void ComputeBoneBounds(const NiPoint3* pkVerts);

    // As of GB1.2, this pointer is deprecated. It continues to exist only
    // for purposes of streaming older NIF files.
    NiSkinPartitionPtr m_spSkinPartition;

    NiTransform m_kRootParentToSkin;
    unsigned int m_uiBones;
    BoneData* m_pkBoneData;
};


typedef NiPointer<NiSkinData> NiSkinDataPtr;

#include "NiSkinData.inl"

#endif // NISKINDATA_H
