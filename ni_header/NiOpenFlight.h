// NUMERICAL DESIGN LIMITED PROPRIETARY INFORMATION
//
// This software is supplied under the terms of a license agreement or
// nondisclosure agreement with Numerical Design Limited and may not 
// be copied or disclosed except in accordance with the terms of that 
// agreement.
//
//      Copyright (c) 1996-2002 Numerical Design Limited.
//      All Rights Reserved.
//
// Numerical Design Limited, Chapel Hill, North Carolina 27514
// http://www.ndl.com

#ifndef NIOPENFLIGHT_H
#define NIOPENFLIGHT_H

#include <NiTMap.h>

// must do this to avoid having to include MultiGen headers in public header
typedef struct mgrec mgrec;

class NiAVObject;
class NiNode;
class NiOFPolygon;

class NiOpenFlight
{
public:
    NiOpenFlight ();
    ~NiOpenFlight ();

    static mgrec* GetActiveDB () { return ms_pkActiveDB; }

    NiNode* CreateScene (const char* pcFLTName);

    void SetFreezeBillboards(bool bFreeze) { m_bFreezeBillboards = bFreeze; }
    bool GetFreezeBillboards() { return m_bFreezeBillboards; }

    static void Init();
    static void Shutdown();

    static void SetUseInternalTextures(bool bInt);
    static void SetAddDefaultLights(bool bAddDefaultLights);
	static void SetUseTrueDoubleSided(bool bUseTrueDoubleSided);

    static void SetForceMergeSiblingSwitchNodes(bool bForce) 
    { ms_bForceMergeSiblingSwitchNodes = bForce; }

    static bool GetForceMergeSiblingSwitchNodes() 
    { return ms_bForceMergeSiblingSwitchNodes; }

    static void SetForceMergeSiblingLODNodes(bool bForce) 
    { ms_bForceMergeSiblingLODNodes = bForce; }

    static bool GetForceMergeSiblingLODNodes() 
    { return ms_bForceMergeSiblingLODNodes; }

protected:
    NiAVObject* ProcessPolygons (mgrec* pkPoly, NiNode*& pkNode);
    void AttachTransformMatrix (mgrec* pkMgNode, NiAVObject* pkObject);
    void AttachDOFTransformMatrix (mgrec* pkMgNode, NiNode* pkNode);
    void ApplyDeferredTransforms (NiAVObject* pkObject);

    NiNode* HeaderHandler (mgrec* pkMgNode, float& fUnitScale);
    NiNode* GroupHandler (mgrec* pkRec, bool& bFlipbook);
    NiNode* SwitchHandler (mgrec* pkRec);
    NiNode* LodHandler (mgrec* pkRec);
    NiNode* BspHandler (mgrec* pkRec);
    NiNode* DofHandler (mgrec* pkRec);
    NiNode* LightSourceHandler (mgrec* pkRec);
    NiNode* SoundHandler (mgrec* pkRec);
    NiNode* ObjectHandler (mgrec* pkRec);
    NiAVObject* PolygonHandler (mgrec* pkRec, NiNode* pkNode);
    NiNode* XrefHandler (mgrec* pkRec, float fUnitScale);
    void DefaultHandler (int iCode);

    NiAVObject* Traverse (mgrec* pkRec, float fUnitScale,
        NiNode*& pkHeaderNode);

    void MergeSiblingSwitchNodes(NiAVObject* pkModel);
    void MergeSiblingLODNodes(NiAVObject* pkModel);

    static mgrec* ms_pkActiveDB;
    NiTMap<mgrec*, NiAVObject*> m_kInstanceCache;

    static bool ms_bForceMergeSiblingSwitchNodes;
    static bool ms_bForceMergeSiblingLODNodes;

    bool m_bFreezeBillboards;
};

#endif
