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

#ifndef NIFRAMERATE_H
#define NIFRAMERATE_H

#include <NiColor.h>
#include <NiMaterialProperty.h>
#include <NiScreenGeometry.h>

class NiScreenSpaceCamera;
class NiRenderer;

//---------------------------------------------------------------------------
class NiFrameRate
{
public:
    NiFrameRate();
    ~NiFrameRate();
    
    void Init(bool bDisplayFrameRate, unsigned int iHistoSize = 0);
    void Shutdown();

    // set the normalized upper left location of the highest order digit
    void SetLocation(float fX, float fY);
    void GetLocation(float& fX, float& fY) const;

    // Set the horizontal spacing of the digits
    // Default spacing == 3 pixels
    void SetDigitSpacing(unsigned short usSpacing);
    unsigned short GetDigitSpacing() const;

    void SetColor(const NiColor& kColor);
    const NiColor& GetColor() const;

    void SetAlpha(float fAlpha);
    float GetAlpha() const;

    void TakeSample();
    void GetStats(float& fAvg, float& fStdDev, float& fMin, float& fMax,
        unsigned int* piHisto = 0);
    void AddToCamera(NiScreenSpaceCamera* pkSSCam);
    void RemoveFromCamera(NiScreenSpaceCamera* pkSSCam);
    void Update();

    unsigned int GetFrameRate() const;
 
protected:
    void SetupScreenGeometry();
    void DeleteScreenGeometry();

    enum 
    { 
        NUM_DIGITS = 3, 
        NUM_NUMS = 11, 
        WINDOW = 20, 
        DIGIT_HEIGHT = 16, 
        DIGIT_WIDTH = 8
    };

    static unsigned short ms_aausNumberBits[NUM_NUMS][DIGIT_HEIGHT];

    NiScreenGeometryPtr m_spScreenGeometry;

    bool m_bDisplayFrameRate;

    unsigned int m_uiFrameRate;
    unsigned int m_uiLastFrameRate;
    unsigned int m_uiNumSamples;
    float m_fSummedSamples;
    float m_fSumOfSquares;

    bool m_bFirstSample;
    float m_fStartTime;
    float m_fLastTime;

    float m_afRunningSamples[WINDOW];
    unsigned int m_uiCurInsertionPoint;

    float m_fMin;
    float m_fMax;

    unsigned int m_uiHistoSize;
    unsigned int* m_puiHisto;

    float m_fXLocation;
    float m_fYLocation;
    float m_fDigitHeight;

    const unsigned short m_usDigitSpacing;

    NiMaterialPropertyPtr m_spMatProp;

    NiScreenSpaceCamera* m_pkCamera;
};

#include "NiFrameRate.inl"

#endif
