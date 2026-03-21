#ifndef TYPEKSPOLOATACJI_H_INCLUDED
#define TYPEKSPOLOATACJI_H_INCLUDED

using namespace std;
#include <iostream>

enum typWpisu {
    PRZEGLAD,
    TANKOWANIE,
    NAPRAWA,
    INNE
};

inline string typToString(typWpisu typ) {
    switch (typ) {
        case PRZEGLAD: return "Przeglad techniczny";
        case TANKOWANIE: return "Tankowanie";
        case NAPRAWA: return "Naprawa";
        default: return "Inne zdarzenie";
    }
}

#endif
