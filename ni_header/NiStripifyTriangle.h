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

#ifndef NISTRIPIFYTRIANGLE_H
#define NISTRIPIFYTRIANGLE_H

#include "NiStripifyLibType.h"
#include <NiRTLib.h>

class NiStripifyEdge;

class NISTRIPIFY_ENTRY NiStripifyTriangle
{
public:
    void SetEdge(unsigned int i, NiStripifyEdge* pkEdge);
    void SetNeighborEdge(unsigned int i, NiStripifyEdge* pkNeighborEdge);
    NiStripifyEdge* GetNeighborEdge(unsigned int i) const;
    
    // Remove is called when the triangle is added to a strip. The triangle
    // removes itself from the list of triangles in all of its edges.
    void RemoveFromEdges();

#ifdef _DEBUG
    unsigned short m_usTriangle;
#endif
    
protected:
    // Edges are oriented, so we keep pointer to both versions of each
    // edge that is part of each triangle.
    NiStripifyEdge* m_apkEdges[3];
    NiStripifyEdge* m_apkNeighborEdges[3];

    friend class NiNeighborManager;
    // NiNeighborManager manipulates these fields to maintain lists of 
    // triangles:
    NiStripifyTriangle* m_pkNext;
    NiStripifyTriangle* m_pkPrev;
};

//---------------------------------------------------------------------------
inline void NiStripifyTriangle::SetEdge(unsigned int i, 
    NiStripifyEdge* pkEdge)
{
    assert(i <= 2);
    m_apkEdges[i] = pkEdge;
}

//---------------------------------------------------------------------------
inline void NiStripifyTriangle::SetNeighborEdge(unsigned int i, 
    NiStripifyEdge* pkEdge)
{
    assert(i <= 2);
    m_apkNeighborEdges[i] = pkEdge;
}

//---------------------------------------------------------------------------
inline NiStripifyEdge *
NiStripifyTriangle::GetNeighborEdge(unsigned int i) const
{
    assert(i <= 2);
    return m_apkNeighborEdges[i];
}

#endif // NISTRIPIFYTRIANGLE_H
