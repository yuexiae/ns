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

#ifndef NIDYNAMICEFFECT_H
#define NIDYNAMICEFFECT_H

#include "NiAVObject.h"

class NiNode;

// note that these are stars, not smart pointers
typedef NiTPointerList<NiNode*> NiNodeList;

class NIMAIN_ENTRY NiDynamicEffect : public NiAVObject
{
    NiDeclareRTTI;
    NiDeclareAbstractClone(NiDynamicEffect);
    NiDeclareAbstractStream;
    NiDeclareViewerStrings;

public:
    enum EffectType
    {
        AMBIENT_LIGHT,
        DIR_LIGHT,
        POINT_LIGHT,
        SPOT_LIGHT,
        TEXTURE_EFFECT,
        MAX_TYPES,

        // Note - all vertex-based lights types _must_ come before
        // the texture effects.  This allows the enum below to be
        // used for fast type checking in the low-level renderers, i.e.
        // (pE->GetEffectType() <= MAX_LIGHT_TYPE) <---> IsKindOf(NiLight, pS)

        MAX_LIGHT_TYPE = SPOT_LIGHT
    };


    // construction and destruction
    NiDynamicEffect();
    virtual ~NiDynamicEffect();

    // attributes
    virtual EffectType GetEffectType() const = 0;
    
    void SetSwitch(bool bOn);
    bool GetSwitch() const;

    // affected objects
    const NiNodeList& GetAffectedNodeList();
    void AttachAffectedNode(NiNode* pkAffectedNode);
    void DetachAffectedNode(NiNode* pkAffectedNode);
    void DetachAllAffectedNodes();

    // Unaffected objects
    const NiNodeList& GetUnaffectedNodeList();
    void AttachUnaffectedNode(NiNode* pkUnaffectedNode);
    void DetachUnaffectedNode(NiNode* pkUnaffectedNode);
    void DetachAllUnaffectedNodes();
    bool IsUnaffectedNode(NiNode* pkPossibleNode);

    // *** begin NDL internal use only ***

    // bookkeeping
    int GetIndex() const;
    void IncRevisionID();
    unsigned int GetRevisionID() const;
    void SetRevisionID(unsigned int uiRevID);

    void IncPushCount();
    void DecPushCount();
    int GetPushCount() const;

#ifdef PS2
    u_long128* GetRenderData();
#endif

    // *** end NDL internal use only ***

protected:
    bool m_bOn;

    // bookkeeping
    int m_iIndex;
    unsigned int m_uiPushCount;
    unsigned int m_uiRevID;
    static int ms_iNextIndex;
    
    // illuminated objects
    NiNodeList m_kAffectedNodeList;

    // unaffected objects
    NiNodeList m_kUnaffectedNodeList;

#ifdef PS2
    // The PS2 renderer caches data that has to be calculated once per
    // click per dynamic effect in m_aulRenderData.
    u_long128 m_aulRenderData[4];
#endif

#if !defined(_XBOX) && !defined(WIN32) && !defined(_XENON)
    static NiCriticalSection ms_kCritSec;
#endif
};

typedef NiPointer<NiDynamicEffect> NiDynamicEffectPtr;

// note that these are stars, not smart pointers
typedef NiTPointerList<NiDynamicEffect*> NiDynamicEffectList;

#include "NiDynamicEffect.inl"

#endif // NIDYNAMICEFFECT_H

