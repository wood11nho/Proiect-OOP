//
// Created by Elias Stoica on 08-May-22.
//

#ifndef OOP_ENERGIZANT_H
#define OOP_ENERGIZANT_H

#include <memory>
#include <ostream>
#include "Items.h"

class Energizant:public Items {
    int FitnessBoost;
    int SkillBoost;
public:
    Energizant(int pret, const std::string &nume, int fitnessBoost, int skillBoost);

    virtual ~Energizant();

    std::shared_ptr<Items> clone() const override;

    void afisare(std::ostream &os) const override;

    friend std::ostream &operator<<(std::ostream &os, const Energizant &energizant);

};


#endif //OOP_ENERGIZANT_H
