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

#ifndef NiTransformData_H
#define NiTransformData_H

#include <NiObject.h>
#include "NiAnimationLibType.h"
#include "NiRotKey.h"
#include "NiPosKey.h"
#include "NiFloatKey.h"

NiSmartPointer(NiTransformData);

class NIANIMATION_ENTRY NiTransformData : public NiObject
{
    NiDeclareRTTI;
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiTransformData ();
    virtual ~NiTransformData ();

    // rotation key access
    unsigned int GetNumRotKeys () const;
    NiRotKey* GetRotAnim (unsigned int& uiNumKeys,
        NiRotKey::KeyType& eType, unsigned char& ucSize) const;

    // For swapping rotation animation sequences at runtime. The 
    //   object assumes ownership of the data array being 
    //   passed in, and has the responsibility for deleting it when finished 
    //   with it.
    void ReplaceRotAnim (NiRotKey* pkKeys, unsigned int uiNumKeys,
        NiRotKey::KeyType eType);

    // For swapping rotation animation sequences at runtime.  The method
    // neither deletes the old data nor makes internal copies of the new
    // data. The application is responsible for the deletion.
    void SetRotAnim (NiRotKey* pkKeys, unsigned int uiNumKeys,
        NiRotKey::KeyType eType);

    // position key access
    unsigned int GetNumPosKeys () const;
    NiPosKey* GetPosAnim (unsigned int& uiNumKeys,
        NiPosKey::KeyType& eType, unsigned char& ucSize) const;

    // For swapping position animation sequences at runtime. The 
    //   object assumes ownership of the data array being 
    //   passed in, and has the responsibility for deleting it when finished 
    //   with it.
    void ReplacePosAnim (NiPosKey* pkKeys, unsigned int uiNumKeys,
        NiPosKey::KeyType eType);

    // For swapping position animation sequences at runtime.  The method
    // neither deletes the old data nor makes internal copies of the new
    // data. The application is responsible for the deletion.
    void SetPosAnim (NiPosKey* pkKeys, unsigned int uiNumKeys,
        NiPosKey::KeyType eType);

    // scale key access
    unsigned int GetNumScaleKeys () const;
    NiFloatKey* GetScaleAnim (unsigned int& uiNumKeys,
        NiFloatKey::KeyType& eType, unsigned char& ucSize) const;

    // For swapping scale animation sequences at runtime. The 
    //   object assumes ownership of the data array being 
    //   passed in, and has the responsibility for deleting it when finished 
    //   with it.
    void ReplaceScaleAnim (NiFloatKey* pkKeys, unsigned int uiNumKeys,
        NiFloatKey::KeyType eType);

    // For swapping scale animation sequences at runtime.  The method
    // neither deletes the old data nor makes internal copies of the new
    // data. The application is responsible for the deletion.
    void SetScaleAnim (NiFloatKey* pkKeys, unsigned int uiNumKeys,
        NiFloatKey::KeyType eType);

    // *** begin NDL internal use only ***
    void GuaranteeKeysAtStartAndEnd(float fStartTime, float fEndTime);
    NiTransformDataPtr GetSequenceData(float fStartTime, float fEndTime);
    // *** end NDL internal use only ***

protected:
    void CleanRotAnim (NiRotKey* pkRotKeys, unsigned int uiRotKeys,
        NiRotKey::KeyType eType);
    
    unsigned int m_uiNumRotKeys;
    NiRotKey* m_pkRotKeys;
    NiRotKey::KeyType m_eRotType;
    unsigned char m_ucRotSize;

    unsigned int m_uiNumPosKeys;
    NiPosKey* m_pkPosKeys;
    NiPosKey::KeyType m_ePosType;
    unsigned char m_ucPosSize;

    unsigned int m_uiNumScaleKeys;
    NiFloatKey* m_pkScaleKeys;
    NiFloatKey::KeyType m_eScaleType;
    unsigned char m_ucScaleSize;
};

#include "NiTransformData.inl"

#endif
