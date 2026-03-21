#include "Rezerwacja.h"
#include "Samochod.h"
#include "Pracownik.h"
#include <iostream>

int Rezerwacja::licznikId = 1;

Rezerwacja::Rezerwacja(Uzytkownik* u, Samochod* s, const string& start, const string& koniec) :
    id(licznikId++), uzytkownik(u), samochod(s), dataStart(start), dataKoniec(koniec), status("Potwierdzona") {}

    void Rezerwacja::zmienStatusRez(const string& nowyStatus) {
        this->status = nowyStatus;
    }

    void Rezerwacja::przedluzRez(const string& nowaDataKoniec) {
        this->dataKoniec = nowaDataKoniec;
    }

    bool Rezerwacja::czyKoliduje(int idSamochodu, const string& innyStart, const string& innyKoniec) const {
        if (this->samochod->getId() != idSamochodu) {
            return false;
        }

        if (this->status == "Anulowana") {
            return false;
        }

        if (innyStart > this->dataKoniec || innyKoniec < this->dataStart) {
            return false;
        }

        return true;
    }

    // GET
    int Rezerwacja::getId() const{
        return id;
    }
    string Rezerwacja::getStatus() const{
        return status;
    }
    string Rezerwacja::getDataStart() const{
        return dataStart;
    }
    string Rezerwacja::getDataKoniec() const{
        return dataKoniec;
    }
    Samochod* Rezerwacja::getSamochod() const{
        return this->samochod;
    }
    Uzytkownik* Rezerwacja::getUzytkownik() const {
        return this->uzytkownik;
    }
