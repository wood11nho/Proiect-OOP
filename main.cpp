#include "rlutil.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <random>
#include "Echipa.h"
#include "Jucator.h"
#include "vEchipe.h"
#include "Transfer.h"
#include "Imprumut.h"
#include "Meci.h"
#include "Echipe_disponibile.h"
#include "Items.h"
#include "Adidas.h"
#include "Energizant.h"
#include <memory>
using namespace std;



class vMeciuri{
    std::vector<Meci> VectorMeciuri;
public:
    explicit vMeciuri(const vector <Meci> &vectorMeciuri) : VectorMeciuri(vectorMeciuri) {}

     ~vMeciuri() {

    }
    friend ostream &operator<<(ostream &os, const vMeciuri &meciuri) {
        os << "VectorMeciuri: ";
        int i = 0;
        for (const auto& meci1 : meciuri.VectorMeciuri) {
            i = i + 1;
            os << "Meciul" << i << meci1<<"\n";
        }
        return os;
    }

    void adaugare_meci(Meci m1){
        this->VectorMeciuri.push_back(m1);
    }
    Meci& last_one(){
        return VectorMeciuri.back();
    }

};

class Inventar{
    std::vector<std::shared_ptr<Items>> Colectie;

public:
    explicit Inventar(const vector<std::shared_ptr<Items>> &colectie) : Colectie(colectie) {}

    ~Inventar() {

    }

    friend ostream &operator<<(ostream &os, const Inventar &inventar) {
        os << "\n-------------------------------------";
        os <<"\nEnergizante: \n";
        int contor = 1;
        for(shared_ptr<Items> i: inventar.Colectie){
            if(contor == 5)
                os<<"Adidasi: \n";
            os<<contor<<".";
            os<< *i<<'\n';
            contor++;

        }
        return os;
    }

    void addItem(std::shared_ptr<Items> pulledItem){
        this->Colectie.push_back(pulledItem);
    }
};

class Campionat{
    
};

