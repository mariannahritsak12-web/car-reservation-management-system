#include "Protocol.h"
#include <iostream>

Protocol::Protocol(int id, int idSamochodu, const string& dataUtworzenia, double przebieg, double paliwo, bool czysty, const string& uszkodzenia) :
    Dokument(id, idSamochodu, "Protokol Zdawczo-Odbiorczy", uszkodzenia, "Protocol", dataUtworzenia), przebieg(przebieg), poziomPaliwa(paliwo), czyCzysty(czysty), listaUszkodzen(uszkodzenia) {}

    void Protocol::wypiszSzczegoly() const {
        Dokument::wypiszSzczegoly();

        cout << "Szczegoly protokolu:" << endl;
        cout << "Przebieg: " << przebieg << endl;
        cout << "Paliwo: " << poziomPaliwa * 100 << "%" << endl;
        cout << "Czystosc: " << (czyCzysty ? "Czysty" : "Brudny") << endl;
        cout << "Uszkodzenia: " << (listaUszkodzen.empty() ? "Brak" : listaUszkodzen) << endl;
    }

    // GET
    double Protocol::getPoziomPaliwa() const {
        return poziomPaliwa;
    }
    double Protocol::getPrzebieg() const {
        return przebieg;
    }
    string Protocol::getListaUszkodzen() const {
        return listaUszkodzen;
    }
