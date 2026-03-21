#include <iostream>
#include <sstream>
#include <cassert>
#include <string>

#include "Administrator.h"
#include "Pracownik.h"
#include "Kalendarz.h"
#include "WpisWKalendarzu.h"
#include "InterfaceProvider.h"
#include "KatalogSamochodow.h"
#include "ListaRezerwacji.h"
#include "Uzytkownicy.h"


using namespace std;

void test_F01_ObslugaKalendarza() {
    Kalendarz kalendarz;
    KatalogSamochodow katalog;
    Uzytkownicy uzytkownicy;
    ListaRezerwacji rezerwacje;

    Administrator admin(1, "Jan", "Testowy", "admin", "admin123", "Szef");
    Pracownik pracownik(1, "Adam", "Nowak", "pracownik", "pracownik123", "Handlowiec");

    string symulowaneWejscie =
        "1\n"
        "admin\n"
        "admin123\n"

        "1\n"
        "1\n"
        "1\n"
        "1\n"
        "2025-12-20\n"
        "0\n"
        "0\n"

        "Czyszczenie filtrow\n"
        "1\n"
        "2\n"
        "1\n"
        "2025-12-22\n"
        "2\n"
        "4000\n"
        "Zamiana silnika\n"

        "5\n"
        "1\n"

        "2\n"

        "7\n"
        "1\n"

        "2\n"

        "6\n"

        "4\n"
        "2\n"

        "2\n"

        "0\n"
        "0\n"
        "0\n";

        istringstream input(symulowaneWejscie);
        ostringstream output;

        streambuf* old_cin = cin.rdbuf(input.rdbuf());
        streambuf* old_cout = cout.rdbuf(output.rdbuf());

        ConsoleInterfaceProvider interfejs(kalendarz, katalog, uzytkownicy, rezerwacje, admin, pracownik);

        try {
        interfejs.run();
        } catch (...) {
        }

        cin.rdbuf(old_cin);
        cout.rdbuf(old_cout);

        string wynikKonsoli = output.str();

        cout << "Weryfikacja wynikow" << endl;
        cout << wynikKonsoli << endl;

        bool znalezionoSukces = wynikKonsoli.find("Dodano wydarzenie do kalendarza.") != string::npos;
        if (!znalezionoSukces) {
            cout << "Blad: Nie znaleziono komunikatu 'Dodano wydarzenie do kalendarza.' " << endl;

        }
        assert(znalezionoSukces && "Blad: Nie wyswietlono komunikatu o sukcesie!");

        bool opisWpis1 = wynikKonsoli.find("Czyszczenie filtrow") != string::npos;
        bool opisWpis2 = wynikKonsoli.find("Zamiana silnika") != string::npos;
        assert(opisWpis1 && "Blad: Nie znaleziono opisu pierwszego wpisu!");
        assert(opisWpis2 && "Blad: Nie znaleziono opisu drugiego wpisu!");

        bool dataWpis1 = wynikKonsoli.find("2025-12-20") != string::npos;
        bool dataWpis2 = wynikKonsoli.find("2025-12-22") != string::npos;
        assert(dataWpis1 && "Blad: Data nie pojawila sie na liscie!");
        assert(dataWpis2 && "Blad: Data nie pojawila sie na liscie!");

        bool kosztyPoprawne = wynikKonsoli.find("4000PLN") != string::npos || wynikKonsoli.find("4000") != string::npos;
        assert(kosztyPoprawne && "Blad: Obliczenie kosztow jest niepoprawne!");

        bool statusZmieniony = wynikKonsoli.find("Status: Zrealizowane") != string::npos;
        assert(statusZmieniony && "Blad: Status nie zmienil sie na 'Zrealizowane'!");

        bool usunietoWpis = wynikKonsoli.find("Wpis zostal usuniety") != string::npos;
        assert(usunietoWpis && "Blad: Nie pojawil sie komunikat o usunieciu!");

        cout << "\nTest F01 zakonczony sukcesem!" << endl;
}

/*int main() {
    test_F01_ObslugaKalendarza();
    return 0;
}
*/
