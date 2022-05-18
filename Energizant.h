//
// Created by Elias Stoica on 08-May-22.
//

#ifndef OOP_ENERGIZANT_H
#define OOP_ENERGIZANT_H

#include <memory>
#include <ostream>
#include "Item.h"

class Energizant:public Item {
    int FitnessBoost;
    int SkillBoost;
    static int nrenerg;

public:
    Energizant(int pret, const std::string &nume, int fitnessBoost, int skillBoost);

    virtual ~Energizant();

    Energizant(const Energizant& other);

    std::shared_ptr<Item> clone() const override;

    void afisare(std::ostream &os) const override;

    friend std::ostream &operator<<(std::ostream &os, const Energizant &energizant);

    Energizant& operator=(const Energizant &e1);

    void folosit_de(Jucator& j) override;

    static int getNrenerg();
};


#endif //OOP_ENERGIZANT_H
