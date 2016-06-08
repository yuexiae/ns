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

#ifndef NILOGBEHAVIOR_H
#define NILOGBEHAVIOR_H
#include "NiSystemLibType.h"

#ifndef NI_LOGGER_DISABLE
class NISYSTEM_ENTRY NiLogBehavior
{
public:
    static void Set(NiLogBehavior* pkBehavior);
    static NiLogBehavior* Get();

    // override this to change log behavior
    virtual void Initialize();

private:
    static NiLogBehavior* ms_pkSingleton;
    static NiLogBehavior ms_kDefault;
};


class NISYSTEM_ENTRY NiMemoryLogBehavior : public NiLogBehavior
{
public:
    // override this to change log behavior
    virtual void Initialize();

    // used to set default behavior pre-main in NiMemory builds
    static NiMemoryLogBehavior ms_kMemoryDefault;
};

class NISYSTEM_ENTRY NiProfileLogBehavior : public NiLogBehavior
{
public:
    // override this to change log behavior
    virtual void Initialize();

    // used to set default behavior pre-main in NiProfile builds
    static NiProfileLogBehavior ms_kProfileDefault;
};

#endif // #ifndef NI_LOGGER_DISABLE

#endif // #ifndef NILOGBEHAVIOR_H
