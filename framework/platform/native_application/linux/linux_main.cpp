#include "cmake_val.h"
#ifdef TARGET_PLATFORM_TYPE_LINUX

#include "common/interface/base_application.h"
#include "common/interface/base_renderer.h"

using namespace BriskEngine;

namespace BriskEngine {
    extern BaseApplication *g_pApp;
    extern BaseRenderer* g_pRenderer;
}

int main(int argc, char *argv[]) {
    if (!g_pApp->Initialize())
        return 0;
    if (!g_pRenderer->Initialize())
        return 0;

    //Main Loop
    while (!g_pApp->IsQuit()) {
        g_pApp->Tick();
        g_pRenderer->Tick();
    }

    g_pApp->Finalize();
    g_pRenderer->Finalize();
    return 0;
}

#endif