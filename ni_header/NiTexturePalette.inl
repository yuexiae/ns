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
inline NiDefaultTexturePalette::NiDefaultTexturePalette(
    bool bSearchGlobalTextureList)
{
    m_bSearchGlobalTextureList = bSearchGlobalTextureList;
}
//---------------------------------------------------------------------------
inline NiTexture* NiDefaultTexturePalette::GetTexture(const char* pcPath,
    NiTexture* pkSelf = NULL) const
{
    NiTexturePtr spTex = NULL;
    if (m_kHash.GetAt(pcPath, spTex))
    {
        return spTex;
    }
    else if (m_bSearchGlobalTextureList)
    {
        NiTexture::LockTextureList();
        NiTexture* pkTexture = NiTexture::GetListHead();
        while (pkTexture != NULL)
        {
            if (pkTexture != pkSelf && NiIsKindOf(NiSourceTexture, pkTexture))
            {
                NiSourceTexture* pkSrcTexture = (NiSourceTexture*) pkTexture;
                const char* pcFilename = pkSrcTexture->GetFilename();
                if(pcFilename && NiStricmp(pcFilename, pcPath) == 0)
                {
                    NiTexture::UnlockTextureList();
                    return pkSrcTexture;
                }
            }
            pkTexture = pkTexture->GetListNext();
        }
        NiTexture::UnlockTextureList();
    }

    return NULL;
}
//---------------------------------------------------------------------------
inline void NiDefaultTexturePalette::SetTexture(const char* pcPath, 
    NiTexture* pkTex)
{
    m_kHash.SetAt(pcPath, pkTex);
}
//---------------------------------------------------------------------------
inline void NiDefaultTexturePalette::SetSearchGlobalTextureList(bool bSearch)
{
    m_bSearchGlobalTextureList = bSearch;
}
//---------------------------------------------------------------------------
inline bool NiDefaultTexturePalette::GetSearchGlobalTextureList() const
{
    return m_bSearchGlobalTextureList;
}
//---------------------------------------------------------------------------
