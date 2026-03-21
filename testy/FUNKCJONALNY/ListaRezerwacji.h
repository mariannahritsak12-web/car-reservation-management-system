#ifndef LISTAREZERWACJI_H_INCLUDED
#define LISTAREZERWACJI_H_INCLUDED
#include "Rezerwacja.h"
#include "Samochod.h"

using namespace std;
#include <iostream>
#include <string>
#include <vector>

class ListaRezerwacji {
private:
    std::vector<Rezerwacja*> rezerwacje;

public:
    ListaRezerwacji();
    ~ListaRezerwacji();

    bool dodajRez(Rezerwacja* rezerwacja, bool wymus = false);
    bool anulujRez(int idRezerwacji, int idUzytkownika);
    bool przedluzRez(int idRezerwacji, string nowaData);
    bool usunRez(int id);
    bool czyWolny(int idSamochodu, const string& start, const string& koniec);

    vector<Rezerwacja*> pobierzWszystkieRez();
    vector<Rezerwacja*> pobierzDlaUzytkownika(int idUzytkownika);
};

#endif
