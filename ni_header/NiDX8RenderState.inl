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
//  NiDX8RenderState inline functions
//---------------------------------------------------------------------------
inline void NiDX8RenderState::SetVertexShader(
    NiD3DVertexShaderHandle hShader, bool bSave)
{
    if (hShader == NULL)
        return;
    if (bSave)
        m_hPreviousVertexShader = m_hCurrentVertexShader;
    if (m_hCurrentVertexShader != hShader)
    {
        m_hCurrentVertexShader = hShader;
        m_pkD3DDevice->SetVertexShader(m_hCurrentVertexShader);
    }
}
//---------------------------------------------------------------------------
inline NiD3DVertexShaderHandle NiDX8RenderState::GetVertexShader() const
{
    return m_hCurrentVertexShader;
}
//---------------------------------------------------------------------------
inline void NiDX8RenderState::RestoreVertexShader()
{
    SetVertexShader(m_hPreviousVertexShader);
}
//---------------------------------------------------------------------------
inline void NiDX8RenderState::ClearVertexShader(
    NiD3DVertexShaderHandle hShader)
{
    if (hShader == NULL)
        return;
    if (m_hCurrentVertexShader == hShader)
    {
        // We need to clear this!
        m_hCurrentVertexShader = D3DFVF_XYZ;
        m_pkD3DDevice->SetVertexShader(D3DFVF_XYZ);
    }

    if (m_hPreviousVertexShader == hShader)
    {
        // This is likely a bad thing to have happening
        // If someone calls restore on this, they will have lost what
        // if happening
        m_hPreviousVertexShader = D3DFVF_XYZ;
    }
}
//---------------------------------------------------------------------------
inline void NiDX8RenderState::SetFVF(unsigned int uiFVF, bool bSave)
{
    SetVertexShader((NiD3DVertexShaderHandle)uiFVF, bSave);
}
//---------------------------------------------------------------------------
inline unsigned int NiDX8RenderState::GetFVF() const
{
    return (unsigned int)GetVertexShader();
}
//---------------------------------------------------------------------------
inline void NiDX8RenderState::RestoreFVF()
{
    RestoreVertexShader();
}
//---------------------------------------------------------------------------
inline void NiDX8RenderState::ClearFVF(unsigned int uiFVF)
{
    ClearVertexShader((NiD3DVertexShaderHandle)uiFVF);
}
//---------------------------------------------------------------------------
inline void NiDX8RenderState::SetDeclaration(
    NiD3DVertexDeclaration hDeclaration, bool bSave)
{ /* */ }
//---------------------------------------------------------------------------
inline NiD3DVertexDeclaration NiDX8RenderState::GetDeclaration() const
{
    return (NiD3DVertexDeclaration)0;
}
//---------------------------------------------------------------------------
inline void NiDX8RenderState::RestoreDeclaration()
{ /* */ }
//---------------------------------------------------------------------------
inline void NiDX8RenderState::ClearDeclaration(
    NiD3DVertexDeclaration hDeclaration)
{
    ClearVertexShader((NiD3DVertexShaderHandle)hDeclaration);
}
//---------------------------------------------------------------------------
inline void NiDX8RenderState::SetSamplerState(unsigned int uiStage, 
    NiD3DSamplerState eState, unsigned int uiValue, bool bSave)
{
    D3DTEXTURESTAGESTATETYPE eType = 
        (D3DTEXTURESTAGESTATETYPE)ms_auiSamplesStateMappings[eState];

    // Check for invalid
    if (eType == 0xFFFFFFFF)
        return;

    // Set the state
    SetTextureStageState(uiStage, eType, uiValue, bSave);
}
//---------------------------------------------------------------------------
inline unsigned int NiDX8RenderState::GetSamplerState(unsigned int uiStage, 
    NiD3DSamplerState eState)
{
    D3DTEXTURESTAGESTATETYPE eType = 
        (D3DTEXTURESTAGESTATETYPE)ms_auiSamplesStateMappings[eState];
    return GetTextureStageState(uiStage, eType);
}
//---------------------------------------------------------------------------
inline void NiDX8RenderState::RestoreSamplerState(unsigned int uiStage, 
    NiD3DSamplerState eState)
{
    D3DTEXTURESTAGESTATETYPE eType = 
        (D3DTEXTURESTAGESTATETYPE)ms_auiSamplesStateMappings[eState];
    RestoreTextureStageState(uiStage, eType);
}
//---------------------------------------------------------------------------
