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
#ifndef NIDX9PIXELFORMAT_H
#define NIDX9PIXELFORMAT_H

#include <NiSystem.h>
#include <NiPixelFormat.h>
#include "NiDX9RendererLibType.h"
#include "NiDX9Headers.h"

class NIDX9RENDERER_ENTRY NiDX9PixelFormat : public NiPixelFormat
{
public:
    NiDX9PixelFormat();
    NiDX9PixelFormat(const NiPixelFormat &kFmt);
    NiDX9PixelFormat(const NiDX9PixelFormat &kFmt);
    NiDX9PixelFormat(D3DFORMAT eD3DFmt);

    static D3DFORMAT DetermineD3DFormat(const NiPixelFormat& kDesc);

    unsigned int GetExtraData() const;
    void SetExtraData(unsigned int uiExtraData);
    D3DFORMAT GetD3DFormat() const;
    void SetD3DFormat(D3DFORMAT eD3DFmt);

    bool operator==(const NiDX9PixelFormat& kPixDesc) const;
    bool operator!=(const NiDX9PixelFormat& kPixDesc) const;
    NiPixelFormat& operator=(const NiDX9PixelFormat& kPixDesc);

protected:

    void InitFromD3DFormat(D3DFORMAT eD3DFmt);

    unsigned int m_uiExtra;
    D3DFORMAT m_eD3DFmt;
};    

#include "NiDX9PixelFormat.inl"

#endif  //#ifndef NIDX9PIXELFORMAT_H
