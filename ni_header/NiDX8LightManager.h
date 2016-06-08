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
#ifndef NIDX8LIGHTMANAGER_H
#define NIDX8LIGHTMANAGER_H

#include "NiDX8Headers.h"
#include "NiDX8RendererLibType.h"
#include <NiTPointerMap.h>
#include <NiTPointerList.h>
#include <NiRTLib.h>
#include <NiSmartPointer.h>
#include <NiRefObject.h>
#include <NiTexturingProperty.h>
#include <NiVertexColorProperty.h>

NiSmartPointer(NiLight);

class NiDX8RenderState;
class NiDynamicEffectState;

class NIDX8RENDERER_ENTRY NiDX8LightManager : public NiRefObject
{
public:
    NiDX8LightManager(NiDX8RenderState* pkRenderState,
        LPDIRECT3DDEVICE8 pkD3DDevice8);
    ~NiDX8LightManager();

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

        D3DLIGHT8* GetD3DLight();
        int GetIndex() const;

        void SetRemoval(bool bRemove);
        bool GetRemoval() const;

        void SetActive(bool bActive);
        bool GetActive() const;

    protected:
        D3DLIGHT8 m_kD3DLight;
        unsigned int m_uiRevID;
        int m_iIndex;
        bool m_bNeedsRemoval;
        bool m_bActive;

        static const float ms_fRangeMax;
    };

    void UpdateLights(const NiDynamicEffectState* pkState);

    NiTPointerMap<NiLight*, LightEntry*> m_kLights;

    NiTPointerList<NiLight*> m_kDeviceLights;
    
    LPDIRECT3DDEVICE8 m_pkD3DDevice8;
    NiDX8RenderState* m_pkRenderState;

    const NiDynamicEffectState* m_pkLastState;
    bool m_bLastAmbientDiffuse;

    //------------------------------------------------
    // Vertex Color Members
    NiTexturingProperty::ApplyMode m_eApply;
    bool m_bAmbientDiffuse;

    NiVertexColorProperty::SourceVertexMode m_eSourceMode;
};

typedef NiPointer<NiDX8LightManager> NiDX8LightManagerPtr;

#endif  //#ifndef NIDX8LIGHTMANAGER_H
