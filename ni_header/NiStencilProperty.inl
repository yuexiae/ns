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
//  NiStencilProperty inline functions

//---------------------------------------------------------------------------
inline NiStencilProperty::NiStencilProperty ()
{
    m_bEnable = false;
    m_eTest = TEST_GREATER;
    
    m_uiRef = 0;
    m_uiMask = 0xffffffff;

    m_eFailAct = ACTION_KEEP;
    m_eZFailAct = ACTION_KEEP;
    m_ePassAct = ACTION_INCREMENT;

    m_eDrawMode = DRAW_CCW_OR_BOTH;
}
//---------------------------------------------------------------------------
inline NiStencilProperty::~NiStencilProperty ()
{
    /* */
}
//---------------------------------------------------------------------------
inline void NiStencilProperty::SetStencilOn(NiBool bOn)
{
    m_bEnable = bOn;
}
//---------------------------------------------------------------------------
inline NiBool NiStencilProperty::GetStencilOn() const
{
    return m_bEnable;
}
//---------------------------------------------------------------------------
inline void NiStencilProperty::SetStencilFunction(TestFunc eFunc)
{
    m_eTest = eFunc;
}
//---------------------------------------------------------------------------
inline NiStencilProperty::TestFunc 
    NiStencilProperty::GetStencilFunction() const
{
    return m_eTest;
}
//---------------------------------------------------------------------------
inline void NiStencilProperty::SetStencilReference(unsigned int uiRef)
{
    m_uiRef = uiRef;
}
//---------------------------------------------------------------------------
inline unsigned int NiStencilProperty::GetStencilReference() const
{
    return m_uiRef;
}
//---------------------------------------------------------------------------
inline void NiStencilProperty::SetStencilMask(unsigned int uiMask)
{
    m_uiMask = uiMask;
}
//---------------------------------------------------------------------------
inline unsigned int NiStencilProperty::GetStencilMask() const
{
    return m_uiMask;
}
//---------------------------------------------------------------------------
inline void NiStencilProperty::SetStencilPassAction(Action eAct)
{
    m_ePassAct = eAct;
}
//---------------------------------------------------------------------------
inline NiStencilProperty::Action 
    NiStencilProperty::GetStencilPassAction() const
{
    return m_ePassAct;
}
//---------------------------------------------------------------------------
inline void NiStencilProperty::SetStencilPassZFailAction(Action eAct)
{
    m_eZFailAct = eAct;
}
//---------------------------------------------------------------------------
inline NiStencilProperty::Action 
    NiStencilProperty::GetStencilPassZFailAction() const
{
    return m_eZFailAct;
}
//---------------------------------------------------------------------------
inline void NiStencilProperty::SetStencilFailAction(Action eAct)
{
    m_eFailAct = eAct;
}
//---------------------------------------------------------------------------
inline NiStencilProperty::Action 
    NiStencilProperty::GetStencilFailAction() const
{
    return m_eFailAct;
}
//---------------------------------------------------------------------------
inline void NiStencilProperty::SetDrawMode(DrawMode eDraw)
{
    m_eDrawMode = eDraw;
}
//---------------------------------------------------------------------------
inline NiStencilProperty::DrawMode NiStencilProperty::GetDrawMode() const
{
    return m_eDrawMode;
}
//---------------------------------------------------------------------------
inline bool NiStencilProperty::IsEqualFast(
    const NiStencilProperty& prop) const
{
    if(m_bEnable || prop.m_bEnable)
        return false;
    else
        return true;
}
//---------------------------------------------------------------------------
inline int NiStencilProperty::Type () const
{
    return NiProperty::STENCIL;
}
//---------------------------------------------------------------------------
inline int NiStencilProperty::GetType ()
{
    return NiProperty::STENCIL;
}
//---------------------------------------------------------------------------
inline NiStencilProperty *NiStencilProperty::GetDefault ()
{
    return ms_spDefault;
}
//---------------------------------------------------------------------------

