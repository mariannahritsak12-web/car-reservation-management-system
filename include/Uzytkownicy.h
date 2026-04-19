#ifndef UZYTKOWNICY_H_INCLUDED
#define UZYTKOWNICY_H_INCLUDED

#include "Uzytkownik.h"

using namespace std;
#include <iostream>
#include <string>
#include <vector>

class Uzytkownicy {
private:
    std::vector<Uzytkownik*> pracownicy;

public:
    Uzytkownicy();
    ~Uzytkownicy();

    bool dodajUzyt(Uzytkownik* u);
    bool usunUzyt(int idUzytkownika);
    vector<Uzytkownik*> pobierzWszystkieUzyt() const;
};

#endif
