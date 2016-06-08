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
inline NiD3DShaderProgramCreatorHLSL::NiD3DShaderProgramCreatorHLSL() :
    m_uiShaderCreationFlags(0)
{ /* */ }
//---------------------------------------------------------------------------
inline NiD3DShaderProgramCreatorHLSL::~NiD3DShaderProgramCreatorHLSL()
{ /* */ }
//---------------------------------------------------------------------------
inline unsigned int NiD3DShaderProgramCreatorHLSL::GetShaderCreationFlags()
    const
{
    return m_uiShaderCreationFlags;
}
//---------------------------------------------------------------------------
inline void NiD3DShaderProgramCreatorHLSL::SetShaderCreationFlags(
    unsigned int uiFlags)
{
    m_uiShaderCreationFlags = uiFlags;
}
//---------------------------------------------------------------------------
inline void NiD3DShaderProgramCreatorHLSL::_SDMInit()
{
    ms_pkCreator = new NiD3DShaderProgramCreatorHLSL();

    NiD3DShaderProgramFactory::RegisterShaderCreator("hlsl", ms_pkCreator);
}
//---------------------------------------------------------------------------
inline void NiD3DShaderProgramCreatorHLSL::_SDMShutdown()
{
    Shutdown();
}
//---------------------------------------------------------------------------
inline NiD3DShaderProgramCreatorHLSL* 
    NiD3DShaderProgramCreatorHLSL::GetInstance()
{
    return ms_pkCreator;
}
//---------------------------------------------------------------------------
inline void NiD3DShaderProgramCreatorHLSL::Shutdown()
{
    if (ms_pkCreator)
        NiD3DShaderProgramFactory::UnregisterShaderCreator(ms_pkCreator);
    delete ms_pkCreator;
    ms_pkCreator = NULL;
}
//---------------------------------------------------------------------------
