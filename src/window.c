#ifndef UNICODE
#define UNICODE
#endif /* ifndef UNICODE */

#include <windows.h>
#include <string.h>
#include <winuser.h>
#include <stdio.h>

#include "jalgui.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int createJalWin(jalWindow* win, HINSTANCE hInstance, LPCWSTR winName, int nCmdShow) {
  // Register the window class.
    const wchar_t CLASS_NAME[]  = L"Main Window Class";
    
    WNDCLASS wc;
    memset(&wc, 0, sizeof(wc));

    wc.lpfnWndProc   = WindowProc;
    wc.hInstance     = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    // Create the window.

    win->window = CreateWindowEx(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        winName,    // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,       // Parent window    
        NULL,       // Menu
        hInstance,  // Instance handle
        NULL        // Additional application data
        );

    if (win->window == NULL)
    {
        return 0;
    }

    ShowWindow(win->window, nCmdShow);

    // Run the message loop.

    MSG msg;
    memset(&msg, 0, sizeof(msg));
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            // All painting occurs here, between BeginPaint and EndPaint.

            FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));

            EndPaint(hwnd, &ps);
        }
        return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
