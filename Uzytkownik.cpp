#include "Uzytkownik.h"
using namespace std;

Uzytkownik::Uzytkownik(int id, const string& imie, const string& nazwisko, const string& login, const string& haslo) :
    id(id), imie(imie), nazwisko(nazwisko), login(login), haslo(haslo) {}


//GET
    int Uzytkownik::getId() const {
        return id;
    }
    string Uzytkownik::getLogin() const {
        return login;
    }
    string Uzytkownik::getImieNazwisko() const {
        return imie, nazwisko;
    }
