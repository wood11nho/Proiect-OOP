//
// Created by Elias Stoica on 08-May-22.
//

#include "Energizant.h"

Energizant::Energizant(int pret, const std::string &nume, int fitnessBoost, int skillBoost) : Items(pret, nume),
                                                                                              FitnessBoost(
                                                                                                      fitnessBoost),
                                                                                              SkillBoost(skillBoost) {}

std::shared_ptr<Items> Energizant::clone() const{
    return std::make_shared<Energizant>(*this);
}

std::ostream &operator<<(std::ostream &os, const Energizant &energizant) {
    os << static_cast<const Items &>(energizant) << " FitnessBoost: " << energizant.FitnessBoost << " SkillBoost: "
       << energizant.SkillBoost;
    return os;
}

void Energizant::afisare(std::ostream &os) const {
    Items::afisare(os);
    const auto& op1 = *this;
    os<<"\nFitness boost: "<<op1.FitnessBoost<<"\nSkill boost: "<<op1.SkillBoost<<"\n";
}

Energizant::~Energizant() {

}


