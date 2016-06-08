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

#ifndef NIAPPLICATION_H
#define NIAPPLICATION_H

// Gamebryo main engine
#include "NiMain.h"

// Many NiApplication subclasses use NiOutputDebugString and other
// system-related calls
#include <NiSystem.h>

// command line parsing
#include "NiCommand.h"

// application-level classes
#include "NiAppWindow.h"

// input devices
#include "NiInputSystem.h"
#include "NiTurret.h"

// frame rate display in the hardware-accelerated window
#include "NiFrameRate.h"

#include <NiUniversalTypes.h>

#if defined(PS2)
#include <NiPS2Renderer.h>
#endif

#if defined(WIN32) && !(defined(_XBOX) || defined(_XENON))
#include <NiDirectXVersion.h>
#endif //#if defined(WIN32) && !(defined(_XBOX) || defined(_XENON))

class NiApplication
{
//----- base application layer ----------------------------------------------
public:
    // the unique application instance
    static NiApplication* ms_pkApplication;

    // Create must be implemented in the NiApplication-derived class.
    static NiApplication* Create();

    NiApplication
    (
        const char* pcWindowCaption,       // caption of window
        unsigned int uiWidth,              // client window width
        unsigned int uiHeight,             // client window height
        unsigned int uiMenuID = 0,         // menu resource ID
        unsigned int uiNumStatusPanes = 0, // number of panes in status window
        unsigned int uiBitDepth = 0        // kColor depth of screen
    );
    virtual ~NiApplication();

    // command line parsing
    static void SetCommandLine(char* pcCommandLine);
    static void SetCommandLine(int iArgc, char** ppcArgv);
    static NiCommand* GetCommand();
    static void CommandSelectRenderer();

    // Media Path
    static void SetMediaPath(const char* pcPath);
    static const char* GetMediaPath();

#ifdef PS2
    // IRX Module Path
    static void SetModulePath(const char* pcPath);
    static const char* GetModulePath();
    
    // argv[0]
    static void SetArgV0(const char* pcPath);
    static const char* GetArgV0();

    // SCECdDVD or SCECdCD. SCECdCD is default.
    static void SetMedia(int iMedia);
    static int GetMedia();
#endif    

#if defined(_XBOX) && !defined(_XENON)
    void WaitForGPU();
    
    //  PROFILING
    static void EnablePerfMonitor(unsigned int uiFPSInterval, 
        bool bGPUPerf = true);
    static void DisablePerfMonitor(void);
    static void EnableNULLHardware(void);
#endif  //#if defined(_XBOX) && !defined(_XENON)

    // Each call to this function will return the _same_ storage -
    // each call overwrites the previously returned string, so applications
    // must take care to copy the return immediately
    static const char* ConvertMediaFilename(const char* pcFilename);

    // Window methods
    NiWindowRef CreateMainWindow(int iWinMode, 
        NiWindowRef hWnd = NULL) const;

    // selection of renderer and attributes
    void SetFullscreen(bool bOn);
    bool GetFullscreen() const;
    void SetStencil(bool bOn);
    bool GetStencil() const;
    void SetRendererDialog(bool bOn);
    bool GetRendererDialog() const;

    // Frame rate
    virtual void EnableFrameRate(bool bEnable);
    float GetMaxFrameRate();
    void SetMaxFrameRate(float fMax);

    // This is called by WinMain after ShowWindow and UpdateWindow, but before
    // the idle loop.  The window handle is valid at this point, so any
    // NiApplication-derived class may safely use ms_hWnd in this routine.
    // The routine should be used for allocating resources and initializing
    // any data values.
    virtual bool Initialize();

    // Terminate is called after the idle loop exits. The application
    // should free up its resources in this routine.
    virtual void Terminate();

    virtual void CreateMenuBar();

    NiWindowRef GetWindowReference() const;
    NiWindowRef GetRenderWindowReference() const;
    static void SetInstanceReference(NiInstanceRef pInstance);
    static NiInstanceRef GetInstanceReference();
    static void SetAcceleratorReference(NiAcceleratorRef pAccel);
    static NiAcceleratorRef GetAcceleratorReference();

    NiAppWindow* GetAppWindow() const;
    unsigned int GetMenuID() const;    

    // Control cursor visibility
    void HidePointer();
    void ShowPointer();

    void MainLoop();
    void QuitApplication(void);

    // Events
    // Not all events apply to all platforms; the corresponding event handlers
    // will be simply not be called on those platforms.  Look in the event 
    // handler appropriate to your system to see how the respective events are 
    // processed before the virtual handlers are called.
    
