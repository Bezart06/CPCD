// CPCD App

#include <iostream>
#ifdef _WIN32 || _WIN64
#define OEMRESOURCE
#include <windows.h>
#include <conio.h>
#elif __linux__
#include <unistd.h>
#endif

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_DESTROY:
            PostQuitMessage(0);
        return 0;
        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}

void cpcd() {
#ifdef _WIN32 || _WIN64
    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = GetModuleHandle(nullptr);
    wc.lpszClassName = "FullScreenClass";
    wc.hCursor = nullptr;

    RegisterClass(&wc);

    HWND fullScreenWnd = CreateWindowEx(0, "FullScreenClass", nullptr,
        WS_POPUP | WS_VISIBLE, 0, 0,
        GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN),
        nullptr, nullptr, GetModuleHandle(nullptr), nullptr);

    if (fullScreenWnd == nullptr) {
        std::cerr << "Не удалось создать окно!" << std::endl;
        return;
    }

    SetWindowPos(fullScreenWnd, HWND_TOPMOST, 0, 0, GetSystemMetrics(SM_CXSCREEN),
        GetSystemMetrics(SM_CYSCREEN), SWP_SHOWWINDOW);

    ShowCursor(FALSE);

    MSG msg = {};
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    std::cout << "CPCD on Windows!" << std::endl;

#elif __linux__
    // ! added later !
#endif
}

int main() {
    cpcd();
    return 0;
}
