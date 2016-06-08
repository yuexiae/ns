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
inline NiDX9PixelFormat::NiDX9PixelFormat() : NiPixelFormat() 
{
    m_uiExtra = 0;
    m_eD3DFmt = D3DFMT_UNKNOWN;
}
//---------------------------------------------------------------------------
inline NiDX9PixelFormat::NiDX9PixelFormat(const NiPixelFormat &kFmt) :
    NiPixelFormat(kFmt) 
{
    m_uiExtra = 0;
    m_eD3DFmt = DetermineD3DFormat(kFmt);
}
//---------------------------------------------------------------------------
inline NiDX9PixelFormat::NiDX9PixelFormat(const NiDX9PixelFormat &kFmt)
{
    (NiPixelFormat&)(*this) = (NiPixelFormat&)kFmt;
    m_uiExtra = 0;
    m_eD3DFmt = DetermineD3DFormat(kFmt);
}
//---------------------------------------------------------------------------
inline NiDX9PixelFormat::NiDX9PixelFormat(D3DFORMAT eD3DFmt)
{
    InitFromD3DFormat(eD3DFmt);
}
//---------------------------------------------------------------------------
inline unsigned int NiDX9PixelFormat::GetExtraData() const
{
    return m_uiExtra;
}
//---------------------------------------------------------------------------
inline void NiDX9PixelFormat::SetExtraData(unsigned int uiExtraData)
{
    m_uiExtra = uiExtraData;
}
//---------------------------------------------------------------------------
inline D3DFORMAT NiDX9PixelFormat::GetD3DFormat() const
{
    return m_eD3DFmt;
}
//---------------------------------------------------------------------------
inline void NiDX9PixelFormat::SetD3DFormat(D3DFORMAT eD3DFmt)
{
    m_eD3DFmt = eD3DFmt;
}
//---------------------------------------------------------------------------
inline bool NiDX9PixelFormat::operator==(
    const NiDX9PixelFormat& kPixDesc) const
{
    return (*((NiPixelFormat*)this) == *((NiPixelFormat*)&kPixDesc) &&
        (m_eD3DFmt == kPixDesc.GetD3DFormat()));
}
//---------------------------------------------------------------------------
inline bool NiDX9PixelFormat::operator!=(
    const NiDX9PixelFormat& kPixDesc) const
{
    return (*((NiPixelFormat*)this) != *((NiPixelFormat*)&kPixDesc) ||
        (m_eD3DFmt != kPixDesc.GetD3DFormat()));
}
//---------------------------------------------------------------------------
inline NiPixelFormat& NiDX9PixelFormat::operator=(
    const NiDX9PixelFormat& kPixDesc)
{
    m_eD3DFmt = kPixDesc.GetD3DFormat();

    return *((NiPixelFormat*)this) = *((NiPixelFormat*)&kPixDesc);
}
//---------------------------------------------------------------------------
