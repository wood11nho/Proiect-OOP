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

std::vector<int> Meci::setare_sanse(){
    int rating1 = this->team1.getRating();
    int rating2;
    rating2 = this->team2.getRating();
    std::vector<int> sanse{32, 40, 28};
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
    return sanse;
}

void Meci::playmatch(){
    std::vector<int> sanse = this->setare_sanse();
    for(int i = 1; i <= 10;i++) {
        auto nr_random = Random::get(0,200);
        if(nr_random <= sanse[0])
            scor.first += 1;
        else if(nr_random >= 100 - sanse[2] and nr_random <= 100)
            scor.second += 1;
    }
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
    auto aux1 = Random::get(0,3);
    auto aux2 = Random::get(0,3);
    std::cout << "SUTURI              "<< this->getScor().first + aux1 + rand()%7<< "       -       "<< this->getScor().second + aux2 +rand()%7<<"\n";
    std::cout << "SUTURI PE POARTA    "<< this->getScor().first + aux1 << "       -       "<< this->getScor().second + aux2<<"\n";

}

void Meci::gol1() {
    this->scor.first +=1;
}
void Meci::gol2() {
    this->scor.second +=1;
}
