#include "Pracownik.h"
#include "ListaRezerwacji.h"
#include "KatalogSamochodow.h"
#include "OcenaStanu.h"
#include "Dokumentacja.h"
#include "Samochod.h"
#include "Protocol.h"
#include "Rezerwacja.h"

#include <iostream>
using namespace std;

Pracownik::Pracownik(int id, const string& imie, const string& nazwisko, const string& login, const string& haslo, const string& dzial) :
    Uzytkownik(id, imie, nazwisko, login, haslo), dzial(dzial) {}

    void Pracownik::zarezerwujSamochod(ListaRezerwacji& lista, Samochod* samochod, string dataStart, string dataKoniec) {
        if (samochod->getStatus() != "Dostepny") {
            cout << "Nie mozna zarezerwowac tego samochodu!" << endl;
            cout << "Obecny status pojazdu: " << samochod->getStatus() << endl;
            return;
        }

        if (!lista.czyWolny(samochod->getId(), dataStart, dataKoniec)) {
            cout << "Nie mozna zarezerwowac: Wybrany termin jest juz zajety!" << endl;
            return;
        }

        Rezerwacja* r = new Rezerwacja(this, samochod, dataStart, dataKoniec);

        if (lista.dodajRez(r)) {
            samochod->ustawStatus("Zarezerwowany");

            cout << "Rezerwacja udana!" << endl;
        } else {
            delete r;
        }
    }

    void Pracownik::anulujRezerwacje(ListaRezerwacji& lista, int idRezerwacji) {
        lista.anulujRez(idRezerwacji, this->getId());
    }

    /*void Pracownik::przedluzRezerwacje(ListaRezerwacji& lista, int idRezerwacji, const string& NowaDataKoniec) {
        lista.przedluzRez(idRezerwacji, NowaDataKoniec);
    }

    void Pracownik::wyszukajSamochod(KatalogSamochodow& katalog, string kryteria) {
        katalog.wyszukajSam(kryteria);
    }*/

    void Pracownik::przegladajSamochody(KatalogSamochodow& katalog) const {
        cout << "Lista samochodoow sluzbowych: " << endl;

        vector<Samochod*> samochody = katalog.pobierzWszystkieSam();

        if (samochody.empty()) {
            cout << "Katalog samochodow jest pusty." << endl;
            return;
        }

        for (auto s : samochody) {
            cout << "ID: " << s->getId()
            << " | " << s->getMarka()
            << " | " << s->getModel()
            << " | Status: " << s->getStatus()
            << endl;
        }
    }

    void Pracownik::przegladajSzczegoly(KatalogSamochodow& katalog, int idSamochodu) const {
        Samochod* s = katalog.pobierzSamochod(idSamochodu);
        if (s) {
            s->wypiszSzczegoly();
        } else {
            cout << "Nie znaleziono samochodu" << endl;
        }
    }

    void Pracownik::przegladajRezerwacje(ListaRezerwacji& lista, int idUzytkownika) const {
        vector<Rezerwacja*> mojeRez = lista.pobierzDlaUzytkownika(idUzytkownika);

        cout << "Moje rezerwacje:" << endl;

        if (mojeRez.empty()) {
            cout << "Brak aktywnych rezerwacji." << endl;
        } else {
            for (auto r : mojeRez) {
                cout << "ID: " << r->getId()
                << " | Auto: " << r->getSamochod()->getMarka() << " " << r->getSamochod()->getModel()
                << " | Od: " << r->getDataStart()
                << " | Do: " << r->getDataKoniec()
                << " | Status: " << r->getStatus() << endl;
            }
        }
    }

    void Pracownik::ocenPojazd(OcenaStanu& serwis, KatalogSamochodow& katalog, int idSamochodu, int ocena) {
        serwis.ocenSamochod(katalog, idSamochodu, ocena);
    }

    void Pracownik::zglosProblem(OcenaStanu& serwis, Dokumentacja& dok, int idSamochodu, string typZgloszenia, string opis, string data) {
        if (typZgloszenia == "AWARIA") {
            serwis.zglosAwarie(dok, idSamochodu, opis, data);
        } else if (typZgloszenia == "SZKODA") {
            serwis.zglosSzkode(dok, idSamochodu, opis, data);
        }
    }

    void Pracownik::wystawProtocol(Dokumentacja& dok, Rezerwacja* rezerwacja) {
        if (!rezerwacja) {
            cout << "Brak zakonczonej rezerwacji." << endl;
            return;
        }
       //
    }
