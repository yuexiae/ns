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

#ifndef NIREFOBJECT_H
#define NIREFOBJECT_H

#include "NiMainLibType.h"

// NiRefObject provides the reference counting functionality needed for use
// of Gamebryo smart pointers. A class derived from NiRefObject can be used
// with the template class NiPointer.

class NIMAIN_ENTRY NiRefObject
{
public:
    NiRefObject();
    virtual ~NiRefObject();
    void IncRefCount();
    void DecRefCount();
    unsigned int GetRefCount() const;
    static unsigned int GetTotalObjectCount();

private:
    unsigned int m_uiRefCount;
    static unsigned int ms_uiObjects;
};

#include "NiRefObject.inl"

#endif // NIREFOBJECT_H
