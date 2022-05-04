//
// Created by Elias Stoica on 11-Apr-22.
//

#include <iostream>
#include <random>
#include <optional>
#include <cstdlib>
#include <ctime>
#include <vector>
#ifndef OOP_VECHIPE_H
#define OOP_VECHIPE_H
#include "Echipa.h"

class vEchipe {
    std::vector<Echipa> VectorEchipe;
public:
    explicit vEchipe(const std::vector<Echipa> &vectorEchipe) : VectorEchipe(vectorEchipe) {}

    virtual ~vEchipe() {

    }

    friend std::ostream &operator<<(std::ostream &os, const vEchipe &echipe) {
        os << "Vector Echipe: \n";
        int i = 0;
        for (const auto& echipa1 : echipe.VectorEchipe) {
            i = i + 1;
            os << "Echipa " << i << echipa1<<"\n";
        }
        return os;
    }

    const std::vector<Echipa> &getVectorEchipe() const {
        return VectorEchipe;
    }
    void adaugare_echipa(Echipa& e1){
        this->VectorEchipe.push_back(e1);
    }
};


#endif //OOP_VECHIPE_H
