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

#ifndef NIQUATERNIONINTERPOLATOR_H
#define NIQUATERNIONINTERPOLATOR_H

#include "NiKeyBasedInterpolator.h"
#include "NiRotData.h"

class NIANIMATION_ENTRY NiQuaternionInterpolator : public NiKeyBasedInterpolator
{
    NiDeclareRTTI;
    NiDeclareClone(NiQuaternionInterpolator);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiQuaternionInterpolator(NiRotData* pkQuaternionData = NULL);
    NiQuaternionInterpolator(NiQuaternion kPoseValue);

    // Virtual function overrides from base class.
    virtual bool Update(float fTime, NiObjectNET* pkInterpTarget, NiQuaternion& kValue);
    virtual bool IsQuaternionValueSupported() const;

    NiRotData* GetQuaternionData() const;
    void SetQuaternionData(NiRotData* pkQuaternionData);
    void SetPoseValue(NiQuaternion kPoseValue);

    NiRotKey* GetKeys(unsigned int& uiNumKeys, NiRotKey::KeyType& eType,
        unsigned char& ucSize) const;
    void ReplaceKeys(NiRotKey* pkKeys, unsigned int uiNumKeys,
        NiRotKey::KeyType eType);
    void SetKeys(NiRotKey* pkKeys, unsigned int uiNumKeys,
        NiRotKey::KeyType eType);


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
    virtual void GetActiveTimeRange(float& fBeginKeyTime, float& fEndKeyTime)
        const;
    virtual void GuaranteeTimeRange(float fStartTime, 
        float fEndTime);
    virtual NiInterpolator* GetSequenceInterpolator(float fStartTime,
        float fEndTime);
    // *** end NDL internal use only ***

protected:
    // Virtual function overrides from base class.
    
    NiQuaternion m_kQuaternionValue;

    NiRotDataPtr m_spQuaternionData;
    unsigned int m_uiLastIdx;
};

NiSmartPointer(NiQuaternionInterpolator);

#include "NiQuaternionInterpolator.inl"

#endif  // #ifndef NIQUATERNIONINTERPOLATOR_H
