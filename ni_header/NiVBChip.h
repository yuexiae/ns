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
#ifndef NIVBCHIP_H
#define NIVBCHIP_H

#include "NiD3DDefines.h"
#include "NiD3DMacros.h"
#include <NiRTLib.h>

// NiVBChip represent a chunk of vertex buffer memory.
// A chip may be either a whole vertex buffer, or just a section of a much 
//   larger one. 
// A NiVBChip is ALWAYS linked to a NiVBBlock - it can not exist without one.

class NiVBBlock;
#if defined(_XBOX) && !defined(_XENON)
    #include "NiXBoxVBCacheEntry.h"
#endif  //#if defined(_XBOX) && !defined(_XENON)

class NiVBChip
{
protected:
    NiVBChip();
public:
    ~NiVBChip();

    // *** begin NDL internal use only ***
    static NiVBChip* Create(NiVBBlock* pkBlock, D3DVertexBufferPtr pkVB,
        unsigned int uiOffset, unsigned int uiSize, unsigned int uiIndex);

    NiVBBlock* GetBlock();
    D3DVertexBufferPtr GetVB();
    unsigned int GetOffset();
    unsigned int GetLockFlags();
    unsigned int GetSize();
    unsigned int GetIndex();

    NiVBChip* GetNext();
    void SetNext(NiVBChip* pkChip);
    NiVBChip* GetPrev();
    void SetPrev(NiVBChip* pkChip);

    // Set functions should only ever be called by geometry groups.
    void SetBlock(NiVBBlock* pkBlock);
    void SetVB(D3DVertexBufferPtr pkVB);
    void SetOffset(unsigned int uiOffset);
    void SetLockFlags(unsigned int uiLockFlags);
    void SetSize(unsigned int uiSize);
    void SetIndex(unsigned int uiIndex);

#if defined(_XBOX) && !defined(_XENON)
    void SetVBType(NiXBoxVBCacheEntry::Type eType);
    NiXBoxVBCacheEntry::Type GetVBType();
    void SetVBCacheEntry(NiXBoxVBCacheEntry* pkVBCacheEntry);
    NiXBoxVBCacheEntry* GetVBCacheEntry();
    DWORD GetVBFence();
    void SetVBFence(DWORD dwFence);
#endif  //#if defined(_XBOX) && !defined(_XENON)
    // *** end NDL internal use only ***

protected:

    unsigned int m_uiIndex;         // Internally referenced ID
    NiVBBlock* m_pkBlock;           // Parent block
    D3DVertexBufferPtr m_pkVB;      // Pointer to the VB
    unsigned int m_uiOffset;        // Offset into the VB
    unsigned int m_uiLockFlags;     // D3D Flags to use when locking
    unsigned int m_uiSize;          // Size of data in VB (bytes)
#if defined(_XBOX) && !defined(_XENON)
    NiXBoxVBCacheEntry::Type m_eType;
    NiXBoxVBCacheEntryPtr m_spVBCacheEntry;
#endif  //#if defined(_XBOX) && !defined(_XENON)

    NiVBChip* m_pkNextChip;
    NiVBChip* m_pkPrevChip;

    friend class NiVBBlock;
};

#include "NiVBChip.inl"

#endif  //#ifndef NIVBCHIP_H
