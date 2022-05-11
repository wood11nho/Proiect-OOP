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
    explicit vEchipe(const std::vector<Echipa> &vectorEchipe);

    virtual ~vEchipe();

    friend std::ostream &operator<<(std::ostream &os, const vEchipe &echipe);

    const std::vector<Echipa> &getVectorEchipe() const;
    void adaugare_echipa(Echipa& e1);
};


#endif //OOP_VECHIPE_H
