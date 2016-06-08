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

#ifndef NITRISHAPEDYNAMICDATA_H
#define NITRISHAPEDYNAMICDATA_H

#include "NiTriShapeData.h"

class NIMAIN_ENTRY NiTriShapeDynamicData : public NiTriShapeData
{
public:
    NiDeclareRTTI;
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    // The constructed object is given ownership of the input arrays and
    // has the responsibility for deleting them when finished with them.
    NiTriShapeDynamicData(unsigned short usVertices, NiPoint3* pkVertex,
        NiPoint3* pkNormal, NiColorA* pkColor, NiPoint2* pkTexture, 
        unsigned short usNumTextureSets, DataFlags eNBTMethod,
        unsigned short usTriangles, unsigned short* pusTriList,
        unsigned short usActiveVertices = 0,
        unsigned short usActiveTriangles = 0);

    NiTriShapeDynamicData();

    // For resetting the valid size of the model data arrays.
    // Useful for applications that manipulate the arrays after 
    // creating the model data, like NiTerrain, NiClod, NiClodSkin
    virtual void SetActiveVertexCount(unsigned short usActiveVertices);
    virtual void SetActiveTriangleCount(unsigned short usActiveTriangles);
    virtual unsigned short GetActiveVertexCount() const;
    virtual unsigned short GetActiveTriangleCount() const;

    // *** begin NDL internal use only ***
    virtual void GetStripData(unsigned short& usStrips,
        const unsigned short*& pusStripLengths,
        const unsigned short*& pusTriList,
        unsigned int& uiStripLengthSum) const;
    // *** end NDL internal use only ***

protected:
    unsigned short m_usActiveVertices;
    unsigned short m_usActiveTriangles;

};

typedef NiPointer<NiTriShapeDynamicData> NiTriShapeDynamicDataPtr;

//---------------------------------------------------------------------------
//  Inline include
#include "NiTriShapeDynamicData.inl"

//---------------------------------------------------------------------------

#endif // NITRISHAPEDYNAMICDATA_H
