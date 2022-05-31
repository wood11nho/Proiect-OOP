//
// Created by Elias Stoica on 11-Apr-22.
//

#include "Echipa.h"

Echipa::Echipa(int buget, int rating, const std::string &nume) :
        id(id1++), buget(buget), rating(rating), nume(nume){

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
