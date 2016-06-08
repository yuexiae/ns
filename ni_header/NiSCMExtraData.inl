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
//  NiSCMExtraData inline functions

//---------------------------------------------------------------------------
inline void NiSCMExtraData::AddEntry(
    unsigned int uiConstantIndex, unsigned int uiPass,
    NiSCMExtraData::ShaderProgramType eType, NiExtraData* pkExtraData,
    bool bGlobal)
{
    assert(m_auiCurrentEntry[eType] < m_auiNumEntries[eType]);
    // Set pass to 255 if bGlobal is true since it is highly unlikely any
    // shader will have 255 passes.
    if (bGlobal)
        uiPass = 255;
    unsigned int uiIndex = uiConstantIndex | uiPass << m_uiPassShift;

    m_apkEntries[eType][m_auiCurrentEntry[eType]].m_uiIndex = uiIndex;
  	m_apkEntries[eType][m_auiCurrentEntry[eType]++].m_pkExtraData = pkExtraData;
}
//---------------------------------------------------------------------------
inline NiExtraData* NiSCMExtraData::GetNextEntry(
    unsigned int uiConstantIndex, unsigned int uiPass,
    NiSCMExtraData::ShaderProgramType eType, bool bGlobal)
{
 	assert(m_auiCurrentEntry[eType] < m_auiNumEntries[eType]);
    unsigned int uiIndex = uiConstantIndex | uiPass << m_uiPassShift;

    // Make sure the indicies match as a simple error check.
	if (m_apkEntries[eType][m_auiCurrentEntry[eType]].m_uiIndex == uiIndex)
		return m_apkEntries[eType][m_auiCurrentEntry[eType]++].m_pkExtraData;
	   
    return 0;
}
//---------------------------------------------------------------------------
inline void NiSCMExtraData::Reset()
{
    // Reset the walk through the list.
    m_auiCurrentEntry[VERTEX] = 0;
    m_auiCurrentEntry[PIXEL] = 0;
}
//---------------------------------------------------------------------------