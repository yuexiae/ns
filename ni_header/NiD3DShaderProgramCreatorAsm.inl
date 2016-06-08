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
inline NiD3DShaderProgramCreatorAsm::NiD3DShaderProgramCreatorAsm() :
    m_uiShaderCreationFlags(0),
    m_pvConstantBuffer(NULL),
    m_uiConstantBufferSize(0)
{ /* */ }
//---------------------------------------------------------------------------
inline NiD3DShaderProgramCreatorAsm::~NiD3DShaderProgramCreatorAsm()
{
    delete[] m_pvConstantBuffer;
}
//---------------------------------------------------------------------------
inline unsigned int NiD3DShaderProgramCreatorAsm::GetShaderCreationFlags()
    const
{
    return m_uiShaderCreationFlags;
}
//---------------------------------------------------------------------------
inline void NiD3DShaderProgramCreatorAsm::SetShaderCreationFlags(
    unsigned int uiFlags)
{
    m_uiShaderCreationFlags = uiFlags;
}
//---------------------------------------------------------------------------
inline void NiD3DShaderProgramCreatorAsm::_SDMInit()
{
    ms_pkCreator = new NiD3DShaderProgramCreatorAsm();

    NiD3DShaderProgramFactory::RegisterShaderCreator("vsh", ms_pkCreator);
    NiD3DShaderProgramFactory::RegisterShaderCreator("psh", ms_pkCreator);
}
//---------------------------------------------------------------------------
inline void NiD3DShaderProgramCreatorAsm::_SDMShutdown()
{
    Shutdown();
}
//---------------------------------------------------------------------------
inline NiD3DShaderProgramCreatorAsm* 
    NiD3DShaderProgramCreatorAsm::GetInstance()
{
    return ms_pkCreator;
}
//---------------------------------------------------------------------------
inline void NiD3DShaderProgramCreatorAsm::Shutdown()
{
    if (ms_pkCreator)
        NiD3DShaderProgramFactory::UnregisterShaderCreator(ms_pkCreator);
    delete ms_pkCreator;
    ms_pkCreator = NULL;
}
//---------------------------------------------------------------------------
