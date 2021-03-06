//
// Created by Elias Stoica on 08-May-22.
//

#include "Adidas.h"
#include "Jucator.h"
Adidas::Adidas(int pret, const std::string &nume, int attUpgrade, int defUpgrade, int drbUpgrade) : Item(pret, nume), att_upgrade(attUpgrade), def_upgrade(defUpgrade), drb_upgrade(drbUpgrade) {
    nradidasi++;
    if(attUpgrade < 0 or defUpgrade < 0 or drbUpgrade < 0)
        throw(invalidStat("Un item nu poate avea un upgrade negativ!"));
}


Adidas::~Adidas() {

}

std::shared_ptr<Item> Adidas::clone() const{
    return std::make_shared<Adidas>(*this);
}

Adidas::Adidas(const Adidas &other) : Item(other), att_upgrade(other.att_upgrade), def_upgrade(other.def_upgrade), drb_upgrade(other.drb_upgrade){

}

std::ostream &operator<<(std::ostream &os, const Adidas &adidas) {
    os << static_cast<const Item &>(adidas) << " att_upgrade: " << adidas.att_upgrade << " def_upgrade: "
       << adidas.def_upgrade << " drb_upgrade: " << adidas.drb_upgrade;
    return os;
}

void Adidas::afisare(std::ostream &os) const {
    Item::afisare(os);
    const auto& op2 = *this;
    os<<"\nUpgrade at attacking stats: "<<op2.att_upgrade<<"\nUpgrade at dribbling stats: "<<op2.drb_upgrade<<"\nUpgrade at defending stats: "<<op2.def_upgrade<<"\n";
}

void Adidas::folosit_de(Jucator &j) {
    j.setAttStats(this->att_upgrade + j.getAttStats());
    j.setDrbStats(this->drb_upgrade + j.getDrbStats());
    j.setDefStats(this->def_upgrade + j.getDefStats());
}

Adidas &Adidas::operator=(const Adidas &a1) {
    nume = a1.nume;
    pret = a1.pret;
    att_upgrade = a1.att_upgrade;
    def_upgrade = a1.def_upgrade;
    drb_upgrade = a1.drb_upgrade;
    return *this;
}

int Adidas::getNradidasi() {
    return nradidasi;
}

