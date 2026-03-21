#ifndef PRACOWNIK_H_INCLUDED
#define PRACOWNIK_H_INCLUDED

#include "Uzytkownik.h"

using namespace std;
#include <iostream>
#include <string>
#include <vector>

class ListaRezerwacji;
class KatalogSamochodow;
class OcenaStanu;
class Dokumentacja;
class Samochod;
class Rezerwacja;

class Pracownik : public Uzytkownik {
private:
    string dzial;

public:
    Pracownik(int id, const string& imie, const string& nazwisko, const string& login, const string& haslo, const string& dzial);

    void zarezerwujSamochod(ListaRezerwacji& lista, Samochod* samochod, string dataStart, string dataKoniec);
    void anulujRezerwacje(ListaRezerwacji& lista, int idRezerwacji);
    void przedluzRezerwacje(ListaRezerwacji& lista, int idRezerwacji, const string& NowaDataKoniec);
    void przegladajRezerwacje(ListaRezerwacji& lista, int idUzytkownika) const;

    void wyszukajSamochod(KatalogSamochodow& katalog, string kryteria);
    void przegladajSamochody(KatalogSamochodow& katalog) const;
    void przegladajSzczegoly(KatalogSamochodow& katalog, int idSamochodu) const;

    void ocenPojazd(OcenaStanu& serwis, KatalogSamochodow& katalog, int idSamochodu, int ocena);
    void zglosProblem(OcenaStanu& serwis, Dokumentacja& dok, int idSamochodu, string typZgloszenia, string opis, string data);

    void wystawProtocol(Dokumentacja& dok, Rezerwacja* rezerwacja);

    string getRola() const override {
        return "Pracownik";
    }
};

#endif
