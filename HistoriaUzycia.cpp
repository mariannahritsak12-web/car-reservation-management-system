#include "HistoriaUzycia.h"
#include "Rezerwacja.h"
#include "Samochod.h"
#include "Uzytkownik.h"

#include <iostream>
using namespace std;

HistoriaUzycia::HistoriaUzycia() {}
HistoriaUzycia::~HistoriaUzycia() {}
/*
    void HistoriaUzycia::dodajWpis(Rezerwacja* zakonczonaRezerwacja) {
        if (zakonczonaRezerwacja != nullptr) {
            historia.push_back(zakonczonaRezerwacja);
        }
    }

    void HistoriaUzycia::wyswietlHistoriePojazdu(int idSamochodu) const {
        cout << "Historia uzycia pojazdu o ID: " << idSamochodu << endl;
        bool znaleziono = false;

        for (const auto& wpis : historia) {
            if (wpis->getSamochod()->getId() == idSamochodu) {
                cout << "ID Rezerwacji: " << wpis->getId()
                << " | Data: " << wpis->getDataStart() << " - " << wpis->getDataKoniec()
                 << " | Status: " << wpis->getStatus()
                 << endl;
                 znaleziono = true;
            }
        }
        if (!znaleziono) {
            cout << "Brak wpisow w historii dla tego pojazdu." << endl;
        }
    }

    void HistoriaUzycia::wysiwetlHistorieUzytkownika(int idUzytkownika)const {
        cout << "Historia uzycia uzytkownika o ID: " << idSamochodu << endl;
        bool znaleziono = false;
        //
    }

    void HistoriaUzycia::wysiwetlCalaHistorie() const {
        cout << "HISTORIA UZYCIA FLOTY" << idSamochodu << endl;
        //
    }
*/
