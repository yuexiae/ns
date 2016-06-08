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

#ifndef NICURSOR_H
#define NICURSOR_H

#include "NiCursorLibType.h"

#include <NiAlphaProperty.h>
#include <NiRefObject.h>
#include <NiRenderer.h>
#include <NiScreenGeometry.h>
#include <NiScreenSpaceCamera.h>
#include <NiTexture.h>
#include <NiTexturingProperty.h>

class NICURSOR_ENTRY NiCursor : public NiRefObject
{
    NiDeclareRootRTTI(NiCursor);
    NiDeclareViewerStrings;

public:
    enum
    {
        MAGIC_NUMBER    = 0x0046434E,
    };

    enum Flags
    {
        WINDOWED        = 0x00000001,
        ANIMATED        = 0x00000002,
        IMMEDIATE       = 0x00000004,
        BASE_FLAG_MASK  = 0x0000000f
    };

protected:
    //  Constructors
    NiCursor(NiRenderer* pkRenderer);

public:
    //  Destructor
    virtual ~NiCursor();

    // Static creation call - to allow for failing...
    // The first one is for creating cursors on the fly
    static NiCursor* Create(NiRenderer* pkRenderer, 
        NiRect<int>& kRect, unsigned int uiFlags, 
        unsigned int uiHotSpotX, unsigned int uiHotSpotY, 
        const char* pacImageFile);
    // This one is for loading cursors from files
    static NiCursor* Create(NiRenderer* pkRenderer, 
        NiRect<int>& kRect, const char* pacCursorFile);

    // Run-time functions
    virtual int Show(bool bShow);
    virtual bool SetPosition(float fTime, int iScreenSpaceX, 
        int iScreenSpaceY);
    virtual bool Move(float fTime, int iDeltaX, int iDeltaY);
    virtual void Draw(NiCamera* pkCamera);

    // Accessors
    const int GetShow() const;
    void GetHotSpot(unsigned int& uiX, unsigned int& uiY);

    void GetScreenSpacePosition(int& iX, int& iY);

    void SetRect(NiRect<int>& kRect);

    //*** begin NDL internal use only
    void SetHotSpot(unsigned int uiX, unsigned int uiY);
    virtual void SetFlags(unsigned int uiFlags);

    virtual bool SetImage(const char* pacImageFile);

    virtual bool UpdateScreenGeometry();
    //*** end NDL internal use only

protected:
    NiRendererPtr m_spRenderer;
    NiScreenSpaceCameraPtr m_spScreenSpaceCamera;

    unsigned int m_uiFlags;
    unsigned int m_uiHotSpotX;
    unsigned int m_uiHotSpotY;

    unsigned int m_uiDrawWidth;
    unsigned int m_uiDrawHeight;
    NiAlphaPropertyPtr m_spAlphaProp;
    NiTexturePtr m_spImage;
    NiTexturingPropertyPtr m_spTextureProp;
    NiScreenGeometryPtr m_spScreenGeom;
    
    unsigned int m_uiDrawFlags;
    int m_iScreenSpaceX;
    int m_iScreenSpaceY;

    int m_iShowCount;
    bool m_bSystemCursorShowing;

    NiRect<int> m_kRect;
};

typedef NiPointer<NiCursor> NiCursorPtr;

#include "NiCursor.inl"

#endif //#ifndef NICURSOR_H
