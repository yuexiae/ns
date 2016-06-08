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
// NiBinaryShader inline functions
//---------------------------------------------------------------------------
inline NSBUserDefinedDataSet* NiBinaryShader::GetShaderUserDefinedDataSet()
{
    return m_spUDDSet_Shader;
}
//---------------------------------------------------------------------------
inline NSBUserDefinedDataSet* 
NiBinaryShader::GetImplementationUserDefinedDataSet()
{
    return m_spUDDSet_Implementation;
}
//---------------------------------------------------------------------------
inline NSBUserDefinedDataSet* NiBinaryShader::GetPassUserDefinedDataSet(
    unsigned int uiPass)
{
    if (uiPass > m_uiPassCount)
        return 0;

    return m_kUDDSet_PassArray.GetAt(uiPass);
}
//---------------------------------------------------------------------------
inline void NiBinaryShader::SetUserDefinedDataSet(
    NSBUserDefinedDataSet* pkUDDSet)
{
    m_spUDDSet_Shader = pkUDDSet;
}
//---------------------------------------------------------------------------
inline void NiBinaryShader::SetImplementationUserDefinedDataSet(
    NSBUserDefinedDataSet* pkUDDSet)
{
    m_spUDDSet_Implementation = pkUDDSet;
}
//---------------------------------------------------------------------------
inline void NiBinaryShader::SetPassUserDefinedDataSet(unsigned int uiPass, 
    NSBUserDefinedDataSet* pkUDDSet)
{
    m_kUDDSet_PassArray.SetAtGrow(uiPass, pkUDDSet);
}
//---------------------------------------------------------------------------
inline NiD3DShaderDeclaration* NiBinaryShader::GetShaderDecl()
{
    return m_spShaderDecl;
}
//---------------------------------------------------------------------------
inline void NiBinaryShader::SetShaderDecl(
    NiD3DShaderDeclaration* pkShaderDecl)
{
    m_spShaderDecl = pkShaderDecl;
}
//---------------------------------------------------------------------------
inline NiD3DRenderStateGroup* NiBinaryShader::GetRenderStateGroup(void)
{
    return m_pkRenderStateGroup;
}
//---------------------------------------------------------------------------
inline void NiBinaryShader::SetRenderStateGroup(
    NiD3DRenderStateGroup* pkRenderStateGroup)
{
    m_pkRenderStateGroup = pkRenderStateGroup;
}
//---------------------------------------------------------------------------
inline NiD3DSCM_Pixel* NiBinaryShader::GetPixelConstantMap(void)
{
    return m_spPixelConstantMap;
}
//---------------------------------------------------------------------------
inline void NiBinaryShader::SetPixelConstantMap(NiD3DSCM_Pixel* pkSCMPixel)
{
    m_spPixelConstantMap = pkSCMPixel;
}
//---------------------------------------------------------------------------
inline NiD3DSCM_Vertex* NiBinaryShader::GetVertexConstantMap(void)
{
    return m_spVertexConstantMap;
}
//---------------------------------------------------------------------------
inline void NiBinaryShader::SetVertexConstantMap(
    NiD3DSCM_Vertex* pkSCMVertex)
{
    m_spVertexConstantMap = pkSCMVertex;
}
//---------------------------------------------------------------------------
inline bool NiBinaryShader::InsertPass(unsigned int uiPass, 
    NiD3DPass* pkPass)
{
    // Increment the pass if there was none there previously
    if (m_kPasses.GetAllocatedSize() <= uiPass ||
        m_kPasses.GetAt(uiPass) == 0)
    {
        m_uiPassCount++;
    }

    m_kPasses.SetAtGrow(uiPass, pkPass);
    
    m_kUDDSet_PassArray.SetSize(m_uiPassCount);

    return true;
}
//---------------------------------------------------------------------------
inline D3DDevicePtr NiBinaryShader::GetD3DDevice()
{
    return m_pkD3DDevice;
}
//---------------------------------------------------------------------------
inline NiD3DRenderer* NiBinaryShader::GetD3DRenderer()
{
    return m_pkD3DRenderer;
}
//---------------------------------------------------------------------------
inline NiD3DRenderState* NiBinaryShader::GetD3DRenderState()
{
    return m_pkD3DRenderState;
}
//---------------------------------------------------------------------------
inline unsigned int NiBinaryShader::GetBonesPerPartition() const
{
    return m_uiBonesPerPartition;
}
//---------------------------------------------------------------------------
inline void NiBinaryShader::SetBonesPerPartition(unsigned int uiBones)
{
    m_uiBonesPerPartition = uiBones;
}
//---------------------------------------------------------------------------
inline unsigned int NiBinaryShader::GetBoneMatrixRegisters() const
{
    return m_uiBoneMatrixRegisters;
}
//---------------------------------------------------------------------------
inline void NiBinaryShader::SetBoneMatrixRegisters(unsigned int uiRegisters)
{
    m_uiBoneMatrixRegisters = uiRegisters;
}
//---------------------------------------------------------------------------
inline NiBinaryShader::BoneMatrixCalcMethod 
NiBinaryShader::GetBoneCalcMethod() const
{
    return m_eBoneCalcMethod;
}
//---------------------------------------------------------------------------
inline void NiBinaryShader::SetBoneCalcMethod(
    NiBinaryShader::BoneMatrixCalcMethod eMethod)
{
    m_eBoneCalcMethod = eMethod;
}
//---------------------------------------------------------------------------
inline NiGeometryData::DataFlags NiBinaryShader::GetBinormalTangentMethod() 
    const
{
    return m_eBinormalTangentMethod;
}
//---------------------------------------------------------------------------
inline void NiBinaryShader::SetBinormalTangentMethod(
    NiGeometryData::DataFlags eNBTMethod)
{
    m_eBinormalTangentMethod = eNBTMethod;
}
//---------------------------------------------------------------------------
