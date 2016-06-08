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

#ifndef NIANIMATIONKEYMACROS_H
#define NIANIMATIONKEYMACROS_H

// Insert in class declaration for NiFloatKey-derived classes.  Note the
// start of public scope.
#define NiDeclareAnimationStream \
    public: \
        static int RegisterLoader(); \
        static void RegisterSupportedFunctions(KeyContent eContent, \
            KeyType eType); \
    protected: \
        static NiAnimationKey* CreateFromStream(NiStream& stream, \
            unsigned int uiNumKeys); \
        void LoadBinary(NiStream& stream); \
        static void SaveToStream(NiStream& stream, NiAnimationKey* pkKeys, \
            unsigned int uiNumKeys); \
        static void SaveBinary(NiStream &stream, NiAnimationKey* pKey); \
        static void Copy(NiAnimationKey* pkNewKey, \
            const NiAnimationKey* pkOrigKey); \
        static NiAnimationKey* CreateArray(unsigned int uiNumKeys); \
        static void DeleteArray(NiAnimationKey* pkKeyArray); \
        static bool Insert(float fTime, NiAnimationKey*& pkKeys, \
            unsigned int& uiNumKeys); \
        static float ComputeMaxCurvature(NiAnimationKey* pkKeys, \
            unsigned int uiNumKeys); \
        static void Interpolate(float fTime, const NiAnimationKey* pKey0, \
            const NiAnimationKey* pKey1, void* pResult); \
        static void InterpolateD1(float fTime, const NiAnimationKey* pKey0, \
            const NiAnimationKey* pKey1, void* pResult); \
        static void InterpolateD2(float fTime, const NiAnimationKey* pKey0, \
            const NiAnimationKey* pKey1, void* pResult); \
        static bool Equal(const NiAnimationKey& key0, \
            const NiAnimationKey& key1); \
        static void FillDerivedVals(NiAnimationKey* pkKeys, \
            unsigned int uiNumKeys, unsigned char ucSize)

// Insert in header for class.
#define NiRegisterAnimationStream(classname) \
    static int classname##registerloaderreturn = classname::RegisterLoader()

// Insert in source for class.
#define NiImplementAnimationStream(classname,content,type) \
    int classname::RegisterLoader() \
    { \
        static bool bRegistered = false; \
        if(bRegistered) \
            return 0; \
        bRegistered = true; \
        SetCreateFunction(content, type, classname::CreateFromStream); \
        SetSaveFunction(content, type, classname::SaveToStream); \
        SetCopyFunction(content, type, classname::Copy); \
        SetArrayFunction(content, type, classname::CreateArray); \
        SetDeleteFunction(content, type, classname::DeleteArray); \
        SetKeySize(content, type, sizeof(classname)); \
        RegisterSupportedFunctions(content, type); \
        return 1; \
    }

#endif
