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

#ifndef NISCRIPTNAMECHANGEDIALOG_H
#define NISCRIPTNAMECHANGEDIALOG_H

#include "NiDialog.h"
#include "NiScriptInfo.h"
#include "NiScriptInfoSet.h"

class NIPLUGINTOOLKIT_ENTRY NiScriptNameChangeDialog : public NiDialog
{
    public:
        NiScriptNameChangeDialog(NiModuleRef hInstance, NiWindowRef hWnd, 
            const char* pcName, const char* pcTitle);
        ~NiScriptNameChangeDialog();
        int DoModal();
        virtual void InitDialog();
        virtual BOOL OnCommand(int iWParamLow, int iWParamHigh, long lParam);
        
        char* m_pcName;
        char* m_pcTitle;
};

#endif
