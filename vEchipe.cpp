//
// Created by Elias Stoica on 11-Apr-22.
//

#include "vEchipe.h"

void vEchipe::adaugare_echipa(Echipa &e1) {
    this->VectorEchipe.push_back(e1);
}

const std::vector<Echipa> &vEchipe::getVectorEchipe() const {
    return VectorEchipe;
}

std::ostream &operator<<(std::ostream &os, const vEchipe &echipe) {
    os << "Vector Echipe: \n";
    int i = 0;
    for (const auto& echipa1 : echipe.VectorEchipe) {
        i = i + 1;
        os << "Echipa " << i << echipa1<<"\n";
    }
    return os;
}

vEchipe::~vEchipe() {

}

vEchipe::vEchipe(const std::vector<Echipa> &vectorEchipe) : VectorEchipe(vectorEchipe) {}
