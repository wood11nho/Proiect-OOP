//
// Created by Elias Stoica on 08-May-22.
//

#ifndef OOP_ADIDAS_H
#define OOP_ADIDAS_H

#include <memory>
#include <ostream>
#include "Item.h"

class Adidas:public Item {
    int att_upgrade;
    int def_upgrade;
    int drb_upgrade;
    static int nradidasi;
public:
    Adidas(int pret, const std::string &nume, int attUpgrade, int defUpgrade, int drbUpgrade);

    virtual ~Adidas();

    Adidas(const Adidas& other);

    std::shared_ptr<Item> clone() const override;

    void afisare(std::ostream &os) const override;

    friend std::ostream &operator<<(std::ostream &os, const Adidas &adidas);
    Adidas& operator=(const Adidas& a1);

    void folosit_de(Jucator& j) override;

    static int getNradidasi();
};


#endif //OOP_ADIDAS_H
