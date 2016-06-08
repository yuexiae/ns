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
#ifndef NIDX9LIGHTMANAGER_H
#define NIDX9LIGHTMANAGER_H

#include "NiDX9Headers.h"
#include "NiDX9RendererLibType.h"
#include <NiTPointerMap.h>
#include <NiTPointerList.h>
#include <NiRTLib.h>
#include <NiSmartPointer.h>
#include <NiRefObject.h>
#include <NiTexturingProperty.h>
#include <NiVertexColorProperty.h>

NiSmartPointer(NiLight);

class NiDX9RenderState;
class NiDynamicEffectState;

class NIDX9RENDERER_ENTRY NiDX9LightManager : public NiRefObject
{
public:
    NiDX9LightManager(NiDX9RenderState* pkRenderState,
        LPDIRECT3DDEVICE9 pkD3DDevice9);
    ~NiDX9LightManager();

    void NextFrame();
    void SetState(const NiDynamicEffectState* pkState, 
        const NiTexturingProperty* pkTex, 
        const NiVertexColorProperty* pkColor);

    void RemoveLight(NiLight& kLight);

    void ReleaseLights();

    // this value is not valid for a set of states until after the
    // call to UpdateRenderStates() is made
    bool IsLit() const;
    
    // *** begin NDL internal use only ***

    void InitRenderModes();

    // *** end NDL internal use only ***

protected:
    class LightEntry
    {
    public:
        LightEntry(const NiLight& kLight);

        // returns true if the material has changed
        bool Update(const NiLight& kLight);

        D3DLIGHT9* GetD3DLight();
        int GetIndex() const;

        void SetRemoval(bool bRemove);
        bool GetRemoval() const;

        void SetActive(bool bActive);
        bool GetActive() const;

    protected:
        D3DLIGHT9 m_kD3DLight;
        unsigned int m_uiRevID;
        int m_iIndex;
        bool m_bNeedsRemoval;
        bool m_bActive;

        static const float ms_fRangeMax;
    };

    void UpdateLights(const NiDynamicEffectState* pkState);

    NiTPointerMap<NiLight*, LightEntry*> m_kLights;

    NiTPointerList<NiLight*> m_kDeviceLights;
    
    LPDIRECT3DDEVICE9 m_pkD3DDevice9;
    NiDX9RenderState* m_pkRenderState;

    const NiDynamicEffectState* m_pkLastState;
    bool m_bLastAmbientDiffuse;

    //------------------------------------------------
    // Vertex Color Members
    NiTexturingProperty::ApplyMode m_eApply;
    bool m_bAmbientDiffuse;

    NiVertexColorProperty::SourceVertexMode m_eSourceMode;
};

typedef NiPointer<NiDX9LightManager> NiDX9LightManagerPtr;

#endif  //#ifndef NIDX9LIGHTMANAGER_H
