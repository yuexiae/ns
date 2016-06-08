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

#ifndef NIMATERIALCOLORCONTROLLER_H
#define NIMATERIALCOLORCONTROLLER_H

#include <NiMaterialProperty.h>
#include <NiPoint3InterpController.h>

NiSmartPointer(NiMaterialColorController);

class NIANIMATION_ENTRY NiMaterialColorController : public NiPoint3InterpController
{
    NiDeclareRTTI;
    NiDeclareClone(NiMaterialColorController);
    NiDeclareStream;
    NiDeclareViewerStrings;
    NiDeclareFlags(unsigned short);

public:
    NiMaterialColorController();
    virtual ~NiMaterialColorController();
    
    virtual void Update(float fTime);
    
    enum Field { AMB, DIFF, SPEC, SELF_ILLUM };
    void SetType(Field eType);
    Field GetType() const; 

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
        MAX_POS = 8
    };
    // --- End NIF conversion code

    // flags
    enum
    {
        FIELD_MASK  = 0x0007,
        FIELD_POS   = 0
    };
};

#include "NiMaterialColorController.inl"

#endif  // #ifndef NIMATERIALCOLORCONTROLLER_H
