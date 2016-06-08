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
inline NiD3DShaderProgramCreator::NiD3DShaderProgramCreator()
{ /* */ }
//---------------------------------------------------------------------------
inline NiD3DShaderProgramCreator::~NiD3DShaderProgramCreator()
{ /* */ }
//---------------------------------------------------------------------------
inline unsigned int 
    NiD3DShaderProgramCreator::GetUniversalShaderCreationFlags()
{
    return ms_uiUniversalShaderCreationFlags;
}
//---------------------------------------------------------------------------
inline void NiD3DShaderProgramCreator::SetUniversalShaderCreationFlags(
    unsigned int uiFlags)
{
    ms_uiUniversalShaderCreationFlags = uiFlags;
}
//---------------------------------------------------------------------------
inline void NiD3DShaderProgramCreator::_SDMInit()
{ /* */ }
//---------------------------------------------------------------------------
inline void NiD3DShaderProgramCreator::_SDMShutdown()
{
    SetD3DRenderer(NULL);
}
//---------------------------------------------------------------------------
