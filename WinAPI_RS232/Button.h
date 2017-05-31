#ifndef BUTTON_H
#define BUTTON_H
#include <windows.h>


class Button
{
    protected:
    HWND handle; //uchwyt przycisku
    LPCSTR objectName; //nazwa przycisku
    DWORD objectStyle; // styl przycisku
    int posX, posY, width, height; //pozycja x,y szerokosc, wysokosc
    int objectID; // identyfikator przycisku;

    public:

        Button();
        virtual ~Button();

        void createObject(LPCSTR,DWORD,int,int,int,int,HWND,int);
};

#endif // BUTTON_H
