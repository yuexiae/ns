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

#ifndef NITRISTRIPSDATA_H
#define NITRISTRIPSDATA_H

#include "NiTriBasedGeomData.h"

class NIMAIN_ENTRY NiTriStripsData : public NiTriBasedGeomData
{
    NiDeclareRTTI;
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    // The constructed object is given ownership of the input arrays and
    // has the responsibility for deleting them when finished with them.
    NiTriStripsData(unsigned short usVertices, NiPoint3* pkVertex,
        NiPoint3* pkNormal, NiColorA* pkColor, NiPoint2* pkTexture, 
        unsigned short usNumTextureSets, DataFlags eNBTMethod,
        unsigned short usTriangles, unsigned short usStrips, 
        unsigned short* pusStripLengths, unsigned short* pusStripLists);

    NiTriStripsData();
    virtual ~NiTriStripsData();

    // triangles
    virtual void GetTriangleIndices(unsigned short i, unsigned short& i0,
        unsigned short& i1, unsigned short& i2) const;

    unsigned short GetStripCount() const;
    unsigned short* GetStripLengths() const;
    unsigned short* GetStripLists() const;
    unsigned short GetStripLengthSum() const;

    // reallocation support
    void Replace(unsigned short usStrips, unsigned short* pusStripLengths, 
        unsigned short* pusStripLists);

    // *** begin NDL internal use only ***

    // updates
    virtual void CalculateNormals();

    virtual void GetStripData(unsigned short& usStrips,
        const unsigned short*& pusStripLengths,
        const unsigned short*& pusTriList,
        unsigned int& uiStripLengthSum) const;

    virtual unsigned int GetBlockAllocationSize() const;
    // *** end NDL internal use only ***

protected:
    unsigned short m_usStrips;
    unsigned short* m_pusStripLengths;
    unsigned short* m_pusStripLists;

    // cached data used to accelerate queries for the indices of the vertices
    // of a triangle (GetPickInfo)
    static unsigned short ms_usPickID;
    static unsigned short ms_usPrevQuery;
    static unsigned short ms_usStrip;
    static unsigned short ms_usI;
    static const unsigned short* ms_pusStripList;
};

typedef NiPointer<NiTriStripsData> NiTriStripsDataPtr;

#include "NiTriStripsData.inl"

#endif // NITRISTRIPSDATA_H
