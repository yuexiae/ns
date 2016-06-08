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

#include <NiNode.h>

//---------------------------------------------------------------------------
inline NiBoneLODController::NiBoneLODController() : m_iLOD(-1),
    m_uiNumLODs(0)
{
}
//---------------------------------------------------------------------------
inline NiBoneLODController::~NiBoneLODController()
{
    CleanUp();
}
//---------------------------------------------------------------------------
inline bool NiBoneLODController::TargetIsRequiredType() const
{
    return NiIsKindOf(NiNode, m_pTarget);
}
//---------------------------------------------------------------------------
inline void NiBoneLODController::Update(float fTime)
{
    if (ms_iGlobalLOD != -1 && ms_iGlobalLOD != m_iLOD)
    {
        int iNewLOD = ms_iGlobalLOD;
        if (ms_iGlobalLOD > (int) m_uiNumLODs)
            iNewLOD = m_uiNumLODs - 1;
            
        if (iNewLOD != m_iLOD)
            SetBoneLOD(iNewLOD);
    }
}
//---------------------------------------------------------------------------
inline int NiBoneLODController::GetBoneLOD() const
{
    return m_iLOD;
}
//---------------------------------------------------------------------------
inline unsigned int NiBoneLODController::GetNumberOfBoneLODs() const
{
    return m_uiNumLODs;
}
//---------------------------------------------------------------------------
inline void NiBoneLODController::SetGlobalLOD(int iLevel)
{
    ms_iGlobalLOD = iLevel;
}
//---------------------------------------------------------------------------
inline int NiBoneLODController::GetGlobalLOD() 
{
    return ms_iGlobalLOD;
}
//---------------------------------------------------------------------------
