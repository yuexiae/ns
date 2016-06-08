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
inline NiStringPalette::NiStringPalette() : m_pcBuffer(NULL),
    m_uiAllocatedSize(0), m_uiEndOfBuffer(0)
{
}
//---------------------------------------------------------------------------
inline NiStringPalette::NiStringPalette(unsigned int uiAllocatedSize) :
    m_pcBuffer(NULL), m_uiAllocatedSize(uiAllocatedSize), m_uiEndOfBuffer(0)
{
    if (m_uiAllocatedSize > 0)
    {
        m_pcBuffer = new char[m_uiAllocatedSize];
        memset(m_pcBuffer, 0, m_uiAllocatedSize * sizeof(char));
    }
}
//---------------------------------------------------------------------------
inline NiStringPalette::~NiStringPalette()
{
    delete[] m_pcBuffer;
}
//---------------------------------------------------------------------------
inline char* NiStringPalette::GetBasePointer() const
{
    return m_pcBuffer;
}
//---------------------------------------------------------------------------
inline unsigned int NiStringPalette::AddString(const char* pcString)
{
    assert(pcString != NULL);

    unsigned int uiStringLength = strlen(pcString) + 1;
    if (m_uiEndOfBuffer + uiStringLength > m_uiAllocatedSize)
    {
        ReallocateBuffer();
        assert(m_uiEndOfBuffer + uiStringLength <= m_uiAllocatedSize);
    }

    unsigned int uiStringLocation = m_uiEndOfBuffer;
    char* pcStringLocation = m_pcBuffer + uiStringLocation;
    *pcStringLocation = '\0';
    strcpy(pcStringLocation, pcString);
    m_uiEndOfBuffer += uiStringLength;

    return uiStringLocation;
}
//---------------------------------------------------------------------------
inline void NiStringPalette::ReallocateBuffer()
{
    unsigned int uiNewAllocatedSize = m_uiAllocatedSize * 2;
    char* pcNewBuffer = new char[uiNewAllocatedSize];
    memset(pcNewBuffer, 0, uiNewAllocatedSize * sizeof(char));

    memcpy(pcNewBuffer, m_pcBuffer, m_uiAllocatedSize * sizeof(char));
    delete[] m_pcBuffer;
    m_pcBuffer = pcNewBuffer;
    m_uiAllocatedSize = uiNewAllocatedSize;
}
//---------------------------------------------------------------------------
