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

#ifndef NIFLOATDATA_H
#define NIFLOATDATA_H

#include "NiAnimationLibType.h"
#include "NiObject.h"
#include "NiFloatKey.h"
#include "NiStream.h"

NiSmartPointer(NiFloatData);

class NIANIMATION_ENTRY NiFloatData : public NiObject
{
    NiDeclareRTTI;
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    // construction and destruction
    NiFloatData ();
    virtual ~NiFloatData ();

    // member access
    unsigned int GetNumKeys () const;
    NiFloatKey* GetAnim (unsigned int& uiNumKeys,
        NiFloatKey::KeyType& eType, unsigned char& ucSize) const;

    // For swapping animation sequences at runtime. The object 
    //   assumes ownership of the data array being passed in, and has the 
    //   responsibility for deleting it when finished with it.
    void ReplaceAnim (NiFloatKey* pkFloatKeys, unsigned int uiNumKeys,
        NiFloatKey::KeyType eType);

    // For swapping rotation animation sequences at runtime.  The method
    // neither deletes the old data nor makes internal copies of the new
    // data. 
    void SetAnim (NiFloatKey* pkKeys, unsigned int uiNumKeys,
        NiFloatKey::KeyType eType);

    // *** begin NDL internal use only ***
    void GuaranteeKeysAtStartAndEnd(float fStartTime, float fEndTime);
    NiFloatDataPtr GetSequenceData(float fStartTime, float fEndTime);
    // *** end NDL internal use only ***

protected:
    unsigned int m_uiNumKeys;
    NiFloatKey* m_pkKeys;
    NiFloatKey::KeyType m_eType;
    unsigned char m_ucKeySize;
};

#include "NiFloatData.inl"

#endif
