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

#ifndef NITEXTUREEFFECT_H
#define NITEXTUREEFFECT_H

#include "NiTexture.h"
#include "NiDynamicEffect.h"
#include "NiPlane.h"
#include "NiTexturingProperty.h"

class NIMAIN_ENTRY NiTextureEffect : public NiDynamicEffect 
{
    NiDeclareRTTI;
    NiDeclareClone(NiTextureEffect);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    typedef enum 
    { 
        PROJECTED_LIGHT, 
        PROJECTED_SHADOW,
        ENVIRONMENT_MAP, 
        FOG_MAP 
    } TextureType;

    typedef enum
    {
        WORLD_PARALLEL,
        WORLD_PERSPECTIVE,
        SPHERE_MAP,
        SPECULAR_CUBE_MAP,
        DIFFUSE_CUBE_MAP,
        NUM_COORD_GEN
    } CoordGenType;

    NiTextureEffect();
    virtual ~NiTextureEffect();

    // attributes
    virtual EffectType GetEffectType() const;
    
    const NiMatrix3& GetModelProjectionMatrix() const;
    void SetModelProjectionMatrix(const NiMatrix3& kMat);

    const NiPoint3& GetModelProjectionTranslation() const;
    void SetModelProjectionTranslation(const NiPoint3& kMat);

    const NiMatrix3& GetWorldProjectionMatrix() const;
    const NiPoint3& GetWorldProjectionTranslation() const;

    NiTexture* GetEffectTexture() const; 
    void SetEffectTexture(NiTexture* pkTexture); 

    NiTexturingProperty::FilterMode GetTextureFilter() const;
    void SetTextureFilter(NiTexturingProperty::FilterMode eFilter);

    // PS2 ONLY: mip-map LOD selection parameters
    void SetL(short sL);
    short GetL() const;   
    void SetK(short sK);
    short GetK() const;   

    NiTexturingProperty::ClampMode GetTextureClamp() const;
    void SetTextureClamp(NiTexturingProperty::ClampMode eClamp);

    TextureType GetTextureType() const;
    void SetTextureType(TextureType eTexType);

    CoordGenType GetTextureCoordGen() const;
    void SetTextureCoordGen(CoordGenType eGen);

    bool GetClippingPlaneEnable() const;
    void SetClippingPlaneEnable(bool bEnable);

    const NiPlane& GetModelClippingPlane() const;
    void SetModelClippingPlane(const NiPlane& kPlane);

    const NiPlane& GetWorldClippingPlane() const;

    // *** begin NDL internal use only ***

    // streaming support
    static char* GetViewerString(const char* pcPrefix, TextureType eMode);
    static char* GetViewerString(const char* pcPrefix, CoordGenType eMode);

    // *** end NDL internal use only ***
protected:
    virtual void UpdateWorldData();

    void UpdateProjection();

    // Assembly code (in PS2 renderer) assumes that m_kWorldProjTrans
    // immediately follows m_kWorldProjMat, so don't change the order.
    NiMatrix3 m_kModelProjMat;
    NiPoint3 m_kModelProjTrans;
    NiMatrix3 m_kWorldProjMat;
    NiPoint3 m_kWorldProjTrans;

    NiTexturePtr m_spTexture; 
    NiTexturingProperty::FilterMode m_eFilter;
    NiTexturingProperty::ClampMode m_eClamp;
    TextureType m_eTextureMode;
    CoordGenType m_eCoordMode;

    bool m_bPlaneEnable;
    NiPlane m_kModelPlane;
    NiPlane m_kWorldPlane;

    short m_sL;
    short m_sK;
};
   

typedef NiPointer<NiTextureEffect> NiTextureEffectPtr;

#include "NiTextureEffect.inl"

#endif // NITEXTUREEFFECT_H