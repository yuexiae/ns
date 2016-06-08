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
//---------------------------------------------------------------------------
#ifndef NIDX8MATERIALMANAGER_H
#define NIDX8MATERIALMANAGER_H

#include "NiDX8Headers.h"
#include "NiDX8RendererLibType.h"
#include <NiRTLib.h>
#include <NiSmartPointer.h>
#include <NiRefObject.h>

class NiMaterialProperty;

class NIDX8RENDERER_ENTRY NiDX8MaterialManager : public NiRefObject
{
public:
    NiDX8MaterialManager();
    ~NiDX8MaterialManager();

    D3DMATERIAL8* GetCurrentMaterial();
    void SetCurrentMaterial(NiMaterialProperty& kMat);

    void UpdateToDevice(LPDIRECT3DDEVICE8 pkD3DDevice8);
    void PurgeMaterial(NiMaterialProperty* pkMaterial);

    // *** begin NDL internal use only ***

    void Initialize();

    // *** end NDL internal use only ***

protected:
    class MaterialEntry
    {
    public:
        MaterialEntry(const NiMaterialProperty& kMat);

        // returns true if the material has changed
        bool Update(const NiMaterialProperty& kMat);

        D3DMATERIAL8* GetD3DMaterial() { return &m_kD3dMat; }

    protected:
        D3DMATERIAL8 m_kD3dMat;
        unsigned int m_uiRevID;
    };

    MaterialEntry* m_pkCurrentMaterial;
    bool m_bChanged;
};

typedef NiPointer<NiDX8MaterialManager> NiDX8MaterialManagerPtr;

#endif  //#ifndef NIDX8MATERIALMANAGER_H