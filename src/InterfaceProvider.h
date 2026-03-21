#ifndef INTERFACEPROVIDER_H_INCLUDED
#define INTERFACEPROVIDER_H_INCLUDED

#include "Kalendarz.h"
#include "Administrator.h"
#include "Pracownik.h"
#include "ListaRezerwacji.h"
#include "KatalogSamochodow.h"
#include "Uzytkownicy.h"

#include <string>
#include <iostream>

using namespace std;

class ConsoleInterfaceProvider {
private:
    Kalendarz& kalendarz;
    KatalogSamochodow& katalog;
    Uzytkownicy& uzytkownicy;
    ListaRezerwacji& rezerwacje;
    Administrator& administrator;
    Pracownik& pracownik;

public:
    explicit ConsoleInterfaceProvider(Kalendarz& k, KatalogSamochodow& kat, Uzytkownicy& u, ListaRezerwacji& rez, Administrator& admin, Pracownik& prac);

    bool wyswietlMenuGlowne();
    void wyswietlMenuPracownika();
    void wyswietlMenuAdministratora();

    void submenuZarzadzajKalendarzem() const;
    void submenuZarzadzajFlota();
    void submenuZarzadzajDokumentacja();
    void submenuZarzadzajRezerwacjami();
    void submenuZarzadzajUzytkownikami();
    void submenuZarzadzajSamochodami();

    void submenuPodgladRezerwacji();

    void run();

    int pobierzLiczbe(string komunikat) const;
    string pobierzTekst(string komunikat) const;
};

#endif
