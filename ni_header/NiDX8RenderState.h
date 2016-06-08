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
#ifndef NIDX8RENDERSTATE_H
#define NIDX8RENDERSTATE_H

#include "NiD3DRenderState.h"
#include "NiDX8Headers.h"
#include "NiD3DPass.h"
#include "NiDX8RendererLibType.h"

class NID3D_ENTRY NiDX8RenderState : public NiD3DRenderState
{
protected:
    NiDX8RenderState(NiD3DRenderer* pkRenderer, const D3DCAPS8& kD3DCaps8);

public:
    virtual ~NiDX8RenderState();

    static NiDX8RenderState* Create(NiD3DRenderer* pkRenderer, 
        const D3DCAPS8& kD3DCaps8, bool bHW, bool bZBuffer, 
        bool bDefaultWBuffer, bool bStencil);

    virtual void PurgeMaterial(NiMaterialProperty* pkMaterial);

    // Shader program management
    virtual void InitShaderState();

    // Vertex declarations
    virtual void SetVertexShader(NiD3DVertexShaderHandle hShader, 
        bool bSave = false);
    virtual NiD3DVertexShaderHandle GetVertexShader() const;
    virtual void RestoreVertexShader();
    virtual void ClearVertexShader(NiD3DVertexShaderHandle hShader);

    virtual void SetFVF(unsigned int uiFVF, bool bSave = false);
    virtual unsigned int GetFVF() const;
    virtual void RestoreFVF();
    virtual void ClearFVF(unsigned int uiFVF);

    virtual void SetDeclaration(NiD3DVertexDeclaration hDeclaration, 
        bool bSave = false);
    virtual NiD3DVertexDeclaration GetDeclaration() const;
    virtual void RestoreDeclaration();
    virtual void ClearDeclaration(NiD3DVertexDeclaration hDeclaration);

    // Texture stage and sampler states
    virtual void SetSamplerState(unsigned int uiStage, 
        NiD3DSamplerState eState, unsigned int uiValue, 
        bool bSave = false);
    virtual unsigned int GetSamplerState(unsigned int uiStage, 
        NiD3DSamplerState eState);
    virtual void RestoreSamplerState(unsigned int uiStage, 
        NiD3DSamplerState eState);

    virtual void SetSoftwareVertexProcessing(bool bSoftwareVP);
    virtual bool GetSoftwareVertexProcessing() const;

    // *** begin NDL internal use only ***
    virtual void InitRenderModes();
    // *** end NDL internal use only ***

protected:
    virtual void ReadRenderStateCaps();

    // Software vertex processing
    bool m_bUsingSoftwareVP;

    D3DCAPS8 m_kD3DCaps8;
};

typedef NiPointer<NiDX8RenderState> NiDX8RenderStatePtr;

#include "NiDX8RenderState.inl"

#endif  //#ifndef NIDX8RENDERSTATE_H
