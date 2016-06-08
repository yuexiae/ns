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

#ifndef NINIFIMAGEREADER_H
#define NINIFIMAGEREADER_H

#include "NiImageReader.h"
#include "NiStream.h"

class NIMAIN_ENTRY NiNIFImageReader : public NiImageReader
{
public:
    NiNIFImageReader();
    ~NiNIFImageReader();

    virtual bool CanReadFile(const char* pcFileExtension) const;

    virtual NiPixelData* ReadFile(NiFile& kIst, NiPixelData* pkOptDest);

    virtual bool ReadHeader(NiFile& kIst, 
        unsigned int& uiWidth, unsigned int& uiHeight, 
        NiPixelFormat& kFormat, bool& bMipmap);

protected:
    NiStream m_kStream;
};

#endif
