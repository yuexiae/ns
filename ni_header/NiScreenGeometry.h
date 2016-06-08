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

#ifndef NISCREENGEOMETRY_H
#define NISCREENGEOMETRY_H

#include "NiTriShape.h"
#include "NiScreenGeometryData.h"

class NIMAIN_ENTRY NiScreenGeometry : public NiTriShape
{
    NiDeclareRTTI;
    NiDeclareClone(NiScreenGeometry);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    // The constructed object shares the input data.
    NiScreenGeometry(NiScreenGeometryData* pkModelData);

    virtual ~NiScreenGeometry();

    // The constructed object is given ownership of the input arrays and
    // has the responsibility for deleting them when finished with them.
    unsigned int AddScreenElement(unsigned int uiNumVerts, NiPoint2* pkVertex,
        NiColorA* pkColor, NiPoint2* pkTexture, 
        unsigned short usNumTextureSets);
    unsigned int AddScreenElement(unsigned int uiNumVerts, short* psHorz, 
        short* psVert, NiColorA* pkColor, NiPoint2* pkTexture, 
        unsigned short usNumTextureSets);

    unsigned int AddScreenElementRect(float fLeft, float fTop, float fWidth, 
        float fHeight, NiColorA* pkColor, NiPoint2* pkTexture, 
        unsigned short usNumTextureSets);

    unsigned int GetNumScreenElements() const;
    unsigned int GetScreenElementArraySize() const;
    NiScreenGeometryData::ScreenElement* GetScreenElement(
        unsigned int uiIndex) const;
    void SetScreenElement(unsigned int uiIndex, 
        NiScreenGeometryData::ScreenElement* pkElement);
    bool RemoveScreenElement(unsigned int uiIndex);
    void RemoveAllScreenElements();

    bool GetPixelAccurate() const;
    void SetPixelAccurate(bool bAccurate);

    bool GetUnorderedElements() const;
    void SetUnorderedElements(bool bUnordered);

    void UpdateGeometryData();

protected:
    // streaming support
    NiScreenGeometry();
};

typedef NiPointer<NiScreenGeometry> NiScreenGeometryPtr;

#include "NiScreenGeometry.inl"

#endif //NISCREENGEOMETRY_H

