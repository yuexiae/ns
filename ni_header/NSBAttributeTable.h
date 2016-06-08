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

#ifndef NSBATTRIBUTETABLE_H
#define NSBATTRIBUTETABLE_H

#include <NiShaderAttributeDesc.h>
#include <NiTPointerList.h>
#include "NiBinaryShaderLibLibType.h"

class NIBINARYSHADERLIB_ENTRY NSBAttributeTable
{
public:
    NSBAttributeTable();
    ~NSBAttributeTable();

    bool AddAttribDesc(NiShaderAttributeDesc* pkDesc);

    bool AddAttribDesc_Bool(char* pszName, char* pszDesc, bool bHidden,
        bool bInitValue);
    bool AddAttribDesc_String(char* pszName, char* pszDesc, bool bHidden,
        char* pszInitValue, unsigned int uiMaxLen = 0);
    bool AddAttribDesc_UnsignedInt(char* pszName, char* pszDesc, 
        bool bHidden, unsigned int uiInitValue, unsigned int uiLow = 0,
        unsigned int uiHigh = 0);
    bool AddAttribDesc_Float(char* pszName, char* pszDesc, bool bHidden, 
        float fInitValue, float fLow = 0.0f, float fHigh = 0.0f);
    bool AddAttribDesc_Point2(char* pszName, char* pszDesc, bool bHidden, 
        float* pfInitValue, float* pfLow = 0, float* pfHigh = 0);
    bool AddAttribDesc_Point3(char* pszName, char* pszDesc, bool bHidden, 
        float* pfInitValue, float* pfLow = 0, float* pfHigh = 0);
    bool AddAttribDesc_Point4(char* pszName, char* pszDesc, bool bHidden, 
        float* pfInitValue, float* pfLow = 0, float* pfHigh = 0);
    bool AddAttribDesc_Matrix3(char* pszName, char* pszDesc, bool bHidden, 
        float* pfInitValue);
    bool AddAttribDesc_Matrix4(char* pszName, char* pszDesc, bool bHidden, 
        float* pfInitValue);
    bool AddAttribDesc_Color(char* pszName, char* pszDesc, bool bHidden, 
        float* pfInitValue, float* pfLow = 0, float* pfHigh = 0);
    bool AddAttribDesc_ColorA(char* pszName, char* pszDesc, bool bHidden, 
        float* pfInitValue, float* pfLow = 0, float* pfHigh = 0);
    bool AddAttribDesc_Texture(char* pszName, char* pszDesc, bool bHidden, 
        unsigned int uiSlot, const char* pszDefault = 0);

    unsigned int GetAttributeCount();

    NiShaderAttributeDesc* GetFirstAttribute();
    NiShaderAttributeDesc* GetNextAttribute();
    NiShaderAttributeDesc* GetAttributeByName(char* pszName);

    // *** begin NDL internal use only
    bool SaveBinary(NiBinaryStream& kStream);
    bool LoadBinary(NiBinaryStream& kStream);

#if defined(_DEBUG)
    void Dump(FILE* pf);
    void DumpAttribDesc(FILE* pf, NiShaderAttributeDesc* pkDesc);
#endif  //#if defined(_DEBUG)
    // *** end NDL internal use only

protected:
    NiShaderAttributeDesc* CreateAttributeDesc(char* pszName, 
        NiShaderAttributeDesc::AttributeType eType, bool bHidden);

    NiTListIterator m_kAttribListIter;
    NiTPointerList<NiShaderAttributeDesc*> m_kAttribList;
};

#endif  //NSBATTRIBUTETABLE_H
