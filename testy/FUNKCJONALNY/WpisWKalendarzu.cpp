#include "WpisWKalendarzu.h"
#include "TypEkspoloatacji.h"
#include <iostream>
using namespace std;

WpisWKalendarzu::WpisWKalendarzu(int id, int idSamochodu, string dataPlan, typWpisu typ, string opis, double koszt, string status) :
    id(id), idSamochodu(idSamochodu), dataPlanowana(dataPlan), typ(typ), opis(opis), koszt(koszt), status("Planowane") {}

    void WpisWKalendarzu::oznaczZrealizowane(const string& nowyStatus) {
        this->status = nowyStatus;
    }

    bool WpisWKalendarzu::czyZrealizowane() {
        return this->status == "Zrealizowane";
    }

//GET
    int WpisWKalendarzu::getId() const {
        return id;
    }
    string WpisWKalendarzu::getDataPlanowana() const {
        return dataPlanowana;
    }
    typWpisu WpisWKalendarzu::getTyp() const {
        return typ;
    }
    string WpisWKalendarzu::getOpis() const {
        return opis;
    }
    double WpisWKalendarzu::getKoszt() const {
        return koszt;
    }
    int WpisWKalendarzu::getIdSamochodu() const {
        return idSamochodu;
    }
    string WpisWKalendarzu::getStatus() {
        return status;
    }

//SET
    void WpisWKalendarzu::setDataPlanowana(const string& nowaData) {
        this->dataPlanowana = nowaData;
    }
    void WpisWKalendarzu::setTyp(typWpisu& zmienTyp) {
        this->typ = zmienTyp;
    }
    void WpisWKalendarzu::setOpis(const string& nowyOpis) {
        this->opis = nowyOpis;
    }
    void WpisWKalendarzu::setKoszt(double nowyKoszt) {
        this->koszt = nowyKoszt;
    }
