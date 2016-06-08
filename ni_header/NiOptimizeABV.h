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

#ifndef NIOPTIMIZEABV_H
#define NIOPTIMIZEABV_H

#include "NiOptimizationLibType.h"
#include "NiTPointerList.h"

class NiAVObject;
class NiBoundingVolume;
class NiColor;
class NiNode;
class NiPoint3;

class NIOPTIMIZATION_ENTRY NiOptimizeABV
{
public:
    static void CreateABVFromProxy(NiAVObject* pkObject, 
        NiTPointerList<char*>* pkErrors = NULL);
    static void CreateWireABV(NiAVObject* pkObject, const NiColor& kColor,
        float fMult, const char* pcName, bool bCreateOBB);
    static void CreateWireABVProxy(NiAVObject* pkObject,
        const NiColor& kColor, float fMult, const char* pcName);

    static void RemoveByFirstToken(NiAVObject* pkObject, const char* pcName);
    static NiNode* GetNodeByFirstToken(NiNode* pkNode, const char* pcToken);

    static void CountByName(NiAVObject* pkObject, const char* pcName,
        unsigned int& uiCount);
    static void StoreNodesWithName(NiAVObject* pkObject, const char* pcName,
        NiNode** ppkArray, unsigned int& uiIndex);
    static void GroupNoTestNodes(NiNode* pkNode);

private:
    // ABV creation helper functions
    static NiBoundingVolume* CreateSphereABV(NiNode* pkChild, 
        NiTPointerList<char*>* pkErrors = NULL);
    static NiBoundingVolume* CreateCapsuleABV(NiNode* pkChild, 
        NiTPointerList<char*>* pkErrors = NULL);
    static NiBoundingVolume* CreateBoxABV(NiNode* pkChild, 
        NiTPointerList<char*>* pkErrors = NULL);
    static NiBoundingVolume* CreateUnionABV(NiNode* pkChild, 
        NiTPointerList<char*>* pkErrors = NULL);
    static NiBoundingVolume* CreateHalfSpaceABV(NiNode* pkChild, 
        NiTPointerList<char*>* pkErrors = NULL);

    // other helper functions
    static void GetCenterAndExtents(NiNode* pkNode, NiPoint3& kCenter, 
        NiPoint3& kExtents, int aiAxisOrder[3], 
        NiTPointerList<char*>* pkErrors = NULL);
    static void ApplyNodeTransformToABV(NiNode* pkNode,
        NiBoundingVolume* pkABV);
    static void ApplyTriShapeTransformToABV(NiNode* pkNode, 
        NiBoundingVolume* pkABV);
    static void ApplyNodeTransformToObject(NiNode* pkNode,
        NiAVObject* pkObject);

    static const char* SafeErrorName(const char* pcName);
    static void BuildError(NiTPointerList<char*>* pkErrors, const char* pcError, 
        const char* pcObjName );
    static void BuildUnionError(NiTPointerList<char*>* pkErrors, 
        const char* pcError, const char* pcUnionName, const char* pcObjName );
};

#endif  // #ifndef NIOPTIMIZEABV_H
