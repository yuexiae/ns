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

#ifndef NITSTRINGMAP_H
#define NITSTRINGMAP_H

#include "NiTMap.h"
#include "NiTPointerMap.h"

template <class TPARENT, class TVAL> class NiTStringTemplateMap :
    public TPARENT
{
public:
    // construction and destruction
    NiTStringTemplateMap(unsigned int uiHashSize = 37, bool bCopy = true);
    virtual ~NiTStringTemplateMap();

protected:
    virtual unsigned int KeyToHashIndex(const char* pcKey) const;
    virtual bool IsKeysEqual(const char* pcKey1, const char* pcKey2) const;
    virtual void SetValue(NiTMapItem<const char*, TVAL>* pkItem,
        const char* pcKey, TVAL val);
    virtual void ClearValue(NiTMapItem<const char*, TVAL>* pkItem);

    bool m_bCopy;
};

template <class TVAL> class NiTStringMap :
    public NiTStringTemplateMap<NiTMap<const char*, TVAL>, TVAL>
{
public:
    NiTStringMap(unsigned int uiHashSize = 37, bool bCopy = true);
};

template <class TVAL> class NiTStringPointerMap :
    public NiTStringTemplateMap<NiTPointerMap<const char*, TVAL>, TVAL>
{
public:
    NiTStringPointerMap(unsigned int uiHashSize = 37, bool bCopy = true);
};

#include "NiTStringMap.inl"


#endif // NITSTRINGMAP_H
