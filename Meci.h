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
    Meci(Echipa &team1, Echipa &team2, const std::pair<int, int> &scor, char rezultat)
            : team1(team1), team2(team2), scor(scor), rezultat(rezultat) {}

    virtual ~Meci() {

    }

    friend std::ostream &operator<<(std::ostream &os, const Meci &meci) {
        os << "team1: " << meci.team1 << " team2: " << meci.team2 << " scor: " << meci.scor.first<<" - "<<meci.scor.second << " rezultat: "
           << meci.rezultat;
        return os;
    }
    Meci& operator=(const Meci& other){
        team1 = other.team1;
        team2 = other.team2;
        scor = other.scor;
        rezultat = other.rezultat;
        return *this;
    }
    void playmatch(){
        int rating1 = team1.getRating();
        int rating2 = team2.getRating();
        std::vector<int> sanse;
        sanse.push_back(35);
        sanse.push_back(30);
        sanse.push_back(35);
        int dif = rating1 - rating2;
        if(dif > 0){
            while(dif!=0)
            {
                sanse[0]+=3;
                sanse[1]-=2;
                sanse[2]-=1;
                dif-=1;
            }
        }
        else
        {
            while(dif!=0)
            {
                sanse[0]-=1;
                sanse[1]-=2;
                sanse[2]+=3;
                dif+=1;
            }
        }
        int ocazii1 = abs(sanse[0] - sanse[1]);
        int ocazii2 = abs(sanse[2] - sanse[1]);
        for(int i = 1; i<=ocazii1;i++)
            scor.first += (rand() % 2);
        for(int i = 1; i<=ocazii2;i++)
            scor.second += (rand() % 2);
        rlutil::cls();
        std::cout<<"Meciul s-a terminat!\n";
        std::cout<<"REZULTAT FINAL: \n";
        std::cout<<team1.getNume()<<" "<<scor.first<<" - "<<team2.getNume()<<" "<<scor.second;
    }
};


#endif //OOP_MECI_H
