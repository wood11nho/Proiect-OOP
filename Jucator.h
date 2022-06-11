//
// Created by Elias Stoica on 11-Apr-22.
//
#include <iostream>
#include <random>
#include <optional>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "rlutil.h"
#ifndef OOP_JUCATOR_H
#define OOP_JUCATOR_H
#include "Echipa.h"
#include "Erori.h"
#include <memory>
#include "Energizant.h"
#include "Adidas.h"
#include "Aplicatie.h"

class Jucator {
    int id;
    std::string nume;
    std::string prenume;
    std::string nationalitate;
    int varsta;
    int att_stats;
    int def_stats;
    int drb_stats;
    std::optional <Echipa> echipa;
    int pret;
    int salariu;
    int avere;
    int fitness;
public:


    Jucator();
    Jucator(const int &id, const std::string &name, const std::string &prenume, const std::string &nationalitate , const int &varsta, const int &att_stats,const int &def_stats, const int &drb_stats, const Echipa &echipa,const  int &pret, const int &salariu, const int &avere, const int &fitness):
            id(id), nume(name), prenume(prenume), nationalitate(nationalitate),  varsta(varsta), att_stats(att_stats), def_stats(def_stats), drb_stats(drb_stats), echipa(echipa), pret(pret), salariu(salariu), avere(avere), fitness(fitness)
    {

    }
    Jucator(Jucator const &j1);
    ~Jucator() {
        //destructor jucator
    }

    Jucator& operator=(const Jucator& j1);

    static bool containsOnlyLetters(std::string const &str);

    static bool containsOnlyDigits(std::string const &str);

    friend std::ostream &operator<<(std::ostream &os, const Jucator &jucator);
    friend std::istream &operator>>(std::istream &is, Jucator &jucator);

    [[nodiscard]] const std::optional<Echipa> &getEchipa();

    void setEchipa(const std::optional<Echipa> &echipa1);

    void creeaza_jucator();

    void alege_echipa(const Aplicatie &a1);
    int rating() const {
        return (this->att_stats + this->drb_stats +this->def_stats) / 3;
    }
    void antrenament();

    void consuma(Item& item);

    void cumpara(Item& item, Aplicatie& a1);

    int getAttStats() const;

    int getDefStats() const;

    int getDrbStats() const;

    int getAvere() const;

    void setAttStats(int attStats);

    void setDefStats(int defStats);

    void setDrbStats(int drbStats);

    void setAvere(int avere);

    void setFitness(int fitness);

    int getFitness() const;

    const std::string &getPrenume() const;

    int getSalariu() const;
};


#endif //OOP_JUCATOR_H
