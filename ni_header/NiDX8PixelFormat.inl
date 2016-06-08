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
inline NiDX8PixelFormat::NiDX8PixelFormat() : NiPixelFormat() 
{
    m_uiExtra = 0;
    m_eD3DFmt = D3DFMT_UNKNOWN;
}
//---------------------------------------------------------------------------
inline NiDX8PixelFormat::NiDX8PixelFormat(const NiPixelFormat &kFmt) :
    NiPixelFormat(kFmt) 
{
    m_uiExtra = 0;
    m_eD3DFmt = DetermineD3DFormat(kFmt);
}
//---------------------------------------------------------------------------
inline NiDX8PixelFormat::NiDX8PixelFormat(const NiDX8PixelFormat &kFmt)
{
    (NiPixelFormat&)(*this) = (NiPixelFormat&)kFmt;
    m_uiExtra = 0;
    m_eD3DFmt = DetermineD3DFormat(kFmt);
}
//---------------------------------------------------------------------------
inline NiDX8PixelFormat::NiDX8PixelFormat(D3DFORMAT eD3DFmt)
{
    InitFromD3DFormat(eD3DFmt);
}
//---------------------------------------------------------------------------
inline unsigned int NiDX8PixelFormat::GetExtraData() const
{
    return m_uiExtra;
}
//---------------------------------------------------------------------------
inline void NiDX8PixelFormat::SetExtraData(unsigned int uiExtraData)
{
    m_uiExtra = uiExtraData;
}
//---------------------------------------------------------------------------
inline D3DFORMAT NiDX8PixelFormat::GetD3DFormat() const
{
    return m_eD3DFmt;
}
//---------------------------------------------------------------------------
inline void NiDX8PixelFormat::SetD3DFormat(D3DFORMAT eD3DFmt)
{
    m_eD3DFmt = eD3DFmt;
}
//---------------------------------------------------------------------------
inline bool NiDX8PixelFormat::operator==(
    const NiDX8PixelFormat& kPixDesc) const
{
    return (*((NiPixelFormat*)this) == *((NiPixelFormat*)&kPixDesc) &&
        (m_eD3DFmt == kPixDesc.GetD3DFormat()));
}
//---------------------------------------------------------------------------
inline bool NiDX8PixelFormat::operator!=(
    const NiDX8PixelFormat& kPixDesc) const
{
    return (*((NiPixelFormat*)this) != *((NiPixelFormat*)&kPixDesc) ||
        (m_eD3DFmt != kPixDesc.GetD3DFormat()));
}
//---------------------------------------------------------------------------
inline NiPixelFormat& NiDX8PixelFormat::operator=(
    const NiDX8PixelFormat& kPixDesc)
{
    m_eD3DFmt = kPixDesc.GetD3DFormat();

    return *((NiPixelFormat*)this) = *((NiPixelFormat*)&kPixDesc);
}
//---------------------------------------------------------------------------
