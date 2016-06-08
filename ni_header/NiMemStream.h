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

#ifndef NIMEMSTREAM_H
#define NIMEMSTREAM_H

#include "NiSystemLibType.h"
#include "NiRTLib.h"
#include "NiBinaryStream.h"

class NISYSTEM_ENTRY NiMemStream : public NiBinaryStream
{
public:
    // create a read-only stream.
    NiMemStream(const void* pBuffer, unsigned int uiSize);
    // create a read-write stream
    NiMemStream();
    virtual ~NiMemStream();

    virtual operator bool() const;

    virtual unsigned int Read(void* pBuffer, unsigned int uiBytes);
    virtual unsigned int Write(const void* pBuffer, unsigned int uiBytes);
    void* Str();
    void Freeze(bool bFreeze);
    unsigned int GetSize() const;

protected:
    char* m_pBuffer;
    unsigned int m_uiRead;
    unsigned int m_uiWrite;

    unsigned int m_uiAllocSize;
    bool m_bUserMemory;
    bool m_bFreeze;
};

//---------------------------------------------------------------------------
inline unsigned int NiMemStream::GetSize() const
{
    return m_uiWrite;
}
//---------------------------------------------------------------------------

#endif // NIMEMSTREAM_H
