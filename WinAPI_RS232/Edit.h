#ifndef EDIT_H
#define EDIT_H

#include "Button.h"



class Edit : public Button
{
    LPSTR buff;
    public:

        Edit();
        virtual ~Edit();
        void createObject(LPCTSTR,DWORD,int,int,int,int,HWND,int);
        void getData();
        LPSTR getBuff();

    protected:

    private:
};

#endif // EDIT_H
