//
// Created by Elias Stoica on 11-Apr-22.
//

#include "Echipa.h"

Echipa::Echipa(int id, int buget, int rating, const string &nume) :
        id(id), buget(buget), rating(rating), nume(nume){

}

Echipa::Echipa() :
        id(0), buget(0), rating(0), nume(""){

}

Echipa::~Echipa() {

}

const string &Echipa::getNume() const {
    return nume;
}

int Echipa::getId() const {
    return id;
}

int Echipa::getRating() const {
    return rating;
}

ostream &operator<<(ostream &os, const Echipa &echipa) {
    os << "id: " << echipa.id << "\nbuget: "<<echipa.buget<<"\nnume: " << echipa.nume<<"\nrating: "<<echipa.rating;
    os<<"\n";

    return os;
}
