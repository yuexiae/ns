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

#ifndef NIBOOLTIMELINEINTERPOLATOR_H
#define NIBOOLTIMELINEINTERPOLATOR_H

#include "NiBoolInterpolator.h"

class NIANIMATION_ENTRY NiBoolTimelineInterpolator : public NiBoolInterpolator
{
    NiDeclareRTTI;
    NiDeclareClone(NiBoolTimelineInterpolator);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiBoolTimelineInterpolator(NiBoolData* pkBoolData = NULL);
    NiBoolTimelineInterpolator(bool bPoseValue);

    virtual bool Update(float fTime, NiObjectNET* pkInterpTarget, bool& bValue);

protected:

    unsigned int m_uiPreviousIdx;
    bool m_bPreviousValue;
};

NiSmartPointer(NiBoolTimelineInterpolator);

#endif  // #ifndef NIBOOLTIMELINEINTERPOLATOR_H