int main() {
    Echipa empty_team(0, 0, 0, "");
//    Jucator empty_jucator1;
//    cout<<empty_jucator1;
    Jucator empty_jucator(0,"","","",16,30,30,30,empty_team,1, 1, 1, 99);
    Echipa e1(1, 50, 64,"Dinamo Bucuresti");
    Echipa e2(2, 150, 69, "Steaua Bucuresti");
    Echipa e3(3, 75, 64, "Rapid Bucuresti");
    Echipa e4(4, 125, 69, "CFR Cluj");
    Echipa e5(5, 100, 65, "Farul Constanta");
    Echipa e6(6, 125, 68, "Universitatea Craiova");
    Jucator j1(1,"Stoica","Elias","Romania",19,70,45,50,e1,15, 10, 25, 99);
    Adidas a1(15, "Adidas Nemezis", 3, 1, 1);
    Adidas a2(15, "Nike Tiempo", 1, 3, 1);
    Adidas a3(15, "Puma One", 1, 1, 3);
    Adidas a4(30, "Adidas Predator", 6, 2, 2);
    Adidas a5(30, "Nike Mercurial", 2, 6, 2);
    Adidas a6(30, "Puma Future", 2, 2, 6);
    Adidas a7(100, "Nike Mercurial Superfly x Cristiano Ronaldo", 15, 5, 10);
    Adidas a8(100, "Adidas x Speedflow Messi Unparalleled", 10, 5, 15);
    Energizant nrg1(5, "NRG Classic", 100, 1);
    Energizant nrg2(30, "NRG Bronze", 100, 2);
    Energizant nrg3(70, "NRG Silver", 100, 3);
    Energizant nrg4(125, "NRG Gold", 100, 4);
    Inventar inventar_player(std::vector<std::shared_ptr<Items>> {});
    Inventar multime_consumabile(std::vector<std::shared_ptr<Items>> {});
    multime_consumabile.addItem(nrg1.clone());
    multime_consumabile.addItem(nrg2.clone());
    multime_consumabile.addItem(nrg3.clone());
    multime_consumabile.addItem(nrg4.clone());
    multime_consumabile.addItem(a1.clone());
    multime_consumabile.addItem(a2.clone());
    multime_consumabile.addItem(a3.clone());
    multime_consumabile.addItem(a4.clone());
    multime_consumabile.addItem(a5.clone());
    multime_consumabile.addItem(a6.clone());
    multime_consumabile.addItem(a7.clone());
    multime_consumabile.addItem(a8.clone());

    cout<<multime_consumabile;
    vEchipe vector_echipe(vector<Echipa> {});
    vMeciuri vector_meciuri(vector<Meci> {});
    vector_echipe.adaugare_echipa(empty_team);
    vector_echipe.adaugare_echipa(e1);
    vector_echipe.adaugare_echipa(e2);
    vector_echipe.adaugare_echipa(e3);
    vector_echipe.adaugare_echipa(e4);
    vector_echipe.adaugare_echipa(e5);
    vector_echipe.adaugare_echipa(e6);
    cout<<vector_echipe<<"\n";

    nrg1.cumpara_item(j1);

    cout<<j1;

    Imprumut impr{(Echipa &) j1.getEchipa(), e2, j1, 1};
    impr.Imprumutare(1);



    cout<<"Salut! Suntem echipa Fantasy Player si iti uram bun venit in lumea noastra virtuala!"<<'\n';
    cout<<"Pentru inceput, haide sa iti creezi propriul jucator, apasand tasta 1! Daca vrei sa continuam alta data, apasa tasta 0!"<<'\n';
    Jucator your_player;
    int tasta = 0;
    do
    {
        cin>>tasta;
        try {
            if(tasta == 1)
                your_player.creeaza_jucator();
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
    do {
        cout << "Totul este pregatit! Hai sa incepem\n";
        cout << "--------------------------------------------------\n";
        cout << "1.  Alege echipa\n";
        cout << "0.  Inchide jocul\n";
        cin >> tasta;
        try {
            if (tasta == 1) {
                vector<bool> v2;
                int echipe_disp = 0;
                Echipe_disponibile vechipedisp(v2);
                srand((unsigned int) time(nullptr));
                for (int i = 1; i <= (int)vector_echipe.getVectorEchipe().size(); i++) {
                    if (rand() % 2 == 1) {
                        vechipedisp.este_valabila(true);
                        echipe_disp++;
                    }
                    else vechipedisp.este_valabila(false);
                }
                if(echipe_disp == 0)
                    vechipedisp.setEchDisp();
//              cout<<vechipedisp;
                cout << "Urmatoarele echipe sunt disponibile: \n";
                for (int i = 1; i <= 6; i++) {
                    if (vechipedisp.getEchDisp().at(i - 1)) {
                        cout << vector_echipe.getVectorEchipe()[i].getId() << ". "
                             << vector_echipe.getVectorEchipe()[i].getNume() << "\n";
                    }
                }
                your_player.alege_echipa(vector_echipe, vechipedisp);
            }
            else if(tasta == 0)
                return 0;
            else{
                throw(invalidInput("Input invalid!!!"));
            }
        }
        catch(std::exception &err){
            std::cout<<err.what() << '\n';
            rlutil::anykey();
        }


    }while(tasta!=1);
    do
    {
        rlutil::cls();
        cout<<"Alege o optiune dintre cele de mai jos.\n";
        cout<<"1. Joaca meci amical\n";
        cout<<"2. Antrenament\n";
        cout<<"3. Magazin\n";
        cout<<"4. Joaca in campionat.\n";
        cin>>tasta;
        try {

            if (tasta == 1) {

                int ok = 1;
                while (tasta != 2) {
                    rlutil::cls();
                    cout << "Meci amical\n";
                    ok++;
                    int i = rand() % 6 + 1;
                    while (i == your_player.getEchipa()->getId())
                        i = rand() % 6 + 1;
                    cout << "Urmeaza meciul impotriva celor de la " << vector_echipe.getVectorEchipe()[i].getNume()
                         << "\n";
                    cout << "1. Incepe meciul\n";
                    cout << "2. Inventar\n";
                    cin >> tasta;
                    if (tasta == 1) {
                        char rezultat = 'X';
                        vector_meciuri.adaugare_meci(Meci((Echipa &) your_player.getEchipa(), (Echipa &) vector_echipe.getVectorEchipe()[i],
                                     {0, 0}, rezultat));
                        vector_meciuri.last_one().playmatch();
                        cout << "\n";
                        cout << "Statistici: \n";
                        cout << "              "<<your_player.getEchipa()->getNume() << "   -   "<<vector_echipe.getVectorEchipe()[i].getNume()<<"\n";
                        std::random_device rd; // obtain a random number from hardware
                        std::mt19937 gen(rd()); // seed the generator
                        std::uniform_int_distribution<> distr(30, 69); // define the range
                        int aux = distr(gen);
                        cout << "POSESIE             "<< aux << "       -       " << 100 - aux<<"\n";
                        cout << " ------------------------------------------------ \n";
                        int aux1 = rand() % 3;
                        int aux2 = rand() % 3;
                        cout << "SUTURI              "<< vector_meciuri.last_one().getScor().first + aux1 + rand()%7<< "       -       "<< vector_meciuri.last_one().getScor().second + aux2 +rand()%7<<"\n";
                        cout << "SUTURI PE POARTA    "<< vector_meciuri.last_one().getScor().first + aux1 << "       -       "<< vector_meciuri.last_one().getScor().second + aux2<<"\n";
                        cout << "1. Continua\n";
                        cout << "2. Meniu principal\n";
                        cin >> tasta;
                    } else {

                    }
                }

            }
            else if(tasta == 2)
            {
                do {
                    //Antrenament
                    rlutil::cls();
                    your_player.antrenament();
                    cout << "\n";
                    cout << "1. Antrenament nou";
                    cout << "2. Meniu Principal";
                    cin >> tasta;
                }while(tasta!=2);
            }
            else if(tasta == 3)
            {
                do {
                    rlutil::cls();
                    cout << "MAGAZIN";
                    cout << "\n-------------------------------------";
                    cout<<multime_consumabile;
                    cout<<"\nPentru a cumpara item-ul dorit, scrieti numarul corespunzator acestuia: ";
                    cout<<"\nITEM DORIT: ";
                    cin >> tasta;


                }while(tasta!=3);

            }
            else if(tasta == 4)
            {
                cout<<"Campionat";
                cin>>tasta;
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