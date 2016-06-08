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
//---------------------------------------------------------------------------
//  NiTextureEffect inline functions

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
inline NiTextureEffect::EffectType NiTextureEffect::GetEffectType() const
{
    return TEXTURE_EFFECT;
}
//---------------------------------------------------------------------------
inline const NiMatrix3& NiTextureEffect::GetModelProjectionMatrix() const
{
    return m_kModelProjMat;
}
//---------------------------------------------------------------------------
inline void NiTextureEffect::SetModelProjectionMatrix(const NiMatrix3& kMat)
{
    m_kModelProjMat = kMat;
}
//---------------------------------------------------------------------------
inline const NiPoint3& NiTextureEffect::GetModelProjectionTranslation() const
{
    return m_kModelProjTrans;
}
//---------------------------------------------------------------------------
inline void 
NiTextureEffect::SetModelProjectionTranslation(const NiPoint3& kTrans)
{
    m_kModelProjTrans = kTrans;
}
//---------------------------------------------------------------------------
inline const NiMatrix3& NiTextureEffect::GetWorldProjectionMatrix() const
{
    return m_kWorldProjMat;
}
//---------------------------------------------------------------------------
inline const NiPoint3& NiTextureEffect::GetWorldProjectionTranslation() const
{
    return m_kWorldProjTrans;
}
//---------------------------------------------------------------------------
inline NiTexture* NiTextureEffect::GetEffectTexture() const
{
    return m_spTexture;
}
//---------------------------------------------------------------------------
inline void NiTextureEffect::SetEffectTexture(NiTexture* pkTexture)
{
    m_spTexture = pkTexture;
}
//---------------------------------------------------------------------------
inline NiTexturingProperty::FilterMode 
    NiTextureEffect::GetTextureFilter() const
{
    return m_eFilter;
}
//---------------------------------------------------------------------------
inline void 
    NiTextureEffect::SetTextureFilter(NiTexturingProperty::FilterMode eFilter)
{
    m_eFilter = eFilter;
}
//---------------------------------------------------------------------------
inline void NiTextureEffect::SetL(short sL)
{
    m_sL = sL;
}
//---------------------------------------------------------------------------
inline short NiTextureEffect::GetL() const
{
    return m_sL;
}
//---------------------------------------------------------------------------
inline void NiTextureEffect::SetK(short sK)
{
    m_sK = sK;
}
//---------------------------------------------------------------------------
inline short NiTextureEffect::GetK() const
{
    return m_sK;
}
//---------------------------------------------------------------------------
inline NiTexturingProperty::ClampMode 
    NiTextureEffect::GetTextureClamp() const
{
    return m_eClamp;
}
//---------------------------------------------------------------------------
inline void 
    NiTextureEffect::SetTextureClamp(NiTexturingProperty::ClampMode eClamp)
{
    m_eClamp = eClamp;
}
//---------------------------------------------------------------------------
inline NiTextureEffect::TextureType NiTextureEffect::GetTextureType() const
{
    return m_eTextureMode;
}
//---------------------------------------------------------------------------
inline void NiTextureEffect::SetTextureType(TextureType eTexType)
{
    m_eTextureMode = eTexType;
}
//---------------------------------------------------------------------------
inline NiTextureEffect::CoordGenType 
NiTextureEffect::GetTextureCoordGen() const
{
    return m_eCoordMode;
}
//---------------------------------------------------------------------------
inline void NiTextureEffect::SetTextureCoordGen(CoordGenType eGen)
{
    m_eCoordMode = eGen;

    // Texture coordinate generation may change the way the world projection
    // matrix is computed internally, so we must update it
    UpdateProjection();
}
//---------------------------------------------------------------------------
inline bool NiTextureEffect::GetClippingPlaneEnable() const
{
    return m_bPlaneEnable;
}
//---------------------------------------------------------------------------
inline void NiTextureEffect::SetClippingPlaneEnable(bool bEnable)
{
    m_bPlaneEnable = bEnable;
}
//---------------------------------------------------------------------------
inline const NiPlane& NiTextureEffect::GetModelClippingPlane() const
{
    return m_kModelPlane;    
}
//---------------------------------------------------------------------------
inline void NiTextureEffect::SetModelClippingPlane(const NiPlane& kPlane)
{
    m_kModelPlane = kPlane;    

    UpdateProjection();
}
//---------------------------------------------------------------------------
inline const NiPlane& NiTextureEffect::GetWorldClippingPlane() const
{
    return m_kWorldPlane;    
}
//---------------------------------------------------------------------------
