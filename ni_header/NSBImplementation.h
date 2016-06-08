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

#ifndef NSBIMPLEMENTATION_H
#define NSBIMPLEMENTATION_H

#include "NiBinaryShaderLibLibType.h"
#include "NSBRequirements.h"
#include "NSBRenderStates.h"
#include "NSBStateGroup.h"
#include "NSBConstantMap.h"
#include "NSBUserDefinedDataSet.h"

class NSBPass;
class NiBinaryShader;

class NIBINARYSHADERLIB_ENTRY NSBImplementation
{
public:
    NSBImplementation();
    ~NSBImplementation();

    // Name
    const char* GetName();
    void SetName(const char* pszName);
    const char* GetDesc();
    void SetDesc(const char* pszDesc);

    // User-defined class name
    const char* GetClassName();
    void SetClassName(const char* pszClassName);

    // Requirements
    NSBRequirements* GetRequirements();

    // PackingDef
    const char* GetPackingDef();
    void SetPackingDef(const char* pszPackingDef);

    // RenderStateGroup
    NSBStateGroup* GetRenderStateGroup();

    // Constant Maps
    NSBConstantMap* GetPixelConstantMap();
    NSBConstantMap* GetVertexConstantMap();

    // Passes
    unsigned int GetPassCount();
    NSBPass* GetPass(unsigned int uiIndex, bool bCreate = true);

    // User defined data set
    NSBUserDefinedDataSet* GetUserDefinedDataSet();
    void SetUserDefinedDataSet(NSBUserDefinedDataSet* pkUDDSet);

    // *** begin NDL internal use only
    // Index
    unsigned int GetIndex();
    void SetIndex(unsigned int uiIndex);

    void SetSoftwareVP(bool bSoftwareVP);
    bool GetSoftwareVP() const;

    bool SetupNiBinaryShader(NiBinaryShader& kShader, 
        NiShaderDesc* pkShaderDesc);

    // Serialization
    bool SaveBinary(NiBinaryStream& kStream);
    bool LoadBinary(NiBinaryStream& kStream);

#if defined(_DEBUG)
    void Dump(FILE* pf);
#endif  //#if defined(_DEBUG)
    // *** end NDL internal use only

protected:
    bool SaveBinaryRequirements(NiBinaryStream& kStream);
    bool SaveBinaryPackingDef(NiBinaryStream& kStream);
    bool SaveBinaryPasses(NiBinaryStream& kStream);

    bool LoadBinaryRequirements(NiBinaryStream& kStream);
    bool LoadBinaryPackingDef(NiBinaryStream& kStream);
    bool LoadBinaryPasses(NiBinaryStream& kStream);

    char* m_pszName;
    char* m_pszDesc;
    char* m_pszClassName;

    unsigned int m_uiIndex;

    NSBRequirements* m_pkRequirements;

    // User defined data set
    NSBUserDefinedDataSetPtr m_spUserDefinedDataSet;

    // Packing definition name
    char* m_pszPackingDef;

    // 'Global' render state settings for the shader
    NSBStateGroup* m_pkRenderStateGroup;
    //  'Global' pixel shader mapping for the shader
    NSBConstantMap* m_pkPixelConstantMap;
    //  'Global' vertex shader mapping for the shader
    NSBConstantMap* m_pkVertexConstantMap;

    NiTArray<NSBPass*> m_akPasses;

    bool m_bSoftwareVP;
};

#include "NSBImplementation.inl"

#endif  //NSBIMPLEMENTATION_H
