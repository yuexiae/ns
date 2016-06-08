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

#ifndef NID3DSHADERPROGRAMCREATOROBJ_H
#define NID3DSHADERPROGRAMCREATOROBJ_H

#include "NiD3DShaderProgramCreatorAsm.h"

class NID3D_ENTRY NiD3DShaderProgramCreatorObj : 
    public NiD3DShaderProgramCreatorAsm
{
public:
    virtual ~NiD3DShaderProgramCreatorObj();

    // *** begin NDL internal use only ***

    static void _SDMInit();
    static void _SDMShutdown();

    static NiD3DShaderProgramCreatorObj* GetInstance();
    static void Shutdown();

    // *** end NDL internal use only ***

protected:
    NiD3DShaderProgramCreatorObj();

    virtual bool LoadShaderCodeFromFile(const char* pcFileName, 
        void*& pvCode, unsigned int& uiCodeSize, void*& pvConstantData, 
        unsigned int& uiConstantSize);
    virtual bool LoadShaderCodeFromBuffer(const void* pvBuffer, 
        unsigned int uiBufferSize, void*& pvCode, unsigned int& uiCodeSize, 
        void*& pvConstantData, unsigned int& uiConstantSize);

    static NiD3DShaderProgramCreatorObj* ms_pkCreator;
};

#include "NiD3DShaderProgramCreatorObj.inl"

#endif  //NID3DSHADERPROGRAMCREATOROBJ_H
