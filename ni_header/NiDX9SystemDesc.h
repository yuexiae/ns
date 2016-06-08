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
#ifndef NIDX9SYSTEMDESC_H
#define NIDX9SYSTEMDESC_H

#include "NiDX9Headers.h"
#include "NiDX9Renderer.h"
#include <NiTArray.h>
#include <NiTPointerList.h>
#include <NiTPointerMap.h>


//#define _DEBUG_DEVICE_INFO_

//---------------------------------------------------------------------------
//  Device description - describes the modes and capabilities of the 
// given rendering device
class NIDX9RENDERER_ENTRY NiDX9DeviceDesc
{
public:
    // Represents a valid screen format and the related properties
    class NIDX9RENDERER_ENTRY DisplayFormatInfo
    {
    public:
        bool CanRenderFullscreen() const;
        bool CanRenderWindowed() const;
        D3DFORMAT GetFormat() const;

        NiDX9Renderer::DepthStencilFormat 
            FindClosestDepthStencil(unsigned int uiDesiredDepthBPP,
            unsigned int uiDesiredStencilBPP) const;
        NiDX9Renderer::DepthStencilFormat 
            FindClosestDepthStencil(D3DFORMAT eFBFormat, 
            unsigned int uiDesiredDepthBPP,
            unsigned int uiDesiredStencilBPP) const;

        bool IsDepthStencilValid(bool bWindowed, D3DFORMAT eRenderFormat, 
            D3DFORMAT eDepthFormat) const;

        static void GetDepthStencilBPPFromFormat(D3DFORMAT eD3DFormat,
            unsigned int& uiDepthBPP, unsigned int& uiStencilBPP);

        unsigned int GetNonmaskableMultiSampleQuality(bool bWindowed, 
            D3DFORMAT eRenderFormat, D3DFORMAT eDepthFormat) const;

        D3DMULTISAMPLE_TYPE GetHighestMultiSampleType(bool bWindowed, 
            D3DFORMAT eRenderFormat, D3DFORMAT eDepthFormat) const;

        bool IsMultiSampleValid(bool bWindowed, 
            D3DMULTISAMPLE_TYPE eMultiSampleType,
            D3DFORMAT eRenderFormat, D3DFORMAT eDepthFormat) const;

        // *** begin NDL internal use only ***

        DisplayFormatInfo(LPDIRECT3D9 pkD3D9, unsigned int uiAdapter, 
            D3DDEVTYPE kDevType, D3DFORMAT eFormat, bool bFullscreen, 
            bool bWindowed);
        ~DisplayFormatInfo();

        static unsigned int GetDepthStencilIndex(D3DFORMAT eDepthFormat);

        void Dump();

        enum 
        {
            DEPTH_STENCIL_NUM = 9
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
            unsigned char m_ucMultiSampleQuality;
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

    const D3DCAPS9& GetCaps() const;
    D3DDEVTYPE GetDeviceType() const;
    bool IsDeviceValid() const;

    bool CanRenderWindowed() const;

    const DisplayFormatInfo* GetFormatInfo(D3DFORMAT eFormat) const;

    NiDX9Renderer::FrameBufferFormat GetNearestFrameBufferFormat(
        bool bWindowed, unsigned int uiDesiredBPP) const;
    NiDX9Renderer::DepthStencilFormat GetNearestDepthStencilFormat(
        D3DFORMAT eAdapterMode, D3DFORMAT eFBFormat,
        unsigned int uiDesiredDepthBPP, 
        unsigned int uiDesiredStencilBPP) const;

    // *** begin NDL internal use only ***
    
    NiDX9DeviceDesc(LPDIRECT3D9 pkD3D9, unsigned int uiAdapter, 
        D3DDEVTYPE kD3DDevType, D3DFORMAT eCurrDisplayFormat, 
        NiTPointerList<unsigned int>& kFormats);
    ~NiDX9DeviceDesc();

    void Dump();

    // *** end NDL internal use only ***

protected:
    D3DDEVTYPE m_kD3DDevType;
    D3DCAPS9 m_kD3DCaps9;
    NiTPointerList<DisplayFormatInfo*> m_kScreenFormats;
    bool m_bRenderWindowed;
};

//  Adapter description
class NIDX9RENDERER_ENTRY NiDX9AdapterDesc
{
public:
    //  Mode decription
    class NIDX9RENDERER_ENTRY ModeDesc
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
    const D3DADAPTER_IDENTIFIER9& GetAdapterIdentifier() const;

    const NiDX9DeviceDesc* GetDevice(D3DDEVTYPE kDevType) const;
    const D3DCAPS9* GetDeviceCaps(D3DDEVTYPE kDevType) const;
    bool CanDeviceRenderWindowed(D3DDEVTYPE kDevType) const;

    ModeDesc* ValidateFullscreenMode(D3DFORMAT eFormat,
        unsigned uiWidth, unsigned uiHeight, 
        unsigned int& uiRefreshRate) const;

    unsigned int GetModeCount() const;
    const ModeDesc* GetMode(unsigned int uiMode) const;

    // *** begin NDL internal use only ***
    
    NiDX9AdapterDesc(LPDIRECT3D9 pkD3D9, unsigned int uiAdapter,
        NiTPointerList<unsigned int>& kFormats);
    ~NiDX9AdapterDesc();
    void Dump();

    // *** end NDL internal use only ***

protected:
    unsigned int m_uiAdapter;
    D3DADAPTER_IDENTIFIER9 m_kAdapterIdentifier;
    
    NiTArray<ModeDesc*> m_kModeList;

    NiDX9DeviceDesc* m_pkHALDeviceDesc;
    NiDX9DeviceDesc* m_pkREFDeviceDesc;
};
//---------------------------------------------------------------------------
class NIDX9RENDERER_ENTRY NiDX9SystemDesc
{
public:
    unsigned int GetAdapterCount() const;
    const NiDX9AdapterDesc* GetAdapter(unsigned int uiAdapter) const;

    static char* GetD3D9FormatString(D3DFORMAT eD3DFormat);
    static unsigned int GetBPPFromFormat(D3DFORMAT eD3DFormat);

    // *** begin NDL internal use only ***

    NiDX9SystemDesc(LPDIRECT3D9 pkD3D9, NiTPointerList<unsigned int>& kFormats);
    ~NiDX9SystemDesc();

    // *** end NDL internal use only ***

protected:
    void FillAdapterInformation(LPDIRECT3D9 pkD3D9,
        NiTPointerList<unsigned int>& kFormats);

    void Dump();

    unsigned int m_uiAdapterCount;
    NiTArray<NiDX9AdapterDesc*> m_kAdapterList;
};
//---------------------------------------------------------------------------

#include "NiDX9SystemDesc.inl"

#endif  //#ifndef NIDX9SYSTEMDESC_H
