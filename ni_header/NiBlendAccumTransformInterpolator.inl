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
inline NiBlendAccumTransformInterpolator::AccumArrayItem::AccumArrayItem()
{
    ClearValues();
}
//---------------------------------------------------------------------------
inline void NiBlendAccumTransformInterpolator::AccumArrayItem::ClearValues()
{
    m_fLastTime = -NI_INFINITY;
    m_kLastValue.MakeInvalid();
    m_kDeltaValue.MakeInvalid();
    m_kRefFrame = NiMatrix3::IDENTITY;
}
//---------------------------------------------------------------------------
inline void NiBlendAccumTransformInterpolator::AccumArrayItem::LoadBinary(
    NiStream& kStream)
{
    m_kLastValue.LoadBinary(kStream);
    m_kDeltaValue.LoadBinary(kStream);
    m_kRefFrame.LoadBinary(kStream);
}
//---------------------------------------------------------------------------
inline void NiBlendAccumTransformInterpolator::AccumArrayItem::SaveBinary(
    NiStream& kStream)
{
    m_kLastValue.SaveBinary(kStream);
    m_kDeltaValue.SaveBinary(kStream);
    m_kRefFrame.SaveBinary(kStream);
}
//---------------------------------------------------------------------------
inline NiBlendAccumTransformInterpolator::NiBlendAccumTransformInterpolator(
    bool bManagerControlled, float fWeightThreshold, unsigned char ucArraySize)
    : NiBlendInterpolator(bManagerControlled,
    fWeightThreshold, ucArraySize), m_bReset(false), m_pkAccumArray(NULL)
{
    if (m_ucArraySize > 0)
    {
        // Allocate memory for array.
        m_pkAccumArray = new AccumArrayItem[m_ucArraySize];
    }
}
//---------------------------------------------------------------------------
inline NiBlendAccumTransformInterpolator::NiBlendAccumTransformInterpolator()
    : m_bReset(false), m_pkAccumArray(NULL)
{
}
//---------------------------------------------------------------------------
inline void NiBlendAccumTransformInterpolator::ClearAccumulatedTransform()
{
    if (m_ucInterpCount == 1)
    {
        NiQuatTransform kEmpty;
        m_kAccumulatedTransformValue = kEmpty;
    }
    else
    {
        m_kAccumulatedTransformValue.SetTranslate(NiPoint3::ZERO);
        m_kAccumulatedTransformValue.SetRotate(NiQuaternion::IDENTITY);
        m_kAccumulatedTransformValue.SetScale(1.0f);
    }
    m_bReset = true;
}
//---------------------------------------------------------------------------
inline void NiBlendAccumTransformInterpolator::SetAccumulatedTransform(
    const NiQuatTransform& kTransform)
{
    if (kTransform.IsTranslateValid())
    {
        m_kAccumulatedTransformValue.SetTranslate(kTransform.GetTranslate());
    }
    if (kTransform.IsRotateValid())
    {
        m_kAccumulatedTransformValue.SetRotate(kTransform.GetRotate());
    }
    if (kTransform.IsScaleValid())
    {
        m_kAccumulatedTransformValue.SetScale(kTransform.GetScale());
    }
    m_bReset = true;
}
//---------------------------------------------------------------------------
