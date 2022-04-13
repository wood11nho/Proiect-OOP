//
// Created by Elias Stoica on 11-Apr-22.
//
#include <optional>
#include <cstdlib>
#include <ctime>
#include <vector>
#ifndef OOP_IMPRUMUT_H
#define OOP_IMPRUMUT_H
#include "Echipa.h"
#include "Jucator.h"
#include "Transfer.h"

class Imprumut:public Transfer{
    int durata;
public:
    Imprumut(Echipa &e1, Echipa &e2, Jucator &j, int durata) : Transfer(e1, e2, j), durata(durata) {}
    void Imprumutare(int durata_imprumut){
        this->j.setEchipa(e2);
        this->durata = durata_imprumut;
    }
};


#endif //OOP_IMPRUMUT_H
