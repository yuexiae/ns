#include "client/client_pch.h"

#include "client/application.h"
#include "base/logging.h"

extern "C" {

__declspec(dllexport) int Instance() {
	LOGINFO("Instance()");
	base::Singleton<Application>::GetSingleton()->OnMain();
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

