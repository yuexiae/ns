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

#ifndef NICLONINGPROCESS_H
#define NICLONINGPROCESS_H

#include "NiMainLibType.h"
#include "NiObjectNET.h"
#include "NiTPointerMap.h"

class NiObject;

class NIMAIN_ENTRY NiCloningProcess
{
public:
    NiCloningProcess()
    {
        m_pkCloneMap = new NiTPointerMap<NiObject*, NiObject*>;
        assert(m_pkCloneMap != NULL);
        m_pkProcessMap = new NiTPointerMap<NiObject*, bool>;
        assert(m_pkProcessMap != NULL);
        m_eCopyType = NiObjectNET::GetDefaultCopyType();
        m_cAppendChar = NiObjectNET::GetDefaultAppendCharacter();
    }

    ~NiCloningProcess()
    {
        delete m_pkCloneMap;
        delete m_pkProcessMap;
    }

    NiTPointerMap<NiObject*, NiObject*>* m_pkCloneMap;
    NiTPointerMap<NiObject*, bool>* m_pkProcessMap;
    NiObjectNET::CopyType m_eCopyType;
    char m_cAppendChar;
};

#endif // NICLONINGPROCESS_H
