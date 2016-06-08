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
#ifndef NIDX8PIXELFORMAT_H
#define NIDX8PIXELFORMAT_H

#include <NiSystem.h>
#include <NiPixelFormat.h>
#include "NiDX8RendererLibType.h"
#include "NiDX8Headers.h"

class NIDX8RENDERER_ENTRY NiDX8PixelFormat : public NiPixelFormat
{
public:
    NiDX8PixelFormat();
    NiDX8PixelFormat(const NiPixelFormat &kFmt);
    NiDX8PixelFormat(const NiDX8PixelFormat &kFmt);
    NiDX8PixelFormat(D3DFORMAT eD3DFmt);

    static D3DFORMAT DetermineD3DFormat(const NiPixelFormat& kDesc);

    unsigned int GetExtraData() const;
    void SetExtraData(unsigned int uiExtraData);
    D3DFORMAT GetD3DFormat() const;
    void SetD3DFormat(D3DFORMAT eD3DFmt);

    bool operator==(const NiDX8PixelFormat& kPixDesc) const;
    bool operator!=(const NiDX8PixelFormat& kPixDesc) const;
    NiPixelFormat& operator=(const NiDX8PixelFormat& kPixDesc);

protected:

    void InitFromD3DFormat(D3DFORMAT eD3DFmt);

    unsigned int m_uiExtra;
    D3DFORMAT m_eD3DFmt;
};    

#include "NiDX8PixelFormat.inl"

#endif  //#ifndef NIDX8PIXELFORMAT_H
