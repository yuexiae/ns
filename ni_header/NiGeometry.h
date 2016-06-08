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

#ifndef NIGEOMETRY_H
#define NIGEOMETRY_H

#include "NiAVObject.h"
#include "NiDynamicEffectState.h"
#include "NiGeometryData.h"
#include "NiProcessor.h"
#include "NiPropertyState.h"
#include "NiRenderer.h"
#include "NiSkinInstance.h"

#if defined(WIN32) || defined(_XENON) || defined(_XBOX)
    #include "NiShader.h"
#endif  //#if defined(WIN32) || defined(_XENON) || defined(_XBOX)

class NiRenderer;

class NIMAIN_ENTRY NiGeometry : public NiAVObject
{
    NiDeclareRTTI;
    NiDeclareAbstractClone(NiGeometry);
    NiDeclareAbstractStream;
    NiDeclareViewerStrings;

public:
    virtual ~NiGeometry();

    // vertices
    unsigned short GetVertexCount() const;
    NiPoint3* GetVertices() const;
    void SetActiveVertexCount(unsigned short usActive);
    unsigned short GetActiveVertexCount() const;

    // normals
    void CreateNormals(bool bInitialize);
    NiPoint3* GetNormals() const;
    NiGeometryData::DataFlags GetNormalBinormalTangentMethod() const;
    void StoreNormalBinormalTangent(NiGeometryData::DataFlags eNBTMethod);

    // bounds
    void SetModelBound(const NiBound& kBound);
    NiBound& GetModelBound() const;

    // color access
    void CreateColors(bool bInitialize);
    NiColorA* GetColors() const;

    // texture coordinate access
    void CreateTextures(bool bInitialize, unsigned short usSets);
    unsigned short GetTextureSets() const;
    NiPoint2* GetTextures() const;
    NiPoint2* GetTextureSet(unsigned short usSet) const;
    void AppendTextureSet(NiPoint2* pkSet);

    // skinning
    NiSkinInstance* GetSkinInstance() const;
    void SetSkinInstance(NiSkinInstance* pkSkinInstance);

#if defined(WIN32) || defined(_XENON) || defined(_XBOX)
    // NiShader system
    NiShader* GetShader() const;
    void SetShader(NiShader* pkShader);
#endif  //#if defined(WIN32) || defined(_XENON) || defined(_XBOX)

    // *** begin NDL internal use only ***

    virtual void Display(NiCamera* pkCamera);
    virtual void RenderImmediate(NiRenderer* pkRenderer);

    // shared data access
    virtual void SetModelData(NiGeometryData* pkModelData);
    NiGeometryData* GetModelData() const;

    // State access
    NiPropertyStatePtr GetPropertyState() const;
    void SetPropertyState(NiPropertyState* pkState);
    virtual void UpdatePropertiesDownward(NiPropertyState* pkParentState);
    NiDynamicEffectStatePtr GetEffectState() const;
    void SetEffectState(NiDynamicEffectState* pkState);
    virtual void UpdateEffectsDownward(NiDynamicEffectState* pkParentState);

    // transforms
    virtual void ApplyTransform(const NiMatrix3& kMat, const NiPoint3& kTrn,
        bool bOnLeft);

    // updates
    virtual void CalculateNormals();

    // consistency
    virtual void CalculateConsistency(bool bTool = false);
    NiGeometryData::Consistency GetConsistency() const;
    void SetConsistency(NiGeometryData::Consistency eConsistency);

    // cloning
    virtual void ProcessClone(
        NiCloningProcess& kCloning);

    // post-link
    virtual void PostLinkObject(NiStream& kStream);

    // set selective update flags
    virtual void SetSelectiveUpdateFlags(bool& bSelectiveUpdate, 
        bool bSelectiveUpdateTransforms, bool& bRigid);

    // renderer data
    virtual void PurgeRendererData(NiRenderer* pkRenderer);

    // *** end NDL internal use only ***

protected:
    // construction (always uses a shared data object)
    NiGeometry(NiGeometryData* pkModelData);

    // streaming support
    NiGeometry();

    // updates
    virtual void UpdateWorldBound();

    // property and effect state caching
    NiPropertyStatePtr m_spPropertyState;
    NiDynamicEffectStatePtr m_spEffectState;

    // model data
    NiGeometryDataPtr m_spModelData;
    NiSkinInstancePtr m_spSkinInstance;

    unsigned int m_uiActiveCullingPlaneFlags;

#if defined(WIN32) || defined(_XENON) || defined(_XBOX)
    NiShaderPtr m_spShader;
#endif  //#if defined(WIN32) || defined(_XENON) || defined(_XBOX)
};

typedef NiPointer<NiGeometry> NiGeometryPtr;

#include "NiGeometry.inl"

#endif

