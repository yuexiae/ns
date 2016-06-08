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
// NSBPass inline functions
//---------------------------------------------------------------------------
inline const char* NSBPass::GetName() const
{
    return m_pcName;
}
//---------------------------------------------------------------------------
inline const char* NSBPass::GetPixelShaderProgramFile() const
{
#if defined(_XBOX)
    return m_pcPixelShaderProgramFileXBox;
#elif defined(_DX8)
    return m_pcPixelShaderProgramFileDX8;
#elif defined(_DX9)
    return m_pcPixelShaderProgramFileDX9;
#endif  //#if defined(_XBOX)
}
//---------------------------------------------------------------------------
inline const char* NSBPass::GetVertexShaderProgramFile() const
{
#if defined(_XBOX)
    return m_pcVertexShaderProgramFileXBox;
#elif defined(_DX8)
    return m_pcVertexShaderProgramFileDX8;
#elif defined(_DX9)
    return m_pcVertexShaderProgramFileDX9;
#endif  //#if defined(_XBOX)
}
//---------------------------------------------------------------------------
inline const char* NSBPass::GetPixelShaderProgramEntryPoint() const
{
    return m_pcVSProgramEntryPoint;
}
//---------------------------------------------------------------------------
inline const char* NSBPass::GetPixelShaderProgramShaderTarget() const
{
    return m_pcVSProgramTarget;
}
//---------------------------------------------------------------------------
inline const char* NSBPass::GetVertexShaderProgramEntryPoint() const
{
    return m_pcVSProgramEntryPoint;
}
//---------------------------------------------------------------------------
inline const char* NSBPass::GetVertexShaderProgramShaderTarget() const
{
    return m_pcVSProgramTarget;
}
//---------------------------------------------------------------------------
inline bool NSBPass::GetSoftwareVertexProcessing() const
{
    return m_bSoftwareVP;
}
//---------------------------------------------------------------------------
inline void NSBPass::SetSoftwareVertexProcessing(bool bSoftwareVP)
{
    m_bSoftwareVP = bSoftwareVP;
}
//---------------------------------------------------------------------------
inline NSBUserDefinedDataSet* NSBPass::GetUserDefinedDataSet()
{
    return m_spUserDefinedDataSet;
}
//---------------------------------------------------------------------------
inline void NSBPass::SetUserDefinedDataSet(NSBUserDefinedDataSet* pkUDDSet)
{
    m_spUserDefinedDataSet = pkUDDSet;
}
//---------------------------------------------------------------------------
