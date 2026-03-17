#ifndef UZYTKOWNIK_H_INCLUDED
#define UZYTKOWNIK_H_INCLUDED

using namespace std;
#include <iostream>
#include <string>

class Uzytkownik {
protected:
    int id;
    string imie;
    string nazwisko;
    string login;
    string haslo;

public:
    Uzytkownik(int id, const string& imie, const string& nazwisko, const string& login, const string& haslo);
    virtual ~Uzytkownik() {}


    virtual string getRola() const {
        return "Uzytkownik";
    }

    int getId() const;
    string getLogin() const;
    string getImieNazwisko() const;

    void setImie(const string& zmienImie);
    void setNazwisko(const string& zmienNazwisko);
};

#endif
