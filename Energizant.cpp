//
// Created by Elias Stoica on 08-May-22.
//

#include "Energizant.h"
#include "Jucator.h"
#include "Inventar.h"
Energizant::Energizant(int pret, const std::string &nume, int fitnessBoost, int skillBoost) : Item(pret, nume),
                                                                                              FitnessBoost(
                                                                                                      fitnessBoost),
                                                                                              SkillBoost(skillBoost) {}

std::shared_ptr<Item> Energizant::clone() const{
    return std::make_shared<Energizant>(*this);
}

std::ostream &operator<<(std::ostream &os, const Energizant &energizant) {
    os << static_cast<const Item &>(energizant) << " FitnessBoost: " << energizant.FitnessBoost << " SkillBoost: "
       << energizant.SkillBoost;
    return os;
}

void Energizant::afisare(std::ostream &os) const {
    Item::afisare(os);
    const auto& op1 = *this;
    os<<"\nFitness boost: "<<op1.FitnessBoost<<"\nSkill boost: "<<op1.SkillBoost<<"\n";
}

Energizant::~Energizant() {

}

Energizant &Energizant::operator=(const Energizant &e1) {
    FitnessBoost = e1.FitnessBoost;
    SkillBoost = e1.SkillBoost;
    pret = e1.pret;
    nume = e1.nume;
    return *this;
}

void Energizant::folosit_de(Jucator &j) {
    j.setAttStats(j.getAttStats() + this->SkillBoost);
    j.setDrbStats(j.getDrbStats() + this->SkillBoost);
    j.setDefStats(j.getDefStats() + this->SkillBoost);
    j.setFitness(this->FitnessBoost);
}






