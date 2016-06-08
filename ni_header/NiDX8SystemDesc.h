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
#ifndef NIDX8SYSTEMDESC_H
#define NIDX8SYSTEMDESC_H

#include "NiDX8Headers.h"
#include "NiDX8Renderer.h"
#include <NiTArray.h>
#include <NiTPointerList.h>
#include <NiTPointerMap.h>


//#define _DEBUG_DEVICE_INFO_

//---------------------------------------------------------------------------
//  Device description - describes the modes and capabilities of the 
// given rendering device
class NIDX8RENDERER_ENTRY NiDX8DeviceDesc
{
public:
    // Represents a valid screen format and the related properties
    class NIDX8RENDERER_ENTRY DisplayFormatInfo
    {
    public:
        bool CanRenderFullscreen() const;
        bool CanRenderWindowed() const;
        D3DFORMAT GetFormat() const;

        NiDX8Renderer::DepthStencilFormat 
            FindClosestDepthStencil(unsigned int uiDesiredDepthBPP,
            unsigned int uiDesiredStencilBPP) const;
        NiDX8Renderer::DepthStencilFormat 
            FindClosestDepthStencil(D3DFORMAT eFBFormat, 
            unsigned int uiDesiredDepthBPP,
            unsigned int uiDesiredStencilBPP) const;

        bool IsDepthStencilValid(bool bWindowed, D3DFORMAT eRenderFormat, 
            D3DFORMAT eDepthFormat) const;

        static void GetDepthStencilBPPFromFormat(D3DFORMAT eD3DFormat,
            unsigned int& uiDepthBPP, unsigned int& uiStencilBPP);

        D3DMULTISAMPLE_TYPE GetHighestMultiSampleType(bool bWindowed, 
            D3DFORMAT eRenderFormat, D3DFORMAT eDepthFormat) const;

        bool IsMultiSampleValid(bool bWindowed, 
            D3DMULTISAMPLE_TYPE eMultiSampleType,
            D3DFORMAT eRenderFormat, D3DFORMAT eDepthFormat) const;

        // *** begin NDL internal use only ***

        DisplayFormatInfo(LPDIRECT3D8 pkD3D8, unsigned int uiAdapter, 
            D3DDEVTYPE kDevType, D3DFORMAT eFormat, bool bFullscreen, 
            bool bWindowed);
        ~DisplayFormatInfo();

        static unsigned int GetDepthStencilIndex(D3DFORMAT eDepthFormat);

        void Dump();

        enum 
        {
            DEPTH_STENCIL_NUM = 7
        };
        static D3DFORMAT
            ms_aeDepthStencilFormats[DEPTH_STENCIL_NUM];
        
        // *** end NDL internal use only ***

    protected:
        D3DFORMAT m_eFormat;
        bool m_bWindowed;
        bool m_bFullscreen;

        class DepthStencilInfo
        {
        public:
            bool m_bValid;
            unsigned short m_usMultiSampleTypes;
        };

        class RenderTargetInfo
        {
        public:
            RenderTargetInfo();

            // Available depth stencil values
            DepthStencilInfo m_akWindowedDSFormats[DEPTH_STENCIL_NUM];
            DepthStencilInfo m_akFullscreenDSFormats[DEPTH_STENCIL_NUM];
        };

        NiTPointerMap<D3DFORMAT, RenderTargetInfo*> m_kRenderTargets;
    };

    const D3DCAPS8& GetCaps() const;
    D3DDEVTYPE GetDeviceType() const;
    bool IsDeviceValid() const;

    bool CanRenderWindowed() const;

    const DisplayFormatInfo* GetFormatInfo(D3DFORMAT eFormat) const;

    NiDX8Renderer::FrameBufferFormat GetNearestFrameBufferFormat(
        bool bWindowed, unsigned int uiDesiredBPP) const;
    NiDX8Renderer::DepthStencilFormat GetNearestDepthStencilFormat(
        D3DFORMAT eAdapterMode, D3DFORMAT eFBFormat,
        unsigned int uiDesiredDepthBPP, 
        unsigned int uiDesiredStencilBPP) const;

