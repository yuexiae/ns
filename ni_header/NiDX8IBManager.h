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
#ifndef NIDX8IBMANAGER_H
#define NIDX8IBMANAGER_H

//  The IndexBuffer manager is responsible for giving out and tracking index
//  buffers required by the application.
#include "NiDX8Headers.h"
#include "NiDX8RendererLibType.h"
#include "NiDX8Resource.h"
#include <NiBool.h>
#include <NiTPointerMap.h>
#include <NiRefObject.h>

class NiGeometryData;

class NIDX8RENDERER_ENTRY NiDX8IndexBufferManager : public NiRefObject
{
public:
    enum { DX8_MAX_IBS = 5 };

    class NiDX8IBResource : public NiDX8Resource
    {
    public:
        unsigned int m_uiLength;        //  Length of ib
        D3DFORMAT m_eFormat;            //  Format of ib
        unsigned int m_uiRevID;         //  Revision of ib
        LPDIRECT3DINDEXBUFFER8 m_pkIB;  //  Ptr to ib
        D3DINDEXBUFFER_DESC m_kIBDesc;  //  Description of ib
    };
    class NIDX8RENDERER_ENTRY NiDX8IBInfo
    {
    public:
        unsigned int m_uiIBID;                      //  ID w/in ib manager
        unsigned char m_ucIndex;                    //  Index next 'free'
        NiDX8IBResource* m_apkIBRes[DX8_MAX_IBS];   //  Ptr to ib
    };

    NiDX8IndexBufferManager(LPDIRECT3DDEVICE8 pkD3DDevice8);
    ~NiDX8IndexBufferManager();

    LPDIRECT3DINDEXBUFFER8 GetIndexBuffer(unsigned int uiLength, 
        unsigned int uiUsage, D3DFORMAT eFormat, D3DPOOL ePool);

    LPDIRECT3DINDEXBUFFER8 PackBuffer(const unsigned short* pusTriList, 
        unsigned int uiLength, LPDIRECT3DINDEXBUFFER8 pkOldIB, 
        unsigned int& uiIBSize, D3DPOOL ePool, unsigned int uiUsage);

    LPDIRECT3DINDEXBUFFER8 ResizeTempPointConnectivity(unsigned int uiPoints, 
        bool bRefill = false, unsigned int uiUsage = 0, 
        D3DPOOL ePool = D3DPOOL_MANAGED);
    LPDIRECT3DINDEXBUFFER8 ResizeTempLineConnectivity(unsigned int uiPoints, 
        NiBool* pbFlags, unsigned int& uiConn, unsigned int uiUsage = 0, 
        D3DPOOL ePool = D3DPOOL_MANAGED);

    void DestroyDefaultBuffers();

protected:
    NiDX8IBInfo* GetIBInfo(unsigned int uiUsage, D3DFORMAT eFormat,
        D3DPOOL ePool);
    NiDX8IBInfo* CreateIBInfo();
    LPDIRECT3DINDEXBUFFER8 CreateIndexBuffer(unsigned int uiLength, 
        unsigned int uiUsage, D3DFORMAT eFormat, D3DPOOL ePool, 
        D3DINDEXBUFFER_DESC* pkDesc = NULL);

    LPDIRECT3DDEVICE8 m_pkD3DDevice8;

    // Temporary array of pre-packed point connectivities
    LPDIRECT3DINDEXBUFFER8 m_pkTempPointConnIB;
    unsigned int m_uiTempPointConnLen;
    // Temporary array of pre-packed line connectivities
    LPDIRECT3DINDEXBUFFER8 m_pkTempLineConnIB;
    unsigned int m_uiTempLineConnLen;

    NiTPointerMap<unsigned int, NiDX8IBInfo*> m_kDefaultResources;
    NiTPointerMap<unsigned int, NiDX8IBInfo*> m_kManagedResources;
    NiTPointerMap<unsigned int, NiDX8IBInfo*> m_kSystemMemResources;

};

typedef NiPointer<NiDX8IndexBufferManager> NiDX8IndexBufferManagerPtr;

#endif  //#ifndef NIDX8IBMANAGER_H
