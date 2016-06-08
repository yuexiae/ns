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

#ifndef NIFLOATINTERPOLATOR_H
#define NIFLOATINTERPOLATOR_H

#include "NiKeyBasedInterpolator.h"
#include "NiFloatData.h"

class NIANIMATION_ENTRY NiFloatInterpolator : public NiKeyBasedInterpolator
{
    NiDeclareRTTI;
    NiDeclareClone(NiFloatInterpolator);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiFloatInterpolator(NiFloatData* pkFloatData = NULL);
    NiFloatInterpolator(float fPoseValue);

    // Virtual function overrides from base class.
    virtual bool Update(float fTime, NiObjectNET* pkInterpTarget, float& fValue);
    virtual bool IsFloatValueSupported() const;

    NiFloatData* GetFloatData() const;
    void SetFloatData(NiFloatData* pkFloatData);
    void SetPoseValue(float fValue);

    NiFloatKey* GetKeys(unsigned int& uiNumKeys, NiFloatKey::KeyType& eType,
        unsigned char& ucSize) const;
    
    // For swapping animation sequences at runtime. The object 
    //   assumes ownership of the data array being passed in, and has the 
    //   responsibility for deleting it when finished with it.
    void ReplaceKeys(NiFloatKey* pkKeys, unsigned int uiNumKeys,
        NiFloatKey::KeyType eType);

    // For swapping rotation animation sequences at runtime.  The method
    // neither deletes the old data nor makes internal copies of the new
    // data. The application is responsible for the deletion.
    void SetKeys (NiFloatKey* pkKeys, unsigned int uiNumKeys,
        NiFloatKey::KeyType eType);

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
    
    float m_fFloatValue;

    NiFloatDataPtr m_spFloatData;
    unsigned int m_uiLastIdx;
};

NiSmartPointer(NiFloatInterpolator);

#include "NiFloatInterpolator.inl"

#endif  // #ifndef NIFLOATINTERPOLATOR_H
