#include "ListaRezerwacji.h"
#include "Rezerwacja.h"
#include <iostream>

ListaRezerwacji::ListaRezerwacji() {}

ListaRezerwacji::~ListaRezerwacji() {
    for (Rezerwacja* r : rezerwacje) {
        delete r;
    }
    rezerwacje.clear();
    cout << "Wszystkie rezerwacje zostaly wyczyszczone" << endl;
}

bool ListaRezerwacji::czyWolny(int idSamochodu, const string& start, const string& koniec) {
    for (const auto& r : rezerwacje) {
        if (r->czyKoliduje(idSamochodu, start, koniec)) {
            //if (start < r->getDataKoniec() && koniec > r->getDataStart()) {
              //  return false;
            //}
            return false;
        }
    }
    return true;
}


bool ListaRezerwacji::dodajRez(Rezerwacja* r, bool wymus) {
    if (r == nullptr) return false;

    int idSam = r->getSamochod()->getId();

    if (!wymus && !czyWolny(idSam, r->getDataStart(), r->getDataKoniec())) {
        cout << "Samochod nie jest dostepny w tym terminie." << endl;

        delete r;

        return false;
    }

    rezerwacje.push_back(r);
    cout << "Dodano rezerwacje." << endl;
    return true;
}

bool ListaRezerwacji::anulujRez(int idRezerwacji, int idUzytkownika) {
    for (auto i = rezerwacje.begin(); i != rezerwacje.end(); ++i) {
        if ((*i)->getId() == idRezerwacji && (*i)->getUzytkownik()->getId() == idUzytkownika) {
            (*i)->zmienStatusRez("Anulowana");
            delete *i;
            rezerwacje.erase(i);
            return true;
        }
    }
    return false;
}
/*
bool ListaRezerwacji::przedluzRez(int idRezerwacji, string nowaData) {
    for (auto& r : rezerwacje) {
        if (r->getId() == idRezerwacji) {
            if (nowaData <= r->getDataKoniec()) {
                cout << "Nowa data musi byc pozniejsza niz obecna." << endl;
                return false;
            }

            int idSam = r->getSamochod()->getId();
            string start = r->getDataStart();

            for (const auto& inna : rezerwacje) {
                if (inna->getId() == idRezerwacji) continue;
                if (inna->getSamochod()->getId() != idSam);

            }
        }
    }
}
*/
bool ListaRezerwacji::usunRez(int idRezerwacji) {
    for (auto i = rezerwacje.begin(); i != rezerwacje.end(); ++i) {
        if ((*i)->getId() == idRezerwacji) {
            delete *i;
            rezerwacje.erase(i);
            cout << "Uzunieto rezerwacje." << endl;
            return true;
        }
    }
    cout << "Nie znaleziono rezerwacji o podanym ID." << endl;
    return false;
}

vector<Rezerwacja*> ListaRezerwacji::pobierzWszystkieRez() {
    return rezerwacje;
}

vector<Rezerwacja*> ListaRezerwacji::pobierzDlaUzytkownika(int idUzytkownika) {
    vector<Rezerwacja*> wynik;

    for (auto r : rezerwacje) {
        if (r->getUzytkownik()->getId() == idUzytkownika) {
            wynik.push_back(r);
        }
    }
    return wynik;
}
