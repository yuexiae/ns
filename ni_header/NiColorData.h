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

#ifndef NICOLORDATA_H
#define NICOLORDATA_H

#include <NiObject.h>
#include "NiAnimationLibType.h"
#include "NiColorKey.h"

NiSmartPointer(NiColorData);

class NIANIMATION_ENTRY NiColorData : public NiObject
{
    NiDeclareRTTI;
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiColorData ();
    virtual ~NiColorData ();

    // color key access
    unsigned int GetNumKeys () const;
    NiColorKey* GetAnim (unsigned int& uiNumKeys,
        NiColorKey::KeyType& eType, unsigned char& ucSize) const;

    // For swapping animation sequences at runtime. The object
    //   assumes ownership of the data array being passed in, and has the 
    //   responsibility for deleting it when finished with it.
    void ReplaceAnim (NiColorKey* pkKeys, unsigned int uiNumKeys,
        NiColorKey::KeyType eType);

    // For swapping rotation animation sequences at runtime.  The method
    // neither deletes the old data nor makes internal copies of the new
    // data. 
    void SetAnim (NiColorKey* pkKeys, unsigned int uiNumKeys,
        NiColorKey::KeyType eType);

    // *** begin NDL internal use only ***
    void GuaranteeKeysAtStartAndEnd(float fStartTime, float fEndTime);
    NiColorDataPtr GetSequenceData(float fStartTime, float fEndTime);
    // *** end NDL internal use only ***

protected:
    unsigned int m_uiNumKeys;
    NiColorKey* m_pkKeys;
    NiColorKey::KeyType m_eType;
    unsigned char m_ucKeySize;
};

#include "NiColorData.inl"

#endif
