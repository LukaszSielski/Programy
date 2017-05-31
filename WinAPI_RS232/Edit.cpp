#include "Edit.h"

void Edit::createObject(LPCTSTR objectName,DWORD objectStyle,int posX,int posY,int width,int height,HWND hwnd,int objectID)
{
    handle = CreateWindow("EDIT",objectName,objectStyle,posX,posY,width,height,hwnd,(HMENU)objectID,NULL,NULL);
}

void Edit::getData()
{

    DWORD length = GetWindowTextLength(handle);
    buff = (LPSTR)GlobalAlloc(GPTR,length);
    GetWindowText(handle,buff,length+1);
}

LPSTR Edit::getBuff()
{
    return buff;
}


Edit::Edit()
{
    objectName = "";
    objectStyle = WS_CHILD | WS_VISIBLE | WS_BORDER;
    posX = 25;
    posY = 0;
    width = 200;
    height = 200;
    objectID = 9999;
}

Edit::~Edit()
{
    //dtor
}
