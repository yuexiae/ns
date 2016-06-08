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
// NSBImplementation inline functions
//---------------------------------------------------------------------------
inline const char* NSBImplementation::GetName()
{
    return m_pszName;
}
//---------------------------------------------------------------------------
inline const char* NSBImplementation::GetDesc()
{
    return m_pszDesc;
}
//---------------------------------------------------------------------------
inline const char* NSBImplementation::GetClassName()
{
    return m_pszClassName;
}
//---------------------------------------------------------------------------
inline const char* NSBImplementation::GetPackingDef()
{
    return m_pszPackingDef;
}
//---------------------------------------------------------------------------
inline unsigned int NSBImplementation::GetIndex()
{
    return m_uiIndex;
}
//---------------------------------------------------------------------------
inline void NSBImplementation::SetIndex(unsigned int uiIndex)
{
    m_uiIndex = uiIndex;
}
//---------------------------------------------------------------------------
inline NSBUserDefinedDataSet* NSBImplementation::GetUserDefinedDataSet()
{
    return m_spUserDefinedDataSet;
}
//---------------------------------------------------------------------------
inline void NSBImplementation::SetUserDefinedDataSet(
    NSBUserDefinedDataSet* pkUDDSet)
{
    m_spUserDefinedDataSet = pkUDDSet;
}
//---------------------------------------------------------------------------
inline void NSBImplementation::SetSoftwareVP(bool bSoftwareVP)
{
    m_bSoftwareVP = bSoftwareVP;
}
//---------------------------------------------------------------------------
inline bool NSBImplementation::GetSoftwareVP() const
{
    return m_bSoftwareVP;
}
//---------------------------------------------------------------------------
