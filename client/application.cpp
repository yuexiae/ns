#include "client/client_pch.h"

#include "client/application.h"
#include "base/logging.h"
#include "base/hook_util.h"
#include "game_header/ns.h"
#include "client/filter/filter_init.h"

#define FILTER_INIT(name) name() ? LOGINFO("%s init", #name) : LOGERROR("%s init failure", #name)


void Application::Initialize() {
    ::DeleteFile(L".\\gamelog.txt");
    base::Logging *loger = base::Logging::DefualtLogging();
	loger->ConfigFilename(".\\gamelog.txt");
	loger->ConfigStderr();

    GameStructCheck::Check();

    PatchClient();
    FILTER_INIT(CPlayModeMainFilterInit);
}

class NSTestFrame : public NSFrameWindow {
public:
    NSTestFrame() : NSFrameWindow(0xA00000, 1, 0, NSRect<int>(0, 0, 300, 300), 3, 1, 0, NSRect<int>(0), 0) {}
};


void __stdcall TestThread(int param) {
	MessageBox(NULL, L"", L"", MB_OK);
        LOGINFO("mode:%d->%d", CPlayModeMain::Instance()->m_wMode, CPlayModeMain::Instance()->m_wNextMode);
	NSFrameWindow *window = new NSTestFrame();
    window->SetVisible(true);
    NSRenderWindow::Instance()->AddChild(window,NSRect<int>(0));
}


void Application::OnMain() {
    LOGINFO("vtable:%04x", *reinterpret_cast<unsigned long **>(0x712F48));


    CloseHandle(CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)TestThread, NULL, NULL, NULL));
}

void Application::PatchClient() {
    base::HookUtil::PatchUChar(0x00425AD2, 0xeb);
    base::HookUtil::PatchULong(0x0041D92a, 0xC80000 | WS_MINIMIZEBOX);
}