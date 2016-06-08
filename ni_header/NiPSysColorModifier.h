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

#ifndef NIPSYSCOLORMODIFIER_H
#define NIPSYSCOLORMODIFIER_H

#include "NiPSysModifier.h"
#include <NiColorData.h>

class NIPARTICLE_ENTRY NiPSysColorModifier : public NiPSysModifier
{
    NiDeclareRTTI;
    NiDeclareClone(NiPSysColorModifier);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiPSysColorModifier(const char* pcName, NiColorData* pkColorData = NULL);

    virtual void Update(float fTime, NiPSysData* pkData);

    NiColorData* GetColorData() const;
    void SetColorData(NiColorData* pkColorData);

    // *** begin NDL internal use only ***
    void ResetKeyTimeExtrema(); // Called automatically by SetColorData.
    // *** end NDL internal use only ***

protected:
    // For cloning and streaming only.
    NiPSysColorModifier();

    NiColorDataPtr m_spColorData;

    float m_fLoKeyTime;
    float m_fHiKeyTime;
};

NiSmartPointer(NiPSysColorModifier);

#include "NiPSysColorModifier.inl"

#endif  // #ifndef NIPSYSCOLORMODIFIER_H
