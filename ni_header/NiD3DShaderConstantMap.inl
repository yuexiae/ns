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
// NiD3DShaderConstantMap inline functions
//---------------------------------------------------------------------------
inline NiD3DShaderConstantMap::PredefinedMapping::PredefinedMapping(
    unsigned int uiMappingID, char* pszMappingName)
{
    m_uiMappingID = uiMappingID;
    m_pszMappingName = pszMappingName;
}
//---------------------------------------------------------------------------
inline NiD3DShaderConstantMap::NiD3DShaderConstantMap(
    NiD3DRenderer* pkRenderer) :
    m_pkD3DDevice(NULL), 
    m_pkD3DRenderer(NULL), 
    m_pkD3DRenderState(NULL), 
    m_eUsage(NiD3DShaderConstantMap::SCM_USAGE_VERTEX), 
    m_bModified(true),
    m_eLastError(NISHADERERR_OK),
    m_pkLastShaderProgram(NULL)
{
    SetD3DRenderer(pkRenderer);
    m_aspEntries.RemoveAll();
}
//---------------------------------------------------------------------------
inline const NiD3DShaderConstantMap::Usage NiD3DShaderConstantMap::GetUsage()
{
    return m_eUsage;
}
//---------------------------------------------------------------------------
inline bool NiD3DShaderConstantMap::GetModified()
{
    return m_bModified;
}
//---------------------------------------------------------------------------
inline void NiD3DShaderConstantMap::SetModified(bool bModified)
{
    m_bModified = bModified;
}
//---------------------------------------------------------------------------
inline NiD3DError NiD3DShaderConstantMap::GetLastError()
{
    return m_eLastError;
}
//---------------------------------------------------------------------------
inline unsigned int NiD3DShaderConstantMap::GetEntryCount()
{
    return m_aspEntries.GetEffectiveSize();
}
//---------------------------------------------------------------------------
inline const char* NiD3DShaderConstantMap::GetTimeExtraDataName()
{
    return ms_pcTimeExtraDataName;
}
//---------------------------------------------------------------------------
