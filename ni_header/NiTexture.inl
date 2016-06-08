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
inline NiTexture::NiTexture()
{
    m_pkRendererData = 0;
    AddTextureToList();
}
//---------------------------------------------------------------------------
inline NiTexture::~NiTexture()
{
    delete m_pkRendererData;
    RemoveTextureFromList();
}
//---------------------------------------------------------------------------
inline NiTexture::FormatPrefs::FormatPrefs()
{
    m_ePixelLayout = PIX_DEFAULT;
    m_eMipMapped = MIP_DEFAULT;
    m_eAlphaFmt = ALPHA_DEFAULT;
}
//---------------------------------------------------------------------------
inline const NiTexture::FormatPrefs& NiTexture::GetFormatPreferences() const
{
    return m_kFormatPrefs;
}
//---------------------------------------------------------------------------
inline void NiTexture::SetRendererData(RendererData* pkRendererData)
{
    m_pkRendererData = pkRendererData;
}
//---------------------------------------------------------------------------
inline NiTexture* NiTexture::GetListNext()
{
    return m_pkNext;
}
//---------------------------------------------------------------------------
inline NiTexture* NiTexture::GetListPrev()
{
    return m_pkPrev;
}
//---------------------------------------------------------------------------
inline NiTexture::RendererData* NiTexture::GetRendererData() const
{
    return m_pkRendererData;
}
//---------------------------------------------------------------------------
inline bool NiTexture::GetMipmapByDefault()
{
    return ms_bMipmapByDefault;
}
//---------------------------------------------------------------------------
inline void NiTexture::SetMipmapByDefault(bool bMipmap)
{
    ms_bMipmapByDefault = bMipmap;
}
//---------------------------------------------------------------------------
inline NiTexture::RendererData::RendererData(NiTexture* pkTexture)
{
    m_pkTexture = pkTexture;
}
//---------------------------------------------------------------------------
inline NiTexture::RendererData::~RendererData()
{
    /* */
}
//---------------------------------------------------------------------------
inline NiTexture* NiTexture::GetListHead()
{
    return ms_pkHead;
}
//---------------------------------------------------------------------------
inline NiTexture* NiTexture::GetListTail()
{
    return ms_pkTail;
}
//---------------------------------------------------------------------------
inline void NiTexture::AddTextureToList()
{
    ms_kTextureListCriticalSection.Lock();
    if (!ms_pkHead)
        ms_pkHead = this;
    if (ms_pkTail)
    {
        ms_pkTail->m_pkNext = this;
        m_pkPrev = ms_pkTail;
    }
    else
    {
        m_pkPrev = 0;
    }
    ms_pkTail = this;
    m_pkNext = 0;
    ms_kTextureListCriticalSection.Unlock();
}
//---------------------------------------------------------------------------
inline void NiTexture::RemoveTextureFromList()
{
    ms_kTextureListCriticalSection.Lock();
    if (ms_pkHead == this)
        ms_pkHead = m_pkNext;
    if (ms_pkTail == this)
        ms_pkTail = m_pkPrev;

    if (m_pkPrev)
        m_pkPrev->m_pkNext = m_pkNext;
    if (m_pkNext)
        m_pkNext->m_pkPrev = m_pkPrev;
    ms_kTextureListCriticalSection.Unlock();
}
//---------------------------------------------------------------------------
inline void NiTexture::LockTextureList()
{
    ms_kTextureListCriticalSection.Lock();
}
//---------------------------------------------------------------------------
inline void NiTexture::UnlockTextureList()
{
    ms_kTextureListCriticalSection.Unlock();
}
