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

#ifndef NID3DTIMESYNCCONTROLLER_H
#define NID3DTIMESYNCCONTROLLER_H

#include "NiD3DController.h"
#include <NiFloatExtraData.h>

class NID3D_ENTRY NiD3DTimeSyncController :
    public NiD3DController
{
    NiDeclareRTTI;
    NiDeclareClone(NiD3DTimeSyncController);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiD3DTimeSyncController();
    virtual ~NiD3DTimeSyncController();

    virtual void Update(float fTime);

    // *** begin NDL internal use only ***
    virtual void GuaranteeKeysAtStartAndEnd(float fStartTime, float fEndTime);
    
    // Overridden from NiTimeController so that m_spExtraData can be set
    // appropriately.
    virtual void SetTarget(NiObjectNET* pkTarget);

    virtual bool CanBeExtracted() const;
    virtual bool TargetIsRequiredType() const;
    // *** end NDL internal use only ***

    virtual bool IsStreamable() const;

protected:

    NiFloatExtraDataPtr m_spExtraData;

};

NiSmartPointer(NiD3DTimeSyncController);

#include "NiD3DTimeSyncController.inl"

#endif  // #ifndef NID3DTIMESYNCCONTROLLER_H
