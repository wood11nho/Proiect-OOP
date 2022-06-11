//
// Created by Elias Stoica on 08-May-22.
//

#include "Item.h"

Item::Item(int pret, const std::string &nume) : pret(pret), nume(nume) {}

Item::~Item() {

}

void Item::afisare(std::ostream &os) const {
    os << "\npret: " << this->pret << "\nnume: " << this->nume;
}

std::ostream &operator<<(std::ostream &os, const Item &items) {
    items.afisare(os);
    return os;
}

Item::Item(const Item &other) :
        pret(other.pret), nume(other.nume)
{}

Item &Item::operator=(const Item &other) {
    pret = other.pret;
    nume = other.nume;
    return *this;
}

int Item::getPret() const {
    return pret;
}

bool Item::operator<(const Item &rhs) const {
    return pret < rhs.pret;
}

bool Item::operator>(const Item &rhs) const {
    return rhs < *this;
}

bool Item::operator<=(const Item &rhs) const {
    return !(rhs < *this);
}

bool Item::operator>=(const Item &rhs) const {
    return !(*this < rhs);
}
