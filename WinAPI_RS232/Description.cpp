#include "Description.h"

Description::Description()
{
    objectName = "Default";
    objectStyle = WS_CHILD | WS_VISIBLE ;
    posX = 0;
    posY = 0;
    width = 20;
    height = 20;
    objectID = 9999;
}

Description::~Description()
{
    //dtor
}


void Description::createObject(LPCSTR objectName,DWORD objectStyle,int posX,int posY,int width,int height,HWND hwnd,int objectID)
{
    handle = CreateWindow("STATIC",objectName,objectStyle,posX,posY,width,height,hwnd,(HMENU)objectID,NULL,NULL);
}
