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

#ifndef NISHAREDDATA_H
#define NISHAREDDATA_H

#include "NiPluginToolkitLibType.h"
#include <NiObject.h>

typedef const NiRTTI* NiSharedDataType;

/// The NiSharedData object defines the base class for all structures
/// being shared between plug-ins. This defines the base interface used by
/// all NiSharedData objects.
class NIPLUGINTOOLKIT_ENTRY NiSharedData : public NiObject
{
public:
    NiDeclareRTTI;

    /// Virtual destructor.
    virtual ~NiSharedData(){}

    /// Returns the shared data type for the object.
    NiSharedDataType GetType();
};

NiSmartPointer(NiSharedData);

#define NiGetSharedDataType(classname)\
    &classname::m_RTTI

#endif  // #ifndef NISHAREDDATA_H
