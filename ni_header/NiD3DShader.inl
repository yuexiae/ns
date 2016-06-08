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
// NiD3DShader inline functions
//---------------------------------------------------------------------------
inline NiD3DShader::NiD3DShader() :
    NiD3DShaderInterface(), 
    m_bUsesNiRenderState(false), 
    m_bUsesNiLightState(false),
    m_pkRenderStateGroup(0), 
    m_uiCurrentPass(0), 
    m_uiPassCount(0), 
    m_kPasses(2, 2)
{
    m_kPasses.RemoveAll();
}
//---------------------------------------------------------------------------
inline bool NiD3DShader::IsInitialized()
{
    return m_bInitialized;
}
//---------------------------------------------------------------------------
inline bool NiD3DShader::GetUsesNiRenderState() const
{
    return m_bUsesNiRenderState;
}
//---------------------------------------------------------------------------
inline void NiD3DShader::SetUsesNiRenderState(bool bUses)
{
    m_bUsesNiRenderState = bUses;
}
//---------------------------------------------------------------------------
inline bool NiD3DShader::GetUsesNiLightState() const
{
    return m_bUsesNiLightState;
}
//---------------------------------------------------------------------------
inline void NiD3DShader::SetUsesNiLightState(bool bUses)
{
    m_bUsesNiLightState = bUses;
}
//---------------------------------------------------------------------------
inline bool NiD3DShader::GetIsBestImplementation() const
{
    return m_bIsBestImplementation;
}
//---------------------------------------------------------------------------
inline void NiD3DShader::SetIsBestImplementation(bool bIsBest)
{
    m_bIsBestImplementation = bIsBest;
}
//---------------------------------------------------------------------------
inline void NiD3DShader::ResetSCMExtraData(NiGeometry* pkGeometry)
{
    if (pkGeometry)
    {
        NiSCMExtraData* pkShaderData = 
            (NiSCMExtraData*)
            pkGeometry->GetExtraData(NiD3DShader::m_pcNDLShaderMapName);
        if (pkShaderData)
            pkShaderData->Reset();
    }
}
//---------------------------------------------------------------------------