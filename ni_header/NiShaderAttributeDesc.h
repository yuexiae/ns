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

#ifndef NISHADERATTRIBUTEDESC_H
#define NISHADERATTRIBUTEDESC_H

// These classes and functions are used for DLL-based shader libraries
#include "NiShaderDescBase.h"

#include "NiPoint2.h"
#include "NiPoint3.h"
#include "NiMatrix3.h"
#include "NiTransform.h"
#include "NiColor.h"

// Description of an 'attribute' a shader exposes
class NIMAIN_ENTRY NiShaderAttributeDesc : public NiShaderDescBase
{
public:
    NiShaderAttributeDesc();
    virtual ~NiShaderAttributeDesc();

    enum Flags
    {
        ATTRIB_FLAGS_NONE       = 0x00000000,
        ATTRIB_FLAGS_RANGED     = 0x00000001,
        ATTRIB_FLAGS_HIDDEN     = 0x00000002
    };

    enum AttributeType
    {
        ATTRIB_TYPE_UNDEFINED   = 0x00000000,
        ATTRIB_TYPE_BOOL        = 0x00000001,
        ATTRIB_TYPE_STRING      = 0x00000002,
        ATTRIB_TYPE_UNSIGNEDINT = 0x00000003,
        ATTRIB_TYPE_FLOAT       = 0x00000004,
        ATTRIB_TYPE_POINT2      = 0x00000005,
        ATTRIB_TYPE_POINT3      = 0x00000006,
        ATTRIB_TYPE_POINT4      = 0x00000007,
        ATTRIB_TYPE_MATRIX3     = 0x00000008,
        ATTRIB_TYPE_MATRIX4     = 0x00000009,
        ATTRIB_TYPE_COLOR       = 0x0000000A,
        ATTRIB_TYPE_TEXTURE     = 0x0000000B,
        // The FLOAT8 and FLOAT12 were added to allow for those
        // arrangements in the mappings
        ATTRIB_TYPE_FLOAT8      = 0x0000000C,
        ATTRIB_TYPE_FLOAT12     = 0x0000000D,
        // New attribute types go above here!
        ATTRIB_TYPE_COUNT,
    };

    AttributeType GetType() const;
    unsigned int GetFlags() const;
    bool GetValue_Bool(bool& bValue) const;
    bool GetValue_String(const char*& pszValue) const;
    bool GetValue_UnsignedInt(unsigned int& uiValue) const;
    bool GetValue_Float(float& fValue) const;
    bool GetValue_Point2(NiPoint2& kPt2Value) const;
    bool GetValue_Point3(NiPoint3& kPtValue) const;
    bool GetValue_Point4(float*& pafValue) const;
    bool GetValue_Matrix3(NiMatrix3& kMatValue) const;
    bool GetValue_Matrix4(float*& pafValue) const;
    bool GetValue_Color(NiColor& kClrValue) const;
    bool GetValue_ColorA(NiColorA& kClrValue) const;
    bool GetValue_Texture(unsigned int& uiValue, const char*& pszValue) 
        const;

    bool IsHidden() const;

    bool IsRanged() const;
    bool GetRange_UnsignedInt(unsigned int& uiLow, unsigned int& uiHigh) const;
    bool GetRange_Float(float& fLow, float& fHigh) const;
    bool GetRange_Point2(NiPoint2& kPt2Low, NiPoint2& kPt2High) const;
    bool GetRange_Point3(NiPoint3& kPtLow, NiPoint3& kPtHigh) const;
    bool GetRange_Floats(unsigned int uiCount, float* pafLow, float* pafHigh) const;
    bool GetRange_Color(NiColor& kClrLow, NiColor& kClrHigh) const;
    bool GetRange_ColorA(NiColorA& kClrLow, NiColorA& kClrHigh) const;

    // *** begin NDL internal use only ***
    void SetType(AttributeType eType);
    void SetFlags(unsigned int uiFlags);

    // Value setting
    void SetValue_Bool(bool bValue);
    void SetValue_String(const char* pszValue);
    void SetValue_UnsignedInt(unsigned int uiValue);
    void SetValue_Float(float fValue);
    void SetValue_Point2(NiPoint2& kPt2Value);
    void SetValue_Point3(NiPoint3& kPt3Value);
    void SetValue_Point4(float* pafValue);
    void SetValue_Matrix3(NiMatrix3& kMatValue);
    void SetValue_Matrix4(float* pafValue);
    void SetValue_Color(NiColor& kClrValue);
    void SetValue_ColorA(NiColorA& kClrValue);
    void SetValue_Texture(unsigned int uiValue, const char* pszValue);

