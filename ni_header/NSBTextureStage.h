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

#ifndef NSBTEXTURESTAGE_H
#define NSBTEXTURESTAGE_H

#include "NiBinaryShaderLibLibType.h"
#include "NSBStageAndSamplerStates.h"
#include "NSBStateGroup.h"

#include <NiD3DDefines.h>
#include <NiD3DUtility.h>
#include <NiD3DTextureStage.h>

class NiD3DTextureStage;

class NIBINARYSHADERLIB_ENTRY NSBTextureStage
{
public:
    NSBTextureStage();
    ~NSBTextureStage();

    // Name
    const char* GetName();
    void SetName(const char* pszName);

    unsigned int GetStage();
    void SetStage(unsigned int uiStage);

    // 
    NSBStateGroup* GetTextureStageGroup();
    NSBStateGroup* GetSamplerStageGroup();

    unsigned int GetTextureFlags();

    void SetNDLMap(unsigned int uiNDLMap);
    void SetDecalMap(unsigned int uiDecal);
    void SetShaderMap(unsigned int uiShaderMap);
    void SetUseIndexFromMap(bool bUse);

    bool GetUseTextureTransformation();
    D3DMATRIX& GetTextureTransformation();

    void SetUseTextureTransformation(bool bUse);
    void SetTextureTransformation(D3DMATRIX& kTrans);

    unsigned int GetTextureTransformFlags();
    void SetTextureTransformFlags(unsigned int uiFlags);

    const char* GetGlobalName();
    void SetGlobalName(const char* pszGlobalName);

    bool SetupD3DTextureStage(NiD3DTextureStage& kD3DStage);

    // *** begin NDL internal use only
    bool SaveBinary(NiBinaryStream& kStream);
    bool LoadBinary(NiBinaryStream& kStream);

#if defined(_DEBUG)
    void Dump(FILE* pf);
#endif  //#if defined(_DEBUG)
    // *** end NDL internal use only

protected:
    bool SetupD3DTextureStage_DX9(NiD3DTextureStage& kD3DStage);
    bool SetupD3DTextureStage_DX8(NiD3DTextureStage& kD3DStage);
    bool SetupD3DTextureStage_XBox(NiD3DTextureStage& kD3DStage);

    bool SaveBinaryTextureTransform(NiBinaryStream& kStream);
    bool LoadBinaryTextureTransform(NiBinaryStream& kStream);

    char* m_pszName;

    unsigned int m_uiStage;
    unsigned int m_uiTextureFlags;
    NSBStateGroup* m_pkTextureStageGroup;
    NSBStateGroup* m_pkSamplerStageGroup;
    bool m_bTextureTransform;
    D3DMATRIX m_kTextureTransformation;
    unsigned int m_uiTextureTransformFlags;
    char* m_pszGlobalEntry;
};

#include "NSBTextureStage.inl"

#endif  //NSBTEXTURESTAGE_H
