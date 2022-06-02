//
// Created by Elias Stoica on 18-May-22.
//

#ifndef OOP_ETAPE_H
#define OOP_ETAPE_H


#include "Meci.h"
#include "vEchipe.h"
#include "Clasament.h"

class Etape {
    std::vector<Meci> VectorMeciuri;
public:
    explicit Etape(const std::vector <Meci> &vectorMeciuri);

    ~Etape() = default;
    friend std::ostream &operator<<(std::ostream &os, const Etape &meciuri);

    void adaugare_meci(const Meci& m1);
    Meci& last_one();
    void joaca_campionat(Aplicatie &a1);
};


#endif //OOP_ETAPE_H