    // *** begin NDL internal use only ***
    
    NiDX8DeviceDesc(LPDIRECT3D8 pkD3D8, unsigned int uiAdapter, 
        D3DDEVTYPE kD3DDevType, D3DFORMAT eCurrDisplayFormat);
    ~NiDX8DeviceDesc();

    void Dump();

    // *** end NDL internal use only ***

protected:
    D3DDEVTYPE m_kD3DDevType;
    D3DCAPS8 m_kD3DCaps8;
    NiTPointerList<DisplayFormatInfo*> m_kScreenFormats;
    bool m_bRenderWindowed;
};

//  Adapter description
class NIDX8RENDERER_ENTRY NiDX8AdapterDesc
{
public:
    //  Mode decription
    class NIDX8RENDERER_ENTRY ModeDesc
    {
    public:
        unsigned int GetClosestRefreshRate(unsigned int uiRefreshRate) const;

        unsigned int m_uiWidth;
        unsigned int m_uiHeight;
        unsigned int m_uiBPP;
        D3DFORMAT m_eD3DFormat;
        NiTPointerList<unsigned int> m_kRefreshRates;

        // *** begin NDL internal use only ***

        ModeDesc(D3DDISPLAYMODE& kD3DMode);

        void Dump();
        
        // *** end NDL internal use only ***
    };

    unsigned int GetAdapterIndex() const;
    const char* GetStringDescription() const;
    const D3DADAPTER_IDENTIFIER8& GetAdapterIdentifier() const;

    const NiDX8DeviceDesc* GetDevice(D3DDEVTYPE kDevType) const;
    const D3DCAPS8* GetDeviceCaps(D3DDEVTYPE kDevType) const;
    bool CanDeviceRenderWindowed(D3DDEVTYPE kDevType) const;

    ModeDesc* ValidateFullscreenMode(D3DFORMAT eFormat,
        unsigned uiWidth, unsigned uiHeight, 
        unsigned int& uiRefreshRate) const;

    unsigned int GetModeCount() const;
    const ModeDesc* GetMode(unsigned int uiMode) const;

    // *** begin NDL internal use only ***
    
    NiDX8AdapterDesc(LPDIRECT3D8 pkD3D8, unsigned int uiAdapter);
    ~NiDX8AdapterDesc();
    void Dump();

    // *** end NDL internal use only ***

protected:
    unsigned int m_uiAdapter;
    D3DADAPTER_IDENTIFIER8 m_kAdapterIdentifier;
    
    NiTArray<ModeDesc*> m_kModeList;

    NiDX8DeviceDesc* m_pkHALDeviceDesc;
    NiDX8DeviceDesc* m_pkREFDeviceDesc;
};
//---------------------------------------------------------------------------
class NIDX8RENDERER_ENTRY NiDX8SystemDesc
{
public:
    unsigned int GetAdapterCount() const;
    const NiDX8AdapterDesc* GetAdapter(unsigned int uiAdapter) const;

    static char* GetD3D8FormatString(D3DFORMAT eD3DFormat);
    static unsigned int GetBPPFromFormat(D3DFORMAT eD3DFormat);

    // *** begin NDL internal use only ***

    NiDX8SystemDesc(LPDIRECT3D8 pkD3D8);
    ~NiDX8SystemDesc();

    // *** end NDL internal use only ***

protected:
    void FillAdapterInformation(LPDIRECT3D8 pkD3D8);

    void Dump();

    unsigned int m_uiAdapterCount;
    NiTArray<NiDX8AdapterDesc*> m_kAdapterList;
};
//---------------------------------------------------------------------------

#include "NiDX8SystemDesc.inl"

#endif  //#ifndef NIDX8SYSTEMDESC_H