#include "COM.h"

void COM::createPort(LPCSTR portName)
{
    hNumPort = CreateFile(portName,GENERIC_WRITE | GENERIC_READ,0,NULL,OPEN_EXISTING,0,NULL);
}


void COM::sendInformations()
{
    WriteFile(hNumPort,lpBuffor_write.c_str(),strlen(lpBuffor_write.c_str()),&RS_ile,0);
}

int COM::getIsOpen()
{
    return isOpen;
}

void COM::connectPort()
{
    if(SetCommState(hNumPort,&dcb)==true)
    {
        MessageBox(NULL,"Udalo sie otworzyc port!","Sukces",MB_OK);
        isOpen = 1;
    }
    else
        MessageBox(NULL,"Nie udalo sie otworzyc portu!","Blad",MB_OK);
}


void COM::setMessage(std::string message)
{
    lpBuffor_write = message;
}

COM::COM(/*LPCSTR com,DWORD gen,DWORD share,LPSECURITY_ATTRIBUTES secure,DWORD disposition,DWORD flags,HANDLE templatef*/)
{
    //hNumPort = CreateFile(com,gen,share,secure,disposition,flags,templatef);

    isOpen = 0;
    dcb.DCBlength = sizeof(dcb);

    dcb.BaudRate = CBR_600;
    dcb.fParity = TRUE;
    dcb.Parity = EVENPARITY;
    dcb.StopBits = ONESTOPBIT;
    dcb.ByteSize = 8;

    dcb.fDtrControl = DTR_CONTROL_ENABLE;
    dcb.fRtsControl = RTS_CONTROL_ENABLE;

    dcb.fOutxCtsFlow = FALSE;
    dcb.fOutxDsrFlow = FALSE;
    dcb.fDsrSensitivity = FALSE;
    dcb.fAbortOnError = FALSE;
    dcb.fOutX = FALSE;
    dcb.fInX = FALSE;
    dcb.fErrorChar = FALSE;
    dcb.fNull = FALSE;
}

COM::~COM()
{
    //dtor
}
