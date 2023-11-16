#include <stdio.h>

#pragma warning(push, 0)
#include <windows.h>
#pragma  warning(pop)


LRESULT CALLBACK MainWindowProc(HWND, UINT, WPARAM, LPARAM);

int WinMain(HINSTANCE Instance, HINSTANCE PreviousInstance, PSTR CommandLine, int CmdShow)
{

    WNDCLASSEXA WindowClass = {0};
    HWND WindowsHandle = 0;
    MSG Msg;

    WindowClass.cbSize        = sizeof(WNDCLASSEXA);
    WindowClass.style         = 0;
    WindowClass.lpfnWndProc   = MainWindowProc;
    WindowClass.cbClsExtra    = 0;
    WindowClass.cbWndExtra    = 0;
    WindowClass.hInstance     = Instance;
    WindowClass.hIcon         = LoadIconA(NULL, IDI_APPLICATION);
    WindowClass.hCursor       = LoadCursorA(NULL, IDC_ARROW);
    WindowClass.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    WindowClass.lpszMenuName  = NULL;
    WindowClass.lpszClassName = "GAME_B_WINDOW_CLASS";
    WindowClass.hIconSm       = LoadIconA(NULL, IDI_APPLICATION);

    if(RegisterClassExA(&WindowClass) == 0)
    {
        MessageBox(NULL, "Window Registration Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    WindowsHandle = CreateWindowEx(
            WS_EX_CLIENTEDGE,
            WindowClass.lpszClassName ,
            "The title of my window",
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT, CW_USEDEFAULT, 240, 120,
            NULL, NULL, Instance, NULL);

    if(WindowsHandle == NULL)
    {
        MessageBox(NULL, "Window Creation Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    ShowWindow(WindowsHandle, CmdShow);
    UpdateWindow(WindowsHandle);


    MSG message = {0};
    while(GetMessageA(&message, NULL, 0, 0) > 0)
    {
        TranslateMessage(&message);
        DispatchMessageA(&message);
    }

    return 0;
}




LRESULT CALLBACK MainWindowProc(
        HWND hwnd,        // handle to window
        UINT uMsg,        // message identifier
        WPARAM wParam,    // first message parameter
        LPARAM lParam)    // second message parameter
{
    switch (uMsg)
    {
        case WM_CREATE:
            // Initialize the window.
            return 0;

        case WM_PAINT:
            // Paint the window's client area.
            return 0;

        case WM_SIZE:
            // Set the size and position of the window.
            return 0;

        case WM_DESTROY:
            // Clean up window-specific data objects.
            return 0;

            //
            // Process other messages.
            //

        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}