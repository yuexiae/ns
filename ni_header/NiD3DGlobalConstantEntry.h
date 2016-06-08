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

#ifndef NID3DGLOBALCONSTANTENTRY_H
#define NID3DGLOBALCONSTANTENTRY_H

#include "NiD3DShaderConstantMapEntry.h"
#include "NiD3DUtility.h"

class NID3D_ENTRY NiD3DGlobalConstantEntry : public NiRefObject
{
public:
    NiD3DGlobalConstantEntry();
    NiD3DGlobalConstantEntry(const char* pszKey, 
        NiShaderAttributeDesc::AttributeType eType, 
        unsigned int uiDataSize, void* pvDataSource);
    ~NiD3DGlobalConstantEntry();

    //*** Access functions
    const char* GetKey() const;
    void SetKey(const char* pszKey);

    const NiShaderAttributeDesc::AttributeType GetType() const;
    void SetType(NiShaderAttributeDesc::AttributeType eType);

    bool IsBool() const;
    bool IsString() const;
    bool IsUnsignedInt() const;
    bool IsFloat() const;
    bool IsPoint2() const;
    bool IsPoint3() const;
    bool IsPoint4() const;
    bool IsMatrix3() const;
    bool IsMatrix4() const;
    bool IsColor() const;
    bool IsTexture() const;

    unsigned int GetDataSize() const;
    void* GetDataSource() const;
    void GetData(unsigned int& uiDataSize, void*& pvDataSource) const;
    void SetData(unsigned int uiDataSize, void* pvDataSource);

    // *** begin NDL internal use only
    // *** end NDL internal use only

protected:
    // The name of the attribute this constant is mapped to,
    // or the name of the pre-defined/constant entry.
    char* m_pszKey;

    // Type of data
    NiShaderAttributeDesc::AttributeType m_eType;

    // The data itself - only used in CONSTANT and some DEFINED mappings.
    // If the data is a constant, the entry will delete, otherwise, it is
    // left up to the one who set it.
    unsigned int m_uiDataSize;  // Size of the data element
    void* m_pvDataSource;       // Pointer to source of data
};

#include "NiD3DGlobalConstantEntry.inl"

#endif  //#ifndef NID3DGLOBALCONSTANTENTRY_H
