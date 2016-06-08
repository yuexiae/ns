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

#ifndef NIPS2GEOMETRYSTREAMER_H
#define NIPS2GEOMETRYSTREAMER_H

#include "NiExportPlatformGeometryLibType.h"
#include <NiObject.h>
#include <NiTMap.h>

class NiAVObject;
class NiGeometryData;
class NiSkinPartition;
class NiTexturingProperty;
class NiTriBasedGeom;
class NiTriBasedGeomData;

class NIEXPORTPLATFORMGEOMETRY_ENTRY NiPS2GeometryStreamer : public NiObject
{
    NiDeclareRTTI;
    NiDeclareStream;
public:
    virtual ~NiPS2GeometryStreamer();
    void ConvertObject(NiAVObject* pkObject);
    void ConvertGeometry(NiTriBasedGeom* pkGeometry, 
        NiTexturingProperty* pkTexProp);

protected:
    struct PS2Geometry;
    void ConvertObject(NiAVObject* pkObject, NiTexturingProperty* pkTexProp);
    void PackVerts(NiGeometryData* pkData, 
        PS2Geometry* pkGeom,
        const unsigned short *pusStripLength,
        const unsigned short *pusTriList,
        const unsigned short* pusVertexMap,
        unsigned short usStrips,
        const float* pfSourceWeight,
        unsigned int uiStripLengthIncrement,
        unsigned int uiWrapFlags);
    void ThrowAwayOriginalData(NiTriBasedGeom* pkGeometry);

    NiTMap<NiObject*, PS2Geometry*> m_kMap;
};

typedef NiPointer<NiPS2GeometryStreamer> NiPS2GeometryStreamerPtr;

#endif // NIPS2GEOMETRYSTREAMER_H