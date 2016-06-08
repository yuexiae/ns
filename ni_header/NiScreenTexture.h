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

#ifndef NISCREENTEXTURE_H
#define NISCREENTEXTURE_H

#include "NiColor.h"
#include "NiObject.h"
#include "NiTSet.h"
#include "NiTexturingProperty.h"

NiSmartPointer(NiTexture);

class NiRenderer;

#if defined(WIN32) || defined(_XBOX)
class NiGeometryBufferData;
#endif // defined(WIN32) || defined(_XBOX)

class NIMAIN_ENTRY NiScreenTexture : public NiObject
{
    NiDeclareRTTI;
    NiDeclareClone(NiScreenTexture);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:

    class NIMAIN_ENTRY ScreenRect
    {
    public:
        short m_sPixTop;
        short m_sPixLeft;
        unsigned short m_usPixWidth;
        unsigned short m_usPixHeight;

        unsigned short m_usTexTop;
        unsigned short m_usTexLeft;

        NiColorA m_kColor;
    };

    // construction and destruction
    NiScreenTexture(NiTexture* pkTexture);
    virtual ~NiScreenTexture();

    // Screen Rect handling
    unsigned int AddNewScreenRect(short sPixTop, short sPixLeft, 
        unsigned short usPixWidth, unsigned short usPixHeight, 
        unsigned short usTexTop, unsigned short usTexLeft, 
        NiColorA kColor = NiColorA::WHITE);

    const ScreenRect& GetScreenRect(unsigned int uiIndex) const;
    ScreenRect& GetScreenRect(unsigned int uiIndex);
    void RemoveScreenRect(unsigned int uiIndex);

    unsigned int GetNumScreenRects() const;
    void RemoveAllScreenRects();

    NiTexture* GetTexture() const;
    void SetTexture(NiTexture* pkTexture);

    NiTexturingProperty::ClampMode GetClampMode() const;
    void SetClampMode(NiTexturingProperty::ClampMode eClampMode);

    NiTexturingProperty::ApplyMode GetApplyMode() const;
    void SetApplyMode(NiTexturingProperty::ApplyMode eApplyMode);

    // MarkAsChanged should be called if vertices, texture coordinates,
    // heights, widths, or colors are changed, or if rectangles are added or
    // deleted. Values from the following enum should be OR'd together and
    // passed to MarkAsChanged to indicate what values have changed. 
    
    // (If heights or widths are changed, VERTEX_MASK | TEXTURE_MASK
    // should be passed.)

    enum
    {
        VERTEX_MASK = 1,
        TEXTURE_MASK = 2,
        COLOR_MASK = 4,
        RECTANGLE_COUNT_MASK = 8,

        EVERYTHING_MASK = 
            (VERTEX_MASK | TEXTURE_MASK | COLOR_MASK | RECTANGLE_COUNT_MASK)
    };
    void MarkAsChanged(unsigned short usFlags);

    // *** begin NDL internal use only ***

    // revision ID access
    unsigned short GetRevisionID() const;
    void ClearRevisionID();

    NiTexturingProperty* GetTexturingProperty() const;

    void Draw(NiRenderer* pkRenderer);

#if defined(WIN32) || defined(_XBOX)
    NiGeometryBufferData* GetRendererData() const;
    void SetRendererData(NiGeometryBufferData* pkRendererData);
#elif defined(PS2)
    struct PS2Data;
    PS2Data& GetRendererData(unsigned int i);
    unsigned char& GetRendererIndex();
#endif

    // *** end NDL internal use only ***

protected:
    NiScreenTexture();

    NiTSet<ScreenRect> m_kScreenRects;
    NiTexturingPropertyPtr m_spTexProp;
    unsigned short m_usDirtyFlags;

#if defined(WIN32) || defined(_XBOX)
    NiGeometryBufferData* m_pkBuffData;
#elif defined(PS2)
    struct PS2Data
    {
        PS2Data();
        u_long128* m_puqData;
        unsigned int m_uiRects;
        unsigned int m_uiStamp;
    };

    unsigned char m_ucIndex;
    PS2Data m_akRendererData[2];
#endif
};

NiSmartPointer(NiScreenTexture);
typedef NiTArray<NiScreenTexturePtr> NiScreenTextureArray;

#include "NiScreenTexture.inl"

#endif // NISCREENTEXTURE_H

