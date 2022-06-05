//
// Created by Elias Stoica on 11-Apr-22.
//
#include <iostream>
#include <random>
#include <optional>
#include <cstdlib>
#include <ctime>
#include <vector>
#ifndef OOP_ECHIPA_H
#define OOP_ECHIPA_H

#include "Erori.h"


class Echipa {
private:
    static int id1;
    int id;
    int buget;
    int rating;
    std::string nume;
public:
    Echipa(int buget, int rating, const std::string &nume);
    Echipa();

    virtual ~Echipa();

    const std::string &getNume() const;

    int getId() const;

    int getRating() const;

    friend std::ostream &operator<<(std::ostream &os, const Echipa &echipa);

    bool operator==(const Echipa &rhs) const;
};


#endif //OOP_ECHIPA_H
