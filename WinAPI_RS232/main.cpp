#if defined(UNICODE) && !defined(_UNICODE)
#define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
#define UNICODE
#endif

#include <tchar.h>
#include <windows.h>
#include <iostream>
#include "COM.h"
#include "Button.h"
#include "Edit.h"
#include "Description.h"
using namespace std;


/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
// port
COM port;
//przyciski
Button portInit;
Button d;
//pola tekstowe
Edit e1;
Edit pole[12];
//przycisk wysylajacy dane
//Button send;

int wysokosc = 800;
int szerokosc = 600;



/*  Make the class name into a global variable  */
TCHAR szClassName[ ] = _T("CodeBlocksWindowsApp");

int WINAPI WinMain (HINSTANCE hThisInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpszArgument,
                    int nCmdShow)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
               0,                   /* Extended possibilites for variation */
               szClassName,         /* Classname */
               _T("Wysylanie przez port szeregowy"),       /* Title Text */
               WS_OVERLAPPEDWINDOW, /* default window */
               CW_USEDEFAULT,       /* Windows decides the position */
               CW_USEDEFAULT,       /* where the window ends up on the screen */
               szerokosc,                 /* The programs width */
               wysokosc,                 /* and height in pixels */
               HWND_DESKTOP,        /* The window is a child-window to desktop */
               NULL,                /* No menu */
               hThisInstance,       /* Program Instance handler */
               NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}


/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  /* handle the messages */
    {
    case WM_CREATE:
        //port.connectPort();
        //port.setMessage("Test");
        //port.sendInformations();
        //port.createPort("COM3");
        portInit.createObject("Connect",WS_CHILD | WS_VISIBLE | WS_BORDER,0,0,70,25,hwnd,1);
        e1.createObject("",WS_CHILD | WS_VISIBLE | WS_BORDER,70,0,70,25,hwnd,2);
        for(int i = 0; i<12; i++)
            pole[i].createObject("",WS_CHILD | WS_VISIBLE | WS_BORDER,70,(i+1)*25,70,25,hwnd,i+3);

        d.createObject("SEND",WS_CHILD | WS_VISIBLE | WS_BORDER,szerokosc/2,wysokosc/2,70,25,hwnd,20);
        break;

    case WM_COMMAND:
        switch(LOWORD(wParam))
        {
        case 1:
            e1.getData();
            port.createPort(e1.getBuff());
            switch(port.getIsOpen())
            {
            case 0:
                port.connectPort();
                break;
            default:
                break;
            }
            break;
        case 20:
            for(int i = 0; i<12; i++)
                pole[i].getData();

            string dane = "";
            for(int i = 0; i<12; i++)
                dane += (string)pole[i].getBuff();
            port.setMessage(dane);
            port.sendInformations();
            break;
        }


        break;


    case WM_DESTROY:
        PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
        //CloseHandle(hNumPort);
        break;
    default:                      /* for messages that we don't deal with */
        return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}
