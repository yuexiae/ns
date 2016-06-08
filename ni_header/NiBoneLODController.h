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

#ifndef NIBONELODCONTROLLER_H
#define NIBONELODCONTROLLER_H

#include <NiTimeController.h>
#include "NiAnimationLibType.h"
#include <NiSkinInstance.h>
#include <NiTArray.h>
#include <NiTSet.h>

class NiNode;
class NiTriBasedGeom;

NiSmartPointer(NiBoneLODController);

class NIANIMATION_ENTRY NiBoneLODController : public NiTimeController
{
    NiDeclareRTTI;
    NiDeclareClone(NiBoneLODController);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    // Constructor and destructor.
    NiBoneLODController();
    virtual ~NiBoneLODController();

    virtual void Update(float fTime);

    bool SetBoneLOD(int iLOD);
    int GetBoneLOD() const;
    unsigned int GetNumberOfBoneLODs() const;

    // Function to remove all references to a particular skin geometry from
    // the controller. Call this function if you are removing the geometry
    // object from the scene graph. There is no way to add it back in.
    void RemoveSkinFromAllLODs(NiTriBasedGeom* pkSkinToRemove);

    // *** begin NDL internal use only ***
    static bool ProcessScene(NiNode* pkSceneRoot);
    bool InitializeData(NiNode* pkBoneRoot,
        const NiTPointerMap<NiTriBasedGeom*, NiTSet<unsigned int>*>& kSkinToLOD);
    void GetSkinData(NiTSet<NiTriBasedGeom*>& kGeoms,
        NiTSet<NiSkinInstance*>& kInstances);
    void ReplaceSkin(NiTriBasedGeom* pkOldSkin, NiTriBasedGeom* pkNewSkin);
    bool FindGeom(NiTriBasedGeom* pkGeom);
    // *** end NDL internal use only ***

    // This is a global debug setting used to set all LOD Levels 
    static int GetGlobalLOD();
    static void SetGlobalLOD(int iNewLOD);

protected:
    struct SkinInfo
    {
        NiTriBasedGeom* m_pkSkinGeom;
        NiSkinInstancePtr m_spSkinInst;
    };

    struct BoneDataObj
    {
        NiSkinData::BoneData* m_pkBoneData;
        NiTSet<NiSkinData::BoneVertData*> m_kBoneVertData;
    };

    static void FindBoneRootNodes(NiNode* pkNode,
        NiTSet<NiNode*>& kBoneRootNodes);
    static void FindSkinGeometry(NiAVObject* pkObject,
        NiTPointerMap<NiTriBasedGeom*, NiTSet<unsigned int>*>& kSkinToLOD,
        NiNode* pkBoneRoot);
    static void GetGeomChildren(NiNode* pkNode,
        NiTSet<NiTriBasedGeom*>& kGeomChildren);

    virtual bool TargetIsRequiredType() const;

    void CleanUp();

    void CollectMarkedBones(NiNode* pkBone,
        NiTPointerMap<NiNode*, unsigned int>& kBoneToLOD,
        NiTPointerMap<unsigned int, bool>& kUsedLODs);
    void BuildBoneMap(NiNode* pkBone,
        NiTPointerMap<NiNode*, unsigned int>& kBoneToLOD,
        unsigned int& uiCurrentLOD);
    bool FillSkinArray(
        const NiTPointerMap<NiTriBasedGeom*, NiTSet<unsigned int>*>& kSkinToLOD,
        const NiTPointerMap<NiNode*, unsigned int>& kBoneToLOD,
        NiTPointerMap<unsigned int, bool>& kUsedLODs);
    NiSkinInstance* CreateLODSkinInstance(NiTriBasedGeom* pkOldGeom,
        unsigned int uiDesiredLOD,
        const NiTPointerMap<NiTriBasedGeom*, NiTSet<unsigned int>*>& kSkinToLOD,
        const NiTPointerMap<NiNode*, unsigned int>& kBoneToLOD);

    // Cloning support.
    virtual void ProcessClone(
        NiCloningProcess& kCloning);

    // Streaming support.
    virtual void PostLinkObject(NiStream& kStream);

    int m_iLOD;
    unsigned int m_uiNumLODs;
    NiTArray<NiTSet<NiNode*>*> m_kBoneArray;
    NiTArray<NiTSet<SkinInfo*>*> m_kSkinArray;
    NiTSet<NiTriBasedGeom*> m_kSkinSet;

    static int ms_iGlobalLOD;
};

#include "NiBoneLODController.inl"

#endif  // #ifndef NIBONELODCONTROLLER_H
