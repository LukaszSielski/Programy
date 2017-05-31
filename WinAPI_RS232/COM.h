#ifndef COM_H
#define COM_H

#include <windows.h>
#include <string>


class COM
{
    //LPCSTR portName; //zmienna przechowujaca nazwe portu
    HANDLE hNumPort; // uchwyt do portu
    DCB dcb; // ustawienia potu
    std::string lpBuffor_write; // zmienna przechowujaca tresc do wyslania
    DWORD RS_ile; // zmienna przechowujaca ile czego wysy³amy
    int isOpen; // zmienna przechowujaca status portu

public:
    COM(/*LPCSTR = "COM3", DWORD = GENERIC_WRITE | GENERIC_READ,DWORD = 0,LPSECURITY_ATTRIBUTES = NULL,DWORD = OPEN_EXISTING ,DWORD = 0,HANDLE = NULL*/);// konstruktor przypiszedomyslne wartosci parametom transmisji oraz utworzy uchwyt do portu
    virtual ~COM();
    void sendInformations(); // wywyolujemy funkcje do wysylania danych
    void connectPort(); // wlacza port
    void setMessage(std::string); // ustawia wiadomosc
    void createPort(LPCSTR); // tworzy port o zadanej nazwie
    int getIsOpen(); //zwraca 1 gdy port jest wlaczony i 0 gdy jes wylaczony
};

#endif // COM_H
