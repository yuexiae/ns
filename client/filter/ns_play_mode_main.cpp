#include "client/client_pch.h"

#include "game_header/ns.h"
#include "base/util.h"

class FpsTimer {
public:
    FpsTimer() {
        m_hTimer = CreateWaitableTimer(NULL, FALSE, NULL);
        SetInterval(1000/60);
    }

    ~FpsTimer() {
        CloseHandle(m_hTimer);
        m_hTimer = INVALID_HANDLE_VALUE;
    }

    void SetInterval(int nInternal) {
        if (m_nInternal != nInternal) {
            m_nInternal = nInternal;

            LARGE_INTEGER waitTime = { 0 };
            if (!SetWaitableTimer(m_hTimer, &waitTime, m_nInternal, NULL, NULL, FALSE)) {
                CloseHandle(m_hTimer);
                m_hTimer = INVALID_HANDLE_VALUE;
            }
        }
    }

    int GetInterval() {
        return m_nInternal;
    }

    BOOL Wait(HANDLE handle) {
        INT rc = MsgWaitForMultipleObjects(1, &m_hTimer, FALSE, INFINITE, QS_ALLINPUT);
        return rc == WAIT_OBJECT_0 + 0; 
    }

private:
    int m_nInternal;
    HANDLE m_hTimer;
};

static FpsTimer g_Timer;
static unsigned int g_dwFrameRate = 0;

class CPlayModeMainFilter : public CPlayModeMain {
public:
    static CPlayModeMain::_Invoke invoke_;


    bool ActionFilter() {
        timeBeginPeriod(1);

        NSApplication *pApplication = NSApplication::Instance();

        if (g_dwFrameRate != pApplication->m_dwFrameRate && pApplication->m_Hwnd) {
            wchar_t szTitle[256];
            wsprintf(szTitle, L"Neosteam[%u:%u]", pApplication->m_dwFrameRate, g_Timer.GetInterval());
            SetWindowText(NSApplication::Instance()->m_Hwnd, szTitle);
            g_dwFrameRate = pApplication->m_dwFrameRate;
        }
        
        HWND hForegroundHandle = GetForegroundWindow();
        if (hForegroundHandle != pApplication->m_Hwnd && GetParent(hForegroundHandle) != pApplication->m_Hwnd) {
            g_Timer.SetInterval(1000/5);
        } else {
            g_Timer.SetInterval(1000/100);
        }

        if (g_Timer.Wait(pApplication->m_Hwnd)) {
            return (this->*invoke_.Action)();
        } else {
            return true;
        }
    }
};


CPlayModeMain::_Invoke CPlayModeMainFilter::invoke_;

bool CPlayModeMainFilterInit() {
    //base::HookUtil::PatchUShort(0x0046838A + 4, 5); //init play mode
    //base::HookUtil::PatchUShort(0x0042660B, 0x0BEB);//SetForegroundWindow
    return CPlayModeMain::_PatchAction(&CPlayModeMainFilter::ActionFilter, &CPlayModeMainFilter::invoke_.Action);
}