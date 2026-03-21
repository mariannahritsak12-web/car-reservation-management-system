#include "Dokument.h"
#include <iostream>

Dokument::Dokument(int id, int idSamochodu, const string& tytul, const string& opis, const string& typ, const string& dataUtworzenia) :
    id(id), idSamochodu(idSamochodu), tytul(tytul), opis(opis), typ(typ), dataUtworzenia(dataUtworzenia) {}

void Dokument::wypiszSzczegoly() const {
    cout << "Typ dokumentu: " << typ << endl;
    cout << "Tytul: " << tytul << endl;
    cout << "ID: " << id << endl;
    cout << "Dotyczy samochodu: " << idSamochodu << endl;
    cout << "Opis: " << opis << endl;
    cout << "---------------------" << endl;
    cout << "Data utworzenia: " << dataUtworzenia << endl;
}

//GET
    int Dokument::getId() const {
        return id;
    }
    string Dokument::getTytul() const {
        return tytul;
    }
    string Dokument::getTyp() const {
        return typ;
    }

//SET
    void Dokument::setTytul(const string& nowyTytul) {
        this->tytul = nowyTytul;
    }
    void Dokument::setOpis(const string& nowyOpis) {
        this->opis = nowyOpis;
    }
