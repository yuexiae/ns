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
// NiD3DPass inline functions
//---------------------------------------------------------------------------
inline const char* NiD3DPass::GetName() const
{
    return m_szName;
}
//---------------------------------------------------------------------------
inline void NiD3DPass::SetName(char* pcName)
{
    if (pcName)
        strncpy(m_szName, pcName, NID3DPASS_NAME_LEN);
    else
        strcpy(m_szName, "");
}
//---------------------------------------------------------------------------
inline NiD3DRenderStateGroup* NiD3DPass::GetRenderStateGroup() const
{
    return m_pkRenderStateGroup;
}
//---------------------------------------------------------------------------
inline void NiD3DPass::SetRenderStateGroup(
    NiD3DRenderStateGroup* pkRenderStateGroup)
{
    if (m_pkRenderStateGroup != pkRenderStateGroup)
        NiD3DRenderStateGroup::ReleaseRenderStateGroup(m_pkRenderStateGroup);

    m_pkRenderStateGroup = pkRenderStateGroup;
}
//---------------------------------------------------------------------------
inline void NiD3DPass::SetRenderState(unsigned int uiRenderState, 
    unsigned int uiValue, bool bSave)
{
    if (m_pkRenderStateGroup == NULL)
    {
        m_pkRenderStateGroup = 
            NiD3DRenderStateGroup::GetFreeRenderStateGroup();
    }
    m_pkRenderStateGroup->SetRenderState(uiRenderState, uiValue, bSave);
}
//---------------------------------------------------------------------------
inline bool NiD3DPass::RemoveRenderState(unsigned int uiRenderState)
{
    bool bReturn = false;
    if (m_pkRenderStateGroup != NULL)
    {
        m_pkRenderStateGroup->RemoveRenderState(uiRenderState);
        bReturn = true;
    }
    return bReturn;
}
//---------------------------------------------------------------------------
inline bool NiD3DPass::GetRenderState(unsigned int uiRenderState, 
    unsigned int& uiValue, bool& bSave) const
{
    bool bReturn = false;
    if (m_pkRenderStateGroup != NULL)
    {
        m_pkRenderStateGroup->GetRenderState(uiRenderState, uiValue, bSave);
        bReturn = true;
    }
    return bReturn;
}
//---------------------------------------------------------------------------
inline NiD3DSCM_Pixel* NiD3DPass::GetPixelConstantMap() const
{
    return m_spPixelConstantMap;
}
//---------------------------------------------------------------------------
inline void NiD3DPass::SetPixelConstantMap(NiD3DSCM_Pixel* pkSCMPixel)
{
    m_spPixelConstantMap = pkSCMPixel;
}
//---------------------------------------------------------------------------
inline const char* NiD3DPass::GetPixelShaderProgramFileName() const
{
    return m_pcPixelShaderProgramFile;
}
//---------------------------------------------------------------------------
inline void NiD3DPass::SetPixelShaderProgramFileName(
    const char* pcProgramFile)
{
    delete [] m_pcPixelShaderProgramFile;
    m_pcPixelShaderProgramFile = 0;

    if (pcProgramFile && strcmp(pcProgramFile, ""))
    {
        m_pcPixelShaderProgramFile = new char[strlen(pcProgramFile) + 1];
        assert(m_pcPixelShaderProgramFile);

        strcpy(m_pcPixelShaderProgramFile, pcProgramFile);
    }
}
//---------------------------------------------------------------------------
inline const char* NiD3DPass::GetPixelShaderProgramEntryPoint() const
{
    return m_pcPixelShaderEntryPoint;
}
//---------------------------------------------------------------------------
inline void NiD3DPass::SetPixelShaderProgramEntryPoint(
    const char* pcEntryPoint)
{
    delete [] m_pcPixelShaderEntryPoint;
    m_pcPixelShaderEntryPoint = 0;

    if (pcEntryPoint && strcmp(pcEntryPoint, ""))
    {
        m_pcPixelShaderEntryPoint = new char[strlen(pcEntryPoint) + 1];
        assert(m_pcPixelShaderEntryPoint);

        strcpy(m_pcPixelShaderEntryPoint, pcEntryPoint);
    }
}
//---------------------------------------------------------------------------
inline const char* NiD3DPass::GetPixelShaderProgramShaderTarget() const
{
    return m_pcPixelShaderTarget;
}
//---------------------------------------------------------------------------
inline void NiD3DPass::SetPixelShaderProgramShaderTarget(
    const char* pcShaderTarget)
{
    delete [] m_pcPixelShaderTarget;
    m_pcPixelShaderTarget = 0;

    if (pcShaderTarget && strcmp(pcShaderTarget, ""))
    {
        m_pcPixelShaderTarget = new char[strlen(pcShaderTarget) + 1];
        assert(m_pcPixelShaderTarget);

        strcpy(m_pcPixelShaderTarget, pcShaderTarget);
    }
}
//---------------------------------------------------------------------------
inline NiD3DPixelShader* NiD3DPass::GetPixelShader() const
{
    return m_spPixelShader;
}
//---------------------------------------------------------------------------
inline void NiD3DPass::SetPixelShader(NiD3DPixelShader* pkPixelShader)
{
    m_spPixelShader = pkPixelShader;
}
//---------------------------------------------------------------------------
inline NiD3DSCM_Vertex* NiD3DPass::GetVertexConstantMap() const
{
    return m_spVertexConstantMap;
}
//---------------------------------------------------------------------------
inline void NiD3DPass::SetVertexConstantMap(NiD3DSCM_Vertex* pkSCMVertex)
{
    m_spVertexConstantMap = pkSCMVertex;
}
//---------------------------------------------------------------------------
inline const char* NiD3DPass::GetVertexShaderProgramFileName() const
{
    return m_pcVertexShaderProgramFile;
}
//---------------------------------------------------------------------------
inline void NiD3DPass::SetVertexShaderProgramFileName(
    const char* pcProgramFile)
{
    delete [] m_pcVertexShaderProgramFile;
    m_pcVertexShaderProgramFile = 0;

    if (pcProgramFile && strcmp(pcProgramFile, ""))
    {
        m_pcVertexShaderProgramFile = new char[strlen(pcProgramFile) + 1];
        assert(m_pcVertexShaderProgramFile);

        strcpy(m_pcVertexShaderProgramFile, pcProgramFile);
    }
}
//---------------------------------------------------------------------------
inline const char* NiD3DPass::GetVertexShaderProgramEntryPoint() const
{
    return m_pcVertexShaderEntryPoint;
}
//---------------------------------------------------------------------------
inline void NiD3DPass::SetVertexShaderProgramEntryPoint(
    const char* pcEntryPoint)
{
    delete [] m_pcVertexShaderEntryPoint;
    m_pcVertexShaderEntryPoint = 0;

    if (pcEntryPoint && strcmp(pcEntryPoint, ""))
    {
        m_pcVertexShaderEntryPoint = new char[strlen(pcEntryPoint) + 1];
        assert(m_pcVertexShaderEntryPoint);

        strcpy(m_pcVertexShaderEntryPoint, pcEntryPoint);
    }
}
//---------------------------------------------------------------------------
inline const char* NiD3DPass::GetVertexShaderProgramShaderTarget() const
{
    return m_pcVertexShaderTarget;
}
//---------------------------------------------------------------------------
inline void NiD3DPass::SetVertexShaderProgramShaderTarget(
    const char* pcShaderTarget)
{
    delete [] m_pcVertexShaderTarget;
    m_pcVertexShaderTarget = 0;

    if (pcShaderTarget && strcmp(pcShaderTarget, ""))
    {
        m_pcVertexShaderTarget = new char[strlen(pcShaderTarget) + 1];
        assert(m_pcVertexShaderTarget);

        strcpy(m_pcVertexShaderTarget, pcShaderTarget);
    }
}
//---------------------------------------------------------------------------
inline NiD3DVertexShader* NiD3DPass::GetVertexShader() const
{
    return m_spVertexShader;
}
//---------------------------------------------------------------------------
inline void NiD3DPass::SetVertexShader(NiD3DVertexShader* pkVertexShader)
{
    m_spVertexShader = pkVertexShader;
}
//---------------------------------------------------------------------------
inline bool NiD3DPass::GetSoftwareVertexProcessing() const
{
    return m_bSoftwareVP;
}
//---------------------------------------------------------------------------
inline void NiD3DPass::SetSoftwareVertexProcessing(bool bSoftwareVP)
{
    m_bSoftwareVP = bSoftwareVP;
}
//---------------------------------------------------------------------------
inline unsigned int NiD3DPass::GetCurrentStage() const
{
    return m_uiCurrentStage;
}
//---------------------------------------------------------------------------
inline unsigned int NiD3DPass::GetStageCount() const
{
    return m_uiStageCount;
}
//---------------------------------------------------------------------------
inline unsigned int NiD3DPass::GetTextureCount() const
{
    return m_uiTexturesPerPass;
}
//---------------------------------------------------------------------------
inline NiD3DTextureStage* NiD3DPass::GetStage(unsigned int uiStageNum) const
{
    return m_kStages.GetAt(uiStageNum);
}
//---------------------------------------------------------------------------
inline NiD3DError NiD3DPass::AppendStage(NiD3DTextureStage* pkStage)
{
    return SetStage(m_uiCurrentStage, pkStage);
}
//---------------------------------------------------------------------------
inline unsigned int NiD3DPass::GetAvailableStages() const
{
    return ms_uiMaxTextureBlendStages - m_uiCurrentStage;
}
//---------------------------------------------------------------------------
inline unsigned int NiD3DPass::GetAvailableTextures() const
{
    return ms_uiMaxSimultaneousTextures - m_uiTexturesPerPass;
}
//---------------------------------------------------------------------------
inline unsigned int NiD3DPass::GetTotalAvailableStages() const
{
    return ms_uiMaxTextureBlendStages - m_uiStageCount;
}
//---------------------------------------------------------------------------
inline bool NiD3DPass::IsPassContiguous() const
{
    return (m_uiStageCount == m_uiCurrentStage);
}
//---------------------------------------------------------------------------
inline bool NiD3DPass::IsPassEmpty() const
{
    return (m_uiStageCount == 0);
}
//---------------------------------------------------------------------------
inline void NiD3DPass::IncRefCount()
{
    m_uiRefCount++;
}
//---------------------------------------------------------------------------
inline void NiD3DPass::DecRefCount()
{
    m_uiRefCount--;
    if (m_uiRefCount == 0)
    {
        ReturnPassToPool();
    }
}
//---------------------------------------------------------------------------
