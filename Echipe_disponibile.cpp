//
// Created by Elias Stoica on 05-May-22.
//

#include "Echipe_disponibile.h"

Echipe_disponibile::Echipe_disponibile(const vector<bool> &echDisp) : EchDisp(echDisp) {}

void Echipe_disponibile::este_valabila(bool ok) {
    this->EchDisp.push_back(ok);
}

const vector<bool> &Echipe_disponibile::getEchDisp() const {
    return EchDisp;
}

void Echipe_disponibile::setEchDisp(const vector<bool> &echDisp) {
    EchDisp = echDisp;
}
