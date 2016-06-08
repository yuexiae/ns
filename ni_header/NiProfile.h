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

#ifndef NIPROFILE_H
#define NIPROFILE_H

#if defined(NIPROFILE)

#include "NiTPointerList.h"

class NiAVObject;

// To use NiProfile, NIPROFILE must be defined in your Gamebryo libraries 
// and application. 

class NiProfile
{
public:

    // WriteAllStatisticsToLog() dumps the scene graph profile stats to a log
    // file, which you can import into a spreadsheet program for analysis.
    // The stats are not sorted.  This function automatically opens and 
    // closes the log file.
    static void WriteAllStatisticsToLog(NiAVObject* pkObject);

    // Sort and Display nodes by various stats:

    // by UpdateDownwardPass time 
    static void DisplaySortedUpdateDownTime(NiAVObject* pkObject);
    // by UpdateDownwardPass time * calls
    static void DisplaySortedUpdateDownTimeCalls(NiAVObject* pkObject);
    // by UpdateDownwardPass time - minus children
    static void DisplaySortedUpdateDownTimeNoChildren(NiAVObject* pkObject);
    // by UpdateDownwardPass time * calls - minus children
    static void DisplaySortedUpdateDownTimeCallsNoChildren(
        NiAVObject* pkObject);
    // by UpdateUpwardPass time
    static void DisplaySortedUpdateUpTime(NiAVObject* pkObject);
    // by UpdateUpwardPass time * calls
    static void DisplaySortedUpdateUpTimeCalls(NiAVObject* pkObject);
    // by Display time
    static void DisplaySortedDisplayTime(NiAVObject* pkObject);
    // by Display time * calls
    static void DisplaySortedDisplayTimeCalls(NiAVObject* pkObject);
    // by Display time - minus children
    static void DisplaySortedDisplayTimeNoChildren(NiAVObject* pkObject);
    // by Display time * calls - minus children
    static void DisplaySortedDisplayTimeCallsNoChildren(NiAVObject* pkObject);

    // log all profile stats (non-recursive)
    static void DisplayProfileStats(NiAVObject* pkObject);
    // log all profile stats (recursive)
    static void DisplayProfileStatsRecursive(NiAVObject* pkObject);
    // write a line to the log that labels each stat column
    static void DisplayProfileHeader();
    // predict how long it will take for the performance counter to roll over
    static void TestTimers();

    // resets all call counters
    static void ResetCallCounts(NiAVObject* pkObject);

private:
    typedef NiTPointerList<NiAVObject*> NiSortedObjectList;

    // pointer to NiAVObject member function to be used as sort key
    typedef unsigned int (NiAVObject::*NiAVObjectSortKey)(void) const;

    static void InsertObjectSorted(NiAVObject* pkObject, 
         NiSortedObjectList& kObjectList, NiAVObjectSortKey pfSortKey);

};

#define NIPROFILE_EVAL(a) a

#else //#if defined(NIPROFILE)

#define NIPROFILE_EVAL(a) 

#endif //#if defined(NIPROFILE)

#endif  // NIPROFILE_H
