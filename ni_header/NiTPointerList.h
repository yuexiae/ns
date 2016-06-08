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

#ifndef NITPOINTERLIST_H
#define NITPOINTERLIST_H

#include "NiMainLibType.h"
#include "NiRTLib.h"

#include "NiTPointerListBase.h"
#include "NiTPointerAllocator.h"

template <class T> class NiTPointerList : public
    NiTPointerListBase<NiTPointerAllocator<unsigned int>, T>{};

#endif // NITPOINTERLIST_H
