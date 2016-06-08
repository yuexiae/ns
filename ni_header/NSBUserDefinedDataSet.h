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

#ifndef NSBUSERDEFINEDDATASET_H
#define NSBUSERDEFINEDDATASET_H

#include "NSBUserDefinedDataBlock.h"

// NSBUserDefinedDataSet is a container for a collection of 
// NSBUserDefinedDataBlock instances. This class exists to minimize
// code duplication as NSBShader, NSBImplementation, and NSBPass may
// all have a collection of NSBUserDefinedDataBlock instances.
//
class NIBINARYSHADERLIB_ENTRY NSBUserDefinedDataSet : public NiRefObject
{
public:
    NSBUserDefinedDataSet();
    ~NSBUserDefinedDataSet();

    // The user-defined data
    unsigned int GetBlockCount();
    NSBUserDefinedDataBlock* GetBlock(const char* pacName, 
        bool bCreate = false);
    NSBUserDefinedDataBlock* GetFirstBlock();
    NSBUserDefinedDataBlock* GetNextBlock();

    // *** begin NDL internal use only
    virtual bool SaveBinary(NiBinaryStream& kStream);
    virtual bool LoadBinary(NiBinaryStream& kStream);

#if defined(_DEBUG)
    virtual void Dump(FILE* pf);
#endif  //#if defined(_DEBUG)
    // *** end NDL internal use only

protected:
    NiTListIterator m_kBlockIter;
    NiTPointerList<NSBUserDefinedDataBlock*> m_kUserDefinedDataBlocks;
};

NiSmartPointer(NSBUserDefinedDataSet);

#include "NSBUserDefinedDataSet.inl"

#endif  //NSBUSERDEFINEDDATASET_H