    NiInputSystem* GetInputSystem();

    // timing
    float GetCurrentTime();
    float GetLastTime();
    float GetDeltaTime();
    float GetAccumTime();

    // updating the input sytem
    virtual void UpdateInput();

    // process the collected input. You would override this function to 
    // implement poll the devices states or check for action maps.
    virtual void ProcessInput();
    
    // idle processing
    virtual void OnIdle(void); // glut requires its display function to have
                               // an explicit "void"; parameter must match

#if defined(WIN32) && !defined(_XBOX)
    static LRESULT CALLBACK WinProc(HWND hWnd, UINT uiMsg, WPARAM wParam,
        LPARAM lParam);
    
    // windows messages
    virtual bool OnWindowResize(int iWidth, int iHeight, 
        unsigned int uiSizeType, NiWindowRef pWnd);
    virtual bool OnWindowDestroy(NiWindowRef pWnd, bool bOption);
    virtual bool OnDefault(NiEventRef pEventRecord);
#endif

protected:
    virtual bool CreateScene();
    virtual bool CreateCamera();
    virtual bool CreateScreenSpaceCamera();
    virtual bool CreateRenderer();
    virtual bool CreateInputSystem();
    virtual NiInputSystem::CreateParams* GetInputSystemCreateParams();
    virtual void ConfigureInputDevices();
    virtual bool MeasureTime();
    virtual void DrawFrameRate();

    // basic objects
    NiNodePtr m_spScene;
    NiCameraPtr m_spCamera;
    NiScreenSpaceCameraPtr m_spScreenSpaceCamera;
    NiRendererPtr m_spRenderer;
    NiInputSystemPtr m_spInputSystem;

    // Application-related classes
    NiAppWindow* m_pkAppWindow;
    static NiInstanceRef ms_pInstance;
    static NiAcceleratorRef ms_pAccel;
    unsigned int m_uiMenuID;

    // renderer creation and properties
    bool m_bFullscreen;
    bool m_bStencil;
    bool m_bRendererDialog;
    bool m_bMultiThread;
    unsigned int m_uiBitDepth;
    NiFrameRate* m_pkFrameRate;
    bool m_bFrameRateEnabled;

    // frame rate counting and display
    int m_iMaxTimer;
    int m_iTimer;
    float m_fCurrentTime;
    float m_fLastTime;
    float m_fDeltaTime;
    float m_fAccumTime;
    int m_iClicks;
    float m_fFrameRate;
    float m_fLastFrameRateTime;
    int m_iLastFrameRateClicks;

    // Frame rate limitation
    float m_fMinFramePeriod;
    float m_fLastFrame;

    // command line
    static NiCommand* ms_pkCommand;

    // media path
    static char ms_acMediaPath[256];
    static char ms_acTempMediaFilename[256];

#ifdef PS2
    void ToggleVRAMBrowseMode();
    void ScrollVRAM(int iDelta);
    bool m_bBrowsingVRAM;

    bool m_bField;              // default: true
    bool m_bBlend;              // default: true
    unsigned int m_uiVideoMode; // default: SCE_GS_NTSC
    int m_iClut8Pages;          // default: 1
    int m_iClut4Pages;          // default: 0
    unsigned int m_uiFBPSM;     // default: SCE_GS_PSMCT32
    unsigned int m_uiZBPSM;     // default: SCE_GS_PSMZ24

    // Members of m_kFront are not initialized by NiApplication. If a derived
    // class sets m_bAlternateFrontBuffer to true, that class is responsible
    // for filling in m_kFront.
    bool m_bAlternateFrontBuffer; // default: false;
    NiPS2Renderer::FrontBufferParams m_kFront;

    static char ms_acModulePath[256];
    static const char* ms_pcArgV0;
    static int ms_iMedia;
#endif    

#if defined(_XBOX) || defined(_XENON)
    //  App-specific setup flags
    unsigned int m_uiSetupFlags;
#endif

#if defined(WIN32) && !(defined(_XBOX) || defined(_XENON))
    virtual bool Process();

	// Runtime-setting flags
    bool m_bRefRast;
    bool m_bSWVertex;
    bool m_bNVPerfHUD;
    bool m_bExclusiveMouse;
#else   //#if defined(WIN32) && !(defined(XBOX) || defined(_XENON))
    bool m_bQuitApp;
#endif  //#if defined(WIN32) && !(defined(XBOX) || defined(_XENON))
};

#include "NiApplication.inl"

#endif // NIAPPLICATION_H