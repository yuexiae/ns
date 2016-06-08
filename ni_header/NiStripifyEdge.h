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

#ifndef NISTRIPIFYEDGE_H
#define NISTRIPIFYEDGE_H

#include "NiStripifyLibType.h"
#include <NiTSet.h>

class NiStripifyTriangle;

class NISTRIPIFY_ENTRY NiStripifyEdge
{
public:
    NiStripifyEdge(unsigned short usVert0, unsigned short usVert1);
    void AddTriangle(NiStripifyTriangle* pkTriangle);
    NiStripifyTriangle* GetTriangle(unsigned int i) const;
    void RemoveTriangle(NiStripifyTriangle* pkTriangle);
    unsigned short GetVert(unsigned int i) const;
    unsigned int GetTriangleCount() const;

protected:
    unsigned short m_aVert[2];
    NiTSet<NiStripifyTriangle *> m_kTriangles;
};

//---------------------------------------------------------------------------
inline unsigned short NiStripifyEdge::GetVert(unsigned int i) const
{
    assert(i <= 1);
    return m_aVert[i];
}

//---------------------------------------------------------------------------
inline unsigned int NiStripifyEdge::GetTriangleCount() const
{
    return m_kTriangles.GetSize();
}

//---------------------------------------------------------------------------
inline NiStripifyTriangle* NiStripifyEdge::GetTriangle(unsigned int i) const
{
    return m_kTriangles.GetAt(i);
}

#endif // NISTRIPIFYEDGE_H