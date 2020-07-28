#include "common/interface/base_application.h"

using namespace BriskEngine;

namespace BriskEngine {
    extern BaseApplication *g_pApp;
}

int main(int argc, char *argv[]) {
    if (g_pApp && !g_pApp->Initialize())
        return 0;

    //Main Loop
    while (!g_pApp->isNeedExit())
        g_pApp->Update();

    g_pApp->Finalize();
    return 0;
}