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

#ifndef NILIGHTCOLORCONTROLLER_H
#define NILIGHTCOLORCONTROLLER_H

#include <NiLight.h>
#include <NiPoint3InterpController.h>
#include "NiPosData.h"

NiSmartPointer(NiLightColorController);

class NIANIMATION_ENTRY NiLightColorController : public NiPoint3InterpController
{
    NiDeclareRTTI;
    NiDeclareClone(NiLightColorController);
    NiDeclareStream;
    NiDeclareViewerStrings;
    NiDeclareFlags(unsigned short);

public:
    NiLightColorController ();
    virtual ~NiLightColorController();

    virtual void Update(float fTime);
    
    // animation data access
    void SetAmbient(bool bIsAmbient);
    bool GetAmbient() const;

    // *** begin NDL internal use only ***
    virtual const char* GetCtlrID();
    // *** begin NDL internal use only ***

protected:
    // Virtual function overrides from base classes.
    virtual bool InterpTargetIsCorrectType(NiObjectNET* pkTarget) const;
    virtual void GetTargetPoint3Value(NiPoint3& kValue);

    // --- Begin NIF conversion code
    // Deprecated flags - use new flag code
    enum
    {
        MAX_POS = 6
    };
    // --- End NIF conversion code

    // flags
    enum
    {
        ISAMBIENT_MASK  = 0x0001
    };
};

#include "NiLightColorController.inl"

#endif

