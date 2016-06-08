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
//  NiLines inline functions

//---------------------------------------------------------------------------
inline NiBool* NiLines::GetFlags()
{
    NiLinesData* pkData = NiSmartPointerCast(NiLinesData, m_spModelData);
    return pkData->GetFlags();
}
//---------------------------------------------------------------------------
inline const NiBool* NiLines::GetFlags() const
{
    NiLinesData* pkData = NiSmartPointerCast(NiLinesData, m_spModelData);
    return pkData->GetFlags();
}
//---------------------------------------------------------------------------
