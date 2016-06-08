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
// NiD3DPixelShader inline functions
//---------------------------------------------------------------------------
inline NiD3DPixelShader::NiD3DPixelShader(NiD3DRenderer* pkRenderer) :
    NiD3DShaderProgram(pkRenderer), 
    m_hShader(0) 
{
}
//---------------------------------------------------------------------------
inline NiD3DPixelShaderHandle NiD3DPixelShader::GetShaderHandle()
{
    return m_hShader;
}
//---------------------------------------------------------------------------
inline void NiD3DPixelShader::SetShaderHandle(NiD3DPixelShaderHandle hShader)
{
    m_hShader = hShader;
}
//---------------------------------------------------------------------------
