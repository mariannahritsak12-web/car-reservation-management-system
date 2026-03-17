#ifndef OCENASTANU_H_INCLUDED
#define OCENASTANU_H_INCLUDED

using namespace std;
#include <iostream>
#include <string>
#include <vector>

class Dokumentacja;
class KatalogSamochodow;

class OcenaStanu {
public:
    void zglosAwarie(Dokumentacja& dok, int idSamochodu, string opis, string data);
    void zglosSzkode(Dokumentacja& dok, int idSamochodu, string opis, string data);

    void ocenSamochod(KatalogSamochodow& katalog, int idSamochodu, int ocena);
};

#endif
