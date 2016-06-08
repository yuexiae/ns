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

#ifndef NITRISHAPE_H
#define NITRISHAPE_H

#include "NiTriBasedGeom.h"
#include "NiTriShapeData.h"


class NIMAIN_ENTRY NiTriShape : public NiTriBasedGeom
{
    NiDeclareRTTI;
    NiDeclareClone(NiTriShape);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    // The constructed object is given ownership of the input arrays and
    // has the responsibility for deleting them when finished with them.
    NiTriShape(unsigned short usVertices, NiPoint3* pkVertex,
        NiPoint3* pkNormal, NiColorA* pkColor, NiPoint2* pkTexture, 
        unsigned short usNumTextureSets, NiGeometryData::DataFlags eNBTMethod,
        unsigned short usTriangles, unsigned short* pusTriList);

    // The constructed object shares the input data.
    NiTriShape(NiTriShapeData* pkModelData);

    // triangle access
    unsigned int GetTriListLength() const;
    unsigned short* GetTriList() const;
    virtual void GetModelTriangle(unsigned short usTriangle, NiPoint3*& pkP0,
        NiPoint3*& pkP1, NiPoint3*& pkP2);

    // *** begin NDL internal use only ***

    // display
    virtual void RenderImmediate(NiRenderer* pkRenderer);

    // *** end NDL internal use only ***

protected:
    // streaming support
    NiTriShape();
};

typedef NiPointer<NiTriShape> NiTriShapePtr;

#include "NiTriShape.inl"

#endif
