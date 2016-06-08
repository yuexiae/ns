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

#ifndef NIDX8SELECT_H
#define NIDX8SELECT_H

#include "NiApplication.h"
#if defined(_DX8)

#include <NiOS.h>
#include <NiRenderer.h>
#include <NiUniversalTypes.h>

class NiDX8AdapterDesc;
class NiDX8DeviceDesc;
class NiDX8SystemDesc;

//---------------------------------------------------------------------------
class NiDX8Select 
{
public:
    static NiRendererPtr CreateRenderer(NiWindowRef pTopLevelWnd, 
        NiWindowRef pRenderWnd, bool bDialog, unsigned int uiBitDepth, 
        unsigned int uiWidth, unsigned int uiHeight, bool bStencil, 
        bool bMultiThread, bool bRefRast, bool bSWVertex, bool& bFullscreen);

protected:
    typedef enum {
        RETURN_OK,
        RETURN_FAIL,
        RETURN_CANCEL
    } ReturnVal;

    enum { IDC_STATIC = 0xffff };
    enum { IDC_ADAPTER_COMBO = 1000 };
    enum { IDC_MODE_COMBO = 1001 };
    enum { IDC_RESOLUTION_COMBO = 1002 };
    enum { IDC_ZBUFFER_CHECK = 1003 };
    enum { IDC_MULTISAMPLE_COMBO = 1004 };

    static NiRenderer* DialogCreateRenderer(NiWindowRef pTopLevelWnd, 
        NiWindowRef pRenderWnd, bool bStencil, bool bMultiThread, 
        bool bRefRast, bool bSWVertex, bool& bFullscreen);

    static ReturnVal Select(NiWindowRef pWnd, bool& bFullscreen,
        bool& b32BitZBuffer, const void* &pkAdapter, const void* &pkDevice, 
        const void*& pkMode, unsigned int& uiFBMode);
    static void EnumerateAdapters(NiWindowRef pDialog);
    static void EnumerateResolutions(NiWindowRef pDialog);
    static void EnumerateMultisamples(NiWindowRef pDialog);
    static bool UpdateAdapter(NiWindowRef pDialog);
    static bool UpdateResolution(NiWindowRef pDialog);
    static bool UpdateMultisample(NiWindowRef pDialog);
    static BOOL CALLBACK Callback(NiWindowRef pDialog, unsigned int uiMsg,
        WPARAM wParam, LPARAM lParam);
    static void CopyToWideChar(unsigned short** ppusStrOut, 
        const char* pcStrIn);
    static void AddDialogControl(unsigned short** ppusTemplate, 
        unsigned int uiStyle, short sSX, short sSY, short sCX, short sCY, 
        unsigned short usID, const char* pcStrClassName, 
        const char* pcStrTitle);
    static DLGTEMPLATE* BuildAdapterSelectTemplate();

    static const NiDX8DeviceDesc* ms_pkDevice;
    static const void* ms_pkMode;
    static const NiDX8AdapterDesc* ms_pkAdapter;
    static const NiDX8SystemDesc* ms_pkInfo;
    static bool ms_bFullscreen;
    static bool ms_b32BitZBuffer;
    static unsigned int ms_uiMultisample;
    static bool ms_bDialogOpen;
};

#endif //#if defined(_DX8)

#endif
