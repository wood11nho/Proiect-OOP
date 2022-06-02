//
// Created by Elias Stoica on 02-Jun-22.
//

#ifndef OOP_APLICATIE_H
#define OOP_APLICATIE_H
#include <vector>
#include <memory>
#include <iostream>
#include "ext/random.hpp"
using Random = effolkronium::random_static;

#include "Echipa.h"
#include "Item.h"

class Aplicatie {
    std::vector<bool> EchDisp;
    std::vector<Echipa> VectorEchipe;
    std::vector<std::shared_ptr<Item>> Colectie;
    std::vector<std::shared_ptr<Item>> multime_consumabile;
    Aplicatie() = default;

public:
    Aplicatie(const Aplicatie&) = delete;

    Aplicatie &operator=(const Aplicatie&) = delete;

    static Aplicatie& get_aplicatie(){
        static Aplicatie i;
        return i;
    }


    void este_valabila(bool ok) {
        this->EchDisp.push_back(ok);
    }


    const std::vector<bool> &getEchDisp() const {
        return EchDisp;
    }

    const std::vector<Echipa> &getVectorEchipe() const {
        return VectorEchipe;
    }

    const std::vector<std::shared_ptr<Item>> &getColectie() const {
        return Colectie;
    }

    const std::vector<std::shared_ptr<Item>> &getMultimeConsumabile() const {
        return multime_consumabile;
    }

    void setMultimeConsumabile(const std::vector<std::shared_ptr<Item>> &multimeConsumabile) {
        multime_consumabile = multimeConsumabile;
    }

    void setEchDisp() {
        auto val = Random::get(1, 16);
        this->EchDisp.at(val) = true;
    }

    void afisare_echdisp(){
        for(bool i:this->EchDisp)
        {
            std::cout<<i<<" ";
        }
    }

    void afisare_vechipe(){
        std::cout << "Vector Echipe: \n";
        int i = 0;
        for (const auto& echipa1 : this->getVectorEchipe()) {

            std::cout << "Echipa " << i << echipa1<<"\n";
            i = i + 1;
        }
    }

    void afisare_colectie(){
        std::cout << "\n-------------------------------------\n";
        int contor = 1;
        for(const std::shared_ptr<Item>& i: this->Colectie){
            std::cout<<contor<<".";
            std::cout<< *i<<'\n';
            contor++;

        }
    }

    void afisare_consumabile(){
        std::cout << "\n-------------------------------------\n";
        int contor = 1;
        for(const std::shared_ptr<Item>& i: this->multime_consumabile){
            std::cout<<contor<<".";
            std::cout<< *i<<'\n';
            contor++;

        }
    }

    void addItemColectie(std::shared_ptr<Item> pulledItem) {
        this->Colectie.push_back(pulledItem);
    }

    void addItemConsumabile(std::shared_ptr<Item> pulledItem){
        this->multime_consumabile.push_back(pulledItem);
    }

    void adaugare_echipa(Echipa e1) {
        this->VectorEchipe.push_back(e1);
    }

    int getNrechipe() const {
        return this->VectorEchipe.size() - 1;
    }

    void pop_echipa(){
        this->VectorEchipe.pop_back();
    }
    void insert_echipa(int pozitie, Echipa& e1){
        this->VectorEchipe.insert(this->VectorEchipe.begin() + pozitie, e1);
    }
};


#endif //OOP_APLICATIE_H
