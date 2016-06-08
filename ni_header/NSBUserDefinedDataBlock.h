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

#ifndef NSBUSERDEFINEDDATABLOCK_H
#define NSBUSERDEFINEDDATABLOCK_H

#include "NSBConstantMap.h"
#include <NiD3DUtility.h>

class NiD3DShaderConstantMap;
class NiShaderDesc;

class NIBINARYSHADERLIB_ENTRY NSBUserDefinedDataBlock :
    public NSBConstantMap
{
public:
    NSBUserDefinedDataBlock(const char* pacName);
    virtual ~NSBUserDefinedDataBlock();

    const char* GetName() const;
    void SetName(const char* pacName);

    virtual bool AddEntry(char* pszKey, unsigned int uiFlags, 
        unsigned int uiSize, unsigned int uiStride, void* pvSource, 
        bool bCopyData = true);

    virtual NiD3DSCM_Pixel* GetD3DSCM_Pixel(NiD3DRenderer* pkRenderer, 
        NiShaderDesc* pkShaderDesc);
    virtual NiD3DSCM_Vertex* GetD3DSCM_Vertex(NiD3DRenderer* pkRenderer, 
        NiShaderDesc* pkShaderDesc);

    // *** begin NDL internal use only
    virtual bool SaveBinary(NiBinaryStream& kStream);
    virtual bool LoadBinary(NiBinaryStream& kStream);

#if defined(_DEBUG)
    virtual void Dump(FILE* pf);
#endif  //#if defined(_DEBUG)
    // *** end NDL internal use only

protected:
    virtual bool SaveBinaryEntries(NiBinaryStream& kStream);
    virtual bool LoadBinaryEntries(NiBinaryStream& kStream);

    char* m_pacName;
};

#include "NSBUserDefinedDataBlock.inl"

#endif  //NSBUSERDEFINEDDATABLOCK_H
