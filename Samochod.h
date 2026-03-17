#ifndef SAMOCHOD_H_INCLUDED
#define SAMOCHOD_H_INCLUDED

using namespace std;
#include <iostream>
#include <string>
#include <vector>

class Samochod {
    private:
        int id;
        string marka;
        string model;
        int rokProdukcji;
        string status;
        int miejsca;
        double aktualnyPrzebieg;
        int ocenaSrednia;
        int liczbaOcen;

    public:
        Samochod(int id, const string& marka, const string& model, int rok, int miejsca, const string& status, double aktualnyPrzebieg);


        int getId() const;
        string getMarka() const;
        string getModel() const;
        string getStatus() const;
        double getAktualnyPrzebieg() const;

        void wypiszSzczegoly();

        void ustawStatus(const string& nowyStatus);
        void zaktualizujPrzebieg(double nowyPrzebieg);
        void dodajOcene(int ocena);
        bool czyDostepny() const;

        void setMarka(const string& nowaMarka);
        void setModel(const string& nowyModel);
        void setRok(int zmienRok);
        void setMiejsca(int zmienMiejsca);
};


#endif
