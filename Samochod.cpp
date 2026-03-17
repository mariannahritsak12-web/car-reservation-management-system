#include "Samochod.h"
using namespace std;

Samochod::Samochod(int id, const string& marka, const string& model, int rok, int miejsca, const string& status, double przebieg) :
    id(id), marka(marka), model(model), rokProdukcji(rok), miejsca(miejsca), status("Dostepny"), aktualnyPrzebieg(przebieg), ocenaSrednia(0), liczbaOcen(0)
    {
        cout << "Utworzono obiekt klasy Samochod." << endl;
    }

    void Samochod::ustawStatus(const string& nowyStatus) {
        cout << "Wywolano metode ustawStatus()" << endl;
        this->status = nowyStatus;
    }

    void Samochod::zaktualizujPrzebieg(double nowyPrzebieg) {
        if (nowyPrzebieg > aktualnyPrzebieg) {
            this->aktualnyPrzebieg = nowyPrzebieg;
        }
    }

    void Samochod::dodajOcene(int ocena) {
        double suma = ocenaSrednia * liczbaOcen;
        suma += ocena;
        liczbaOcen++;
        ocenaSrednia = suma / liczbaOcen;
    }

    void Samochod::wypiszSzczegoly() {
        cout << "Szczegoly samochod : " << endl;
        cout << "ID: " << id << endl;
        cout << "Marka: " << marka << endl;
        cout << "Model: " << model << endl;
        cout << "Rok produkcji: " << rokProdukcji << endl;
        cout << "Liczba miejsc: " << miejsca << endl;
        cout << "Status: " << status << endl;
        cout << "Aktualny przebieg: " << status << endl;
    }

    bool Samochod::czyDostepny() const {
        cout << "Wywolano metode czyDostepny()" << endl;
        return status == "Dostepny";
    }

// GET
    int Samochod::getId() const {
        return id;
    }
    string Samochod::getMarka() const {
        return marka;
    }
    string Samochod::getModel() const {
        return model;
    }
    string Samochod::getStatus() const {
        return status;
    }
    double Samochod::getAktualnyPrzebieg() const {
        return aktualnyPrzebieg;
    }

//SET
    void Samochod::setMarka(const string& nowaMarka) {
        this->marka = nowaMarka;
    }
    void Samochod::setModel(const string& nowyModel) {
        this->model = nowyModel;
    }
    void Samochod::setRok(int zmienRok) {
        this->rokProdukcji = zmienRok;
    }
    void Samochod::setMiejsca(int zmienMiejsca) {
        this->miejsca = zmienMiejsca;
    }
