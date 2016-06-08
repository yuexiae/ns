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

#ifndef NICOLORINTERPOLATOR_H
#define NICOLORINTERPOLATOR_H

#include "NiKeyBasedInterpolator.h"
#include "NiColorData.h"

class NIANIMATION_ENTRY NiColorInterpolator : public NiKeyBasedInterpolator
{
    NiDeclareRTTI;
    NiDeclareClone(NiColorInterpolator);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiColorInterpolator(NiColorData* pkColorData = NULL);
    NiColorInterpolator(NiColorA kPoseValue);

    // Virtual function overrides from base class.
    virtual bool Update(float fTime, NiObjectNET* pkInterpTarget, NiColorA& kValue);
    virtual bool IsColorAValueSupported() const;

    NiColorData* GetColorData() const;
    void SetColorData(NiColorData* pkColorData);
    void SetPoseValue(NiColorA kPoseValue);

    NiColorKey* GetKeys(unsigned int& uiNumKeys, NiColorKey::KeyType& eType,
        unsigned char& ucSize) const;
    void ReplaceKeys(NiColorKey* pkKeys, unsigned int uiNumKeys,
        NiColorKey::KeyType eType);
    void SetKeys(NiColorKey* pkKeys, unsigned int uiNumKeys,
        NiColorKey::KeyType eType);

    // Implemented from 
    virtual unsigned short GetKeyChannelCount() const ;
    virtual unsigned int GetKeyCount(unsigned short usChannel ) const ;
    virtual NiAnimationKey::KeyType GetKeyType(unsigned short 
        usChannel ) const ;
    virtual NiAnimationKey::KeyContent GetKeyContent(unsigned short
        usChannel ) const ;
    virtual NiAnimationKey* GetKeyArray(unsigned short usChannel ) const ;
    virtual unsigned char GetKeyStride(unsigned short usChannel ) const ;

    virtual bool GetChannelPosed(unsigned short usChannel) const;
    virtual void Collapse();

    // *** begin NDL internal use only ***
    virtual void GuaranteeTimeRange(float fStartTime, 
        float fEndTime);
    virtual NiInterpolator* GetSequenceInterpolator(float fStartTime,
        float fEndTime);
    // *** end NDL internal use only ***

protected:
    // Virtual function overrides from base class.
    
    NiColorA m_kColorValue;

    NiColorDataPtr m_spColorData;
    unsigned int m_uiLastIdx;
};

NiSmartPointer(NiColorInterpolator);

#include "NiColorInterpolator.inl"

#endif  // #ifndef NICOLORINTERPOLATOR_H
