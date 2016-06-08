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

#ifndef NILINES_H
#define NILINES_H

#include "NiGeometry.h"
#include "NiLinesData.h"

class NIMAIN_ENTRY NiLines : public NiGeometry
{
public:
    NiDeclareRTTI;
    NiDeclareClone(NiLines);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    // The constructed object is given ownership of the input arrays and
    // has the responsibility for deleting them when finished with them.
    NiLines(unsigned short usVertices, NiPoint3* pkVertex, NiColorA* pkColor,
        NiPoint2* pkTexture, unsigned short usNumTextureSets, 
        NiGeometryData::DataFlags eNBTMethod, NiBool* pbFlags);

    // The constructed object shares the input data.
    NiLines(NiLinesData* pkModelData);

    // connection flags
    NiBool* GetFlags();
    const NiBool* GetFlags() const;


    // *** begin NDL internal use only ***

    // display
    virtual void RenderImmediate(NiRenderer* pkRenderer);
    virtual void UpdateEffectsDownward(NiDynamicEffectState* pkParentState);

    // *** end NDL internal use only ***

protected:
    // streaming support
    NiLines();
};

typedef NiPointer<NiLines> NiLinesPtr;

//---------------------------------------------------------------------------
//  Inline include
#include "NiLines.inl"

//---------------------------------------------------------------------------

#endif

