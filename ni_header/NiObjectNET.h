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

#ifndef NIOBJECTNET_H
#define NIOBJECTNET_H

// This class adds (N)ames, (E)xtra Data, and (T)ime controllers to
// NiObject.
//
// WARNING. Be aware of calls to RemoveExtraData(pExtra) deleting the
// object to which pExtra points. This happens when pExtra is only
// referenced by the internal extra data list. For example the deletion
// occurs in the code
//
//    const char* pcKey = <some string>;
//    NiNode* pkNode = <some node>;
//    NiMyExtraData* pkExtra = new NiMyExtraData; // refs = 0
//    pkNode->AddExtraData(pcKey, pkExtra);       // refs = 1
//    pkNode->RemoveExtraData(pcKey);             // refs = 0, deletion occurs
//    <pkExtra is now a dangling pointer>
//
// To make sure you can still use the extra data after removal, do
//
//    const char* pcKey = <some string>;
//    NiNode* pkNode = <some node>;
//    NiMyExtraDataPtr spkExtra = new NiMyExtraData;   // refs = 1
//    pkNode->AddExtraData(pcKey, spkExtra);           // refs = 2
//    pkNode->RemoveExtraData(pcKey);                  // refs = 1
//    <use spkExtra however>;
//    spkExtra = 0;                                    // refs = 0, deletion
//
// The same warning applies to RemoveController(pkControl).


#include "NiObject.h"
#include "NiExtraData.h"
#include "NiTimeController.h"

NiSmartPointer(NiObjectNET);

class NIMAIN_ENTRY NiObjectNET : public NiObject
{
    NiDeclareRTTI;
    NiDeclareAbstractClone(NiObjectNET);
    NiDeclareAbstractStream;
    NiDeclareViewerStrings;

public:
    virtual ~NiObjectNET();

    // names
    void SetName(const char* pcName);
    const char* GetName() const;

    // extra data

    // WARNING: GetExtraDataAt is for iterating over all extra data items
    // (in conjunction with GetExtraDataSize). Indices are likely to change 
    // any time extra data is added, so applications should not rely on 
    // these indices! The same applies to RemoveExtraDataAt.
    // For fast extra data access, use short names. GetExtraData uses 
    // a binary search.

    unsigned int GetExtraDataSize() const;
    bool AddExtraData(const char* pcKey, NiExtraData* pkExtra);
    bool AddExtraData(NiExtraData* pkExtra);
    NiExtraData* GetExtraData(const char* pcKey) const;
    NiExtraData* GetExtraDataAt(unsigned int uiExtraDataIndex) const; 
    bool RemoveExtraData(const char* pcKey);
    bool RemoveExtraDataAt(unsigned int uiExtraDataIndex);
    void RemoveAllExtraData();
    // Pre-allocate ExtraData array to a particular size 
    // when the size is known.
    bool SetExtraDataSize(unsigned int uiSize); 

    // time controllers
    void PrependController(NiTimeController* pkControl);
    void SetControllers(NiTimeController* pkControl);
    NiTimeController* GetControllers() const;
    void RemoveController(NiTimeController* pkControl);
    void RemoveAllControllers();

    // cloning
    enum CopyType
    {
        COPY_NONE,
        COPY_EXACT,
        COPY_UNIQUE
    };

    // The CopyType refers to how object name strings are copied during a 
    // Clone() operation.
    //
    //   COPY_NONE:    Object names are not copied. New objects are unnamed.
    //
    //   COPY_EXACT:   Object names are duplicated. A side effect to be aware
    //                 of is the following. If the cloned graph is attached
    //                 to the original graph, a search by name will find only
    //                 the first occurrence of an object by that name.
    //
    //   COPY_UNIQUE:  Object names are copied, but a character is appended to
    //                 each name. The default append character is '$', but 
    //                 can be changed by the application.
    static void SetDefaultCopyType(CopyType eCopyType);
    static CopyType GetDefaultCopyType();
    static void SetDefaultAppendCharacter(char cAppendCharacter);
    static char GetDefaultAppendCharacter();
    
    // *** begin NDL internal use only ***

    bool InsertExtraData(NiExtraData* pkExtra);
    void DeleteExtraData(unsigned int uiExtraDataIndex);

    NiTimeController* GetController(const NiRTTI* pkRTTI) const;
    
    void PostLinkObject(NiStream& kStream);  // streaming support

    virtual void ProcessClone(NiCloningProcess& kCloning);
    // *** end NDL internal use only ***

protected:
    // abstract class
    NiObjectNET();

    // cloning
    static CopyType ms_eCopyType;
    static char ms_cAppendCharacter;

    char* m_pcName;
    NiTimeControllerPtr m_spControllers;

    // New Items
    NiExtraData** m_ppkExtra;
    unsigned int m_uiExtraDataSize;
    unsigned int m_uiMaxSize;  // number of slots in array
};

#include "NiObjectNET.inl"

#endif // NIOBJECTNET_H
