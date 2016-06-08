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

#ifndef NIFLIPCONTROLLER_H
#define NIFLIPCONTROLLER_H

#include <NiTexturingProperty.h>
#include <NiFloatInterpController.h>
#include "NiAnimationLibType.h"

NiSmartPointer(NiFlipController);

class NIANIMATION_ENTRY NiFlipController : public NiFloatInterpController
{
    NiDeclareRTTI;
    NiDeclareClone(NiFlipController);
    NiDeclareStream;
 
public:
    NiFlipController();
    ~NiFlipController();

    virtual void Update(float fTime);
    
    bool SetAffectedMap(NiTexturingProperty::Map* pkMap);
    NiTexturingProperty::Map* GetAffectedMap(void) const;

    void AttachTexture(NiTexture* pkTexture, unsigned int uiIndex);
    NiTexturePtr DetachTexture(unsigned int uiIndex);

    unsigned int GetIndex() const;
    unsigned int GetTextureArraySize() const;

    NiTexture* GetTextureAt(unsigned int uiIndex);
    NiTexture* GetTexture() const;

    // *** begin NDL internal use only ***
    virtual const char* GetCtlrID();
    
    virtual NiBlendInterpolator* CreateBlendInterpolator(
        unsigned short usIndex = 0, bool bManagerControlled = false, 
        bool bAccumulateAnimations = false, float fWeightThreshold = 0.0f,
        unsigned char ucArraySize = 2) 
        const;

    // *** begin NDL internal use only ***

protected:
    // Virtual function overrides from base classes.
    virtual bool InterpTargetIsCorrectType(NiObjectNET* pkTarget) const;
    virtual void GetTargetFloatValue(float& fValue);
    
    NiTArray<NiTexturePtr> m_kTextures;
    unsigned int m_uiIndex;
    unsigned int m_uiAffectedMap;
    char* m_pcCtlrID;

    void ResetCtlrID();
};

#include "NiFlipController.inl"

#endif

