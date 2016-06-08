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
//  NiMultiTextureProperty inline functions

//---------------------------------------------------------------------------
inline const NiRendererSpecificProperty::RendererData* 
    NiRendererSpecificProperty::GetRendererData(
    unsigned int uiRendererTypeID) const
{
    if (!m_pkRendererData || 
        (m_pkRendererData->GetRendererTypeID() != uiRendererTypeID))
    {
        return NULL;
    }
    else
    {
        return m_pkRendererData;
    }
}
//---------------------------------------------------------------------------
inline NiRendererSpecificProperty::RendererData* 
    NiRendererSpecificProperty::GetRendererData(
    unsigned int uiRendererTypeID)
{
    if (!m_pkRendererData || 
        (m_pkRendererData->GetRendererTypeID() != uiRendererTypeID))
    {
        return NULL;
    }
    else
    {
        return m_pkRendererData;
    }
}
//---------------------------------------------------------------------------
inline void NiRendererSpecificProperty::SetRendererData(RendererData* pkData)
{
    if (pkData != m_pkRendererData)
    {
        delete m_pkRendererData;

        m_pkRendererData = pkData;
    }
}
//---------------------------------------------------------------------------
inline int NiRendererSpecificProperty::Type () const
{ 
    return NiProperty::REND_SPEC; 
}
//---------------------------------------------------------------------------
inline int NiRendererSpecificProperty::GetType ()
{
    return NiProperty::REND_SPEC;
}
//---------------------------------------------------------------------------
inline NiRendererSpecificProperty *NiRendererSpecificProperty::GetDefault ()
{
    return ms_spDefault;
}
//---------------------------------------------------------------------------
inline bool NiRendererSpecificProperty::IsEqualFast (
    const NiRendererSpecificProperty& kProp) const
{
    // For now, return that any two distinct properties are different.
    return this == &kProp;
}
//---------------------------------------------------------------------------
