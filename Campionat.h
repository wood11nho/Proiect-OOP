//
// Created by Elias Stoica on 18-May-22.
//

#ifndef OOP_CAMPIONAT_H
#define OOP_CAMPIONAT_H


#include "Meci.h"
#include "vEchipe.h"
#include "Clasament.h"

class Campionat {
    std::vector<Meci> VectorMeciuri;
public:
    explicit Campionat(const std::vector <Meci> &vectorMeciuri);

    ~Campionat() = default;
    friend std::ostream &operator<<(std::ostream &os, const Campionat &meciuri);

    void adaugare_meci(const Meci& m1);
    Meci& last_one();
    void joaca_campionat(vEchipe& ve);
};


#endif //OOP_CAMPIONAT_H
