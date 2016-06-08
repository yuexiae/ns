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

#ifndef NIPARTICLEMESHESDATA_H
#define NIPARTICLEMESHESDATA_H

#include "NiAVObject.h"
#include "NiNode.h"
#include "NiParticlesData.h"

class NIMAIN_ENTRY NiParticleMeshesData : public NiParticlesData
{
    NiDeclareRTTI;
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    // The constructed object is given ownership of the input arrays and
    // has the responsibility for deleting them when finished with them.
    NiParticleMeshesData(unsigned short usVertices, NiPoint3* pkVertex,
        NiPoint3* pkNormal, NiColorA* pkColor, NiQuaternion* pkRots);

    NiParticleMeshesData();

    virtual ~NiParticleMeshesData();

    // particle attributes
    NiAVObject* GetMeshAt(unsigned int uiIndex) const;
    void SetMeshAt(unsigned short usIndex, NiAVObject* pkMesh);

    virtual void SetActiveVertexCount(unsigned short usActive);
    virtual void RemoveParticle(unsigned short usParticle);

    // *** begin NDL internal use only ***
    NiNode* GetContainerNode() const;
    bool GetNeedPropertyEffectUpdate() const;
    void SetNeedPropertyEffectUpdate(bool bUpdate);

    void UpdateParticles();

    // For temporarily using data only.  This call is like Replace(), 
    // but does not delete any pointers.  Be careful to call this only 
    // on objects created by the default (empty) constructor to prevent 
    // memory leaks.  These pointers will be owned (and deleted upon 
    // destruction) by this object so use this call carefully.
    //void SetData(NiTriShapePtr* pspTriMeshes);

    // *** end NDL internal use only ***

protected:
    NiNodePtr m_spParticleMeshes;
    bool m_bNeedsPropertyEffectUpdate;
};

NiSmartPointer(NiParticleMeshesData);

#include "NiParticleMeshesData.inl"

#endif // NIPARTICLEMESHESDATA_H

