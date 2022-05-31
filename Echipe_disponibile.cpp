//
// Created by Elias Stoica on 05-May-22.
//

#include "Echipe_disponibile.h"

Echipe_disponibile::Echipe_disponibile(const std::vector<bool> &echDisp) : EchDisp(echDisp) {}

void Echipe_disponibile::este_valabila(bool ok) {
    this->EchDisp.push_back(ok);
}

const std::vector<bool> &Echipe_disponibile::getEchDisp() const {
    return EchDisp;
}

void Echipe_disponibile::setEchDisp() {
    auto val = Random::get(1, 16);
    this->EchDisp.at(val) = true;
}

std::ostream &operator<<(std::ostream &os, const Echipe_disponibile &disponibile) {
    for(bool i:disponibile.EchDisp)
    {
        os<<i<<" ";
    }
    return os;
}
