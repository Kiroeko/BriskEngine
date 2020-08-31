#include "cmake_val.h"
#ifdef TARGET_PLATFORM_TYPE_WINDOWS

#ifndef UNICODE
#define UNICODE
#endif 

#include <windows.h>
#include "common/interface/base_application.h"

using namespace BriskEngine;
namespace BriskEngine {
    extern BaseApplication* g_pApp;
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
    const wchar_t CLASS_NAME[] = L"Brisk Engine";
    WNDCLASS wc = {};
    wc.lpfnWndProc   = WindowProc;
    wc.hInstance     = hInstance;
    wc.lpszClassName = CLASS_NAME;
    RegisterClass(&wc);

    // Create the window.
    HWND hwnd = CreateWindowEx(
        0,                                // Optional window styles.
        CLASS_NAME,                       // Window class
        L"Brisk Engine",                  // Window text
        WS_OVERLAPPEDWINDOW,              // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
        NULL,       // Parent window    
        NULL,       // Menu
        hInstance,  // Instance handle
        NULL        // Additional application data
    );
    if (hwnd == NULL)
        return 0;

    //Initialize g_pApp
    if (!g_pApp->Initialize())
        return 0;

    ShowWindow(hwnd, nCmdShow);

    // Run the message loop.
    MSG msg = {};
    while (!g_pApp->IsQuit()) {
        bool bGotMsg = (PeekMessage(&msg, NULL, 0u, 0u, PM_REMOVE) != 0);
        if (bGotMsg) {
            if (msg.message == WM_QUIT)
                break;
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        } else {
            g_pApp->Tick();
        }
    }

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
        break;
    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}

#endif