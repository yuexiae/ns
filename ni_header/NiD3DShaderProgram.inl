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
// NiD3DShaderProgram inline functions
//---------------------------------------------------------------------------
inline const char* NiD3DShaderProgram::GetName() const
{
    return m_pszName;
}
//---------------------------------------------------------------------------
inline void NiD3DShaderProgram::SetName(const char* pszName)
{
    if (pszName && strcmp(pszName, ""))
    {
        unsigned int uiNewLen = strlen(pszName) + 1;
        if (m_pszName)
        {
            if (strlen(m_pszName) < uiNewLen)
            {
                delete [] m_pszName;
                m_pszName = 0;
            }
        }

        if (!m_pszName)
            m_pszName = new char[uiNewLen];
        
        assert(m_pszName);
        strcpy(m_pszName, pszName);
    }
    else
    {
        delete [] m_pszName;
        m_pszName = 0;
    }
}
//---------------------------------------------------------------------------
inline const char* NiD3DShaderProgram::GetShaderProgramName() const
{
    return m_pszShaderProgramName;
}
//---------------------------------------------------------------------------
inline void NiD3DShaderProgram::SetShaderProgramName(const char* pszName)
{
    if (pszName && strcmp(pszName, ""))
    {
        unsigned int uiNewLen = strlen(pszName) + 1;
        if (m_pszShaderProgramName)
        {
            if (strlen(m_pszShaderProgramName) < uiNewLen)
            {
                delete [] m_pszShaderProgramName;
                m_pszShaderProgramName = 0;
            }
        }

        if (!m_pszShaderProgramName)
            m_pszShaderProgramName = new char[uiNewLen];
        
        assert(m_pszShaderProgramName);
        strcpy(m_pszShaderProgramName, pszName);
    }
    else
    {
        // This is likely a very bad thing...
        delete [] m_pszShaderProgramName;
        m_pszShaderProgramName = 0;
    }
}
//---------------------------------------------------------------------------
inline unsigned int NiD3DShaderProgram::GetCodeSize() const
{
    return m_uiCodeSize;
}
//---------------------------------------------------------------------------
inline void* NiD3DShaderProgram::GetCode() const
{
    return m_pvCode;
}
//---------------------------------------------------------------------------
inline void NiD3DShaderProgram::SetCode(unsigned int uiSize, void* pvCode)
{
    m_uiCodeSize = uiSize;
    m_pvCode = pvCode;
}
//---------------------------------------------------------------------------
inline NiD3DShaderProgramCreator* NiD3DShaderProgram::GetCreator() const
{
    return m_pkCreator;
}
//---------------------------------------------------------------------------
inline void NiD3DShaderProgram::SetCreator(
    NiD3DShaderProgramCreator* pkCreator)
{
    m_pkCreator = pkCreator;
}
//---------------------------------------------------------------------------
