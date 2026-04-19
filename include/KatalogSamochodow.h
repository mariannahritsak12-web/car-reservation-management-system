#ifndef KATALOGSAMOCHODOW_H_INCLUDED
#define KATALOGSAMOCHODOW_H_INCLUDED

using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include "Samochod.h"

class KatalogSamochodow {
private:
    std::vector<Samochod*> flota;

public:
    KatalogSamochodow();
    ~KatalogSamochodow();

    bool dodajSam(Samochod* samochod);
    bool usunSam(int idSamochodu);
    bool wyszukajSam(const string& kryterium) const;
    Samochod* pobierzSamochod(int idSamochodu) const;
    vector<Samochod*> pobierzWszystkieSam() const;
    bool zmienStatusSamochodu(int idSamochodu, const string& nowyStatus);
    bool wyswietlDostepneSam();
};

#endif
