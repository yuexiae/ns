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

#ifndef NISWITCHNODE_H
#define NISWITCHNODE_H

#include "NiNode.h"
#include "NiStream.h"
class NiCamera;

class NIMAIN_ENTRY NiSwitchNode : public NiNode
{
    NiDeclareRTTI;
    NiDeclareClone(NiSwitchNode);
    NiDeclareStream;
    NiDeclareViewerStrings;
    NiDeclareFlags(unsigned short);

public:
    // construction and destruction
    NiSwitchNode();

    // child attaching/detaching
    virtual void AttachChild(NiAVObject* pkChild, bool bFirstAvail = false);
    virtual NiAVObjectPtr DetachChild(NiAVObject* pkChild);
    virtual NiAVObjectPtr DetachChildAt(unsigned int i);
    virtual NiAVObjectPtr SetAt(unsigned int i, NiAVObject* pkChild);

    // switch operations
    NiAVObject* GetActiveChild() const;
    void SetIndex(int iIndex);
    int GetIndex() const;

    // updates
    void UpdateOnlyActiveChild(bool bUpdateOnlyActive);
    bool GetUpdateOnlyActiveChild() const;

    // *** begin NDL internal use only ***

    // updates
    virtual void UpdateControllers(float fTime);
    virtual void UpdateDownwardPass(float fTime, bool bUpdateControllers);
    virtual void UpdateSelectedDownwardPass(float fTime);
    virtual void UpdateRigidDownwardPass(float fTime);
    virtual void UpdateWorldBound();
    virtual void UpdateNodeBound();

    // scene graph traversal
    virtual void Display(NiCamera* pkCamera);

    // *** end NDL internal use only ***

protected:
    // --- Begin NIF conversion code
    // Deprecated flags - use new flag code
    enum
    {
        MAX_POS = 9
    };
    // --- End NIF conversion code

    // flags
    enum
    {
        UPDATE_ONLY_ACTIVE_CHILD_MASK   = 0x0001
    };

    int m_iIndex;

    float m_fSavedTime;
    unsigned int m_uiRevID;
    NiTArray<unsigned int> m_kChildRevID;

    bool m_bUpdateControllers;
};

typedef NiPointer<NiSwitchNode> NiSwitchNodePtr;

#include "NiSwitchNode.inl"

#endif
