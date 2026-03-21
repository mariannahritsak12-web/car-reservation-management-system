#include "Dokumentacja.h"
#include "Dokument.h"
#include <iostream>

Dokumentacja::Dokumentacja() {}

Dokumentacja::~Dokumentacja() {
    for (Dokument* d : dokumenty) {
        delete d;
    }
    dokumenty.clear();
}

bool Dokumentacja::dodajDok(Dokument* d) {
    if (d == nullptr) return false;
    dokumenty.push_back(d);
    return true;
}

bool Dokumentacja::usunDok(int idDokumentu) {
    for (auto i = dokumenty.begin(); i != dokumenty.end(); ++i) {
        if ((*i)->getId() == idDokumentu) {
            delete *i;
            dokumenty.erase(i);
            return true;
        }
    }
    return false;
}

Dokument* Dokumentacja::pobierzDokument(int id) const {
    for (auto d : dokumenty) {
        if (d->getId() == id) {
            return d;
        }
    }
    return nullptr;
}

vector<Dokument*> Dokumentacja::pobierzWszyskieDok() const {
    return dokumenty;
}
