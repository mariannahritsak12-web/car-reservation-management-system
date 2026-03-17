#include "InterfaceProvider.h"
#include "Kalendarz.h"
#include "WpisWKalendarzu.h"
#include "Administrator.h"
#include "Pracownik.h"
#include "Uzytkownik.h"
#include "ListaRezerwacji.h"
#include "Rezerwacja.h"
#include "KatalogSamochodow.h"
#include "Samochod.h"
#include "Uzytkownicy.h"
#include "TypEkspoloatacji.h"
#include <vector>
#include <string>
#include <iostream>
#include <limits>

using namespace std;

ConsoleInterfaceProvider::ConsoleInterfaceProvider(Kalendarz& k, KatalogSamochodow& kat, Uzytkownicy& u, ListaRezerwacji& rez, Administrator& admin, Pracownik& prac) :
    kalendarz(k), katalog(kat), uzytkownicy(u), rezerwacje(rez), administrator(admin), pracownik(prac) {}

    //POBIERZ DANE OD UZYTKOWNIKA
    int ConsoleInterfaceProvider::pobierzLiczbe(string komunikat) const {
        int liczba;
        cout << komunikat;
        while (!(cin >> liczba)) {
            cout << "To nie jest liczba. Sprobuj ponownie: ";
            cin.clear();
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return liczba;
    }
    string ConsoleInterfaceProvider::pobierzTekst(string komunikat) const {
        string tekst;
        cout << komunikat;
        getline(cin, tekst);
        return tekst;
    }

void ConsoleInterfaceProvider::run() {
    bool dziala = true;

    while (dziala) {
        dziala = wyswietlMenuGlowne();
    }
}

    void ConsoleInterfaceProvider::wyswietlMenuAdministratora() {
        int wybor = -1;
        while (wybor != 0) {
            cout << "===Panel Administratora===" << endl;
            cout << "1. Zarzadzaj Kalendarzem" << endl;
            cout << "2. Zarzadzaj Flota" << endl;
            cout << "3. Zarzadzaj Dokumentacja" << endl;
            cout << "4. Zarzadzaj Rezerwacjami" << endl;
            cout << "5. Zarzadzaj Uzytkownikami" << endl;
            cout << "0. Wyloguj" << endl;

            wybor = pobierzLiczbe("Wybierz opcje: ");

            switch(wybor) {
            case 1:
                submenuZarzadzajKalendarzem();
                break;
            case 2:
                submenuZarzadzajFlota();
                break;
            case 3:
                submenuZarzadzajDokumentacja();
                break;
            case 4:
                submenuZarzadzajRezerwacjami();
                break;
            case 5:
                submenuZarzadzajUzytkownikami();
                break;
            case 0:
                cout << "Wylogowywanie..." << endl;
                return;
            }
        }
    }

   void ConsoleInterfaceProvider::wyswietlMenuPracownika() {
        int wybor = -1;

        while (wybor != 0) {
            cout << "===Panel Pracownika===" << endl;
            cout << "1. Zarezerwuj samochod" << endl;
            cout << "2. Podglad rezerwacji" << endl;
            cout << "0. Wyloguj" << endl;

            wybor = pobierzLiczbe("Wybierz opcje: ");

            switch(wybor) {
            case 1: {
                pracownik.przegladajSamochody(katalog);
                cout << "Rezerwacja samochodu" << endl;

                int idSamochodu = pobierzLiczbe("Podaj ID Samochodu do rezerwacji: ");
                string dataStart, dataKoniec;

                Samochod* autoDoRez = katalog.pobierzSamochod(idSamochodu);

                if (autoDoRez == nullptr) {
                    cout << "Nie ma samochodu o takim ID." << endl;
                    break;
                }

                if (autoDoRez->getStatus() != "Dostepny") {
                    cout << "Ten samochod jest niedostepny!" << endl;
                    cout << "Status samochodu: " << autoDoRez->getStatus() << endl;
                    break;
                }

                cout << "Podaj date poczatku rezerwacji(RRRR-MM-DD): "; cin >> dataStart;
                cout << "Podaj date zakonczenia rezerwacji(RRRR-MM-DD): "; cin >> dataKoniec;

                pracownik.zarezerwujSamochod(rezerwacje, autoDoRez, dataStart, dataKoniec);
                break;
            }
            case 2:
                submenuPodgladRezerwacji();
                break;
            case 0:
                cout << "Wylogowywanie..." << endl;
                return;
            }
        }
   }


    //PODMENU DO ZARZADZANIA KALENDARZEM
    void ConsoleInterfaceProvider::submenuZarzadzajKalendarzem() const {
        int wybor = -1;

        while(wybor != 0) {
            cout << "===Zarzadzanie kalendarzem===" << endl;
            cout << "1. Zaplanuj wydarzenie(PRZEGLAD, TANKOWANIE, SERWIS)" << endl;
            cout << "2. Wyswietl wszystkie wydarzenia" << endl;
            cout << "3. Edytuj dane wpisu" << endl;
            cout << "4. Usun wydarzenie" << endl;
            cout << "5. Oblicz koszty eskploatacji" << endl;
            cout << "6. Monitoruj terminy" << endl;
            cout << "7. Oznacz zadanie jako zrealizowane" << endl;
            cout << "0. Powrot" << endl;
            cout << "Wybierz opcje: ";

            if (!(cin >> wybor)) {
                cout << "Nieprawidlowe dane. Sprobuj ponownie." << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }

            switch(wybor) {
            case 1: {
                int id = pobierzLiczbe("Wpisz ID wpisu: ");
                int idSamochodu = pobierzLiczbe("Wpisz ID Samochodu: ");
                string data = pobierzTekst("Wpisz date(RRR-MM-DD): ");
                int wyborTypu = pobierzLiczbe("Podaj typ (0 - PRZEGLAD, 1 - TANKOWANIE, 2 - SERWIS): ");
                typWpisu typ = (typWpisu)wyborTypu;

                double koszt;
                cout << "Podaj koszt(PLN): ";
                if (!(cin >> koszt)) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    koszt = 0;
                }
                cin.ignore(1000, '\n');

                string opis = pobierzTekst("Opis: ");

                WpisWKalendarzu* nowyWpis = new WpisWKalendarzu(id, idSamochodu, data, typ, opis, koszt);

                administrator.zaplanujZdarzenie(const_cast<Kalendarz&>(kalendarz), nowyWpis);

                cout << "Dodano wydarzenie do kalendarza." << endl;

                break;
            }
            case 2: {
                administrator.przegladajKalendarz(kalendarz);
                break;
            }
            case 3: {
                int idWpisu = pobierzLiczbe("Podaj ID wpisu do edycji: ");
                string nowaData = pobierzTekst("Podaj nowa date: ");
                int nowyTypInt = pobierzLiczbe("Podaj nowy typ (0-2): ");

                string nowyOpis = pobierzTekst("Podaj nowy opis: ");
                double nowyKoszt = pobierzLiczbe("Podaj nowy koszt: ");

                typWpisu nowyTyp = (typWpisu)nowyTypInt;
                cin.ignore();

                administrator.edytujKalendarz(kalendarz, idWpisu, nowaData, nowyTyp, nowyOpis, nowyKoszt);
                break;
            }
            case 4: {
                int idWpisu = pobierzLiczbe("Podaj ID wpisu do usuniecia: ");

                administrator.usunWydarzenie(kalendarz, idWpisu);
                break;
            }
            case 5: {
                int idSamochodu = pobierzLiczbe("Oblicz koszty ekspoatacji dla samochodu(ID): ");

                administrator.obliczKosztyEksploatacji(kalendarz, idSamochodu);
                break;
            }
            case 6:
                administrator.monitorujTerminy(kalendarz);
                break;
            case 7: {
                int id = pobierzLiczbe("Wykonano zadanie(ID wpisu): ");

                administrator.oznaczJakoZrealoziwane(kalendarz, id);
                break;
            }
            case 0:
                cout << "Powrot..." << endl;
                break;
            default:
                cout << "Zla opcja." << endl;
            }
        }
    }

   void ConsoleInterfaceProvider::submenuZarzadzajFlota() {
        int wybor = -1;

        while(wybor != 0) {
            cout << "===Zarzadzanie Flota===" << endl;
            cout << "1. Dodaj samochod" << endl;
            cout << "2. Wyswietl flote" << endl;
            cout << "3. Edytuj dane samochodu" << endl;
            cout << "4. Usun samochod" << endl;
            cout << "5. Zmien status samochodu" << endl;
            cout << "0. Powrot" << endl;
            cout << "7. Oznacz zadanie jako zrealizowane" << endl;
            cout << "0. Powrot" << endl;
            cout << "Wybierz opcje: ";

            if (!(cin >> wybor)) {
                cout << "Nieprawidlowe dane. Sprobuj ponownie." << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }

            switch(wybor) {
            case 1:
                int idSamochodu = pobierzLiczbe("Wpisz ID samchodu: "); // Wygenerowaæ ID
                std::string marka = pobierzTekst("Wpisz marke samochodu: ");
                //std:: string model = po

                //Samochod* s1 = new Samochod(idSamochodu, marka, model, rok, miejsca, status, przebieg);
            }
        }
   }

    void ConsoleInterfaceProvider::submenuZarzadzajDokumentacja() {
        cout << "===Zarzadzanie dokumentacja===" << endl;
        cout << "1. Dodaj dokumentacje do samochodu" << endl;
        cout << "2. Wyswietl wszystkie dokumenty" << endl;
        cout << "3. Edytuj dokument" << endl;
        cout << "4. Usun dokumentacje" << endl;
        cout << "5. Wystaw protokol" << endl;
        cout << "0. Powrot" << endl;
        cout << "Wybierz opcje: ";
    }

    void ConsoleInterfaceProvider::submenuZarzadzajRezerwacjami() {
        cout << "===Zarzadzanie Rezerwacjami===" << endl;
        cout << "1. Usun rezerwacje z archiwum" << endl;
        cout << "2. Wyswietl archiwum rezerwacji" << endl;
        cout << "3. Przypisz samochod uzytkownikowi" << endl;
        cout << "0. Powrot" << endl;
        cout << "Wybierz opcje: ";
    }

    void ConsoleInterfaceProvider::submenuZarzadzajUzytkownikami() {
        cout << "===Zarzadzanie Uzytkownikami===" << endl;
        cout << "1. Dodaj nowego uzytkownika" << endl;
        cout << "2. Wyswietl wszystkich uzytkownikow" << endl;
        cout << "3. Edytuj dane uzytkownika" << endl;
        cout << "4. Usun uzytkownika" << endl;
        cout << "0. Powrot" << endl;
        cout << "Wybierz opcje: ";
    }

    // PODMENU DO OPERACJI NAD REZERWACJAMI
    void ConsoleInterfaceProvider::submenuPodgladRezerwacji() {
        int wybor = -1;
        int idPracownika = 1;

        while (wybor != 0) {
            pracownik.przegladajRezerwacje(rezerwacje, idPracownika);

        cout << "1. Anuluj rezerwacje" << endl;
        cout << "2. Przedluz rezerwacje" << endl;
        cout << "3. Ocen stan samochodu" << endl;
        cout << "4. Zglos problem z samochodem" << endl;
        cout << "5. Wystaw protokol" << endl;
        cout << "0. Powrot" << endl;

        wybor = pobierzLiczbe("Wybierz opcje: ");

        switch(wybor) {
        case 1: {
            /*if (mojeRez.empty()) { cout << "Brak rezerwacji do anulowania." << endl; break; }
            int id = pobierzLiczbe("Podaj ID rezerwacji do anulowania: ");
            if(rezerwacje.anulujRez(id, idPracownika))
                cout << "Anulowano." << endl;
            else
                cout << "Nie znaleziono takiej rezerwacji." << endl;*/
            break;
        }
        /*case 2: {
             if (mojeRez.empty()) { cout << "Brak rezerwacji do przedluzenia." << endl; break; }
             int id = pobierzLiczbe("Podaj ID rezerwacji: ");
             string data = pobierzTekst("Podaj nowa date konca: ");
             if(rezerwacje.przedluzRez(id, data))
                cout << "Przedluzono." << endl;
             else
                cout << "Blad przedluzania." << endl;
             break;
        }*/
        case 0:
            cout << "Powrot..." << endl;
            break;
        default:
            cout << "Nieznana opcja." << endl;
        }
    }
}

    //MENU GLOWNE
    bool ConsoleInterfaceProvider::wyswietlMenuGlowne() {
        cout << "===System zarzadzania rezerwacjami samochodow sluzbowych FleetReserve===" << endl;
        cout << "1. Zaloguj jako Administrator" << endl;
        cout << "2. Zaloguj jako Pracownik" << endl;
        cout << "0. Zamnknij program" << endl;

        int wybor = pobierzLiczbe("Wybierz: ");

        switch (wybor) {
        case 1: {
            cout << "Logowanie administratora" << endl;
            string login = pobierzTekst("Login: ");
            string haslo = pobierzTekst("Haslo: ");

            if (login == "admin" && haslo == "admin123") {
                cout << "Zalogowano pomyslnie!" << endl;
                wyswietlMenuAdministratora();
            } else {
                cout << "Niepoprawny login lub haslo." << endl;
            }
            break;
        }
        case 2: {
            cout << "Logowanie pracownika" << endl;
            string login = pobierzTekst("Login: ");

            if (login == "pracownik") {
                cout << "Zalogowano pomyslnie!" << endl;
                wyswietlMenuPracownika();
            } else {
                cout << "Niepoprawny login lub haslo." << endl;
            }
            break;
        }
        case 0:
            cout << "Zamykanie programu..." << endl;
            return false;
        default:
            cout << "Zla opcja." << endl;
        }
        return true;
    }

