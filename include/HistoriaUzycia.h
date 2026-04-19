#ifndef HISTORIAUZYCIA_H_INCLUDED
#define HISTORIAUZYCIA_H_INCLUDED

using namespace std;
#include <iostream>
#include <string>
#include <vector>

class Rezerwacja;
class Samochod;
class Uzytkownik;

class HistoriaUzycia {
private:
    std::vector<Rezerwacja*> historia;

public:
    HistoriaUzycia();
    ~HistoriaUzycia();

    void dodajWpis(Rezerwacja* zakonczonaRezerwacja);
    void wyswietlHistoriePojazdu(int idSamochodu) const;
    void wysiwetlHistorieUzytkownika(int idUzytkownika)const;
    void wysiwetlCalaHistorie() const;
};

#endif
