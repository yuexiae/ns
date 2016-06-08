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
// NSBShader inline functions
//---------------------------------------------------------------------------
inline NSBShader::CREATENIBINARYSHADER 
NSBShader::SetCreateNiBinaryShaderCallback(
    NSBShader::CREATENIBINARYSHADER pfnCallback)
{
    CREATENIBINARYSHADER pfnOld = ms_pfnCreateNiBinaryShader;

    if (pfnCallback)
        ms_pfnCreateNiBinaryShader = pfnCallback;
    else
        ms_pfnCreateNiBinaryShader = DefaultCreateNiBinaryShader;

    return pfnOld;
}
//---------------------------------------------------------------------------
inline NSBShader::CREATENIBINARYSHADER 
NSBShader::GetCreateNiBinaryShaderCallback()
{
    return ms_pfnCreateNiBinaryShader;
}
//---------------------------------------------------------------------------
inline const char* NSBShader::GetName()
{
    return m_pszName;
}
//---------------------------------------------------------------------------
inline const char* NSBShader::GetDescription()
{
    return m_pszDescription;
}
//---------------------------------------------------------------------------
inline unsigned int NSBShader::GetMinPixelShaderVersion()
{
    return m_uiMinPixelShaderVersion;
}
//---------------------------------------------------------------------------
inline unsigned int NSBShader::GetMaxPixelShaderVersion()
{
    return m_uiMaxPixelShaderVersion;
}
//---------------------------------------------------------------------------
inline unsigned int NSBShader::GetMinVertexShaderVersion()
{
    return m_uiMinVertexShaderVersion;
}
//---------------------------------------------------------------------------
inline unsigned int NSBShader::GetMaxVertexShaderVersion()
{
    return m_uiMaxVertexShaderVersion;
}
//---------------------------------------------------------------------------
inline unsigned int NSBShader::GetMinUserVersion()
{
    return m_uiMinUserVersion;
}
//---------------------------------------------------------------------------
inline unsigned int NSBShader::GetMaxUserVersion()
{
    return m_uiMaxUserVersion;
}
//---------------------------------------------------------------------------
inline unsigned int NSBShader::GetPlatform()
{
    return m_uiPlatform;
}
//---------------------------------------------------------------------------
inline NSBAttributeTable* NSBShader::GetGlobalAttributeTable()
{
    return &m_kGlobalAttribTable;
}
//---------------------------------------------------------------------------
inline NSBAttributeTable* NSBShader::GetAttributeTable()
{
    return &m_kAttribTable;
}
//---------------------------------------------------------------------------
inline void NSBShader::SetMinPixelShaderVersionRequest(
    unsigned int uiVersion)
{
    m_uiMinPixelShaderVersionRequest = uiVersion;
}
//---------------------------------------------------------------------------
inline void NSBShader::SetMaxPixelShaderVersionRequest(
    unsigned int uiVersion)
{
    m_uiMaxPixelShaderVersionRequest = uiVersion;
}
//---------------------------------------------------------------------------
inline void NSBShader::SetMinVertexShaderVersionRequest(
    unsigned int uiVersion)
{
    m_uiMinVertexShaderVersionRequest = uiVersion;
}
//---------------------------------------------------------------------------
inline void NSBShader::SetMaxVertexShaderVersionRequest(
    unsigned int uiVersion)
{
    m_uiMaxVertexShaderVersionRequest = uiVersion;
}
//---------------------------------------------------------------------------
inline void NSBShader::SetMinUserVersionRequest(unsigned int uiVersion)
{
    m_uiMinUserVersionRequest = uiVersion;
}
//---------------------------------------------------------------------------
inline void NSBShader::SetMaxUserVersionRequest(unsigned int uiVersion)
{
    m_uiMaxUserVersionRequest = uiVersion;
}
//---------------------------------------------------------------------------
inline void NSBShader::AddPlatform(unsigned int uiPlatformFlag)
{
    m_uiPlatform |= uiPlatformFlag;
}
//---------------------------------------------------------------------------
/***
inline void NSBShader::RemovePlatform(unsigned int uiPlatformFlag)
{
    m_uiPlatform &= ~uiPlatformFlag;
}
***/
//---------------------------------------------------------------------------
inline void NSBShader::SetPlatformRequest(unsigned int uiPlatform)
{
    m_uiPlatformRequest = uiPlatform;
}
//---------------------------------------------------------------------------
inline void NSBShader::AddPixelShaderVersion(unsigned int uiVersion)
{
    if (m_uiMinPixelShaderVersion > uiVersion)
        m_uiMinPixelShaderVersion = uiVersion;
    if (m_uiMaxPixelShaderVersion < uiVersion)
        m_uiMaxPixelShaderVersion = uiVersion;
}
//---------------------------------------------------------------------------
inline void NSBShader::AddVertexShaderVersion(unsigned int uiVersion)
{
    if (m_uiMinVertexShaderVersion > uiVersion)
        m_uiMinVertexShaderVersion = uiVersion;
    if (m_uiMaxVertexShaderVersion < uiVersion)
        m_uiMaxVertexShaderVersion = uiVersion;
}
//---------------------------------------------------------------------------
inline void NSBShader::AddUserVersion(unsigned int uiVersion)
{
    if (m_uiMinUserVersion > uiVersion)
        m_uiMinUserVersion = uiVersion;
    if (m_uiMaxUserVersion < uiVersion)
        m_uiMaxUserVersion = uiVersion;
}
//---------------------------------------------------------------------------
inline unsigned int NSBShader::GetReadVersion()
{
    return ms_uiReadVersion;
}
//---------------------------------------------------------------------------
inline NSBUserDefinedDataSet* NSBShader::GetUserDefinedDataSet()
{
    return m_spUserDefinedDataSet;
}
//---------------------------------------------------------------------------
inline void NSBShader::SetUserDefinedDataSet(NSBUserDefinedDataSet* pkUDDSet)
{
    m_spUserDefinedDataSet = pkUDDSet;
}
//---------------------------------------------------------------------------
