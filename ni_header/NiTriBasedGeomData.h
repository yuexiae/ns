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

#ifndef NITRIBASEDGEOMDATA_H
#define NITRIBASEDGEOMDATA_H

#include "NiGeometryData.h"
#include "NiPlane.h"


class NIMAIN_ENTRY NiTriBasedGeomData : public NiGeometryData
{
    NiDeclareRTTI;
    NiDeclareAbstractStream;
    NiDeclareViewerStrings;

public:
    virtual ~NiTriBasedGeomData();

    // triangles
    unsigned short GetTriangleCount() const;
    void SetTriangleCount(unsigned short usTriangles);
    virtual void SetActiveTriangleCount(unsigned short usActive);
    virtual unsigned short GetActiveTriangleCount() const;
    virtual void GetTriangleIndices(unsigned short i, unsigned short& i0,
        unsigned short& i1, unsigned short& i2) const;

    // Mask values for NiGeometryData::MarkAsChanged:
    enum
    {
        TRIANGLE_INDEX_MASK = 0x10,
        TRIANGLE_COUNT_MASK = 0x20
    };

    // *** begin NDL internal use only ***
    virtual void GetStripData(unsigned short& usStrips,
        const unsigned short*& pusStripLengths,
        const unsigned short*& pusTriList,
        unsigned int& uiStripLengthSum) const;
    // *** end NDL internal use only ***
protected:
    // The constructed object is given ownership of the input arrays and
    // has the responsibility for deleting them when finished with them.
    NiTriBasedGeomData(unsigned short usVertices, NiPoint3* pkVertex,
        NiPoint3* pkNormal, NiColorA* pkColor, NiPoint2* pkTexture, 
        unsigned short usNumTextureSets, NiGeometryData::DataFlags eNBTMethod,
        unsigned short usTriangles);

    NiTriBasedGeomData();

    unsigned short m_usTriangles;
};

typedef NiPointer<NiTriBasedGeomData> NiTriBasedGeomDataPtr;

#include "NiTriBasedGeomData.inl"

#endif
