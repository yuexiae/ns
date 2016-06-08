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
inline NiD3DShaderProgramCreatorObj::NiD3DShaderProgramCreatorObj()
{ /* */ }
//---------------------------------------------------------------------------
inline NiD3DShaderProgramCreatorObj::~NiD3DShaderProgramCreatorObj()
{ /* */ }
//---------------------------------------------------------------------------
inline void NiD3DShaderProgramCreatorObj::_SDMInit()
{
    ms_pkCreator = new NiD3DShaderProgramCreatorObj();

    NiD3DShaderProgramFactory::RegisterShaderCreator("vso", ms_pkCreator);
    NiD3DShaderProgramFactory::RegisterShaderCreator("pso", ms_pkCreator);
}
//---------------------------------------------------------------------------
inline void NiD3DShaderProgramCreatorObj::_SDMShutdown()
{
    Shutdown();
}
//---------------------------------------------------------------------------
inline NiD3DShaderProgramCreatorObj* 
    NiD3DShaderProgramCreatorObj::GetInstance()
{
    return ms_pkCreator;
}
//---------------------------------------------------------------------------
inline void NiD3DShaderProgramCreatorObj::Shutdown()
{
    if (ms_pkCreator)
        NiD3DShaderProgramFactory::UnregisterShaderCreator(ms_pkCreator);
    delete ms_pkCreator;
    ms_pkCreator = NULL;
}
//---------------------------------------------------------------------------
