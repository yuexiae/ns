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
inline NiD3DShaderProgramFactory* NiD3DShaderProgramFactory::Create()
{
    if (!ms_pkFactory)
        ms_pkFactory = new NiD3DShaderProgramFactory();

    return ms_pkFactory;
}
//---------------------------------------------------------------------------
#if defined(_XBOX)
//---------------------------------------------------------------------------
inline NiD3DShaderProgramFactory::FFShaderInfo::FFShaderInfo() :
    m_iRefCount(0), 
    m_uiVSHandle(0), 
    m_uiDeclarationCount(0), 
    m_pdwDeclaration(0)
{
}
//---------------------------------------------------------------------------
inline NiD3DShaderProgramFactory::FFShaderInfo::FFShaderInfo(
    unsigned int uiDeclarationCount, DWORD* pdwDeclaration, 
    unsigned int uiVSHandle) :
    m_iRefCount(0), 
    m_uiVSHandle(uiVSHandle), 
    m_uiDeclarationCount(0), 
    m_pdwDeclaration(0)
{
    SetDeclaration(uiDeclarationCount, pdwDeclaration);
}
//---------------------------------------------------------------------------
inline NiD3DShaderProgramFactory::FFShaderInfo::~FFShaderInfo()
{
    delete [] m_pdwDeclaration;
}
//---------------------------------------------------------------------------
inline const unsigned int 
NiD3DShaderProgramFactory::FFShaderInfo::GetVSHandle() const
{
    return m_uiVSHandle;
}
//---------------------------------------------------------------------------
inline const unsigned int 
NiD3DShaderProgramFactory::FFShaderInfo::GetDeclarationCount() const
{
    return m_uiDeclarationCount;
}
//---------------------------------------------------------------------------
inline const DWORD* 
NiD3DShaderProgramFactory::FFShaderInfo::GetDeclaration() const
{
    return m_pdwDeclaration;
}
//---------------------------------------------------------------------------
inline void NiD3DShaderProgramFactory::FFShaderInfo::SetVSHandle(
    unsigned int uiVSHandle)
{
    m_uiVSHandle = uiVSHandle;
}
//---------------------------------------------------------------------------
inline void NiD3DShaderProgramFactory::FFShaderInfo::SetDeclaration(
    unsigned int uiDeclarationCount, DWORD* pdwDeclaration)
{
    delete [] m_pdwDeclaration;
    m_pdwDeclaration = 0;
    m_uiDeclarationCount = 0;

    if (uiDeclarationCount && pdwDeclaration)
    {
        m_uiDeclarationCount = uiDeclarationCount;
        m_pdwDeclaration = new DWORD[m_uiDeclarationCount];
        assert(m_pdwDeclaration);
        memcpy((void*)m_pdwDeclaration, (const void*)pdwDeclaration,
            sizeof(DWORD) * m_uiDeclarationCount);
    }
}
//---------------------------------------------------------------------------
inline const int NiD3DShaderProgramFactory::FFShaderInfo::GetRefCount() const
{
    return m_iRefCount;
}
//---------------------------------------------------------------------------
inline int NiD3DShaderProgramFactory::FFShaderInfo::IncRefCount()
{
    m_iRefCount++;
    return m_iRefCount;
}
//---------------------------------------------------------------------------
inline int NiD3DShaderProgramFactory::FFShaderInfo::DecRefCount()
{
    m_iRefCount--;
    return m_iRefCount;
}
//---------------------------------------------------------------------------
#endif  //#if defined(_XBOX)
//---------------------------------------------------------------------------
