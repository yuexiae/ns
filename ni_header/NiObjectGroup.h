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

#ifndef NIOBJECTGROUP_H
#define NIOBJECTGROUP_H

#include "NiMainLibType.h"
#include "NiMemManager.h"

class NIMAIN_ENTRY NiObjectGroup
{
public:
    NiObjectGroup(unsigned int uiBytes = 0);
    ~NiObjectGroup();

    void* Allocate(unsigned int uiBytes);
    void DecRefCount();

    void SetSize(unsigned int uiSize);
    unsigned int GetSize() const;

private:
    unsigned int m_uiSize;
    void* m_pvBuffer;
    void* m_pvFree;
    unsigned int m_uiRefCount;
};

#include "NiObjectGroup.inl"

#endif // NIOBJECTGROUP_H
