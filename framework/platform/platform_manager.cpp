#include "platform/platform_manager.h"
#include "platform/native_application/windows/win_application.h"
namespace BriskEngine {

#ifdef TARGET_PLATFORM_TYPE_WINDOWS
	WinApplication g_App;
	BaseApplication* g_pApp = &g_App;
#endif
#ifdef TARGET_PLATFORM_TYPE_LINUX
	LinuxApplication g_App;
	BaseApplication* g_pApp = &g_App;
#endif
#ifdef TARGET_PLATFORM_TYPE_MACOSX
	MacOSXApplication g_App;
	BaseApplication* g_pApp = &g_App;
#endif

}