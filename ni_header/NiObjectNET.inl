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
inline void NiObjectNET::SetDefaultCopyType(CopyType eCopyType)
{
    ms_eCopyType = eCopyType;
}
//---------------------------------------------------------------------------
inline NiObjectNET::CopyType NiObjectNET::GetDefaultCopyType()
{
    return ms_eCopyType;
}
//---------------------------------------------------------------------------
inline void NiObjectNET::SetDefaultAppendCharacter(char cAppendCharacter)
{
    ms_cAppendCharacter = cAppendCharacter;
}
//---------------------------------------------------------------------------
inline char NiObjectNET::GetDefaultAppendCharacter()
{
    return ms_cAppendCharacter;
}
//---------------------------------------------------------------------------
inline unsigned int NiObjectNET::GetExtraDataSize() const
{
    return m_uiExtraDataSize;
}
//---------------------------------------------------------------------------
inline NiExtraData* NiObjectNET::GetExtraDataAt(unsigned int uiExtraDataIndex)
    const
{
    assert(uiExtraDataIndex < m_uiExtraDataSize);

    return m_ppkExtra[uiExtraDataIndex];
}
//---------------------------------------------------------------------------
inline const char* NiObjectNET::GetName() const
{
    return m_pcName;
}
//---------------------------------------------------------------------------
inline NiTimeController* NiObjectNET::GetControllers () const
{
    return m_spControllers;
}
//---------------------------------------------------------------------------
#define NiGetController(classname, pkObjectNET) \
    ((classname*) pkObjectNET->GetController(&classname::m_RTTI))
//---------------------------------------------------------------------------
