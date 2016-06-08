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
//  NiBillboardNode inline functions

//---------------------------------------------------------------------------
inline NiBillboardNode::NiBillboardNode()
{
    m_uFlags = 0;
    SetMode(ROTATE_ABOUT_UP);
    m_fSavedTime = 0.0f;
    m_bUpdateControllers = true;
}
//---------------------------------------------------------------------------
inline void NiBillboardNode::SetMode(FaceMode eMode)
{
    SetField(eMode, FACE_MODE_MASK, FACE_MODE_POS);
}
//---------------------------------------------------------------------------
inline NiBillboardNode::FaceMode NiBillboardNode::GetMode() const
{
    return (FaceMode) GetField(FACE_MODE_MASK, FACE_MODE_POS);
}
//---------------------------------------------------------------------------
