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

#ifndef NILINESDATA_H
#define NILINESDATA_H

#include "NiBool.h"
#include "NiGeometryData.h"

class NIMAIN_ENTRY NiLinesData : public NiGeometryData
{
    NiDeclareRTTI;
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    // The constructed object is given ownership of the input arrays and
    // has the responsibility for deleting them when finished with them.
    NiLinesData(unsigned short usVertices, NiPoint3* pkVertex,
        NiColorA* pkColor, NiPoint2* pkTexture,
        unsigned short usNumTextureSets, DataFlags eNBTMethod, 
        NiBool* pkFlags);

    NiLinesData();

    virtual ~NiLinesData();

    // connection flags
    NiBool* GetFlags();
    const NiBool* GetFlags() const;

    // reallocation support
    void Replace(NiBool* pkFlags);


    // *** begin NDL internal use only ***

    // For temporarily using data only.  This call is like Replace(), 
    // but does not delete any pointers.  Be careful to call this only 
    // on objects created by the default (empty) constructor to prevent 
    // memory leaks.  These pointers will be owned (and deleted upon 
    // destruction) by this object so use this call carefully.
    void SetData(NiBool* pkFlags);

    // updates
    virtual void CalculateNormals();

    // *** end NDL internal use only ***

protected:
    NiBool* m_pkFlags;
};

typedef NiPointer<NiLinesData> NiLinesDataPtr;

//---------------------------------------------------------------------------
//  Inline include
#include "NiLinesData.inl"

//---------------------------------------------------------------------------

#endif

