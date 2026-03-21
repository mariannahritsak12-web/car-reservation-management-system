#include <iostream>
#include "InterfaceProvider.h"
#include "Kalendarz.h"
#include "KatalogSamochodow.h"
#include "Uzytkownicy.h"
#include "ListaRezerwacji.h"
#include "Administrator.h"
#include "Pracownik.h"
#include "Samochod.h"
using namespace std;

int main() {
    Kalendarz kalendarz;
    KatalogSamochodow katalog;
    Uzytkownicy uzytkownicy;
    ListaRezerwacji rezerwacje;


    Administrator admin(1, "Anna", "Zarzadzajaca", "admin", "admin123", "Zarzad");
    Pracownik pracownik(1, "Jan", "Kowalski", "pracownik", "pracownik123", "Handlowiec");


    Samochod* auto1 = new Samochod(0, "Toyota", "Corolla", 2015, 4, "Dostepny", 5000);
    Samochod* auto2 = new Samochod(2, "Ford", "Focus", 2010, 4, "Serwis", 1000);
    Samochod* auto3 = new Samochod(3, "Skoda", "Octavia", 2022, 5, "Dostepny", 20000);


    katalog.dodajSam(auto1);
    katalog.dodajSam(auto2);
    katalog.dodajSam(auto3);

    cout << "Zaladowano dane testowe (3 samochody)." << endl;


    ConsoleInterfaceProvider interfejs(kalendarz, katalog, uzytkownicy, rezerwacje, admin, pracownik);

    interfejs.run();

    return 0;
}
