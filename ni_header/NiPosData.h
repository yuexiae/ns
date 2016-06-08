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

#ifndef NIPOSDATA_H
#define NIPOSDATA_H

#include <NiObject.h>
#include "NiAnimationLibType.h"
#include "NiPosKey.h"

NiSmartPointer(NiPosData);

class NIANIMATION_ENTRY NiPosData : public NiObject
{
    NiDeclareRTTI;
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiPosData ();
    virtual ~NiPosData ();

    // position key access
    unsigned int GetNumKeys () const;
    NiPosKey* GetAnim (unsigned int& uiNumKeys,
        NiPosKey::KeyType& eType, unsigned char& ucSize) const;

    // For swapping animation sequences at runtime. The object 
    //   assumes ownership of the data array being passed in, and has the 
    //   responsibility for deleting it when finished with it.
    void ReplaceAnim (NiPosKey* pkKeys, unsigned int uiNumKeys,
        NiPosKey::KeyType eType);

    // For swapping rotation animation sequences at runtime.  The method
    // neither deletes the old data nor makes internal copies of the new
    // data. 
    void SetAnim (NiPosKey* pkKeys, unsigned int uiNumKeys,
        NiPosKey::KeyType eType);

    // *** begin NDL internal use only ***
    void GuaranteeKeysAtStartAndEnd(float fStartTime, float fEndTime);
    NiPosDataPtr GetSequenceData(float fStartTime, float fEndTime);
    // *** end NDL internal use only ***

protected:
    unsigned int m_uiNumKeys;
    NiPosKey* m_pkKeys;
    NiPosKey::KeyType m_eType;
    unsigned char m_ucKeySize;
};

#include "NiPosData.inl"

#endif
