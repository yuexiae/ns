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

#ifndef NISKININSTANCE_H
#define NISKININSTANCE_H

#include "NiAVObject.h"
#include "NiGeometryData.h"
#include "NiTransform.h"
#include "NiSkinData.h"
#include "NiSkinPartition.h"

// NiSkinInstance contains data that cannot shared by multiple
// instances of the same skinned object.

#ifdef PS2
class NiMatrix4;
#endif

class NIMAIN_ENTRY NiSkinInstance : public NiObject
{
    NiDeclareRTTI;
    NiDeclareClone(NiSkinInstance);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    // The NiSkinInstance class assumes control of the ppkBones array passed
    // to its constructor. (i.e. Its destructor deletes it.)

    NiSkinInstance(NiSkinData* pkSkinData, NiAVObject* pkRootParent,
        NiAVObject** ppkBones);
    virtual ~NiSkinInstance();

    NiSkinData* GetSkinData() const;
    NiAVObject* GetRootParent() const;
    NiAVObject*const* GetBones() const;
    NiSkinPartition* GetSkinPartition() const;

    void Deform(const NiGeometryData* pkModelData, NiPoint3* pkDstVertex,
        NiPoint3* pkDstNormal, NiPoint3* pkDstBinormal, 
        NiPoint3* pkDstTangent, unsigned int uiStride) const;

    void Deform(const NiPoint3* pkSrcVertex, const NiPoint3* pkSrcNormal,
        unsigned int uiVertices, NiPoint3* pkDstVertex, NiPoint3* pkDstNormal,
        NiPoint3* pkDstBinormal, NiPoint3* pkDstTangent, 
        unsigned int uiStride) const;

    void UpdateModelBound(NiBound& kBound);

    // Besides being used internally, these functions provide an interface
    // which eases the development of custom skinning code.
    void GetWorldToSkinTransform(NiTransform& kWorldToSkin) const;
    void ConcatWorldToSkinTransform(const NiTransform& kSourceMat, 
        NiTransform& kDestMat) const;
    void GetBoneWorldTransform(unsigned int uiBone, 
        NiTransform& kBoneWorld) const;
    void ConcatBoneWorldTransform(unsigned int uiBone, 
        const NiTransform& kSourceMat, NiTransform& kDestMat) const;
    void GetSkinToBoneTransform(unsigned int uiBone, 
        NiTransform& kSkinToBone) const;
    void ConcatSkinToBoneTransform(unsigned int uiBone, 
        const NiTransform& kSourceMat, NiTransform& kDestMat) const;
    void ConcatBoneWorldTransformAndSkinToBoneTransform(unsigned int uiBone, 
        NiTransform& kDestMat) const;

    // *** begin NDL internal use only ***

    NiSkinInstance();
    void SetSkinData(NiSkinData* pkSkinData);
    void SetRootParent(NiAVObject* pkRootParent);
    void SetBone(unsigned int i, NiAVObject* pkBone);
    void SetSkinPartition(NiSkinPartition* pkSkinPartition);

    unsigned int GetFrameID() const;
    void SetFrameID(unsigned int uiID);

    // streaming support
    virtual void PostLinkObject(NiStream& kStream);

    // *** end NDL internal use only ***

protected:
    bool NeedClone(NiCloningProcess& kCloning) const;

    NiSkinDataPtr m_spSkinData;
    NiSkinPartitionPtr m_spSkinPartition;

    // Bone pointers are regular pointers rather than smart pointers to avoid
    // reference cycles that arise when a skin is a descendant of the root 
    // bone.
    NiAVObject* m_pkRootParent;
    NiAVObject** m_ppkBones;

    unsigned int m_uiFrameID;

#if defined(WIN32) || defined(_XBOX) || defined(_XENON)
public:
    void SetBoneMatrices(void* pvMatrices, unsigned int uiNumMatrices,
        unsigned int uiNumRegisters = 4);
    unsigned int GetNumBoneMatrices() const;
    unsigned int GetBoneMatrixRegisters() const;
    void* GetBoneMatrices() const;

    void SetSkinToWorldWorldToSkinMatrix(void* pvMatrix);
    void* GetSkinToWorldWorldToSkinMatrix() const;

protected: 
    unsigned int m_uiNumMatrices;
    void* m_pvBoneMatrices;
    // Matrix palette skinning required values
    // Per-matrix register count
    unsigned int m_uiNumRegisters;
    // SkinToWorld-WorldToSkin matrix. Used to remove the overhead of the
    // additional matrix concatenation per-bone.
    void* m_pvSkinToWorldWorldToSkinMatrix;
#elif defined(NGC)
public:
    void SetDeformVertex(NiPoint3* pkDeform);
    NiPoint3* GetDeformVertex() const;
    void SetDeformNormal(NiPoint3* pkDeform);
    NiPoint3* GetDeformNormal() const;
    unsigned char GetActiveBuffer() const;
    void ToggleActiveBuffer();
protected:
    NiPoint3* m_pkDeformVertex[2];
    NiPoint3* m_pkDeformNormal[2];
    unsigned char m_ucActiveBuffer;
#elif defined(PS2)
public:
    void CalculateTransforms(bool bOddFrame);
    void InitializeBones();
    NiMatrix4* m_pkBoneMatrices;
#endif
};

typedef NiPointer<NiSkinInstance> NiSkinInstancePtr;

#include "NiSkinInstance.inl"

#endif // NISKININSTANCE_H
