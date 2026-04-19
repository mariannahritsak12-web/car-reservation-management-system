#ifndef PROTOCOL_H_INCLUDED
#define PROTOCOL_H_INCLUDED

using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include "Dokument.h"

class Protocol : public Dokument {
private:
    double przebieg;
    double poziomPaliwa;
    bool czyCzysty;
    string listaUszkodzen;

public:
    Protocol(int id, int idSamochodu, const string& dataUtworzenia, double przebieg, double paliwo, bool czysty, const string& uszkodzenia);

    double getPoziomPaliwa() const;
    double getPrzebieg() const;
    string getListaUszkodzen() const;
    void wypiszSzczegoly() const override;
};


#endif
