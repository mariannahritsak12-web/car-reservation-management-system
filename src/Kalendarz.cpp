#include "Kalendarz.h"
#include "WpisWKalendarzu.h"
#include <iostream>

Kalendarz::Kalendarz() {}

Kalendarz::~Kalendarz() {
    for (WpisWKalendarzu* w : wpisy) {
        delete w;
    }
    wpisy.clear();
    cout << "Kalendarz zostal wyczyszczony." << endl;
}

bool Kalendarz::dodajWpis(WpisWKalendarzu* wpis) {
    if(wpis != nullptr) {
        wpisy.push_back(wpis);
        return true;
    }
    return false;
}

bool Kalendarz::usunWpis(int idWpisu) {
    for (auto i = wpisy.begin(); i != wpisy.end(); ++i) {
        if ((*i)->getId() == idWpisu) {
            delete *i;
            wpisy.erase(i);
            cout << "Wpis zostal usuniety." << endl;
            return true;
        }
    }
    return false;
}

vector<WpisWKalendarzu*> Kalendarz::pobierzNadchodzaceWpisy() {
    vector<WpisWKalendarzu*> wynik;

    for (auto wpis : wpisy) {
        if (!wpis->czyZrealizowane()) {
            wynik.push_back(wpis);
        }
    }

    return wynik;
}

vector<WpisWKalendarzu*> Kalendarz::pobierzWszystkieWpisy() const {
    return wpisy;
}

double Kalendarz::obliczKoszty(int idSamochodu) {
    double suma = 0.0;
    bool znalezionoWpis = false;

    for (auto wpis : wpisy) {
        if (wpis->getIdSamochodu() == idSamochodu) {
            suma += wpis->getKoszt();
            znalezionoWpis = true;
        }
    }

    if (!znalezionoWpis) {
        return -1;
    }

    return suma;
}


