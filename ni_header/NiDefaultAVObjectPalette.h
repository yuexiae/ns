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

#ifndef NIDEFAULTAVOBJECTPALETTE_H
#define NIDEFAULTAVOBJECTPALETTE_H

#include "NiAVObjectPalette.h"

class NIMAIN_ENTRY NiDefaultAVObjectPalette : public NiAVObjectPalette
{
    NiDeclareRTTI;
    NiDeclareClone(NiDefaultAVObjectPalette);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiDefaultAVObjectPalette(NiAVObject* pkScene = NULL);
    ~NiDefaultAVObjectPalette() { /* */ }

    virtual NiAVObject* GetAVObject(const char* pcName);
    virtual void SetAVObject(const char* pcName, NiAVObject* pkObj);

    virtual void SetScene(NiAVObject* pkScene);
    virtual NiAVObject* GetScene();

    // *** begin NDL internal use only ***
    virtual void ProcessClone(NiCloningProcess& kCloning);
    // *** end NDL internal use only ***

protected:
    NiTStringPointerMap<NiAVObject*> m_kHash;
    NiAVObject* m_pkScene;
};

#include "NiDefaultAVObjectPalette.inl"

#endif
