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
// NiD3DVertexShader inline functions
//---------------------------------------------------------------------------
inline NiD3DVertexShader::NiD3DVertexShader(NiD3DRenderer* pkRenderer) :
    NiD3DShaderProgram(pkRenderer), 
    m_uiUsage(0),
    m_hShader(0),
    m_hDecl(0),
    m_bSoftwareVP(false)
{
}
//---------------------------------------------------------------------------
inline unsigned int NiD3DVertexShader::GetUsage() const
{
    return m_uiUsage;
}
//---------------------------------------------------------------------------
inline void NiD3DVertexShader::SetUsage(unsigned int uiUsage)
{
    m_uiUsage = uiUsage;
}
//---------------------------------------------------------------------------
inline NiD3DVertexShaderHandle NiD3DVertexShader::GetShaderHandle() const
{
    return m_hShader;
}
//---------------------------------------------------------------------------
inline void NiD3DVertexShader::SetShaderHandle(
    NiD3DVertexShaderHandle hShader)
{
    m_hShader = hShader;
}
//---------------------------------------------------------------------------
inline NiD3DVertexDeclaration NiD3DVertexShader::GetVertexDeclaration() const
{
    return m_hDecl;
}
//---------------------------------------------------------------------------
inline void NiD3DVertexShader::SetVertexDeclaration(
    NiD3DVertexDeclaration hDecl)
{
    m_hDecl = hDecl;
}
//---------------------------------------------------------------------------
inline bool NiD3DVertexShader::GetSoftwareVertexProcessing() const
{
    return m_bSoftwareVP;
}
//---------------------------------------------------------------------------
inline void NiD3DVertexShader::SetSoftwareVertexProcessing(bool bSoftwareVP)
{
    m_bSoftwareVP = bSoftwareVP;
}
//---------------------------------------------------------------------------

