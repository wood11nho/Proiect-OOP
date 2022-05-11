//
// Created by Elias Stoica on 13-Apr-22.
//
#include <optional>
#include <cstdlib>
#include <ctime>
#include <vector>
#ifndef OOP_MECI_H
#define OOP_MECI_H
#include "Echipa.h"
#include "rlutil.h"

class Meci {
    Echipa& team1;
    Echipa& team2;
    std::pair<int, int> scor{0, 0};
    char rezultat;
public:
    Meci(Echipa &team1, Echipa &team2, const std::pair<int, int> &scor, char rezultat);

    ~Meci() {

    }

    friend std::ostream &operator<<(std::ostream &os, const Meci &meci);
    Meci& operator=(const Meci& other);
    void playmatch();

    const std::pair<int, int> &getScor() const;
};


#endif //OOP_MECI_H
