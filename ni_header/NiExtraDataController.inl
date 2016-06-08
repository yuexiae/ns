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

#include <NiObjectNET.h>

//---------------------------------------------------------------------------
inline const char* NiExtraDataController::GetExtraDataName()
{
    return m_pcExtraDataName;
}
//---------------------------------------------------------------------------
inline NiExtraData* NiExtraDataController::GetExtraDataPointer()
{
    return m_spExtraData;
}
//---------------------------------------------------------------------------
inline void NiExtraDataController::GetExtraDataPointerFromName()
{
    assert(m_pTarget && m_pcExtraDataName);
    m_spExtraData = m_pTarget->GetExtraData(m_pcExtraDataName);
    assert(m_spExtraData);
}
//---------------------------------------------------------------------------
inline void NiExtraDataController::SetExtraDataName(const char* pcName)
{
    assert(pcName);
    delete[] m_pcExtraDataName;
    m_pcExtraDataName = new char[strlen(pcName) + 1];
    strcpy(m_pcExtraDataName, pcName);
}
//---------------------------------------------------------------------------
