#include <iostream>
#include <cassert>
#include "src/Samoshod"
#include "src/KatalogSamochodow.h"

using namespace std;

void test_Integracyjny_KatalogSamochodow() {
    cout << "Start: Test Integracyjny klas KatalogSamochodow i Samochod" << endl;

    KatalogSamochodow katalog;
    Samochod* s1 = new Samochod(100, "Ford", "Focus", 2019, 5, "Dostepny", 120000);

    bool dodano = katalog.dodajSam(s1);
    assert(dodano && "Blad: nie udalo sie dodac samochodu.");

    Samochod* pobrany = katalog.pobierzSamochod(100);

    assert(pobrany != nullptr && "Blad: nie znaleziono dodanego samochodu.");
    assert(pobrany->getModel() == "Focus" && "Blad: Model samochodu sie nie zgadza.");

    cout << "Koniec testu. Test zakonczony sukcesem." << endl;
}

int main() {
    test_Integracyjny_KatalogSamochodow();
    return 0;
}
