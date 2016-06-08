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
inline NiSourceTexture::NiSourceTexture() :
    m_pcFilename(NULL),
    m_pcPlatformFilename(NULL),
    m_bStatic(true),
    m_bLoadDirectToRendererHint(false)
{
    /* */
}
//---------------------------------------------------------------------------
inline NiSourceTexture::~NiSourceTexture()
{
    delete [] m_pcFilename;
    delete [] m_pcPlatformFilename;
    m_spSrcPixelData = 0;
}
//---------------------------------------------------------------------------
inline const char* NiSourceTexture::GetFilename() const
{
    return m_pcFilename;
}
//---------------------------------------------------------------------------
inline const char* NiSourceTexture::GetPlatformSpecificFilename() const
{
    return m_pcPlatformFilename;
}
//---------------------------------------------------------------------------
inline NiPixelData* NiSourceTexture::GetSourcePixelData()
{
    return m_spSrcPixelData;
}
//---------------------------------------------------------------------------
inline const NiPixelData* NiSourceTexture::GetSourcePixelData() const
{
    return m_spSrcPixelData;
}
//---------------------------------------------------------------------------
inline void NiSourceTexture::SetStatic(bool bStatic)
{
    m_bStatic = bStatic;
}
//---------------------------------------------------------------------------
inline bool NiSourceTexture::GetStatic() const
{
    return m_bStatic;
}
//---------------------------------------------------------------------------
inline const NiPixelFormat* NiSourceTexture::GetRendererPixelFormat() const
{
    if (m_pkRendererData)
        return m_pkRendererData->GetPixelFormat();
    else
        return 0;
}
//---------------------------------------------------------------------------
inline void NiSourceTexture::SetLoadDirectToRendererHint(bool bDirect)
{
    m_bLoadDirectToRendererHint = bDirect;
}
//---------------------------------------------------------------------------
inline bool NiSourceTexture::GetLoadDirectToRendererHint() const
{
    return m_bLoadDirectToRendererHint;
}
//---------------------------------------------------------------------------
inline void NiSourceTexture::SetUsePreloading(bool bPreload)
{
    ms_bPreload = bPreload;
}
//---------------------------------------------------------------------------
inline bool NiSourceTexture::GetUsePreloading()
{
    return ms_bPreload;
}
//---------------------------------------------------------------------------
inline void NiSourceTexture::SetUseMipmapping(bool bMipmap)
{
    ms_bMipmap = bMipmap;
}
//---------------------------------------------------------------------------
inline bool NiSourceTexture::GetUseMipmapping()
{
    return ms_bMipmap;
}
//---------------------------------------------------------------------------
inline void NiSourceTexture::SetDestroyAppDataFlag(bool bDestroy)
{
    ms_bDestroyAppData = bDestroy;
}
//---------------------------------------------------------------------------
inline bool NiSourceTexture::GetDestroyAppDataFlag()
{
    return ms_bDestroyAppData;
}
//---------------------------------------------------------------------------
