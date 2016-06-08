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

#ifndef NITEXTURETRANSFORM_H
#define NITEXTURETRANSFORM_H

#include "NiMatrix3.h"
#include "NiPoint2.h"

class NIMAIN_ENTRY NiTextureTransform
{
public:
    enum TransformMethod
    {
        MAYA_TRANSFORM = 0,
        MAX_TRANSFORM
    };

    NiTextureTransform();
    NiTextureTransform(const NiPoint2& kTranslate, float fRotate,
        const NiPoint2& kScale, const NiPoint2& kCenter, 
        TransformMethod eMethod);

    // Return the 3x3 Matrix representation of this transform. This is 
    // for the renderers so they won't need to construct the matrix for
    // every object every frame.
    const NiMatrix3* GetMatrix() const;

    // Convert this transform into an equivelent identity transform.
    void MakeIdentity();

    // UV translation
    NiPoint2 GetTranslate() const;
    void SetTranslate(const NiPoint2& kTranslate);

    // W axis rotation in texture space
    float GetRotate() const;
    void SetRotate(float fRotate);

    // UV Scale
    NiPoint2 GetScale() const;
    void SetScale(const NiPoint2& kScale);

    // Depending on the originating you expect to scale before the 
    // rotation or after the rotation. 3DS Max Scales first while Maya 
    // scales after.
    TransformMethod GetTransformMethod() const;
    void SetTransformMethod(TransformMethod eMethod);

    // The Center point defines where the texture rotates around
    NiPoint2 GetCenter() const;
    void SetCenter(const NiPoint2& kCenter);

    bool operator==(const NiTextureTransform &xform) const;
    bool operator!=(const NiTextureTransform &xform) const;

    static const NiTextureTransform IDENTITY;

    // *** begin NDL internal use only ***

    // streaming
    void LoadBinary(NiStream& stream);
    void SaveBinary(NiStream& stream);

    // *** end NDL internal use only ***

protected:

    NiPoint2 m_kTranslate;
    float m_fRotate;
    NiPoint2 m_kScale;
    NiPoint2 m_kCenter;

    // Cached matrix for the renderers. So building the Matrix only needs
    // to happen once and not every object every frame.
    mutable bool m_bMatrixDirty;
    mutable NiMatrix3 m_kMatrix;

    // Depending on the originating you expect to scale before the 
    // rotation or after the rotation. 3DS Max Scales first while Maya 
    // scales after.
    TransformMethod m_eMethod;

    // Rebuild the Cached matrix.  This can be called on a const instance
    // because it will need to be called when the renderers use it.  
    void UpdateMatrix() const;
};


#include "NiTextureTransform.inl"

#endif // NITEXTURETRANSFORM_H
