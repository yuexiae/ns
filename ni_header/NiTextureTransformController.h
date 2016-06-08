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

#ifndef NITEXTURETRANSFORMCONTROLLER_H
#define NITEXTURETRANSFORMCONTROLLER_H

#include <NiTexturingProperty.h>
#include <NiFloatInterpController.h>

NiSmartPointer(NiTextureTransformController);

class NIANIMATION_ENTRY NiTextureTransformController : public NiFloatInterpController
{
    NiDeclareRTTI;
    NiDeclareClone(NiTextureTransformController);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:

    enum TransformMember {
        TT_TRANSLATE_U = 0,
        TT_TRANSLATE_V,
        TT_ROTATE,
        TT_SCALE_U,
        TT_SCALE_V
    };

    NiTextureTransformController( NiTexturingProperty* pkTarget = 0,
        NiTexturingProperty::Map* pkMap = 0, 
        TransformMember eMember = TT_TRANSLATE_U);

    virtual ~NiTextureTransformController();
    
    virtual void Update(float fTime);
    
    NiTexturingProperty::Map* GetMap();
    bool SetMap(NiTexturingProperty::Map* pkMap,
        NiTexturingProperty* pkTarget = 0);


    TransformMember GetAffectedMember();
    void SetAffectedMember(TransformMember eMember);

    // Override default
    virtual void SetTarget(NiObjectNET* pkTarget);

    // *** begin NDL internal use only ***
    virtual const char* GetCtlrID();
    // *** begin NDL internal use only ***

protected:

    unsigned int m_uiLastIdx;
    
    NiTexturingProperty::Map* m_pkMap;
    bool m_bShaderMap;
    unsigned int m_uiMapIndex;
    TransformMember m_eMember;
    char* m_pcCtlrID;
    
    // Set and internal map pointer for performance
    bool SetInternalMap();

    // Virtual function overrides from base classes.
    virtual bool InterpTargetIsCorrectType(NiObjectNET* pkTarget) const;
    virtual void GetTargetFloatValue(float& fValue);

    void ResetCtlrID();
};

#include "NiTextureTransformController.inl"

#endif  // #ifndef NITEXTURETRANSFORMCONTROLLER_H
