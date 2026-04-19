#ifndef KALENDARZ_H_INCLUDED
#define KALENDARZ_H_INCLUDED

using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include "WpisWKalendarzu.h"

class Kalendarz {
private:
    std::vector<WpisWKalendarzu*> wpisy;

public:
    Kalendarz();
    ~Kalendarz();

    bool dodajWpis(WpisWKalendarzu* wpis);
    bool usunWpis(int idWpisu);
    bool zmienStatusWpisu(int idWpisu);

    vector<WpisWKalendarzu*> pobierzNadchodzaceWpisy();
    vector<WpisWKalendarzu*> pobierzWszystkieWpisy() const;
    double obliczKoszty(int idSamochodu);
    void monitorujTerminy(string dataDo);
};


#endif
