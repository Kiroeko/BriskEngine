#include "platform/platform_manager.h"
#include "platform/native_application/windows/win_application.h"
namespace BriskEngine {

#ifdef TARGET_PLATFORM_TYPE_WINDOWS
	WinApplication g_App;
#elif defined TARGET_PLATFORM_TYPE_LINUX
	LinuxApplication g_App;
#elif defined TARGET_PLATFORM_TYPE_MACOS
	MacOSApplication g_App;
#endif
	BaseApplication* g_pApp = &g_App;

}