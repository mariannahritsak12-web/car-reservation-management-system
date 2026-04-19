#ifndef DOKUMENTACJA_H_INCLUDED
#define DOKUMENTACJA_H_INCLUDED

using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include "Dokument.h"

class Dokumentacja {
private:
    std::vector<Dokument*> dokumenty;

public:
    Dokumentacja();
    ~Dokumentacja();

    bool dodajDok(Dokument* d);
    bool usunDok(int idDokumentu);
    Dokument* pobierzDokument(int id) const;
    vector<Dokument*> pobierzWszyskieDok() const;
};

#endif
