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
#ifndef NIDX9MATERIALMANAGER_H
#define NIDX9MATERIALMANAGER_H

#include "NiDX9Headers.h"
#include "NiDX9RendererLibType.h"
#include <NiRTLib.h>
#include <NiSmartPointer.h>
#include <NiRefObject.h>

class NiMaterialProperty;

class NIDX9RENDERER_ENTRY NiDX9MaterialManager : public NiRefObject
{
public:
    NiDX9MaterialManager();
    ~NiDX9MaterialManager();

    D3DMATERIAL9* GetCurrentMaterial();
    void SetCurrentMaterial(NiMaterialProperty& kMat);

    void UpdateToDevice(LPDIRECT3DDEVICE9 pkD3DDevice9);
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

        D3DMATERIAL9* GetD3DMaterial() { return &m_kD3dMat; }

    protected:
        D3DMATERIAL9 m_kD3dMat;
        unsigned int m_uiRevID;
    };

    MaterialEntry* m_pkCurrentMaterial;
    bool m_bChanged;
};

typedef NiPointer<NiDX9MaterialManager> NiDX9MaterialManagerPtr;

#endif  //#ifndef NIDX9MATERIALMANAGER_H
