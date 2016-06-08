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

#ifndef NINODE_H
#define NINODE_H

#include "NiAVObject.h"
#include "NiDynamicEffect.h"
#include "NiProperty.h"
#include "NiTArray.h"

class NiBitVector;
class NiCamera;
NiSmartPointer(NiNode);

class NIMAIN_ENTRY NiNode : public NiAVObject
{
    NiDeclareRTTI;
    NiDeclareClone(NiNode);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    // construction and destruction
    NiNode(unsigned int uiNumChildren = 0);
    virtual ~NiNode();

    // children
    unsigned int GetArrayCount() const;
    unsigned int GetChildCount() const;
    virtual void AttachChild(NiAVObject* pkChild, bool bFirstAvail = false);
    virtual NiAVObjectPtr DetachChild(NiAVObject* pkChild);
    virtual NiAVObjectPtr DetachChildAt(unsigned int i);
    virtual NiAVObjectPtr SetAt(unsigned int i, NiAVObject* pkChild);
    NiAVObject* GetAt(unsigned int i) const;

    // transforms
    virtual void ApplyTransform(const NiMatrix3& kMat, const NiPoint3& kTrn,
        bool bOnLeft);

    // dynamic effects
    const NiDynamicEffectList& GetEffectList() const;
    void AttachEffect(NiDynamicEffect* pkEffect);
    void DetachEffect(NiDynamicEffect* pkEffect);
    void DetachAllEffects();

    // name search
    virtual NiAVObject* GetObjectByName(const char* pcName);

    // *** begin NDL internal use only ***

    // updates
    virtual void UpdateControllers(float fTime);
    virtual void UpdateDownwardPass(float fTime, bool bUpdateControllers);
    virtual void UpdateSelectedDownwardPass(float fTime);
    virtual void UpdateUpwardPass();
    virtual void UpdateWorldBound();
    virtual void UpdateRigidDownwardPass(float fTime);
    virtual void UpdateNodeBound();

    NiPropertyStatePtr UpdatePropertiesUpward();
    NiDynamicEffectStatePtr UpdateEffectsUpward();
    NiDynamicEffectStatePtr PushLocalEffects(
        NiDynamicEffectState* pkParentState, bool bCopyOnChange);
    virtual void UpdatePropertiesDownward(NiPropertyState* pkParentState);
    virtual void UpdateEffectsDownward(NiDynamicEffectState* pkParentState);

    // scene graph traversal
    virtual void Display(NiCamera* pkCamera);

    // Returns 'true' iff both trees have same parent-child topology and
    // the RTTI of each pair of corresponding nodes are identical.
    static bool SameTopology(NiAVObject* pkObj0, NiAVObject* pkObj1);

    // needed by NiOptimize functions
    void RemoveAllChildren();
    void CompactChildArray();

    // set selective update flags
    virtual void SetSelectiveUpdateFlags(bool& bSelectiveUpdate, 
        bool bSelectiveUpdateTransforms, bool& bRigid);

    // renderer data
    virtual void PurgeRendererData(NiRenderer* pkRenderer);

    virtual void ProcessClone(NiCloningProcess& kCloning);
    // *** end NDL internal use only ***

protected:
    // cloning
    void CopyEffectListClones(const NiDynamicEffectList* pkList,
        NiCloningProcess& kCloning);

    // scene graph links
    NiTArray<NiAVObjectPtr> m_kChildren;

    // lights
    NiDynamicEffectList m_kEffectList;

    // --- Begin NIF conversion code
    // Deprecated flags - use new flag code
    enum
    {
        MAX_POS = 8
    };
    // --- End NIF conversion code

    // bound of subtree 
    NiBound m_kBound;
};

// note these are stars, not smart pointers
typedef NiTPointerList<NiNode*> NiNodeList;

#include "NiNode.inl"

#endif

