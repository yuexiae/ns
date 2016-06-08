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

#ifndef NIDX8SHADERCONSTANTMANAGER_H
#define NIDX8SHADERCONSTANTMANAGER_H

#include "NiD3DShaderConstantManager.h"

class NID3D_ENTRY NiDX8ShaderConstantManager : 
    public NiD3DShaderConstantManager
{
public:
    virtual ~NiDX8ShaderConstantManager();

    // *** begin NDL internal use only ***

    virtual void CommitChanges();

    static NiDX8ShaderConstantManager* Create(NiD3DRenderer* pkRenderer, 
        const D3DCAPS8& kD3DCaps8);

    // *** end NDL internal use only ***

protected:
    NiDX8ShaderConstantManager(NiD3DRenderer* pkD3DRenderer, 
        const D3DCAPS8& kD3DCaps8);

    bool m_bSoftwareOnlyVP;
};

typedef NiPointer<NiDX8ShaderConstantManager> NiDX8ShaderConstantManagerPtr;

//#include "NiDX8ShaderConstantManager.inl"

#endif  //#ifndef NIDX8SHADERCONSTANTMANAGER_H
