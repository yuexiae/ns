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

#ifndef NIKEYFRAMEMANAGER_H
#define NIKEYFRAMEMANAGER_H

#include <NiTimeController.h>
#include "NiAnimationLibType.h"
#include "NiSequence.h"
#include <NiTStringMap.h>

NiSmartPointer(NiKeyframeManager);

// NOTICE: This class is deprecated. You should use NiControllerManager
//         instead.

class NIANIMATION_ENTRY NiKeyframeManager : public NiTimeController
{
    NiDeclareRTTI;
    NiDeclareStream;

protected:
    NiKeyframeManager();

    virtual bool TargetIsRequiredType() const;

    bool Add(const char* pcSequenceFile, const char* pcSequenceName,
        unsigned int uiIndex = 0);
    bool Add(NiSequence* pkSequence);

    virtual void Update(float fTime){}

    NiTStringPointerMap<NiSequencePtr> m_kMap;

    // This LinkRecord class is for backwards compatibility only.
    // It can be removed when loading NIF GetFileVersion < 4.1.0.3 is
    // no longer supported.
    class NIANIMATION_ENTRY LinkRecord
    {
    public:
        NiTArray<unsigned int> m_kTextKeyReferences;
        NiTArray<char*> m_kSequenceNames;
        NiTArray<unsigned int> m_kNumSequenceKeys;
        NiTArray<char*> m_kObjectName;
    };
    static LinkRecord* ms_pkLinkRecord;
};

#endif
