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
// NSBUserDefinedData inline functions
//---------------------------------------------------------------------------
inline NSBUserDefinedDataBlock::NSBUserDefinedDataBlock(const char* pacName): 
    NSBConstantMap(),
    m_pacName(0)
{
    SetName(pacName);
}
//---------------------------------------------------------------------------
inline NSBUserDefinedDataBlock::~NSBUserDefinedDataBlock()
{
    delete [] m_pacName;
}
//---------------------------------------------------------------------------
inline const char* NSBUserDefinedDataBlock::GetName() const
{
    return m_pacName;
}
//---------------------------------------------------------------------------
inline void NSBUserDefinedDataBlock::SetName(const char* pacName)
{
    NiD3DUtility::SetString(m_pacName, pacName);
}
//---------------------------------------------------------------------------
