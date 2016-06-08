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
//  NiTStringTemplateMap inline functions

//---------------------------------------------------------------------------
template <class TVAL>  inline
NiTStringMap<TVAL>::NiTStringMap(unsigned int uiHashSize, bool bCopy) :
    NiTStringTemplateMap<NiTMap<const char*, TVAL>, TVAL>(uiHashSize, bCopy)
{
} 
//---------------------------------------------------------------------------
template <class TVAL>  inline
NiTStringPointerMap<TVAL>::NiTStringPointerMap(unsigned int uiHashSize, 
    bool bCopy) : NiTStringTemplateMap<
    NiTPointerMap<const char*, TVAL>, TVAL>(uiHashSize, bCopy)
{
} 
//---------------------------------------------------------------------------
template <class TPARENT, class TVAL>  inline
NiTStringTemplateMap<TPARENT,TVAL>::NiTStringTemplateMap(
    unsigned int uiHashSize, bool bCopy) :
    TPARENT(uiHashSize)
{
    m_bCopy = bCopy;
} 
//---------------------------------------------------------------------------
template <class TPARENT, class TVAL>  inline
NiTStringTemplateMap<TPARENT,TVAL>::~NiTStringTemplateMap()
{
    if (m_bCopy)
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++) 
        {
            NiTMapItem<const char*, TVAL>* pkItem = m_ppkHashTable[i];
            while (pkItem) 
            {
                NiTMapItem<const char*, TVAL>* pkSave = pkItem;
                pkItem = pkItem->m_pkNext;
                delete[] (char*) pkSave->m_key;
            }
        }
    }
}
//---------------------------------------------------------------------------
template <class TPARENT, class TVAL>  inline
unsigned int NiTStringTemplateMap<TPARENT,TVAL>::KeyToHashIndex (
    const char* pKey) const
{
    unsigned int uiHash = 0;

    while (*pKey)
        uiHash = (uiHash << 5) + uiHash + *pKey++;

    return uiHash % m_uiHashSize;
}
//---------------------------------------------------------------------------
template <class TPARENT, class TVAL>  inline
bool NiTStringTemplateMap<TPARENT,TVAL>::IsKeysEqual(const char* pcKey1,
    const char* pcKey2) const
{
    return strcmp(pcKey1, pcKey2) == 0;
}
//---------------------------------------------------------------------------
template <class TPARENT, class TVAL>  inline
void NiTStringTemplateMap<TPARENT,TVAL>::SetValue(
    NiTMapItem<const char*, TVAL>* pkItem, const char* pcKey, TVAL val)
{
    if (m_bCopy)
    {
        pkItem->m_key = new char[strlen(pcKey) + 1];
        assert(pkItem->m_key);
        strcpy((char*) pkItem->m_key, pcKey);
    }
    else
    {
        pkItem->m_key = pcKey;
    }
    pkItem->m_val = val;
}
//---------------------------------------------------------------------------
template <class TPARENT, class TVAL>  inline
void NiTStringTemplateMap<TPARENT,TVAL>::ClearValue(
    NiTMapItem<const char*, TVAL>* pkItem)
{
    if (m_bCopy)
    {
        delete[] (char*) pkItem->m_key;
    }
}
//---------------------------------------------------------------------------
