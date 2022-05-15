//
// Created by Elias Stoica on 15-May-22.
//

#include "Inventar.h"

Inventar::Inventar(const std::vector<std::shared_ptr<Items>> &colectie) : Colectie(colectie) {}

std::ostream &operator<<(std::ostream &os, const Inventar &inventar) {
    os << "\n-------------------------------------";
    int contor = 1;
    for(const std::shared_ptr<Items>& i: inventar.Colectie){
        os<<contor<<".";
        os<< *i<<'\n';
        contor++;

    }
    return os;
}

void Inventar::addItem(std::shared_ptr<Items> pulledItem) {
    this->Colectie.push_back(pulledItem);
}

const std::vector<std::shared_ptr<Items>> &Inventar::getColectie() const {
    return Colectie;
}
