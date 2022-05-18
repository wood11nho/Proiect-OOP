//
// Created by Elias Stoica on 13-Apr-22.
//

#include "Meci.h"

Meci::Meci(Echipa &team1, Echipa &team2, const std::pair<int, int> &scor)
        : team1(team1), team2(team2), scor(scor) {}

std::ostream &operator<<(std::ostream &os, const Meci &meci) {
    os << "team1: " << meci.team1 << " team2: " << meci.team2 << " scor: " << meci.scor.first<<" - "<<meci.scor.second;
    return os;
}

Meci &Meci::operator=(const Meci &other) {
    team1 = other.team1;
    team2 = other.team2;
    scor = other.scor;
    return *this;
}

void Meci::playmatch(){
    int rating1 = team1.getRating();
    int rating2;
    rating2 = team2.getRating();
    std::vector<int> sanse{35, 30, 35};
    int dif = rating1 - rating2;
    if(dif > 0){
        while(dif!=0)
        {
            sanse[0]+=2;
            sanse[1]-=1;
            sanse[2]-=1;
            dif-=1;
        }
    }
    else
    {
        while(dif!=0)
        {
            sanse[0]-=1;
            sanse[1]-=1;
            sanse[2]+=2;
            dif+=1;
        }
    }
    int ocazii1 = abs(sanse[0] - sanse[1]);
    int ocazii2 = abs(sanse[2] - sanse[1]);
    for(int i = 1; i * i<=ocazii1;i++)
        scor.first += (rand() % 2);
    for(int i = 1; i* i<=ocazii2;i++)
        scor.second += (rand() % 2);
    rlutil::cls();
    std::cout<<"Meciul s-a terminat!\n";
    std::cout<<"REZULTAT FINAL: \n";
    std::cout<<team1.getNume()<<" "<<scor.first<<" - "<<team2.getNume()<<" "<<scor.second;

}

const std::pair<int, int> &Meci::getScor() const {
    return scor;
}

Echipa &Meci::getTeam1() const {
    return team1;
}

Echipa &Meci::getTeam2() const {
    return team2;
}

void Meci::statistici() const {
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(30, 69); // define the range
    int aux = distr(gen);
    std::cout << "\nPOSESIE             "<< aux << "       -       " << 100 - aux<<"\n";
    std::cout << " ------------------------------------------- \n";
    int aux1 = rand() % 3;
    int aux2 = rand() % 3;
    std::cout << "SUTURI              "<< this->getScor().first + aux1 + rand()%7<< "       -       "<< this->getScor().second + aux2 +rand()%7<<"\n";
    std::cout << "SUTURI PE POARTA    "<< this->getScor().first + aux1 << "       -       "<< this->getScor().second + aux2<<"\n";

}
