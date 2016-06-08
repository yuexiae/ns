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
#ifndef NISGIREADER_H
#define NISGIREADER_H

#include "NiImageReader.h"
#include "NiPixelFormat.h"

class NIMAIN_ENTRY NiSGIReader : public NiImageReader
{
public:
    NiSGIReader();
    ~NiSGIReader();

    virtual bool CanReadFile(const char* pFileExtension) const;

    virtual NiPixelData* ReadFile(NiFile& ist, NiPixelData* pOptDest);

    virtual bool ReadHeader(NiFile& ist, 
        unsigned int& uiWidth, unsigned int& uiHeight, 
        NiPixelFormat& kFormat, bool& bMipmap);

protected:
    enum 
    {
        SGI_VERBATIM = 0,
        SGI_RLE = 1
    };
 
    enum
    {
        SGI_MAGIC = 474
    };

    static unsigned char GetRevByte(NiFile &ist);
    static unsigned short GetRevWord(NiFile &ist);
    static unsigned long GetRevDWord(NiFile &ist);
    void ProcessRLERowByte (unsigned char* pOutputImageData, 
        unsigned char* pInputImageData, int iImageStep);
    void ProcessRLERowWord (unsigned char* pOutputImageData, 
        unsigned char* pInputImageData, int iImageStep);

    unsigned short m_usWidth;
    unsigned short m_usHeight;
    unsigned short m_usDepth;
    unsigned char m_ucBytesPerComponent;
    bool m_bRLE;
    NiPixelFormat m_kFormat;
};

#endif
