#include "KatalogSamochodow.h"
#include "Samochod.h"
#include <iostream>

using namespace std;

KatalogSamochodow::KatalogSamochodow()
    {
        cout << "Utworzono katalog samochodow." << endl;
    }


KatalogSamochodow::~KatalogSamochodow() {
  for (Samochod* s : flota) {
        delete s;
    }
    flota.clear();
    cout << "Flota zostala wyczyszczona." << endl;
}

bool KatalogSamochodow::dodajSam(Samochod* samochod) {
    if (samochod == nullptr) {
        return false;
    }

    for (const auto& s : flota) {
        if (s->getId() == samochod->getId()) {
            cout << "Samochod o takim ID jusz istnieje." << endl;
            delete samochod;
            return false;
        }
    }

    flota.push_back(samochod);
    cout << "Dodano samochod do katalogu." << endl;
    return true;
}

bool KatalogSamochodow::usunSam(int idSamochodu) {
    for (auto i = flota.begin(); i != flota.end(); ++i) {
        if ((*i)->getId() == idSamochodu) {
            delete *i;
            flota.erase(i);
            cout << "Samochod zostal usuniety." << endl;
            return true;
        }
     }
     return false;
}

bool KatalogSamochodow::wyszukajSam(const string& kryterium) const {
    bool znaleziono = false;

    for (const auto& s : flota) {
        if (s->getMarka() == kryterium || s->getModel() == kryterium) {
            cout << "ID: " << s->getId() << " " << s->getMarka() << " " << s->getModel() << endl;
            znaleziono = true;
        }
    }

    if (!znaleziono) {
        cout << "Nie znaleziono pojazdow spelniajacych kryteria." << endl;
    }

    return znaleziono;
}

Samochod* KatalogSamochodow::pobierzSamochod(int idSamochodu) const {
    for(auto s : flota) {
        if(s->getId() == idSamochodu) {
            return s;
        }
    }
    return nullptr;
}

vector<Samochod*> KatalogSamochodow::pobierzWszystkieSam() const {
    return flota;
}

bool KatalogSamochodow::zmienStatusSamochodu(int idSamochodu, const string& nowyStatus) {
    Samochod* s = pobierzSamochod(idSamochodu);
    if(s != nullptr) {
        s->ustawStatus(nowyStatus);
        return true;
    }
    return false;
}


