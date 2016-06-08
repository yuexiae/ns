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

#ifndef NICOLLISIONOBJECT_H
#define NICOLLISIONOBJECT_H

#include "NiObject.h"

class NiAVObject;

class NIMAIN_ENTRY NiCollisionObject : public NiObject
{
    NiDeclareRTTI;
    NiDeclareAbstractClone(NiCollisionObject);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    // Constructors and Destructors
    NiCollisionObject(NiAVObject* pkSceneObject);
    virtual ~NiCollisionObject() = 0;

    // scene graph object access
    NiAVObject* GetSceneGraphObject() const;
    virtual void SetSceneGraphObject(NiAVObject* pkSceneObject);

    virtual void UpdateWorldData() = 0;
    virtual void RecreateWorldData() = 0;

    // *** begin NDL internal use only ***   
    virtual void Initialize(void *pkData){};
    virtual void AddViewerStrings(NiTArray<char*>* pkStrings);
    virtual void Convert(unsigned int uiVersion, void *pkData = NULL){};
    // *** end NDL internal use only ***
    
protected:
    // To prevent public access to a constructor with no scene association
    NiCollisionObject();

    NiAVObject* m_pkSceneObject;
};

typedef NiPointer<NiCollisionObject> NiCollisionObjectPtr;

#endif



