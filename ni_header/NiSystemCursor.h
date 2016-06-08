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

#ifndef NISYSTEMCURSOR_H
#define NISYSTEMCURSOR_H

#include "NiCursor.h"

NiSmartPointer(NiSystemCursor);

class NICURSOR_ENTRY NiSystemCursor : public NiCursor
{
    NiDeclareRTTI;
    NiDeclareViewerStrings;

public:
    enum SystemCursor
    {
        BULLSEYE        = 0,
        CLOSEHAND,
        CROSS,
        CROSSHAIR,
        DIAG_RESIZE,
        HAND,
        HORZ_RESIZE,
        HOURGLASS,
        IBEAM,
        MAGNIFY,
        MOVE,
        PEN,
        QUESTION,
        STANDARD,
        STOP,
        UNAVAILABLE,
        VERT_RESIZE,
        WAIT,
        // When adding new system cursors, make sure to match the oreder
        // in the SystemCursor texture.
        SYSTEM_COUNT,
        ARROW           = STANDARD
    };

protected:
    //  Constructors
    NiSystemCursor(NiRenderer* pkRenderer);

public:
    //  Destructor
    virtual ~NiSystemCursor();

    // Static creation call - to allow for failing...
    // The first one is for creating cursors on the fly
    static NiCursor* Create(NiRenderer* pkRenderer, NiRect<int>& kRect, 
        unsigned int uiFlags, SystemCursor eType);
    static void Shutdown();
    // 
    static NiSystemCursor* GetCursor(SystemCursor eType);

    // Accessors
    const SystemCursor GetType() const;
    SystemCursor SetType(SystemCursor eType);


    //*** begin NDL internal use only
    virtual bool ResetScreenGeometry();
    //*** end NDL internal use only

protected:
    class SystemCursorInfo
    {
    public:
        SystemCursor m_eType;
        unsigned int m_uiHotSpotX;
        unsigned int m_uiHotSpotY;
        unsigned int m_uiTextureOffsetLeft;
        unsigned int m_uiTextureOffsetTop;
    };

    SystemCursor m_eType;
    unsigned int m_uiCurrentOffsetLeft;
    unsigned int m_uiCurrentOffsetTop;
    
    static SystemCursorInfo ms_akInfo[SYSTEM_COUNT];
    static NiSystemCursorPtr ms_spSystemCursor;
};

#include "NiSystemCursor.inl"

#endif //#ifndef NISYSTEMCURSOR_H
