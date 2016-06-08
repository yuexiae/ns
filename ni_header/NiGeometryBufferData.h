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
#ifndef NIGEOMETRYBUFFERDATA_H
#define NIGEOMETRYBUFFERDATA_H

#include "NiD3DDefines.h"

class NiGeometryGroup;
class NiVBChip;

//  Geometry buffer tracking class
class NID3D_ENTRY NiGeometryBufferData
{
public:
    NiGeometryBufferData();
    ~NiGeometryBufferData();

    unsigned int GetFlags() const;

    NiGeometryGroup* GetGeometryGroup() const;

    unsigned int GetFVF() const;
    NiD3DVertexDeclaration GetVertexDeclaration() const;
    unsigned int GetVertCount() const;
    bool GetSoftwareVP() const;

    unsigned int GetStreamCount() const;

    unsigned int GetVertexStride(unsigned int uiIndex) const;
    NiVBChip* GetVBChip(unsigned int uiIndex) const;
    
    bool IsVBChipValid() const;
    void RemoveVBChip(unsigned int uiIndex);
    void RemoveAllVBChips();

    // IndexBuffer data
    unsigned int GetIndexCount() const;
    unsigned int GetIBSize() const;
    D3DIndexBufferPtr GetIB() const;
    unsigned int GetBaseVertexIndex() const;

    void RemoveIB();
    
    // Primitive data
    D3DPRIMITIVETYPE GetType() const;
    unsigned int GetTriCount() const;
    unsigned int GetNumArrays() const;
    const unsigned short* GetArrayLengths() const;
    const unsigned short* GetIndexArray() const;

#if defined(_XBOX) && !defined(_XENON)
    // PushBuffer
    unsigned int GetPBSize() const;
    void* GetPBData() const;
    LPDIRECT3DPUSHBUFFER8 GetPB() const;
#endif  //#if defined(_XBOX) && !defined(_XENON)

    // *** begin NDL internal use only ***
    void SetFlags(unsigned int uiFlags);
    void SetGeometryGroup(NiGeometryGroup* pkGroup); 

    void SetStreamCount(unsigned int uiStreamCount);
    void SetFVF(unsigned int uiFVF);
    void SetVertexDeclaration(NiD3DVertexDeclaration hDecl);
    void SetVertCount(unsigned int uiVertCount);
    void SetSoftwareVP(bool bSoftwareVP);

    void SetBaseVertexIndex(unsigned int uiBaseVertexIndex);

    void SetVBChip(unsigned int uiStream, NiVBChip* pkChip);
    void SetVertexStride(unsigned int uiStream, unsigned int uiStride);

    void SetIB(D3DIndexBufferPtr pkIB, unsigned int uiIndexCount,
        unsigned int uiIBSize);

    void SetType(D3DPRIMITIVETYPE ePrimType);
    void SetIndices(unsigned int uiTriCount, 
        const unsigned short* pusIndexArray, 
        const unsigned short* pusArrayLengths, unsigned int uiNumArrays);

#if defined(_XBOX) && !defined(_XENON)
    // PushBuffer
    void SetPushBuffer(unsigned int uiPBSize, void* pvPBData, 
        LPDIRECT3DPUSHBUFFER8 pkPB);
    void SetPBSize(unsigned int uiPBSize);
    void SetPBData(void* pvPBData);
    void SetPB(LPDIRECT3DPUSHBUFFER8 pkPB);
    // Compression support
    const bool GetCompressedData() const;
    void SetCompressedData(bool bCompressedData);
#endif  //#if defined(_XBOX) && !defined(_XENON)

    // *** end NDL internal use only ***
protected:
    unsigned int m_uiFlags;

    NiGeometryGroup* m_pkGeometryGroup;

    // VertexBuffer data
    unsigned int m_uiFVF;
    NiD3DVertexDeclaration m_hDeclaration;
    bool m_bSoftwareVP;

    // This the number of verts to be drawn, while each NiVBChip holds
    // the number of vertices allocated in the VBs.
    unsigned int m_uiVertCount;

    unsigned int m_uiStreamCount;
    unsigned int* m_puiVertexStride;
    NiVBChip** m_ppkVBChip;
    
    // IndexBuffer data
    // This the number of indices that will be used in a Draw call, while
    // uiIBSize holds the total number of indices allocated in the IB.
    unsigned int m_uiIndexCount;
    unsigned int m_uiIBSize;
    D3DIndexBufferPtr m_pkIB;
    unsigned int m_uiBaseVertexIndex;
    
    // Primitive data
    D3DPRIMITIVETYPE m_eType;
    // This must be the number of triangles to be drawn, based
    // on the current active index count and how the indices are arranged.
    unsigned int m_uiTriCount;
    unsigned int m_uiNumArrays;
    const unsigned short* m_pusArrayLengths;
    const unsigned short* m_pusIndexArray;

#if defined(_XBOX) && !defined(_XENON)
    // PushBuffer
    unsigned int m_uiPBSize;
    void* m_pvPBData;
    LPDIRECT3DPUSHBUFFER8 m_pkPB;

    // Compression support
    bool m_bCompressedData;
#endif  //#if defined(_XBOX) && !defined(_XENON)
};

#include "NiGeometryBufferData.inl"

#endif  //#ifndef NIGEOMETRYBUFFERDATA_H