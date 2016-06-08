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

#ifndef NISTRING2D_H
#define NISTRING2D_H

#include "NiFontString.h"

#include <NiRect.h>
#include <NiScreenTexture.h>

class NIFONT_ENTRY NiString2D : public NiFontString
{
public:
    NiString2D(NiFont* pkFont, unsigned int uiFlags,
        unsigned int uiMaxStringLen, const char* pcString,
        const NiColorA& kColor, unsigned int uiX, unsigned int uiY);
    virtual ~NiString2D();

    //
    void sprintf(const char* pcFormatString, ...);

    //
    void SetPosition(unsigned int uiX, unsigned int uiY);
    
    //
    unsigned int GetLimitWidth();
    unsigned int SetLimitWidth(unsigned int uiWidth);

    // Rendering Functions
    void Draw(NiRenderer* pkRenderer);

    // Get Size, etc.
    void GetTextExtent(float& fWidth, float& fHeight);

    //*** begin NDL internal use only
    void CreateScreenTexture();
    void UpdateScreenTexture();
    //*** end NDL internal use only

protected:
    unsigned int m_uiX;     // Position in screen coordinates
    unsigned int m_uiY;
    NiRect<float> m_rfPos;

    unsigned int m_uiLimitWidth;
    unsigned int m_uiLimitStringLen;
    float m_fLimitStringLen;

    NiScreenTexturePtr m_spScreenTexture;
};

typedef NiPointer<NiString2D> NiString2DPtr;

#include "NiString2D.inl"

#endif // NISTRING2D_H
