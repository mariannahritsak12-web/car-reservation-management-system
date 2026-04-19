#ifndef WPISWKALENDARZU_H_INCLUDED
#define WPISWKALENDARZU_H_INCLUDED

using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include "TypEkspoloatacji.h"

class WpisWKalendarzu {
private:
    int id;
    int idSamochodu;
    string dataPlanowana;
    typWpisu typ;
    string opis;
    double koszt;
    string status;

public:
    WpisWKalendarzu(int id, int idSamochodu, string dataPlan, typWpisu typ, string opis, double koszt = 0.0, string status = "Planowane");

    int getId() const;
    string getDataPlanowana() const;
    typWpisu getTyp() const;
    string getOpis() const;
    double getKoszt() const;
    string getStatus();
    int getIdSamochodu() const;
    bool czyZrealizowane();
    void oznaczZrealizowane(const string& nowyStatus);

    void setDataPlanowana(const string& nowaData);
    void setTyp(typWpisu& zmienTyp);
    void setOpis(const string& nowyOpis);
    void setKoszt(double nowyKoszt);
};


#endif
