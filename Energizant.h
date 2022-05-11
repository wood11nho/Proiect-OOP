//
// Created by Elias Stoica on 08-May-22.
//

#ifndef OOP_ENERGIZANT_H
#define OOP_ENERGIZANT_H
#include "Items.h"

class Energizant:public Items {
    int FitnessBoost;
    int SkillBoost;
public:
    Energizant(int pret, const std::string &nume, int fitnessBoost, int skillBoost);
};


#endif //OOP_ENERGIZANT_H
