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

#ifndef NISHADERREQUIREMENTDESC_H
#define NISHADERREQUIREMENTDESC_H

// These classes and functions are used for DLL-based shader libraries
#include "NiShaderDescBase.h"

#include "NiGeometryData.h"

// Description which contains requirements
class NIMAIN_ENTRY NiShaderRequirementDesc : public NiShaderDescBase
{
public:
    NiShaderRequirementDesc();
    virtual ~NiShaderRequirementDesc();

    virtual const unsigned int GetMinPixelShaderVersion() const;
    virtual const unsigned int GetMaxPixelShaderVersion() const;
    virtual const unsigned int GetMinVertexShaderVersion() const;
    virtual const unsigned int GetMaxVertexShaderVersion() const;
    virtual const unsigned int GetMinUserDefinedVersion() const;
    virtual const unsigned int GetMaxUserDefinedVersion() const;
    virtual const unsigned int GetPlatformFlags() const;

    // Add to these platforms as NiShader support expands
    virtual const bool IsPlatformDX8() const;
    virtual const bool IsPlatformDX9() const;
    virtual const bool IsPlatformXbox() const;

    unsigned int GetBonesPerPartition() const;
    NiGeometryData::DataFlags GetBinormalTangentMethod() const;

    bool GetSoftwareVPAcceptable() const;
    bool GetSoftwareVPRequired() const;

    // Translate shader version values
    static const unsigned int GetMinorPixelShaderVersion(
        const unsigned int uiVersion);
    static const unsigned int GetMajorPixelShaderVersion(
        const unsigned int uiVersion);
    static const unsigned int CreatePixelShaderVersion(
        const unsigned int uiMajorVersion, const unsigned int uiMinorVersion);
    static const unsigned int GetMinorVertexShaderVersion(
        const unsigned int uiVersion);
    static const unsigned int GetMajorVertexShaderVersion(
        const unsigned int uiVersion);
    static const unsigned int CreateVertexShaderVersion(
        const unsigned int uiMajorVersion, const unsigned int uiMinorVersion);

    // *** begin NDL internal use only ***
    virtual void AddPixelShaderVersion(unsigned int uiVersion);
    virtual void AddVertexShaderVersion(unsigned int uiVersion);
    virtual void AddUserDefinedVersion(unsigned int uiVersion);
    virtual void AddPlatformFlags(unsigned int uiPlatformFlags);
    virtual void RemovePlatformFlags(unsigned int uiPlatformFlags);
    virtual void SetPlatformDX8(bool bAllowed);
    virtual void SetPlatformDX9(bool bAllowed);
    virtual void SetPlatformXbox(bool bAllowed);

    virtual void SetBonesPerPartition(unsigned int uiBPP);
    virtual void SetBinormalTangentMethod(NiGeometryData::DataFlags eNBTMethod);

    virtual void SetSoftwareVPAcceptable(bool bSoftwareVP);
    virtual void SetSoftwareVPRequired(bool bSoftwareVP);

    virtual bool SaveBinary(NiBinaryStream& kStream);
    virtual bool LoadBinary(NiBinaryStream& kStream);
    // *** end NDL internal use only ***

protected:
    unsigned int m_uiMinPixelShaderVersion;
    unsigned int m_uiMaxPixelShaderVersion;
    unsigned int m_uiMinVertexShaderVersion;
    unsigned int m_uiMaxVertexShaderVersion;
    unsigned int m_uiMinUserVersion;
    unsigned int m_uiMaxUserVersion;
    unsigned int m_uiPlatformFlags;
    unsigned int m_uiBonesPerPartition;
    NiGeometryData::DataFlags m_eBinormalTangentMethod;
    bool m_bSoftwareVPAcceptable;
    bool m_bSoftwareVPRequired;
};

typedef NiPointer<NiShaderRequirementDesc> NiShaderRequirementDescPtr;

#endif  //#ifndef NISHADERREQUIREMENTDESC_H
