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
inline int NiFloatsExtraDataController::GetFloatsExtraDataIndex() const
{
    return m_iFloatsExtraDataIndex;
}
//---------------------------------------------------------------------------
inline void NiFloatsExtraDataController::SetFloatsExtraDataIndex(
    int iFloatsExtraDataIndex)
{
    m_iFloatsExtraDataIndex = iFloatsExtraDataIndex;
    delete [] m_pcCtlrID;
    m_pcCtlrID = NULL;
}
//---------------------------------------------------------------------------
