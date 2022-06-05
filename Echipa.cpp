//
// Created by Elias Stoica on 11-Apr-22.
//

#include "Echipa.h"

Echipa::Echipa(int buget, int rating, const std::string &nume) :
        id(id1++), buget(buget), rating(rating), nume(nume){
    if(buget < 0)
        throw invalidBuget("Bugetul echipei nu poate sa fie negativ\n");
    if(nume.empty())
        throw invalidName("Numele nu poate fi inexistent!\n");

}

Echipa::Echipa() :
        id(id1), buget(0), rating(0), nume(""){
    id1++;
}

Echipa::~Echipa() {

}

const std::string &Echipa::getNume() const {
    return nume;
}

int Echipa::getId() const {
    return id;
}

int Echipa::getRating() const {
    return rating;
}

std::ostream &operator<<(std::ostream &os, const Echipa &echipa) {
    os << "\nid: " << echipa.id << "\nbuget: "<<echipa.buget<<"\nnume: " << echipa.nume<<"\nrating: "<<echipa.rating;
    os<<"\n";

    return os;
}

bool Echipa::operator==(const Echipa &rhs) const {
    return id == rhs.id &&
           buget == rhs.buget &&
           rating == rhs.rating &&
           nume == rhs.nume;
}
