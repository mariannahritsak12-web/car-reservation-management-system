#ifndef DOKUMENT_H_INCLUDED
#define DOKUMENT_H_INCLUDED

using namespace std;
#include <iostream>
#include <string>
#include <vector>

class Dokument {
protected:
    int id;
    int idSamochodu;
    string tytul;
    string opis;
    string typ;
    string dataUtworzenia;

public:
    Dokument(int id, int idSamochodu, const string& tytul, const string& opis, const string& typ, const string& dataUtworzenia);
    virtual ~Dokument() {}

    int getId() const;
    string getTytul() const;
    string getTyp() const;

    void setTytul(const string& nowyTytul);
    void setOpis(const string& nowyOpis);

    virtual void wypiszSzczegoly() const;
};

#endif
