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

#ifndef NIBINARYSTREAM_H
#define NIBINARYSTREAM_H
#include "NiSystemLibType.h"

//---------------------------------------------------------------------------
class NISYSTEM_ENTRY NiBinaryStream
{
public:
    virtual ~NiBinaryStream();
    virtual operator bool() const = 0;

    // Read returns the number of bytes read.
    virtual unsigned int Read(void* pBuffer, unsigned int uiBytes) = 0;

    // Write returns the number of bytes written.
    virtual unsigned int Write(const void* pBuffer, unsigned int uiBytes) = 0;

    // GetLine reads bytes until it reachs a '\n' character, or it reaches
    // the end of the stream, or it reads uiMaxBytes - 1 bytes. It does not
    // copy the '\n' to pBuffer, but it does terminate pBuffer with a 0. The
    // return value is the number of bytes read.
    unsigned int GetLine(char* pBuffer, unsigned int uiMaxBytes);

    // PutS writes a 0-terminated string. The 0 is not written. The return
    // value is the number of bytes written.
    unsigned int PutS(const char* pBuffer);


};

//---------------------------------------------------------------------------
// Inline load/save routines for native data.
//---------------------------------------------------------------------------
template <class T>
void NiStreamLoadBinary (NiBinaryStream& binstream, T& value)
{
    NiBinaryStreamLoad(binstream, &value, 1);
}
//---------------------------------------------------------------------------
template <class T>
void NiStreamLoadBinary (NiBinaryStream& binstream, T* value, 
    unsigned int uiNumEls)
{
    NiBinaryStreamLoad(binstream, value, uiNumEls);
}
//---------------------------------------------------------------------------
template <class T>
void NiStreamSaveBinary (NiBinaryStream& binstream, T& value)
{
    NiBinaryStreamSave(binstream, &value, 1);
}
//---------------------------------------------------------------------------
template <class T>
void NiStreamSaveBinary (NiBinaryStream& binstream, T* value, 
    unsigned int uiNumEls)
{
    NiBinaryStreamSave(binstream, value, uiNumEls);
}
//---------------------------------------------------------------------------

#endif // NIBINARYSTREAM_H
