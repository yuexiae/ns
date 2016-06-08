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

#ifndef NITEXTKEYEXTRADATA_H
#define NITEXTKEYEXTRADATA_H

#include "NiExtraData.h"
#include "NiTextKey.h"

NiSmartPointer(NiTextKeyExtraData);

class NIANIMATION_ENTRY NiTextKeyExtraData : public NiExtraData
{
    NiDeclareRTTI;
    NiDeclareClone(NiTextKeyExtraData);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    NiTextKeyExtraData ();
    NiTextKeyExtraData (NiTextKey* pKeys, unsigned int uiNumKeys);
    virtual ~NiTextKeyExtraData ();

    void SetKeys (NiTextKey* pKeys, unsigned int uiNumKeys);
    NiTextKey* GetKeys (unsigned int& uiNumKeys) const;

protected:
    unsigned int m_uiNumKeys;
    NiTextKey* m_pKeys;
};

#include "NiTextKeyExtraData.inl"

#endif
