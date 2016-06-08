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
//---------------------------------------------------------------------------
#ifndef NIDX8RESOURCE_H
#define NIDX8RESOURCE_H

//  NiDX8Resource is a base class for tracking resources under DX8 in the
//  ResourceManager, VBManager, IBManager, and TextureManager.
#include "NiDX8Headers.h"
#include "NiDX8RendererLibType.h"

#include <NiRTLib.h>
#include <NiSmartPointer.h>

class NIDX8RENDERER_ENTRY NiDX8Resource
{
public:
    // *** begin NDL internal use only ***

    enum Type
    {
        TYPE_TEXTURE    = 0,
        TYPE_TEXTURE_CUBE,
        TYPE_TEXTURE_VOLUME,
        TYPE_VERTEXBUFFER,
        TYPE_INDEXBUFFER,
        TYPE_INVALID    = 0xFFFF,
        TYPE_COUNT
    };

    NiDX8Resource();
    ~NiDX8Resource();

    const unsigned int GetResourceID();
    const Type GetType();
    const D3DPOOL GetPool();
    const unsigned int GetUsage();
    const LPDIRECT3DRESOURCE8 GetResource();

    unsigned int m_uiResID;             //  Resource ID
    Type m_eType;                       //  Type of resource
    D3DPOOL m_ePool;                    //  Memory class for resource
    unsigned int m_uiUsage;             //  USage for resource
    LPDIRECT3DRESOURCE8 m_pkD3DResource; //  Ptr. to D3D resource

    // *** end NDL internal use only ***
};

typedef NiPointer<NiDX8Resource> NiDX8ResourcePtr;

#include "NIDX8Resource.inl"

#endif  //#ifndef NiDX8RESOURCE_H
