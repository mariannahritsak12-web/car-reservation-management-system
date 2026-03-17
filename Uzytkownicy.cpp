#include "Uzytkownicy.h"
#include "Uzytkownik.h"
#include <iostream>

Uzytkownicy::Uzytkownicy() {}

Uzytkownicy::~Uzytkownicy() {
    for (Uzytkownik* u : pracownicy) {
        delete u;
    }
    pracownicy.clear();
}

bool Uzytkownicy::dodajUzyt(Uzytkownik* u) {
    if (u == nullptr) return false;
    pracownicy.push_back(u);
    cout << "Dodano uzytkownika" << endl;
    return true;
}

bool Uzytkownicy::usunUzyt(int idUzytkownika) {
    for (auto i = pracownicy.begin(); i != pracownicy.end(); ++i) {
        if ((*i)->getId() == idUzytkownika) {
            delete *i;
            pracownicy.erase(i);
            return true;
        }
    }
    return false;
}

vector<Uzytkownik*> Uzytkownicy::pobierzWszystkieUzyt() const {
    return pracownicy;
}
