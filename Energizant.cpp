//
// Created by Elias Stoica on 08-May-22.
//

#include "Energizant.h"

Energizant::Energizant(int pret, const std::string &nume, int fitnessBoost, int skillBoost) : Items(pret, nume),
                                                                                              FitnessBoost(
                                                                                                      fitnessBoost),
                                                                                              SkillBoost(skillBoost) {}
