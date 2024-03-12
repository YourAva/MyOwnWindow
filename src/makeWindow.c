#include "windowLogic.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg)
    {
        case WM_CLOSE:
            DestroyWindow(hwnd);
        break;
        case WM_DESTROY:
            PostQuitMessage(0);
        break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

int WINAPI makeWindow(char *title, int x_scale, int y_scale, int backgroundColor) {
    HINSTANCE hInstance;
    HINSTANCE hPrevInstance;
    LPSTR lpCmdLine;
    int nCmdShow;

    const char ava_window[] = "AVA_WINDOW"; //Define the window class name -- This is needed for future references.

    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;

    wc.cbSize        = sizeof(WNDCLASSEX);                //Size of the structure 
    wc.style         = 0;                                 // Class styles
    wc.lpfnWndProc   = WndProc;                           // Pointer to window procedure for this windows class.
    wc.cbClsExtra    = 0;                                 // Amount of extra data allocated for this clas in memory (normally 0)
    wc.cbWndExtra    = 0;                                 // Amount of extra data allocated in memory per window of this type. Usually 0. 
    wc.hInstance     = hInstance;                         // Handle to application instance
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);   // Large icon, normally shown under ALT + TAB
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);       // Cursor to display when on window
    wc.hbrBackground = (HBRUSH)(backgroundColor);                      // Background Color
    wc.lpszMenuName  = NULL;                              // Name of a menu resource to use for the windows with this class (???)
    wc.lpszClassName = ava_window;                        // Name to identify class with
    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);   // Small 16x16 icon in the top left corner of window.

    if(!RegisterClassEx(&wc)) // If we can't register a window class for subsequent use in calls, return an error box.
    {
        MessageBox(NULL, "We shit the bed! (Ur window failed bruh)", "Error!", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    hwnd = CreateWindowEx(                             // --- If you're looking at this, I highly recommend looking at all the paramaters that can go with it.
        0,                                             // Extended window style, can give a sunken inner border with something like WS_EX_CLIENTEDGE
        ava_window,                                    // Classname, nothing we haven't seen before.
        title,                                         // Title to show on the window. Duh.
        WS_OVERLAPPEDWINDOW,                           // Window style paramater, there are quite a few that you should look up to find out what they do.
        CW_USEDEFAULT, CW_USEDEFAULT, x_scale, y_scale,// X, Y, Width, Height.
        NULL, NULL, hInstance, NULL);                  // Parent window handle, menu handle, application instance handle, pointer to window creation data.
    if(hwnd == NULL)
    {
        MessageBox(NULL, "We shit the bed! (Ur window failed bruh)", "Error!", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    ShowWindow(hwnd, SW_SHOWNORMAL); // created window data, if the window can start as minimised, fullscreened etc... This is fucking stupid. We're putting it under SW_SHOWNORMAL
    UpdateWindow(hwnd);

    while(GetMessage(&Msg, NULL, 0, 0) > 0)
    //GetMessage gets a message from the applications message queue. Any time the user does smth, a message is generated, getMessage calls the next available message.
    {
        TranslateMessage(&Msg); // A little extra processing of the message.
        DispatchMessage(&Msg); // Send message to the window that the data was sent to.
    }
    return Msg.wParam;
}

int callError(){
    MessageBox(NULL, "We shit the bed! (Ur window failed bruh)", "Error!", MB_ICONEXCLAMATION | MB_OK);
    return 0;
}