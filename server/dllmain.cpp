#include "server/server_pch.h"

#include "server/application.h"
#include "server/game_util.h"

extern "C" {
int __declspec(dllexport) Instance() {
    Application::GetSingleton()->OnMain();
	return 0;
}
}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
	) {
	switch (ul_reason_for_call) {
	case DLL_PROCESS_ATTACH: {
		DisableThreadLibraryCalls(hModule);
		Application::GetSingleton()->Initialize();
	}
	break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	break;
	case DLL_PROCESS_DETACH:
		Application::DestorySingleton();
	break;
	}
	return TRUE;
}

