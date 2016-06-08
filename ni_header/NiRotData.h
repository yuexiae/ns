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

#ifndef NIROTDATA_H
#define NIROTDATA_H

#include <NiObject.h>
#include "NiAnimationLibType.h"
#include "NiRotKey.h"

NiSmartPointer(NiRotData);

class NIANIMATION_ENTRY NiRotData : public NiObject
{
    NiDeclareRTTI;
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiRotData();
    virtual ~NiRotData();

    // position key access
    unsigned int GetNumKeys() const;
    NiRotKey* GetAnim(unsigned int& uiNumKeys, NiRotKey::KeyType& eType, 
        unsigned char& ucSize) const;

    // For swapping animation sequences at runtime. The object
    // assumes ownership of the data array being passed in, and has the
    // responsibility for deleting it when finished with it.
    void ReplaceAnim (NiRotKey* pkKeys, unsigned int uiNumKeys,
        NiRotKey::KeyType eType);

    // For swapping rotation animation sequences at runtime.  The method
    // neither deletes the old data nor makes internal copies of the new
    // data. 
    void SetAnim (NiRotKey* pkKeys, unsigned int uiNumKeys,
        NiRotKey::KeyType eType);

    // *** begin NDL internal use only ***
    void GuaranteeKeysAtStartAndEnd(float fStartTime, float fEndTime);
    NiRotDataPtr GetSequenceData(float fStartTime, float fEndTime);
    // *** end NDL internal use only ***

protected:
    unsigned int m_uiNumKeys;
    NiRotKey* m_pkKeys;
    NiRotKey::KeyType m_eType;
    unsigned char m_ucKeySize;
};

#include "NiRotData.inl"

#endif  // #ifndef NIROTDATA_H
