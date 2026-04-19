#ifndef REZERWACJA_H_INCLUDED
#define REZERWACJA_H_INCLUDED
#include "Samochod.h"
#include "Uzytkownik.h"

using namespace std;
#include <iostream>
#include <string>
#include <vector>

class Rezerwacja {
    private:
        static int licznikId;
        int id;
        Uzytkownik* uzytkownik;
        Samochod* samochod;
        string dataStart;
        string dataKoniec;
        string status;

    public:
        Rezerwacja(Uzytkownik* u, Samochod* s, const string& start, const string& koniec);

        int getId() const;
        string getStatus() const;
        string getDataStart() const;
        string getDataKoniec() const;
        Samochod* getSamochod() const;
        Uzytkownik* getUzytkownik() const;

        void zmienStatusRez(const string& nowyStatus);
        void przedluzRez(const string& nowaDataKoniec);
        bool czyKoliduje(int idSamochodu, const string& innyStart, const string& innyKoniec) const;
};

#endif
