#ifndef DESCRIPTION_H
#define DESCRIPTION_H
#include "Button.h"


class Description : public Button
{
    public:
        Description();
        virtual ~Description();
        void createObject(LPCSTR,DWORD,int,int,int,int,HWND,int);

    protected:

    private:
};

#endif // DESCRIPTION_H
