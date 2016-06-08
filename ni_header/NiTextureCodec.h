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
#ifndef NITEXTURECODEC_H
#define NITEXTURECODEC_H

#include "NiPixelFormat.h"

class NIMAIN_ENTRY NiTextureCodec
{
public:
    NiTextureCodec();
    ~NiTextureCodec();

    NiPixelData* ExpandCompressedData(const NiPixelData& kSrc);

protected:
    enum 
    {
        DEST_PIXEL_STRIDE = 4
    };

    void DecodeT3AlphaBlock(unsigned char* pucAlphas);
    void DecodeT5AlphaBlock(unsigned char* pucAlphas);
    void DecodeColorBlock(unsigned char* pucColors);
    void DecodeColorAlphaBlock(unsigned char* pucDest);

    void DecodeBlock(unsigned char* pucDest, unsigned int uiCols, 
        unsigned int uiRows);

    void (NiTextureCodec::*m_pfnAlphaBlockDecoder)(unsigned char* pucDest);
    void (NiTextureCodec::*m_pfnColorBlockDecoder)(unsigned char* pucDest);

    const unsigned char* m_pucSrcPtr;

    unsigned int m_uiDestRowStride;

    unsigned char m_aaucExplicitAlphaLookup[256][2];
};

#endif
