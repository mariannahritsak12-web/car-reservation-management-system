#include <iostream>
#include <string>
#include "Kalendarz.h"
#include "WpisWKalendarzu.h"
#include "Administrator.h"

using namespace std;

class InterfaceKalendarz {
private:
    Kalendarz& kalendarz;
    Administrator& administrator;

public:
    explicit InterfaceKalendarz(Kalendarz& k, Administrator& admin) : kalendarz(k), administrator(admin) {}

    //Menu do zarzadzania kalendarzem
    void wyswietlMenu() const {
        cout << "===Zarzadzanie kalendarzem===" << endl;
        cout << "1. Zaplanuj wydarzenie(PRZEGLAD, TANKOWANIE, SERWIS)" << endl;
        cout << "2. Wyswietl wszystkie wydarzenia" << endl;
        cout << "3. Edytuj dane wpisu" << endl;
        cout << "4. Usun wydarzenie" << endl;
        cout << "5. Oblicz koszty eskploatacji" << endl;
        cout << "6. Monitoruj terminy" << endl;
        cout << "7. Oznacz zadanie jako zrealizowane" << endl;
        cout << "0. Wyjdz" << endl;
        cout << "Wybierz opcje: ";
    }

    // Wyswietlanie
    void uruchom() {
        int wybor = -1;
        while(wybor != 0) {
            wyswietlMenu();
            if (!(cin >> wybor)) {
                cout << "Nieprawidlowe dane. Sprobuj ponownie." << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }

            switch(wybor) {
            case 1: {
                int id, idSamochodu;
                double koszt;
                string data, opis;
                typWpisu typ;

                cout << "Wpisz ID: "; cin >> id;
                cout << "Wpisz ID Samochodu: "; cin >> idSamochodu;
                cout << "Wpisz date: "; cin >> data;

                int wyborTypu;
                cout << "Podaj typ (0-PRZEGLAD, 1-TANKOWANIE, 2-SERWIS): ";
                cin >> wyborTypu;
                typ = (typWpisu)wyborTypu;

                cout << "Podaj koszt: "; cin >> koszt;

                cout << "Opis: ";
                cin.ignore();
                getline(cin, opis);

                WpisWKalendarzu* nowyWpis = new WpisWKalendarzu(id, idSamochodu, data, typ, opis, koszt);

                administrator.zaplanujZdarzenie(kalendarz, nowyWpis);

                cout << "Dodano wydarzenie do kalendarza." << endl;

                break;
            }
            case 2: {
                administrator.przegladajKalendarz(kalendarz);
                break;
            }
            case 3: {
                int idWpisu;
                string nowaData, nowyOpis;
                double nowyKoszt;
                int nowyTypInt;
                typWpisu nowyTyp;

                cout << "Podaj ID wpisu do edycji: "; cin >> idWpisu;
                cout << "Podaj nowa date: "; cin >> nowaData;
                cout << "Podaj nowy typ (0-2): "; cin >> nowyTypInt;
                nowyTyp = (typWpisu)nowyTypInt;
                cout << "Podaj nowy koszt"; cin >> nowyKoszt;

                cout << "Podaj nowy opis: ";
                cin.ignore();
                getline(cin, nowyOpis);

                administrator.edytujKalendarz(kalendarz, idWpisu, nowaData, nowyTyp, nowyOpis, nowyKoszt);
                break;
            }
            case 4:
                int idWpisu;

                cout << "Podaj ID wpisu do usuniecia: "; cin >> idWpisu;

                administrator.usunWydarzenie(kalendarz, idWpisu);
            case 5: {
                int idSamochodu;

                cout << "Oblicz koszty eksploatacj dla samochodu(ID): "; cin >> idSamochodu;
                administrator.obliczKosztyEksploatacji(kalendarz, idSamochodu);
                break;
            }
            case 6:
                administrator.monitorujTerminy(kalendarz);
                break;
            case 7:
                int id;

                cout << "Wykonano zadanie(ID): "; cin >> id;
                administrator.oznaczJakoZrealoziwane(kalendarz, id);
            case 0:
                cout << "Koniec testu" << endl;
                break;
            default:
                cout << "Zla opcja." << endl;
            }
        }
    }
};

/*int main() {
    Kalendarz mojKalendarz;
    Administrator admin(1, "Admin", "Systemowy", "admin", "admin", "manager");
    InterfaceKalendarz interfejsTestowy(mojKalendarz, admin);
    interfejsTestowy.uruchom();
}
*/
