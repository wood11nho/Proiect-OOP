//
// Created by Elias Stoica on 08-May-22.
//

#include "Adidas.h"


Adidas::Adidas(int pret, const std::string &nume, int attUpgrade, int defUpgrade, int drbUpgrade) : Items(pret, nume),att_upgrade(attUpgrade),def_upgrade(defUpgrade),drb_upgrade(drbUpgrade) {}

Adidas::~Adidas() {

}

std::shared_ptr<Items> Adidas::clone() const{
    return std::make_shared<Adidas>(*this);
}

std::ostream &operator<<(std::ostream &os, const Adidas &adidas) {
    os << static_cast<const Items &>(adidas) << " att_upgrade: " << adidas.att_upgrade << " def_upgrade: "
       << adidas.def_upgrade << " drb_upgrade: " << adidas.drb_upgrade;
    return os;
}

void Adidas::afisare(std::ostream &os) const {
    Items::afisare(os);
    const auto& op2 = *this;
    os<<"\nUpgrade at attacking stats: "<<op2.att_upgrade<<"\nUpgrade at dribbling stats: "<<op2.drb_upgrade<<"\nUpgrade at defending stats: "<<op2.def_upgrade;
}

