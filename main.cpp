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
#include "Imprumut.h"
#include "Meci.h"
#include "Echipe_disponibile.h"
#include "Item.h"
#include "Adidas.h"
#include "Energizant.h"
#include "Inventar.h"

#include <memory>
using namespace std;



class Campionat{
    std::vector<Meci> VectorMeciuri;
public:
    explicit Campionat(const vector <Meci> &vectorMeciuri) : VectorMeciuri(vectorMeciuri) {}

     ~Campionat() = default;
    friend ostream &operator<<(ostream &os, const Campionat &meciuri) {
        os << "VectorMeciuri: ";
        int i = 0;
        for (const auto& meci1 : meciuri.VectorMeciuri) {
            i = i + 1;
            os << "Meciul" << i << meci1<<"\n";
        }
        return os;
    }

    void adaugare_meci(const Meci& m1){
        this->VectorMeciuri.push_back(m1);
    }
    Meci& last_one(){
        return VectorMeciuri.back();
    }
    void joaca_campionat(vEchipe& ve){
        for(int i = 0 ;i< ve.getNrechipe();i++){
            int mid = ve.getNrechipe() / 2;
            vEchipe v1({}), v2({});
            for(int j = 1; j<=mid;j++)
                v1.adaugare_echipa((Echipa &)ve.getVectorEchipe().at(j));
            for(int j = ve.getNrechipe();j>mid;j--)
                v2.adaugare_echipa((Echipa &) ve.getVectorEchipe().at(j));
            cout<<v1<<"\n"<<v2;
            if(i%2==1){
                cout<<"\nETAPA "<<i + 1<<"\n";
                for(int j = 0;j<mid;j++){
                    this->adaugare_meci(Meci((Echipa &) v1.getVectorEchipe().at(j), (Echipa &) v2.getVectorEchipe().at(j), {0,0}));
                    cout<<"\n---"<<VectorMeciuri.back().getTeam1().getNume()<<" "<<VectorMeciuri.back().getScor().first<<" - "<<VectorMeciuri.back().getScor().second<<" "<<VectorMeciuri.back().getTeam2().getNume()<<"\n\n\n";
                }
            }
            else{
                cout<<"\nETAPA "<<i + 1<<"\n";
                for(int j = 0;j<mid;j++){
                    this->adaugare_meci(Meci((Echipa &) v2.getVectorEchipe().at(j), (Echipa &) v1.getVectorEchipe().at(j), {0,0}));
                    cout<<"\n---"<<VectorMeciuri.back().getTeam1().getNume()<<" "<<VectorMeciuri.back().getScor().first<<" - "<<VectorMeciuri.back().getScor().second<<" "<<VectorMeciuri.back().getTeam2().getNume()<<"\n\n\n";
                }
            }
            char tasta;
            do {
                cout << "\n1. Joaca etapa\n";
                cin >> tasta;
                if (tasta == '1') {
                    for (int k = 1; k <= mid; k++) {
                        VectorMeciuri.back().playmatch();
                        cout<<"\n-------------------------------------------";
                        VectorMeciuri.back().statistici();
                        cout<<"\n";
                        VectorMeciuri.pop_back();
                    }
                    cout<<"\nAcestea sunt rezultatele din prima etapa.\n";
                    rlutil::anykey();
                } else {
                    cout << "Ai introdus o tasta gresita. Incearca din nou!";
                    rlutil::anykey();
                }
            }while(tasta!='1');
            Echipa aux(ve.getVectorEchipe().back());
            ve.pop_echipa();
            ve.insert_echipa(1, aux);
        }
    }

};

int Adidas::nradidasi=0;
int Energizant::nrenerg=0;

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

//    cout<<Energizant::getNrenerg()<<"energizante \n"<<Adidas::getNradidasi()<<"adidasi\n";

    Inventar inventar_player(std::vector<std::shared_ptr<Item>> {});

    Inventar multime_consumabile(std::vector<std::shared_ptr<Item>> {});
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

//    cout<<multime_consumabile;
    vEchipe vector_echipe(vector<Echipa> {});
    Campionat vector_meciuri(vector<Meci> {});
    vector_echipe.adaugare_echipa(empty_team);
    vector_echipe.adaugare_echipa(e1);
    vector_echipe.adaugare_echipa(e2);
    vector_echipe.adaugare_echipa(e3);
    vector_echipe.adaugare_echipa(e4);
    vector_echipe.adaugare_echipa(e5);
    vector_echipe.adaugare_echipa(e6);
//    cout<<vector_echipe<<"\n";

    j1.cumpara(nrg1, inventar_player);
    j1.consuma(nrg1);
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
    int acasa = 1;
    do
    {
        rlutil::cls();
        cout<<"Alege o optiune dintre cele de mai jos.\n";
        cout<<"1. Joaca meci amical\n";
        cout<<"2. Antrenament\n";
        cout<<"3. Magazin\n";
        cout<<"4. Joaca in campionat.\n";
        cout<<"5. Iesi din joc\n";
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
                        vector_meciuri.adaugare_meci(Meci((Echipa &) your_player.getEchipa(), (Echipa &) vector_echipe.getVectorEchipe()[i],
                                     {0, 0}));
                        vector_meciuri.last_one().playmatch();
                        cout << "\n";
                        cout << "Statistici: \n";
                        cout << "              "<<your_player.getEchipa()->getNume() << "   -   "<<vector_echipe.getVectorEchipe()[i].getNume()<<"\n";
                        vector_meciuri.last_one().statistici();
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
                    do {
                        if (tasta >= 1 and tasta <= (int) multime_consumabile.getColectie().size() ) {
                            your_player.cumpara(*multime_consumabile.getColectie().at(tasta - 1), inventar_player);
                            tasta = 0;
                            //aici ori il adaug la colectie, ori il consum
                        } else {
                            cout << "\nTasta incorecta! Alege din nou!\n";
                            cin >> tasta;
                        }
                    }
                    while(tasta!=0);
                    cout<<"-------------------------------------";
                    cout<<"\n0. Inapoi la meniul principal.";
                    cout<<"\n1. Incearca din nou\n Alegere: ";
                    cin>>tasta;
                    cout<<"\n";

                }while(tasta!=0);

            }
            else if(tasta == 4)
            {
                do {
                    rlutil::cls();
                    cout << "Campionat\n---------------------------------------";
                    vector_meciuri.joaca_campionat(vector_echipe);
                    cout << "\n0. Meniu principal\n";
                    cin>>tasta;
                }
                while(tasta!=0);
            }
            else
            {
                if(tasta!=0)
                    throw (invalidInput{"Input invalid!!!"});
                else acasa = 0;
            }
        }
        catch(std::exception &err){
            std::cout<<err.what() << '\n';
            rlutil::anykey();
        }
    }
    while(acasa!=0);

}