#include "Administrator.h"
#include "ListaRezerwacji.h"
#include "KatalogSamochodow.h"
#include "Dokumentacja.h"
#include "Uzytkownicy.h"
#include "Kalendarz.h"
#include "Samochod.h"
#include "Rezerwacja.h"
#include "WpisWKalendarzu.h"
#include "TypEkspoloatacji.h"

#include <iostream>
using namespace std;


Administrator::Administrator(int id, const string& imie, const string& nazwisko, const string& login, const string& haslo, const string& stanowisko) :
    Uzytkownik(id, imie, nazwisko, login, haslo), stanowisko(stanowisko) {}

    void Administrator::dodajSamochod(KatalogSamochodow& katalog, Samochod* nowySamochod) {
        katalog.dodajSam(nowySamochod);

        cout << "Dodano nowy samochod." << endl;
    }
    void Administrator::usunSamochod(KatalogSamochodow& katalog, int idSamochodu) {
        if (katalog.usunSam(idSamochodu)) {
            cout << "Samochod zostal usuniety." << endl;
        } else {
            cout << "Nie znaleziono samochodu o podanym ID." << endl;
        }
    }

    void Administrator::zmienStatusSamochodu(KatalogSamochodow* katalog, int idSamochodu, const string& nowyStatus) {
        if (katalog) {
            katalog->zmienStatusSamochodu(idSamochodu, nowyStatus);
        }
    }
    void Administrator::przegladajSamochody(KatalogSamochodow& katalog) {
        auto flota = katalog.pobierzWszystkieSam();

        if (flota.empty()) {
            cout << "Brak samochodow w katalogu." << endl;
            return;
        }

        cout << "KATALOG SAMOCHODOW" << endl;
        for (auto s : flota) {
            cout << "ID: " << s->getId() << " | " << s->getModel() << " | Status: "  << s->getStatus() << endl;
        }
    }
    void Administrator::edytujSamochod(KatalogSamochodow& katalog, const string& nowaMarka, const string& nowyModel, int zmienRok, int zmienMiejsca) {
        //
    }
    void Administrator::usunRezerwacje(ListaRezerwacji& lista, int idRezerwacji) {
        lista.usunRez(idRezerwacji);
    }
    void Administrator::przegladajRezerwacje(ListaRezerwacji& lista) {
        auto rezerwacje = lista.pobierzWszystkieRez();

        if (rezerwacje.empty()) {
            cout << "Brak rezerwacji." << endl;
            return;
        }

        cout << "LISTA REZERWACJI" << endl;
        for (auto r : rezerwacje) {
            cout << "ID: " << r->getId() << " | Auto ID: " << r->getSamochod()->getId() << " | Od: " << r->getDataStart() << " | Do: "  << r->getDataKoniec() << endl;
        }
    }

    // LOGIKA ZARZADZANIA KALENDARZEM - testowane

    void Administrator::edytujKalendarz(Kalendarz& kalendarz, int idWpisu, const string& nowaData, typWpisu& zmienTyp, const string& nowyOpis, double nowyKoszt) {
    vector<WpisWKalendarzu*> lista = kalendarz.pobierzWszystkieWpisy();

    bool znaleziono = false;

    for (auto wpis : lista) {
        if (wpis->getId() == idWpisu) {
            wpis->setDataPlanowana(nowaData);
            wpis->setTyp(zmienTyp);
            wpis->setOpis(nowyOpis);
            wpis->setKoszt(nowyKoszt);

            cout << "Zaktualizowano wpis." << endl;
            znaleziono = true;
            break;
        }
    }

    if (!znaleziono) {
        cout << "Nie znaleziono wpisu o podanym ID." << endl;
    }
    }

    void Administrator::oznaczJakoZrealoziwane(Kalendarz& kalendarz, int idWpisu) {
        auto lista = kalendarz.pobierzWszystkieWpisy();

        for (auto wpis : lista) {
            if( wpis->getId() == idWpisu) {
                wpis->oznaczZrealizowane("Zrealizowane");
                cout << "Zadanie zostalo oznaczone jako zrealizowane" << endl;
                return;
            }
        }
        cout << "Nie znaleziono wpisu o ID " << idWpisu << endl;
    }

    void Administrator::usunWydarzenie(Kalendarz& kalendarz, int idWpisu) {
        kalendarz.usunWpis(idWpisu);
    }

    void Administrator::przegladajKalendarz(Kalendarz& kalendarz) {
        auto lista = kalendarz.pobierzWszystkieWpisy();
        if(lista.empty()) cout << "Brak wydarzen." << endl;
                for(auto w : lista) {
                string nazwaTypu;
                switch(w->getTyp()) {
                    case 0: nazwaTypu = "PRZEGLAD"; break;
                    case 1: nazwaTypu = "TANKOWANIE"; break;
                    case 2: nazwaTypu = "SERWIS"; break;
                    default: nazwaTypu = "INNY"; break;
                }

                cout << "ID: " << w->getId()
                     << " | Data: " << w->getDataPlanowana()
                     << " | Typ: " << nazwaTypu
                     << " | Opis: " << w->getOpis()
                     << " | Status: " << w->getStatus()
                     << endl;
            }
    }

    void Administrator::zaplanujZdarzenie(Kalendarz& kalendarz, WpisWKalendarzu* wpis) {
        kalendarz.dodajWpis(wpis);
    }

    void Administrator::monitorujTerminy(Kalendarz& kalendarz) {
        cout << "Lista nadchodzacych wydarzen: " << endl;

        vector<WpisWKalendarzu*> nadchodzace = kalendarz.pobierzNadchodzaceWpisy();

        if (nadchodzace.empty()) {
            cout << "Brak nadchodzacych wydarzen." << endl;
            return;
        }

        for (auto w : nadchodzace) {
            cout << "Data: " << w->getDataPlanowana()
            << " | Typ: " << (w->getTyp() == 0 ? "PRZEGLAD" : "TANKOWANIE")
            << " | Opis: " << w->getOpis()
            << " ID Auta: " << w->getIdSamochodu()
            << endl;
        }
    }
    void Administrator::obliczKosztyEksploatacji(Kalendarz& kalendarz, int idSamochodu) {
        double suma = kalendarz.obliczKoszty(idSamochodu);

        if (suma < 0) {
            cout << "Brak wpisow dla samochodu o ID " << idSamochodu << endl;
        } else {
            cout << "Koszty eksploatacji dla wybranego samochodu o ID " << idSamochodu << " : " << suma << "PLN" << endl;
        }
    }


    void Administrator::dodajDokument(Dokumentacja& dok, Dokument* d) {

    }

    void Administrator::przegladajDokumenty(Dokumentacja& dok) {
        auto dokumenty = dok.pobierzWszyskieDok();

        if (dokumenty.empty()) {
            cout << "Brak dokumentow." << endl;
            return;
        }

        cout << "DOKUMENTACJA" << endl;
        for (auto d : dokumenty) {
            d->wypiszSzczegoly();
        }
    }
    void Administrator::edytujDokument(Dokumentacja& dok, int idDokumentu, const string& nowyTytul, const string& nowyOpis) {
        //
    }
    void Administrator::usunDokument(Dokumentacja& dok, int idDokumentu) {
        if (dok.usunDok(idDokumentu)) {
            cout << "Dokument zostal usuniety." << endl;
        } else {
            cout << "Nie znaleziono dokumentu" << endl;
        }
    }

    void Administrator::dodajUzytkownika(Uzytkownicy& pracownicy, Uzytkownik* u) {
        if (pracownicy.dodajUzyt(u)) {
            cout << "Uzytkownik zostal dodany." << endl;
        }
    }

    void Administrator::usunUzytkownika(Uzytkownicy& pracownicy, int idUzytkownika) {
        if (pracownicy.usunUzyt(idUzytkownika)) {
            cout << "Uzytkownik zostal usuniety." << endl;
        } else {
        cout << "Blad usuwania uzytkownika." << endl;
        }
    }
    void Administrator::przegladajUzytkownikow(Uzytkownicy& pracownicy) {
        //
    }
    void Administrator::edytujUzytkownika(Uzytkownicy& pracownicy, const string& zmienImie, const string& zmienNazwisko) {
        //
    }
/*
    void Administrator::zarchiwizujRezerwacje(ListaRezerwacji& lista, HistoriaUzycia& historia, int idRezerwacji) {
        Rezerwacja* r = lista.pobierzDlaUzytkownika(idRezerwacji);
        if (r) {
            historia.dodajRekord(r);
            lista.usunRez(idRezerwacji);
        }
    }
    void Administrator::wyswietlHistorieUzycia() {
        //
    }

*/
