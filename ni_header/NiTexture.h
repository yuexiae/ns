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

#ifndef NITEXTURE_H
#define NITEXTURE_H

#include "NiObjectNET.h"
#include "NiMainLibType.h"
#include "NiColor.h"

class NiPixelFormat;

NiSmartPointer(NiImageConverter);
NiSmartPointer(NiPixelData);
NiSmartPointer(NiTexture);

class NIMAIN_ENTRY NiTexture : public NiObjectNET
{
    NiDeclareRTTI;
    NiDeclareAbstractStream;
    NiDeclareViewerStrings;

public:
    NiTexture();
    virtual ~NiTexture();

    virtual unsigned int GetWidth() const = 0;
    virtual unsigned int GetHeight() const = 0;

    class FormatPrefs
    {
    public:
        // Creates a format preferences instance with DEFAULT values
        // for all data members
        FormatPrefs();

        // Preferred "high-level" pixel layout -- does not dictate
        // the exact pixel *format* (i.e. NiPixelFormat) for the image
        // but rather an application level of pixel setup.
        enum PixelLayout
        {
            PALETTIZED_8,
            HIGH_COLOR_16,
            TRUE_COLOR_32,
            COMPRESSED,
            BUMPMAP,
            PALETTIZED_4,
            PIX_DEFAULT
        };
        PixelLayout m_ePixelLayout;
        // Mip-mapping preference
        enum MipFlag
        {
            NO = false,
            YES = true,
            MIP_DEFAULT
        }; 
        MipFlag m_eMipMapped;
        // Alpha preference
        enum AlphaFormat
        {
            NONE, 
            BINARY, // 1-bit
            SMOOTH, // multi-bit
            ALPHA_DEFAULT
        };
        AlphaFormat m_eAlphaFmt;
    };

    // Get a reference to the application format preferences.
    const FormatPrefs& GetFormatPreferences() const;

    static bool GetMipmapByDefault();
    static void SetMipmapByDefault(bool bMipmap);

    /*** begin NDL internal use only ***/

    // Renderer specific data class
    class RendererData;
    class NIMAIN_ENTRY RendererData
    {
    public:
        RendererData(NiTexture* pkTexture);
        virtual ~RendererData();

        virtual bool IsLoaded() const = 0;
        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHeight() const = 0;
        virtual const NiPixelFormat* GetPixelFormat() const = 0;

        enum CreationFailure
        {
            NONE                = 0x00000000,
            GENERIC             = 0x80000000,
            NO2DMATCH           = 0x80000001,
            NOCUBEMAPMATCH      = 0x80000002,
            NOCONVERTER         = 0x80000003,
            FAILEDCONVERT       = 0x80000004,
            FILENOTFOUND        = 0x80000005,
            BADDIMENSIONS       = 0x80000006,
            // New failures go ABOVE this enum, just for readability
            // Make sure to update the COUNT value below. It should
            // be the (last value & 0x7fffffff) + 1
            CREATEFAIL_COUNT    = (BADDIMENSIONS & 0x7fffffff) + 1
        };

        static void _SDMInit();
        static void _SDMShutdown();

        typedef NiPixelData* (*TEXTUREFAILUREFUNC)(NiTexture* pkTexture, 
            CreationFailure eFailure);

        static void SetTextureFailureCallback(TEXTUREFAILUREFUNC pfnFunc);

        static NiPixelData* DefaultTextureFailureCallback(NiTexture* pkTexture,
            CreationFailure eFailure);

        static void SetTextureReplacementFormat(const NiPixelFormat& kFormat);

    protected:
        static NiPixelData* GetReplacementData(NiTexture* pkTexture, 
            CreationFailure eFailure, bool bReport = true);
        static NiPixelData* MakeDataFromColors(const NiColorA& kTopLeftColor,
            const NiColorA& kBottomLeftColor, const NiPixelFormat& kDesc);
        static void ReportDataCreationError(CreationFailure eFailure);

        NiTexture* m_pkTexture;

        // Default TEXTUREFAILUREFUNC function, called when a texture fails to
        // open or convert.
        static TEXTUREFAILUREFUNC ms_pfnTextureFailureCallback;

        static NiPixelDataPtr ms_aspReplacementData[CREATEFAIL_COUNT];
        static NiPixelFormat ms_kReplacementFormat;
    };

    void SetRendererData(RendererData* pkRendererData);
    RendererData* GetRendererData() const;

    NiTexture* GetListNext();
    NiTexture* GetListPrev();

    static NiTexture* GetListHead();
    static NiTexture* GetListTail();

    static void LockTextureList();
    static void UnlockTextureList();

    /*** end NDL internal use only ***/

protected:
    void AddTextureToList();
    void RemoveTextureFromList();

    FormatPrefs m_kFormatPrefs;
    RendererData* m_pkRendererData;

    // Doubly linked list traversal members for list of all textures
    NiTexture* m_pkPrev;
    NiTexture* m_pkNext;
    static NiTexture* ms_pkHead;
    static NiTexture* ms_pkTail;
    static NiCriticalSection ms_kTextureListCriticalSection;

    static bool ms_bMipmapByDefault;
};

#include "NiTexture.inl"

#endif
