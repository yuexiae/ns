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
//  NiZBufferProperty inline functions

//---------------------------------------------------------------------------
inline NiZBufferProperty::NiZBufferProperty()
{
    m_uFlags = 0;
    SetZBufferTest(true);
    SetZBufferWrite(true);
    SetTestFunction(TEST_LESSEQUAL);
}
//---------------------------------------------------------------------------
inline void NiZBufferProperty::SetZBufferTest(bool bZBufferTest)
{
    SetBit(bZBufferTest, ZBUFFERTEST_MASK);
}
//---------------------------------------------------------------------------
inline bool NiZBufferProperty::GetZBufferTest() const
{
    return GetBit(ZBUFFERTEST_MASK);
}
//---------------------------------------------------------------------------
inline void NiZBufferProperty::SetZBufferWrite(bool bZBufferWrite)
{
    SetBit(bZBufferWrite, ZBUFFERWRITE_MASK);
}
//---------------------------------------------------------------------------
inline bool NiZBufferProperty::GetZBufferWrite() const
{
    return GetBit(ZBUFFERWRITE_MASK);
}
//---------------------------------------------------------------------------
inline void NiZBufferProperty::SetTestFunction(TestFunction eTest)
{
    m_eTest = eTest;
}
//---------------------------------------------------------------------------
inline NiZBufferProperty::TestFunction NiZBufferProperty::GetTestFunction() 
    const
{
    return m_eTest;
}
//---------------------------------------------------------------------------
inline bool NiZBufferProperty::IsEqualFast(const NiZBufferProperty& kProp) 
    const
{
    return m_uFlags == kProp.m_uFlags && m_eTest == kProp.m_eTest;
}
//---------------------------------------------------------------------------
inline int NiZBufferProperty::Type() const
{
    return NiProperty::ZBUFFER;
}
//---------------------------------------------------------------------------
inline int NiZBufferProperty::GetType()
{
    return NiProperty::ZBUFFER;
}
//---------------------------------------------------------------------------
inline NiZBufferProperty* NiZBufferProperty::GetDefault()
{
    return ms_spDefault;
}
//---------------------------------------------------------------------------
