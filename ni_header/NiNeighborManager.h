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

#ifndef NINEIGHBORMANAGER_H
#define NINEIGHBORMANAGER_H

#include "NiStripifyLibType.h"
#include "NiNeighborManager.h"

class NiStripifyTriangle;

class NISTRIPIFY_ENTRY NiNeighborManager
{
public:
    NiNeighborManager();
    void Add(NiStripifyTriangle* pkTriangle);
    void Remove(NiStripifyTriangle* pkTriangle);
    void Adjust(NiStripifyTriangle* pkTriangle);
    NiStripifyTriangle* GetMinimum() const;
    void AdjustNeighbors(NiStripifyTriangle* pkTriangle);
    
protected:
    static unsigned int CountNeighbors(const NiStripifyTriangle* pkTriangle);

    // m_pNeighborList[i] is the triangle at the head of a list of triangles 
    // which all have neighbors adjacent to i edges.
    NiStripifyTriangle* m_apkNeighborLists[4];
};

#endif // NINEIGHBORMANAGER_H