    // Hidden or exposed
    void SetHidden(bool bHide);

    // Range setting
    void SetRanged(bool bRanged);
    bool SetRange_UnsignedInt(unsigned int uiLow, unsigned int uiHigh);
    bool SetRange_Float(float fLow, float fHigh);
    bool SetRange_Point2(NiPoint2& kPt2Low, NiPoint2& kPt2High);
    bool SetRange_Point3(NiPoint3& kPtLow, NiPoint3& kPtHigh);
    bool SetRange_Point4(float* pafLow, float* pafHigh);
    bool SetRange_Floats(unsigned int uiCount, float* pafLow, float* pafHigh);
    bool SetRange_Color(NiColor& kClrLow, NiColor& kClrHigh);
    bool SetRange_ColorA(NiColorA& kClrLow, NiColorA& kClrHigh);

    // 
    virtual NiShaderAttributeDesc& operator=(
        const NiShaderAttributeDesc& kSrcDesc);

    // Serialization
    virtual bool SaveBinary(NiBinaryStream& kStream);
    virtual bool LoadBinary(NiBinaryStream& kStream);
    // *** end NDL internal use only ***

protected:
    virtual bool SaveBinary_Bool(NiBinaryStream& kStream);
    virtual bool SaveBinary_String(NiBinaryStream& kStream);
    virtual bool SaveBinary_UnsignedInt(NiBinaryStream& kStream);
    virtual bool SaveBinary_Float(NiBinaryStream& kStream);
    virtual bool SaveBinary_Point2(NiBinaryStream& kStream);
    virtual bool SaveBinary_Point3(NiBinaryStream& kStream);
    virtual bool SaveBinary_Point4(NiBinaryStream& kStream);
    virtual bool SaveBinary_Matrix3(NiBinaryStream& kStream);
    virtual bool SaveBinary_Matrix4(NiBinaryStream& kStream);
    virtual bool SaveBinary_Color(NiBinaryStream& kStream);
    virtual bool SaveBinary_Texture(NiBinaryStream& kStream);

    virtual bool LoadBinary_Bool(NiBinaryStream& kStream);
    virtual bool LoadBinary_String(NiBinaryStream& kStream);
    virtual bool LoadBinary_UnsignedInt(NiBinaryStream& kStream);
    virtual bool LoadBinary_Float(NiBinaryStream& kStream);
    virtual bool LoadBinary_Point2(NiBinaryStream& kStream);
    virtual bool LoadBinary_Point3(NiBinaryStream& kStream);
    virtual bool LoadBinary_Point4(NiBinaryStream& kStream);
    virtual bool LoadBinary_Matrix3(NiBinaryStream& kStream);
    virtual bool LoadBinary_Matrix4(NiBinaryStream& kStream);
    virtual bool LoadBinary_Color(NiBinaryStream& kStream);
    virtual bool LoadBinary_Texture(NiBinaryStream& kStream);

    AttributeType m_eType;
    unsigned int m_uiFlags;

    // Data values
    // For float:
    //      m_aafValue[0][0] contains the data
    // For NiPoint#:
    //      m_aafValue[0] 'row' contains the data
    // For NiMatrix3:
    //      m_aafValue[0][0]..m_aafValue[0][2] contains row1
    //      m_aafValue[1][0]..m_aafValue[1][2] contains row2
    //      m_aafValue[2][0]..m_aafValue[2][2] contains row3
    // For Matrix4:
    //      m_aafValue[0][0]..m_aafValue[0][3] contains row1
    //      m_aafValue[1][0]..m_aafValue[1][3] contains row2
    //      m_aafValue[2][0]..m_aafValue[2][3] contains row3
    //      m_aafValue[3][0]..m_aafValue[3][3] contains row4
    // For NiColor(A)
    //      m_aafValue[0] 'row' contains the data
    union
    {
        bool m_bValue;
        char* m_pszValue;
        unsigned int m_uiValue;
        float m_aafValue[4][4];
    };

    // Range values
    union
    {
        unsigned int m_uiLow;
        float m_aafLow[4][4];
    };
    union
    {
        unsigned int m_uiHigh;
        float m_aafHigh[4][4];
    };

    char* m_pszDefault;
};

typedef NiPointer<NiShaderAttributeDesc> NiShaderAttributeDescPtr;

#endif  //#ifndef NISHADERATTRIBUTEDESC_H
