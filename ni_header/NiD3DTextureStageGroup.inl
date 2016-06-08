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
// NiD3DTextureStageGroup inline functions
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
inline NiD3DTextureStageGroup::NiD3DTextureStageGroup() :
    m_bRendererOwned(false),
    m_uiNumSavedStages(0),
    m_uiSavedStageArrayIter(0),
    m_uiNumStages(0),
    m_uiStageArrayIter(0),
    m_uiNumSavedSamplers(0),
    m_uiSavedSamplerArrayIter(0),
    m_uiNumSamplers(0),
    m_uiSamplerArrayIter(0)
{
    memset(m_auiSavedStageArray, 0, sizeof(m_auiSavedStageArray));
    memset(m_abSavedStageValid, 0, sizeof(m_abSavedStageValid));
    memset(m_auiStageArray, 0, sizeof(m_auiStageArray));
    memset(m_abStageValid, 0, sizeof(m_abStageValid));
    memset(m_auiSavedSamplerArray, 0, sizeof(m_auiSavedSamplerArray));
    memset(m_abSavedSamplerValid, 0, sizeof(m_abSavedSamplerValid));
    memset(m_auiSamplerArray, 0, sizeof(m_auiSamplerArray));
    memset(m_abSamplerValid, 0, sizeof(m_abSamplerValid));
}
//---------------------------------------------------------------------------
