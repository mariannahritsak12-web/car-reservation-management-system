#include <iostream>
#include <cassert>
#include "Samochod.h"

using namespace std;

void test_Jednostkowy_Samochod() {
    cout << "Start: Test Jednostkowy klasy Samochod" << endl;

    Samochod autoTestowe(1, "Toyota", "Corolla", 2020, 5, "Dostepny", 50000);

    assert(autoTestowe.czyDostepny() == true && "Blad: Nie udalo sie zweryfikowac dostepnosc");

    autoTestowe.ustawStatus("Zarezerwowany");

    assert(autoTestowe.czyDostepny() == false && "Blad: nie udalo sie zweryfikowac dostepnosc");

    cout << "Koniec testu" << endl;
}

int main() {
    test_Jednostkowy_Samochod();
    return 0;
}
