//
// Created by Elias Stoica on 11-Apr-22.
//

#include "Imprumut.h"

Imprumut::Imprumut(Echipa &e1, Echipa &e2, Jucator &j, int durata) : Transfer(e1, e2, j), durata(durata) {}

[[maybe_unused]] void Imprumut::Imprumutare(int durata_imprumut) {
    this->j.setEchipa(e2);
    this->durata = durata_imprumut;
}
