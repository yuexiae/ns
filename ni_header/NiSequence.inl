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
inline const char* NiSequence::GetName() const
{
    return m_pcName;
}
//---------------------------------------------------------------------------
inline unsigned int NiSequence::GetCount() const
{
    return m_kObjectName.GetSize();
}
//---------------------------------------------------------------------------
inline const char* NiSequence::GetObjectName(unsigned int uiIndex)
{
    return m_kObjectName.GetAt(uiIndex);
}
//---------------------------------------------------------------------------
inline NiTransformController* NiSequence::GetController(unsigned int uiIndex)
{
    return m_kCtrl.GetAt(uiIndex);
}
//---------------------------------------------------------------------------
inline NiTextKeyExtraData* NiSequence::GetTextKeys() const
{
    return m_spTextKeys;
}
//---------------------------------------------------------------------------
inline void NiSequence::SetName(const char* pcName)
{
    delete[] m_pcName;
    m_pcName = NULL;
    if (pcName)
    {
        m_pcName = new char[strlen(pcName) + 1];
        strcpy(m_pcName, pcName);
    }
}
//---------------------------------------------------------------------------
inline void NiSequence::SetTextKeyReference(unsigned int uiReference)
{
    m_uiTextKeyReference = uiReference;
}
//---------------------------------------------------------------------------
inline void NiSequence::SetTextKeys(NiTextKeyExtraData* pkData)
{
    m_spTextKeys = pkData;
}
//---------------------------------------------------------------------------
