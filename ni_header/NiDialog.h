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

#ifndef NIDIALOG_H
#define NIDIALOG_H

#include "NiPluginToolkitDefinitions.h"
#include <NiRefObject.h>

class NIPLUGINTOOLKIT_ENTRY NiDialog : public NiRefObject
{
    public:
        NiDialog(WORD wResourceId, NiModuleRef hInstance, NiWindowRef hWndParent);
        virtual ~NiDialog();

        virtual int DoModal();

        void Create();
        void Destroy();

        NiWindowRef GetWindowRef();
    protected:
        NiDialog() {};
        NiDialog(NiDialog&){};
        static BOOL CALLBACK TheDialogProc(NiWindowRef hWnd, UINT message,
            WPARAM wParam,LPARAM lParam);

        virtual void InitDialog();

        virtual BOOL OnCommand(int iWParamLow, int iWParamHigh, long lParam);

        virtual BOOL OnMessage(unsigned int uiMessage, int iWParamLow, int iWParamHigh, long lParam);

        virtual void OnClose();

        virtual void OnDestroy();

        NiModuleRef m_hInstance;
        NiWindowRef m_hWndParent;
        WORD m_wResourceId;
        NiWindowRef m_hWnd;
        bool m_bIsModalDlg;

};

NiSmartPointer(NiDialog);

#endif