#include "Button.h"

Button::Button()
{
    objectName = "Default";
    objectStyle = WS_CHILD | WS_VISIBLE | WS_BORDER;
    posX = 0;
    posY = 0;
    width = 20;
    height = 20;
    objectID = 9999;
}

Button::~Button()
{

}

void Button::createObject(LPCSTR objectName,DWORD objectStyle,int posX,int posY,int width,int height,HWND hwnd,int objectID)
{
    handle = CreateWindow("BUTTON",objectName,objectStyle,posX,posY,width,height,hwnd,(HMENU)objectID,NULL,NULL);
}
