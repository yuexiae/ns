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

#ifndef NIAVOBJECTPALETTE_H
#define NIAVOBJECTPALETTE_H

#include "NiTStringMap.h"
#include "NiAVObject.h"

class NIMAIN_ENTRY NiAVObjectPalette : public NiObject
{
    NiDeclareRTTI;
    NiDeclareAbstractClone(NiAVObjectPalette);
    NiDeclareAbstractStream;
    NiDeclareViewerStrings;

public:
    NiAVObjectPalette() { /* */ }
    ~NiAVObjectPalette() { /* */ }

    virtual NiAVObject* GetAVObject(const char* pcName) = 0;
    virtual void SetAVObject(const char* pcName, NiAVObject* pkObj) = 0;
};

typedef NiPointer<NiAVObjectPalette> NiAVObjectPalettePtr;

#endif
