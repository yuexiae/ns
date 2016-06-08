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
// NiActionMap inline functions
//---------------------------------------------------------------------------
inline const char* NiActionMap::GetName() const
{
    return m_pcName;
}
//---------------------------------------------------------------------------
inline const void* NiActionMap::GetPlatformSpecificData() const
{
    return m_pvPlatformSpecificData;
}
//---------------------------------------------------------------------------
inline const unsigned int NiActionMap::GetActionCount() const
{
    return m_akActions.GetEffectiveSize();
}
//---------------------------------------------------------------------------
inline const NiAction* NiActionMap::GetAction(unsigned int uiIndex) const
{
    if (uiIndex > m_akActions.GetSize())
        return 0;

    return m_akActions.GetAt(uiIndex);
}
//---------------------------------------------------------------------------
inline NiAction* NiActionMap::GetActionFromPool()
{
    if (!ms_pakActionPool)
        CreateActionPool();

    assert(ms_pakActionPool);
    
    return ms_pakActionPool->GetFreeObject();
}
//---------------------------------------------------------------------------
inline void NiActionMap::ReturnActionToPool(NiAction* pkAction)
{
    assert(ms_pakActionPool);
    ms_pakActionPool->ReleaseObject(pkAction);
}
//---------------------------------------------------------------------------
