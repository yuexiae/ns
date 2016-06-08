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

#ifndef NISTREAMMACROS_H
#define NISTREAMMACROS_H

class NiStream;

//---------------------------------------------------------------------------
// Macros for declaring and registering streams.
//---------------------------------------------------------------------------
// Insert in class declaration (note the start of public scope).  The
// routine IsEqual is for debugging purposes only.
#define NiDeclareAbstractStream \
    public: \
        virtual void LoadBinary(NiStream& kStream); \
        virtual void LinkObject(NiStream& kStream); \
        virtual bool RegisterStreamables(NiStream& kStream); \
        virtual void SaveBinary(NiStream& kStream); \
        virtual bool IsEqual(NiObject* pkObject)

#define NiDeclareStream \
    NiDeclareAbstractStream; \
        static NiObject* CreateObject()

// Call for each streamable class in libname##SDM::Init function.
#define NiRegisterStream(classname) \
    NiStream::RegisterLoader(#classname, classname::CreateObject)

// Call for each streamable class in libname##SDM::Shutdown function.
#define NiUnregisterStream(classname) \
    NiStream::UnregisterLoader(#classname)

#endif // NISTREAMMACROS_H
