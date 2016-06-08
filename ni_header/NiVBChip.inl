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
//  NiVBChip Inline Functions
//---------------------------------------------------------------------------
inline NiVBChip::NiVBChip()
{
    SetIndex(0);
    SetBlock(0);
    SetVB(0);
    SetOffset(0);
    SetSize(0);
    SetLockFlags(0);
#if defined(_XBOX) && !defined(_XENON)
    m_spVBCacheEntry = 0;
#endif  //#if defined(_XBOX) && !defined(_XENON)

    m_pkNextChip = 0;
    m_pkPrevChip = 0;
}
//---------------------------------------------------------------------------
inline NiVBChip::~NiVBChip()
{
    m_pkVB = 0;
}
//---------------------------------------------------------------------------
inline NiVBChip* NiVBChip::Create(NiVBBlock* pkBlock, 
    D3DVertexBufferPtr pkVB, unsigned int uiOffset, unsigned int uiSize, 
    unsigned int uiIndex)
{
    NiVBChip* pkChip = new NiVBChip();
    if (pkChip)
    {
        pkChip->SetIndex(uiIndex);
        pkChip->SetBlock(pkBlock);
        pkChip->SetVB(pkVB);
        pkChip->SetOffset(uiOffset);
        pkChip->SetSize(uiSize);
        pkChip->SetLockFlags(0);
    }

    return pkChip;
}
//---------------------------------------------------------------------------
inline NiVBBlock* NiVBChip::GetBlock(void)
{
    return m_pkBlock;
}
//---------------------------------------------------------------------------
inline D3DVertexBufferPtr NiVBChip::GetVB(void)
{
    return m_pkVB;
}
//---------------------------------------------------------------------------
inline unsigned int NiVBChip::GetOffset(void)
{
    return m_uiOffset;
}
//---------------------------------------------------------------------------
inline unsigned int NiVBChip::GetLockFlags(void)
{
    return m_uiLockFlags;
}
//---------------------------------------------------------------------------
inline unsigned int NiVBChip::GetSize(void)
{
    return m_uiSize;
}
//---------------------------------------------------------------------------
inline unsigned int NiVBChip::GetIndex(void)
{
    return m_uiIndex;
}
//---------------------------------------------------------------------------
inline NiVBChip* NiVBChip::GetNext()
{
    return m_pkNextChip;
}
//---------------------------------------------------------------------------
inline void NiVBChip::SetNext(NiVBChip* pkChip)
{
    m_pkNextChip = pkChip;
}
//---------------------------------------------------------------------------
inline NiVBChip* NiVBChip::GetPrev()
{
    return m_pkPrevChip;
}
//---------------------------------------------------------------------------
inline void NiVBChip::SetPrev(NiVBChip* pkChip)
{
    m_pkPrevChip = pkChip;
}
//---------------------------------------------------------------------------
inline void NiVBChip::SetBlock(NiVBBlock* pkBlock)
{
    m_pkBlock = pkBlock;
}
//---------------------------------------------------------------------------
inline void NiVBChip::SetVB(D3DVertexBufferPtr pkVB)
{
    m_pkVB = pkVB;
}
//---------------------------------------------------------------------------
inline void NiVBChip::SetOffset(unsigned int uiOffset)
{
    m_uiOffset = uiOffset;
}
//---------------------------------------------------------------------------
inline void NiVBChip::SetLockFlags(unsigned int uiLockFlags)
{
    m_uiLockFlags = uiLockFlags;
}
//---------------------------------------------------------------------------
inline void NiVBChip::SetSize(unsigned int uiSize)
{
    m_uiSize = uiSize;
}
//---------------------------------------------------------------------------
inline void NiVBChip::SetIndex(unsigned int uiIndex)
{
    m_uiIndex = uiIndex;
}
//---------------------------------------------------------------------------
#if defined(_XBOX) && !defined(_XENON)
//---------------------------------------------------------------------------
inline void NiVBChip::SetVBType(NiXBoxVBCacheEntry::Type eType)
{
    m_eType = eType;
}
//---------------------------------------------------------------------------
inline NiXBoxVBCacheEntry::Type NiVBChip::GetVBType()
{
    return m_eType;
}
//---------------------------------------------------------------------------
inline void NiVBChip::SetVBCacheEntry(NiXBoxVBCacheEntry* pkVBCacheEntry)
{
    m_spVBCacheEntry = pkVBCacheEntry;
}
//---------------------------------------------------------------------------
inline NiXBoxVBCacheEntry* NiVBChip::GetVBCacheEntry(void)
{
    return m_spVBCacheEntry;
}
//---------------------------------------------------------------------------
inline DWORD NiVBChip::GetVBFence()
{
    assert(m_spVBCacheEntry);
    return m_spVBCacheEntry->GetFence();
}
//---------------------------------------------------------------------------
inline void NiVBChip::SetVBFence(DWORD dwFence)
{
    assert(m_spVBCacheEntry);
    m_spVBCacheEntry->SetFence(dwFence);
}
//---------------------------------------------------------------------------
#endif  //#if defined(_XBOX) && !defined(_XENON)
//---------------------------------------------------------------------------
