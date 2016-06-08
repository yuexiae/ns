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
inline NiFloatController::NiFloatController (NiFloatData* pData)
    :
    m_spFloatData(pData)
{ 
    m_uiLastIdx = 0; 
}
//---------------------------------------------------------------------------
inline void NiFloatController::SetFloatData (NiFloatData* pData)
{
    m_spFloatData = pData;
}
//---------------------------------------------------------------------------
inline NiFloatData* NiFloatController::GetFloatData ()
{
    return m_spFloatData;
}
//---------------------------------------------------------------------------
