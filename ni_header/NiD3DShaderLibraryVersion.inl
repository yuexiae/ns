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
// NiD3DShaderLibraryVersion inline functions
//---------------------------------------------------------------------------
inline NiD3DShaderLibraryVersion::NiD3DShaderLibraryVersion() :
    m_uiSystemPixelShaderVersion(0), 
    m_uiMinPixelShaderVersion(0), 
    m_uiRequestedPixelShaderVersion(0), 
    m_uiSystemVertexShaderVersion(0), 
    m_uiMinVertexShaderVersion(0), 
    m_uiRequestedVertexShaderVersion(0), 
    m_uiSystemUserVersion(0), 
    m_uiMinUserVersion(0), 
    m_uiRequestedUserVersion(0), 
    m_uiPlatform(0)
{
}
//---------------------------------------------------------------------------
inline void NiD3DShaderLibraryVersion::SetSystemPixelShaderVersion(
    unsigned int uiVersion)
{
    m_uiSystemPixelShaderVersion = uiVersion;
}
//---------------------------------------------------------------------------
inline void NiD3DShaderLibraryVersion::SetMinPixelShaderVersion(
    unsigned int uiVersion)
{
    m_uiMinPixelShaderVersion = uiVersion;
}
//---------------------------------------------------------------------------
inline void NiD3DShaderLibraryVersion::SetPixelShaderVersionRequest(
    unsigned int uiVersion)
{
    m_uiRequestedPixelShaderVersion = uiVersion;
}
//---------------------------------------------------------------------------
inline void NiD3DShaderLibraryVersion::SetSystemPixelShaderVersion(
    unsigned int uiMaj, unsigned int uiMin)
{
    m_uiSystemPixelShaderVersion = D3DPS_VERSION(uiMaj, uiMin);
}
//---------------------------------------------------------------------------
inline void NiD3DShaderLibraryVersion::SetMinPixelShaderVersion(
    unsigned int uiMaj, unsigned int uiMin)
{
    m_uiMinPixelShaderVersion = D3DPS_VERSION(uiMaj, uiMin);
}
//---------------------------------------------------------------------------
inline void NiD3DShaderLibraryVersion::SetPixelShaderVersionRequest(
    unsigned int uiMaj, unsigned int uiMin)
{
    m_uiRequestedPixelShaderVersion = D3DPS_VERSION(uiMaj, uiMin);
}
//---------------------------------------------------------------------------
inline void NiD3DShaderLibraryVersion::SetSystemVertexShaderVersion(
    unsigned int uiVersion)
{
    m_uiSystemVertexShaderVersion = uiVersion;
}
//---------------------------------------------------------------------------
inline void NiD3DShaderLibraryVersion::SetMinVertexShaderVersion(
    unsigned int uiVersion)
{
    m_uiMinVertexShaderVersion = uiVersion;
}
//---------------------------------------------------------------------------
inline void NiD3DShaderLibraryVersion::SetVertexShaderVersionRequest(
    unsigned int uiVersion)
{
    m_uiRequestedVertexShaderVersion = uiVersion;
}
//---------------------------------------------------------------------------
inline void NiD3DShaderLibraryVersion::SetSystemVertexShaderVersion(
    unsigned int uiMaj, unsigned int uiMin)
{
    m_uiSystemVertexShaderVersion = D3DVS_VERSION(uiMaj, uiMin);
}
//---------------------------------------------------------------------------
inline void NiD3DShaderLibraryVersion::SetMinVertexShaderVersion(
    unsigned int uiMaj, unsigned int uiMin)
{
    m_uiMinVertexShaderVersion = D3DVS_VERSION(uiMaj, uiMin);
}
//---------------------------------------------------------------------------
inline void NiD3DShaderLibraryVersion::SetVertexShaderVersionRequest(
    unsigned int uiMaj, unsigned int uiMin)
{
    m_uiRequestedVertexShaderVersion = D3DVS_VERSION(uiMaj, uiMin);
}
//---------------------------------------------------------------------------
inline void NiD3DShaderLibraryVersion::SetSystemUserVersion(
    unsigned int uiVersion)
{
    m_uiSystemUserVersion = uiVersion;
}
//---------------------------------------------------------------------------
inline void NiD3DShaderLibraryVersion::SetMinUserVersion(
    unsigned int uiVersion)
{
    m_uiMinUserVersion = uiVersion;
}
//---------------------------------------------------------------------------
inline void NiD3DShaderLibraryVersion::SetUserVersionRequest(
    unsigned int uiVersion)
{
    m_uiRequestedUserVersion = uiVersion;
}
//---------------------------------------------------------------------------
inline void NiD3DShaderLibraryVersion::SetSystemUserVersion(
    unsigned int uiMaj, unsigned int uiMin)
{
    m_uiSystemUserVersion = D3DVS_VERSION(uiMaj, uiMin);
}
//---------------------------------------------------------------------------
inline void NiD3DShaderLibraryVersion::SetMinUserVersion(
    unsigned int uiMaj, unsigned int uiMin)
{
    m_uiMinUserVersion = D3DVS_VERSION(uiMaj, uiMin);
}
//---------------------------------------------------------------------------
inline void NiD3DShaderLibraryVersion::SetUserVersionRequest(
    unsigned int uiMaj, unsigned int uiMin)
{
    m_uiRequestedUserVersion = D3DVS_VERSION(uiMaj, uiMin);
}
//---------------------------------------------------------------------------
inline void NiD3DShaderLibraryVersion::SetPlatform(unsigned int uiPlatform)
{
    m_uiPlatform = uiPlatform;
}
//---------------------------------------------------------------------------
inline unsigned int NiD3DShaderLibraryVersion::GetSystemPixelShaderVersion()
{
    return m_uiSystemPixelShaderVersion;
}
//---------------------------------------------------------------------------
inline unsigned int NiD3DShaderLibraryVersion::GetMinPixelShaderVersion()
{
    return m_uiMinPixelShaderVersion;
}
//---------------------------------------------------------------------------
inline unsigned int NiD3DShaderLibraryVersion::GetPixelShaderVersionRequest()
{
    return m_uiRequestedPixelShaderVersion;
}
//---------------------------------------------------------------------------
inline unsigned int NiD3DShaderLibraryVersion::GetSystemVertexShaderVersion()
{
    return m_uiSystemVertexShaderVersion;
}
//---------------------------------------------------------------------------
inline unsigned int NiD3DShaderLibraryVersion::GetMinVertexShaderVersion()
{
    return m_uiMinVertexShaderVersion;
}
//---------------------------------------------------------------------------
inline unsigned int 
NiD3DShaderLibraryVersion::GetVertexShaderVersionRequest()
{
    return m_uiRequestedVertexShaderVersion;
}
//---------------------------------------------------------------------------
inline unsigned int NiD3DShaderLibraryVersion::GetSystemUserVersion()
{
    return m_uiSystemUserVersion;
}
//---------------------------------------------------------------------------
inline unsigned int NiD3DShaderLibraryVersion::GetMinUserVersion()
{
    return m_uiMinUserVersion;
}
//---------------------------------------------------------------------------
inline unsigned int NiD3DShaderLibraryVersion::GetUserVersionRequest()
{
    return m_uiRequestedUserVersion;
}
//---------------------------------------------------------------------------
inline unsigned int NiD3DShaderLibraryVersion::GetPlatform()
{
    return m_uiPlatform;
}
//---------------------------------------------------------------------------

