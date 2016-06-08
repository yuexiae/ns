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

#ifndef NISCREENPOLYGON_H
#define NISCREENPOLYGON_H

#include "NiObject.h"
#include "NiProperty.h"
#include "NiStream.h"
#include "NiTArray.h"
#include "NiColor.h"
#include "NiPoint3.h"
#include "NiPoint2.h"
#include "NiPropertyState.h"

class NiRenderer;

#if defined(WIN32) || defined(_XBOX)
class NiGeometryBufferData;
#endif 

class NIMAIN_ENTRY NiScreenPolygon : public NiObject
{
    NiDeclareRTTI;
    NiDeclareClone(NiScreenPolygon);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    // construction and destruction
    NiScreenPolygon(unsigned short usVertices, const NiPoint3* pkVertex,
        const NiPoint2* pkTexture, const NiColorA* pkColor);
    virtual ~NiScreenPolygon();

    // properties
    NiPropertyState* GetPropertyState() const;
    void AttachProperty(NiProperty* pkProperty);
    void DetachProperty(NiProperty* pkProperty);
    void DetachAllProperties();
    
    // geometry and attributes
    unsigned short GetVertexCount() const;
    const NiPoint3* GetVertices() const;
    const NiPoint2* GetTextures() const;
    const NiColorA* GetColors() const;
    NiPoint3* GetVertices();
    NiPoint2* GetTextures();
    NiColorA* GetColors();

    // MarkAsChanged should be called if vertices, colors, or texture
    // coordinates are changed. The renderers cache geometric data to increase
    // performance. They need to know when any of that data has changed.
    // Values from the following enum should be OR'd together and passed to 
    // MarkAsChanged to indicate what values have changed:
    enum
    {
        VERTEX_MASK = 0x1,
        COLOR_MASK = 0x2,
        TEXTURE_MASK = 0x4,
        EVERYTHING_MASK = 
            (VERTEX_MASK | COLOR_MASK | TEXTURE_MASK)
    };
    void MarkAsChanged(unsigned short usFlags);

    // *** begin NDL internal use only ***

    void Draw(NiRenderer* pkRenderer);
    void ClearRevisionID();
    unsigned short GetRevisionID() const;

    // *** end NDL internal use only ***

protected:
    NiScreenPolygon();

    // properties
    NiPropertyStatePtr m_spPropertyState;

    // coord data
    unsigned short m_usVertices;
    NiPoint3* m_pkVertex;
    NiPoint2* m_pkTexture;
    NiColorA* m_pkColor;

    unsigned short m_usDirtyFlags;

    // renderer data
#if defined(PS2)
public:
    struct PS2Data
    {
        PS2Data();
        u_long128* m_puqData;
        unsigned int m_uiStamp;
    };
    PS2Data& GetRendererData(unsigned int i);
    unsigned char& GetRendererIndex();
protected:
    unsigned char m_ucIndex;
    PS2Data m_akRendererData[2];
#elif defined(WIN32) || defined(_XBOX)
public:
    NiGeometryBufferData* GetRendererData() const;
    void SetRendererData(NiGeometryBufferData* pkBuffData);
protected:
    NiGeometryBufferData* m_pkBuffData;
#elif defined(NGC)
public:
    void* GetRendererData() const;
    void SetRendererData(void* pvData);
protected:
    void* m_pvBufferData;
#endif 
};

typedef NiPointer<NiScreenPolygon> NiScreenPolygonPtr;
typedef NiTArray<NiScreenPolygonPtr> NiScreenPolygonArray;

#include "NiScreenPolygon.inl"

#endif // NISCREENPOLYGON_H

