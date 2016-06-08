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
inline bool NiTextureAccumulator::RegisterObject (NiGeometry* pkObject)
{
    // will hit this if the app has not called UpdateProperties
    assert(pkObject->GetPropertyState());

    const NiAlphaProperty *pkAlpha = pkObject->GetPropertyState()->GetAlpha();
    // If alpha blended, then add to the list - otherwise,
    // add to texture hash table. 
    // Every property state should have a valid alpha property
    assert(pkAlpha);

    if (pkAlpha->GetAlphaBlending() && 
       !(m_bObserveNoSortHint && pkAlpha->GetNoSorter()) )
    {
        m_kItems.AddTail(pkObject);
    }
    else
    {
        InsertObject(pkObject);
    }

    return true;
}
//---------------------------------------------------------------------------
inline unsigned int NiTextureAccumulator::HashID(NiTexture* pkTex)
{
    return (unsigned int)pkTex % m_uiHashSlots;
}
//---------------------------------------------------------------------------
