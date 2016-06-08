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

#ifndef NIQUATTRANSFORM_H
#define NIQUATTRANSFORM_H

#include "NiAnimationLibType.h"
#include <NiPoint3.h>
#include <NiQuaternion.h>
#include "NiFlags.h"

class NiStream;

class NIANIMATION_ENTRY NiQuatTransform
{
public:
    NiQuatTransform();
    NiQuatTransform(const NiPoint3& kTranslate, const NiQuaternion& kRotate,
        float fScale);

    const NiPoint3& GetTranslate() const;
    void SetTranslate(const NiPoint3& kTranslate);

    const NiQuaternion& GetRotate() const;
    void SetRotate(const NiQuaternion& kRotate);

    // This SetRotate function converts the NiMatrix3 to an NiQuaternion
    // before storing the value. It is provided as a convenience function.
    void SetRotate(const NiMatrix3& kRotate);

    float GetScale() const;
    void SetScale(float fScale);

    bool IsTranslateValid() const;
    bool IsRotateValid() const;
    bool IsScaleValid() const;
    bool IsTransformInvalid() const;

    bool operator==(const NiQuatTransform& kTransform) const;
    bool operator!=(const NiQuatTransform& kTransform) const;
    NiQuatTransform operator*(const NiQuatTransform& kTransform) const;

    void Invert(NiQuatTransform& kDest) const;
    
    void HierInvert(NiQuatTransform& kDest) const;
    NiQuatTransform HierApply(const NiQuatTransform& kTransform) const;

    void MakeInvalid();

    // *** begin NDL internal use only ***
    void LoadBinary(NiStream& kStream);
    void SaveBinary(NiStream& kStream);
    void GetViewerStrings(NiTArray<char*>* pkStrings);
    // *** end NDL internal use only ***

protected:
    NiPoint3 m_kTranslate;
    NiQuaternion m_kRotate;
    float m_fScale;

    void SetTranslateValid(bool bValid);
    void SetRotateValid(bool bValid);
    void SetScaleValid(bool bValid);

    static const NiPoint3 INVALID_TRANSLATE;
    static const NiQuaternion INVALID_ROTATE;
    static const float INVALID_SCALE;
};

#include "NiQuatTransform.inl"

#endif   // #ifndef NIQUATTRANSFORM_H
