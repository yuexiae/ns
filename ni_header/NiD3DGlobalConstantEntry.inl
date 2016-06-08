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
// NiD3DGlobalConstantEntry inline functions
//---------------------------------------------------------------------------
inline NiD3DGlobalConstantEntry::NiD3DGlobalConstantEntry() :
    m_pszKey(0), 
    m_eType(NiShaderAttributeDesc::ATTRIB_TYPE_UNDEFINED), 
    m_uiDataSize(0), 
    m_pvDataSource(0)
{
}
//---------------------------------------------------------------------------
inline NiD3DGlobalConstantEntry::NiD3DGlobalConstantEntry(const char* pszKey, 
    NiShaderAttributeDesc::AttributeType eType, 
    unsigned int uiDataSize, void* pvDataSource) :
    m_pszKey(0), 
    m_eType(NiShaderAttributeDesc::ATTRIB_TYPE_UNDEFINED), 
    m_uiDataSize(0), 
    m_pvDataSource(0)
{
    SetKey(pszKey);
    SetType(eType);
    SetData(uiDataSize, pvDataSource);
}
//---------------------------------------------------------------------------
inline NiD3DGlobalConstantEntry::~NiD3DGlobalConstantEntry()
{
    delete [] m_pszKey;
    delete [] m_pvDataSource;
}
//---------------------------------------------------------------------------
inline const char* NiD3DGlobalConstantEntry::GetKey() const
{
    return m_pszKey;
}
//---------------------------------------------------------------------------
inline void NiD3DGlobalConstantEntry::SetKey(const char* pszKey)
{
    NiD3DUtility::SetString(m_pszKey, pszKey);
}
//---------------------------------------------------------------------------
inline const NiShaderAttributeDesc::AttributeType 
    NiD3DGlobalConstantEntry::GetType() const
{
    return m_eType;
}
//---------------------------------------------------------------------------
inline void NiD3DGlobalConstantEntry::SetType(
    NiShaderAttributeDesc::AttributeType eType)
{
    m_eType = eType;
}
//---------------------------------------------------------------------------
inline bool NiD3DGlobalConstantEntry::IsBool() const
{
    return NiD3DShaderConstantMapEntry::IsBool((unsigned int)m_eType);
}
//---------------------------------------------------------------------------
inline bool NiD3DGlobalConstantEntry::IsString() const
{
    return NiD3DShaderConstantMapEntry::IsString((unsigned int)m_eType);
}
//---------------------------------------------------------------------------
inline bool NiD3DGlobalConstantEntry::IsUnsignedInt() const
{
    return NiD3DShaderConstantMapEntry::IsUnsignedInt((unsigned int)m_eType);
}
//---------------------------------------------------------------------------
inline bool NiD3DGlobalConstantEntry::IsFloat() const
{
    return NiD3DShaderConstantMapEntry::IsFloat((unsigned int)m_eType);
}
//---------------------------------------------------------------------------
inline bool NiD3DGlobalConstantEntry::IsPoint2() const
{
    return NiD3DShaderConstantMapEntry::IsPoint2((unsigned int)m_eType);
}
//---------------------------------------------------------------------------
inline bool NiD3DGlobalConstantEntry::IsPoint3() const
{
    return NiD3DShaderConstantMapEntry::IsPoint3((unsigned int)m_eType);
}
//---------------------------------------------------------------------------
inline bool NiD3DGlobalConstantEntry::IsPoint4() const
{
    return NiD3DShaderConstantMapEntry::IsPoint4((unsigned int)m_eType);
}
//---------------------------------------------------------------------------
inline bool NiD3DGlobalConstantEntry::IsMatrix3() const
{
    return NiD3DShaderConstantMapEntry::IsMatrix3((unsigned int)m_eType);
}
//---------------------------------------------------------------------------
inline bool NiD3DGlobalConstantEntry::IsMatrix4() const
{
    return NiD3DShaderConstantMapEntry::IsMatrix4((unsigned int)m_eType);
}
//---------------------------------------------------------------------------
inline bool NiD3DGlobalConstantEntry::IsColor() const
{
    return NiD3DShaderConstantMapEntry::IsColor((unsigned int)m_eType);
}
//---------------------------------------------------------------------------
inline bool NiD3DGlobalConstantEntry::IsTexture() const
{
    return NiD3DShaderConstantMapEntry::IsTexture((unsigned int)m_eType);
}
//---------------------------------------------------------------------------
inline unsigned int NiD3DGlobalConstantEntry::GetDataSize() const
{
    return m_uiDataSize;
}
//---------------------------------------------------------------------------
inline void* NiD3DGlobalConstantEntry::GetDataSource() const
{
    return m_pvDataSource;
}
//---------------------------------------------------------------------------
inline void NiD3DGlobalConstantEntry::GetData(unsigned int& uiDataSize, 
    void*& pvDataSource) const
{
    uiDataSize = m_uiDataSize;
    pvDataSource = m_pvDataSource;
}
//---------------------------------------------------------------------------
