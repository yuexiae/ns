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
// NiD3DShaderConstantMapEntry inline functions
//---------------------------------------------------------------------------
inline NiD3DShaderConstantMapEntry::NiD3DShaderConstantMapEntry() :
    m_pszKey(0), 
    m_uiFlags(0), 
    m_uiExtra(0), 
    m_uiShaderRegister(0), 
    m_uiRegisterCount(0), 
    m_pszVariableName(0),
    m_uiDataSize(0), 
    m_uiDataStride(0), 
    m_pvDataSource(0), 
    m_bOwnData(false)
{
    if (ms_bTableInitialized == false)
        InitializeTable();
}
//---------------------------------------------------------------------------
inline NiD3DShaderConstantMapEntry::NiD3DShaderConstantMapEntry(
    const char* pszKey, unsigned int uiFlags, unsigned int uiExtra, 
    unsigned int uiShaderRegister, unsigned int uiRegisterCount, 
    unsigned int uiDataSize, unsigned int uiDataStride, 
    void* pvDataSource, bool bCopyData)
{
    SetKey(pszKey);
    m_uiFlags = uiFlags;
    m_uiExtra = uiExtra;
    m_uiShaderRegister = uiShaderRegister;
    m_uiRegisterCount = uiRegisterCount;
    SetData(uiDataSize, uiDataStride, pvDataSource, bCopyData);
}
//---------------------------------------------------------------------------
inline NiD3DShaderConstantMapEntry::~NiD3DShaderConstantMapEntry()
{
    delete [] m_pszKey;
    delete [] m_pszVariableName;
    if (m_bOwnData)
        delete [] m_pvDataSource;
}
//---------------------------------------------------------------------------
inline const char* NiD3DShaderConstantMapEntry::GetKey() const
{
    return m_pszKey;
}
//---------------------------------------------------------------------------
inline void NiD3DShaderConstantMapEntry::SetKey(const char* pszKey)
{
    if (pszKey && strcmp(pszKey, ""))
    {
        unsigned int uiNewLen = strlen(pszKey) + 1;
        if (m_pszKey)
        {
            if (strlen(m_pszKey) < uiNewLen)
            {
                delete [] m_pszKey;
                m_pszKey = 0;
            }
        }

        if (!m_pszKey)
            m_pszKey = new char[uiNewLen];
        
        assert(m_pszKey);
        strcpy(m_pszKey, pszKey);
    }
    else
    {
        // This is likely a very bad thing...
        delete [] m_pszKey;
        m_pszKey = 0;
    }
}
//---------------------------------------------------------------------------
inline unsigned int NiD3DShaderConstantMapEntry::GetFlags() const
{
    return m_uiFlags;
}
//---------------------------------------------------------------------------
inline void NiD3DShaderConstantMapEntry::SetFlags(unsigned int uiFlags)
{
    m_uiFlags = uiFlags;
}
//---------------------------------------------------------------------------
inline bool NiD3DShaderConstantMapEntry::IsConstant() const
{
    return ((m_uiFlags & SCME_MAP_MASK) == SCME_MAP_CONSTANT);
}
//---------------------------------------------------------------------------
inline bool NiD3DShaderConstantMapEntry::IsDefined() const
{
    return ((m_uiFlags & SCME_MAP_MASK) == SCME_MAP_DEFINED);
}
//---------------------------------------------------------------------------
inline bool NiD3DShaderConstantMapEntry::IsAttribute() const
{
    return ((m_uiFlags & SCME_MAP_MASK) == SCME_MAP_ATTRIBUTE);
}
//---------------------------------------------------------------------------
inline bool NiD3DShaderConstantMapEntry::IsGlobal() const
{
    return ((m_uiFlags & SCME_MAP_MASK) == SCME_MAP_GLOBAL);
}
//---------------------------------------------------------------------------
inline bool NiD3DShaderConstantMapEntry::IsOperator() const
{
    return ((m_uiFlags & SCME_MAP_MASK) == SCME_MAP_OPERATOR);
}
//---------------------------------------------------------------------------
inline bool NiD3DShaderConstantMapEntry::IsConstant(unsigned int uiFlags)
{
    return ((uiFlags & SCME_MAP_MASK) == SCME_MAP_CONSTANT);
}
//---------------------------------------------------------------------------
inline bool NiD3DShaderConstantMapEntry::IsDefined(unsigned int uiFlags)
{
    return ((uiFlags & SCME_MAP_MASK) == SCME_MAP_DEFINED);
}
//---------------------------------------------------------------------------
inline bool NiD3DShaderConstantMapEntry::IsAttribute(unsigned int uiFlags)
{
    return ((uiFlags & SCME_MAP_MASK) == SCME_MAP_ATTRIBUTE);
}
//---------------------------------------------------------------------------
inline bool NiD3DShaderConstantMapEntry::IsGlobal(unsigned int uiFlags)
{
    return ((uiFlags & SCME_MAP_MASK) == SCME_MAP_GLOBAL);
}
//---------------------------------------------------------------------------
inline bool NiD3DShaderConstantMapEntry::IsOperator(unsigned int uiFlags)
{
    return ((uiFlags & SCME_MAP_MASK) == SCME_MAP_OPERATOR);
}
//---------------------------------------------------------------------------
inline NiShaderAttributeDesc::AttributeType 
    NiD3DShaderConstantMapEntry::GetAttributeType() const
{
    return GetAttributeType(m_uiFlags);
}
//---------------------------------------------------------------------------
inline bool NiD3DShaderConstantMapEntry::IsBool() const
{
    return (GetAttributeType() == NiShaderAttributeDesc::ATTRIB_TYPE_BOOL);
}
//---------------------------------------------------------------------------
inline bool NiD3DShaderConstantMapEntry::IsString() const
{
    return (GetAttributeType() == NiShaderAttributeDesc::ATTRIB_TYPE_STRING);
}
//---------------------------------------------------------------------------
inline bool NiD3DShaderConstantMapEntry::IsUnsignedInt() const
{
    return (GetAttributeType() == 
        NiShaderAttributeDesc::ATTRIB_TYPE_UNSIGNEDINT);
}
//---------------------------------------------------------------------------
inline bool NiD3DShaderConstantMapEntry::IsFloat() const
{
    return (GetAttributeType() == NiShaderAttributeDesc::ATTRIB_TYPE_FLOAT);
}
//---------------------------------------------------------------------------
inline bool NiD3DShaderConstantMapEntry::IsPoint2() const
{
    return (GetAttributeType() == NiShaderAttributeDesc::ATTRIB_TYPE_POINT2);
}
//---------------------------------------------------------------------------
inline bool NiD3DShaderConstantMapEntry::IsPoint3() const
{
    return (GetAttributeType() == NiShaderAttributeDesc::ATTRIB_TYPE_POINT3);
}
//---------------------------------------------------------------------------
inline bool NiD3DShaderConstantMapEntry::IsPoint4() const
{
    return (GetAttributeType() == NiShaderAttributeDesc::ATTRIB_TYPE_POINT4);
}
//---------------------------------------------------------------------------
inline bool NiD3DShaderConstantMapEntry::IsMatrix3() const
{
    return (GetAttributeType() == NiShaderAttributeDesc::ATTRIB_TYPE_MATRIX3);
}
//---------------------------------------------------------------------------
inline bool NiD3DShaderConstantMapEntry::IsMatrix4() const
{
    return (GetAttributeType() == NiShaderAttributeDesc::ATTRIB_TYPE_MATRIX4);
}
//---------------------------------------------------------------------------
inline bool NiD3DShaderConstantMapEntry::IsColor() const
{
    return (GetAttributeType() == NiShaderAttributeDesc::ATTRIB_TYPE_COLOR);
}
//---------------------------------------------------------------------------
inline bool NiD3DShaderConstantMapEntry::IsTexture() const
{
    return (GetAttributeType() == NiShaderAttributeDesc::ATTRIB_TYPE_TEXTURE);
}
//---------------------------------------------------------------------------
inline bool NiD3DShaderConstantMapEntry::IsBool(unsigned int uiFlags)
{
    return (GetAttributeType(uiFlags) == 
        NiShaderAttributeDesc::ATTRIB_TYPE_BOOL);
}
//---------------------------------------------------------------------------
inline bool NiD3DShaderConstantMapEntry::IsString(unsigned int uiFlags)
{
    return (GetAttributeType(uiFlags) == 
        NiShaderAttributeDesc::ATTRIB_TYPE_STRING);
}
//---------------------------------------------------------------------------
inline bool NiD3DShaderConstantMapEntry::IsUnsignedInt(unsigned int uiFlags)
{
    return (GetAttributeType(uiFlags) == 
        NiShaderAttributeDesc::ATTRIB_TYPE_UNSIGNEDINT);
}
//---------------------------------------------------------------------------
inline bool NiD3DShaderConstantMapEntry::IsFloat(unsigned int uiFlags)
{
    return (GetAttributeType(uiFlags) == 
        NiShaderAttributeDesc::ATTRIB_TYPE_FLOAT);
}
//---------------------------------------------------------------------------
inline bool NiD3DShaderConstantMapEntry::IsPoint2(unsigned int uiFlags)
{
    return (GetAttributeType(uiFlags) == 
        NiShaderAttributeDesc::ATTRIB_TYPE_POINT2);
}
//---------------------------------------------------------------------------
inline bool NiD3DShaderConstantMapEntry::IsPoint3(unsigned int uiFlags)
{
    return (GetAttributeType(uiFlags) == 
        NiShaderAttributeDesc::ATTRIB_TYPE_POINT3);
}
//---------------------------------------------------------------------------
inline bool NiD3DShaderConstantMapEntry::IsPoint4(unsigned int uiFlags)
{
    return (GetAttributeType(uiFlags) == 
        NiShaderAttributeDesc::ATTRIB_TYPE_POINT4);
}
//---------------------------------------------------------------------------
inline bool NiD3DShaderConstantMapEntry::IsMatrix3(unsigned int uiFlags)
{
    return (GetAttributeType(uiFlags) == 
        NiShaderAttributeDesc::ATTRIB_TYPE_MATRIX3);
}
//---------------------------------------------------------------------------
inline bool NiD3DShaderConstantMapEntry::IsMatrix4(unsigned int uiFlags)
{
    return (GetAttributeType(uiFlags) == 
        NiShaderAttributeDesc::ATTRIB_TYPE_MATRIX4);
}
//---------------------------------------------------------------------------
inline bool NiD3DShaderConstantMapEntry::IsColor(unsigned int uiFlags)
{
    return (GetAttributeType(uiFlags) == 
        NiShaderAttributeDesc::ATTRIB_TYPE_COLOR);
}
//---------------------------------------------------------------------------
inline bool NiD3DShaderConstantMapEntry::IsTexture(unsigned int uiFlags)
{
    return (GetAttributeType(uiFlags) == 
        NiShaderAttributeDesc::ATTRIB_TYPE_TEXTURE);
}
//---------------------------------------------------------------------------
inline unsigned int NiD3DShaderConstantMapEntry::GetExtra() const
{
    return m_uiExtra;
}
//---------------------------------------------------------------------------
inline void NiD3DShaderConstantMapEntry::SetExtra(unsigned int uiExtra)
{
    m_uiExtra = uiExtra;
}
//---------------------------------------------------------------------------
inline unsigned int NiD3DShaderConstantMapEntry::GetShaderRegister() const
{
    return m_uiShaderRegister;
}
//---------------------------------------------------------------------------
inline void NiD3DShaderConstantMapEntry::SetShaderRegister(
    unsigned int uiShaderRegister)
{
    m_uiShaderRegister = uiShaderRegister;
}
//---------------------------------------------------------------------------
inline unsigned int NiD3DShaderConstantMapEntry::GetRegisterCount() const
{
    return m_uiRegisterCount;
}
//---------------------------------------------------------------------------
inline void NiD3DShaderConstantMapEntry::SetRegisterCount(
    unsigned int uiRegisterCount)
{
    m_uiRegisterCount = uiRegisterCount;
}
//---------------------------------------------------------------------------
inline const char* NiD3DShaderConstantMapEntry::GetVariableName() const
{
    return m_pszVariableName;
}
//---------------------------------------------------------------------------
inline void NiD3DShaderConstantMapEntry::SetVariableName(
    const char* pszVariableName)
{
    if (pszVariableName && pszVariableName[0] != '\0')
    {
        unsigned int uiNewLen = strlen(pszVariableName) + 1;
        if (m_pszVariableName)
        {
            if (strlen(m_pszVariableName) < uiNewLen)
            {
                delete [] m_pszVariableName;
                m_pszVariableName = 0;
            }
        }

        if (!m_pszVariableName)
            m_pszVariableName = new char[uiNewLen];
        
        assert(m_pszVariableName);
        strcpy(m_pszVariableName, pszVariableName);
    }
    else
    {
        // This is likely a very bad thing...
        delete [] m_pszVariableName;
        m_pszVariableName = NULL;
    }
}
//---------------------------------------------------------------------------
inline void NiD3DShaderConstantMapEntry::GetRegisterInfo(
    unsigned int& uiShaderRegister, unsigned int& uiRegisterCount, 
    const char*& pszVariableName) const
{
    uiShaderRegister = m_uiShaderRegister;
    uiRegisterCount = m_uiRegisterCount;
    pszVariableName = m_pszVariableName;
}
//---------------------------------------------------------------------------
inline void NiD3DShaderConstantMapEntry::SetRegisterInfo(
    unsigned int uiShaderRegister, unsigned int uiRegisterCount, 
    const char* pszVariableName)
{
    m_uiShaderRegister = uiShaderRegister;
    m_uiRegisterCount = uiRegisterCount;
    SetVariableName(pszVariableName);
}
//---------------------------------------------------------------------------
inline unsigned int NiD3DShaderConstantMapEntry::GetDataSize() const
{
    return m_uiDataSize;
}
//---------------------------------------------------------------------------
inline unsigned int NiD3DShaderConstantMapEntry::GetDataStride() const
{
    return m_uiDataStride;
}
//---------------------------------------------------------------------------
inline void* NiD3DShaderConstantMapEntry::GetDataSource() const
{
    return m_pvDataSource;
}
//---------------------------------------------------------------------------
inline void NiD3DShaderConstantMapEntry::GetData(unsigned int& uiDataSize, 
    unsigned int& uiDataStride, void*& pvDataSource) const
{
    uiDataSize = m_uiDataSize;
    uiDataStride = m_uiDataStride;
    pvDataSource = m_pvDataSource;
}
//---------------------------------------------------------------------------
inline void NiD3DShaderConstantMapEntry::SetData(unsigned int uiDataSize, 
    unsigned int uiDataStride, void* pvDataSource, bool bCopyData)
{
    m_uiDataSize = uiDataSize;
    m_uiDataStride = uiDataStride;

    if (bCopyData)
    {
        // Make a copy of the data.
        m_bOwnData = true;
        delete [] m_pvDataSource;
        m_pvDataSource = new unsigned char[uiDataSize];
        assert(m_pvDataSource);
        memcpy(m_pvDataSource, pvDataSource, uiDataSize);
    }
    else
    {
        m_bOwnData = false;
        m_pvDataSource = pvDataSource;
    }
}
//---------------------------------------------------------------------------
inline unsigned int NiD3DShaderConstantMapEntry::GetInternal() const
{
    return m_uiInternal;
}
//---------------------------------------------------------------------------
inline void NiD3DShaderConstantMapEntry::SetInternal(unsigned int uiInternal)
{
    m_uiInternal = uiInternal;
}
//---------------------------------------------------------------------------
inline NiShaderAttributeDesc::AttributeType 
    NiD3DShaderConstantMapEntry::GetAttributeType(unsigned int uiFlags)
{
    assert ((uiFlags & SCME_ATTRIB_TYPE_MASK) < 
        NiShaderAttributeDesc::ATTRIB_TYPE_COUNT);

    if (ms_bTableInitialized == false)
        InitializeTable();

    return ms_aeAttribType[uiFlags & SCME_ATTRIB_TYPE_MASK];
}
//---------------------------------------------------------------------------
inline unsigned char NiD3DShaderConstantMapEntry::GetAttributeFlags(
    NiShaderAttributeDesc::AttributeType eType)
{
    return ms_aucAttribFlags[(unsigned int)eType];
}
//---------------------------------------------------------------------------
inline unsigned int NiD3DShaderConstantMapEntry::GetAttributeMask()
{
    return SCME_ATTRIB_TYPE_MASK;
}
//---------------------------------------------------------------------------
