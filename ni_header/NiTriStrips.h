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

#ifndef NITRISTRIPS_H
#define NITRISTRIPS_H

#include "NiTriBasedGeom.h"
#include "NiTriStripsData.h"

class NIMAIN_ENTRY NiTriStrips : public NiTriBasedGeom
{
    NiDeclareRTTI;
    NiDeclareClone(NiTriStrips);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    // The constructed object is given ownership of the input arrays and
    // has the responsibility for deleting them when finished with them.
    NiTriStrips(unsigned short usVertices, NiPoint3* pkVertex,
        NiPoint3* pkNormal, NiColorA* pkColor, NiPoint2* pkTexture, 
        unsigned short usNumTextureSets, NiGeometryData::DataFlags eNBTMethod,
        unsigned short usTriangles, unsigned short usStrips, 
        unsigned short* pusStripLengths, unsigned short* pusStripLists);

    // The constructed object shares the input data.
    NiTriStrips(NiTriStripsData* pkModelData);

    virtual void GetModelTriangle(unsigned short usTriangle, NiPoint3*& pkP0,
        NiPoint3*& pkP1, NiPoint3*& pkP2);

    // *** begin NDL internal use only ***

    // display
    virtual void RenderImmediate(NiRenderer* pkRenderer);

    // *** end NDL internal use only ***

protected:
    NiTriStrips();
};

typedef NiPointer<NiTriStrips> NiTriStripsPtr;

#endif // NITRISTRIPS_H
