#include "rlutil.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include "Echipa.h"
#include "Jucator.h"
#include "vEchipe.h"
#include "Transfer.h"
#include "Meci.h"

using namespace std;
//class Meciuri{
//    vector<Meci>
//};
vector<Meci> Meciuri;
int main() {
    Echipa empty_team(0, 0, 0, "");
    Jucator empty_jucator(0,"","","",16,30,30,30,"",empty_team,1, 1, 1);
    Echipa e1(1,50, 64,"Dinamo Bucuresti");
    Echipa e2(2, 150, 69, "Steaua Bucuresti");
    Echipa e3(3, 75, 64, "Rapid Bucuresti");
    Echipa e4(4, 125, 69, "CFR Cluj");
    Echipa e5(5, 100, 65, "Farul Constanta");
    Echipa e6(6, 125, 68, "Universitatea Craiova");
    Jucator j1(1,"Stoica","Elias","Romania",19,70,45,50,"Atacant",e1,15, 10, 25);
//    cout<<j1;
//    j1.schimbare_pozitie("Mijlocas");
//    j1.antrenament();
//    cout<<j1;
    vector<Echipa> v1;
    vEchipe vector_echipe(v1);
    vector_echipe.adaugare_echipa(empty_team);
    vector_echipe.adaugare_echipa(e1);
    vector_echipe.adaugare_echipa(e2);
    vector_echipe.adaugare_echipa(e3);
    vector_echipe.adaugare_echipa(e4);
    vector_echipe.adaugare_echipa(e5);
    vector_echipe.adaugare_echipa(e6);
    cout<<vector_echipe<<"\n";

    cout<<"Salut! Suntem echipa Fantasy Player si iti uram bun venit in lumea noastra virtuala!"<<'\n';
    cout<<"Pentru inceput, haide sa iti creezi propriul jucator, apasand tasta 1! Daca vrei sa continuam alta data, apasa tasta 0!"<<'\n';
    Jucator your_player;
    int tasta = 0;
    do
    {
        cin>>tasta;
        try {
            if(tasta == 1)
                Jucator::creeaza_jucator(your_player);
            else{
                if(tasta!=0)
                    throw (invalidInput{"Input invalid!!!"});
                else return 0;
            }
        }
        catch(std::exception &err){
            std::cout<<err.what() << '\n';
            rlutil::anykey();
            rlutil::cls();
            cout<<"Salut! Suntem echipa Fantasy Player si iti uram bun venit in lumea noastra virtuala!"<<'\n';
            cout<<"Pentru inceput, haide sa iti creezi propriul jucator, apasand tasta 1! Daca vrei sa continuam alta data, apasa tasta 0!"<<'\n';
        }
    }while(tasta!=1);
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
    do
    {
        cout<<"Totul este pregatit! Hai sa organizam niste meciuri de pregatire inainte de sezonul regulat!\n";
        cout<<"1. Joaca meci\n";
        cout<<"0. Inchide jocul.\n";
        cin>>tasta;
        try {

            if (tasta == 1) {

                int ok = 0;
                while (tasta != 0) {
                    rlutil::cls();
                    cout << "Etapa " << ok << "\n";
                    int i = rand() % 6 + 1;
                    while (i == your_player.getEchipa()->getId())
                        i = rand() % 6 + 1;
                    cout << "Urmeaza meciul impotriva celor de la " << vector_echipe.getVectorEchipe()[i].getNume() << "\n";
                    cout << "1. Incepe meciul\n";
                    cout << "2. Vizualizeaza echipa\n";
                    cin >> tasta;
                    if (tasta == 1) {
                        char rezultat = 'X';
                        Meciuri.push_back(
                                Meci((Echipa &) your_player.getEchipa(), (Echipa &) vector_echipe.getVectorEchipe()[i],
                                     {0, 0}, rezultat));
                        Meciuri.back().playmatch();
                        cout << "\n";
                        cout << " ------------------------------------------------ \n";
                        cout << "1. Continua\n";
                        cout << "2. Vezi Statistici\n";
                        cin >> tasta;
                    }
                    else
                        cout<<"ce cauti aici";
                }

            }
            else
            {

                if(tasta!=0)
                    throw (invalidInput{"Input invalid!!!"});
            }
        }
        catch(std::exception &err){
            std::cout<<err.what() << '\n';
            rlutil::anykey();
        }
    }
    while(tasta!=0);
}