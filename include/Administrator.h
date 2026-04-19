#ifndef ADMINISTRATOR_H_INCLUDED
#define ADMINISTRATOR_H_INCLUDED

using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include "Uzytkownik.h"
#include "TypEkspoloatacji.h"

class ListaRezerwacji;
class KatalogSamochodow;
class Dokumentacja;
class Kalendarz;
class Uzytkownicy;
class WpisWKalendarzu;
class Samochod;
class Dokument;

class Administrator : public Uzytkownik {
private:
    string stanowisko;

public:
    Administrator(int id, const string& imie, const string& nazwisko, const string& login, const string& haslo, const string& stanowisko);

    void dodajSamochod(KatalogSamochodow& katalog, Samochod* nowySamochod);
    void usunSamochod(KatalogSamochodow& katalog, int idSamochodu);
    void zmienStatusSamochodu(KatalogSamochodow& katalog, int idSamochodu, const string& nowyStatus);
    void przegladajSamochody(KatalogSamochodow& katalog);
    void edytujSamochod(KatalogSamochodow& katalog, const string& nowaMarka, const string& nowyModel, int zmienRok, int zmienMiejsca);

    void przypiszSamochod(ListaRezerwacji& lista); //
    void usunRezerwacje(ListaRezerwacji& lista, int idRezerwacji);
    void przegladajRezerwacje(ListaRezerwacji& lista);

    void przegladajKalendarz(Kalendarz& kalendarz);
    void zaplanujZdarzenie(Kalendarz& kalendarz, WpisWKalendarzu* wpis);
    void monitorujTerminy(Kalendarz& kalendarz);
    void obliczKosztyEksploatacji(Kalendarz& kalendarz, int idSamochodu);
    void edytujKalendarz(Kalendarz& kalendarz, int idWpisu, const string& nowaData, typWpisu& zmienTyp, const string& nowyOpis, double nowyKoszt);
    void usunWydarzenie(Kalendarz& kalendarz, int idWpisu);
    void oznaczJakoZrealoziwane(Kalendarz& kalendarz, int idWpisu);


    void przegladajDokumenty(Dokumentacja& dok);
    void dodajDokument(Dokumentacja& dok, Dokument* d);
    void usunDokument(Dokumentacja& dok, int idDokumentu);
    void edytujDokument(Dokumentacja& dok, int idDokumentu, const string& nowyTytul, const string& nowyOpis);

    void dodajUzytkownika(Uzytkownicy& pracownicy, Uzytkownik* u);
    void usunUzytkownika(Uzytkownicy& pracownicy, int idUzytkownika);
    void przegladajUzytkownikow(Uzytkownicy& pracownicy);
    void edytujUzytkownika(Uzytkownicy& pracownicy, const string& zmienImie, const string& zmienNazwisko);

    void zarchiwizujRezerwacje(ListaRezerwacji& lista, int idRezerwacji);
    void wyswietlHistorieUzycia();

    string getRola() const override {
        return "Administrator";
    }
};

#endif
