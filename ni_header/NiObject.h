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

#ifndef NIOBJECT_H
#define NIOBJECT_H

#include "NiRTTI.h"
#include "NiSmartPointer.h"
#include "NiClone.h"
#include "NiRefObject.h"
#include "NiStreamMacros.h"
#include "NiViewerStrings.h"
#include "NiTPointerList.h"

class NiObjectGroup;

NiSmartPointer(NiObject);
template <class TKEY, class TVAL> class NiTPointerMap;

class NIMAIN_ENTRY NiObject : public NiRefObject
{
    NiDeclareRootRTTI(NiObject);
    NiDeclareClone(NiObject);
    NiDeclareStream;
    NiDeclareViewerStrings;
    virtual void AddViewerStrings (NiTArray<char*>* pStrings) {};

public:
    // destruction (constructor is protected, abstract base class)
    virtual ~NiObject();

    // cloning
    NiObject* Clone();
    NiObject* Clone(NiCloningProcess& kCloning);
    virtual void ProcessClone(
        NiCloningProcess& kCloning);

    NiObjectPtr CreateDeepCopy();

    // *** begin NDL internal use only ***

    // streaming support
    virtual void PostLinkObject(NiStream& kStream);

    // block allocation
    virtual unsigned int GetBlockAllocationSize() const;
    virtual NiObjectGroup* GetGroup() const;
    virtual void SetGroup(NiObjectGroup* pkGroup);

    // *** end NDL internal use only ***

protected:
    // constructor for streaming
    NiObject();

private:
    // To prevent an application from inadvertently causing the compiler to
    // generate the default copy constructor or default assignment operator,
    // these methods are declared as private. They are not defined anywhere,
    // so code that attempts to use them will not link.
    // Applications should use NiObject::Clone() to duplicate NiObject-derived
    // classes.
    NiObject(const NiObject& kObject);
    NiObject& operator=(const NiObject& kObject);
};

// smart pointer type for objects
typedef NiPointer<NiObject> NiObjectPtr;
typedef NiTPointerList<NiObjectPtr> NiObjectList;

#endif

