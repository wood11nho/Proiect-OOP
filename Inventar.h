//
// Created by Elias Stoica on 15-May-22.
//

#ifndef OOP_INVENTAR_H
#define OOP_INVENTAR_H
#include "Items.h"
#include <vector>


class Inventar {
    std::vector<std::shared_ptr<Items>> Colectie;

public:
    explicit Inventar(const std::vector<std::shared_ptr<Items>> &colectie);

    ~Inventar() {

    }

    friend std::ostream &operator<<(std::ostream &os, const Inventar &inventar);

    void addItem(std::shared_ptr<Items> pulledItem);

    const std::vector<std::shared_ptr<Items>> &getColectie() const;
};


#endif //OOP_INVENTAR_H