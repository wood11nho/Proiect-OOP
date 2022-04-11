//
// Created by Elias Stoica on 11-Apr-22.
//

#include <iostream>
#include <random>
#include <optional>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
#ifndef OOP_VECHIPE_H
#define OOP_VECHIPE_H
#include "Echipa.h"

class vEchipe {
    vector<Echipa> VectorEchipe;
public:
    explicit vEchipe(const vector<Echipa> &vectorEchipe) : VectorEchipe(vectorEchipe) {}

    virtual ~vEchipe() {

    }

    friend ostream &operator<<(ostream &os, const vEchipe* &echipe) {
        os << "Vector Echipe: \n";
        int n = sizeof(echipe);
        for (int i = 0; i < n; i++) { os << "Echipa " << i << (const vEchipe *&) echipe[i]; }
        return os;
    }

    const vector<Echipa> &getVectorEchipe() const {
        return VectorEchipe;
    }
    void adaugare_echipa(Echipa& e1){
        this->VectorEchipe.push_back(e1);
    }
};


#endif //OOP_VECHIPE_H
