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

#ifndef NIPOINT3INTERPOLATOR_H
#define NIPOINT3INTERPOLATOR_H

#include "NiKeyBasedInterpolator.h"
#include "NiPosData.h"

class NIANIMATION_ENTRY NiPoint3Interpolator : public NiKeyBasedInterpolator
{
    NiDeclareRTTI;
    NiDeclareClone(NiPoint3Interpolator);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiPoint3Interpolator(NiPosData* pkPoint3Data = NULL);
    NiPoint3Interpolator(NiPoint3 kPoseValue);

    // Virtual function overrides from base class.
    virtual bool Update(float fTime, NiObjectNET* pkInterpTarget, NiPoint3& kValue);
    virtual bool IsPoint3ValueSupported() const;

    NiPosData* GetPoint3Data() const;
    void SetPoint3Data(NiPosData* pkPoint3Data);
    void SetPoseValue(NiPoint3 kPoseValue);

    NiPosKey* GetKeys(unsigned int& uiNumKeys, NiPosKey::KeyType& eType,
        unsigned char& ucSize) const;
    void ReplaceKeys(NiPosKey* pkKeys, unsigned int uiNumKeys,
        NiPosKey::KeyType eType);
    void SetKeys(NiPosKey* pkKeys, unsigned int uiNumKeys,
        NiPosKey::KeyType eType);

    // Implemented from NiKeyBasedInterpolator
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
    
    NiPoint3 m_kPoint3Value;

    NiPosDataPtr m_spPoint3Data;
    unsigned int m_uiLastIdx;
};

NiSmartPointer(NiPoint3Interpolator);

#include "NiPoint3Interpolator.inl"

#endif  // #ifndef NIPOINT3INTERPOLATOR_H
