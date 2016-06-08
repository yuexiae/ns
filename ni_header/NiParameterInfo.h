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

#ifndef NIPARAMETERINFO_H
#define NIPARAMETERINFO_H

#include "NiPluginToolkitLibType.h"
#include "NiString.h"

/// The container of key/value parameter pairs.
class NIPLUGINTOOLKIT_ENTRY NiParameterInfo : public NiRefObject
{
public:
    /// The constructor takes the key and value to store.
    NiParameterInfo();

    /// Gets the key string.
    const NiString& GetKey() const;
    
    /// Gets the value string.
    const NiString& GetValue() const;

    /// Set the key string
    void SetKey(const char* pcKey);

    /// Set the value string
    void SetValue(const char* pcValue);

protected:
    /// The key string.
    NiString m_strKey;
    
    /// The value string.
    NiString m_strValue;
};

NiSmartPointer(NiParameterInfo);

#endif  // #ifndef NIPARAMETERINFO_H
