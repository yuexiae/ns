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

#ifndef NIBATCHEXECUTIONRESULT_H
#define NIBATCHEXECUTIONRESULT_H

#include "NiPluginToolkitLibType.h"
#include "NiExecutionResult.h"
#include <NiTArray.h>

class NiScriptInfo;

/// The containter for the results of a script execution.
class NIPLUGINTOOLKIT_ENTRY NiBatchExecutionResult : public NiExecutionResult
{
public:
    NiDeclareRTTI;

    /// The constructor accepts the return code.
    NiBatchExecutionResult(ReturnCode eReturnCode);

    /// An array containing the plugin results.
    NiTArray<NiExecutionResultPtr> m_pkPluginResults;

    bool WasSuccessful();
};

NiSmartPointer(NiBatchExecutionResult);

#endif  // #ifndef NIBATCHEXECUTIONRESULT_H
