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

#ifndef NIOPTGEOMETRY_H
#define NIOPTGEOMETRY_H

#include "NiOptimizationLibType.h"
#include "NiOptVertex.h"
#include <NiMain.h>

class NIOPTIMIZATION_ENTRY NiOptGeometry
{
public:
    NiOptGeometry(unsigned int uiVertices, NiOptVertex* pkVertex,
        unsigned int uiNumBones, void** ppvBones, void *pvRootParent, 
        NiTransform* pkInitXforms, NiTransform &kRootParentToSkin);

    virtual ~NiOptGeometry();

    unsigned int GetNewVertexCount() const;
    const unsigned int* GetNewToOldMapping() const;
    void CreateNiSkinInstance(NiAVObject* pkShape);

    static void SetMinSkinVertexWeight(float fMinWeight);
    static float GetMinSkinVertexWeight();

protected:
    // vertex reduction
    virtual void RemoveDegenerateVertices() = 0;

    // bone-weight per vertex reduction
    void RemoveWeightsHavingZeroEffect();

    // quicksort for NiOptVertex arrays
    int VertexCompare(unsigned int uiV0, unsigned int uiV1);
    void IndexSort(unsigned int*& puiIndex0, unsigned int*& puiIndex1);
    void IndexQSort(unsigned int* puiIndex, int iL, int iR);
    int ChoosePivot(unsigned int* puiIndex, int iL, int iR);

    unsigned int m_uiVertices;
    NiOptVertex* m_pkVertex;

    unsigned int m_uiNumBones;
    void** m_ppvBones;         // coming from MAX, the bone pointers
                               // have not been resolved yet so
                               // we store them as void*
    void* m_pvRootParent;
    NiTransform* m_pkInitXforms;
    NiTransform m_kRootParentToSkin;

    // mapping of new-to-old and old-to-new vertex indices
    unsigned int m_uiNewVertices;
    unsigned int* m_puiNewToOld;
    unsigned int* m_puiOldToNew;

    // constants
    static const unsigned int ms_uiMaxUnsignedShort;
    static const unsigned int ms_uiMaxUnsignedInt;

    static float ms_fMinSkinVertexWeight;
};

//---------------------------------------------------------------------------
inline unsigned int NiOptGeometry::GetNewVertexCount() const
{
    return m_uiNewVertices;
}
//---------------------------------------------------------------------------
inline const unsigned int* NiOptGeometry::GetNewToOldMapping() const
{
    return m_puiNewToOld;
}
//---------------------------------------------------------------------------
inline int NiOptGeometry::VertexCompare(unsigned int uiV0, unsigned int uiV1)
{
    return m_pkVertex[uiV0].Compare(m_pkVertex[uiV1]);
}

#endif  // #ifndef NIOPTGEOMETRY_H
