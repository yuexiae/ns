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

#ifndef NSBREQUIREMENTS_H
#define NSBREQUIREMENTS_H

#include "NiBinaryShaderLibLibType.h"
#include "NiBinaryShader.h"
#include <NiMain.h>

class NIBINARYSHADERLIB_ENTRY NSBRequirements
{
public:
    NSBRequirements();
    ~NSBRequirements();

    unsigned int GetPSVersion() const;
    void SetPSVersion(unsigned int uiVersion);
    unsigned int GetVSVersion() const;
    void SetVSVersion(unsigned int uiVersion);
    unsigned int GetUserVersion() const;
    void SetUserVersion(unsigned int uiVersion);
    unsigned int GetPlatformFlags() const;
    void SetPlatformFlags(unsigned int uiFlags);

    bool UsesNiRenderState() const;
    void SetUsesNiRenderState(bool bUses);

    bool UsesNiLightState() const;
    void SetUsesNiLightState(bool bUses);

    NiGeometryData::DataFlags GetBinormalTangentMethod() const;
    void SetBinormalTangentMethod(NiGeometryData::DataFlags eNBTMethod);

    bool GetSoftwareVPAcceptable() const;
    void SetSoftwareVPAcceptable(bool bSoftwareVP);

    bool GetSoftwareVPRequired() const;
    void SetSoftwareVPRequired(bool bSoftwareVP);

    // For skinning shaders
    unsigned int GetBonesPerPartition() const;
    void SetBonesPerPartition(unsigned int uiBones);
    unsigned int GetBoneMatrixRegisters() const;
    void SetBoneMatrixRegisters(unsigned int uiRegisters);
    NiBinaryShader::BoneMatrixCalcMethod GetBoneCalcMethod() const;
    void SetBoneCalcMethod(NiBinaryShader::BoneMatrixCalcMethod eMethod);

    // *** begin NDL internal use only
    bool SaveBinary(NiBinaryStream& kStream);
    bool LoadBinary(NiBinaryStream& kStream);

#if defined(_DEBUG)
    void Dump(FILE* pf);
#endif  //#if defined(_DEBUG)
    // *** end NDL internal use only

protected:
    unsigned int m_uiPSVersion;
    unsigned int m_uiVSVersion;
    unsigned int m_uiUserVersion;
    unsigned int m_uiPlatformFlags;
    bool m_bUsesNiRenderState;
    bool m_bUsesNiLightState;
    unsigned int m_uiBonesPerPartition;
    unsigned int m_uiBoneMatrixRegisters;
    NiBinaryShader::BoneMatrixCalcMethod m_eBoneCalcMethod;
    NiGeometryData::DataFlags m_eBinormalTangentMethod;

    bool m_bSoftwareVPAcceptable;
    bool m_bSoftwareVPRequired;
};

#endif  //NSBREQUIREMENTS_H
