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

#ifndef NISOURCETEXTURE_H
#define NISOURCETEXTURE_H

#include "NiBool.h"
#include "NiPixelData.h"
#include "NiTexture.h"

class NiPixelFormat;

class NIMAIN_ENTRY NiSourceTexture : public NiTexture
{
    NiDeclareRTTI;
    NiDeclareStream;
    NiDeclareViewerStrings;

protected:
    static FormatPrefs ms_kDefaultPrefs;
public:
    // Create from a filename
    static NiSourceTexture* Create(const char* pcFilename,
        FormatPrefs& kPrefs = ms_kDefaultPrefs,
        bool bLoadDirectToRendererHint = false);

    // Create from application pixel data
    static NiSourceTexture* Create(NiPixelData* pkRaw,
        FormatPrefs& kPrefs = ms_kDefaultPrefs);

    virtual unsigned int GetWidth() const;
    virtual unsigned int GetHeight() const;

    // Filename will be null if created from pixel data
    const char* GetFilename() const;
    void SetFilename(const char* pcFilename);

    // This is the filename that is actually used to read from disk
    const char* GetPlatformSpecificFilename() const;

    // PixelData will be null if image was created from PixelData and
    // has been marked as static OR if image was created from a file 
    // and LoadPixelDataFromFile has not been called.
    NiPixelData* GetSourcePixelData();
    const NiPixelData* GetSourcePixelData() const;

    // Create the application level backing store for an image
    // loaded from file.  By default this backing store is not 
    // created, instead only the renderer specific store is built.
    virtual void LoadPixelDataFromFile();

    // Destroy the application level backing store -- this can be done
    // if an application has no need to retain access to a version of
    // the pixel data for its own modification or otherwise.
    virtual void DestroyAppPixelData();

    // Gives texture/renderer freedom to assume that a texture (i.e.
    // its pixel data) will not change.  This can offer a sizable
    // optimization for renderer image setup costs.  
    void SetStatic(bool bStatic);
    bool GetStatic() const;

    // Returns a pointer to a pixel descriptor that matches the format
    // that will be used by the renderer
    const NiPixelFormat* GetRendererPixelFormat() const;

    // Supplies a hint to the renderer indicating whether to load the
    // texture directly into the internal data structures, bypassing
    // the application-accessible NiPixelData, as well as all texture
    // conversion, entirely.
    void SetLoadDirectToRendererHint(bool bDirect);
    bool GetLoadDirectToRendererHint() const;

    // Default behavior is to always preload.  Application must turn
    // off preloading if they want otherwise
    static void SetUsePreloading(bool bPreload);
    static bool GetUsePreloading();

    // Default behavior is to always mipmap.  Application must turn
    // off mipmapping if they want otherwise
    static void SetUseMipmapping(bool bMipmap);
    static bool GetUseMipmapping();

    // Default behavior is to not destroy the NiPixelData object once the
    // texture is loaded into the renderer.  Application must turn
    // on this feature if they want otherwise
    static void SetDestroyAppDataFlag(bool bDestroy);
    static bool GetDestroyAppDataFlag();

    /*** begin NDL internal use only ***/

    // streaming support
    virtual void PostLinkObject(NiStream& kStream);

    /*** end NDL internal use only ***/

protected:
    NiSourceTexture();
    virtual ~NiSourceTexture();

    virtual bool CreateRendererData();

    char* m_pcFilename;
    char* m_pcPlatformFilename;
    NiPixelDataPtr m_spSrcPixelData;
    bool m_bStatic;

    bool m_bLoadDirectToRendererHint;

    static bool ms_bPreload;
    static bool ms_bMipmap;
    static bool ms_bDestroyAppData;
};

typedef NiPointer<NiSourceTexture> NiSourceTexturePtr;

//---------------------------------------------------------------------------
#include "NiSourceTexture.inl"
//---------------------------------------------------------------------------

#endif
