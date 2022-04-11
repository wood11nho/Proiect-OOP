#include <iostream>
#include <optional>
#include <cstdlib>
#include <ctime>
#include <vector>


#include "Echipa.h"
#include "Jucator.h"
#include "vEchipe.h"
#include "Transfer.h"
using namespace std;
class Meci;
vector<Meci> Meciuri;
class Meci{
    Echipa& team1;
    Echipa& team2;
    std::pair<int, int> scor{0, 0};
    char rezultat;
public:
    Meci(Echipa &team1, Echipa &team2, const pair<int, int> &scor, char rezultat)
            : team1(team1), team2(team2), scor(scor), rezultat(rezultat) {}

    virtual ~Meci() {

    }

    friend ostream &operator<<(ostream &os, const Meci &meci) {
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
        system("cls");
        cout<<"Meciul s-a terminat!\n";
        cout<<"REZULTAT FINAL: \n";
        cout<<team1.getNume()<<" "<<scor.first<<" - "<<team2.getNume()<<" "<<scor.second;
    }

};
class Imprumut:public Transfer{
    int durata;
public:
    Imprumut(Echipa &e1, Echipa &e2, Jucator &j, int durata) : Transfer(e1, e2, j), durata(durata) {}
    void Imprumutare(int durata_imprumut){
        this->j.setEchipa(e2);
        this->durata = durata_imprumut;
    }
};
int main() {
    Echipa empty_team(0, 0, 0, "");
    Jucator empty_jucator(0,"","","",16,30,30,30,"",empty_team,1, 1, 1);
    Echipa e1(1,50, 64,"Dinamo Bucuresti");
    Echipa e2(2, 150, 69, "Steaua Bucuresti");
    Echipa e3(3, 75, 64, "Rapid Bucuresti");
    Echipa e4(4, 125, 69, "CFR Cluj");
    Echipa e5(5, 100, 65, "Farul Constanta");
    Echipa e6(6, 125, 68, "Universitatea Craiova");
    vector<Echipa> v1;
    vEchipe vector_echipe(v1);
    vector_echipe.adaugare_echipa(empty_team);
    vector_echipe.adaugare_echipa(e1);
    vector_echipe.adaugare_echipa(e2);
    vector_echipe.adaugare_echipa(e3);
    vector_echipe.adaugare_echipa(e4);
    vector_echipe.adaugare_echipa(e5);
    vector_echipe.adaugare_echipa(e6);


    cout<<"Salut! Suntem echipa Fantasy Player si iti uram bun venit in lumea noastra virtuala!"<<'\n';
    cout<<"Pentru inceput, haide sa iti creezi propriul jucator, apasand tasta 1! Daca vrei sa continuam alta data, apasa tasta 0!"<<'\n';
    int tasta = 0;
    cin>>tasta;
    Jucator your_player;
    if(tasta == 1)
        Jucator::creeaza_jucator(your_player);
    else return 0;
    cout<<"Totul este pregatit! Hai sa incepem\n";
    cout<<"--------------------------------------------------\n";
    cout<<"1.  Alege echipa\n";
    cout<<"0.  Inchide jocul\n";
    cin>>tasta;
    if (tasta == 1) {
        bool v[7];
        srand ( (unsigned int)time(nullptr) );
        for (int i = 1; i <= 6; i++) {
            if (rand()%2 == 1)
                v[i] = true;
            else v[i] = false;
        }
        cout << "Urmatoarele echipe sunt disponibile: \n";
        for (int i = 1; i <= 6; i++) {
            if (v[i]) {
                cout << vector_echipe.getVectorEchipe()[i].getId() << ". " << vector_echipe.getVectorEchipe()[i].getNume() << "\n";
            }
        }
        your_player.alege_echipa(vector_echipe);
    }
    else
        return 0;
    cout<<"Totul este pregatit! Hai sa organizam niste meciuri de pregatire inainte de sezonul regulat!\n";
    cout<<"1. Joaca meci\n";
    cout<<"0. Inchide jocul.\n";
    cin>>tasta;
    if(tasta!=0) {
        int ok = 0;
        while (tasta != 0)
        {
            system("cls");
            cout<<"Etapa "<<ok<<"\n";
            int i = rand() % 6 + 1;
            while(i==your_player.getEchipa()->getId())
                i = rand() % 6 + 1;
            cout<<"Urmeaza meciul impotriva celor de la "<<vector_echipe.getVectorEchipe()[i].getNume()<<"\n";
            cout<<"1. Incepe meciul\n";
            cout<<"2. Vizualizeaza echipa\n";
            cin>>tasta;
            if(tasta == 1) {
                char rezultat = 'X';
                Meciuri.push_back(Meci((Echipa &) your_player.getEchipa(), (Echipa &) vector_echipe.getVectorEchipe()[i], {0, 0}, rezultat));
                Meciuri.back().playmatch();
                cout<<"\n";
                cout<<" ------------------------------------------------ \n";
                cout<<"1. Continua\n";
                cout<<"2. Vezi Statistici\n";
                cin>>tasta;
            }
            else
                return 0;
        }

    }
    else {
        cout<<"Va asteptam data urmatoare sa continuam joaca!";
    }
    system("pause");
    Jucator j1(1,"Stoica","Elias","Romania",19,70,45,50,"Atacant",e1,15, 10, 25);
    cout<<j1;
    j1.schimbare_pozitie("Mijlocas");
    j1.antrenament();

    return 0;
}