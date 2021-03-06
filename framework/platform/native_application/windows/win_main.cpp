#include "cmake_val.h"
#ifdef TARGET_PLATFORM_TYPE_WINDOWS

#ifndef UNICODE
#define UNICODE
#endif
#ifndef _UNICODE
#define _UNICODE
#endif

#include <windows.h>
#include "platform/native_application/base_application.h"
#include "graphic/renderer/base_renderer.h"

using namespace BriskEngine;
namespace BriskEngine {
    extern BaseApplication* g_pApp;
    extern BaseRenderer* g_pRenderer;
}

LRESULT CALLBACK WindowProc(HWND hwnd,
                            UINT uMsg,
                            WPARAM wParam,
                            LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInstance,
                    HINSTANCE,
                    PWSTR pCmdLine,
                    int nCmdShow)
{
    // Register the window class.
    const wchar_t CLASS_NAME[] = TEXT(PROJECT_NAME);
    WNDCLASS wc                = {};
    wc.lpfnWndProc             = WindowProc;
    wc.hInstance               = hInstance;
    wc.lpszClassName           = CLASS_NAME;
    RegisterClass(&wc);

    // Create the window.
    HWND hwnd = CreateWindowEx(
        0,                                // Optional window styles.
        CLASS_NAME,                       // Window class
        TEXT(PROJECT_NAME),               // Window text
        WS_BORDER,                        // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
        NULL,                             // Parent window    
        NULL,                             // Menu
        hInstance,                        // Instance handle
        NULL                              // Additional application data
    );

    if (hwnd == NULL)
        return 0;
    if (!g_pApp->Initialize())
        return 0;
    if (!g_pRenderer->Initialize())
        return 0;

    ShowWindow(hwnd, nCmdShow);
    // Run the message loop.
    MSG msg = {};
    while (true) {
        BOOL bGotMsg = PeekMessage(&msg, NULL, 0u, 0u, PM_REMOVE);
        if (bGotMsg) {
            if (msg.message == WM_QUIT)
                break;
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        } else {
            g_pApp->Tick();
            g_pRenderer->Tick();
        }
    }

    g_pRenderer->Finalize();
    g_pApp->Finalize();
    return (int)msg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hwnd,
                            UINT uMsg,
                            WPARAM wParam,
                            LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}

#endif