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
inline unsigned int NiBltSource::GetWidth() const
{
    if (m_pkRendererData)
        return m_pkRendererData->GetWidth();
    else if (m_spSrcPixelData)
        return m_spSrcPixelData->GetWidth();
    else
        return 0;
}
//---------------------------------------------------------------------------
inline unsigned int NiBltSource::GetHeight() const
{
    if (m_pkRendererData)
        return m_pkRendererData->GetHeight();
    else if (m_spSrcPixelData)
        return m_spSrcPixelData->GetHeight();
    else
        return 0;
}
//---------------------------------------------------------------------------
inline const char* NiBltSource::GetFilename() const
{
    return m_pcFilename;
}
//---------------------------------------------------------------------------
inline const char* NiBltSource::GetPlatformSpecificFilename() const
{
    return m_pcPlatformFilename;
}
//---------------------------------------------------------------------------
inline const NiPixelData* NiBltSource::GetSourcePixelData() const
{
    return m_spSrcPixelData;
}
//---------------------------------------------------------------------------
inline NiBltSource::NiBltSource()
{
    m_pcFilename = 0;
    m_pcPlatformFilename = 0;

    m_pkRendererData = 0;

    m_pkPrev = 0;
    m_pkNext = 0;

    AddBltToList();
}
//---------------------------------------------------------------------------
inline NiBltSource::~NiBltSource()
{
    delete[] m_pcFilename;
    delete[] m_pcPlatformFilename;

    delete m_pkRendererData;
    RemoveBltFromList();
}
//---------------------------------------------------------------------------
inline void NiBltSource::SetRendererData(RendererData* pkRendererData)
{
    m_pkRendererData = pkRendererData;
}
//---------------------------------------------------------------------------
inline NiBltSource* NiBltSource::GetListNext()
{
    return m_pkNext;
}
//---------------------------------------------------------------------------
inline NiBltSource* NiBltSource::GetListPrev()
{
    return m_pkPrev;
}
//---------------------------------------------------------------------------
inline NiBltSource::RendererData* NiBltSource::GetRendererData() const
{
    return m_pkRendererData;
}
//---------------------------------------------------------------------------
inline NiBltSource::RendererData::RendererData(NiBltSource* pkBlt)
{
    m_pkBlt = pkBlt;
}
//---------------------------------------------------------------------------
inline NiBltSource::RendererData::~RendererData()
{
    /* */
}
//---------------------------------------------------------------------------
inline NiBltSource* NiBltSource::GetListHead()
{
    return ms_pkHead;
}
//---------------------------------------------------------------------------
inline NiBltSource* NiBltSource::GetListTail()
{
    return ms_pkTail;
}
//---------------------------------------------------------------------------
inline void NiBltSource::AddBltToList()
{
    ms_kBltListCriticalSection.Lock();
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
    ms_kBltListCriticalSection.Unlock();
}
//---------------------------------------------------------------------------
inline void NiBltSource::RemoveBltFromList()
{
    ms_kBltListCriticalSection.Lock();
    if (ms_pkHead == this)
        ms_pkHead = m_pkNext;
    if (ms_pkTail == this)
        ms_pkTail = m_pkPrev;

    if (m_pkPrev)
        m_pkPrev->m_pkNext = m_pkNext;
    if (m_pkNext)
        m_pkNext->m_pkPrev = m_pkPrev;
    ms_kBltListCriticalSection.Unlock();
}
//---------------------------------------------------------------------------
