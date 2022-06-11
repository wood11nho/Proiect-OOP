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

#include "ext/random.hpp"

using Random = effolkronium::random_static;

class Meci {
    Echipa& team1;
    Echipa& team2;
    std::pair<int, int> scor{0, 0};
public:


    Meci(Echipa &team1, Echipa &team2, const std::pair<int, int> &scor);

    ~Meci() {

    }

    void gol1();

    void gol2();

    std::vector<int> setare_sanse();
    friend std::ostream &operator<<(std::ostream &os, const Meci &meci);
    Meci& operator=(const Meci& other);
    void playmatch();

    const std::pair<int, int> &getScor() const;

    Echipa &getTeam1() const;

    Echipa &getTeam2() const;

    void statistici() const;
};


#endif //OOP_MECI_H
