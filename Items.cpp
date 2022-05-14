//
// Created by Elias Stoica on 08-May-22.
//

#include "Items.h"

Items::Items(int pret, const std::string &nume) : pret(pret), nume(nume) {}

Items::~Items() {

}

void Items::afisare(std::ostream &os) const {
    os << "\npret: " << this->pret << "\nnume: " << this->nume;
}

std::ostream &operator<<(std::ostream &os, const Items &items) {
    items.afisare(os);
    return os;
}

Items::Items(const Items &other) :
        pret(other.pret), nume(other.nume)
{}

Items &Items::operator=(const Items &other) {
    pret = other.pret;
    nume = other.nume;
    return *this;
}

int Items::getPret() const {
    return pret;
}
